"""Round 50: match absent CHR_CC blocks to the gaps between dumped parameter ID table blocks by ACCESS signature: every
load / store the ROM and the live flash2 make inside the gap (raw lis + displacement scan, named or not) must land on a
record of the same width, and loads must agree in sign (lha <-> S, lhz <-> U; byte loads, stores and addi are neutral).
Lists, per gap, the unnamed addresses read inside it and the candidates that cover every access (one block, or an
ordered pair), most covered records first.  usage: gap_access_signatures.py <repo> [max_gap]"""
import contextlib
import io
import os
import re
import sys

sys.path.insert(0, "/home/linux/.claude/jobs/374b0424/tmp/w15/r45")
repo = os.path.abspath(sys.argv[1])
max_gap = sys.argv[2] if len(sys.argv) > 2 else "64"
sys.argv = [sys.argv[0], repo, max_gap]
with contextlib.redirect_stdout(io.StringIO()):
    import sweep_table_gaps as s  # noqa: E402

CM = s.CM
D_FORM = {14: ("addi", 0, None), 32: ("lwz", 4, None), 34: ("lbz", 1, None), 36: ("stw", 4, None), 38: ("stb", 1, None),
          40: ("lhz", 2, "U"), 42: ("lha", 2, "S"), 44: ("sth", 2, None), 33: ("lwzu", 4, None), 35: ("lbzu", 1, None),
          41: ("lhzu", 2, "U"), 43: ("lhau", 2, "S"), 37: ("stwu", 4, None), 39: ("stbu", 1, None), 45: ("sthu", 2, None)}
in_gap = {}
for start, gap, b1, b2 in s.gaps:
    for a in range(start, start + gap):
        in_gap[a] = (start, gap)
access = {}
images = [(open(os.path.join(CM, "originals/cm848_rom.bin"), "rb").read(), 0),
          (s.flash2, 0x500000)]
for data, base in images:
    words = [int.from_bytes(data[i:i + 4], "big") for i in range(0, len(data) - 3, 4)]
    for k, w in enumerate(words):
        op, ra, d = w >> 26, (w >> 16) & 31, w & 0xFFFF
        if op not in D_FORM or ra == 0:
            continue
        sd = d - 0x10000 if d & 0x8000 else d
        for j in range(k - 1, max(-1, k - 25), -1):
            p = words[j]
            if p >> 26 == 15 and (p >> 21) & 31 == ra and (p >> 16) & 31 == 0:
                a = (((p & 0xFFFF) << 16) + sd) & 0xFFFFFFFF
                if a in in_gap:
                    access.setdefault(a, set()).add(D_FORM[op])
                break
            if (p >> 21) & 31 == ra and p >> 26 in (14, 15, 32, 33, 34, 35, 40, 41, 42, 43, 31):
                break
cpp = open(os.path.join(CM, "output/cm848_rom.ghidra.cpp"), errors="replace").read()
unnamed = {int(t, 16) for t in re.findall(r"\b(?:DAT|WORD|BYTE|DWORD|_DAT)_00([0-9a-f]{6})\b", cpp)}


def fits(block, base):
    """(records covering an access, accesses covered, accesses in range, conflict)"""
    recs = s.absent[block][1]
    covered = n_rec = 0
    conflict = False
    for o, (name, typ, size, desc) in recs.items():
        a = base + o
        acc = access.get(a)
        if not acc or not size:
            continue
        n_rec += 1
        for opname, width, sign in acc:
            if opname == "addi":
                continue
            if width != size or (sign and recs[o][1] in ("N", "S", "B") and False):
                conflict = True
        covered += 1
    return n_rec, conflict


sign_of = {}
for path in s.releases:
    for line in open(path, errors="replace"):
        head = line.split(";")[0].split(",")
        if len(head) > 11 and re.fullmatch(r"[0-9A-Fa-f]{4}", head[2]) and re.fullmatch(r"[0-9A-Fa-f]{1,4}", head[3]):
            sign_of.setdefault((int(head[2], 16), int(head[3], 16)), head[9])


def score(placed, start, gap):
    hit_addrs, conflict, n = set(), False, 0
    for b, off in placed:
        for o, (name, typ, size, desc) in s.absent[b][1].items():
            a = start + off + o
            acc = access.get(a)
            if not acc or not size:
                continue
            n += 1
            hit_addrs.add(a)
            for opname, width, sign in acc:
                if opname == "addi":
                    continue
                if width != size:
                    conflict = True
                if sign and sign_of.get((b, o)) in ("S", "U") and sign != sign_of[(b, o)]:
                    conflict = True
    accessed = {a for a in access if start <= a < start + gap}
    return (not conflict) and accessed <= hit_addrs, n, len(accessed)


for start, gap, b1, b2 in s.gaps:
    accessed = sorted(a for a in access if start <= a < start + gap)
    reads = sorted(a for a in unnamed if start <= a < start + gap)
    if not reads:
        continue
    cands = []
    for b, x in s.absent_scalar.items():
        pass
    sizes = {}
    for x, bs in s.absent_scalar.items():
        for b in bs:
            sizes[b] = x
    for b, x in sizes.items():
        if x == gap or (x % 2 and x + 1 == gap):
            ok, n, m = score([(b, 0)], start, gap)
            if ok:
                cands.append((n, [(b, 0)]))
    for p, xp in sizes.items():
        step = xp + (xp % 2)
        if step >= gap:
            continue
        for q, xq in sizes.items():
            if p != q and step + xq in (gap, gap - (xq % 2)):
                ok, n, m = score([(p, 0), (q, step)], start, gap)
                if ok:
                    cands.append((n, [(p, 0), (q, step)]))
    cands.sort(key=lambda c: -c[0])
    print(f"gap {start:#09x} +{gap} after {b1:04X} before {b2:04X}: {len(accessed)} accessed, unnamed read "
          f"{', '.join(hex(a) for a in reads)}; {len(cands)} access-consistent candidates")
    for n, c in cands[:4]:
        print(f"   {n} records hit: " + " + ".join(f"{b:04X}@{o} {[s.absent[b][1][k][0] for k in sorted(s.absent[b][1])][:3]}"
                                                 for b, o in c))

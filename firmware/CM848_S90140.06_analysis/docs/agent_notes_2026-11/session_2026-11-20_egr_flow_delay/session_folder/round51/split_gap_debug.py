"""Round 51: debug why a gap has no fill. Place a known block at a fixed address, then for each remaining sub-gap list
the absent blocks whose size fits and say, record by record, what fails (width, sign, uncovered address).
usage: split_gap_debug.py <repo> <gap start hex> <block hex>@<address hex> [<block>@<address> ...]"""
import contextlib
import csv
import io
import os
import sys

sys.path.insert(0, "/home/linux/.claude/jobs/374b0424/tmp/w15/r45")
sys.path.insert(0, "/home/linux/.claude/jobs/374b0424/tmp/w15/r50")
repo = os.path.abspath(sys.argv[1])
gap_start = int(sys.argv[2], 16)
fixed = [(int(b, 16), int(a, 16)) for b, a in (x.split("@") for x in sys.argv[3:])]
sys.argv = [sys.argv[0], repo, "64"]
with contextlib.redirect_stdout(io.StringIO()):
    import gap_access_signatures as gs  # noqa: E402
s = gs.s
WIDTH = {"byte": 1, "word": 2, "i16": 2, "dword": 4}
rows = {}
for r in csv.reader(open(os.path.join(s.CM, "output/global_variables.csv"))):
    if r and r[0].startswith("0x") and len(r) > 2:
        w = WIDTH.get(r[2])
        if w is None and "[" in r[2]:
            base, n = r[2].split("[")
            w = WIDTH.get(base, 0) * int(n.rstrip("]") or 0)
        rows[int(r[0], 16)] = (r[1], w or 0, r[2])
gap = next(g for g in s.gaps if g[0] == gap_start)
start, size, b1, b2 = gap
print(f"gap {start:#x} +{size} ({start:#x}..{start + size - 1:#x}) after {b1:04X} before {b2:04X}")
sizes = {}
for x, bs in s.absent_scalar.items():
    for b in bs:
        sizes[b] = x


def report(b, base):
    bad = []
    for o, (name, typ, sz, desc) in sorted(s.absent[b][1].items()):
        a = base + o
        acc = gs.access.get(a, set())
        row = rows.get(a)
        notes = []
        for opname, width, sign in acc:
            if opname != "addi" and width != sz:
                notes.append(f"{opname} width {width} != {sz}")
            if sign and gs.sign_of.get((b, o)) in ("S", "U") and sign != gs.sign_of[(b, o)]:
                notes.append(f"{opname} sign {sign} != {gs.sign_of[(b, o)]}")
        if row and row[1] and row[1] != sz:
            notes.append(f"row {row[0]} is {row[2]}")
        bad += notes
        print(f"   +{o:02X} {a:#x} {name} [{gs.sign_of.get((b, o))}{sz}] acc={sorted(x[0] for x in acc)} "
              f"row={row[0] if row else '-'} {'; '.join(notes)}")
    covered = {base + o for o in s.absent[b][1]}
    return bad, covered


covered_all = set()
for b, a in fixed:
    print(f"== fixed {b:04X} @ {a:#x} (size {sizes.get(b)})")
    bad, cov = report(b, a)
    covered_all |= cov
spans = sorted((a, a + sizes[b] + (sizes[b] % 2)) for b, a in fixed)
free, cur = [], start
for lo, hi in spans:
    if lo > cur:
        free.append((cur, lo - cur))
    cur = max(cur, hi)
if cur < start + size:
    free.append((cur, start + size - cur))
for lo, n in free:
    need = sorted({a for a in gs.access if lo <= a < lo + n} | {a for a in rows if lo <= a < lo + n})
    print(f"== free {lo:#x} +{n}: accessed / named {[hex(a) for a in need]}")
    print("   rows: " + ", ".join(f"{a:#x} {rows[a][0]} {rows[a][2]}" for a in need if a in rows))
    print("   accesses: " + ", ".join(f"{a:#x} {sorted(x[0] for x in gs.access[a])}" for a in need if a in gs.access))
    for b, x in sorted(sizes.items(), key=lambda kv: kv[0]):
        if x == n or x + (x % 2) == n:
            print(f"   candidate {b:04X} (size {x}):")
            bad, cov = report(b, lo)
            miss = [hex(a) for a in need if a not in cov]
            print(f"      -> {'FAILS ' + str(len(bad)) if bad else 'width/sign ok'}; uncovered {miss}")

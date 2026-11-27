"""Round 51: exact covers of a free span by one, two or three absent blocks back to back (a 1-byte pad after an odd
block allowed). Width mismatches reject a cover; sign mismatches (lha on a U record, lhz on an S one) only lower its
score, since the compiler loads some state / enum words with lha. Every accessed or typed-row address in the span must
start a record.  usage: scored_cover.py <repo> <span start hex> <span bytes>"""
import contextlib
import csv
import io
import os
import sys

sys.path.insert(0, "/home/linux/.claude/jobs/374b0424/tmp/w15/r45")
sys.path.insert(0, "/home/linux/.claude/jobs/374b0424/tmp/w15/r50")
repo = os.path.abspath(sys.argv[1])
lo = int(sys.argv[2], 16)
n = int(sys.argv[3])
sys.argv = [sys.argv[0], repo, "64"]
with contextlib.redirect_stdout(io.StringIO()):
    import gap_access_signatures as gs  # noqa: E402
s = gs.s
WIDTH = {"byte": 1, "word": 2, "i16": 2, "dword": 4}
rows = {}
for r in csv.reader(open(os.path.join(s.CM, "output/global_variables.csv"))):
    if r and r[0].startswith("0x") and len(r) > 2:
        rows[int(r[0], 16)] = (r[1], WIDTH.get(r[2]))
sizes = {}
for x, bs in s.absent_scalar.items():
    for b in bs:
        sizes[b] = x
need = {a for a in gs.access if lo <= a < lo + n} | {a for a in rows if lo <= a < lo + n}


def score(placed):
    hit, sign_bad = set(), 0
    for b, base in placed:
        for o, (name, typ, size, desc) in s.absent[b][1].items():
            a = base + o
            for opname, width, sign in gs.access.get(a, ()):
                if opname != "addi" and width != size:
                    return None
                if sign and gs.sign_of.get((b, o)) in ("S", "U") and sign != gs.sign_of[(b, o)]:
                    sign_bad += 1
            if a in rows and rows[a][1] and rows[a][1] != size:
                return None
            hit.add(a)
    if not need <= hit:
        return None
    return sign_bad


def step(x):
    return x + (x % 2)


by_size = {}
for b, x in sizes.items():
    if x <= n:
        by_size.setdefault(x, []).append(b)


def ends(rest):
    """blocks that end the span exactly when placed with `rest` bytes left"""
    return by_size.get(rest, []) + by_size.get(rest - 1, []) if rest > 0 else []


found = []
for b in ends(n):
    sc = score([(b, lo)])
    if sc is not None:
        found.append((sc, [(b, lo)]))
for p, xp in sizes.items():
    sp = step(xp)
    if sp >= n:
        continue
    for q in ends(n - sp):
        if q != p:
            sc = score([(p, lo), (q, lo + sp)])
            if sc is not None:
                found.append((sc, [(p, lo), (q, lo + sp)]))
    for q, xq in sizes.items():
        sq = step(xq)
        if q == p or sp + sq >= n:
            continue
        for r in ends(n - sp - sq):
            if r in (p, q):
                continue
            sc = score([(p, lo), (q, lo + sp), (r, lo + sp + sq)])
            if sc is not None:
                found.append((sc, [(p, lo), (q, lo + sp), (r, lo + sp + sq)]))
found.sort(key=lambda f: (f[0], len(f[1])))
print(f"span {lo:#x} +{n}: need {sorted(hex(a) for a in need)}; {len(found)} covers")
for sc, f in found[:12]:
    print(f"  sign mismatches {sc}: " + " + ".join(
        f"{b:04X}@{a:#x}[{sizes[b]}] {[s.absent[b][1][k][0] for k in sorted(s.absent[b][1])][:3]}" for b, a in f))

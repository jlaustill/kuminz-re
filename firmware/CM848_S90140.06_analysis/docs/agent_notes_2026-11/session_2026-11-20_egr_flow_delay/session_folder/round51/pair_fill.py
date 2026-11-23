"""Round 51: ordered pairs of absent blocks that tile a free span exactly and pass the width / sign / named-row
checks.  usage: pair_fill.py <repo> <span start hex> <span bytes>"""
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
    if r and r[0].startswith("0x") and len(r) > 2 and r[2] in WIDTH:
        rows[int(r[0], 16)] = (r[1], WIDTH[r[2]])
sizes = {}
for x, bs in s.absent_scalar.items():
    for b in bs:
        sizes[b] = x
need = {a for a in gs.access if lo <= a < lo + n} | {a for a in rows if lo <= a < lo + n}


def ok(placed):
    hit = set()
    for b, base in placed:
        for o, (name, typ, size, desc) in s.absent[b][1].items():
            a = base + o
            for opname, width, sign in gs.access.get(a, ()):
                if opname != "addi" and width != size:
                    return False
                if sign and gs.sign_of.get((b, o)) in ("S", "U") and sign != gs.sign_of[(b, o)]:
                    return False
            if a in rows and rows[a][1] != size:
                return False
            hit.add(a)
    return need <= hit


def step(x):
    return x + (x % 2)


small = [(b, x) for b, x in sizes.items() if x < n]
found = []
for p, xp in small:
    for q, xq in small:
        if q == p:
            continue
        if step(xp) + step(xq) == n or step(xp) + xq == n:
            if ok([(p, lo), (q, lo + step(xp))]):
                found.append([(p, lo), (q, lo + step(xp))])
for f in found:
    print(" + ".join(f"{b:04X}@{a:#x}[{sizes[b]}] {[s.absent[b][1][k][0] for k in sorted(s.absent[b][1])][:4]}"
                     for b, a in f))
print(f"{len(found)} pairs; need {sorted(hex(a) for a in need)}")

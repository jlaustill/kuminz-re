"""Round 51: fill a large gap with up to three absent CHR_CC blocks back to back. A fill must:
  - sum exactly to the gap (a 1-byte pad after an odd block allowed);
  - put every load / store in the gap on a record of its width, with lha / lhz agreeing with the record's sign;
  - put every named row's asm width on a record of the same width.
Ranked by records that land on accessed or named addresses.  usage: three_block_fill.py <repo> <gap start hex>..."""
import contextlib
import csv
import io
import os
import re
import sys

sys.path.insert(0, "/home/linux/.claude/jobs/374b0424/tmp/w15/r45")
sys.path.insert(0, "/home/linux/.claude/jobs/374b0424/tmp/w15/r50")
repo = os.path.abspath(sys.argv[1])
targets = [int(x, 16) for x in sys.argv[2:]]
sys.argv = [sys.argv[0], repo, "64"]
with contextlib.redirect_stdout(io.StringIO()):
    import gap_access_signatures as gs  # noqa: E402  (access map, gaps, absent blocks, signs)
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


def check(placed, start, gap):
    hit, good = set(), True
    for b, off in placed:
        for o, (name, typ, size, desc) in s.absent[b][1].items():
            a = start + off + o
            if not size:
                continue
            for opname, width, sign in gs.access.get(a, ()):
                if opname != "addi" and width != size:
                    return False, 0
                if sign and gs.sign_of.get((b, o)) in ("S", "U") and sign != gs.sign_of[(b, o)]:
                    return False, 0
            if a in rows and rows[a][1] != size:
                return False, 0
            if a in gs.access or a in rows:
                hit.add(a)
    need = {a for a in gs.access if start <= a < start + gap} | {a for a in rows if start <= a < start + gap}
    return need <= hit, len(hit)


def step(x):
    return x + (x % 2)


for start, gap, b1, b2 in s.gaps:
    if start not in targets:
        continue
    found = []
    blocks = [(b, x) for b, x in sizes.items() if x <= gap]
    for p, xp in blocks:
        sp = step(xp)
        if sp > gap:
            continue
        for q, xq in blocks:
            if q == p:
                continue
            sq = step(xq)
            if sp + sq > gap:
                continue
            rest = gap - sp - sq
            if rest == 0:
                ok, n = check([(p, 0), (q, sp)], start, gap)
                if ok:
                    found.append((n, [(p, 0), (q, sp)]))
                continue
            for r, xr in blocks:
                if r in (p, q) or step(xr) != rest and xr != rest:
                    continue
                ok, n = check([(p, 0), (q, sp), (r, sp + sq)], start, gap)
                if ok:
                    found.append((n, [(p, 0), (q, sp), (r, sp + sq)]))
    found.sort(key=lambda f: -f[0])
    need = len({a for a in gs.access if start <= a < start + gap} | {a for a in rows if start <= a < start + gap})
    print(f"gap {start:#09x} +{gap} after {b1:04X} before {b2:04X}: {need} accessed or named addresses; "
          f"{len(found)} consistent fills")
    for n, f in found[:8]:
        print(f"   {n} hits: " + " + ".join(f"{b:04X}@{o}({s.absent[b][1][min(s.absent[b][1])][0]})" for b, o in f))

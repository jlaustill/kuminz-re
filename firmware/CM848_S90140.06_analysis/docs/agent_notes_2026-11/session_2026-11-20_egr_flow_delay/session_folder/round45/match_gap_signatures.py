"""Round 45: rank absent CHR_CC blocks for each gap between dumped parameter ID table blocks by their width signature:
every record (offset, size) of the candidate - one block, or an ordered pair placed back to back - must land on a
CM848 row of the same width (byte 1, word / i16 2, dword 4), and every CM848 row in the gap must be covered.
A PERFECT match covers all rows with all records (rows with an unknown width count as a miss).
usage: match_gap_signatures.py <repo> [max_gap]"""
import csv
import os
import re
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
repo = os.path.abspath(sys.argv[1])
max_gap = int(sys.argv[2]) if len(sys.argv) > 2 else 64
sys.argv = [sys.argv[0], repo, str(max_gap)]
import io  # noqa: E402
import contextlib  # noqa: E402

buf = io.StringIO()
with contextlib.redirect_stdout(buf):
    import sweep_table_gaps as s  # noqa: E402  (reuses its tables, extents and gaps)

WIDTH = {"byte": 1, "char": 1, "bool": 1, "word": 2, "i16": 2, "short": 2, "ushort": 2, "dword": 4, "uint": 4, "int": 4,
         "i32": 4, "float": 4, "pointer": 4}
rows = {}
for r in csv.reader(open(os.path.join(s.CM, "output/global_variables.csv"))):
    if r and r[0].startswith("0x") and len(r) > 2:
        a = int(r[0], 16)
        t = r[2].strip()
        w = WIDTH.get(t) or (4 if t.endswith("*") else None)
        if "[" in t or (t and w is None):
            w = -1  # arrays / structs / enums: width not comparable here
        rows[a] = (r[1], w)


def signature(recs):
    return sorted((o, size) for o, (_, typ, size, _) in recs.items() if size)


def score(start, gap, placed):
    """placed = [(block, offset_in_gap)]; returns (perfect, covered rows, total rows, matched records, records)."""
    in_gap = {a - start: rows[a] for a in rows if start <= a < start + gap}
    matched = recs_n = 0
    covered = set()
    for b, base in placed:
        for o, size in signature(s.absent[b][1]):
            recs_n += 1
            row = in_gap.get(base + o)
            if row and row[1] == size:
                matched += 1
                covered.add(base + o)
    perfect = bool(in_gap) and matched == recs_n and len(covered) == len(in_gap)
    return perfect, len(covered), len(in_gap), matched, recs_n


sizes = {}
for x, bs in s.absent_scalar.items():
    for b in bs:
        sizes[b] = x
out = []
for start, gap, b1, b2 in s.gaps:
    cands = []
    for b, x in sizes.items():
        if x == gap or (x % 2 and x + 1 == gap):
            cands.append([(b, 0)])
    for p, xp in sizes.items():
        step = xp + (xp % 2)
        for q, xq in sizes.items():
            if p != q and step + xq in (gap, gap - (xq % 2)) and step < gap:
                cands.append([(p, 0), (q, step)])
    best = []
    for c in cands:
        sc = score(start, gap, c)
        if sc[0]:
            best.append((c, sc))
    n_rows = sum(1 for a in rows if start <= a < start + gap)
    label = f"gap {start:#09x} +{gap:<3} after {b1:04X} before {b2:04X} ({n_rows} rows)"
    if best:
        out.append(f"{label}: {len(best)} PERFECT -> " + " | ".join(
            "+".join(f"{b:04X}@{o}" for b, o in c) for c, _ in best[:6]))
    else:
        out.append(f"{label}: no perfect match ({len(cands)} size candidates)")
print("\n".join(out))

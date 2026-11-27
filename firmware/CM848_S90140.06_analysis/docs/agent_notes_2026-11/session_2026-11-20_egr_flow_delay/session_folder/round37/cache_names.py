"""Round 37: name every unnamed lookup cache word from its interpolator calls.
For each DAT_ / WORD_ label passed as the first argument of lookupTableInterpolation (1-D: word) or
cm848_dualAxisTableInterpolation (2-D: word[2]), the table base is the x axis argument without its role suffix
(_x_axis / _axis); a cache whose calls use one base gets <base>_cached_axis_offset(s). Reports conflicts (calls with
several bases, mixed 1-D / 2-D use, an address that already has a named row, a name already taken) for review.
usage: cache_names.py <cpp> <global_variables.csv> <out.tsv>"""
import re
import sys
from collections import defaultdict

text = open(sys.argv[1], errors="replace").read()
rows, names = {}, set()
for l in open(sys.argv[2], errors="replace"):
    p = l.split(",", 3)
    if len(p) >= 3 and p[0].startswith("0x"):
        rows[int(p[0], 16)] = (p[1], p[2])
        if p[1]:
            names.add(p[1])
marks = [(m.start(), m.group(1)) for m in re.finditer(r"^// Function: (\S+) @", text, re.M)]


def func_at(pos):
    f = None
    for s, n in marks:
        if s > pos:
            break
        f = n
    return f


uses = defaultdict(list)
for m in re.finditer(r"\b(lookupTableInterpolation|cm848_dualAxisTableInterpolation)\s*\(([^;]*?)\);", text, re.S):
    args = [a.strip() for a in re.sub(r"\s+", " ", m.group(2)).split(",")]
    mm = re.match(r"&?(?:DAT|WORD)_(00[34][0-9a-f]{5})$", args[0])
    if not mm:
        continue
    a = int(mm.group(1), 16)
    dims = 1 if m.group(1) == "lookupTableInterpolation" else 2
    data = args[3] if dims == 1 else (args[5] if len(args) > 5 else "")
    base = re.sub(r"(_values|_grid)$", "", data.lstrip("&").split("[")[0].replace("(word *)", "").strip())
    if base == data.lstrip("&").split("[")[0].replace("(word *)", "").strip():
        axis = args[2] if len(args) > 2 else ""
        base = re.sub(r"(_x_axis|_axis)$", "", axis.lstrip("&").split("[")[0].replace("(word *)", "").strip())
    uses[a].append((dims, base, func_at(m.start())))
out, conflicts = [], []
for a in sorted(uses):
    dims = {u[0] for u in uses[a]}
    bases = sorted({u[1] for u in uses[a]})
    funcs = sorted({u[2] for u in uses[a]})
    row = rows.get(a)
    if len(dims) != 1 or len(bases) != 1 or not re.match(r"^[a-z][a-z0-9_]+$", bases[0]) or "WORD_ARRAY" in bases[0]:
        conflicts.append(f"0x{a:06x}\tdims={dims}\tbases={bases}\t{funcs}")
        continue
    d = dims.pop()
    name = bases[0] + ("_cached_axis_offset" if d == 1 else "_cached_axis_offsets")
    typ = "word" if d == 1 else "word[2]"
    if row and row[0]:
        conflicts.append(f"0x{a:06x}\tnamed row {row[0]} ({row[1]})\twould be {name}\t{funcs}")
        continue
    if name in names:
        conflicts.append(f"0x{a:06x}\tname {name} taken\t{funcs}")
        continue
    out.append(f"0x{a:08x}\t{name}\t{typ}\t{len(uses[a])} calls in {', '.join(funcs)}")
    names.add(name)
open(sys.argv[3], "w").write("\n".join(out) + "\n")
print(f"{len(out)} nameable, {len(conflicts)} for review")
for c in conflicts:
    print("REVIEW", c[:240])

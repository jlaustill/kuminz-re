"""Round 38: audit the named lookup cache rows against their own interpolator calls.
For each named label passed as the first argument of lookupTableInterpolation (1-D) / cm848_dualAxisTableInterpolation
(2-D): its row type (1-D wants word, 2-D wants word[2]: a 2-D cache typed word leaves its y offset unnamed), and the
name a cache_names.py-style derivation would give (<data table>_cached_axis_offset(s)).
usage: cache_audit.py <cpp> <global_variables.csv>"""
import re
import sys
from collections import defaultdict

text = open(sys.argv[1], errors="replace").read()
by_name = {}
for l in open(sys.argv[2], errors="replace"):
    p = l.split(",", 3)
    if len(p) >= 3 and p[0].startswith("0x") and p[1]:
        by_name[p[1]] = (int(p[0], 16), p[2])
uses = defaultdict(list)
for m in re.finditer(r"\b(lookupTableInterpolation|cm848_dualAxisTableInterpolation)\s*\(([^;]*?)\);", text, re.S):
    args = [a.strip() for a in re.sub(r"\s+", " ", m.group(2)).split(",")]
    first = args[0].lstrip("&").split("[")[0].strip()
    if first not in by_name:
        continue
    dims = 1 if m.group(1) == "lookupTableInterpolation" else 2
    data = args[3] if dims == 1 else (args[5] if len(args) > 5 else "")
    base = re.sub(r"(_values|_grid)$", "", data.lstrip("&").split("[")[0].replace("(word *)", "").strip())
    uses[first].append((dims, base))
width, naming, ok = [], [], 0
for name, us in sorted(uses.items()):
    a, typ = by_name[name]
    dims = {u[0] for u in us}
    bases = sorted({u[1] for u in us})
    if dims == {2} and typ != "word[2]":
        width.append(f"0x{a:06x} {name} {typ}: 2-D cache ({len(us)} calls)")
    if dims == {1} and typ not in ("word", "i16"):
        width.append(f"0x{a:06x} {name} {typ}: 1-D cache")
    want = (bases[0] + ("_cached_axis_offset" if dims == {1} else "_cached_axis_offsets")) if len(bases) == 1 and len(dims) == 1 else None
    if want and want != name:
        naming.append(f"0x{a:06x} {name} -> {want}")
    else:
        ok += 1
print(f"named caches: {len(uses)}; width problems: {len(width)}; name differs from its lookup: {len(naming)}; "
      f"matching or shared: {ok}")
for w in width:
    print("WIDTH", w)
for n in naming[:40]:
    print("NAME", n)

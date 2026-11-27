"""Round 10 stage A generator: each RE lookup cache word (the first argument of lookupTableInterpolation /
cm848_dualAxisTableInterpolation) gets the name of the table it serves + _interp_state (a second cache of the same table:
_interp_state_2; the one cache shared by the 3rd and 4th gear exhaust brake unlock lookups: its own name). Writes
worklist_r10a.py (rows that have a name: through apply_hand_worklist.py) and new_r10a.json (DAT_ rows: through
apply_r10a_new.py). usage: gen_r10a.py <cpp> <global_variables.csv> <out dir>"""
import collections
import json
import os
import re
import sys

cpp_path, gv_path, out_dir = sys.argv[1:]
text = open(cpp_path).read()
func_at = [(m.start(), m.group(1)) for m in re.finditer(r"^// Function: (\S+) @", text, re.M)]


def func_of(pos):
    name = None
    for start, f in func_at:
        if start > pos:
            break
        name = f
    return name


uses = collections.defaultdict(lambda: (set(), set()))
for m in re.finditer(r"(lookupTableInterpolation|cm848_dualAxisTableInterpolation)\s*\(\s*&(\w+)\s*,([^;]*?)\)\s*;", text, re.S):
    tables = re.findall(r"\b([a-z0-9_]+?_(?:x_axis|axis|values|grid))\b", m.group(3))
    if tables:
        uses[m.group(2)][0].add(tables[-1])
        uses[m.group(2)][1].add(func_of(m.start()))
rows = {}
for line in open(gv_path):
    mm = re.match(r"^(0x[0-9a-f]{8}),([^,]*),([^,]*),?(.*)$", line.rstrip("\n"))
    if mm:
        rows.setdefault(mm.group(2) or f"DAT_{mm.group(1)[2:]}", mm.group(1))
want = ("transmission_", "governor_pressure_", "exhaust_brake_")
picked = {}
for cache, (tables, funcs) in uses.items():
    if not (re.match(r"^(protection_|DAT_|WORD_)", cache) or "protection" in cache):
        continue
    if any(t.startswith(want) for t in tables):
        picked[cache] = (sorted(tables), sorted(funcs))
by_table = collections.defaultdict(list)
for cache, (tables, funcs) in picked.items():
    if len(tables) == 1:
        by_table[tables[0]].append(cache)
names = {}
for table, caches in by_table.items():
    base = re.sub(r"_(values|grid)$", "", table)
    # the first by address keeps the plain name
    def addr(c):
        return int(c[4:], 16) if c.startswith("DAT_") else int(rows.get(c, "0xffffffff"), 16)
    for k, c in enumerate(sorted(caches, key=addr)):
        names[c] = base + "_interp_state" + ("" if k == 0 else f"_{k + 1}")
for cache, (tables, funcs) in picked.items():
    if len(tables) == 2 and all("exhaust_brake_unlock_maximum_throttle" in t for t in tables):
        names[cache] = "transmission_exhaust_brake_unlock_maximum_throttle_interp_state"
existing = set(rows)
named, new = [], []
for cache, new_name in sorted(names.items()):
    assert new_name not in existing, new_name
    tables, funcs = picked[cache]
    role = (f"Lookup cache (the last axis segment offset) of {' and '.join(tables)}: "
            f"{' / '.join(funcs)} passes it to the table lookup")
    if len(tables) == 2:
        role += "; one cache word serves both lookups"
    if cache.startswith("DAT_"):
        new.append(("0x" + cache[4:].lower().rjust(8, "0"), new_name, role))
    else:
        named.append((rows[cache], new_name, role))
with open(os.path.join(out_dir, "worklist_r10a.py"), "w") as f:
    f.write('"""Round 10 stage A (label-only): the RE table lookup caches named after their tables (gen_r10a.py)."""\n')
    f.write("GLOBALS = [\n")
    for a, n, r in sorted(named):
        f.write(f"    ({a!r}, {n!r},\n     {r!r}),\n")
    f.write("]\nFUNCTIONS = []\n")
json.dump(sorted(new), open(os.path.join(out_dir, "new_r10a.json"), "w"), indent=1)
print(len(named), "named rows,", len(new), "DAT_ rows")

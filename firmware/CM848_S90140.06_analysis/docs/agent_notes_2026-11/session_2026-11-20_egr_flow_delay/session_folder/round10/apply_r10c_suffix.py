"""Round 10 stage C (label-only), part 1: spell out the lookup cache suffix. Every lookup cache word is named
<table>_cached_axis_offset (41 rows already were); the 103 <table>_interp_state and 24 <table>_interpolation_state
rows (interp is an invented short form) take that suffix, and the seven word[2] 2-D grid caches take
_cached_axis_offsets. A numbered suffix keeps its number; a name already taken gets the next free number. String edits
only (global_variables.csv takes commas unquoted); the comment gets ' (was <old>)'.
usage: apply_r10c_suffix.py <repo> <map.csv> [--dry-run]"""
import os
import re
import sys

repo, map_path = os.path.abspath(sys.argv[1]), sys.argv[2]
dry = "--dry-run" in sys.argv
p = os.path.join(repo, "firmware", "CM848_S90140.06_analysis", "output", "global_variables.csv")
lines = open(p).read().split("\n")
ROW = re.compile(r"^(0x[0-9a-f]{8}),([^,]*),([^,]*),?(.*)$")
taken = set()
for l in lines:
    m = ROW.match(l)
    if m and m.group(2):
        taken.add(m.group(2))
SUFFIX = re.compile(r"^(?P<base>[a-z0-9_]+?)_(?:interp_state|interpolation_state)(?:_(?P<n>\d+))?$")
plan = []
for i, l in enumerate(lines):
    m = ROW.match(l)
    if not m:
        continue
    s = SUFFIX.match(m.group(2))
    if not s:
        continue
    plan.append((i, m.group(1), m.group(2), m.group(3), m.group(4), s.group("base"), s.group("n")))
renamed = {}
# numbered names first, so 'x_interp_state' cannot take a number a 'x_interp_state_2' keeps
BASE_FIX = {"coolant_temp": "coolant_temperature", "injection_timing_min_fuel": "injection_timing_minimum_fuel"}
for i, addr, old, typ, comment, base, n in sorted(plan, key=lambda r: (r[6] is None, r[1])):
    base = BASE_FIX.get(base, base)
    stem = base +("_cached_axis_offsets" if typ.startswith("word[") else "_cached_axis_offset")
    new = stem + (f"_{n}" if n else "")
    k = int(n) if n else 1
    while new in taken:
        k += 1
        new = f"{stem}_{k}"
    taken.add(new)
    taken.discard(old)
    renamed[i] = (addr, old, new, typ, comment)
maps = []
for i, (addr, old, new, typ, comment) in sorted(renamed.items()):
    lines[i] = ",".join([addr, new, typ, (comment + f" (was {old})").lstrip()])
    maps.append(f"{addr},{new},{old},global")
    if dry:
        print(addr, old, "->", new)
if not dry:
    open(p, "w").write("\n".join(lines))
    with open(map_path, "a") as f:
        f.write("\n".join(maps) + "\n")
print(len(renamed), "rows renamed;", sum(1 for v in renamed.values() if v[2].endswith("s") or "_offsets_" in v[2]),
      "grid caches")

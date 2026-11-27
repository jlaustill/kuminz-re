"""List the lookup cache words (the first argument of lookupTableInterpolation / cm848_dualAxisTableInterpolation) that
still carry a protection_* / DAT_ / WORD_ name, with the table each one serves and the calling functions.
usage: list_caches.py <cpp> [prefix filter for the table names, comma separated]"""
import collections
import re
import sys

cpp_path = sys.argv[1]
want = tuple(sys.argv[2].split(",")) if len(sys.argv) > 2 else ("transmission_", "governor_pressure_", "exhaust_brake_")
text = open(cpp_path).read()
func_at = []
for m in re.finditer(r"^// Function: (\S+) @", text, re.M):
    func_at.append((m.start(), m.group(1)))


def func_of(pos):
    name = None
    for start, f in func_at:
        if start > pos:
            break
        name = f
    return name


by_cache = collections.defaultdict(lambda: (set(), set()))
for m in re.finditer(r"(lookupTableInterpolation|cm848_dualAxisTableInterpolation)\s*\(\s*&(\w+)\s*,([^;]*?)\)\s*;", text, re.S):
    cache, args = m.group(2), m.group(3)
    tables = re.findall(r"\b([a-z0-9_]+?_(?:x_axis|axis|values|grid))\b", args)
    base = tables[-1] if tables else "?"
    by_cache[cache][0].add(base)
    by_cache[cache][1].add(func_of(m.start()))
n = 0
for cache, (tables, funcs) in sorted(by_cache.items()):
    if not re.match(r"^(protection_|DAT_|WORD_)", cache) and "protection" not in cache:
        continue
    if not any(t.startswith(want) for t in tables):
        continue
    n += 1
    print(f"{cache:48s} {sorted(tables)} {sorted(funcs)}")
print(n, "caches")

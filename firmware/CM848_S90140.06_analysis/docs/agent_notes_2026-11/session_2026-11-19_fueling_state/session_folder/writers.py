"""For each global: its CSV row (address / type / comment start) and every line that assigns it, with the function.
usage: writers.py <output dir> <name>..."""
import csv
import re
import sys

out = sys.argv[1]
rows = {}
with open(f"{out}/global_variables.csv") as f:
    for line in f:
        parts = line.rstrip("\n").split(",", 3)
        if len(parts) >= 3 and parts[0].startswith("0x"):
            rows.setdefault(parts[1], parts)
cpp = open(f"{out}/cm848_rom.ghidra.cpp").read().split("\n")
func = None
owners = []
for line in cpp:
    m = re.match(r"^// Function: (\S+) @ (0x[0-9a-f]+)", line)
    if m:
        func = f"{m.group(1)}@{m.group(2)}"
    owners.append(func)
for name in sys.argv[2:]:
    r = rows.get(name)
    desc = f"{r[0]} {r[2]} | {(r[3] if len(r) > 3 else '')[:160]}" if r else "no row"
    print(f"== {name}: {desc}")
    pat = re.compile(rf"(?<![\w.]){re.escape(name)}(\.\w+)?\s*=(?!=)")
    hits = [(n, owners[n], line.strip()) for n, line in enumerate(cpp) if pat.search(line)]
    for n, owner, text in hits[:8]:
        print(f"   {n + 1} [{owner}] {text[:110]}")
    if len(hits) > 8:
        print(f"   ... {len(hits) - 8} more")

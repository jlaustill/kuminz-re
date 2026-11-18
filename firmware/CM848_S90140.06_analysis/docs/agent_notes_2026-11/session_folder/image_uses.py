"""For each global row in an address range, count .cpp lines that use it per function."""
import re
import sys
from collections import defaultdict

cpp_path, globals_csv, start, end = sys.argv[1], sys.argv[2], int(sys.argv[3], 16), int(sys.argv[4], 16)
rows = []
for line in open(globals_csv):
    parts = line.rstrip("\n").split(",", 3)
    if parts[0].startswith("0x") and start <= int(parts[0], 16) <= end:
        rows.append((int(parts[0], 16), parts[1], parts[2] if len(parts) > 2 else ""))
lines = open(cpp_path).read().split("\n")
func = "?"
by_name = defaultdict(lambda: defaultdict(int))
header = re.compile(r"^// Function: (\S+) @")
for text in lines:
    m = header.match(text)
    if m:
        func = m.group(1)
        continue
    if text.lstrip().startswith(("/*", "*")):
        continue
    for _, name, _ in rows:
        base = name.split(".")[0]
        if re.search(r"(?<![A-Za-z0-9_])" + re.escape(name) + r"(?![A-Za-z0-9_])", text):
            by_name[name][func] += 1
for addr, name, typ in rows:
    uses = by_name.get(name, {})
    total = sum(uses.values())
    detail = ", ".join(f"{f}:{n}" for f, n in sorted(uses.items(), key=lambda kv: -kv[1]))
    print(f"0x{addr:06x} byte {addr - start:2d} {name:40s} {typ:22s} {total:3d}  {detail[:150]}")

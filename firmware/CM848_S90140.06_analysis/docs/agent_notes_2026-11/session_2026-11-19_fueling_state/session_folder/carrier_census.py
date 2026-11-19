"""For each carrier global: its CSV row, the constants it is compared with or assigned, and any ordering compare.
usage: carrier_census.py <output dir> <name>..."""
import re
import sys
from collections import Counter

out = sys.argv[1]
rows = {}
for line in open(f"{out}/global_variables.csv"):
    parts = line.rstrip("\n").split(",", 3)
    if len(parts) >= 3 and parts[0].startswith("0x"):
        rows.setdefault(parts[1], parts)
text = open(f"{out}/cm848_rom.ghidra.cpp").read()
for name in sys.argv[2:]:
    r = rows.get(name)
    n = re.escape(name)
    consts = Counter(re.findall(rf"(?<![\w.]){n}\s*(?:==|!=|=)\s*(0x[0-9a-f]+|\d+|[A-Z][A-Z0-9_]+)\b", text))
    consts += Counter(re.findall(rf"\b(0x[0-9a-f]+|\d+)\s*(?:==|!=)\s*{n}\b", text))
    ordering = re.findall(rf"(?<![\w.]){n}\s*(?:<=?|>=?)\s*[^=<>]|[<>]=?\s*{n}\b", text)
    uses = len(re.findall(rf"(?<![\w.]){n}\b", text))
    vals = ", ".join(f"{k}x{v}" if v > 1 else k for k, v in sorted(consts.items(), key=lambda kv: kv[0]))
    print(f"== {name} [{r[0] + ' ' + r[2] if r else 'no row'}] uses={uses} ordering={len(ordering)}\n   {vals}")

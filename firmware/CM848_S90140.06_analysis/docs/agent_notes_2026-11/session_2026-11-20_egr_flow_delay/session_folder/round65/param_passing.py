"""For each named function, the calls in its body that take its first parameter (param_1) as an argument - to see
where typing that parameter could add casts.  usage: param_passing.py <repo> <name>..."""
import os
import re
import sys

repo, names = os.path.abspath(sys.argv[1]), sys.argv[2:]
text = open(os.path.join(repo, "firmware/CM848_S90140.06_analysis/output/cm848_rom.ghidra.cpp"), errors="replace").read()
for name in names:
    m = re.search(rf"^// Function: {re.escape(name)} @.*?(?=^// Function: )", text, re.M | re.S)
    if not m:
        print(f"{name}: not found")
        continue
    body = " ".join(m.group(0).split("*/", 1)[-1].split())
    calls = sorted(set(re.findall(r"(\w+)\s*\([^()]*\bparam_1\b[^()]*\)", body)) - {"if", "while", "for", "return"})
    print(f"{name}: param_1 passed to {calls}")

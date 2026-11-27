"""List the functions in the CM848 .cpp whose bodies call each named function (by a 'name(' or wrapped 'name\\n(' call).
usage: callers.py <repo> <name>..."""
import os
import re
import sys

repo, names = os.path.abspath(sys.argv[1]), sys.argv[2:]
cpp = open(os.path.join(repo, "firmware/CM848_S90140.06_analysis/output/cm848_rom.ghidra.cpp"), errors="replace").read()
blocks = re.split(r"^// Function: ", cpp, flags=re.M)[1:]
for name in names:
    found = []
    for block in blocks:
        owner = block.split(" @ ", 1)[0]
        body = block.split("*/", 1)[-1] if "/*" in block.split("\n{", 1)[0] else block
        if owner != name and re.search(rf"\b{re.escape(name)}\s*\(", body):
            found.append(owner)
    print(f"{name}: {len(found)} callers: {' / '.join(found)}")

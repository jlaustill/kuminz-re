"""Skeptic pass 2 (read-only): print one function's decompilation from a Ghidra .cpp export, by name or by address.
usage: sk2_func.py <cpp> <name | 0xaddr> [max lines]"""
import re
import sys

cpp = open(sys.argv[1], errors="replace").read().split("\n")
key = sys.argv[2]
limit = int(sys.argv[3]) if len(sys.argv) > 3 else 400
starts = [i for i, l in enumerate(cpp) if l.startswith("// Function: ")]
for n, i in enumerate(starts):
    m = re.match(r"^// Function: (\S+) @ 0x([0-9a-fA-F]+)", cpp[i])
    if not m:
        continue
    if m.group(1) == key or (key.lower().startswith("0x") and int(m.group(2), 16) == int(key, 16)):
        end = starts[n + 1] if n + 1 < len(starts) else len(cpp)
        body = cpp[i:end]
        print("\n".join(body[:limit]))
        if len(body) > limit:
            print("... (%d more lines)" % (len(body) - limit))
        break
else:
    print("not found:", key)

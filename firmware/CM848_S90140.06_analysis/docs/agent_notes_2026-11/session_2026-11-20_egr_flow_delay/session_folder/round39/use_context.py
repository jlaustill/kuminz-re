"""Round 39 stage C: the .cpp lines around the first uses of each global (code lines only), with the function name.
usage: use_context.py <cpp> <lines before> <lines after> <name>..."""
import re
import sys

lines = open(sys.argv[1], errors="replace").read().split("\n")
before, after = int(sys.argv[2]), int(sys.argv[3])
func = []
cur = None
for l in lines:
    m = re.match(r"^// Function: (\S+) @", l)
    if m:
        cur = m.group(1)
    func.append(cur)
for name in sys.argv[4:]:
    shown = 0
    for i, l in enumerate(lines):
        if re.search(r"\b" + re.escape(name) + r"\b", l) and not l.lstrip().startswith(("/*", "*", "//")):
            print(f"--- {name} in {func[i]} (line {i + 1})")
            for k in range(max(0, i - before), min(len(lines), i + after + 1)):
                print("   " + lines[k][:150])
            shown += 1
            if shown >= 2:
                break

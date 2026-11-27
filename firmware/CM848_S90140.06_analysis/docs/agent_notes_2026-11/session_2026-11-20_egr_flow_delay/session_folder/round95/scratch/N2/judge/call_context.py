"""Print every lookupTableInterpolation call in the frozen CM550 decompilation with its function and the lines
around it. usage: python3 call_context.py > call_context_out.txt"""
import re

F = "/home/linux/.claude/jobs/374b0424/tmp/w15/r95/frozen/cm550/J90350.00.ghidra.cpp"
lines = open(F, errors="replace").read().split("\n")
func = None
count = 0
for i, ln in enumerate(lines):
    m = re.match(r"// Function: (\S+) @ (\S+)", ln)
    if m:
        func = (m.group(1), m.group(2))
        continue
    if "lookupTableInterpolation" in ln and func and func[0] != "lookupTableInterpolation" and not ln.lstrip().startswith(("//", "*", "/*")):
        count += 1
        print(f"--- {count}: {func[0]} @ {func[1]} (line {i + 1})")
        for j in range(max(0, i - 4), min(len(lines), i + 4)):
            print(("> " if j == i else "  ") + lines[j][:170])
print("TOTAL", count)

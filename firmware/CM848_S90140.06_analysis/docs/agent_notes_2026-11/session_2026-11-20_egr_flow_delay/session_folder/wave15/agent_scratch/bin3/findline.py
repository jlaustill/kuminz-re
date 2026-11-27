"""usage: findline.py <name> [<name> ...]  -- every .cpp line that uses the name (word match), with its enclosing function.
Prints:  <function>: <stripped line>   (line number in brackets)"""
import re
import sys

CPP = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM848_S90140.06_analysis/output/cm848_rom.ghidra.cpp"
lines = open(CPP, errors="replace").read().split("\n")
current = None
fn_of = []
for line in lines:
    m = re.match(r"^// Function: (\S+) @", line)
    if m:
        current = m.group(1)
    fn_of.append(current)
for name in sys.argv[1:]:
    pat = re.compile(r"(?<![A-Za-z0-9_])" + re.escape(name) + r"(?![A-Za-z0-9_])")
    print(f"=== {name}")
    for i, line in enumerate(lines):
        if pat.search(line):
            print(f"[{i + 1}] {fn_of[i]}: {line.strip()}")

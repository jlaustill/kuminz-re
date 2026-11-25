"""List every decompiled call of lookupTableInterpolation with its enclosing function (read-only)."""
import re

cpp = "/home/linux/.claude/jobs/374b0424/tmp/w15/r95/frozen/cm550/J90350.00.ghidra.cpp"
fn = None
n = 0
for line in open(cpp, errors="replace"):
    m = re.match(r"// Function: (\S+) @ (\S+)", line)
    if m:
        fn = f"{m.group(1)} @ {m.group(2)}"
        continue
    if "lookupTableInterpolation" not in line:
        continue
    s = line.strip()
    if s.startswith(("short lookupTableInterpolation", "word lookupTableInterpolation")):
        continue
    hits = len(re.findall(r"lookupTableInterpolation\s*\(", line))
    if hits:
        for _ in range(hits):
            n += 1
        print(f"{n:3d} x{hits} [{fn}] {s[:170]}")
    else:
        print(f"    (other) [{fn}] {s[:170]}")

"""usage: rows.py 0xLO 0xHI   -> print global_variables.csv rows with LO <= address <= HI"""
import csv, sys
OUT = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-fueling-state-enum/firmware/CM848_S90140.06_analysis/output/"
lo, hi = int(sys.argv[1], 16), int(sys.argv[2], 16)
width = int(sys.argv[3]) if len(sys.argv) > 3 else 300
for line in open(OUT + "global_variables.csv", errors="replace"):
    if not line.startswith("0x"):
        continue
    parts = (line.rstrip("\n").split(",", 3) + [""])[:4]
    a = int(parts[0], 16)
    if lo <= a <= hi:
        print(f"{parts[0]} {parts[1]} [{parts[2]}] {parts[3][:width]}")

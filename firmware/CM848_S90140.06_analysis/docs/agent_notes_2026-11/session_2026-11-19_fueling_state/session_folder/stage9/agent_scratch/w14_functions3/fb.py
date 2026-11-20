"""usage: fb.py name[:max] ...  -- print function bodies from the CM848 .cpp (wraps the session's fnbody.py)"""
import subprocess
import sys

CPP = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-fueling-state-enum/firmware/CM848_S90140.06_analysis/output/cm848_rom.ghidra.cpp"
FNBODY = "/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/fnbody.py"
sys.stdout.write(subprocess.run(["python3", FNBODY, CPP] + sys.argv[1:], capture_output=True, text=True).stdout)

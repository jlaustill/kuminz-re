"""usage: check_names.py name...   -> where each name already occurs (word boundary) in the CSVs and the .cpp"""
import re
import sys

OUT = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM848_S90140.06_analysis/output/"
FILES = ["global_variables.csv", "structure_definitions.csv", "function_renames.csv", "enums.csv",
         "local_variables.csv", "arrays.csv", "constants.csv", "labels.csv", "function_definitions.csv",
         "cm848_rom.ghidra.cpp", "firmware_globals.hpp", "firmware_functions.hpp", "firmware_types.hpp"]
texts = {}
for f in FILES:
    try:
        texts[f] = open(OUT + f, errors="replace").read()
    except OSError:
        texts[f] = ""
for name in sys.argv[1:]:
    pattern = re.compile(r"(?<![A-Za-z0-9_])" + re.escape(name) + r"(?![A-Za-z0-9_])")
    hits = {f: len(pattern.findall(t)) for f, t in texts.items() if pattern.search(t)}
    print(f"{name}: {'FREE' if not hits else hits}")

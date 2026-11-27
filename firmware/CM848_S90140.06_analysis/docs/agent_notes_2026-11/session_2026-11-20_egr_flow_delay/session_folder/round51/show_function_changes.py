"""Print the changed lines of named functions between two .cpp copies.
usage: show_function_changes.py <old.cpp> <new.cpp> <function>..."""
import difflib
import re
import sys


def functions(path):
    t = open(path, errors="replace").read()
    return {m.group(1): m.group(0) for m in re.finditer(r"^// Function: (\S+) @.*?(?=^// Function: |\Z)", t, re.S | re.M)}


old, new = functions(sys.argv[1]), functions(sys.argv[2])
for f in sys.argv[3:]:
    lines = [l for l in difflib.unified_diff(old[f].splitlines(), new[f].splitlines(), lineterm="", n=0)
             if l[:1] in "+-" and not l.startswith(("+++", "---"))]
    print(f"== {f}: {len(lines)} changed lines")
    for l in lines[:30]:
        print("  " + l[:150])

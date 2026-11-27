"""Gate for round 24 stage A (comments only): the .cpp's code with comments stripped is identical, and every changed
CSV line differs only in its comment column (the address / name / type columns are untouched).
usage: prove_r24a.py <old.cpp> <new.cpp> <repo> <base git ref>"""
import io
import csv
import re
import subprocess
import sys

old_cpp, new_cpp, repo, ref = sys.argv[1:5]


def code_only(text):
    text = re.sub(r"/\*.*?\*/", "", text, flags=re.S)
    return [l.rstrip() for l in re.sub(r"//[^\n]*", "", text).split("\n") if l.strip()]


a, b = code_only(open(old_cpp).read()), code_only(open(new_cpp).read())
print("code-only .cpp identical:", a == b, f"({len(a)} lines)")
KEEP = {"global_variables.csv": 3, "function_renames.csv": 2, "structure_definitions.csv": 5, "enums.csv": 3}
problems = 0
for name, col in KEEP.items():
    path = f"firmware/CM848_S90140.06_analysis/output/{name}"
    old = subprocess.run(["git", "-C", repo, "show", f"{ref}:{path}"], capture_output=True, text=True).stdout.split("\n")
    new = open(f"{repo}/{path}").read().split("\n")
    if len(old) != len(new):
        print(name, "line count changed", len(old), len(new))
        problems += 1
        continue
    changed = 0
    for o, n in zip(old, new):
        if o == n:
            continue
        changed += 1
        if name in ("global_variables.csv", "function_renames.csv"):
            fo, fn = o.split(",", col), n.split(",", col)
        else:
            fo, fn = next(csv.reader(io.StringIO(o))), next(csv.reader(io.StringIO(n)))
        if fo[:col] != fn[:col] or (name not in ("global_variables.csv", "function_renames.csv") and fo[col + 1:] != fn[col + 1:]):
            print(name, "non-comment change:", o[:80])
            problems += 1
    print(name, changed, "lines changed, comment column only" if not problems else "")
print("GATE PASS" if a == b and not problems else "GATE FAIL")

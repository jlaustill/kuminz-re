"""Round 93 (read-only): the counts for the closing notes - CM550 function rows and placeholder names, global row
types, .cpp lines, before (the commit before the round, read with git show) and now.
usage: round_counts_r93.py <repo> <base commit>"""
import collections
import re
import subprocess
import sys

repo, base = sys.argv[1], sys.argv[2]
O = "firmware/CM550_J90350.00_analysis/output/"


def show(rel):
    return subprocess.run(["git", "-C", repo, "show", f"{base}:{O}{rel}"], capture_output=True, text=True, errors="replace").stdout


def now(rel):
    return open(f"{repo}/{O}{rel}", newline="", errors="replace").read()


for label, get in (("before", show), ("now", now)):
    names = [l.split(",")[1] for l in get("function_renames.csv").split("\n") if l.startswith("0x")]
    placeholders = [n for n in names if re.match(r"^[a-z0-9]+_FUN_[0-9a-f]{8}$", n)]
    types = collections.Counter(l.split(",")[2] for l in get("global_variables.csv").split("\n") if l.startswith("0x") and l.count(",") >= 2)
    cpp = get("J90350.00.ghidra.cpp")
    print(f"{label}: {len(names)} function rows, {len(placeholders)} placeholder names, {len(set(names))} distinct names; "
          f"globals undefined {types['undefined']}, word {types['word']}, byte {types['byte']}, dword {types['dword']}, i16 {types['i16']}, i32 {types['i32']}; "
          f".cpp {cpp.count(chr(10))} lines, {len(re.findall(r'^// Function: ', cpp, re.M))} functions")

"""Diff the code of named functions between two .cpp files with comments stripped and whitespace collapsed.
usage: fn_code_diff.py old.cpp new.cpp NAME [NAME...]"""
import difflib
import re
import sys


def functions(path):
    text = open(path).read()
    out = {}
    for chunk in re.split(r"(?m)^(?=// Function: )", text):
        m = re.match(r"// Function: (\S+)", chunk)
        if m:
            code = re.sub(r"/\*.*?\*/", " ", chunk, flags=re.S)
            code = re.sub(r"//[^\n]*", " ", code)
            out[m.group(1)] = [re.sub(r"\s+", " ", line).strip() for line in code.split("\n") if line.strip()]
    return out


old, new = functions(sys.argv[1]), functions(sys.argv[2])
for name in sys.argv[3:]:
    print(f"== {name}")
    a, b = old.get(name, []), new.get(name, [])
    for d in difflib.unified_diff(a, b, lineterm="", n=0):
        if d[:3] not in ("---", "+++") and not d.startswith("@@"):
            print("  " + d[:200])

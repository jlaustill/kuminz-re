"""Print functions' decompiled code without the plate comment and blank lines, and without filtering any code line
(round 67: the declaration filters used before also hid 'return xVarN;' and every deeper-indented line).
usage: body.py <cpp> <function> [<function> ...]"""
import re
import sys

text = open(sys.argv[1], errors="replace").read()
for name in sys.argv[2:]:
    m = re.search(rf"^// Function: {re.escape(name)} @[^\n]*\n(.*?)(?=^// Function: |\Z)", text, flags=re.M | re.S)
    if not m:
        print(f"=== {name}: not found")
        continue
    body = re.sub(r"/\*.*?\*/\n?", "", m.group(1), flags=re.S)
    print(f"=== {name}")
    for line in body.split("\n"):
        if line.strip() and line.strip() != "//":
            print(line[:140])

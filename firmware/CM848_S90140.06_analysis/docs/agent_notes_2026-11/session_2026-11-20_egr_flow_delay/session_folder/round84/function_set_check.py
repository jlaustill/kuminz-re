"""Compare two decompilations function by function: the functions removed / added, and - for the functions in both -
the ones whose body differs after the comments are stripped and the rename map is applied.
usage: function_set_check.py <old cpp> <new cpp> <map.csv>"""
import csv
import difflib
import re
import sys


def functions(path, renames):
    text = open(path, errors="replace").read()
    text = re.sub(r"/\*.*?\*/", "", text, flags=re.S)
    text = re.sub(r"//[^\n]*", lambda m: m.group(0) if m.group(0).startswith("// Function:") else "", text)
    for old, new in renames:
        text = re.sub(rf"\b{re.escape(old)}\b", new, text)
    parts = re.split(r"^// Function: (\S+) @ (0x[0-9a-f]+)[^\n]*\n", text, flags=re.M)
    return {parts[i + 1]: (parts[i], [l.rstrip() for l in parts[i + 2].split("\n") if l.strip()])
            for i in range(1, len(parts), 3)}


renames = [(r["old_label"], r["name"]) for r in csv.DictReader(open(sys.argv[3]))]
old, new = functions(sys.argv[1], renames), functions(sys.argv[2], [])
removed = sorted(set(old) - set(new))
added = sorted(set(new) - set(old))
print(f"removed {len(removed)}:", ", ".join(f"{a} {old[a][0]}" for a in removed))
print(f"added {len(added)}:", ", ".join(f"{a} {new[a][0]}" for a in added))
changed = []
for address in sorted(set(old) & set(new)):
    a, b = old[address], new[address]
    if a != b:
        diff = [l for l in difflib.unified_diff([a[0]] + a[1], [b[0]] + b[1], lineterm="", n=0)
                if l[:1] in "+-" and not l.startswith(("+++", "---"))]
        changed.append((address, b[0], diff))
print(f"changed {len(changed)}")
for address, name, diff in changed:
    print(f"  {address} {name}: {len(diff)} lines")
    for line in diff[:24]:
        print("     ", line[:150])

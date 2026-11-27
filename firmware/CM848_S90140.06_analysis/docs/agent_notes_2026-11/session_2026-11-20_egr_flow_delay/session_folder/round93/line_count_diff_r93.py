"""Round 93 proof detail (read-only): functions (by address) whose number of code lines or of statements (';')
differs between two decompilations - a type change should re-word lines, not add or drop statements.
For each such function a short unified diff. usage: line_count_diff_r93.py <before.cpp> <after.cpp>"""
import difflib
import re
import sys


def functions(path):
    text = open(path, errors="replace").read()
    out = {}
    for m in re.finditer(r"^// Function: (\w+) @ (0x[0-9a-f]+)\n(.*?)(?=^//\n// Function: |^// Function: |\Z)", text, re.M | re.S):
        body = re.sub(r"/\*.*?\*/", "", m.group(3), flags=re.S)
        lines = [l.rstrip() for l in body.split("\n") if l.strip() and not l.strip().startswith("//")]
        out[int(m.group(2), 16)] = (m.group(1), lines)
    return out


before, after = functions(sys.argv[1]), functions(sys.argv[2])
n = 0
for a in sorted(set(before) & set(after)):
    b, c = before[a][1], after[a][1]
    sb, sc = sum(l.count(";") for l in b), sum(l.count(";") for l in c)
    if sb == sc:
        continue
    n += 1
    print(f"0x{a:05x} {after[a][0]}: statements {sb} -> {sc}, lines {len(b)} -> {len(c)}")
    for l in list(difflib.unified_diff(b, c, lineterm="", n=0))[2:16]:
        print("     " + l[:160])
print(n, "functions with a different statement count")

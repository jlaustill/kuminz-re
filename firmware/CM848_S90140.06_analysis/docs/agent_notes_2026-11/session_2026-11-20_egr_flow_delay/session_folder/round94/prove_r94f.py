"""Round 94 stage F proof (cleanups): split both .cpp files into functions (by their '// Function: name @ address'
header) and compare them. Every function outside the expected set must be byte-identical (the definition name sync
and the overlap row removals must not change the decompilation). For the expected functions (their local rows were
re-targeted) print the statement counts (lines ending in ';') and the diff. usage:
prove_r94f.py <before.cpp> <after.cpp> <expected function address>..."""
import difflib
import re
import sys

before, after, expected = sys.argv[1], sys.argv[2], {int(a, 16) for a in sys.argv[3:]}
HEAD = re.compile(r"^// Function: (\S+) @ (0x[0-9a-fA-F]+)", re.M)


def split(path):
    text = open(path, errors="replace").read()
    marks = list(HEAD.finditer(text))
    out = {}
    for i, m in enumerate(marks):
        end = marks[i + 1].start() if i + 1 < len(marks) else len(text)
        out[int(m.group(2), 16)] = (m.group(1), text[m.start():end])
    return out


b, a = split(before), split(after)
print(f"functions: {len(b)} -> {len(a)}; removed {sorted(set(b) - set(a))}; added {sorted(set(a) - set(b))}")
changed = [x for x in sorted(set(a) & set(b)) if a[x][1] != b[x][1]]
unexpected = [x for x in changed if x not in expected]
print(f"changed: {len(changed)}; outside the expected set: {len(unexpected)} {[(hex(x), a[x][0]) for x in unexpected[:10]]}")
for x in sorted(expected):
    if x not in a or x not in b:
        print(f"0x{x:x}: missing")
        continue
    sb = sum(1 for l in b[x][1].splitlines() if l.rstrip().endswith(";"))
    sa = sum(1 for l in a[x][1].splitlines() if l.rstrip().endswith(";"))
    print(f"== 0x{x:x} {a[x][0]}: statements {sb} -> {sa}" + ("" if a[x][1] != b[x][1] else " (unchanged)"))
    for line in difflib.unified_diff(b[x][1].splitlines(), a[x][1].splitlines(), lineterm="", n=0):
        if not line.startswith(("---", "+++", "@@")):
            print("   ", line[:150])

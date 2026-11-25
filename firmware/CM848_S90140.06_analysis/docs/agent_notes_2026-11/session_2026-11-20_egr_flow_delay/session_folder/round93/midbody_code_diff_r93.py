"""Round 93 proof detail (read-only): for the functions whose code differs between two CM550 decompilations (same
address), classify the difference after normalising the decompiler's temporaries (uVar1 / iVar2 / local_x ->
numbered by first use) and the removed functions' names: SAME-AFTER-NORMALISING (only temporaries were renumbered) or
DIFFERENT, with a short unified diff for the latter. usage: midbody_code_diff_r93.py <before.cpp> <after.cpp>"""
import difflib
import re
import sys


def functions(path):
    text = open(path, errors="replace").read()
    out = {}
    for m in re.finditer(r"^// Function: (\w+) @ (0x[0-9a-f]+)\n(.*?)(?=^//\n// Function: |^// Function: |\Z)", text, re.M | re.S):
        body = re.sub(r"/\*.*?\*/", "", m.group(3), flags=re.S)
        out[int(m.group(2), 16)] = (m.group(1), [l.rstrip() for l in body.split("\n") if l.strip() and not l.strip().startswith("//")])
    return out


def normalise(lines):
    seen = {}

    def sub(m):
        return seen.setdefault(m.group(0), f"T{len(seen)}")
    text = "\n".join(lines)
    text = re.sub(r"\b(?:[a-z]{1,3}Var\d+|local_[0-9a-f]+|[a-z]+Stack_[0-9a-f]+|in_[A-Za-z0-9_]+|unaff_[A-Za-z0-9_]+|extraout_[A-Za-z0-9_]+)\b", sub, text)
    decls = sorted(l for l in text.split("\n") if re.match(r"^\s+[\w ]+\*?\s*\*?T\d+;$", l))
    rest = [l for l in text.split("\n") if not re.match(r"^\s+[\w ]+\*?\s*\*?T\d+;$", l)]
    return decls, rest


before, after = functions(sys.argv[1]), functions(sys.argv[2])
same = different = 0
for a in sorted(set(before) & set(after)):
    if before[a][1] == after[a][1]:
        continue
    b, c = normalise(before[a][1]), normalise(after[a][1])
    if b[1] == c[1]:
        same += 1
        print(f"SAME-AFTER-NORMALISING 0x{a:05x} {after[a][0]} ({len(after[a][1])} lines)")
        continue
    different += 1
    print(f"DIFFERENT 0x{a:05x} {after[a][0]}: {len(before[a][1])} -> {len(after[a][1])} lines")
    for l in list(difflib.unified_diff(b[1], c[1], lineterm="", n=0))[2:14]:
        print("     " + l[:150])
print(f"{same} functions differ only in temporaries; {different} differ in code")

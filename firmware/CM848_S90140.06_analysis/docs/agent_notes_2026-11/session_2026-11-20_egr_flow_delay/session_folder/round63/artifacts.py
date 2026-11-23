"""Count decompiler artifacts (CONCAT / in_register / extraout / unaff_ / SUB4x) per function in two .cpp files and
print the functions where the count changed.  usage: artifacts.py <old.cpp> <new.cpp>"""
import re
import sys

ART = re.compile(r"\b(?:CONCAT\d+|in_register_\w+|extraout_\w+|unaff_\w+|SUB\d+|ZEXT\d+|SEXT\d+)\b")


def per_function(path):
    out = {}
    text = open(path, errors="replace").read()
    for block in re.split(r"^// Function: ", text, flags=re.M)[1:]:
        name = block.split(" @ ", 1)[0]
        body = block.split("*/", 1)[-1] if "/*" in block[:600] else block
        out[name] = len(ART.findall(body))
    return out


a, b = per_function(sys.argv[1]), per_function(sys.argv[2])
changed = [(n, a.get(n, 0), b.get(n, 0)) for n in sorted(set(a) | set(b)) if a.get(n, 0) != b.get(n, 0)]
for name, x, y in changed:
    print(f"{name}: {x} -> {y}")
print("functions with a changed artifact count:", len(changed))

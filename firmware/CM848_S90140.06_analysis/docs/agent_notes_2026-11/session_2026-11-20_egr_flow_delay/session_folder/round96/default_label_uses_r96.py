"""Round 96 (read-only): every line that uses a default-labelled struct instance (<type>_<address>, an instance with no
row name), with the enclosing function, so each one can be named from its use. usage: default_label_uses_r96.py <cpp> [label...]"""
import re
import sys

cpp = open(sys.argv[1], errors="replace").read().split("\n")
labels = sys.argv[2:]
if not labels:
    labels = sorted({m for l in cpp for m in re.findall(r"\b[a-z][a-z0-9_]*_t_00[0-9a-f]{6}\b", l)})
current = "?"
hits = {l: [] for l in labels}
for i, line in enumerate(cpp):
    m = re.match(r"^// Function: (\S+) @", line)
    if m:
        current = m.group(1)
    for lab in labels:
        if lab in line and not line.lstrip().startswith(("/*", "*")) and "Function:" not in line:
            context = line.strip()
            if context.endswith(",") or context.endswith("("):
                context += " " + cpp[i + 1].strip()
            hits[lab].append(f"{current}: {context[:150]}")
for lab, lines in hits.items():
    print(f"== {lab} ({len(lines)})")
    for l in lines[:6]:
        print("   ", l)

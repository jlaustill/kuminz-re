"""The real code differences of the named functions, after the reversal (reverse_names.py --write-reversed): comments
stripped, goto labels canonical, and Ghidra's auto-named locals (iVar1, uVar2, wVar3, pbVar13, local_44, uStack_32,
...) renumbered by first appearance within each function, so a local that appears or disappears does not renumber the
rest. Prints the remaining changed lines per function, and the functions that become equal.
usage: real_code_diffs.py <old.cpp> <reversed new.cpp> <repo> [function...]"""
import difflib
import re
import sys

old_path, new_path, repo, names = sys.argv[1], sys.argv[2], sys.argv[3], sys.argv[4:]
sys.path.insert(0, f"{repo}/firmware/scripts/rename_waves")
from common import canonical_labels, strip_comments, strip_generated_header  # noqa: E402

AUTO = re.compile(r"\b(?:[a-z]{1,3}Var\d+|local_[0-9a-f]+|[a-z]{1,3}Stack_[0-9a-f]+|extraout_\w+|in_\w+)\b")


def functions(path, stripped):
    text = strip_generated_header(open(path, errors="replace").read())
    if not stripped:
        text = canonical_labels(strip_comments(text))
    out = {}
    for chunk in re.split(r"(?m)^(?=// Function: )", text):
        m = re.match(r"// Function: (\S+)", chunk)
        if not m:
            continue
        seen, counts = {}, {}

        def rename(v):
            name = v.group(0)
            if name not in seen:
                kind = re.sub(r"\d+$|_[0-9a-f]+$", "", name)
                counts[kind] = counts.get(kind, 0) + 1
                seen[name] = f"{kind}{counts[kind]}"
            return seen[name]
        body = AUTO.sub(rename, chunk)
        lines = [l.strip() for l in body.split("\n") if l.strip()]
        out[m.group(1)] = [l for l in lines if not re.match(r"^[A-Za-z_][\w ]*[\w\*]\s*\**[A-Za-z_]\w*(\[\d+\])?;$", l)]
    return out


old, new = functions(old_path, False), functions(new_path, True)
names = names or sorted(n for n in old if n in new and old[n] != new[n])
for name in names:
    a, b = old.get(name, []), new.get(name, [])
    if re.sub(r"\s+", "", "".join(a)) == re.sub(r"\s+", "", "".join(b)):  # whitespace / line breaks only
        print(f"== {name}: equal after the local renumbering")
        continue
    print(f"== {name}")
    for line in difflib.unified_diff(a, b, lineterm="", n=0):
        if not line.startswith(("---", "+++", "@@")):
            print("  " + line[:170])

"""Show the code-only differences (comments stripped, goto labels canonical, declarations sorted) between an old .cpp
and a reversed new .cpp, for the named functions: each changed old / new line pair.
usage: show_code_diffs.py <old.cpp> <reversed new.cpp> <repo> <function>..."""
import difflib
import re
import sys

old_path, new_path, repo, names = sys.argv[1], sys.argv[2], sys.argv[3], sys.argv[4:]
sys.path.insert(0, f"{repo}/firmware/scripts/rename_waves")
from common import canonical_labels, strip_comments, strip_generated_header  # noqa: E402


def functions(path, stripped):
    text = strip_generated_header(open(path, errors="replace").read())
    if not stripped:
        text = canonical_labels(strip_comments(text))
    out = {}
    for chunk in re.split(r"(?m)^(?=// Function: )", text):
        m = re.match(r"// Function: (\S+)", chunk)
        if m:
            out[m.group(1)] = [l.strip() for l in chunk.split("\n") if l.strip()]
    return out


old, new = functions(old_path, False), functions(new_path, True)
for name in names:
    a, b = old.get(name, []), new.get(name, [])
    print(f"== {name}")
    for line in difflib.unified_diff(sorted(a) if False else a, b, lineterm="", n=0):
        if line.startswith(("---", "+++", "@@")):
            continue
        print("  " + line[:170])

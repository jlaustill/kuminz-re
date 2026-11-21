"""Every function whose code differs between an old .cpp and a label-reversed new .cpp, with comments and the
generated header stripped from BOTH (reverse_names.py's own report hides _N_M_ piece changes after canonicalizing).
usage: changed_functions_W15.py <repo> <old.cpp> <reversed_new.cpp>"""
import os
import re
import sys

repo = os.path.abspath(sys.argv[1])
sys.path.insert(0, os.path.join(repo, "firmware", "scripts", "rename_waves"))
from common import strip_comments, strip_generated_header  # noqa: E402


def functions(path):
    text = strip_comments(strip_generated_header(open(path, errors="replace").read()))
    out = {}
    for chunk in re.split(r"(?m)^(?=// Function: )", text):
        m = re.match(r"// Function: (\S+)", chunk)
        if m:
            out[m.group(1)] = re.sub(r"\s+", "", chunk)
    return out


old, new = functions(sys.argv[2]), functions(sys.argv[3])
changed = sorted(n for n in old if n in new and old[n] != new[n])
print(f"{len(changed)} functions differ; only in old: {len(set(old) - set(new))}; only in new: {len(set(new) - set(old))}")
for n in changed:
    print("  ", n)

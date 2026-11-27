"""Round 93 (read-only): show each spot where the working tree's CSV text differs from HEAD by a NEW name of the
given maps (so: what a refresh wrote, and the hand-written rows that cite the new names), word by word with 7 words
of context. Rows are matched by their first field (address / struct name) plus the second for the multi-row files.
With --only-refresh, rows whose name column changed are left out (those are the renamed rows themselves).
usage: review_refresh_r93.py <repo> [--only-refresh] <map.csv>... -- <csv relative path>..."""
import csv
import difflib
import re
import subprocess
import sys

args = sys.argv[1:]
repo = args.pop(0)
only = "--only-refresh" in args
if only:
    args.remove("--only-refresh")
split = args.index("--")
maps, files = args[:split], args[split + 1:]
new_names = set()
for m in maps:
    for r in csv.reader(open(m)):
        if len(r) > 2 and r[0] != "address":
            new_names.add(r[1])
for rel in files:
    base = rel.split("/")[-1]
    single = base in ("global_variables.csv", "function_renames.csv", "deleted_functions.csv")

    def keyed(text):
        out = {}
        for l in text.replace("\r\n", "\n").split("\n"):
            parts = l.split(",")
            out[parts[0] if single else ",".join(parts[:3] if base == "structure_definitions.csv" else parts[:3])] = l
        return out
    old = keyed(subprocess.run(["git", "-C", repo, "show", f"HEAD:{rel}"], capture_output=True, text=True, errors="replace").stdout)
    new = keyed(open(f"{repo}/{rel}", newline="", errors="replace").read())
    spots = 0
    for k, l in new.items():
        o = old.get(k)
        if o is None or o == l:
            continue
        if only and single and o.split(",")[1:2] != l.split(",")[1:2]:
            continue
        ow, lw = re.findall(r"[\w\[\].]+|[^\w\s]", o), re.findall(r"[\w\[\].]+|[^\w\s]", l)
        for tag, i1, i2, j1, j2 in difflib.SequenceMatcher(None, ow, lw, autojunk=False).get_opcodes():
            if tag == "equal" or not (set(lw[j1:j2]) & new_names):
                continue
            spots += 1
            print(f"{base} {k[:40]}\n      old: ...{' '.join(ow[max(0, i1 - 7):i2 + 7])}\n      new: ...{' '.join(lw[max(0, j1 - 7):j2 + 7])}")
    print(f"-- {base}: {spots} spots")

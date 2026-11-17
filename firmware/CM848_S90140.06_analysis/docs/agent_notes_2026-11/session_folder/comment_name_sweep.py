"""List identifier-shaped tokens in a diff's added lines that are not a current name anywhere.

usage: comment_name_sweep.py <repo> <base> <head>
Skips tokens inside "(was ...)" and after "was" / "were" lists; prints token, count and one context per token."""
import csv
import re
import subprocess
import sys

repo, base, head = sys.argv[1:4]
out = f"{repo}/firmware/CM848_S90140.06_analysis/output"
files = ["firmware/CM848_S90140.06_analysis/output/global_variables.csv",
         "firmware/CM848_S90140.06_analysis/output/function_renames.csv",
         "firmware/CM848_S90140.06_analysis/output/structure_definitions.csv",
         "firmware/CLAUDE.md"]
diff = subprocess.run(["git", "-C", repo, "diff", "-U0", base, head, "--"] + files,
                      capture_output=True, text=True, check=True).stdout if head != "-" else subprocess.run(["git", "-C", repo, "diff", "-U0", base, "--"] + files, capture_output=True, text=True, check=True).stdout

known = set()
for row in csv.reader(open(f"{out}/global_variables.csv")):
    if len(row) > 2:
        known.add(row[1])
        known.add(re.sub(r"\[\d+\]$", "", row[2]))
for name in ("function_renames.csv", "deleted_functions.csv"):
    for row in csv.reader(open(f"{out}/{name}")):
        if len(row) > 1:
            known.add(row[1])
for row in csv.reader(open(f"{out}/structure_definitions.csv")):
    if len(row) > 2:
        known.update((row[0], row[2]))
for row in csv.reader(open(f"{out}/enums.csv")):
    if len(row) > 2:
        known.update((row[0], row[2]))
for name in ("local_variables.csv",):
    for row in csv.reader(open(f"{out}/{name}")):
        if len(row) > 3:
            known.add(row[3])
for row in csv.reader(open(f"{out}/function_definitions.csv")):
    if len(row) > 3:
        known.add(row[3])

token = re.compile(r"\b(?:[a-z][a-z0-9]*(?:_[a-z0-9]+){2,}|(?:cm848|mpc555|hpcr|vp44|mc68k|cm550)_[A-Za-z0-9_]+)\b")
was = re.compile(r"\((?:was|were) [^)]*\)")
hits = {}
for line in diff.split("\n"):
    if not line.startswith("+") or line.startswith("+++"):
        continue
    text = was.sub("", line)
    for m in token.finditer(text):
        t = m.group(0)
        if t in known or re.sub(r"_(?:cal|[0-9]+)$", "", t) in known:
            continue
        before = text[max(0, m.start() - 60):m.start()]
        if re.search(r"\b(?:was|were)\b[^);.]*$", before):
            continue
        hits.setdefault(t, [0, text[max(0, m.start() - 70):m.end() + 30]])[0] += 1
for t, (n, ctx) in sorted(hits.items()):
    print(f"{t} x{n} | {ctx}")
print(f"-- {len(hits)} unknown tokens")

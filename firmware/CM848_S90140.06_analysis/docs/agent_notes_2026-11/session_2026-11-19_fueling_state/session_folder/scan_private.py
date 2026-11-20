"""Show what private-looking text a file holds, with context: the owner's handle / address from the local git config
(never written into this public file) plus generic token prefixes.
usage: scan_private.py <file>..."""
import re
import subprocess
import sys

email = subprocess.run(["git", "config", "user.email"], capture_output=True, text=True).stdout.strip()
parts = [re.escape(email), re.escape(email.split("@")[0])] if "@" in email else []
PATTERN = re.compile("|".join(parts + ["ghp_", "github_pat_", "sk-ant-"]), re.I)
for path in sys.argv[1:]:
    text = open(path, errors="replace").read()
    hits = {}
    for m in PATTERN.finditer(text):
        ctx = text[max(0, m.start() - 20):m.end() + 20].replace("\n", " ")
        hits[ctx] = hits.get(ctx, 0) + 1
    print(f"== {path}: {sum(hits.values())} hits")
    for ctx, n in list(hits.items())[:4]:
        print(f"   {n}x ...{ctx}...")

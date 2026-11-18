"""Count mentions of renamed identifiers (old names) in the repo docs; optionally replace them in given files.
Usage: doc_mentions.py <repo> <mapping.csv> [--replace FILE...]
A mention inside '(was `old`)' / 'was `old`' / 'were `old`' is history and is kept."""
import csv
import glob
import os
import re
import sys

repo, mapping = sys.argv[1:3]
replace = sys.argv[sys.argv.index("--replace") + 1:] if "--replace" in sys.argv else []
pairs = [(r["old_label"], r["name"]) for r in csv.DictReader(open(mapping))
         if r["old_label"] and not r["old_label"].startswith("DAT_")]
pairs.sort(key=lambda p: -len(p[0]))
files = [f for f in glob.glob(os.path.join(repo, "**", "*.md"), recursive=True)
         if "/.claude/" not in f[len(repo):] and "/node_modules/" not in f and "/insite9/decompiled/" not in f]
counts = {}
for f in files:
    t = open(f, errors="replace").read()
    n = sum(len(re.findall(rf"\b{re.escape(o)}\b", t)) for o, _ in pairs)
    if n:
        counts[os.path.relpath(f, repo)] = n
for f, n in sorted(counts.items(), key=lambda kv: -kv[1])[:20]:
    print(f"{n:4d} {f}")
HISTORY = re.compile(r"(was|were|formerly|old name)\s+`?$")
for f in replace:
    path = os.path.join(repo, f)
    t = open(path).read()
    out, total = t, 0
    for o, n in pairs:
        def sub(m):
            global total
            before = out_text[max(0, m.start() - 12):m.start()]
            if HISTORY.search(before):
                return m.group(0)
            total += 1
            return n
        out_text = out
        out = re.sub(rf"\b{re.escape(o)}\b", sub, out)
    open(path, "w").write(out)
    print(f"replaced {total} mentions in {f}")

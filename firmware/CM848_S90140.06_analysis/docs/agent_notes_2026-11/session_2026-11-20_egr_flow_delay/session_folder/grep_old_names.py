"""Repo-wide search for old names outside history: prints file:line:context for each hit that is not a history
mention ('was' / 'were' / 'earlier note' just before it) and not in an excluded path.
Usage: grep_old_names.py <repo> <names file> [exclude substring]..."""
import os
import re
import sys

repo, names_file, *excludes = sys.argv[1:]
names = [n.strip() for n in open(names_file) if n.strip()]
pat = re.compile(r"\b(" + "|".join(re.escape(n) for n in sorted(names, key=len, reverse=True)) + r")\b")
HISTORY = re.compile(r"(\bwas|\bwere|earlier note:?|formerly|old name)\s*[`(]?\s*$")
skip_dirs = {".git", "node_modules", "build", "project"}
for root, dirs, files in os.walk(repo):
    dirs[:] = [d for d in dirs if d not in skip_dirs and not d.startswith(".claude")]
    for f in files:
        path = os.path.join(root, f)
        rel = os.path.relpath(path, repo)
        if any(e in rel for e in excludes):
            continue
        try:
            text = open(path, encoding="utf-8").read()
        except (UnicodeDecodeError, OSError):
            continue
        for i, line in enumerate(text.split("\n"), 1):
            for m in pat.finditer(line):
                before = line[:m.start()]
                if HISTORY.search(before[-20:]) or re.search(r"\((was|were) [^)]*$", before):
                    continue
                print(f"{rel}:{i}: ...{line[max(0, m.start() - 50):m.end() + 30]}")

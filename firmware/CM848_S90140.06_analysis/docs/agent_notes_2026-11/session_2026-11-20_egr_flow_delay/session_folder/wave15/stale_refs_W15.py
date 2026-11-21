"""List places that still cite a stage's old names outside its "(was ...)" / "earlier note" history.
usage: stale_refs_W15.py <repo> <map csv> <file>..."""
import csv
import os
import re
import sys

repo, mapping = sys.argv[1:3]
old = {r["old_label"]: r["name"] for r in csv.DictReader(open(mapping)) if r.get("old_label")}
pattern = re.compile(r"(?<![A-Za-z0-9_])(" + "|".join(map(re.escape, sorted(old, key=len, reverse=True))) +
                     r")(?![A-Za-z0-9_])")
hits = 0
for path in sys.argv[3:]:
    for n, line in enumerate(open(os.path.join(repo, path), errors="replace"), 1):
        # drop the history parts: "(was ...)" groups and everything after "| earlier note:"
        text = re.sub(r"\| earlier note:.*", "", line)
        text = re.sub(r"\(was [^)]*\)", "", text)
        text = re.sub(r"\bwas [A-Za-z0-9_]+", "", text)
        for m in pattern.finditer(text):
            hits += 1
            if hits <= 40:
                print(f"{path}:{n}: {m.group(1)} -> {old[m.group(1)]} | {text[max(0, m.start() - 60):m.end() + 40].strip()}")
print(f"{hits} stale references")

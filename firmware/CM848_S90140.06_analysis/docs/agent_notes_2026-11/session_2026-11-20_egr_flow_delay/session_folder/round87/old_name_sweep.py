"""Round 87: where the renamed symbols' OLD names still appear. (1) "(was <new name>" history notes that a reference
refresh may have rewritten by mistake; (2) every tracked Markdown file (session archives excluded) that mentions an
old name, with file:line. usage: old_name_sweep.py <repo> <map.csv>..."""
import os
import re
import subprocess
import sys

repo, maps = sys.argv[1], sys.argv[2:]
renames = {}
for path in maps:
    for line in open(path):
        p = line.strip().split(",")
        if p[0].startswith("0x"):
            renames[p[2]] = p[1]
csvs = ["firmware/CM550_J90350.00_analysis/output", "firmware/CM848_S90140.06_analysis/output"]
for d in csvs:
    for name in os.listdir(os.path.join(repo, d)):
        if not name.endswith(".csv"):
            continue
        text = open(os.path.join(repo, d, name), errors="replace").read()
        for new in set(renames.values()):
            for m in re.finditer(rf"\(was {re.escape(new)}[;),]", text):
                line = text[:m.start()].count("\n") + 1
                print(f"HISTORY REWRITTEN? {d}/{name}:{line} {text[m.start():m.start() + 90]}")
files = subprocess.run(["git", "ls-files", "*.md"], cwd=repo, capture_output=True, text=True).stdout.split()
files = [f for f in files if "/agent_notes_" not in f and "/session_" not in f]
rx = re.compile(r"(?<![A-Za-z0-9_])(" + "|".join(re.escape(o) for o in sorted(renames, key=len, reverse=True)) + r")(?![A-Za-z0-9_])")
for f in files:
    for i, line in enumerate(open(os.path.join(repo, f), errors="replace"), 1):
        for m in rx.finditer(line):
            print(f"{f}:{i}: {m.group(1)} -> {renames[m.group(1)]} | {line.strip()[:150]}")

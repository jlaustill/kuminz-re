"""Round 87 pre-checks: (1) a proposed name already used at another address in its firmware's CSV; (2) the CM848 names
being retired and how often firmware/CLAUDE.md and other tracked Markdown files mention them.
usage: precheck.py <repo/firmware> <final_changes.tsv>"""
import os
import re
import subprocess
import sys

fw_dir, tsv = sys.argv[1], sys.argv[2]
DIRS = {"CM550": "CM550_J90350.00_analysis", "CM848": "CM848_S90140.06_analysis"}
changes = [l.rstrip("\n").split("\t") for l in open(tsv)]
changes.append(["twins", "CM848", "function", "0x00026f78", "emptyStubFunction4", "ignoreCanTransmitInterrupt", "", "manual", ""])
for group, fw, kind, address, current, final, *_ in changes:
    csv = os.path.join(fw_dir, DIRS[fw], "output", "global_variables.csv" if kind == "global" else "function_renames.csv")
    for line in open(csv, errors="replace"):
        p = line.split(",")
        if len(p) > 1 and p[1].strip() == final and p[0].lower() != address.lower():
            print(f"COLLISION {fw} {final}: already at {p[0]}")
print("collision check done")
retired = sorted({c[4] for c in changes if c[1] == "CM848"})
md_files = subprocess.run(["git", "ls-files", "*.md"], cwd=fw_dir, capture_output=True, text=True).stdout.split()
claude = open(os.path.join(fw_dir, "CLAUDE.md"), errors="replace").read()
for name in retired:
    rx = re.compile(rf"\b{re.escape(name)}\b")
    docs = [f for f in md_files if rx.search(open(os.path.join(fw_dir, f), errors="replace").read())]
    print(f"{name}: firmware/CLAUDE.md {len(rx.findall(claude))}; Markdown files {len(docs)} {docs[:4]}")

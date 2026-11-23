"""Round 63 follow-up: every live-text mention of the round's 46 old function labels, EF00_SERVICE_ID, and the three
overturned claims (0x43 = an offset / 0x46 not registered / 0x15 = get address by ID) outside the CM848 output CSVs.
Skipped: generated .cpp / .hpp, the session archives (agent_notes_*), dated plans (docs/superpowers), git, node_modules,
decompiled third-party trees.  usage: sweep_live_text.py <repo> <map>..."""
import csv
import os
import re
import sys

repo, maps = os.path.abspath(sys.argv[1]), sys.argv[2:]
olds = sorted({r["old_label"] for m in maps for r in csv.DictReader(open(m))} | {"EF00_SERVICE_ID"})
NAME = re.compile(r"\b(" + "|".join(map(re.escape, olds)) + r")\b")
CLAIMS = [re.compile(p, re.I) for p in (r"0x43\b[^\n]{0,80}offset", r"0x46\b[^\n]{0,60}not registered",
                                         r"0x15\b[^\n]{0,60}(get ?address|GetAddressByParam)")]
SKIP_DIRS = {".git", "node_modules", "decompiled", "agent_notes_2026-11", "superpowers", "build", "originals",
             "__pycache__", ".venv", "dist"}
CM848_OUT = os.path.join("firmware", "CM848_S90140.06_analysis", "output")
hits = 0
for root, dirs, files in os.walk(repo):
    dirs[:] = [d for d in dirs if d not in SKIP_DIRS and not d.startswith("session_")]
    rel_root = os.path.relpath(root, repo)
    if rel_root.startswith(os.path.join(".claude", "worktrees")):
        dirs[:] = []
        continue
    for name in files:
        if not name.endswith((".md", ".py", ".csv", ".txt", ".ts", ".cpp", ".h", ".hpp", ".java", ".sh", ".json")):
            continue
        rel = os.path.normpath(os.path.join(rel_root, name))
        if name.endswith((".cpp", ".hpp")) and "output" in rel.split(os.sep):
            continue
        if rel.startswith(CM848_OUT) and name.endswith(".csv"):
            continue
        try:
            text = open(os.path.join(root, name), errors="replace").read()
        except OSError:
            continue
        for number, line in enumerate(text.split("\n"), 1):
            found = [m.group(1) for m in NAME.finditer(line)]
            claims = [c.pattern for c in CLAIMS if c.search(line)]
            if found or claims:
                hits += 1
                print(f"{rel}:{number}: {found or ''} {claims or ''} :: {line.strip()[:150]}")
print("hits:", hits)

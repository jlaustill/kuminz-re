"""Security log verdicts for commits: for each short hash, the review's start line (the "detected git commit" line
just before the reflog line that names the hash) and the next "Commit review:" verdict line after it.
usage: verdicts.py <log.txt> <hash>..."""
import re
import sys

lines = open(sys.argv[1], errors="replace").read().split("\n")
for short in sys.argv[2:]:
    idx = next((i for i, l in enumerate(lines) if "reflog shows" in l and f"({short}" in l), None)
    if idx is None:
        print(f"{short}: no review found yet")
        continue
    start = next((lines[j] for j in range(idx, max(idx - 5, 0), -1) if "detected git commit" in lines[j]), lines[idx])
    verdict = next((l for l in lines[idx + 1:] if "Commit review:" in l and "sha(s) resolved" not in l), None)
    ts = re.match(r"\[([^\]]+)\]", start)
    print(f"{short}: start {ts.group(1) if ts else '?'} -> {verdict.split('Commit review: ', 1)[1] if verdict else 'pending'}"
          f"{' (' + re.match(r'\[([^\]]+)\]', verdict).group(1) + ')' if verdict else ''}")

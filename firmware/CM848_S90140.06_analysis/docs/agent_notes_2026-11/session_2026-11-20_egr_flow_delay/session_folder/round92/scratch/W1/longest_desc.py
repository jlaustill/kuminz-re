"""For each Calterm mnemonic of e2m block 106B offsets 0x0-0xE, print the longest description in every e2m file
in the repo (and which file, and the S-record masks seen). Read-only."""
import collections
import glob
import os

REPO = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/e2m-analysis"
files = sorted(set(glob.glob(REPO + "/**/*.e2m", recursive=True)))
offsets = {0x0, 0x2, 0x4, 0x6, 0x8, 0xA, 0xC, 0xE}
best = {}
masks = collections.defaultdict(set)
where = collections.defaultdict(set)
for f in files:
    try:
        lines = open(f, encoding="latin-1").read().splitlines()
    except OSError:
        continue
    for raw in lines:
        data, _, comment = raw.partition(";")
        c = data.split(",")
        if len(c) < 12 or c[2].upper() != "106B":
            continue
        try:
            off = int(c[3], 16)
        except ValueError:
            continue
        if off not in offsets:
            continue
        name = c[0].split(":")[-1].strip() if c[0].lstrip().startswith("#") else c[0].strip()
        mnemonic = name
        com = comment.strip()
        if com.startswith("[") and "]" in com:
            mnemonic = com[1:com.index("]")]
        key = (off, mnemonic)
        if c[5] == "S":
            masks[key].add(c[10].lstrip("0") or "0")
        where[key].add(os.path.basename(f))
        if key not in best or len(com) > len(best[key][0]):
            best[key] = (com, name, os.path.basename(f))
for key in sorted(best):
    com, name, f = best[key]
    print("+0x%x %-10s masks=%-12s files=%2d %s | %s | %s" % (key[0], key[1], ",".join(sorted(masks[key])), len(where[key]), name, f, com[:200]))

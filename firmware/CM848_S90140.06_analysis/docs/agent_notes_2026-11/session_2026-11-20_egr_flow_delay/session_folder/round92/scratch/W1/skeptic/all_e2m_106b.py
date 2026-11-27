"""Skeptic: every e2m file's block 106B records at the given offsets: per (offset, mnemonic) the record types and
S masks seen (with file counts), the names, and the two longest description texts. Read-only."""
import collections
import glob
import os
import re
import sys

REPO = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/e2m-analysis"
files = sorted(set(glob.glob(REPO + "/**/*.e2m", recursive=True)) | set(glob.glob(REPO + "/**/*.E2M", recursive=True)))
want = set(int(x, 16) for x in sys.argv[1:]) if len(sys.argv) > 1 else {0, 2, 4, 6, 8, 0xA, 0xC, 0xE}
info = collections.defaultdict(lambda: collections.defaultdict(set))
texts = collections.defaultdict(lambda: collections.defaultdict(set))
names = collections.defaultdict(set)
for f in files:
    for raw in open(f, encoding="latin-1"):
        data, _, comment = raw.rstrip("\r\n").partition(";")
        c = data.split(",")
        if len(c) < 12 or c[2].upper() != "106B":
            continue
        try:
            off = int(c[3], 16)
        except ValueError:
            continue
        if off not in want:
            continue
        com = comment.strip()
        mn = c[0].strip()
        if mn.startswith("#"):
            mn = mn.split(":")[-1].strip()
        m = re.match(r"\[([A-Z0-9_]+)\]", com)
        if m:
            mn = m.group(1)
        typ = c[5]
        mask = c[10].lstrip("0") or "0"
        info[(off, mn)][(typ, mask if typ == "S" else "-")].add(os.path.basename(f))
        texts[(off, mn)][com.split("~")[0][:170]].add(os.path.basename(f))
        names[(off, mn)].add(c[0].split(":")[-1].strip())
for key in sorted(info):
    off, mn = key
    parts = ["%s:%s x%d" % (t, m, len(fs)) for (t, m), fs in sorted(info[key].items())]
    print("+%X %-12s %s | names: %s" % (off, mn, "; ".join(parts), ", ".join(sorted(names[key]))[:150]))
    for t, fs in sorted(texts[key].items(), key=lambda kv: -len(kv[0]))[:2]:
        print("        %2d files: %s" % (len(fs), t))

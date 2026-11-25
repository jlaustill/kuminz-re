"""Scratch (read-only): every e2m in e2m-analysis/originals (and CHR): block 106B records at the given offsets,
grouped by offset + mnemonic: record type, mask column, the files carrying it, one description.
usage: survey_e2m.py <repo> <offset hex> [...]"""
import collections
import glob
import os
import sys

repo = sys.argv[1]
wanted = {int(x, 16) for x in sys.argv[2:]}
files = sorted(glob.glob(os.path.join(repo, "e2m-analysis/originals/*.e2m")))
groups = collections.defaultdict(lambda: {"files": [], "rec": None})
for f in files:
    seen = set()
    for raw in open(f, encoding="latin-1"):
        data, _, comment = raw.rstrip("\r\n").partition(";")
        c = data.split(",")
        if len(c) < 12 or c[2] != "106B":
            continue
        try:
            off = int(c[3], 16)
        except ValueError:
            continue
        if off not in wanted:
            continue
        key = (off, c[0], c[5], c[10].lower().replace("0x", "").lstrip("0") or "0")
        if key in seen:
            continue
        seen.add(key)
        g = groups[key]
        g["files"].append(os.path.basename(f).replace(".e2m", ""))
        g["rec"] = comment.strip()[:100]
for key in sorted(groups, key=lambda k: (k[0], k[3].zfill(4), k[1])):
    off, name, typ, mask = key
    g = groups[key]
    fl = g["files"]
    print(f"+0x{off:x} {typ} mask={mask:>5} {name:10} n={len(fl):2} {'v64t6_s' in fl and 'IN-v64t6_s' or '':10} {g['rec']}")
    print(f"        files: {' '.join(fl)}")

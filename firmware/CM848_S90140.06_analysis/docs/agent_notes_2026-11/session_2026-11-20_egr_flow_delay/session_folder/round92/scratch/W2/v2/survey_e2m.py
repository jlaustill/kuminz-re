"""Survey every e2m file in e2m-analysis for block 106B records at given offsets (read-only).
Per (offset, mnemonic): record types, S masks, number of files, labels, and the DISTINCT description texts
(case-folded, the '~range' tail cut; longest first, at most --top) with one file that carries each.
The mnemonic is the bracketed tag of labelled (CHR) files, else the record name ('# file: NAME' lines -> NAME).
usage: survey_e2m.py <e2m-analysis dir> <hex offset>... [--names NAME,NAME] [--all-offsets] [--top N]"""
import collections
import glob
import os
import re
import sys

root = sys.argv[1]
args = sys.argv[2:]
names = None
all_offsets = False
top = 3
offs = set()
i = 0
while i < len(args):
    if args[i] == "--names":
        names = set(args[i + 1].upper().split(","))
        i += 2
    elif args[i] == "--top":
        top = int(args[i + 1])
        i += 2
    elif args[i] == "--all-offsets":
        all_offsets = True
        i += 1
    else:
        offs.add(int(args[i], 16))
        i += 1
files = sorted(set(glob.glob(root + "/**/*.e2m", recursive=True)))
info = collections.defaultdict(lambda: {"types": collections.Counter(), "masks": collections.Counter(),
                                        "texts": collections.defaultdict(set), "files": set(), "labels": set()})
for f in files:
    base = os.path.basename(f)
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
        com = comment.strip()
        label = c[0].strip()
        if label.startswith("#"):
            label = label.split(":")[-1].strip()
        mnemonic = label
        m = re.match(r"^\[([A-Z0-9_]+)\]\s*(.*)$", com)
        if m:
            mnemonic = m.group(1)
            com = m.group(2)
        if names is not None:
            if mnemonic.upper() not in names and label.upper() not in names:
                continue
        elif not all_offsets and off not in offs:
            continue
        key = (off, mnemonic)
        d = info[key]
        d["types"][c[5]] += 1
        if c[5] == "S":
            d["masks"][c[10].lstrip("0") or "0"] += 1
        text = com.split("~")[0].strip().upper()
        text = re.sub(r"\s+", " ", text)
        d["texts"][text].add(base)
        d["files"].add(base)
        d["labels"].add(label)
for key in sorted(info):
    d = info[key]
    print("+0x%x %-10s types=%s masks=%s files=%d labels=%s" % (
        key[0], key[1], dict(d["types"]), dict(d["masks"]), len(d["files"]), sorted(d["labels"])[:4]))
    for text in sorted(d["texts"], key=lambda t: (-len(t), t))[:top]:
        fl = sorted(d["texts"][text])
        print("      [%2d files e.g. %s] %s" % (len(fl), fl[0], text))

"""Skeptic (read-only): for each e2m file given, list the block 106B records at one word offset (hex, no padding),
as: file, name, type, mask (column 11), first 70 chars of the description. Groups identical (name, type, mask) rows.
usage: skeptic_survey.py <offset hex> <e2m> [<e2m> ...]"""
import collections
import os
import sys

off = int(sys.argv[1], 16)
seen = collections.defaultdict(list)
for path in sys.argv[2:]:
    for raw in open(path, encoding="latin-1"):
        data, _, comment = raw.rstrip("\r\n").partition(";")
        c = data.split(",")
        if len(c) < 12 or c[2].upper() != "106B":
            continue
        try:
            o = int(c[3], 16)
        except ValueError:
            continue
        if o != off:
            continue
        mask = c[10]
        key = (c[0], c[5], mask.lower().replace("0x", "").lstrip("0") or "0", comment.strip()[:70])
        name = os.path.basename(path)
        if name not in seen[key]:
            seen[key].append(name)
for key in sorted(seen, key=lambda k: (k[2].zfill(4) if k[1] == "S" else "N", k[0])):
    n, typ, mask, desc = key
    files = seen[key]
    print(f"{typ} {mask:>5} {n:10} [{len(files):2} files] {desc}")
    print(f"        {' '.join(files)}")

"""Skeptic pass 2 (read-only): across every e2m file in a directory, the block 106B records at one word offset.
Groups by (mnemonic, record type, mask column, bit numbers found in the description) and lists the files.
Also (with --name) finds one mnemonic at ANY block / offset in every file.
usage: sk2_survey.py <e2m dir> <offset hex> | sk2_survey.py <e2m dir> --name <MNEMONIC> [...]"""
import collections
import glob
import os
import re
import sys

d = sys.argv[1]
files = sorted(glob.glob(os.path.join(d, "*.e2m")))


def records(path):
    for raw in open(path, encoding="latin-1"):
        data, _, comment = raw.rstrip("\r\n").partition(";")
        c = data.split(",")
        if len(c) < 12:
            continue
        yield c, comment.strip()


def norm_mask(m):
    m = m.lower().replace("0x", "")
    try:
        return "%x" % int(m, 16)
    except ValueError:
        return m


if sys.argv[2] == "--name":
    for name in sys.argv[3:]:
        seen = collections.defaultdict(list)
        for f in files:
            for c, comment in records(f):
                if c[0].upper() == name.upper():
                    try:
                        off = "%x" % int(c[3], 16)
                    except ValueError:
                        off = c[3]
                    key = (c[2].upper().lstrip("0") or "0", off, c[5], norm_mask(c[10]), comment.split("~")[0][:90].upper())
                    b = os.path.basename(f).replace(".e2m", "")
                    if b not in seen[key]:
                        seen[key].append(b)
        print("== %s" % name)
        for key in sorted(seen):
            print("  block %s +%s type %s mask %s [%d files] %s" % (key[0], key[1], key[2], key[3], len(seen[key]), key[4]))
            print("      %s" % " ".join(seen[key]))
    sys.exit()

off = int(sys.argv[2], 16)
seen = collections.defaultdict(list)
have_block = []
for f in files:
    b = os.path.basename(f).replace(".e2m", "")
    any106b = False
    for c, comment in records(f):
        if c[2].upper().lstrip("0") != "106B":
            continue
        any106b = True
        try:
            o = int(c[3], 16)
        except ValueError:
            continue
        if o != off:
            continue
        key = (c[5], norm_mask(c[10]) if c[5] == "S" else "-", c[0].upper(), comment.split("~")[0][:80].upper())
        if b not in seen[key]:
            seen[key].append(b)
    if any106b:
        have_block.append(b)
print("files with a 106B block: %d of %d" % (len(have_block), len(files)))
missing = [os.path.basename(f).replace(".e2m", "") for f in files if os.path.basename(f).replace(".e2m", "") not in have_block]
if missing:
    print("  without: %s" % " ".join(missing))


def order(k):
    try:
        return (0, int(k[1], 16), k[2])
    except ValueError:
        return (1, 0, k[2])


for key in sorted(seen, key=order):
    typ, mask, name, desc = key
    fl = seen[key]
    print("%s mask %5s %-9s [%2d] %s" % (typ, mask, name, len(fl), desc))
    print("        %s" % " ".join(fl))

"""Skeptic: one mnemonic (or a block + offset) over every e2m file: type, mask and description, counted.
usage: survey.py <repo> name <MNEMONIC>...        (records whose first column or [bracket] mnemonic is MNEMONIC)
       survey.py <repo> at <block hex> <offset hex>  (every record at that block + offset, per distinct name/mask)"""
import collections
import glob
import os
import re
import sys

repo = sys.argv[1]
mode = sys.argv[2]
files = sorted(glob.glob(os.path.join(repo, "e2m-analysis/originals/*.e2m")) +
               glob.glob(os.path.join(repo, "e2m-analysis/CHR/*.e2m")))


def records(path):
    for raw in open(path, encoding="latin-1"):
        line = raw.rstrip("\r\n")
        data, _, comment = line.partition(";")
        c = data.split(",")
        if len(c) < 12:
            continue
        yield c, comment


if mode == "name":
    for want in sys.argv[3:]:
        seen = collections.Counter()
        where = collections.defaultdict(set)
        for path in files:
            base = os.path.basename(path)
            for c, comment in records(path):
                m = re.match(r"\[(\w+)\]", comment.strip())
                mn = m.group(1) if m else c[0]
                if mn != want and c[0] != want:
                    continue
                try:
                    off = int(c[3], 16)
                except ValueError:
                    off = -1
                # mask column: index 10 in the old layout; CHR layout has it at 10 too
                key = (c[2].upper(), off, c[5], c[10], c[0], comment.split("~")[0].strip())
                seen[key] += 1
                where[key].add(base)
        print(f"== {want}: {sum(seen.values())} records, {len(seen)} distinct")
        for key, n in sorted(seen.items(), key=lambda kv: -kv[1]):
            block, off, typ, mask, name, text = key
            print(f"   {n:3d}x in {len(where[key]):2d} files  {block} +{off:02X} {typ} mask={mask:>5} {name}: {text[:150]}")
else:
    block = sys.argv[3].upper()
    want_off = int(sys.argv[4], 16)
    seen = collections.Counter()
    where = collections.defaultdict(set)
    for path in files:
        base = os.path.basename(path)
        for c, comment in records(path):
            if c[2].upper() != block:
                continue
            try:
                off = int(c[3], 16)
            except ValueError:
                continue
            if off != want_off:
                continue
            m = re.match(r"\[(\w+)\]", comment.strip())
            mn = m.group(1) if m else c[0]
            key = (c[5], c[10], mn, c[0] if m else "", comment.split("~")[0].strip()[:110])
            seen[key] += 1
            where[key].add(base)

    def sort_key(kv):
        typ, mask, mn, label, text = kv[0]
        try:
            mv = int(mask, 16)
        except ValueError:
            mv = 0
        return (typ != "S", mv, mn)

    for key, n in sorted(seen.items(), key=sort_key):
        typ, mask, mn, label, text = key
        print(f"   {typ} mask={mask:>5} {mn:10} {label:38} files={len(where[key]):2d}  {text}")

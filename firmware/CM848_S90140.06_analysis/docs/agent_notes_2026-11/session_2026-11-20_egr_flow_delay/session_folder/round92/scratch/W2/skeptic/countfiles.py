"""Skeptic: per mnemonic, how many e2m files carry it at 106B, split by record type and mask (v64t6_s excluded and
reported separately). usage: countfiles.py <repo> <MNEMONIC>..."""
import collections
import glob
import os
import re
import sys

repo = sys.argv[1]
files = sorted(glob.glob(os.path.join(repo, "e2m-analysis/originals/*.e2m")) +
               glob.glob(os.path.join(repo, "e2m-analysis/CHR/*.e2m")))
for want in sys.argv[2:]:
    per = collections.defaultdict(set)
    texts = collections.defaultdict(set)
    for path in files:
        base = os.path.basename(path)
        for raw in open(path, encoding="latin-1"):
            line = raw.rstrip("\r\n")
            data, _, comment = line.partition(";")
            c = data.split(",")
            if len(c) < 12:
                continue
            m = re.match(r"\s*\[(\w+)\]", comment)
            mn = m.group(1) if m else c[0]
            if mn != want:
                continue
            try:
                blk = int(c[2], 16)
                off = int(c[3], 16)
            except ValueError:
                continue
            mask = ""
            if c[5] == "S":
                try:
                    mask = "0x%x" % int(c[10], 16)
                except ValueError:
                    mask = c[10]
            key = (blk, off, c[5], mask)
            per[key].add(base)
            texts[key].add(comment.split("~")[0].strip()[:120])
    print(f"== {want}")
    for key in sorted(per):
        blk, off, typ, mask = key
        fs = per[key]
        other = sorted(f for f in fs if f != "v64t6_s.e2m")
        chr_n = sum(1 for f in other if f.startswith("CHR_"))
        print(f"   {blk:04X} +{off:02X} {typ} mask={mask or '-':>7}: {len(other)} other files ({chr_n} CHR, {len(other) - chr_n} originals)"
              f"{' + v64t6_s' if 'v64t6_s.e2m' in fs else ''}")
        for t in sorted(texts[key]):
            print(f"        '{t}'")

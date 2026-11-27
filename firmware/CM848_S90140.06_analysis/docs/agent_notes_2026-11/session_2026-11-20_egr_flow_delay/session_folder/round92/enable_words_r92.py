"""Round 92 (read-only): e2m block 106B (CM550's feature enable words) - per word offset, the records that describe it:
type, mask (the scale column of an S record), name, description; and the CM550 row there with its .cpp references.
usage: enable_words_r92.py <repo> [<word offset>]"""
import collections
import csv
import os
import re
import sys

repo = sys.argv[1]
only = int(sys.argv[2], 16) if len(sys.argv) > 2 else None
sys.path.insert(0, os.path.join(repo, "firmware/scripts"))
import e2m_block_addresses as t  # noqa: E402

O = os.path.join(repo, "firmware/CM550_J90350.00_analysis/output")
table = t.parse_cm550_table(open(t.CM550_DEFAULTS["rom"], "rb").read())
base = t.cm550_ram_address(table[0x106B])
rows = {int(r[0], 16): r for r in csv.reader(open(os.path.join(O, "global_variables.csv"), newline="")) if r and r[0].startswith("0x")}
cpp = open(os.path.join(O, "J90350.00.ghidra.cpp"), errors="replace").read()
refs = collections.Counter(re.findall(r"\b[A-Za-z_]\w*\b", cpp))
words = collections.defaultdict(list)
for raw in open(t.CM550_DEFAULTS["e2m"], encoding="latin-1"):
    data, _, comment = raw.rstrip("\r\n").partition(";")
    c = data.split(",")
    if len(c) < 12 or c[2] != "106B":
        continue
    words[int(c[3], 16)].append((c[5], c[10], c[0], comment.strip()))
print(f"block 106B at 0x{base:x}: {len(words)} offsets, {sum(len(v) for v in words.values())} records")
for off in sorted(words):
    if only is not None and off != only:
        continue
    a = base + off
    r = rows.get(a)
    name = r[1] if r else ""
    types = collections.Counter(x[0] for x in words[off])
    print(f"+0x{off:x} 0x{a:x} {name or '(no row)'} {r[2] if r else ''} refs={refs.get(name, 0) + refs.get('_' + name, 0)} types={dict(types)}")
    if only is not None:
        for typ, mask, n, d in sorted(words[off], key=lambda x: x[1]):
            print(f"     {typ} {mask:>8} {n:10} {d[:90]}")

"""Skeptic: CM550's own e2m (v64t6_s): per A/D channel n the block 1003 records of its 24-byte config record
(offset 24 n .. 24 n + 23) whose description names the channel (CA / HE / LE records), next to the block 106B
override record (OD) whose S mask is bit n (word 5) or bit n - 16 (word 6). Read-only."""
import collections

E2M = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/e2m-analysis/originals/v64t6_s.e2m"
cfg = collections.defaultdict(list)
od = {}
for raw in open(E2M, encoding="latin-1"):
    data, _, comment = raw.rstrip("\r\n").partition(";")
    c = data.split(",")
    if len(c) < 12:
        continue
    try:
        off = int(c[3], 16)
    except ValueError:
        continue
    if c[2] == "1003":
        cfg[off // 24].append((off % 24, c[0], comment.split("~")[0]))
    if c[2] == "106B" and off in (0xC, 0xE) and c[5] == "S":
        mask = int(c[10], 16)
        bit = mask.bit_length() - 1
        if off == 0xE and bit > 8:
            continue
        ch = bit + (16 if off == 0xE else 0)
        od[ch] = (c[0], "%x" % mask, comment.split("~")[0])
for ch in sorted(cfg):
    recs = sorted(set(cfg[ch]))
    stems = collections.Counter(r[1][:-2] for r in recs)
    named = [r for r in recs if r[0] in (0x10, 0x14, 0x15)]
    print("channel %2d  stems %s  OD %s" % (ch, dict(stems), od.get(ch)))
    for r in named:
        print("      +0x%02x %-10s %s" % r)

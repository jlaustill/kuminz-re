"""Round 44 stage B evidence: lay each absent e2m block's CHR_CC layout over the CM848 rows at a hypothesized base, with
the dump value scaled by the record's scale. A block fits when its size fills the gap between dumped-table blocks and
every record's meaning matches the code that reads the row.
usage: align_blocks.py <repo>"""
import csv
import glob
import os
import re
import sys

repo = os.path.abspath(sys.argv[1])
CM = os.path.join(repo, "firmware/CM848_S90140.06_analysis")
ram = open(os.path.join(CM, "originals/cm848_ram.bin"), "rb").read()
RAM_BASE = 0x3FA000
rows = {}
for r in csv.reader(open(os.path.join(CM, "output/global_variables.csv"))):
    if r and r[0].startswith("0x"):
        rows.setdefault(int(r[0], 16), []).append((r[1], r[2], (r[3] if len(r) > 3 else "")[:70]))
recs = {}
for path in sorted(glob.glob(os.path.join(repo, "e2m-analysis/CHR/CHR_CC*.e2m"))):
    for line in open(path, errors="replace"):
        head, _, desc = line.strip().partition(";")
        f = head.split(",")
        if len(f) > 11 and re.fullmatch(r"[0-9A-Fa-f]{4}", f[2]) and re.fullmatch(r"[0-9A-Fa-f]{1,4}", f[3]):
            recs.setdefault((int(f[2], 16), int(f[3], 16)), (f[0], int(f[7], 16) if f[7].isdigit() else f[7], f[9], f[10], desc.strip()[:70]))


def value(a, size, sign):
    if not (RAM_BASE <= a < RAM_BASE + len(ram)) or not isinstance(size, int) or size not in (1, 2, 4):
        return None
    v = int.from_bytes(ram[a - RAM_BASE:a - RAM_BASE + size], "big")
    if sign == "S" and v >> (8 * size - 1):
        v -= 1 << (8 * size)
    return v


for block, base in [(0x8C30, 0x3FF6CA), (0x8B12, 0x408E96), (0x8B4E, 0x408A66), (0x8BAC, 0x408A72), (0x8B50, 0x3FEE34), (0x8B4F, 0x40B54A), (0x8BAD, 0x40B54C), (0x8B59, 0x3FD8EC),
                    (0x8BAE, 0x3FEE46)]:
    print(f"== {block:04X} at 0x{base:06x}")
    for (b, o), (name, size, sign, scale, desc) in sorted(recs.items()):
        if b != block:
            continue
        a = base + o
        v = value(a, size, sign)
        try:
            eng = f"{v * float(scale):g}" if v is not None else "-"
        except ValueError:
            eng = "-"
        here = rows.get(a, [("(no row)", "", "")])
        print(f"   +{o:02X} 0x{a:06x} {name} [{size}{sign} x{scale}] dump {v} = {eng}")
        for n, t, c in here:
            print(f"        row: {n} {t} | {c}")

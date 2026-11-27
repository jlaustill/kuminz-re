"""Find every reference to a CM848 code address: bl / b (relative, both images) and raw 4-byte pointers.
usage: callers848.py 0xADDR [...]"""
import bisect
import csv
import sys

BASE = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM848_S90140.06_analysis/originals/"
images = [(0, open(BASE + "cm848_rom.bin", "rb").read()), (0x500000, open(BASE + "cm848_flash2_live.bin", "rb").read())]
names = {}
for row in csv.reader(open("/home/linux/.claude/jobs/374b0424/tmp/w15/r97/frozen/cm848/function_renames.csv")):
    if row and row[0].startswith("0x"):
        names[int(row[0], 16)] = row[1]
starts = sorted(names)


def owner(a):
    i = bisect.bisect_right(starts, a) - 1
    return f"{names[starts[i]]}@0x{starts[i]:x}+0x{a - starts[i]:x}" if i >= 0 else "?"


for arg in sys.argv[1:]:
    t = int(arg, 16)
    print(f"== 0x{t:x} {names.get(t, '')}")
    for base, img in images:
        pat = t.to_bytes(4, "big")
        i = img.find(pat)
        while i != -1:
            print(f"  pointer at 0x{base + i:x} in {owner(base + i)}")
            i = img.find(pat, i + 1)
        for off in range(0, len(img) - 3, 4):
            w = int.from_bytes(img[off:off + 4], "big")
            if (w >> 26) != 18:
                continue
            li = w & 0x03fffffc
            if li & 0x02000000:
                li -= 0x04000000
            aa = (w >> 1) & 1
            lk = w & 1
            pc = base + off
            tgt = li if aa else pc + li
            if tgt == t:
                print(f"  {'bl' if lk else 'b'} at 0x{pc:x} in {owner(pc)}")

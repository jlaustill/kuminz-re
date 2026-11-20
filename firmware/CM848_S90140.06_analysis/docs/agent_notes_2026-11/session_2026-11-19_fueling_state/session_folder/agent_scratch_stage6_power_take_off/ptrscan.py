"""Find big-endian 32-bit words equal to the given addresses (pointer tables) in ROM and flash2, plus `bl`/`b` branches to them.
usage: ptrscan.py 0xADDR..."""
import struct
import sys

ORIG = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-fueling-state-enum/firmware/CM848_S90140.06_analysis/originals"
rom = open(f"{ORIG}/cm848_rom.bin", "rb").read()
fl2 = open(f"{ORIG}/cm848_flash2_live.bin", "rb").read()
images = [("rom", 0x0, rom), ("flash2", 0x500000, fl2)]
for a in sys.argv[1:]:
    target = int(a, 16)
    print(f"== 0x{target:x}")
    for name, base, img in images:
        # aligned 32-bit pointer words
        for off in range(0, len(img) - 3, 2):
            w = struct.unpack(">I", img[off:off + 4])[0]
            if w == target and off % 2 == 0:
                print(f"   pointer word in {name} @ 0x{base + off:x}")
        # relative / absolute branches (opcode 18): bl = LK 1, b = LK 0, AA bit
        for off in range(0, len(img) - 3, 4):
            w = struct.unpack(">I", img[off:off + 4])[0]
            if (w >> 26) != 18:
                continue
            li = w & 0x03FFFFFC
            if li & 0x02000000:
                li -= 0x04000000
            aa = (w >> 1) & 1
            lk = w & 1
            dest = li if aa else (base + off + li)
            if dest == target:
                print(f"   {'bl' if lk else 'b '} {'abs' if aa else 'rel'} in {name} @ 0x{base + off:x}")

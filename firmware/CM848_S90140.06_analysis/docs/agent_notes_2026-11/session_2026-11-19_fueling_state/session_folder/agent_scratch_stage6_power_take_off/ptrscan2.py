"""Byte-aligned search (step 1) for big-endian 32-bit words equal to the given addresses in ROM and flash2,
so odd-aligned pointers (e.g. 6-byte records: command byte + 4-byte pointer + pad) are found too.
usage: ptrscan2.py 0xADDR..."""
import struct
import sys

ORIG = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-fueling-state-enum/firmware/CM848_S90140.06_analysis/originals"
rom = open(f"{ORIG}/cm848_rom.bin", "rb").read()
fl2 = open(f"{ORIG}/cm848_flash2_live.bin", "rb").read()
for a in sys.argv[1:]:
    target = int(a, 16)
    pat = struct.pack(">I", target)
    print(f"== 0x{target:x}")
    for name, base, img in (("rom", 0, rom), ("flash2", 0x500000, fl2)):
        i = img.find(pat)
        while i != -1:
            print(f"   BE word in {name} @ 0x{base + i:x} (offset parity {i % 2})")
            i = img.find(pat, i + 1)

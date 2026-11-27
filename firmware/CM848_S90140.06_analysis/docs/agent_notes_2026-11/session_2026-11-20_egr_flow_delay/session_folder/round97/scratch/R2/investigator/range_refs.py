"""List every big-endian 4-byte occurrence (even offsets) of an address inside [lo, hi) in the CM550 ROM.
usage: range_refs.py 0xLO 0xHI"""
import sys

rom = open("/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/"
           "firmware/J90350.00.rom.bin", "rb").read()
lo, hi = int(sys.argv[1], 16), int(sys.argv[2], 16)
for i in range(0, len(rom) - 3, 2):
    v = int.from_bytes(rom[i:i + 4], "big")
    if lo <= v < hi:
        print(f"0x{i:05x}: 0x{v:x}  prev {rom[i - 2:i].hex()}")

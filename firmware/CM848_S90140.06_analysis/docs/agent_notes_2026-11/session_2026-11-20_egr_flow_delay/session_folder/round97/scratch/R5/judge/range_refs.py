"""List every 4-byte big-endian value in the CM550 ROM that points inside [lo, hi) (even offsets only).
usage: range_refs.py lo hi [lo hi ...]   (hex). Splits code hits from parameter ID table hits (0x35900-0x39000)."""
import sys
rom = open('/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin', 'rb').read()
args = sys.argv[1:]
for k in range(0, len(args), 2):
    lo = int(args[k], 16)
    hi = int(args[k + 1], 16)
    print(f"== 0x{lo:x}-0x{hi:x}")
    table = 0
    for i in range(0, len(rom) - 3, 2):
        v = int.from_bytes(rom[i:i + 4], 'big')
        if lo <= v < hi:
            if 0x35900 <= i <= 0x39000:
                table += 1
                continue
            print(f"  0x{i:05x}: 0x{v:06x} (+0x{v - lo:x}) prev {rom[i - 2:i].hex()}")
    print(f"  parameter table hits: {table}")

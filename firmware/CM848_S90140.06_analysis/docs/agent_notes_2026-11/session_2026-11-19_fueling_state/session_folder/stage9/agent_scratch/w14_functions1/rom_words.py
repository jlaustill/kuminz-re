"""rom_words.py: read big-endian words from the CM848 ROM image (bank 1) or the flash2 dump.
usage: rom_words.py 0xADDR[:count[:width]] ...   (width 1/2/4, default 2; addresses >= 0x500000 read cm848_flash2_live.bin)"""
import struct
import sys

BASE = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-fueling-state-enum/firmware/CM848_S90140.06_analysis/originals/"
rom = open(BASE + "cm848_rom.bin", "rb").read()
fl2 = open(BASE + "cm848_flash2_live.bin", "rb").read()
for arg in sys.argv[1:]:
    parts = arg.split(":")
    a = int(parts[0], 16)
    n = int(parts[1]) if len(parts) > 1 else 1
    w = int(parts[2]) if len(parts) > 2 else 2
    data, off = (fl2, a - 0x500000) if a >= 0x500000 else (rom, a)
    fmt = {1: ">B", 2: ">H", 4: ">I"}[w]
    vals = [struct.unpack(fmt, data[off + i * w: off + (i + 1) * w])[0] for i in range(n)]
    print(f"0x{a:x}: " + " ".join(str(v) for v in vals) + "   (hex " + " ".join(f"{v:x}" for v in vals) + ")")

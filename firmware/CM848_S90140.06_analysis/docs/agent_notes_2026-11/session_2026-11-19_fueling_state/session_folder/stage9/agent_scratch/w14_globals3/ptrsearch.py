"""usage: ptrsearch.py 0xADDR [0xADDR ...]  -> 32-bit big-endian pointer hits in ROM and flash2 images"""
import re
import sys

BASE = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-fueling-state-enum/firmware/CM848_S90140.06_analysis/originals/'
rom = open(BASE + 'cm848_rom.bin', 'rb').read()
fl2 = open(BASE + 'cm848_flash2_live.bin', 'rb').read()
for arg in sys.argv[1:]:
    a = int(arg, 16)
    pat = re.escape(a.to_bytes(4, 'big'))
    rom_hits = [hex(m.start()) for m in re.finditer(pat, rom)]
    fl2_hits = [hex(m.start() + 0x500000) for m in re.finditer(pat, fl2)]
    print(hex(a), 'rom', rom_hits, 'flash2', fl2_hits)

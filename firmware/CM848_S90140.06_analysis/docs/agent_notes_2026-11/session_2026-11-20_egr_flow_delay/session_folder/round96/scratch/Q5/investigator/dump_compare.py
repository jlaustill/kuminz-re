"""Compare the CM848 RAM dump (base 0x3fa000) with the EEPROM dump (RAM = 0x3fd482 + EEPROM offset)
for a word range.  usage: dump_compare.py <lo hex> <hi hex>"""
import os
import sys

D = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM848_S90140.06_analysis/originals"
ram = open(os.path.join(D, "cm848_ram.bin"), "rb").read()
ee = open(os.path.join(D, "cm848_eeprom.bin"), "rb").read()
lo, hi = int(sys.argv[1], 16), int(sys.argv[2], 16)
for a in range(lo, hi, 2):
    r = ram[a - 0x3fa000:a - 0x3fa000 + 2]
    o = a - 0x3fd482
    e = ee[o:o + 2]
    print(f"0x{a:06x} ee+0x{o:04x} ram={r.hex()} ee={e.hex()} {'SAME' if r == e else 'DIFF'}")

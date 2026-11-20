"""usage: fault.py N ...   -> P-code for fault N (ROM 0x5985a slot table -> obd_dtc_code_table 0x5b57c)"""
import sys
BASE = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-fueling-state-enum/firmware/CM848_S90140.06_analysis/originals/"
rom = open(BASE + "cm848_rom.bin", "rb").read()
u16 = lambda a: int.from_bytes(rom[a:a + 2], "big")
for arg in sys.argv[1:]:
    f = int(arg, 0)
    s = u16(0x5985a + 2 * f)
    print(f"fault {f}: slot {s} -> " + (f"P{u16(0x5b57c + 2 * s):04x}" if s < 170 else "no DTC slot"))

"""pcode.py: fault number -> ROM 0x5985a slot -> obd_dtc_code_table (ROM 0x5b57c) P-code.
usage: pcode.py <fault> ...      (same lookup as session_2026-11-17_p0500/session_folder/fault_setters.py)"""
import struct
import sys

ROM = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-fueling-state-enum/firmware/CM848_S90140.06_analysis/originals/cm848_rom.bin"
rom = open(ROM, "rb").read()
u16 = lambda a: struct.unpack(">H", rom[a:a + 2])[0]
for arg in sys.argv[1:]:
    f = int(arg, 0)
    s = u16(0x5985a + 2 * f)
    if s < 170:
        print(f"fault {f}: slot {s} (ROM 0x{0x5985a + 2 * f:x}) -> P{u16(0x5b57c + 2 * s):04x} (ROM 0x{0x5b57c + 2 * s:x})")
    else:
        print(f"fault {f}: slot {s} (ROM 0x{0x5985a + 2 * f:x}) -> no code slot")

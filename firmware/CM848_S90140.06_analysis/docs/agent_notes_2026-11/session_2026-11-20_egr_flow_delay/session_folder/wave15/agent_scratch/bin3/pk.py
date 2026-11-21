"""usage: pk.py <address> [b|w|d|s] [count]   -- read the RAM dump / ROM image / flash2 at a width.
       pk.py fault <n> [<n> ...]            -- map fault bit numbers to P-codes (ROM 0x5985a slot table -> obd_dtc_code_table)
RAM dump: addresses >= 0x3f0000, file base 0x3FA000, with the 0x80-byte gap at 0x40c200-0x40c27f (read 0x40c280+ at address - 0x80)."""
import struct
import sys

A = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM848_S90140.06_analysis/originals/"
ram = open(A + "cm848_ram.bin", "rb").read()
rom = open(A + "cm848_rom.bin", "rb").read()
flash2 = open(A + "cm848_flash2_live.bin", "rb").read()


def u16(a):
    return struct.unpack(">H", rom[a:a + 2])[0]


if sys.argv[1] == "fault":
    for f in sys.argv[2:]:
        n = int(f)
        slot = u16(0x5985a + 2 * n)
        print(f"fault {n}: slot {slot} -> " + (f"P{u16(0x5b57c + 2 * slot):04x}" if slot < 170 else "no slot"))
    sys.exit(0)

address = int(sys.argv[1], 16)
kind = sys.argv[2] if len(sys.argv) > 2 else "w"
count = int(sys.argv[3]) if len(sys.argv) > 3 else 1
width = {"b": 1, "w": 2, "s": 2, "d": 4}[kind]
for i in range(count):
    a = address + i * width
    if a >= 0x500000:
        data, at = flash2, a - 0x500000
    elif a >= 0x3F0000:
        data, at = ram, a - 0x3FA000
        if a >= 0x40c280:
            at -= 0x80
    else:
        data, at = rom, a
    raw = data[at:at + width]
    u = int.from_bytes(raw, "big")
    sgn = int.from_bytes(raw, "big", signed=True)
    print(f"0x{a:x}: {u} (0x{u:x}) signed {sgn}")

"""Round 93 F1 (read-only): every reference to a CM550 code address - absolute longs (jsr / jmp / pointer tables)
and pc-relative bsr.w / bsr.s / bra / bcc displacements that land on it.
usage: find_refs.py <hex address> [...]"""
import struct
import sys

ROM = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin"
rom = open(ROM, "rb").read()
for arg in sys.argv[1:]:
    target = int(arg, 16)
    print(f"== 0x{target:x}")
    pat = struct.pack(">I", target)
    i = rom.find(pat)
    while i != -1:
        if i % 2 == 0:
            prev = struct.unpack(">H", rom[i - 2:i])[0]
            kind = {0x4EB9: "jsr (abs).l", 0x4EF9: "jmp (abs).l"}.get(prev, f"long (prev word {prev:04x})")
            print(f"  abs long at 0x{i:x}: {kind}")
        i = rom.find(pat, i + 1)
    # pc-relative branches: 0x61xx bsr.s, 0x6100 dddd bsr.w, 0x60xx bra, 0x6xxx bcc
    for pc in range(0, len(rom) - 4, 2):
        w = struct.unpack(">H", rom[pc:pc + 2])[0]
        if (w & 0xF000) != 0x6000:
            continue
        d8 = w & 0xFF
        if d8 == 0:
            disp = struct.unpack(">h", rom[pc + 2:pc + 4])[0]
            dest = pc + 2 + disp
        elif d8 == 0xFF:
            disp = struct.unpack(">i", rom[pc + 2:pc + 6])[0]
            dest = pc + 2 + disp
        else:
            dest = pc + 2 + (d8 - 256 if d8 & 0x80 else d8)
        if dest == target:
            cond = (w >> 8) & 0xF
            name = {0: "bra", 1: "bsr"}.get(cond, f"bcc({cond:x})")
            print(f"  pc-relative {name} at 0x{pc:x} (opcode {w:04x})")

"""List callers of CM550 functions: jsr (abs).l, bsr.w, bsr.s and raw 4-byte pointers. usage: callers.py <hex addr>..."""
import struct
import sys
import csv

ROM = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin"
FR = "/home/linux/.claude/jobs/374b0424/tmp/w15/r97/frozen/cm550/function_renames.csv"
rom = open(ROM, "rb").read()
funcs = []
with open(FR, newline="") as f:
    for row in csv.reader(f):
        try:
            funcs.append((int(row[0], 16), row[1]))
        except (ValueError, IndexError):
            pass
funcs.sort()


def owner(a):
    best = None
    for fa, n in funcs:
        if fa <= a:
            best = (fa, n)
        else:
            break
    return f"{best[1]}@0x{best[0]:x}" if best else "?"


for arg in sys.argv[1:]:
    t = int(arg, 16)
    print(f"== 0x{t:x} {owner(t)}")
    pat = t.to_bytes(4, "big")
    i = rom.find(pat)
    while i != -1:
        kind = "ptr"
        if i >= 2 and rom[i - 2:i] == b"\x4e\xb9":
            kind = "jsr"
        elif i >= 2 and rom[i - 2:i] == b"\x4e\xf9":
            kind = "jmp"
        at = i - 2 if kind != "ptr" else i
        print(f"  {kind} at 0x{at:x} in {owner(at)}")
        i = rom.find(pat, i + 1)
    for pc in range(0, len(rom) - 4, 2):
        w = struct.unpack_from(">H", rom, pc)[0]
        if w == 0x6100:
            d = struct.unpack_from(">h", rom, pc + 2)[0]
            if pc + 2 + d == t:
                print(f"  bsr.w at 0x{pc:x} in {owner(pc)}")
        elif (w & 0xff00) == 0x6100 and (w & 0xff) not in (0, 0xff):
            d = w & 0xff
            d = d - 256 if d & 0x80 else d
            if pc + 2 + d == t:
                print(f"  bsr.s? at 0x{pc:x} in {owner(pc)}")

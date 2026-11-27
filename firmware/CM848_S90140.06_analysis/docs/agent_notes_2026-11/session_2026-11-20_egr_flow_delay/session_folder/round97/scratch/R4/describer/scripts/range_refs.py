"""Every 4-byte big-endian value (any alignment) in the CM550 ROM that falls inside [lo, hi], with the containing function
and the two opcode words before it. usage: range_refs.py 0xLO 0xHI [0xLO 0xHI ...]"""
import bisect
import re
import sys

CPP = "/home/linux/.claude/jobs/374b0424/tmp/w15/r97/frozen/cm550/J90350.00.ghidra.cpp"
ROM = ("/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/"
       "firmware/J90350.00.rom.bin")
text = open(CPP, errors="replace").read()
funcs = sorted((int(m.group(2), 16), m.group(1))
               for m in re.finditer(r"^// Function: (\S+) @ (?:0x)?([0-9a-fA-F]+)", text, flags=re.M))
starts = [f[0] for f in funcs]
rom = open(ROM, "rb").read()


def containing(addr):
    i = bisect.bisect_right(starts, addr) - 1
    return funcs[i][1] if i >= 0 else "?"


args = [int(x, 16) for x in sys.argv[1:]]
for lo, hi in zip(args[0::2], args[1::2]):
    print(f"== [0x{lo:x}, 0x{hi:x}]")
    for i in range(0, len(rom) - 4):
        v = int.from_bytes(rom[i:i + 4], "big")
        if lo <= v <= hi:
            print(f"  @0x{i:x} value 0x{v:x} align{i % 2} prev {rom[max(0, i - 4):i].hex(' ')} in {containing(i)}")

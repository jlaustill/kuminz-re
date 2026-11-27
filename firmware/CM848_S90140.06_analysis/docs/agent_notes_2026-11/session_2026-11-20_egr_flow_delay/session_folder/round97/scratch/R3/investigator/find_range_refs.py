"""Every 4-byte big-endian occurrence (even offset) in the CM550 ROM of a value in [lo, hi), with its containing
function. usage: find_range_refs.py 0xLO 0xHI"""
import re, sys, bisect
CPP = "/home/linux/.claude/jobs/374b0424/tmp/w15/r97/frozen/cm550/J90350.00.ghidra.cpp"
ROM = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin"
rom = open(ROM, "rb").read()
funcs = sorted((int(m.group(2), 16), m.group(1)) for m in
               re.finditer(r"^// Function: (\S+) @ 0x([0-9a-fA-F]+)", open(CPP, errors="replace").read(), re.M))
starts = [f[0] for f in funcs]
lo, hi = int(sys.argv[1], 16), int(sys.argv[2], 16)
for i in range(0, len(rom) - 4, 2):
    v = int.from_bytes(rom[i:i + 4], "big")
    if lo <= v < hi:
        k = bisect.bisect_right(starts, i) - 1
        print("0x%05x -> 0x%06x  %s  prev %s" % (i, v, funcs[k][1] if k >= 0 else "?", rom[i - 2:i].hex()))

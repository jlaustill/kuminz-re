"""Q5 describer cross-check: every D-form load / store / addi whose 16-bit immediate is 0xdb80-0xdc80 (= 0x3fdb80-0x3fdc80
when the base is lis 0x40), in ROM + flash2, whatever the base register. Prints the lines that scan_keep_bl.txt does not
already hold (by instruction address).
usage: raw_imm_scan.py <scan_keep_bl.txt>"""
import bisect
import re
import struct
import sys

BASE = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM848_S90140.06_analysis/originals/"
CPP = "/home/linux/.claude/jobs/374b0424/tmp/w15/r96/frozen/cm848/cm848_rom.ghidra.cpp"
funcs = sorted({(int(m.group(2), 16), m.group(1)) for m in
                (re.match(r"^// Function: (\S+) @ 0x([0-9a-fA-F]+)", l) for l in open(CPP, errors="replace")) if m})
fs = [a for a, _ in funcs]
OPS = {14: "addi", 32: "lwz", 33: "lwzu", 34: "lbz", 35: "lbzu", 36: "stw", 37: "stwu", 38: "stb", 39: "stbu",
       40: "lhz", 41: "lhzu", 42: "lha", 43: "lhau", 44: "sth", 45: "sthu"}
seen = set()
for line in open(sys.argv[1]):
    parts = line.split()
    if len(parts) > 1:
        seen.add(int(parts[1], 16))
total = 0
for org, name in ((0, "cm848_rom.bin"), (0x500000, "cm848_flash2_live.bin")):
    d = open(BASE + name, "rb").read()
    for off in range(0, len(d) - 3, 4):
        w = struct.unpack(">I", d[off:off + 4])[0]
        op = w >> 26
        if op in OPS and 0xdb80 <= (w & 0xffff) < 0xdc80:
            total += 1
            pc = org + off
            if pc in seen:
                continue
            i = bisect.bisect_right(fs, pc) - 1
            print(f"{'BOOT' if pc < 0x7f60 else 'APP'} 0x{pc:06x} {funcs[i][1]:55s} {OPS[op]} r{(w >> 21) & 31},"
                  f"0x{w & 0xffff:04x}(r{(w >> 16) & 31})")
print("raw hits:", total)

"""Scratch (read-only): disassemble the CM550 function that contains a ROM address, with addresses.
usage: dis68k.py <repo> <rom hit address hex> [context lines] | --range <start> <end>"""
import re
import subprocess
import sys

repo = sys.argv[1]
ROM = repo + "/firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin"
CPP = repo + "/firmware/CM550_J90350.00_analysis/output/J90350.00.ghidra.cpp"
rom = open(ROM, "rb").read()
funcs = sorted({(int(m.group(2), 16), m.group(1)) for m in
                (re.match(r"^// Function: (\S+) @ 0x([0-9a-fA-F]+)", l) for l in open(CPP, errors="replace")) if m})


def disasm(start, end):
    data = rom[start:end]
    text = " ".join("0x%02x" % b for b in data)
    out = subprocess.run(["llvm-mc-18", "--disassemble", "--triple=m68k", "--show-encoding"], input=text,
                         capture_output=True, text=True).stdout
    addr = start
    lines = []
    for line in out.splitlines():
        line = line.strip()
        if not line or line.startswith(".text"):
            continue
        m = re.search(r"; encoding: \[(.*)\]", line)
        if not m:
            continue
        n = len([x for x in m.group(1).split(",") if x.strip()])
        lines.append((addr, line.split(";")[0].strip(), n))
        addr += n
    return lines


if sys.argv[2] == "--range":
    s, e = int(sys.argv[3], 16), int(sys.argv[4], 16)
    for a, ins, n in disasm(s, e):
        print("%06x  %s" % (a, ins))
    sys.exit()
hit = int(sys.argv[2], 16)
ctx = int(sys.argv[3]) if len(sys.argv) > 3 else 8
cand = [f for f in funcs if f[0] <= hit]
fstart, fname = cand[-1]
nxt = [f for f in funcs if f[0] > hit]
fend = nxt[0][0] if nxt else fstart + 0x400
print("function %s @ 0x%x (next 0x%x)" % (fname, fstart, fend))
lines = disasm(fstart, min(fend, hit + 0x40))
idx = [i for i, (a, ins, n) in enumerate(lines) if a <= hit < a + n]
if not idx:
    print("hit not on an instruction boundary from the function start; raw window:")
    for a, ins, n in disasm(hit - 4, hit + 24):
        print("%06x  %s" % (a, ins))
    sys.exit()
i = idx[0]
for a, ins, n in lines[max(0, i - ctx): i + ctx]:
    print("%s%06x  %s" % ("=>" if a <= hit < a + n else "  ", a, ins))

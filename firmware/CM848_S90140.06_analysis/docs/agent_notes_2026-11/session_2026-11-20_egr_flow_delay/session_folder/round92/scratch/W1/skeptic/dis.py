"""Disassemble a range of the CM550 ROM with llvm-mc (m68k, 68020 for scaled index). usage: dis.py START END"""
import subprocess
import sys

ROM = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin"
d = open(ROM, "rb").read()
start, end = int(sys.argv[1], 16), int(sys.argv[2], 16)
data = " ".join("0x%02x" % b for b in d[start:end])
out = subprocess.run(["llvm-mc-18", "--disassemble", "--triple=m68k", "-mcpu=M68020", "--show-encoding"],
                     input=data, capture_output=True, text=True)
pc = start
for line in out.stdout.splitlines():
    line = line.strip()
    if not line or line.startswith(".text"):
        continue
    if "encoding:" in line:
        ins, enc = line.split("# encoding:")
        n = enc.count("0x")
        print("%06x  %-44s %s" % (pc, ins.strip(), enc.strip()))
        pc += n
    else:
        print("        " + line)
if out.stderr:
    print(out.stderr[:3000])

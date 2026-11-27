"""Round 94 (read-only): disassemble a CM550 ROM range with llvm-mc-18 (m68k, 68020 - CPU32 is a subset), printing
each instruction's address (summed from its encoding length). usage: disasm68k_r94.py <repo> <start hex> <end hex>"""
import os
import re
import subprocess
import sys

repo = os.path.abspath(sys.argv[1])
rom = open(os.path.join(repo, "firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin"), "rb").read()
start, end = int(sys.argv[2], 16), int(sys.argv[3], 16)
data = " ".join(f"0x{b:02x}" for b in rom[start:end])
out = subprocess.run(["llvm-mc-18", "--disassemble", "--triple=m68k", "-mcpu=M68020", "--show-encoding"],
                     input=data, capture_output=True, text=True)
address = start
for line in out.stdout.splitlines():
    m = re.match(r"\s*(\S.*?)\s*#\s*encoding:\s*\[(.*)\]", line)
    if not m:
        continue
    text, encoding = m.group(1), m.group(2)
    n = len([x for x in encoding.split(",") if x.strip()])
    print(f"{address:06x}: {text.replace(chr(9), ' ')}")
    address += n
if out.stderr.strip():
    print("stderr:", out.stderr.strip().splitlines()[:3])

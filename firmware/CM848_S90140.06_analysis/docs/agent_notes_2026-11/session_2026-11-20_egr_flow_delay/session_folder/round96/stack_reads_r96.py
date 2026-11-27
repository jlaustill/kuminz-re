"""Round 96: list a CM550 function's instructions up to its first rts (or N bytes) with llvm-mc, marking stack-pointer /
frame-pointer relative operands, to read its argument offsets. usage: stack_reads_r96.py <hex start> [max bytes]"""
import re
import subprocess
import sys

ROM = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin"
start = int(sys.argv[1], 16)
size = int(sys.argv[2]) if len(sys.argv) > 2 else 400
data = open(ROM, "rb").read()[start:start + size]
hexes = " ".join(f"0x{b:02x}" for b in data)
out = subprocess.run(["llvm-mc-18", "--disassemble", "--triple=m68k", "-mcpu=M68020", "--show-encoding"],
                     input=hexes, capture_output=True, text=True).stdout
pc = start
for line in out.splitlines():
    m = re.match(r"\s+(.*?)\s*; encoding: \[(.*)\]", line)
    if not m:
        continue
    n = len(m.group(2).split(","))
    ins = m.group(1)
    mark = "  <-- stack" if re.search(r"\(\d+,%(sp|a6)\)|%sp\)\+|-\(%sp\)|link", ins) else ""
    print(f"0x{pc:05x}: {ins}{mark}")
    pc += n
    if ins.startswith("rts"):
        break

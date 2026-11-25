"""Round 96: offsets of a big-endian absolute long address inside a CM550 ROM window. usage: find_abs_refs_r96.py <hex addr> <hex start> <hex end>"""
import sys

rom = open("/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin", "rb").read()
target = int(sys.argv[1], 16).to_bytes(4, "big")
start, end = int(sys.argv[2], 16), int(sys.argv[3], 16)
i = rom.find(target, start)
while 0 <= i < end:
    print(f"0x{i:x}: opcode bytes before = {rom[i - 2:i].hex()}")
    i = rom.find(target, i + 1)

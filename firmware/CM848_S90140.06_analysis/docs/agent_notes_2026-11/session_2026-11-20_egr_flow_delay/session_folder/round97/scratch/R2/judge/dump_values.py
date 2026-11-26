"""Print RAM / extended RAM dump values (word, signed word; dword for longs) of the batch addresses (read-only).
usage: dump_values.py <file with one hex address per line>"""
import sys

BASE = ("/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/"
        "CM550_J90350.00_analysis/firmware/")
ram = open(BASE + "J90350.00.ram.bin", "rb").read()
ext = open(BASE + "J90350.00.extended_ram.bin", "rb").read()


def read(address, count):
    if 0x800000 <= address < 0x800000 + len(ram):
        return ram[address - 0x800000:address - 0x800000 + count]
    if 0x809242 <= address < 0x809242 + len(ext):
        return ext[address - 0x809242:address - 0x809242 + count]
    return None


for line in open(sys.argv[1]):
    if not line.strip():
        continue
    address = int(line.split()[0], 16)
    data = read(address, 4)
    if data is None:
        print(f"{address:#x}: not dumped")
        continue
    word = int.from_bytes(data[:2], "big")
    signed = word - 0x10000 if word & 0x8000 else word
    print(f"{address:#x}: byte {data[0]:#04x} word {word} (0x{word:04x}) signed {signed} "
          f"dword 0x{int.from_bytes(data, 'big'):08x}")

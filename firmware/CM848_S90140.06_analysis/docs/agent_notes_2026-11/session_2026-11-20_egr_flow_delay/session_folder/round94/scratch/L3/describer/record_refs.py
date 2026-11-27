"""For each 22-byte record address, list every absolute-long ROM reference to any byte inside it (the 4-byte
big-endian pattern anywhere in the ROM, even offsets only) with the containing function from the frozen .cpp.
usage: record_refs.py 0xREC [...]"""
import re
import sys

ROM = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin"
CPP = "/home/linux/.claude/jobs/374b0424/tmp/w15/r94/frozen/cm550/J90350.00.ghidra.cpp"
rom = open(ROM, "rb").read()
text = open(CPP, errors="replace").read()
starts = sorted((int(a, 16), n) for n, a in re.findall(r"^// Function: (\S+) @ (0x[0-9a-fA-F]+)", text, flags=re.M))
FIELDS = {0: "x_axis_offset", 2: "x_axis_pointer", 6: "x_input", 8: "y_axis_offset", 0xa: "y_axis_pointer",
          0xe: "y_input", 0x10: "z_values_pointer", 0x14: "no_interpolation_flag"}


def owner(pc):
    best = "?"
    for s, n in starts:
        if s <= pc:
            best = f"{n}@0x{s:x}"
        else:
            break
    return best


for arg in sys.argv[1:]:
    rec = int(arg, 16)
    print(f"== record 0x{rec:x}")
    for off in range(0, 22):
        pat = (rec + off).to_bytes(4, "big")
        i = rom.find(pat)
        while i != -1:
            if i % 2 == 0:
                prev = rom[i - 2:i].hex()
                where = "param-ID table" if 0x35224 <= i < 0x36400 else owner(i)
                print(f"   +0x{off:x} ({FIELDS.get(off, 'inside')}) ref 0x{i:x} prev {prev} in {where}")
            i = rom.find(pat, i + 1)

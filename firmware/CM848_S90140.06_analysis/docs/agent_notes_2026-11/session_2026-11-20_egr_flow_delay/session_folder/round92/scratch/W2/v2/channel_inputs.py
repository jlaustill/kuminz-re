"""CM550 engine protection channels: the input pointer at the start of each 46-byte state record (0x80d0dc + 46n),
read from the extended RAM dump (file offset = address - 0x809242 from 0x8092C2 on; the dump is 0x80 short).
Also the J1939 switch defaults and the switch status / value bytes. usage: channel_inputs.py <repo>"""
import csv
import struct
import sys

repo = sys.argv[1]
F = repo + "/firmware/CM550_J90350.00_analysis"
ext = open(F + "/firmware/J90350.00.extended_ram.bin", "rb").read()
rows = {int(r[0], 16): r[1] for r in csv.reader(open(F + "/output/global_variables.csv", newline=""))
        if r and r[0].startswith("0x")}


def rd(addr, n):
    off = addr - 0x809242
    return ext[off:off + n]


names = ["coolant level", "coolant temperature", "intake manifold temperature", "oil pressure", "water in fuel",
         "boost pressure", "engine sync fuel pressure", "fuel temperature", "ambient air pressure"]
for n in range(9):
    a = 0x80d0dc + 46 * n
    p = struct.unpack(">I", rd(a, 4))[0]
    print(n, names[n], hex(a), "input pointer 0x%08x" % p, rows.get(p, "?"))
print("switch status bytes 0x80bcce..: ", rd(0x80bcce, 10).hex())
print("user values 0x80bcd8..:        ", rd(0x80bcd8, 10).hex())
print("override mask pointer 0x80054c: (main RAM)")
ram = open(F + "/firmware/J90350.00.ram.bin", "rb").read()
print("   0x%08x" % struct.unpack(">I", ram[0x54c:0x550])[0])
print("priority bytes 0x80bd4a..+32:  ", rd(0x80bd4a, 32).hex())

"""Round 93 J1 describer (read-only): dump the J1939 input signal descriptor tables of CM550 (ROM 0x20108) and
CM848 (flash2 0x53a278) side by side: received-byte pointer, timeout slot, logical switch."""
import csv

REPO = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay"
FROZEN = "/home/linux/.claude/jobs/374b0424/tmp/w15/r93/frozen"

rom = open(REPO + "/firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin", "rb").read()
names = {int(r[0], 16): r[1] for r in csv.reader(open(FROZEN + "/cm550/global_variables.csv")) if r and r[0].startswith("0x")}
base = 0x20108
print("CM550 j1939_input_signal_descriptor_table @0x20108")
for i in range(18):
    e = rom[base + 10 * i: base + 10 * i + 10]
    ptr = int.from_bytes(e[0:4], "big")
    slot = e[4]
    pad = e[5]
    sw = int.from_bytes(e[6:10], "big")
    print(i, f"ptr 0x{ptr:06x} {names.get(ptr, '?'):55s} slot {slot:3d} pad {pad} switch {sw} (word {13 + sw // 16} bit {sw % 16})",
          "" if i < 17 else "<- past the 17 entries")
print("bytes 0x201b2-0x201d5:", rom[0x201b2:0x201d6].hex(" "))

f2 = open(REPO + "/firmware/CM848_S90140.06_analysis/originals/cm848_flash2_live.bin", "rb").read()
n8 = {int(r[0], 16): r[1] for r in csv.reader(open(FROZEN + "/cm848/global_variables.csv")) if r and r[0].startswith("0x")}
print("CM848 table @0x53a278")
b = 0x53a278 - 0x500000
for i in range(17):
    e = f2[b + 10 * i:b + 10 * i + 10]
    ptr = int.from_bytes(e[0:4], "big")
    slot = e[4]
    sw = int.from_bytes(e[6:10], "big")
    print(i, f"ptr 0x{ptr:06x} {n8.get(ptr, '?'):55s} slot {slot:3d} switch {sw}")

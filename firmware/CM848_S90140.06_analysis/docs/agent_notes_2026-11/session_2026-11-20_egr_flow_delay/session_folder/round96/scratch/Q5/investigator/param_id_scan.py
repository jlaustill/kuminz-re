"""List CM848 parameter ID table records (flash2 0x53be38-0x53ea6c, 6 bytes: id u16, address u32) whose address is
EEPROM 0x01000600-0x01000900 or RAM 0x3fdb00-0x3fdd00 (the Q5 tables and their neighbours)."""
import struct

F2 = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM848_S90140.06_analysis/originals/cm848_flash2_live.bin"
data = open(F2, "rb").read()
start, end, base = 0x53be38, 0x53ea6c, 0x500000
rows = []
off = start - base
while off + 6 <= min(end - base, len(data)):
    pid, addr = struct.unpack(">HI", data[off:off + 6])
    rows.append((pid, addr))
    off += 6
for pid, addr in rows:
    if 0x01000600 <= addr < 0x01000900 or 0x3fdb00 <= addr < 0x3fdd00:
        ram = addr - 0x01000000 + 0x3fd482 if addr >= 0x01000000 else addr
        print(f"block {pid:04X} -> 0x{addr:08x} (RAM 0x{ram:06x})")
print(len(rows), "records read")

"""Search the CM550 RAM / extended RAM dumps (and the ROM) for big-endian 4-byte values (pointers to a record).
usage: ram_pointer_search.py <value hex> ..."""
import sys

FW = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/"
images = [("ROM", open(FW + "J90350.00.rom.bin", "rb").read(), 0),
          ("RAM", open(FW + "J90350.00.ram.bin", "rb").read(), 0x800000),
          ("XRAM", open(FW + "J90350.00.extended_ram.bin", "rb").read(), 0x809242)]
for arg in sys.argv[1:]:
    v = int(arg, 16).to_bytes(4, "big")
    found = []
    for name, data, base in images:
        i = data.find(v)
        while i != -1:
            found.append("%s 0x%x" % (name, base + i))
            i = data.find(v, i + 1)
    print("0x%s: %s" % (v.hex(), ", ".join(found) or "none"))

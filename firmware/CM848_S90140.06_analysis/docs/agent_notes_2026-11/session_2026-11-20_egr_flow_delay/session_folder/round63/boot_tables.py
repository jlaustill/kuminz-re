"""Round 63 stage B: the boot kernel's PGN 61184 tables in cm848_rom.bin - the read reply table the boot read handler
indexes at 0x7f60 + service - 0x43, and the bytes around it.  usage: boot_tables.py <repo>"""
import os
import sys

rom = open(os.path.join(os.path.abspath(sys.argv[1]),
                        "firmware/CM848_S90140.06_analysis/originals/cm848_rom.bin"), "rb").read()
print("rom 0x7f50-0x7f8f:")
for a in range(0x7f50, 0x7f90, 16):
    print(f"  {a:#07x}: {rom[a:a + 16].hex(' ')}")
print("reply by read service (0x7f60 + s - 0x43):",
      " / ".join(f"{s:#04x}->{rom[0x7f60 + s - 0x43]:#04x}" for s in (0x43, 0x46, 0x48, 0x4a, 0x4c)))

"""Round 63: the PGN 61184 service tables in the CM848 images - the application's header lengths (flash2, base 0x53a2e1
+ service, services 0x41-0x4e), its read reply services (0x53a330 + service - 0x43), and the Bank 1 header lengths
(0x575dd + service, services 0x41-0x4e).  usage: service_tables.py <repo>"""
import os
import sys

CM848 = os.path.join(os.path.abspath(sys.argv[1]), "firmware/CM848_S90140.06_analysis/originals")
flash2 = open(os.path.join(CM848, "cm848_flash2_live.bin"), "rb").read()
rom = open(os.path.join(CM848, "cm848_rom.bin"), "rb").read()


def f2(address):
    return flash2[address - 0x500000]


print("service : app header length (0x53a2e1+s) | Bank 1 header length (0x575dd+s) | app read reply (0x53a330+s-0x43)")
for s in range(0x41, 0x4f):
    reply = f"{f2(0x53a330 + s - 0x43):#04x}" if 0x43 <= s <= 0x4d else "-"
    print(f"  {s:#04x} : {f2(0x53a2e1 + s):4} | {rom[0x575dd + s]:4} | {reply}")
print("flash2 0x53a322-0x53a33f:", flash2[0x53a322 - 0x500000:0x53a340 - 0x500000].hex(" "))
print("rom 0x5761e-0x5762b:", rom[0x5761e:0x5762c].hex(" "))

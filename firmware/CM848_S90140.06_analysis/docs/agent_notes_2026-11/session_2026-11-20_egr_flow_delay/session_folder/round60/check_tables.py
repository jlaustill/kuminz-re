"""Round 60: print the SCI command dispatch table's records (command / pad / handler name) and a few parameter ID table
records from the flash2 dump.  usage: check_tables.py <repo>"""
import os
import struct
import sys

repo = os.path.abspath(sys.argv[1])
cm = os.path.join(repo, "firmware/CM848_S90140.06_analysis")
f = open(os.path.join(cm, "originals/cm848_flash2_live.bin"), "rb").read()
names = {int(l.split(",")[0], 16): l.split(",")[1]
         for l in open(os.path.join(cm, "output/function_renames.csv")) if l.startswith("0x")}
recs = []
for k in range(20):
    b = f[0x53a9a0 - 0x500000 + 6 * k:0x53a9a0 - 0x500000 + 6 * k + 6]
    cmd, pad, handler = b[0], b[1], struct.unpack(">I", b[2:])[0]
    recs.append(f"{k}:{cmd}/{pad}/{names.get(handler, hex(handler))[:34]}")
print(" | ".join(recs))
rows = [struct.unpack(">HI", f[0x53be38 - 0x500000 + 6 * k:0x53be38 - 0x500000 + 6 * k + 6]) for k in (0, 1, 2, 1440)]
print("parameter table records 0 / 1 / 2 / 1440:", [(hex(a), hex(b)) for a, b in rows])
index = [struct.unpack(">H", f[0x53af76 - 0x500000 + 2 * k:0x53af76 - 0x500000 + 2 * k + 2])[0] for k in range(1889)]
print("bucket index: max below 0xffff", max(i for i in index if i != 0xffff), "| 0xffff count", index.count(0xffff))

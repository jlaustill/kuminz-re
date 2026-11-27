"""Round 44 stage B review checks: (1) every '(was ...' note of a renamed row's old comment survives; (2) dumped-table
blocks near the EEPROM rows (0x01001980-0x010019f0) and the ROM tables (0x5c700-0x5ca00), for anchoring; (3) the
ROM byte behind 0x408a84 (Accelerator_Position_Sensor_Type).  usage: check_r44b_review.py <repo> <before.csv> <map.csv>"""
import csv
import os
import re
import sys

repo, before, map_path = os.path.abspath(sys.argv[1]), sys.argv[2], sys.argv[3]
sys.path.insert(0, os.path.join(repo, "firmware/scripts"))
import e2m_block_addresses as e  # noqa: E402

m = list(csv.DictReader(open(map_path)))
old = {l[:10]: l for l in open(before).read().split("\n") if l.startswith("0x")}
new = {l[:10]: l for l in open(os.path.join(repo, "firmware/CM848_S90140.06_analysis/output/global_variables.csv")).read().split("\n") if l.startswith("0x")}
for r in m:
    a = r["address"]
    oc, nc = old[a].split(",", 3)[3], new[a].split(",", 3)[3]
    lost = [h for h in re.findall(r"\(was [^;)]*", oc) if h not in nc]
    print(("LOST " + str(lost)) if lost else "kept", a, r["name"])
t = e.parse_table(open(e.DEFAULTS["flash2"], "rb").read())
print("dumped-table blocks near the EEPROM rows and the ROM tables:")
for b, a in sorted(t.items(), key=lambda kv: kv[1]):
    if 0x01001980 <= a <= 0x010019f0 or 0x5c700 <= a <= 0x5ca00:
        print(f"   {b:04X} {a:#x}")
rom = open(os.path.join(repo, "firmware/CM848_S90140.06_analysis/originals/cm848_rom.bin"), "rb").read()
print("ROM byte behind 0x408a84 (ROM %#x): %d" % (0x408a84 - 0x39a3e6, rom[0x408a84 - 0x39a3e6]))

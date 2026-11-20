"""List the wave-13 rows (map_stage8.csv) whose row width differs from the size of the e2m record at their address
(e2m_name_audit.py output). A word row over two 1-byte records renders the second record under the row's name.
usage: width_mismatches_W13.py <audit.csv> <map_stage8.csv>"""
import csv
import sys

audit = list(csv.DictReader(open(sys.argv[1])))
mapped = {r["address"].lower(): r["name"] for r in csv.DictReader(open(sys.argv[2]))}
by_address = {}
for r in audit:
    by_address.setdefault(f"0x{int(r['address'], 16):08x}", []).append(r)
count = 0
for address, name in mapped.items():
    for r in by_address.get(address, []):
        if r["status"] == "named" and r["row_width"] and r["size"] and int(r["row_width"]) != int(r["size"]):
            count += 1
            print(f"{address} {r['row_name']} [{r['row_type']}, {r['row_width']} B] vs e2m {r['block']} +{r['offset']}"
                  f" {r['record']} ({r['size']} B, {r['signed']})")
print("rows:", count)

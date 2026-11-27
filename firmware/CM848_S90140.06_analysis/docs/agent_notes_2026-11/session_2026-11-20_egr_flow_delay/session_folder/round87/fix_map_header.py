"""Rewrite a rename map with its header first and each data row once (sorted). usage: fix_map_header.py <map.csv>"""
import sys

path = sys.argv[1]
rows = sorted({l.rstrip("\n") for l in open(path) if l.startswith("0x")})
with open(path, "w") as fh:
    fh.write("address,name,old_label,kind,dims\n")
    for r in rows:
        fh.write(r + "\n")
print(len(rows), "rows")

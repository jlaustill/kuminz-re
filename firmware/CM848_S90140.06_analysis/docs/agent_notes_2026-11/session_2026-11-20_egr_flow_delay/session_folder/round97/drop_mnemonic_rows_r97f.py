"""Round 97 stage F: drop the refresh map rows of globals whose old label is a bare e2m mnemonic (EPCVEREN, EPFTFLFG,
...: CM550 rows named only by their record). A comment that cites such a mnemonic cites the e2m record, in both
firmwares, so the refresh must not turn it into a CM550 table path. Enum member rows (no address) stay.
usage: drop_mnemonic_rows_r97f.py <maps dir>"""
import csv
import glob
import os
import re
import sys

for path in sorted(glob.glob(os.path.join(sys.argv[1], "map_*_cm*.csv"))):
    rows = list(csv.DictReader(open(path)))
    keep = [r for r in rows if not (r["address"] and re.match(r"^[A-Z][A-Z0-9]*$", r["old_label"]))]
    with open(path, "w", newline="") as f:
        w = csv.DictWriter(f, fieldnames=["address", "name", "old_label", "kind", "dims"])
        w.writeheader()
        w.writerows(keep)
    print(os.path.basename(path), len(rows), "->", len(keep))

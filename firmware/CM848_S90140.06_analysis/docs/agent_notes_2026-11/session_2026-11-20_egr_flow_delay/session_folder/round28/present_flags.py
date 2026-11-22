"""Round 28: e2m flag records whose meaning is in their name ('..._Present', '..._Installed', '..._Enable',
'..._Is_...') next to the row at their address: rows whose name drops that word (present / installed / enable /
is / has) are candidates for a reading that describes the effect instead of the flag.
usage: present_flags.py <e2m_audit.csv>"""
import csv
import re
import sys

KEY = re.compile(r"(?i)(?:^|_)(present|installed|enable|enabled|is|has|type|select)(?:_|$)")
for r in csv.DictReader(open(sys.argv[1])):
    if r["status"] != "named" or not r["row_name"]:
        continue
    m = KEY.search(r["record"])
    if not m:
        continue
    word = m.group(1).lower().rstrip("d")
    name = r["row_name"].lower()
    if word in ("present", "installed") and not re.search(r"present|installed|fitted", name):
        print(f"{r['address']} {r['block']} +{r['offset']} {r['record']:44} -> {r['row_name']} ({r['references']} refs)")

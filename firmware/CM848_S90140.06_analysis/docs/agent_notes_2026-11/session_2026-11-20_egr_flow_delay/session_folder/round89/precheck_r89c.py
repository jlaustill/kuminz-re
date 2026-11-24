"""Round 89 stage C pre-check (read-only): the 25 A/D channel records 0x80a2aa + 22 x channel as 22-byte
sensor_debounce_state_t. For each record: the rows inside its bytes, whether each sits on a field start with a
compatible width (word field: word / i16 / undefined; byte field: byte / undefined) and its render count.
usage: precheck_r89c.py <repo>"""
import csv
import os
import re
import sys

repo = sys.argv[1]
O5 = os.path.join(repo, "firmware/CM550_J90350.00_analysis/output")
cpp = open(os.path.join(O5, "J90350.00.ghidra.cpp"), errors="replace").read()
rows = {int(r[0], 16): r for r in csv.reader(open(os.path.join(O5, "global_variables.csv"), newline=""))
        if r and r[0].startswith("0x")}
FIELDS = {0: ("filter", 8), 8: ("filtered_value", 2), 10: ("lookup_result", 2), 12: ("debounce_counter", 2),
          14: ("fault_active_flag", 1), 15: ("sample_counter", 1), 16: ("adc_raw_value", 2), 18: ("reserved_18", 4)}
WIDTH = {"word": 2, "i16": 2, "short": 2, "byte": 1, "dword": 4, "undefined": 0, "": 0}
problems = 0
total = 0
for k in range(25):
    base = 0x80a2aa + 22 * k
    found = []
    for o in range(22):
        r = rows.get(base + o)
        if not r:
            continue
        total += 1
        name, typ = r[1], r[2]
        field = FIELDS.get(o)
        n = len(re.findall(rf"(?<![A-Za-z0-9]){re.escape(name)}(?![A-Za-z0-9_])", cpp)) if name else 0
        ok = field is not None and (o == 0 or WIDTH.get(typ, -1) in (0, field[1]))
        if not ok:
            problems += 1
        found.append(f"+{o} {name}:{typ} r{n}{'' if ok else ' <-- NOT A FIELD START / WIDTH'}")
    print(f"record {k} 0x{base:x}: " + "; ".join(found))
print(total, "rows inside;", problems, "problems")

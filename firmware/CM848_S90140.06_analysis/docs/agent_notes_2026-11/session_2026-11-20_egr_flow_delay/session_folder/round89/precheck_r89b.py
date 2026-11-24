"""Round 88 stage B pre-check (read-only): for each struct instance in the audit's changes, the rows inside its bytes
(size from its type: j1939_tx_msg_t 14, engine_overspeed_event_t 8, j1939_diagnostic_service_entry_t 6, T[N] = N x)
and each row's render count in the current .cpp (bare and _-prefixed); for each global, its current row; name
collisions (a final name already used at another address in the same firmware).
usage: precheck_r88b.py <repo> <audit_changes.tsv>"""
import csv
import os
import re
import sys

repo, tsv = sys.argv[1], sys.argv[2]
DIRS = {"CM550": "firmware/CM550_J90350.00_analysis/output", "CM848": "firmware/CM848_S90140.06_analysis/output"}
CPP = {"CM550": "J90350.00.ghidra.cpp", "CM848": "cm848_rom.ghidra.cpp"}
SIZES = {"j1939_tx_msg_t": 14, "engine_overspeed_event_t": 8, "j1939_diagnostic_service_entry_t": 6, "sensor_config_t": 24}
rows, names, cpp = {}, {}, {}
for fw, d in DIRS.items():
    rows[fw], names[fw] = {}, {}
    for f in ("global_variables.csv", "function_renames.csv"):
        for r in csv.reader(open(os.path.join(repo, d, f), newline="")):
            if r and r[0].startswith("0x") and len(r) > 1:
                a = int(r[0], 16)
                if f == "global_variables.csv":
                    rows[fw][a] = r
                if r[1]:
                    names[fw].setdefault(r[1], set()).add(a)
    cpp[fw] = open(os.path.join(repo, d, CPP[fw]), errors="replace").read()


def renders(fw, name):
    if not name:
        return "-"
    return len(re.findall(rf"(?<![A-Za-z0-9]){re.escape(name)}(?![A-Za-z0-9_])", cpp[fw]))


def size_of(t):
    m = re.match(r"^(\w+)\[(\d+)\]$", t)
    if m:
        return SIZES.get(m.group(1), 0) * int(m.group(2))
    return SIZES.get(t, 0)


changes = [l.rstrip("\n").split("\t") for l in open(tsv)]
for group, fw, kind, address, current, final, ftype, fields, verdict, conf, reason in changes:
    if kind in ("global", "struct_instance", "function") and address:
        a = int(address, 16)
        others = names[fw].get(final, set()) - {a}
        if others:
            print(f"COLLISION {fw} {final} also at {[hex(x) for x in others]}")
    if kind == "struct_instance":
        a, n = int(address, 16), size_of(ftype)
        inside = [(o, rows[fw][a + o][1], rows[fw][a + o][2]) for o in range(n) if a + o in rows[fw]]
        desc = "; ".join(f"+{o} {nm or '(type-only)'}:{t} r{renders(fw, nm)}" for o, nm, t in inside)
        print(f"INSTANCE {fw} {address} {ftype}({n}) -> {final}: {desc or 'no rows'}")
    elif kind == "global":
        a = int(address, 16)
        r = rows[fw].get(a)
        print(f"GLOBAL {fw} {address} -> {final} {ftype}: {'row ' + r[1] + ':' + r[2] if r else 'NO ROW'}")

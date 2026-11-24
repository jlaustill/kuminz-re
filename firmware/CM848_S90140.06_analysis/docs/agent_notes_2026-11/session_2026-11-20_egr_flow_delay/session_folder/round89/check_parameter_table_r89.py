"""Round 89 stage D pre-check (read-only): CM550 parameter_id_lookup_table.csv's firmware_variable column against the
current globals. For each row: the current symbol at its address - an exact global row, or a struct instance's field
(field offsets from structure_definitions.csv) - and whether the column already says it.
usage: check_parameter_table_r89.py <repo> [<out.tsv>]"""
import csv
import os
import sys

repo = sys.argv[1]
O5 = os.path.join(repo, "firmware/CM550_J90350.00_analysis/output")
globals_ = {}
for r in csv.reader(open(os.path.join(O5, "global_variables.csv"), newline="")):
    if r and r[0].startswith("0x"):
        globals_[int(r[0], 16)] = (r[1], r[2])
structs, sizes = {}, {}
for r in csv.reader(open(os.path.join(O5, "structure_definitions.csv"), newline="")):
    if len(r) < 5 or r[0].startswith("#") or not r[2]:
        continue
    off = sum(z for _, _, z in structs.get(r[0], []))
    try:
        size = int(r[4])
    except ValueError:
        continue
    structs.setdefault(r[0], []).append((r[2], r[3], size))
for name, fields in structs.items():
    sizes[name] = sum(z for _, _, z in fields)


def symbol_at(a):
    if a in globals_ and globals_[a][0]:
        name, typ = globals_[a]
        if typ in structs and structs[typ]:
            return f"{name}.{structs[typ][0][0]}" if False else name
        return name
    for base in range(a - 1, a - 600, -1):
        g = globals_.get(base)
        if not g:
            continue
        name, typ = g
        if typ in sizes and base + sizes[typ] > a:
            off = a - base
            pos = 0
            for field, ftype, size in structs[typ]:
                if pos == off:
                    return f"{name}.{field}"
                if pos < off < pos + size:
                    return f"{name}.{field}+{off - pos}"
                pos += size
        return None
    return None


rows = list(csv.DictReader(open(os.path.join(O5, "parameter_id_lookup_table.csv"), newline="")))
stats = {"same": 0, "stale": 0, "empty_now_named": 0, "empty": 0, "no_symbol": 0}
out = []
for r in rows:
    a = int(r["address_hex"], 16)
    now = symbol_at(a)
    old = r["firmware_variable"]
    if now is None:
        stats["no_symbol"] += 1
        kind = "no_symbol"
    elif old == now:
        stats["same"] += 1
        kind = "same"
    elif not old:
        stats["empty_now_named"] += 1
        kind = "empty_now_named"
    else:
        stats["stale"] += 1
        kind = "stale"
    out.append((r["param_id_hex"], r["address_hex"], r["region"], old, now or "", r["e2m_parameter"], kind))
print(len(rows), "rows:", stats)
if len(sys.argv) > 2:
    with open(sys.argv[2], "w") as fh:
        fh.write("param_id_hex\taddress_hex\tregion\tfirmware_variable\tcurrent\te2m_parameter\tkind\n")
        for o in out:
            fh.write("\t".join(o) + "\n")

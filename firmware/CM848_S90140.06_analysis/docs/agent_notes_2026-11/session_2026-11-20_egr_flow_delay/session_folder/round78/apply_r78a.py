"""Round 78 stage A (CM550): remove the 16 remaining structs whose field rows each carry their own address, and type the
globals at their field addresses. Idempotent; keeps line endings. usage: apply_r78a.py <repo>
- ApplyStructures builds one type from all of a struct name's rows and puts an instance at every listed address, and
  global rows typed with such a struct get the same oversize type. Four of them render: data_collector_t /
  engine_rpm_history_t / fuel_arbitrator_diag_t / diagnostic_buffers_t give 64 fake 'global.field' renders of addresses
  that have their own globals. The other twelve render nowhere, but can flip as round 76's param_circular_buffer_t did.
- Each field row's address already has a global row (three do not, and get type-only rows). The global gets the field's
  scalar width (byte / word / dword). A global typed with the removed struct gets it too. An existing specific type
  stays.
- Arrays: the diagnostic transmit / receive buffers (0x808B00 / 0x808C00) are byte[256]; nothing else lies in
  0x808B00-0x808CFF. The 32-byte 'data_buffer' field at 0x80965E is not typed: globals start 2 bytes later, so
  timing_mode_source_selector is a scalar of unknown width and stays untyped."""
import collections
import csv
import io
import os
import sys

repo = os.path.abspath(sys.argv[1])
O5 = os.path.join(repo, "firmware/CM550_J90350.00_analysis/output")
R = "PR #53 round 78"


def read(p):
    with open(p, "rb") as fh:
        raw = fh.read().decode()
    return raw, ("\r\n" if "\r\n" in raw else "\n")


def write(p, s):
    with open(p, "wb") as fh:
        fh.write(s.encode())


S5, G5 = os.path.join(O5, "structure_definitions.csv"), os.path.join(O5, "global_variables.csv")
s, eol = read(S5)
fields = collections.defaultdict(list)
for row in csv.reader(io.StringIO(s.replace(eol, "\n"))):
    if row and not row[0].startswith("#") and row[0] != "struct_name" and len(row) > 4 and row[2].strip():
        fields[row[0]].append((row[1].strip().lower(), row[2].strip(), row[3].strip(), row[4].strip()))
dead = {n for n, rows in fields.items() if len({a for a, *_ in rows if a}) > 1}
if dead:
    lines = s.split(eol)
    kept = [l for l in lines if l.split(",")[0] not in dead]
    write(S5, eol.join(kept))
    print(f"structs removed: {len(dead)} ({len(lines) - len(kept)} rows)")
    plan = {}  # address -> (width type, struct, field)
    for name in sorted(dead):
        for address, field, type_, size in fields[name]:
            if not address:
                continue
            width = {"1": "byte", "2": "word", "4": "dword"}.get(size)
            if address in ("0x00808b00", "0x00808c00"):
                width = "byte[256]"
            plan.setdefault(address, (width, name, field))
    open(os.path.join(os.path.dirname(os.path.abspath(__file__)), "plan_r78a.txt"), "w").write(
        "\n".join(f"{a} {w} {n}.{f}" for a, (w, n, f) in sorted(plan.items())) + "\n")
else:
    plan = {}
    for line in open(os.path.join(os.path.dirname(os.path.abspath(__file__)), "plan_r78a.txt")):
        a, w, nf = line.split()
        plan[a] = (None if w == "None" else w, *nf.split(".", 1))
g, eol = read(G5)
out, seen = [], set()
for line in g.split(eol):
    address = line.split(",")[0].lower() if line.startswith("0x") else ""
    if address in plan and address not in seen and R not in line:
        width, name, field = plan[address]
        parts = line.split(",", 3)
        parts += [""] * (4 - len(parts))
        current = parts[2]
        if current in ("", "undefined") or current == name:
            new_type = width if width else ("undefined" if current == name else current)
            note = (f"typed {new_type} from the removed {name}.{field} - was {current or 'untyped'}; {R}"
                    if new_type != current else f"was a field of the removed {name} ({field}); {R}")
            parts[2] = new_type
            parts[3] = f"({note})" + (" " + parts[3] if parts[3] else "")
            line = ",".join(parts)
        seen.add(address)
    elif address in plan:
        seen.add(address)
    out.append(line)
for address in sorted(set(plan) - seen):
    width, name, field = plan[address]
    row = f"{address},,{width},The removed {name}'s field {field} - no other name ({R})"
    for i, l in enumerate(out):
        if l.startswith("0x") and int(l.split(",")[0], 16) > int(address, 16):
            out.insert(i, row)
            break
    print("type-only row added:", address, width)
write(G5, eol.join(out))
print("round 78 stage A applied")

"""Round 95 stage C, after apply_r95.py (the judges' applier notes the apply does not cover):
- function_definitions.csv: the judged prototypes. CM550 cm550_lookupTableInterpolation (0x34de0: was args
  table_interp_args_t*) and cm550_tableLookup2D (0x35088: was table_args short*) get a return row and their record
  pointer; scheduleJ1939PeriodicMessage gets its full prototype in both firmwares (CM550 0x1fe84 / CM848 0x538c8c:
  the queue as the new J1939_PERIODIC_TRANSMIT_QUEUE enum, the PGN key, the interval, the first-send offset, the builder).
- CM550 structure_definitions.csv: table_interp_args_t goes (no row uses it; the 1-D record is the 14-byte
  table_lookup_1d_arguments_t, the 12-byte struct missed its no_interpolation_flag and its header named the 2-D lookup).
- CM550 local_variables_actual.csv (read by no build script): the 0xb7bc local's type follows.
- CM550 comments that name CM550's lookupTableInterpolation say cm550_lookupTableInterpolation; mentions of CM848's
  function (CM848 keeps the unprefixed name: the two are counterparts) stay.
- part_number_list moves from 0x803ec2 (3 bytes early, inside component_identification_unit_number_cal) to 0x803ec5,
  where the dump's part numbers start (the N1 judge).
Asserts each edit; idempotent; keeps line endings. usage: post_apply_r95.py <repo>"""
import os
import re
import sys

repo = os.path.abspath(sys.argv[1])
C550 = os.path.join(repo, "firmware/CM550_J90350.00_analysis/output")
C848 = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")
R = "PR #53 round 95"


def load(path):
    text = open(path, newline="").read()
    return text, ("\r\n" if "\r\n" in text else "\n")


def save(path, text):
    open(path, "w", newline="").write(text)


QUEUE = ("J1939_PERIODIC_TRANSMIT_QUEUE_ENGINE = queue 0 (the engine node's 20 entries) / "
         "J1939_PERIODIC_TRANSMIT_QUEUE_RETARDER = queue 1 (the retarder node's 10 entries)")
PROTOTYPES = {
    C550: [
        ("0x00034de0,cm550_lookupTableInterpolation,", [
            f"0x00034de0,cm550_lookupTableInterpolation,return,,word,The value at the input: the value of the point found or one interpolated between two points (d0.w) ({R})",
            f"0x00034de0,cm550_lookupTableInterpolation,0,arguments,table_lookup_1d_arguments_t*,The 14-byte argument record at entry +4: the function writes back its x_axis_offset and reads x_axis_pointer / x_input / y_values_pointer / no_interpolation_flag (was args table_interp_args_t*; {R})"]),
        ("0x00035088,cm550_tableLookup2D,", [
            f"0x00035088,cm550_tableLookup2D,return,,word,The grid value at the two inputs (d0.w: every exit writes d0 with a word operation) ({R})",
            f"0x00035088,cm550_tableLookup2D,0,lookup,table_lookup_2d_arguments_t*,The 22-byte argument record at entry +4: axes / inputs / grid / no-interpolation flag; the function writes back the x_axis_offset (+0) and the y_axis_offset (+8) it finds (was table_args short*; {R})"]),
        ("0x0001fe84,scheduleJ1939PeriodicMessage,", [
            f"0x0001fe84,scheduleJ1939PeriodicMessage,return,,byte,1 when the queue is full (moveq #1) / else 0 (clr.b d0); no caller reads it ({R})",
            f"0x0001fe84,scheduleJ1939PeriodicMessage,0,queue_index,J1939_PERIODIC_TRANSMIT_QUEUE,The queue: the long at +4: {QUEUE}; the callers push clr.l or pea (1).w ({R})",
            f"0x0001fe84,scheduleJ1939PeriodicMessage,1,pgn_key,ushort,The PGN key stored at the entry's +0 (the word at +8) ({R})",
            f"0x0001fe84,scheduleJ1939PeriodicMessage,2,interval_milliseconds,ushort,The transmit interval in ms (the word at +10): divs.l #10 into the entry's +2 as 10 ms ticks ({R})",
            f"0x0001fe84,scheduleJ1939PeriodicMessage,3,first_send_offset_milliseconds,ushort,The delay of the first send in ms (the word at +12): divs.l #10 plus the queue's current tick into the entry's +4 ({R})",
            f"0x0001fe84,scheduleJ1939PeriodicMessage,4,builder,void*,The message builder (the long at +14) stored at the entry's +6: cm550_runJ1939PeriodicTransmitQueues calls it when its tick comes ({R})"]),
    ],
    C848: [
        ("0x00538c8c,scheduleJ1939PeriodicMessage,", [
            f"0x00538c8c,scheduleJ1939PeriodicMessage,return,,byte,1 when the queue is full (li r3 1) / else 0; no caller reads it ({R})",
            f"0x00538c8c,scheduleJ1939PeriodicMessage,0,queue_index,J1939_PERIODIC_TRANSMIT_QUEUE,The queue (r3; cmpwi r3 0): {QUEUE}; any value other than 0 picks queue 1 ({R})",
            f"0x00538c8c,scheduleJ1939PeriodicMessage,1,pgn_key,ushort,The PGN key (r4) stored with sth at the entry's +0 ({R})",
            f"0x00538c8c,scheduleJ1939PeriodicMessage,2,interval_milliseconds,int,The transmit interval in ms (r5): divw by 10 into the entry's +2 (a full 32-bit divide) ({R})",
            f"0x00538c8c,scheduleJ1939PeriodicMessage,3,first_send_offset_milliseconds,int,The delay of the first send in ms (r6): divw by 10 plus the queue's current tick into the entry's +4 ({R})",
            f"0x00538c8c,scheduleJ1939PeriodicMessage,4,builder,void*,The message builder (r7) stored with stw at the entry's +6: the periodic transmit code calls it when its tick comes ({R})"]),
    ],
}
for out, items in PROTOTYPES.items():
    p = os.path.join(out, "function_definitions.csv")
    t, E = load(p)
    lines = t.split(E)
    for prefix, rows in items:
        assert all("," not in r.split(",", 5)[5] for r in rows), prefix
        if rows[0] in lines:
            continue
        idx = [i for i, l in enumerate(lines) if l.lower().startswith(prefix.lower())]
        if idx:
            lines[idx[0]:idx[-1] + 1] = rows
        else:
            while lines and lines[-1] == "":
                lines.pop()
            lines += ["", f"# {prefix.split(',')[1]} ({R})"] + rows + [""]
        print(f"{os.path.basename(os.path.dirname(out))}: {prefix.split(',')[1]} {len(rows)} rows (replaced {len(idx)})")
    save(p, E.join(lines))

p = os.path.join(C550, "structure_definitions.csv")
t, E = load(p)
lines = t.split(E)
head = "# Table Interpolation Arguments - used by FUN_00035088 (2D lookup)"
if head in lines:
    i = lines.index(head)
    assert all(lines[i + k].startswith("table_interp_args_t,") for k in range(1, 5)) and not lines[i + 5].startswith("table_interp_args_t,")
    del lines[i:i + 5]
    if lines[i - 1] == "" and lines[i] == "":
        del lines[i]
    save(p, E.join(lines))
    print("CM550 table_interp_args_t removed")
p = os.path.join(C550, "local_variables_actual.csv")
t, E = load(p)
old = "0x0000b7bc,sensorInputFilterProcessor,local_8,table_interp_args_t *,false"
if old in t:
    save(p, t.replace(old, "0x0000b7bc,sensorInputFilterProcessor,local_8,table_lookup_1d_arguments_t *,false"))
    print("CM550 local_variables_actual.csv: 0xb7bc local type")

# CM550's own lookupTableInterpolation in CM550 text
KEEP = re.compile(r"(CM848'?s?\s+(?:own\s+)?|cm848\s+)$", re.I)
changed = 0
for name in ("global_variables.csv", "function_renames.csv", "structure_definitions.csv", "enums.csv",
             "local_variables.csv", "function_definitions.csv"):
    p = os.path.join(C550, name)
    t, E = load(p)
    out, last = [], 0
    for m in re.finditer(r"(?<![A-Za-z0-9_])lookupTableInterpolation(?![A-Za-z0-9_])", t):
        before = t[max(0, m.start() - 20):m.start()]
        after = t[m.end():m.end() + 10]
        if KEEP.search(before) or "0x55ef4" in after:
            continue
        out.append(t[last:m.start()] + "cm550_lookupTableInterpolation")
        last = m.end()
        changed += 1
    out.append(t[last:])
    save(p, "".join(out))
print("CM550 lookupTableInterpolation -> cm550_lookupTableInterpolation in CM550 CSV text:", changed)

p = os.path.join(C550, "global_variables.csv")
t, E = load(p)
lines = t.split(E)
row = (f"0x00803ec5,part_number_list,undefined,The part number list: 8 x 10 ASCII digits in the dump (3945360100 ... "
       f"3945389800) right after the unit number (moved from 0x803ec2 - 3 bytes early inside "
       f"component_identification_unit_number_cal; {R})")
if not any(l.startswith("0x00803ec5,") for l in lines):
    assert not any(l.startswith("0x00803ec2,") for l in lines), "the apply should have removed 0x803ec2"
    i = next(i for i, l in enumerate(lines) if l.startswith("0x00803ebb,"))
    lines.insert(i + 1, row)
    save(p, E.join(lines))
    print("CM550 part_number_list at 0x803ec5")

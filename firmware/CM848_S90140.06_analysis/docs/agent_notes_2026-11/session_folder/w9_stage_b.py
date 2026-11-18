"""Wave 9 stage B: the kernel table cut, retypes, split words, two enums, prose / plate rows, the '+2' label row, CM550 rows.
usage: w9_stage_b.py <CM848 output dir> <CM550 output dir> <renames dir>"""
import json
import os
import re
import sys

out, out550, rdir = sys.argv[1:4]


def lines_of(path):
    return open(path).read().split("\n")


def note_rows(text, prefix):
    """Split a note's 'EXACT ROWS: a | b | c' list into the rows that start with prefix (e.g. '0x')."""
    return [p.strip() for p in text.split(" | ") if p.strip().startswith(prefix)]


notes = {}
for g in ("gear_down", "charge_turbo", "governor"):
    for n, line in enumerate(open(os.path.join(rdir, f"aligned_W9_{g}.jsonl")), 1):
        r = json.loads(line) if line.strip() else {}
        notes[(g, n)] = r
# ---------- arrays.csv: the kernel dispatch table cut to its first two entries ----------
ar = lines_of(f"{out}/arrays.csv")
done = any(l.startswith("0x003fdb30,diagnostic_service_dispatch_table,byte,10,") for l in ar)
i = None if done else next(k for k, l in enumerate(ar) if l.startswith("0x003fdb30,diagnostic_service_dispatch_table,byte,100,"))
t = " ".join(notes[("gear_down", 66)]["text"].split())
m = re.search(r"EXACT REPLACEMENT of the arrays\.csv row 0x003fdb30 \(the comment cell has no commas\): (0x003fdb30,diagnostic_service_dispatch_table,byte,10,.*?scans them in cm848_dispatchDiagnosticService with a variable index x 5 so the declared length does not matter there\.)", t)
assert m, "arrays row"
if i is not None:
    ar[i] = m.group(1)
open(f"{out}/arrays.csv", "w").write("\n".join(ar))

# ---------- global_variables.csv ----------
gv = lines_of(f"{out}/global_variables.csv")


def find(addr, name):
    hits = [k for k, l in enumerate(gv) if l.startswith(f"0x{addr:08x},{name},")]
    assert len(hits) == 1, (hex(addr), name, len(hits))
    return hits[0]


def set_type(addr, name, new_type):
    k = find(addr, name)
    p = gv[k].split(",", 3)
    while len(p) < 4:
        p.append("")
    p[2] = new_type
    gv[k] = ",".join(p)


# retypes: the charge-turbo exact list against the current rows, plus the two the other agents proved
exact = note_rows(" ".join(notes[("charge_turbo", 138)]["text"].split()), "0x")
changed = []
for row in exact:
    a, name, typ = row.split(",")[:3]
    if int(a, 16) in (0x40a68a, 0x40a690):
        continue
    k = find(int(a, 16), name)
    cur = gv[k].split(",", 3)[2] if len(gv[k].split(",")) > 2 else ""
    if cur != typ and not (int(a, 16) in (0x40a68a, 0x40a690)):
        set_type(int(a, 16), name, typ)
        changed.append(f"{a} {name} {cur or '-'} -> {typ}")
set_type(0x40a280, "torque_limit_init_flag", "word")                 # one sth store, 0 reads (gear-down agent)
changed.append("0x0040a280 torque_limit_init_flag dword -> word")
for a, name, typ in ((0x40a2f2, "injection_timing_intermediate_source_code", "INJECTION_TIMING_INTERMEDIATE_SOURCE"),
                     (0x40a476, "injection_timing_source_code_before_combustion_limits", "INJECTION_TIMING_INTERMEDIATE_SOURCE"),
                     (0x40a2f6, "main_injection_timing_source_code", "MAIN_INJECTION_TIMING_SOURCE")):
    set_type(a, name, typ)
    changed.append(f"0x{a:08x} {name} -> {typ}")
# prose / comment rows given exactly
replace = (note_rows(" ".join(notes[("governor", 70)]["text"].split()), "0x0040")
           + note_rows(" ".join(notes[("governor", 73)]["text"].split()).split(". PLATE ")[0], "0x0040"))
gov29 = " ".join(notes[("governor", 29)]["text"].split())
replace.append(gov29[gov29.index("EXACT REPLACEMENT ROW (global_variables.csv 0x0040a5ee): ") + len("EXACT REPLACEMENT ROW (global_variables.csv 0x0040a5ee): "):])
for row in replace:
    a, name = row.split(",")[:2]
    k = find(int(a, 16), name)
    gv[k] = row
gv[find(0x3fa892, "timing_compensation_accumulator+2")] = "0x003fa892,high_speed_governor_integrator+2,,"
# the two label rows inside the split dwords
for a, name in ((0x40a68a, "boost_correction_block_mode_flag+2"), (0x40a690, "fuel_demand_mode_index_init_flag+2")):
    del gv[find(a, name)]
open(f"{out}/global_variables.csv", "w").write("\n".join(gv))

# ---------- the plate of 0xff04 ----------
fr = lines_of(f"{out}/function_renames.csv")
plate = " ".join(notes[("governor", 73)]["text"].split()).split("PLATE 0x0000ff04 cm848_calculateGovernorCompensatorCoefficients: ")[1]
k = next(k for k, l in enumerate(fr) if l.startswith("0x0000ff04,cm848_calculateGovernorCompensatorCoefficients,"))
fr[k] = "0x0000ff04,cm848_calculateGovernorCompensatorCoefficients," + plate
open(f"{out}/function_renames.csv", "w").write("\n".join(fr))

# ---------- enums ----------
en = lines_of(f"{out}/enums.csv")
tail = en.pop() if en and en[-1] == "" else None
gov25 = " ".join(notes[("governor", 25)]["text"].split())
rows = [p.strip() for p in gov25.split("EXACT ROWS: ")[1].split(" | ")]
assert len(rows) == 19 and all(re.fullmatch(r"(INJECTION_TIMING_INTERMEDIATE_SOURCE|MAIN_INJECTION_TIMING_SOURCE),\d+,[A-Z0-9_]+,[^,]*,2", r) for r in rows), rows[:2]
en += ["# Injection timing intermediate source (injection_timing_intermediate_source_code 0x40a2f2 / "
       "injection_timing_source_code_before_combustion_limits 0x40a476; e2m SOI_State; every value proven by a store)"]
en += [r for r in rows if r.startswith("INJECTION_TIMING_INTERMEDIATE_SOURCE,")]
en += ["# Main injection timing source (main_injection_timing_source_code 0x40a2f6; every value proven by a store)"]
en += [r for r in rows if r.startswith("MAIN_INJECTION_TIMING_SOURCE,")]
if tail is not None:
    en.append(tail)
open(f"{out}/enums.csv", "w").write("\n".join(en))

# ---------- CM550: the five shared high speed governor functions ----------
gov19 = " ".join(notes[("governor", 19)]["text"].split())
rows550 = [p.strip() for p in gov19.split("the 0x0001d392 row is already done): ")[1].split(" | ")]
f5 = lines_of(f"{out550}/function_renames.csv")
for row in rows550:
    a = row.split(",")[0]
    k = [k for k, l in enumerate(f5) if l.startswith(a + ",")]
    assert len(k) == 1, a
    old = f5[k[0]].split(",")[1]
    f5[k[0]] = row
    changed.append(f"CM550 {a} {old} -> {row.split(',')[1]}")
open(f"{out550}/function_renames.csv", "w").write("\n".join(f5))

# the six new rows of stage B
b_addr = {0x3fdb7a, 0x3fdb80, 0x3fdb82, 0x3fdb86, 0x40a68a, 0x40a690}
new = []
for g in ("gear_down", "charge_turbo", "governor"):
    for line in open(os.path.join(rdir, f"aligned_W9_{g}.jsonl")):
        r = json.loads(line) if line.strip() else {}
        if r.get("kind") == "new_global" and int(r["address"], 16) in b_addr:
            new.append(r)
assert len(new) == 6, len(new)
open(os.path.join(rdir, "aligned_W9_stage_b_new.jsonl"), "w").write("".join(json.dumps(r) + "\n" for r in new))
print("\n".join(changed))
print(f"stage B: arrays 1, retypes / typings {len(changed) - len(rows550)}, prose rows {len(replace)}, plate 1, "
      f"enum rows {len(rows)}, CM550 rows {len(rows550)}, new rows queued {len(new)}")

"""Apply the lookup-table plan to the CM848 global_variables.csv / structure_definitions.csv."""
import csv
import sys

OUT, PLAN, CACHE = sys.argv[1], sys.argv[2], sys.argv[3]
GLOBALS, STRUCTS = f"{OUT}/global_variables.csv", f"{OUT}/structure_definitions.csv"

plan = list(csv.DictReader(open(PLAN)))
cache = list(csv.DictReader(open(CACHE)))

DUPLICATE_RENAMES = {
    0x40853e: ("protection_fuel_limit_l2_values_axis_cal", 2),
    0x408566: ("protection_fuel_limit_l3_values_axis_cal", 3),
    0x40858e: ("protection_fuel_limit_l4_values_axis_cal", 4),
}

def describe(p):
    readers = p["readers"].split()
    shown = " / ".join(readers[:3]) + (f" (+{len(readers) - 3} more)" if len(readers) > 3 else "")
    return f"Lookup table - {p['detail']} - read by {shown}"

changes = {}          # addr -> (name, type, comment) replacing or adding a row
remove = set()        # addrs of rows to drop
for p in plan:
    if p["arrays"]:          # already declared in arrays.csv (same size) - leave it there
        print("skip (arrays.csv)", p["address"], p["arrays"]); continue
    a, count = int(p["address"], 16), int(p["count"])
    end = a + 2 * count
    typ = f"word[{count}]"
    for item in p["named_inside"].split():
        remove.add(int(item.split(":")[0], 16))
    if p["action"] in ("retype_named", "retype_duplicate_name"):
        name = p["name"]
        comment = None
        if a in DUPLICATE_RENAMES:
            name, gear = DUPLICATE_RENAMES[a]
            comment = (f"Axis (transmission output speed) of protection_fuel_limit_l{gear}_values_cal - the torque "
                       f"converter lockup schedule in cm848_applyConverterLockupSchedule / "
                       f"cm848_applyConverterUnlockConditions; renamed from a second "
                       f"protection_fuel_limit_l{gear}_axis_cal (that name stays on the governor pressure axis "
                       f"read by cm848_selectGovernorPressureNormal)")
        changes[a] = (name, typ, comment)
    elif p["action"] in ("junk_to_type_only", "add_type_only"):
        changes[a] = ("", typ, describe(p))
    else:
        raise SystemExit(f"unknown action {p['action']}")

# Two named "states" hold two cache words each (their own ._0_2_ / ._2_2_ and + 2 uses);
# the next row in each case is a junk "<name>+2" label row, which goes.
TWO_WORD_STATES = {"fuel_map_interpolation_state", "coolant_temp_interp_state"}
for c in cache:
    a, words, gap = int(c["address"], 16), int(c["words"]), c["gap"]
    if c["name"] in TWO_WORD_STATES:
        words, gap = 2, None
    if gap and int(gap) < 2 * words:
        print("skip cache (gap)", c); continue
    typ = "word" if words == 1 else f"word[{words}]"
    for b in range(a + 1, a + 2 * words):
        remove.add(b)
    if c["name"]:
        changes[a] = (c["name"], typ, None)
    else:
        changes[a] = ("", typ, f"Lookup cache: {'the last axis segment offset (2 x index)' if words == 1 else 'the last x / y axis segment offsets (2 x index)'} "
                               f"kept by {c['callees']}")

import bisect

def row_text(a, name, typ, comment):
    return f"0x{a:08x},{name},{typ},{comment or ''}"

# Pass 1: edit or drop existing rows where they are (the file is not strictly address-sorted).
lines = open(GLOBALS).read().split("\n")
out, done, dropped, duplicates = [], set(), [], []
for line in lines:
    parts = line.split(",", 3)
    if parts[0].startswith("0x"):
        a = int(parts[0], 16)
        if a in changes:
            if a in done:
                duplicates.append(line); out.append(line); continue   # keep - report only
            name, typ, comment = changes[a]
            old_comment = parts[3] if len(parts) > 3 else ""
            out.append(row_text(a, name, typ, comment if comment is not None else old_comment))
            done.add(a); continue
        if a in remove:
            dropped.append(parts[1]); continue
    out.append(line)

# Pass 2: insert rows for addresses without one, after the nearest lower-address row.
index_of = {}
for i, line in enumerate(out):
    p = line.split(",", 1)
    if p[0].startswith("0x"):
        index_of.setdefault(int(p[0], 16), i)
anchors = sorted(index_of)
inserts = []
for a in sorted(set(changes) - done):
    j = bisect.bisect_left(anchors, a) - 1
    at = index_of[anchors[j]] + 1 if j >= 0 else 1
    inserts.append((at, a))
for at, a in sorted(inserts, key=lambda t: (t[0], t[1]), reverse=True):
    out.insert(at, row_text(a, *changes[a]))
open(GLOBALS, "w").write("\n".join(out))
print(f"existing rows retyped {len(done)}, new rows {len(inserts)}, dropped {len(dropped)}: {dropped}")
if duplicates:
    print("addresses with two rows (left as they are):", duplicates)

s_lines = open(STRUCTS).read().split("\n")
kept = [l for l in s_lines if not l.startswith("boost_in_range_config_t,")]
open(STRUCTS, "w").write("\n".join(kept))
print("boost_in_range_config_t rows removed:", len(s_lines) - len(kept))

"""Stage 9 (wave 14) hand part B: the agents' held width items and the enum rows.
- Splits proposed by wave 14 (globals1 / globals3), each a word or byte row over records of other sizes (the ._0_1_ /
  (byte) pieces prove it): 0x408f8c / 0x408f8d, 0x408fa3 / 0x408fa4, 0x408fa5 / 0x408fa6 (byte + word), 0x40912a byte ->
  word. The typeless label rows at the second address are replaced.
- 0x3fddc4: the data collector address table is dword[32] (e2m 003B +0 Collector_Table, its length word 128 at
  0x3fddc2 gets a row).
- Enums (functions3's enum items): DIAG_SESSION_STATE -> RAM_REFRESH_STATE (LOCKED_OUT dropped: nothing stores or tests
  2), J1939_STANDBY_STATE -> DEVELOPMENT_MODE_STATE; and RUN_LOCATION (new, 1 byte) on run_location (was
  cal_write_mode): the code stores and tests only 0xee / 0xea.
Writes map_stage9_hand_b.csv (address,name,old_label,kind).
usage: apply_stage9_hand_b.py <stage9 dir> <CM848 output dir>"""
import json
import os
import sys

here, out = sys.argv[1:3]
held = {h["address"]: h for h in json.load(open(os.path.join(here, "held_W14.json")))}
splits = {}
for address in ("0x00408f8c", "0x00408fa3", "0x00408fa5", "0x0040912a"):
    for s in held[address]["split"]:
        splits[f"0x{int(s['address'], 16):08x}"] = s
path = os.path.join(out, "global_variables.csv")
lines = open(path, newline="").read().split("\n")
index = {l.split(",", 1)[0]: i for i, l in enumerate(lines) if l.startswith("0x")}
mapping = []
EXPECT = {"0x00408f8c": ("crank_period_capture_index_max_cal", "word"), "0x00408f8d": ("crank_period_reference_scale_cal", ""),
          "0x00408fa3": ("crank_sync_period_limit_state1_cal", "word"), "0x00408fa4": ("crank_sync_period_limit_state3_cal", ""),
          "0x00408fa5": ("crank_tooth_timer_max_cal", "word"), "0x00408fa6": ("crank_tooth_timer_min_cal", ""),
          "0x0040912a": ("cam_sync_speed_filter_state_cal", "byte")}
for address, (old, old_type) in EXPECT.items():
    s = splits[address]
    a, name, typ, comment = (lines[index[address]].split(",", 3) + [""])[:4]
    assert (name, typ) == (old, old_type), (address, name, typ)
    note = " ".join(s["comment"].split()) + f" (was {old}" + (", a label row)" if not old_type else ")")
    if comment:
        note += f" | earlier note: {comment}"
    lines[index[address]] = ",".join([a, s["name"], s["type"], note])
    mapping.append((address, s["name"], old))
# the data collector address table
h = held["0x003fddc4"]
a, name, typ, comment = (lines[index["0x003fddc4"]].split(",", 3) + [""])[:4]
assert (name, typ) == ("diag_dm1_fault_source_table", "dword"), (name, typ)
table_comment = " ".join(h["comment"].split())
lines[index["0x003fddc4"]] = ",".join([a, h["new"], "dword[32]", f"{table_comment} (was diag_dm1_fault_source_table)" +
                                        (f" | earlier note: {comment}" if comment and not h.get("old_comment_wrong") else "")])
mapping.append(("0x003fddc4", h["new"], "diag_dm1_fault_source_table"))
assert "0x003fddc2" not in index
lines.insert(index["0x003fddc4"], "0x003fddc2,data_collector_address_table_byte_count_cal,word,e2m 003B +0 Collector_Table:"
             " the length word in front of the data collector address table (128 in the dump = 32 entries x 4 bytes); no"
             " code reads it")
# enums
EROWS = {"0x0040c04a": ("diagnostic_session_state", "DIAG_SESSION_STATE"), "0x0040aa9a": ("j1939_standby_flag", "J1939_STANDBY_STATE")}
index = {l.split(",", 1)[0]: i for i, l in enumerate(lines) if l.startswith("0x")}
enum_items = {h["address"]: h for h in held.values() if h.get("kind") == "enum"}
renames_enum = {}
for address, (old, old_enum) in EROWS.items():
    e = enum_items[address]
    assert e["old"] == old and e["enum_old"] == old_enum, address
    a, name, typ, comment = (lines[index[address]].split(",", 3) + [""])[:4]
    assert (name, typ) == (old, old_enum), (address, name, typ)
    lines[index[address]] = ",".join([a, e["new"], e["enum_new"], " ".join(e["comment"].split()) + f" (was {old})"])
    mapping.append((address, e["new"], old))
    renames_enum[old_enum] = e
a, name, typ, comment = (lines[index["0x0040a346"]].split(",", 3) + [""])[:4]
assert (name, typ, comment) == ("cal_write_mode", "byte", ""), (name, typ, comment)
lines[index["0x0040a346"]] = (
    "0x0040a346,run_location,RUN_LOCATION,e2m 0010 +0 RUN_LOC / Run_Location 'Indicator that code is executing from"
    " ROM(0) FLASH(1) or RAM(2)' (byte; 0xee in the dump). This build stores only 0xee (normal: cm848_applicationMain at"
    " boot / cm848_runPowerDownSequence / cm848_activateDiagnosticSession / cm848_forceActivateDiagnosticSession) and 0xea"
    " (development: cm848_resetDiagnosticSession); cm848_lookupParameterIdAddress answers with raw EEPROM addresses only"
    " for 0xee while not_safe_to_program_flag is 0. (was cal_write_mode)")
mapping.append(("0x0040a346", "run_location", "cal_write_mode"))
open(path, "w", newline="").write("\n".join(lines))

epath = os.path.join(out, "enums.csv")
elines = open(epath, newline="").read().split("\n")
new_lines, inserted = [], False
for line in elines:
    parts = line.split(",", 4)
    if parts[0] in renames_enum:
        e = renames_enum[parts[0]]
        member = next(m for m in e["members"] if int(m["value"]) == int(parts[1], 0))
        if not member["new"]:
            continue                                   # LOCKED_OUT: dropped
        size = parts[4] if len(parts) > 4 else ""
        new_lines.append(",".join([e["enum_new"], parts[1], member["new"], " ".join(member["comment"].replace(",", ";").split()),
                                   size]))
        if parts[0] == "J1939_STANDBY_STATE" and not inserted and member["new"] == "DEVELOPMENT_MODE_ON":
            new_lines.append("RUN_LOCATION,0xea,RUN_LOCATION_DEVELOPMENT,Development: set by"
                             " cm848_resetDiagnosticSession together with development_mode on and the RAM refresh off,1")
            new_lines.append("RUN_LOCATION,0xee,RUN_LOCATION_NORMAL,Normal: set at boot / power-down and by the activate"
                             " services; the only value for which cm848_lookupParameterIdAddress gives raw EEPROM"
                             " addresses,1")
            inserted = True
        continue
    new_lines.append(line)
assert inserted
open(epath, "w", newline="").write("\n".join(new_lines))
with open(os.path.join(here, "map_stage9_hand_b.csv"), "w") as f:
    f.write("address,name,old_label,kind\n")
    for address, new, old in mapping:
        f.write(f"{address},{new},{old},global\n")
print(f"{len(mapping)} renames / retypes; enums RAM_REFRESH_STATE, DEVELOPMENT_MODE_STATE, RUN_LOCATION")

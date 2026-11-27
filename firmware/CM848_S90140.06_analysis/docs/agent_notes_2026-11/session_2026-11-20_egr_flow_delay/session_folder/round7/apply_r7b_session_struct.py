"""Round 7 stage B (types): the J1939 monitor's control session record (e2m 10FD / 10FE / 10FF "see j1939mon
specification") as j1939_control_session_t.
The layout, from cm848_startJ1939ControlSession / cm848_trackJ1939ControlSessions / cm848_storeJ1939ControlSessionInHistoryTable
(12 words copied per record) and the EEPROM image (originals/cm848_eeprom.bin, RAM = 0x3fd482 + offset):
  0x3fead4  0x0078 length word (= j1939_input_signal_timeouts[24]: the supervision tick's 25-word loop, addi r3,r4,48 /
            cmplw / bge @ 0x50bd9c-0x50bdc4, covers it; j1939_input_processing_enable_cal is 0 in this calibration)
  0x3fead6  5 x 24-byte history entries (e2m 10FD J1939_History_Table)
  0x3feb4e  0x0018 length word, 0x3feb50 the active engine record (e2m 10FE J1939_Active_Engine at 0x3feb4e)
  0x3feb68  0x0018 length word, 0x3feb6a the active retarder record (e2m 10FF J1939_Active_Retarder at 0x3feb68)
  record: +0 kind (byte: 0 engine / 1 retarder; 0xFE empty), +1 source address (byte), +2 control device (word),
  +4 mode history count (word: 1 at the start, at most 5), +6 five override control modes (words), +0x10 start time
  (dword key_on_hour_meter), +0x14 duration (dword). Every record in the image is empty (kind and address 0xFE).
usage: apply_r7b_session_struct.py <repo> [--dry-run]"""
import csv
import io
import os
import re
import sys

repo = os.path.abspath(sys.argv[1])
dry = "--dry-run" in sys.argv
out = os.path.join(repo, "firmware", "CM848_S90140.06_analysis", "output")
T = "j1939_control_session_t"
STRUCT = [
    ("session_kind", "byte", "1",
     "0 = an engine control (TSC1) session, 1 = a retarder control session; 0xFE (with the source address 0xFE) in an "
     "empty record"),
    ("controlling_source_address", "byte", "1", "the J1939 source address of the controlling device"),
    ("control_device", "J1939_CONTROL_DEVICE", "2",
     "engine_control_device_indicator / engine_retarder_control_device_indicator at the start"),
    ("override_control_mode_count", "word", "2",
     "how many override_control_modes are filled: 1 at the start, + 1 per mode change, at most 5 (then the history "
     "shifts)"),
    ("override_control_modes", "TSC1_OVERRIDE_MODE", "10",
     "the session's override control modes in order (the last five when there were more)"),
    ("start_time", "dword", "4", "key_on_hour_meter at the start (0.2 s counts)"),
    ("duration", "dword", "4", "key_on_hour_meter - start_time, stored when the session ends (0.2 s counts)"),
]
NEW_ROWS = [
    ("0x003fead6", "j1939_control_session_history_cal", "j1939_control_session_t[5]",
     "e2m 10FD J1939_History_Table ('J1939 History Table see j1939mon specification'): the last five finished J1939 "
     "control sessions; cm848_storeJ1939ControlSessionInHistoryTable copies the closing record into entry "
     "j1939_control_session_history_next_entry_cal. Its length word 0x78 at 0x3fead4 is also "
     "j1939_input_signal_timeouts[24] (see that row). Empty in the EEPROM image"),
    ("0x003feb4e", "j1939_active_engine_control_session_length_cal", "word",
     "e2m 10FE J1939_Active_Engine starts here: the record length 0x18 (24) in the EEPROM image; no code access found"),
    ("0x003feb50", "j1939_active_engine_control_session_cal", T,
     "the open engine control (TSC1) session record (e2m 10FE J1939_Active_Engine): cm848_startJ1939ControlSession "
     "opens it, cm848_trackJ1939ControlSessions appends the mode changes and closes it. Empty in the EEPROM image"),
    ("0x003feb68", "j1939_active_retarder_control_session_length_cal", "word",
     "e2m 10FF J1939_Active_Retarder starts here: the record length 0x18 (24) in the EEPROM image; no code access found"),
    ("0x003feb6a", "j1939_active_retarder_control_session_cal", T,
     "the open retarder control session record (e2m 10FF J1939_Active_Retarder); kind 1. Empty in the EEPROM image"),
]
MEMBER_ROWS = {"0x003feb54": "etc1_governor_mode_history_write_index", "0x003feb60": "etc1_governor_calib_session_start_time",
               "0x003feb6e": "governor_mode_history_write_index", "0x003feb7a": "governor_mode_calib_session_start_time"}
RETYPE = {"0x003feb86": "J1939_CONTROL_DEVICE", "0x003feb88": "J1939_CONTROL_DEVICE",
          "0x003fbd6e": "TSC1_OVERRIDE_MODE"}
ARRAY_NOTE = ("0x003feaa4", "j1939_input_signal_timeouts",
              " Slot 24 (0x3fead4) is also the J1939 history table's length word (0x78 in the EEPROM image): the tick's "
              "loop covers 25 words (addi r3 = r4 + 48 then cmplw / bge @ 0x50bd9c-0x50bdc4) while the receive "
              "handlers' constant indices stop at 22; j1939_input_processing_enable_cal (bit 0x400 enables the tick) is "
              "0 in this calibration")


def text_of(row):
    s = io.StringIO()
    csv.writer(s, lineterminator="").writerow(row)
    return s.getvalue()


cpp = open(os.path.join(out, "cm848_rom.ghidra.cpp")).read()
problems = []
for a, n, *_ in NEW_ROWS:
    if re.search(r"\b" + n + r"\b", cpp):
        problems.append(f"{n} is taken")
if re.search(r"\b" + T + r"\b", cpp):
    problems.append(f"{T} is taken")
gv_path = os.path.join(out, "global_variables.csv")
gv = open(gv_path).read().split("\n")
out_rows, removed, retyped, seen = [], [], 0, set()
for line in gv:
    a = line.split(",", 1)[0]
    if a in MEMBER_ROWS and line.startswith(a + "," + MEMBER_ROWS[a] + ","):
        removed.append(line)
        continue
    if a in RETYPE and not line.startswith("#"):
        row = next(csv.reader([line]))
        row[2] = RETYPE[a]
        line = text_of(row)
        retyped += 1
    if re.match(r"^0x[0-9a-f]{8},", line):
        seen.add(a)
    out_rows.append(line)
for a, *_ in NEW_ROWS:
    if a in seen:
        problems.append(f"{a} already has a row")
if len(removed) != len(MEMBER_ROWS):
    problems.append(f"{len(removed)} of {len(MEMBER_ROWS)} member rows found")
if retyped != len(RETYPE):
    problems.append(f"{retyped} of {len(RETYPE)} retypes")
if problems:
    print("\n".join("PROBLEM " + p for p in problems))
    sys.exit(1)
# insert the new rows in address order
for a, n, t, c in NEW_ROWS:
    v = int(a, 16)
    idx = next(i for i, l in enumerate(out_rows) if re.match(r"^0x[0-9a-f]{8},", l) and int(l[:10], 16) > v)
    out_rows.insert(idx, text_of([a, n, t, c]))
sd_path = os.path.join(out, "structure_definitions.csv")
sd = open(sd_path).read().rstrip("\n").split("\n")
sd += ["", "# J1939 monitor control session record (j1939mon): e2m 10FD J1939_History_Table (5 at 0x3fead6) and 10FE / 10FF",
       "#   J1939_Active_Engine / J1939_Active_Retarder (0x3feb50 / 0x3feb6a); 24 bytes, each behind a length word"]
sd += [text_of([T, "", f, t, s, c, "", "verified"]) for f, t, s, c in STRUCT]
ar_path = os.path.join(out, "arrays.csv")
ar_lines = open(ar_path).read().split("\n")
hits = [i for i, l in enumerate(ar_lines) if l.startswith(ARRAY_NOTE[0] + "," + ARRAY_NOTE[1] + ",")]
assert len(hits) == 1, hits
row = next(csv.reader([ar_lines[hits[0]]]))
row[4] = row[4] + ARRAY_NOTE[2]
ar_lines[hits[0]] = text_of(row)
ar = "\n".join(ar_lines)
print(f"removed {len(removed)} member rows, retyped {retyped}, {len(NEW_ROWS)} new rows, struct {len(STRUCT)} fields")
if dry:
    sys.exit(0)
open(gv_path, "w").write("\n".join(out_rows))
open(sd_path, "w").write("\n".join(sd) + "\n")
open(ar_path, "w").write(ar)
with open(os.path.join(os.path.dirname(os.path.abspath(__file__)), "removed_r7b.csv"), "w") as f:
    f.write("\n".join(removed) + "\n")
print("written")

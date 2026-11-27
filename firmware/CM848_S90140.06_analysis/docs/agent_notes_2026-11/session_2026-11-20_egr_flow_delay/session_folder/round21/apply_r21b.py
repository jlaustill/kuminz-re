"""Round 21 stage B (types): the engine protection fault log and the current-channel pointers.
- engine_protection_fault_log_entry_t (8 bytes): fault_snapshot_capture opens an entry at log + index * 8
  (occurrence_time = key_on_hour_meter at +0, extreme_value = 0x8000 / 0x7fff at +4 - a signed extreme it then tracks,
  read with lha - and duration = 0 at +6); fault_event_timing_snapshot closes it (duration = key_on_hour_meter -
  occurrence_time) and advances the index % 5. The e2m names the same three fields in 1152 +2E / +32 / +34.
- The two EEPROM logs (e2m 10DA +28 / +50, 40 bytes each = 5 entries) get rows typed
  engine_protection_fault_log_entry_t[5].
- engine_protection_channel_state_t: the two fault log pointers point at those logs
  (hpcr_initFuelTemperatureSensorChannel), and +2E / +36 hold a copy of the current entry (both helpers copy the 8
  bytes there), so they become fueling_fault_log_entry / engine_speed_fault_log_entry.
- The current-channel pointers of governor_fault_channelProcess_mainLoop and the two log helpers:
  fault_channel_config_ptr (0x3fbd42) and fault_channel_state_ptr (0x3fbd46) were dword, and 0x3fbd4a was an unnamed
  pointer (rendered PTR_engine_startup_inhibit_cal_003fbd4a after its boot copy's value); the loop sets them to the
  three records. Stage C names 0x3fbd4a.
usage: apply_r21b.py <repo> [--dry-run]"""
import os
import sys

repo = os.path.abspath(sys.argv[1])
dry = "--dry-run" in sys.argv
out = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")
sp, gp = os.path.join(out, "structure_definitions.csv"), os.path.join(out, "global_variables.csv")
s = open(sp).read()
g = open(gp).read().split("\n")
ENTRY = [
    "# engine_protection_fault_log_entry_t: one entry of an engine protection fault log (8 bytes; PR #53 round 21): the "
    "e2m 10DA logs hold 5, and the channel state keeps a copy of the current one",
    'engine_protection_fault_log_entry_t,,occurrence_time,dword,4,"+0: key_on_hour_meter when the fault became active '
    "(fault_snapshot_capture); e2m 1152 +2E EPF_Input_Source_0_Fueling_Fault_Occurrence_Time (0.2 s) names the copy in "
    'the channel state",,verified',
    'engine_protection_fault_log_entry_t,,extreme_value,short,2,"+4: the input\'s extreme while the fault is active: '
    "starts at 0x8000, or 0x7fff while configuration flag 0x8 is set, and with configuration flags 0xc it takes the "
    "input whenever protection_condition_eval(input, value, flags) is nonzero (the code reads it as a signed short); "
    "e2m 1152 +32 "
    'EPF_Input_Source_0_Fueling_Fault_Log_Value",,verified',
    'engine_protection_fault_log_entry_t,,duration,word,2,"+6: 0 while the fault is active, then key_on_hour_meter - '
    "occurrence_time when it clears (fault_event_timing_snapshot); e2m 1152 +34 EPF_Input_Source_0_Fueling_Fault_Log_"
    'Duration (0.2 s)",,verified',
]
assert "engine_protection_fault_log_entry_t," not in s
anchor = s.index("# engine_protection_channel_configuration_t:")
s = s[:anchor] + "\n".join(ENTRY) + "\n" + s[anchor:]
lines = s.split("\n")


def field_row(name):
    k = [i for i, l in enumerate(lines) if l.startswith(f"engine_protection_channel_state_t,,{name},")]
    assert len(k) == 1, name
    return k[0]


for name in ("fueling_fault_log_pointer", "engine_speed_fault_log_pointer"):
    i = field_row(name)
    lines[i] = lines[i].replace(f",{name},pointer,4,", f",{name},engine_protection_fault_log_entry_t*,4,", 1)
    lines[i] = lines[i].replace('",,verified', " | points at the channel's EEPROM fault log (fuel temperature: "
                                "fuel_temperature_engine_protection_*_fault_log_cal; typed in round 21 stage B)\",,verified")
for kind, first in (("fueling", "fueling_fault_occurrence_time"), ("engine_speed", "engine_speed_fault_occurrence_time")):
    i = field_row(first)
    names = [first, f"{kind}_fault_log_value", f"{kind}_fault_log_duration"]
    assert [lines[i + k].split(",")[2] for k in range(3)] == names, names
    lines[i:i + 3] = [f'engine_protection_channel_state_t,,{kind}_fault_log_entry,engine_protection_fault_log_entry_t,8,'
                      f'"+0x{0x2e if kind == "fueling" else 0x36:x}: a copy of the {kind.replace("_", " ")} fault log\'s '
                      f"current entry (both log helpers copy the 8 bytes here); e2m 1152 "
                      f"EPF_Input_Source_0_{'Fueling' if kind == 'fueling' else 'RPM'}_Fault_Occurrence_Time / _Log_Value "
                      f'/ _Log_Duration (were the fields {", ".join(names)} in stage A)",,verified']
s = "\n".join(lines)
RETYPE = {"0x003fbd42": ("fault_channel_config_ptr", "dword", "engine_protection_channel_configuration_t*"),
          "0x003fbd46": ("fault_channel_state_ptr", "dword", "engine_protection_channel_state_t*"),
          "0x003fbd4a": ("", "pointer", "engine_protection_channel_history_t*")}
for address, (name, old, new) in RETYPE.items():
    k = [i for i, l in enumerate(g) if l.startswith(f"{address},{name},{old},")]
    assert len(k) == 1, address
    a, n, t, c = g[k[0]].split(",", 3)
    g[k[0]] = ",".join([a, n, new, (c + " | " if c.strip() else "") +
                        f"the current channel's record while governor_fault_channelProcess_mainLoop runs (typed in PR "
                        f"#53 round 21, was {old})"])
LOGS = [(0x3fe006, "fuel_temperature_engine_protection_fueling_fault_log_cal", "10DA +28 EPF_Input_Source_0_Fueling_Fault_Log",
         "fueling"),
        (0x3fe02e, "fuel_temperature_engine_protection_engine_speed_fault_log_cal", "10DA +50 EPF_Input_Source_0_RPM_Fault_Log",
         "engine speed")]
for address, name, record, kind in LOGS:
    assert not any(l.startswith("0x") and address <= int(l[:10], 16) < address + 40 for l in g), hex(address)
    row = (f"0x{address:08x},{name},engine_protection_fault_log_entry_t[5],The fuel temperature channel's {kind} fault "
           f"log (e2m {record}, 40 bytes: 5 entries, 'Keeps history of input source 0 fault info'): the history's "
           f"{kind.replace(' ', '_')}_fault_log_index picks the entry, and the index advances % 5 when an entry closes "
           f"(PR #53 round 21)")
    i = max(j for j, l in enumerate(g) if l.startswith("0x") and int(l[:10], 16) < address)
    g.insert(i + 1, row)
if dry:
    print("checks passed (dry run)")
    sys.exit(0)
open(sp, "w").write(s)
open(gp, "w").write("\n".join(g))
print("entry struct, state fields, 3 pointers retyped, 2 logs")

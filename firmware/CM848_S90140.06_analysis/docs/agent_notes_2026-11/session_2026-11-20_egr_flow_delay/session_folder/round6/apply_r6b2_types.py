"""Round 6 stage B2 (types): enums from e2m 10E8 / 10E6 and SPN 695, the blocked message bitfield, the e2m S fields
as short, the source configuration pointers and table, the ETC2 receive layout from the stores, 0x5c39a, the
lookup's return type and the TSC1 handler's sender local.
Facts (all quoted before writing):
- e2m 10E8 +4 / 10E6 +0 Jcomm_*_Control_Mode 0 disable / 1 speed / 2 torque / 3 limit = SPN 695 -> TSC1_OVERRIDE_MODE
  (it existed with the SPN 695 members but size 1 and unused; the four words are word, so size 2).
- e2m 10E8 +2 / 10E6 +2 Jcomm_*_Control_Device_Indicator 0 none / 1 trans / 2 ABS / 3 ASR / 4 unknown; the
  lookup returns 1 / 2 / 3 / 4 for the transmission / ABS / ASR / other source address. 0x40adf6: lha x5, sth x5.
- e2m 10E8 +1A / +1C Jcomm_*_Network_Type 0 = J1922 / 1 = J1939 -> CONTROL_NETWORK.
- e2m 10E8 +24 J1939_Block_Message bit 0 TSC1 destination engine / bit 1 TSC1 destination retarder / bit 2 ETC1.
- e2m S: 10E8 +E Jcomm_Engine_Torque_Command, +28 Jcomm_Engine_Output_Net_Torque (lha x2 at 0x40ae1c).
- ETC2: sth r9,-22132(r10) @ 0x22cf0 (the previous ratio) and sth r11,-22132(r12) @ 0x22d2c (init) write a word at
  0x3fa98c (+0xa, typed byte auxiliary_state: the _10_2_ piece); stb 2(r5) / stb 1(r5) + lhz 1(r5) @ 0x22cb4-0x22cc4
  with r5 = 0x3fa98e assemble the SPN 526 ratio at 0x3fa98f (+0xd).
- 0x5c39a: lhz r11,-15462(r11) @ 0x1b544 / 0x1fea4; 0x40adf4: sth r11,-21004(r12) @ 0x22f24.
usage: apply_r6b2_types.py <repo> [--dry-run]"""
import csv
import io
import os
import re
import sys

repo = os.path.abspath(sys.argv[1])
dry = "--dry-run" in sys.argv
out = os.path.join(repo, "firmware", "CM848_S90140.06_analysis", "output")
P, R, C = "j1939_powertrain_control_state_t", "j1939_powertrain_messages_received_t", "tsc1_source_configuration_t"
SD_TYPES = {
    (P, "tsc1_override_control_mode"): "TSC1_OVERRIDE_MODE",
    (P, "tsc1_controlling_data_link"): "CONTROL_NETWORK",
    (P, "out_of_gear_network_type"): "CONTROL_NETWORK",
    (P, "tsc1_requested_percent_torque_times_256"): "short",
    (P, "engine_net_output_torque"): "short",
    (P, "tsc1_matched_source_configuration_ptr"): "tsc1_source_configuration_t*",
    (P, "retarder_tsc1_source_configuration_ptr"): "tsc1_source_configuration_t*",
    (C, "data_link"): "CONTROL_NETWORK",
}
SD_REPLACE = {
    (P, "j1939_blocked_message_bits"): [
        ("tsc1_engine_blocked", "bitfield:1@0", "2",
         "e2m 10E8 +24 J1939_Block_Message bit 0 'TSC1 destination engine': set when an engine TSC1 sender hit its "
         "time limit (it went into the ignored request list); processEngineTsc1Request clears it on override disabled"),
        ("tsc1_retarder_blocked", "bitfield:1@1", "0",
         "J1939_Block_Message bit 1 'TSC1 Destination retarder': set when an engine retarder TSC1 sender hit its time "
         "limit"),
        ("etc1_high_idle_override_blocked", "bitfield:1@2", "0",
         "J1939_Block_Message bit 2 'ETC1': set when the high idle override hit its time limit (the recovery: e2m "
         "Jcomm_Recovery_Time); cleared by ETC1 SPN 606 = 00 and when high_idle_override_timeout_timer runs out"),
    ],
    (R, "auxiliary_state"): [
        ("etc2_actual_gear_ratio_previous", "word", "2",
         "etc2_actual_gear_ratio before the latest valid ETC2 (sth @ 0x22cf0; cm848_initEtc2Handler zeroes it, sth @ "
         "0x22d2c); no reader in the decompile (was auxiliary_state, a byte: the word store rendered as the _10_2_ "
         "piece)"),
    ],
    (R, "reserved_0b"): [
        ("reserved_0c", "byte", "1", "no access found"),
        ("etc2_spn526_actual_gear_ratio", "word", "2",
         "ETC2 bytes 2-3 (SPN 526 transmission actual gear ratio, 0.001 per bit) as received: cm848_j1939ProcessPgn61445Etc2 "
         "stores byte 3 at +0xd and byte 2 at +0xe and reads the word (lhz @ 0x22cc4); below 0xfb00 it becomes "
         "etc2_actual_gear_ratio (was bytes 2-3 of reserved_0b)"),
        ("reserved_0f", "byte", "5", "no access found"),
    ],
}
GV_TYPES = {"0x003faf34": "TSC1_OVERRIDE_MODE", "0x003faf3b": "TSC1_OVERRIDE_MODE", "0x0040ad5a": "TSC1_OVERRIDE_MODE",
            "0x0040adf6": "J1939_CONTROL_DEVICE", "0x0040ad5c": "J1939_CONTROL_DEVICE",
            "0x003faf36": "CONTROL_NETWORK", "0x0040adf4": "word",
            "0x0005c3b4": "tsc1_source_configuration_t[10]"}
GV_NEW = ("0x0005c39a", "j1939_high_idle_override_speed", "word",
          "e2m 10E7 +18 Jcomm_High_Idle_Override_Speed (RPM 0.125: 'speed to which HSG ref should be set when Jcomm "
          "High Idle override commanded'). selectEngineSpeedLimit applies it while "
          "j1939_powertrain_control_state.high_idle_override_active_flag is 1; the EC1 builder sends it as point 7 (SPN "
          "533 maximum momentary engine override speed). Word (lhz @ 0x1b544 / 0x1fea4)")
GV_ALIAS = {"0x003fa98c": ("j1939_powertrain_messages_received.auxiliary_state",
                           "j1939_powertrain_messages_received.etc2_actual_gear_ratio_previous"),
            "0x0040ae18": ("j1939_powertrain_control_state.j1939_blocked_message_bits",
                           "j1939_powertrain_control_state.tsc1_engine_blocked")}
ENUM_SIZE = {"TSC1_OVERRIDE_MODE": "2"}
ENUM_COMMENTS = {
    ("TSC1_OVERRIDE_MODE", "0"): "SPN 695 00 = override disabled (e2m Jcomm_Engine_Control_Mode / Jcomm_Retarder_Control_Mode 0 = disable)",
    ("TSC1_OVERRIDE_MODE", "1"): "SPN 695 01 = speed control: the engine governs to the requested speed (e2m 1 = speed)",
    ("TSC1_OVERRIDE_MODE", "2"): "SPN 695 10 = torque control (e2m 2 = torque)",
    ("TSC1_OVERRIDE_MODE", "3"): "SPN 695 11 = speed and torque limit control (e2m 3 = limit)",
}
ENUM_NEW = [
    ("J1939_CONTROL_DEVICE", "0", "J1939_CONTROL_DEVICE_NONE", "e2m Jcomm_Engine_Control_Device_Indicator 0 = NONE"),
    ("J1939_CONTROL_DEVICE", "1", "J1939_CONTROL_DEVICE_TRANSMISSION", "1 = TRANS: the sender is j1939_transmission_source_address"),
    ("J1939_CONTROL_DEVICE", "2", "J1939_CONTROL_DEVICE_ANTI_LOCK_BRAKES", "2 = ABS: j1939_anti_lock_brake_source_address"),
    ("J1939_CONTROL_DEVICE", "3", "J1939_CONTROL_DEVICE_ANTI_SLIP_REGULATION", "3 = ASR: j1939_anti_slip_regulation_source_address"),
    ("J1939_CONTROL_DEVICE", "4", "J1939_CONTROL_DEVICE_UNKNOWN", "4 = UNKNOWN: any other source address"),
    ("CONTROL_NETWORK", "0", "CONTROL_NETWORK_J1922", "e2m Jcomm_Engine_Control_Network_Type 0 = J1922 (on the J1708 link)"),
    ("CONTROL_NETWORK", "1", "CONTROL_NETWORK_J1939", "1 = J1939"),
]
FD_EDIT = {("0x00053a4c", "return"): ("J1939_CONTROL_DEVICE",
                                      "the control device of the source address (1 transmission / 2 ABS / 3 ASR / 4 other)"),
           ("0x00053a4c", "0"): (None, "the J1939 source address to classify")}
LV_EDIT = ("0x00022d60,processEngineTsc1Request,cVar1,source_address,char,",
           ["0x00022d60", "processEngineTsc1Request", "bVar1", "sender_source_address", "byte",
            "the TSC1 sender's source address (msg->source_address)"])
problems = []


def row_of(line):
    return next(csv.reader([line]))


def text_of(row):
    s = io.StringIO()
    csv.writer(s, lineterminator="").writerow(row)
    return s.getvalue()


CPP = open(os.path.join(out, "cm848_rom.ghidra.cpp")).read()
for _, rows in SD_REPLACE.items():
    for f, *_ in rows:
        if f.startswith("reserved_"):
            continue
        if re.search(r"(?<![A-Za-z0-9_])" + f + r"(?![A-Za-z0-9_])", CPP):
            problems.append(f"field {f} is taken")
for _, _, m, _ in ENUM_NEW:
    if re.search(r"(?<![A-Za-z0-9_])" + m + r"(?![A-Za-z0-9_])", CPP):
        problems.append(f"enum member {m} is taken")
if re.search(r"\bj1939_high_idle_override_speed\b", CPP) or re.search(r"\bsender_source_address\b", CPP):
    problems.append("a new name is taken")

# structure_definitions.csv
sd_path = os.path.join(out, "structure_definitions.csv")
sd, done = [], set()
for line in open(sd_path).read().split("\n"):
    if not line or line.startswith("#"):
        sd.append(line)
        continue
    row = row_of(line)
    key = (row[0], row[2]) if len(row) > 2 else None
    if key in SD_TYPES:
        row[3] = SD_TYPES[key]
        done.add(key)
        sd.append(text_of(row))
    elif key in SD_REPLACE:
        for f, t, size, comment in SD_REPLACE[key]:
            sd.append(text_of([row[0], row[1], f, t, size, comment, "", "verified"]))
        done.add(key)
    else:
        sd.append(line)
missing = (set(SD_TYPES) | set(SD_REPLACE)) - done
if missing:
    problems.append(f"struct rows not found: {missing}")

# global_variables.csv
gv_path = os.path.join(out, "global_variables.csv")
gv, gv_done, inserted = [], set(), False
for line in open(gv_path).read().split("\n"):
    a = line.split(",", 1)[0]
    if a in GV_ALIAS and line.startswith(a + "," + GV_ALIAS[a][0] + ","):
        line = line.replace(GV_ALIAS[a][0], GV_ALIAS[a][1], 1)
        gv_done.add(a + "alias")
    if a in GV_TYPES and not line.startswith("#"):
        row = row_of(line)
        if len(row) > 2 and not row[1].count("."):
            row[2] = GV_TYPES[a]
            line = text_of(row)
            gv_done.add(a)
    if not inserted and re.match(r"^0x[0-9a-f]{8},", line) and int(a, 16) > int(GV_NEW[0], 16) and \
            int(a, 16) < 0x60000 and int(a, 16) > 0x5c000:
        gv.append(text_of(list(GV_NEW)))
        inserted = True
    gv.append(line)
if not inserted:
    problems.append("0x5c39a not inserted")
missing = (set(GV_TYPES) | {a + "alias" for a in GV_ALIAS}) - gv_done
if missing:
    problems.append(f"global rows not found: {missing}")

# enums.csv
en_path = os.path.join(out, "enums.csv")
en, last_tsc1 = [], None
for line in open(en_path).read().split("\n"):
    if line.startswith("TSC1_OVERRIDE_MODE,"):
        row = row_of(line)
        row[4] = ENUM_SIZE["TSC1_OVERRIDE_MODE"]
        row[3] = ENUM_COMMENTS[("TSC1_OVERRIDE_MODE", row[1])]
        line = text_of(row)
        last_tsc1 = len(en)
    en.append(line)
if last_tsc1 is None:
    problems.append("TSC1_OVERRIDE_MODE not found")
else:
    new_rows = ["# J1939 control device (e2m 10E8 +2 Jcomm_Engine_Control_Device_Indicator / 10E6 +2 the retarder's):"
                " cm848_lookupJ1939ControlDevice", ]
    new_rows += [text_of([e, v, m, c, "2"]) for e, v, m, c in ENUM_NEW if e == "J1939_CONTROL_DEVICE"]
    new_rows += ["# Control network (e2m 10E8 +1A Jcomm_Engine_Control_Network_Type / +1C Jcomm_Out_of_Gear_Network_Type)"]
    new_rows += [text_of([e, v, m, c, "2"]) for e, v, m, c in ENUM_NEW if e == "CONTROL_NETWORK"]
    en[last_tsc1 + 1:last_tsc1 + 1] = new_rows
for (e, v), c in ENUM_COMMENTS.items():
    if "," in c:
        problems.append(f"comma in enum comment {e} {v}")
for _, _, _, c in ENUM_NEW:
    if "," in c:
        problems.append(f"comma in enum comment: {c}")

# function_definitions.csv
fd_path = os.path.join(out, "function_definitions.csv")
fd, fd_done = [], set()
for line in open(fd_path).read().split("\n"):
    if line.startswith("0x00053a4c,"):
        row = row_of(line)
        key = (row[0], row[2])
        if key in FD_EDIT:
            t, c = FD_EDIT[key]
            if t:
                row[4] = t
            row[5] = c
            line = text_of(row)
            fd_done.add(key)
    fd.append(line)
if fd_done != set(FD_EDIT):
    problems.append(f"function_definitions rows not found: {set(FD_EDIT) - fd_done}")

# local_variables.csv
lv_path = os.path.join(out, "local_variables.csv")
lv_text = open(lv_path).read()
lv_lines = lv_text.split("\n")
idx = [i for i, l in enumerate(lv_lines) if l.startswith(LV_EDIT[0])]
if len(idx) != 1:
    problems.append(f"local row matches: {len(idx)}")
else:
    lv_lines[idx[0]] = text_of(LV_EDIT[1])

if problems:
    print("\n".join("PROBLEM " + p for p in problems))
    sys.exit(1)
print(f"struct rows: {len(done)}; global rows: {len(gv_done)} + 0x5c39a; enums: TSC1_OVERRIDE_MODE size 2 + "
      f"{len(ENUM_NEW)} new members; function_definitions: {len(fd_done)}; local: 1")
if dry:
    sys.exit(0)
open(sd_path, "w").write("\n".join(sd))
open(gv_path, "w").write("\n".join(gv))
open(en_path, "w").write("\n".join(en))
open(fd_path, "w").write("\n".join(fd))
open(lv_path, "w").write("\n".join(lv_lines))
print("written")

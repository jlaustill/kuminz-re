"""Round 73 stage B: the development mode functions and the EEPROM mirror commit are the same functions in CM848 and
CM550 (one shared unprefixed name each), and two of the variables they set get CM848's names in CM550. Idempotent; keeps
line endings. The twin proofs (both bodies):
- enterDevelopmentMode (CM848 0x21668 / CM550 0x118b2 cm550_waterInFuelFaultClear): RAM refresh off, development mode
  on, run location to development (CM848 0xea / CM550 0xeaea), result 0.
- exitDevelopmentMode (0x21624 / 0x1188c cm550_waterInFuelDetectionStateInit): only while development mode is on - off,
  RAM refresh on, run location normal (0xee / 0xeeee), 0; else 4.
- forceExitDevelopmentMode (0x21694 / 0x118cc cm550_FUN_000118cc): 7 while the not-safe state is 1; RAM refresh on; when
  the run location is development: normal and development mode off; 0.
- commitEepromMirrorToEeprom (0x21918 / 0x11a74 cm550_FUN_00011a74): 7 while the not-safe state is 1; the mirror in
  16-byte chunks through the EEPROM byte write queue (cm848_queueEepromByteWrites / cm550_circularBufferWrite); up to
  16000 waits for the queue.
- CM550 0x80dc6c (was calibration_data_valid_flag) = ram_refresh_enable: a word (tst.w / clr.w / cmpi.w #1) written 0 / 1
  only - by the three development mode functions as above, and read by the writer's EEPROM queue gate as in CM848.
- CM550 0x80dc90 (was water_in_fuel_state_code) = run_location: a word (cmpi.w #0xeaea / move.w #0xeeee through a0)
  written 0xeeee / 0xeaea only - 0xeeee also by the boot / power-down code (vp44_mainSystemInitialization ...), as CM848.
Not renamed: CM550 0x80dc92 (_diagnostic_session_state) - its value 1 is CM848's not-safe state, but CM550 also writes 2
(cm550_fuel_limit_arbitrator: stopped + a switch bit), which CM848 does not have. The development mode flag itself
(0x80de30) still renders as j1708_transmit_buffer_2_32_ddc6.count_106 (a struct instance covers it - a lead).
usage: apply_r73b.py <repo> <map_cm848.csv> <map_cm550.csv>"""
import os
import sys

repo, map8, map5 = os.path.abspath(sys.argv[1]), sys.argv[2], sys.argv[3]
O8 = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")
O5 = os.path.join(repo, "firmware/CM550_J90350.00_analysis/output")
R = "PR #53 round 73"
EOL = {}


def read(p):
    s = open(p, newline="").read()
    EOL[p] = "\r\n" if "\r\n" in s else "\n"
    return s.replace("\r\n", "\n")


def write(p, s):
    open(p, "w", newline="").write(s.replace("\n", EOL[p]))


def edit(p, old, new):
    s = read(p)
    if new in s:
        return
    assert s.count(old) == 1, (os.path.basename(p), old[:90], s.count(old))
    write(p, s.replace(old, new))


FLAG = "the development mode flag at 0x80de30 (still rendered as j1708_transmit_buffer_2_32_ddc6.count_106)"
PAIRS = [  # CM848 address, CM848 old, CM550 address, CM550 old, shared name, CM550 plate
    ("0x00021668", "cm848_enterDevelopmentMode", "0x000118b2", "cm550_waterInFuelFaultClear", "enterDevelopmentMode",
     f"Enters development mode (J1708 command 3 subcommand 0x40 after the security key): ram_refresh_enable off / {FLAG} "
     "set / run_location RUN_LOCATION_DEVELOPMENT; result 0"),
    ("0x00021624", "cm848_exitDevelopmentMode", "0x0001188c", "cm550_waterInFuelDetectionStateInit",
     "exitDevelopmentMode",
     f"Leaves development mode: only while {FLAG} is 1 - clears it / ram_refresh_enable on / run_location "
     "RUN_LOCATION_NORMAL / result 0; else 4"),
    ("0x00021694", "cm848_forceExitDevelopmentMode", "0x000118cc", "cm550_FUN_000118cc", "forceExitDevelopmentMode",
     "Forces an exit from development mode (J1708 command 3 subcommand 0x41 after the security key): 7 while the 0x80dc92 "
     f"state is 1 (CM848: not safe to program); else ram_refresh_enable on and - when run_location is "
     f"RUN_LOCATION_DEVELOPMENT - run_location RUN_LOCATION_NORMAL and {FLAG} cleared; result 0"),
    ("0x00021918", "cm848_commitEepromMirrorToEeprom", "0x00011a74", "cm550_FUN_00011a74", "commitEepromMirrorToEeprom",
     "Writes the EEPROM mirror 0x803b0a-0x804155 back to the EEPROM: 7 while the 0x80dc92 state is 1 (CM848: not safe to "
     "program); else 16-byte chunks through cm550_circularBufferWrite (the EEPROM byte write queue) with up to 16000 "
     "waits for the queue each; 0"),
]

# ---- function_renames ---------------------------------------------------------------------------------------------------
F8, F5 = os.path.join(O8, "function_renames.csv"), os.path.join(O5, "function_renames.csv")
for a8, old8, a5, old5, new, plate5 in PAIRS:
    edit(F8, f"\n{a8},{old8},", f"\n{a8},{new},The same function as CM550 {int(a5, 16):#x} (shared name; was {old8}; "
                                f"{R}). ")
    edit(F5, f"\n{a5},{old5}\n", f"\n{a5},{new},{plate5}. The same function as CM848 {int(a8, 16):#x} (shared name; "
                                 f"was {old5}; {R}).\n")
# ---- CM848 function_definitions / local_variables: the name column ------------------------------------------------------
for name in ("function_definitions.csv", "local_variables.csv"):
    p = os.path.join(O8, name)
    lines = read(p).split("\n")
    for i, l in enumerate(lines):
        for a8, old8, _, _, new, _ in PAIRS:
            if l.startswith(f"{a8},{old8},"):
                lines[i] = l.replace(f",{old8},", f",{new},", 1)
    write(p, "\n".join(lines))
# ---- CM550 prototypes: a byte result (the bodies returned 'in_D0 & 0xffffff00' / a uint for 0 / 4 / 7) ----------------
D5 = os.path.join(O5, "function_definitions.csv")
lines = read(D5).split("\n")
for a8, _, a5, _, new, _ in PAIRS:
    row = (f"{a5},{new},return,,byte,The result as CM848's J1939_DIAGNOSTIC_RESULT numbers (0 accepted / 4 cannot "
           f"comply / 7 not safe) - a byte so the 4-byte register does not show ({R})")
    if row not in lines:
        while lines and lines[-1] == "":
            lines.pop()
        lines.append(row)
write(D5, "\n".join(lines).rstrip("\n") + "\n")
# ---- CM550 globals and their enums --------------------------------------------------------------------------------------
G5 = os.path.join(O5, "global_variables.csv")
edit(G5, "0x0080dc6c,calibration_data_valid_flag,undefined,\n",
     "0x0080dc6c,ram_refresh_enable,RAM_REFRESH_STATE,The RAM refresh switch (a word - tst.w / clr.w / cmpi.w #1; written "
     "0 / 1 only): off in development mode / on again by exitDevelopmentMode and forceExitDevelopmentMode; gates the "
     "writer's EEPROM byte write queue - CM848's ram_refresh_enable (e2m 10C7 RAM_Refresh_Enable) by the twin functions "
     f"(was calibration_data_valid_flag; {R})\n")
edit(G5, "0x0080dc90,water_in_fuel_state_code,undefined,\n",
     "0x0080dc90,run_location,RUN_LOCATION,Where the code runs (a word - cmpi.w #0xeaea / move.w #0xeeee; written 0xeeee / "
     "0xeaea only): RUN_LOCATION_DEVELOPMENT in development mode / RUN_LOCATION_NORMAL at boot and power-down and on "
     f"leaving it - CM848's run_location (e2m 0010 RUN_LOC) by the twin functions (was water_in_fuel_state_code; {R})\n")
E5 = os.path.join(O5, "enums.csv")
ENUM = [
    f"# RAM_REFRESH_STATE / RUN_LOCATION - CM848's enums for ram_refresh_enable (0x80dc6c) and run_location (0x80dc90); "
    f"CM550 holds both as words, so RUN_LOCATION's bytes come doubled ({R})",
    "RAM_REFRESH_STATE,0,RAM_REFRESH_DISABLED,RAM refresh off (development mode - set by enterDevelopmentMode),2",
    "RAM_REFRESH_STATE,1,RAM_REFRESH_ENABLED,RAM refresh on - set by exitDevelopmentMode / forceExitDevelopmentMode and "
    "the boot code,2",
    "RUN_LOCATION,0xeaea,RUN_LOCATION_DEVELOPMENT,Development - set by enterDevelopmentMode (CM848: 0xea),2",
    "RUN_LOCATION,0xeeee,RUN_LOCATION_NORMAL,Normal - set at boot / power-down and on leaving development mode (CM848: "
    "0xee),2",
]
lines = read(E5).split("\n")
if ENUM[1] not in lines:
    while lines and lines[-1] == "":
        lines.pop()
    lines += ENUM + [""]
    write(E5, "\n".join(lines))

with open(map8, "w") as fh:
    fh.write("address,name,old_label,kind,dims\n")
    for a8, old8, _, _, new, _ in PAIRS:
        fh.write(f"{a8},{new},{old8},function,1\n")
with open(map5, "w") as fh:
    fh.write("address,name,old_label,kind,dims\n")
    for _, _, a5, old5, new, _ in PAIRS:
        fh.write(f"{a5},{new},{old5},function,1\n")
    fh.write("0x0080dc6c,ram_refresh_enable,calibration_data_valid_flag,global,1\n"
             "0x0080dc90,run_location,water_in_fuel_state_code,global,1\n")
print("round 73 stage B applied")

"""Apply the FUELING_STATE enum change to the CM848 CSVs (2026-11-19).

Renames the ENGINE_OPERATING_MODE enum to FUELING_STATE (members ENGINE_OPERATING_MODE_* -> FUELING_STATE_*), adds the
members 4 / 9 / 10 / 11 / 12, types the carriers of the code with it, renames 0x40b67c and splits the 0x3fb526 dword.
Every old row is asserted before it is replaced, so a stale checkout fails loudly instead of editing the wrong row.
Usage: apply_fueling_state.py <CM848 output dir>"""
import os
import sys

OUT = sys.argv[1]


def replace_lines(path, replacements):
    """replacements: list of (old_line, new_lines) - old_line must occur exactly once (whole line, no newline)."""
    with open(path, newline="") as f:
        text = f.read()
    eol = "\r\n" if "\r\n" in text else "\n"
    lines = text.split(eol)
    for old, new in replacements:
        hits = [i for i, line in enumerate(lines) if line == old]
        if len(hits) != 1:
            sys.exit(f"{os.path.basename(path)}: expected one line {old[:90]!r}, found {len(hits)}")
        i = hits[0]
        lines[i:i + 1] = new if isinstance(new, list) else [new]
    with open(path, "w", newline="") as f:
        f.write(eol.join(lines))


# ---------------------------------------------------------------- enums.csv
enums = os.path.join(OUT, "enums.csv")
with open(enums, newline="") as f:
    old_rows = {line.split(",")[2]: line for line in f.read().splitlines() if line.startswith("ENGINE_OPERATING_MODE,")}
OLD_HEADER = ("# Engine Operating Mode (engine_operating_mode 0x40b000): which governor drives the fuel this pass "
              "(corrected 2026-11-17 from every store of 0x40b000; 37 and 38 are only compared - never stored - so they "
              "have no member)")


def renamed(member):
    """The old row with the enum and member renamed; its comment and size stay."""
    row = old_rows[member]
    enum, value, name, rest = row.split(",", 3)
    return ",".join(["FUELING_STATE", value, name.replace("ENGINE_OPERATING_MODE_", "FUELING_STATE_"), rest])


NEW_ENUM = [
    "# Fueling State (renamed 2026-11-19 from ENGINE_OPERATING_MODE): the code of the algorithm in control of the fuel - "
    "one numbering for every fueling stage (Cummins e2m FSDSFLST user fueling state 1-8 / 38 - FSGVFLST governed "
    "fueling state 1-12 - FSLMFLST limited state 13-41 - FSFNFLST final state 1-41). Carriers: engine_operating_mode "
    "(the user stage; members 1-8 / 30 corrected 2026-11-17 from every store of 0x40b000) -> "
    "operating_mode_governor_output.mode_code (power take-off selection adds 4) -> governor_fuel_demand_working_mode "
    "(cruise adds 9) -> governor_fuel_demand_mode (the governed stage adds 10 / 11 / 12; cm848_processProtectionSelection "
    "then mixes it with the 13-41 limiter codes of torque_derate_fuel_source_code). 37 and 38 are only compared - never "
    "stored - so they have no member; the 13-41 codes have none yet",
    renamed("ENGINE_OPERATING_MODE_NOT_SELECTED"),
    renamed("ENGINE_OPERATING_MODE_TSC1_TORQUE_CONTROL"),
    renamed("ENGINE_OPERATING_MODE_TSC1_SPEED_CONTROL"),
    "FUELING_STATE,4,FUELING_STATE_POWER_TAKE_OFF,operating_mode_governor_output.mode_code only "
    "(cm848_updateGovernorFromProtection): governor_fuel_demand_command (another speed governor - the PID of "
    "cm848_calculateProtectionLoadCompensation) replaces the user fueling while governor_fuel_active_flag is 1 and "
    "j1939_governor_feature_cal bit 0x10 is set (modes 5 / 6 always; 7 / 8 / 30 unless the user fueling is larger and "
    "governor_feature_config_word bit 0x2000 is set). Power take-off is e2m-derived: block 1265 PTTHDQRP / PTTHOV / "
    "PTSLFL / PTSLFLST line up with 0x40af56 / 0x40af58 / 0x40af5a / 0x40af5c; the code alone shows only the "
    "replacement,2",
    renamed("ENGINE_OPERATING_MODE_CALIBRATED_FIXED_FUEL_DEMAND"),
    renamed("ENGINE_OPERATING_MODE_ACCELERATOR_PEDAL_FAULT"),
    renamed("ENGINE_OPERATING_MODE_VARIABLE_SPEED_GOVERNOR"),
    renamed("ENGINE_OPERATING_MODE_DUAL_AXIS_FUEL_DEMAND_TABLE"),
    "FUELING_STATE,9,FUELING_STATE_CRUISE_CONTROL,governor_fuel_demand_working_mode only "
    "(cm848_calculateProtectionLevelLimit): cruise control is engaged and the cruise PID fuel governor_pid_fuel_output "
    "replaces the user fueling; governor_cruise_setpoint_calc and protectionRampRateControl run their cruise branches "
    "(cruise_control_state set / resume / accelerate / decelerate) in 9,2",
    "FUELING_STATE,10,FUELING_STATE_VEHICLE_SPEED_LIMIT,governor_fuel_demand_mode (cm848_processProtectionRampControl): "
    "the vehicle speed limit fuel cruise_fuel_demand_setpoint (cm848_processProtectionRampTimer: "
    "cruise_speed_setpoint_adjusted - the vehicle speed - against cruise_speed_limit_working; no limit while "
    "j1939_governor_feature_cal bit 0x80 is clear) is the smallest demand; protectionRampRateControl runs the "
    "limit-minus-speed error in 10,2",
    "FUELING_STATE,11,FUELING_STATE_LOW_SPEED_GOVERNOR,governor_fuel_demand_mode (cm848_processProtectionRampControl "
    "and the initial value of cm848_initFuelFilterCoefficients): at or below the governor speed the low speed governor "
    "asks for more fuel than the selected demand (a max select); only in 11 does cm848_processSpeedGovernorControl "
    "write its fuel into governor_fuel_demand_value (e2m FSGVFL: fueling as limited by limiting governors LSG / HSG) "
    "and governor_request_active_flag latch. RAM dump: 11,2",
    "FUELING_STATE,12,FUELING_STATE_HIGH_SPEED_GOVERNOR,governor_fuel_demand_mode (cm848_processProtectionRampControl): "
    "high_speed_governor_fueling is the smallest demand and becomes governor_fuel_demand_value; runHighSpeedGovernorPid "
    "resets its integrator in 12 (the same compare as CM550 0x1ce7c on FSGVFLST),2",
    renamed("ENGINE_OPERATING_MODE_ALL_SPEED_GOVERNOR_RESTORE"),
]
assert len(old_rows) == 8, sorted(old_rows)
assert not any("," in line.split(",", 3)[3].rsplit(",", 1)[0] for line in NEW_ENUM if not line.startswith("#")), \
    "an enum comment holds a comma"
replace_lines(enums, [(OLD_HEADER, NEW_ENUM[0])] + [(old_rows[m], []) for m in old_rows])
# the eight old member rows are gone; put the new block right after the header comment
with open(enums, newline="") as f:
    text = f.read()
eol = "\r\n" if "\r\n" in text else "\n"
lines = text.split(eol)
at = lines.index(NEW_ENUM[0]) + 1
lines[at:at] = NEW_ENUM[1:]
with open(enums, "w", newline="") as f:
    f.write(eol.join(lines))

# ---------------------------------------------------------------- global_variables.csv
globals_csv = os.path.join(OUT, "global_variables.csv")
EOMP_OLD = [line for line in open(globals_csv) if line.startswith("0x003fa0ec,engine_operating_mode_previous_pass,word,")]
assert len(EOMP_OLD) == 1
eomp_old = EOMP_OLD[0].rstrip("\r\n")
eomp_new = eomp_old.replace(",word,", ",FUELING_STATE,", 1) + " | typed FUELING_STATE 2026-11-19 (it holds engine_operating_mode codes; lha / sth word)"
replace_lines(globals_csv, [
    (eomp_old, eomp_new),
    ("0x003fb524,governor_fuel_demand_mode_prev,word,",
     "0x003fb524,governor_fuel_demand_mode_prev,FUELING_STATE,governor_fuel_demand_mode at the start of the pass: "
     "cm848_processProtectionRampControl copies it (lhz @ 0x4045c / sth @ 0x40460) before the arbitration and reads it "
     "for the low speed governor hold (11) and for the first pass of cruise control or the vehicle speed limit (9 / 10 "
     "after another state)"),
    ("0x003fb526,governor_pid_integral_working,dword,",
     "0x003fb526,governor_fuel_demand_working_mode_prev,FUELING_STATE,governor_fuel_demand_working_mode at the start of "
     "the pass (sth @ 0x40474 in cm848_processProtectionRampControl; nothing reads it) (was governor_pid_integral_working "
     "- a dword over this word and fuel_demand_enable_sync_flag_shadow)"),
    ("0x003fb528,fuel_demand_enable_sync_flag_shadow,,",
     "0x003fb528,fuel_demand_enable_sync_flag_shadow,word,fuel_demand_enable_sync_flag at the end of the last pass "
     "(lhz @ 0x4064c / sth @ 0x406b8 in cm848_processProtectionRampControl); a first pass of 9 / 10 with it 0 runs "
     "protectionRampRateControl. Was the upper half of the governor_pid_integral_working dword"),
    ("0x0040a154,governor_fuel_demand_mode,word,",
     "0x0040a154,governor_fuel_demand_mode,FUELING_STATE,The governed fueling state (Cummins FSGVFLST - e2m block 1045 +2: "
     "indicator as to which algorithm is in control of fueling after it is governed - 1-12; CM550 0x0080a8f2; "
     "governor_fuel_demand_value / governor_request_active_flag are FSGVFL / LSLOFG at +0 / +4). Set only by "
     "cm848_processProtectionRampControl: the smallest of the user demand (state governor_fuel_demand_working_mode), "
     "high_speed_governor_fueling (12) and the vehicle speed limit fuel (10), then the low speed governor (11) when it "
     "asks for more fuel at or below its speed; 11 at start. All 35 accesses are 16-bit whole-value compares or copies "
     "(30 lha / 2 lhz / 3 sth). RAM dump: 11"),
    ("0x0040b000,engine_operating_mode,ENGINE_OPERATING_MODE,",
     "0x0040b000,engine_operating_mode,FUELING_STATE,The user fueling state (Cummins FSDSFLST 1-8 / 38): which user "
     "fueling algorithm runs this pass; copied into operating_mode_governor_output.mode_code. RAM dump: 7 (the enum was "
     "ENGINE_OPERATING_MODE until 2026-11-19)"),
    ("0x0040b67c,governor_pid_integral_snapshot,word,",
     "0x0040b67c,governor_fuel_demand_working_mode,FUELING_STATE,State of governor_fuel_demand_working: "
     "cm848_calculateProtectionLevelLimit sets it to operating_mode_governor_output.mode_code or 9 (cruise control); "
     "cm848_processProtectionRampControl passes it on to governor_fuel_demand_mode when the user demand is the smallest "
     "(lha @ 0x404c0 / 0x40500). RAM dump: 7 (was governor_pid_integral_snapshot - it never holds a PID integral)"),
    ("0x003fd048,cruise_fuel_demand_mode_prev,word,prev governor_fuel_demand_mode for cruise PID path (ROM-aliased)",
     "0x003fd048,cruise_fuel_demand_mode_prev,FUELING_STATE,governor_fuel_demand_mode at the end of "
     "protectionOutputActuatorControl (lhz @ 0x525db4) for the next cruise pass; protectionRampRateControl compares it "
     "with 1 / 2 / 7 / 8 / 9 / 37 / 38 (ROM-aliased)"),
])

# ---------------------------------------------------------------- structure_definitions.csv
structs = os.path.join(OUT, "structure_definitions.csv")
replace_lines(structs, [
    ("operating_mode_governor_output_t,0x0040af5a,fuel_demand,word,2,Fuel demand of the engine operating mode governor "
     "as the output stages see it (engine_operating_mode_fuel_demand or the protection limit) (was proportional_gain),,"
     "verified",
     "operating_mode_governor_output_t,0x0040af5a,fuel_demand,word,2,Fuel demand of the engine operating mode governor "
     "as the output stages see it: engine_operating_mode_fuel_demand or governor_fuel_demand_command (the power take-off "
     "fuel - Cummins PTSLFL per e2m block 1265 +4) (was proportional_gain),,verified"),
    ("operating_mode_governor_output_t,0x0040af5a,mode_code,word,2,Copy of engine_operating_mode (1 2 5 6 7 8 30 37 38) "
     "or 4 when the output is replaced by the limit in cm848_updateGovernorFromProtection (was integral_term),,verified",
     "operating_mode_governor_output_t,0x0040af5a,mode_code,FUELING_STATE,2,The user fueling state after the power "
     "take-off selection (Cummins PTSLFLST per e2m block 1265 +6 - 1-8): engine_operating_mode (1 2 5 6 7 8 30 37 38) "
     "or FUELING_STATE_POWER_TAKE_OFF when cm848_updateGovernorFromProtection lets governor_fuel_demand_command "
     "replace the fuel (was integral_term),,verified"),
])
print("applied")

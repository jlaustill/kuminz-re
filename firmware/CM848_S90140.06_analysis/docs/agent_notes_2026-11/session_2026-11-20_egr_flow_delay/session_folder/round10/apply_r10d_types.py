"""Round 10 stage D (types). String edits only for global_variables.csv (commas unquoted); enums.csv and
structure_definitions.csv are quote-aware (comments with commas go in double quotes, none inside).
- DIAGNOSTIC_MONITOR_STATE (size 2) from the e2m value list the 48RE monitor states share (TCC_Rationality_Monitor_State,
  TTSR_Monitor_State, TVA_AZ_Monitor_Status: 0000=NORUN 0001=RUN 0002=CMPPS 0003=CMPFL 0004=ABORT), on the six monitor
  state words that store exactly those values with that meaning.
- The four limp-home bytes keep byte fields (wave 11 reverted a bitfield on limp_home_flags_4: Ghidra 12.1 prints the
  | / & updates as ._N_1_ pieces); their comments get the e2m 8C19 bit map with each bit's setter.
usage: apply_r10d_types.py <repo>"""
import os
import re
import sys

repo = os.path.abspath(sys.argv[1])
out = os.path.join(repo, "firmware", "CM848_S90140.06_analysis", "output")
ENUM = "DIAGNOSTIC_MONITOR_STATE"
MEMBERS = [
    (0, "NOT_RUN", "e2m NORUN: the monitor has not run (initializers store 0)"),
    (1, "RUNNING", "e2m RUN: the enable conditions hold and the test is running"),
    (2, "PASSED", "e2m CMPPS (complete, passed): the monitor cleared its fault"),
    (3, "FAILED", "e2m CMPFL (complete, failed): the monitor set its fault"),
    (4, "ABORTED", "e2m ABORT: a related fault or condition stopped the monitor"),
]
STATES = {
    "0x0040b55c": "governor_pressure_rationality_monitor_state",
    "0x0040b560": "governor_pressure_zero_check_state",
    "0x0040b566": "governor_pressure_mid_range_check_state",
    "0x0040b56e": "output_speed_sensor_check_state",
    "0x0040b570": "park_neutral_switch_monitor_state",
    "0x0040b57f": "converter_clutch_rationality_monitor_state",
}
WIDTHS = {}  # moved to stage F (apply_r10f_types.py) so each proof covers one kind of change
gv = os.path.join(out, "global_variables.csv")
lines = open(gv).read().split("\n")
done = 0
for i, l in enumerate(lines):
    a = l[:10]
    if a in STATES or a in WIDTHS:
        addr, name, typ, comment = (l.split(",", 3) + [""])[:4]
        if a in STATES:
            assert name == STATES[a] and typ == "word", (a, name, typ)
            typ = ENUM
            comment += f" Typed {ENUM} (round 10): 1 running / 2 passed / 3 failed / 4 aborted, the e2m NORUN..ABORT list."
        else:
            assert typ == WIDTHS[a][0], (a, typ)
            typ = WIDTHS[a][1]
        lines[i] = ",".join([addr, name, typ, comment])
        done += 1
assert done == 6, done
open(gv, "w").write("\n".join(lines))
en = os.path.join(out, "enums.csv")
text = open(en).read()
assert f"\n{ENUM}," not in text
rows = [f'{ENUM},{v},{ENUM}_{m},"{c}",2' for v, m, c in MEMBERS]
text = text.rstrip("\n") + "\n" + "\n".join(rows) + "\n"
open(en, "w").write(text)
sd = os.path.join(out, "structure_definitions.csv")
text = open(sd).read()
BITS = {
    "limp_home_flags_1": "0x01 RE_Trans_Relay_Circuit_Open ('transmission power relay is open-circuit'): fault 137 "
                         "P0882 / 0x02 RE_TPS_Elect_Limp ('throttle signal is invalid'): the pedal faults P2121 / P2122 "
                         "/ P2123 / P2127 / P2128 and P0698 / 0x04 RE_Cltemp_Elect_Limp: no writer or reader in this "
                         "build. Set and cleared by cm848_updateTransmissionLimpHomeFlags; bit 0 drops the transmission "
                         "relay (cm848_updateTransmissionRelayRequest), bit 1 is read by cm848_runTransmissionControl",
    "limp_home_flags_2": "0x01 RE_Governor_Press_Sol_Circuit: fault 351 P0748 / 0x02 RE_Overdrive_Solenoid_Circuit: "
                         "fault 139 P0973 (both set and cleared by cm848_updateTransmissionLimpHomeFlags; either drops "
                         "the transmission relay) / 0x04 RE_TPS_Rat_Limp: read by cm848_runTransmissionControl, no "
                         "writer in this build",
    "limp_home_flags_3": "0x01 RE_Gov_Sensor_Limp_Circuit: faults 299 / 300 P0868 / P0869, or "
                         "governor_pressure_rationality_monitor_state = FAILED (P1762); set and cleared by "
                         "cm848_updateTransmissionLimpHomeFlags; cm848_determineCurrentGearAndLockupInhibit turns it "
                         "(with limp_home_flags_4 bits 0 / 2) into limp_home_and_temperature_flags bit 0 / 0x02 "
                         "RE_Trans_Sump_Temp_Rationality: no writer or reader in this build",
    "limp_home_flags_4": "0x01 RE_Gov_Sensor_Limp_Offset / 0x04 RE_GCST_Limp ('a problem with the GCST circuit'; GCST "
                         "is not expanded in the e2m or the DRB database): read with limp_home_flags_3 bit 0 by "
                         "cm848_determineCurrentGearAndLockupInhibit, no writer in this build / 0x02 RE_Spd_Rat_Limp and "
                         "0x08 RE_Trans_Sump_Temp_Circuit: no writer or reader / 0x10 "
                         "RE_Lockup_Converter_Clutch_Solenoid_Circuit: fault 141 P2769 (drops the transmission relay) / "
                         "0x20 RE_OSS_Limp: P0720, from cm848_monitorTransmissionOutputSpeedSensor",
}
for field, bits in BITS.items():
    m = re.search(r"^transmission_control_flags_t,0x0040b0e8," + field + r",byte,1,(\"(?:[^\"]|\"\")*\"|[^,\n]*),,"
                  r"(verified|needs_review)$", text, re.M)
    assert m, field
    old = m.group(1).strip('"')
    head = re.match(r"e2m 8C19 \+\d RE_Limp_Flags\d", old).group(0)
    rest = old[len(head):].strip()
    rest = re.sub(r"^\([^)]*\)\s*", "", rest)  # the old record-name list, now in the bit map
    # present-tense mentions of the functions renamed in stage C
    rest = (rest.replace("cm848_processProtectionFaultSeverity", "cm848_updateTransmissionLimpHomeFlags")
                .replace("cm848_evaluateProtectionFaultCondition", "cm848_updateTransmissionRelayRequest"))
    new = f"{head} 'Contains transmission control limp-home mode flags'. Bits: {bits}"
    if rest:
        new += " " + rest if rest.startswith("|") else f" | earlier note: {rest.lstrip(':').strip()}"
    assert '"' not in new
    row = f'transmission_control_flags_t,0x0040b0e8,{field},byte,1,"{new}",,verified'
    text = text[:m.start()] + row + text[m.end():]
open(sd, "w").write(text)
print(f"{done} rows typed, {len(MEMBERS)} enum members, 4 limp-home comments")

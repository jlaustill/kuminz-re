"""Round 11 stage C (pilot, types): switch_input_state_bits (0x40c050, 4 bytes) as switch_input_state_t, one 1-byte
bitfield unit per byte, each bit from its e2m 1612 record (switch N = byte N/8, mask 1 << N%8; 12A8 +N names the same
switches). A switch with a record and a code user gets a name; switches 18 / 29 (no 11.45 record) and 30 (TVA, no
user) stay reserved_bit_N. The arrays.csv byte[4] row moves to a global_variables.csv row typed with the struct.
Accept only if the single-bit | / & setters (switches 2 / 13 / 31) and the scanner's indexed accesses render without
._N_1_ pieces. usage: apply_r11c_switch_struct.py <repo>  (writes switch_masks_r11c.json for the proof)"""
import json
import os
import re
import sys

repo = os.path.abspath(sys.argv[1])
out = os.path.join(repo, "firmware", "CM848_S90140.06_analysis", "output")
E2M = os.path.join(repo, "e2m-analysis", "CHR", "CHR_CC_11.45.01.07.e2m")
records = {}
for line in open(E2M, errors="replace"):
    f = line.split(";")[0].split(",")
    if len(f) > 10 and f[2] == "1612" and f[5] == "S":
        records[int(f[3], 16) * 8 + (int(f[10], 16).bit_length() - 1)] = f[0]
NAMES = {
    0: "key_switch", 1: "lift_pump_feedback", 2: "not_brake_switch", 3: "power_take_off_on_switch",
    4: "wait_to_start_lamp_feedback", 5: "engine_brake_driver_1_feedback", 6: "air_conditioning_clutch_feedback",
    7: "idle_switch", 8: "not_idle_switch", 9: "intake_air_heater_1_feedback", 10: "intake_air_heater_2_feedback",
    11: "brake_switch", 12: "exhaust_brake_switch", 13: "air_conditioning_switch", 14: "low_oil_pressure_switch",
    15: "clutch_switch", 16: "egr_valve_driver_feedback", 17: "variable_geometry_turbocharger_driver_feedback",
    19: "remote_power_take_off_switch", 20: "park_neutral_switch", 21: "overdrive_off_switch",
    22: "transmission_relay_feedback", 23: "overdrive_solenoid_feedback", 24: "converter_clutch_solenoid_feedback",
    25: "cruise_vent_solenoid_feedback", 26: "throttle_interlock_switch", 27: "cruise_vacuum_solenoid_feedback",
    28: "cruise_servo_supply_feedback", 31: "unwired_switch",
}
NOTES = {
    2: "the second brake contact; cm848_deriveSecondBrakeSwitchSignal writes it",
    12: "Engine_Brake_Select_1: the exhaust brake switch on this truck (round 8)",
    13: "cm848_updateAirConditioningSwitchFromPci writes it from the PCI bus",
    20: "the transmission park / neutral switch (line 13)",
    21: "the O/D OFF button (it toggles overdrive_off_flag)",
    22: "Transmission_VFS_Battery_Feedback: the transmission relay output (logical output 16)",
    31: "no 11.45 record and no line: every unwired switch function compiles to it, and "
        "cm848_updateSwitch31FromAcceleratorPedal / cm848_checkSwitch31OnTimeFault pulse or hold it from the "
        "accelerator pedal",
}
rows, masks = [], {}
for n in range(32):
    byte, bit = divmod(n, 8)
    rec = records.get(n)
    field = NAMES.get(n, f"reserved_bit_{n}")
    c = f"switch {n} (byte {byte} mask 0x{1 << bit:02x}): " + (f"e2m 1612 {rec}" if rec else "no e2m 1612 record")
    if n in NOTES:
        c += f"; {NOTES[n]}"
    if field.startswith("reserved"):
        c += "; no named use"
    assert '"' not in c
    rows.append(f'switch_input_state_t,,{field},bitfield:1@{bit},{1 if bit == 0 else 0},"{c}",,verified')
    if not field.startswith("reserved"):
        masks[field] = [byte, 1 << bit]
sd = os.path.join(out, "structure_definitions.csv")
text = open(sd).read()
assert "\nswitch_input_state_t," not in text
open(sd, "w").write(text.rstrip("\n") + "\n" + "\n".join(rows) + "\n")
ar = os.path.join(out, "arrays.csv")
lines = open(ar).read().split("\n")
i = next(k for k, l in enumerate(lines) if l.startswith("0x0040c050,switch_input_state_bits,byte,4,"))
comment = lines[i][len("0x0040c050,switch_input_state_bits,byte,4,"):].strip('"')
del lines[i]
open(ar, "w").write("\n".join(lines))
gv = os.path.join(out, "global_variables.csv")
glines = open(gv).read().split("\n")
assert not any(l.startswith("0x0040c050,") for l in glines)
row = ("0x0040c050,switch_input_state_bits,switch_input_state_t,Debounced logical switch states "
       "(switch_input_state_t: switch N = byte N/8 bit N%8; cm848_scanAndDebounceSwitchInputs). Typed in round 11 "
       "(was the arrays.csv byte[4] row) | earlier note: " + comment.replace('""', "'"))
k = next(j for j, l in enumerate(glines) if re.match(r"^0x[0-9a-f]{8},", l) and int(l[:10], 16) > 0x40c050)
glines.insert(k, row)
open(gv, "w").write("\n".join(glines))
json.dump(masks, open(os.path.join(os.path.dirname(os.path.abspath(__file__)), "switch_masks_r11c.json"), "w"),
          indent=1)
print(len(rows), "bitfield rows,", len(masks), "named")

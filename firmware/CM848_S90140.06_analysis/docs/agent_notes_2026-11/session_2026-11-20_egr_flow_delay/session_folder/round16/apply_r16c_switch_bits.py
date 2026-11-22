"""Round 16 stage C (types; the user's decision, 2026-11-21 "Yes, ship the bitfields"): switch_input_state_t bytes 0 / 1
/ 3 become bitfield units like byte 2, one bit per switch from its e2m 1612 record (switch N = byte N/8, mask
1 << N%8). The names are the round 11 pilot's (apply_r11c_switch_struct.py). The byte-field rows switches_0_to_7 /
switches_8_to_15 / switches_24_to_31 are replaced in place. Writes switch_masks_r16c.json (new field -> [old byte
field, mask]) for the proof.
usage: apply_r16c_switch_bits.py <repo> <masks.json>"""
import json
import os
import sys

repo, masks_path = os.path.abspath(sys.argv[1]), sys.argv[2]
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
    15: "clutch_switch", 24: "converter_clutch_solenoid_feedback", 25: "cruise_vent_solenoid_feedback",
    26: "throttle_interlock_switch", 27: "cruise_vacuum_solenoid_feedback", 28: "cruise_servo_supply_feedback",
    31: "unwired_switch",
}
NOTES = {
    0: "the ignition key switch (line 128 = the MDA30 pin; 1 = key on)",
    2: "the second brake contact; cm848_deriveSecondBrakeSwitchSignal writes it",
    7: "the accelerator at idle (the idle validation pair with switch 8)",
    8: "the accelerator off idle",
    11: "the brake switch the CCVS1 broadcast reports",
    12: "Engine_Brake_Select_1: the exhaust brake switch on this truck (round 8)",
    13: "cm848_updateAirConditioningSwitchFromPci writes it from the PCI bus",
    15: "the clutch switch the CCVS1 broadcast reports",
    31: "no 11.45 record and no line: every unwired switch function compiles to it (the two-speed axle switch of "
        "cm848_updateCruiseAndRoadSpeedGovernorDroops among them), and cm848_updateSwitch31FromAcceleratorPedal / "
        "cm848_checkSwitch31OnTimeFault pulse or hold it from the accelerator pedal",
}
BYTE_FIELD = {0: "switches_0_to_7", 1: "switches_8_to_15", 3: "switches_24_to_31"}
sd = os.path.join(out, "structure_definitions.csv")
lines = open(sd).read().split("\n")
masks = {}
for byte, field_name in BYTE_FIELD.items():
    prefix = f"switch_input_state_t,,{field_name},byte,1,"
    k = [i for i, l in enumerate(lines) if l.startswith(prefix)]
    assert len(k) == 1, (field_name, k)
    rows = []
    for bit in range(8):
        n = byte * 8 + bit
        rec = records.get(n)
        field = NAMES.get(n, f"reserved_bit_{n}")
        c = f"switch {n} (byte {byte} mask 0x{1 << bit:02x}): " + (f"e2m 1612 {rec}" if rec else "no e2m 1612 record")
        if n in NOTES:
            c += f"; {NOTES[n]}"
        if field.startswith("reserved"):
            c += "; no named use"
        assert '"' not in c
        rows.append(f'switch_input_state_t,,{field},bitfield:1@{bit},{1 if bit == 0 else 0},"{c}",,verified')
        masks[field] = [field_name, 1 << bit]
    lines[k[0]] = "\n".join(rows)
# byte 2's unused bit was named by its bit in the byte; name it by its switch number like the others
old18 = "switch_input_state_t,,reserved_bit_2,bitfield:1@2,0,"
k = [i for i, l in enumerate(lines) if l.startswith(old18)]
assert len(k) == 1
lines[k[0]] = lines[k[0]].replace(old18, "switch_input_state_t,,reserved_bit_18,bitfield:1@2,0,", 1)
open(sd, "w").write("\n".join(lines))
json.dump(masks, open(masks_path, "w"), indent=1)
print(len(masks), "bitfields in bytes 0 / 1 / 3")

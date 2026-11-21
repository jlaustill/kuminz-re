"""Round 10 stage F (types): widths and the SCI actuator test timer struct.
- Widths: 0x3fceee governor_pressure_mid_range_check_fault_reported_flag word -> dword (lwz / stw only; it rendered
  with a '_' prefix, the one overlap WARNING); the stage E rows 0x3fcef6 word (sth / lhz), 0x3fcf08 word (sth),
  0x3fcf0e dword (lwz / stw).
- sci_output_test_timers_t at 0x3fcf40 (14 words, 0x3fcf40-0x3fcf5b): one timer per SCI 0x13 actuator test, in phases
  of 141 passes. The two named rows inside it (0x3fcf4c / 0x3fcf4e, the 13-5E / 13-5F countdowns) are deleted; their
  roles go into the field comments. String edits only (global_variables.csv takes commas unquoted;
  structure_definitions.csv is quote-aware).
usage: apply_r10f_types.py <repo>"""
import os
import re
import sys

repo = os.path.abspath(sys.argv[1])
out = os.path.join(repo, "firmware", "CM848_S90140.06_analysis", "output")
FIELDS = [  # offset, field, output, DRB code and name, duration
    (0x00, "air_conditioning_clutch_relay", 38, "13-09 A/C CLUTCH RELAY", 300),
    (0x02, "intake_heater_1", 43, "13-28 INTAKE HEATER #1", 11),
    (0x04, "intake_heater_2", 44, "13-29 INTAKE HEATER #2", 11),
    (0x06, "fuel_transfer_pump", 53, "13-33 FUEL PUMP RELAY / TRANSFER PUMP", 300),
    (0x08, "wait_to_start_lamp", 4, "13-49 WAIT TO START LAMP", 300),
    (0x0a, "exhaust_brake", 11, "13-5D EXHAUST BRAKE", 11),
    (0x0c, "fuel_control", None, "13-5E FUEL CONTROL", 11),
    (0x0e, "cooling_fan", None, "13-5F PWM RAD FAN", 11),
    (0x10, "converter_clutch_solenoid", 18, "13-0F TORQUE CONV CLUTCH", 300),
    (0x12, "overdrive_solenoid", 17, "13-16 OVERDRIVE SOLENOID", 300),
    (0x14, "cruise_vent_solenoid", 19, "13-1A S/C VENT SOLENOID (and 13-0C with the vacuum solenoid)", 300),
    (0x16, "cruise_vacuum_solenoid", 20, "13-1B S/C VAC SOLENOID (and 13-0C)", 300),
    (0x18, "cruise_servo_supply", 21, "13-2C S/C 12 VOLT FEED", 11),
    (0x1a, "transmission_relay", 16, "13-43 TRANS 12V RELAY", 300),
]
BASE = 0x3fcf40
WIDTHS = {"0x003fceee": ("word", "dword"), "0x003fcef6": ("", "word"), "0x003fcf08": ("", "word"),
          "0x003fcf0e": ("", "dword")}
gv = os.path.join(out, "global_variables.csv")
lines = open(gv).read().split("\n")
done = 0
for i, l in enumerate(lines):
    a = l[:10]
    if a in WIDTHS:
        addr, name, typ, comment = (l.split(",", 3) + [""])[:4]
        assert typ == WIDTHS[a][0], (a, typ)
        lines[i] = ",".join([addr, name, WIDTHS[a][1], comment])
        done += 1
assert done == 4, done
inner = {"0x003fcf4c": "cold_start_sync_protection_countdown", "0x003fcf4e": "cold_start_injection_protection_countdown"}
old_comments = {}
keep = []
for l in lines:
    a = l[:10]
    if a in inner:
        addr, name, typ, comment = (l.split(",", 3) + [""])[:4]
        assert name == inner[a], (a, name)
        old_comments[a] = comment
        continue
    assert not (re.match(r"^0x[0-9a-f]{8},", l) and BASE <= int(a, 16) < BASE + 0x1c), ("row inside the struct", l)
    keep.append(l)
lines = keep
instance = ("0x003fcf40,sci_output_test_timers,sci_output_test_timers_t,The SCI command 0x13 actuator test timers "
            "(sci_output_test_timers_t: one word per test; phases of 141 passes left; 0 = not running). "
            "cm848_sciStartTimedOutputTest / cm848_sciCommand19OutputTestCallback set them, cm848_stepSciOutputTest "
            "counts them down, cm848_stopSciOutputTest / cm848_stopAllSciOutputTests zero them (was DAT_003fcf40 .. "
            "DAT_003fcf5a with cold_start_sync_protection_countdown / cold_start_injection_protection_countdown at +0xc "
            "/ +0xe)")
k = next(i for i, l in enumerate(lines) if re.match(r"^0x[0-9a-f]{8},", l) and int(l[:10], 16) > BASE)
lines.insert(k, instance)
open(gv, "w").write("\n".join(lines))
sd = os.path.join(out, "structure_definitions.csv")
text = open(sd).read()
assert "\nsci_output_test_timers_t," not in text
rows = []
for off, field, output, drb, duration in FIELDS:
    what = f"logical output {output}" if output is not None else (
        "fuel_control_actuator_test_active_flag" if field == "fuel_control" else "cooling_fan_actuator_test_active_flag")
    c = (f"+0x{off:02x}: timer of the DRB actuator test {drb} ({what}; started with {duration} phases)")
    a = f"0x{BASE + off:08x}"
    if a in old_comments:
        c += f" (was {inner[a]}) | earlier note: {old_comments[a]}"
    assert '"' not in c
    rows.append(f'sci_output_test_timers_t,0x003fcf40,{field},word,2,"{c}",,verified')
text = text.rstrip("\n") + "\n" + "\n".join(rows) + "\n"
open(sd, "w").write(text)
with open(os.path.join(os.path.dirname(os.path.abspath(__file__)), "relabel_r10f.txt"), "w") as f:
    for off, field, output, drb, duration in FIELDS:
        a = f"0x{BASE + off:08x}"
        f.write(f"{field} {inner.get(a, 'DAT_%08x' % (BASE + off))}\n")
print(f"{done} widths, 2 inner rows deleted, sci_output_test_timers_t ({len(FIELDS)} fields) + instance row")

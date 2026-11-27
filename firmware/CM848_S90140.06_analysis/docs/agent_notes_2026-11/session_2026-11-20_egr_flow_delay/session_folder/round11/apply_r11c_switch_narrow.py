"""Round 11 stage C (types), the narrowed form after the pilot (pilot_r11c_numbers.txt): switch_input_state_bits
(0x40c050) as switch_input_state_t with the wave 11 rule's shape -
  +0 switches_0_to_7, +1 switches_8_to_15, +3 switches_24_to_31: plain byte fields (their bits are written with | / &
     by five setter functions: switches 2 / 13 / 31), each with its e2m 1612 bit map in the comment;
  +2: one bitfield unit (switches 16-23: no direct setter, only the scanner's indexed update), each bit from 1612.
The arrays.csv byte[4] row moves to a global_variables.csv row typed with the struct.
usage: apply_r11c_switch_narrow.py <repo>  (writes switch_fields_r11c.json for the proof)"""
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
NOTES = {2: "the second brake contact; cm848_deriveSecondBrakeSwitchSignal writes it",
         12: "the exhaust brake switch on this truck (round 8)",
         13: "cm848_updateAirConditioningSwitchFromPci writes it from the PCI bus",
         31: "no 11.45 record and no line: every unwired switch function compiles to it; "
             "cm848_detectThreeAcceleratorPedalPresses / cm848_updateSwitch31FromAcceleratorPedal / "
             "cm848_checkSwitch31OnTimeFault set and clear it from the accelerator pedal"}


def byte_map(byte):
    parts = []
    for bit in range(8):
        n = byte * 8 + bit
        rec = records.get(n, "no record")
        note = f" ({NOTES[n]})" if n in NOTES else ""
        parts.append(f"0x{1 << bit:02x} switch {n} {rec}{note}")
    return " / ".join(parts)


BYTE2 = {0: ("egr_valve_driver_feedback", ""), 1: ("variable_geometry_turbocharger_driver_feedback", ""),
         2: ("reserved_bit_2", "no e2m 1612 record; no named use"), 3: ("remote_power_take_off_switch", ""),
         4: ("park_neutral_switch", "the transmission park / neutral switch (line 13)"),
         5: ("overdrive_off_switch", "the O/D OFF button (it toggles overdrive_off_flag)"),
         6: ("transmission_relay_feedback", "the transmission relay output (logical output 16)"),
         7: ("overdrive_solenoid_feedback", "")}
rows, fields = [], {}
for byte, name in ((0, "switches_0_to_7"), (1, "switches_8_to_15")):
    c = f"Switches {byte * 8}-{byte * 8 + 7} (e2m 1612 +{byte}); a byte because setters update its bits with | / &: {byte_map(byte)}"
    assert '"' not in c
    rows.append(f'switch_input_state_t,,{name},byte,1,"{c}",,verified')
    fields[name] = ["byte", byte]
for bit in range(8):
    field, note = BYTE2[bit]
    rec = records.get(16 + bit)
    c = f"switch {16 + bit} (byte 2 mask 0x{1 << bit:02x}): " + (f"e2m 1612 {rec}" if rec else "no e2m 1612 record")
    if note and not field.startswith("reserved"):
        c += f"; {note}"
    elif field.startswith("reserved"):
        c += "; no named use"
    assert '"' not in c
    rows.append(f'switch_input_state_t,,{field},bitfield:1@{bit},{1 if bit == 0 else 0},"{c}",,verified')
    if not field.startswith("reserved"):
        fields[field] = ["bit", 2, 1 << bit]
c = f"Switches 24-31 (e2m 1612 +3); a byte because setters update its bits with | / &: {byte_map(3)}"
assert '"' not in c
rows.append(f'switch_input_state_t,,switches_24_to_31,byte,1,"{c}",,verified')
fields["switches_24_to_31"] = ["byte", 3]
sd = os.path.join(out, "structure_definitions.csv")
text = open(sd).read()
assert "\nswitch_input_state_t," not in text
open(sd, "w").write(text.rstrip("\n") + "\n" + "\n".join(rows) + "\n")
ar = os.path.join(out, "arrays.csv")
lines = open(ar).read().split("\n")
i = next(k for k, l in enumerate(lines) if l.startswith("0x0040c050,switch_input_state_bits,byte,4,"))
comment = lines[i][len("0x0040c050,switch_input_state_bits,byte,4,"):]
assert comment.startswith('"') and comment.endswith('"')
comment = comment[1:-1].replace('""', "'")
comment = comment.replace("It stays a byte array: three functions update single bits with | / & (switches 2 / 13 / 31)",
                          "Bytes 0 / 1 / 3 stay bytes: five functions update single bits of them with | / & "
                          "(switches 2 / 13 / 31)")
del lines[i]
open(ar, "w").write("\n".join(lines))
gv = os.path.join(out, "global_variables.csv")
glines = open(gv).read().split("\n")
assert not any(l.startswith("0x0040c050,") for l in glines)
row = ("0x0040c050,switch_input_state_bits,switch_input_state_t,Debounced logical switch states (switch_input_state_t: "
       "switch N = byte N/8 bit N%8; cm848_scanAndDebounceSwitchInputs; round 11, was the arrays.csv byte[4] row). "
       "Byte 2 (switches 16-23) is a bitfield unit; bytes 0 / 1 / 3 are byte fields | " + comment)
k = next(j for j, l in enumerate(glines) if re.match(r"^0x[0-9a-f]{8},", l) and int(l[:10], 16) > 0x40c050)
glines.insert(k, row)
open(gv, "w").write("\n".join(glines))
json.dump(fields, open(os.path.join(os.path.dirname(os.path.abspath(__file__)), "switch_fields_r11c.json"), "w"),
          indent=1)
print(len(rows), "struct rows")

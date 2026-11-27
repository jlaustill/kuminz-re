"""Round 11 stage B, part 3 (comments): the byte 0 row gets the e2m 1577 +0 output map; the existing
logical_output_request_bits_16_to_23_t fields get their 1577 / 12A7 record names. global_variables.csv takes commas
unquoted; structure_definitions.csv is quote-aware. usage: apply_r11b_docs.py <repo>"""
import os
import re
import sys

repo = os.path.abspath(sys.argv[1])
out = os.path.join(repo, "firmware", "CM848_S90140.06_analysis", "output")
gv = os.path.join(out, "global_variables.csv")
lines = open(gv).read().split("\n")
i = next(k for k, l in enumerate(lines) if l.startswith("0x0040c080,logical_output_request_bits,"))
a, n, t, c = lines[i].split(",", 3)
MAP0 = ("e2m 1577 is the request array (output N = byte N/8 mask 1 << N%8; e2m 12A7 = the per-output priorities at "
        "0x40c094). Byte 0: 0x01 Stop_Lamp_Driver / 0x02 Maintenance_Lamp_Driver / 0x04 T2_Lamp_Driver / 0x08 "
        "TAS_Lamp_Driver / 0x10 Wait_To_Start_Lamp_Driver (output 4: DRB test 13-49, set during the intake air heater "
        "preheat, sent in PCI message 2) / 0x20 Warning_Lamp_Driver (output 5, PCI message 3) / 0x40 "
        "Water_In_Fuel_Lamp_Driver / 0x80 T2_High_Gear_Driver. Bytes 1 / 2 / 4 / 5 / 6 / 8 / 9 are bitfield structs "
        "named from the same records; this byte stays a byte because cm848_setLogicalOutputRequest / "
        "cm848_clearLogicalOutputRequest index the array from it. | earlier note: ")
assert "e2m 1577 is the request array" not in c
lines[i] = ",".join([a, n, t, MAP0 + c])
open(gv, "w").write("\n".join(lines))
sd = os.path.join(out, "structure_definitions.csv")
text = open(sd).read()
FIELDS = {
    "transmission_relay_request": "e2m 1577 +2 0x01 Transmission_VFS_Battery_Driver (12A7 +0x10 "
                                  "Transmission_VFS_Battery_Driver_Priority): the battery feed of the transmission "
                                  "solenoids. ",
    "overdrive_solenoid_request": "e2m 1577 +2 0x02 Transmission_Overdrive_Driver. ",
    "converter_clutch_solenoid_request": "e2m 1577 +2 0x04 Transmission_TCC_Driver. ",
    "cruise_vent_solenoid_request": "e2m 1577 +2 0x08 Cruise_Vent_Driver. ",
    "cruise_vacuum_solenoid_request": "e2m 1577 +2 0x10 Cruise_Vacuum_Driver. ",
    "cruise_servo_supply_request": "e2m 1577 +2 0x20 Cruise_SC_Source_Driver. ",
}
for field, head in FIELDS.items():
    m = re.search(r'^(logical_output_request_bits_16_to_23_t,,' + field + r',bitfield:1@\d,\d,)"', text, re.M)
    assert m, field
    text = text[:m.end()] + head + text[m.end():]
for bit, rec in ((6, "CORS_Makeup_Valve_Driver"), (7, "Fan_Clutch_Control_Driver1")):
    old = (f"logical_output_request_bits_16_to_23_t,,reserved_bit_{bit},bitfield:1@{bit},0,output {16 + bit}: "
           "no direct read or write found,,verified")
    new = (f"logical_output_request_bits_16_to_23_t,,reserved_bit_{bit},bitfield:1@{bit},0,output {16 + bit} "
           f"(mask 0x{1 << bit:02x}): e2m 1577 +2 {rec}; no direct read or write found,,verified")
    assert text.count(old) == 1, bit
    text = text.replace(old, new)
open(sd, "w").write(text)
print("byte 0 map and the 16-23 record names written")

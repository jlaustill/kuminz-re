"""Round 25 stage A (types): TRANSMISSION_SELECTED_GEAR, the J1939 SPN 524 coding (one gear per bit, -125 offset;
251 = park), replaces the unapplied PROTECTION_OVERRIDE enum (0x7e / 0x7f named after their ASCII glyphs) and types
the four carriers: transmission_selected_gear (the PCI 0x37 shift lever decode), _previous, _last_valid and
j1939_powertrain_control_state_t.etc2_transmission_selected_gear (ETC2 byte 1). Every literal the code compares with or
assigns to them has a member: 0x7c-0x82, 0xfb, 0xff (0xfe added, the J1939 error value).
usage: apply_r25a.py <repo>"""
import csv
import io
import os
import sys

repo = os.path.abspath(sys.argv[1])
out = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")
E = "TRANSMISSION_SELECTED_GEAR"
MEMBERS = [
    ("0x7c", "REVERSE", "-1: reverse (shift lever position 2, cm848_updateSelectedGearFromShiftLever)"),
    ("0x7d", "NEUTRAL", "0: neutral (lever position 3)"),
    ("0x7e", "FIRST", "1st gear"),
    ("0x7f", "SECOND", "2nd gear"),
    ("0x80", "THIRD", "3rd gear (drive while overdrive is off)"),
    ("0x81", "FOURTH", "4th gear (drive with overdrive)"),
    ("0x82", "FIFTH", "5th gear"),
    ("0xfb", "PARK", "251: park (lever position 1; J1939 SPN 524 special value)"),
    ("0xfe", "ERROR", "254: J1939 error indicator"),
    ("0xff", "NOT_AVAILABLE", "255: not available (the PCI 0x37 message is invalid, or no ETC2 arrived)"),
]


def write_csv_row(row):
    s = io.StringIO()
    csv.writer(s, lineterminator="").writerow(row)
    return s.getvalue()


ep = os.path.join(out, "enums.csv")
lines = open(ep).read().split("\n")
i = lines.index("# Protection Override Mode (DAT_0040b4ff values)")
assert lines[i + 1].startswith("PROTECTION_OVERRIDE,0x7e,") and lines[i + 2].startswith("PROTECTION_OVERRIDE,0x7f,")
new = ["# Transmission selected gear (PR #53 round 25): the J1939 SPN 524 coding of transmission_selected_gear and its "
       "copies - one gear per bit with a -125 offset, 251 = park. Replaces PROTECTION_OVERRIDE, which no variable used "
       "and whose members were named after the ASCII glyphs of 0x7e / 0x7f"]
new += [write_csv_row([E, v, f"{E}_{m}", c, "1"]) for v, m, c in MEMBERS]
lines[i:i + 3] = new
open(ep, "w").write("\n".join(lines))
gp = os.path.join(out, "global_variables.csv")
g = open(gp).read().split("\n")
done = 0
for k, line in enumerate(g):
    for name in ("transmission_selected_gear", "transmission_selected_gear_previous",
                 "transmission_selected_gear_last_valid"):
        if line.split(",", 2)[1:2] == [name] and line.split(",", 3)[2] == "byte":
            parts = line.split(",", 3)
            parts[2] = E
            g[k] = ",".join(parts)
            done += 1
assert done == 3, done
open(gp, "w").write("\n".join(g))
sp = os.path.join(out, "structure_definitions.csv")
s = open(sp).read().split("\n")
hit = 0
for k, line in enumerate(s):
    if line.startswith("j1939_powertrain_control_state_t,") and ",etc2_transmission_selected_gear,byte," in line:
        row = next(csv.reader([line]))
        row[3] = E
        s[k] = write_csv_row(row)
        hit += 1
assert hit == 1, hit
open(sp, "w").write("\n".join(s))
print("enum written, 4 carriers typed")

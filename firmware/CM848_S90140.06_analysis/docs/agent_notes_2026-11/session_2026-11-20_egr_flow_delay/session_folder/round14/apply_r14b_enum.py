"""Round 14 stage B (types): LOW_SPEED_GOVERNOR_REFERENCE_SPEED_STATE (size 2) from e2m 1496 +14
LSG_Reference_Speed_State's own value labels (0000=COOLANT:0001=PARK_NEU:...:000C=MOVING; keys hex). Every value
0-12 is stored: cm848_selectLowSpeedGovernorDesiredReferenceSpeed stores 0-6 and 9-12, the slew 7 and 8, the
initializer 5. It types the struct field low_speed_governor_reference_t.reference_speed_state and the word
low_speed_governor_reference_speed_state_previous.
usage: apply_r14b_enum.py <repo>"""
import csv
import io
import os
import sys

repo = os.path.abspath(sys.argv[1])
out = os.path.join(repo, "firmware", "CM848_S90140.06_analysis", "output")
E, P = "LOW_SPEED_GOVERNOR_REFERENCE_SPEED_STATE", "LOW_SPEED_GOVERNOR_REFERENCE"
MEMBERS = [
    (0, "COOLANT", "e2m COOLANT: low_speed_governor_coolant_temperature_speed_request"),
    (1, "PARK_NEUTRAL", "e2m PARK_NEU: low_speed_governor_park_or_drive_speed_request"),
    (2, "EXTENDED_IDLE", "e2m EXTENDED: low_speed_governor_extended_idle_speed_request"),
    (3, "AIR_CONDITIONING", "e2m AC: low_speed_governor_air_conditioning_speed_request (switch 13)"),
    (4, "J1850", "e2m J1850: low_speed_governor_j1850_speed_request (the PCI idle speed request)"),
    (5, "BASE", "e2m BASE: low_speed_governor_base_reference_speed_cal; also whenever it differs from its boot copy"),
    (6, "J1939", "e2m JCOMM: a J1939 TSC1 override with low_speed_governor_j1939_override_enable (the minimum idle speed)"),
    (7, "MINIMUM", "e2m MIN: the slew clamped the reference to low_speed_governor_minimum_idle_speed"),
    (8, "MAXIMUM", "e2m MAX: the slew clamped the reference to low_speed_governor_maximum_idle_speed"),
    (9, "ALTITUDE", "e2m ALTITUDE: the altitude speed (low_speed_governor_reference.altitude_speed)"),
    (10, "SHIFT_IN_PROCESS", "e2m SIP: a shift in process holds the desired speed (low_speed_governor_shift_in_process_timer)"),
    (11, "TOOL", "e2m TOOL: low_speed_governor_tool_speed_request (SCI SET RPM or the high pressure safety valve test)"),
    (12, "MOVING", "e2m MOVING: low_speed_governor_moving_speed_request"),
]


def text_of(row):
    s = io.StringIO()
    csv.writer(s, lineterminator="").writerow(row)
    return s.getvalue()


p = os.path.join(out, "enums.csv")
s = open(p).read()
assert f"\n{E}," not in s
existing = {r[2] for r in csv.reader(l for l in s.split("\n") if l and not l.startswith("#")) if len(r) > 2}
block = [f"# {E}: e2m 1496 +14 LSG_Reference_Speed_State 'Indication of which logic is controlling LSG idle speed' "
         "(its own value labels; PR #53 round 14)"]
for v, m, c in MEMBERS:
    assert f"{P}_{m}" not in existing, m
    block.append(text_of([E, str(v), f"{P}_{m}", c, "2"]))
open(p, "w").write(s.rstrip("\n") + "\n" + "\n".join(block) + "\n")
sd = os.path.join(out, "structure_definitions.csv")
lines = open(sd).read().split("\n")
done = 0
for i, l in enumerate(lines):
    if l.startswith("low_speed_governor_reference_t,"):
        row = next(csv.reader([l]))
        if row[2] == "reference_speed_state":
            assert row[3] == "word", row[3]
            row[3] = E
            lines[i] = text_of(row)
            done += 1
assert done == 1
open(sd, "w").write("\n".join(lines))
gv = os.path.join(out, "global_variables.csv")
lines = open(gv).read().split("\n")
done = 0
for i, l in enumerate(lines):
    if l.startswith("0x003faf90,low_speed_governor_reference_speed_state_previous,word,"):
        a, n, t, c = l.split(",", 3)
        lines[i] = ",".join([a, n, E, c + f" | typed {E} (round 14)"])
        done += 1
assert done == 1
open(gv, "w").write("\n".join(lines))
print(f"{len(MEMBERS)} members; the field and the previous-state word typed")

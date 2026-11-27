"""Round 16 stage A: rename enum members (labels): FUELING_STATE 10, and CRUISE_CONTROL_STATE 3 / 5-8 from the e2m
value list of 1184 +2 Cruise_Command_Mode 'off/set/resume/coast/accel/bump down/bump up/hold/cancel' (the old names
and comments assumed J1939 SPN 527 states; the firmware's own value list is the e2m one, and every case of
cm848_cruiseSpeedCommandStateMachine matches it).
Appends the renamed members to the map (kind global). usage: apply_r16a_enums.py <repo> <map.csv>"""
import csv
import io
import os
import sys

repo, map_path = os.path.abspath(sys.argv[1]), sys.argv[2]
p = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output/enums.csv")
L = "e2m 1184 +2 Cruise_Command_Mode value list 'off/set/resume/coast/accel/bump down/bump up/hold/cancel'"
NEW = {
    ("FUELING_STATE", "10"): ("FUELING_STATE_ROAD_SPEED_GOVERNOR", None),
    ("CRUISE_CONTROL_STATE", "0"): ("CRUISE_OFF", "Off: clears engaged, resume and the resume speed valid flag (" + L + ")"),
    ("CRUISE_CONTROL_STATE", "1"): ("CRUISE_SET", "Set: cruise_speed_command = the road speed (at most the cruise maximum); "
                                    "engaged (" + L + ")"),
    ("CRUISE_CONTROL_STATE", "2"): ("CRUISE_RESUME", "Resume: cruise_speed_command = cruise_resume_speed; an external reset "
                                    "of the governor (" + L + ")"),
    ("CRUISE_CONTROL_STATE", "3"): ("CRUISE_COAST", "Coast: cruise_speed_command falls by cruise_coast_ramp per pass ("
                                    + L + ")"),
    ("CRUISE_CONTROL_STATE", "4"): ("CRUISE_ACCELERATE", "Accelerate: cruise_speed_command rises by cruise_accelerate_ramp "
                                    "per pass (" + L + ")"),
    ("CRUISE_CONTROL_STATE", "5"): ("CRUISE_BUMP_DOWN", "Bump down: cruise_speed_command falls by cruise_bump_down_step ("
                                    + L + ")"),
    ("CRUISE_CONTROL_STATE", "6"): ("CRUISE_BUMP_UP", "Bump up: cruise_speed_command rises by cruise_bump_up_step while "
                                    "below the road speed plus one step (" + L + ")"),
    ("CRUISE_CONTROL_STATE", "7"): ("CRUISE_HOLD", "Hold: cruise_resume_speed follows cruise_speed_command (" + L + ")"),
    ("CRUISE_CONTROL_STATE", "8"): ("CRUISE_CANCEL", "Cancel: clears engaged and resume but keeps the resume speed ("
                                    + L + ")"),
}
out, maps = [], []
for line in open(p).read().split("\n"):
    if line and not line.startswith("#"):
        row = next(csv.reader([line]))
        key = (row[0], row[1]) if len(row) > 3 else None
        if key in NEW:
            new, comment = NEW.pop(key)
            old = row[2]
            was = ""
            if old != new:
                maps.append(f",{new},{old},global")
                row[2] = new
                was = f" (was {old})"
            if comment is not None:
                row[3] = comment + was + (" | earlier note: " + row[3] if row[3] else "")
            elif was:
                row[3] = row[3] + was
            b = io.StringIO()
            csv.writer(b, lineterminator="").writerow(row)
            line = b.getvalue()
    out.append(line)
assert not NEW, NEW
open(p, "w").write("\n".join(out))
with open(map_path, "a") as f:
    f.write("\n".join(maps) + "\n")
print(len(maps), "members renamed")

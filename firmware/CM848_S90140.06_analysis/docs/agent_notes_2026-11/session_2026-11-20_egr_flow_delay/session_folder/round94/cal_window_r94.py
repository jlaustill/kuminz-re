"""Round 94 (CM550): the EEPROM image is 0x148a bytes, so every named row in RAM 0x804156-0x804f93 (EEPROM
0x64c-0x1489) is EEPROM-backed and takes _cal, as in CM848 (whose window is its start-up load, 0x3fd482-0x3feec1).
Evidence: mc68k_initializeSerialEepromDriverAndLoadMirror (0x26854) sets the start-up load length with
move.l #0x804f94,d0 / subi.l #0x803b08,d0 / addi.w #-2,d0 = 0x148a (RAM 0x803b0a-0x804f93) and only afterwards the
refresh length 0x64c (RAM 0x803b0a-0x804155).
Skipped: names already ending in _cal, documentation rows (name[n] / name.field) and unnamed rows. Refuses on a name
that would collide. Writes the map (address,name,old_label,kind,dims) for the proofs and the reference refresh.
usage: cal_window_r94.py <repo> <map out.csv> [--dry-run]"""
import os
import re
import sys

repo = os.path.abspath(sys.argv[1])
map_path = sys.argv[2]
dry = "--dry-run" in sys.argv
R = "PR #53 round 94"
NOTE = f"(was {{old}}; {R}: the EEPROM image is 0x148a bytes, RAM 0x803b0a-0x804f93)"
path = os.path.join(repo, "firmware/CM550_J90350.00_analysis/output/global_variables.csv")
text = open(path, newline="").read()
lines = text.split("\n")
names = {}
for l in lines:
    p = l.split(",", 3)
    if len(p) > 2 and p[0].startswith("0x") and p[1]:
        names.setdefault(p[1], set()).add(p[0].lower())
renames, skipped = [], []
for i, l in enumerate(lines):
    p = l.split(",", 3)
    if len(p) < 3 or not p[0].startswith("0x"):
        continue
    a = int(p[0], 16)
    if not 0x804156 <= a < 0x804f94:
        continue
    old = p[1]
    if not old or old.endswith("_cal") or not re.match(r"^[a-z][a-z0-9_]*$", old):
        skipped.append(f"{p[0]} {old or '(no name)'}")
        continue
    new = old + "_cal"
    assert new not in names, f"{new} is already used at {names[new]}"
    comment = p[3] if len(p) > 3 else ""
    end = "\r" if comment.endswith("\r") else ""
    comment = comment.rstrip("\r")
    comment = (comment + " " if comment else "") + NOTE.format(old=old)
    lines[i] = ",".join([p[0], new, p[2], comment]) + end
    renames.append((p[0].lower(), new, old))
if not dry:
    open(path, "w", newline="").write("\n".join(lines))
with open(map_path, "w") as f:
    f.write("address,name,old_label,kind,dims\n")
    for a, new, old in renames:
        f.write(f"{a},{new},{old},symbol,1\n")
print(f"{len(renames)} renamed, {len(skipped)} skipped: {skipped}")
# CM848's twin of j1939_input_signal_timeouts (word[25] at 0x3feaa4, inside CM848's EEPROM mirror 0x3fd482-0x3feec1)
# is an arrays.csv row, which the _cal audit does not read; its users are all application code (Bank 2), none in the
# boot ROM, so it takes _cal like the CM550 row and the twins keep one name.
c8 = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output/arrays.csv")
t8 = open(c8, newline="").read()
old8 = "0x003feaa4,j1939_input_signal_timeouts,word,25,"
new8 = "0x003feaa4,j1939_input_signal_timeouts_cal,word,25,"
m8 = map_path.replace("cm550", "cm848")
if old8 in t8 or new8 in t8:
    if old8 in t8 and not dry:
        assert t8.count(old8) == 1
        line_end = t8.index("\n", t8.index(old8)) if "\n" in t8[t8.index(old8):] else len(t8)
        line = t8[t8.index(old8):line_end].rstrip("\r")
        t8 = t8.replace(line, line.replace(old8, new8) + f" (was j1939_input_signal_timeouts; {R}: EEPROM-backed, inside the mirror)")
        open(c8, "w", newline="").write(t8)
    with open(m8, "w") as f:
        f.write("address,name,old_label,kind,dims\n0x003feaa4,j1939_input_signal_timeouts_cal,j1939_input_signal_timeouts,symbol,1\n")
    print("CM848 arrays.csv 0x3feaa4 -> j1939_input_signal_timeouts_cal; map", m8)
else:
    raise SystemExit("CM848 arrays.csv row 0x3feaa4 not found")

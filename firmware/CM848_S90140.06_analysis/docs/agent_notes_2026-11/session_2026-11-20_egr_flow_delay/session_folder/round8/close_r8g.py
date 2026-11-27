"""Round 8 stage G closing: retarget the tasks' resolved lines that point at a stage F name stage G renamed, update the
memory note (stage G names, the commit count).
usage: close_r8g.py <repo> <map_r8g.csv> <memory dir> <commit count> <task file>..."""
import csv
import os
import re
import sys

repo, map_path, mem, count, *tasks = sys.argv[1:]
repo = os.path.abspath(repo)
new_of = {r["old_label"]: r["name"] for r in csv.DictReader(open(map_path))
          if r.get("old_label") and r["old_label"] != r["name"]}
HEAD = "## Resolved by PR #53 round 8 (2026-11-21)"
for rel in tasks:
    path = os.path.join(repo, rel)
    text = open(path).read()
    i = text.rindex(HEAD)
    section = text[i:].split("\n")
    n = 0
    for k, line in enumerate(section):
        m = re.match(r"^- `([A-Za-z0-9_]+)` → `([A-Za-z0-9_]+)`$", line)
        if m and m.group(2) in new_of:
            section[k] = f"- `{m.group(1)}` → `{new_of[m.group(2)]}`"
            n += 1
    open(path, "w").write(text[:i] + "\n".join(section))
    print(f"{rel}: {n} retargeted")
p = os.path.join(mem, "typing_focus_2026_11.md")
s = open(p).read()
for old, new in [("cm848_updateExhaustBrakeLockupInhibit, exhaust_brake_lockup_flags (0x40b0fe = 8C19 +16, bit 0 =",
                  "cm848_updateExhaustBrakeInhibitForLockup, transmission_exhaust_brake_flags (0x40b0fe = 8C19 +16 "
                  "RE_Trans_EBrake, bit 2 = RE_Ebrake_Inhibit_Timeout_Flag, bit 0 ="),
                 (", 40 after round 7, 49 after round 8.", f", 40 after round 7, {count} after round 8.")]:
    assert s.count(old) == 1, old[:50]
    s = s.replace(old, new)
a = "  - Lesson (stage F): quote the e2m DESCRIPTION"
assert s.count(a) == 1
s = s.replace(a, "  - Stage G (label, after a second advisor review): exhaust_brake_inhibit_timer / _timeout / _previous (the "
                 "e2m word order: the exhaust brake is inhibited, not the lockup); switch 12 PROVED the exhaust brake switch "
                 "(cm848_driveEngineRetarderOutput: engine_retarder_switch_percent_2 = 100); 8C19 checked at +0..+3, +9, +A, "
                 "+C, +16; csv-module audit found no other damage.\n" + a)
open(p, "w").write(s)
p = os.path.join(mem, "MEMORY.md")
s = open(p).read()
a = "(cm848/egr-flow-delay-model, 49 commits)"
assert s.count(a) == 1
open(p, "w").write(s.replace(a, f"(cm848/egr-flow-delay-model, {count} commits)"))
print("memory ok")

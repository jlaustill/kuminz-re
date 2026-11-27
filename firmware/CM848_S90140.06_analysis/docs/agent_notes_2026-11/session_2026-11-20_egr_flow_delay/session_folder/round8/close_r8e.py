"""Round 8 stage E closing: add the stage E names each task file cites to its 'Resolved by PR #53 round 8' section (the
last section of the file), and update the memory note (stage E, commit count).
usage: close_r8e.py <repo> <map_r8e.csv> <memory dir> <commit count> <task file>..."""
import csv
import os
import re
import sys

repo, map_path, mem, count, *tasks = sys.argv[1:]
repo = os.path.abspath(repo)
new_of = {r["old_label"]: r["name"] for r in csv.DictReader(open(map_path))
          if r.get("old_label") and r["old_label"] != r["name"] and not r["old_label"].startswith("DAT_")}
pattern = re.compile(r"(?<![A-Za-z0-9_])(" + "|".join(map(re.escape, sorted(new_of, key=len, reverse=True))) +
                     r")(?![A-Za-z0-9_])")
HEAD = "## Resolved by PR #53 round 8 (2026-11-21)"
for rel in tasks:
    path = os.path.join(repo, rel)
    text = open(path).read()
    i = text.rindex(HEAD)
    assert "\n## " not in text[i + len(HEAD):], rel  # the round 8 section is the last one
    found = []
    for line in text[:i].split("\n"):
        live = re.sub(r"\(was [^)]*\)", "", line)
        for m in pattern.finditer(live):
            if m.group(1) not in found:
                found.append(m.group(1))
    add = [f"- `{old}` → `{new_of[old]}`" for old in found if f"`{old}` →" not in text[i:]]
    if add:
        open(path, "w").write(text.rstrip("\n") + "\n" + "\n".join(add) + "\n")
    print(f"{rel}: {len(add)} names added")

p = os.path.join(mem, "typing_focus_2026_11.md")
s = open(p).read()
a = "cm848_protectionStateTransitionCheck (3-4 / 4-3 lines), cm848_calculateProtectionThresholdLimit, "
assert s.count(a) == 1
s = s.replace(a, "cm848_protectionStateTransitionCheck (3-4 / 4-3 lines; its gate condition_flags_1 bit 4, pressure "
                 "state 3, switch 12 = alternate _c shift lines), ")
b = "transmission_vehicle_inertia_default, cm848_initializeTransmissionShiftLogic).\n"
assert s.count(b) == 1
s = s.replace(b, b + "  - Stage E 94773eb (label, after the closing f349dd2): cm848_monitorConverterClutchEngagement (3 s for the "
                     "speed ratio to enter the gear's locked window 43-50 / 28-35 / 19-25, else lockup inhibit = "
                     "condition_eval bit 6), cm848_selectGovernorPressureHighGear (state 0x10), the WOT anti-hang timer "
                     "and upshift target 3075 rpm, the cruise decel delay timers; 8C17 drifts from +4A (not +4C).\n"
                     "  - Lesson: refresh_references.py rewrites history mentions too (it garbled a firmware/CLAUDE.md "
                     "'were guesses' sentence); audit comment-only refreshes with round8/refresh_audit.py.\n")
c = ", 40 after round 7, 44 after round 8."
assert s.count(c) == 1
s = s.replace(c, f", 40 after round 7, {count} after round 8.")
open(p, "w").write(s)
p = os.path.join(mem, "MEMORY.md")
s = open(p).read()
d = "(cm848/egr-flow-delay-model, 44 commits)"
assert s.count(d) == 1
s = s.replace(d, f"(cm848/egr-flow-delay-model, {count} commits)")
open(p, "w").write(s)
print("memory ok")

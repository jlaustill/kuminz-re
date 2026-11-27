"""Round 8 stage F closing.
- In each task file's 'Resolved by PR #53 round 8' section (the last section), point every line whose new name stage F
  renamed again at the final name, and add the stage F old names the file cites outside history.
- The memory note: the stage F line, the stage E line's correction, the commit count.
usage: close_r8f.py <repo> <map_r8f.csv> <memory dir> <commit count> <task file>..."""
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
    assert "\n## " not in text[i + len(HEAD):], rel
    section = text[i:].split("\n")
    retargeted = 0
    for k, line in enumerate(section):
        m = re.match(r"^- `([A-Za-z0-9_]+)` → `([A-Za-z0-9_]+)`$", line)
        if m and m.group(2) in new_of:
            section[k] = f"- `{m.group(1)}` → `{new_of[m.group(2)]}`"
            retargeted += 1
    found = []
    for line in text[:i].split("\n"):
        live = re.sub(r"\(was [^)]*\)", "", line)
        for m in pattern.finditer(live):
            if m.group(1) not in found:
                found.append(m.group(1))
    body = "\n".join(section)
    add = [f"- `{old}` → `{new_of[old]}`" for old in found if f"`{old}` →" not in body]
    text = text[:i] + body.rstrip("\n") + ("\n" + "\n".join(add) if add else "") + "\n"
    open(path, "w").write(text)
    print(f"{rel}: {retargeted} retargeted, {len(add)} names added")

p = os.path.join(mem, "typing_focus_2026_11.md")
s = open(p).read()
a = "  - Stage E 94773eb (label, after the closing f349dd2): cm848_monitorConverterClutchEngagement"
assert s.count(a) == 1
s = s.replace(a, "  - Stage E 94773eb (label, after the closing f349dd2; its first two names were WRONG, stage F corrects "
                 "them): cm848_monitorConverterClutchEngagement")
b = "  - Lesson: refresh_references.py rewrites history mentions too"
assert s.count(b) == 1
s = s.replace(b, "  - Stage F 0b685f3 (label, after an advisor review): e2m 8C18 aligns at 0x4082f4 (+00..+98; 71 ROM cals: "
                 "engine accel limits, WOT lag band, lockup / overheat lockup delays, detent / WOT thresholds, "
                 "hot_mode_* = overheat protection temps, governor_pressure_lockup_boost = RE_Lockup_Boost, state 0x10 = "
                 "cm848_selectGovernorPressureLockupBoost). Stage E's 'converter clutch engagement monitor' is the "
                 "EXHAUST BRAKE lockup aid: cm848_updateExhaustBrakeLockupInhibit, exhaust_brake_lockup_flags (0x40b0fe = "
                 "8C19 +16, bit 0 = RE_E_Brake_Inhibit_LU, read by cm848_updateEngineRetarderEnableState as lockup "
                 "disengaged), the 8C18 RE_EB_Lockup_Range_* windows; 8C17 drifts from +4C. 8C19 (RE flag bytes) = "
                 "0x40b0e8 protection_condition_flags_t (+0 condition_eval = RE_Trans_Flag1: Request_3_4 bit 2 / 4_3 "
                 "bit 1; +1 low range bit 2; +2 forced 2nd gear bit 1, high pressure bit 2; +3 RE_OD_Flags) = the next "
                 "lead. Switch 12 = the exhaust brake switch.\n"
                 "  - Lesson (stage F): quote the e2m DESCRIPTION of every record a rename leans on; an offset-aligned "
                 "name with an unread description is a guess (stage E's 'does not fit' was wrong). And never write "
                 "global_variables.csv / function_renames.csv rows with Python csv: the importer splits them with "
                 "split(',', 4 / 3), so csv quotes leak in (3 rows repaired).\n" + b)
c = ", 40 after round 7, 46 after round 8."
assert s.count(c) == 1
s = s.replace(c, f", 40 after round 7, {count} after round 8.")
open(p, "w").write(s)
p = os.path.join(mem, "MEMORY.md")
s = open(p).read()
d = "(cm848/egr-flow-delay-model, 46 commits)"
assert s.count(d) == 1
s = s.replace(d, f"(cm848/egr-flow-delay-model, {count} commits)")
e = "(the 48RE transmission controller from the e2m RE_ blocks 8BBC / 8C17 / 8C53: anti-hunt, low range, lockup, WOT)"
assert s.count(e) == 1
s = s.replace(e, "(the 48RE transmission controller from the e2m RE_ blocks 8BBC / 8C17 / 8C18 / 8C53: anti-hunt, low range, "
                 "lockup boost, WOT, the exhaust brake lockup aid; 8C19 flag bits = next lead)")
open(p, "w").write(s)
print("memory ok")

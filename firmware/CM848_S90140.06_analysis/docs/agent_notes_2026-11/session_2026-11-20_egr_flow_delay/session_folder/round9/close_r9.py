"""Round 9 closing: mark task 046's round 8 leads resolved, write the 'Resolved by PR #53 round 9' sections (from the round 8
script), update the memory note. usage: close_r9.py <repo> <map_r9_all.csv> <memory dir> <commit count> <task file>..."""
import csv
import os
import re
import sys

repo, map_path, mem, count, *tasks = sys.argv[1:]
repo = os.path.abspath(repo)
here = os.path.dirname(os.path.abspath(__file__))


def edit(path, pairs):
    s = open(path).read()
    for a, b in pairs:
        assert s.count(a) == 1, (path, a[:60], s.count(a))
        s = s.replace(a, b)
    open(path, "w").write(s)
    print(os.path.basename(path), len(pairs), "edits")


edit(os.path.join(repo, "work", "tasks", "046-cm848-egr-flow-estimate.md"), [
    ("- **Round 8 leads:**\n  - The pressure state codes 1-0x18",
     "- **Round 8 leads** (round 9 resolved all of them except signedness: the enum, the cruise function, the low range\n"
     "  lockup, the 8C19 bytes, the tables, 8BB5 / 8BBB / 8BBD and the ring. 8BBB sits at 0x4077f6, not 0x4077cc;\n"
     "  0x407800 is its +0A, the OD-off 4-3 lockup delay):\n  - The pressure state codes 1-0x18"),
])
new_of = {}
for r in csv.DictReader(open(map_path)):
    if r.get("old_label") and r["old_label"] != r["name"] and r["kind"] != "field" and not r["old_label"].startswith("DAT_"):
        new_of[r["old_label"]] = r["name"]
pattern = re.compile(r"(?<![A-Za-z0-9_])(" + "|".join(map(re.escape, sorted(new_of, key=len, reverse=True))) + r")(?![A-Za-z0-9_])")
for rel in tasks:
    path = os.path.join(repo, rel)
    text = open(path).read()
    if "## Resolved by PR #53 round 9" in text:
        print(rel, "already marked")
        continue
    found = []
    for line in text.split("\n"):
        live = re.sub(r"\(was [^)]*\)", "", line)
        if line.startswith("- `") and "` → `" in line:
            continue  # earlier resolved lines
        for m in pattern.finditer(live):
            if m.group(1) not in found:
                found.append(m.group(1))
    if not found:
        print(rel, "none")
        continue
    block = ["", "## Resolved by PR #53 round 9 (2026-11-21)", "",
             "The old names this file cites were renamed in PR #53 round 9 (the text above keeps its wording):"]
    block += [f"- `{old}` → `{new_of[old]}`" for old in found]
    open(path, "w").write(text.rstrip("\n") + "\n" + "\n".join(block) + "\n")
    print(rel, len(found), "names")
p = os.path.join(mem, "typing_focus_2026_11.md")
s = open(p).read()
pairs = [
    ("8C19 (RE flag bytes) = 0x40b0e8 protection_condition_flags_t (+0 condition_eval = RE_Trans_Flag1",
     "8C19 (RE flag bytes) = 0x40b0e8, now transmission_control_flags_t (+0 request_flags = RE_Trans_Flag1"),
    (", 40 after round 7, 50 after round 8.", f", 40 after round 7, 50 after round 8, {count} after round 9."),
]
for a, b in pairs:
    assert s.count(a) == 1, a[:50]
    s = s.replace(a, b)
a = "  - Open: the pressure state enum (codes 1-0x18)"
i = s.index(a)
j = s.index("\n", i)
s = s[:i] + ("  - Open (after round 8; round 9 resolved all but signedness): the pressure state enum (codes 1-0x18)" + s[i + len(a):j]) + \
    ("\n- Round 9 (2026-11-21, next 'keep going'): e2m COLUMN 5 = the ROM calibration layout order (RAM blocks 0000). "
     "round9/walk_tables.py walks table blocks from a known address sizing each from its length word (Z grid = nx*ny, no "
     "header): ~100 48RE tables proven (each lands on an existing word[N] row of its size). 0f4daf6 (A: tables, 8BB5 = "
     "governor pressure PID cals at 0x408ae0, 8BBB 0x4077f6 +0..+14, 8BBD 0x40b0ae; the cm848_throttle* family = the "
     "governor pressure solenoid PID; cm848_selectGovernorPressureCruise) / 84be9af (B: post-8C18 tables; the exhaust "
     "brake tables are e2m 8CA6..8CC6 = column 5 1010..1030, NOT 11.46-only) / 3301eb9 (C: TRANSMISSION_PRESSURE_STATE, "
     "24 members) / f63a28b (D: 8C19 = transmission_control_flags_t / transmission_shift_strategy_flags_t).\n"
     "  - Open: single flag bits, lookup caches (protection_filter_stage_*), the EEPROM shift lag tables (RE_One_Two_Lag / "
     "RE_Two_Three_Lag at 0x3fede2), 8BBB's missing tail, blocks 8C33 / 8C34 / 8C55 / 8C49, signedness.") + s[j:]
open(p, "w").write(s)
p = os.path.join(mem, "MEMORY.md")
s = open(p).read()
for a, b in [("(cm848/egr-flow-delay-model, 50 commits)", f"(cm848/egr-flow-delay-model, {count} commits)"),
             ("the exhaust brake lockup aid; 8C19 flag bits = next lead)",
              "the exhaust brake lockup aid) + round 9 (e2m column 5 = ROM layout: ~100 RE tables walked, the governor "
              "pressure PID, TRANSMISSION_PRESSURE_STATE, the 8C19 flag structs)")]:
    assert s.count(a) == 1, a[:40]
    s = s.replace(a, b)
open(p, "w").write(s)
print("memory ok")

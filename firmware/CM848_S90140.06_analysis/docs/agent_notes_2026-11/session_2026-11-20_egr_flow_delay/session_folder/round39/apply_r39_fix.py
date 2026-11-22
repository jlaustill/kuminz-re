"""Round 39 closing fix (advisor review): the ROM-copy claims say what was measured. RAM 0x3feed0-0x40a048 equals ROM
0x64aea-0x6fc62 (RAM = ROM + 0x39a3e6) in all 22717 words of the running dump; 'never written' rested on a name regex.
Comment-only CSV edits (globals' comments do not render in the .cpp), the firmware/CLAUDE.md sentence, task 046, the PR
body's test plan line and the memory notes. Idempotent.  usage: apply_r39_fix.py <repo> <pr_body.md> <commit count>"""
import os
import sys

repo, pr, count = os.path.abspath(sys.argv[1]), sys.argv[2], sys.argv[3]
COPY = "RAM = ROM + 0x39a3e6; the running dump holds the ROM value"


def path(rel):
    return rel if os.path.isabs(rel) else os.path.join(repo, rel)


def edit(rel, old, new, count_expected=1):
    p = path(rel)
    t = open(p).read()
    if new in t and old not in t:
        return
    assert t.count(old) == count_expected, (rel, old[:70], t.count(old))
    open(p, "w").write(t.replace(old, new))


gv = "firmware/CM848_S90140.06_analysis/output/global_variables.csv"
t = open(path(gv)).read()
n_rom = t.count(" ROM-copied (RAM = ROM + 0x39a3e6), never written, so no _cal")
n_unv = t.count("(outside the EEPROM mirror, never written by the code)")
print("ROM suffix rows:", n_rom, "unverified rows:", n_unv)
if n_rom:
    t = t.replace(" ROM-copied (RAM = ROM + 0x39a3e6), never written, so no _cal", f" ROM-copied ({COPY}), so no _cal")
if n_unv:
    t = t.replace("(outside the EEPROM mirror, never written by the code)",
                  f"(outside the EEPROM mirror; ROM-copied, {COPY})")
for addr, marker in (("0x003ff6d8,all_speed_governor_minimum_speed_offset,", " - it (was "),
                     ("0x003ffca2,wastegate_duty_proportional_gain_rate_limit,", " toward (was ")):
    i = t.index(addr)
    j = t.index("\n", i)
    row = t[i:j]
    if "ROM-copied" not in row:
        k = row.index(marker) + len(marker) - len(" (was ")
        row = row[:k] + f". ROM-copied ({COPY}), so no _cal" + row[k:]
        t = t[:i] + row + t[j:]
open(path(gv), "w").write(t)
edit("firmware/CLAUDE.md",
     "The 0x40xxxx calibration block is a ROM copy (RAM = ROM + 0x39a3e6, the dumps match).",
     "RAM 0x3feed0-0x40a048, from just past the EEPROM mirror, is a copy of ROM 0x64aea-0x6fc62 (RAM = ROM + 0x39a3e6: "
     "all 22717 words of the RAM dump match).")
edit("work/tasks/046-cm848-egr-flow-estimate.md",
     "- **Stage C (2aa86ed, labels, types):** the last 42 HARD scalars. 39 of them sit in the 0x40xxxx block, which is a "
     "ROM copy\n  (RAM = ROM + 0x39a3e6), and the code writes none of the 42.",
     "- **Stage C (2aa86ed, labels, types):** the last 42 HARD scalars. All 42 sit in RAM 0x3feed0-0x40a048, a copy of\n"
     "  ROM 0x64aea-0x6fc62 (RAM = ROM + 0x39a3e6: all 22717 words of the running dump match; stage C's \"never written\"\n"
     "  rested on a name regex and is now that measurement).")
edit("work/tasks/046-cm848-egr-flow-estimate.md",
     "- **firmware/CLAUDE.md (factual refresh):** the \"~1352 HARD\" sentence now says the HARD list is empty, that the\n"
     "  0x40xxxx block is a ROM copy, and that 258 MISSING remain.",
     "- **Width and sign:** each of the 32 rows named from an e2m record matches the record's size (2 bytes). The one\n"
     "  signed record, Expected_Firing_Revs_X_Axis, is the lookup's signed axis (flags 1); tables stay `word[N]` because\n"
     "  they are passed as `word *`.\n"
     "- **firmware/CLAUDE.md (factual refresh):** the \"~1352 HARD\" sentence now says the HARD list is empty, gives the\n"
     "  ROM copy's measured range, and says 258 MISSING remain.")
edit("work/tasks/046-cm848-egr-flow-estimate.md",
     "  - `engine_retarder_torque_cached_axis_offset`'s phantom `in_r6` data argument.\n",
     "  - `engine_retarder_torque_cached_axis_offset`'s phantom `in_r6` data argument.\n"
     "  - `fuel_rpm_compensated_offset_upper_limit` / `_lower_limit` render under `(short)` casts: `i16` candidates.\n"
     "  - `audit_cal_suffixes.py` calls RAM 0x3feed0-0x40a048 WORKING_RAM; it is the ROM copy.\n")
edit(pr, "- [x] Round 39: every function matches the canonical form or has 0 differing statements; "
         "`audit_cal_suffixes.py` HARD 63 -> 0, SOFT 4 -> 0.",
     "- [x] Round 39: every function matches the canonical form or has 0 differing statements; "
     "`audit_cal_suffixes.py` HARD 63 -> 0, SOFT 4 -> 0; e2m sizes agree; RAM 0x3feed0-0x40a048 = ROM + 0x39a3e6 "
     "(all 22717 words).")
M = "/home/linux/.claude/projects/-home-linux-code-kuminz-re/memory/"
m = open(M + "MEMORY.md").read()
import re
m = re.sub(r"\(cm848/egr-flow-delay-model, \d+ commits\)", f"(cm848/egr-flow-delay-model, {count} commits)", m)
old_cal = "2026-06-06 audit found 1352 legacy working-RAM `_cal` = cleanup backlog (rule unchanged)"
if old_cal in m:
    m = m.replace(old_cal, "the HARD backlog (1352 in 2026-06) is cleared since 2026-11-22 (PR #53 round 39); RAM "
                           "0x3feed0-0x40a048 = ROM + 0x39a3e6 (rule unchanged)")
open(M + "MEMORY.md", "w").write(m)
f = M + "typing_focus_2026_11.md"
t = open(f).read()
t = t.replace("The 0x40xxxx block is a ROM copy (RAM = ROM + 0x39a3e6).",
              "RAM 0x3feed0-0x40a048 is a ROM copy (RAM = ROM + 0x39a3e6, all 22717 dump words match).")
open(f, "w").write(t)
cf = M + "feedback_cal_suffix_memory_map.md"
if os.path.exists(cf):
    c = open(cf).read()
    add = ("\n\n**Update 2026-11-22 (PR #53 round 39):** the CM848 HARD list is empty (24 tables + 42 scalars renamed "
           "from their code and the parameter ID table). RAM 0x3feed0-0x40a048, just past the EEPROM mirror, is a copy "
           "of ROM 0x64aea-0x6fc62 (RAM = ROM + 0x39a3e6), so nothing there is `_cal`. 258 MISSING remain.")
    if "Update 2026-11-22" not in c:
        open(cf, "w").write(c.rstrip("\n") + add + "\n")
print("fix applied")

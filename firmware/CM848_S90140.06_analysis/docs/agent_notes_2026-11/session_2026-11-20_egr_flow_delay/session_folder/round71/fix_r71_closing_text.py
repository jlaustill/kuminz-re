"""Round 71 closing text fixes, applied to the closed files AND to apply_r71_closing.py (so the archived script
reproduces them). Idempotent.
- 'The pass-back made one DAT_0006ffff label disappear' named the wrong cause: typing the application table removed
  the pointer row at 0x53a33e (entry 0's end address 0x6ffff) that had created the label.
- The refused window is 0x3fd481 up to sensor_channel_ram_start (0x40a046) - say what it holds.
- The follow-up's proof and the audit's MISSING 211 -> 210 step were missing from task 046 / the PR test plan / the
  README.  usage: fix_r71_closing_text.py <repo> <pr_body.md>"""
import os
import sys

repo, pr = os.path.abspath(sys.argv[1]), sys.argv[2]
W = os.path.dirname(os.path.abspath(__file__))
TASK = os.path.join(repo, "work/tasks/046-cm848-egr-flow-estimate.md")
README = os.path.join(repo, "firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/"
                            "session_2026-11-20_egr_flow_delay/README.md")
CLOSING = os.path.join(W, "apply_r71_closing.py")
COMMIT = os.path.join(W, "commit_r71_closing.txt")

SEEN_OLD = ("- **Also seen:** the application writer also refuses (10) type 3 writes into 0x3fd481 up to "
            "`sensor_channel_ram_start`\n  while RAM refresh is on. The pass-back made one `DAT_0006ffff` label "
            "disappear: a removed pointer row had created it.")
SEEN_NEW = ("- **Also seen:** the application writer also refuses (10) type 3 writes into 0x3fd481 up to "
            "`sensor_channel_ram_start`\n  (0x40a046: the EEPROM mirror and the ROM-copied constants behind it) while "
            "RAM refresh is on. Typing the\n  application table removed a `DAT_0006ffff` label from "
            "`mpc555_cmfEraseBlocks`: the pointer row at 0x53a33e (entry\n  0's end address, 0x6ffff) had created it.")
JUNK_OLD = ("  - The junk row at 0x3fee03 (`j1939_cruise_state_t_003fee00.cruise_state_pad_03`: no such struct) is "
            "gone.")
JUNK_NEW = ("  - The junk row at 0x3fee03 (`j1939_cruise_state_t_003fee00.cruise_state_pad_03`: no such struct) is "
            "gone. It was an\n    EEPROM mirror name without `_cal`, so `audit_cal_suffixes.py` MISSING goes 211 -> "
            "210.\n  - **Proof:** 5 of 1968 functions differ (the callers whose temps lost `_00`); casts and "
            "placeholders are\n    unchanged; verify is byte-identical with stage A's warnings.")
FOLLOW = (" Follow-up (88e54bbb): 5 functions differ (the callers' temps), casts and placeholders unchanged, "
          "MISSING 210.")
README_OLD = "  `apply_r71_closing.py`, `update_large_tar_r71.sh`.\n"
README_NEW = ("  `apply_r71_closing.py`, `fix_r71_closing_text.py`, `update_large_tar_r71.sh`. **Follow-up:** "
              "`fix_r71b.py`. **Commit\n  messages:** `commit_r71a.txt`, `commit_r71b.txt`, "
              "`commit_r71_closing.txt`.\n")
COMMIT_OLD = ("  - The application writer's extra refusal of the calibration RAM window while RAM refresh is on.\n"
              "  - The lost DAT_0006ffff label.\n")
COMMIT_NEW = ("  - The application writer's extra refusal of 0x3fd481 up to sensor_channel_ram_start (the EEPROM mirror "
              "and the\n    ROM-copied constants) while RAM refresh is on.\n"
              "  - The DAT_0006ffff label that the removed pointer row at 0x53a33e had created.\n"
              "  - The follow-up's proof and the audit's MISSING 211 -> 210 step.\n")


def edit(p, old, new):
    t = open(p).read()
    if new in t:
        return
    assert t.count(old) == 1, (p, old[:70], t.count(old))
    open(p, "w").write(t.replace(old, new))


for p in (TASK, CLOSING):
    edit(p, SEEN_OLD, SEEN_NEW)
    edit(p, JUNK_OLD, JUNK_NEW)
edit(README, README_OLD, README_NEW)
# the closing script holds the README text as a Python literal: match its \n escapes
edit(CLOSING, README_OLD.replace("\n", "\\n"), README_NEW.replace("\n", "\\n"))
# the PR test plan line ends with the proof text; the closing script builds it from {proof}
t = open(pr).read()
i = t.index("- [x] Round 71: ")
j = t.index("\n", i)
if FOLLOW not in t[i:j]:
    t = t[:j] + FOLLOW + t[j:]
    open(pr, "w").write(t)
edit(CLOSING, 'edit(pr, "- [x] Round 70:", f"- [x] Round 71: {proof}\\n- [x] Round 70:")',
     'edit(pr, "- [x] Round 70:", f"- [x] Round 71: {proof}' + FOLLOW + '\\n- [x] Round 70:")')
edit(COMMIT, COMMIT_OLD, COMMIT_NEW)
print("closing text fixed")

"""Round 44 stage B closing: task 046 (stage B, the corrected stage A evidence and leads), PR body, README, todo, memory.
No CLAUDE.md edit. Idempotent (guard: the new text already present).
usage: apply_r44b_closing.py <repo> <pr_body.md> <hash B> <count> <proof line>"""
import os
import re
import sys

repo, pr, hb, count, proof = os.path.abspath(sys.argv[1]), sys.argv[2], sys.argv[3], sys.argv[4], sys.argv[5]


def path(rel):
    return rel if os.path.isabs(rel) else os.path.join(repo, rel)


def edit(rel, old, new):
    p = path(rel)
    t = open(p).read()
    if new in t:
        return
    assert t.count(old) == 1, (rel, old[:70], t.count(old))
    open(p, "w").write(t.replace(old, new))


T = "work/tasks/046-cm848-egr-flow-estimate.md"
edit(T, "  - The pedal block 0x408a72-0x408a7e lies past the dumped table, and no e2m record describes dual-channel pedal idle\n"
        "    learning or disagreement.\n",
     "  - The pedal block 0x408a72-0x408a7e lies past the dumped table. Stage A said no e2m record describes it. That was\n"
     "    wrong: the search output was read through `head`, which cut it before the 8Bxx-8Cxx blocks (stage B).\n")
edit(T, "- **Leads:**\n"
        "  - The oil change monitor's third accumulator. CHR_B2's e2m has an OCM \"FOD\" accumulator: grams since the last oil\n"
        "    change, from an rpm x fueling quantity map scaled by an Aux2 start-of-injection factor. CM848's is a 1-D table on\n"
        "    `main_injection_end_timing`, so the names do not transfer. Its \"engine power\" name stays unproven.\n"
        "  - `cruise_out_of_gear_disable` is 1 in the calibration, but no code reads it.\n",
     f"- **Stage B ({hb}, labels, rows):** the uncapped search finds the blocks that hold stage A's rows. They lie past the\n"
     "  dumped parameter ID table. Each block's CHR_CC layout fills a gap between dumped-table blocks exactly, and every\n"
     "  record's description matches the code that reads the row (`align_blocks.py`):\n"
     "  - 8C30 (6 bytes) fills 0x3ff6ca-0x3ff6cf, between 107D's last record and 107B.\n"
     "    - +4 Vac_Throttle_ASG_Delta is 0x3ff6ce, now `vacuum_throttle_all_speed_governor_fueling_reduction`.\n"
     "    - +0 / +2 (the driver override thresholds) get `i16` documentation rows; no instruction forms their addresses.\n"
     "  - 8B12 (4 bytes) fills 0x408e96-0x408e99, between 118F and 1071.\n"
     "    - +0 Cruise_Throttle_Transition_Threshold ('If throttle <= to this cal, will transition to cruise') is 0x408e96,\n"
     "      now `cruise_throttle_transition_threshold`.\n"
     "    - +2 Cruise_Bump_Up_Step_Adjust is `cruise_bump_up_step_margin_scale`.\n"
     "  - 8B4E (12 bytes) and 8BAC (28 bytes) fill 0x408a66-0x408a8d, between 8C5F and 8C55.\n"
     "    - 8BAC's 15 records match the 15 pedal calibration rows in order.\n"
     "    - +4 PPS_Test_Cell_Threshold_Auto_Zero ('PPS Auto_Zero threshold value if greater than is considered in test\n"
     "      cell') is 0x408a76, now `accelerator_pedal_test_cell_idle_threshold`.\n"
     "  - 8B4F (2 bytes) and 8BAD (14 bytes) fill 0x40b54a-0x40b559, between 8C60 and 8C56.\n"
     "    - They hold the severity factor and the 9 pedal state rows, widths included (+4..+7 are bytes).\n"
     "  - 8B50 (18 bytes) and 8BAE (4 bytes) fill the EEPROM rows 0x3fee34-0x3fee49.\n"
     "    - They hold the oil change monitor accumulators and the learned idle thresholds (PPS1 / PPS2_Auto_Zero).\n"
     "  - The oil change monitor's third accumulator is the oil soot percentage.\n"
     "    - 8B4E +8 OCM_Soot_Percentage_Threshold is 2.10 % here, and 8B50 +0xA is OCM_Soot_Percentage_Since_Last_Reset.\n"
     "    - The soot table 8B54 / 8B55 runs over the end of injection: 'Percentage of soot present in the engine oil\n"
     "      based on 250 operating hours'.\n"
     "    - The code adds table x 85048 / 900000 per pass. At the e2m's scales that is exactly 0.2 s per pass\n"
     "      (900000 s = 250 h; 85048 = 0.01 / 2.351589501e-8 x 0.2).\n"
     "    - The `engine_power_accumulator` names become `oil_change_monitor_soot_percentage_*`. The severity table\n"
     "      (8B51-8B53) becomes `oil_change_monitor_severity_factor_by_coolant_and_rpm_*`, and its output\n"
     "      `oil_change_monitor_severity_factor` (8B4F +0).\n"
     "    - The tables decode with the e2m scales: coolant -50..250 F, 0..3000 rpm, factors 1.00..2.00, the end of\n"
     "      injection -20.04..-5.04 deg, soot 47..0.37 %.\n"
     "  - Sources:\n"
     "    - The OCM blocks exist only in the older CHR_CC_11.20.13.16 / 11.25.05.07; the default 11.45.01.07 lacks them.\n"
     "    - The PPS, vacuum throttle and cruise blocks are in the default.\n"
     "    - 8B59 (OCM_Interval_Warning_Min_Miles, 2000 miles here) is cited by meaning only.\n"
     "  - 33 rows gain citations. 0x408e94's note narrows \"no code reads it\" to \"no direct access found\". The firmware\n"
     "    uses no small-data base register (r2 / r13 bases are under 0.1 % of D-form instructions), so the lis scan is\n"
     "    representative.\n"
     f"- **Proof (stage B):** {proof}\n"
     "- Stage B resolves task 042's [G4] soot table lead, round 43's \"engine power\" accumulator lead, and stage A's\n"
     "  oil change monitor lead.\n"
     "- **Leads:**\n"
     "  - The time-shared oil change monitor rows keep their types. e2m 8B50 gives +0 2 bytes and +2 / +6 4 bytes; the\n"
     "    rows at 0x3fee34 / 0x3fee36 / 0x3fee3a are dword / untyped / word. 0x3fee3a renders\n"
     "    `_oil_change_monitor_distance_pulses_cal`. The boot ROM shares 0x3fee34-0x3fee3d.\n"
     "  - `cruise_out_of_gear_disable` (e2m 118F +0x0C) is 1 in the calibration, but no direct access was found.\n"
     "  - 8B13 ASG_Throttle_Reset_Allow is not placed: no gap matches it.\n")
edit(pr, "  Cruise_Out_Of_Gear_Disable.\n\n## Test plan\n",
     "  Cruise_Out_Of_Gear_Disable.\n"
     f"- **Stage B ({hb}, labels, rows):** nine e2m blocks past the dumped parameter ID table placed by tiling. Stage A's\n"
     "  rows get their e2m names (Vac_Throttle_ASG_Delta, Cruise_Throttle_Transition_Threshold,\n"
     "  PPS_Test_Cell_Threshold_Auto_Zero). The oil change monitor's third accumulator is the oil soot percentage (e2m\n"
     "  OCM_Soot_Percentage_*). 33 rows gain citations.\n"
     "\n## Test plan\n")
edit(pr, "- [x] Round 44: label-only proof matches all 1968 functions",
     f"- [x] Round 44 stage B: {proof}\n"
     "- [x] Round 44: label-only proof matches all 1968 functions")
README = "firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-20_egr_flow_delay/README.md"
edit(README, "**Closing:** `apply_r44_closing.py`, `update_large_tar_r44.sh`.",
     "**Closing:** `apply_r44_closing.py`, `update_large_tar_r44.sh`. **Stage B:** `apply_r44b.py`, `map_r44b.csv`, "
     "`align_blocks.py` (+ `align_blocks.txt`), `candidate_blocks.txt`, `col5_neighbours.txt`, `check_history_r44b.py`, "
     "`apply_r44b_closing.py`.")
edit("work/todo.md", "round 44: round 39's unverified rows, the last typed junk row - open: the task 046 leads",
     "round 44: round 39's unverified rows, the last typed junk row, the oil soot model and the PPS block placed by "
     "tiling - open: the task 046 leads")
M = "/home/linux/.claude/projects/-home-linux-code-kuminz-re/memory/"
m = open(M + "MEMORY.md").read()
m = re.sub(r"\(cm848/egr-flow-delay-model, \d+ commits\)", f"(cm848/egr-flow-delay-model, {count} commits)", m)
old = "the last typed junk row named from code; raw_address_scan.py); task 046 leads"
new = ("the last typed junk row; stage B: 9 e2m blocks past the dumped table placed by TILING the gaps between table "
       "blocks - the oil soot model e2m 8B4E/8B50/8B54/8B55, the PPS block 8BAC/8BAD); task 046 leads")
if new not in m:
    assert m.count(old) == 1
    m = m.replace(old, new)
open(M + "MEMORY.md", "w").write(m)
f = M + "typing_focus_2026_11.md"
note = (f"  - Round 44 stage B (2026-11-22): {hb}. A block past the dumped parameter ID table can still be placed: its CHR_CC "
        "layout must fill a gap between dumped-table blocks exactly (end of one block to the base of the next), and "
        "every record's description must match the code. Never read a search's output through head (the cut fell "
        "before 8Bxx-8Cxx twice: rounds 43 and 44). Older CHR_CC releases carry blocks the default e2m lacks (the OCM "
        "is only in 11.20 / 11.25).\n")
if "Round 44 stage B (2026-11-22" not in open(f).read():
    open(f, "a").write(note)
print("round 44 stage B closing applied")

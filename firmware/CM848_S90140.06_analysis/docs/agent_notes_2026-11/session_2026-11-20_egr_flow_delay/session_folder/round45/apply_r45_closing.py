"""Round 45 closing: task 046, PR body, README, todo, memory. No CLAUDE.md edit. Idempotent (guard: new text present).
usage: apply_r45_closing.py <repo> <pr_body.md> <hash A> <count> <proof line>"""
import os
import re
import sys

repo, pr, ha, count, proof = os.path.abspath(sys.argv[1]), sys.argv[2], sys.argv[3], sys.argv[4], sys.argv[5]


def path(rel):
    return rel if os.path.isabs(rel) else os.path.join(repo, rel)


def edit(rel, old, new):
    p = path(rel)
    t = open(p).read()
    if new in t:
        return
    assert t.count(old) == 1, (rel, old[:70], t.count(old))
    open(p, "w").write(t.replace(old, new))


T46 = f"""## Done, round 45 (2026-11-22, same PR): the table gap sweep

A peer relay started the round; the scripts are in `session_folder/round45/`.
- **Method:** round 44's tiling, made systematic.
  - `sweep_table_gaps.py` sizes every dumped parameter ID table block from its default e2m records. An axis or array
    adds its ROM byte-length word; a grid makes the extent unknown. It lists the gaps between consecutive blocks.
  - `match_gap_signatures.py` keeps the absent CHR_CC blocks, one or an ordered pair, whose record widths land on
    the CM848 rows' asm-verified widths and cover every row in the gap.
  - `rank_gap_semantics.py` ranks candidates by shared words; `show_placement.py` lays a candidate over its rows.
  - Layouts come from the default CHR_CC_11.45.01.07 first, then the nearest release. The e2m size column is
    decimal; the first run parsed it as hex.
- **Validation:** the sweep finds round 44's placement independently: one perfect match, 8B4E + 8BAC, for the
  40-byte gap. It agrees with the offset alignments of rounds 12, 14 and 26: 8B3C, 1496, 14EF and 8C2F.
- **Stage A ({ha}, labels, rows):** six blocks, from the default e2m, each with one layout across the releases.
  - Tiled, each filling a gap between dumped-table blocks exactly:
    - 8A88 is the injector diagnostic debounce limits.
    - 8A89 + 1D41 (the only width match for its gap) is the fuel level rationality monitor (the
      `fuel_level_low_distance_*` rows) and the fuel pressure idle rationality test (the
      `fuel_pressure_sensor_plausibility_*` rows).
    - 15C7 (ROM) is the P0500 vehicle speed sensor monitor.
    - 8A7E is the oil pressure gauge and the low oil switch.
  - Anchored at the start and matched by field: 14EB, the J1939 DM13 state. Its rows already quoted its bracket codes.
  - Round 12's 8B3C: three rows gain citations.
  - Names:
    - `fuel_pressure_sensor_plausibility_maximum_governor_output` -> `fuel_pressure_sensor_plausibility_maximum_throttle`
      (FP_Idle_Throttle_Limit, %THROTTLE; the code compares `all_speed_governor_equivalent_throttle`).
    - New names in 8A7E: `engine_oil_pressure_filter_coefficient` (OPG_Pressure_Filter_Constant) and its EMA
      `engine_oil_pressure_filter_state`.
    - New rows in 8A7E: `low_oil_switch_chime_enable` and `engine_oil_pressure_default`, both read by
      `cm848_processEngineOilPressure`.
    - A documentation row: `vehicle_speed_sensor_stopped_engine_speed` (15C7 +4; no direct access found).
  - This truck runs the oil pressure switch-only path, so the sensor-path threshold (0) is unused.
  - Names kept, with the code checked:
    - `oil_pressure_switch_stuck_count_limit` (Low_Oil_Switch_Error_Time: the count runs with the engine stopped and
      no low pressure shown) and `oil_pressure_switch_fault_running_count_limit` (Low_Oil_Switch_Chime_Time).
    - `fuel_pressure_sensor_plausibility_step_limit` (FP_Idle_Time_Limit, 0.1 s; its counter is the average's sample
      count).
  - Rejected:
    - 8D04: its widths match 0x40a264, but its throttle valve actuator records land on rows the J1939 anti-theft
      handler writes.
    - 8B06: its EEPROM byte 0x34 is `eeprom_version_marker`; `feature_selection_bits_cal` is at EEPROM 0x480.
- **Coverage:** 106 gaps of 1-64 bytes between blocks of known extent. 25 have a perfect width match; this round read
  the unique ones and the word-ranked leads above 0.5. The rest, and the gaps next to grids, stay a lead.
- **Proof:** {proof}
- **firmware/CLAUDE.md:** no edit. HARD stays 0 and MISSING 221.
- **Leads:**
  - The other perfect-match gaps (many candidates each) and the 81 gaps with none.
  - The `fuel_level_low_distance_*` family (11 rows) could take the e2m's "rationality" vocabulary.

## Leads (not in this PR)"""
edit("work/tasks/046-cm848-egr-flow-estimate.md", "## Leads (not in this PR)", T46)
edit(pr, "\n## Test plan\n",
     "**Round 45.**\n"
     f"- **Stage A ({ha}, labels, rows):** a sweep of the gaps between dumped parameter ID table blocks. It places six\n"
     "  more e2m blocks: the injector debounce limits, the fuel level and fuel pressure rationality tests, the P0500\n"
     "  vehicle speed sensor monitor, the oil pressure gauge and low oil switch (2 new rows, 2 named), and the DM13\n"
     "  state. One rename.\n"
     "\n## Test plan\n")
edit(pr, "- [x] Round 44 stage C:", f"- [x] Round 45: {proof}\n- [x] Round 44 stage C:")
README = "firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-20_egr_flow_delay/README.md"
t = open(path(README)).read()
NEW = ("\n## Round 45: the table gap sweep (`session_folder/round45/`)\n\n"
       "- **Sweep:** `sweep_table_gaps.py` (+ `sweep_gaps.txt`), `match_gap_signatures.py` (+ `gap_signatures*.txt`), "
       "`rank_gap_semantics.py` (+ `gap_semantics.txt`), `show_placement.py` (+ `placements_*.txt`), "
       "`citation_status.py`, `fix_tools_r45.py`. **Stage A:** `apply_r45a.py`, `map_r45a.csv`. **Closing:** "
       "`apply_r45_closing.py`, `update_large_tar_r45.sh`.\n")
if "## Round 45:" not in t:
    i = t.index("## Round 44:")
    j = t.find("\n## ", i + 5)
    t = t[:j] + "\n" + NEW.rstrip("\n") + t[j:] if j != -1 else t.rstrip("\n") + "\n" + NEW
    open(path(README), "w").write(t)
edit("work/todo.md", "the PPS learning time limit - open: the task 046 leads",
     "the PPS learning time limit; round 45: the table gap sweep, six more e2m blocks - open: the task 046 leads")
M = "/home/linux/.claude/projects/-home-linux-code-kuminz-re/memory/"
m = open(M + "MEMORY.md").read()
m = re.sub(r"\(cm848/egr-flow-delay-model, \d+ commits\)", f"(cm848/egr-flow-delay-model, {count} commits)", m)
old = "stage C: the PPS learning time limit); task 046 leads"
new = ("stage C: the PPS learning time limit) + round 45 (table GAP SWEEP: sweep_table_gaps.py + match_gap_signatures.py "
       "width signatures, 6 more blocks; width match alone misleads - check meaning); task 046 leads")
if new not in m:
    assert m.count(old) == 1
    m = m.replace(old, new)
open(M + "MEMORY.md", "w").write(m)
f = M + "typing_focus_2026_11.md"
note = (f"  - Round 45 (2026-11-22): {ha}. The gap sweep (session_folder/round45/) sizes each dumped-table block, lists "
        "the gaps and keeps absent CHR_CC blocks whose record widths land on the rows' asm widths. A width match alone "
        "misleads (8D04's actuator records fit J1939 anti-theft rows): read the code. The e2m size column is decimal. "
        "When a script inserts rows, rebuild its address index.\n")
if "Round 45 (2026-11-22" not in open(f).read():
    open(f, "a").write(note)
print("round 45 closing applied")

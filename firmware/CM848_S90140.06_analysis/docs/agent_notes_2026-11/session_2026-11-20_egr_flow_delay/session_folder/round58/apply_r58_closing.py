"""Round 58 closing: task 046, PR body, README, todo, memory, and one factual firmware/CLAUDE.md correction (the
MISSING count this round's own rows changed: numbers only, no rule text). Idempotent.
usage: apply_r58_closing.py <repo> <pr_body.md> <hash A> <count> <proof> <protection names left>"""
import os
import re
import sys

repo, pr, ha, count, proof, left = os.path.abspath(sys.argv[1]), *sys.argv[2:7]


def path(rel):
    return rel if os.path.isabs(rel) else os.path.join(repo, rel)


def edit(rel, old, new):
    p = path(rel)
    t = open(p).read()
    if new in t:
        return
    assert t.count(old) == 1, (rel, old[:70], t.count(old))
    open(p, "w").write(t.replace(old, new))


T46 = f"""## Done, round 58 (2026-11-23, same PR): the last 12 protection_* globals named from their code

A peer relay started the round; the scripts are in `session_folder/round58/`.
- **Stage A ({ha}).** Accesses were checked with `scan_accesses_v2.py`, a base-tracking D-form scan of both banks
  (lis / addi / ori / mr bases). Computed pointers can escape it, so the rows say "no other access found".
  - **The logical output line map** (EEPROM mirror; the boot kernel's time-shared rows inside it keep their names):
    `logical_output_line_cal` (the table), `logical_output_line_active_low_bits_cal` (the polarity bits),
    `logical_output_62_line_cal` (was `qadc_adc_enable_flag`) and `cm848_mirrorTransmissionSolenoidRequestsToOutputs62And63`
    (outputs 62 / 63 follow the overdrive / converter clutch solenoid requests; active on this truck).
  - **The injector driver booster:** `injector_driver_booster_recharge_off_delay_counter` (e2m 8041 +26) and
    `fuel_system_hardware_shutdown_check_enable_flag` (was `tpu_protection_enable_flag`).
  - **The P0116 coolant rationality monitor:** its snapshot words (two of them new rows), the start delay countdown,
    and `cm848_initializeCoolantTemperatureSensorPerformanceMonitor`.
  - **Others:** `transmission_diagnostic_flags_6` (e2m 8C19 +13), `combustion_torque_by_fuel_quantity_friction_cached_axis_offsets`
    with `cm848_initializeFrictionTorqueLookupCache` (was `cm848_initThrottleRateFilterState`), and
    `all_speed_governor_spare_word_1` / `_2` / `_3` (set to 2 at boot; no other access found).
  - Two junk documentation rows were deleted (`protection_b_state_t_003feebc.protection_b_pad_01` / `_03`).
- **Proof:** {proof}
- **firmware/CLAUDE.md (factual correction, numbers only):** the MISSING sentence now gives 218 since round 58 (121
  documentation rows, 3 deferred). This round's own rows changed it: `logical_output_62_line_cal` gained `_cal`, and two
  documentation rows were deleted.
- **Leads:**
  - No global keeps a `protection_` prefix now. {left} rows still have `protection` inside their names.
  - Entry 17 of the line table renders as the boot kernel's time-shared name `qadc_queue_timing_config._0_2_` in the
    mirror function.
  - `coolant_temperature_sensor_performance_snapshot_coolant_temperature` is read only with `lha`, so it is an `i16`
    candidate.
  - `scan_accesses_v2.py` could become a repo tool (an access finder that sees base-register forms).

## Leads (not in this PR)"""
edit("work/tasks/046-cm848-egr-flow-estimate.md", "## Leads (not in this PR)", T46)
edit(pr, "\n## Test plan\n",
     "**Round 58.**\n"
     f"- **Stage A ({ha}):** the last 12 `protection_*` globals named from their code. They cover the logical output\n"
     "  line map and its active-low bits, the injector driver booster recharge-off delay, the P0116 coolant monitor's\n"
     "  snapshot, 8C19 +13 and a friction torque lookup cache. Also 3 functions, 2 new rows and 2 junk rows deleted;\n"
     "  MISSING 221 -> 218.\n"
     "\n## Test plan\n")
edit(pr, "- [x] Round 57:", f"- [x] Round 58: {proof}\n- [x] Round 57:")
README = "firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-20_egr_flow_delay/README.md"
t = open(path(README)).read()
NEW = ("\n## Round 58: the last protection_* globals (`session_folder/round58/`)\n\n"
       "- **Stage A:** `apply_r58a.py`, `map_r58a.csv`, the access scanners `scan_accesses.py` / `scan_accesses_v2.py`, "
       "`uses.py`. Proof: `prove_r58.sh`, `count_casts.py`. **Closing:** `apply_r58_closing.py`, "
       "`update_large_tar_r58.sh`.\n")
if "## Round 58:" not in t:
    i = t.index("## Round 57:")
    j = t.find("\n## ", i + 5)
    t = t[:j] + "\n" + NEW.rstrip("\n") + t[j:] if j != -1 else t.rstrip("\n") + "\n" + NEW
    open(path(README), "w").write(t)
edit("work/todo.md",
     "round 57: the cruise cluster, the cruise N/V ratio, two warning chime sources - open: the task 046 leads",
     "round 57: the cruise cluster, the cruise N/V ratio, two warning chime sources; round 58: the last protection_* "
     "globals - open: the task 046 leads")
edit("firmware/CLAUDE.md",
     "MISSING (EEPROM-backed names without `_cal`) is 221 since PR #53 round 43: 123 documentation rows (`name[n]` / "
     "`name.field`, which never end in `_cal`), 77 boot-named and 10 dual-use rows at addresses the boot kernel shares, "
     "7 with no reference by name, and 4 deferred.",
     "MISSING (EEPROM-backed names without `_cal`) is 218 since PR #53 round 58: 121 documentation rows (`name[n]` / "
     "`name.field`, which never end in `_cal`), 77 boot-named and 10 dual-use rows at addresses the boot kernel shares, "
     "7 with no reference by name, and 3 deferred.")
M = "/home/linux/.claude/projects/-home-linux-code-kuminz-re/memory/"
edit(M + "feedback_cal_suffix_memory_map.md",
     "MISSING is 221 since round 43 (123 documentation rows, 77 boot-named and 10 dual-use rows at time-shared "
     "addresses, 7 unreferenced, 4 deferred)",
     "MISSING is 218 since round 58 (121 documentation rows, 77 boot-named and 10 dual-use rows at time-shared "
     "addresses, 7 unreferenced, 3 deferred)")
m = open(M + "MEMORY.md").read()
m = re.sub(r"\(cm848/egr-flow-delay-model, \d+ commits\)", f"(cm848/egr-flow-delay-model, {count} commits)", m)
old = "the 8A0E / 8A0F N/V ratio, 2 warning chime sources); task 046 leads"
new = ("the 8A0E / 8A0F N/V ratio, 2 warning chime sources) + round 58 (the last 12 protection_* globals: the logical "
       "output line map, the booster recharge-off delay, the P0116 snapshot; MISSING 218); task 046 leads")
if new not in m:
    assert m.count(old) == 1
    m = m.replace(old, new)
open(M + "MEMORY.md", "w").write(m)
f = M + "typing_focus_2026_11.md"
note = (f"  - Round 58 (2026-11-23): {ha}. The last protection_* globals. A lis-only address scan misses base-register "
        "forms (lbz r11,19(r31) after mr r31,r6): use r58's scan_accesses_v2.py (lis / addi / ori / mr tracking) before "
        "claiming a word has no reader.\n")
if "Round 58 (2026-11-23" not in open(f).read():
    open(f, "a").write(note)
print("round 58 closing applied")

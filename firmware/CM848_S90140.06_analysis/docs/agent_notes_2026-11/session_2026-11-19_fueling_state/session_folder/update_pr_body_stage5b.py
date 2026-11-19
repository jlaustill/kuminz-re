"""Add stage 5b to pr_body.md (summary item, a stage section, the checks bullet, the open items).
usage: update_pr_body_stage5b.py <pr_body.md>"""
import sys

path = sys.argv[1]
s = open(path).read()


def replace(old, new):
    global s
    assert s.count(old) == 1, old[:70]
    s = s.replace(old, new)


replace("Code 32 is the master / slave override.\n",
        "Code 32 is the master / slave override. A follow-up (5b) renamed the emission control (AECD) words, which "
        "read backwards, and fixed the comments that still used the old engine state words.\n")
replace("  - the engine start / extended idle / extreme ambient AECD words (e2m `EMO_*_AECD_Active` / `_Cap_EL`);\n",
        "  - the engine start / extended idle / extreme ambient AECD words (e2m `EMO_*_AECD_Active` / `_Cap_EL`), renamed "
        "again in stage 5b;\n")
replace("## Checks\n", """## Stage 5b: the AECD words fixed, the old engine state prose

A review of stage 5 found 16 applied rows that had not been checked. Checking them led to these fixes:

- **The AECD words.** Stage 5's `*_emission_control_active_flag` read backwards: an auxiliary emission control device relaxes NOx control while it is active. They now follow wave 9's `condensation_protection_*` family:
  - `engine_start_warmup_protection_*` (e2m 19B2 / 19B3);
  - `extended_idle_protection_*` (19B0 / 19B1). Its 300 s timer runs only while the low speed governor or the power take-off governor has the fueling;
  - `extreme_ambient_overheat_protection_*` (19A1-19A4): a 217 / 222 °F coolant hysteresis. The old names called it a cold start boost override.
  - Each `_emission_level_cap` goes into the max-select of `fuel_demandMin_maxSelect_rateLimit`. EL is the emission level: the condensation AECD's cap is the "NOx cap value to be used when condensation triggers EGR off".
  - Four calibration rows were added and the three update functions renamed. None of the three AECDs is enabled on this truck (`algorithm_enable_flags_20_cal` = 0x0100).
- **The old engine state words in comments.** "At the governor setpoint" is RUNNING, "fuel mode switch" is ENGINE_BRAKE and "cold start phase 3" is `engine_is_active_flag`. All ten comments were checked against the compare in the code. `fuel_cold_start_phase3_compensation_enable_flag` is now `condensation_count_enable_flag`.
- **A correction.** `combustion_status_flags` bit 0x02 means "engine stopped", so the dump's 0x402 only shows that it was taken with the engine off. The old note "why EGR is requested off on this truck" was a misreading.
- **Checked, no change:**
  - the crank tables: the e2m 8A44-8A4C axes and destinations match the code;
  - ENGINE_BRAKE: its only entry needs `engine_brake_driveline_brake_type_cal` = 0 (e2m: 1 = retarder), and the dump has 1.

## Checks
""")
replace("- Every `FUELING_STATE_` name in the `.cpp` sits on a carrier.\n",
        "- **Stage 5b.** `reverse_names.py` says **EQUIVALENT**: a pure label rename, all 17 names rendered (one function differs only in the order of its local declarations).\n"
        "- Every `FUELING_STATE_` name in the `.cpp` sits on a carrier.\n")
replace("- The i16 retypes of the signed crank words, and the four low-confidence crank words.\n",
        "- The i16 retypes of the signed crank words, and the four low-confidence crank words.\n"
        "- The rest of the EMO family: the other inputs of `fuel_demandMin_maxSelect_rateLimit` and its output `fuel_demand_min_threshold`, which look like AECD caps rather than fuel demands.\n")
open(path, "w").write(s)
print("pr_body.md updated for 5b")

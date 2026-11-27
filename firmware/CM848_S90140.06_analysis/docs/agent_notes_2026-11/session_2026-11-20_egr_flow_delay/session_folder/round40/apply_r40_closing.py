"""Round 40 closing: task 046, PR body, README, todo, memory. Idempotent.
usage: apply_r40_closing.py <repo> <pr_body.md> <hash A> <hash B> <commit count>"""
import os
import re
import sys

repo, pr, ha, hb, count = os.path.abspath(sys.argv[1]), sys.argv[2], sys.argv[3], sys.argv[4], sys.argv[5]


def path(rel):
    return rel if os.path.isabs(rel) else os.path.join(repo, rel)


def edit(rel, old, new):
    p = path(rel)
    t = open(p).read()
    if new in t:
        return
    assert t.count(old) == 1, (rel, old[:70], t.count(old))
    open(p, "w").write(t.replace(old, new))


T46 = f"""## Done, round 40 (2026-11-22, same PR): the application's EEPROM mirror names

Two peer relays covered the round. The scripts are in `session_folder/round40/`.
- **Stage A ({ha}, labels):** `audit_cal_suffixes.py` MISSING 258 -> 234.
  - **Which rows:** `missing_users.py` sorts the rows by who uses them; only names that application code alone uses and
    that describe the application's EEPROM value change. Every candidate went through the ECU's parameter ID table
    first, which resolves 8.
  - **Seven names change with the evidence:**
    - the idle counters (e2m 117F +A Total_Idle_Fuel_Used: the "governed speed" flag is the low speed governor within
      50 rpm of its reference), now `lifetime_idle_*_cal` / `trip_idle_*_cal` / `engine_idling_flag`;
    - `low_speed_governor_no_load_fuel_trim_cal` (was governor_speed_target_trim: a fuel addend);
    - `feature_selection_bits_cal` (was j1939_governor_feature_byte: a scan-tool feature bitmap);
    - `eeprom_verify_retry_lifetime_total_cal`;
    - `final_fueling_state_before_shutdown_or_excess_injection_fault_cal`;
    - `exhaust_brake_switch_learned_flag_cal` (was protection_b_fault_active_flag).
  - The other 17 rows only gain `_cal`, among them the VIN, `lifetime_distance_pulses_cal` and the
    0x19ce-0x19f2 counters.
  - `arrays.csv` also named the VIN; its arrays stage overrides the globals' name, so it changed too.
  - 1967 functions match the canonical form; the VIN reader differs only by whitespace.
- **Stage B ({hb}, a type):** `feature_selection_bits_t`, five proven bits and three reserved.
  - The five tests are mask-exact (0 differing statements).
  - The SCI setting lookup's pointer temp is typed `byte *` (`local_variables.csv`), so the struct type does not spread
    there. With it, 15 raw setting addresses render as fields (each checked against its old address).
- **firmware/CLAUDE.md (name refreshes):**
  - The trip / lifetime, vehicle speed, switch, sensor channel and power take-off sections use the new names
    (`refresh_references.py`).
  - One factual fix: "+/-400 rpm ... probably idle" is +/-400 counts = 50 rpm, idle by e2m 117F +A.
- **The residual 234 MISSING:**
  - 123 documentation rows (`name[n]` / `name.field`, which can never end in `_cal`: an auditor false positive);
  - 77 boot-named rows at addresses the boot kernel uses before the application loads the mirror;
  - 10 dual-use rows;
  - 18 with no reference by name (not proof of unused);
  - 6 deferred: the region labels `eeprom_mirror` / `eeprom_checksummed_block_start`; `qadc_adc_enable_flag` and
    `fault_list_iteration_counter` without evidence; the `fault_status_array` / `_word_array` pair (needs a shape).
- **Leads:**
  - the 6 deferred rows;
  - the junk rows `sensor_validation_accum+2` (inside `lifetime_distance_pulses_cal`) and
    `sensor_validation_delta+1`;
  - the immobilizer secret key bytes under boot-time names;
  - `audit_cal_suffixes.py` could skip documentation rows.

## Leads (not in this PR)"""
edit("work/tasks/046-cm848-egr-flow-estimate.md", "## Leads (not in this PR)", T46)
edit(pr, "\n## Test plan\n",
     "**Round 40.**\n"
     f"- **Stage A ({ha}, labels):** 24 application-side names in the EEPROM mirror gain `_cal`; 7 renamed from their e2m\n"
     "  records and code (the idle counters, the feature bitmap, the exhaust brake switch learned flag, ...).\n"
     f"- **Stage B ({hb}, a type):** `feature_selection_bits_cal` as a bitfield struct; the SCI setting lookup's pointer\n"
     "  typed `byte *`.\n"
     "\n## Test plan\n")
edit(pr, "- [x] Round 39: every function matches the canonical form or has 0 differing statements;",
     "- [x] Round 40: every function matches the canonical form or has 0 differing statements (bitfield tests "
     "rewritten to their masks); 15 / 15 resolved addresses checked; MISSING 258 -> 234.\n"
     "- [x] Round 39: every function matches the canonical form or has 0 differing statements;")
README = "firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-20_egr_flow_delay/README.md"
t = open(path(README)).read()
NEW = ("\n## Round 40: the application's EEPROM mirror names (`session_folder/round40/`)\n\n"
       "- **Stage A:** `audit.txt`, `missing_survey.py` / `missing.tsv`, `missing_users.py` / `missing_users.tsv` (who "
       "uses each row), `app_e2m.txt` (the parameter ID table), `apply_r40a.py`, `apply_r40a_followups.py`.\n"
       "- **Stage B:** `apply_r40b.py`, `rules_r40b*.json`, `address_pairs_check.py`.\n"
       "- **Closing:** `apply_r40_closing.py`, `update_large_tar_r40.sh`.\n")
if "## Round 40:" not in t:
    i = t.index("## Round 39:")
    j = t.find("\n## ", i + 5)
    t = t[:j] + "\n" + NEW.rstrip("\n") + t[j:] if j != -1 else t.rstrip("\n") + "\n" + NEW
    open(path(README), "w").write(t)
edit("work/todo.md", "round 39: the _cal HARD list cleared (63 -> 0) - open: the task 046 leads",
     "round 39: the _cal HARD list cleared (63 -> 0); round 40: the EEPROM mirror names (MISSING 258 -> 234) - open: "
     "the task 046 leads")
M = "/home/linux/.claude/projects/-home-linux-code-kuminz-re/memory/"
m = open(M + "MEMORY.md").read()
m = re.sub(r"\(cm848/egr-flow-delay-model, \d+ commits\)", f"(cm848/egr-flow-delay-model, {count} commits)", m)
old = ("supervisor chip block re-domained); task 046 leads")
new = ("supervisor chip block re-domained) + round 40 (EEPROM mirror names gain _cal, MISSING 258 -> 234: the idle "
       "counters, feature_selection_bits_t, the exhaust brake switch learned flag); task 046 leads")
if new not in m:
    assert m.count(old) == 1
    m = m.replace(old, new)
open(M + "MEMORY.md", "w").write(m)
f = M + "typing_focus_2026_11.md"
note = (f"  - Round 40 (2026-11-22): {ha} / {hb} MISSING 258 -> 234. Sort MISSING rows by who uses them "
        "(missing_users.py: boot / app / both) - only app-only names describing the application's EEPROM value get "
        "_cal; boot-named rows at time-shared addresses keep their names. arrays.csv names override "
        "global_variables.csv (rename both). Typing a pointer-taken global as a struct spreads the type to a shared "
        "pointer temp: type that local in local_variables.csv.\n")
if "Round 40 (2026-11-22" not in open(f).read():
    open(f, "a").write(note)
print("round 40 closing applied")

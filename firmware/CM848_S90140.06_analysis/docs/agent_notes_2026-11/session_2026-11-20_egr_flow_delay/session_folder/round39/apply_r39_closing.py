"""Round 39 closing: task 046, PR body, README, todo, memory. Idempotent.
usage: apply_r39_closing.py <repo> <pr_body.md> <hash A> <hash B> <hash C> <commit count>"""
import os
import sys

repo, pr, ha, hb, hc, count = os.path.abspath(sys.argv[1]), sys.argv[2], sys.argv[3], sys.argv[4], sys.argv[5], sys.argv[6]


def path(rel):
    return rel if os.path.isabs(rel) else os.path.join(repo, rel)


def edit(rel, old, new):
    p = path(rel)
    t = open(p).read()
    if new in t:
        return
    assert t.count(old) == 1, (rel, old[:70], t.count(old))
    open(p, "w").write(t.replace(old, new))


T46 = f"""## Done, round 39 (2026-11-22, same PR): the `_cal` HARD list cleared

A peer relay started the round. The `auditing-cal-suffixes` skill drove it, and the scripts are in
`session_folder/round39/`. `audit_cal_suffixes.py` HARD went from 63 to 0 and SOFT from 4 to 0, so no `_cal` name is
left outside the EEPROM mirror.
- **Stage A ({ha}, labels, types):** the 24 lookup tables that the auditor flagged (20 HARD at 0x40xxxx, 4 SOFT in
  Bank1 ROM), named from their own lookups in the table grammar, with 11 caches. Four caches were widened to `word[2]`
  with their y halves merged, and DAT_003fb01a gained a `word[2]` row.
  - Wrong-domain old names: the "injection timing temperature correction" map is the turbocharger corrected speed map,
    and the "J1939 fuel table" is e2m MT_Max_Torque_Map.
- **Stage B ({hb}, labels, a type):** stage A's names checked against the ECU's parameter ID table
  (`e2m_block_addresses.py --address`). It resolves 19 of the 24.
  - Four renames:
    - `cylinder_balance_stop_compensation_*` (81B1-81B3);
    - `next_cylinder_by_crank_tooth_*` / `next_cylinder_by_cam_tooth_*` (8197 / 8198, 8195 / 8196; table b reads TPU-A
      channel 1);
    - `cam_tooth_good_window_fraction_*` (PMA = the cam wheel input);
    - `low_speed_governor_fuel_by_commanded_throttle_*` (one addend of the no-load fuel).
  - The dword `crank_sync_phase_counter` is two words: `crank_out_of_phase_count` (e2m 8194 +8) and the good window
    cache that stage A missed.
  - Stage A's comments were corrected: the expected firing revolutions lookup is a signed axis read at the literal 2,
    not a step lookup, and the fuel metering PWM unit is open (see the leads).
- **Stage C ({hc}, labels, types):** the last 42 HARD scalars. 39 of them sit in the 0x40xxxx block, which is a ROM copy
  (RAM = ROM + 0x39a3e6), and the code writes none of the 42.
  - 39 are renamed from their code use, 11 of them also from their e2m record.
  - 3 only lose the `_cal` and are marked unverified.
  - The supervisor chip block was J1939-named: `supervisor_register_148` / `152` / `158` / `164` settings, the word[4]
    `supervisor_configuration_transmit_words`, `supervisor_watchdog_cycle_interval` / `_window_setting`, and the
    schedule counters (the word `j1939_tx_periodic_counter` is two byte counters).
  - `temperature_protection_*` is the park / neutral exit window, the `cruise_speed_*` rows are the
    fuel_rpm_compensated_offset clamps, and the `protection_fuel_demand_snapshot_*` rows are the pedal substitutes.
- **Proof:** every stage matches `prove_caches.py`'s canonical form for each function the type changes leave alone.
  `statement_diff.py` shows 0 differing statements in the 3 + 5 functions those changes touch.
- **firmware/CLAUDE.md (factual refresh):** the "~1352 HARD" sentence now says the HARD list is empty, that the
  0x40xxxx block is a ROM copy, and that 258 MISSING remain.
- **Leads:**
  - The fuel metering PWM frequency: e2m 80C2 says Hz at 1.0 per count, but TPU-B's 3.2 us tick makes it
    value / 16 Hz. Scope the output on the bench.
  - The 3 unverified rows: `governor_override_fuel_decay`, `governor_override_fuel_threshold`, `cruise_speed_target_min`.
  - `cm848_processFaultScanLookup` is the injector driver booster capacitor monitor; the function and its
    `per_cylinder_timing_*` arrays still carry guessed names.
  - The 258 MISSING (EEPROM-backed names without `_cal`); many are dotted documentation rows.
  - `safety_fuel_limit_*` and the commanded-throttle addend resolve no e2m record (the parameter ID table dump holds
    1441 of 1886 records).
  - `engine_retarder_torque_cached_axis_offset`'s phantom `in_r6` data argument.
  - The `auditing-cal-suffixes` skill still says "~1352 HARD"; the list is empty now.

## Leads (not in this PR)"""
edit("work/tasks/046-cm848-egr-flow-estimate.md", "## Leads (not in this PR)", T46)
edit(pr, "\n## Test plan\n",
     "**Round 39.**\n"
     f"- **Stage A ({ha}, labels, types):** the 24 lookup tables named `_cal` outside the EEPROM mirror, renamed after\n"
     "  their lookups (the turbocharger corrected speed map, e2m MT_Max_Torque_Map, ...), and 11 caches.\n"
     f"- **Stage B ({hb}, labels, a type):** stage A checked against the ECU's parameter ID table: four e2m renames (CBD\n"
     "  stop compensation, crank / cam based next cylinder, the cam tooth window) and the cam window cache split from a\n"
     "  dword.\n"
     f"- **Stage C ({hc}, labels, types):** the last 42 HARD `_cal` scalars renamed from their code (11 with e2m records);\n"
     "  the J1939-named supervisor chip block re-domained. `audit_cal_suffixes.py` HARD 63 -> 0.\n"
     "\n## Test plan\n")
edit(pr, "- [x] Round 38: all 1968 functions match the canonical form.",
     "- [x] Round 39: every function matches the canonical form or has 0 differing statements; "
     "`audit_cal_suffixes.py` HARD 63 -> 0, SOFT 4 -> 0.\n"
     "- [x] Round 38: all 1968 functions match the canonical form.")
README = "firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-20_egr_flow_delay/README.md"
t = open(path(README)).read()
NEW = ("\n## Round 39: the `_cal` HARD list cleared (`session_folder/round39/`)\n\n"
       "- **Stage A:** `audit.txt` (the auditor's report), `plan.txt` (`lookup_tables.py --plan`), `table_calls.py`, "
       "`apply_r39a.py`.\n"
       "- **Stage B:** `apply_r39b.py`, `make_rules_r39b.py` / `rules_r39b*.json` (`statement_diff.py` rules).\n"
       "- **Stage C:** `hard_scalars.py` / `hard_scalars.tsv` (each HARD row with its e2m record, ROM-copy check and "
       "writes), `symbol_uses.py`, `use_context.py`, `apply_r39c.py`, `make_rules_r39c.py`.\n"
       "- **Closing:** `apply_r39_closing.py`, `update_large_tar_r39.sh`.\n")
if "## Round 39:" not in t:
    i = t.index("## Round 38:")
    j = t.find("\n## ", i + 5)
    t = t[:j] + "\n" + NEW.rstrip("\n") + t[j:] if j != -1 else t.rstrip("\n") + "\n" + NEW
    open(path(README), "w").write(t)
edit("work/todo.md", "round 38: the named cache audit (34 widened / 24 renamed) - open: the task 046 leads",
     "round 38: the named cache audit (34 widened / 24 renamed); round 39: the _cal HARD list cleared (63 -> 0) - open: "
     "the task 046 leads")
M = "/home/linux/.claude/projects/-home-linux-code-kuminz-re/memory/"
m = open(M + "MEMORY.md").read()
m = m.replace("(cm848/egr-flow-delay-model, 189 commits)", f"(cm848/egr-flow-delay-model, {count} commits)")
old = "+ round 38 (named cache audit: 34 2-D caches widened to word[2], 24 renamed); task 046 leads"
new = ("+ round 38 (named cache audit: 34 2-D caches widened to word[2], 24 renamed) + round 39 (the _cal HARD list "
       "cleared 63 -> 0: 24 tables + 42 scalars named from their code / the parameter ID table; the J1939-named "
       "supervisor chip block re-domained); task 046 leads")
if new not in m:
    assert m.count(old) == 1
    m = m.replace(old, new)
open(M + "MEMORY.md", "w").write(m)
f = M + "typing_focus_2026_11.md"
note = (f"  - Round 39 (2026-11-22): {ha} / {hb} / {hc} cleared audit_cal_suffixes.py HARD 63 -> 0 (24 tables, 42 "
        "scalars). Check every table / scalar against `e2m_block_addresses.py --address` BEFORE naming it from code "
        "(stage B had to fix 4 stage A names). The 0x40xxxx block is a ROM copy (RAM = ROM + 0x39a3e6). Left: 258 "
        "MISSING, 3 unverified names, the fuel metering PWM unit (bench).\n")
if "Round 39 (2026-11-22" not in open(f).read():
    open(f, "a").write(note)
print("round 39 closing applied")

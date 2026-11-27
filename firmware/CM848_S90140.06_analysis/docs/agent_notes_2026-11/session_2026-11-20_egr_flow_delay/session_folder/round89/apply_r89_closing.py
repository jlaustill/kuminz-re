"""Round 89 closing: task 046, PR body, session README, todo, the memory round log. Idempotent (an edit is skipped
when its new text is already there). usage: apply_r89_closing.py <repo> <pr_body.md> <count>"""
import os
import re
import sys

repo, pr, count = os.path.abspath(sys.argv[1]), sys.argv[2], sys.argv[3]


def path(rel):
    return rel if os.path.isabs(rel) else os.path.join(repo, rel)


def edit(rel, old, new):
    p = path(rel)
    t = open(p, newline="").read()
    if new in t:
        return
    assert t.count(old) == 1, (rel, old[:70], t.count(old))
    open(p, "w", newline="").write(t.replace(old, new))


T46 = """## Done, round 89 (2026-11-24, same PR): the filter callers; sensor_config_t / sensor_state_t; the Calterm names

Peer relays started and continued the round (12:19, 12:50). The scripts are in `session_folder/round89/`.
- **Stage A (7167490a):** round 88's generated comments lost their "(frozen J90350.00.ghidra.cpp:N)" citations and
  audit framing; three stale script comments; the dump provenance (kuminz-cli asks for 0x46000 / 0x6E3E bytes and each
  file is exactly 0x80 short) in firmware/CLAUDE.md, the CM550 README and memory_map.md.
- **Stage B (72416e1a), round 88's verified second audit (2 investigators, 2 skeptics), applied by address:** 9 twin
  pairs share one name (`calculateFilteredEngineAcceleration`, `initializeEngineAccelerationFilters`,
  `smoothPowerTakeOffReferenceEngineSpeed`, `initializePowerTakeOffGovernorFiltersAndGains`,
  `initializePowerTakeOffReferenceFilter`, `presetPowerTakeOffSmoothedReferenceEngineSpeed`,
  `initializeFaultDerateEngineSpeedLimit`, `initializePedalFaultModeEngineSpeedFilter`, `presetPedalFaultModeFuelDemand`);
  CM550's governors and their initializers (`cm550_runLowSpeedGovernor`, `cm550_runAllSpeedGovernor`,
  `cm550_runPowerTakeOffGovernor`, `cm550_calculateEngineSpeed` - was `cm550_fuel_limit_arbitrator` - ...), the A/D
  loop `mc68k_processAnalogSensorChannels` (was `validateServiceDataLength`) and `cm550_initializeAnalogSensorChannels`.
  0x1ae0c / 0x1ae06 are fall-through points inside `cm550_initializeElectronicSmartPower` (deleted_functions.csv).
  `sensor_config_t` (24 bytes, e2m block 1003) replaces the unused `sensor_fault_config_t`; `ad_sensor_config_t` goes;
  25 `<channel>_sensor_config` instances replace 373 rows.
  - **Proof:** CM550 verify DETERMINISTIC; 2 functions removed on purpose; 7 changed beyond labels (the A/D loops'
    config fields, five default-value readers); caller artifacts unchanged. CM848 label-only. Two local rows for the
    config pointers were tried and dropped (one never applied, the other split the pointer).
- **Stage C (5222d5a1), the runtime records:** `sensor_debounce_state_t` is `sensor_state_t` (`lookup_result` ->
  `unfiltered_value`: Calterm's ...UF "unfiltered and linearized"; `reserved_18` one dword) with 25
  `<channel>_sensor_state` instances (e2m block 1004) replacing the filter records and 74 e2m-named rows. Readers print
  `coolant_temperature_sensor_state.filtered_value` (31 renders; it was the untyped
  `_filtered_and_linearized_coolant_temperature_50_to_293`), and the start-up loops share one typed pointer (round 88's
  garbled `peVar3` stride is gone; their local rows split the pointers, so they were removed). The Calterm names come
  back from `e2m-analysis/originals/v64t6_s.e2m` (its block 1003 / 1004 layout agrees with 410 of the 447 old e2m
  rows): suffixes in the field comments, stems in the instance comments, every name in the new
  `CM550_J90350.00_analysis/docs/analog_sensor_channels.md`. `ApplyLocalVariables` builds `T[N]` array types itself
  (it found an array only when something else had created it, so `byte[4]` broke with `reserved_18`).
  - **Proof:** CM550 verify DETERMINISTIC; 0 removed / added; 39 changed (the A/D loops and 37 readers); caller
    artifacts unchanged; only the two walker rows render differently. CM848 byte-identical (the shared script).
    Script tests 109 / 109; headers 0 errors; _cal HARD 0.
- **Stage D (92f1ba9d):** CM550's README and npm scripts still ran the removed partial pipeline (`ghidra:full`, `init` ...
  `export`; 11 of 13 npm scripts failed); they now follow build / verify, with recounted state.
- **firmware/CLAUDE.md:** stage A added the dump request size to the RAM dump gap bullet (full lines in the commit).
- **Leads (round 90):**
  - CM550 `output/parameter_id_lookup_table.csv`: its `firmware_variable` column is stale (42 rows name an old global,
    99 empty rows now have one; nothing regenerates it).
  - CM550's 20 `unnamed_data_<address>` rows at 0x806e24 and up: the parameter ID table maps e2m blocks onto them
    (0x1011 -> 0x806F08 ...), so the e2m files can name them.
  - `validateSecurityKey`'s `bool` local rows: `ApplyLocalVariables` has no `bool` keyword (Unknown type), and the
    `copy_counter` row types a 0-4 loop counter `bool`.
  - The A/D array-end bound renders `((int)&operational_amplifier_and_comparator_supply_voltage_sensor_state.reserved_18 + 3)`
    in both loops; CM550's `analyze.sh` hwregs stage still prints "Run '$0 export'".
  - Carried: the misnamed PGN builders; `linearization_table_ch15_x_axis` is channel 0's table; 0x803f40 needs `_cal`;
    ESCMES / ENGRPM names; CM848's DM8 words; the DIAG enum members 0x42 / 0x52 / 0x54; the descriptor rows
    0x801ab6-0x801b0d; `cm550_peakTorqueFuelCorrection`; `cm550_j1939TorqueControlMode*` (services 4 / 5);
    `cm848_mathMultiplyDivide32`'s fall-through; 0x80ddd3.

## Leads (not in this PR)"""
edit("work/tasks/046-cm848-egr-flow-estimate.md", "## Leads (not in this PR)", T46)
edit(pr, "\n## Test plan\n",
     "\n**Round 89.**\n"
     "- **Stage A (7167490a):** round 88's generated comments cleaned; the dump provenance documented.\n"
     "- **Stage B (72416e1a):** round 88's second audit: 9 more twins (the filter records' users and initializers),\n"
     "  CM550's governors, its A/D channel loop (was `validateServiceDataLength`) and the 24-byte `sensor_config_t`\n"
     "  (e2m block 1003, 25 instances).\n"
     "- **Stage C (5222d5a1):** the A/D runtime records as `sensor_state_t` (e2m block 1004, 25 instances), so readers\n"
     "  print `coolant_temperature_sensor_state.filtered_value`; the Calterm names from the e2m files\n"
     "  (`docs/analog_sensor_channels.md`); `ApplyLocalVariables` builds array types.\n"
     "- **Stage D (92f1ba9d):** CM550's README and npm scripts follow the one deterministic build.\n"
     "\n## Test plan\n")
edit(pr, "- **Beyond CM848 (rounds 72-88):**", "- **Beyond CM848 (rounds 72-89):**")
edit(pr, "- [x] Round 88: B: ",
     "- [x] Round 89: D: docs only (no build input changed); package.json parses.\n"
     "- [x] Round 89: C: CM550 verify DETERMINISTIC (0 functions removed / added; 39 changed: the A/D loops and 37 readers; caller artifacts unchanged; only the two walker rows render differently); CM848 verify DETERMINISTIC and byte-identical (ApplyLocalVariables change); 109 JUnit tests pass; headers 0 g++ errors; _cal HARD 0.\n"
     "- [x] Round 89: B: CM550 verify DETERMINISTIC (2 fall-through rows deleted on purpose; 7 functions changed beyond labels; caller artifacts unchanged); CM848 label-only; headers 0 g++ errors; _cal HARD 0.\n"
     "- [x] Round 89: A: comments and docs only.\n"
     "- [x] Round 88: B: ")
README = "firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-20_egr_flow_delay/README.md"
t = open(path(README)).read()
NEW = ("\n## Round 89: the filter callers, sensor_config_t / sensor_state_t, the Calterm names (`session_folder/round89/`)\n\n"
       "- **Stage A:** `apply_r89a.py` (round 88's generated comments, three script comments, the dump provenance).\n"
       "- **Stage B:** `check_current.py` (the audit's current names against HEAD), `precheck_r89b.py`, `apply_r89b.py`,\n"
       "  `fix_extra_notes.py` (the audit's framing), `apply_r89b2.py` / `revert_r89b2.py` (the config-pointer rows that\n"
       "  failed).\n"
       "- **Stage C:** `calterm_stems_r89.py` (which e2m original carries J90350.00's block 1003 / 1004 layout, and each\n"
       "  channel's Calterm names), `precheck_r89c.py`, `apply_r89c.py` + `patch_apply_r89c.py` (second pass) +\n"
       "  `run_r89c.sh` (refresh with the Calterm-named old labels kept), `apply_r89c2.py` / `drop_bcf0_rows_r89.py`\n"
       "  (the walker rows), `apply_r89c3.py` (reserved_18 as a dword). The ApplyLocalVariables change is in the commit.\n"
       "- **Stage D:** `apply_r89d.py`.\n"
       "- **Round 90 leads:** `check_parameter_table_r89.py` / `parameter_table_r89.tsv` (the parameter ID table's stale\n"
       "  firmware_variable column).\n"
       "- **Closing:** `apply_r89_closing.py`, `update_large_tar_r89.sh`.\n")
if "## Round 89:" not in t:
    i = t.index("## Round 88:")
    j = t.find("\n## ", i + 5)
    t = t[:j] + "\n" + NEW.rstrip("\n") + t[j:] if j != -1 else t.rstrip("\n") + "\n" + NEW
    open(path(README), "w").write(t)
edit("work/todo.md", "round 88: the filter library, 6 more twins, ENGINE_STATE, the dump chunk-skip fix - open:",
     "round 88: the filter library, 6 more twins, ENGINE_STATE, the dump chunk-skip fix; round 89: 9 more twins, CM550's "
     "A/D channel records as sensor_config_t / sensor_state_t with their Calterm names, the CM550 README - open:")
M = "/home/linux/.claude/projects/-home-linux-code-kuminz-re/memory/"
for name, pat, rep in (("MEMORY.md", r"\(cm848/egr-flow-delay-model, \d+ commits\)", f"(cm848/egr-flow-delay-model, {count} commits)"),
                       ("pr53_egr_flow_delay_rounds.md", r"is still OPEN on 2026-11-24\n\(\d+ commits\)",
                        f"is still OPEN on 2026-11-24\n({count} commits)")):
    p = M + name
    s = open(p).read()
    s2 = re.sub(pat, rep, s)
    assert f"{count} commits" in s2, name
    open(p, "w").write(s2)
log = M + "pr53_egr_flow_delay_rounds.md"
s = open(log).read()
note = ("- Round 89 (round 88's second audit applied by address: 9 more twins + CM550's governors + the A/D loop was "
        "validateServiceDataLength; the A/D records typed: sensor_config_t (e2m 1003) and sensor_state_t (e2m 1004), "
        "Calterm names from v64t6_s.e2m in docs/analog_sensor_channels.md; refresh_references protects a \"were\" list "
        "only within 120 chars - write \"+N was X\"; committing a loop pointer splits it between loops; ApplyLocalVariables "
        "now builds T[N]; CM550 README fixed; round 90 leads in task 046)\n")
if "- Round 89 (" not in s:
    open(log, "w").write(s.rstrip("\n") + "\n" + note)
print("round 89 closing applied")

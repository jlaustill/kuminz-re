# EGR transport delay session (2026-11-20, todo 046)

The question was whether `cm848_throttleBasedFuelCalculation` (0x128a0) is named properly. It is not. It is the EGR
transport delay stage of the CHP charge flow model (e2m 177F, resolved by the ECU's parameter ID table; CHP is the e2m
prefix and is never spelled out), so it is now `cm848_calculateDelayedEgrFlowAndFraction`. The user then asked for the
rest of the family on the same PR (stages 3 / 4). The findings and the open leads are in
`work/tasks/046-cm848-egr-flow-estimate.md`. No subagents ran. The work was done by hand, with advisor reviews before
the edits of each round and before the end.

`session_folder/` has these files:
- **Stage 1 (label-only):**
  - `apply_stage1.py` makes the CSV edits: the three functions, the 12 struct fields with their comments, and the two
    globals. Before it runs, `rename_waves/rename_struct_types.py ... throttle_fuel_trim_t=egr_flow_estimate_terms_t@0x0040a3ea=egr_flow_estimate_terms`
    must rename the type and the instance.
  - `fix_bare_fields.py` fixes the bare old field names in five comments that `refresh_references.py` cannot reach.
    A bare `reserved_0c` also names fields of other structs, so the tool skips them.
  - The mappings:
    - `map_struct.csv` comes from `rename_struct_types.py`.
    - `map_stage1.csv` holds the fields, functions and globals.
    - `map_all_stage1.csv` joins the two and is the proof input.
    - `map_refresh_stage1.csv` holds the old -> new pairs for `refresh_references.py`, including the
      `instance.field` / `type.field` forms.
  - The proof result: `reverse_names.py` reported EQUIVALENT, and `squash_changed.py` found 0 functions that differ.
- **Stage 2 (shape):**
  - `apply_stage2.py`:
    - the `delay_line_t` template and its two instances;
    - the six e2m-signed 177F words as `short`;
    - removes the type-only byte row at 0x3fa5a0;
    - adds the two helper prototypes.
  - `fix_stage2_plates.py` makes the plate comments name the delay lines.
  - `apply_stage2b.py` retypes the two EGR flow limits as `i16` and names the five locals.
    - The `uVar5` row was renamed by hand afterwards to `volumetric_efficiency_speed_product`: committing a name on
      it splits the reused register, which is why that one rename was needed.
- **Review fixes:** `fix_review_comments.py`, from the advisor's final review. Above a fraction of 1.0 it is the scaled
  term that becomes 0xffff, not the delay. The first delay line's comment now names its boot call target.
- **Stage 3 (label-only, the rest of the family):**
  - `apply_stage3.py` makes the edits: 12 functions with their plate comments and 37 globals, one of them a new row at
    0x3fd8ea. It checks each old name and type, and that every new name is unused.
  - `fix_stage3_comments.py` fixes the struct field comment that `refresh_references.py` skips, and the 0x128a0
    plate's "charge properties" wording.
  - `map_stage3.csv` is the proof mapping, and `map_refresh_stage3.csv` holds the refresh pairs.
  - `users.py` lists the functions whose code (not comments) uses a symbol. It was used to bound the scope.
  - The proof result: EQUIVALENT, with 49 names, all rendered. One function differs, and only in its declaration order.
- **Stage 4 (shape):**
  - `apply_stage4.py`:
    - the three 2-D caches as `word[2]`;
    - `void` prototypes for 0x12ad4 / 0x12dc4 / 0x130dc;
    - `word` returns for the two source checks;
    - `i16` for the signed pumping torque words.
  - `predicted_stage4.txt` is the changed-function set, written before the build. The 10 core functions changed as
    predicted. The two `pumping_torque_adjustment` readers did not, because they never cast it. One more function only
    reorders its declarations.
- **Round 3, stages 5-8 (the user: "keep going, nothing is out of scope"):**
  - **Investigation helpers:**
    - `symbol_e2m_table.py` lists every global a function uses with the e2m record at its address (from an
      `e2m_name_audit.py` output).
    - `use_lines.py` prints a few code lines per symbol, and `fault_dtc.py` maps fault bit -> OBD DTC.
  - **Stage 5:**
    - `apply_stage5.py` does the TPE charge pressure estimate, the in range monitor, the exhaust pressure estimate and
      sensor, the EGR delta pressures, two source words and the monitor bit.
    - `fix_stage5_collision.py`: the first build's proof failed. The bit's first name equalled a new global's name, so
      the global reversal also rewrote `.field`. This script renames it `charge_pressure_estimate_enable` and fixes the
      name column of 0x13294's prototype rows.
    - The mappings are `map_stage5.csv` / `map_refresh_stage5.csv`.
  - **Stage 6:** `apply_stage6.py`, the `i16` words and 0x13294's `void` prototype.
  - **Stage 7:**
    - `apply_stage7.py` does the 819B engine speed block. Run `rename_struct_types.py ...
      engine_rpm_state_t=engine_speed_state_t@0x0040b7ac=engine_speed_state` first.
    - The mappings are `map_struct7.csv` / `map_stage7.csv` / `map_refresh_stage7*.csv`. `7b` maps the bare
      `current_rpm` in comments.
  - **Stage 8, the signedness sweep:**
    - `signed_candidates.py` counts the candidates.
    - `classify_signed_loads.py` writes `signed_loads.csv` with each candidate's loads (lha-only / has-lhz / no-load).
    - `apply_stage8.py` applies the sweep.
    - `revert_pointer_passed.py` restores `word` on the rows in `revert_ptr.txt` (passed to `word *` parameters) and
      `revert_ptr2.txt` (read through an `lhz` pointer).
    - `cast_normalized_diff.py` is the proof.
- `commit1.txt` .. `commit12.txt` are the commit messages, and `pr_body.md` is the pull request text.

`session_folder_large_files.tar.xz` holds the build logs:
- `build1.log`: stage 1;
- `build2.log`: stage 2;
- `build3.log`: stage 2b;
- `build4.log`: the final locals;
- `build5.log`: the review comment fix;
- `verify.log`: `./analyze.sh verify` after round 1, two byte-identical builds;
- `build6.log` / `build7.log`: stages 3 / 4;
- `verify2.log`: `./analyze.sh verify` after stage 4;
- `build8.log` / `build9.log`: stage 5, before / after the collision fix;
- `build10.log` / `build11.log`: stages 6 / 7;
- `build12.log` / `build13.log` / `build14.log`: the sweep, then its two reverts;
- `verify3.log`: `./analyze.sh verify` after stage 8.

It also holds `stage2.cpp`, the stage 2 output before the locals were named.
- The other snapshots are in git: the pre-session `.cpp` is 9ba021f's and stage 1's is a513107's.
- The proof's canonical / reversed copies can be regenerated with the commands in
  `firmware/scripts/rename_waves/README.md`.

What the build logs show:
- **Stage 2 thunks:** the stage 2 logs read "made 19, call overrides 13". Stage 1 read 21 / 11. The two boot-ROM call
  targets inside the delay lines are now call overrides:
  - 0x3fa2f0, `cm848_runFlashProgramStateMachine`, under `egr_oxygen_fraction_delay_line`;
  - 0x3fa5a0, `mpc555_cmfEraseBlocks`, under `egr_mass_flow_delay_line`.
- **Warnings:** the warning and error lines are the same in every build up to stage 3. Stage 4 removes two of them,
  the stale-prototype warnings ("defines 2 param row(s) but Ghidra recovered 0") for 0x12ad4 and 0x130dc.

## Round 4: rename wave 15 (`session_folder/wave15/`)

The user gave the go-ahead for an agent wave over the e2m audit's low-overlap rows.
- **The pool (`funnel_W15.py`, `overlap_pool_W15.py`, `build_context_W15.py`):** named scalar / array / enum rows,
  used in the code, dump in range, never reviewed (no `| e2m:` note, the comment does not cite the record), whose
  name shares at most 20 % of the words of the e2m record the ECU's table resolves to the address. An address whose
  name fits another record there better is out. `earlier_verdicts_W15.py` attached waves 12-14's notes and dropped
  wave 13's 15 drift rows: 378 rows in 6 bins.
- **The agents:** `brief_W15.md` (every rename needs a quoted `.cpp` line), six Sonnet agents, ~3.3M tokens. Their
  results are in `results/`, their scripts in `agent_scratch/`, and their prompts and reports in
  `agent_prompts_and_reports_W15.md` (extracted with `extract_reports_W15.py`).
- **The apply (`apply_W15.py`):** bin coverage, old = current, name free (global / function / struct field /
  parameter / local / any `.cpp` identifier), `_cal` = EEPROM mirror, banned abbreviations, CM550 sharing, the
  quoted line, and the repo gate. `patch_apply_hand.py` adds the main session's decisions (`RENAMED_BY_HAND`,
  `NOT_TWINS`, the PGN 56320 comment fix, drift markers). `apply_stage10_extras.py` adds the 1170 family.
- **The hand follow-ups:** `apply_hand_worklist.py` applies a worklist (`worklist_10b_*.py`) through the same checks.
  `evidence_W15.py` prints each row's e2m record and code lines for the review. `finish_10b5.py` finished one run
  that the repo gate stopped at the function step. `add_e2m_prefix_W15.py` repaired the 90 comments that a
  relative-path bug left without their e2m record.
- **The types:** `apply_stage10c_types.py`.
- **Checks:**
  - `check_quoted_dump_values_W15.py` and `dump_mismatch_context_W15.py` (the 17 flags were regex hits on scaled
    values);
  - `stale_refs_W15.py`;
  - the comment-name sweeps `sweep10*.txt`;
  - the width checks `map10*_width.csv`.
- **Maps:** `map_stage10.csv` (the wave and the 1170 extras), `map_stage10b.csv` / `map_stage10c.csv` (the
  follow-ups), `map_stage10d.csv` (the 10c labels). Commit messages: `commit15-18.txt`.
- **Regenerating `all.dis`** (6.7 MB, not archived): `powerpc-linux-gnu-objdump -D -b binary -m powerpc -EB
  --adjust-vma=0x0 --start-address=0x0 --stop-address=0x70000 originals/cm848_rom.bin` followed by the same for
  `originals/cm848_flash2_live.bin` with `--adjust-vma=0x500000 --start-address=0x500000 --stop-address=0x53e000`.

## Round 5: hand fixes on the wave 15 leads (`session_folder/round5/`)

The user's second "keep going". No agents.
- **`j1939_header_pgns.py`:** every J1939 header builder with the PGN its constant encodes. PDU1 PS bytes are
  destinations, not part of the PGN.
- **`writes_of.py`:** a function's profile (the globals it writes, the functions it calls, the fueling states it
  names), used to name long functions.
- **Worklists `worklist_r5_j1939.py`, `worklist_r5b_functions.py`, `worklist_r5d.py`, `worklist_r5e.py`, `worklist_r5f.py`
  and `worklist_r5g.py`:** applied with `wave15/apply_hand_worklist.py`. The maps are `map_r5a.csv`-`map_r5g.csv`
  (`map_r5a_cm550.csv` for the shared EC1 rename) and `map_r5_all.csv`.
- **Type stages:**
  - `apply_r5b_asg_gain_set.py` (`all_speed_governor_gain_set_t`; `removed_r5b.csv` lists the member rows that went,
    and `replace_member_refs.py` replaced them in comments);
  - `apply_r5c_vehicle_speed_sensor_type.py` (`VEHICLE_SPEED_SENSOR_TYPE`);
  - the `INTAKE_AIR_HEATER_PHASE` enum.
- **Checks:**
  - `wave15/changed_functions_W15.py`, which compares function bodies with comments stripped on both sides. Pass it a
    `--write-reversed` file written without `--canonical-code-labels`, or every `LAB_` differs.
  - The piece census, `grep_old_names.py` over `map_r5_all.csv`, and `append_resolved_r5.py` for the task files.
- **Commit messages:** `commit_r5*.txt`.
- **Logs:** the round 5 build logs (`build_r5*.log`, with the CM550 build `build_r5a_cm550.log`) and `verify_round5.log` are in `session_folder_large_files.tar.xz` (added by `round5/update_large_tar_r5.sh`).

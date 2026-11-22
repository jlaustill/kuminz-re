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

## Round 6: the TSC1 / ETC1 / Jcomm vocabulary (`session_folder/round6/`)

The round 5 lead, as hand work.
- **Stage 0:** the two orphan struct definitions were deleted, proved with `diff_underscore_fix.py`.
- **Stage A, label-only on both firmwares:** `worklist_r6a.py` for the globals and functions,
  `gate_r6a_shared_cm848.jsonl` / `gate_r6a_shared_cm550.jsonl` for the shared handler (`apply_renames.py` directly:
  the worklist gate wants a prefix, and CM550 has no arrays.csv), then `apply_r6a_structs.py` for the types, fields,
  label and comment refresh. `rename_alias_rows_r6a.py` and `fix_headers_r6a.py` cover the dotted per-field alias
  rows and the `#` headers. The maps are `map_r6a.csv`, `map_r6a_cm550.csv` and `map_r6a_proof.csv`, which adds the
  auto-named local `ptVar1` and shows 0 changed functions.
- **Stage B1, label-only:** `worklist_r6b1.py` plus `apply_r6b1_fields.py`, from e2m blocks 10E8 / 10E6.
- **Stage B2, the types:** `apply_r6b2_types.py`, with every fact quoted in its docstring, then `apply_r6b2_fixes.py`
  after the first build: the bitfield revert, the lookup's local and the monitor copies. Each changed function was
  read with `fn_code_diff.py`.
- **Closing:** `fix_comments_r6c.py`, `append_resolved_r6.py` and `memory_edits_r6.py`, which updates the private
  memory notes.
- **Commit messages:** `commit_r6*.txt`. The logs go into the large-files tarball.

## Round 7: the J1939 monitor, the retarder TSC1 words, the drivetrain ratio module (`session_folder/round7/`)

Hand work on the round 6 leads.
- **Stage A, label-only:** `worklist_r7a.py` plus `apply_r7a_fields.py`, covering two retarder fields and the session
  functions' `int32_t` parameter. The first build rendered `int` as `dword`, which is how the importer maps `int`.
- **Stage C, label-only:** `worklist_r7c.py`, the drivetrain ratio module.
- **Stage B, the types:**
  - `apply_r7b_session_struct.py`: `j1939_control_session_t` and its instances, the length words, the four member rows
    (`removed_r7b.csv`) and the array note.
  - `apply_r7b_drivetrain.py`: the e2m 106D cals, `gear_down_gear_ratio_cal` and `DRIVETRAIN_GEAR_RANGE`.
  - The history store's local rows took three builds. A `word *` local and then a `byte *` local both rendered the
    copy start longer than the struct pointer did.
- **Closing:** `docs_r7.py`, `fix_leads_r7.py`, `append_resolved_r7.py` and `memory_round7.py`. The commit messages are
  `commit_r7*.txt`.

## Round 8: the 48RE transmission controller (`session_folder/round8/`)

Hand work on the round 7 lead.
- **Finding the vocabulary:**
  - `e2m_of_names.py` looks up the e2m record of each named row by address.
  - `align_block.py` prints an e2m block against the CSV rows at an assumed base, with each row's RAM value and users.
    It is the tool that proved the 8C17 and 8BBC bases.
- **Stage A, label-only:** `worklist_r8a.py` and `apply_r8a_struct.py` (`transmission_pressure_state_t`).
- **Stage B, label-only:** `worklist_r8b.py` and `apply_r8b_struct.py` (`transmission_lockup_timers_t`; generated by
  `make_r8b_struct.py`).
- **Stage C, the types:** `worklist_r8c.py` and `apply_r8c_types.py`.
- **Stage E, label-only:** `worklist_r8e.py` and `apply_r8e_comment.py` (the converter clutch transition state comment); `worktree_refresh_audit.py` is `refresh_audit.py` for an uncommitted tree.
- **Stage F, label-only:** `worklist_r8f.py` and `apply_r8f_fix.py`: the stage E rows' notes, the two-method plate, the new 0x408370 row, three unquoted comments. Also `width_check_r8.py` (e2m size against the declared width, block by block), `keyed_refresh_audit.py` (the comment-refresh audit keyed by address) and `quote_counts.py` (quoted CSV lines on two revisions).
- **Stage G, label-only:** `worklist_r8g.py` and `apply_r8g_fix.py` (the exhaust brake inhibit word order, the 0x408388 polarity comment). `csv_tail_check.py` / `csv_tail_check2.py` look for the silent forms of the csv-module bug (left-over comment tails) between two revisions.
- **References:** `refresh_struct_comments.py` refreshes the comment columns of `structure_definitions.csv` /
  `enums.csv`, which `refresh_references.py` skips.
- **Commit messages:** `commit_r8*.txt`.
- **Closing:** `old_names_r8.py` writes the old names for `grep_old_names.py` (results `grep_old_r8.txt` / `grep_old_r8_after.txt`); `close_r8.py` marks the round 7 lead resolved and writes `append_resolved_r8.py` (tasks 025 / 027); `refresh_audit.py` lists every comment-only change a commit made to a CSV, to catch a reference refresh that rewrote a history mention (it caught one in firmware/CLAUDE.md); `memory_round8.py` and `update_large_tar_r8.sh` (the round 8 build / verify logs).

## Round 9: the 48RE tables in memory order (`session_folder/round9/`)

- **The table walk:** `walk_tables.py` walks e2m table blocks in column-5 order from a start address, sizing each from
  the dump. `walk_*.csv` are the walks from 0B43, 0B9E and 0BB5.
- **Stage A:** `worklist_r9a.py` and `apply_r9a_new.py`. The second adds label-only rows (empty type) for unnamed
  words.
- **Stage B:** `worklist_r9b.py` and `apply_r9b_fix.py`.
- **Stage C:** `apply_r9c_enum.py` and `apply_r9c_types.py`.
- **Stage D:** `apply_r9d_structs.py` (two structs, the field split), `worklist_r9d.py` and
  `refresh_qualified_r9d.py` (it refreshes `instance.field` mentions, which the generic refresh cannot do safely).
- **Stage F (the review fixes):** `worklist_r9f.py` and `apply_r9f_fix.py` (the 8BB6 records, the proportional term row, the bare old field names in 48RE comments and plates). `csv_tail_check*.py` audits the CSVs for the csv-module bug; `close_r9.py` writes the resolved notes.
- **Commit messages:** `commit_r9*.txt`.

## Round 10: types, the 48RE monitors, the transmission relay, the SCI actuator tests (`session_folder/round10/`)

- **Stage A (the RE lookup caches):** `list_caches.py` lists the cache words with old names, `gen_r10a.py` writes
  `worklist_r10a.py` and `new_r10a.json`, and `apply_r10a_new.py` inserts label-only rows.
- **Stage B (types):** `re_audit.py` builds the audit CSV for the aligned RE blocks, `classify_signed_loads.py` (one
  level up) gives `re_signed_loads.csv`, and `apply_r10b_types.py` writes the i16s, the label-only types and the
  1-2 shift lag table.
- **Stage C:**
  - `apply_r10c_suffix.py`: the `_cached_axis_offset` suffix;
  - `worklist_r10c.py`;
  - `apply_r10c_extra.py`: the `_`-prefixed row and the output 16 field.
- **Stage E:** `worklist_r10e.py`, `new_r10e.json` and `apply_r10e_plates.py`. `sci_test_codes.py` lists the SCI
  0x13 test codes with their outputs.
- **Stage D:** `gen_r10d.py` writes `worklist_r10d.py`, and `apply_r10d_types.py` adds the enum and the limp-home
  comments.
- **Stage F:** `apply_r10f_types.py` (the widths and `sci_output_test_timers_t`) and `apply_r10f_prototypes.py` (the
  three helpers' `word *timer` prototypes; the first build, without them, printed the field addresses as raw
  constants). `relabel_struct.py` maps `instance.field` back to the old labels for the proof.
- **Helpers:**
  - `cache_tables.py`: the tables each cache serves;
  - `final_names.py`: old to final name through the round's maps;
  - `resolved_r10.py`: the task file sections.
- **The closing checks (after the advisor review):**
  - `output_requesters.py`: the firmware requesters of each tested output;
  - `docs_requesters_r10.py`: adds them to the firmware/CLAUDE.md table;
  - `stem_check.py` / `stem_check_r10.py`: each cache's stem against its lookup's table.
- **Logs:** the round 10 build logs (`build_r10*.log`, with 10F's first attempt `build_r10f_attempt1.log`) and
  `verify_round10.log` are in `session_folder_large_files.tar.xz` (`round10/update_large_tar_r10.sh`).
- **Commit messages:** `commit_r10*.txt`.

## Round 11: the e2m output and switch maps (`session_folder/round11/`)

- **Stage A:** `worklist_r11a.py`, `new_r11a.json` (rows through `../round10/apply_r10a_new.py`) and
  `apply_r11a_extra.py` (the `FUN_0051dfdc` function row and the arrays.csv switch map).
- **Stage B:** `apply_r11b_types.py` (the six request-byte bitfield structs from e2m 1577), `apply_r11b_lift_pump.py`
  (types, `LIFT_PUMP_RUN_REASON`) and `apply_r11b_docs.py` (the byte 0 map, the 16-23 record names).
  `bitfield_normalize.py` is the proof helper. `output_bit_reads.py` lists the tested bits with their records.
- **Stage C:**
  - `apply_r11c_switch_struct.py` is the all-bitfield pilot; its numbers are in `pilot_r11c_numbers.txt`.
  - `apply_r11c_switch_narrow.py` is the committed shape.
  - `switch_bit_reads.py` lists the tested switches and their setters; `switch_normalize.py` / `switch_normalize2.py`
    are the proof helpers.
- **Stages D / E:** `apply_r11d_field.py` and `apply_r11e_field.py` (output 54; stage E after the review).
- **Logs:** the round 11 build logs (with the pilot's `build_r11c_attempt1.log`) are in the large-files tarball.
- **Commit messages:** `commit_r11*.txt`.

## Round 12: arrays and the CP3 fuel metering vocabulary (`session_folder/round12/`)

- **Stage A:**
  - `array_candidates.py` checks each candidate's range for other rows and for the `DAT_` words inside it.
  - `apply_r12a_arrays.py` and `apply_r12a_fix.py` (the eight setpoint caches) write the types.
  - `array_normalize.py` is the proof helper (it maps each array back to its old labels).
- **Stage B:** `worklist_r12b.py`, the 43 `HPCR_*` names. `apply_r12_plate.py` updates the function's plate in the
  closing.
- **Stage C:** `apply_r12c.py` (the remaining names, the plate, the stale text).
- **Logs:** the round 12 build logs (with 12A's first attempt) are in the large-files tarball.
- **Commit messages:** `commit_r12*.txt`.

## Round 13: the end-of-line tests and the SCI command 0x25 service tests (`session_folder/round13/`)

- **Stage A:** `worklist_r13a.py` (35 renames, 13 functions), `new_r13a.json` (10 new rows) and `apply_r13a_plates.py`.
- **Stage B:** `apply_r13b_enums.py`. The proof is `check_enum_proof3.py`, a copy of the fueling state session's
  `check_enum_proof2.py` that normalizes byte-sized enum types to `byte`.
- **Stage C:** `worklist_r13c.py`, `apply_r13c_comments.py` (the bit maps, the cutout correction) and
  `apply_r13c_docs.py`.
- **Stage D:** `apply_r13d_cutout.py` (tests 5-10 cut out firing-order slots; three task 046 leads).
- **Audits:** `refresh_diff_offline.py` checks a committed stage's reference refresh between two commits.
  `keyed_refresh_audit_refs.py` is the same audit pinned to two commits.
- **Logs:** the round 13 build logs and the final verify log are in the large-files tarball.
- **Commit messages:** `commit_r13*.txt`.

## Round 14: the low speed governor reference speed chain (`session_folder/round14/`)

- **Stage A:** `worklist_r14a.py` (68 globals, 7 functions), `apply_r14a_struct.py` (the struct at 0x40aec2) and
  `new_r14a.json` (the 14EF gain and clamps).
- **Stage B:** `apply_r14b_enum.py`, proved with round 13's `check_enum_proof3.py`.
- **Stage C:** `apply_r14c_split.py`; its proof map sends the two words back to the old `._0_2_` / `._2_2_` pieces.
- **Closing:** `apply_r14_closing.py`.
- **Logs and commit messages:** the round 14 build logs are in the large-files tarball; the messages are
  `commit_r14*.txt`.

## Round 15: the e2m pool above 0.2 overlap, part 1 (`session_folder/round15/`)

- **The pool:** `pool_r15.py` (wave 15's filter, by overlap band) and `evidence_r15.py` (code lines per candidate).
- **Stage A:**
  - `channel_calls_r15.py` proves each channel at its calls.
  - `gen_channels_r15.py` and `make_worklist_r15a.py` build `worklist_r15a.py` (named rows) and `fill_r15a.json`
    (type-only rows, via `apply_r15a_fill.py`).
- **Stage B:** `worklist_r15b.py`. `width_check_r15.py` compares each row's width with its e2m size.
- **Closing:** `apply_r15_closing.py`.

## Round 16: the cruise control / road speed governor (`session_folder/round16/`)

- **The records:** `blocks.txt` / `blocks2.txt` (e2m_block_addresses.py on 117D-1192), `check*_out.txt` (code lines
  per candidate), `width_r16a.txt` (the width check).
- **Stage A:** `worklist_r16a.py` (through apply_hand_worklist.py), `fill_r16a.json` (type-only rows, via
  round15/apply_r15a_fill.py) and `apply_r16a_enums.py`; `refresh_enums_structs.py` refreshes the two CSVs that
  refresh_references.py skips.
- **Stage B:** `apply_r16b.py`. **Stage C:** `apply_r16c_switch_bits.py` and the proof helper
  `switch_normalize_r16c.py`. **Closing:** `apply_r16_closing.py`; after the review, `retired_prose.py` (the old
  vocabulary in current comment text) and `fix_retired_prose.py`.

## Round 17: the engine retarder request chain (`session_folder/round17/`)

- **The records:** `blocks.txt` (e2m_block_addresses.py on 1070 / 1071 / 1192), `check*_out.txt`, `width_r17a.txt`.
- **Stage A:** `worklist_r17a.py` (through apply_hand_worklist.py), `apply_r17a_plates.py` (the chain's plates),
  `retired_prose_r17.py` / `fix_retired_prose_r17.py` (the old words in current comments).
- **Stage B:** `apply_r17b_enums.py`. **Stage C:** `apply_r17c.py` and the proof helper `normalize_r17c.py`.
  **Closing:** `apply_r17_closing.py`.

## Round 18: types and the main injection timing selection (`session_folder/round18/`)

- **Stage A:** `apply_r18a.py` (after the q16 pilot build). **Stage B:** `worklist_r18b.py` / `worklist_r18b2.py`
  (through apply_hand_worklist.py) and `apply_r18b_enums.py`. **Stage C:** `apply_r18c.py`. **Closing:**
  `fix_retired_prose_r18.py`, `apply_r18_closing.py`.

## Round 19: tables, sources and the ANC pass-through (`session_folder/round19/`)

- **Stage A:** `worklist_r19a.py`. **Stage B:** `apply_r19b.py`, with `source_values.py` (the values each source word
  stores and compares). **Stage C:** `worklist_r19c.py`. **Closing:** `apply_r19_closing.py`.

## Round 20: the algorithm enable flags block (`session_folder/round20/`)

- **Stage A:** `worklist_r20a.py`, `make_worklist_r20a2.py` (generates `worklist_r20a2.py`). **Stage B:** `apply_r20b.py`
  + `normalize_r20b.py`. **Stage C:** `worklist_r20c.py`, `apply_r20c2.py` (its structs-only rerun
  `apply_r20c2_structs.py`), `apply_r20c3.py`. **Stage D:** `apply_r20d.py` (the naming table and its checks) +
  `normalize_r20d.py`. **Stage E:** `worklist_r20e.py`. **Stage F (after the advisor's review):** `apply_r20f.py`, `patch_r20d_for_f.py` (adds the generator's `--only` / `SAME_ENABLE`), then `apply_r20d.py --only 11`. **Closing:** `apply_r20_closing.py`, `apply_r20f_closing.py`, `fix_r20_task046_order.py`.
- **Evidence:** `flag_word_uses.py` / `bit_readers.txt` (the readers of each bit), `flag_records.txt` /
  `flag_records_typed.txt` (the e2m records with their descriptions), `bit_context.py` (the code around a bit's
  tests).

## Round 21: the engine protection module (`session_folder/round21/`)

- **Stage A:** `apply_r21a.py` (the three structs and the helper prototypes; `--only state` was the packing pilot),
  `refresh_r21a_plates.py`, the gate `prove_r21a.py`. **Stage B:** `apply_r21b.py` + `prove_r21b.py`, and
  `struct_type_fallbacks.py` (the field types the importer does not know). **Stage C:** `worklist_r21c.py`,
  `apply_r21c2.py`. **Stage D:** `patch_apply_structures.py` (mind the file's CRLF line endings); its positive control's log is
  `build_r21_control.log` in the large-files tarball. **Stage E:** `apply_r21e.py` + `prove_r21e.py`. **Closing:**
  `apply_r21_closing.py`, `apply_r21_closing2.py`.
- **Evidence:** `blocks.txt` (e2m 112E / 1152 / 1143), the per-function bodies `body_*.txt`.

## Round 22: the engine protection leftovers (`session_folder/round22/`)

- **Stage A:** `worklist_r22a.py`, `apply_r22a2.py` (the two new rows and the configuration flags comment).
  **Stage B:** `worklist_r22b.py`, `apply_r22b2.py` (the two comments). **Closing:** `apply_r22_closing.py`,
  `apply_r22_closing2.py`. `raw_addr_scan.py` is the fixed scanner: the nearest `lis` decides, and `--permissive`
  keeps the old rule for "no access" claims.

## Round 23: the ambient module and the source enum (`session_folder/round23/`)

- **Stage A:** `worklist_r23a.py`, `apply_r23a2.py` (the unnamed and new rows). **Stage B:** `source_scan.py` (each
  `*_source` word's e2m value list against the code's literals; rerun it as `source_scan.py <firmware> <round19/source_values.py>`), `apply_r23b.py`. **Stage C:** `apply_r23c.py`, `stale_ghidra_labels.py` (dry run only), `source_scan_after.txt`. **Closing:** `apply_r23_closing.py`, `apply_r23_closing2.py`.

## Round 24: the Ghidra-label struct instances (`session_folder/round24/`)

- **Stage A:** `classify_labels.py`, `apply_r24a.py`, `prove_r24a.py`. The proof is comments-only: the code without comments is identical, and the CSV changes are in comment columns only.
- **Stages B-D:**
  - `worklist_r24b.py` / `_c` / `_d`, run through `apply_hand_worklist.py` (the snapshot here has the `NOT_CAL` exemption);
  - `spec_r24b.py` / `_c` / `_d`, run through `apply_struct_renames.py` (struct types, fields, dotted alias rows, qualified references);
  - `apply_r24b2.py` (new rows) and `apply_r24b_docs.py`;
  - the checks: `instance_users.py`, `fault_bit_names.py` (the e2m 1036 fault bit names), `definition_flag_2000.py`, `byte_enum_renders.py`.
- **Stage E:** `fault_bit_names.py` (the e2m 1036 bit table), `apply_r24e.py`, `refresh_r24e.py`, `prove_r24e.py`
  (each fault word reference mapped to an address token). **Stage F:** `apply_r24f.py`, `refresh_r24f.py`,
  `prove_tokens.py` (a general token-normalized gate for type changes).
- **Closing:** `apply_r24_interim.py` (interim, after stage D) and `apply_r24_closing.py`.

## Round 25: an enum and three shapes (`session_folder/round25/`)

- **Stage A:** `apply_r25a.py`, which is checked by `check_enum_proof3.py` from round 13.
- **Stage B:** `apply_r25b.py`. `raw_addr_scan_any.py` is round 22's scanner with the `lis` base taken from
  the range; round 22's version only tried 0x40 / 0x41.
- **Stage C:** `apply_r25c.py`. **Stage D:** `apply_r25d.py`.
- **The proofs:** `tokens_r25*.json`, checked by round 24's `prove_tokens.py`.
- **Closing:** `apply_r25_closing.py`.

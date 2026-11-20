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
- `commit1.txt` .. `commit6.txt` are the commit messages, and `pr_body.md` is the pull request text.

`session_folder_large_files.tar.xz` holds the build logs:
- `build1.log`: stage 1;
- `build2.log`: stage 2;
- `build3.log`: stage 2b;
- `build4.log`: the final locals;
- `build5.log`: the review comment fix;
- `verify.log`: `./analyze.sh verify` after round 1, two byte-identical builds;
- `build6.log` / `build7.log`: stages 3 / 4;
- `verify2.log`: `./analyze.sh verify` after stage 4.

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

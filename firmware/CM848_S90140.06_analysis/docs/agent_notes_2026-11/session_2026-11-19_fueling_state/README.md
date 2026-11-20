# Fueling state session (2026-11-19, todo 045)

The question was whether `governor_fuel_demand_mode` (0x40a154) is an enum. It is the Cummins FSGVFLST governed
fueling state, so `ENGINE_OPERATING_MODE` became the shared `FUELING_STATE` enum. The findings and follow-ups are in
`work/tasks/045-cm848-fueling-state-enum.md`. This folder keeps the session's scratch work. Seventeen read-only
subagents ran: two in stage 4, one in stage 5, two in stage 6, six in stage 7 and six in stage 8.

`session_folder/` has these files:
- `apply_fueling_state.py`: the CSV edit. It checks each old row before it replaces it.
- `check_enum_proof.py`: the stricter proof. It runs after `rename_waves/reverse_names.py` and normalizes member names
  and numbers to values, the enum type to `word`, auto-named locals to placeholders and the split dword's pieces. It
  then lists every function that still differs. One did: the split local in `cm848_processProtectionRampControl`.
- `map_all.csv`: the reverse mapping (two globals, the enum type and the eight renamed members).
- `follow.sh`: prints the first users of the register after each load of the target. Every load fed a `cmpwi` or a
  copy.
- `archive_fueling_state_session.py`: writes this folder, and writes the private transcript archive outside the repo.
  Since stage 5 that archive also holds the agents' own transcripts.
  `check_archive_restore.py` checks that the tar.xz restores byte-identically.
- **Stage 2** (the derate, combustion and final stages):
  - `apply_fueling_state_stage2.py`: 17 members, ten carriers typed and renamed.
  - `apply_fueling_state_stage2b.py`: the 16 `FUELING_STATE_UNIDENTIFIED_<n>` members. Ghidra printed 15 / 27 / 59 as
    ORs of members until they had members of their own.
  - `map_stage2*.csv`: the reverse mappings.
- **Stage 3:**
  - `apply_fueling_state_stage3.py`: 16 functions and 10 words of the arbitration. It also writes `map_stage3.csv`.
  - `refresh_other_csvs.py`: refreshes the comments in `enums.csv` / `structure_definitions.csv`, which
    `refresh_references.py` does not cover.
- **Investigation helpers:**
  - `fnbody.py`: prints function bodies.
  - `writers.py`: lists every assignment of a global.
  - `carrier_census.py`: lists the constants compared or assigned per carrier, and any ordering compare.
  - `width_census.py`: displacement-form access widths from `all.dis`.
- **Stage 4** (the e2m value labels, the engine state, the power take-off governor, the limiters):
  - `apply_fueling_state_stage4.py`: the main edit.
  - `stage4_power_take_off.py`: the power take-off part, merged into it.
  - `check_enum_proof2.py`: the strict check for several enums at once.
  - `map_stage4*.csv`: the reverse mappings.
- **Stage 5** (the power take-off words, the crank routine, the two backwards flags, code 32):
  - `apply_fueling_state_stage5.py`: the main edit (the power take-off words and code 32).
  - `stage5_crank_routine.py`: the crank routine part, merged into it.
  - `finish_stage5.py`: completes the edit after its text step stopped (the stale `CSP_*` sentence occurs twice). It
    replaces the old `CSP_*` names token by token and writes `map_stage5.csv`.
  - `compare_warnings.py`: checks that each warning of a verify log (two builds) occurs exactly twice as often as in the
    baseline build log.
  - `stage5.diff`: the uncommitted stage-5 diff that the privacy scan read.
  - `update_pr_body_stage5.py`: the stage-5 edit of `pr_body.md`.
- **Stage 5b** (the fix forward after a review of stage 5):
  - `apply_stage5b_aecd.py`: the AECD words, four new calibration rows, the three update functions and three plate
    shorthand tokens. It writes `map_stage5b.csv`.
  - `apply_stage5b_prose.py`: `condensation_count_enable_flag`, the "cold start phase 3" plates, and the
    `combustion_status_flags` bits.
  - `apply_stage5b_state_prose.py`: ten comments that still described `engine_state` with the old state words.
  - `stage5b.diff` / `update_pr_body_stage5b.py`: the diff the privacy scan read, and the PR body edit.
- **Stage 6a** (the signed filter records typed as `ema_filter_state_t`):
  - `filter_call_census.py`: every call of a function, with calls split over several lines joined (a one-line grep
    had found 15 of the 39).
  - `filter_records.py` / `filter_record_rows.py` / `filter_coefficients.py`: the rows, uses and dump values of each
    record and coefficient.
  - `apply_stage6a_filter_records.py`, then `fix_stage6a_comments.py`: the edit and its comment fixes.
  - `check_stage6a.py`: maps each field access back to the flat form it replaced and lists what still differs.
- **Stage 6b** (the parameter ID table, the emission manager, the power take-off helpers):
  - `parameter_id_table.py`: the first, independent parse of the ECU's table. It became
    `firmware/scripts/e2m_block_addresses.py`.
  - `apply_stage6b.py`: the edit from both agents' reports.
  - `refresh_default_labels.py`: replaces `DAT_` / `WORD_ARRAY_` labels that now have names, which
    `refresh_references.py` leaves alone.
  - `extract_handback_reports.py` / `append_stage6_agent_notes.py`: the stage-6 agents' reports, taken from their own
    transcripts.
  - `agent_scratch_stage6_emission_manager/` and `agent_scratch_stage6_power_take_off/`: the two agents' own scratch
    scripts. Their large `.cpp` snapshots are in the tar.xz.
  - `update_pr_body_stage6.py`, `stage6a.diff` / `stage6b.diff`.
- **Stage 7** (the e2m audit, rename wave 12, the fueling chain), in `stage7/`:
  - `audit.csv`: the output of `firmware/scripts/e2m_name_audit.py`, one line per resolved record.
  - `build_context.py`, then `bins/`: the six agents' inputs.
  - `brief_W12.md`: the shared brief.
  - `result_W12_bin*.jsonl` / `aligned_W12_*` / `gated_W12.jsonl`: the agents' results, then the gate's output.
  - `gate_W12.py` / `apply_W12.py`: the gate and the apply.
  - `apply_stage7_fueling_chain.py`: the hand renames of blocks 1045 / 1051.
  - `map_stage7.csv`, `classify7.txt`: the proof map and the classified differences.
  - `reports/`: the six handback reports. `agent_scratch/`: the agents' own scratch scripts.
  - `update_pr_body_stage7.py`, `append_W12_agent_notes.py`, `commit_message_stage7.txt`, `stage7.diff`.
- **Stage 8** (rename wave 13, the misname review), in `stage8/`:
  - `build_context_W13.py`, then `bins/`: the six agents' inputs. A row is in a bin when its name shares no word with
    its table-resolved e2m record.
  - `brief_W13.md`: the shared brief.
  - `result_W13_bin*.jsonl`: the agents' verdicts (rename / keep / drift / uncertain).
  - `apply_W13.py`: the hold list, the cross-firmware check, the repo gate (`gate_input_W13.jsonl`), the apply and
    `map_stage8.csv`.
  - `fix_stage8_comments.py`, `fix_stage8_note_order.py`, `apply_stage8_injector_family.py`: the fixes after the
    apply. They restore one old comment's proved facts and fix stale tokens. They move the rename note to the repo
    order, and give the 80B9 debounce rows their bits bytes' meanings.
  - `reports/`: the six handback reports. `agent_scratch/`: the scratch scripts of bins 4-6 (bins 1-3 wrote none).
  - `append_W13_agent_notes.py`, `sweep8.txt` (the comment sweep), `commit_message_stage8.txt`, `stage8.diff`.
- **The agents** (two in stage 4, one in stage 5, two in stage 6, six in stage 7, six in stage 8):
  - `agent_prompts.jsonl`: their exact prompts.
  - `agent_prompts_and_reports.md`: the stage-4 prompts and reports in short, stage 5's in full, and what was checked
    before applying.
  - `crank_agent_report.md`: the stage-5 agent's exact report.
  - `extract_agent_prompts.py`: pulls the prompts out of the transcript.
  - `extract_agent_report.py` / `find_agent_notification.py`: two attempts to find a background agent's report in the
    main transcript. Neither works. The tool result only says that the agent started, and the second script matched the
    compaction summary. The report is the handback message in the agent's own transcript (`subagents/agent-*.jsonl`).
  - `append_stage5_agent_notes.py`: writes the stage-5 section of `agent_prompts_and_reports.md`.
- `scan_private.py`: the privacy scan used before archiving. It reads the owner's address from the local git config,
  so the file itself carries none.
- `commit_message*.txt` / `pr_body.md`: the commit messages and the PR #52 body.

`session_folder_large_files.tar.xz` holds the files listed in `session_folder_large_files.txt`:
- `all.dis`: the full disassembly of both banks that the access census scanned.
- `pre.cpp` / `pre_canon.cpp` / `reversed.cpp`: the baseline build and the two proof inputs. `pre2`-`pre5b` and
  `reversed2`-`reversed5b` are the same inputs for stages 2-5b.
- The build and verify logs of every stage.
- The committed headers used as the compile baseline.
- The check logs.

Unpack it with `tar -xJf session_folder_large_files.tar.xz`.

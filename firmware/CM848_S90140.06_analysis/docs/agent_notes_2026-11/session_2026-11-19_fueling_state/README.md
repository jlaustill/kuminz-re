# Fueling state session (2026-11-19, todo 045)

The question was whether `governor_fuel_demand_mode` (0x40a154) is an enum. It is the Cummins FSGVFLST governed
fueling state, so `ENGINE_OPERATING_MODE` became the shared `FUELING_STATE` enum. The findings and follow-ups are in
`work/tasks/045-cm848-fueling-state-enum.md`. This folder keeps the session's scratch work. Three read-only subagents
ran: two in stage 4 and one in stage 5.

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
- **The agents** (two in stage 4, one in stage 5):
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

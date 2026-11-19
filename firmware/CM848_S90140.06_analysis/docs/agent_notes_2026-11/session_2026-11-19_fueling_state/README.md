# Fueling state session (2026-11-19, todo 045)

The question was whether `governor_fuel_demand_mode` (0x40a154) is an enum. It is the Cummins FSGVFLST governed
fueling state, so `ENGINE_OPERATING_MODE` became the shared `FUELING_STATE` enum. The findings and follow-ups are in
`work/tasks/045-cm848-fueling-state-enum.md`. This folder keeps the session's scratch work. The session started no
subagents.

`session_folder/` has these files:
- `apply_fueling_state.py`: the CSV edit. It checks each old row before it replaces it.
- `check_enum_proof.py`: the stricter proof. It runs after `rename_waves/reverse_names.py` and normalizes member names
  and numbers to values, the enum type to `word`, auto-named locals to placeholders and the split dword's pieces. It
  then lists every function that still differs. One did: the split local in `cm848_processProtectionRampControl`.
- `map_all.csv`: the reverse mapping (two globals, the enum type and the eight renamed members).
- `follow.sh`: prints the first users of the register after each load of the target. Every load fed a `cmpwi` or a
  copy.
- `archive_fueling_state_session.py`: writes this folder, and writes the private transcript archive outside the repo.
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
- **The two stage-4 agents:**
  - `agent_prompts.jsonl`: their exact prompts.
  - `agent_prompts_and_reports.md`: their prompts and reports in short, and what was checked before applying.
  - `extract_agent_prompts.py`: pulls the prompts out of the transcript.
- `scan_private.py`: the privacy scan used before archiving. It reads the owner's address from the local git config,
  so the file itself carries none.
- `commit_message*.txt` / `pr_body.md`: the commit messages and the PR #52 body.

`session_folder_large_files.tar.xz` holds the files listed in `session_folder_large_files.txt`:
- `all.dis`: the full disassembly of both banks that the access census scanned.
- `pre.cpp` / `pre_canon.cpp` / `reversed.cpp`: the baseline build and the two proof inputs.
- Both build logs.
- The committed headers used as the compile baseline.
- The check logs.

Unpack it with `tar -xJf session_folder_large_files.tar.xz`.

# Session 2026-11-17: the P0500 vehicle speed sensor monitor (todo 044)

One session, no subagents. The request was to find at least one misnamed symbol in `cm848_rom.ghidra.cpp`.
- **First pass (`findings.md`, first part):** this ran on a checkout 36 commits behind main and found the PGN 65213
  Fan Drive builder, which PR #50 had already renamed.
- **Second pass, on 809fd25:** a DTC-code check found `diag_boostLoad_overtemp_monitor`, which sets only P0500. The
  branch `cm848/vehicle-speed-sensor-p0500-monitor` renames it and its group (see
  `work/tasks/044-cm848-dtc-code-name-clashes.md`).

`session_folder/` mirrors the scratch folder:
- `fault_setters.py` / `fault_setters_origin_main.txt`: the DTC-code check, listing the fault bits each function sets
  (fault n → ROM 0x5985a slot → `obd_dtc_code_table` P-code), run on 809fd25.
- `scan_addr_range.py` / `sweep_addrs.py`: whole-binary sweeps, over both banks, for every access to an address. They
  use `disasm_func.find_accesses`. `xref_addr.py` only scans functions whose `.cpp` text names the symbol.
- `disassembly_both_banks.tar.xz`: the objdump of both banks that the sweeps read.
- `proof/`: the label-only proof and the check outputs.
  - `map_all.csv` is the `reverse_names.py` mapping, and `map_refresh.csv` the `refresh_references.py` mapping.
  - All 20 names render. 1966 of 1969 functions are identical. The 3 that differ are the intended type changes: the
    FD1 prototype, the `ema_filter_state_t` at 0x3fd070 and the `byte` local.

`session_folder_large_files.tar.xz` holds the files listed in `session_folder_large_files.txt`: the baseline and
build-1 `.cpp`, their canonical and reversed copies, and the two build logs.

**Wave 10 (2026-11-18, same PR):** four read-only agents verified the ten DTC-code leads of task 044. Their prompts are
in `agent_prompts.md` / `.jsonl`, and their brief is `rename_waves/briefs/brief_wave10.md`. `session_folder/wave10/` has:
- each agent's `result_W10_<group>.jsonl` and its `aligned_` copy;
- the mappings (`map_renames.csv`, `map_newrows.csv`, the hand edits in `map_hand.csv`, all of them in `map_all.csv`,
  and `map_refresh.csv`);
- the proof outputs;
- `hsg_gain_set_rows.py`, the script that typed the high speed governor gain sets.

The snapshots and build logs are in the large-files archive. The proof result: all 247 names render with no
underscore variants. The 10 functions that differ change only in typing: the misfire state dwords, the array / byte /
`i16` types of new rows, and the CRC `word[2]` pairs.

**Wave 11 (2026-11-18, same PR):** four read-only agents proposed struct / array / bitfield shapes from a census of
named-struct casts, piece accesses and `(&name)[i]` indexing. Their brief is `rename_waves/briefs/brief_wave11.md`
and their prompts are entries 5-8 of `agent_prompts.md`. `session_folder/wave11/` has:
- each agent's `result_W11_<group>.jsonl` and its `aligned_` copy. The `aligned_W11_pieces_commit2.jsonl` copy holds
  back 0x3fed92.
- The tools that applied the shapes:
  - `descriptor_census.py` / `descriptor_struct.py`: the J1939 transmit descriptors.
  - `triage_shapes.py` / `new_row_overlaps.py`: the triage.
  - `apply_shapes.py`: the batch A / B converter. It recomputes the rows inside each shape from the current CSVs.
  - `fix_*.py`: the label, comment and RMW-byte fixes.
- The checks:
  - `accept_shapes.py`: the pattern census, the boot-ROM function check, the warnings and the thunk log.
  - `piece_census.py`: lists each symbol whose `._N_M_` piece count went up.
- The proof and check outputs, the boot-ROM diff summaries, and the `refresh_references.py` mappings (`map_*.csv`).
- `extract_agent_prompts.py`, which appended the wave 11 prompts to `agent_prompts.md` / `.jsonl`.

The `.cpp` snapshots of each step, their canonical and reversed copies, and the build logs are in the large-files
archive under `wave11/`. Overall the pieces in the `.cpp` went from 917 to 512.

The session transcript and the subagent transcripts are kept privately, outside the repo.

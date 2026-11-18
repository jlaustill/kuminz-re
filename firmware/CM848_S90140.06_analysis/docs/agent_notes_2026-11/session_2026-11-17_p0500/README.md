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

The session transcript is kept privately, outside the repo.

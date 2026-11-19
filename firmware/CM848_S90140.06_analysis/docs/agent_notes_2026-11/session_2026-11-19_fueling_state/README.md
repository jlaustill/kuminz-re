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

`session_folder_large_files.tar.xz` holds the files listed in `session_folder_large_files.txt`:
- `all.dis`: the full disassembly of both banks that the access census scanned.
- `pre.cpp` / `pre_canon.cpp` / `reversed.cpp`: the baseline build and the two proof inputs.
- Both build logs.
- The committed headers used as the compile baseline.
- The check logs.

Unpack it with `tar -xJf session_folder_large_files.tar.xz`.

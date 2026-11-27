
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
- **Stage F:** `apply_r10f_types.py` (the widths and `sci_output_test_timers_t`). `relabel_struct.py` maps
  `instance.field` back to the old labels for the proof.
- **Helpers:**
  - `cache_tables.py`: the tables each cache serves;
  - `final_names.py`: old to final name through the round's maps;
  - `resolved_r10.py`: the task file sections.
- **Commit messages:** `commit_r10*.txt`.

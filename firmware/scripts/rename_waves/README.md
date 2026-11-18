# Rename-wave toolchain

These scripts gate, apply and prove the renames that read-only agents propose for a firmware's CSVs. The CM848
rename waves 1-7 of PR #50 ran on them. Those waves' briefs, raw results and applied mappings are in
`firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/`.

A rename is only accepted when the build proves it is **label-only**: map every new name back to the label it
replaced, and the new decompiled output must equal the old one.

## Agent result format

One JSON object per line.
- `kind`: `function`, `global`, `new_global`, `struct_field`, `enum_member`, `enum_type` or `note`.
- `verdict`: `confirmed`, `uncertain` or `rejected`.
- Other keys: `address`, `old`, `new`, `type` (new rows), `struct` (fields), `enum` (members), `plate_comment`
  (functions), `evidence`, `comment`, `text` (notes).
- A note whose text starts with `DELETE 0x<address> <name>:` removes that row (`apply_extras.py` stage 1).

## One wave

`OUT=firmware/CM848_S90140.06_analysis/output`, `S=firmware/scripts/rename_waves`, and `T` is a scratch folder that
holds the agents' `result_<wave>_<group>.jsonl` files.

1. **Vocabulary pass:** `python3 $S/align_results.py $T W8 rail governor [--swap OLD=NEW]...` writes
   `aligned_W8_*.jsonl`. It turns `init` into `initialize` in function names, applies prefix decisions given with
   `--swap`, makes the same replacements in the text fields, and drops `<name>+N` sub-label rows.
2. **Gate:** `python3 $S/apply_renames.py $OUT $T/aligned_W8_*.jsonl` prints a `PROBLEM` line for each of these:
   - two proposals for one address that disagree, or one new name proposed twice;
   - a new name already in a CSV;
   - a banned abbreviation (the `BANNED` set, which includes `init`);
   - a hex-looking part, or a malformed name;
   - an old name that is not the row's current name, or a register address;
   - `_cal` outside the EEPROM mirror (0x3fd482-0x3feec1), or an EEPROM value that lost its `_cal`;
   - a bare "protection" (it must say protection of what).

   Resolve every line (drop a row with `--skip ADDRESS,...` or fix the result), then run the gate again.
3. **Keep the baseline:** `cp $OUT/cm848_rom.ghidra.cpp $T/pre.cpp`.
4. **Apply:**
   - `python3 $S/apply_renames.py $OUT $T/aligned_W8_*.jsonl --out $T/map_renames.csv --apply` (functions with
     their plate comments, globals with "evidence (was old)" comments);
   - `python3 $S/apply_extras.py $OUT $T/map_fields.csv 1 $T/aligned_W8_*.jsonl` (struct fields, DELETE notes);
   - `python3 $S/apply_extras.py $OUT $T/map_newrows.csv 2 $T/aligned_W8_*.jsonl` (new rows);
   - `apply_enums.py` for enum members and types, and `rename_struct_types.py OLD_T=NEW_T[@0xADDRESS=INSTANCE]` for
     struct types.

   Concatenate the mappings (one header line) into `$T/map_all.csv`.
5. **Build:** `./analyze.sh build`. Ghidra refuses a project path with an element that starts with a dot (a
   `.claude/worktrees/` checkout), so build such a checkout through a symlink.
6. **Prove:**
   ```
   python3 $S/canonicalize_cpp.py $T/pre.cpp $T/pre_canon.cpp
   python3 $S/reverse_names.py $T/pre.cpp $OUT/cm848_rom.ghidra.cpp $T/map_all.csv --ignore-comments \
       --canonical-code-labels --write-reversed $T/reversed.cpp
   python3 $S/squash_changed.py $T/pre_canon.cpp $T/reversed.cpp
   python3 $S/classify_diffs.py $T/pre_canon.cpp $T/reversed.cpp
   python3 $S/token_diff.py $T/pre_canon.cpp $T/reversed.cpp <function> [max]   # or fn_diff.py
   ```
   `reverse_names.py` reports whether every new name renders, and any `_name` variant (a width mismatch).

   Every function that still differs needs an explanation. The ones these waves accepted:
   - the default label of a row that had no name (`WORD_ARRAY_x`, `<type>_x`);
   - the order of local declarations;
   - a cast that comes from a new row's type. Check the load instruction (`disasm_func.py`) and type the row from it:
     `lha` is signed (`i16`), `lhz` unsigned (`word`).
7. **Refresh references:** write a refresh mapping (the function and global rows whose old label is not `DAT_`,
   and `struct.field` pairs for renamed fields), then run `python3 $S/refresh_references.py <repo> $T/map_refresh.csv`.
   It rewrites old names in CSV comments, `firmware/CLAUDE.md` and `test_disasm_tools.py`, and it keeps history
   ("(was old)", "were a / b") as it is. `python3 $S/comment_name_sweep.py <repo> HEAD` then lists the names that
   comments cite but no CSV defines.
8. **Check:**
   - `python3 firmware/scripts/lookup_tables.py`, plus `test_lookup_tables.py` and `test_disasm_tools.py`;
   - no new build warnings;
   - regenerate the headers with `python3 $S/regen_headers.py $OUT`, then run
     `g++ -fsyntax-only -std=c++17 -I $OUT $S/hdr_check.cpp`;
   - `./analyze.sh verify` after the commit. Check out the timestamp-only `.cpp` change.

Tests: `python3 firmware/scripts/test_rename_waves.py`.

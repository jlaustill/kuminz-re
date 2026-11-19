# CSV Type Reference — deep-type details

Read this when working enums, structs/bitfields, or function prototypes. The shared loop and the
"obsolete commands" rules live in `SKILL.md`. All examples below are real rows from the CM848 CSVs.

## Enums (`enums.csv`)

Columns: `enum_name,value,member_name,comment,size`

```
J1939_PGN_LOWER,0xfef1,PGN_65265_CRUISE_VEHICLE_SPEED,Cruise Control/Vehicle Speed (CCVS),2
```

To make a variable render the enum, set the variable's `type` column (in `global_variables.csv`)
to the `enum_name`.

**When the enum name will NOT render (even though the row is correct):**
- The access is masked: `(var & 0x80)` or `(var & MASK) == VALUE` → the mask survives, no enum name.
  Use a **struct bitfield** for packed flags instead.
- The variable is `byte`-width → enum substitution is suppressed; widen only if the hardware access
  is genuinely wider (don't lie about width).
- `size` (enum storage width) ≠ the variable's declared width → the type is silently dropped.

Enum names render for whole-value compares only: `if (state == CSP_CRANKING)`.

**The enum name renders WRONG when a value has no member (Ghidra 12.1).** A code-like enum whose values share bits
(1, 2, 4, 5, 12 ...) gets printed as an OR of members for any value without an exact member. Example (CM848
`FUELING_STATE`, 2026-11-19): 15 rendered as `FUELING_STATE_HIGH_SPEED_GOVERNOR | FUELING_STATE_TSC1_SPEED_CONTROL |
FUELING_STATE_TSC1_TORQUE_CONTROL`, which reads as a flag set.
- Give every value the enum's carriers store or compare a member. Unproven values get a placeholder,
  `<ENUM>_UNIDENTIFIED_<n>`, with the setter in its comment.
- Adding members can make new ORs possible. With 16 and 32 as members, the compared-only 37 = 32 | 5 and 49 = 32 | 16 | 1
  become representable, so the compared-only values need members too.
- After any enum change, diff the build with members and numbers normalized to their values (the 2026-11-19 session's
  `check_enum_proof.py` in `docs/agent_notes_2026-11/session_2026-11-19_fueling_state/session_folder/`), and grep for
  `<ENUM>_\w+ | `.

## Struct bitfields (`structure_definitions.csv`)

Columns: `struct_name,address,field_name,type,size,comment,dependency,Status`

A single flag bit (bit7 = the `0x80` bit of a byte):
```
protection_enable_t,0x0040c050,protection_active,bitfield:1@7,1,Runtime protection-engaged boolean - bit7 (0x80),,verified
```
- `type` = `bitfield:<bitSize>@<bitOffset>`; `bitOffset` is from the LSB (bit7 is the `0x80` bit).
- `size` = storage byte-width on the FIRST field of the unit; each additional field packed in the
  same byte/word gets `size=0` (continuation — shares the opener's storage).
- **Requires Ghidra ≥ 12.1** to recover bitfield names on PowerPC (12.0-from-source renders the raw
  mask AND loses the name). `scripts/common.sh` defaults `GHIDRA_DIR` to the prebuilt 12.1.
- Result: `(var & 0x80)` becomes `var.protection_active`; `| 0x80` / `& 0x7f` become
  `protection_active = 1` / `= 0`.

**Do not** model an `sth`-paired flag (e.g. `sth` storing `0x0001`) as two byte fields — big-endian
ordering makes the names come out backwards. Declare a single `word` instead.

## Multiple instances of one struct type

`ApplyStructures.java` builds ONE type from ALL rows sharing a `struct_name`. List the fields once
at the first instance's address, then add an empty **marker row** for each additional address:
```
dual_axis_table_dims_t,0x003fa878,row_count,word,2,First field,,verified
dual_axis_table_dims_t,0x003fa878,col_count,word,2,Second field,,verified
dual_axis_table_dims_t,0x003fa87c,,,,governor offset table B - second instance,,verified
```
The marker row (empty `field_name`/`type`/`size`) registers the address without duplicating fields.
Listing fields at two addresses instead creates one oversize type applied only at the first.

**Commas in comments must be quoted** — this file uses a quote-aware parser, unlike
`global_variables.csv`/`function_renames.csv` which absorb commas into the last column.

## Function prototypes (`function_definitions.csv`)

Columns: `function_address,function_name,param_index,name,type,comment`

Declare the FULL prototype — the return row plus one row per parameter. A return-only row is
auto-handled (import keeps Ghidra-recovered params) but yields generic `param_N` names.

**r4-return gotcha:** on MPC555, `r4` is param1+return for some division helpers. NEVER give a
return type to an r4-return helper whose r4 is NOT a parameter (no-arg / globals-only helpers such as
diag handlers) — the decompiler then assumes r4 is preserved and swaps the wrong operand at every
call site. To undo a bad prototype, fix/remove the row and rebuild.

**Type keywords (`function_definitions.csv` and `local_variables.csv`):**
- `int` / `uint` / `dword` / `uint32_t` → unsigned `dword`. For a signed 32-bit value use **`int32_t`** (signed `int`, added 2026-11-14). The `int` mapping was left alone so existing rows do not re-render.
- `short` / `ushort` / `word` / `uint16_t` → unsigned `word`. There is no signed 16-bit keyword for prototypes or locals yet.
- The other CSVs use different mappers: `structure_definitions.csv` (ApplyStructures) maps `int` / `short` to **signed** types, and `global_variables.csv` (ImportAnalysis) has its own signed keywords `i8` / `i16` / `i32` and no `int` case (an `int` there goes to a named-type lookup). ApplyGlobalVariableTypes is a further copy, but only the unused `cmd_vartypes` reaches it.
- `undefined4` locks only the **name**; the decompiler keeps inferring the type. Use it for a 4-byte parameter whose inferred type is already right.
- A 2-byte parameter committed as `undefined4` renders as `x._2_2_` sub-pieces — give it `ushort`.
- Locked pointer types (`int *`, `word *`, `undefined4 *`) and committed parameters on one-line wrappers add casts at the call sites (`(uint)global`, `(dword *)&x`). Leave such wrappers uncommitted, or check every caller after the build.

## Troubleshooting matrix (change didn't render)

| Symptom in `.cpp` | Cause | Fix |
|---|---|---|
| global still `DAT_<addr>` | CSV row not applied | exact 4 fields, no dup address, address matches symbol |
| global renders `_<name>` | declared type too narrow | widen, or pair-clear → single wider var/struct (see SKILL.md) |
| enum name absent, mask shown | masked access | use a struct bitfield, not an enum |
| enum name absent, value shown | width mismatch / `byte` var | match `size` to var width |
| bitfield shows raw `& MASK` | Ghidra 12.0 | use the prebuilt 12.1 (`GHIDRA_DIR`) |
| 2nd struct instance untyped | listed fields twice | use a marker row for the 2nd address |
| function still `FUN_<addr>` | — | `build` force-creates; check the address matches exactly |
| call site swaps an operand | bad r4-return prototype | remove the return row for globals-only helpers |
| only `// Generated:` line changed | timestamp churn | `git checkout` the file |

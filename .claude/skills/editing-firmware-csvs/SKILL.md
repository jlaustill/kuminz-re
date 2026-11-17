---
name: editing-firmware-csvs
description: Use when editing any Cummins firmware analysis CSV (global_variables, enums, structure_definitions, function_renames, function_definitions, local_variables, labels, constants, arrays) to name/type/annotate symbols, when a CSV change did not appear in the decompiled .cpp after building, when a global renders with a leading-underscore prefix, when an enum or struct bitfield name fails to substitute, or when an r4-return prototype mangles call sites. Covers CM848 and CM550.
---

# Editing Firmware CSVs (CM848 / CM550)

## Overview

A change is **not applied** when you edit a CSV — it is applied when a fresh `build` renders it **clean** in the `.cpp`. The CSVs are the only inputs; the decompiler is the judge. Never report a change as done from the edit alone — it is done only when the render check passes.

**`./analyze.sh build` is the ONLY producer.** It rebuilds the `.rep` from scratch and applies *every* CSV in the correct internal order. The real subcommands are: `build`, `verify`, `status`, `decompile`, `listfuncs`, `classifyfuncs`, `deletefuncs`. There is no standalone `import` / `export` / `enums` / `memmap` / `localvars` / `structures` — those are internal build stages, not commands. **Ignore any CLAUDE.md or CSV-header text that tells you to run them separately or in a particular order; `build` handles ordering** (enums-before-import, memmap-before-structures, funcdefs/localvars-at-export are all automatic).

## The loop (same for every CSV)

1. **Read before editing — never assert from memory.** grep the symbol's real usages in the `.cpp` and its real neighbors in the target CSV. Pick names/types/widths from what you SEE.
2. **Edit the right CSV** (table below). Match the column format exactly.
3. **Build:** `cd firmware/<fw>_analysis/ghidra && ./analyze.sh build` (~2–3 min).
4. **Verify the render** in `output/<fw>.ghidra.cpp`: new symbol present, old default (`DAT_`, `FUN_`, raw mask, magic number) gone, no `_`-prefixed variant.
5. If it didn't land → per-type fix below → rebuild. Loop until the render is clean.

## Which CSV, which columns

| CSV | columns | use for |
|---|---|---|
| `global_variables.csv` | `address,name,type,comment` | RAM/ROM globals (`DAT_`/`_DAT_`) |
| `enums.csv` | `enum_name,value,member_name,comment,size` | magic numbers compared by `==` |
| `structure_definitions.csv` | `struct_name,address,field_name,type,size,comment,dependency,Status` | structs, **packed flag bitfields** |
| `function_renames.csv` | `address,name[,plate_comment]` | function names (`FUN_`) |
| `function_definitions.csv` | `function_address,function_name,param_index,name,type,comment` | prototypes (params + return) |
| `local_variables.csv` | `function_address,function_name,old_name,new_name,type,comment` | rename decompiler locals (`uVar1`) |
| `labels.csv` | `address,label_name,comment` | code labels |
| `constants.csv` | `address,constant_name,value,comment` | document magic numbers |
| `arrays.csv` | `address,array_name,element_type,element_count,comment` | arrays/buffers |

## Per-type gotchas (the parts that bite)

- **global_variables** — type width MUST match the load (`byte`=lbz/1B, `word`=lhz/2B, `dword`=lwz/4B). An array type `T[N]` (`word[10]`) applies as an array, and an empty name types the address without naming it (unnamed word arrays render `WORD_ARRAY_<addr>`); a type the importer cannot map is listed with a WARNING in the build log (since 2026-11-15 - before that `T[N]` was dropped silently). After touching a lookup table or a lookup prototype, run `python3 firmware/scripts/lookup_tables.py` (it audits every table size; `--apply` adds the rows for new tables). Leading `_name` = type too narrow → see underscore fix. **`_cal` = EEPROM-backed (Calterm-tunable) only — classify by the MEMORY MAP, not e2m** (e2m uses Calterm virtual addresses, so a RAM-address grep is blind): ROM / the ROM→RAM copy window (0x3F9800–0x3FDB30) / Bank2 flash = fixed constant → **no `_cal`**; EEPROM (0x01xxxxxx) or an EEPROM-loaded RAM value → `_cal`; computed/working RAM vars → never `_cal`. **CM848 shortcut:** the EEPROM RAM mirror is `0x3fd482`-`0x3feec1` (RAM = 0x3fd482 + EEPROM offset), so EEPROM-backed (`_cal`) values live there; `0x40xxxx`/`0x3fxxxx` cals are ROM/flash → no `_cal`.
- **enums** — the name renders ONLY for whole-value compares (`var == VALUE`). It will NOT render for masked access (`var & MASK`) or for `byte`-width variables. For packed flags, use a **struct bitfield**, not an enum. (Width must match `size`, or the type is silently dropped.) **Member names: spell words out — NO invented abbreviations** (`CCS_SET`/`CSR_IDLE` are banned; only universal industry abbrevs like RPM/J1939/ADC are OK). Use a fully-spelled domain prefix: `CRUISE_SET`, `CRUISE_SWITCH_SET`, `DRIVETRAIN_STANDALONE` — never an invented initialism. A short disambiguator suffix (`_2`/`_B`/`_PREV`) is fine.
- **structure_definitions** — bitfield field type is `bitfield:<bitSize>@<bitOffset>` (bitOffset from LSB; bit7 = the `0x80` bit), `size` = storage byte-width on the first field and `0` on each additional field packed in the same unit. **Requires Ghidra ≥ 12.1** to recover bitfield names on PowerPC. Multiple instances of one struct type = one full field set at the first address + an empty-field **marker row** per additional address. Commas in comments must be **quoted** (this file uses a quote-aware parser).
- **function_renames** — `build` **force-creates** the function even at an address Ghidra didn't recognize as one (it disassembles + creates), so naming works before the function "exists." Optional 3rd column is a plate comment that round-trips.
- **function_definitions** — r4-return gotcha: declare the FULL prototype (return + every param row). NEVER give a return type to an r4-return helper whose r4 is not a parameter (no-arg/globals-only helpers) — it makes the decompiler swap the wrong operand at call sites. See `csv-type-reference.md`.
- **local_variables** — don't reuse a global's name for a local (creates a confusing shadow). Applied automatically during `build` (no `localvars` command).
- **labels / constants / arrays** — nothing special: edit, build, grep.

Detailed examples for the deep types (struct bitfield/multi-instance, enum substitution, r4-return prototypes, troubleshooting matrix) are in **`csv-type-reference.md`** — read it when working those types.

## Underscore prefix `_<name>` (globals)

Usually means the declared type is too NARROW — but confirm the cause before "fixing" it (an asm width check distinguishes them):
- **gap ≥ access width** → type too narrow: widen (`word`→`dword`) and rebuild (common case).
- **gap < access width** → PowerPC pair-clear (one `sth`/`stw` writes this var AND its neighbor): declare ONE wider var spanning both, or a struct — never two narrow vars.
- **ROM-to-RAM thunk window (CM848, addr in 0x3F9800–0x3FDB30)** → boot copies ROM 0x3C30–0x7F60 into this window (`RAM = 0x3F9800 + (ROM − 0x3C30)`), and the `romramthunks` build stage puts a 4-byte thunk on each image address the boot ROM calls. **Since todo 043 (2026-11-17)** the stage leaves the address alone when a NAMED row sits in those 4 bytes (it points the boot calls at the ROM function with call-override references instead), so a named data row there renders clean (`j1939_pgn65261_tx_header` @ 0x3faafc used to render `_j1939_pgn65261_tx_header`). A `_` on a type-only (unnamed) row inside a thunk's 4 bytes still means the thunk took those bytes: give the row a name and rebuild. Build log: `Call override: ... data <name> kept`.
- A clean render is achievable in all three cases.

## Obsolete — do NOT do these (the one-shot-build trap)

- ❌ Running `./analyze.sh import` / `export` / `enums` / `memmap` / `structures` / `localvars` — not subcommands. Just `build`.
- ❌ "Run enums before import" / "run memmap before structures" / "run localvars then export" — `build` orders all stages automatically.
- ❌ Editing Ghidra directly — the `.rep` is disposable and rebuilt from scratch; the CSV is the only source of truth.

## Working dirs

| Firmware | ghidra dir | output .cpp |
|---|---|---|
| CM848 | `firmware/CM848_S90140.06_analysis/ghidra` | `output/cm848_rom.ghidra.cpp` |
| CM550 | `firmware/CM550_J90350.00_analysis/ghidra` | `output/J90350.00.ghidra.cpp` |

## Common mistakes

- Asserting neighbor names / line numbers / widths from memory — always grep the real CSV and `.cpp` first.
- Committing timestamp-only churn: every build rewrites the `// Generated:` header. If that's the only diff, `git checkout` the file. `./analyze.sh verify` (build x2, byte-identical) normalizes it.

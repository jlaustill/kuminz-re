# J90350.00 Firmware Analysis (Live ECU Extraction)

## Quick Workflow Reference — ONE deterministic build

The Ghidra `.rep` is a disposable build artifact; the CSVs in `output/` are the only source
of truth. There is one way to produce output — `build` — and it applies every CSV from scratch.

```bash
cd ghidra
# 1. Edit CSV files in ../output/ (function_renames.csv, global_variables.csv, enums.csv, ...)
./analyze.sh build      # 2. Rebuild from scratch (deterministic, single-threaded)
./analyze.sh verify     # 3. (optional) prove byte-identical reproducibility
# 4. Verify output: output/J90350.00.ghidra.cpp ; 5. Commit
```

**CSV Location:** `output/` · **Ghidra Project:** `ghidra/project/J90350/`

## Command Reference

```bash
./analyze.sh build      # The one build: fresh binary → apply every CSV → .cpp + CSVs
./analyze.sh verify     # Build twice, assert byte-identical (determinism contract)
./analyze.sh deletefuncs <addr>...  # Record spurious-function addr(s) to deleted_functions.csv
./analyze.sh status     # Project status (read-only)
./analyze.sh decompile <addr|name>  # Decompile single function (read-only)
./analyze.sh listfuncs <out> / classifyfuncs <addrs> <out>  # Read-only repro diagnostics
```

CM550 `build` order (single-bank MC68336): `init → analyze → memmap → enums → import →
deletions → import → hwregs → labels → constants → arrays → export`. Partials
(`import`/`export`/`analyze`/…) were removed — edit CSVs and run `build`.

---

## CSV Files

All CSV files are in `output/`:

| File | Purpose |
|------|---------|
| `function_renames.csv` | Function names by address |
| `global_variables.csv` | Typed global variables |
| `enums.csv` | Enum definitions |
| `labels.csv` | Code labels |
| `structure_definitions.csv` | C structure definitions |
| `function_definitions.csv` | Function parameter types and return types |
| `local_variables.csv` | Local variable names/types |

---

## General Guidelines

- All changes must go through CSV files, never directly in Ghidra
- Use `./analyze.sh status` to check current project state
- Output decompilation is at `output/J90350.00.ghidra.cpp`
- See `../CLAUDE.md` for detailed workflow order, underscore fixes, and RAM loading requirements

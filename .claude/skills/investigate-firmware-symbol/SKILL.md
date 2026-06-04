---
name: investigate-firmware-symbol
description: Use when deciding whether an unnamed (or poorly named) Cummins firmware symbol — a DAT_/global variable address OR a FUN_/function — has enough context to be given a meaningful name and what type-shape it should take (flat global, enum, struct field, bitfield, array, or function prototype). Read-only research that returns a structured recommendation for a reviewer to apply. Covers CM848 and CM550.
---

# Investigate Firmware Symbol (CM848 / CM550)

## Overview

Investigate ONE symbol — a variable/global address or a function — and return a structured recommendation: is there enough evidence to name it meaningfully, what *type-shape* it really is, and (if nameable) a concrete name + type. This is the **read-only research front-end**: a reviewing agent confirms with the user, then the [[editing-firmware-csvs]] skill applies the rename. 

**This skill writes nothing.** No Edit/Write, no `./analyze.sh build`, no CSV changes. Only read, grep, `./analyze.sh decompile`, and disassemble. If you find yourself editing a CSV, you've left this skill's scope — stop and hand the recommendation off.

**Cite everything.** Every claim (usage, neighbor, width, context) must cite where you saw it (`file:line` or a disassembled instruction). Never assert a neighbor name, width, or value from memory — grep/disassemble it.

## The evidence sweep (run all eight)

Work in `firmware/<fw>_analysis/`. Output is `output/<fw>.ghidra.cpp` (CM848: `cm848_rom.ghidra.cpp`, CM550: `J90350.00.ghidra.cpp`).

1. **Resolve the target** — current symbol (`DAT_`/`FUN_`/named), address, firmware, and which binary/region it lives in (see reference).
2. **All usages** — `grep -n` the symbol in the `.cpp`. The decompiler wraps long lines, so grep the bare name (not `name(`) and read each hit. For a **variable**: classify each as read vs write. For a **function**: collect call sites (callers) + what it calls (callees).
3. **Context** — read the enclosing function(s) around each usage; state what the code is doing in plain terms, cited.
4. **CSV neighbors** — `grep` the address in the relevant CSV; record the entries immediately above/below with their names, types, widths, and byte gaps.
5. **Assembly width check (MANDATORY)** — disassemble the *referencing code* and read the actual load/store width for the target. This is decisive for typing and must be done every run. Exact invocations + the turnkey grep anchor are in `symbol-evidence-reference.md`. CM848/PowerPC is reliable; CM550/m68k is best-effort — if a specific access genuinely won't decode, fall back to the decompilation's width signal and **say so explicitly**.
   - **You must actually run the disassembler and quote the instruction.** "Width from context / from neighbors / from the decompilation / from the byte gap" is **NOT** the assembly check — if your WIDTH line doesn't quote a real `l{b,h,w}z`/`lha`/`st{b,h,w}` (or m68k `.b/.w/.l`) instruction with its address, you have skipped this step. Go back and run it. The whole point is to catch the cases where the context guess is *wrong*.
6. **Tunable check** — `grep` the address in `output/e2m_parameters.csv`. Present → Calterm-tunable (a `_cal` candidate). Absent → **not** tunable → do NOT propose `_cal`, regardless of what neighbors are named.
7. **Cross-firmware analogue** — check the *other* firmware's `.cpp`/CSVs for the same role or a shared name. Note a match (supports a shared name) or its absence.
8. **Type-shape detection (always)** — decide what the symbol really is, because it picks the target CSV. Signals in `symbol-evidence-reference.md`. Summary: `== const` against a small set → **enum**; masked `& 0xNN` bit tests → **bitfield**; clustered base+offset, pointer-passed → **struct field**; indexed `base[i]` → **array**; dispatch-table / sibling handlers → **function family**; otherwise → **flat global**.

## The recommendation (return this; write nothing)

```
TARGET: <addr> · <current symbol> · <firmware>
USAGES: <N reads / M writes>  (or callers/callees for a function) — cited
WIDTH (asm): <byte/word/dword> — quote the instruction, e.g. `lhz r12,-29832(r12) @ 0x526278`  (or, ONLY for m68k that won't decode: "m68k undecoded; .cpp implies <width> via <cite>")
CONTEXT: <what it does, 1-3 lines, cited>
NEIGHBORS: <above/below names · types · gaps>
TUNABLE: <yes: in e2m_parameters.csv | no>
CROSS-FW: <analogue in other firmware, or none>
TYPE-SHAPE: flat global | enum(<which/values>) | struct field(<struct·offset>) | bitfield(<bit>) | array(<elem·count>) | function(<prototype note>)  → target CSV: <which>

VERDICT: NAMEABLE → name=<proposed>  type=<byte/word/dword/enum/...>  csv=<file>  confidence=<high/med/low>
         rationale: <one line>
   — or —
         INSUFFICIENT → missing: <what evidence is absent>; would resolve by: <what to do/name first>
```

Confidence is **low** if the only evidence is neighbor-mimicry, or if key referenced symbols are themselves unnamed — say that rather than inflating it.

**Before you finalize, two hard gates:**
- If `WIDTH (asm)` doesn't quote a real instruction (PowerPC) — re-run the disassembler with the correct binary/window; don't ship a context guess labeled "(asm)".
- If `TUNABLE: no`, the proposed name **must not** end in `_cal` — strip it. (Neighbors having `_cal` is not evidence; the `e2m_parameters.csv` check is.)

## Common mistakes (from baseline failures)

- Inferring width "from context" and skipping the disassembly — the asm width check is **mandatory**, not optional.
- Treating every symbol as a flat global — run the type-shape check; an enum/struct/bitfield routes to a different CSV.
- Proposing `_cal` because neighbors have it — gate `_cal` on `e2m_parameters.csv`, not vibes.
- Conflating "not in e2m" with "no cross-firmware analogue" — they're separate steps (6 vs 7).
- Asserting neighbor names / values from memory — grep them and cite.
- Editing a CSV or running `build` — out of scope; this skill only recommends.

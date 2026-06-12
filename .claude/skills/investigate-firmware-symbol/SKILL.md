---
name: investigate-firmware-symbol
description: Use when deciding whether an unnamed (or poorly named) Cummins firmware symbol — a DAT_/global variable address OR a FUN_/function — has enough context to be given a meaningful name and what type-shape it should take (flat global, enum, struct field, bitfield, array, or function prototype). Read-only research that returns a structured recommendation for a reviewer to apply. Covers CM848 and CM550.
---

# Investigate Firmware Symbol (CM848 / CM550)

## Overview

Investigate ONE symbol — a variable/global address or a function — and return a structured recommendation: is there enough evidence to name it meaningfully, what *type-shape* it really is, and (if nameable) a concrete name + type. This is the **read-only research front-end**: a reviewing agent confirms with the user, then the [[editing-firmware-csvs]] skill applies the rename. 

**The container is the scope.** A symbol is only the *starting point*. If the evidence shows it lives inside a container — an element of an array, a field of a struct, a member of an enum's value-set — then the **container becomes the unit you investigate and recommend**, not the lone address. This is not a follow-up task to hand off later; it is *this* investigation's job. Naming `DAT_003fa01c` as a flat global when it is really `table_interp_args_t.y_axis_ptr` of array-element 0 is a wrong answer, even if the name sounds plausible. Step 8 (type-shape) is where you make this call, and when it fires, your VERDICT models the container (with the target located inside it), not the single symbol. Often the container *type already exists* in `structure_definitions.csv` — recognizing the symbol as an instance/field of it is the whole finding.

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
6. **Tunable check (memory map, NOT e2m)** — classify the address by region: ROM / the ROM→RAM copy window (0x3F9800–0x3FDB30) / Bank2 flash = fixed constant → **no `_cal`**; EEPROM (0x01xxxxxx) or an EEPROM-loaded RAM value = Calterm-tunable → `_cal` candidate; computed/working RAM vars → never `_cal`. Do NOT grep `e2m_parameters.csv` — it uses Calterm *virtual* addresses, so a RAM-address grep is blind. A boot-loaded RAM constant whose source you can't confirm → conservatively no `_cal`.
   - **CM848 shortcut:** EEPROM only shadows into the **`0x3feexx`** RAM block — every boot `mpc555_eepromReadWords` targets it (security key / serial / cal words / config / version). So an EEPROM-backed (`_cal`) value lives in `0x3feexx`; any calibration at `0x40xxxx` / `0x3fxxxx` outside that is ROM/flash-sourced → **no `_cal`**. (To settle a specific address, grep the EEPROM read destinations: `grep -o 'mpc555_eepromReadWords([^)]*)' <fw>.ghidra.cpp`.)
7. **Cross-firmware analogue** — check the *other* firmware's `.cpp`/CSVs for the same role or a shared name. Note a match (supports a shared name) or its absence.
8. **Type-shape detection → escalate to the container (always)** — decide what the symbol really is, because it picks both the target CSV *and the scope of the recommendation*. Signals in `symbol-evidence-reference.md`. Summary: `== const` against a small set → **enum**; masked `& 0xNN` bit tests → **bitfield**; clustered base+offset, pointer-passed (esp. cast to a struct type at a call, e.g. `lookupTableInterpolation((table_interp_args_t *)p)`) → **struct field**; indexed `base[i]` or a fixed-stride run of sibling references → **array**; dispatch-table / sibling handlers → **function family**; otherwise → **flat global**.
   - **When it is NOT a flat global, switch scope to the container — that is the deliverable, not a TODO.** Concretely:
     - **Find the container's extent.** Struct: grep how the consumer (the function the pointer is passed to) dereferences `+offset` to recover the field layout — or check whether the struct type *already exists* in `structure_definitions.csv` and the target is just a field of it. Array: establish the element stride and count from the sibling references (e.g. the `&base + N·stride` call sites), and remember the copy-window edge caveat for sizing (see reference / `firmware/CLAUDE.md`).
     - **Locate the target inside it.** Give the field/element the container-relative coordinate (`<struct>.<field>` at `+<offset>`, or `<array>[<index>]`), and note the `&sym + k` decompiler artifact for what it is — address arithmetic reaching a *neighboring* element, not a property of the symbol.
     - **Recommend the container.** The VERDICT names/declares the container (and routes to `structure_definitions.csv` / `arrays.csv`), with the original target identified as one member. A single-symbol flat-global rename here is the wrong output even when it "reads fine."
     - **Flag layout discrepancies for the applier** (don't silently smooth them over): e.g. a `verified` struct that is 12 bytes tiling at a 10-byte stride means entries overlap or the array isn't uniformly tiled — say so, and tell the applier to verify each instance address rather than blind-tile.

## The recommendation (return this; write nothing)

```
TARGET: <addr> · <current symbol> · <firmware>
USAGES: <N reads / M writes>  (or callers/callees for a function) — cited
WIDTH (asm): <byte/word/dword> — quote the instruction, e.g. `lhz r12,-29832(r12) @ 0x526278`  (or, ONLY for m68k that won't decode: "m68k undecoded; .cpp implies <width> via <cite>")
CONTEXT: <what it does, 1-3 lines, cited>
NEIGHBORS: <above/below names · types · gaps>
TUNABLE: <EEPROM-backed → _cal | ROM/flash/computed → no _cal | source unconfirmed → no>
CROSS-FW: <analogue in other firmware, or none>
TYPE-SHAPE: flat global | enum(<which/values>) | struct field(<struct·offset>) | bitfield(<bit>) | array(<elem·count>) | function(<prototype note>)  → target CSV: <which>
SCOPE: <the unit being recommended> — if NOT a flat global, this is the CONTAINER (struct type / array), with the target located inside it as `<struct>.<field>@+<off>` or `<array>[<index>]`. (For a flat global, scope = the symbol itself.)

VERDICT: NAMEABLE → recommend=<the SCOPE unit: flat name, OR `struct <T> instance @ <addr>` / `array <T>[N] @ <addr>`>
         target-within-scope=<where the original symbol sits, e.g. table_interp_args_t.y_axis_ptr @ +8>
         type=<byte/word/dword/enum/struct/array/...>  csv=<file>  confidence=<high/med/low>
         rationale: <one line>   caveats: <layout discrepancies the applier must verify, or none>
   — or —
         INSUFFICIENT → missing: <what evidence is absent>; would resolve by: <what to do/name first>
```

Confidence is **low** if the only evidence is neighbor-mimicry, or if key referenced symbols are themselves unnamed — say that rather than inflating it.

**Before you finalize, two hard gates:**
- If `WIDTH (asm)` doesn't quote a real instruction (PowerPC) — re-run the disassembler with the correct binary/window; don't ship a context guess labeled "(asm)".
- If the value is ROM/flash-sourced, computed, or its EEPROM source is unconfirmed, the proposed name **must not** end in `_cal` — strip it. (Neighbors having `_cal` is not evidence; the memory-map region is.)

## Common mistakes (from baseline failures)

- Inferring width "from context" and skipping the disassembly — the asm width check is **mandatory**, not optional.
- Treating every symbol as a flat global — run the type-shape check; an enum/struct/bitfield routes to a different CSV.
- **Naming the lone symbol when it lives inside a container** — if it's an array element or struct field, the *container* is the scope and the deliverable. Don't emit a flat-global name for `DAT_…` that is really `<struct>.<field>` of element N; model the container and locate the symbol inside it. (And check `structure_definitions.csv` first — the container type may already exist.)
- **Reading `&sym + k` as a property of `sym`** — that constant offset is the compiler reaching a *neighboring* array element/field; it's a tell that `sym` is inside a fixed-stride container, not a standalone value.
- Proposing `_cal` because neighbors have it — gate `_cal` on the memory map (EEPROM = `_cal`; ROM/flash/computed = no), not vibes or e2m (e2m's virtual addresses make a RAM-address grep unreliable).
- Conflating "not in e2m" with "no cross-firmware analogue" — they're separate steps (6 vs 7).
- Asserting neighbor names / values from memory — grep them and cite.
- Editing a CSV or running `build` — out of scope; this skill only recommends.

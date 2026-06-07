---
name: running-naming-campaigns
description: Use when naming many (dozens to hundreds of) unnamed DAT_/global symbols at once in CM848/CM550 Cummins firmware — a bulk naming campaign with parallel sub-agents, not one symbol. Use when a range is full of unnamed DAT_, when about to dispatch naming agents, or when about to apply a batch of agent-proposed names to global_variables.csv.
---

# Running Naming Campaigns

## Overview

Naming a whole range of unnamed firmware globals at once. Per-symbol analysis is delegated to parallel agents (each runs [[investigate-firmware-symbol]]); **this skill is the orchestration + bulk-validation + verification layer** that makes a batch trustworthy and lands it without corrupting the CSV.

**Core principle: you cannot re-investigate every symbol serially** — that defeats the parallel agents and never finishes. Trust each agent's *cited* evidence, but run the whole batch through fast **mechanical gates** before applying, then **prove it rendered**. Spot-check; don't redo.

## When to use / not

- **Use:** dozens–hundreds of unnamed `DAT_` in a range; about to dispatch naming agents; about to apply a batch of proposed names.
- **Not:** one symbol → [[investigate-firmware-symbol]]. Hand-editing one CSV row → [[editing-firmware-csvs]].

## Workflow

### 1. Build a ranked, tiered worklist
- **Rank by reference count** (refs = context = nameability). Floor at **5 refs**; 1–4 ref symbols are low-confidence — skip them.
- **Tier by region (CM848):** working RAM `0x0040xxxx` + post-copy `0x3F≥DB30` = **CLEAN** (names *and* custom widths stick). The ROM→RAM copy window **`0x3F9800–0x3FDB30` = IN-WINDOW**: names stick; a custom *widening* (a `dword` you declared) may revert to `word` on export — accept that. **But still declare the TRUE width — a `byte` stays `byte`.** Do NOT blanket-declare `word`: declaring `word` for a byte var overlaps the adjacent byte and silently suppresses BOTH symbols from the render (verified 2026-06-07 — 8 consecutive byte flags vanished this way until re-typed to `byte`). Arrays/structs stick in-window — use them for indexed access.
- **Partition batch-coherently:** `extract_variable_context.py <cpp> <prefix> <min_refs> <out>` clusters co-occurring symbols into batches with function-body context. Keep whole batches with one agent so two agents never name the same cluster inconsistently.

### 2. Dispatch
One agent per bin (~12–15 symbols), Sonnet, each **required** to follow [[investigate-firmware-symbol]] per symbol (including the disasm width-check) and return `address|name|type|confidence|width_evidence|rationale`. Point them at `disasm_func.py` / `xref_addr.py`.

### 3. Validate the batch — the gate battery (fast, scales; do NOT re-investigate each)

| Gate | Check | Fix |
|---|---|---|
| Coverage | every assigned address has exactly one row | re-dispatch missing |
| Dup addr / dup name | within the batch | disambiguate |
| Name collision | proposed name already in `global_variables.csv` | rename |
| **Already in CSV** | address row exists (often `PTR_DAT_`/`pointer`) | **EDIT that row in place — never append** (appending = duplicate-address row Ghidra mishandles) |
| `_cal` gate | any `_cal` on `0x40xxxx`/`0x3fxxxx` | strip it (EEPROM only shadows to `0x3feexx`); sweep with `audit_cal_suffixes.py` / [[auditing-cal-suffixes]] |
| Width | **spot-check a few** `width_evidence` citations with `disasm_func.py` | for IN-WINDOW symbols expect revert — don't apply custom width |
| Pointer mistype | `audit_widths.py` flags declared-`pointer` rows accessed narrower | retype |

### 4. Apply + verify the render
Apply via [[editing-firmware-csvs]] (append clean rows; **edit** the already-present ones), then `./analyze.sh build`. **The change is real only here** — verify in the `.cpp`:
- every name present;
- **zero `_name` underscore variants** (a leading `_` = width mismatch / pair-clear);
- the `DAT_<prefix>` distinct count **dropped by exactly the number applied**.

Re-grep to confirm. Never report done from the edit alone.

## Common mistakes / red flags

- "I'll re-investigate every proposal to be safe" → doesn't scale, defeats the parallel agents. Trust cited evidence + spot-check + gate.
- Appending a row for an address **already in the CSV** → duplicate-address row. Edit in place.
- Blanket-declaring `word` for IN-WINDOW (`0x3F9800–0x3FDB30`) symbols → a `word` over a true byte overlaps its neighbor and BOTH names vanish from the render. Use the TRUE width (byte stays `byte`); only a custom `dword` widening may revert to `word`.
- `_cal` because neighbors have it → gate on the memory map, not vibes.
- "Names are in the CSV" ≠ done. Only the render check (present + no underscores + count drop) proves it.

## Tools

`firmware/scripts/`: `extract_variable_context.py` (worklist batches), `disasm_func.py` (width-check, incl. indexed `lbzx`), `xref_addr.py` (whole-binary accesses + read-only detector), `audit_widths.py` (pointer/width-mistype lint), `audit_cal_suffixes.py` (`_cal` sweep).

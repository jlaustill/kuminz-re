# Cross-Firmware RAM Variable Naming Campaign

**Date:** 2026-03-07
**Priority:** Accuracy > Consistency > Volume

## Goal

Name unnamed `DAT_` RAM variables in both CM550 (J90350.00) and CM848D (S90140.06) decompiled output with consistent names across firmwares. Over time this reveals what is identical, unique, or evolved between ECU generations.

## Current State

| Metric | CM848D | CM550 |
|--------|--------|-------|
| RAM address range | 0x0040xxxx | 0x0080xxxx |
| Unnamed RAM DAT_ in decompiled | 159 | 1,917 |
| Already-named variables | 4,404 | 5,242 |
| Shared variable names | 19 meaningful |

## Scope: RAM Variables Only

RAM variables represent live engine state (RPM, sensors, flags, accumulators). They appear in the most functions and are the strongest basis for cross-firmware matching. ROM-to-RAM constants and Bank 2 data are deferred to a later campaign — well-named RAM variables make those easier.

## Tiers by Reference Count

| Tier | Refs | CM550 | CM848 | Approach |
|------|------|-------|-------|----------|
| 1 | 10+ | 176 | 1 | Full function bodies, high confidence expected |
| 2 | 5-9 | 332 | 20 | Good context, most nameable |
| 3 | 3-4 | 361 | 27 | Stretch goal, some will be skippable |
| Skip | 1-2 | 1,048 | 111 | Not enough evidence, don't attempt |

**Target: Tier 1+2 = 508 CM550 + 21 CM848 variables.**

## Context Extraction (Per Variable)

For each unnamed DAT_, extract:
- Every function that references it (full function body)
- The function's name (named functions give domain hints)
- Co-occurring named variables in same expressions

More context than the prior CM848 naming campaign (which used 2 lines before/after). Necessary for accuracy.

## Agent Structure

- **Batches of ~30 variables** (smaller than prior 50-80, deeper context per variable)
- Each agent receives: all function bodies referencing its batch of variables
- Each agent outputs: `address, proposed_name, confidence (high/medium/low), reasoning`
- **Only high-confidence names applied automatically.** Medium-confidence goes to review list.

## Execution Order

### Phase 1: CM550 Tier 1 (176 variables, 10+ refs)

1. Extract context for all 176 variables
2. Split into ~6 batches of ~30
3. Dispatch parallel agents
4. Collect results, apply high-confidence names
5. Re-export decompilation to verify

### Phase 2: CM550 Tier 2 (332 variables, 5-9 refs)

Same process, ~11 batches of ~30.

### Phase 3: CM848 Remaining (21 variables, 5+ refs)

Small enough for 1 batch. Use CM550 newly-named variables as soft reference.

### Phase 4: Cross-Firmware Validation

1. For each newly-named CM550 variable, search CM848 for same name
2. Check if functions using them are equivalent (shared name or scheduler position)
3. Produce `cross_firmware_variable_map.csv`:
   - `cm550_address, cm848_address, name, match_confidence, evidence`
4. Report: confirmed matches, name collisions, firmware-unique variables

### Phase 5 (Stretch): Tier 3 (388 variables, 3-4 refs)

Only if Tier 1+2 quality is satisfactory.

## Output Artifacts

- Updated `global_variables.csv` for both firmwares
- `docs/cross_firmware_variable_map.csv` - matched variables across firmwares
- Skipped variables remain as `DAT_` for future passes

## Agent Prompt Template

```
You are naming unnamed RAM variables in Cummins ECU firmware decompiled output.

RULES:
- Accuracy is the top priority. A wrong name is worse than no name.
- Use camelCase with underscores (e.g., fuel_demand_filtered, sensor_channel3_raw)
- Use decimal in names, not hex
- If you cannot confidently determine what a variable does, mark confidence as "low" and skip it
- Base names on HOW the variable is used, not just where it appears

For each variable, output one CSV line:
address,proposed_name,confidence,reasoning

Confidence levels:
- high: Clear from multiple usage contexts what this variable represents
- medium: Likely correct but only 1-2 strong contextual clues
- low: Uncertain, skip naming

CONTEXT:
[function bodies referencing the batch of variables]
```

## Naming Conventions (from existing named variables)

Common domain prefixes observed in both firmwares:
- fuel_demand_, fuel_limit_, fuel_timing_
- engine_speed_, engine_state_, engine_mode_
- throttle_position_, throttle_
- boost_pressure_, boost_
- governor_speed_, governor_mode_
- sensor_channel_, sensor_
- protection_, fault_, diagnostic_
- j1939_, can_message_
- timing_, rpm_, temperature_

# Brief: verify rename leads in the CM848 firmware (read-only research)

The CM848 engine controller firmware (PowerPC MPC555, 2004 Dodge Ram 5.9 L common rail) is decompiled in
`firmware/CM848_S90140.06_analysis/output/cm848_rom.ghidra.cpp` (repo root:
/home/linux/code/kuminz-re/.claude/worktrees/cm848-typing-arrays). Each function starts with a line
`// Function: <name> @ <address>`; use grep -n and sed -n. A table-naming campaign (2026-11-16) found that many
functions and variables near the lookup tables are named for the wrong system. Your task lists those LEADS. A lead
is a claim, not a fact: verify each one from the code.

READ-ONLY: do not edit any CSV or repo file, do not run `./analyze.sh` or Ghidra, do not change git state. Write
your answers only to your result file.

## Files
- Decompiled C (above). The lookup tables now have names that say what they hold (`pilot_quantity_map_1_grid`,
  `fuel_pressure_setpoint_coolant_limit_grid`, ...): use them as evidence.
- `firmware/CM848_S90140.06_analysis/output/global_variables.csv` (address,name,type,comment),
  `function_renames.csv` (address,name,plate comment), `structure_definitions.csv`.
- `firmware/CM848_S90140.06_analysis/docs/table_naming_campaign_2026-11-16.csv`: every table's traced input,
  output and evidence.
- `firmware/CLAUDE.md`: subsystem notes (grep it). Helpers, run from the repo root:
  `python3 firmware/scripts/xref_addr.py 0x<address>` (every access in the whole binary),
  `python3 firmware/scripts/disasm_func.py <function name or 0xaddress> [0xdata_address]`.
- Scales: engine speed 0.125 rpm; fuel quantity 0.0679 mm3 per stroke; rail pressure 0.0488 MPa; temperature
  1/64 deg F; pressure 0.0159 inHg; injection timing 0.1171875 deg; Q12 factors 4096 = 1.0.

## For each function lead
1. Read the function, its caller(s) and the consumers of what it writes. Decide: `confirmed` (the lead's claim
   holds), `rejected` (it does not; say what the function does instead, if you can), or `uncertain`.
2. Propose a new name only for confirmed (or corrected) functions: `cm848_` + camelCase verb phrase
   (`cm848_calculateAuxiliaryInjectionTiming`, `cm848_monitorFuelMeteringFeedback`). Keep the existing name when it
   is already right.
3. Write a plate comment (1-3 sentences, plain, factual) that replaces the old one: what the function computes,
   its inputs and outputs, and `(was <old name>)`. Keep facts from the old plate comment that still hold.

## For each variable lead (and other clearly misnamed globals inside your functions, at most 10 per function)
- Verify from the reads and writes. Propose `snake_case` names, major concept first, spelled out.
- Only globals in `global_variables.csv` (give the address and the exact current name). Do NOT propose struct
  field renames or type changes; list those as `note` lines instead.
- `_cal` ONLY for an EEPROM-backed value: an address in 0x3fd482-0x3feec1. Never `_cal` elsewhere; keep a
  correct existing `_cal` there.

## Rules for every name
- No invented abbreviations (spell out temperature, pressure, quantity, correction, auxiliary, ...). Allowed:
  rpm, adc, pwm, j1939, can, id, egr, obd, max, min, tpu, pid, pgn, spn, erc1, tsc1, eec2.
- Decimal numbers only, no hex in names. No bare `protection` (protection of what).
- A new name must not already exist in `function_renames.csv` / `global_variables.csv` / `arrays.csv`.
- When the evidence is not enough, say `uncertain` and give no new name. A wrong rename is worse than none.

## Result file: JSONL, one object per line
{"kind": "function", "address": "0x005279d8", "old": "cm848_auxiliary_boundary_condition_eval", "verdict": "confirmed", "new": "cm848_calculateAuxiliaryInjectionTiming", "plate_comment": "...", "evidence": "one or two sentences"}
{"kind": "global", "address": "0x0040b830", "old": "injection_timing_aux_offset", "verdict": "confirmed", "new": "auxiliary_injection_timing_command", "evidence": "..."}
{"kind": "note", "text": "struct field rpm_governor_state_t.commanded_rpm is the wastegate duty / 2 (...)"}
- verdict is confirmed / rejected / uncertain; `new` only with confirmed (or rejected with a better reading).
- Budget: about 60 tool calls. Final message: a short summary (confirmed / rejected / uncertain counts).

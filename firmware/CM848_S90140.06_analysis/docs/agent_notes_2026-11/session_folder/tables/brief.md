# Brief: name CM848 lookup tables (read-only research)

You are naming calibration lookup tables in the decompiled firmware of a Cummins CM848 engine controller
(PowerPC MPC555, 2004 Dodge Ram 5.9L). Work only from the files below. This is READ-ONLY research:
- Do NOT edit any CSV or repo file, do NOT run `./analyze.sh` or Ghidra, do NOT run git commands that change anything.
- Write your answers ONLY to the result file named in your task.

## Files (repo root = /home/linux/code/kuminz-re/.claude/worktrees/cm848-typing-arrays)
- Your bin: given in your task (JSON). `assigned_tables` = the table addresses you name. `lookups` = every
  interpolator call ("lookup") that uses one of them, with the call statement, its input argument(s), and the
  table contents (axis breakpoints, 1-D values, grid range / first and last row) read from the firmware images.
- Decompiled C: `firmware/CM848_S90140.06_analysis/output/cm848_rom.ghidra.cpp`. Each function starts with a
  line `// Function: <name> @ <address>`; find it with grep -n and read the body with sed -n.
- Named globals: `firmware/CM848_S90140.06_analysis/output/global_variables.csv` (address,name,type,comment).
- Subsystem notes: `firmware/CLAUDE.md` (grep it for the variable or subsystem you are tracing).
- Read-only helpers: `python3 firmware/scripts/xref_addr.py <address>` (every access to an address in the
  whole binary, with the name it renders as), `python3 firmware/scripts/disasm_func.py <function name or 0xaddress>
  [0xdata_address]` (the disassembly, optionally only the lines touching one data address). Run them from the
  repo root.

## What a lookup is
- `lookupTableInterpolation(&cache, x_input, x_axis, values, flags)` and
  `cm848_interpolateTableWithoutCache(x_input, x_axis, values)`: 1-D. x_axis = byte-length word + ascending
  breakpoints; values = byte-length word + one output per breakpoint. The result is the interpolated output.
- `cm848_dualAxisTableInterpolation(&cache, x_input, x_axis, y_input, y_axis, grid, flags)`: 2-D. grid =
  nx * ny outputs, no header, read as grid[(y - 1) * nx + x - 1].
- Sensor channel calls (`sensorChannelConfigInit` etc.): x_axis = ADC counts (0..1023), values = the
  engineering value; argument 7 = ADC channel index, argument 10 = where the value is written.
- WORD_ARRAY_<address> in the C is an unnamed table. The type is already correct: do not propose types.

## Your job, per lookup that holds one of your assigned tables
1. Trace the INPUT(s): what quantity is x_input (and y_input)? Follow locals back to named globals.
2. Trace the OUTPUT: where does the result go and what does that consumer do with it? Read the code after
   the call, and the consumers of the destination variable if its name is vague.
3. Check the table contents fit: breakpoints must be plausible in the input's units, values in the
   output's. Known scales: engine speed 0.125 rpm/count (800 rpm = 6400); pedal / percent 0.25 %/count
   (0..400); boost 0.0159 inHg/count; times are often 5 ms ticks. Say what you checked.
4. Decide: give a BASE name, or skip.

EVIDENCE RULE: give a name only when the input and the output both trace to named symbols (or to a computation
you can describe), and the breakpoints fit the input. Otherwise skip, and the table stays WORD_ARRAY_. A skip is
a good answer; an invented name is a bad one.

## Name grammar (the suffix is added for you, never add it yourself)
- You return a BASE only. 1-D lookups become `<base>_axis` + `<base>_values`; 2-D lookups become
  `<base>_x_axis` + `<base>_y_axis` + `<base>_grid`.
- The base names what the table produces, in its subsystem: usually the destination variable's name when that
  name is good (the result of lookup X is stored in `torque_limit_timing_warmup_correction` -> base
  `torque_limit_timing_warmup_correction`). If two lookups feed the same output (if / else branches), make the
  bases differ by what differs (`..._by_coolant_temperature` vs `..._by_coolant_and_intake_temperature`, or the
  branch condition).
- If the destination name looks WRONG for what the code does, do not copy it: name the table by what it does and
  explain in `naming_concern`.
- An assigned table that is shared by lookups with different partner tables (see `shared_by_lookups`) gets its
  own name: return a `shared_base` for it that names its input quantity and subsystem
  (`torque_limit_engine_speed` -> `torque_limit_engine_speed_axis`).
- lowercase snake_case, at most 48 characters, decimal numbers only.

## Bans (hard)
- NO `_cal` suffix or word: none of these tables are EEPROM-backed. Many existing names end in `_cal`; that is
  legacy, do not imitate it.
- NO invented abbreviations. Spell words out: temperature (not temp), pressure, position, correction,
  coefficient, threshold, injection, quantity. Allowed: rpm, adc, pwm, j1939, can, id, egr, obd, max, min.
- NO hex or addresses in a name. NO bare `protection` (say protection of what: rpm / coolant / oil / load).
- Do not reuse a name already in global_variables.csv (check `grep -c ',<name>,'` for each composed name).

## Result file: one JSON object per line (JSONL), nothing else in the file
{"lookup": "L170", "base": "cam_timing_correction_time_constant", "input": "fuel_pressure_feedback_filtered (rail pressure feedback, filtered)", "output": "cam_timing_correction_time_constant -> filter constant in ...", "units_check": "breakpoints 511..3276 ...", "confidence": "high", "evidence": "one or two sentences", "naming_concern": ""}
{"lookup": "L171", "skip": true, "reason": "input is an unnamed local computed from ..., cannot tell its units"}
{"table": "0x0006xxxx", "shared_base": "torque_limit_engine_speed", "evidence": "..."}
- One line per lookup that holds an assigned table (named or skipped). confidence is "high" or "medium";
  anything lower is a skip.
- Final message: a short summary (lookups named / skipped, any naming concerns). Your result file is what counts.

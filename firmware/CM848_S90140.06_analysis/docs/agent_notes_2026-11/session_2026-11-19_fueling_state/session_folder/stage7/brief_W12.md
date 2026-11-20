# Rename wave 12 (CM848): name the e2m records the ECU's parameter ID table resolves

Read-only research plus ONE output file. Do not edit any repository file, do not run `analyze.sh`, do not commit.
Write your results only to the result file named in your prompt.

## What is already proved
The CM848 carries its own e2m record -> address table. `cm848_lookupParameterIdAddress` searches 6-byte records
[e2m block id][address] in flash2. Each record in your bin sits at its `address`; that identity is not in question.
Two risks remain:
- **layout drift:** the labelled e2m is calibration 11.45 and the truck runs 11.46.06, so an offset inside a block may
  have moved;
- **naming quality.**

Each record in your bin has no name yet. The code uses it as `label_in_cpp` (a `DAT_<address>` label), and its dump
value is inside the record's min..max.

## Files
- Your bin: a JSON list (path in your prompt). Each item has:
  - the record: `record`, `unit`, `size_bytes`, `signed`, `scale`, `min`, `max`, `description`;
  - the code context: `code` (up to 4 lines that use the label, `function: line`) and `access_widths` (the load /
    store census; "none" means the census could not see the access);
  - `block_named_rows`: the same block's records that already have names, with a word-overlap score. Use them for
    naming consistency and as a drift check;
  - `region` (it decides `_cal`), `current_row` (`none` or `unnamed`) and `other_records_at_this_address`.
- Decompiled code: /home/linux/code/kuminz-re/.claude/worktrees/cm848-fueling-state-enum/firmware/CM848_S90140.06_analysis/output/cm848_rom.ghidra.cpp
  and the CSVs next to it (global_variables.csv: address,name,type,comment).
- Helpers (python3):
  - /home/linux/.claude/jobs/f6a06670/tmp/fueling_state/fnbody.py `<cpp> name:maxlines`;
  - .../width_census.py `<all.dis> 0xADDR` (all.dis is in the same folder);
  - /home/linux/code/kuminz-re/.claude/worktrees/cm848-fueling-state-enum/firmware/scripts/e2m_block_addresses.py
    `BLOCK` or `--address 0xADDR` (all records of a block with their addresses and current names).

## Per record
1. **Read the code lines.** Open the function when the line alone does not show the role. Check that the use fits
   the record: a flag compared with 0 / 1, a temperature compared with temperatures, a timer counted, a calibration
   only read, a table index used as one.
2. **Check the width.** The record's size (1 / 2 / 4 bytes) must match the access widths when the census shows them.
3. **Name it** in snake_case from the record name and description, following the rules below. Keep the block's
   conventions: a sibling named `air_handling_system_protection_*` means this one gets that prefix too.
4. **Give a verdict:**
   - `confirmed`: the use fits and the width matches;
   - `uncertain`: you cannot tell, or the use only weakly fits;
   - `rejected`: the use contradicts the record (drift), or the width disagrees. Say why.
   A wrong name is worse than no name.

## Naming rules
- Spell words out. No invented abbreviations. Allowed as written: rpm, j1939, pgn, spn, dtc, obd, ecm, egr, nox,
  id, adc, pwm, can, pid, tpu, qadc, vin.
- The `C_` (calibration) and `T_` (trim) prefixes only say "setting": drop them. `_cal` is decided by the region
  alone. In the EEPROM mirror (0x3fd482-0x3feec1) the name ends `_cal`; everywhere else it never does.
- Translate the Cummins abbreviations:
  - **Basic words:** Tmptr / Temp = temperature; Thd = threshold; Cmd = command; Amb = ambient; Ref = reference;
    Avg = average; Frac = fraction; Adj = adjustment; Cnt = count; Ctr = counter; Lmt / Lim = limit; Sw = switch;
    Stat = status; Val = value; Pos = position; Filt = filtered; Diag = diagnostic; Ovr = override; Vlv = valve;
    Pct = percent; Cyl = cylinder; Max / Min = maximum / minimum.
  - **Engine terms:** Inj = injection or injector (from context); SOI = start of injection (the repo writes
    `injection_timing`); Veh = vehicle; Baro = barometric; Alt = altitude; Trq = torque; Batt = battery;
    IMT = intake_manifold_temperature; CT = coolant_temperature; APS = accelerator_pedal; Accel = accelerator or
    acceleration (from context); Decel = deceleration.
  - **Systems:** COT = compressor_outlet_temperature; MCF / CMF = charge_mass_flow; VGT =
    variable_geometry_turbocharger; PTO = power_take_off; CC = cruise_control; EB = engine_brake; Jcomm = j1939;
    EL = emission_level.
  - **Governors:** LSG / HSG / ASG / VSG = low / high / all / variable speed governor.
  - **AECD** = auxiliary emission control device. Follow the repo's `<condition>_protection_*` family
    (`condensation_protection_active_flag`) rather than spelling the acronym.
- Module prefixes (EMO_, EMM_, CBR_, CBO_, FSS_, ...) are Cummins-internal. Use the words the rest of the block uses
  in its existing names, or drop the prefix when the remaining words are specific enough.
- Never a bare "protection": say protection of what.
- Use initialize, never init. Numbers in decimal.
- Flags end `_flag`; counters `_count` / `_counter`; timers `_timer`.
- The new name must not already exist (grep global_variables.csv and the .cpp). Two records in your bin must not get
  the same name.

## Types
- Use the record's size: 1 = `byte`, 2 = `word`, 4 = `dword`.
- Use `i16` only when the record is signed (S) and every access in the census is `lha`.
- If the census width disagrees with the record's size, reject the record and say so.

## Output: one JSON object per line, one line per record of your bin (rejected ones too)
- `current_row` `none`: `{"kind": "new_global", "verdict": ..., "address": "0x...", "new": "...", "type": "word",
  "evidence": "...", "comment": "..."}`
- `current_row` `unnamed`: `{"kind": "global", "verdict": ..., "address": "0x...", "old": "", "new": "...",
  "evidence": "...", "comment": "..."}`
- `evidence`: one line, for example `e2m 1997 +0E EMO_Air_Handling_COT_Limit (DEG_F, 1/64): compared with the
  compressor outlet temperature in cm848_checkAirHandlingSystemNearLimits; lhz; dump 13440`.
- `comment`: the CSV comment for the row. Lead with the e2m record and its description, then the role in the code.
  Include the dump value in engineering units when it helps (`(2048 = 2.0 here)`).

Finish with a short summary in your final message: counts per verdict, and the drift / width problems found.

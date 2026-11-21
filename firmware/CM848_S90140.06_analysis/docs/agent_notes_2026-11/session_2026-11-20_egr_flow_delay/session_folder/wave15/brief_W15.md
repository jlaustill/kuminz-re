# Rename wave 15 (CM848): review names that disagree with their e2m record

Read-only research plus ONE output file. Do not edit any repository file, do not run `analyze.sh`, do not commit.
Write your results only to the result file named in your prompt.

## Background
- The CM848 carries its own e2m record -> address table: `cm848_lookupParameterIdAddress` searches 6-byte records
  [e2m block id][address] in flash2. Every record in your bin sits at its `address`.
- That address already has a name, and the name shares few or no words with the record (`token_overlap` 0 to 0.2 =
  the share of the record's words that the name contains; an abbreviation such as `temp` for Temperature counts as no
  match). Usually one of three things is going on:
  1. **Synonym (keep):** the name is accurate, only worded differently. `key_on_hour_meter` for ECM_Run_Time,
     "Time key switch is on and ECM is running", stays.
  2. **Misname (rename):** the name describes something else. Examples from earlier waves: `boost_*` on an exhaust
     pressure estimate; `diag_dm1_*` on the data collector; `protection_*` on a monitor's parameters; `fuel_demand_*`
     on the pumping torque; a `_cal` on a ROM constant.
  3. **Drift (no change):** the labelled e2m is calibration 11.45 and the truck runs 11.46.06. A record can sit at a
     shifted offset, so the code use contradicts the record, and the current name, based on the code, may be right.
     Known drift: 10E3 / 1228, 8A2B / 8A37, 8A14 (+2C on), 1930 (+12 on), 1902 (+2A..+2E), 1253, 8D14 (from +2), 1B2D
     (from +4), 1966 (from +94), 1649 (from +10); the 8C58 tail overlaps 8C4E.
- Many current names came from careful earlier work. Their comments often hold proved facts. Read the comment before
  you judge the name.
- Most of these rows have only 1-2 code references (earlier waves did the busier ones), so read the functions: one
  line is rarely enough.
- Rows with a partial overlap are often synonyms or a rule break (an abbreviation) rather than a misname: judge the
  meaning first, then the rules.

## Files
- Your bin: a JSON list (path in your prompt). Each item has:
  - the record: `record`, `unit`, `size_bytes`, `signed`, `scale`, `min`, `max`, `description`;
  - the current row: `label_in_cpp` (the current name), `current_row_type`, `current_comment`;
  - the code context: `code` (up to 4 lines that use the name) and `access_widths` (displacement-form loads / stores);
  - `region` (it decides `_cal`), `block_named_rows` (the block's named rows with their word-overlap scores) and
    `other_records_at_this_address`;
  - sometimes `earlier_verdict`: an earlier wave's note on this address. `global_worklist_later.json` means wave 14
    deferred the row unreviewed; a `keep` / `confirmed` line is an earlier judgement to start from (agree or explain).
- Scratch: put any script you write in your own folder `/home/linux/.claude/jobs/374b0424/tmp/w15/agent_scratch/bin<k>/`
  (k = your bin number) and run it as `python3 <file>`. Do not use heredocs or long compound shell commands: the
  sandbox refuses many of them.
- Decompiled code (the current state of this branch):
  /home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM848_S90140.06_analysis/output/cm848_rom.ghidra.cpp
  and the CSVs next to it (global_variables.csv: address,name,type,comment).
- Helpers (python3):
  - /home/linux/.claude/jobs/374b0424/tmp/w15/fnbody.py `<cpp> name:maxlines` prints a function body;
  - /home/linux/.claude/jobs/374b0424/tmp/w15/width_census.py `/home/linux/.claude/jobs/374b0424/tmp/w15/all.dis 0xADDR`;
  - /home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/scripts/xref_addr.py `0xADDR` (every
    function that accesses the address, with each load / store instruction);
  - /home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/scripts/e2m_block_addresses.py `BLOCK`
    or `--address 0xADDR` (the whole e2m block with the current names).

## Per record
1. Read the current comment and the code that uses the name. Open the function when the line alone does not show the
   role.
2. Decide which case it is:
   - **keep:** the current name is accurate. A synonym, or more specific than the record, is fine.
   - **rename:** the current name is wrong or misleading for what the code does, and the record matches the code. A
     name that breaks a rule also gets a rename, even when its meaning is right: an invented abbreviation (temp, cnt,
     ref, val, calc, init, cfg, coef ...), or a wrong `_cal` (`_cal` only in the EEPROM mirror 0x3fd482-0x3feec1).
   - **drift:** the record does not match the code at this address. Leave the name; say what the code shows.
   - **uncertain:** you cannot tell.
3. For a rename, name it in snake_case from the record name and description (the rules below). Keep the accurate
   specifics of the current name and comment, such as units, direction and which monitor or message. Rename a misnamed
   family in your bin consistently: siblings with the same wrong prefix get the same new prefix. Look at the
   block's other rows (`e2m_block_addresses.py BLOCK`) so the new name fits its neighbours.

## Naming rules
- Spell words out. No invented abbreviations. Allowed as written: rpm, j1939, pgn, spn, dtc, obd, ecm, egr, nox, id,
  adc, pwm, can, pid, tpu, qadc, vin, tsc1, vss.
- Drop the e2m `C_` / `T_` prefixes. `_cal` is decided by the region alone: in the EEPROM mirror the name ends `_cal`,
  everywhere else it never does.
- Cummins abbreviations:
  - **Basic words:** Tmptr = temperature; Thd = threshold; Cmd = command; Amb = ambient; Ref = reference;
    Avg = average; Frac = fraction; Adj = adjustment; Cnt = count; Lmt / Lim = limit; Sw = switch; Val = value;
    Pos = position; Filt = filtered; Diag = diagnostic; Ovr = override; Vlv = valve; Pct = percent; Cyl = cylinder;
    Est = estimate; Press = pressure; Spd = speed; Accel = acceleration; Hyst = hysteresis.
  - **Engine terms:** Inj = injection or injector; SOI = start of injection (the repo writes `injection_timing`);
    Veh = vehicle; Baro = barometric; Alt = altitude; Trq = torque; Batt = battery; IMT =
    intake_manifold_temperature; CT = coolant_temperature; APS = accelerator_pedal; ICP = charge_pressure.
  - **Systems:** COT = compressor_outlet_temperature; MCF / CMF = charge_mass_flow; VGT =
    variable_geometry_turbocharger; PTO = power_take_off; CC = cruise_control; EB = engine_brake; Jcomm = j1939;
    EL = emission_level; TPE = the estimate module (no word needed); CHP = the charge flow model (no word needed).
  - **Governors:** LSG / HSG / ASG / VSG = low / high / all / variable speed governor.
  - **AECD:** use the repo's `<condition>_protection_*` family.
- Module prefixes (EMO_, CBR_, FSS_ ...) are Cummins-internal: use the words the block's other names use.
- Never a bare "protection": say protection of what. Use initialize, never init. Numbers in decimal.
- The new name must not exist anywhere yet (grep global_variables.csv and the .cpp). No two rows may get one name.
  Names this branch created recently (do not reuse): `exhaust_pressure*`, `charge_pressure_estimate*`,
  `engine_speed_state.*`, `average_engine_speed`, `main_engine_speed`, `backup_engine_speed`, `egr_valve_delta_pressure`,
  `engine_delta_pressure`, `pumping_torque_*`, `nominal_engine_delta_pressure*`.

## Output: one JSON object per line, one line per record of your bin
- **rename:** `{"kind": "global", "verdict": "confirmed", "address": "0x...", "old": "<current name>", "new": "...",
  "evidence": "...", "code_quote": "<function name>: <one line copied verbatim from the .cpp>", "comment": "..."}`
  - `code_quote` is required: one line of the decompiled code that uses the row and shows the role you name, copied
    exactly (it is checked against the .cpp), with the function it is in.
  - The `comment` is the full new CSV comment. Lead with the e2m record and its description, then the role in the
    code. Keep the old comment's proved facts. Do not add "(was ...)": the apply adds it.
- **keep:** `{"kind": "global", "verdict": "keep", "address": "0x...", "old": "<current name>", "new": "<same>",
  "e2m_note": "e2m <block> +<offset> <record> '<short description>'"}`. The note is appended to the comment, as a
  cross-reference.
- **drift:** `{"kind": "global", "verdict": "drift", "address": "0x...", "old": "<current name>", "evidence": "<what the
  code shows vs the record>"}`
- **uncertain:** `{"kind": "global", "verdict": "uncertain", "address": "0x...", "old": "<current name>", "evidence":
  "..."}`
- `evidence`: one line with code function names and line facts, for example `e2m 1772 +A Exhaust_Press_Est (IN_HG):
  written by cm848_estimateExhaustPressure as the exhaust pressure estimate; the old name said boost`.
- Do not change types. If a type looks wrong (width or signedness against `access_widths` / the record's `signed`),
  say so in the evidence.

Finish with a short summary in your final message:
- counts per verdict;
- the families you renamed;
- drift found;
- any function whose name your evidence shows is wrong (address, current name, proposed name, one-line reason). These
  are not applied automatically;
- out-of-bin siblings: rows outside your bin that share a wrong prefix you renamed (address, current name, why it
  belongs to the family), so the family does not end half-renamed.

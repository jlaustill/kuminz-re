# Rename wave 14 (CM848): the function misnames and the sibling rows left by wave 13

This is read-only research with ONE output file. Do not edit any repository file, run `analyze.sh`, or commit.
Write your results only to the result file named in your prompt.

## Background
- **Waves 12 and 13** renamed about 600 globals from the CM848's own e2m record -> address table
  (`cm848_lookupParameterIdAddress`: 6-byte records [e2m block id][address] in flash2). For example:
  - the data collector (`data_collector_*`, was `diag_dm1_*`);
  - the PGN 65251 torque curve words;
  - alpha, the all-speed governor, the 48RE converter clutch / governor pressure monitors, cylinder balance;
  - the HPCR gain records (`fuel_pressure_governor_*_gains`, structs).
- **The leads.** The wave-13 agents also found functions whose names are wrong, and sibling rows they could not
  rename. Your bin holds those leads. A lead is a hint, not a fact: verify it in the code.
- **The labelled e2m is calibration 11.45; the truck runs 11.46.06.** A record can sit at a shifted offset (drift),
  and then the code use contradicts the record. Known drift: 10E3 tail / 1228, 8A2B / 8A37, 8A14 (+2C on), 1930 (+12
  on), 1902 (+2A..+2E), 1253, 8D14 (+2 on), 1B2D (+4 on), 1966 (+94 on), 1649 (+10 on). The 8C58 tail overlaps 8C4E.
- **Read the current comment or plate before you judge.** Many hold proved facts from earlier work.

## Files
- Decompiled code: /home/linux/code/kuminz-re/.claude/worktrees/cm848-fueling-state-enum/firmware/CM848_S90140.06_analysis/output/cm848_rom.ghidra.cpp
- The CSVs next to it:
  - global_variables.csv: address,name,type,comment;
  - function_renames.csv: address,name,plate;
  - enums.csv;
  - structure_definitions.csv.
- CM550 (the other firmware): /home/linux/code/kuminz-re/.claude/worktrees/cm848-fueling-state-enum/firmware/CM550_J90350.00_analysis/output/function_renames.csv
  and /home/linux/code/kuminz-re/.claude/worktrees/cm848-fueling-state-enum/firmware/cross_firmware_matches.csv
- Helpers (python3):
  - /home/linux/.claude/jobs/f6a06670/tmp/fueling_state/fnbody.py `<cpp> name:maxlines` prints a function;
  - .../width_census.py `<all.dis> 0xADDR` gives the access widths; all.dis is in the same folder;
  - /home/linux/code/kuminz-re/.claude/worktrees/cm848-fueling-state-enum/firmware/scripts/e2m_block_addresses.py
    `BLOCK` or `--address 0xADDR` gives the table-resolved e2m records;
  - the six wave-13 reports (the leads come from them):
    /home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage8/reports/*.md
  - what waves 13 / 8c renamed (`address,name,old_label,kind`); families span blocks, so check these:
    /home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage8/map_stage8.csv and .../stage8/map_stage8c.csv

## Naming rules (all items)
- **Spell words out.** No invented abbreviations. Allowed as written: rpm, j1939, pgn, spn, dtc, obd, ecm, egr, nox,
  id, adc, pwm, can, pid, tpu, qadc, vin, tsc1. In camelCase they are written Rpm, J1939, Pgn, Egr, Tpu, ...
- **Always** use initialize (never init) and calculate (never calc). Never use a bare "protection": say protection of
  what. Numbers are decimal (PGN 65251, not 0xFEE3).
- **`_cal` (globals)** is decided by the region alone. In the EEPROM mirror 0x3fd482-0x3feec1 the name ends `_cal`;
  everywhere else it never does.
- **Uniqueness.** A new name must not exist yet: grep the CSVs and the .cpp. No two items may get one name.
- **Families.** Rename a family consistently, and follow the names wave 13 gave its siblings (`block_named_rows` lists
  them).

## Function items (bins functions1-3)
Each item has:
- `current`, `current_plate`, `callers`, `callees`, `body_lines`;
- `proposals`: names the wave-13 agents suggested, each with its reason and source report. Some items have none.
- `shared_with_cm550` (precomputed): the current name also appears in CM550's CSVs or the cross-firmware map. Judge the
  function as usual; the main session holds shared renames.
- `user_review_note` (on three items): the owner's own signed review of the current name. Copy it verbatim at the end
  of your plate. The main session shows any rename of these to the owner and does not apply it on its own.
A proposal is a hint. Most items come with one, so the temptation is to confirm it. Decide from the code; a better
name or a keep is a fine answer.

Steps:
1. Read the function (`fnbody.py`), its callers where needed, and the globals it reads and writes.
2. Decide:
   - **rename:** the current name is wrong or misleading, and you can say what the function does from the code.
     - The proposal may be right, or you may improve it.
     - Keep the module prefix: `cm848_` for CM848 code; `hpcr_` / `mpc555_` only when the current name already has it
       and it still fits. A legacy unprefixed or mixed name (`faultTimerHandler`, `governor_sourceData_init`) becomes
       `cm848_<camelCase>`.
     - Use the form `<prefix>_<verbObject>` in camelCase (`cm848_calculateFuelMeteringCommand`).
   - **keep:** the current name is accurate.
   - **uncertain:** you cannot tell.
3. Quote the deciding code: `code_quote` is one exact line (or a fragment of 20+ characters) of the function's body
   that shows what it does. The gate checks that the quote is in that function.
4. For a rename, also write a new `plate_comment` (the function's plate comment):
   - say what the function does, its inputs and outputs, and the e2m records it uses;
   - **keep every proved fact of `current_plate`**, rewriting only what your evidence shows is wrong;
   - do not add "(was ...)": the apply adds it.

## Global items (bins globals1-4)
These rows sit next to families that waves 13 / 8c renamed. Each item has:
- the current name / type / comment and the region;
- the access widths, up to 6 code lines, and `e2m_records_here` (the table-resolved records at this address);
- `block_named_rows`, and `report_leads` (what a wave-13 agent wrote about the row).

Decide:
- **keep:** the current name is accurate, or more specific than the record.
- **rename:**
  - the name is wrong or misleading, and the record or the code shows the right meaning; or
  - it breaks a rule: an invented abbreviation, or a wrong or missing `_cal`. Many rows here are only `_cal` fixes.
- **drift:** the record does not match the code. Leave the name and say what the code shows.
- **uncertain:** you cannot tell.

Some rows have no e2m record here (`e2m_records_here` is empty). Name them from the code and the report lead, or say
uncertain.

**Width.** `covered_records` lists the e2m records inside the row. When `width_problem` is set, the row is a scalar
wider than its record, so one name covers several records. For example, a word over two 1-byte records renders the
second record as `(byte)name`. Then add `"split": [{"address": "0x...", "name": "...", "type": "byte|word|dword",
"comment": "..."}]`, one entry per covered record that the code uses. The main session applies splits by hand and
holds the plain rename.

## Checks (every rename)
- **Direction words** (minimum / maximum, upper / lower, positive / negative, enable / disable, high / low): confirm
  each against the deciding compare or use in the code, and quote it in the evidence.
- **Width:** if the row width differs from the e2m record size, or the code reads only part of the row, say so in
  `type_note`. Do not change types yourself; a `type_note` rename is held for the main session.
- **Quotes:** every global rename also carries a `code_quote`: one exact code line that uses the row and decides its
  meaning.
- **PGNs and P-codes:** a PGN, SPN or P-code in a new name must cite where you read it in the evidence. For example:
  the transmit header constant, or fault N -> ROM slot table 0x5985a -> obd_dtc_code_table.
- **Dump values:** quote dump values exactly as `dump_raw` gives them (raw, at the row's width). Write a scaled value
  as "N in the dump = X unit".
- **Old comments:** the apply keeps the old comment as an "earlier note". If your evidence shows that the old comment
  is wrong, set `"old_comment_wrong": true` and carry over its proved facts yourself.

## Output: one JSON object per line, one line per item of your bin (in bin order)
- **function rename:** `{"kind": "function", "verdict": "confirmed", "address": "0x...", "old": "<current>", "new":
  "...", "evidence": "...", "code_quote": "...", "plate_comment": "..."}`
- **function keep:** `{"kind": "function", "verdict": "keep", "address": "0x...", "old": "<current>", "new":
  "<same>", "evidence": "..."}`. A keep may carry a corrected `"plate_comment"`, which the apply writes.
- **function uncertain:** `{"kind": "function", "verdict": "uncertain", "address": "0x...", "old": "<current>",
  "evidence": "..."}`
- **global rename:** `{"kind": "global", "verdict": "confirmed", "address": "0x...", "old": "<current>", "new": "...",
  "evidence": "...", "code_quote": "...", "comment": "<full new CSV comment: the e2m record and its description, then
  the role in the code>"}`. Optional fields: `"type_note"`, `"split"` and `"old_comment_wrong": true`.
- **global keep:** `{"kind": "global", "verdict": "keep", "address": "0x...", "old": "<current>", "new": "<same>",
  "e2m_note": "e2m <block> +<offset> <record> '<short description>'"}`. Leave `e2m_note` empty when no record is here.
- **global drift / uncertain:** `{"kind": "global", "verdict": "drift" or "uncertain", "address": "0x...", "old":
  "<current>", "evidence": "..."}`
- The `evidence` field is one line of code facts: functions, compares, which records.

## The held enum rows (bin functions3 only: `held_enum_rows`)
Wave 13 found these two enum-typed rows misread:
- 0x40c04a `diagnostic_session_state` is the RAM refresh enable;
- 0x40aa9a `j1939_standby_flag` is the development mode.

Their enums (`DIAG_SESSION_STATE` / `J1939_STANDBY_STATE` in enums.csv) still follow the old reading. Re-read the code,
together with your bin's cm848_activateDiagnosticSession / cm848_resetDiagnosticSession /
cm848_forceActivateDiagnosticSession / cm848_initProtectionModule / uds_session_state_init. For each row, add one line:

`{"kind": "enum", "verdict": "confirmed" or "uncertain", "address": "0x...", "old": "<row name>", "new": "<row name>",
"enum_old": "...", "enum_new": "...", "members": [{"value": N, "old": "...", "new": "...", "comment": "..."}],
"comment": "<new row comment>", "evidence": "..."}`

Name the members after what each value does in the code. Keep the enum when it is still the right shape. A plain flag
may need no enum at all; then say so in the evidence.

## Finish with a short summary in your final message
- counts per verdict;
- the families you renamed;
- drift found;
- shared-name holds;
- any new leads outside your bin (address, current name, what the code shows).

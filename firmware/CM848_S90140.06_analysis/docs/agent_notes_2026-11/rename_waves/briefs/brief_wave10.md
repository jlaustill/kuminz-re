# Wave 10 addendum (read after brief.md and brief_wave9.md) - names that clash with the DTC a function sets

**Repo root for this wave (overrides brief.md):** `/home/linux/code/kuminz-re/.claude/worktrees/cm848-vehicle-speed-sensor-p0500`.
The `cm848-typing-arrays` worktree named in brief.md is stale. Do not read anything there.

**Where your leads come from: a DTC-code check.**
- Fault n is word n/16, bit n%16 of the `fault_detected_bits_<first>_to_<last>` words.
- ROM 0x5985a[n] (a big-endian u16) gives its slot, and `obd_dtc_code_table[slot]` (ROM 0x5b57c, BCD) gives the P-code.
  Slot 170 or above means the fault has no DTC.
- `firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-17_p0500/session_folder/fault_setters.py`
  lists the faults each function sets. Its output for HEAD is `fault_setters_origin_main.txt` in the same folder.
- **Worked example:** commit 64aaaa1 (`git show 64aaaa1`) renamed `diag_boostLoad_overtemp_monitor` to
  `cm848_detectVehicleSpeedSensorZeroUnderLoad` (P0500). Use its plate and global comments as the model for evidence
  and wording.

**The P-code is a hint, not proof.** The meanings in your task are generic SAE J2012 titles quoted from memory; no
DTC text table exists locally. Prove every rename from what the function reads and how it decides:
- the sensor, switch or signal it tests;
- its thresholds (read the ROM values with `python3 -I -c` on `originals/cm848_rom.bin`, big-endian);
- its counters and debounce;
- the fault's heal path.

If the logic does not fit the P-code, say so (`rejected` or `uncertain`).

**When to rename a function:** only when detecting (and / or healing) the fault is its whole job. If the fault is one
part of a bigger function, keep the name (or propose one that covers the whole job), name the fault's own state and
write a `note`.

**The unit is the monitor group:** the detector, the heal / clear function, the initializer and the caller that
schedules them.
- Find them by sweeping the monitor's state words:
  `python3 /home/linux/.claude/jobs/821efb84/tmp/sweep_addrs.py <repo>/firmware/scripts 0x<address>[,0x<address>...] /home/linux/.claude/jobs/821efb84/tmp/bank1.dis /home/linux/.claude/jobs/821efb84/tmp/bank2.dis`.
  It lists every load and store in both banks. `xref_addr.py` only scans functions whose `.cpp` text names the symbol.
- Grep the fault word with its mask to find the heal path. Fault 29, for example, is
  `fault_detected_bits_16_to_31 ... & 0xdfff`.

**New rows:** you may propose `new_global` rows for the unnamed ROM limits / RAM words the monitor uses:
`{"kind": "new_global", "address": "0x0005c964", "new": "...", "type": "word", "evidence": "... (lhz @ 0x526b54)"}`.
- Take the type from the load (`python3 firmware/scripts/disasm_func.py <function> 0x<data address>`): `lbz` = byte,
  `lhz` = word, `lha` = i16, `lwz` = dword.
- ROM, the copy window and working RAM get no `_cal`. The EEPROM mirror 0x3fd482-0x3feec1 gets `_cal`.

**Banned words** (the rename gate rejects them anywhere in a name): temp tmp press pos corr coef coeff thresh thr inj
qty ctrl cfg cmd val vals idx cnt num ref spd eng prot lim mult comp adj trq tbl lkp sw calc accel decel pct freq volt
amp deg sec diag cond req resp init tmr buf aux arb iat imt proc mgr util info stat msg.
- Write `diagnostic`, `initialize`, `pressure`, `temperature` and `auxiliary`.
- A pedal "press" is an `accelerator_off_idle_entry` / `application`.
- No bare `protection`.

**Output:** write ONLY your result file, `/home/linux/.claude/jobs/821efb84/tmp/wave10/result_W10_<group>.jsonl`.
Create no other files, and nothing under `/tmp`. Everything else is read-only: no CSV edits, no `./analyze.sh`, no git
changes.

**Budget:** about 80 tool calls. End with confirmed / rejected / uncertain counts and one line per lead.

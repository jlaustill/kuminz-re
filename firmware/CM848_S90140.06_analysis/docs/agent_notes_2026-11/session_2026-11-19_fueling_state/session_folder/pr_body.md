## Summary

`governor_fuel_demand_mode` (0x40a154) is an enum. It is the Cummins **FSGVFLST** governed fueling state: "indicator as to which algorithm is in control of fueling after it is governed", with the e2m range 1-12. Every fueling stage uses one shared numbering for its codes, so the enum is shared too. `ENGINE_OPERATING_MODE` is now **`FUELING_STATE`** and gains members 4 / 9 / 10 / 11 / 12. The carriers are typed with it, 0x40b67c is renamed, and the dword at 0x3fb526 is split.

`cm848_processProtectionRampControl` now reads as the arbitration it is:

```c
FVar1 = FUELING_STATE_HIGH_SPEED_GOVERNOR;            // was 0xc
...
governor_fuel_demand_mode = FUELING_STATE_LOW_SPEED_GOVERNOR;   // was 0xb
if ((governor_fuel_demand_mode == FUELING_STATE_CRUISE_CONTROL) ||
    (governor_fuel_demand_mode == FUELING_STATE_VEHICLE_SPEED_LIMIT)) {   // were 9 / 10
```

## Evidence (firmware first)

- **Access census.** I found 35 accesses in both banks, all 16-bit: 30 `lha`, 2 `lhz`, 3 `sth`. Every load feeds `cmpwi rX,K` or a plain copy. No load feeds arithmetic, a mask, an index or a `<` / `>` compare. Neither bank holds a 32-bit pointer to the word.
- **Writers.** Only the arbitration in `cm848_processProtectionRampControl` writes it: `li 10` / `li 12` / a pass-through at 0x40558 and `li 11` at 0x4061c. `cm848_initFuelFilterCoefficients` stores the initial 11 at 0x4083c.
- **Value chain.** `engine_operating_mode` → `operating_mode_governor_output.mode_code` (+4) → 0x40b67c (+9) → 0x40a154 (+10 / 11 / 12). The RAM dump reads 7 → 7 → 7 → 11.
- **One numbering, proved in the code.** `cm848_processProtectionSelection` writes either this word (1-12) or `torque_derate_fuel_source_code` (13, 20, ...) into one word, `governor_fuel_mode_arbitrated`.
- **CM550.** 0x0080a8f2 is e2m FSGVFLST (block 1045 +2). The shared `runHighSpeedGovernorPid` compares it with 12 in both firmwares.
- **e2m corroboration.** Blocks that line up by offset:
  - block 1045: FSGVFL / FSGVFLST / LSLOFG = 0x40a152 / 0x40a154 / 0x40a156;
  - block 1265: PTTHDQRP / PTTHOV / PTSLFL / PTSLFLST = 0x40af56 / 0x40af58 / 0x40af5a / 0x40af5c.

  The state ranges are FSDSFLST 1-8 / 38, FSGVFLST 1-12, FSLMFLST 13-41 and FSFNFLST 1-41.

| Value | Member | Basis |
|---|---|---|
| 0 1 2 5 6 7 8 30 | the existing members, renamed `FUELING_STATE_*` | code |
| 4 | `FUELING_STATE_POWER_TAKE_OFF` | code shows another governor's command replacing the user fueling; "power take-off" is **e2m-derived** (block 1265) |
| 9 | `FUELING_STATE_CRUISE_CONTROL` | code |
| 10 | `FUELING_STATE_VEHICLE_SPEED_LIMIT` | code (the limit fuel from `vehicle_speed` against `cruise_speed_limit_working`) |
| 11 | `FUELING_STATE_LOW_SPEED_GOVERNOR` | code (the max select; only in 11 does `cm848_processSpeedGovernorControl` write the governed fuel) |
| 12 | `FUELING_STATE_HIGH_SPEED_GOVERNOR` | code (the governed fuel = `high_speed_governor_fueling`) |

## Changes

- **`enums.csv`:** `ENGINE_OPERATING_MODE` → `FUELING_STATE`, plus the five new members.
- **Typed `FUELING_STATE`:**
  - `engine_operating_mode` and `engine_operating_mode_previous_pass`
  - `operating_mode_governor_output_t.mode_code`
  - 0x40b67c and 0x3fb526
  - `governor_fuel_demand_mode` and `governor_fuel_demand_mode_prev`
  - `cruise_fuel_demand_mode_prev`
- **Renamed:** 0x40b67c `governor_pid_integral_snapshot` → `governor_fuel_demand_working_mode`. It never holds a PID term.
- **Split:** the 0x3fb526 dword is now `governor_fuel_demand_working_mode_prev` (`sth` @ 0x40474) and `fuel_demand_enable_sync_flag_shadow` (word, `lhz` @ 0x4064c / `sth` @ 0x406b8).
- **Headers:** regenerated. The CM848 types and globals changed; CM550 is unchanged.
- **Docs:** `firmware/CLAUDE.md` has a new note, `work/tasks/045` holds the evidence and follow-ups, and the session's scratch work is in `docs/agent_notes_2026-11/session_2026-11-19_fueling_state/`.

## Checks

- A fresh baseline build equals the committed `.cpp` apart from the timestamp line.
- **Proof.** I ran `reverse_names.py`, then a stricter check (`check_enum_proof.py`) that normalizes members and numbers to values, the enum type to `word`, auto-named locals to placeholders, and the dword pieces to the new words. **One function is not label-only:** `cm848_processProtectionRampControl`. Its reused local (`wVar1`, first the state and later the fuel value) is now two locals, `FVar1` (`FUELING_STATE`) and `wVar2` (`word`). The values and the control flow are the same.
- Every `FUELING_STATE_` name in the `.cpp` sits on a carrier, so no constant that isn't a fueling code picked up a member name.
- The build warnings are unchanged. `./analyze.sh verify` is deterministic. `lookup_tables.py` is clean. `test_rename_waves`, `test_lookup_tables` and `test_disasm_tools` pass. Both firmwares' headers compile with 0 errors.

## Not covered

- The 37 / 38 compares and the `(int)(short)` temporary compare in `protectionRampRateControl` still render as numbers.
- The 13-41 limiter codes (`torque_derate_fuel_source_code`, `governor_fuel_mode_*`, `governor_mode_code`) have no members yet. Neither does CM550's FSGVFLST typing.
- The misnamed words around the arbitration (`cruise_fuel_demand_setpoint` = the vehicle speed limit fuel, `cruise_speed_setpoint_adjusted` = the vehicle speed, and the `*Protection*` cluster that looks like the power take-off governor) are listed in task 045.

🤖 Generated with [Claude Code](https://claude.com/claude-code)

The typing pass for everything that doesn't need the truck: todo 040's line images, todo 039's lookup tables, todo 035's MIOS driver types, the sensor channels (todo 041), and an importer bug that made array types in `global_variables.csv` silently do nothing.

## What changes in the decompile

| Artifact | Before | After |
|---|---|---|
| `(word *)&` cast lines | 966 | 20 (mostly EEPROM buffers) |
| `(sensor_channel_config_t *)&` / `(dword *)&` casts at sensor-channel calls | 48 / 50 | 0 / 2 |
| Truncated `(word *)0x…` pointer arguments | 29 | 7 |
| `in_stack_` slots (Type A sensor channels) | 18 | 0 |
| `table_interp_args_t` | 50 | 0 |
| `injector_control_t` (bogus, on output lines 88-143) | 93 | 0 |
| `output_lines_*` / raw `0x40c0f8` / `mios1_ext_ctrl` | 54 / 8 / 33 | 0 / 0 / 0 |
| New `_name` (too-narrow) globals | | 0 |

Functions added / removed: 0. Local-rename warnings: none new, and 11 old Type B rows that never matched now apply.

## Commits

1. **Importer: `T[N]` types apply.** `ImportAnalysis` had no array case, so `word[10]` in `global_variables.csv` was counted as "unmapped" and dropped. That hit 3 rows, including the `governor_minimum_speed_by_vehicle_speed` axis and table pair, whose lookup still rendered casts.
   - New `ScriptUtils.parseArrayType` (with 6 unit tests, 88 in total).
   - An empty name now types an address without naming it.
   - Every unmapped type is listed with a WARNING in the build log.
   - CM550 builds byte-identical apart from the timestamp; it has no `T[N]` rows.
2. **Three discrete line images.** Line N is byte N/8 bit N%8 of three 20-byte `discrete_line_image_t` instances (fields `lines_0_to_7` .. `lines_152_to_159`):
   - `output_line_read_back` (0x40c0e4): the ports read back before each refresh.
   - `input_line_image` (0x40c0f8).
   - `output_line_state` (0x40c10c): the command shadow.

   These replace 30 misnamed bytes (`j1939_dm1_*`, `j1939_lamp_status_*`, `io_pin_status_byte` ...), the `output_lines_N_to_M_state` names, and an `injector_control_t` that was really output lines 88-143 (TPU channels used as discrete outputs). Other changes in this commit:
   - `hpcr_injectorPulseWidthCalc` is the bulk input snapshot, now `cm848_refreshInputLineImage`.
   - The MIOS port (submodule 32) is `mios_mpiosm32.data` / `.data_direction`. Its stack copies are `mios_port_data_register_t`, so `CONCAT11` and the `_1_1_` pieces are gone.
3. **Every lookup table is a `word[N]` array: 920 tables (564 unnamed).**
   - **Where the addresses come from:** the decompiled call arguments, cross-checked against the call-site disassembly. 816 of the first pass agreed.
   - **How they're sized:** from the dumps. An axis is 1 + its length word / 2, with monotonic breakpoints; all 515 pass. 1-D data has one value per axis point plus its own header; all 263 headers match their axis. A 2-D grid is nx × ny with no header (142 grids). The hand-written `word[10]` / `word[21]` tables get the same counts.
   - **Unnamed tables** are type-only rows. They render `WORD_ARRAY_<address>`, and each comment gives the role, size and readers for a later naming pass.
   - **Cleanup:**
     - `protection_fuel_limit_l2/l3/l4_axis_cal` each named two tables. The converter-lockup copies are now `..._values_axis_cal`.
     - The `boost_in_range_config` struct overlapped the two axes of a 2-D table, so it's removed.
     - Junk labels inside tables are removed, as are the junk `+2` rows on two cache words.
   - **Type B sensor channels:** `sensorChannelTypeB_*` pass their "unused" table pointers straight to `lookupTableInterpolation`. The prototype now says so, and `table_interp_args_t` is gone.
4. **MIOS submodules.** One `mios_mdasm_t` / `mios_mpwmsm_t` replaces ten per-channel copies, and the instances are named `mios_mdasmN` / `mios_mpwmsmN`. `AR_BR` is one dword, because the drivers only ever move the pair together. The eight `mpc555_mios*` drivers take struct pointers, so `->SCRD` / `->PULR` / `->SCR` replace `+ 6` / `[1]` / `[3]`.
5. **Type A sensor channels.** Their parameters 2-5 are the same lookup arguments, so 22 more tables and 10 cache words are typed. Parameters 6-12 are still mis-specified and logged in todo 041.
6. **Headers and docs.** The headers are regenerated and compile with 0 errors on both firmwares. `firmware/CLAUDE.md`, the CSV-editing skill and the todo list (035 / 036 / 039 / 040, new 041) are updated.

7. **Review follow-ups.**
   - `xref_addr.py` now also looks for Ghidra's typed default labels (`WORD_ARRAY_` / `WORD_` / `BYTE_` ...), so unnamed tables no longer show 0 references. There's a new test case.
   - One of the 312 changed functions wasn't explained by a typed symbol. The word constant just past a typed grid (0x5c788) picked up an auto-string label. It's now `intake_air_heater_runup_holdoff_preset`.
   - A junk `unicode` type is blanked, so the new importer warning is silent on a clean build.

8. **`firmware/scripts/lookup_tables.py`: the table pipeline as a kept tool.**
   - **What it does:** re-derives every table from the last build (the `.cpp` call arguments plus the call-site disassembly), sizes the tables from the dumps, and audits the CSVs. It exits 1 when a table is untyped or wrongly sized, when a row sits inside a table, when a table overlaps a struct, an `arrays.csv` row, a function or another table, or when a cache argument still needs a cast.
   - **Options:** `--apply` writes only the conflict-free fixes and never deletes a row. `--plan` dumps every table.
   - **Results:** the committed state audits clean (920 tables, all typed). Run against main's CSVs, it reports 916 untyped tables and the 7 interior rows.
   - **Shared code:** `disasm_func.py`'s register tracking is now a shared `step_address_registers`.
   - **Tests:** `test_lookup_tables.py` has 11 checks.

9. **Sensor-channel typing pass.** The Type A (`sensorChannelConfigInit` / `updateSensorChannelWithConfig`) and Type B (`sensorChannelTypeB_*`) channel functions run the same algorithm, so they now share one 13-parameter prototype: `(config_ptr, state_ptr, cached_axis_offset, x_axis, y_data, flags, filter_state_ptr, channel_index, high_fault_bit, low_fault_bit, value_output_ptr, default_value_output_ptr, fault_status_output_ptr)`.
   - **Type A was misaligned.** Its 22 call sites passed 16-bit truncated pointers: `0xa020, …, 0xbd90, 0xbd9c, 0xbe16` is now `&sensor_channel1_filter_config_ptr, …, &sensor_channel20_raw, &sensor_channel20_filtered, &sensor_channel20_fault_status`. Its body read the outputs as `in_stack_` slots and its blocks through raw offsets.
   - **New structs:**
     - `sensor_channel_state_t`: `raw_adc_counts` / `value` / `debounce_count` / `held_value` / `spare` / `lookup_input`.
     - `ema_filter_state_t`: a coefficient pointer plus a Q16.16 accumulator. `exponentialMovingAverage` is typed for all 45 callers. Each pass moves the value (65536 − coefficient) / 65536 of the way.
   - **Config field:** `sensor_channel_config_t.config_word0` is the `filter_coefficient` that the filter state points at.
   - **Instances:** 144 typed (32 configs, 30 states, 63 filter states, 19 output words). `sensor_channel_cal_block_start` is now a word; as a dword it covered the first channel config.
   - **Left for todo 041:** 26 blocks with a named row inside stay untyped, because typing them renames every direct use to a struct field. Examples: `boost_pressure_fixed_reference` (the boost config's default), `fuel_level_unfiltered`, and the J1939 pedal pair, which is how EEC2 reaches the pedal channel's `held_value`.
   - **Misleading output names (also todo 041):** the globals passed as outputs are misnamed. `*_raw` receives the filtered value, and `*_filtered` receives the config default.
   - **Type B locals re-anchored:** three names sat on the wrong values before (`high_fault_word_index` held `channel_index >> 4`).
   - **Checks:** 147 functions change, all traced to a symbol this pass typed. `lookup_tables.py` still audits clean.

10. **Sensor / filter blocks with named fields, and honest output names.**
    - **Blocks typed:** the 24 blocks the previous step skipped are typed, and their interior names became fields:
      - `barometric_pressure_sensor_config.default_value` (was `boost_pressure_fixed_reference`).
      - `cruise_switch_sensor_config.high_threshold` / `.low_threshold` (were `cruise_engage_adc_valid_*`).
      - `fuel_level_sensor_channel_state.value`.
      - The J1939 pedal pair: `sensor_channel13_ram.held_value` / `.held_value_source_priority`. +8 is a byte, so the state struct splits its spare word.
    - **Filter names:** filter states are `<x>_filter_state` (25 renamed from `*_ptr` / `*_pointer`), and their 36 coefficient words are `word` / `<x>_filter_coefficient`.
    - **Output names:** `<x>_value` / `<x>_default_value` (52 renamed from `*_raw` / `*_filtered`). The disassembly shows argument 10 gets the filtered output and argument 11 the config default. `boost_pressure_sensor_value` (0x40bd8e) is channel 1's filtered intake manifold pressure; the docs that called it "raw" are fixed.
    - **Checks:** 155 functions change, all traced to the renamed / typed symbols. One of my apply scripts briefly blanked every auto-label row; those names are restored and every remaining row change was checked against the plan.

11. **Ghidra auto-label rows.**
    - 120 rows named `BYTE_…` / `PTR_DAT_…` / `PTR_FUN_…` are now type-only, and one untyped string label is gone. Register addresses are left alone.
    - Boot-ROM calls into the kernel's RAM copy now show their functions: `mpc555_dispatchCanMessageHandlers()` (was `BYTE_003fae3c()`), `mpc555_serviceJ1939TransportSessions`, `mpc555_cmfEraseBlocks`, `cm848_copyBytes`, `cm848_allocateDiagnosticResponseBuffer`.
    - 0x3fd1ac / 0x3fd284 / 0x3fd298 keep a `BYTE_` label on purpose. The application uses them as data, and they'd otherwise render as `cm848_sendDiagResponsePending = 0`.
    - 19 functions change, every change a label.
12. **Todo 039 closed: a stale-r29 quirk, confirmed in the disassembly.**
    - Only governor mode 1 sets r29, the start temperature. In every other mode the integrator-preset lookup at 0x48ba8 reads the caller's r29, which is the `unaff_r29` argument.
    - It's likely harmless: it only runs with the engine stopped, and mode 1 recomputes the preset before a start.

13. **Table-naming campaign: 519 of the 564 unnamed lookup tables named** (e081b73 pilot, 973925d main wave).
    - **Method:** one agent per bin of reader functions, given each lookup's call, its inputs and the table contents. Each agent named the lookup from its traced input, its traced output and breakpoints converted to units (0.125 rpm, 0.0679 mm³, 0.0488 MPa, 1/64 °F, 0.0159 inHg), or skipped it. A script added the role suffix (`_axis` / `_values`, `_x_axis` / `_y_axis` / `_grid`).
    - **Pilot gate:** 4 agents ran first, with the go / no-go criteria written down before any result came back. Two independent agents agreed on the meaning of 11 of 11 lookups in the same bin, and 15 of 15 hand-checked names fit their breakpoints. After that, 16 agents named the rest. Several agents reproduced table outputs from the RAM dump; for example, the stored rail-pressure setpoint 1000 matched an interpolated 999.9.
    - **Consistency pass:** sibling families share one vocabulary (`base_map` + `map_1`..`map_4`, and `coolant` / `ambient` / `boost` factor pairs) across `injection_timing_main_*`, `injection_timing_offset_*`, `injection_timing_auxiliary_*`, `injection_quantity_auxiliary_*`, `pilot_quantity_*` and `fuel_pressure_setpoint_*`. Sensor tables are `<sensor>_linearization`, identified by decoded DTCs or the slot table, or `sensor_channel<N>_linearization` with N = the output slot. The three injection events are pilot / main / auxiliary.
    - **Proof:** mapping every new name back to its old label gives back the old `.cpp`. The only exception is three functions whose local declarations changed order; they hold the same declarations. `WORD_ARRAY_` labels went from 568 to 47, there are no underscore variants and no new warnings. The audit is clean, the tests pass, `verify` is deterministic, and the headers compile.
    - **45 tables stay unnamed** because their input units or output could not be traced.
    - **Review pass (dfef374):**
      - `docs/table_naming_campaign_2026-11-16.csv` records every table's evidence or skip reason; 39 % of the names are medium confidence.
      - 24 names were aligned: `cold_start` to match `cold_start_phase`, the sensor tables to `<sensor>_linearization`, reference voltage `_b`, and `wastegate_duty_ceiling` / `_floor` without the unsupported fuel-quantity claim.
      - The 4WD switch identity is now sourced from the DRB database (P0836 / P0837 "4WD MUX SWITCH").
      - Bin 10's domain words came from the repo's e2m name lists; its traces stand on the code alone.
      - That the auxiliary event comes after main is marked as inferred.
    - **Rename leads for the code around the tables** are in `work/tasks/042`: about 20 wrong-domain functions, for example `cm848_torque_limit_state_update` is the pilot injection quantity and `cm848_boostCompensatedRpmGovernor` is the wastegate duty. Two duplicate global names are listed there too.

14. **The code around the tables, renamed: 27 functions and 237 globals (482038a, todo 042).**
    - **Method:** five read-only agents checked each lead from the table campaign against the code, with RAM-dump reproductions where possible. Every lead held. They also found the chains around each function: the timing / quantity / on-time paths of all three injection events, the rail-pressure setpoint and its monitors, wastegate duty and its monitor, the charging regulator, the intake air heater test, the J1939 retarder, and an oil-change monitor.
    - **Injection:** there are three events per cylinder (TPU-A channel 5 slots 4 / 8 / 12, in crank order pilot → main → auxiliary).
      - Timing: `cm848_calculateMainInjectionTiming` (was `cm848_calculateEngineTimingData`), `cm848_calculatePilotInjectionTiming(Offset)`, `cm848_calculateAuxiliaryInjectionTiming` (was `cm848_auxiliary_boundary_condition_eval`).
      - Quantity: `cm848_calculatePilotInjectionQuantity` (was `cm848_torque_limit_state_update`) and `cm848_calculateAuxiliaryInjectionQuantityLimit` (was `cm848_calculateGovernorOutput`).
      - On-time: `cm848_calculate{Pilot,Main,Auxiliary}InjectionPulseWidth`.
      - Variables: the headline values are `main_injection_timing` (was `torque_limit_fault_snapshot`), `pilot_injection_quantity` and `main_injection_pulse_width` (was `fuel_quantity_active`), and the component families follow the tables (`injection_timing_main_*`, `injection_quantity_pilot_*`, ...).
    - **Rail pressure:** `cm848_calculateFuelPressureSetpoint` (was `cm848_sensor_channel_state_load`), plus monitors for P1223 / P0088 / P1222 and the rail-pressure-shortfall fuel limiter.
    - **Air and electrical:** `cm848_calculateWastegateDutyRequest` (was `cm848_boostCompensatedRpmGovernor`), the wastegate monitor, the charging-voltage target and regulator, and the P2609 heater test. Also `barometric_pressure_reference` / `barometric_altitude_feet` (were `fuel_pressure_sensor_reference` / `governor_adjustment_input`).
    - **Governor / J1939:** the retarder stage selection and torque, the governor compensator coefficients, the no-load fuel, the reference-speed blend, and `cm848_updateOilChangeMonitor`. The oil-change identity rests on e2m names matching its block layout.
    - **Recorded with the renames:** each renamed global's comment now starts with its evidence and `(was <old>)`, and the function plates are rewritten. The two duplicate global names are fixed. Four leads stayed uncertain and are listed in task 042 with the agents' 49 further notes.
    - **Proof:** mapping every new name back to its old one gives back the previous `.cpp`, plate comments aside; three functions only reorder their declarations. One new row is `i16`: typing it `word` added casts, which the proof caught. `verify` is deterministic.
    - **Review pass (f813725):**
      - 473 comments and 18 plates that cited renamed identifiers now use the new names.
      - Five names were tightened where the evidence was weaker: auxiliary quantity *limit*, governor *compensator coefficients*, *governed-speed* (not "idle"), and a neutral oil-change accumulator name at a time-shared address.
      - Decoded from ROM: fault 411 = P2609, and the limp-home flag's triggers are P0193 / P0192 / P0088 / P0251.
      - Checked: 155 of 234 renamed globals are used only inside the verified functions, and the outside users of the rest fit their names. The e2m parameter blocks match CM848 RAM by relative offset (two blocks verified, same scales).
      - Recorded in task 042: CM550 shares three of the old names, and 21 duplicate names predate this wave.

15. **Rename wave 3 (2c83cea, cfd889a, 3f64709).** Six read-only agents checked the first wave's further leads, retried the skipped tables and resolved every duplicate name.
    - **Renamed:** 53 functions (plus 5 plate refreshes), 183 globals and 16 struct fields. `rpm_governor_state_t` becomes `wastegate_duty_controller_state_t`, with every field in half-duty counts; the `fault_entry_t` freeze-frame fields are renamed too.
    - **Duplicates and junk:** all 21 duplicate names now have distinct names, 31 junk rows are deleted (27 `switchD`, 4 USIU), and 5 more tables are named (524 of 564).
    - **New rows:** 113 rows for unnamed words, typed from their access widths. The two Q16 slew accumulators and 0x3fd108 are now dwords, which removes their underscores.
    - **Highlights:** `crank_position_valid_flag` was the speed-limp-home flag read backwards (now `engine_speed_limp_home_active_flag`, with `cm848_enter/exitSpeedLimpHome`). Also the ERC1 / TSC1 retarder chain and the PGN 65213 / 65249 messages, the charging-regulator chain (P2504 / P2503), the P0148 / P1221 rail-pressure monitors, the per-injector diagnostic bitmaps (P0201–P0206 / P2146 / P2149), and `all_speed_governor_droop`.
    - **Proof:**
      - The renames map back exactly, comments aside. Goto-target labels are normalised for the deleted `switchD` rows, since Ghidra now names its own switch defaults.
      - The new rows changed 13 functions beyond whitespace, and every change is a typing improvement: `0` instead of `'\0'`, dropped `(short)` casts, `table[i]` arrays. Two rows were retyped when the first build showed added casts.
      - **Reverted:** retyping the oil-change block 0x3fee34–0x3fee3d made three boot-ROM functions worse, because the boot ROM time-shares those bytes. That block keeps its old types, and the rows document why.
      - `verify` is deterministic, the audit is clean, the tests pass and the headers compile.
    - **Review checks (e54732c):**
      - With goto labels renumbered one-to-one per function, only the 12 type-improved functions differ from the pre-wave build, and each of their token changes is classified.
      - No new row overlaps another row, no renamed window global has a boot-ROM user, and no duplicate names remain.
      - The speed-limp-home flag is confirmed apart from e2m: entering it sets fault 335 = P0336, the crankshaft position sensor signal.
    - **Still open:** 9 items left uncertain and 49 further notes, recorded in task 042.

16. **Rename wave 4 (14dfd97).** Four agents worked the wave-3 leftovers.
    - **Renamed:** 44 functions (plus 7 plate refreshes), 219 globals, 6 more `fault_entry_t` fields, and 12 new rows.
    - **New functions:** the alternator regulator's four state handlers, which are reached only through a pointer table, so Ghidra had never created them. Their five thresholds now render.
    - **Highlights:**
      - `torque_limit_*` is an engine *speed* limit family: every value is rpm × 8.
      - The P0191 fuel-pressure-sensor plausibility check.
      - An exhaust-brake request chain (P0478 / P0477).
      - The dual accelerator pedal (was the `cruise_speed_*` block).
      - The J1939 CAN receive and transmit queues.
      - The main-timing base command and combustion limits.
      - An "actuator E" closed loop on the wastegate duty request, unassigned on this truck.
    - **Proof:** with goto labels matched one-to-one, only two existing lines differ, both benign: a pointer label and the export footer's function count. The 12 new rows matched the decompiler's own types.
    - **Conflict for review:** the 2026-06-27 engine-load-protection re-domain (7c997eb) may monitor sensor channel 101, not engine load. It is recorded in task 042 and not acted on.

17. **Rename wave 5 (40a41e7): the load-protection cluster is a VGT position servo; the combustion manager.**
    - **Renamed:** 64 functions, 191 globals, 1 enum type and 2 members, 11 struct fields and 2 struct types, plus 12 new rows.
    - **Load protection (7c997eb) was wrong.** The 0x2e17c–0x2f6a0 cluster filters sensor channel 101, the position feedback of a two-direction valve servo. It runs that sensor's key-on stop seek and position learning.
      - Its position formula reproduces the dump, and wave 4's "actuator E" loop drives the same servo.
      - The turbocharger label comes from the e2m VGT group; the code itself proves only the servo.
      - It is not fitted on this truck.
    - **Combustion manager (CBR / CBO / CBL / CBP):** `cm848_runCombustionReference`, `cm848_runOffNominalCompensation` and `cm848_runCombustionLimits`.
      - `cm848_interpolateAlphaChiValue` (was `cm848_filterInputValue`, 18 users) blends the alpha/chi maps; the dump selects chi 4, the EGR-off map.
      - Bank 2 holds the cylinder oxygen balance, the net combustion torque and the ambient air density.
    - **Proof:** label-only with one-to-one goto labels, except two functions whose stores now cast to the new rows' `word` type.
    - `firmware/CLAUDE.md` gains a "Rename waves 1-5" summary.

18. **Rename wave 6 (1839d0b).** Four agents worked the waves 4–5 leftovers.
    - **Renamed:** 52 functions, 399 globals (10 of them rows that had no name), and 6 struct fields, plus 44 new rows.
    - **VGT servo:** the "actuator E" loop is the VGT valve position servo itself. The whole module is `variable_geometry_turbocharger_*`: the PID, the direction and PWM outputs, the H-bridge and over-current faults, and the motor thermal model.
    - **High speed governor:** the `fuel_ema_coeff_*` / `injection_timing_compensation_*` words are its speed-error PID. The RAM dump reproduces P 2062 + I 117 + D 0 = 2179.
    - **Speed limits:** the engine speed limit chain, and a cruise vehicle-speed limit (was `cm848_calculateTorqueCurveValue`).
    - **Combustion manager:** its limit and calibration tables, 20 map grids reached through pointer words, and the mass flows.
    - **Proof:** label-only with one-to-one goto labels, except array-decay rendering in the map-pointer setup and one `SUB42` that became a plain cast.

19. **Rename wave 7 (4c39da3).** Three agents worked the wave-6 leftovers.
    - **Renamed:** 59 functions, 309 globals and 1 struct field, plus 23 new rows and 1 retype (`i16`, read with `lha`).
    - **EGR valve servo:** the VGT loop's twin is the EGR valve position servo (`egr_valve_*`). Its feedback is sensor channel 75 through a learned zero offset; it has direction, PWM and enable outputs, and the EGR fraction PI command is its setpoint. It is compiled in and runs, but it is not fitted on this truck.
    - **Wave-6 uncertain rows settled:** `battery_voltage_selected` / `battery_voltage_nominal` and `coolant_temperature_selected`, confirmed by their DTCs.
    - **Old `torque_*` functions:** the pedal fault operating mode (mode 6), the EEC1 driver demand percent torque, and the switch-selected and fault-derate speed limits.
    - **Found, not fixed (todo 043):** the ROM-to-RAM thunk build stage swallows the data rows at 8 kernel-image addresses that the boot ROM calls (0x3fb54c / 0x3fb54e and 7 more; spot-checked against the commit that added the stage). The CSV rows are right, so the fix belongs in `ApplyRomToRamThunks.java`.
    - **Proof:** label-only with one-to-one goto labels, apart from default labels of rows that had no name, one declaration order, and store casts.

20. **Comment fix-ups (c3345c0).** Comment-only changes to 327 rows of `global_variables.csv`; the code is unchanged.
    - **Truncated comments:** this PR's apply scripts cut each agent's evidence at 400 characters, leaving identifiers cut mid-word. 305 bodies are re-cut at a word boundary and marked "...", 265 of them from the agents' full text.
    - **Stale references:** 13 default struct labels are replaced by the rows' new names, and 2 retired names by the current ones.

21. **Rename-wave toolchain and the agents' notes saved (1a35aec).**
    - **Toolchain:** `firmware/scripts/rename_waves/`, with a README of the steps. It holds the scripts that gated, applied and proved waves 1-7 (vocabulary pass, gate, appliers, label-only proof, reference refresh, comment sweep, header check), made reusable, with shared helpers in `common.py`.
    - **Tests:** `firmware/scripts/test_rename_waves.py` runs 28 synthetic checks (cad969f added the gate, struct-type renames and stage-1 extras); a pure rename passes and a one-constant change is caught. A build with the new folder under `firmware/scripts/` changes only the `.cpp` timestamp. Re-running wave 7's proof with the saved scripts gives the same result byte for byte.
    - **Notes:** `firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/` holds the agents' raw results, briefs and applied mappings for rename waves 1-7 and the table campaign (3.1 MB). Task 042 had quoted the notes cut short.
    - **Naming decision:** new names say `initialize`, never `init`, recorded in `firmware/CLAUDE.md` and the gate. No name this PR added uses `init`.
    - **CM550 link (task 042):** wave 6 renamed CM848's shared `selectSensorRawChannels`; CM550 still has that name at 0x1d392, so check whether it is the same function.

22. **Everything from the session kept (e7b795d, e21ff46; at the user's request).**
    - **In the repo:** `firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/` holds the 505 scratch files, the 131 `.cpp` snapshots and build logs (0.8 MB compressed, checked byte-identical), and the exact prompt of each of the 48 subagents.
    - **Outside this public repo:** the session and agent transcripts, kept privately because they hold the session's private context.
23. **ROM-to-RAM thunk stage fixed (335ec12, todo 043).**
    - **The fix:** where a named application variable sits in the 4 bytes a thunk would take, the stage now keeps the data and points the boot calls at the ROM function with `CALL_OVERRIDE_UNCONDITIONAL` references. This applies at 10 addresses.
    - **Boot side:** boot calls now name their function (they used to render as calls to a variable).
    - **Application side:** variables render under their own names, without `_`, and a crossed counter pair is fixed. 30 functions changed, all reviewed; 8 fewer overlap warnings.
24. **Rename wave 8 (b66e3a7).**
    - **Labels:** 36 functions, 260 globals and 38 new rows: the droop block, the auxiliary quantity maps, the EGR delta-pressure autozero, the charge manager, and the all-speed governor override record. The proof is label-only.
    - **Types:** the arbitration struct split and the governor output struct, 46 retypes from load/store evidence, the split dwords, and three enums (`ENGINE_OPERATING_MODE` corrected from every store; `EGR_VALVE_CONTROL_STATE`, `COMBUSTION_CHI_SOURCE`). The 79-function diff was reviewed.
    - **CM550:** `selectHighSpeedGovernorGainSet` is now shared with CM550 (proof EQUIVALENT).

## Finding for task 022: the J1939 pedal reaches fueling

The 2026-11-12 "EEC2 pedal = dead end" conclusion was wrong. That value is the accelerator channel's `held_value` (state + 6), and the sensor-channel functions read it through `state_ptr`, which a name search can't see.

- `cm848_processJ1939AcceleratorPedalPosition` writes SPN 91 x 16 / 10 into `sensor_channel13_ram.held_value`. It runs when EEPROM 0x5e6 (`fuel_demand_feature_flags`, really a per-channel hold bitmap) has bit 13 set and switch 7 is datalink-sourced.
- With that bit set, channel 13 outputs `held_value`, and `cm848_fuelDemandFinalCalculation` takes fuel demand from `accelerator_pedal_sensor_filtered`.
- The pedal channel's own table maps ADC 39..839 to 0..400. That is the same 0.25 % per count as the J1939 writer, so this is a designed drop-in J1939 pedal mode.
- Enabling it means EEPROM changes, a bench job: bit 13 of 0x5e6, the switch-7 datalink bit at 0x74c, `j1939_input_processing_enable_cal` 0x400, and the input-7 enable.

## Finding for the bench

The disassembly shows the MIOS port byte order disagrees between the output paths. `cm848_refreshOutputPortsAndReadback` and the input image put lines 8-15 in port bits 7-0. `mpc555_driveOutputLineHigh` / `Low` set bit (line mod 16), with the bytes swapped, until the next refresh rewrites the port. Which one matches the harness needs a bench check (todo 041).

## Checks

- `analyze.sh build` after each commit; `analyze.sh verify` (two builds, byte-identical) on the final state.
- The CM550 rebuild after the importer change is byte-identical except the timestamp.
- `firmware/script_tests/run_tests.sh`: 88/88 pass.
- `firmware/scripts/test_lookup_tables.py` (11 checks) and `test_disasm_tools.py`: ALL PASS. `lookup_tables.py` exits 0 on the committed state.
- Headers: `g++ -fsyntax-only -std=c++17` with 0 errors, CM848 and CM550.

🤖 Generated with [Claude Code](https://claude.com/claude-code)

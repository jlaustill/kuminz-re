W12 bin6 is done. All 66 records are in /home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage7/result_W12_bin6.jsonl. I made no repo edits and ran no builds. The untracked firmware/scripts/test_e2m_name_audit.py is not mine.

**Checks run on the file**
- 66 lines of valid JSON, in bin order, with the schema keys.
- Addresses match the bin.
- 64 names, all unique, none already in global_variables.csv or the .cpp.
- Types follow the size and signedness rules.

**Verdicts:** 64 confirmed, 0 uncertain, 2 rejected. The two rejected rows have `new` and `type` empty.

**Drift and width problems**
- **0x5c7ac, 8A2B +24 IAH_Pulsewidth_Time_Duration (rejected, drift):** the address belongs to block 8A37 +00 IAH_Default_IMT (signed DEG_F). The only code, cm848_captureIntakeAirHeaterStartTemperature, loads it with `lha` as the default start temperature. Block 8A2B ends at +22 in this ROM. That 8A37 record needs its own name, for example `intake_air_heater_default_intake_manifold_temperature` with type `i16`.
- **0x3ff06c, 10A0 +0E C_TSE_Charge_Press_Derate (rejected, width):** the record is a 4-byte bitmap (dump 0x010f000f), but the only access is one `lbz` of byte 0. Bytes +1 and +3 are separate byte rows (0x3ff06d, 0x3ff06f), so a dword row would swallow them.
- **0x5a48e / 0x5a490 / 0x5a492 (1228, kept):** the 10E3 tail records +22 / +24 / +26 resolve to the same addresses. Block 1228 starts at 0x5a48c, which is 10E3 + 0x20, so the 10E3 tail is not in this ROM. The DM4 and DM5 code fits 1228.
- **12F7 +14 J1939_Mux_Wet_Tank_Pressure (0x40aaba, not in my bin):** in this ROM it receives EEC2 accelerator pedal position 2, so that one e2m label does not match. The +11 to +13 and +15 records do match.

**Deliberate deviations (each is stated in the row's evidence)**
- **0x3fe9a8 fault_detected_bits_416_to_431 has no `_cal`.** The region rule says it should end `_cal`. I followed its 20+ siblings and the 0x3fe9c4 note "no _cal: runtime state". The e2m defines its bits 0x1 and 0x2 as the cylinder 7 and 8 misfire errors, and the misfire monitor tests exactly those masks.
- **0x408adc has a direction-neutral name (`converter_clutch_lockup_fourth_gear_ratio_limit`).** The e2m calls it "Min", but the code passes when the ratio is at or below it, so it is a ceiling in use. The neighbours +0C, +0E, +12 and +13 all fit, so this is a label issue, not drift. Verdict is confirmed.
- **The four PGN 65264 PTO rows use e2m-derived names** (`j1939_received_power_take_off_*`, `j1939_received_remote_power_take_off_switch`). They deviate from the sibling SPN-name convention because the local database has no usable PGN 65264 layout, so the SPN names cannot be verified. The A/C row uses SPN 985 (A/C High Pressure Fan Switch), from the SHUTDN positions the database files under number 65251.
- **0x3ff05e is `altitude_derate_engine_speed_threshold`.** I left out "air handling fault" because the early return also skips the normal cool and hot grids.
- **0xb74a is `application_overlay_core_software_version`.** It avoids a mix-up with the EEPROM calibration V11.46.06; the dump is 0x11201401.
- **The TCC rows use the repo's `converter_clutch_` prefix** rather than `torque_converter_clutch_`.

**Leads, outside my bin**
- The `cold_start_*` and `intake_temp_ema` names in the 0xe0f4-0xe518 functions are alpha names. `fuel_demand_ramp_factor` is alpha, and 0x5be66 `cold_start_intake_temperature_filter_coefficient` is e2m Alpha_Fuel_Rate_Filter_Constant.
- The `diag_dm1_*` names around cm848_phase_groupB_calculation are the e2m data collector. Collector_Schedule, Collector_Trigger and Collector_Stop_Mode sit at 0x3fddb6, 0x3fddb8 and 0x3fddba.
- `throttle_trim_predictor_output` (0x40a692) and `throttle_trim_predictor_gain` (0x40a696) are INM_EGRT_After_Lead and the lead time constant of EGR orifice temperature.
- `j1939_feature_config_word` (0x5a494) is Supported_Non_Continuous_Monitors, and `cm848_governorDroopCalculation` is a number-to-decimal-text helper.
- The `protection_*` rows at 0x408ad2-0x408ade are the P1740 converter clutch rationality values (e2m TCC_Rationality_* and TCC_Steady_Throttle_Count_Limit).
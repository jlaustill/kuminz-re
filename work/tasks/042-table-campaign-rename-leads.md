# 042 — Rename leads from the table-naming campaign (CM848)

**Type:** implementation (naming / readability)
**Source:** PR #50, 2026-11-16. Twenty agents named 519 lookup tables. Each traced its tables' inputs and
outputs and recorded the misnamed functions and variables around them. These are **leads, not verified
renames**: check each against the code (and `xref_addr.py` / the disassembly) before renaming, per the
`review-function-readability` skill. Where two agents agreed independently, it says so.

## Functions (what they compute)

| Function | What the code does | Evidence |
|---|---|---|
| `cm848_auxiliary_boundary_condition_eval` | auxiliary (third, post-main) injection timing | two independent agents (bin 02 A / B) |
| `cm848_calculateGovernorOutput` | auxiliary injection quantity limit (`crank_sync_threshold` is its output) | bin 03 |
| `cm848_torque_limit_state_update` | pilot injection quantity (capped at half the fuel demand) | bin 00, RAM-dump reproduction |
| `cm848_calculateEngineTimingData` | main injection timing (`torque_limit_fault_snapshot`, PGN 65504) | bin 05, RAM-dump reproduction |
| `engine_injectionTiming_arbitration_calc` | an injection timing offset added to the main timing (which event: open) | bin 01 |
| `cm848_sensor_channel_state_load` | rail pressure setpoint (`fuel_pressure_setpoint`) | bin 04, RAM-dump reproduction |
| `cm848_calculateTimingWithTables` / `cm848_calculateEngineFaultTiming` | main / auxiliary injector on-time | bin 09 |
| `cm848_calculateEngineTimingInterpolation` | pilot injector on-time | bins 00 / 13 |
| `engine_camTiming_positionCorrection_calc` | fuel-metering feedback monitor (fault bit 60 = P1223) | bin 06 |
| `cm848_processEnginePositionDiagnostics` / `engine_camSync_referenceCheck_update` | rail pressure diagnostics (fault bit 303 = P0088) | bins 07 / 13 |
| `cm848_boostCompensatedRpmGovernor` | wastegate duty: `rpm_governor_state_t.desired_rpm` / `lower_rpm_limit` / `commanded_rpm` are duty / 2 (12800 = 100 %) | bin 07 |
| `hpcr_fuelDemandProc` | electronic wastegate monitor (pass window) | bin 10 |
| `cm848_filterProtectionOutput` | 4-state charging-voltage (alternator field) regulator | bin 08 |
| `hpcr_injectPressureTuning` | intake air heater performance test (P2609) | bin 17 |
| `j1939FormatMultiFrameResponse` / `cm848_calculateSpeedControlError` | TSC1 retarder request quantizer / ERC1 byte 2 builder | bin 12 |
| `cm848_calculateFuelTrimValues` | governor PID gains | bin 12 |
| `cm848_calculateFuelTimingBlend` (+ `fuel_timing_blend_factor`) | a drivetrain-ratio (gear) blend of two governor tunings | bins 10 / 12 |
| `cm848_fuelTimingRateLimitedBlend` | an engine-speed blend, not injection timing | bin 15 |
| `protection_fuel_demand_limiting` | rail-pressure-shortfall fuel quantity limiter | bin 18 |
| `governorCruiseTimerManagement` | weighted-fuel / distance / power accumulator, maybe a service-interval monitor (unverified) | bin 11 |
| `cm848_processProtectionCoolantLookup` | reads battery temperature | bin 15 |

## Variables

- **Injection quantities and on-times are swapped by name:** `engine_timing_reference*`, `engine_timing_delta`,
  `cam_timing_reference_offset` hold fuel quantities; `fuel_quantity_active`, `fuel_quantity_table_result`,
  `fuel_quantity_trim`, `injection_timing_active_flag` hold on-times (bins 00 / 09 / 13).
- `torque_limit_fault_snapshot` = the main injection timing (bins 02 / 05). `torque_limit_demand_output` = the pilot quantity.
- `boost_map_index_current` / `_target` = blend table numbers 1..4 (several bins).
- `fuel_pressure_sensor_reference` = barometric (ambient) pressure reference, capped at 30 inHg (bins 08 / 10 / 11).
- `governor_adjustment_input` = altitude in feet; `governor_adjustment_rpm_axis_cal` is an altitude axis (bins 07 / 08; the altitude table matches the standard atmosphere).
- `sensor_channelGeneric_*` = the coolant temperature channel (slot 2); `fuel_demand_boost_input` = that coolant value (bins 17 / 18).
- `sensor_channel9_pressure_value` / `_default_value` = intake manifold temperature (bin 16).
- `governor_torque_output` (0x40bb00) = the remote accelerator pedal position (bin 16).
- `cruise_speed_current_a` / `_b` (0x40bbb2 / 0x40bbb4) = the two accelerator pedal tracks (bin 15).
- `battery_voltage_prev` (0x40b26e) = the charging voltage target (bin 15).
- `fuel_timing_sensor_value` = slot 4 = battery voltage (P0563 / P0562); `governor_speed_input_value` = slot 75 (sensor unknown).
- `cruise_state_machine_index` / `cruise_prev_state_index` / `cruise_voltage_*` = the alternator regulator state (bin 08; task 029).
- `protection_iat_scaled`, `governor_cold_start_iat_correction`, `iat_fuel_trim_*` use barometric pressure, not intake air temperature (bins 12 / 14).
- `fuel_correction_upper_limit` = a maximum fuel quantity limit; `timing_limit_lower` (ROM 0x5c306 = 5888) is its no-limit value (bin 09).
- `cold_start_*` / `fuel_coldStart_*` at 0x5139b8-0x513ddc = a coolant-overheat derate (bin 14).
- `injection_timing_factor_cyl2/3/4_*` / `injection_timing_demand_cyl*` = the intake-temperature / coolant / boost / barometric components, not cylinders (bin 05).

## Duplicate names in global_variables.csv

- `fuel_demand_offset_correction` at 0x0040a550 and 0x0040b22a (bin 13).
- `sensor_channel7_fault_status` at 0x0040be18 and 0x0040be3a (bin 16).

## Tables left unnamed (45)

Their lookups were skipped: an input of unknown units, an untraced output, or a flat / all-zero table with no
shape. The skip reasons are in the campaign result files; re-run the naming for a lookup once its input or
output is named.

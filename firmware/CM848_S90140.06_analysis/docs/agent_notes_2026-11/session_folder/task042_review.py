"""Task 042: correct the P0088 pairing and append the review findings."""
import sys

p = sys.argv[1] + "/work/tasks/042-table-campaign-rename-leads.md"
t = open(p).read()
old = "| rail pressure diagnostics (fault bit 303 = P0088) | bins 07 / 13 |"
new = ("| rail pressure diagnostics (fault bit 303 = P0088) / a no-injection pressure check (fault 58 = P1222 - "
       "verification corrected the P0088 pairing for engine_camSync_referenceCheck_update) | bins 07 / 13 |")
assert t.count(old) == 1, "lead row"
t = t.replace(old, new)
t += """
### Review of the rename wave (2026-11-16)

- **Second pass:** `cm848_calculateAuxiliaryInjectionQuantityLimit` (the function's result caps
  `auxiliary_injection_quantity`; its terms are `injection_quantity_auxiliary_coolant_limit` / `_boost_limit`, like
  the tables), `cm848_calculateGovernorCompensatorCoefficients` (a bilinear-transform pole a and (a + 1024) / 2 -
  "PID gains" claimed more than the code shows), `fuel_pressure_governor_demand_limit_at_governed_speed` /
  `..._check_minimum_coolant_temperature` (governor mode 11 = governed speed, only probably idle),
  `oil_change_monitor_engine_power_accumulator_cal` (0x3fee3e: "soot" was only by elimination; the address is
  time-shared - the boot ROM uses byte 0 as its SCI diagnostic timeout counter).
- **Independence check:** 155 of the 234 renamed globals are used only inside the verified functions; the outside
  users of the rest fit their names (PGN 65504 sends `main_injection_timing`, the PCI fuel-used message reads
  `main_injection_pulse_width`, the charging chain uses `alternator_field_regulator_state`, ...).
- **Decoded:** fault 411 = P2609; `fuel_pressure_limp_home_active_flag` triggers = P0193 / P0192 / P0088 / P0251 +
  faults 264 / 265 (no DTC slot) + two fault reaction requests.
- **e2m block layout matches CM848 RAM by relative offset (verified for two blocks):** e2m Pilot_Fuel_Quantity /
  RPM_With_Hyst / Pilot_Fuel_State at 0x01806A00 + 0x02 / 0x0C / 0x1E = CM848 0x40b938 + 0x02 / 0x0C / 0x1E (same
  scales), and HPCR_Duration_Main_Injection / _Pilot1 / _Aux at 0x01805B00 + 0 / 2 / 4 = CM848 0x40b85c / 5e / 60
  (0.4 us). Names that lean on e2m words: the oil change monitor, the all-speed governor no-load fuel, the wastegate
  (CWG) monitor and G1b's quantity / on-time blocks.
- **CM550 shares three renamed names (cross-firmware links now broken; CM550 semantics not checked):**
  `crank_sync_threshold` (CM550 0x80707a), `fuel_timing_blend_factor` (0x80c9aa), `j1939FormatMultiFrameResponse`
  (0x2f632). Check the CM550 counterparts before renaming them to the CM848 names.
- **Duplicate names that predate this wave (not fixed):** globals `cruise_speed_setpoint_b`,
  `cruise_speed_target_working`, `engine_data_log_buffer`, `engine_data_log_read_ptr`, `fuel_demand_mode_code`,
  `fuel_demand_rate_output`, `fuel_demand_rpm_factor`, `governor_setpoint_table_ptr`, `governor_speed_error_delta`,
  `injection_timing_compensation_lower_cal`, `j1939_tsc1_active_flag`, `protection_confirm_counter_a` / `_b`,
  `switchD`, `USIU_PITR`, `USIU_RTCAL`; functions `cm848_addCoolantCalEntry`, `cm848_emptyStubFunction`,
  `cm848_processFaultIncrement`, `emptyStubFunction3`, `mpc555_updateSensorDiagnosticFlags`.
- Pre-existing underscore variants (dwords typed word in the ROM-to-RAM window): `_fuel_pressure_setpoint_offset_slewed`
  (0x3fd0c6), `_injection_quantity_pilot_slewed_q16` (0x3fd104).
"""
open(p, "w").write(t)
print("ok")

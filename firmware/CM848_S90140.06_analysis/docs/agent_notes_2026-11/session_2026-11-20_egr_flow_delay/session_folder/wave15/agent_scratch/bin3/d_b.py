"""Rows 33-46: e2m blocks 12A6, 16A2, 1901, 1A1A, 1A1B."""

ROWS = {}

RETYPED = " | retyped word -> i16 2026-11-20 (e2m signed, every load lha)"


def rename(address, new, evidence, code_quote, comment):
    ROWS[address] = {"verdict": "confirmed", "new": new, "evidence": evidence, "code_quote": code_quote, "comment": comment}


def keep(address, e2m_note):
    ROWS[address] = {"verdict": "keep", "e2m_note": e2m_note}


# ---- 12A6 ----
rename(
    "0x003feebe",
    "scheduler_overrun_count_cal",
    "e2m 12A6 +0 Executive_Timing_Overflows [SSECTMOV] (DEC, 0 in the dump): main_loop adds 1 when a scheduler frame's measured time exceeds task_execution_time_threshold; 0x3feebe is EEPROM 0x1a3c inside the EEPROM mirror (0x3fd482-0x3feec1), so the name needs _cal; the second record resolving here, e2m 1930 +18 BTR_Denominator, is the known 1930 drift",
    "main_loop: scheduler_overrun_count = scheduler_overrun_count + 1;",
    "EEPROM 0x1a3c - e2m 12A6 +0 Executive_Timing_Overflows '[SSECTMOV] Number of times which frame overflow has occured in executive.' (DEC, 0..65535; 0 in the dump): main_loop adds 1 each time the measured time of a scheduler frame (TBLr - timer_base_snapshot) exceeds task_execution_time_threshold, "
    "while algorithm_enable_flags_18_cal.executive_timing_enable is set (the same test also counts the overrun in the frame's own statistics word). EEPROM mirror (0x3fd482-0x3feec1), so _cal. The second e2m record at this address, 1930 +18 BTR_Denominator, is the known 1930 drift.",
)

# ---- 16A2 ----
rename(
    "0x0040a3e0",
    "wastegate_duty_turbocharger_speed_derate_derivative_term",
    "e2m 16A2 +22 TGC_Turbo_Deriv_Term (UNITLESS, signed, 1/32 per count, -800..800): cm848_calculateWastegateDutyRequest stores the turbocharger speed change x fuel_demand_delta_scale_cal clamped to +-0x6400 (= +-800) in it and subtracts it from the speed error x gain to form first_error_proportional_derivative_term; governor_* is the wrong domain; typed word but the record is signed and the code casts (short): i16 candidate (only an sth store, no load to prove it)",
    "cm848_calculateWastegateDutyRequest: governor_pid_adjustment_output = (word)iVar8;",
    "e2m 16A2 +22 TGC_Turbo_Deriv_Term 'Turbo speed limiter derivative term' (UNITLESS signed, 1/32 per count, -800..800; -25 in the dump): the derivative term of the turbocharger speed derate loop of the wastegate duty controller. "
    "cm848_calculateWastegateDutyRequest stores the change of turbocharger_speed since the last pass x fuel_demand_delta_scale_cal x 32 / 320000, clamped to +-0x6400, in it and subtracts it from (charge_flow_turbocharger_speed_derate_limit - turbocharger_speed) x the error gain x throttle_rate_pid_gain_cal / 64000 "
    "to form wastegate_duty_controller_state.first_error_proportional_derivative_term (e2m 16A2 +10 TGC_Turbo_Spd_Drt_Error). Typed word; the record is signed and the code reads it as (short).",
)
rename(
    "0x0040a3e2",
    "wastegate_duty_compressor_outlet_temperature_derate_error_gain",
    "e2m 16A2 +24 TGC_COT_Drt_SET_Gain (UNITLESS, 1/64 per count, 64 = 1.0 in the dump): cm848_calculateWastegateDutyRequest looks the compressor outlet temperature derate error up in wastegate_duty_second_error_gain_by_error_axis / _values into it and multiplies the error by it to form wastegate_duty_compressor_outlet_temperature_derate_error_term; governor_* is the wrong domain",
    "cm848_calculateWastegateDutyRequest: uVar6 = iVar7 * (uint)governor_trim_lookup_result;",
    "e2m 16A2 +24 TGC_COT_Drt_SET_Gain 'COT limiter error-based gain' (UNITLESS 1/64 per count, 0..400; 64 in the dump = 1.0): the error-based gain of the compressor outlet temperature derate loop of the wastegate duty controller. "
    "cm848_calculateWastegateDutyRequest looks it up from (charge_flow_compressor_outlet_temperature_derate_limit - compressor_outlet_temperature) in wastegate_duty_second_error_gain_by_error_axis / _values, multiplies the error by it and by fuel_flow_rate_gain_cal / 16384, "
    "and subtracts the derivative term to form wastegate_duty_compressor_outlet_temperature_derate_error_term (e2m 16A2 +28 TGC_COT_Drt_Error).",
)

# ---- 1901 ----
keep(
    "0x00409fa4",
    "e2m 1901 +30 C_BT_Max_Counts 'Debounce counter limit for BT key-on fault'",
)

# ---- 1A1A / 1A1B : the TPE charge temperature estimate ----
MAPS = (
    ("0x004051f8", "boost1", "alpha_1", "+2", "C_TPE_CIT_Ref_Alpha1", "Alpha1 CIT reference", 1),
    ("0x004051fa", "boost2", "chi_2", "+4", "C_TPE_CIT_Ref_Chi2", "Chi2 CIT Reference", 2),
    ("0x004051fc", "boost3", "chi_3", "+6", "C_TPE_CIT_Ref_Chi3", "Chi3 CIT Reference", 3),
    ("0x004051fe", "boost4", "chi_4", "+8", "C_TPE_CIT_Ref_Chi4", "Chi4 CIT Reference", 4),
)

rename(
    "0x004051f6",
    "compressor_inlet_temperature_reference_alpha_0",
    "e2m 1A1A +0 C_TPE_CIT_Ref_Alpha0 (DEG_F, signed, 4928 = 77.0 F in the dump): cm848_processBoostProtectionMode passes it as the base (alpha 0) value, the third argument, of cm848_interpolateAlphaChiValue for the compressor inlet temperature reference; the old name said injection timing filter coefficient (wrong domain) and carried _cal in the RAM region",
    "cm848_processBoostProtectionMode: (unaff_r31,param_2,(int)injection_timing_filter_coeff_cal,",
    "e2m 1A1A +0 C_TPE_CIT_Ref_Alpha0 'Alpha0 CIT reference' (DEG_F 1/64 signed, -50..350; 4928 = 77.0 F in the dump): the alpha 0 base value of the compressor inlet temperature (CIT) reference of the charge temperature estimate. "
    "cm848_processBoostProtectionMode passes it as the third argument of cm848_interpolateAlphaChiValue, which blends the chi interpolated value of the map references (e2m 1A1A +2..+8, selected by combustion_chi_lower_map_number / combustion_chi_upper_map_number) toward it while alpha is below 100 percent; "
    "the result is e2m 1A1B +2 TPE_CIT_Ref (compressor_inlet_temperature_reference)." + RETYPED,
)
for address, old_tag, suffix, off, record, desc, number in MAPS:
    rename(
        address,
        f"compressor_inlet_temperature_reference_{suffix}",
        f"e2m 1A1A {off} {record} (DEG_F, signed, 4928 = 77.0 F in the dump): cm848_processBoostProtectionMode reads it as the reference of combustion chi map number {number} (combustion_chi_lower_map_number / _upper_map_number == {number}) for the compressor inlet temperature reference; the old name said injection timing offset boost (wrong domain) and carried _cal in the RAM region",
        f"cm848_processBoostProtectionMode: param_2 = (int)injection_timing_offset_{old_tag}_cal;",
        f"e2m 1A1A {off} {record} '{desc}' (DEG_F 1/64 signed, -50..350; 4928 = 77.0 F in the dump): the compressor inlet temperature (CIT) reference of combustion chi map number {number} (the e2m labels the four chi maps Alpha1 / Chi2 / Chi3 / Chi4 at +2 / +4 / +6 / +8). "
        f"cm848_processBoostProtectionMode picks it when combustion_chi_lower_map_number / combustion_chi_upper_map_number is {number} and passes the lower and upper map values to cm848_interpolateAlphaChiValue; the result is e2m 1A1B +2 TPE_CIT_Ref (compressor_inlet_temperature_reference)." + RETYPED,
    )

rename(
    "0x00405200",
    "charge_temperature_estimate_filter_coefficient",
    "e2m 1A1A +A C_TPE_Charge_Tmptr_Est_Fil_Cnst (UNITLESS, 1/65536, 65404 = 0.998 in the dump): the coefficient of the cm848_signedFirstOrderFilter record fuel_demand_boost_offset_filter (cm848_initBoostProtectionState points .coefficient at it) that filters the charge temperature estimate; the old name said fuel demand boost offset (wrong domain)",
    "cm848_initBoostProtectionState: fuel_demand_boost_offset_filter.coefficient = &fuel_demand_boost_offset_filter_coefficient;",
    "e2m 1A1A +A C_TPE_Charge_Tmptr_Est_Fil_Cnst 'Filter constant for charge temperature' (UNITLESS 1/65536 per count, 0..1; 65404 = 0.998 in the RAM dump): coefficient of the cm848_signedFirstOrderFilter record fuel_demand_boost_offset_filter (read through its coefficient pointer as a 16-bit word; cm848_initBoostProtectionState sets the pointer): "
    "the weight of the previous value, 0 = no filtering. cm848_processBoostProtectionMode filters the clamped charge temperature estimate through it into charge_temperature_estimate.",
)
rename(
    "0x00405202",
    "charge_temperature_estimate_offset",
    "e2m 1A1A +C C_TPE_Charge_Tmptr_Est_Offset (DEG_F, signed, 0 in the dump): the additive offset of the charge temperature estimate sum in cm848_processBoostProtectionMode; the old name said fuel demand timing offset (wrong domain) and carried _cal in the RAM region",
    "cm848_processBoostProtectionMode: (int)fuel_demand_timing_scale_cal >> 0xb) + (int)fuel_demand_timing_offset_cal +",
    "e2m 1A1A +C C_TPE_Charge_Tmptr_Est_Offset 'Offset used for Charge Temperature Estimation' (DEG_F 1/64 signed, -50..50; 0 in the dump): added to the charge temperature estimate. cm848_processBoostProtectionMode computes "
    "((ambient_air_temperature_selected - compressor_inlet_temperature_reference) x charge_temperature_estimate_compressor_inlet_temperature_gain >> 11) + this + charge_temperature_combustion_reference, clamps it to -50..350 F and filters it into charge_temperature_estimate." + RETYPED,
)
rename(
    "0x00405204",
    "charge_temperature_estimate_compressor_inlet_temperature_gain",
    "e2m 1A1A +E C_TPE_Charge_Tmptr_Est_CIT_Gain (UNITLESS, signed, 1/2048 per count, 2048 = 1.0 in the dump): the multiplier of (ambient_air_temperature_selected - compressor_inlet_temperature_reference) in the charge temperature estimate (>> 11 in cm848_processBoostProtectionMode); the old name said fuel demand timing scale (wrong domain) and carried _cal in the RAM region",
    "cm848_processBoostProtectionMode: (int)fuel_demand_timing_scale_cal >> 0xb) + (int)fuel_demand_timing_offset_cal +",
    "e2m 1A1A +E C_TPE_Charge_Tmptr_Est_CIT_Gain 'Charge temperature estimate multiplier' (UNITLESS 1/2048 per count, signed, 0..10; 2048 in the dump = 1.0): the gain on the compressor inlet temperature (CIT) term of the charge temperature estimate. "
    "cm848_processBoostProtectionMode multiplies (ambient_air_temperature_selected - compressor_inlet_temperature_reference) by it and shifts right by 11, then adds charge_temperature_estimate_offset and charge_temperature_combustion_reference." + RETYPED,
)
rename(
    "0x0040a452",
    "charge_temperature_estimate",
    "e2m 1A1B +0 Charge_Tmptr_Est (DEG_F, signed, 4692 = 73.3 F in the dump): the filtered estimate written by cm848_processBoostProtectionMode and read by cm848_filterAndSelectIntakeManifoldTemperature as the backup intake manifold temperature (source 1); the old name said fuel demand boost offset (wrong domain)",
    "cm848_filterAndSelectIntakeManifoldTemperature: intake_manifold_temperature_filtered = fuel_demand_boost_offset_filtered;",
    "e2m 1A1B +0 Charge_Tmptr_Est 'Estimated Charge Tmptr' (DEG_F 1/64 signed, -50..350; 4692 = 73.3 F in the dump): the charge temperature estimate of the estimate module. cm848_processBoostProtectionMode filters the clamped sum "
    "((ambient_air_temperature_selected - compressor_inlet_temperature_reference) x charge_temperature_estimate_compressor_inlet_temperature_gain >> 11) + charge_temperature_estimate_offset + charge_temperature_combustion_reference through the record fuel_demand_boost_offset_filter into it; "
    "cm848_filterAndSelectIntakeManifoldTemperature uses it as the backup source (intake_manifold_temperature_filtered_source 1) when the sensor path is faulted." + RETYPED,
)
rename(
    "0x0040a454",
    "compressor_inlet_temperature_reference",
    "e2m 1A1B +2 TPE_CIT_Ref (DEG_F, signed, 4928 = 77.0 F in the dump; the e2m text 'Offset for Charge Pressure Estimate' does not fit the unit): the cm848_interpolateAlphaChiValue result over the C_TPE_CIT_Ref_* values, subtracted from ambient_air_temperature_selected in the charge temperature estimate; the old name said injection timing offset (wrong domain); typed word but the record is signed and the code casts (short): i16 candidate (only an sth store, no load to prove it)",
    "cm848_processBoostProtectionMode: iVar1 = ((int)(short)(ambient_air_temperature_selected - injection_timing_offset_filtered) *",
    "e2m 1A1B +2 TPE_CIT_Ref 'Offset for Charge Pressure Estimate' (the e2m text; the unit is DEG_F, 1/64 signed, -50..350, and the code uses it as a temperature; 4928 = 77.0 F in the dump): the compressor inlet temperature (CIT) reference of the charge temperature estimate. "
    "cm848_processBoostProtectionMode interpolates it from the five C_TPE_CIT_Ref_* values (compressor_inlet_temperature_reference_alpha_0 / _alpha_1 / _chi_2 / _chi_3 / _chi_4) with cm848_interpolateAlphaChiValue, by the chi and alpha of the combustion reference, "
    "and subtracts it from ambient_air_temperature_selected (the CIT source here) before the gain. Typed word; the record is signed and the code reads it as (short), but the only access is an sth store.",
)

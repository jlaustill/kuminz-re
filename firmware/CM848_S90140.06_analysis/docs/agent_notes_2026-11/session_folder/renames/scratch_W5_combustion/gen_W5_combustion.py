import json, re, sys

OUT = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-typing-arrays/firmware/CM848_S90140.06_analysis/output/'
RES = '/home/linux/.claude/jobs/d55ae3c6/tmp/renames/result_W5_combustion_rom.jsonl'
rows = []


def A(a):
    return '0x%08x' % a


def F(addr, old, new, plate, evidence, verdict='confirmed'):
    r = {'kind': 'function', 'address': A(addr), 'old': old, 'verdict': verdict}
    if new:
        r['new'] = new
    if plate:
        r['plate_comment'] = plate
    r['evidence'] = evidence
    rows.append(r)


def G(addr, old, new, evidence, verdict='confirmed'):
    r = {'kind': 'global', 'address': A(addr), 'old': old, 'verdict': verdict}
    if new:
        r['new'] = new
    r['evidence'] = evidence
    rows.append(r)


def SF(struct, old, new, evidence):
    rows.append({'kind': 'struct_field', 'struct': struct, 'old': old, 'new': new, 'evidence': evidence})


def N(text):
    rows.append({'kind': 'note', 'text': text})


E2M = 'e2m'

# ---------------------------------------------------------------- functions
F(0x14080, 'mpc555_initPressureSensorFilterState', 'cm848_initializeIntakeTemperatureFilterStates',
  'Boot initialisation of the intake temperature estimate: copies the intake manifold temperature sensor value (sensor channel 9, 1/64 deg F) into sensor_channel9_pressure_snapshot and fuel_demand_boost_offset, loads the two Q16 filter accumulators with it (coefficient pointers to 0x405206) and sets fuel_demand_phase_state from the sensor fault status (0 or 1 -> 0, 2 -> 2). (was mpc555_initPressureSensorFilterState)',
  'Code: the value stored in fuel_demand_boost_offset is sensor_channel9_pressure_value (slot 9 = intake manifold temperature in the firmware/CLAUDE.md slot table, SPN 105); the RAM dump holds 2604 / 2602 = 40.7 deg F, a temperature, not a pressure. fuel_demand_boost_offset is the intake temperature that cm848_calculateOffNominalChargeTemperatureAdjustment subtracts from the charge temperature reference. Medium confidence: the later users of the two filter states were not traced.')

F(0x1410c, 'cm848_applyCombustionTimingLimits', 'cm848_applyCombustionTimingLimits', None,
  'Name and plate comment are right: this is the start-of-injection limit stage of the combustion limits (e2m CBL +0A max limit / +0C min limit / +0E reference after limits / +18 user increment flag, all confirmed by the code and the dump: 384 / 43 / 68 / 0).')

F(0x1429c, 'cm848_selectFuelDemandOverride', 'cm848_selectCombustionFuelCommand',
  'Selects the combustion fuel command injection_quantity_combustion_command: fuel_demand_limit_copy (the fuel reference after the off-nominal stage), or the calibrated override value (0x405236) when engine_feature_enable_flags bit 1 (2) is set. Its reader cm848_selectFuelDemandSource takes it as the base of the cranking / cold-start fuel arbitration. (was cm848_selectFuelDemandOverride)',
  'Code: copy of fuel_demand_limit_copy unless bit 1 of engine_feature_enable_flags selects the calibration; the only reader is the fuel arbitration cm848_selectFuelDemandSource. e2m: CBL_Fuel_Cmd (+04) and T_CBL_Fuel_User_Override (bit 1 of Word 6), C_CBL_Fuel_Override_Value. Dump 1030 = fuel_demand_limit_copy.')

F(0x142d0, 'cm848_selectMainBaseTimingOverride', 'cm848_selectMainBaseTimingOverride', None,
  'Name and plate comment are right (e2m CBL_SOI_Cmd +08, T_CBL_SOI_User_Override = bit 4, C_CBL_SOI_Override_Value 0x40523a; dump 68 = the reference, no override).')

F(0x14304, 'cm848_setFuelStatusFlags', 'cm848_setTimingIncrementFlags',
  'Sets bits of fuel_demand_mode_flags for the timing increments active in this pass: 0x40 when the fuel-limited increment is added (injection_timing_fuel_limited_adjustment_active_flag), 0x20 when the off-nominal timing adjustment is non-zero (injection_timing_reference_adjustment_active_flag), 0x10 when the user increment is active (injection_timing_user_increment_active_flag). The word is cleared again at the end of cm848_calculateCombustionTimingReference. (was cm848_setFuelStatusFlags)',
  'Code: three flag tests OR bits 0x40 / 0x20 / 0x10 into fuel_demand_mode_flags (0x40a2f4); cm848_calculateFuelDemandTimingOffset (now cm848_calculateCombustionTimingReference) clears the word. e2m: Timing_State_Incr_Before_CBL (+12) is described as the algorithms that adjusted timing before the combustion limits, which is what the three flags are; the +12 slot itself (0x40a478) has no access in this build.')

F(0x14374, 'cm848_calculateRpmLoadLimit', 'cm848_limitMassChargeFlowReference',
  'Looks up the density-based mass charge flow limit (engine speed x intake air density engine_load_input_value, 1/128 lb/min) into mass_charge_flow_density_limit, and limits the mass charge flow reference cached in fuel_demand_rate_raw_cached into mass_charge_flow_combustion_limited_reference: by the density limit when boost_fuel_mode_active is set, otherwise by a fixed cap of 51200 (400 lb/min). (was cm848_calculateRpmLoadLimit)',
  'Code: 2-D lookup with y = engine_load_input_value, which cm848_mainLoop_step_2 computes as (a pressure word x constant) / (temperature + 460 R) = an air density (dump 1166 x 6.1e-5 = 0.071 lbm/ft3, the density of air at the 26 inHg barometer on slot 3); grid values 3200..9600 (25..75 lb/min); the limited result feeds cm848_selectMassChargeFlowCommand. Dump: reference 556, density limit 4733, result 556. e2m: CBL_MCF_Ref (+14) and CBL_Density_MCF_Limit (+16). The lead reading (load rate cap = mass charge flow limit) holds.')

F(0x14430, 'cm848_selectFinalLoadLimit', 'cm848_selectMassChargeFlowCommand',
  'Selects the mass charge flow command mass_charge_flow_combustion_command: the limited mass charge flow reference, or the calibrated override value (0x405238) when engine_feature_enable_flags bit 2 (4) is set. Its reader copies it into the boost / charge chain (cm848_selectTemperatureTrimValue). (was cm848_selectFinalLoadLimit)',
  'Code: copy of fuel_demand_load_rate_cap unless bit 2 selects the calibration. e2m: CBL_MCF_Cmd (+06), T_CBL_MCF_User_Override (bit 2), C_CBL_MCF_Override_Value. Dump 556.')

F(0x14464, 'cm848_selectFuelLoadOverride', 'cm848_selectEgrFractionCommand',
  'Selects the EGR fraction command egr_fraction_combustion_command: the cached EGR fraction reference (fuel_demand_high_limit_cached, Q13), or the calibrated override value (0x405234) when engine_feature_enable_flags bit 0 (1) is set. Its only reader is cm848_calculateTurboBlendOutput. (was cm848_selectFuelLoadOverride)',
  'Code: copy of fuel_demand_high_limit_cached (itself a copy of the EGR fraction reference, see cm848_calculateCombustionOffNominalReferences) unless bit 0 selects the calibration. e2m: CBL_EGR_Frac_Cmd (+00), T_CBL_EGR_Frac_User_Override (bit 0). Dump 0: every EGR map is zero in this calibration.')

F(0x14498, 'cm848_processFuelLimitCalculations', 'cm848_runCombustionLimits',
  'Entry point of the combustion limits stage: runs cm848_selectCombustionFuelCommand, cm848_applyCombustionTimingLimits, cm848_setTimingIncrementFlags, cm848_selectMainBaseTimingOverride, cm848_limitMassChargeFlowReference, cm848_selectMassChargeFlowCommand and cm848_selectEgrFractionCommand in that order. (was cm848_processFuelLimitCalculations)',
  'Code: the function is exactly those seven calls. e2m: these seven steps write the CBL block (0x01171B00 = 0x40a466) commands for fuel, start of injection, mass charge flow and EGR fraction.')

F(0x144d0, 'mpc555_initFuelLimitTableSizes', 'cm848_initializeCombustionLimitLookupCaches',
  'Sets the six lookup cache words 0x3fa634-0x3fa640 to 2 (the first segment) for the combustion limit lookups: the minimum and maximum timing limit grids and the density-based mass charge flow limit grid of cm848_applyCombustionTimingLimits and cm848_limitMassChargeFlowReference. (was mpc555_initFuelLimitTableSizes)',
  'Code: the stored words are the cached_axis_offsets arguments (&DAT_003fa634, &DAT_003fa638, &DAT_003fa63e) of those lookups; 2 is the start offset of the cached segment search, not a table size. The words are in the time-shared window 0x3F9800-0x3FDB30; only the function is renamed here, no word is renamed or retyped.')

F(0x14508, 'cm848_compareForFuelMapSelection', 'cm848_selectChiSourceCode',
  'Returns the chi source code of the larger chi: 3 (coolant temperature source) when the first chi (air density source) is smaller than the second, otherwise 1 (air density source). Only caller cm848_determineBaseChi. (was cm848_compareForFuelMapSelection)',
  'Code: return 3 if p1 < p2 else 1; the caller passes the chi words of the density record and the coolant temperature record and stores the result as the base chi source (combustion_base_chi_source_code, 1 in the dump).')

F(0x14528, 'cm848_filterInputValue', 'cm848_interpolateAlphaChiValue',
  'Alpha-chi interpolation used by the combustion reference and by the pilot / auxiliary timing and quantity families: interpolates linearly from the value of the lower map (param_1) to the value of the upper map (param_2) as the chi (param_6, in hundredths) runs from lower map number x 100 (param_4) to upper map number x 100 (param_5), holding the end values outside; then, unless alpha (param_7, percent) is 100, blends the result with the alpha 0 base map value (param_3). (was cm848_filterInputValue)',
  'Code: the formula as written (value = v1 + (v2 - v1) x (chi - lower x 100) x 100 / (upper x 100 - lower x 100) / 100; then base + (value - base) x alpha / 100). It is a map interpolation, not a filter. e2m names for the two parameters: chi (CBR_Chi_Value, 1.00..4.00) and alpha (CBR_Alpha). The caller words are named combustion_chi_hundredths and combustion_alpha_percent.')

F(0x14610, 'cm848_calculateFuelDemandMode1', 'cm848_calculateNitrogenOxidesTargetReference',
  'Alpha-chi interpolation of the five NOx target maps (engine speed x fuel reference, unsigned): evaluates only the maps selected by the chi map numbers and the base map, and blends them with cm848_interpolateAlphaChiValue into nitrogen_oxides_target_combustion_reference. The result is scaled by the off-nominal adjustments in cm848_calculateOffNominalCompensation. (was cm848_calculateFuelDemandMode1)',
  'Code: same five-map structure as the other reference functions, output 0x40a490 read only by cm848_calculateOffNominalCompensation, which multiplies it by the composite adjustment and the timing adjustment scale. e2m: the block position (CBR_NOx_Target_Ref +10, maps CBR_NOx_Alpha0..Chi4 +48..+50) and CBO_bsNOx = it adjusted for off-nominal conditions; dump 5120 = 2.5 g/hp-hr at 1/2048 with all maps flat. The meaning NOx rests on the e2m; the code proves a reference value scaled by the off-nominal stage.')

F(0x149a4, 'cm848_calculateFuelDemandMode2', 'cm848_calculateChargeTemperatureReference',
  'Alpha-chi interpolation of the five charge temperature maps (engine speed x fuel reference, signed, 1/64 deg F): evaluates the maps selected by the chi map numbers and the base map and blends them into charge_temperature_combustion_reference. cm848_calculateOffNominalChargeTemperatureAdjustment compares it with the intake temperature. (was cm848_calculateFuelDemandMode2)',
  'Code: signed lookups (flag 4); the result minus fuel_demand_boost_offset (the intake temperature, 2602 in the dump against 2601 on the slot 9 sensor) is clamped and looked up in cm848_calculateOffNominalChargeTemperatureAdjustment; dump 7360 = 115 deg F with all five maps flat. e2m: CBR_Charge_Tmptr_Ref (+0E) and CBO_Delta_Charge_Tmptr = reference minus filtered intake temperature.')

F(0x14d38, 'cm848_calculateFuelDemandTimingOffset', 'cm848_calculateCombustionTimingReference',
  'Calculates the start of injection reference: looks up the four timing maps (engine speed x fuel reference) and the base map, blends them by chi and alpha into injection_timing_combustion_reference, adds the fuel-limited adjustment table (injection_timing_fuel_limited_adjustment) when alpha is 0 and the fuel is limited, and also interpolates the base-chi value injection_timing_combustion_reference_at_base_chi. Clears fuel_demand_mode_flags. (was cm848_calculateFuelDemandTimingOffset)',
  'Code: writes 0x40a488 (twice) and 0x40a486, all four map outputs 0x40a4d4-0x40a4da are always evaluated; the reference feeds cm848_applyOffNominalTimingAdjustment and the CBL limits via fuel_correction_output. Dump: all five maps 68 = 8 deg. e2m: CBR_SOI_Ref (+08), CBR_Base_Chi_SOI_Cmd (+06), CBR_OFC_Limit_SOI_Alpha0 (+1A), maps +52..+5A. Confirmed by the lead note for 0x40a488 and the four maps.')

F(0x150b0, 'cm848_calculateFuelDemandMode3', 'cm848_calculateMassChargeFlowReference',
  'Alpha-chi interpolation of the five mass charge flow maps (engine speed x gross fuel, 1/128 lb/min): evaluates the maps selected by the chi map numbers and the base map and blends them into mass_charge_flow_combustion_reference. (was cm848_calculateFuelDemandMode3)',
  'Code: y input is injection_quantity_combustion_gross (fuel_table_load_axis), not the fuel reference; grid values 512..6912 = 4..54 lb/min at 1/128; output 0x40a48a is cached for the density limit and used as the air flow in the air-fuel ratio of cm848_calculateOffNominalOxygenFractionAdjustment. e2m: CBR_MCF_Ref (+0A), maps +3E..+46. Dump 556.')

F(0x15444, 'cm848_calculateFuelDemandBlendTables', 'cm848_calculateEgrFractionReference',
  'Alpha-chi interpolation of the five EGR fraction maps (engine speed x gross fuel, Q13): blends them into egr_fraction_combustion_reference, which is 0 while the fuel is limited or the EGR-off flag is set, and also into egr_fraction_combustion_reference_at_base_chi (base chi, alpha 100 percent). (was cm848_calculateFuelDemandBlendTables)',
  'Code: 0x2000 minus the result is used as a Q13 complement in cm848_calculateOffNominalOxygenFractionAdjustment, the base-chi value is the weight of a temperature mixture in cm848_fuelDemandBlendCalculation; all five maps are zero in this calibration (no EGR hardware), so both outputs are 0 in the dump. e2m: CBR_EGR_Frac_Ref (+0C), CBR_Base_Chi_EGR_Frac_Cmd (+62), maps +34..+3C.')

F(0x15760, 'cm848_lookupFuelDemandRpmTables', 'cm848_calculateCombustionChiMaximumFuel',
  'Interpolates the maximum fuel curve by chi and alpha: looks up the four 1-D maximum fuel curves selected by the chi map numbers and the base curve against engine speed, and blends them with cm848_interpolateAlphaChiValue into injection_quantity_combustion_chi_maximum. (was cm848_lookupFuelDemandRpmTables)',
  'Code: five 1-D lookups against fuel_map_rpm_axis_cal (curve values 1030..2082 counts = 70..141 mm3), blended exactly like the other references; the result is the second term of injection_quantity_combustion_maximum_limit and the full-load fuel read by six functions outside the combustion reference. e2m: CBR_Max_Chi_Fuel (+6A), curves CBR_Max_Fuel_Alpha0..Chi4 (+72..+7A). Dump 1030 (the Chi4 curve start).')

F(0x15a24, 'cm848_calculateFuelLimitSource', 'cm848_calculateCombustionGrossFuel',
  'Calculates the gross fuel and its maximum limit: looks up the density-based maximum fuel (engine speed x intake air density), keeps the smaller of it and the chi maximum fuel (plus fuel_demand_offset_correction when fuel_feature_control_flags bits 0x80 / 0x40 are set) as injection_quantity_combustion_maximum_limit (source code 52 density / 53 chi), subtracts fuel_demand_offset_load_delta_correction from the arbitrated demand when it is at or above the adjustment threshold, clamps it to 0..5888 (or the override calibration when engine_feature_enable_flags bit 10 is set, source 55) and limits it by the maximum limit into injection_quantity_combustion_gross. (was cm848_calculateFuelLimitSource)',
  'Code: all steps as listed (the demand source is fuel_demand_arbitrated_snapshot; governor_fuel_mode_working carries the source code 52 / 53 / 55). Dump: density maximum 1575, chi maximum 1030, offset 256 (flag 0x40), limit 1286, gross 1030. e2m: CBR_Density_Max_Fuel (+6E), CBR_Max_Fuel_Limit (+7C), CBR_Gross_Fuel (+00), CBR_SOI_Adj_Fuel_Active (+18), CBR_Gross_Fuel_Before_Adj (+1C), C_CBR_SOI_Adj_Fuel_Thd and T_CBR_Gross_Fuel_User_Override (bit 10).')

F(0x15bd8, 'cm848_selectFuelLimitWithFiltering', 'cm848_calculateCombustionFuelReference',
  'Calculates the fuel reference injection_quantity_combustion_reference: the gross fuel capped by fuel_demand_load_axis_cap (source 54) and by fuel_demand_limit_input (source 58), or the override calibration (0x4059ee) when engine_feature_enable_flags bit 9 (0x200) is set (source 23). Also computes the gross-to-limit ratio (Q13) and sets or clears injection_quantity_combustion_limited_flag with the on / off ratios 17203 / 9830 as hysteresis. (was cm848_selectFuelLimitWithFiltering)',
  'Code: as listed; nothing is filtered. Dump: gross 1030, limit 2944, ratio 2866 = 1030 / 2944 x 8192, flag 0. e2m: CBR_Fuel_Ref (+04) and CBR_Fuel_Ref_State (+70), CBR_FCLR_Ref (+02) with C_CBR_FCLR_On / C_CBR_FCLR_Off, OFC_Lmtd_Flag, T_CBR_Fuel_Ref_User_Override (bit 9).')

F(0x15d2c, 'cm848_interpolateTableWithoutCache', 'cm848_interpolateTableWithoutCache', None,
  'Name and plate comment are right (stateless interpolation, only caller cm848_lookupProtectiveChi, used for the chi / level axis conversions).')

F(0x15e08, 'cm848_interpolateFuelMapTable', 'cm848_lookupProtectiveChi',
  'Determines the chi that one protective source asks for: looks up the chi for the input (cached), converts it to the level of the second table pair, raises the level to fuel_demand_min_threshold x 2, converts back to a chi and keeps the larger chi, then looks up the low and high map numbers of that chi. Writes (desired chi, chi, level, low map number, high map number) to the result record. Called for the intake air density and for the coolant temperature. (was cm848_interpolateFuelMapTable)',
  'Code: lookupTableInterpolation of the input, three stateless interpolations (chi to level, level to chi, chi to the two map number tables fuel_map_*_filter_d / _c) and a max; the two sources have density axis 655..1638 (0.04..0.1 lbm/ft3) and a signed coolant axis -3200..16000 = -50..250 deg F, chi values 400..100, level axis 2048..8192, map numbers 1..4. e2m: C_CBR_Inlet_Density_* and C_CBR_Coolant_Tmptr_* chi / level / high / low table sets. The level reading is the e2m unit (G/HP*HR).')

F(0x15f34, 'cm848_processFuelMapInterpolation', 'cm848_determineBaseChi',
  'Determines the base chi (the determine_chi() step of the combustion reference): evaluates the air density source (engine_load_input_value) and the coolant temperature source (fuel_demand_boost_input) with cm848_lookupProtectiveChi, keeps the record with the larger chi (cm848_selectChiSourceCode: 1 air density, 3 coolant temperature) and stores its desired chi, chi, level, low / high map numbers and source in the combustion_base_chi_* words. (was cm848_processFuelMapInterpolation)',
  'Code: two record lookups and a compare; fuel_demand_boost_input equals the slot 2 coolant temperature (2050 against 2049 in the dump, substitute 190 deg F at 0x40bdae) and its table axis is signed deg F. Dump: engine_load_input_value 1166 gives chi 100 on the density table (chi 400 only below density 786 counts) and the coolant table is flat 100, so the tie keeps source 1; stored chi 100, level 2048 (1.0), low / high map numbers 1 / 2. e2m: CBR_Base_Chi (+5C), CBR_Base_Low_Table / High_Table (+5E / +60), CBR_Base_Desired_Chi (+66), CBR_Base_EL (+68), CBR_Base_Chi_Source (+64).')

F(0x160ac, 'cm848_calculateFuelBlendModeSelection', 'cm848_selectChiAndAlpha',
  'Selects the chi and alpha of the combustion reference: takes the base chi, or the fixed EGR-off or protection chi when fuel_mode_status_flags ask for it (combustion_chi_source_code 10 / 14), or the calibrated override chi (bit 7 of engine_feature_enable_flags; bit 6 picks the full override, source 12, or the single value, source 13); clamps the two map numbers to 1..4 and sets combustion_alpha_percent from the alpha command fuel_blend_coefficient (Q14 -> percent), the override value (bit 5) or 100 (EGR off or chi above the limit). Also sets fuel_blend_state_t.egr_off_flag (bit 8 overrides it). (was cm848_calculateFuelBlendModeSelection)',
  'Code: the branches as listed; the flag bits match the e2m Word 6 user overrides T_CBR_Alpha_User_Override (5), T_CBR_Chi_Selective_Override (6), T_CBR_Chi_User_Override (7), T_CBR_EGR_Off_User_Override (8) and the calibrations at 0x4059d6-0x4059fa match C_CBR_Alpha_Override_Value ... C_CBR_UHC_Charge_Tmptr_Limit in order. Dump: chi 400 from the EGR-off calibration (source 10), alpha 100, both map numbers 4, EGR off because fuel_mode_status_flags bit 1 is set.')

F(0x164ac, 'cm848_processFuelDemandCalculations', 'cm848_runCombustionReference',
  'Entry point of the combustion reference stage: runs cm848_selectChiAndAlpha, cm848_calculateCombustionFuelReference (gross fuel and fuel reference), cm848_calculateEgrFractionReference, cm848_calculateMassChargeFlowReference, cm848_calculateCombustionTimingReference, cm848_calculateChargeTemperatureReference and cm848_calculateNitrogenOxidesTargetReference in that order. (was cm848_processFuelDemandCalculations)',
  'Code: the function is exactly those calls (cm848_calculateCombustionFuelReference runs the gross fuel step first). e2m: these seven steps fill the CBR block 0x0116A500 = 0x40a480.')

F(0x164e4, 'cm848_fuelDemandTableLookup', 'cm848_lookupChiMaximumFuelAtSpeed',
  'Maximum fuel of the chi-interpolated curve at the given engine speed (param_1): the same five 1-D curve lookups and chi / alpha blend as cm848_calculateCombustionChiMaximumFuel, but at an arbitrary speed. Called five times by cm848_calculateChiMaximumFuelAndTorquePoints. (was cm848_fuelDemandTableLookup)',
  'Code: lookupTableInterpolation of fuel_rpm_table_boost1..4_cal and governor_fuel_demand_values_cal at param_1, then cm848_interpolateAlphaChiValue; duplicates the lookup block of cm848_calculateCombustionChiMaximumFuel (a candidate for one shared helper).')

F(0x16724, 'cm848_fuelDemandRpmCorrection', 'cm848_convertFuelToTorqueAtSpeed',
  'Converts a fuel quantity (param_1) at an engine speed (param_2) to a signed value through the speed x fuel grid protection_rpm_correction_yend_cal (axes 620..3500 rpm and 0..140 mm3); used for the torque points of the chi maximum fuel curve. (was cm848_fuelDemandRpmCorrection)',
  'Code: dual-axis lookup, speed against the speed axis, fuel against the fuel axis (the same fuel axis values as the combustion reference maps), signed result (flags 6). The grid is all zero in this calibration, so the torque meaning is not data-checked; it rests on the e2m (CBR_Max_Chi_Torque_At_Point_1..5, FT*LB 0.5, +8C..+94) whose block positions are exactly the five words this function feeds. Medium confidence.')

F(0x16774, 'cm848_lookupProtectionFuelDemand', 'cm848_calculateChiMaximumFuelAndTorquePoints',
  'Calculates the maximum fuel of the chi curve at five engine speed points (cm848_lookupChiMaximumFuelAtSpeed, stored as chi_maximum_fuel_at_point_1..5 of the struct at 0x40a502) and converts each to a torque value (cm848_convertFuelToTorqueAtSpeed, combustion_chi_maximum_torque_at_point_1..5). Called from main_loop. (was cm848_lookupProtectionFuelDemand)',
  'Code: five fuel lookups at five speed inputs, then five conversions; the ten results are written here and read nowhere else (testpoints). Dump fuel points 1030 / 1182 / 1443 / 1607 / 1475 (70..109 mm3), torque points 0. e2m: CBR_Max_Chi_Fuel_At_Point_1..5 (+82..+8A) and CBR_Max_Chi_Torque_At_Point_1..5 (+8C..+94) sit at exactly these addresses. Nothing here is protection.')

F(0x16888, 'mpc555_initFuelDemandTablePointers', 'cm848_initializeCombustionReferenceMapPointers',
  'Boot initialisation of the combustion reference: stores the RAM addresses of the four selectable maps (map 1..4) of the EGR fraction, mass charge flow, start of injection, charge temperature and NOx target references in the pointer words, and sets the lookup cache words of these lookups to 2. (was mpc555_initFuelDemandTablePointers)',
  'Code: 20 pointer stores (0x402f5c ... 0x40471c) and the cache words; every map is 0x260 bytes (19 x 16 words) and the base map follows the three Chi maps, so the order Chi2 < Chi3 < Chi4 < base < map 1 in RAM is the e2m table order. The pointer words and caches are in the time-shared window 0x3F9800-0x3FDB30 and are not renamed here.')

F(0x16a90, 'cm848_calculateFuelInjectionTiming', 'cm848_calculateOffNominalOxygenFractionAdjustment',
  'Calculates the off-nominal oxygen fraction adjustment engine_load_correction_blend: derives the reference air-fuel ratio ((1 - EGR fraction) x mass charge flow reference / fuel flow) and the reference intake oxygen fraction (0x76b = 0.232 minus the EGR dilution term), looks both up in the fuel_correction table, and divides the lookup of the actual value (fuel_load_correction_input) by it in Q13, capped at 0x2000. It does not calculate any injection timing. (was cm848_calculateFuelInjectionTiming)',
  'Code: fuel_demand_rate_complement = 0x2000 - EGR fraction reference; fuel_injection_divisor_base = complement x MCF reference / (fuel_rate_rpm_factor x 64) (rpm x fuel quantity); 0x76b is 23.2 percent, the oxygen fraction of air; ratio of two lookups in the same 11-point table. e2m CBO block: CBO_Air_Fuel_Ratio_Ref (+26), CBO_Intake_Charge_O2_Frac_Ref (+2A), CBO_FSNOx_Ratio_Ref / Actual (+28 / +2C), CBO_O2_Frac_Adj (+24) = engine_load_correction_blend. Medium-high confidence (e2m positions and the arithmetic agree).')

F(0x16c40, 'cm848_calculateManifoldPressureOffset', 'cm848_calculateOffNominalChargeTemperatureAdjustment',
  'Calculates the off-nominal charge temperature adjustment: the charge temperature reference minus the intake temperature (fuel_demand_boost_offset), clamped to the calibrated window, into fuel_demand_mode2_adjusted, and its table lookup into fuel_demand_mode2_correction_lookup. No manifold pressure is involved. (was cm848_calculateManifoldPressureOffset)',
  'Code: charge_temperature_combustion_reference - fuel_demand_boost_offset (both 1/64 deg F) clamped by the calibrations 0x4059fc / 0x4059fe (both 0 in this calibration, so the adjustment is 0); signed lookup of the result. e2m CBO block: CBO_Delta_Charge_Tmptr (+0A = 0x40a522), CBO_Charge_Tmptr_Adj (+0C = 0x40a524), C_CBO_Delta_Charge_Tmptr_Min / Max.')

F(0x16cd4, 'cm848_calculateTimingReferenceDeltaAdjustment', 'cm848_calculateTimingReferenceDeltaAdjustment', None,
  'Name and plate comment are right (CBO_Delta_SOI +1E and CBO_SOI_Adj +16: timing reference minus implemented main timing, clamped and looked up).')

F(0x16d6c, 'cm848_applyFuelDemandOffset', 'cm848_applyOffNominalTimingAdjustment',
  'Looks up the off-nominal timing adjustment (injection_timing_reference_adjustment) from the composite adjustment fuel_demand_correction_input, sets its active flag, and adds it to the combustion timing reference clamped to -1023..1024 counts (fuel_correction_output). The adjustment is switched off (engine_load_correction_mode_flag = 1, output = the unadjusted reference) when EGR is off, alpha is 0, the chi is above the threshold or fuel_blend_correction_inhibit_flag is set. (was cm848_applyFuelDemandOffset)',
  'Code: lookup, flag (adjustment != 0), clamped sum, then the off condition on egr_off_flag / alpha_percent / chi_hundredths x 1024 against fuel_blend_weight_threshold_cal x 100. e2m: CBO_SOI_Ref_Adj (+1C), CBO_SOI_Adjust_Flag (+20), CBO_SOI_Ref (+08 = 0x40a520 = fuel_correction_output), CBO_Off (+22) = SHM_CBO_OFF or CBR_EGR_Off.')

F(0x16e90, 'cm848_processFuelTimingCalculations', 'cm848_calculateOffNominalCompensation',
  'Calculates the off-nominal compensation (CBO): the oxygen fraction adjustment and the charge temperature adjustment, their product clamped to the composite window (fuel_demand_correction_input), the timing adjustment and timing delta adjustment, and the NOx target scaled by both into fuel_demand_timing_correction. (was cm848_processFuelTimingCalculations)',
  'Code: calls cm848_calculateOffNominalOxygenFractionAdjustment, cm848_calculateOffNominalChargeTemperatureAdjustment, multiplies their outputs (>> 13) and clamps by 0x405a08 / 0x405a0a, then calls cm848_applyOffNominalTimingAdjustment and cm848_calculateTimingReferenceDeltaAdjustment and forms the scaled NOx target. e2m CBO block: CBO_Composite_Adj (+18), C_CBO_Composite_Min / Max, CBO_bsNOx (+1A).')

F(0x16f9c, 'cm848_storeFuelLimitValues', 'cm848_runOffNominalCompensation',
  'Entry point of the off-nominal compensation: copies the fuel reference into fuel_demand_limit_copy (the fuel input of the combustion limits), runs cm848_calculateOffNominalCompensation, then caches the mass charge flow reference (fuel_demand_rate_raw_cached), the EGR fraction reference (fuel_demand_high_limit_cached) and the gross-to-limit ratio (fuel_blend_load_ratio_cached) for the limit stage. (was cm848_storeFuelLimitValues)',
  'Code: one copy, one call, three copies. e2m CBO block (0x01171100 = 0x40a518): CBO_Fuel_Ref (+04), CBO_MCF_Ref (+06), CBO_EGR_Frac_Ref (+02), CBO_Charge_Aggressiveness_Ref (+00); in this build only the timing reference and the NOx target are actually compensated, the other references pass through unchanged (dump 1030 / 556 / 0 / 2866 equal the CBR values).')

F(0x16ffc, 'mpc555_initFuelTimingTablePointers', 'cm848_initializeOffNominalCompensationLookupCaches',
  'Sets the lookup cache words 0x3fa6d2-0x3fa6da of the off-nominal compensation lookups (charge temperature adjustment, oxygen fraction tables, timing adjustment tables) to 2. It sets no table pointers. (was mpc555_initFuelTimingTablePointers)',
  'Code: five word stores of 2 into the cached_axis_offsets words (&DAT_003fa6d2, fuel_load_correction_timing_interp_state, &DAT_003fa6d8, &DAT_003fa6da) used by the lookups of cm848_calculateOffNominalChargeTemperatureAdjustment, cm848_calculateOffNominalOxygenFractionAdjustment, cm848_calculateTimingReferenceDeltaAdjustment and cm848_applyOffNominalTimingAdjustment. Time-shared window; no word renamed.')

# ---------------------------------------------------------------- CBL words
G(0x40a466, 'fuel_demand_high_limit', 'egr_fraction_combustion_command',
  'Code: only writer cm848_selectEgrFractionCommand (cached EGR fraction reference, Q13, or the calibration at 0x405234 when engine_feature_enable_flags bit 0 is set); only reader cm848_calculateTurboBlendOutput (band compare against fuel_demand_band_low / high_threshold, then a rate-limited output). e2m: CBL_EGR_Frac_Cmd (+00 of CBL block 0x01171B00 = 0x40a466), T_CBL_EGR_Frac_User_Override. Dump 0 (EGR maps are zero).')
G(0x40a46a, 'fuel_timing_target_raw', 'injection_quantity_combustion_command',
  'Code: written by cm848_selectCombustionFuelCommand = fuel_demand_limit_copy (1030 = 70 mm3 in the dump) or the calibration at 0x405236 (bit 1); only reader cm848_selectFuelDemandSource, the cranking / cold-start fuel arbitration. The word is a fuel quantity (0.0679 mm3 per count), not a timing target. e2m: CBL_Fuel_Cmd (+04), T_CBL_Fuel_User_Override.')
G(0x40a46c, 'fuel_demand_rate_cap_input', 'mass_charge_flow_combustion_command',
  'Code: cm848_selectMassChargeFlowCommand = fuel_demand_load_rate_cap (the density-limited reference) or the calibration at 0x405238 (bit 2); only reader cm848_selectTemperatureTrimValue (copies it to fuel_demand_rate_min unless engine_retarder_active_flag is 1, which feeds the boost / charge chain). e2m: CBL_MCF_Cmd (+06) charge flow command passed to the Charge Manager, T_CBL_MCF_User_Override. Dump 556.')
G(0x40a46e, 'injection_timing_main_base_command', None,
  'Keep: the name is right (code: written by cm848_selectMainBaseTimingOverride, base term of the main timing combination; e2m CBL_SOI_Cmd +08; dump 68).')
G(0x40a470, 'injection_timing_combustion_maximum_limit', None,
  'Keep: right (e2m CBL_SOI_Max_Limit +0A; code and dump 384 = 45 deg).')
G(0x40a472, 'injection_timing_combustion_minimum_limit', None,
  'Keep: right (e2m CBL_SOI_Min_Limit +0C; code and dump 43 = 5 deg).')
G(0x40a474, 'injection_timing_main_base_before_override', None,
  'Keep: right (e2m CBL_SOI_Ref +0E, the clamped reference before the user override; dump 68).')
G(0x40a476, 'fuel_demand_mode_code_snapshot', 'injection_timing_source_code_before_combustion_limits',
  'Code: written once, as a copy of fuel_demand_mode_code taken at the start of cm848_applyCombustionTimingLimits before the limits can set code 27 / 28; no reader. e2m: SOI_State_Before_CBL (+10) algorithm that set the timing before the combustion limits. Dump 0. The name keeps the code meaning (a timing source code) without claiming the e2m enumeration.')
G(0x40a47a, 'fuel_demand_load_rate_cap', 'mass_charge_flow_combustion_limited_reference',
  'Code: cm848_limitMassChargeFlowReference writes the cached mass charge flow reference limited by the density limit (boost_fuel_mode_active set) or by 51200 = 400 lb/min; only reader cm848_selectMassChargeFlowCommand. e2m: CBL_MCF_Ref (+14) passed to CBL_MCF_Cmd unless overridden. Dump 556. It is a mass charge flow limit result, not a load rate cap.')
G(0x40a47c, 'fuel_demand_load_rate_cap_snapshot', 'mass_charge_flow_density_limit',
  'Code: the raw output of the engine speed x air density grid (3200..9600 counts = 25..75 lb/min), stored before the reference is applied; no reader (testpoint). e2m: CBL_Density_MCF_Limit (+16) testpoint from the density based MCF limit table. Dump 4733 = 37 lb/min.')
G(0x40a47e, 'injection_timing_user_increment_active_flag', None,
  'Keep: right (e2m CBL_User_Incr_Flag +18; code: bit 3 of engine_feature_enable_flags and a non-zero injection_timing_user_increment).')

# CBL calibrations
G(0x405234, 'fuel_demand_high_limit_override_cal', 'egr_fraction_combustion_command_override_value',
  'Code: copied into the EGR fraction command when engine_feature_enable_flags bit 0 (1) is set (cm848_selectEgrFractionCommand); 0x405234 is not in the EEPROM range 0x3fd482-0x3feec1, so no _cal. e2m: C_CBL_EGR_Frac_Override_Value (+0 of cal block 0x01171A00 = 0x405234); dump 0.')
G(0x405236, 'fuel_timing_target_override_cal', 'injection_quantity_combustion_command_override_value',
  'Code: copied into the fuel command when bit 1 (2) is set (cm848_selectCombustionFuelCommand); it is a fuel quantity (dump 221 = 15 mm3), not a timing; not EEPROM, so no _cal. e2m: C_CBL_Fuel_Override_Value (+2).')
G(0x405238, 'fuel_demand_rate_cap_override_cal', 'mass_charge_flow_combustion_command_override_value',
  'Code: copied into the mass charge flow command when bit 2 (4) is set (cm848_selectMassChargeFlowCommand); dump 2560 = 20 lb/min; not EEPROM, so no _cal. e2m: C_CBL_MCF_Override_Value (+4).')

# CBL limit tables (calibrations; the six timing limit tables were proposed by wave 4)
G(0x40523e, 'injection_timing_rpm_axis_cal', 'injection_timing_combustion_minimum_limit_x_axis',
  'Code: x axis (engine speed, 4000..28000 = 500..3500 rpm) of the first lookup in cm848_applyCombustionTimingLimits, whose output is injection_timing_combustion_minimum_limit; wave 4 proposed this name. Outside the EEPROM range, so no _cal. e2m: C_CBL_SOI_Min_Speed_Axis.')
G(0x405266, 'injection_timing_load_axis_cal', 'injection_timing_combustion_minimum_limit_y_axis',
  'Code: y axis (fuel_demand_limit_copy, 0..2208 counts = 0..150 mm3) of the same lookup. e2m: C_CBL_SOI_Min_Fuel_Axis.')
G(0x405288, 'injection_timing_advance_yend_cal', 'injection_timing_combustion_minimum_limit_grid',
  'Code: 19 x 16 grid of the minimum limit lookup, flat 43 counts (5 deg) in the dump = injection_timing_combustion_minimum_limit. e2m: C_CBL_SOI_Min_Limit_Table.')
G(0x4054e8, 'injection_timing_mode2_rpm_axis_cal', 'injection_timing_combustion_maximum_limit_x_axis',
  'Code: x axis (engine speed) of the second lookup in cm848_applyCombustionTimingLimits (output injection_timing_combustion_maximum_limit). e2m: C_CBL_SOI_Max_Speed_Axis.')
G(0x405510, 'injection_timing_mode2_ystart_cal', 'injection_timing_combustion_maximum_limit_y_axis',
  'Code: y axis (fuel_demand_limit_copy) of the maximum limit lookup. e2m: C_CBL_SOI_Max_Fuel_Axis.')
G(0x405532, 'injection_timing_mode2_yend_cal', 'injection_timing_combustion_maximum_limit_grid',
  'Code: 19 x 16 grid of the maximum limit lookup, flat 384 counts (45 deg) in the dump = injection_timing_combustion_maximum_limit. e2m: C_CBL_SOI_Max_Limit_Table.')
G(0x405792, 'fuel_demand_load_rate_cap_rpm_axis_cal', 'mass_charge_flow_density_limit_x_axis',
  'Code: x axis (engine speed, 6400..28000 = 800..3500 rpm) of the lookup in cm848_limitMassChargeFlowReference whose output is mass_charge_flow_density_limit. Outside the EEPROM range, so no _cal. e2m: C_CBL_MCF_Limit_Speed_Axis.')
G(0x4057b4, 'fuel_demand_load_rate_cap_ystart_cal', 'mass_charge_flow_density_limit_y_axis',
  'Code: y axis, intake air density (engine_load_input_value, 737..1638 counts = 0.045..0.1 lbm/ft3 at 6.1e-5). e2m: C_CBL_MCF_Limit_Density_Axis (LBM/FT3).')
G(0x4057d6, 'fuel_demand_load_rate_cap_yend_cal', 'mass_charge_flow_density_limit_grid',
  'Code: 16 x 16 grid, 3200..9600 counts = 25..75 lb/min at 1/128, the density limit (dump output 4733). e2m: C_CBL_MCF_Limit_Table.')

# ---------------------------------------------------------------- CBR words
G(0x40a480, 'fuel_table_load_axis', 'injection_quantity_combustion_gross',
  'Code: written twice in cm848_calculateCombustionGrossFuel (arbitrated demand minus the timing adjustment, clamped 0..5888, then limited by injection_quantity_combustion_maximum_limit); read as the fuel input of the mass charge flow and EGR fraction maps and as the first cap of the fuel reference. The old name says load axis, but it is a fuel quantity (0.0679 mm3 per count; dump 1030 = 70 mm3). e2m: CBR_Gross_Fuel (+00).')
G(0x40a482, 'fuel_blend_load_ratio', 'injection_quantity_combustion_gross_to_limit_ratio',
  'Code: (gross fuel << 13) / max(fuel_demand_limit_input, 5), capped at 65535 (Q13), written once in cm848_calculateCombustionFuelReference and compared with the on / off thresholds 17203 / 9830 (hysteresis) to set injection_quantity_combustion_limited_flag; copied to fuel_blend_load_ratio_cached. Dump 2866 = 1030 / 2944 x 8192, exact. e2m: CBR_FCLR_Ref (+02) gross fuel divided by the fuel limit, 1/8192.')
G(0x40a484, 'fuel_demand_limit', 'injection_quantity_combustion_reference',
  'Code: cm848_calculateCombustionFuelReference writes the gross fuel capped by fuel_demand_load_axis_cap (source 54) and fuel_demand_limit_input (source 58), or the override calibration 0x4059ee (bit 9 of engine_feature_enable_flags, source 23); read as the fuel axis of the NOx, charge temperature and timing maps and copied to fuel_demand_limit_copy for the off-nominal and limit stages. Dump 1030. e2m: CBR_Fuel_Ref (+04) fuel reference, unlimited and uncompensated; T_CBR_Fuel_Ref_User_Override.')
G(0x40a486, 'fuel_demand_timing_filtered', 'injection_timing_combustion_reference_at_base_chi',
  'Code: second cm848_interpolateAlphaChiValue call in cm848_calculateCombustionTimingReference: the five timing maps interpolated with the base chi and alpha fixed at 100 percent; its only reader (fuel_injectionTiming_cylinderCheck_update) compares it with the main timing intake temperature and coolant components. e2m: CBR_Base_Chi_SOI_Cmd (+06) SOI command with the base chi (alpha = 1). Dump 68.')
G(0x40a488, 'injection_timing_combustion_reference', None,
  'Keep: right. Code: alpha-chi blend of the five timing maps (cm848_calculateCombustionTimingReference) plus the fuel-limited adjustment; readers cm848_applyOffNominalTimingAdjustment and cm848_calculateTimingReferenceDeltaAdjustment; dump 68 = 8 deg. e2m: CBR_SOI_Ref (+08). Confirms the lead note.')
G(0x40a48a, 'fuel_demand_rate_raw', 'mass_charge_flow_combustion_reference',
  'Code: alpha-chi blend of the five mass charge flow maps (values 4..54 lb/min at 1/128), written once in cm848_calculateMassChargeFlowReference; cached in fuel_demand_rate_raw_cached for the density limit, and used in cm848_calculateOffNominalOxygenFractionAdjustment as the air flow in (1 - EGR fraction) x flow / fuel flow. Dump 556 = 4.3 lb/min. e2m: CBR_MCF_Ref (+0A) mass charge flow reference, unlimited and uncompensated.')
G(0x40a48c, 'fuel_demand_rate_output_b', 'egr_fraction_combustion_reference',
  'Code: written once in cm848_calculateEgrFractionReference: the alpha-chi blend of the EGR maps, forced to 0 when injection_quantity_combustion_limited_flag or the EGR-off flag is set; cm848_calculateOffNominalOxygenFractionAdjustment uses 0x2000 minus it (Q13 complement) and cm848_runOffNominalCompensation caches it (fuel_demand_high_limit_cached, then the EGR fraction command). All five EGR maps are zero in this calibration, dump 0. e2m: CBR_EGR_Frac_Ref (+0C).')
G(0x40a48e, 'fuel_demand_mode2_filtered', 'charge_temperature_combustion_reference',
  'Code: signed (flag 4) alpha-chi blend of five maps in 1/64 deg F, written once in cm848_calculateChargeTemperatureReference; cm848_calculateOffNominalChargeTemperatureAdjustment subtracts the intake temperature fuel_demand_boost_offset from it, and cm848_processBoostProtectionMode adds it to a temperature estimate clamped to -50..350 deg F. Dump 7360 = 115 deg F with every map flat. e2m: CBR_Charge_Tmptr_Ref (+0E) and CBO_Delta_Charge_Tmptr.')
G(0x40a490, 'fuel_demand_mode1_filtered', 'nitrogen_oxides_target_combustion_reference',
  'Code: unsigned alpha-chi blend of five maps, written once in cm848_calculateNitrogenOxidesTargetReference; the only reader multiplies it by the composite off-nominal adjustment and the timing adjustment scale, divides by 546 and clamps 0..65533 into fuel_demand_timing_correction. The meaning NOx target is e2m (CBR_NOx_Target_Ref +10, G/HP*HR at 1/2048, CBO_bsNOx = that value adjusted for off-nominal conditions at +1A = 0x40a532); the dump 5120 = 2.5 g/hp-hr with every map flat fits the scale. The code alone proves a reference scaled by the off-nominal stage. Medium-high confidence.')
G(0x40a492, 'fuel_demand_limit_input', None,
  'Code: fuel limit calculated in Bank 2 by fuel_demandLimit_rpmLoad_calc (rpm x fuel grid, barometric pressure scale and fuel_demand_qty_boost_corrected, clamped 0..5888 and to two calibrated limits), used as the third cap of the fuel reference (source 58), as the divisor of the gross-to-limit ratio and in cm848_calculateEffectiveFuelLimit. The e2m block list has no word at +12, so the only support for a name like OFC fuel limit is the e2m description of CBR_FCLR_Ref. Left unchanged: the existing name already says fuel demand limit; a better one needs the Bank 2 function reviewed.', verdict='uncertain')
G(0x40a4a0, 'fuel_blend_step_b_stored', 'combustion_chi_emission_level',
  'Code: written once in cm848_selectChiAndAlpha with the level paired with the chi (record word 2 of the base chi, or the calibrations 0x4059dc / 0x4059e6 / 0x4059f0 of the override, EGR-off and protection branches); no reader (testpoint). Dump 16384 = 8.0 at 1/2048, the EGR-off calibration. e2m: CBR_Chi_EL (+20) final chi.el, unit G/HP*HR; the word emission level is the e2m unit reading, the code only shows a second value tied to the chi by the chi / level axes.')
G(0x40a4a2, 'fuel_blend_weight_stored', 'combustion_chi_desired_hundredths',
  'Code: written once in cm848_selectChiAndAlpha with the chi before the level limit (record word 0 of the base chi, or the fixed chi of the EGR-off / protection / override branches); no reader. Dump 400. e2m: CBR_Chi_Desired (+22) protective chi prior to limitation by EMM_Cap_EL_Cmd.')
G(0x40a4a4, 'fuel_blend_table_size', 'combustion_chi_source_code',
  'Code: written once in cm848_selectChiAndAlpha: 1 / 3 = base chi from the air density / coolant temperature table, 10 = EGR-off fixed chi, 12 = full user override, 13 = single-value user override, 14 = protection chi; no reader. Dump 10. e2m: CBR_Chi_Source (+24) enumerated indicator of condition or override source of chi. A new enum would fit (see the note on the chi source codes).')
G(0x40a4a6, 'fuel_blend_lower_map_number', 'combustion_chi_lower_map_number',
  'Code: only writer cm848_selectChiAndAlpha (clamps the low table of the chi to 1..4); 17 other functions read it to pick map_N of the combustion reference maps and of the pilot / auxiliary timing and quantity families and pass it to cm848_interpolateAlphaChiValue, with chi_hundredths running from lower x 100 to upper x 100 as the interpolation position. No fuel blend and no boost pressure is involved. e2m: CBR_Chi_Low (+26) final chi.lowtable. Dump 4.')
G(0x40a4a8, 'fuel_blend_upper_map_number', 'combustion_chi_upper_map_number',
  'Code: same writer and clamp as the lower number, second map number argument of cm848_interpolateAlphaChiValue (end of the interpolation). e2m: CBR_Chi_High (+28) final chi.hightable. Dump 4: lower = upper = 4, so pure map 4 (the lead note reads this as Chi4).')

QTY = [
    # name, base addr, old base, [map addrs], [old map names], y input, writer, e2m names, dump
    ('injection_timing', 0x40a4d2, 'fuel_demand_timing_lookup',
     [0x40a4d4, 0x40a4d6, 0x40a4d8, 0x40a4da], ['fuel_demand_calc_c', 'fuel_demand_calc_b', 'fuel_demand_calc_a', 'fuel_demand_calc_boost5_lookup'],
     'fuel reference', 'cm848_calculateCombustionTimingReference', 'CBR_SOI_Alpha0..Chi4 (+52..+5A), tables C_CBR_SOI_*_Table', 'all five 68 (8 deg)'),
    ('mass_charge_flow', 0x40a4be, 'fuel_demand_rate_map5_lookup',
     [0x40a4c0, 0x40a4c2, 0x40a4c4, 0x40a4c6], ['fuel_demand_mode3_boost_map1', 'fuel_demand_mode3_boost_map2', 'fuel_demand_mode3_boost_map3', 'fuel_demand_mode3_boost_map4'],
     'gross fuel', 'cm848_calculateMassChargeFlowReference', 'CBR_MCF_Alpha0..Chi4 (+3E..+46), tables C_CBR_MCF_*_Table', 'base 556 and map 4 556, the unselected maps 0'),
    ('egr_fraction', 0x40a4b4, 'fuel_demand_rate_b_base_lookup',
     [0x40a4b6, 0x40a4b8, 0x40a4ba, 0x40a4bc], ['fuel_quantity_channel_a', 'fuel_quantity_channel_b', 'fuel_quantity_channel_c', 'fuel_quantity_channel_boost5_lookup'],
     'gross fuel', 'cm848_calculateEgrFractionReference', 'CBR_EGR_Frac_Alpha0..Chi4 (+34..+3C), tables C_CBR_EGR_Frac_*_Table', 'all 0 (the five tables are zero in this calibration)'),
    ('charge_temperature', 0x40a4aa, 'fuel_demand_mode2_map5_lookup',
     [0x40a4ac, 0x40a4ae, 0x40a4b0, 0x40a4b2], ['fuel_demand_mode2_boost_map1', 'fuel_demand_mode2_boost_map2', 'fuel_demand_mode2_boost_map3', 'fuel_demand_mode2_boost_map4'],
     'fuel reference', 'cm848_calculateChargeTemperatureReference', 'CBR_Charge_Tmptr_Alpha0..Chi4 (+2A..+32), tables C_CBR_Charge_Tmptr_*_Table', 'base 7360 (115 deg F) and map 4 7360, the unselected maps 0'),
    ('nitrogen_oxides_target', 0x40a4c8, 'fuel_demand_mode1_boost5_lookup',
     [0x40a4ca, 0x40a4cc, 0x40a4ce, 0x40a4d0], ['fuel_demand_mode1_boost_map1', 'fuel_demand_mode1_boost_map2', 'fuel_demand_mode1_boost_map3', 'fuel_demand_mode1_boost_map4'],
     'fuel reference', 'cm848_calculateNitrogenOxidesTargetReference', 'CBR_NOx_Alpha0..Chi4 (+48..+50), tables C_CBR_NOx_*_Table', 'base 5120 (2.5 g/hp-hr) and map 4 5120, the unselected maps 0'),
]
MAPNAMES = ['Alpha1', 'Chi2', 'Chi3', 'Chi4']
for q, base, oldbase, maps, oldmaps, yin, writer, e2m, dump in QTY:
    G(base, oldbase, '%s_combustion_base_map_output' % q,
      'Code: 2-D lookup (engine speed x %s) in the base map, the alpha 0 end of the blend in %s; the value is the third argument of cm848_interpolateAlphaChiValue. e2m: %s; the base map is the Alpha0 table. Dump: %s.' % (yin, writer, e2m, dump))
    for n, (a, o) in enumerate(zip(maps, oldmaps), start=1):
        extra = ''
        if q == 'injection_timing' and n == 1:
            extra = ' A second reader, cm848_auxiliaryControl_tableInterpolation (Bank 2), takes the difference to the main timing for the timing-to-fuel adjustment.'
        allfour = ' (the timing and EGR functions evaluate all four maps every pass)' if q in ('injection_timing', 'egr_fraction') else ' (the unselected maps keep their old value)'
        G(a, o, '%s_combustion_map_%d_output' % (q, n),
          'Code: 2-D lookup (engine speed x {yin}) in map {n}, evaluated when the lower or upper chi map number is {n}{allfour}. e2m: map {n} is the {mapname} table ({e2m}); the RAM order Chi2 < Chi3 < Chi4 < base (Alpha0) < map 1 (Alpha1) with 0x260 bytes between maps, and the axis order, are the e2m order.{extra} Dump: {dump}.'.format(
              yin=yin, n=n, allfour=allfour, mapname=MAPNAMES[n - 1], e2m=e2m, extra=extra, dump=dump))

G(0x40a4dc, 'fuel_blend_scale_factor', 'combustion_base_chi_hundredths',
  'Code: cm848_determineBaseChi stores the chi after the level limit (record word 1 of the winning protective source); read as the interpolation position of the base-chi lookups in cm848_calculateCombustionTimingReference and cm848_calculateEgrFractionReference and as the unoverridden chi of cm848_selectChiAndAlpha. Dump 100. e2m: CBR_Base_Chi (+5C) chi calculated by determine_chi().')
G(0x40a4de, 'sensor_filter_state_a', 'combustion_base_chi_lower_map_number',
  'Code: cm848_determineBaseChi stores the low map number of the base chi (record word 3, from the fuel_map_*_filter_d tables 1,1,2,2,3,3,4...); read as the lower map number of the base-chi lookups. No sensor or filter is involved. e2m: CBR_Base_Low_Table (+5E). Dump 1.')
G(0x40a4e0, 'sensor_filter_state_b', 'combustion_base_chi_upper_map_number',
  'Code: cm848_determineBaseChi stores the high map number of the base chi (record word 4, from the fuel_map_*_filter_c tables 2,2,3,3,4,4...); read as the upper map number of the base-chi lookups. e2m: CBR_Base_High_Table (+60). Dump 2.')
G(0x40a4e2, 'boost_fuel_blend_weight_b', 'egr_fraction_combustion_reference_at_base_chi',
  'Code: written in cm848_calculateEgrFractionReference: the EGR maps interpolated with the base chi and alpha 100 percent (Q13 fraction); read as the weight in cm848_fuelDemandBlendCalculation ((0x2000 - it) x one temperature + it x another, a mixture) and in two other blend functions. Dump 0. e2m: CBR_Base_Chi_EGR_Frac_Cmd (+62) EGR fraction derived from chi_base.')
G(0x40a4e4, 'fuel_blend_boost_map_index_saved', 'combustion_base_chi_source_code',
  'Code: cm848_determineBaseChi stores 1 (air density source) or 3 (coolant temperature source) from cm848_selectChiSourceCode; read once by cm848_selectChiAndAlpha as the chi source. Dump 1. e2m: CBR_Base_Chi_Source (+64).')
G(0x40a4e6, 'fuel_blend_filter_state_a_saved', 'combustion_base_chi_desired_hundredths',
  'Code: record word 0 of cm848_lookupProtectiveChi (the chi before the level limit) stored by cm848_determineBaseChi; read once by cm848_selectChiAndAlpha as the desired chi. Dump 100. e2m: CBR_Base_Desired_Chi (+66).')
G(0x40a4e8, 'fuel_blend_filter_state_b_saved', 'combustion_base_chi_emission_level',
  'Code: record word 2 (the level) stored by cm848_determineBaseChi, read once by cm848_selectChiAndAlpha. Dump 2048 (1.0 at 1/2048). e2m: CBR_Base_EL (+68) base chi.el prior to overrides, unit G/HP*HR (the emission level reading is the e2m unit).')
G(0x40a4ea, 'fuel_demand_load_axis', 'injection_quantity_combustion_chi_maximum',
  'Code: cm848_calculateCombustionChiMaximumFuel blends five maximum fuel curves against engine speed (1030..2082 counts = 70..141 mm3) by chi and alpha; it is the second term of injection_quantity_combustion_maximum_limit and is read by six functions outside the combustion reference as the full-load fuel (load percentages, output torque, protection and rail pressure shortfall ramps), which fits. Dump 1030. e2m: CBR_Max_Chi_Fuel (+6A) from the chi-based max fuel curve, limits CBR_Gross_Fuel. Resolves the earlier waves keeping this word because of its other readers.')
G(0x40a4ec, 'fuel_blend_bypass_flag', 'injection_quantity_combustion_limited_flag',
  'Code: only writer cm848_calculateCombustionFuelReference sets it when the gross-to-limit ratio reaches 17203 and clears it at 9830 or below (hysteresis); read by cm848_calculateCombustionTimingReference (alpha 0 and set: add the fuel-limited timing adjustment) and cm848_calculateEgrFractionReference (set: EGR fraction 0). Dump 0. e2m: no word at +6C, but C_CBR_FCLR_On / Off name the same hysteresis as the OFC limited flag.')
G(0x40a4ee, 'fuel_demand_load_table_result', 'injection_quantity_combustion_density_maximum',
  'Code: 2-D lookup (engine speed x intake air density) in cm848_calculateCombustionGrossFuel, grid 0..2134 counts = 0..145 mm3; the first term of the maximum fuel limit (source 52). Dump 1575. e2m: CBR_Density_Max_Fuel (+6E) from the density based fuel limit table.')
G(0x40a4f0, 'governor_mode_select', 'injection_quantity_combustion_reference_source_code',
  'Code: written in cm848_calculateCombustionFuelReference (the gross fuel source code 52 / 53 / 55 or the incoming demand source, 54 cap, 58 fuel limit, 23 override) and read by cm848_selectFuelDemandSource, which hands it on as governor_mode_code. It is the source of the fuel reference, not a governor mode select. Dump 62 (the incoming demand source). e2m: CBR_Fuel_Ref_State (+70) enumerated source of the CBR fuel reference.')
G(0x40a4f2, 'fuel_demand_load_axis_base_lookup', 'injection_quantity_combustion_maximum_base_curve_output',
  'Code: 1-D lookup of governor_fuel_demand_values_cal against engine speed in cm848_calculateCombustionChiMaximumFuel, the alpha 0 end of the maximum fuel blend. Dump 1303 (the curve start). e2m: CBR_Max_Fuel_Alpha0 (+72).')
for n, (a, o) in enumerate(zip([0x40a4f4, 0x40a4f6, 0x40a4f8, 0x40a4fa], ['fuel_demand_rpm_table_boost1', 'fuel_demand_rpm_table_boost2', 'fuel_demand_rpm_table_boost3', 'fuel_demand_rpm_table_boost4']), start=1):
    G(a, o, 'injection_quantity_combustion_maximum_curve_%d_output' % n,
      'Code: 1-D lookup of fuel_rpm_table_boost%d_cal against engine speed, evaluated when the lower or upper chi map number is %d (dump: only curve 4, 1030 = the curve start, the others stay 0). The word has nothing to do with boost. e2m: CBR_Max_Fuel_%s (+%02X).' % (n, n, MAPNAMES[n - 1], 0x74 + 2 * (n - 1)))
G(0x40a4fc, 'fuel_table_load_working', 'injection_quantity_combustion_maximum_limit',
  'Code: cm848_calculateCombustionGrossFuel keeps the smaller of the chi maximum fuel and the density maximum fuel (each plus fuel_demand_offset_correction under the fuel_feature_control_flags bits); it limits the gross fuel and is read by cm848_calculateEffectiveFuelLimit as a maximum fuel limit. Dump 1286 = 1030 + 256. e2m: CBR_Max_Fuel_Limit (+7C) min(density max fuel, chi max fuel) limits CBR_Gross_Fuel.')
G(0x40a4fe, 'boost_fuel_blend_active_flag', 'injection_timing_fuel_limited_adjustment_active_flag',
  'Code: cm848_calculateCombustionTimingReference sets it to 1 when alpha is 0 and injection_quantity_combustion_limited_flag is set (the fuel-limited timing adjustment is added to the reference) and to 0 otherwise; read by cm848_setTimingIncrementFlags (bit 0x40) and cm848_updateMainInjectionTimingByDeliveryMode. Dump 0. e2m: CBR_OFC_Alpha0_Incr_Flag (+7E) non-zero output of the SOI adjust table is being used.')
G(0x40a500, 'fuel_blend_enable_flag', 'egr_off_requested_flag',
  'Code: only user is cm848_selectChiAndAlpha: set to 1 for the protection state masks of fuel_mode_status_flags (8, 0x10, 0x200) or any EGR-off condition (masks 1, 2, 0x80, 0x100, and masks 0x20 / 0x40 with the intake / coolant temperature at or below the calibrations 0x4059fa / 0x4059f8), and copied into fuel_blend_state_t.egr_off_flag before the user override. It selects the fixed chi instead of the base chi. The e2m names +80 CBR_Protection_Chi_Flag (protection chi chosen over base), but the code ORs the protection and the EGR-off conditions, so the name follows the code. Dump 1 (fuel_mode_status_flags = 0x402 contains mask 2).')

# max chi fuel and torque points (struct at 0x40a502 and five words)
SF('protection_threshold_set_t', 'threshold_scaled', 'chi_maximum_fuel_at_point_1',
   'Code: cm848_calculateChiMaximumFuelAndTorquePoints stores cm848_lookupChiMaximumFuelAtSpeed(governor_integrator_rpm_output) here, the first of five engine speed points (1030 in the dump); the five results are not read elsewhere. e2m: CBR_Max_Chi_Fuel_At_Point_1 (+82 = 0x40a502). The old name (protection threshold) is wrong: nothing here is a protection threshold.')
SF('protection_threshold_set_t', 'recovery_threshold', 'chi_maximum_fuel_at_point_2',
   'Code: second point (input protection_recovery_threshold_cal), dump 1182. e2m: CBR_Max_Chi_Fuel_At_Point_2 (+84).')
SF('protection_threshold_set_t', 'hysteresis', 'chi_maximum_fuel_at_point_3',
   'Code: third point (input protection_threshold_lookup_rpm), dump 1443. e2m: CBR_Max_Chi_Fuel_At_Point_3 (+86).')
SF('protection_threshold_set_t', 'threshold_scaled_alt', 'chi_maximum_fuel_at_point_4',
   'Code: fourth point (input protection_threshold_scale_working), dump 1607. e2m: CBR_Max_Chi_Fuel_At_Point_4 (+88).')
SF('protection_threshold_set_t', 'threshold_base', 'chi_maximum_fuel_at_point_5',
   'Code: fifth point (input protection_base_threshold_working), dump 1475. e2m: CBR_Max_Chi_Fuel_At_Point_5 (+8A).')
for n, (a, o) in enumerate(zip([0x40a50c, 0x40a50e, 0x40a510, 0x40a512, 0x40a514],
                               ['protection_threshold_scaled_rpm', 'protection_recovery_threshold_rpm', 'protection_hysteresis_rpm', 'protection_threshold_alt_rpm', 'protection_base_threshold_rpm']), start=1):
    G(a, o, 'combustion_chi_maximum_torque_at_point_%d' % n,
      'Code: cm848_convertFuelToTorqueAtSpeed of chi_maximum_fuel_at_point_%d at the same engine speed, written once in cm848_calculateChiMaximumFuelAndTorquePoints and read nowhere; it is not an rpm and not a protection value (dump 0, the conversion grid is all zero in this calibration). e2m: CBR_Max_Chi_Torque_At_Point_%d (+%02X) torque limit at rpm %d from the chi limit function, FT*LB at 0.5. Medium confidence (block position and the fuel-to-signed-value conversion).' % (n, n, 0x8c + 2 * (n - 1), n))

# fuel_blend_state_t fields
SF('fuel_blend_state_t', 'blend_mode', 'alpha_percent',
   'Code: set in cm848_selectChiAndAlpha to the calibration 0x4059d6 when engine_feature_enable_flags bit 5 (0x20) is set, else to fuel_blend_coefficient x 100 >> 14 (a Q14 fraction as percent) while the chi is below the calibration 0x4059d8 and EGR is not off, else 100; cm848_interpolateAlphaChiValue blends the chi-interpolated value with the base map by this percentage (100 = pure chi value, 0 = base map). Dump 100. e2m: CBR_Alpha (+14) EMM_Alpha unless EGR off, high chi or user override; T_CBR_Alpha_User_Override = bit 5.')
SF('fuel_blend_state_t', 'blend_enable', 'egr_off_flag',
   'Code: egr_off_requested_flag, or the calibration 0x4059e8 when engine_feature_enable_flags bit 8 (0x100) is set; when set, the EGR fraction reference is 0, alpha is 100 and the off-nominal timing adjustment is off. Dump 1. e2m: CBR_EGR_Off (+16) EGR is off by EMM permission or user override; T_CBR_EGR_Off_User_Override = bit 8; CBO_Off (+22) = SHM_CBO_OFF or CBR_EGR_Off.')
SF('fuel_blend_state_t', 'demand_above_threshold', 'gross_fuel_timing_adjustment_active_flag',
   'Code: cm848_calculateCombustionGrossFuel sets it to 1 when the arbitrated demand is at or above the calibration 0x4059f2 (588 = 40 mm3); then fuel_demand_offset_load_delta_correction is subtracted from the gross fuel. Dump 1. e2m: CBR_SOI_Adj_Fuel_Active (+18) TRUE when the gross fuel is being adjusted; C_CBR_SOI_Adj_Fuel_Thd.')
SF('fuel_blend_state_t', 'bypass_load_correction', 'injection_timing_fuel_limited_adjustment',
   'Code: cm848_calculateCombustionTimingReference writes the signed lookup of the fuel-limited timing grid (engine speed x fuel reference, calibrations 0x4009da / 0x400a02 / 0x400a24) here and adds it to the timing reference only while alpha is 0 and the fuel is limited; the value is otherwise left unchanged. Dump 0. e2m: CBR_OFC_Limit_SOI_Alpha0 (+1A) adjustment to CBR_SOI_Ref if the fuel is limited or alpha = 0. The old comment (added to engine_load_normalized) is wrong.')
SF('fuel_blend_state_t', 'fuel_demand_snapshot', 'injection_quantity_gross_before_timing_adjustment',
   'Code: cm848_calculateCombustionGrossFuel copies fuel_demand_arbitrated_snapshot here before the timing adjustment is subtracted (dump 1030 = the demand). e2m: CBR_Gross_Fuel_Before_Adj (+1C) torque command converted to fuel before SOI adjustment.')
SF('fuel_blend_state_t', 'blend_weight', 'chi_hundredths',
   'Code: set in cm848_selectChiAndAlpha (base chi, EGR-off / protection chi or the override calibration 0x4059e0), 100..400; 18 functions read it as the interpolation position between lower x 100 and upper x 100 map numbers, never as a percentage. Dump 400. e2m: CBR_Chi_Value (+1E) scalar indication of the combustion strategy, 0.01 per count.')

# ---------------------------------------------------------------- notes
N('Combustion manager, ROM part (0x14000-0x17000) - verified. The code agrees with the lead note and extends it: the functions are three stages called once per pass. (1) cm848_runCombustionReference (0x164ac, was cm848_processFuelDemandCalculations) = CBR: chi and alpha selection (0x160ac, base chi 0x15f34 / 0x15e08), gross fuel (0x15a24), fuel reference (0x15bd8), then the five alpha-chi references EGR fraction (0x15444), mass charge flow (0x150b0), start of injection (0x14d38), charge temperature (0x149a4), NOx target (0x14610); each blends a base map with four maps selected by combustion_chi_lower / upper_map_number through cm848_interpolateAlphaChiValue (0x14528, was cm848_filterInputValue). (2) cm848_runOffNominalCompensation (0x16f9c, was cm848_storeFuelLimitValues) = CBO: only the timing reference and the NOx target are actually compensated; the other references are copied. (3) cm848_runCombustionLimits (0x14498, was cm848_processFuelLimitCalculations) = CBL: start of injection limits, user increment and the commands for fuel, mass charge flow and EGR fraction. The RAM words fuel_demand_* / engine_load_* / fuel_blend_* of this range are therefore combustion reference quantities (injection timing counts, fuel per stroke, mass charge flow, EGR fraction, temperatures), not engine load or fuel blending. Code-proved: the five-map structure and map order (all four maps of the timing and EGR functions are evaluated, the unselected ones stay 0 in the dump), the chi / alpha arithmetic and its override bits, the gross fuel / fuel reference / limited flag arithmetic (dump ratio 2866 = 1030 / 2944 x 8192 exactly), the CBL commands and override bits, the density mass charge flow limit. e2m-only (names, not behavior): alpha / chi / emission level wording, NOx for 0x40a490, torque for the five points at 0x40a50c-0x40a514. RAM dump sanity (engine off, key on): chi 4.00 from the EGR-off calibration, alpha 1.0, both map numbers 4, SOI 68 = 8 deg, MCF 556 = 4.3 lb/min, charge temperature 115 deg F, NOx 2.5, EGR 0 (all five EGR tables are zero: this calibration has no EGR).')

N('engine_feature_enable_flags (0x3fd5a6, EEPROM 0x124, 0 in the dump) is the combustion manager user override bitmap (e2m Word 6 at 0x01106B0C): bit 0 EGR fraction command override (0x405234), 1 fuel command override (0x405236), 2 mass charge flow command override (0x405238), 3 timing increment enable (0x40523c), 4 timing override (0x40523a), 5 alpha override, 6 chi override mode (0 single value, source 13 / 1 full, source 12), 7 chi override, 8 EGR-off override, 9 fuel reference override (0x4059ee), 10 gross fuel override (0x4059f6); each bit is tested in the function named for it in the plate comments above. Bits 0x800 / 0x1000 are read by fuel_demandLimit_rpmLoad_calc (limit overrides). The word is EEPROM-backed (0x3fd482-0x3feec1), so by the _cal rule its name should end in _cal; a name like combustion_manager_user_override_flags_cal would say what it is. Not renamed here: it is outside the assigned blocks and used by many functions. engine_feature_enable_flags_cal (0x3fd5ec, EEPROM 0x16a = 0x27EF) is a different word.')

N('CBR calibration scalars 0x4059d6-0x4059fa (outside the assigned blocks, names proposed for whoever owns them; none is in the EEPROM range, so no _cal). Order = e2m C_CBR block 0x0116A400, every one matched to the reading in cm848_selectChiAndAlpha / cm848_calculateCombustionGrossFuel / cm848_calculateCombustionFuelReference and the dump value: 0x4059d6 fuel_blend_mode_default_cal (100) -> combustion_alpha_override_percent; 0x4059d8 fuel_blend_threshold_cal (101) -> combustion_alpha_clamp_chi_limit_hundredths; 0x4059da fuel_blend_step_a_cal (400) -> combustion_protection_chi_hundredths; 0x4059dc fuel_blend_step_b_cal (5120) -> combustion_chi_override_emission_level; 0x4059de fuel_blend_mode_b_param_cal (1) -> combustion_chi_override_upper_map_number; 0x4059e0 fuel_blend_weight_percent_cal (100) -> combustion_chi_override_hundredths; 0x4059e2 fuel_blend_step_b_threshold_cal (0) -> combustion_chi_override_lower_map_number; 0x4059e4 fuel_blend_step_c_cal (400) -> combustion_egr_off_chi_hundredths; 0x4059e6 fuel_blend_step_c_threshold_cal (16384) -> combustion_egr_off_emission_level; 0x4059e8 fuel_blend_mode_override_cal (1) -> combustion_egr_off_override_flag; 0x4059ea fuel_blend_load_ratio_lower_cal (9830) -> injection_quantity_combustion_limited_off_ratio; 0x4059ec fuel_blend_load_ratio_upper_cal (17203) -> injection_quantity_combustion_limited_on_ratio; 0x4059ee fuel_demand_limit_mode17_cal (0) -> injection_quantity_combustion_reference_override_value; 0x4059f0 fuel_blend_step_a_threshold_cal (8192) -> combustion_protection_emission_level; 0x4059f2 fuel_demand_blend_threshold_cal (588) -> injection_quantity_combustion_gross_timing_adjustment_threshold; 0x4059f6 fuel_demand_mode_0x37_val_cal (0, hex in the name) -> injection_quantity_combustion_gross_override_value; 0x4059f8 fuel_demand_boost_input_lower_cal (3840 = 60 deg F) -> combustion_egr_off_coolant_temperature_limit; 0x4059fa fuel_demand_boost_offset_lower_cal (2880 = 45 deg F) -> combustion_egr_off_intake_temperature_limit. 0x4059f4 fuel_demand_rpm_correction_scale (2099) has no e2m word and was not traced. The next words are CBO calibrations (0x4059fc fuel_demand_blend_lower_cal / 0x4059fe fuel_demand_mode2_upper_limit_cal = the charge temperature delta window, 0x405a08 / 0x405a0a = composite window, 0x405a0c / 0x405a0e = timing delta window).')

N('CBR calibration tables (outside the assigned blocks; proposed names, grammar <base>_x_axis / _y_axis / _grid and _axis / _values, no _cal). Maps: base map = e2m Alpha0, map 1..4 = Alpha1, Chi2, Chi3, Chi4, each 19 x 16 words, speed axis x fuel axis, RAM order Chi2 < Chi3 < Chi4 < Alpha0 < Alpha1 (0x260 apart). Base grids: 0x40153c fuel_demand_mode_b_map_values_cal -> injection_timing_combustion_base_map_grid, 0x40211c fuel_demand_rate_map_values_cal -> mass_charge_flow_combustion_base_map_grid, 0x402cfc fuel_demand_rate_b_map_values_cal -> egr_fraction_combustion_base_map_grid, 0x4038dc fuel_demand_mode2_map_values_cal -> charge_temperature_combustion_base_map_grid, 0x4044bc fuel_demand_mode1_map_values_cal -> nitrogen_oxides_target_combustion_base_map_grid. Maps 1..4 are reached only through the pointer words (no table row exists): timing 0x40179c / 0x400e1c / 0x40107c / 0x4012dc, mass charge flow 0x40237c / 0x4019fc / 0x401c5c / 0x401ebc, EGR 0x402f5c / 0x4025dc / 0x40283c / 0x402a9c, charge temperature 0x403b3c / 0x4031bc / 0x40341c / 0x40367c, NOx 0x40471c / 0x403d9c / 0x403ffc / 0x40425c; they need type-only word[304] rows. Axes (speed, fuel pairs; the same values for all five maps): 0x40499e / 0x40497c base, 0x4049e8 / 0x4049c6 map 1, 0x404a32 / 0x404a10 map 2, 0x404a7c / 0x404a5a map 3, 0x404ac6 / 0x404aa4 map 4 (now fuel_table_rpm_axis_cal / fuel_table_load_axis_cal, fuel_demand_rpm_axis_cal / fuel_demand_load_axis_cal, fuel_demand_xaxis_cal_1..6): shared by five lookups each, so name them for their input, e.g. combustion_map_1_engine_speed_axis / combustion_map_1_fuel_axis. 1-D maximum fuel curves vs fuel_map_rpm_axis_cal (0x404aee, 21 points = 750..3600 rpm): 0x404b1a governor_fuel_demand_values_cal = base curve, 0x404b46 / 0x404b72 / 0x404b9e / 0x404bca fuel_rpm_table_boost1..4_cal = curves 1..4 -> injection_quantity_combustion_maximum_curve_N_values. Density based maximum fuel: 0x404bf6 / 0x404c1e / 0x404c40 fuel_load_table_rpm_axis_cal / _ystart_cal / _yend_cal -> injection_quantity_combustion_density_maximum_x_axis / _y_axis / _grid. Fuel-limited timing adjustment: 0x4009da / 0x400a02 / 0x400a24 fuel_blend_rpm_axis_cal / _ystart_cal / _yend_cal -> injection_timing_fuel_limited_adjustment_x_axis / _y_axis / _grid. Protective chi tables (cm848_lookupProtectiveChi): air density source 0x400c84 axis / 0x400ca6 chi values / 0x400cc8 chi axis / 0x400cea level axis / 0x400d0c high map number / 0x400d2e low map number (fuel_map_load_*), coolant temperature source 0x400d50 axis (signed 1/64 deg F) / 0x400d94 chi values / 0x400d72 chi axis / 0x400db6 level axis / 0x400dd8 high / 0x400dfa low (fuel_map_boost_*): the roles follow the code (two lookups plus chi / level conversions and the two map number tables); these are e2m C_CBR_Inlet_Density_* / C_CBR_Coolant_Tmptr_*. Fuel to torque grid for the torque points: 0x405d52 / 0x405d7a / 0x405d9c protection_rpm_correction_axis_cal / _ystart_cal / _yend_cal (grid all zero) -> chi_maximum_torque_x_axis / _y_axis / _grid.')

N('Pointer and cache words in the time-shared window 0x3F9800-0x3FDB30 (no word there is renamed or retyped here, so the boot-ROM user check was not needed): the map pointers fuel_quantity_table_a..d_pointer (0x3fa646.., EGR maps 1..4), fuel_demand_mode3_load_axis_offset1..4 (0x3fa656.., mass charge flow), fuel_demand_limit_table_a..d_pointer (0x3fa666.., timing), fuel_demand_mode2_load_axis_offset1..4 (0x3fa676.., charge temperature), fuel_demand_mode1_load_axis_offset1..4 (0x3fa686.., NOx) are filled by cm848_initializeCombustionReferenceMapPointers and hold the map base addresses (the *_load_axis_offset names are wrong: they are map pointers); the lookup cache words DAT_003fa634-0x3fa640, 0x3fa698-0x3fa6c8 and 0x3fa6d2-0x3fa6da are the cached_axis_offsets arguments of the lookups in this range. fuel_demand_mode_code_prev_snapshot (0x3fa644) is the copy of fuel_demand_mode_code taken after the minimum timing limit stage (value 28 when the minimum limit won) - not renamed.')

N('CBO block words (0x40a518 = e2m 0x01171100) as written by the ROM functions of this range, for the owner of that block; all agree with the e2m offsets and the dump: 0x40a518 fuel_blend_load_ratio_cached = CBO_Charge_Aggressiveness_Ref (copy of the gross-to-limit ratio, 2866); 0x40a51a fuel_demand_high_limit_cached = CBO_EGR_Frac_Ref (copy of the EGR fraction reference, 0); 0x40a51c fuel_demand_limit_copy = CBO_Fuel_Ref (copy of the fuel reference, 1030); 0x40a51e fuel_demand_rate_raw_cached = CBO_MCF_Ref (copy of the mass charge flow reference, 556; 4733 / 400 lb/min limit applies after it); 0x40a520 fuel_correction_output = CBO_SOI_Ref (timing reference + adjustment, clamped -1023..1024); 0x40a522 fuel_demand_mode2_adjusted = CBO_Delta_Charge_Tmptr; 0x40a524 fuel_demand_mode2_correction_lookup = CBO_Charge_Tmptr_Adj; 0x40a52e fuel_demand_correction_scale = CBO_SOI_Adj; 0x40a530 fuel_demand_correction_input = CBO_Composite_Adj (product of the charge temperature and oxygen fraction adjustments, window 0x405a08 / 0x405a0a); 0x40a532 fuel_demand_timing_correction = CBO_bsNOx; 0x40a53a engine_load_correction_mode_flag = CBO_Off; 0x40a53c engine_load_correction_blend = CBO_O2_Frac_Adj (Q13, capped 0x2000); 0x40a53e fuel_injection_divisor_base = CBO_Air_Fuel_Ratio_Ref ((1 - EGR) x mass charge flow / fuel flow, capped 51200); 0x40a540 fuel_load_correction_from_timing = CBO_FSNOx_Ratio_Ref; 0x40a542 fuel_injection_timing_complement = CBO_Intake_Charge_O2_Frac_Ref (0x76b = 0.232 minus the EGR dilution); 0x40a544 fuel_load_correction_alt = CBO_FSNOx_Ratio_Actual; 0x40a54c fuel_load_correction_input = the actual oxygen fraction input written by Bank 2 fuel_loadCorrection_rpmNormalized_calc. fuel_demand_rate_complement (0x2000 - EGR fraction) is a further word of cm848_calculateOffNominalOxygenFractionAdjustment.')

N('Inputs of the reference stage that sit outside the CBR / CBL blocks (notes, no rename proposed): fuel_demand_boost_input (0x40a61c, 2050) is the coolant temperature (1/64 deg F; slot 2 reads 2049, the normal source 0x40bd88 and the fault substitute 0x40bdae = 12160 = 190 deg F, written by cm848_mainLoop_step_3), name it coolant_temperature_in_use-like; fuel_demand_boost_offset (0x40a460, 2602) is the intake temperature (init from slot 9 = 2604) that the charge temperature adjustment uses; engine_load_input_value (0x40a604, 1166) is the intake air density (cm848_mainLoop_step_2: pressure constant / (temperature + 460 R), rate limited by engine_load_ramp_rate_lower / upper; 6.1035e-5 lbm/ft3 per count = 0.071 lbm/ft3); fuel_blend_coefficient (0x40a168, 0 in the dump) is the alpha command as a Q14 fraction (written by hpcr_calculateFuelTrimOutput / cm848_temperatureBasedFuelTrim); fuel_mode_status_flags (0x40a5ee, 0x402) holds the permission / protection state bits that cm848_selectChiAndAlpha tests (1, 2, 8, 0x10, 0x20, 0x40, 0x80, 0x100, 0x200), written by fuel_modeStatusFlags_update; fuel_demand_min_threshold (0x40a5b4, 1024) x 2 is the minimum level used by cm848_lookupProtectiveChi; boost_fuel_mode_active (0x40a668, 1) is written by cm848_selectBoostPressureFromSensorChannel75 and switches cm848_limitMassChargeFlowReference between the density limit and the fixed 400 lb/min cap; fuel_demand_load_axis_cap (0x40a55a) is the cap of the fuel reference with source code 54; fuel_demand_offset_correction (0x40b22a, 256) is added to the maximum fuel limit under fuel_feature_control_flags bits 0x40 / 0x80; fuel_demand_mode_code (0x40a2f2) / fuel_demand_mode_flags (0x40a2f4) are the main timing source code (27 / 28 set by the combustion limits) and the timing increment flags (0x10 / 0x20 / 0x40).')

N('Words in the blocks with no code access in the whole binary (xref_addr.py: 0 reads, 0 writes): 0x40a468 (e2m CBL_EGR_Frac_Ref +02), 0x40a478 (e2m Timing_State_Incr_Before_CBL +12, whose role is played by fuel_demand_mode_flags at 0x40a2f4) and 0x40a516 (e2m OFC_Torque_Limit +96, torque limit from the fuel limit). No new_global rows: there is no access width to type them from. The CBR words 0x40a496-0x40a49c have no direct references only because they are the fields of fuel_blend_state_t (rendered through the struct).')

N('Struct and instance renames for the lead: fuel_blend_state_t -> combustion_reference_state_t (instance 0x40a494 and the sub-rows 0x40a496 / 0x40a498 / 0x40a49a / 0x40a49c / 0x40a49e in global_variables.csv, fields renamed in the struct_field rows; the field comments in structure_definitions.csv lines 221-226 are wrong in several places (blend_weight is not 0-100 percent, bypass_load_correction is not added to engine_load_normalized) and should be replaced by the evidence texts). protection_threshold_set_t -> combustion_chi_maximum_fuel_points_t (instance 0x40a502, fields in the struct_field rows; the instance rows in global_variables.csv for 0x40a504-0x40a50a follow). A new enum for combustion_chi_source_code would fit (1 CHI_SOURCE_AIR_DENSITY, 3 CHI_SOURCE_COOLANT_TEMPERATURE, 10 CHI_SOURCE_EGR_OFF, 12 CHI_SOURCE_USER_OVERRIDE_FULL, 13 CHI_SOURCE_USER_OVERRIDE_SINGLE_VALUE, 14 CHI_SOURCE_PROTECTION; the e2m does not list the enumerators, the numbers are from the code) - not defined here because the enum row types of this wave only rename existing enums.')

N('Cross-checks and cautions: (a) the e2m block layout matched the code at every offset I could test (CBR +00..+7E, the five map groups, the max fuel points +82..+94, CBL +00..+18 except +02 / +12 which have no access, CBO +00..+2C, the calibration orders C_CBR 0x0116A400-0x0116A424, C_CBL 0x01171A00, C_CBO 0x01171000, and the table order Chi2 / Chi3 / Chi4 / Alpha0 / Alpha1); the two exceptions are +12 (0x40a492 is a fuel limit input from Bank 2, no e2m word) and +80 (code ORs protection and EGR-off). (b) The alpha-chi family is shared: 17 functions besides the writer read combustion_chi_lower / upper_map_number, chi_hundredths and alpha_percent to pick map_1..4 (pilot / auxiliary timing and quantity and the fuel pressure setpoint); the families named in earlier waves keep their names, only their comments that cite fuel_blend_lower_map_number need the new name. (c) Names in plate comments use the proposed new names for the words and functions renamed here. (d) Nothing was run on the Ghidra project; no CSV was edited.')

# ---------------------------------------------------------------- review fixes (advisor pass)
def row(kind, addr=None, old=None, struct=None):
    for r in rows:
        if r['kind'] != kind:
            continue
        if addr is not None and r.get('address') != A(addr):
            continue
        if old is not None and r.get('old') != old:
            continue
        if struct is not None and r.get('struct') != struct:
            continue
        return r
    raise KeyError((kind, addr, old))


# keep rows carry no new name
for r in rows:
    if r['kind'] == 'function' and r.get('new') == r['old']:
        del r['new']

# CBL tables are outside the assigned range 0x405234-0x40523f: one note instead of global rows
TABLE_ADDRS = [0x40523e, 0x405266, 0x405288, 0x4054e8, 0x405510, 0x405532, 0x405792, 0x4057b4, 0x4057d6]
table_rows = [row('global', a) for a in TABLE_ADDRS]
rows[:] = [r for r in rows if not any(r is t for t in table_rows)]
rows.append({'kind': 'note', 'text': 'CBL calibration tables (proposals only; they lie outside the assigned range 0x405234-0x40523f, so no global rows; wave 4 already proposed the first six; no _cal because none is EEPROM-backed). Minimum start of injection limit lookup in cm848_applyCombustionTimingLimits (x = engine speed 500..3500 rpm, y = fuel_demand_limit_copy 0..150 mm3): 0x40523e injection_timing_rpm_axis_cal -> injection_timing_combustion_minimum_limit_x_axis; 0x405266 injection_timing_load_axis_cal -> injection_timing_combustion_minimum_limit_y_axis; 0x405288 injection_timing_advance_yend_cal -> injection_timing_combustion_minimum_limit_grid (19 x 16, flat 43 counts = 5 deg in the dump). Maximum limit lookup of the same function: 0x4054e8 injection_timing_mode2_rpm_axis_cal -> injection_timing_combustion_maximum_limit_x_axis; 0x405510 injection_timing_mode2_ystart_cal -> injection_timing_combustion_maximum_limit_y_axis; 0x405532 injection_timing_mode2_yend_cal -> injection_timing_combustion_maximum_limit_grid (flat 384 counts = 45 deg). Density based mass charge flow limit lookup in cm848_limitMassChargeFlowReference (x = engine speed 800..3500 rpm, y = intake air density 737..1638 counts): 0x405792 fuel_demand_load_rate_cap_rpm_axis_cal -> mass_charge_flow_density_limit_x_axis; 0x4057b4 fuel_demand_load_rate_cap_ystart_cal -> mass_charge_flow_density_limit_y_axis; 0x4057d6 fuel_demand_load_rate_cap_yend_cal -> mass_charge_flow_density_limit_grid (16 x 16, 3200..9600 counts = 25..75 lb/min). Roles come from the lookup calls in the code and the axes / grids in the dump; the e2m C_CBL_SOI_Min_* / C_CBL_SOI_Max_* / C_CBL_MCF_Limit_* tables follow in the same order.'})

# torque: neither code nor data carry it
r = row('function', 0x16724)
r.pop('plate_comment', None)
r.pop('new', None)
r['verdict'] = 'uncertain'
r['evidence'] = 'Code: dual-axis lookup of an engine speed (param_2) against the speed axis and a fuel quantity (param_1) against the fuel axis of protection_rpm_correction_* (speed 620..3500 rpm x fuel 0..140 mm3, the same fuel axis as the combustion reference maps), signed result (flags 6); the grid is all zero in this calibration and the result is only stored into five write-only words. e2m: CBR_Max_Chi_Torque_At_Point_1..5 (FT*LB at 0.5) sit at exactly the five words it feeds, but neither the code nor the data show a torque, so no rename is proposed.'
r = row('function', 0x16774)
r['new'] = 'cm848_calculateChiMaximumFuelAtSpeedPoints'
r['plate_comment'] = 'Calculates the maximum fuel of the chi curve at five engine speed points (cm848_lookupChiMaximumFuelAtSpeed, stored as chi_maximum_fuel_at_point_1..5 of the struct at 0x40a502) and passes each through cm848_fuelDemandRpmCorrection into protection_threshold_scaled_rpm, protection_recovery_threshold_rpm, protection_hysteresis_rpm, protection_threshold_alt_rpm and protection_base_threshold_rpm. Called from main_loop; the ten results are read nowhere else. (was cm848_lookupProtectionFuelDemand)'
r['evidence'] = 'Code: five fuel lookups at five engine speed inputs (governor_integrator_rpm_output, protection_recovery_threshold_cal, protection_threshold_lookup_rpm, protection_threshold_scale_working, protection_base_threshold_working, all used as the x input of the engine speed curves), then five conversions; the ten results are written here and read nowhere else. Dump fuel points 1030 / 1182 / 1443 / 1607 / 1475 (70..109 mm3), second set 0. e2m: CBR_Max_Chi_Fuel_At_Point_1..5 (+82..+8A) sit at exactly the five fuel words; the second set (CBR_Max_Chi_Torque_At_Point_1..5) is left uncertain (see 0x16724). The fuel points are chi curve values, not protection thresholds.'
for n, a in enumerate([0x40a50c, 0x40a50e, 0x40a510, 0x40a512, 0x40a514], start=1):
    r = row('global', a)
    r.pop('new', None)
    r['verdict'] = 'uncertain'
    r['evidence'] = 'Code: write-only result of cm848_fuelDemandRpmCorrection(chi_maximum_fuel_at_point_%d, the same engine speed): a signed value from a speed x fuel grid that is all zero in this calibration (dump 0); it is not an rpm. e2m: CBR_Max_Chi_Torque_At_Point_%d (+%02X, FT*LB at 0.5) sits at exactly this address, but neither the code nor the data show a torque, so no new name; if a running engine shows a torque here, combustion_chi_maximum_torque_at_point_%d fits.' % (n, n, 0x8c + 2 * (n - 1), n)

# emission level: name only what the code proves
r = row('global', 0x40a4a0)
r['new'] = 'combustion_chi_paired_level'
r['evidence'] = 'Code: written once in cm848_selectChiAndAlpha with the value paired with the chi by the chi / level axes (record word 2 of the base chi, or the calibrations 0x4059dc / 0x4059e6 / 0x4059f0 of the override, EGR-off and protection branches); no reader (testpoint). Dump 16384 at 1/2048 = the EGR-off calibration. e2m calls it chi.el (CBR_Chi_EL +20, unit G/HP*HR); the code proves the pairing and the chi / level conversion but not what the level is, so the name says only paired level.'
r = row('global', 0x40a4e8)
r['new'] = 'combustion_base_chi_paired_level'
r['evidence'] = 'Code: record word 2 (the level paired with the base chi) stored by cm848_determineBaseChi, read once by cm848_selectChiAndAlpha. Dump 2048 (1.0 at 1/2048). e2m calls it base chi.el (CBR_Base_EL +68, G/HP*HR); the code proves the pairing, not the meaning of the level.'

# no hedge wording on the rows we stand behind
r = row('function', 0x14610)
r['evidence'] = 'Code: same five-map structure as the other reference functions; the output 0x40a490 is read only by cm848_calculateOffNominalCompensation, which multiplies it by the composite adjustment and the timing adjustment scale, divides by 546 and clamps 0..65533. e2m: block position (CBR_NOx_Target_Ref +10, maps CBR_NOx_Alpha0..Chi4 +48..+50), scale G/HP*HR at 1/2048 and CBO_bsNOx = it adjusted for off-nominal conditions (+1A = fuel_demand_timing_correction). Dump 5120 = exactly 2.5 g/hp-hr with all five maps flat. Code and e2m agree.'
r = row('global', 0x40a490)
r['evidence'] = 'Code: unsigned alpha-chi blend of five maps, written once in cm848_calculateNitrogenOxidesTargetReference; the only reader multiplies it by the composite off-nominal adjustment and the timing adjustment scale, divides by 546 and clamps 0..65533 into fuel_demand_timing_correction. e2m: CBR_NOx_Target_Ref (+10), G/HP*HR at 1/2048, and CBO_bsNOx (+1A = 0x40a532) = that value adjusted for off-nominal conditions. Dump 5120 = exactly 2.5 g/hp-hr with every map flat. Code and e2m agree.'
r = row('function', 0x14080)
r['evidence'] = 'Code: the value stored in fuel_demand_boost_offset is sensor_channel9_pressure_value (slot 9 = intake manifold temperature in the firmware/CLAUDE.md slot table, SPN 105); the RAM dump holds 2604 / 2602 = 40.7 deg F, a temperature, not a pressure. fuel_demand_boost_offset is the intake temperature that cm848_calculateOffNominalChargeTemperatureAdjustment subtracts from the charge temperature reference; the two Q16 accumulators are loaded with the same value.'
r = row('function', 0x16a90)
r['evidence'] = 'Code: fuel_demand_rate_complement = 0x2000 - EGR fraction reference; fuel_injection_divisor_base = complement x MCF reference / (fuel_rate_rpm_factor x 64) (rpm x fuel quantity); 0x76b is 23.2 percent, the oxygen fraction of air; the result is the ratio of two lookups in the same 11-point table, capped at 0x2000. e2m CBO block: CBO_Air_Fuel_Ratio_Ref (+26), CBO_Intake_Charge_O2_Frac_Ref (+2A), CBO_FSNOx_Ratio_Ref / Actual (+28 / +2C), CBO_O2_Frac_Adj (+24) = engine_load_correction_blend. Code and e2m agree on every term.'
r = row('function', 0x15e08)
r['evidence'] = r['evidence'].replace('The level reading is the e2m unit (G/HP*HR).', 'The e2m calls the level EL (G/HP*HR); the code only shows the chi / level conversion.')
r = row('function', 0x14528)
r['evidence'] = r['evidence'].replace('The caller words are named combustion_chi_hundredths and combustion_alpha_percent.', 'The caller words are the struct fields chi_hundredths and alpha_percent.')

# stale or non-existent names inside plate comments and evidence
SUBS = [
    ('cm848_calculateCombustionOffNominalReferences', 'cm848_runOffNominalCompensation'),
    ('sets combustion_alpha_percent from', 'sets alpha_percent of the struct at 0x40a494 from'),
    ('combustion_alpha_percent', 'alpha_percent'),
    ('combustion_chi_hundredths', 'chi_hundredths'),
    ('alpha / chi / emission level wording', 'alpha / chi / level wording'),
    ('combustion_chi_override_emission_level', 'combustion_chi_override_paired_level'),
    ('combustion_egr_off_emission_level', 'combustion_egr_off_paired_level'),
    ('combustion_protection_emission_level', 'combustion_protection_paired_level'),
    ('torque for the five points at 0x40a50c-0x40a514', 'torque for the five words at 0x40a50c-0x40a514 (left uncertain)'),
    ('cm848_calculateChiMaximumFuelAndTorquePoints', 'cm848_calculateChiMaximumFuelAtSpeedPoints'),
    ('NOx for 0x40a490,', 'NOx for 0x40a490 (block position, scale and CBO_bsNOx from the e2m; the consumer arithmetic and the dump fit),'),
    ('fuel_demand_band_low / high_threshold', 'fuel_demand_band_low_threshold / fuel_demand_band_high_threshold'),
    ('fuel_rpm_table_boost1..4_cal', 'the four curves fuel_rpm_table_boost1_cal to fuel_rpm_table_boost4_cal'),
    ('fuel_blend_state_t.egr_off_flag', 'egr_off_flag of the struct at 0x40a494'),
    ('(added to engine_load_normalized)', '(it claims the value is added to the normalized engine load)'),
]
for r in rows:
    for key in ('plate_comment', 'evidence', 'text'):
        if key in r:
            for a, b in SUBS:
                r[key] = r[key].replace(a, b)

# the protection torque grid proposal in the table note is not made any more
for r in rows:
    if r['kind'] == 'note' and 'chi_maximum_torque_x_axis' in r['text']:
        r['text'] = r['text'].replace(' Fuel to torque grid for the torque points: 0x405d52 / 0x405d7a / 0x405d9c protection_rpm_correction_axis_cal / _ystart_cal / _yend_cal (grid all zero) -> chi_maximum_torque_x_axis / _y_axis / _grid.', ' The speed x fuel grid behind the five uncertain words (0x405d52 / 0x405d7a / 0x405d9c protection_rpm_correction_axis_cal / _ystart_cal / _yend_cal, all zero) is not renamed.')


# ---------------------------------------------------------------- validation
def load_names():
    glob_names = {}
    for fn in ('global_variables.csv',):
        with open(OUT + fn) as f:
            for line in f:
                if line.startswith('#') or not line.strip():
                    continue
                p = line.rstrip('\n').split(',', 3)
                try:
                    a = int(p[0], 16)
                except ValueError:
                    continue
                glob_names.setdefault(p[1], []).append(a)
    func_names = {}
    with open(OUT + 'function_renames.csv') as f:
        for line in f:
            if line.startswith('#') or not line.strip():
                continue
            p = line.rstrip('\n').split(',', 2)
            try:
                a = int(p[0], 16)
            except ValueError:
                continue
            func_names[p[1]] = a
    arr_names = set()
    with open(OUT + 'arrays.csv') as f:
        for line in f:
            if line.startswith('#') or not line.strip():
                continue
            p = line.rstrip('\n').split(',', 4)
            if len(p) > 1:
                arr_names.add(p[1])
    struct_fields = {}
    with open(OUT + 'structure_definitions.csv') as f:
        for line in f:
            if line.startswith('#') or not line.strip():
                continue
            p = line.rstrip('\n').split(',')
            if len(p) > 2:
                struct_fields.setdefault(p[0], set()).add(p[2])
    return glob_names, func_names, arr_names, struct_fields


glob_names, func_names, arr_names, struct_fields = load_names()
addr_to_glob = {}
for n, al in glob_names.items():
    for a in al:
        addr_to_glob.setdefault(a, set()).add(n)
addr_to_func = {a: n for n, a in func_names.items()}
BANNED = ['tmptr', 'mcf', 'soi', 'nox', 'ofc', 'fclr', 'emm', 'cbr', 'cbl', 'cbo', 'cbp', 'fss', 'cmpr', 'temp_', '_el_', 'qty', 'cmd', 'ref_', 'adj_']
problems = []
newnames = {}
for r in rows:
    k = r['kind']
    if k == 'note':
        continue
    new = r.get('new')
    if k == 'function':
        a = int(r['address'], 16)
        if addr_to_func.get(a) != r['old']:
            problems.append('function old mismatch %s %s (csv %s)' % (r['address'], r['old'], addr_to_func.get(a)))
        if new and not re.fullmatch(r'cm848_[a-z][A-Za-z0-9]*', new):
            problems.append('function name shape %s' % new)
        if new and new != r['old'] and (new in func_names or new in glob_names or new in arr_names):
            problems.append('function name collides %s' % new)
    elif k == 'global':
        a = int(r['address'], 16)
        if r['old'] not in addr_to_glob.get(a, set()):
            problems.append('global old mismatch %s %s (csv %s)' % (r['address'], r['old'], addr_to_glob.get(a)))
        if new:
            if not re.fullmatch(r'[a-z][a-z0-9_]*', new):
                problems.append('global name shape %s' % new)
            if new != r['old'] and (new in func_names or new in glob_names or new in arr_names):
                problems.append('global name collides %s' % new)
            if new.endswith('_cal') and not (0x3fd482 <= a <= 0x3feec1):
                problems.append('_cal outside EEPROM %s' % new)
    elif k == 'struct_field':
        if r['old'] not in struct_fields.get(r['struct'], set()):
            problems.append('struct field missing %s.%s' % (r['struct'], r['old']))
        if new in struct_fields.get(r['struct'], set()):
            problems.append('struct field name exists %s' % new)
        for s, fs in struct_fields.items():
            if new in fs:
                problems.append('struct field name used by another struct %s in %s' % (new, s))
        if not re.fullmatch(r'[a-z][a-z0-9_]*', new):
            problems.append('field name shape %s' % new)
    if new:
        low = new.lower()
        for b in BANNED:
            if b in low:
                problems.append('banned token %s in %s' % (b, new))
        if '0x' in low or re.search(r'(^|_)hex(_|$)', low):
            problems.append('hex in name %s' % new)
        if re.search(r'(^|_)protection(_|$)', low) and 'protection_chi' not in low and 'protection_emission' not in low:
            problems.append('bare protection %s' % new)
        key = (k, new) if k != 'struct_field' else (k, r['struct'], new)
        if key in newnames and new != r['old']:
            problems.append('duplicate new name %s' % (key,))
        newnames[key] = r['address'] if 'address' in r else r['struct']
    if k != 'note':
        if 'evidence' not in r or not r['evidence']:
            problems.append('no evidence %s' % r)
        if k == 'function' and r.get('plate_comment') and not r['plate_comment'].rstrip().endswith(')'):
            problems.append('plate comment lacks (was ...) %s' % r['old'])

# JSON shape and write
with open(RES, 'w') as f:
    for r in rows:
        f.write(json.dumps(r, ensure_ascii=True) + '\n')
from collections import Counter
print('rows', len(rows), Counter(r['kind'] for r in rows))
print('verdicts', Counter(r.get('verdict') for r in rows if r['kind'] != 'note' and r['kind'] != 'struct_field'))
print('PROBLEMS', len(problems))
for p in problems:
    print('  ', p)

# identifier check inside plate comments / evidence / notes
known = set(glob_names) | set(func_names) | set(arr_names)
for s, fs in struct_fields.items():
    known |= fs
    known.add(s)
emitted = set()
old_renamed = set()
for r in rows:
    if r['kind'] == 'note':
        continue
    if r.get('new'):
        emitted.add(r['new'])
        if r['new'] != r['old']:
            old_renamed.add(r['old'])
tok_re = re.compile(r'(?<![A-Za-z0-9_*/.])(cm848_[A-Za-z0-9]+|[a-z][a-z0-9]*(?:_[a-z0-9]+){2,})(?![A-Za-z0-9_*])')
unknown = {}
stale = {}
for r in rows:
    for key in ('plate_comment', 'evidence', 'text'):
        if key not in r:
            continue
        txt = r[key]
        if key == 'plate_comment':
            txt = re.sub(r'\(was [^)]*\)\s*$', '', txt)
        for t in tok_re.findall(txt):
            if t in known or t in emitted:
                if key == 'plate_comment' and t in old_renamed and t not in emitted:
                    stale.setdefault(t, []).append(r.get('old') or r.get('kind'))
                continue
            unknown.setdefault((key == 'text', t), []).append(r.get('old') or r.get('kind'))
print('UNKNOWN identifiers in plate/evidence:')
for (isnote, t), where in sorted(unknown.items()):
    if not isnote:
        print('   ', t, '<-', sorted(set(where))[:4])
print('UNKNOWN identifiers in notes (proposals expected):')
for (isnote, t), where in sorted(unknown.items()):
    if isnote:
        print('   ', t)
print('STALE old names used in plate comments:')
for t, where in sorted(stale.items()):
    print('   ', t, '<-', sorted(set(where))[:4])
from collections import Counter as C2
print('FINAL', len(rows), C2(r['kind'] for r in rows), C2(r.get('verdict') for r in rows if r['kind'] in ('function', 'global')))

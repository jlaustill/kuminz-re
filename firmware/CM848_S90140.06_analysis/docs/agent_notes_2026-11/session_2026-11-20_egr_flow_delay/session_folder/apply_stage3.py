"""Stage 3 (label-only): the rest of the CHP charge flow family, its tables / caches / filters, the pumping torque
words (e2m 1780 / 1781 / 1954) and the exhaust pressure words (e2m 1A5D / 1772) with their two writers.
Usage: apply_stage3.py <firmware output dir> <scratch dir>
Writes <scratch>/map_stage3.csv (proof mapping) and <scratch>/map_refresh_stage3.csv (refresh pairs)."""
import csv
import os
import sys

out, scratch = sys.argv[1:3]
CF = "cm848_calculateChargeFlows"

FUNCTIONS = {
    0x00012724: ("cm848_checkFuelSystemFaultFlags", "cm848_calculateDownstreamEgrFlowSource",
        "e2m 177F +18 EGR_Flow_Source of the downstream EGR flow model (0 = PRIMARY / 1 = BACKUP): 0 only while "
        "egr_valve_position_source, egr_orifice_delta_pressure_source, charge_pressure_source and "
        "egr_orifice_temperature_source are all 0 (the model's inputs). cm848_calculateEgrMassFlowBeforeDelay stores "
        "it in egr_flow_source while egr_flow_downstream_model_select is nonzero. (was cm848_checkFuelSystemFaultFlags)"),
    0x00012778: ("cm848_checkEngineFaultConditions", "cm848_calculateUpstreamEgrFlowSource",
        "e2m 177F +18 EGR_Flow_Source of the upstream EGR flow model (0 = PRIMARY / 1 = BACKUP): 0 only while "
        "egr_valve_position_source, exhaust_pressure_source and exhaust_temperature_source are all 0 (the model's "
        "inputs). cm848_calculateEgrMassFlowBeforeDelay stores it in egr_flow_source while "
        "egr_flow_downstream_model_select is 0. (was cm848_checkEngineFaultConditions)"),
    0x00012a58: ("cm848_initFilterCoefficients", "cm848_initializeEgrFlowEstimate",
        "Boot initialization of the EGR flow estimate (e2m 177E / 177F), called by cm848_initializeChargeFlows: presets "
        "the lookup caches of the upstream and downstream corrected flow grids and of the two square-root temperature "
        "tables to 2, and clears the three filters - egr_oxygen_fraction_filter_state and egr_mass_flow_delayed_filter "
        "on egr_mass_flow_delayed_filter_coefficient (C_CHP_EGR_Flow_Fil_Cnst), egr_valve_position_filter on "
        "egr_valve_position_filter_coefficient (C_CHP_EGR_Pos_Delay_Fil_Cnst). (was cm848_initFilterCoefficients)"),
    0x00012dc4: ("cm848_fuelDemandWithLoadCompensation", "cm848_calculateChargeFlowEstimate",
        "The charge flow estimate (e2m 177C / 177D), called by cm848_calculateChargeFlows: stores the intake manifold "
        "temperature in degrees Rankine (charge_flow_estimate_terms.intake_manifold_temperature_rankine = "
        "intake_manifold_temperature_filtered + 0x7300, i.e. + 460 F at 1/64 F per count; 177D +2 "
        "CHP_Intake_Manifold_Tmptr_R), runs cm848_calculateVolumetricEfficiency and cm848_calculateChargeMassFlow, and "
        "sets charge_flow_estimate_terms.charge_flow_source (177D +C Charge_Flow_Source): 0 PRIMARY only while "
        "intake_manifold_temperature_filtered_source, charge_pressure_source and exhaust_pressure_source are all 0. "
        "(was cm848_fuelDemandWithLoadCompensation)"),
    0x00012e40: ("cm848_initFilterTablePointers", "cm848_initializeChargeMassFlowFilter",
        "Boot initialization of the charge mass flow filter, called by cm848_initializeChargeFlows: clears "
        "charge_mass_flow_filter_state and points its coefficient at charge_mass_flow_filter_coefficient (e2m 177C +0 "
        "C_CHP_Charge_Flow_Fil_Cnst). (was cm848_initFilterTablePointers)"),
    0x00012e60: ("cm848_fuelControlMainCalculation", CF,
        "The CHP charge flow model's 10 ms task (cm848_phase_group_a_processing, every even phase of the 40-phase main "
        "loop): cm848_calculateChargeFlowEstimate (the speed-density charge mass flow, e2m 177C / 177D), "
        "cm848_calculateDelayedEgrFlowAndFraction (the EGR mass flow, its transport delay and the EGR fraction, 177E / "
        "177F) and cm848_calculateFreshAirMassFlow (charge minus EGR, 177B). CHP is the e2m prefix of all these "
        "records; the e2m never spells it out. (was cm848_fuelControlMainCalculation)"),
    0x00012e88: ("cm848_initFuelControlFilterSystem", "cm848_initializeChargeFlows",
        "Boot initialization of the CHP charge flow model, called by cm848_applicationMain: "
        "cm848_initializeChargeMassFlowFilter, cm848_initializeEgrFlowEstimate, cm848_initializeFreshAirMassFlowFilter "
        "and cm848_initializePumpingTorqueLookupCache. (was cm848_initFuelControlFilterSystem)"),
    0x00012eb4: ("cm848_fuelDemandErrorCalculation", "cm848_calculateFreshAirMassFlow",
        "The fresh air mass flow (e2m 177B), called by cm848_calculateChargeFlows: charge_mass_flow_filtered - "
        "egr_mass_flow_delayed_filtered (0 unless the EGR flow is the smaller), filtered by exponentialMovingAverage "
        "(fresh_air_mass_flow_filter_state, coefficient fresh_air_mass_flow_filter_coefficient = e2m 1A0F +0 "
        "C_CHP_Fresh_Air_Flow_Fil_Cnst) into charge_flow_estimate_terms.fresh_air_mass_flow_filtered (177B +0 "
        "Fresh_Air_Flow); charge_flow_estimate_terms.fresh_air_flow_source (177B +2) is 0 PRIMARY only while "
        "charge_flow_source and egr_flow_source are 0. (was cm848_fuelDemandErrorCalculation)"),
    0x00012f40: ("cm848_initFuelDemandBlendPointers", "cm848_initializeFreshAirMassFlowFilter",
        "Boot initialization of the fresh air mass flow filter, called by cm848_initializeChargeFlows: clears "
        "fresh_air_mass_flow_filter_state and points its coefficient at fresh_air_mass_flow_filter_coefficient (e2m "
        "1A0F +0 C_CHP_Fresh_Air_Flow_Fil_Cnst). (was cm848_initFuelDemandBlendPointers)"),
    0x0001327c: ("cm848_initFuelFilterDefaults", "cm848_initializePumpingTorqueLookupCache",
        "Boot initialization of the pumping torque lookup, called by cm848_initializeChargeFlows: presets both words "
        "of the 2-D lookup cache that cm848_calculatePumpingTorqueAdjustment passes to cm848_dualAxisTableInterpolation "
        "(the nominal engine delta pressure grid, e2m 1954) to 2. (was cm848_initFuelFilterDefaults)"),
    0x00509848: ("phase_group_a_validateEngineSync", "cm848_calculateExhaustPressure",
        "Exhaust pressure post-processing (e2m 1A5D), every 10 ms from cm848_phase_group_a_processing. With "
        "egr_flow_cold_side_algorithm_select set (e2m 177E +8, the cold side EGR flow algorithm) the measurement is "
        "sensor channel 109 and exhaust_pressure_state = exhaust_pressure_estimate_state | sensor_channel109_fault_status; "
        "otherwise the measurement is charge_pressure + egr_delta_pressure_sensor_output and the state gets 8 / 4 for a "
        "DEFAULT / BACKUP charge pressure or delta pressure source. Fault bit 524 (fault_detected_bits_512_to_527 "
        "0x1000) adds 0x20 in both. Then: no 0x2a state bit - the measurement (negative values clamped to 0), "
        "exhaust_pressure_source 0 PRIMARY; else no 0x80 bit - exhaust_pressure_estimate (e2m 1772 +A), source 1 BACKUP; "
        "else the sensor default sensor_channel109_default_value, source 2 DEFAULT. exhaust_pressure_estimate_as_primary_cal "
        "(1 on this truck) forces the estimate with source 0. exhaust_pressure_virtual_sensor_copy (1772 +0) keeps the "
        "raw sensor value. (was phase_group_a_validateEngineSync)"),
    0x00509a2c: ("cm848_initBoostPressureFaultHandling", "cm848_initializeExhaustPressure",
        "Boot initialization of the exhaust pressure (e2m 1A5D), called by cm848_applicationMain: exhaust_pressure and "
        "exhaust_pressure_virtual_sensor_copy = sensor_channel109_value; exhaust_pressure_source 0 PRIMARY while "
        "sensor_channel109_fault_status is 0 or 1 and 2 DEFAULT when it is 2. (was cm848_initBoostPressureFaultHandling)"),
}

NO_CAL = "ROM-copied RAM outside the EEPROM mirror, so no _cal."
# address: (old label, new name, type, comment); type is checked against the current row (None = no row yet)
GLOBALS = {
    0x0040a7d0: ("boost_pressure_current_raw", "exhaust_pressure", "word",
        "e2m 1A5D +0 Exhaust_Press [IN_HG] 'Exhaust pressure post processing value' (0.0159 inHg per count; 1784 in the "
        "RAM dump): cm848_calculateExhaustPressure picks the measurement (sensor channel 109 on the cold side EGR "
        "algorithm, else charge_pressure + egr_delta_pressure_sensor_output), the estimate or the sensor default. "
        "Readers: the volumetric efficiency pressure ratio (charge_flow_estimate_terms.pressure_ratio), the upstream EGR "
        "flow model, cm848_calculateEgrDeltaPressures and cm848_calculateResidualGasMass. (was boost_pressure_current_raw)"),
    0x0040a7d2: ("fuel_demand_droop_state", "exhaust_pressure_source", "word",
        "e2m 1A5D +2 Exhaust_Press_Source (0 = PRIMARY / 1 = BACKUP / 2 = DEFAULT; 0 in the RAM dump): set by "
        "cm848_calculateExhaustPressure / cm848_initializeExhaustPressure; read by charge_flow_source "
        "(cm848_calculateChargeFlowEstimate), the upstream EGR_Flow_Source (cm848_calculateUpstreamEgrFlowSource), "
        "cm848_calculateEgrDeltaPressures and cm848_updateEgrSystemHealthFlags. (was fuel_demand_droop_state)"),
    0x0040a7d4: ("boost_pressure_source_flags", "exhaust_pressure_state", "word",
        "e2m 1A5D +4 Exhaust_Press_State (130 = 0x82 in the RAM dump): exhaust_pressure_estimate_state | the sensor's "
        "fault status (cold side) or 8 / 4 for a DEFAULT / BACKUP charge pressure or delta pressure source (hot side), "
        "| 0x20 with fault bit 524. A 0x2a bit stops cm848_calculateExhaustPressure from using the measurement, 0x80 "
        "from using the estimate. (was boost_pressure_source_flags)"),
    0x0040a67c: ("boost_pressure_synthetic_ema", "exhaust_pressure_estimate", "word",
        "e2m 1772 +A Exhaust_Press_Est [IN_HG] 'Exhaust pressure estimate - backup to sensor' (1785 in the RAM dump): "
        "cm848_phase_groupA_exponentialAverage filters the e2m 198C C_TPE_EMP_* model (engine speed, EGR valve "
        "position, charge pressure, a constant) into it; cm848_calculateExhaustPressure uses it as the backup, or as "
        "the primary while exhaust_pressure_estimate_as_primary_cal is set. (was boost_pressure_synthetic_ema)"),
    0x0040a67a: ("boost_correction_mode_flags", "exhaust_pressure_estimate_state", "word",
        "e2m 1772 +8 Exhaust_Press_EStat (128 = 0x80 in the RAM dump): cm848_phase_groupA_exponentialAverage sets 0x80 "
        "while the estimate is disabled (combustion_override_and_estimation_enable_flags_cal bit 0x2000 clear) or an "
        "input source is DEFAULT, 0x40 while one is BACKUP, else 0; OR'ed into exhaust_pressure_state. "
        "(was boost_correction_mode_flags)"),
    0x003fd8ea: ("DAT_003fd8ea", "exhaust_pressure_estimate_as_primary_cal", None,
        "EEPROM 0x468 (lhz @ 0x5099fc; 1 in the RAM mirror and the EEPROM dump; no e2m record): while nonzero, "
        "cm848_calculateExhaustPressure takes exhaust_pressure_estimate as the exhaust pressure with source 0 PRIMARY, "
        "whatever the measurement does. Named from that one use."),
    0x003fa5d6: ("boost_modifier_filter_state", "charge_mass_flow_filter_state", "ema_filter_state_t",
        "exponentialMovingAverage record (ema_filter_state_t) of the charge mass flow: cm848_calculateChargeMassFlow "
        "filters the clamped speed-density flow into charge_mass_flow_filtered; cm848_initializeChargeMassFlowFilter "
        "points its coefficient at charge_mass_flow_filter_coefficient (e2m 177C +0 C_CHP_Charge_Flow_Fil_Cnst). "
        "(was boost_modifier_filter_state)"),
    0x003fa5e2: ("fuel_blend_rpm_base_filter_state", "fresh_air_mass_flow_filter_state", "ema_filter_state_t",
        "exponentialMovingAverage record (ema_filter_state_t) of the fresh air mass flow in "
        "cm848_calculateFreshAirMassFlow (output charge_flow_estimate_terms.fresh_air_mass_flow_filtered, e2m 177B +0 "
        "Fresh_Air_Flow); cm848_initializeFreshAirMassFlowFilter points its coefficient at "
        "fresh_air_mass_flow_filter_coefficient. (was fuel_blend_rpm_base_filter_state)"),
    0x004009d2: ("fuel_blend_rpm_base_filter_coefficient", "fresh_air_mass_flow_filter_coefficient", "word",
        "e2m 1A0F +0 C_CHP_Fresh_Air_Flow_Fil_Cnst 'Filter constant for estimating fresh air flow' (the weight of the "
        f"previous value in 1/65536): the coefficient of fresh_air_mass_flow_filter_state. {NO_CAL} "
        "(was fuel_blend_rpm_base_filter_coefficient)"),
    0x003fa5ba: ("egr_oxygen_fraction_filter", "egr_oxygen_fraction_filter_state", "ema_filter_state_t", None),
}

TABLE_ROWS = [  # address, old, new, type, e2m record, description, role
    (0x004002f2, "boost_fuel_trim_pressure_axis_cal", "upstream_egr_corrected_flow_x_axis", "word[19]",
     "18E3 +0 C_CHP_EGR_Corr_Flow_Lift_Axis [%open]", "EGR Valve Position for CHP_EGR_Flow_Before_Delay calc",
     "the egr_valve_position axis of the upstream corrected flow grid (cm848_calculateUpstreamEgrMassFlow)"),
    (0x00400318, "boost_fuel_trim_ystart_cal", "upstream_egr_corrected_flow_y_axis", "word[19]",
     "18E4 +0 C_CHP_EGR_Corr_Flow_Pratio_Axis", "EGR pressure ratio for CHP_EGR_Flow_Before_Delay calc",
     "the charge_flow_estimate_terms.pressure_ratio axis of the upstream corrected flow grid"),
    (0x0040033e, "boost_fuel_trim_yend_cal", "upstream_egr_corrected_flow_grid", "word[324]",
     "18E5 +0 C_CHP_EGR_Corr_Flow_Table", "table output for EGR flow 3D Table",
     "the 18 x 18 grid behind egr_flow_estimate_terms.upstream_egr_corrected_flow"),
    (0x00400612, "throttle_rpm_axis_cal", "downstream_egr_corrected_flow_x_axis", "word[19]",
     "193D +0 C_CHP_Downstream_Lift_Axis [%open]", "EGR Valve Position axis for CHP_Downstream_Corrected_Flow calculation",
     "the filtered egr_valve_position axis of the downstream corrected flow grid (cm848_calculateDownstreamEgrMassFlow)"),
    (0x00400638, "throttle_rpm_ystart_cal", "downstream_egr_corrected_flow_y_axis", "word[19]",
     "193E +0 C_CHP_Downstream_Pratio_Axis", "EGR dP/P pressure ratio axis for CHP_Downstream_Corrected_Flow calculation",
     "the egr_flow_estimate_terms.downstream_egr_pressure_ratio axis of the downstream corrected flow grid"),
    (0x0040065e, "throttle_rpm_yend_cal", "downstream_egr_corrected_flow_grid", "word[324]",
     "193F +0 C_CHP_Downstream_Flow_Table", "Output axis for CHP_Downstream_Corrected_Flow 3D Table",
     "the 18 x 18 grid behind egr_flow_estimate_terms.downstream_egr_corrected_flow"),
    (0x004005c6, "boost_fuel_input_axis_cal", "exhaust_temperature_rankine_square_root_axis", "word[19]",
     "1974 +0 C_CHP_EGR_Texhaust_Axis [DEG_F]", "x-axis of Sqrt(Texhaust) Table",
     "the exhaust_temperature axis of egr_flow_estimate_terms.exhaust_temperature_rankine_square_root "
     "(cm848_calculateUpstreamEgrMassFlow)"),
    (0x004005ec, "boost_fuel_input_output_cal", "exhaust_temperature_rankine_square_root_values", "word[19]",
     "1975 +0 C_CHP_EGR_Sqrt_Texhaust_Table [SQRT(DEG_R)]", "Output of SQRT(Texhaust) Table for EGR flow Calculation",
     "the values of egr_flow_estimate_terms.exhaust_temperature_rankine_square_root"),
    (0x004008e6, "throttle_trim_axis_cal", "egr_orifice_temperature_rankine_square_root_axis", "word[19]",
     "1946 +0 C_CHP_EGR_Torifice_Axis [DEG_F]", "X-axis of Sqrt(Torifice) Table for CHP_Downstream_EGR_Flow calculation",
     "the egr_orifice_temperature axis of egr_flow_estimate_terms.egr_orifice_temperature_rankine_square_root "
     "(cm848_calculateDownstreamEgrMassFlow)"),
    (0x0040090c, "throttle_trim_output_cal", "egr_orifice_temperature_rankine_square_root_values", "word[19]",
     "1940 +0 C_CHP_EGR_Sqrt_Torifice_Table [SQRT(DEG_R)]",
     "Output axis of SQRT(Torifice) Table for CHP_Downstream_EGR_Flow calculation",
     "the values of egr_flow_estimate_terms.egr_orifice_temperature_rankine_square_root"),
    (0x0040094a, "boost_rpm_scale_axis_cal", "volumetric_efficiency_mach_axis", "word[17]",
     "1782 +0 C_CHP_Veff_Piston_Speed_Axis [IN*RPM]", "Volumetric efficiency mach table piston speed axis",
     "the engine speed x engine_stroke_inches >> 16 axis of charge_flow_estimate_terms.volumetric_efficiency_mach "
     "(cm848_calculateVolumetricEfficiency)"),
    (0x0040096c, "boost_rpm_scale_output_cal", "volumetric_efficiency_mach_values", "word[17]",
     "1783 +0 C_CHP_Veff_Mach_Table", "Volumetric efficiency table based on engine speed and stroke",
     "the values of charge_flow_estimate_terms.volumetric_efficiency_mach"),
    (0x0040098e, "boost_load_axis_cal", "volumetric_efficiency_square_root_axis", "word[17]",
     "1961 +0 C_CHP_Veff_Tmptr_Axis [DEG_R]", "Volumetric efficiency sqrt tabel temperature axis in rankine degree",
     "the charge_flow_estimate_terms.intake_manifold_temperature_rankine axis of "
     "charge_flow_estimate_terms.volumetric_efficiency_square_root (cm848_calculateVolumetricEfficiency)"),
    (0x004009b0, "boost_load_output_cal", "volumetric_efficiency_square_root_values", "word[17]",
     "1962 +0 C_CHP_Veff_Sqrt_Table", "Volumetric efficiency table based only on energy",
     "the values of charge_flow_estimate_terms.volumetric_efficiency_square_root"),
    (0x00404eac, "fuel_demand_blend_yend_cal", "nominal_engine_delta_pressure_grid", "word[304]",
     "1954 +0 C_CHP_Nominal_Delta_P_Table [IN_HG]", "Stored nominal engine delta-P table, output axis",
     "the engine speed x total_injection_quantity_for_air_handling grid (on the combustion map 1 axes) behind "
     "nominal_engine_delta_pressure (cm848_calculatePumpingTorqueAdjustment; flags 4 = signed values)"),
]
for a, old, new, typ, rec, desc, role in TABLE_ROWS:
    GLOBALS[a] = (old, new, typ, f"e2m {rec} '{desc}' ({typ}): {role}. {NO_CAL} (was {old})")

CACHE_ROWS = [  # address, old label, new, type, table, function
    (0x003fa5d2, "diag_state_group6_a_state", "exhaust_temperature_rankine_square_root_cached_axis_offset", "word",
     "exhaust_temperature_rankine_square_root_axis", "cm848_calculateUpstreamEgrMassFlow"),
    (0x003fa5d4, "diag_state_group6_b_state", "egr_orifice_temperature_rankine_square_root_cached_axis_offset", "word",
     "egr_orifice_temperature_rankine_square_root_axis", "cm848_calculateDownstreamEgrMassFlow"),
    (0x003fa5de, "WORD_003fa5de", "volumetric_efficiency_mach_cached_axis_offset", "word",
     "volumetric_efficiency_mach_axis", "cm848_calculateVolumetricEfficiency"),
    (0x003fa5e0, "WORD_003fa5e0", "volumetric_efficiency_square_root_cached_axis_offset", "word",
     "volumetric_efficiency_square_root_axis", "cm848_calculateVolumetricEfficiency"),
]
for a, old, new, typ, table, fn in CACHE_ROWS:
    preset = " cm848_initializeEgrFlowEstimate presets it to 2." if old.startswith("diag_") else ""
    GLOBALS[a] = (old, new, typ, f"Lookup cache: the last axis segment offset (2 x index) that lookupTableInterpolation "
                                 f"keeps for {table} ({fn}).{preset} (was {old})")

PUMP = [  # address, old, new, record, description, role
    (0x00404ea0, "fuel_demand_blend_upper_cal", "pumping_torque_maximum", "1780 +0 C_CHP_Pumping_Torque_Max [FT*LB]",
     "Max limit on pumping torque estimate", "the ceiling of pumping_torque_adjustment (lha)"),
    (0x00404ea2, "fuel_demand_min_limit_cal", "pumping_torque_minimum", "1780 +2 C_CHP_Pumping_Torque_Min [FT*LB]",
     "Min limit on pumping torque estimate", "the floor of pumping_torque_adjustment (lha)"),
    (0x00404ea4, "fuel_demand_percent_scale_cal", "pumping_torque_multiplier", "1780 +4 C_CHP_Pump_Torque_Multiplier",
     "Multiplier used to adjust pumping torque", "the percent the delta-pressure torque is multiplied by (lha)"),
    (0x00404ea6, "fuel_demand_blend_offset_cal", "pumping_torque_offset", "1780 +6 C_CHP_Pump_Torque_Offset",
     "Offset used to adjust pumping torque", "added to pumping_torque_without_offset (lha)"),
    (0x00404ea8, "fuel_demand_deadband_cal", "pumping_torque_engine_delta_pressure_deadband",
     "1780 +8 C_CHP_Pump_Torque_Deadband [IN_HG]",
     "Engine delta-P deadband for smoothing pumping torque adjustment at low values",
     "the deadband taken off nominal_engine_delta_pressure - egr_delta_pressure_negated (lha)"),
    (0x00404eaa, "fuel_demand_load_threshold_cal", "pumping_torque_minimum_fuel", "1780 +A C_CHP_Pump_Torque_Min_Fuel [MM3S]",
     "Compared to FSS_Total_Fueling", "below it (total_injection_quantity_for_air_handling) the pumping torque is 0 (lhz)"),
    (0x0040a418, "fuel_demand_blend_lookup", "nominal_engine_delta_pressure", "1781 +0 CHP_Nominal_Engine_Delta_P [IN_HG]",
     "Nominal engine delta-P at current speed, from table lookup",
     "the nominal_engine_delta_pressure_grid lookup; the actual engine delta pressure egr_delta_pressure_negated is "
     "subtracted from it"),
    (0x0040a41c, "fuel_demand_blend_intermediate", "pumping_torque_without_offset",
     "1781 +4 CHP_Pumping_Torque_No_Offset [FT*LB]", "Pumping Torque without C_CHP_Pump_Torque_Offset",
     "the deadbanded delta pressure x displacement x pumping_torque_multiplier, limited to +-8000"),
]
for a, old, new, rec, desc, role in PUMP:
    region = NO_CAL if a < 0x0040a000 else "Computed RAM."
    sign = "unsigned" if new == "pumping_torque_minimum_fuel" else "signed"
    GLOBALS[a] = (old, new, "word", f"e2m {rec} '{desc}' (e2m {sign}): {role} in "
                                    f"cm848_calculatePumpingTorqueAdjustment. {region} (was {old})")


def rewrite(path, fn):
    lines = open(path).read().split("\n")
    lines = [fn(l) for l in lines]
    open(path, "w").write("\n".join(lines))
    return lines


# names must be new
names_in_csvs = set()
for name in ("global_variables.csv", "function_renames.csv", "arrays.csv", "labels.csv"):
    for row in csv.reader(open(os.path.join(out, name))):
        if len(row) > 1 and row[0].startswith("0x"):
            names_in_csvs.add(row[1])
for _, new, *_ in list(GLOBALS.values()) + [(None, v[1]) for v in FUNCTIONS.values()]:
    assert new not in names_in_csvs, new

seen = set()


def global_row(line):
    p = line.split(",", 3)
    if not p[0].startswith("0x"):
        return line
    a = int(p[0], 16)
    if a not in GLOBALS:
        return line
    old, new, typ, comment = GLOBALS[a]
    seen.add(a)
    if old.startswith(("WORD_", "DAT_")):
        assert p[1] == "", (hex(a), p)
    else:
        assert p[1] == old, (hex(a), p, old)
    if typ:
        assert p[2] == typ, (hex(a), p, typ)
    if comment is None:                                   # keep the comment, change the name only
        return f"{p[0]},{new},{p[2]},{p[3] if len(p) > 3 else ''}"
    return f"{p[0]},{new},{p[2]},{comment}"


path = os.path.join(out, "global_variables.csv")
lines = rewrite(path, global_row)
missing = [a for a in GLOBALS if a not in seen]
assert missing == [0x003fd8ea], [hex(a) for a in missing]     # the one new row
old, new, typ, comment = GLOBALS[0x003fd8ea]
row = f"0x003fd8ea,{new},word,{comment}"
for i, l in enumerate(lines):
    if l.startswith("0x") and int(l.split(",", 1)[0], 16) > 0x3fd8ea:
        lines.insert(i, row)
        break
open(path, "w").write("\n".join(lines))


def function_row(line):
    p = line.split(",", 2)
    if not p[0].startswith("0x") or int(p[0], 16) not in FUNCTIONS:
        return line
    old, new, plate = FUNCTIONS[int(p[0], 16)]
    assert p[1] == old, p
    return f"{p[0]},{new},{plate}"


rewrite(os.path.join(out, "function_renames.csv"), function_row)

with open(os.path.join(scratch, "map_stage3.csv"), "w", newline="") as f:
    w = csv.writer(f)
    w.writerow(["address", "name", "old_label", "kind"])
    for a, (old, new, _) in FUNCTIONS.items():
        w.writerow([f"0x{a:08x}", new, old, "function"])
    for a, (old, new, _, _) in GLOBALS.items():
        w.writerow([f"0x{a:08x}", new, old, "global"])
with open(os.path.join(scratch, "map_refresh_stage3.csv"), "w", newline="") as f:
    w = csv.writer(f)
    w.writerow(["address", "name", "old_label", "kind"])
    for a, (old, new, _) in FUNCTIONS.items():
        w.writerow([f"0x{a:08x}", new, old, "function"])
    for a, (old, new, _, _) in GLOBALS.items():
        if not old.startswith(("WORD_", "DAT_")):
            w.writerow([f"0x{a:08x}", new, old, "global"])
print(f"functions {len(FUNCTIONS)}, globals {len(GLOBALS)} (1 new row)")

"""Blocks 125E, 125F, 12EA, 1735, 175F, 191B (bin records 14-21)."""
ENTRIES = []

ENTRIES.append({
    "kind": "global", "verdict": "confirmed", "address": "0x003fd802",
    "old": "protection_fuel_limit_c_working", "new": "torque_derate_override_fuel_quantity_cal",
    "evidence": "e2m 125E +0 Torque_Derate_Override 'Engineering torque derate fueling override': "
                "cm848_arbitrateRequestedFueling loads it into torque_derate_fuel_quantity with source code "
                "FUELING_STATE_TORQUE_DERATE_OVERRIDE (e2m label TRQDROVR) while governor_feature_flags bit 0x10 is set, replacing "
                "the whole derate chain; EEPROM 0x380 so _cal; the old name said protection fuel limit working",
    "code_quote": "cm848_arbitrateRequestedFueling: torque_derate_fuel_quantity = protection_fuel_limit_c_working;",
    "comment": "e2m 125E +0 Torque_Derate_Override '[FSTQDQUO] Engineering torque derate fueling override' (address from the ECU's "
               "parameter ID table: EEPROM 0x380) (MM3S, 0.0679 mm3 per count; 5888 = 400 mm3, the maximum, in the dump): while "
               "bit 0x10 of governor_feature_flags is set (the dump has 0x1020, so it is off) cm848_arbitrateRequestedFueling "
               "replaces the whole derate chain with it: torque_derate_fuel_quantity = this word and "
               "torque_derate_fuel_source_code = FUELING_STATE_TORQUE_DERATE_OVERRIDE (e2m label TRQDROVR). EEPROM mirror, so "
               "_cal.",
})

ENTRIES.append({
    "kind": "global", "verdict": "confirmed", "address": "0x003fd804",
    "old": "fuel_timing_target_working", "new": "user_override_fueling_cal",
    "evidence": "e2m 125E +2 User_Override_Fueling 'Engineering fueling override': cm848_selectFinalFueling takes it as "
                "total_fueling_selected with final_fueling_state FUELING_STATE_FUEL_OVERRIDE (e2m label OVERRIDE) while "
                "governor_feature_flags bit 0x2 (mask 2) is set, before the fuel_demand_minimum / maximum clamp; EEPROM 0x382 so "
                "_cal; the old name said fuel timing target working",
    "code_quote": "cm848_selectFinalFueling: total_fueling_selected = fuel_timing_target_working;",
    "comment": "e2m 125E +2 User_Override_Fueling '[FSUOFL] Engineering fueling override' (address from the ECU's parameter ID "
               "table: EEPROM 0x382) (MM3S, 0.0679 mm3 per count; 0 in the dump): the engineering fuel override. While bit 0x2 "
               "(mask 2) of governor_feature_flags is set (off in the dump) and the engine is running (not stopped, shut down or overspeeding, "
               "no immobilizer fuel disable) cm848_selectFinalFueling takes it as the fueling request total_fueling_selected, with "
               "final_fueling_state = FUELING_STATE_FUEL_OVERRIDE (e2m label OVERRIDE), and clamps it between "
               "fuel_demand_minimum and fuel_demand_maximum. EEPROM mirror, so _cal.",
})

ENTRIES.append({
    "kind": "global", "verdict": "confirmed", "address": "0x003fd8b4",
    "old": "governor_proportional_gain_cal", "new": "user_commanded_fueling_cal",
    "evidence": "e2m 125F +0 User_Commanded_Fueling 'User commanded fuel value for development': cm848_setEngineOperatingMode5 "
                "makes it the governor fuel demand (engine_operating_mode_fuel_demand) with "
                "FUELING_STATE_CALIBRATED_FIXED_FUEL_DEMAND (e2m label USERCOMD) when bit 0x1 of engine_mode_control_flags is set; "
                "EEPROM 0x432; the old name said governor proportional gain",
    "code_quote": "cm848_setEngineOperatingMode5: engine_operating_mode_fuel_demand = governor_proportional_gain_cal;",
    "comment": "e2m 125F +0 User_Commanded_Fueling '[FSUCFL] User commanded fuel value for development' (address from the ECU's "
               "parameter ID table: EEPROM 0x432) (MM3S, 0.0679 mm3 per count; 0 in the dump): a calibration-set fuel quantity "
               "for development. cm848_setEngineOperatingMode5 loads it into engine_operating_mode_fuel_demand and sets "
               "engine_operating_mode to FUELING_STATE_CALIBRATED_FIXED_FUEL_DEMAND (e2m label USERCOMD) when no mode is selected "
               "and bit 0x1 of engine_mode_control_flags is set (0 in every dump). EEPROM mirror, so _cal.",
})

ENTRIES.append({
    "kind": "global", "verdict": "keep", "address": "0x003fd810",
    "old": "engine_speed_limit_droop_cap_alternate_cal", "new": "engine_speed_limit_droop_cap_alternate_cal",
    "e2m_note": "e2m 12EA +6 HSG_Isochronous_Speed_2 'Alternate HSG isochronous speed' (the high speed governor's isochronous "
                "speed is the engine speed limit droop cap: +4 HSG_Isochronous_Speed is engine_speed_limit_droop_cap_cal, 30000 = "
                "3750 rpm in the dump; this one is the cap while the switch input selects the alternate)",
})

ENTRIES.append({
    "kind": "global", "verdict": "confirmed", "address": "0x004062d2",
    "old": "boost_pressure_ratio_upper_limit", "new": "cylinder_residual_gas_mass_upper_limit",
    "evidence": "e2m 1735 +0 C_CBP_Residual_Mass_Max 'Max limit on residual mass estimation': cm848_calculateResidualGasMass "
                "sets cylinder_residual_gas_mass to it when the unclamped estimate is above it (the lower limit is e2m +2, "
                "cylinder_residual_gas_mass_lower_limit); the function's own plate comment already says _upper_limit; the old "
                "name said boost pressure ratio",
    "code_quote": "cm848_calculateResidualGasMass: cylinder_residual_gas_mass = boost_pressure_ratio_upper_limit;",
    "comment": "e2m 1735 +0 C_CBP_Residual_Mass_Max 'Max limit on residual mass estimation' (address from the ECU's parameter ID "
               "table) (MM3S, 0.1359 mm3 per count; 1104 = 150 mm3 in the dump): the ceiling of the in-cylinder residual gas mass. "
               "cm848_calculateResidualGasMass divides cylinder_residual_gas_mass_density_constant x exhaust_pressure by the "
               "exhaust temperature term into cylinder_residual_gas_mass_unclamped and clamps it between "
               "cylinder_residual_gas_mass_lower_limit (e2m +2) and this word into cylinder_residual_gas_mass; "
               "cm848_calculateCylinderOxygenMasses multiplies that by the residual oxygen fraction. ROM copy (RAM 0x4062d2), "
               "not EEPROM: no _cal.",
})

ENTRIES.append({
    "kind": "global", "verdict": "confirmed", "address": "0x0040a60e",
    "old": "boost_pressure_normalized", "new": "compressor_map_corrected_air_flow",
    "evidence": "e2m 175F +0 TPE_Corrected_Air_Flow 'Air flow input to compressor map in corporate units': "
                "cm848_estimateCompressorOutletTemperature stores the fresh air mass flow x compressor_inlet_temperature_square_root "
                "/ compressor_inlet_pressure (the corrected flow) in it and passes it as the flow axis of the compressor map "
                "lookup; the old name said boost pressure normalized",
    "code_quote": "cm848_estimateCompressorOutletTemperature: boost_pressure_normalized = (word)uVar2;",
    "comment": "e2m 175F +0 TPE_Corrected_Air_Flow 'Air flow input to compressor map in corporate units' (address from the ECU's "
               "parameter ID table) (KG*SQR(K)/S/MPa, 0.03125 per count; 0 in the dump, engine off): the corrected fresh air mass "
               "flow, the flow axis of the compressor map. cm848_estimateCompressorOutletTemperature stores "
               "charge_flow_estimate_terms.fresh_air_mass_flow_filtered x compressor_inlet_temperature_square_root / 40000 x 0x2ad5 "
               "/ compressor_inlet_pressure here (capped at 0xffff) and passes it with compressor_map_corrected_turbocharger_speed "
               "(e2m +2) to the dual axis lookup whose output is compressor_outlet_temperature_to_inlet_temperature_ratio (e2m "
               "+4). Working RAM, never _cal.",
})

ENTRIES.append({
    "kind": "global", "verdict": "confirmed", "address": "0x0040a612",
    "old": "fuel_timing_boost_scale_lookup", "new": "compressor_outlet_temperature_to_inlet_temperature_ratio",
    "evidence": "e2m 175F +4 TPE_COT_To_Inlet_Tmptr_Ratio 'Compressor map output in corporate units': it is the dual axis "
                "compressor map result (corrected air flow x corrected turbocharger speed) that "
                "cm848_estimateCompressorOutletTemperature multiplies by the inlet temperature in Rankine "
                "(ambient_air_temperature_selected + 0x7300) to get the outlet temperature; the old name said fuel timing boost "
                "scale lookup",
    "code_quote": "cm848_estimateCompressorOutletTemperature: uVar2 = (uint)fuel_timing_boost_scale_lookup *",
    "comment": "e2m 175F +4 TPE_COT_To_Inlet_Tmptr_Ratio 'Compressor map output in corporate units' (address from the ECU's "
               "parameter ID table) (UNITLESS, 1/2048 per count; 2117 = 1.034 in the dump): the ratio of the compressor outlet "
               "temperature to the inlet temperature, read from the compressor map. cm848_estimateCompressorOutletTemperature "
               "looks it up with cm848_dualAxisTableInterpolation on compressor_map_corrected_air_flow (e2m +0) and "
               "compressor_map_corrected_turbocharger_speed (e2m +2) (tables fuel_timing_boost_scale_axis1_cal / _ystart_cal / "
               "_yend_cal), multiplies it by the compressor inlet temperature in Rankine (ambient_air_temperature_selected + "
               "0x7300), converts the product back to degrees F (floored at 0) and filters it into compressor_outlet_temperature. "
               "Working RAM, never _cal.",
})

ENTRIES.append({
    "kind": "global", "verdict": "confirmed", "address": "0x0040bab4",
    "old": "fuel_flow_rate_snapshot", "new": "compressor_outlet_temperature_virtual_sensor_copy",
    "evidence": "e2m 191B +C Compressor_Outlet_Temperature 'Compressor_Outlet_Temperature virtual sensor value': "
                "cm848_selectCompressorOutletTemperature ends by copying compressor_outlet_temperature into it every pass; "
                "one store and no read (xref_addr.py), in the e2m 191B virtual sensor block next to "
                "exhaust_temperature_virtual_sensor_copy and egr_valve_position_virtual_sensor_copy; the old name said fuel flow "
                "rate snapshot",
    "code_quote": "cm848_selectCompressorOutletTemperature: fuel_flow_rate_snapshot = compressor_outlet_temperature;",
    "comment": "e2m 191B +C Compressor_Outlet_Temperature 'Compressor_Outlet_Temperature virtual sensor value' (address from the "
               "ECU's parameter ID table) (DEG_F, 0.03125 per count; 1662 = 51.9 F in the dump): the virtual sensor copy of "
               "compressor_outlet_temperature (e2m 175F +8), the compressor outlet temperature estimate or its calibrated "
               "default. cm848_selectCompressorOutletTemperature stores it at the end of every pass; xref_addr.py finds this one "
               "store and no read (it sits in the e2m 191B virtual sensor block with exhaust_temperature_virtual_sensor_copy and "
               "egr_valve_position_virtual_sensor_copy). Working RAM, never _cal.",
})

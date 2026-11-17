ROWS = []

E2M_BLOCK = ("E2M (relative offset): the words 0x40a5b6-0x40a5ea sit at the same offsets as the EMO condensation block 0x01196F00-0x01196F34 "
             "(0x40a5b6 = Condensation_AECD_Active, 0x40a5be = Cooler_Cond_Count, 0x40a5c8 = Intake_Cond_Count, 0x40a5ea = Intake_Cndst_Mass_Rate; "
             "every offset checked), and the cooler half is already named from it.")


def g(addr, old, new, evidence, new_type=None):
    r = {"kind": "global", "address": addr, "old": old, "verdict": "confirmed", "new": new, "evidence": evidence}
    if new_type:
        r["new_type"] = new_type
    ROWS.append(r)


def ng(addr, new, typ, evidence):
    ROWS.append({"kind": "new_global", "address": addr, "new": new, "type": typ, "evidence": evidence})


# ---- the dew point model that produces the two targets: cm848_blendBoostAndThrottleFuelDemand (0x50e7f4)
g("0x0040a72c", "fuel_boost_compensation_target", "exhaust_saturation_temperature",
  "CODE (producer read in full, cm848_blendBoostAndThrottleFuelDemand 0x50e7f4): fuel_boost_map_correction_weighted (the water vapor partial "
  "pressure of the exhaust gas x 4) is looked up in fuel_demand_compensation_target_by_pressure (10 breakpoints, pressure -> temperature) = the dew "
  "point of the exhaust. Consumer cm848_updateEgrCoolerCondensationCount: temperature difference = (coolant temperature - margin) - this word; "
  "checked in the dump: (2050 - 640) - 12928 = -11518, the stored difference is -11513. E2M: Exhaust_Saturation_Tmptr 'Exhaust temperature below "
  "which moisture condenses' 0x0118AB14 and EMO_Cooler_Cond_Delta_T 'Coolant_Temperature - Exhaust_Saturation_Tmptr - margin'; 0x0118AB14 - "
  "0x0118AB02 = 0x12 = 0x40a72c - 0x40a71a. 1/64 degree F, dump 12928 = 202 F.")
g("0x0040a71a", "fuel_blend_compensation_target", "charge_saturation_temperature",
  "CODE: the same lookup of fuel_blend_map_correction_weighted (the charge water vapor partial pressure x 4) in the same pressure -> temperature "
  "table = the dew point of the intake charge. Consumer fuel_demand_blend_compensate: temperature difference = (predicted intake manifold "
  "temperature - margin) - this word; dump: (2600 - 640) - 2240 = -280 = the stored difference exactly. E2M: Charge_Saturation_Tmptr 'Saturation "
  "temperature of moisture in intake manifold' 0x0118AB02, EMO_Intake_Cond_Delta_T 'CHP_Predicted_IMT - Charge_Saturation_Tmptr - margin'. 1/64 "
  "degree F, dump 2240 = 35 F.")
g("0x0040af70", "fuel_boost_map_correction_weighted", "exhaust_water_vapor_partial_pressure_times_4",
  "CODE: map_fuel_correction_factor x exhaust_water_vapor_fraction >> 8 in cm848_blendBoostAndThrottleFuelDemand; consumers use value >> 2 as the "
  "partial pressure compared with the saturation vapor pressure table (the unit of EMO_Cooler_Satur_PP / Delta_PP, IN_HG 0.001988), and the "
  "dew point lookup uses the x 4 value directly. Dump 37168 = 9292 counts = 18.5 inHg (engine-off dump, so not a running value).")
g("0x0040af6e", "fuel_blend_map_correction_weighted", "charge_water_vapor_partial_pressure_times_4",
  "CODE: map_fuel_correction_factor x charge_water_vapor_fraction >> 8, the intake twin of the word above (partial pressure compared with the "
  "saturation vapor pressure at the predicted intake manifold temperature minus the margin; value >> 2 in fuel_demand_blend_compensate). Dump 284.")
g("0x0040af6a", "fuel_demand_blend_weight_ema", "exhaust_water_vapor_fraction",
  "CODE: (2 x X + W) x 8192 / (X + W + 39075) with X = fuel_air_equivalence_ratio x 0.31 and W = the ambient air water vapor term x 4.77 (39075 / "
  "8192 = the 4.76 moles of air per mole of oxygen): the water vapor fraction of the exhaust gas (Q13) from combustion plus ambient humidity, "
  "with no EGR dilution. Used only by cm848_calculateEgrCoolerCondensationMassRate: condensation mass rate = (this - the saturation ratio at the "
  "coolant temperature) x egr_mass_flow_delayed_filtered / 2724. MEDIUM confidence on 'fraction' (mole fraction vs mixing ratio): the dump value "
  "5617 (0.69) is an engine-off value.")
g("0x0040af68", "fuel_demand_blend_weight_ema_filtered", "charge_water_vapor_fraction",
  "CODE: the same formula with X scaled by max(EGR fraction at base chi, actual EGR fraction): the water vapor fraction of the intake charge "
  "(Q13). Used by fuel_demand_boost_emaFiltered_compensate (the intake condensation mass rate) and by the charge dew point lookup. Dump 43. Same "
  "MEDIUM confidence note on 'fraction'.")
g("0x0040a416", "fuel_demand_blend_filtered", "predicted_intake_manifold_temperature",
  "CODE: cm848_fuelDemandBlendCalculation (0x12f60) = the filtered measured intake manifold temperature while egr_valve_closed_flag is set, "
  "otherwise intake manifold temperature x (1 - EGR fraction) + EGR fraction x (a blend of coolant temperature, ambient air temperature and "
  "boost_fuel_input_value with the weights boost_fuel_blend_weight_a_cal / _b_cal), first order filtered; initial value = the measured "
  "temperature (mpc555_initManifoldPressureFilter). The intake condensation model subtracts the margin and charge_saturation_temperature from it. "
  "E2M: CHP_Predicted_IMT 'Predicted IMT with EGR' (0x01194500, DEG_F 1/64) with C_CHP_Predicted_IMT_Fil_Cnst. Dump 2600 = 40.6 F.")

# ---- the shared margin and the gain scales
g("0x00406566", "fuel_demand_compensation_base_setpoint", "condensation_protection_temperature_margin",
  "CODE: the only two readers are the EGR cooler and the intake condensation models and both subtract the same word from their temperature before "
  "the saturation lookup and the temperature difference, so it is the shared margin, not a per-model one (RESOLVES the wave 8 doubt). E2M by "
  "offset from C_EMO_Cooler_Cond_Max_Count: 0x406552 = 0x01196E04 and 0x406566 = 0x01196E18 = C_EMO_Condensation_AECD_Margin 'Temperature margin "
  "for condensation protection AECD from saturation line' (DEG_F 1/64); the per-model margins C_EMO_Cooler_Cond_Margin / C_EMO_Intake_Cond_Margin "
  "(0x01196E02 / 0E = ROM 0x406550 / 0x40655a) have no reader at all. ROM word, dump 640 = 10 F.")
g("0x00406556", "fuel_boost_comp_negative_step_scale", "egr_cooler_condensation_off_gain",
  "CODE: fuel_coldStart_quantityScale_update multiplies it by charge_mass_flow_filtered and >> 7 into egr_cooler_condensation_adjusted_off_gain. E2M: "
  "C_EMO_Cooler_Cond_Off_Gain 0x01196E08 (UNITLESS 1/128 = the Q7 scale) at the same offset from C_EMO_Cooler_Cond_Max_Count as 0x406556 from 0x406552. ROM word.")
g("0x00406558", "fuel_boost_comp_positive_step_scale", "egr_cooler_condensation_on_gain",
  "CODE: the same into egr_cooler_condensation_adjusted_on_gain. E2M: C_EMO_Cooler_Cond_On_Gain 0x01196E0A. ROM word.")
g("0x00406560", "fuel_blend_comp_negative_step_scale", "intake_condensation_off_gain",
  "CODE: the same into the intake off gain (fuel_demand_blend_compensation_step_rate_negative). E2M: C_EMO_Intake_Cond_Off_Gain 0x01196E12 (0x406560 - 0x406552 = 0xE = 0x01196E12 - 0x01196E04). ROM word.")
g("0x00406562", "fuel_blend_comp_positive_step_scale", "intake_condensation_on_gain",
  "CODE: the same into the intake on gain. E2M: C_EMO_Intake_Cond_On_Gain 0x01196E14. ROM word.")

# ---- the intake twin of the (already renamed) EGR cooler condensation model
twins = [
    ("0x0040a5c8", "fuel_blend_compensation_integrator", "intake_condensation_count", "dword",
     "cumulative intake condensation, e2m EMO_Intake_Cond_Count (CNTS dword); twin of egr_cooler_condensation_count; dump 0"),
    ("0x0040a5e0", "fuel_blend_compensation_step", "intake_condensation_increment", "dword",
     "per-pass increment, e2m EMO_Intake_Cond_Incrt; twin of egr_cooler_condensation_increment (the on / off gain x the difference / 640)"),
    ("0x0040655c", "fuel_blend_compensation_limit", "intake_condensation_count_maximum", "dword",
     "ROM limit of the count, e2m C_EMO_Intake_Cond_Max_Count 0x01196E0E (4 bytes); twin of egr_cooler_condensation_count_maximum; dump 985766"),
    ("0x0040a5c4", "fuel_demand_blend_compensation_at_limit_flag", "intake_condensation_count_at_limit_flag", "word",
     "1 when the count reaches its maximum, cleared at 0; e2m EMO_Intake_Cond_AECD_Active ('Condensation AECD for Intake is currently permitting "
     "higher emmision levels'); twin of egr_cooler_condensation_count_at_limit_flag"),
    ("0x0040a5c6", "fuel_blend_compensation_direction_flag", "intake_condensation_increasing_flag", "word",
     "1 while the partial pressure difference is positive (condensation predicted); e2m EMO_Intake_Cond_AECD_Possible; twin of egr_cooler_condensation_increasing_flag"),
    ("0x0040a5d4", "fuel_demand_blend_compensation_step_rate_negative", "intake_condensation_adjusted_off_gain", "word",
     "base gain x filtered charge mass flow >> 7 (fuel_coldStart_quantityScale_update), the step rate in the negative branch; e2m EMO_Intake_Cond_Adj_Off_Gain"),
    ("0x0040a5d6", "fuel_demand_blend_compensation_step_rate_positive", "intake_condensation_adjusted_on_gain", "word",
     "the same for the positive branch; e2m EMO_Intake_Cond_Adj_On_Gain"),
    ("0x0040a5e6", "blend_demand_ema_filtered_decay_coeff", "intake_saturation_vapor_pressure", "word",
     "water saturation vapor pressure at the filtered intake manifold temperature (lookupTableInterpolation of water_saturation_vapor_pressure_by_temperature, "
     "stored in fuel_demand_boost_emaFiltered_compensate); e2m EMO_Intake_Satur_PP; twin of egr_cooler_saturation_vapor_pressure (96 counts at 32 F = 0.19 inHg; this one 128)"),
]
for addr, old, new, typ, text in twins:
    g(addr, old, new, "CODE (mirror of the accepted cooler names; the two functions are line for line twins): " + text + ". " + E2M_BLOCK)

ng("0x0040a5da", "intake_condensation_temperature_difference", "i16",
   "CODE: store-only (sth 0x504b44, 0 reads; xref width word) in fuel_demand_blend_compensate: predicted_intake_manifold_temperature - "
   "condensation_protection_temperature_margin - charge_saturation_temperature (1/64 F), dump -280 reproduces it exactly. Typed i16 like its twin "
   "egr_cooler_condensation_temperature_difference (the value is signed, no load proves it). E2M: EMO_Intake_Cond_Delta_T 0x01196F24.")
ng("0x0040a5cc", "intake_condensation_partial_pressure_difference", "i16",
   "CODE: store-only (sth 0x504b84, xref width word) in fuel_demand_blend_compensate: (charge_water_vapor_partial_pressure_times_4 >> 2) - the "
   "saturation vapor pressure at (predicted intake manifold temperature - margin); sets the step direction. i16 like its twin "
   "egr_cooler_condensation_partial_pressure_difference. E2M: EMO_Intake_Cond_Delta_PP 0x01196F16.")
ng("0x0040a5ea", "intake_condensation_mass_rate", "i16",
   "CODE: store-only (sth 0x504aac, xref width word) in fuel_demand_boost_emaFiltered_compensate: (charge_water_vapor_fraction - the saturation "
   "ratio) x charge_mass_flow_filtered / 2724, 0 when negative, capped 0xfffe. i16 like its twin egr_cooler_condensation_mass_rate. E2M: "
   "EMO_Intake_Cndst_Mass_Rate 0x01196F34.")
ng("0x0040654e", "condensation_protection_emission_level_cap_when_active", "word",
   "CODE: read once (lhz 0x505230, xref width word, never written, ROM word) by fuel_coldStart_quantityScale_update, which stores it in "
   "condensation_protection_emission_level_cap while either condensation count is at its limit. E2M: C_EMO_Condensation_AECD_Cap 0x01196E00 'NOx cap "
   "value to be used when condensation triggers EGR off' (1/1024) = 0x406552 - 4; dump 1024 = 1.0. ROM address, so no _cal.")

g("0x0040a5b6", "fuel_coldStart_compensation_at_limit_flag", "condensation_protection_active_flag",
  "CODE: fuel_coldStart_quantityScale_update sets 1 when the intake OR the EGR cooler condensation count is at its limit, else 0; readers: "
  "fuel_modeStatusBits_pack (bit 2 of the packed state DAT_0040a5ec) and fuel_modeStatusFlags_update (mask 0x80 of combustion_status_flags, an EGR-off "
  "request). E2M: EMO_Condensation_AECD_Active 'Condensation Protection AECD is currently permitting higher emissions levels' 0x01196F00 = the "
  "first word of the block. Dump 0.")
g("0x0040a5b8", "fuel_coldStart_compensation_demand_floor", "condensation_protection_emission_level_cap",
  "CODE: = condensation_protection_emission_level_cap_when_active (0x40654e) while condensation_protection_active_flag is 1, else 0; its only reader "
  "fuel_demandMin_maxSelect_rateLimit takes the maximum of this and the other protection floors (cold start phase 2.6 / 3, boost override, sensor "
  "validation, cylinder check, blend) and rate limits it into fuel_demand_min_threshold, which cm848_lookupProtectiveChi uses as the level floor of "
  "the chi: these 'demand floors' are emission level caps, not fuel demand. E2M: EMO_Condensation_Cap_EL 0x01196F02 (UNITLESS 1/1024, 'NOx cap "
  "value to be used when condensation triggers EGR off'). Dump 0.")

# ---- functions
ROWS.append({
    "kind": "function", "address": "0x00504b0c", "old": "fuel_demand_blend_compensate", "verdict": "confirmed",
    "new": "cm848_updateIntakeCondensationCount",
    "plate_comment": (
        "Integrates the cumulative intake condensation count (e2m EMO_Intake_Cond_Count): the temperature difference "
        "(predicted_intake_manifold_temperature minus condensation_protection_temperature_margin minus charge_saturation_temperature, stored in 0x40a5da) "
        "and the partial pressure difference (charge_water_vapor_partial_pressure_times_4 / 4 minus the saturation vapor pressure at the predicted "
        "temperature minus the margin, stored in 0x40a5cc) set the step direction; the step is the intake on / off gain times the difference / 640; the "
        "count follows the step only while fuel_cold_start_phase3_compensation_enable_flag is set (and, going up, while the EGR fraction is at or above "
        "its threshold), is limited to intake_condensation_count_maximum and raises the at-limit flag there. Calls "
        "cm848_calculateIntakeCondensationMassRate. The twin of cm848_updateEgrCoolerCondensationCount (was fuel_demand_blend_compensate)."),
    "evidence": ("CODE: line for line the intake twin of cm848_updateEgrCoolerCondensationCount (same table, same x / 640 step, same limit logic, calls the "
                 "mass rate function at the end); the dump reproduces its temperature difference exactly. E2M: EMO_Intake_Cond_* block."),
})
ROWS.append({
    "kind": "function", "address": "0x00504994", "old": "fuel_demand_boost_emaFiltered_compensate", "verdict": "confirmed",
    "new": "cm848_calculateIntakeCondensationMassRate",
    "plate_comment": (
        "Looks up the water saturation vapor pressure at the filtered intake manifold temperature (intake_saturation_vapor_pressure), forms the intake "
        "condensation rate as (charge_water_vapor_fraction minus the saturation ratio, map_fuel_correction_factor x 8 over that pressure, scaled) times "
        "charge_mass_flow_filtered (stored in 0x40a5ea) and, in cold start phase 3 with the EGR valve not closed, adds a fifth of it to the dword at "
        "0x3fddb2. Called by cm848_updateIntakeCondensationCount. The twin of cm848_calculateEgrCoolerCondensationMassRate (was "
        "fuel_demand_boost_emaFiltered_compensate)."),
    "evidence": "CODE: line for line the twin of cm848_calculateEgrCoolerCondensationMassRate with the intake temperature and the charge mass flow; E2M EMO_Intake_Cndst_Mass_Rate.",
})
ROWS.append({
    "kind": "function", "address": "0x00012f60", "old": "cm848_fuelDemandBlendCalculation", "verdict": "confirmed",
    "new": "cm848_calculatePredictedIntakeManifoldTemperature",
    "plate_comment": (
        "Calculates predicted_intake_manifold_temperature: the filtered measured intake manifold temperature while egr_valve_closed_flag is set, "
        "otherwise intake manifold temperature x (1 - EGR fraction at base chi) + the EGR fraction x a blend of coolant temperature "
        "(boost_fuel_blend_weight_a_cal), ambient air temperature (boost_fuel_blend_weight_b_cal) and boost_fuel_input_value, passed through a first "
        "order filter (e2m CHP_Predicted_IMT 'Predicted IMT with EGR'). Read by the intake condensation model (was cm848_fuelDemandBlendCalculation)."),
    "evidence": "CODE read in full (0x12f60-0x130ac) and e2m CHP_Predicted_IMT / C_CHP_Predicted_IMT_Fil_Cnst; consumer = the intake condensation count only.",
})
ROWS.append({
    "kind": "function", "address": "0x005050f4", "old": "fuel_coldStart_quantityScale_update", "verdict": "confirmed",
    "new": "cm848_updateCondensationProtection",
    "plate_comment": (
        "Condensation protection driver (e2m EMO condensation AECD): fuel_cold_start_phase3_compensation_enable_flag = feature_enable_flags_cal bit "
        "0x200 and cold start phase 3; scales the four condensation on / off gains (EGR cooler and intake) by charge_mass_flow_filtered x scale / 128; "
        "runs cm848_updateIntakeCondensationCount and cm848_updateEgrCoolerCondensationCount; while either count is at its limit sets "
        "condensation_protection_active_flag and condensation_protection_emission_level_cap (the calibrated cap 0x40654e), else clears both "
        "(was fuel_coldStart_quantityScale_update)."),
    "evidence": "CODE read in full (0x5050f4-0x5051c0); e2m EMO_Condensation_AECD_Active / EMO_Condensation_Cap_EL / EMO_Cond_AECD_Timer_Active at the same offsets.",
})

ROWS.append({
    "kind": "note",
    "text": (
        "0x40a61c CONSUMERS (lead 5), what is NOT renamed and why. (a) DAT_003fddae / DAT_003fddb2 (dwords at 0x3fddae / 0x3fddb2, EEPROM mirror "
        "window; 1 read + 1 write each, both the read-modify-write 'x += mass rate / 5 in cold start phase 3 with the EGR valve not closed' of the cooler "
        "and the intake mass rate functions): write-only accumulators of the condensed mass; no reader and no e2m parameter, persistence unproven, so no "
        "name. (b) The per-model margins 0x406550 / 0x40655a (e2m C_EMO_Cooler_Cond_Margin / C_EMO_Intake_Cond_Margin, 640 / -1088 in the dump) have no "
        "reader; the code uses the shared margin. (c) The old fuel_demand_boost_* / fuel_demand_blend_* names were the condensation model, as wave 8 "
        "found for the cooler half; the intake half is the twin above. (d) fuel_demandMin_maxSelect_rateLimit (0x50477c) takes the maximum of the "
        "protection 'floors' and rate limits it into fuel_demand_min_threshold: e2m EMM_Cap_EL_Cmd 'Emission level cap after AECDs'; the floors "
        "fuel_coldStart_phase26_demand_floor, cold_start_phase3_fuel_demand_floor, cold_start_boost_override_fuel_demand, "
        "fuel_demand_sensor_validation_floor, fuel_timing_cylinder_check_demand_floor, fuel_demand_blend_weight, fuel_blend_weight_threshold_active are "
        "the other AECD caps (EMO_Engine_Start_Cap_EL etc.): a follow-up rename family (the function would be cm848_selectEmissionLevelCap, "
        "fuel_demand_min_threshold the emission level cap command); not proposed here because each cap needs its own e2m pairing. (e) "
        "cm848_blendBoostAndThrottleFuelDemand (0x50e7f4) = the exhaust / charge water vapor and dew point model (candidate "
        "cm848_calculateExhaustAndChargeDewPoint); its DAT_0040af76 / af78 / af6c (ambient water vapor pressure at the ambient air temperature capped "
        "at 90 F, x boost_fuel_rpm_blend_scale / 1024, and its ratio to the barometric pressure) are the ambient humidity terms. The wave 7 "
        "'gas temperature estimate' reading is refuted by the code."
    ),
})

# Part A of the wave-9 generator (charge manager tables + turbocharger speed chain). Read-only research output.
import json

ROWS = []

BOOT = ("Time-shared window (0x3F9800-0x3FDB30): xref_addr.py lists no access below 0x7F60 and a scan of the boot ROM 0x0-0x7F5F "
        "(low halfword of the address in a load / store / addi / ori, and aligned 32-bit constants equal to it) finds none.")


def fn(addr, old, new, plate, ev, verdict="confirmed"):
    ROWS.append({"kind": "function", "address": addr, "old": old, "verdict": verdict, "new": new,
                 "plate_comment": plate, "evidence": ev})


def g(addr, old, new, ev, type=None, old_type=None, verdict="confirmed", extra=None):
    r = {"kind": "global", "address": addr, "old": old, "verdict": verdict, "new": new, "evidence": ev}
    if type:
        r["type"] = type
    if old_type:
        r["old_type"] = old_type
    if extra:
        r.update(extra)
    ROWS.append(r)


def ng(addr, new, type, ev):
    ROWS.append({"kind": "new_global", "address": addr, "new": new, "type": type, "evidence": ev})


def unc(addr, old, ev):
    ROWS.append({"kind": "global", "address": addr, "old": old, "verdict": "uncertain", "evidence": ev})


def note(text):
    ROWS.append({"kind": "note", "text": text})


def table(addr, old, new, type, comment, ev):
    ROWS.append({"kind": "global", "address": addr, "old": old, "verdict": "confirmed", "new": new, "type": type,
                 "comment": comment, "arrays_csv": "no arrays.csv row exists for this address (checked)", "evidence": ev})


# ------------------------------------------------------------------------------------------------------------
# (1) CHARGE MANAGER TABLES
# ------------------------------------------------------------------------------------------------------------
E2M_NOTE = "e2m names are corroboration (block relative offsets); the code reads / output scaling are the proof."

# CHL derate tables (three 16-point ratio -> factor tables, one per derate)
table("0x003ff78a", "", "charge_flow_turbocharger_speed_derate_factor_by_ratio_axis", "word[17]",
      "Lookup table - x axis of 16 breakpoints after its byte-length word: ratio of turbocharger_speed to charge_flow_turbocharger_speed_derate_limit in Q15 (0 / 0.5 / 0.7 / 0.8 / 0.9 ... 1.0; e2m C_CHL_Turbo_Drt_Ratio_Axis 0x011AB500, 3.05E-5 per count) - read by cm848_calculateChargeFlowTurbochargerSpeedDerate",
      "Input is the ratio (fuel_demand_quantity << 15) / limit that the function passes as the lookup argument; axis values 0..32768 are Q15 ratios (dump: 0, 16384, 22937, 26214, 29491 ... 32768). Only reader: xref_addr.py 1 function. e2m C_CHL_Turbo_Drt_Ratio_Axis ('ratio input for derate factor') is the same table.")
table("0x003ff7ac", "", "charge_flow_turbocharger_speed_derate_factor_by_ratio_values", "word[17]",
      "Lookup table - data: 16 values (one per axis breakpoint) after a byte-length word: the derate factor in Q14 (signed, 16384 = 1.0; e2m C_CHL_Turbo_Drt_Offset_Table 0x011AB600, 6.1E-5 per count), multiplied by charge_flow_turbocharger_speed_derate_gain >> 14 and capped. All 16 values are -16384 (-1.0) in this calibration - read by cm848_calculateChargeFlowTurbochargerSpeedDerate",
      "Output scaling is the >> 14 the function applies after the multiply by the gain; values read from the ROM image are all 0xC000 = -16384. e2m C_CHL_Turbo_Drt_Offset_Table ('table output for derate factor') has 1/16384 per count.")
table("0x003ff7ce", "", "charge_flow_compressor_outlet_temperature_derate_factor_by_ratio_axis", "word[17]",
      "Lookup table - x axis of 16 breakpoints after its byte-length word: ratio of compressor_outlet_temperature to the COT limit in Q15 (27853 = 0.85 ... 32768 = 1.0; e2m C_CHL_COT_Drt_Ratio_Axis 0x011AB700) - read by cm848_calculateChargeFlowCompressorOutletTemperatureDerate",
      "Lookup argument is (compressor_outlet_temperature << 15) / charge_flow_compressor_outlet_temperature_derate_limit; axis 27853..32768 from the ROM image. e2m C_CHL_COT_Drt_Ratio_Axis ('ratio input for derate factor'). Only reader: 1 function.")
table("0x003ff7f0", "", "charge_flow_compressor_outlet_temperature_derate_factor_by_ratio_values", "word[17]",
      "Lookup table - data: 16 values (one per axis breakpoint) after a byte-length word: the COT derate factor in Q14 (e2m C_CHL_COT_Drt_Offset_Table 0x011AB800), all -16384 (-1.0) in this calibration - read by cm848_calculateChargeFlowCompressorOutletTemperatureDerate",
      "Multiplied by charge_flow_compressor_outlet_temperature_derate_gain >> 14 and capped by the COT derate maximum; values are all 0xC000 in the ROM image.")
table("0x003ff812", "", "charge_flow_delta_pressure_derate_factor_by_ratio_axis", "word[17]",
      "Lookup table - x axis of 16 breakpoints after its byte-length word: ratio of egr_delta_pressure to charge_flow_delta_pressure_derate_limit in Q15 (same breakpoints as the turbocharger speed derate axis; e2m C_CHL_Delta_P_Drt_Ratio_Axis 0x011AB900) - read by cm848_calculateChargeFlowDeltaPressureDerate",
      "Lookup argument is (max(egr_delta_pressure, 0) << 15) / charge_flow_delta_pressure_derate_limit; axis from the ROM image. e2m C_CHL_Delta_P_Drt_Ratio_Axis ('ratio input for derate factor').")
table("0x003ff834", "", "charge_flow_delta_pressure_derate_factor_by_ratio_values", "word[17]",
      "Lookup table - data: 16 values (one per axis breakpoint) after a byte-length word: the delta pressure derate factor in Q14 (e2m C_CHL_Delta_P_Drt_Offset_Table 0x011ABA00), all -16384 (-1.0) in this calibration - read by cm848_calculateChargeFlowDeltaPressureDerate",
      "Multiplied by charge_flow_delta_pressure_derate_gain >> 14 and capped; values all 0xC000 in the ROM image.")

# already named pair (campaign name says wastegate) = ambient pressure adjustment of the turbo speed derate limit
table("0x003ff746", "wastegate_reference_barometric_pressure_factor_axis",
      "charge_flow_turbocharger_speed_limit_factor_by_barometric_pressure_axis", "word[17]",
      "Lookup table - x axis of 16 breakpoints after its byte-length word: barometric_pressure_reference (0.0159 inHg per count, 0 ... 1886 = 30 inHg; e2m C_CHL_Turbo_Drt_AAP_Axis 0x011AB300, 'ambient air pressure axis for CHL_Turbo_Drt_Limit') - read only by cm848_calculateChargeFlowTurbochargerSpeedDerate (was wastegate_reference_barometric_pressure_factor_axis)",
      "Not a wastegate table: the only reader is the turbocharger speed derate (xref_addr.py: 1 function), where it scales the speed limit (limit x factor >> 15); e2m names it the ambient pressure axis of CHL_Turbo_Drt_Limit.")
table("0x003ff768", "wastegate_reference_barometric_pressure_factor_values",
      "charge_flow_turbocharger_speed_limit_factor_by_barometric_pressure_values", "word[17]",
      "Lookup table - data: 16 values (one per axis breakpoint) after a byte-length word: Q15 factor applied to the turbocharger speed limit (all 32768 = 1.0 in this calibration; e2m C_CHL_Turbo_Drt_Adj_Table 0x011AB400, 'table output adjustment for CHL_Turbo_Drt_Limit') - read only by cm848_calculateChargeFlowTurbochargerSpeedDerate (was wastegate_reference_barometric_pressure_factor_values)",
      "Same reader and scaling as the axis row; values all 0x8000 in the ROM image.")

# CSE tables
table("0x003ff862", "throttle_load_gain_angle_x_axis", "charge_system_transform_angle_x_axis", "word[17]",
      "Lookup table - x axis of 16 breakpoints after its byte-length word: engine speed (0.125 rpm per count, 0 ... 28800 = 3600 rpm; e2m C_CSE_Xform_Engine_Speed_Axis 0x0116A900) - read by cm848_selectChargeSystemTransformAngle (was throttle_load_gain_angle_x_axis)",
      "Dual-axis lookup argument 1 is engine_rpm_state_t_0040b7ac.current_rpm; axis values from the ROM image; e2m: 3-D table for the charge system transform angle.")
table("0x003ff884", "throttle_load_gain_angle_y_axis", "charge_system_transform_angle_y_axis", "word[17]",
      "Lookup table - y axis of 16 breakpoints after its byte-length word: total_injection_quantity_for_air_handling (0.0679 mm3 per stroke per count, 0 ... 2355 = 160 mm3; e2m C_CSE_Xform_Engine_Fuel_Axis 0x0116AA00) - read by cm848_selectChargeSystemTransformAngle (was throttle_load_gain_angle_y_axis)",
      "Dual-axis lookup argument 2 is total_injection_quantity_for_air_handling; e2m MM3S 0.0679.")
table("0x003ff8a6", "throttle_load_gain_angle_grid", "charge_system_transform_angle_grid", "word[256]",
      "Lookup table - 2-D grid: 16 rows of 16 values (z[(y - 1) x 16 + x - 1] / no header): the charge system transform angle in 1/512 degree (e2m C_CSE_Xform_Angle_Table 0x0116AB00, DEG 0.001953125); all 256 values are 46080 = 90 degrees in this calibration - read by cm848_selectChargeSystemTransformAngle (was throttle_load_gain_angle_grid)",
      "The output is charge_system_transform_angle_scheduled (e2m CSE_Scheduled_Xform_Angle, same unit); all 256 values read 0xB400 from the ROM image.")
table("0x003fface", "throttle_load_gain_half_angle_cosine_axis", "charge_system_transform_cosine_axis", "word[20]",
      "Lookup table - x axis of 19 breakpoints after its byte-length word: angle 0 ... 46080 in 1/512 degree = 0 ... 90 degrees in 5 degree steps (e2m C_CSE_Cosine_Input_Axis 0x0116AD00, 'input defined from 0-PI/2') - read by cm848_transformChargeSystemErrors (was throttle_load_gain_half_angle_cosine_axis)",
      "REJECTS the wave-8 'half-angle' reading: the table is a plain cosine over 0-90 degrees. The values fit 8192 x cos(angle) with a maximum deviation of 3.3 counts (the same numbers also fit cos(angle / 2) if the angle unit were 1/256 degree, so the CODE cannot discriminate the two; the plain cosine rests on the e2m only: it declares 1/512 degree per count and describes the axis as 'input defined from 0-PI/2'; the angle limits 512 / 46080 then read 1 / 90 degrees and the all-90-degree grid decouples the two controllers).")
table("0x003ffaa6", "throttle_load_gain_half_angle_cosine_values", "charge_system_transform_cosine_values", "word[20]",
      "Lookup table - data: 19 values (one per axis breakpoint) after a byte-length word: cosine of the axis angle in Q13 (8192 = 1.0 ... 0 at 90 degrees; e2m C_CSE_Cosine_Table 0x0116AC00, 1.2207E-4 per count) - read by cm848_transformChargeSystemErrors (was throttle_load_gain_half_angle_cosine_values)",
      "Read at the angle and at 0xb400 minus the angle (cos and sin of the rotation); the product is shifted >> 14, i.e. Q13 x error / 2, matching the e2m unit step between CSE_MCF_Adj_Error (0.015625) and CSE_Xform_Error_1 (0.03125). Values 8192, 8159, 8069, 7913 ... 713, 0 from the ROM image.")
table("0x003ffc3e", "throttle_fuel_demand_deviation_gain_axis", "charge_system_transient_gain_by_mass_charge_flow_error_axis", "word[17]",
      "Lookup table - x axis of 16 breakpoints after its byte-length word: charge_system_mass_charge_flow_error (signed, 0.015625 lb/min per count, -959 ... 384; e2m C_CSE_Trans_MCF_Axis 0x011A1500, 'input axis of Transient Gain Adjust 2D Table') - read by cm848_calculateChargeSystemAdjustedMassChargeFlowError (was throttle_fuel_demand_deviation_gain_axis)",
      "Lookup argument is charge_system_mass_charge_flow_error; the wave-6 'fuel quantity deviation in mm3' reading is rejected (the unit is lb/min of charge flow, e2m LB/MIN 0.015625).")
table("0x003ffc60", "throttle_fuel_demand_deviation_gain_values", "charge_system_transient_gain_by_mass_charge_flow_error_values", "word[17]",
      "Lookup table - data: 16 values (one per axis breakpoint) after a byte-length word: transient gain in Q13 (8192 = 1.0, 16384 = 2.0; e2m C_CSE_Trans_Gain_Mult_Table 0x011A1600, 1.2207E-4 per count) -> charge_system_transient_gain_adjusted - read by cm848_calculateChargeSystemAdjustedMassChargeFlowError (was throttle_fuel_demand_deviation_gain_values)",
      "Output is added to charge_system_aggressiveness_gain_adjusted and multiplied with the error >> 13 (Q13); values 16384 ... 8192 ... 16384 from the ROM image (1.0 inside about -1 to +2 lb/min).")
# EAC tables
table("0x003ffaf6", "", "egr_assist_controller_proportional_gain_multiplier_by_mass_charge_flow_error_axis", "word[20]",
      "Lookup table - x axis of 19 breakpoints after its byte-length word: charge_system_mass_charge_flow_error (signed, 0.015625 lb/min per count, -1536 ... 1921; e2m C_EAC_Trans_MCF_Axis 0x01185500, 'input axis for charge error base EAC P_Gain scheduling') - read by cm848_calculateEgrAssistControllerGains",
      "Lookup argument is charge_system_mass_charge_flow_error; output x egr_assist_controller_proportional_gain >> 12 is egr_assist_controller_adjusted_proportional_gain.")
table("0x003ffb1e", "", "egr_assist_controller_proportional_gain_multiplier_by_mass_charge_flow_error_values", "word[20]",
      "Lookup table - data: 19 values (one per axis breakpoint) after a byte-length word: multiplier of the proportional gain in Q12 (4096 = 1.0; e2m C_EAC_Trans_Gain_Mult_Axis 0x01185600, 'output axis for charge error based EAC P_Gain scheduling'); all 4096 in this calibration - read by cm848_calculateEgrAssistControllerGains",
      "The product with the gain is shifted >> 12; values all 0x1000 in the ROM image.")
table("0x003ffbfa", "", "egr_assist_controller_integral_gain_multiplier_by_egr_valve_error_axis", "word[17]",
      "Lookup table - x axis of 16 breakpoints after its byte-length word: charge_system_error_for_egr_valve (signed, 0.03125 per count, -320 ... 256; e2m C_EAC_I_Gain_Error_Axis 0x0119E800, 'input axis for error-based gain on EAC Integral Gain scheduling') - read by cm848_calculateEgrAssistControllerGains",
      "Lookup argument is charge_system_error_for_egr_valve (CSE_Xform_Error_1, 0.03125 per count); axis from the ROM image.")
table("0x003ffc1c", "", "egr_assist_controller_integral_gain_multiplier_by_egr_valve_error_values", "word[17]",
      "Lookup table - data: 16 values (one per axis breakpoint) after a byte-length word: multiplier of the integral gain in Q12 (4096 = 1.0; e2m C_EAC_I_Gain_Mult_Table 0x0119E900); all 4096 in this calibration - read by cm848_calculateEgrAssistControllerGains",
      "Product with egr_assist_controller_integral_gain >> 12 is egr_assist_controller_adjusted_integral_gain; values all 0x1000.")
table("0x003ffb46", "", "egr_assist_controller_preset_lift_x_axis", "word[7]",
      "Lookup table - x axis of 6 breakpoints after its byte-length word: EGR mass flow = egr_fraction_limited_command x charge_mass_flow_filtered >> 13 (0.0078125 lb/min per count, 0 ... 1024 = 8 lb/min; e2m C_EAC_Preset_EGR_Flow_Axis 0x01187100) - read by cm848_calculateEgrAssistControllerPreset",
      "Dual-axis lookup argument 1; axis values from the ROM image.")
table("0x003ffb54", "", "egr_assist_controller_preset_lift_y_axis", "word[7]",
      "Lookup table - y axis of 6 breakpoints after its byte-length word: egr_delta_pressure (0.0159 inHg per count, 0 ... 880 = 14 inHg; e2m C_EAC_Preset_Delta_P_Axis 0x01187200) - read by cm848_calculateEgrAssistControllerPreset",
      "Dual-axis lookup argument 2 is egr_delta_pressure; axis values from the ROM image.")
table("0x003ffb62", "", "egr_assist_controller_preset_lift_grid", "word[36]",
      "Lookup table - 2-D grid: 6 rows of 6 values (z[(y - 1) x 6 + x - 1] / no header): egr_assist_controller_preset_lift in percent (0.0078125 per count; e2m C_EAC_Preset_Lift_Table 0x01187300, 'set EAC_Preset_Lift when Preset = TRUE'); all 36 values are 0 in this calibration - read by cm848_calculateEgrAssistControllerPreset",
      "Output is stored in egr_assist_controller_preset_lift while the preset is active; all values 0 in the ROM image.")

# renamed variables that carried the wrong half-angle idea
g("0x003fa15a", "charge_system_transform_half_angle_cosine", "charge_system_transform_cosine",
  "code: cos(charge_system_transform_angle) in Q13 from charge_system_transform_cosine_values (not Q14, and not a half-angle: see the table note). Dump 0 (angle 90 degrees = cos 0). " + BOOT + " (was charge_system_transform_half_angle_cosine)")
g("0x003fa15c", "charge_system_transform_half_angle_sine", "charge_system_transform_sine",
  "code: the same table read at 0xb400 minus the angle = cos(90 degrees - angle) = sin(angle), Q13. Dump 8192 (sin 90 degrees = 1.0). " + BOOT + " (was charge_system_transform_half_angle_sine)")
g("0x003fa15e", "charge_system_transform_supplementary_angle", "charge_system_transform_complementary_angle",
  "code: 0xb400 - charge_system_transform_angle: 0xb400 = 46080 = 90 degrees at 1/512 degree per count (e2m CSE_Xform_Angle DEG 0.001953125), so this is the complement, not the supplement. Dump 0. " + BOOT + " (was charge_system_transform_supplementary_angle)")
g("0x003fa150", "throttle_load_gain_interp_state", "charge_system_transform_cosine_interpolation_state",
  "code: interpolation cache word of the two cosine lookups in cm848_transformChargeSystemErrors (initialized to 2 by cm848_initializeChargeSystemErrorTables). " + BOOT + " (was throttle_load_gain_interp_state)")

note("TABLE NOTE, CHARGE MANAGER: none of the 20 charge manager table rows above (CHL derate, CSE angle / cosine / transient gain, EAC gain / preset) and none of the two barometric pressure rows has an arrays.csv row: all are plain global_variables.csv rows typed word[N], so no arrays.csv change is needed. The six C_CHL derate tables of 0x3ff78a-0x3ff834 are e2m C_CHL_*_Drt_Ratio_Axis / _Drt_Offset_Table (0x011AB500-0x011ABA00); all of them are exactly one 16-point ratio axis plus one Q14 factor table with a constant -1.0, so the derates are linear in gain x (ratio - 1) only through the ratio threshold (ratio below C_CHL_*_Drt_Ratio gives -6400). The transform angle is 90 degrees everywhere (all 256 grid values 0xB400), so the rotation decouples the EGR valve error (EGR fraction error) from the turbocharger error (mass charge flow error). The cosine table is a plain cosine (0 to 90 degrees, Q13), not a half-angle cosine; variables charge_system_transform_half_angle_cosine / _half_angle_sine / _supplementary_angle are renamed above, and the plate comments of cm848_transformChargeSystemErrors / cm848_selectChargeSystemTransformAngle need the same correction (see the function row).")

fn("0x00011170", "cm848_transformChargeSystemErrors", "cm848_transformChargeSystemErrors",
   "Rotates the adjusted charge system errors by the transform angle (1/512 degree, 0 to 90 degrees): the cosine table is read at the angle and at 0xb400 (90 degrees) minus the angle, so charge_system_error_for_egr_valve = cos x mass flow error - sin x EGR fraction error / 1.28 and charge_system_error_for_turbocharger = sin x mass flow error + cos x EGR fraction error / 1.28 (Q13 table, >> 14 gives the e2m unit step). (was cm848_calculateLoadAdjustmentFactors)",
   "Name stays; the plate comment said 'half-angle cosine table': the table values equal 8192 x cos(angle) at the e2m unit 1/512 degree (C_CSE_Cosine_Table / C_CSE_Cosine_Input_Axis 'input defined from 0-PI/2'), so it is a plain cosine.")

import csv
import json
import re

OUT = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-typing-arrays/firmware/CM848_S90140.06_analysis/output/"
RES = "/home/linux/.claude/jobs/d55ae3c6/tmp/renames/result_W6_combustion.jsonl"

rows = []


def G(addr, old, new, ev, kind="global"):
    rows.append({"kind": kind, "address": "0x%08x" % addr, "old": old, "verdict": "confirmed", "new": new, "evidence": ev})


def NG(addr, new, typ, ev):
    rows.append({"kind": "new_global", "address": "0x%08x" % addr, "new": new, "type": typ, "evidence": ev})


def F(addr, old, new, plate, ev):
    r = {"kind": "function", "address": "0x%08x" % addr, "old": old, "verdict": "confirmed", "evidence": ev}
    if new != old:
        r["new"] = new
    if plate:
        r["plate_comment"] = plate
    rows.append(r)


def N(text):
    rows.append({"kind": "note", "text": text})


def U(addr, old, ev, kind="global"):
    rows.append({"kind": kind, "address": "0x%08x" % addr, "old": old, "verdict": "uncertain", "evidence": ev})


def SF(struct, old, new, ev):
    rows.append({"kind": "struct_field", "struct": struct, "old": old, "new": new, "evidence": ev})


# ---------------------------------------------------------------- A. CBL tables
CBL_MIN = ("Code: cm848_applyCombustionTimingLimits looks up engine speed against the x axis and fuel_quantity_compensated_reference "
           "against the y axis (cm848_dualAxisTableInterpolation, 19 x 16) into injection_timing_combustion_minimum_limit. "
           "Dump: speed 500..3500 rpm, fuel 0..149.9 mm3, grid flat 43 counts (5 deg). e2m: C_CBL_SOI_Min_Speed_Axis 0x01171C00 / "
           "Min_Fuel_Axis 0x01171D00 / Min_Limit_Table 0x01171E00, in the same order as these RAM addresses.")
CBL_MAX = ("Code: the second lookup of cm848_applyCombustionTimingLimits (engine speed x fuel_quantity_compensated_reference, 19 x 16) "
           "gives injection_timing_combustion_maximum_limit. Dump: same speed and fuel breakpoints as the minimum table, grid flat "
           "384 counts (45 deg). e2m: C_CBL_SOI_Max_Speed_Axis 0x01171F00 / Max_Fuel_Axis 0x01172000 / Max_Limit_Table 0x01172100.")
CBL_MCF = ("Code: cm848_limitMassChargeFlowReference looks up engine speed against the x axis and the ambient air density "
           "(engine_load_input_value) against the y axis (16 x 16) into mass_charge_flow_density_limit (1/128 lb/min). Dump: speed "
           "800..3500 rpm, density 737..1638 counts (6.1035e-5 lbm/ft3 per count), grid 3200..9600 counts = 25..75 lb/min. e2m: "
           "C_CBL_MCF_Limit_Speed_Axis 0x01199800 / Density_Axis 0x01199900 / Table 0x01199A00 (LB/MIN 0.0078125).")
G(0x40523e, "injection_timing_rpm_axis_cal", "injection_timing_combustion_minimum_limit_x_axis", CBL_MIN)
G(0x405266, "injection_timing_load_axis_cal", "injection_timing_combustion_minimum_limit_y_axis", CBL_MIN)
G(0x405288, "injection_timing_advance_yend_cal", "injection_timing_combustion_minimum_limit_grid", CBL_MIN)
G(0x4054e8, "injection_timing_mode2_rpm_axis_cal", "injection_timing_combustion_maximum_limit_x_axis", CBL_MAX)
G(0x405510, "injection_timing_mode2_ystart_cal", "injection_timing_combustion_maximum_limit_y_axis", CBL_MAX)
G(0x405532, "injection_timing_mode2_yend_cal", "injection_timing_combustion_maximum_limit_grid", CBL_MAX)
G(0x405792, "fuel_demand_load_rate_cap_rpm_axis_cal", "mass_charge_flow_density_limit_x_axis", CBL_MCF)
G(0x4057b4, "fuel_demand_load_rate_cap_ystart_cal", "mass_charge_flow_density_limit_y_axis", CBL_MCF)
G(0x4057d6, "fuel_demand_load_rate_cap_yend_cal", "mass_charge_flow_density_limit_grid", CBL_MCF)

# ---------------------------------------------------------------- B. CBR maps, axes, pointers
FAM = [  # (family prefix, base grid addr, old base name, reference function, e2m alpha0 table, pointer first addr, old pointer names, [map1..4 grid addrs], e2m tables)
    ("injection_timing", 0x40153c, "fuel_demand_mode_b_map_values_cal", "cm848_calculateCombustionTimingReference", "C_CBR_SOI_Alpha0_Table 0x01170A00",
     0x3fa666, ["fuel_demand_limit_table_a_pointer", "fuel_demand_limit_table_b_pointer", "fuel_demand_limit_table_c_pointer", "fuel_demand_limit_table_d_pointer"],
     [0x40179c, 0x400e1c, 0x40107c, 0x4012dc], "C_CBR_SOI_Alpha1/Chi2/Chi3/Chi4_Table 0x01170B00 / 0x01170700 / 0x01170800 / 0x01170900"),
    ("mass_charge_flow", 0x40211c, "fuel_demand_rate_map_values_cal", "cm848_calculateMassChargeFlowReference", "C_CBR_MCF_Alpha0_Table 0x01185C00",
     0x3fa656, ["fuel_demand_mode3_load_axis_offset1", "fuel_demand_mode3_load_axis_offset2", "fuel_demand_mode3_load_axis_offset3", "fuel_demand_mode3_load_axis_offset4"],
     [0x40237c, 0x4019fc, 0x401c5c, 0x401ebc], "C_CBR_MCF_Alpha1/Chi2/Chi3/Chi4_Table 0x01185D00 / 0x01170C00 / 0x01170D00 / 0x01170E00"),
    ("egr_fraction", 0x402cfc, "fuel_demand_rate_b_map_values_cal", "cm848_calculateEgrFractionReference", "C_CBR_EGR_Frac_Alpha0_Table 0x01186100",
     0x3fa646, ["fuel_quantity_table_a_pointer", "fuel_quantity_table_b_pointer", "fuel_quantity_table_c_pointer", "fuel_quantity_table_d_pointer"],
     [0x402f5c, 0x4025dc, 0x40283c, 0x402a9c], "C_CBR_EGR_Frac_Alpha1/Chi2/Chi3/Chi4_Table 0x01186200 / 0x01185E00 / 0x01185F00 / 0x01186000"),
    ("charge_temperature", 0x4038dc, "fuel_demand_mode2_map_values_cal", "cm848_calculateChargeTemperatureReference", "C_CBR_Charge_Tmptr_Alpha0_Table 0x01186600",
     0x3fa676, ["fuel_demand_mode2_load_axis_offset1", "fuel_demand_mode2_load_axis_offset2", "fuel_demand_mode2_load_axis_offset3", "fuel_demand_mode2_load_axis_offset4"],
     [0x403b3c, 0x4031bc, 0x40341c, 0x40367c], "C_CBR_Charge_Tmptr_Alpha1/Chi2/Chi3/Chi4_Table 0x01186700 / 0x01186300 / 0x01186400 / 0x01186500"),
    ("nitrogen_oxides_target", 0x4044bc, "fuel_demand_mode1_map_values_cal", "cm848_calculateNitrogenOxidesTargetReference", "C_CBR_NOx_Alpha0_Table 0x01186B00",
     0x3fa686, ["fuel_demand_mode1_load_axis_offset1", "fuel_demand_mode1_load_axis_offset2", "fuel_demand_mode1_load_axis_offset3", "fuel_demand_mode1_load_axis_offset4"],
     [0x40471c, 0x403d9c, 0x403ffc, 0x40425c], "C_CBR_NOx_Alpha1/Chi2/Chi3/Chi4_Table 0x01186C00 / 0x01186800 / 0x01186900 / 0x01186A00"),
]
for fam, base, oldbase, fn, e2m0, ptr0, oldptrs, maps, e2mall in FAM:
    G(base, oldbase, "%s_combustion_base_map_grid" % fam,
      "Code: read only by %s as the base map (alpha 0 end) of the alpha-chi blend, engine speed x fuel quantity, 19 x 16 words by the "
      "base axes; its output word is %s_combustion_base_map_output. e2m: %s; the RAM order Chi2 < Chi3 < Chi4 < Alpha0 < Alpha1 "
      "matches the e2m address order." % (fn, fam, e2m0))
    for i in range(4):
        n = i + 1
        NG(maps[i], "%s_combustion_map_%d_grid" % (fam, n), "word[304]",
           "No row exists and no instruction addresses it: %s reaches it only through the pointer word %s_combustion_map_%d_pointer "
           "that cm848_initializeCombustionReferenceMapPointers fills. Code: word[304] comes from the axes (word[20] x word[17], 19 x 16 "
           "grid) and cm848_dualAxisTableInterpolation, not from xref_addr.py (which has nothing to report for a pointer-reached table). "
           "Map number %d is %s (%s)." % (fn, fam, n, n, ["alpha 1", "chi 2", "chi 3", "chi 4"][i], e2mall))
        G(ptr0 + 4 * i, oldptrs[i], "%s_combustion_map_%d_pointer" % (fam, n),
          "Code: cm848_initializeCombustionReferenceMapPointers stores the address 0x%x of map %d of this family here; the only other "
          "user is %s, which passes it as the grid of the map %d lookup. The old name is wrong (it is a map base address, not a table "
          "or an axis offset). Time-shared RAM (0x3F9800-0x3FDB30): xref_addr.py lists the two users above, no user below 0x7F60; "
          "the row type is not changed." % (maps[i], n, fn, n))

AXES = [  # (x addr, y addr, old x, old y, name stem, users)
    (0x40499e, 0x40497c, "fuel_table_rpm_axis_cal", "fuel_table_load_axis_cal", "combustion_base_map"),
    (0x4049e8, 0x4049c6, "fuel_demand_rpm_axis_cal", "fuel_demand_load_axis_cal", "combustion_map_1"),
    (0x404a32, 0x404a10, "fuel_demand_xaxis_cal_2", "fuel_demand_xaxis_cal_1", "combustion_map_2"),
    (0x404a7c, 0x404a5a, "fuel_demand_xaxis_cal_4", "fuel_demand_xaxis_cal_3", "combustion_map_3"),
    (0x404ac6, 0x404aa4, "fuel_demand_xaxis_cal_6", "fuel_demand_xaxis_cal_5", "combustion_map_4"),
]
E2MAX = {"combustion_base_map": "C_CBR_Alpha0_Speed_Axis 0x01192400 / Alpha0_Fuel_Axis 0x01192300",
         "combustion_map_1": "C_CBR_Alpha1_Speed_Axis 0x01192600 / Alpha1_Fuel_Axis 0x01192500",
         "combustion_map_2": "C_CBR_Chi2_Speed_Axis 0x01192800 / Chi2_Fuel_Axis 0x01192700",
         "combustion_map_3": "C_CBR_Chi3_Speed_Axis 0x01192A00 / Chi3_Fuel_Axis 0x01192900",
         "combustion_map_4": "C_CBR_Chi4_Speed_Axis 0x01192C00 / Chi4_Fuel_Axis 0x01192B00"}
for xa, ya, ox, oy, stem in AXES:
    extra = (" The map 1 axes have a sixth user, cm848_calculateBoostPressureOffset (its own grid, engine speed x "
             "total_injection_quantity_for_air_handling), so these two axes are shared beyond the combustion maps." if stem == "combustion_map_1" else "")
    ev = ("Code: the same axis pair is passed by the timing, mass charge flow, EGR fraction, charge temperature and NOx target reference "
          "functions (cm848_calculate*Reference) as x = engine speed and y = fuel quantity (injection_quantity_combustion_reference or the "
          "gross fuel) for the %s lookups (the grid argument is the base grid for the base axes and the pointer word of the same map number otherwise, checked in all five functions); the axis is shared by "
          "five grids, so it is named for its input, copying the fuel_limit_barometric_engine_speed_x_axis pattern. e2m: %s, the RAM "
          "order Alpha0 / Alpha1 / Chi2 / Chi3 / Chi4 (fuel axis then speed axis).%s"
          % (stem.replace("_", " "), E2MAX[stem], extra))
    G(xa, ox, "%s_engine_speed_x_axis" % stem, ev)
    G(ya, oy, "%s_fuel_quantity_y_axis" % stem, ev)

# 1-D maximum fuel curves and other CBR lookups
MAXF = ("Code: cm848_calculateCombustionChiMaximumFuel (and cm848_lookupChiMaximumFuelAtSpeed at five arbitrary speeds) look the curve "
        "up against engine speed with the shared axis and blend curves 1..4 and the base curve by chi and alpha into "
        "injection_quantity_combustion_chi_maximum; curve N is read when the lower or upper chi map number is N. e2m: C_CBR_Max_Fuel_"
        "Alpha0 / Alpha1 / Chi2 / Chi3 / Chi4_Table 0x01199C00..0x0119A000 (MM3S) over C_CBR_Max_Fuel_Speed_Axis 0x01196800.")
G(0x404aee, "fuel_map_rpm_axis_cal", "injection_quantity_combustion_maximum_curve_axis", MAXF)
G(0x404b1a, "governor_fuel_demand_values_cal", "injection_quantity_combustion_maximum_base_curve_values",
  MAXF + " This is the base (alpha 0) curve; its output word is injection_quantity_combustion_maximum_base_curve_output.")
for i, (a, o) in enumerate([(0x404b46, "fuel_rpm_table_boost1_cal"), (0x404b72, "fuel_rpm_table_boost2_cal"),
                            (0x404b9e, "fuel_rpm_table_boost3_cal"), (0x404bca, "fuel_rpm_table_boost4_cal")]):
    G(a, o, "injection_quantity_combustion_maximum_curve_%d_values" % (i + 1),
      MAXF + " Its output word is injection_quantity_combustion_maximum_curve_%d_output." % (i + 1))
DENS = ("Code: cm848_calculateCombustionGrossFuel looks up engine speed (x) against the ambient air density (engine_load_input_value, y) "
        "into injection_quantity_combustion_density_maximum (0..145 mm3), the density-based maximum fuel; 19 x 16. e2m: "
        "C_CBR_Fuel_Limit_Speed_Axis 0x0119A500 / Fuel_Limit_Density_Axis 0x0119A600 / Density_Fuel_Limit_Table 0x0119A700 (MM3S).")
G(0x404bf6, "fuel_load_table_rpm_axis_cal", "injection_quantity_combustion_density_maximum_x_axis", DENS)
G(0x404c1e, "fuel_load_table_ystart_cal", "injection_quantity_combustion_density_maximum_y_axis", DENS)
G(0x404c40, "fuel_load_table_yend_cal", "injection_quantity_combustion_density_maximum_grid", DENS)
FLA = ("Code: cm848_calculateCombustionTimingReference looks up engine speed against injection_quantity_combustion_reference (19 x 16) "
       "into injection_timing_fuel_limited_adjustment, added to the timing reference only when alpha is 0 and "
       "injection_quantity_combustion_limited_flag is set. e2m: C_CBR_OFC_Limit_SOI_Speed_Axis 0x0116EE00 / OFC_Limit_SOI_Fuel_Axis "
       "0x0116EF00 / OFC_Limit_SOI_Adj_Table 0x0116F000 ('SOI adjustment table when OFC_Limited=TRUE').")
G(0x4009da, "fuel_blend_rpm_axis_cal", "injection_timing_fuel_limited_adjustment_x_axis", FLA)
G(0x400a02, "fuel_blend_ystart_cal", "injection_timing_fuel_limited_adjustment_y_axis", FLA)
G(0x400a24, "fuel_blend_yend_cal", "injection_timing_fuel_limited_adjustment_grid", FLA)

PRO = ("Code: cm848_determineBaseChi passes these six tables to cm848_lookupProtectiveChi for the %s source: input -> chi (first "
       "pair), chi -> level (chi axis, level values; the inverse level -> chi is read from the same pair), chi -> upper map number "
       "(third table, result word 4) and chi -> lower map number (fourth table, result word 3). e2m: %s in the same address order.")
SRC = [("ambient_air_density", "ambient air density (engine_load_input_value, unsigned)",
        "C_CBR_Inlet_Density_Axis 0x0116F500 / Inlet_Chi_Value_Table 0x0116F600 / Inlet_Density_Chi_Axis 0x0116F700 / Inlet_Density_EL_Axis "
        "0x0116F800 / Inlet_Density_High_Table 0x0116F900 / Inlet_Density_Low_Table 0x0116FA00 (compressor inlet density)",
        [0x400c84, 0x400ca6, 0x400cc8, 0x400cea, 0x400d0c, 0x400d2e],
        ["fuel_map_load_axis_cal", "fuel_map_load_values_cal", "fuel_map_load_filter_a_cal", "fuel_map_load_filter_b_cal",
         "fuel_map_load_filter_c_cal", "fuel_map_load_filter_d_cal"]),
       ("coolant_temperature", "coolant temperature (fuel_demand_boost_input, signed 1/64 deg F)",
        "C_CBR_Coolant_Tmptr_Axis 0x01170100 / Coolant_Tmptr_Chi_Axis 0x01170200 / Coolant_Chi_Value_Table 0x01170300 / "
        "Coolant_Tmptr_EL_Axis 0x01170400 / Coolant_Tmptr_High_Table 0x01170500 / Coolant_Tmptr_Low_Table 0x01170600",
        [0x400d50, 0x400d94, 0x400d72, 0x400db6, 0x400dd8, 0x400dfa],
        ["fuel_map_boost_axis_cal", "fuel_map_boost_values_cal", "fuel_map_boost_filter_a_cal", "fuel_map_boost_filter_b_cal",
         "fuel_map_boost_filter_c_cal", "fuel_map_boost_filter_d_cal"])]
for key, label, e2m, addrs, olds in SRC:
    # order of addrs = axis, chi values, chi axis, level values, upper map number, lower map number
    names = ["combustion_protective_chi_by_%s_axis" % key, "combustion_protective_chi_by_%s_values" % key,
             "combustion_%s_chi_axis" % key, "combustion_%s_level_values" % key,
             "combustion_%s_upper_map_number_values" % key, "combustion_%s_lower_map_number_values" % key]
    for a, o, nm in zip(addrs, olds, names):
        G(a, o, nm, PRO % (label, e2m))

# ---------------------------------------------------------------- C. torque map, function, five words
TQ = ("Code: this engine speed x fuel quantity table (signed lookup, flag 6) has three users that all convert a fuel quantity at a "
      "speed to a torque: cm848_calculateNetCombustionTorque (-> combustion_torque, whose name rests on the e2m CBP_Combustion_Torque "
      "'engine torque from CBP_Adj_Total_Fueling & Filtered_Engine_Speed'), cm848_applyProtectionRpmCorrectionFilter (the governor fuel "
      "quantities, whose differences are subtracted from net_combustion_torque) and cm848_fuelDemandRpmCorrection. Dump: speed "
      "620..3500 rpm, fuel 0..139.9 mm3, but the grid is all zero in this calibration, so the values confirm nothing; the role rests on "
      "the three users.")
G(0x405d52, "protection_rpm_correction_axis_cal", "combustion_torque_by_fuel_quantity_x_axis", TQ)
G(0x405d7a, "protection_rpm_correction_ystart_cal", "combustion_torque_by_fuel_quantity_y_axis", TQ)
G(0x405d9c, "protection_rpm_correction_yend_cal", "combustion_torque_by_fuel_quantity_grid", TQ)
F(0x16724, "cm848_fuelDemandRpmCorrection", "cm848_calculateTorqueFromFuelQuantity",
  "Converts a fuel quantity (param_1) at an engine speed (param_2) to a signed torque with the engine speed x fuel quantity torque "
  "map combustion_torque_by_fuel_quantity_*, the same map cm848_calculateNetCombustionTorque uses for combustion_torque. Only caller: "
  "cm848_calculateChiMaximumFuelAtSpeedPoints, for the five chi maximum fuel points. (was cm848_fuelDemandRpmCorrection)",
  "Code: a cm848_dualAxisTableInterpolation of (param_2 speed, param_1 fuel quantity) with signed flag 6 in the table that "
  "cm848_calculateNetCombustionTorque uses for combustion_torque and cm848_applyProtectionRpmCorrectionFilter uses for the governor "
  "fuel quantities: a fuel-to-torque conversion. e2m: CBR_Max_Chi_Fuel_At_Point_1..5 (+82..+8A, 'Max Fuel Curve at rpm N') are its five "
  "inputs and CBR_Max_Chi_Torque_At_Point_1..5 (+8C..+94, 'Torque limit at rpm N from Chi limit function', FT*LB 0.5) sit at exactly "
  "its five outputs. The grid is all zero in this calibration, so the dump cannot confirm the unit.")
for i, (a, o) in enumerate([(0x40a50c, "protection_threshold_scaled_rpm"), (0x40a50e, "protection_recovery_threshold_rpm"),
                            (0x40a510, "protection_hysteresis_rpm"), (0x40a512, "protection_threshold_alt_rpm"),
                            (0x40a514, "protection_base_threshold_rpm")]):
    G(a, o, "combustion_chi_maximum_torque_at_point_%d" % (i + 1),
      "Code: write-only result of cm848_calculateChiMaximumFuelAtSpeedPoints = cm848_fuelDemandRpmCorrection(chi_maximum_fuel_at_point_%d, "
      "engine speed point %d), i.e. the torque map of cm848_calculateNetCombustionTorque evaluated at the chi maximum fuel of that "
      "speed; the value is signed (flag 6), not an rpm. Dump 0 because the torque grid is all zero, which confirms nothing. e2m: "
      "CBR_Max_Chi_Torque_At_Point_%d at +%X, 'Torque limit at rpm %d from Chi limit function', directly after CBR_Max_Chi_Fuel_At_Point_%d."
      % (i + 1, i + 1, i + 1, 0x8C + 2 * i, i + 1, i + 1))
N("Type note for the five combustion_chi_maximum_torque_at_point_N words (0x40a50c-0x40a514): the lookup is signed (flag 6, the function "
  "returns (int)(short)), so i16 would be the honest type; they are not time-shared RAM. Not proposed as a type change here. The five "
  "engine speed points they are computed at (0x40adac-0x40adb4, dump 750 / 3200 / 1400 / 2600 / 2800 rpm) carry old protection_* names "
  "and belong to the protection cluster (cm848_updateProtectionStateMachine and others read them); not renamed here.")

# ---------------------------------------------------------------- D. CBR scalars
CBR = [
    (0x4059d6, "fuel_blend_mode_default_cal", "combustion_alpha_override_percent",
     "Code: cm848_selectChiAndAlpha stores it as alpha_percent first and keeps it when engine_feature_enable_flags bit 5 (0x20, alpha override) is set (dump 100). e2m: C_CBR_Alpha_Override_Value +00 (0.01) 'Force CBR_Alpha to this value upon override'."),
    (0x4059d8, "fuel_blend_threshold_cal", "combustion_alpha_clamp_chi_limit_hundredths",
     "Code: alpha_percent follows the alpha input only when the chi (hundredths) is below this value and egr_off_flag is 0, otherwise it is 100 (dump 101). e2m: C_CBR_Alpha_Clamp_Chi_Limit +02 (0.01) 'CBR_Alpha will be Alpha when Chi is less than this, unless overidden'."),
    (0x4059da, "fuel_blend_step_a_cal", "combustion_status_flag_chi_hundredths",
     "Code: the chi (hundredths, dump 400 = 4.00) that cm848_selectChiAndAlpha forces, as source code 14 with EGR off, when fuel_mode_status_flags bit 8, 0x10 or 0x200 is set; the bits come from sensor validity, cold start and cylinder check words and were not traced further, so the name says only what selects it. e2m: C_CBR_Protection_Chi +04 'If chi.source=CBR_PROTECTION_CHI, then Chi will be this' (hence no bare protection in the name)."),
    (0x4059dc, "fuel_blend_step_b_cal", "combustion_chi_override_paired_level",
     "Code: the level (dump 5120) that goes with the override chi in both override modes (combustion_chi_paired_level). e2m: C_CBR_Chi_Override_EL +06 (G/HP*HR 0.000488) 'Force chi.el to this value upon override'."),
    (0x4059de, "fuel_blend_mode_b_param_cal", "combustion_chi_override_upper_map_number",
     "Code: in the full override (bit 6 set) it is the upper map number of the chi (combustion_chi_upper_map_number, clamped 1..4; dump 1). e2m: C_CBR_Chi_Override_HighTable +08 'Force chi.hightable to this value upon override'."),
    (0x4059e0, "fuel_blend_weight_percent_cal", "combustion_chi_override_hundredths",
     "Code: the override chi in hundredths (dump 100); the full override (bit 6) uses it as is (source 12), the single value override (bit 6 clear) rounds it down to a whole chi clamped 100..400 and derives both map numbers from it (source 13). e2m: C_CBR_Chi_Override_Value +0A (0.01) 'Force Chi to this value upon override'."),
    (0x4059e2, "fuel_blend_step_b_threshold_cal", "combustion_chi_override_lower_map_number",
     "Code: in the full override it is the lower map number of the chi (clamped 1..4; dump 0 becomes 1). e2m: C_CBR_Chi_Override_LowTable +0C 'Force chi.lowtable to this value upon override'."),
    (0x4059e4, "fuel_blend_step_c_cal", "combustion_egr_off_chi_hundredths",
     "Code: the chi (dump 400 = 4.00) forced with source code 10 when EGR is requested off without a status-flag chi; its whole-number part is also used as both map numbers. e2m: C_CBR_EGR_Off_Chi +0E (0.01) 'force chi.value, .lowtable, .hightable to this when EGR off'."),
    (0x4059e6, "fuel_blend_step_c_threshold_cal", "combustion_egr_off_paired_level",
     "Code: the level (dump 16384) that goes with the EGR-off chi. e2m: C_CBR_EGR_Off_EL +10 (G/HP*HR 0.000488) 'force chi.el to this when EGR off'."),
    (0x4059e8, "fuel_blend_mode_override_cal", "combustion_egr_off_override_value",
     "Code: when engine_feature_enable_flags bit 8 (0x100) is set it replaces the egr_off_flag of the combustion reference state (dump 1); the other overrides in this family are named _override_value. e2m: C_CBR_EGR_Off_Override_Value +12 (HEX) 'Set to TRUE to permit EGR to be turned off by user override'."),
    (0x4059ea, "fuel_blend_load_ratio_lower_cal", "injection_quantity_combustion_limited_off_ratio",
     "Code: cm848_calculateCombustionFuelReference clears injection_quantity_combustion_limited_flag when the gross-to-limit ratio (Q13) is at or below it (dump 9830 = 1.2). e2m: C_CBR_FCLR_Off +14 (0.00012207) 'Below this FCLR level the OFC_Lmtd_Flag is set to 0'."),
    (0x4059ec, "fuel_blend_load_ratio_upper_cal", "injection_quantity_combustion_limited_on_ratio",
     "Code: the flag is set when the gross-to-limit ratio (Q13) reaches it (dump 17203 = 2.1). e2m: C_CBR_FCLR_On +16 'Above this FCLR level the OFC_Lmtd_Flag is set to 1'."),
    (0x4059ee, "fuel_demand_limit_mode17_cal", "injection_quantity_combustion_reference_override_value",
     "Code: replaces injection_quantity_combustion_reference (source code 23) when engine_feature_enable_flags bit 9 (0x200) is set (dump 0). e2m: C_CBR_Fuel_Ref_Override_Value +18 (MM3S) 'Fueling override value in combustion manager after OFC limit'."),
    (0x4059f0, "fuel_blend_step_a_threshold_cal", "combustion_status_flag_paired_level",
     "Code: the level (dump 8192) paired with the status-flag chi (combustion_chi_paired_level when source code 14). e2m: C_CBR_Protection_EL +1A (G/HP*HR 0.000488) 'Corresponds to C_CBR_Protection_Chi'."),
    (0x4059f2, "fuel_demand_blend_threshold_cal", "injection_quantity_combustion_gross_timing_adjustment_threshold",
     "Code: cm848_calculateCombustionGrossFuel subtracts injection_timing_torque_to_fuel_adjustment from the arbitrated fuel demand only when the demand is at or above it (dump 588 counts = 40 mm3), and sets gross_fuel_timing_adjustment_active_flag. e2m: C_CBR_SOI_Adj_Fuel_Thd +1C 'Threshold where SOI based fuel adj is turned off'."),
    (0x4059f4, "fuel_demand_rpm_correction_scale", "net_combustion_torque_subtracted_term_scale",
     "Code: cm848_calculateNetCombustionTorque multiplies fuel_demand_rpm_correction_lookup (the torque table value at governor_speed_target_base, a legacy name that was not checked) by it and divides by 0x800 (Q11, dump 2099 = 1.025); the product is subtracted from net_combustion_torque. e2m: C_CBP_Coolant_Torque_Adj_Factor at +1E of the same C_CBR block, 'UNITLESS 0.00048828125' = 1/2048 ('Used on Coolant_Torque_Adjustment in CBR'): position and scale agree with the code; the coolant meaning is not visible in the code, so the name follows the code. The earlier lead said it has no e2m word."),
    (0x4059f6, "fuel_demand_mode_0x37_val_cal", "injection_quantity_combustion_gross_override_value",
     "Code: replaces the gross fuel (source code 55) when engine_feature_enable_flags bit 10 (0x400) is set (dump 0). e2m: C_CBR_Gross_Fuel_Override_Value +20 (MM3S) 'Fueling override value in combustion manager before OFC limit'."),
    (0x4059f8, "fuel_demand_boost_input_lower_cal", "combustion_egr_off_coolant_temperature_limit",
     "Code: cm848_selectChiAndAlpha requests EGR off when fuel_mode_status_flags bit 0x40 is set and the coolant temperature (fuel_demand_boost_input) is at or below it (dump 3840 = 60 deg F at 1/64). e2m: C_CBR_UHC_Coolant_Tmptr_Limit +22 (DEG_F 0.015625) 'limit for combustion reference determine egr off scalars'."),
    (0x4059fa, "fuel_demand_boost_offset_lower_cal", "combustion_egr_off_intake_temperature_limit",
     "Code: EGR off is requested when fuel_mode_status_flags bit 0x20 is set and the filtered intake manifold temperature (fuel_demand_boost_offset) is at or below it (dump 2880 = 45 deg F at 1/64). e2m: C_CBR_UHC_Charge_Tmptr_Limit +24 (DEG_F 0.015625); the e2m calls the intake gas the charge, the code compares the intake manifold temperature."),
]
UNC = {
    0x4059da: "Code: the chi (hundredths, dump 400 = 4.00) that cm848_selectChiAndAlpha forces, with source code 14 and EGR off, when fuel_mode_status_flags bit 8, 0x10 or 0x200 is set. Origin of those bits checked: bit 8 is DAT_003fbd56 = 8 in cm848_updateSensorValidationFlags (from DAT_0040a43c, only when governor_feature_config_flags bit 0x40 is set); DAT_003fbd50 / DAT_003fbd54 are only initialised to 0 by name; DAT_00406568 / DAT_0040656a (1024 in the dump) are ROM-copied words that fuel_modeStatusFlags_update uses as or ORs into the flags, so bits 0x10 and 0x200 can come from the calibration. The bits do not come from one traceable function, so no name that says what triggers it. e2m: C_CBR_Protection_Chi +04 'If chi.source=CBR_PROTECTION_CHI, then Chi will be this' (the old name fuel_blend_step_a_cal stays until the trigger is known; the name must not use a bare protection).",
    0x4059f0: "Code: the level (dump 8192) paired with the same chi: combustion_chi_paired_level when the source code is 14. Same trigger problem as 0x4059da (bits 8 / 0x10 / 0x200 of fuel_mode_status_flags do not all come from cm848_updateSensorValidationFlags), so no name. e2m: C_CBR_Protection_EL +1A (G/HP*HR 0.000488) 'Corresponds to C_CBR_Protection_Chi'.",
}
for a, o, nm, ev in CBR:
    if a in UNC:
        U(a, o, UNC[a])
    else:
        G(a, o, nm, ev)

# ---------------------------------------------------------------- E. CBO scalars, tables, torque to fuel
CBO_S = [
    (0x4059fc, "fuel_demand_blend_lower_cal", "charge_temperature_reference_delta_minimum_limit",
     "Code: cm848_calculateOffNominalChargeTemperatureAdjustment clamps (charge_temperature_combustion_reference - intake temperature) from below to it (dump 0). e2m: C_CBO_Delta_Charge_Tmptr_Min 0x01171000 (DEG_F 0.015625), first word of the C_CBO block in the RAM order."),
    (0x4059fe, "fuel_demand_mode2_upper_limit_cal", "charge_temperature_reference_delta_maximum_limit",
     "Code: upper clamp of the same delta (dump 0). e2m: C_CBO_Delta_Charge_Tmptr_Max 0x01171002."),
    (0x405a08, "engine_load_blend_floor_cal", "off_nominal_composite_adjustment_minimum_limit",
     "Code: cm848_calculateOffNominalCompensation clamps charge_temperature_off_nominal_adjustment x oxygen_fraction_off_nominal_adjustment >> 13 from below to it (dump 0). e2m: C_CBO_Composite_Min 0x0117100C (0.0078125)."),
    (0x405a0a, "engine_load_correction_blend_upper_cal", "off_nominal_composite_adjustment_maximum_limit",
     "Code: upper clamp of the composite adjustment (dump 0). e2m: C_CBO_Composite_Max 0x0117100E."),
    (0x405a0c, "engine_load_correction_lower_cal", "injection_timing_reference_delta_minimum_limit",
     "Code: cm848_calculateTimingReferenceDeltaAdjustment clamps injection_timing_combustion_reference - main_injection_timing_for_air_handling from below to it (dump 0). e2m: C_CBO_Delta_SOI_Min 0x01171010 (CRANK_DEG_BTDC 0.1171875)."),
    (0x405a0e, "engine_load_correction_upper_cal", "injection_timing_reference_delta_maximum_limit",
     "Code: upper clamp of the timing delta (dump 0). e2m: C_CBO_Delta_SOI_Max 0x01171012."),
]
for a, o, nm, ev in CBO_S:
    G(a, o, nm, ev + " All six CBO windows are 0 in this calibration (and every CBO table is zero or 1.0), so the off-nominal compensation is inert on this ECM; the dump therefore confirms only the order.")
N("The e2m words C_CBO_Delta_MCF_Min / Max and C_CBO_Delta_EGR_Frac_Min / Max (0x01171004..0x0117100A) map to RAM 0x405a00-0x405a06 (dump -6400 / 6400 / 0 / 0): no row exists and xref_addr.py finds no access, so no rows are proposed; the matching RAM words 0x40a526-0x40a52c are never accessed either.")
CBO_T = [
    (0x405a10, "fuel_demand_mode2_correction_axis_cal", "charge_temperature_off_nominal_adjustment_axis",
     "Code: lookupTableInterpolation(charge_temperature_reference_delta_clamped, signed) in cm848_calculateOffNominalChargeTemperatureAdjustment; axis -150..+150 deg F (1/64), 7 points. e2m: C_CBO_Delta_Charge_Tmptr_Axis 0x01171200."),
    (0x405a20, "fuel_demand_mode2_correction_values_cal", "charge_temperature_off_nominal_adjustment_values",
     "Code: output of that lookup is charge_temperature_off_nominal_adjustment (7 values, all 0 in the dump). e2m: C_CBO_Charge_Tmptr_Adj_Table 0x01171300 (0.0078125)."),
    (0x405a30, "fuel_correction_load_axis_cal", "fuel_specific_nitrogen_oxide_ratio_by_intake_oxygen_fraction_axis",
     "Code: cm848_calculateOffNominalOxygenFractionAdjustment looks up the reference and the actual intake charge oxygen fraction (intake_charge_oxygen_fraction_reference / intake_charge_oxygen_fraction) here; axis 983..1900 = 0.12..0.232 of 8192, 10 points. e2m: C_CBO_Intake_Charge_O2Frac_Axis 0x01171600."),
    (0x405a46, "fuel_correction_load_values_cal", "fuel_specific_nitrogen_oxide_ratio_by_intake_oxygen_fraction_values",
     "Code: the looked-up values are fuel_specific_nitrogen_oxide_ratio_reference / _actual, whose Q13 quotient is oxygen_fraction_off_nominal_adjustment (all 8192 = 1.0 in the dump). e2m: C_CBO_fsNOx_Ratio_Table 0x01171700 (0.00012207)."),
    (0x405a5c, "engine_load_correction_axis_cal", "injection_timing_reference_adjustment_axis",
     "Code: cm848_applyOffNominalTimingAdjustment looks up off_nominal_composite_adjustment here (0..768 = 0..0.094 of 8192, 7 points). e2m: C_CBO_Composite_Adj_Axis 0x01171800."),
    (0x405a6c, "engine_load_correction_output_cal", "injection_timing_reference_adjustment_values",
     "Code: output is injection_timing_reference_adjustment, added to the timing reference (all 0 in the dump). e2m: C_CBO_SOI_Ref_Adj_Table 0x01171900 (CRANK_DEG_BTDC)."),
    (0x405a7c, "fuel_demand_correction_scale_axis_cal", "injection_timing_off_nominal_adjustment_axis",
     "Code: cm848_calculateTimingReferenceDeltaAdjustment looks up injection_timing_reference_delta_clamped here (0..51 counts, 7 points). e2m: C_CBO_Delta_SOI_Axis 0x01182A00."),
    (0x405a8c, "fuel_demand_correction_scale_output_cal", "injection_timing_off_nominal_adjustment_values",
     "Code: output is injection_timing_off_nominal_adjustment, which cm848_calculateOffNominalCompensation multiplies into the NOx target (composite x NOx target x adjustment / 546, so it acts as a scale although the e2m calls the table a SOI adjustment); all 0 in the dump. e2m: C_CBO_SOI_Adj_Table 0x01182B00."),
]
for a, o, nm, ev in CBO_T:
    G(a, o, nm, ev)
G(0x405a9e, "fuel_demand_offset_load_delta_correction_upper_limit", "injection_timing_torque_to_fuel_adjustment_maximum_limit",
  "Code: cm848_calculateNetCombustionTorque clamps the torque-to-fuel adjustment (injection_timing_torque_to_fuel_adjustment) from above to it (dump 0). e2m: C_CBP_SOI_Torque_Adj_Max 0x01178C02 (MM3S), the word after C_CBP_SOI_Torque_Adj_Min.")
NG(0x405a9c, "injection_timing_torque_to_fuel_adjustment_minimum_limit", "i16",
   "Code: cm848_calculateNetCombustionTorque loads it with lha (signed word, 1 read / 0 writes in the whole binary per xref_addr.py) as the lower clamp of injection_timing_torque_to_fuel_adjustment (dump 0). e2m: C_CBP_SOI_Torque_Adj_Min 0x01178C00 (MM3S), directly before C_CBP_SOI_Torque_Adj_Max = 0x405a9e.")
for a, o, nm in [(0x405aa0, "fuel_demand_offset_load_delta_gain_x_axis", "injection_timing_torque_to_fuel_gain_x_axis"),
                 (0x405ac8, "fuel_demand_offset_load_delta_gain_y_axis", "injection_timing_torque_to_fuel_gain_y_axis"),
                 (0x405aea, "fuel_demand_offset_load_delta_gain_grid", "injection_timing_torque_to_fuel_gain_grid")]:
    G(a, o, nm, "Code: cm848_calculateNetCombustionTorque looks up engine speed (x) against total_injection_quantity_for_air_handling (y) with signed flag 6 into injection_timing_torque_to_fuel_gain, so the table is named for its output word (the old name came from the word's former name). e2m: C_CBP_SOI_Torque_Adj_Speed_Axis 0x01178D00 / Fuel_Axis 0x01178E00 / Gain_Table 0x01178F00 (MM3S/degBTDC 0.015625).")

# ---------------------------------------------------------------- F. Bank 1 CBO chain functions
CHAIN = [
    (0x16a90, "cm848_calculateOffNominalOxygenFractionAdjustment",
     "Keeps the current name. Code: the function derives air_fuel_ratio_reference and intake_charge_oxygen_fraction_reference, looks both up in the fuel specific NOx ratio table and writes oxygen_fraction_off_nominal_adjustment (actual / reference ratio, Q13, capped 0x2000), the output the CBO chain uses; the earlier alternative cm848_calculateReferenceAirFuelRatioAndOxygenFraction names only the intermediates and is not adopted."),
    (0x16c40, "cm848_calculateOffNominalChargeTemperatureAdjustment",
     "Keeps the current name (it says the same as the proposed cm848_calculateChargeTemperatureAdjustment). Code: charge temperature reference minus intake temperature, clamped, then the adjustment table lookup; no manifold pressure is read."),
    (0x16cd4, "cm848_calculateTimingReferenceDeltaAdjustment",
     "Keeps the current name. Code: clamped timing reference minus main timing delta and its lookup into injection_timing_off_nominal_adjustment."),
    (0x16d6c, "cm848_applyOffNominalTimingAdjustment",
     "Keeps the current name (the proposed cm848_applyOffNominalInjectionTimingCompensation adds no information). Code: looks up injection_timing_reference_adjustment and adds it to the timing reference, clamped -1023..1024, with the off flag."),
    (0x16e90, "cm848_calculateOffNominalCompensation",
     "Keeps the current name (the other agent proposed the same name). Code: runs the oxygen fraction and charge temperature adjustments, clamps their product, then the two timing adjustments, and scales the NOx target by the composite and timing adjustments."),
    (0x16f9c, "cm848_runOffNominalCompensation",
     "Keeps the current name; the alternative cm848_storeCompensatedReferences describes only the caching at the end. Code: copies the fuel reference, runs cm848_calculateOffNominalCompensation and caches the mass charge flow, EGR fraction and gross-to-limit ratio references; it is the CBO entry point called by the combustion manager main loop."),
    (0x16ffc, "cm848_initializeOffNominalCompensationLookupCaches",
     "Keeps the current name. Code: sets the five lookup cache words 0x3fa6d2-0x3fa6da to 2 and no table pointers."),
]
for a, nm, ev in CHAIN:
    F(a, nm, nm, None, ev + " In the dump every CBO window and table is zero or 1.0, so the chain is inert on this ECM.")

# ---------------------------------------------------------------- G. engine_feature_enable_flags and enum
G(0x3fd5a6, "engine_feature_enable_flags", "combustion_override_and_estimation_enable_flags_cal",
  "Code: the binary tests these masks on it: 0x1 / 0x2 / 0x4 / 0x10 / 0x8 (EGR fraction, fuel, mass charge flow, main timing overrides and the timing increment enable, cm848_select*Command / cm848_applyCombustionTimingLimits), 0x20 / 0x40 / 0x80 / 0x100 (alpha, chi mode, chi and EGR-off overrides, cm848_selectChiAndAlpha), 0x200 / 0x400 (fuel reference and gross fuel overrides), 0x800 / 0x1000 (cm848_calculateOxygenFuelLimit equivalence ratio and fuel limit overrides), 0x2000 (cm848_phase_groupA_exponentialAverage), 0x4000 (cm848_processBoostProtectionMode and cm848_initBoostProtectionState), 0x8000 (cm848_calculateBoostTorqueOffset). e2m Word 6 at 0x01106B0C names bits 0-12 as user overrides of CBL / CBR / OFC outputs and bits 13-15 as the exhaust pressure (TPE), charge temperature and charge pressure estimate enables, so the name covers both groups. Code at bits 13-15 (read for this row): bit 13 clear sets boost_correction_mode_flags = 0x80 beside boost_pressure_synthetic_ema (cm848_phase_groupA_exponentialAverage; the e2m says exhaust pressure estimate, the code shows a synthetic boost pressure, not verified to be the same quantity); bit 14 clear sets injection_enable_mode_byte = 0x80, which cm848_calculatePressureSensorFiltered turns into the channel default for fuel_demand_boost_offset (cm848_processBoostProtectionMode); bit 15 clear forces boost_fuel_weight_factor to its neutral 0x80 (cm848_calculateBoostTorqueOffset). Each of the three visibly gates an estimate or substitute path. EEPROM-backed (0x3fd5a6 - 0x3fd482 = EEPROM 0x124, in 0x3fd482-0x3feec1, value 0 in the dump), hence _cal; engine_feature_enable_flags_cal at 0x3fd5ec (EEPROM 0x16a) is a different word, so the plain _cal name was not usable. Time-shared RAM: xref_addr.py lists 13 referencing functions, none below 0x7F60; the type is unchanged.")
N("Enum proposal (enums.csv columns enum_name,value,member_name,comment,size; size 2) for the chi source code, code-proved values: "
  "COMBUSTION_CHI_SOURCE,1,COMBUSTION_CHI_SOURCE_AMBIENT_AIR_DENSITY,base chi from the ambient (compressor inlet) air density protective chi table - cm848_selectChiSourceCode returns 1 when that chi is not smaller than the coolant one,2; "
  "COMBUSTION_CHI_SOURCE,3,COMBUSTION_CHI_SOURCE_COOLANT_TEMPERATURE,base chi from the coolant temperature protective chi table - cm848_selectChiSourceCode returns 3 when the density chi is smaller,2; "
  "COMBUSTION_CHI_SOURCE,10,COMBUSTION_CHI_SOURCE_EGR_OFF,fixed chi and level of the EGR-off calibration (combustion_egr_off_chi_hundredths / _paired_level) when EGR is requested off and no status-flag chi applies,2; "
  "COMBUSTION_CHI_SOURCE,12,COMBUSTION_CHI_SOURCE_USER_OVERRIDE_FULL,user override of chi and both map numbers - engine_feature_enable_flags bit 7 set and bit 6 set (e2m CBR_FULL_USER_OVERRIDE),2; "
  "COMBUSTION_CHI_SOURCE,13,COMBUSTION_CHI_SOURCE_USER_OVERRIDE_SINGLE_VALUE,user override with one whole chi that sets both map numbers - bit 7 set and bit 6 clear (e2m CBR_SINGLE_USER_OVERRIDE),2; "
  "Value 14 (chi and level from fuel_blend_step_a_cal 0x4059da / fuel_blend_step_a_threshold_cal 0x4059f0 when fuel_mode_status_flags bit 8, 0x10 or 0x200 is set; e2m CBR_PROTECTION_CHI) has no member name proposed because the trigger bits are not traced to one source (see the two uncertain rows). "
  "It types combustion_chi_source_code (0x40a4a4, values 1 / 3 / 10 / 12 / 13 / 14) and combustion_base_chi_source_code (0x40a4e4, only 1 / 3), both word rows, and the return of cm848_selectChiSourceCode (1 or 3); values 2, 4-9 and 11 never occur in this firmware. "
  "The e2m does not list the enumerators except the three names quoted; the member names above follow the code. The same words 0x40a4f0 (injection_quantity_combustion_reference_source_code) and governor_fuel_mode_working carry a second code space for the fuel reference: 23 reference override, 52 density maximum, 53 chi maximum, 54 temperature headroom cap, 55 gross fuel override, 58 oxygen limit; and the main timing source code (fuel_demand_mode_code at 0x40a2f2) gets 27 maximum limit / 28 minimum limit from cm848_applyCombustionTimingLimits - candidates for two further enums.")

# ---------------------------------------------------------------- H. mass flow words
G(0x40a895, "fuel_rate_rpm_factor", "fuel_mass_flow",
  "Code: fuelDemandProportionalCalculationSlowCycle40Coordinator writes engine speed x (total_injection_quantity_for_air_handling - DAT_0005c310) x 100 / (DAT_0005c312 x 471) (cap 32000) x 128 / 600, i.e. fuel quantity x speed (a flow); DAT_0005c312 = 7520 and DAT_0005c310 = 0 in the ROM give lb/min within 1.5 percent, in the 1/128 lb/min unit of the mass charge flow. It is the divisor of charge_fuel_ratio, air_fuel_ratio and air_fuel_ratio_reference ((1 - EGR fraction) x mass charge flow / flow), so it is the fuel mass flow. xref_addr.py: word (lhz / sth) at the odd address, 2 reads / 2 writes, so the type is right.")
G(0x40a893, "fuel_rate_rpm_factor_raw", "fuel_mass_flow_raw",
  "Code: the same writer stores the value before the x 128 / 600 scaling (about 600 per lb/min); cm848_calculateSensorEma reads it. xref_addr.py: word (lhz / sth) at the odd address, 1 read / 1 write.")
G(0x40bab8, "fuel_quantity_ema_filtered", "charge_mass_flow_filtered",
  "Code: cm848_loadBasedFuelAdjustment writes the EMA of engine speed x boost_pressure_rpm_scale_factor x map_fuel_correction_factor x multiplier / (intake temperature term x 0xa200), clamped between two calibrated limits: a speed-density flow of the intake charge. It is the divisor of the EGR fraction, the numerator of charge_fuel_ratio and the minuend of the fresh air flow (cm848_fuelDemandErrorCalculation). e2m: CBP_Charge_Mass / EGF block terms are per stroke; the flow itself has no e2m word.")
G(0x40baba, "fuel_quantity_ema", "egr_mass_flow_delayed_filtered",
  "Code: cm848_throttleBasedFuelCalculation writes the first-order filtered output of the circular-buffer delayed throttle_fuel_trim_t.final_trim; the same function divides it by the charge flow (<< 13) into throttle_fuel_trim_t.fuel_demand_final, the fresh air flow is charge minus it (cm848_fuelDemandErrorCalculation) and cm848_calculateCylinderOxygenMasses uses it per stroke as cylinder_egr_mass, so it is the EGR part of the charge flow, delayed for the transport time.")
SF("boost_pressure_state_t", "reserved_0c", "fresh_air_mass_flow_filtered",
   "Code (0x40a412, +0x0c): cm848_fuelDemandErrorCalculation writes the EMA of (charge_mass_flow_filtered - egr_mass_flow_delayed_filtered), floor 0, and cm848_calculateAirFuelRatioAndIntakeOxygenFraction divides it by the fuel flow into air_fuel_ratio: the fresh air mass flow. Current name reserved_0c.")
SF("throttle_fuel_trim_t", "fuel_demand_final", "egr_fraction_actual",
   "Code (0x40a3ec): cm848_throttleBasedFuelCalculation writes egr_mass_flow_delayed_filtered << 13 / charge_mass_flow_filtered (cap 0x2000, 0 when the charge flow is below 65): an EGR fraction in Q13; it feeds intake_charge_oxygen_fraction (0x76b - EGR fraction x ...), the actual counterpart of egr_fraction_combustion_reference. e2m: EGF_EGR_Fraction (compared with CBR_EGR_Frac_Ref by C_CBO_Delta_EGR_Frac_*).")
SF("throttle_fuel_trim_t", "efficiency_filtered", "residual_oxygen_fraction_delayed_filtered",
   "Code (0x40a3ea, +0): cm848_throttleBasedFuelCalculation pushes residual_oxygen_fraction_before_delay through a circular buffer (delay from throttle_conversion) and EMA-filters it; cylinder_oxygen_mass_in_exhaust_gas multiplies it with the EGR mass (the oxygen fraction of the recirculated exhaust). e2m: CBP_O2_Frac_Residual_Bef_Delay is the input.")

# ---------------------------------------------------------------- I. stage inputs and oxygen / headroom limits
G(0x40a604, "engine_load_input_value", "ambient_air_density",
  "Code: written only by cm848_calculateAmbientAirDensity: barometric pressure x 2936512 / ((ambient air temperature + 29440) x 128) (pressure over absolute temperature, 29440 = 460 deg F x 64), capped 65535 and slewed by engine_load_ramp_rate_upper / _lower. This settles the disagreement between the two earlier notes: it is the ambient air density, not the intake manifold density. Its readers use it as the density axis of the CBL mass charge flow limit, the density maximum fuel table and the ambient-density protective chi table. e2m: the three tables are C_CBL_MCF_Limit_Density_Axis, C_CBR_Fuel_Limit_Density_Axis and C_CBR_Inlet_Density_Axis (compressor inlet density, 6.1035e-5 lbm/ft3 per count; dump 1166 = 0.071 lbm/ft3).")
G(0x40a608, "fuel_demand_timing_input", "ambient_air_temperature_selected",
  "Code: the temperature in the denominator of cm848_calculateAmbientAirDensity ((value + 29440) x 128); written by cm848_selectAmbientAirTemperatureInput / cm848_initializeAmbientAirTemperatureInput, so it is the selected ambient air temperature (1/64 deg F). Other readers (cm848_calculateFuelFlowRate, cm848_processBoostProtectionMode, hpcr_fuelFinal_exponentialAverage) were not checked.")
N("fuel_demand_boost_input (0x40a61c) is left unrenamed: it is a coolant temperature (1/64 deg F, dump 2050 = 32 deg F) by the code and the e2m - cm848_mainLoop_step_3 copies WORD_0040bd88 (a generic sensor channel output word), or WORD_0040bdae = 12160 = 190 deg F when sensor_generic_fault_status bit 2 is set; the combustion manager uses it as the x of the coolant protective chi table (e2m C_CBR_Coolant_Tmptr_Axis, signed deg F 1/64) and compares it with combustion_egr_off_coolant_temperature_limit (e2m C_CBR_UHC_Coolant_Tmptr_Limit). But it has at least twelve users outside the combustion manager (cm848_checkProtectionEnableConditions, cm848_processSensorMonitoringLogic, cm848_updateEngineModeFromSensor, mpc555_processSensorValidation, fuel_boostCorrection_enableCheck_trimCalc, fuel_demand_boost_ema_compensate and others), and a second coolant copy exists (coolant_temperature_in_use 0x40b152, from cm848_selectSensorValuesInUse with its own substitutes), so a scoped name like coolant_temperature_for_combustion would over-claim; candidate coolant_temperature_substituted once the generic sensor channel at 0x40bd88 is identified.")
G(0x40a460, "fuel_demand_boost_offset", "intake_manifold_temperature_filtered",
  "Code: cm848_calculatePressureSensorFiltered writes it every pass (read for this row): the sensor channel 9 value after a lag correction and two first-order filters, the held value on a sensor fault or the channel default when failed (fuel_demand_phase_state 0 / 1 / 2); cm848_initializeIntakeTemperatureFilterStates seeds it from the channel at boot. The combustion manager uses it as the actual temperature in the charge temperature delta (cm848_calculateOffNominalChargeTemperatureAdjustment) and in the EGR-off intake temperature test, and cm848_auxiliaryControl_process subtracts it from its limit; dump 2602 = 40.7 deg F. e2m: Filtered_Intake_Temperature is the actual in C_CBO_Delta_Charge_Tmptr_*.")
G(0x40a168, "fuel_blend_coefficient", "combustion_alpha_input",
  "Code: cm848_selectChiAndAlpha converts it to alpha_percent with x 100 >> 14 (Q14 fraction) when the chi is below the clamp limit and EGR is not off; written by hpcr_calculateFuelTrimOutput and cm848_temperatureBasedFuelTrim (dump 0). cm848_processTorqueLimitState and cm848_calculateThermalLimitValue also read it and were not checked, so the name says only that it is the alpha input of the combustion reference. e2m: CBR_Alpha / Alpha_Base.")
G(0x40a492, "fuel_demand_limit_input", "injection_quantity_oxygen_limit",
  "Code: cm848_calculateOxygenFuelLimit (Bank 2, read for this row) writes it: the equivalence ratio limit (engine speed x total_injection_quantity_for_air_handling grid, or DAT_00406002 when engine_feature_enable_flags bit 0x800 is set) x an ambient pressure gain x cylinder_total_oxygen_mass x 2 / (injection_timing_period_cal << 11), capped 0x1700 (DAT_00406000 when bit 0x1000 is set), clamped between two calibrated limits: the fuel that the available oxygen allows. Readers: cm848_calculateCombustionFuelReference (cap, source 58, and the divisor of the gross-to-limit ratio) and cm848_calculateEffectiveFuelLimit. e2m: C_OFC_Fuel_Limit_LLim / ULim 0x0117910A / 08, C_OFC_Fuel_Limit_Override_Value 0x01179100 and T_OFC_Fuel_Limit_User_Override (bit 12 = the 0x1000 the code tests), T_OFC_Equiv_Ratio_User_Override (bit 11 = 0x800). Dump 2944 = its upper limit.")
G(0x406008, "fuel_demand_limit_input_upper_limit", "injection_quantity_oxygen_limit_maximum",
  "Code: the upper clamp in cm848_calculateOxygenFuelLimit (dump 2944 = 200 mm3). e2m: C_OFC_Fuel_Limit_ULim 0x01179108. Follows the injection_quantity_oxygen_limit rename.")
G(0x40600a, "fuel_demand_limit_input_lower_limit", "injection_quantity_oxygen_limit_minimum",
  "Code: the lower clamp in cm848_calculateOxygenFuelLimit (dump 736). e2m: C_OFC_Fuel_Limit_LLim 0x0117910A. Follows the injection_quantity_oxygen_limit rename.")
G(0x40a55a, "fuel_demand_load_axis_cap", "injection_quantity_temperature_headroom_cap",
  "Code: written only by cm848_auxiliaryControl_process (per-stroke quantity from the temperature headroom flow, clamped to DAT_00405d4c..DAT_00405d4a = 2944 / 2944 in the dump, so it is a constant 200 mm3 here) and read only by cm848_calculateCombustionFuelReference as the second cap of the fuel reference (source code 54). Neither word has an e2m counterpart (0x01177A0C / 0E are not in the e2m list).")
NG(0x40a55c, "fuel_flow_temperature_headroom_limit", "word",
   "Code: written only by cm848_auxiliaryControl_process (sth, 0 reads / 1 write per xref_addr.py): (limit - intake manifold temperature in deg F) x charge_mass_flow_filtered / the temperature rise model value, capped 51200; the next lines convert it with 0xcb9ca4 / (engine speed x number of cylinders) into the per-stroke cap injection_quantity_temperature_headroom_cap. The unit of the limit (a flow in the unit of the charge mass flow) is inferred from that conversion and the shared 0xc800 cap, not measured; dump 0.")
F(0x503b54, "cm848_auxiliaryControl_process", "cm848_calculateTemperatureHeadroomFuelCap",
  "Calculates the temperature headroom fuel cap injection_quantity_temperature_headroom_cap (fuel_demand_load_axis_cap): a calibrated temperature limit that falls as the filtered gas temperature estimate (boost_correction_block_mode_flag high word) rises, minus the intake manifold temperature (intake_manifold_temperature_filtered), times the charge mass flow over the temperature rise model value (boost_target_load_rpm_output) gives a fuel flow limit (fuel_flow_temperature_headroom_limit, 0x40a55c, capped 51200); it is converted to a per-stroke quantity with the cylinder count and clamped to a calibrated range. cm848_calculateCombustionFuelReference applies it as source code 54. (was cm848_auxiliaryControl_process)",
  "Code only: the two words it writes are the cap read by cm848_calculateCombustionFuelReference and the flow limit above; the inputs are the intake manifold temperature, the filtered gas temperature estimate and the charge mass flow, and DAT_00405ffc = 6 is C_CHP_Number_Of_Cylinders (0x01174F00). With min = max = 2944 in this calibration the cap is constant, so the dump shows nothing; the earlier uncertain verdict rested only on the missing e2m word, which is not needed.")
F(0x506cbc, "boost_targetPressure_loadRpm_calc", "cm848_calculateCombustionTemperatureRise",
  "Calculates the combustion temperature rise estimate: boost_target_load_rpm_output = main_injection_timing_for_air_handling x boost_target_load_gain / 1092 + engine speed and map_fuel_correction_factor terms + a constant, clamped 15000..53000; boost_target_fuel_normalized_ratio = that << 8 / charge_fuel_ratio (floor 128), capped 3000, which cm848_auxiliaryControl_exponentialAverage adds to twice the intake manifold temperature in deg F to form the filtered gas temperature estimate used by cm848_auxiliaryControl_process. It is not a boost pressure target. (was boost_targetPressure_loadRpm_calc)",
  "Code: no pressure is calculated or used as a target; the model value divided by the charge-to-fuel mass ratio is added in cm848_auxiliaryControl_exponentialAverage to 2 x intake temperature (deg F), which is only meaningful if it is a temperature increment in half degrees F, and cm848_auxiliaryControl_process then compares the filtered sum with a calibrated temperature limit. The half degree unit is inferred from that sum, not measured (engine off in the dump). The boost_target_* words belong to the air-handling owner and are not renamed here.")
N("Cluster note for the owner of the temperature estimate: cm848_auxiliaryControl_exponentialAverage (0x506e28) = the gas temperature estimate update (inhibited when engine speed < 1 rpm or charge_fuel_ratio < 128; boost_fuel_input_value = 2 x intake temperature in deg F + the temperature rise, EMA-filtered into the high word of boost_correction_block_mode_flag) - name proposal cm848_updateGasTemperatureEstimate. The words boost_target_load_rpm_output (0x40a682) = temperature rise model value and boost_target_fuel_normalized_ratio (0x40a67e) = temperature rise (half deg F) are the air-handling owner's.")

OFC = ("Code: cm848_calculateOxygenFuelLimit (the function behind injection_quantity_oxygen_limit) looks up %s. e2m: %s; the same "
       "function tests engine_feature_enable_flags bit 0x800 for the equivalence ratio override (T_OFC_Equiv_Ratio_User_Override) and "
       "0x1000 for the fuel limit override (T_OFC_Fuel_Limit_User_Override).")
G(0x40a574, "fuel_demand_rpm_limit_output", "oxygen_limit_equivalence_ratio",
  OFC % ("engine speed x total_injection_quantity_for_air_handling in fuel_demand_limit_scale_by_rpm_and_load_* into this word, "
         "replaced by DAT_00406002 (128 in the dump) when bit 0x800 is set; it multiplies the ambient pressure gain and "
         "cylinder_total_oxygen_mass into the fuel limit (Q7, 256 = 2.0 in the dump); its only user is that function",
         "C_OFC_Equiv_Ratio_Limit_Table 0x01179400 (UNITLESS 0.0078125 = 1/128) over C_OFC_Equiv_Ratio_Speed_Axis 0x01179300 / Fuel_Axis 0x0117C100, override C_OFC_Equiv_Ratio_Value 0x01179102"))
G(0x40600c, "fuel_demand_limit_scale_by_rpm_and_load_x_axis", "oxygen_limit_equivalence_ratio_x_axis",
  OFC % ("engine speed (x) against total_injection_quantity_for_air_handling (y) with the 19 x 16 grid, output oxygen_limit_equivalence_ratio",
         "C_OFC_Equiv_Ratio_Speed_Axis 0x01179300 / Fuel_Axis 0x0117C100 / Limit_Table 0x01179400 (RPM, MM3S, 1/128)"))
G(0x406034, "fuel_demand_limit_scale_by_rpm_and_load_y_axis", "oxygen_limit_equivalence_ratio_y_axis",
  OFC % ("the same grid, y = total_injection_quantity_for_air_handling", "C_OFC_Equiv_Ratio_Fuel_Axis 0x0117C100 (MM3S)"))
G(0x406056, "fuel_demand_limit_scale_by_rpm_and_load_grid", "oxygen_limit_equivalence_ratio_grid",
  OFC % ("the same grid, output oxygen_limit_equivalence_ratio", "C_OFC_Equiv_Ratio_Limit_Table 0x01179400 (UNITLESS 0.0078125)"))
G(0x4062b6, "fuel_demand_limit_scale_by_pressure_axis", "oxygen_limit_ambient_pressure_gain_axis",
  OFC % ("barometric_pressure_reference (x, 6 breakpoints) against the gain values; the gain is multiplied by DAT_00406006 and shifted right 11 (Q11)",
         "C_OFC_AAP_Gain_Axis 0x011ABD00 (IN_HG 0.0159, 'ambient pressure') / C_OFC_AAP_Gain_Table 0x011ABE00 ('Multiplier gain table used to adjust OFC_Fuel_Limit', 4.88e-4 = 1/2048)"))
G(0x4062c4, "fuel_demand_limit_scale_by_pressure_values", "oxygen_limit_ambient_pressure_gain_values",
  OFC % ("the gain values of that lookup (Q11, the code shifts the product right by 11)", "C_OFC_AAP_Gain_Table 0x011ABE00 (4.8828125E-4 = 1/2048)"))
G(0x3fa644, "fuel_demand_mode_code_prev_snapshot", "injection_timing_source_code_after_minimum_limit",
  "Code: written once in cm848_applyCombustionTimingLimits right after the minimum limit stage (28 when the minimum limit applied) with the running main timing source code; no other user (xref: 1 referencing function, none below 0x7F60), so it pairs with injection_timing_source_code_before_combustion_limits written at the start of the same function. Time-shared RAM; the row type is not changed.")

# ---------------------------------------------------------------- J. remaining notes
N("Leads that are informational or unresolved: (a) fuel_demand_min_threshold (0x40a5b4, 1024; x 2 is the minimum level in cm848_lookupProtectiveChi, written by fuel_demandMin_maxSelect_rateLimit in the humidity / altitude blend chain and averaged by fuel_demandTiming_rollingAverage_update) needs that Bank 2 chain read before a name; (b) fuel_mode_status_flags (0x40a5ee) holds cold start, sensor validity (cm848_updateSensorValidationFlags: 0x100 / 8 / 4 from fuel_demand_active_state_flag and others) and cylinder check bits (0x20 / 0x40 from fuel_injectionTiming_cylinderCheck_update); bit 8 of that word comes from cm848_updateSensorValidationFlags (DAT_0040a43c), bits 0x10 / 0x200 have no named writer (DAT_003fbd50 / DAT_003fbd54 are only initialised) and may come from the ROM-copied DAT_00406568 / DAT_0040656a (1024 in the dump); (c) fuel_demand_mode_code (0x40a2f2) and fuel_demand_mode_flags (0x40a2f4) are the main timing source code and increment flags (users: cm848_applyCombustionTimingLimits, cm848_setTimingIncrementFlags, cm848_calculateCombustionTimingReference, cm848_calculateMainInjectionTiming, cm848_processTorqueLimitState, cm848_storeFuelDemandPreviousValues); candidates injection_timing_main_source_code / injection_timing_increment_flags, not proposed until cm848_processTorqueLimitState is read; (d) boost_fuel_mode_active (0x40a668) has eleven users outside the combustion manager (cm848_calculateTurboBlendOutput, cm848_selectFuelTrimMode, the boost compensation functions ...) so it is not a combustion-only word; (e) fuel_demand_offset_correction (0x40b22a, 256) is already consistent with the fuel_demand_offset_correction_by_coolant_and_rpm_* tables and needs no change; (f) the pointer and cache words in 0x3fa634-0x3fa6da other than the 20 map pointers keep their names (the cache words are the cached axis offset arguments of the lookups).")
N("Review items for whoever applies this: (1) 0x3fd5a6 and the 20 map pointer words are in time-shared RAM; xref_addr.py found no user below 0x7F60 for any of them, and none of the proposals changes a type. (2) The twenty new_global map rows have no instruction-level access (pointer-reached); word[304] follows from the 19 x 16 axis pair, as the lookup_tables.py audit does for the base maps. (3) The structure_definitions.csv comments of combustion_reference_state_t (alpha_percent 'Fuel blend mode selector', egr_off_flag, ..., chi_hundredths 'Fuel blend weight factor (0-100%)') and combustion_chi_maximum_fuel_points_t (the 'protection threshold' comments) are still the old guesses; chi_hundredths is a chi in hundredths (100..400), not a percent weight, and the five chi_maximum_fuel_at_point_N fields are the maximum fuel of the chi curve at five engine speeds. (4) No name here contains hex digits; the e2m addresses are in the evidence only. (5) The sub-rows 0x40a496-0x40a49c of combustion_reference_state in global_variables.csv still read .reserved_02 .. .reserved_08. (6) The committed plate comments and row comments that call 0x40a604 the intake air density (for example cm848_limitMassChargeFlowReference) should say ambient air density once engine_load_input_value is renamed.")

with open(RES, "w") as f:
    for r in rows:
        f.write(json.dumps(r, ensure_ascii=False) + "\n")
print("rows written:", len(rows))

# ---------------------------------------------------------------- validation
names = {}
for r in csv.reader(open(OUT + "global_variables.csv")):
    if r and r[0].startswith("0x"):
        names.setdefault(r[1], []).append(r[0])
for r in csv.reader(open(OUT + "function_renames.csv")):
    if r and r[0].startswith("0x"):
        names.setdefault(r[1], []).append(r[0])
for r in csv.reader(open(OUT + "arrays.csv")):
    if r and r[0].startswith("0x"):
        names.setdefault(r[1], []).append(r[0])
cur_by_addr = {}
for r in csv.reader(open(OUT + "global_variables.csv")):
    if r and r[0].startswith("0x"):
        cur_by_addr[int(r[0], 16)] = r[1]
BAD = re.compile(r"(^|_)(temp|tmptr|qty|calc|corr|adj|ref|pos|val|cmd|flt|thr|mgr|cfg|ctrl|avg|amb|inj|cyl|ema|mcf|soi|nox|ofc|cbo|cbr|cbl|cbp|fsnox|pct|lim|sel|stat|param|thres|hys)(_|$)")
seen = {}
bad = 0
for r in rows:
    nm = r.get("new")
    if not nm or r["kind"] in ("note",):
        continue
    probs = []
    addr = int(r["address"], 16) if "address" in r else None
    if r["kind"] in ("global", "new_global"):
        if nm in names and not (nm == r.get("old") or addr in [int(x, 16) for x in names[nm]]):
            probs.append("exists in CSV at %s" % names[nm])
        in_eeprom = 0x3fd482 <= addr <= 0x3feec1
        if nm.endswith("_cal") != in_eeprom:
            probs.append("_cal rule (eeprom=%s)" % in_eeprom)
        if r["kind"] == "global" and r.get("old") != cur_by_addr.get(addr):
            probs.append("old name %s != current %s" % (r.get("old"), cur_by_addr.get(addr)))
    if r["kind"] == "function":
        if not nm.startswith("cm848_") and nm != r.get("old"):
            probs.append("function prefix")
        if nm in names and nm != r.get("old"):
            probs.append("exists in CSV")
    if r["kind"] != "struct_field" and nm in seen:
        probs.append("duplicate in file (%s)" % seen[nm])
    seen[nm] = r.get("address", r.get("struct"))
    if "0x" in nm or re.search(r"(^|_)protection(_|$)", nm):
        probs.append("hex or bare protection")
    if BAD.search(nm) and r["kind"] != "function":
        probs.append("abbreviation token")
    if probs:
        bad += 1
        print("PROBLEM", r["kind"], r.get("address", ""), nm, probs)
print("problems:", bad)

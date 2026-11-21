"""Round 9 stage B (label-only): the RE tables after 8C18 and the exhaust brake tables.
- After 8C18 (0x4082f4 +00..+98) the walk from 0x40838e lands on an existing word[N] row of exactly the walked size for
  0B9E..0BA9 (the closed-throttle relock / unlock 3rd / 4th and the 3rd gear lockup / unlock curves); 11.46 drops the T
  tables RE_Gear_Ratio / RE_Two_Three_Lag here (the gear ratio table sits after 8BBC). From 0x408476 the walk from 0BB5
  matches 0BB5..0BC6 (the 2nd gear relock / lockup / unlock and the overheat lockup / unlock curves); 0x4085de is
  0BCA / 0BCB RE_CT_Unlock_2nd (the code reads it as the 2nd gear closed-throttle unlock curve, next to the 3rd / 4th).
- The exhaust brake tables are e2m blocks 8CA6..8CC6 (column 5 1010..1030), in that order at 0x4080b0..0x4082bf
  (without 1020..1028) and 0x408606..0x408689 (1020..1025, the closed-throttle unlock copies). Every one matches the
  code's switch-12 branch it was read from (stage 9A named the first 14 by the code alone)."""


def t(block, rec, desc, extra=""):
    return f"e2m {block} {rec} ('{desc}')" + (f": {extra}" if extra else "")


GD = "cm848_determineCurrentGearAndLockupInhibit"
LS = "cm848_applyConverterLockupSchedule"
UC = "cm848_applyConverterUnlockConditions"
GLOBALS = [
    ("0x0040838e", "transmission_3rd_gear_closed_throttle_relock_throttle_axis", t("8C1B", "RE_CT_Relock_3rd_OSS_Axis", "Trans output shaft speed axis for 3rd gear relock curve", "walk 0B9E")),
    ("0x004083a2", "transmission_3rd_gear_closed_throttle_relock_throttle_values", t("8C1C", "RE_CT_Relock_3rd_Tbl", "Min TPS for TCC relock in 3rd gear vs OSS", GD)),
    ("0x004083b6", "transmission_4th_gear_closed_throttle_relock_throttle_axis", t("8C1D", "RE_CT_Relock_4th_OSS_Axis", "Trans output shaft speed axis for 4th gear relock curve")),
    ("0x004083ca", "transmission_4th_gear_closed_throttle_relock_throttle_values", t("8C1E", "RE_CT_Relock_4th_Tbl", "Min TPS for TCC relock in 4th gear vs OSS", GD)),
    ("0x004083de", "transmission_3rd_gear_closed_throttle_unlock_throttle_axis", t("8C1F", "RE_CT_Unlock_3rd_OSS_Axis", "Trans output shaft speed axis for 3rd gear unlock curve")),
    ("0x004083f2", "transmission_3rd_gear_closed_throttle_unlock_throttle_values", t("8C20", "RE_CT_Unlock_3rd_Tbl", "Max TPS for unlock in 3rd gear vs OSS", GD)),
    ("0x00408406", "transmission_4th_gear_closed_throttle_unlock_throttle_axis", t("8C21", "RE_CT_Unlock_4th_OSS_Axis", "Trans output shaft speed axis for 4th gear unlock table")),
    ("0x0040841a", "transmission_4th_gear_closed_throttle_unlock_throttle_values", t("8C22", "RE_CT_Unlock_4th_Tbl", "Max TPS for unlock in 4th gear vs OSS", GD)),
    ("0x0040842e", "transmission_3rd_gear_lockup_maximum_throttle_axis", t("8C23", "RE_Lockup_Curve_3_OSS_Axis", "Trans output shaft speed axis for 3rd gear lockup curve")),
    ("0x00408440", "transmission_3rd_gear_lockup_maximum_throttle_values", t("8C24", "RE_Lockup_Curve_3", "Max throttle for lockup in 3rd gear vs OSS", f"{LS}; cm848_selectGovernorPressureLockupBoost holds the lockup boost below it")),
    ("0x00408452", "transmission_3rd_gear_unlock_maximum_throttle_axis", t("8C25", "RE_Unlock_Curve_3_OSS_Axis", "Trans output shaft speed axis for 3rd gear unlock curve")),
    ("0x00408464", "transmission_3rd_gear_unlock_maximum_throttle_values", t("8C26", "RE_Unlock_Curve_3", "Max TPS for unlock vs OSS in 3rd gear", f"{LS} / {UC}; the lockup boost's exit curve")),
    ("0x00408476", "transmission_2nd_gear_closed_throttle_relock_throttle_axis", t("8C37", "RE_CT_Relock_2nd_OSS_Axis", "X-axis for 2nd gear relock table", "walk 0BB5")),
    ("0x0040848a", "transmission_2nd_gear_closed_throttle_relock_throttle_values", t("8C38", "RE_CT_Relock_2nd_Tbl", "2nd gear relock throttle threshold table", GD)),
    ("0x0040849e", "transmission_2nd_gear_lockup_maximum_throttle_axis", t("8C39", "RE_Lockup_Curve_2_OSS_Axis", "X-axis for 2nd gear lockup table")),
    ("0x004084b2", "transmission_2nd_gear_lockup_maximum_throttle_values", t("8C3A", "RE_Lockup_Curve_2", "2nd gear lockup throttle threshold table", LS)),
    ("0x004084c6", "transmission_2nd_gear_overheat_lockup_maximum_throttle_axis", t("8C3B", "RE_Ovr_Heat_Lockup_2_OSS_Axis", "X-axis for 2nd-gear lockup throttle threshold when hot")),
    ("0x004084da", "transmission_2nd_gear_overheat_lockup_maximum_throttle_values", t("8C3C", "RE_Ovr_Heat_Lockup_2", "Table for 2nd-gear lockup throttle threshold when hot", LS)),
    ("0x004084ee", "transmission_3rd_gear_overheat_lockup_maximum_throttle_axis", t("8C3D", "RE_Ovr_Heat_Lockup_3_OSS_Axis", "X-axis for 3rd gear lockup throttle threshold when hot")),
    ("0x00408502", "transmission_3rd_gear_overheat_lockup_maximum_throttle_values", t("8C3E", "RE_Ovr_Heat_Lockup_3", "Table for 3rd gear lockup throttle threshold when hot", LS)),
    ("0x00408516", "transmission_4th_gear_overheat_lockup_maximum_throttle_axis", t("8C3F", "RE_Ovr_Heat_Lockup_4_OSS_Axis", "X-axis for 4th gear lockup throttle threshold when hot")),
    ("0x0040852a", "transmission_4th_gear_overheat_lockup_maximum_throttle_values", t("8C40", "RE_Ovr_Heat_Lockup_4", "Table for 4th gear lockup throttle threshold when hot", LS)),
    ("0x0040853e", "transmission_2nd_gear_overheat_unlock_maximum_throttle_axis", t("8C41", "RE_Ovr_Heat_Unlock_2_OSS_Axis", "X-axis for 2nd gear unlock throttle threshold when hot")),
    ("0x00408552", "transmission_2nd_gear_overheat_unlock_maximum_throttle_values", t("8C42", "RE_Ovr_Heat_Unlock_2", "Table for 2nd gear unlock throttle threshold when hot", f"{LS} / {UC}")),
    ("0x00408566", "transmission_3rd_gear_overheat_unlock_maximum_throttle_axis", t("8C43", "RE_Ovr_Heat_Unlock_3_OSS_Axis", "X-axis for 3rd gear unlock throttle threshold when hot")),
    ("0x0040857a", "transmission_3rd_gear_overheat_unlock_maximum_throttle_values", t("8C44", "RE_Ovr_Heat_Unlock_3", "Table for 3rd gear unlock throttle threshold when hot", f"{LS} / {UC}")),
    ("0x0040858e", "transmission_4th_gear_overheat_unlock_maximum_throttle_axis", t("8C45", "RE_Ovr_Heat_Unlock_4_OSS_Axis", "X-axis for 4th gear unlock throttle threshold when hot")),
    ("0x004085a2", "transmission_4th_gear_overheat_unlock_maximum_throttle_values", t("8C46", "RE_Ovr_Heat_Unlock_4", "Table for 4th gear unlock throttle threshold when hot", f"{LS} / {UC}")),
    ("0x004085b6", "transmission_2nd_gear_unlock_maximum_throttle_axis", t("8C47", "RE_Unlock_Curve_2_OSS_Axis", "X-axis for 2nd-gear unlock throttle threshold")),
    ("0x004085ca", "transmission_2nd_gear_unlock_maximum_throttle_values", t("8C48", "RE_Unlock_Curve_2", "Table for 2nd-gear unlock throttle threshold", f"{LS} / {UC}")),
    ("0x004085de", "transmission_2nd_gear_closed_throttle_unlock_throttle_axis", t("8C4C", "RE_CT_Unlock_2nd_OSS_Axis", "Trans output shaft speed axis for 2nd gear unlock table", "after 0BC6 by the walk's order; the code reads it with the 3rd / 4th closed-throttle unlock curves")),
    ("0x004085f2", "transmission_2nd_gear_closed_throttle_unlock_throttle_values", t("8C4D", "RE_CT_Unlock_2nd_Tbl", "Max TPS for unlock in 2nd gear vs OSS", GD)),
    ("0x00408606", "transmission_2nd_gear_exhaust_brake_closed_throttle_unlock_throttle_axis", t("8CB6", "RE_CT_Unlock_2nd_Tbl_Exhaust_OSS_Axis", "Trans output shaft speed for 2nd gear unlock table e_brake active")),
    ("0x0040861c", "transmission_2nd_gear_exhaust_brake_closed_throttle_unlock_throttle_values", t("8CB7", "RE_CT_Unlock_2nd_Tbl_Exhaust", "Max TPS for unlock in 2nd gear vs OSS with e_brake active", f"{GD}, manual 2 / 1 in 2nd with switch 12 on")),
    ("0x00408632", "transmission_3rd_gear_exhaust_brake_closed_throttle_unlock_throttle_axis", t("8CB8", "RE_CT_Unlock_3rd_Tbl_Exhaust_OSS_Axis", "Trans output shaft speed for 3rd gear unlock curve e_brake active")),
    ("0x00408648", "transmission_3rd_gear_exhaust_brake_closed_throttle_unlock_throttle_values", t("8CB9", "RE_CT_Unlock_3rd_Tbl_Exhaust", "Max TPS for unlock in 3rd gear vs OSS with e_brake active", f"{GD}; also the exhaust brake relock threshold, read at the output speed minus converter_clutch_closed_throttle_relock_exhaust_brake_hysteresis")),
    ("0x0040865e", "transmission_4th_gear_exhaust_brake_closed_throttle_unlock_throttle_axis", t("8CBA", "RE_CT_Unlock_4th_Tbl_Exhaust_OSS_Axis", "Trans output shaft speed for 4th gear unlock table e_brake active")),
    ("0x00408674", "transmission_4th_gear_exhaust_brake_closed_throttle_unlock_throttle_values", t("8CBB", "RE_CT_Unlock_4th_Tbl_Exhaust", "Max TPS for unlock in 4th gear vs OSS with e_brake active", GD)),
    ("0x004081f8", "transmission_4th_gear_exhaust_brake_unlock_maximum_throttle_axis", t("8CB2", "RE_Unlock_Curve_4_Exhaust_Brake_OSS_Axis", "Trans output shaft speed for 4th gear unlock curve e_brake active")),
    ("0x0040820a", "transmission_4th_gear_exhaust_brake_unlock_maximum_throttle_values", t("8CB3", "RE_Unlock_Curve_4_Exhaust_Brake", "Max TPS for unlock vs OSS in 4th gear with e_brake active", f"{LS} / {UC} with switch 12 on")),
    ("0x0040821c", "transmission_cruise_exhaust_brake_unlock_maximum_throttle_axis", t("8CB4", "RE_Unlock_Curve_Cruise_Exhaust_Brake_OSS_Axis", "Trans output shaft speed axis for cruise unlock curve with e_brake active")),
    ("0x0040822e", "transmission_cruise_exhaust_brake_unlock_maximum_throttle_values", t("8CB5", "RE_Unlock_Curve_Cruise_Exhaust_Brake", "Max TPS for unlock vs OSS in cruise mode with e_brake active", f"{LS} / {UC} with switch 12 on")),
    ("0x00408240", "transmission_3rd_gear_exhaust_brake_lockup_maximum_throttle_axis", t("8CBF", "RE_Lockup_Curve_3_Exhaust_Brake_OSS_Axis", "Output shaft speed axis for 3rd gear lockup curve with ebrake active")),
    ("0x00408252", "transmission_3rd_gear_exhaust_brake_lockup_maximum_throttle_values", t("8CC0", "RE_Lockup_Curve_3_Exhaust_Brake", "Max throttle for lockup in 3rd gear vs OSS with ebrake active", f"{LS} with switch 12 on")),
    ("0x00408264", "transmission_3rd_gear_exhaust_brake_unlock_maximum_throttle_axis", t("8CC1", "RE_Unlock_Curve_3_Exhaust_Brake_OSS_Axis", "Output shaft speed axis for 3rd gear unlock curve with ebrake active")),
    ("0x00408276", "transmission_3rd_gear_exhaust_brake_unlock_maximum_throttle_values", t("8CC2", "RE_Unlock_Curve_3_Exhaust_Brake", "Max TPS for unlock vs OSS in 3rd gear with ebrake active", f"{LS} / {UC} with switch 12 on")),
    ("0x00408288", "transmission_anti_hunt_3_4_exhaust_brake_maximum_throttle_axis", t("8CC3", "RE_TPS_Max_3_4_Exhaust_OSS_Axis", "Output shaft speed axis for AH TPS max 3-4 curve with ebrake active")),
    ("0x00408296", "transmission_anti_hunt_3_4_exhaust_brake_maximum_throttle_values", t("8CC4", "RE_TPS_Max_3_4_Exhaust", "Lower boundary TPS for 3-4 antihunt, vs OSS with ebrake active", "cm848_selectGovernorPressureNormal loads transmission_anti_hunt_maximum_throttle_interpolated with it while switch 12 is on")),
    ("0x004082a4", "transmission_anti_hunt_3_4_exhaust_brake_minimum_throttle_axis", t("8CC5", "RE_TPS_Min_3_4_Exhaust_OSS_Axis", "Output shaft speed axis for AH TPS min 3-4 curve with ebrake active")),
    ("0x004082b2", "transmission_anti_hunt_3_4_exhaust_brake_minimum_throttle_values", t("8CC6", "RE_TPS_Min_3_4_Exhaust", "Upper boundary TPS for 3-4 antihunt, vs OSS with ebrake active", "loads transmission_anti_hunt_minimum_throttle_interpolated while switch 12 is on")),
    ("0x004082c0", "governor_pressure_exhaust_brake_curve_axis",
     "Output shaft speed axis of the exhaust brake governor pressure curve (no e2m record in the 11.45 file; 13 points like "
     "RE_Fuel_Economy_Curve)"),
    ("0x004082da", "governor_pressure_exhaust_brake_curve_values",
     "Governor pressure vs output shaft speed with the exhaust brake switch (12) on below "
     "governor_pressure_fuel_economy_maximum_throttle: cm848_selectGovernorPressureBaseCurve uses it instead of "
     "RE_Fuel_Economy_Curve, pressure state 0x18. No e2m record in the 11.45 file"),
    ("0x00407f22", "governor_pressure_manual_2nd_curve_axis",
     t("8C66", "RE_Manual_2nd_OSS_Axis", "Trans output shaft speed axis for manual 2nd gear curve",
       "column 5 0FDA; 11.46 places it after RE_WOT_Curve")),
    ("0x00407f34", "governor_pressure_manual_2nd_curve_values",
     t("8C67", "RE_Manual_2nd_Curve", "Gov press vs OSS in manual 2nd gear mode",
       "pressure state 0x16 with the lever in 1 or 2 (transmission_selected_gear 0x7e / 0x7f) in "
       "cm848_selectGovernorPressureBaseCurve, cm848_selectGovernorPressureCold and cm848_selectGovernorPressureCruise")),
]
FUNCTIONS = []

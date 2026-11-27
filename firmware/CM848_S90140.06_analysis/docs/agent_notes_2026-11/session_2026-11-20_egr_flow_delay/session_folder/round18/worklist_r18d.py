"""Round 18 stage D (label-only, after the review): one prefix rule for e2m 8085 and the main timing (task 046):
main_injection_timing* names the final value and what describes it (its copies, selection and source);
injection_timing_main_* (60 rows) names its inputs, components and limits. So stage B's two limit words move to
injection_timing_main_*, and the misfire timing limit's own table and cache (were injection_timing_demand_floor_*)
follow."""
GLOBALS = [
    ("0x0040aee8", "injection_timing_main_misfire_limit",
     "The misfire timing limit (e2m 8A3D +0 Misfire_Timing_Limit 'Output of the misfire timing limit table'): the main "
     "timing is not taken below it (source MAIN_INJECTION_TIMING_SOURCE_MISFIRE_LIMIT, e2m label 0B MISFIRE)"),
    ("0x00409e44", "injection_timing_main_extended_idle_minimum",
     "While low_speed_governor_extended_idle_active_flag is set the main timing is not taken below this (e2m 8085 +4 "
     "'Final_Timing max wins with this'; source label 17 EX_IDLE)"),
    ("0x0005c4f2", "injection_timing_main_misfire_limit_x_axis",
     "The x axis of the misfire timing limit table (injection_timing_main_misfire_limit)"),
    ("0x0005c500", "injection_timing_main_misfire_limit_y_axis", "The y axis of the misfire timing limit table"),
    ("0x0005c50e", "injection_timing_main_misfire_limit_grid", "The misfire timing limit table (6 x 6)"),
    ("0x003fafa4", "injection_timing_main_misfire_limit_cached_axis_offset",
     "Lookup cache (the x segment offset) of the misfire timing limit table"),
    ("0x003fafa6", "injection_timing_main_misfire_limit_cached_axis_offset_y",
     "The y segment offset of the misfire timing limit table's lookup cache"),
]
FUNCTIONS = []

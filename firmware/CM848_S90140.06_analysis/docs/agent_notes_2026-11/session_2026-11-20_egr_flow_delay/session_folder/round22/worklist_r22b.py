"""Round 22 stage B (label-only, the advisor's review): the two engine protection helpers read only as calls in stage
A, the second derate cache named by the repo's rule (the table base + _2, as engine_retarder_torque_cached_axis_offset
/ _2), and (apply_r22b2.py) two comments corrected."""
GLOBALS = [
    ("0x003fbd2a", "fault_derate_fuel_limit_by_engine_speed_cached_axis_offset_2",
     "The second lookup cache of fault_derate_fuel_limit_by_engine_speed: the five J1939 torque curve speed points "
     "(cm848_applyFaultDerateToJ1939TorqueCurveFuelings); preset to 2 by "
     "cm848_initializeFaultDerateJ1939TorqueCurvePriority. The first, at the engine speed, is "
     "fault_derate_fuel_limit_by_engine_speed_cached_axis_offset"),
]
FUNCTIONS = [
    ("0x00508f24", "cm848_isEngineProtectionInputMoreExtreme",
     "1 when the input is more extreme than the fault log's extreme value: above it with configuration flag 0x4 (the "
     "maximum is tracked), below it with 0x4 clear and 0x8 set (the minimum); 0 with neither"),
    ("0x00507dc0", "cm848_interpolateEngineProtectionSeverity",
     "The input's place between a minimum and a maximum threshold as a severity: (input - minimum) * 256 / (maximum - "
     "minimum), clamped to 0..0x100 (cm848_clampedDivisionWithBounds); 0 when the input is at the minimum"),
]

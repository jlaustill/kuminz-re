"""Round 22 stage A (label-only): the engine protection module's leftovers from round 21 - its boot / restart resets,
the shutdown override detector's words, and the fault derate's J1939 torque curve (PGN 65251) adjustment. None is a
CM550 twin. The two unnamed words (0x3fbd3a, 0x3fbd4e) and the configuration flags comment are apply_r22a2.py's."""
GLOBALS = [
    ("0x003fbd40", "engine_protection_override_switch_previous_state",
     "Logical switch 31 (switch_input_state_bits unwired_switch) at the last call of "
     "cm848_detectEngineProtectionShutdownOverrideRequest: the override request is its rising edge. It is not a J1939 "
     "state (the detector receives no J1939 message)"),
    ("0x0040a78e", "engine_protection_shutdown_override_pending_flag",
     "Set by cm848_detectEngineProtectionShutdownOverrideRequest on switch 31's rising edge while the override is "
     "enabled and a shutdown is approaching; cm848_latchEngineProtectionShutdownOverride turns it into the override "
     "request latch (engine_protection_shutdown_override_request_flag)"),
    ("0x003fbd28", "fault_derate_torque_curve_priority_bit",
     "1 << fault_derate_curve_priority_bit_position (e2m EPF_Torque_Curve_Priority): the fault derate's bit in "
     "j1939_pgn65251_speed_points_request_flags. While the derate is active it sets the bit, and it adjusts the J1939 "
     "torque curve only while no higher bit is set (or the clamp mask lets it)"),
    ("0x003fbd2a", "fault_derate_torque_curve_points_cached_axis_offset",
     "Lookup cache of fault_derate_fuel_limit_by_engine_speed for the five J1939 torque curve speed points "
     "(cm848_applyFaultDerateToJ1939TorqueCurveFuelings); preset to 2 by "
     "cm848_initializeFaultDerateJ1939TorqueCurvePriority. The table's cache for the engine speed itself is "
     "fault_derate_fuel_limit_by_engine_speed_cached_axis_offset"),
]
FUNCTIONS = [
    ("0x00508de8", "cm848_resetEngineProtectionShutdownState",
     "Boot / restart reset of the engine protection shutdown (cm848_applicationMain, "
     "cm848_restartApplicationWithoutReset, hpcr_initializeEngineProtection): clears the approaching and command "
     "flags, the latch, the previous engine speed, the shutdown time counts, the override request and lamp flags and "
     "the timer state, and records the shutdown channel at power-up (engine_protection_power_up_shutdown_channel). "
     "It is not part of an engine start sequence"),
    ("0x005082f0", "cm848_resetEngineProtectionPrecrankState",
     "Boot / restart reset of the pre-crank examination: clears engine_protection_precrank_shutdown_command_flag and "
     "the fuel temperature channel's precrank_error. It touches no sensor channel"),
    ("0x00508f0c", "cm848_resetEngineProtectionShutdownOverrideDetector",
     "Boot / init reset of cm848_detectEngineProtectionShutdownOverrideRequest's state: the switch's previous state "
     "and the pending request"),
    ("0x00507858", "cm848_applyFaultDerateToJ1939TorqueCurveFuelings",
     "Looks the fault derate fuel limit up at the five J1939 torque curve speed points and lowers the J1939 torque "
     "curve fuelings (PGN 65251) to them: always where the clamp mask (fault_derate_curve_clamp_priority_mask) has "
     "the highest requester's bit, else only while fault_derate_torque_curve_priority_bit is the highest request"),
    ("0x00507a20", "cm848_calculateFaultDerateJ1939TorqueCurveSpeedPoints",
     "While the fault derate is active: sets fault_derate_torque_curve_priority_bit in "
     "j1939_pgn65251_speed_points_request_flags and, if no higher request is set, computes the J1939 torque curve "
     "speed points (point 1 from the low speed governor reference speed less its droop correction, the next from the "
     "engine speed limit and its droop)"),
    ("0x00507c1c", "cm848_initializeFaultDerateJ1939TorqueCurvePriority",
     "Sets fault_derate_torque_curve_priority_bit from fault_derate_curve_priority_bit_position (e2m "
     "EPF_Torque_Curve_Priority) and presets fault_derate_torque_curve_points_cached_axis_offset to 2"),
]

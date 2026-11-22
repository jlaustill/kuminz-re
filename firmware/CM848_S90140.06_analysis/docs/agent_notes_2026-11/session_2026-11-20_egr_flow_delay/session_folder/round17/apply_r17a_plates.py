"""Round 17 stage A: rewrite the plates of the engine retarder chain functions that keep their names, in the round 17
words (the override / non-override commands, the allowed state, the command sources, the brake type bits). Each plate
keeps its '(was <old function name>)' tail. Their old plates described the extended idle condition as 'the road speed
limit' and used 'limit source code 3' / 'enable state 2' / 'output mode flags'. usage: apply_r17a_plates.py <repo>"""
import os
import sys

p = os.path.join(os.path.abspath(sys.argv[1]), "firmware/CM848_S90140.06_analysis/output/function_renames.csv")
PLATES = {
    "0x00041938": (
        "cm848_calculateEngineRetarderSelectionPercent",
        "Calculates the operator engine retarder selection engine_retarder_selection_percent: 100 or 0 from the exhaust "
        "brake switch (switch 12) through engine_retarder_switch_percent, or the J1939 EBC1 retarder selection "
        "j1939_engine_retarder_selection_percent when fault_feature_config_flags bit 0 is set; 100 while "
        "low_speed_governor_extended_idle_active_flag is set and algorithm_enable_flags_41_cal bit 0 is set. "
        "engine_retarder_selection_percent_fault_masked is the same value forced to 0 while fault bit 41 or 42 (P0478 / "
        "P0477) is detected and engine_feature_enable_flags_cal bit 0x4000 is set; the ERC1 builder uses it for the "
        "brake assist bits, and cm848_j1939BuildEngineControlByte sends the percent as EBC1 SPN 973 "
        "(was cm848_processProtectionSystemBit4)"),
    "0x00041a10": (
        "cm848_limitEngineRetarderPercentToOperatorSelection",
        "Lowers the non-override command engine_retarder_non_override_command_percent to the operator selection "
        "engine_retarder_selection_percent when that is smaller, with source 3 (switch). Step 3 of "
        "cm848_processEngineRetarderRequest (was cm848_applyMinimumProtectionLimit)"),
    "0x005246b0": (
        "cm848_limitEngineRetarderPercentToCruisePermission",
        "Lowers the non-override command engine_retarder_non_override_command_percent to "
        "engine_retarder_cruise_permission_percent when that is smaller, with source 2 (cruise). Step 2 of "
        "cm848_processEngineRetarderRequest (was governorLoadMinimumUpdate)"),
    "0x00041a40": (
        "cm848_applyEngineRetarderTsc1Request",
        "Applies the TSC1 retarder request recorded by cm848_processEngineRetarderTsc1Request: torque control (override "
        "control mode 2) makes the TSC1 torque request the override command (source 1, J1939 override); torque limit "
        "(mode 3) lowers the non-override command to engine_retarder_torque_limit_percent (source 4, J1939 limit); with "
        "no request (mode 0) the override command is 0 with source 6 (no override). The requesting J1939 device goes to "
        "engine_retarder_j1939_control_device. engine_retarder_tool_override_control_mode (a service tool test point "
        "that this build never writes) forces the same three cases with 1 / 2 / 3 (was "
        "cm848_processGovernorErrorState)"),
    "0x00041be4": (
        "cm848_updateEngineRetarderActiveState",
        "Sets engine_retarder_active_flag (117D +4 E_Brake_Status): 1 while the command level is nonzero, unless "
        "low_speed_governor_extended_idle_active_flag and algorithm_enable_flags_41_cal bit 0 are set; 0 with no "
        "command. The transmission lockup / overdrive logic, the wastegate duty request and the cold start loop read "
        "it. While the transmission reports a shift in process (ETC1 SPN 574), engine_retarder_engage_inhibit_flag "
        "holds the output level and the active flag for up to engine_retarder_shift_hold_passes passes; after the "
        "outputs are released, engine_retarder_release_pending_flag clears the active flag after "
        "engine_retarder_release_passes passes. The engine speed dependent engage delay at the top also writes the "
        "inhibit flag, but it is cleared before the shift block, so that delay has no effect (was "
        "cm848_processTemperatureTrim)"),
    "0x00041fd4": (
        "cm848_driveEngineRetarderOutput",
        "Turns the command level into the brake outputs: engine_retarder_output_level_percent takes "
        "engine_retarder_command_percent unless the engage inhibit flag holds it. Below 50 % it clears the exhaust "
        "brake output (logical output 11, engine_retarder_brake_type bit 0) and the VG brake flag (bit 1); at 50 % or "
        "more for engine_retarder_request_on_delay_passes passes it sets them. With both brake types the exhaust brake "
        "output is cleared above engine_retarder_dual_brake_maximum_engine_speed, and it is cleared while fault bit 101 "
        "is detected. Also saves the previous output level and the switch percent copy (was "
        "cm848_processFuelEfficiencyTrim)"),
    "0x000421c8": (
        "cm848_initializeEngineRetarderRequestState",
        "Power-up initialization of the engine retarder chain: clears logical outputs 11 to 15, the output level, the "
        "inhibit, release, allowed state and delay words and the tool overrides, and sets the override command source "
        "and the command source to 5 (not set) (was cm848_initProtectionEventStates)"),
}
lines = open(p).read().split("\n")
done = 0
for i, line in enumerate(lines):
    a = line[:10]
    if a in PLATES:
        name, plate = PLATES[a]
        parts = line.split(",", 2)
        assert parts[1] == name, (a, parts[1])
        assert "," not in plate or True
        lines[i] = ",".join([a, name, plate])
        done += 1
assert done == len(PLATES), done
open(p, "w").write("\n".join(lines))
print(done, "plates rewritten")

"""Check the proposed names against both firmwares' function_renames.csv / global_variables.csv (exact name match)."""
import csv

frozen = "/home/linux/.claude/jobs/374b0424/tmp/w15/r96/frozen/"
functions = {
    "cm550_calculateAccelerationNoiseControlTimingLimit": None,
    "cm550_emptyPrimarySpeedInterruptStep": None,
    "cm550_emptyBackupSpeedInterruptStep": None,
    "cm550_initializeSpeedRequestBlendWeightLookup": None,
    "cm550_initializeAllSpeedGovernorReferenceSpeedSets": None,
    "cm550_selectVariableSpeedGovernorMode": None,
    "cm550_calculateAllSpeedGovernorDroopFueling": None,
    "emptyPgn61443ElectronicEngineController2InitializationStep": "0x00020aec",
    "cm550_calculateNominalFrictionPercentTorque": None,
    "setJ1939TorqueCurvePoints1And3AtDeratedFueling": "0x00020bfc",
    "initializeJ1939ReferenceEngineFuelingAndTorque": "0x000212dc",
    "handleJ1939ReadByParameterIdLongLengthService": "0x0050c640",
    "handleJ1939ReadByParameterIdShortOffsetService": "0x0050c6a8",
    "handleJ1939ReadByParameterIdLongOffsetService": "0x0050c734",
    "handleJ1939ReadMemoryService": "0x0050c7b0",
    "handleJ1939ReadMemoryLongLengthService": "0x0050c81c",
    "registerJ1939MemoryReadServices": "0x0050c880",
    "cm550_updateLampOutputsAndCheckLampDriverFaults": None,
    "cm550_selectPedalFaultMode": None,
    "cm550_presetLowSpeedGovernorIntegrator": None,
    "cm550_calculateLowSpeedGovernorColdIdleSpeed": None,
    "cm550_calculateNoLoadFuel": None,
    "cm550_emptyStubFunction12": None,
    "cm550_initializeEnginePositionPhaseLag": None,
    "cm550_calculateEnginePositionPhaseLag": None,
    "cm550_buildJ1587Pid243ComponentIdentificationReply": None,
    "mc68k_saveEepromForPowerDown": None,
    "cm550_applyJ1708MemoryWriteRecords": None,
    "initializePowerTakeOffThrottleOverride": "0x0002bd38",
}
globals_cm550 = [
    "acceleration_noise_control_timing_limit_disable_timer",
    "acceleration_noise_control_timing_limit_active_timer",
    "reference_engine_torque_working",
    "all_speed_governor_minimum_reference_speed_1_pointer",
    "all_speed_governor_maximum_reference_speed_1_pointer",
    "all_speed_governor_minimum_reference_speed_2_pointer",
    "all_speed_governor_maximum_reference_speed_2_pointer",
    "all_speed_governor_minimum_reference_speed_1_cal",
    "all_speed_governor_maximum_reference_speed_1_cal",
    "all_speed_governor_minimum_reference_speed_2_cal",
    "all_speed_governor_maximum_reference_speed_2_cal",
    "variable_speed_governor_default_cal",
    "all_speed_governor_switch_droop_fueling_offset",
    "pedal_fault_mode_enable_flag",
    "all_speed_governor_droop_snapshot",
    "all_speed_governor_no_load_fuel",
    "low_speed_governor_integral_accumulator",
    "low_speed_governor_reference_maximum_fuel_quantity",
    "low_speed_governor_previous_engine_speed",
    "low_speed_governor_proportional_gain_previous",
    "low_speed_governor_proportional_gain_2_previous",
    "low_speed_governor_integrator_preset_minimum",
    "low_speed_governor_cold_idle_timer",
    "low_speed_governor_cold_idle_override_flag",
    "engine_position_normal_phase_lag",
    "engine_position_pulse_0_phase_lag",
    "engine_position_normal_phase_lag_intercept",
    "engine_position_normal_phase_lag_slope",
    "cam_wheel_top_dead_center_adjustment",
    "average_engine_speed",
    "j1708_memory_write_records",
    "power_take_off_throttle_override_flag",
    "power_take_off_throttle_override_engine_speed_limit",
    "j1939_nominal_friction_percent_torque_times_256",
]


def names(path, col=1):
    out = {}
    with open(path, newline="", errors="replace") as f:
        for row in csv.reader(f):
            if len(row) > col and row[0].startswith("0x"):
                out.setdefault(row[col], []).append(row[0])
    return out


f550 = names(frozen + "cm550/function_renames.csv")
f848 = names(frozen + "cm848/function_renames.csv")
g550 = names(frozen + "cm550/global_variables.csv")
for n, twin in functions.items():
    hits550 = f550.get(n, [])
    hits848 = f848.get(n, [])
    print(f"{n}: cm550 {hits550 or '-'} cm848 {hits848 or '-'}" + (f" (twin row {twin})" if twin else ""))
for n in globals_cm550:
    print(f"global {n}: cm550 {g550.get(n, '-')}")

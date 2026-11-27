#!/usr/bin/env python3
"""Check proposed names for collisions in both firmwares' CSVs (function and global rows)."""
import csv
import re

FROZEN = '/home/linux/.claude/jobs/374b0424/tmp/w15/r96/frozen/'
functions = {
    'cm550_calculateAccelerationNoiseControlTimingLimit', 'cm550_emptyStubFunction12',
    'cm550_emptyStubFunction13', 'cm550_initializeSpeedRequestBlendWeightLookup',
    'cm550_initializeAllSpeedGovernorReferenceSpeedSelection', 'cm550_selectVariableSpeedGovernorMode',
    'cm550_calculateAllSpeedGovernorDroopLineFueling', 'emptyPgn61443InitializationStep',
    'cm550_calculateNominalFrictionPercentTorque', 'setJ1939TorqueCurvePoints1And3AtDeratedFueling',
    'initializeJ1939ReferenceEngineFuelingAndTorque', 'handleJ1939ReadByParameterIdLongLengthService',
    'handleJ1939ReadByParameterIdShortOffsetService', 'handleJ1939ReadByParameterIdLongOffsetService',
    'handleJ1939ReadMemoryService', 'handleJ1939ReadMemoryLongLengthService',
    'registerJ1939MemoryReadServices', 'cm550_applyLampRequestsAndCheckOutputDriverFeedback',
    'cm550_selectAcceleratorPedalFaultMode', 'cm550_presetLowSpeedGovernorIntegrator',
    'cm550_applyLowSpeedGovernorColdIdleSpeed', 'cm550_calculateNoLoadFuel', 'cm550_emptyStubFunction14',
    'cm550_initializeEngineSpeedPhaseLags', 'cm550_calculateEngineSpeedPhaseLags',
    'cm550_buildJ1587Pid243ComponentIdentificationReply', 'mc68k_saveEepromForPowerDown',
    'cm550_applyJ1708MemoryWriteRecords', 'initializePowerTakeOffThrottleOverride',
}
globals_ = {
    'acceleration_noise_control_timing_limit_inhibit_timer',
    'all_speed_governor_minimum_reference_speed_1_pointer', 'all_speed_governor_maximum_reference_speed_1_pointer',
    'all_speed_governor_minimum_reference_speed_2_pointer', 'all_speed_governor_maximum_reference_speed_2_pointer',
    'all_speed_governor_minimum_reference_speed_1_cal', 'all_speed_governor_maximum_reference_speed_1_cal',
    'all_speed_governor_minimum_reference_speed_2_cal', 'all_speed_governor_maximum_reference_speed_2_cal',
    'pedal_fault_mode_enable_flag', 'variable_speed_governor_selected_flag', 'variable_speed_governor_default_cal',
    'all_speed_governor_switch_droop_fueling_offset', 'all_speed_governor_droop_snapshot',
    'all_speed_governor_no_load_fuel', 'j1939_nominal_friction_percent_torque_times_256',
    'j1939_reference_engine_fueling', 'reference_engine_torque_working',
    'low_speed_governor_integrator_preset_minimum', 'low_speed_governor_integral_accumulator',
    'low_speed_governor_reference_maximum_fuel_quantity', 'low_speed_governor_cold_idle_reference_speed',
    'low_speed_governor_cold_idle_timer', 'low_speed_governor_cold_idle_override_flag',
    'engine_speed_phase_lag', 'engine_speed_pulse_0_phase_lag', 'j1708_memory_write_records',
    'power_take_off_throttle_override_flag', 'power_take_off_throttle_override_engine_speed_limit',
}


def names_in(path, column):
    out = {}
    with open(path, encoding='utf-8', errors='replace') as f:
        for row in csv.reader(f):
            if not row or row[0].startswith('#') or len(row) <= column:
                continue
            out.setdefault(row[column], []).append(row[0])
    return out


for fw in ('cm550', 'cm848'):
    fn = names_in(FROZEN + fw + '/function_renames.csv', 1)
    gv = names_in(FROZEN + fw + '/global_variables.csv', 1)
    for n in sorted(functions):
        if n in fn:
            print(fw, 'FUNCTION exists:', n, fn[n])
        if n in gv:
            print(fw, 'function name used as GLOBAL:', n, gv[n])
    for n in sorted(globals_):
        if n in gv:
            print(fw, 'GLOBAL exists:', n, gv[n])
print('done')

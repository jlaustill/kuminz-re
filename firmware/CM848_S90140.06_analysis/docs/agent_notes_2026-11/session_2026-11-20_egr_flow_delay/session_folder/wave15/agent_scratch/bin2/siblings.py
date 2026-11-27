import glob
import json
import os

SIB = {
    # low speed governor 1065 / 10ED / 10EC
    '0x0040ae96': 'governor_speed_weight_a', '0x0040ae98': 'governor_speed_weight_b', '0x0040ae9c': 'governor_speed_error_derivative',
    '0x0040ae9e': 'governor_speed_setpoint_integrated', '0x0040aea0': 'governor_speed_pid_output_working',
    '0x0040aea2': 'governor_speed_reference_computed', '0x0040aea8': 'governor_speed_pid_gain', '0x0040aeaa': 'governor_speed_debounce_b',
    '0x0040aeac': 'governor_mode_active_flag', '0x003faf48': 'governor_fuel_demand_correction_accumulator',
    '0x0040ae76': 'governor_speed_setpoint_raw', '0x0040ae78': 'governor_d_gain_from_table', '0x0040ae7a': 'governor_p_gain_from_table',
    '0x0040ae8a': 'governor_j1939_gain_extra_working', '0x0040ae82': 'governor_j1939_speed_target', '0x0040ae84': 'governor_j1939_d_gain_stored',
    '0x0040ae86': 'governor_j1939_p_gain_stored', '0x0040ae88': 'governor_j1939_i_gain_stored',
    '0x004070e8': 'governor_j1939_d_gain_default_cal', '0x004070ea': 'governor_j1939_p_gain_default_cal', '0x004070ec': 'governor_j1939_i_gain_default_cal',
    # engine protection
    '0x003fbd2c': 'governor_faultDerate_task_index', '0x003fbd3e': 'governor_faultDerate_peak_value', '0x003fdfb8': 'governor_faultDerate_active_channel',
    '0x003fdfba': 'governor_faultDerate_consecutive_count', '0x003fbd28': 'governor_faultDerate_channel_bit',
    '0x003fbd2a': 'governor_faultDerate_lookup_interp_state', '0x003fbd36': 'governor_faultDerate_prev_rpm', '0x003fbd38': 'governor_faultDerate_latch',
    '0x003fbd3c': 'governor_faultDerate_engine_start_flag', '0x003fdfbc': 'governor_faultDerate_total_event_count',
    '0x0040a78e': 'governor_derate_j1939_trigger_pending',
    # supervisor chip
    '0x0040a040': 'j1939_timer_period_factor_a', '0x0040a043': 'j1939_timer_config_byte_c',
    # injector driver
    '0x004090aa': 'mios_pwm16_period_microseconds_ref', '0x004090ae': 'mios_pwm17_period_microseconds_ref',
    '0x004090b8': 'mios_pwm18_period_microseconds_ref', '0x004090ba': 'mios_pwm19_period_microseconds_ref', '0x004090b2': 'tpu_ch14_period_base',
    # priorities / asg / wastegate
    '0x004071de': 'fuel_demand_override_active_min', '0x0005c950': 'system_speed_limit_working_minimum',
    '0x00409eda': 'fuel_pressure_sensor_plausibility_maximum_governor_output',
    '0x003fd7de': 'wastegate_duty_first_error_term_limit_enable_flag_cal', '0x003fd7e4': 'wastegate_duty_altitude_adjustment_enable_cal',
}
found = {}
for p in sorted(glob.glob('/home/linux/.claude/jobs/374b0424/tmp/w15/results/result_W15_bin*.jsonl')):
    b = os.path.basename(p)
    if b.endswith('bin2.jsonl'):
        continue
    for ln in open(p):
        ln = ln.strip()
        if not ln.startswith('{'):
            continue
        try:
            j = json.loads(ln)
        except Exception:
            continue
        a = j.get('address', '')
        if a in SIB:
            found.setdefault(a, []).append((b[-11:-6], j.get('verdict'), j.get('new') or ''))
for a, n in SIB.items():
    print(a, n, '->', found.get(a, 'in no other bin so far'))

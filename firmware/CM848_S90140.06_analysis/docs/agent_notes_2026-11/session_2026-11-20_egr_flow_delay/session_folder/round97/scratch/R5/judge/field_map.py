"""Map each listed row of family_R5.txt that falls in a table to table[n].field and print it."""
CONFIG = ['configuration_flags', 'fueling_derate_start_duration', 'engine_speed_derate_start_duration', 'fueling_ramp_rate',
          'engine_speed_ramp_rate', 'fueling_minimum_threshold', 'fueling_maximum_threshold',
          'engine_speed_lower_limit_threshold', 'fueling_shutdown_duration_threshold',
          'engine_speed_shutdown_duration_threshold', 'shutdown_delay', 'start_monitor_engine_speed', 'start_monitor_time',
          'fueling_fault_index', 'engine_speed_fault_index', 'shutdown_warning_time', 'fueling_shutdown_severity_threshold',
          'engine_speed_shutdown_severity_threshold']
HISTORY = {0: 'fueling_severity_index', 2: 'engine_speed_severity_index', 4: 'fueling_restart_severity_index',
           6: 'engine_speed_restart_severity_index', 8: 'input_extremity', 0xa: 'input_extremity_time',
           0xe: 'fueling_fault_elapsed_time', 0x12: 'engine_speed_fault_elapsed_time', 0x16: 'fueling_fault_log_flag',
           0x18: 'fueling_fault_log_index', 0x1a: 'engine_speed_fault_log_flag', 0x1c: 'engine_speed_fault_log_index'}
CHANNEL = ['coolant level', 'coolant temperature', 'intake manifold temperature', 'oil pressure', 'water in fuel',
           'boost pressure', 'engine sync fuel pressure', 'fuel temperature', 'ambient air pressure']
for line in open('/home/linux/.claude/jobs/374b0424/tmp/w15/r97/family_R5.txt'):
    if not line.strip():
        continue
    a = int(line.split()[0], 16)
    if 0x807032 <= a < 0x807176:
        n, o = divmod(a - 0x807032, 36)
        print(f"0x{a:x} configuration_table[{n}].{CONFIG[o // 2]} ({CHANNEL[n]}, +0x{o:x})")
    elif 0x8057c0 <= a < 0x8058ce:
        n, o = divmod(a - 0x8057c0, 30)
        print(f"0x{a:x} history_table[{n}].{HISTORY.get(o, '?')} ({CHANNEL[n]}, +0x{o:x})")
    else:
        print(f"0x{a:x} (outside the tables) {line.split()[1]}")

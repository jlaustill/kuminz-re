import csv
rows = []
with open('/home/linux/.claude/jobs/374b0424/tmp/w15/r97/frozen/cm550/global_variables.csv') as f:
    for line in f:
        if line.startswith('#') or line.startswith('address'):
            continue
        p = next(csv.reader([line]))
        try:
            a = int(p[0], 16)
        except ValueError:
            continue
        rows.append((a, p[1], p[2]))
rows.sort()
tables = [
    ('engine_protection_channel_configuration_table', 0x807032, 36, 9,
     ['configuration_flags', 'fueling_derate_start_duration', 'engine_speed_derate_start_duration',
      'fueling_ramp_rate', 'engine_speed_ramp_rate', 'fueling_minimum_threshold',
      'fueling_maximum_threshold', 'engine_speed_lower_limit_threshold',
      'fueling_shutdown_duration_threshold', 'engine_speed_shutdown_duration_threshold',
      'shutdown_delay', 'start_monitor_engine_speed', 'start_monitor_time', 'fueling_fault_index',
      'engine_speed_fault_index', 'shutdown_warning_time', 'fueling_shutdown_severity_threshold',
      'engine_speed_shutdown_severity_threshold'],
     [0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34]),
    ('engine_protection_channel_state_table', 0x80d0dc, 46, 9,
     ['input_pointer', 'input_mask', 'fueling_duration', 'engine_speed_duration',
      'minimum_threshold_pointer', 'maximum_threshold_pointer', 'engine_speed_lower_limit_pointer',
      'errors_allowed', 'precrank_error', 'fueling_shutdown_time_count',
      'engine_speed_shutdown_time_count', 'fueling_start_warning_time',
      'engine_speed_start_warning_time', 'errors_allowed_timer', 'errors_allowed_timer_running',
      'fueling_fault_log_pointer', 'engine_speed_fault_log_pointer'],
     [0, 4, 6, 8, 10, 14, 18, 22, 24, 26, 28, 30, 32, 34, 36, 38, 42]),
    ('engine_protection_channel_history_table', 0x8057c0, 30, 9,
     ['fueling_severity_index', 'engine_speed_severity_index', 'fueling_restart_severity_index',
      'engine_speed_restart_severity_index', 'input_extremity', 'input_extremity_time',
      'fueling_fault_elapsed_time', 'engine_speed_fault_elapsed_time', 'fueling_fault_log_flag',
      'fueling_fault_log_index', 'engine_speed_fault_log_flag', 'engine_speed_fault_log_index'],
     [0, 2, 4, 6, 8, 10, 14, 18, 22, 24, 26, 28]),
]
for name, base, stride, count, fields, offs in tables:
    end = base + stride * count
    inside = [r for r in rows if base <= r[0] < end]
    print('== %s 0x%x-0x%x: %d flat rows' % (name, base, end - 1, len(inside)))
    for a, n, t in inside:
        idx, off = divmod(a - base, stride)
        fld = '?'
        for f, o in zip(fields, offs):
            if o == off:
                fld = f
        if fld == '?':
            # inside a field (odd half of a dword)
            for f, o in zip(fields, offs):
                if o < off:
                    fld = f + '+%d' % (off - o)
        print('  0x%x %-75s %-10s -> [%d].%s' % (a, n, t, idx, fld))
inside = [r for r in rows if 0x805562 <= r[0] < 0x8057be]
print('== fault logs 0x805562-0x8057bd: %d flat rows' % len(inside))
for a, n, t in inside:
    print('  0x%x %s %s' % (a, n, t))

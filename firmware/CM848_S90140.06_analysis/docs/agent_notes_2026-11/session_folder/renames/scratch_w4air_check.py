import csv
import re
import sys

OUT = sys.argv[1]
old = ['cm848_calculateProtectionOutputDemand', 'cm848_dispatchProtectionOutputMode', r'operating_mode_flags(?!_cal)',
       'protection_fuel_output_idle_cal', 'cm848_processProtectionVoltageOffset', 'cm848_turboCompensationWrapper',
       'DAT_00064430', 'engine_protection_batteryLoad_check', 'hpcr_throttlePositionDiagnostic', 'DAT_003fd270',
       'DAT_00409fe0', 'DAT_00409fe4', 'boost_pressure_fuel_working', 'DAT_0040bd0a', 'battery_voltage_filter_coeff_cal',
       'DAT_0006442a', 'DAT_0006442c', 'DAT_0006442e', 'DAT_00064438', 'DAT_0040b9e6']
pat = re.compile('|'.join(old))


def strip_was(text):
    return re.sub(r'\(was [^)]*\)', '', text, flags=re.I)


stale = []
for fn in ['function_renames.csv', 'global_variables.csv']:
    with open(OUT + '/' + fn, newline='') as f:
        for r in csv.reader(f):
            if len(r) > 2 and r[0].startswith('0x'):
                c = strip_was(','.join(r[3:]) if fn == 'global_variables.csv' else ','.join(r[2:]))
                m = pat.search(c)
                if m:
                    stale.append((fn, r[0], r[1], m.group(0)))
print('stale references (outside a was-tail):', len(stale))
for s in stale[:25]:
    print(s)

# rows for names I want to inspect
want = ['sensor_channel0_ram', 'sensor_channel0_interp_state', 'sensor_channel0_filter_state', 'sensor_channel3_ram',
        'wastegate_duty_ceiling_engine_speed_axis', 'governor_base_rpm_output_cal', 'governor_trim_rpm_axis_cal',
        'governor_trim_output_cal', 'cold_start_feature_flags', 'operating_mode_flags_cal']
rows = {}
with open(OUT + '/global_variables.csv', newline='') as f:
    for r in csv.reader(f):
        if len(r) > 2 and r[0].startswith('0x'):
            rows[r[1]] = r
for n in want:
    r = rows.get(n)
    print(n, '->', (r[0], r[2], (r[3] if len(r) > 3 else '')[:200]) if r else 'no global row')
with open(OUT + '/arrays.csv', newline='') as f:
    for r in csv.reader(f):
        if r and any(x in ','.join(r) for x in ['wastegate_duty_ceiling_engine_speed_axis', 'governor_base_rpm_output_cal',
                                                  'governor_trim_rpm_axis_cal', 'governor_trim_output_cal']):
            print('arrays.csv:', ','.join(r)[:200])

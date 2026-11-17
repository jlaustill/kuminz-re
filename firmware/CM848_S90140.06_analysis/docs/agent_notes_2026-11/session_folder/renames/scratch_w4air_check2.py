import csv
import glob
import re
import sys
import json

ROOT = sys.argv[1]
OUT = ROOT + '/firmware/CM848_S90140.06_analysis/output'
CM550 = ROOT + '/firmware/CM550_J90350.00_analysis/output'
RES = sys.argv[2]
ram = open(ROOT + '/firmware/CM848_S90140.06_analysis/originals/cm848_ram.bin', 'rb').read()
BASE = 0x3FA000

rows = {}
byaddr = {}
with open(OUT + '/global_variables.csv', newline='') as f:
    for r in csv.reader(f):
        if r and r[0].startswith('0x') and len(r) > 2:
            rows[r[1]] = r
            byaddr[int(r[0], 16)] = r


def val(a, w=2, signed=False):
    o = a - BASE
    if o < 0 or o + w > len(ram):
        return None
    return int.from_bytes(ram[o:o + w], 'big', signed=signed)


print('--- PID words in the dump (item 3)')
for n in ['governor_speed_p_gain_b_working', 'governor_proportional_gain_working', 'governor_speed_i_gain_b_working',
          'governor_fuel_bias_working', 'governor_integral_limit_working', 'governor_derivative_gain_working',
          'governor_speed_raw_input', 'governor_speed_filtered', 'governor_speed_error_a', 'governor_speed_p_term',
          'governor_speed_i_term', 'governor_fuel_integral_b', 'governor_fuel_integral_b_scaled', 'governor_derivative_term',
          'governor_output_prev_working', 'governor_output_prev_snapshot', 'governor_rpm_monitored', 'governor_speed_proportional_input',
          'throttle_speed_rate_lower', 'throttle_speed_rate_current', 'throttle_speed_rate_upper']:
    r = rows.get(n)
    if not r:
        print(n, 'MISSING')
        continue
    t = r[2]
    w = 4 if t in ('dword', 'u32', 'i32') else 1 if t in ('byte', 'u8', 'i8') else 2
    a = int(r[0], 16)
    print(f'{r[0]} {n:40s} {t:8s} unsigned={val(a, w)} signed={val(a, w, True)}')

print('--- stale references: rows at the cited DAT addresses (item 2)')
for a in [0x64430, 0x6442a, 0x6442c, 0x6442e, 0x64438, 0x3fd270, 0x409fe0, 0x409fe4, 0x40b9e6, 0x40bd0a, 0x64428]:
    r = byaddr.get(a)
    print(hex(a), '->', (r[1], r[2], (r[3] if len(r) > 3 else '')[:120]) if r else 'no row')
print('--- the comments that cite them')
pat = re.compile(r'DAT_00064430|DAT_0006442a|DAT_0006442e|DAT_003fd270|DAT_00409fe4|DAT_0040b9e6|DAT_0040bd0a')
for fn in ['function_renames.csv', 'global_variables.csv']:
    with open(OUT + '/' + fn, newline='') as f:
        for r in csv.reader(f):
            if r and r[0].startswith('0x') and len(r) > 2:
                txt = ','.join(r[3:]) if fn == 'global_variables.csv' else ','.join(r[2:])
                txt2 = re.sub(r'\(was [^)]*\)', '', txt)
                for m in pat.finditer(txt2):
                    s = max(0, m.start() - 90)
                    print(fn, r[0], r[1], '...', txt2[s:m.end() + 60].replace('\n', ' '))
                    break

print('--- dotted sub-rows of the two sensor state instances (item 6)')
for n in ['sensor_channel0_ram', 'sensor_channel3_ram']:
    subs = [k for k in rows if k.startswith(n + '.') or k.startswith(n + '_')]
    print(n, subs)

print('--- cross-firmware check of all old names (item 5)')
old_names = []
for l in open(RES):
    r = json.loads(l)
    if r.get('old'):
        old_names.append(r['old'])
files = [CM550 + '/function_renames.csv', CM550 + '/global_variables.csv', CM550 + '/arrays.csv',
         ROOT + '/docs/cross_firmware_variable_map.csv', ROOT + '/firmware/cross_firmware_matches.csv']
texts = {}
for fp in files:
    try:
        texts[fp] = open(fp, errors='replace').read()
    except OSError as e:
        print('cannot read', fp, e)
hits = []
for n in old_names:
    for fp, t in texts.items():
        if re.search(r'(?<![A-Za-z0-9_])' + re.escape(n) + r'(?![A-Za-z0-9_])', t):
            hits.append((n, fp.split('/')[-1]))
print('old names checked:', len(old_names), 'files read:', len(texts), 'hits:', hits)

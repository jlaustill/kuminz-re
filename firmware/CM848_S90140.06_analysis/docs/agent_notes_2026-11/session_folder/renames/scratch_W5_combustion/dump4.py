import sys, csv, re
sys.path.insert(0, '/home/linux/.claude/jobs/d55ae3c6/tmp/renames/scratch_W5_combustion')
from peek import *
OUT = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-typing-arrays/firmware/CM848_S90140.06_analysis/output/'
rows = {}
with open(OUT + 'global_variables.csv') as f:
    for line in f:
        if line.startswith('#') or not line.strip():
            continue
        p = line.rstrip('\n').split(',', 3)
        try:
            a = int(p[0], 16)
        except ValueError:
            continue
        rows.setdefault(a, []).append(p)
def show(a):
    for p in rows.get(a, []):
        print('  ', p[0], p[1], p[2], '|', (p[3] if len(p) > 3 else '')[:120])
print('== pointer words / names')
for nm in ('fuel_quantity_table_a_pointer', 'fuel_demand_limit_table_a_pointer', 'fuel_demand_mode3_load_axis_offset1',
           'fuel_demand_mode2_load_axis_offset1', 'fuel_demand_mode1_load_axis_offset1', 'fuel_demand_mode1_interp_state',
           'fuel_demand_blend_tables_interp_state', 'fuel_map_interpolation_state'):
    for a, ps in rows.items():
        for p in ps:
            if p[1] == nm:
                print('  ', p[0], p[1], p[2])
print('== 0x40bd88 / 0x40bdae / 0x40bd80 / 0x40bd84')
for a in (0x40bd80, 0x40bd84, 0x40bd88, 0x40bdae, 0x40bd86):
    show(a)
print('== fuel to torque table (protection_rpm_correction_*)')
for nm in ('protection_rpm_correction_axis_cal', 'protection_rpm_correction_ystart_cal', 'protection_rpm_correction_yend_cal'):
    for a, ps in rows.items():
        for p in ps:
            if p[1] == nm:
                hdr = w(a)
                n = max(1, hdr // 2) if hdr < 400 else 304
                t = table(a + 2, hdr // 2, True) if hdr < 400 else table(a, 304, True)
                print('  ', nm, hex(a), p[2], 'hdr', hdr, 'first', t[:6], 'last', t[-4:], 'min', min(t), 'max', max(t))
print('== existing names that could collide (prefix scan)')
pref = ('combustion_', 'chi_', 'alpha_', 'egr_fraction', 'charge_temperature', 'mass_charge_flow', 'nitrogen_oxides', 'injection_quantity_combustion', 'injection_timing_combustion', 'injection_quantity_chi', 'injection_quantity_gross')
for a, ps in sorted(rows.items()):
    for p in ps:
        if p[1].startswith(pref):
            print('  ', p[0], p[1])
fr = open(OUT + 'function_renames.csv').read().splitlines()
for line in fr:
    if line.startswith('#') or not line.strip():
        continue
    p = line.split(',', 2)
    if len(p) > 1 and re.match(r'cm848_(calculate|select|apply|limit|determine|lookup|initialize|convert|set|interpolate)(Combustion|Chi|Alpha|MassCharge|EgrFraction|OffNominal|Nitrogen|ChargeTemp|TimingIncrement|IntakeTemperature)', p[1]):
        print('   FUNC', p[0], p[1])

import sys
sys.path.insert(0, '/home/linux/.claude/jobs/d55ae3c6/tmp/renames/scratch_W5_combustion')
from peek import *
print('slot values (filtered outputs): ')
for nm, a in (('slot1 intake manifold pressure', 0x40baf2), ('slot2 coolant temp', 0x40baf4), ('slot3 barometric', 0x40baf6),
              ('slot9 intake manifold temp', 0x40bb02), ('0x40bd88 (boost_input normal)', 0x40bd88), ('0x40bdae (boost_input fault sub)', 0x40bdae),
              ('0x40bd86 sensor_channel9_pressure_value', 0x40bd86), ('0x40bd84 sensor_channel105_value', 0x40bd84),
              ('fuel_demand_boost_input', 0x40a61c), ('sensor_generic_fault_status?', 0x40a620)):
    print(f"  {nm:42s} {hex(a)} u={w(a)} s={w(a,True)} F={w(a,True)/64:.1f}")
print('fuel->torque grid protection_rpm_correction_yend_cal')
a = 0x405d7a
hdr = w(a)
n = 1 + hdr // 2
grid_addr = a + 2 * n
print('  ystart n', n, 'grid at', hex(grid_addr))
t = table(grid_addr, 304, True)
print('  grid first', t[:10], 'min', min(t), 'max', max(t))
print('  row0', t[0:19], 'row15', t[285:304])

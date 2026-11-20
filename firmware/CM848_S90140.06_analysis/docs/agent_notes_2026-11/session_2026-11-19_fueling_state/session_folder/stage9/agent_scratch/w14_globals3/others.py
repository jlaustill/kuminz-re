"""List other agents' result lines that touch addresses / name families related to my bin (read-only)."""
import glob
import json

STAGE9 = '/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage9/'
want = {'0x0040c274', '0x003fa880', '0x003fa882', '0x003fa884', '0x003fa0d2', '0x003fa5d6', '0x003faf56', '0x003fcff0', '0x003fcff4',
        '0x0040b6b4', '0x0040b6be', '0x0040aeec', '0x003fa712', '0x0040b596', '0x003fcefe', '0x00409472', '0x0040947e', '0x003fb697',
        '0x0040094a', '0x0040096c', '0x0040098e', '0x004009b0', '0x0040b696', '0x003feff2', '0x003ff012'}
keys = ('data_collector', 'commanded_throttle', 'alpha_fuel_rate', 'charge_mass_flow', 'cruise', 'droop', 'volumetric',
        'low_speed_governor_alternator', 'j1939_percent', 'j1939_friction', 'air_fuel_control', 'fuel_metering', 'fuel_pressure_governor',
        'converter_clutch', 'governor_pressure', 'wastegate_duty', 'exhaust_temperature_model')
for path in sorted(glob.glob(STAGE9 + 'result_W14_*.jsonl')):
    if 'globals3' in path:
        continue
    for line in open(path):
        if not line.strip():
            continue
        r = json.loads(line)
        new = r.get('new') or ''
        if r['address'] in want or any(k in new for k in keys):
            print(path.split('result_W14_')[1], r['address'], r['verdict'], r.get('old'), '->', new)

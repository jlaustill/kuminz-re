import re
import subprocess
import sys

ROOT = sys.argv[1]
mod_prefix = ('cm848_calculateVariableGeometry', 'cm848_updateVariableGeometry', 'cm848_runVariableGeometry',
              'cm848_sequenceVariableGeometry', 'cm848_evaluateVariableGeometry', 'cm848_detectVariableGeometry',
              'cm848_checkVariableGeometry', 'cm848_clearVariableGeometry', 'cm848_filterVariableGeometry',
              'cm848_selectVariableGeometry', 'cm848_initializeVariableGeometry', 'cm848_readVariableGeometry')
mod = set("""cm848_calculateActuatorESetpoint cm848_checkSpeedZeroCondition cm848_selectActuatorEControlMode
cm848_calculateSpeedControlRampUp cm848_calculateSpeedControlRampDown cm848_updateSpeedControlOutputs
cm848_selectSpeedControlGains cm848_updateActuatorESetpointAndMode cm848_calculateActuatorEDriveCommand
cm848_selectActuatorEDriveByMode cm848_calculateActuatorEDriveLimits cm848_outputActuatorEDirectionAndDuty
cm848_driveActuatorE cm848_runActuatorEControlLoop cm848_initializeActuatorEControlLoop cm848_updateSpeedControlCounter1
cm848_processSpeedControlFilter1 cm848_updateSpeedControlCounter2 cm848_processSpeedControlFilter2
cm848_initProtectionControlState cm848_clearDiagnosticConditionFlags engine_protection_speedTracking_calc
engine_protection_speedTracking_rampUpdate phase_group_b_updateGovernorModeDiagnostics
cm848_initializeGovernorFuelDemandArray boost_demand_diagBit_counter phase_group_b_computeGovernorFuelDemandOutput
governor_rpm_monitor_calc phase_group_b_filterGovernorRpmSquaredMovingAverage fuel_demand_boost_initialize""".split())


def x(a):
    return subprocess.run(['python3', '-I', ROOT + '/firmware/scripts/xref_addr.py', hex(a)], capture_output=True,
                          text=True, cwd=ROOT).stdout.splitlines()


addrs = []
for t in sys.argv[2:]:
    if '-' in t:
        lo, hi = t.split('-')
        addrs += list(range(int(lo, 16), int(hi, 16) + 1, 2))
    else:
        addrs.append(int(t, 16))
for a in addrs:
    out = x(a)
    hdr = out[0] if out else ''
    nm = re.search(r'\((.*?)\)', hdr)
    funcs = [re.match(r'^(\S+): (\d+r/\d+w)', l).groups() for l in out if re.match(r'^(\S+): \d+r/\d+w', l)]
    outside = [f for f, _ in funcs if f not in mod and not f.startswith(mod_prefix)]
    mn = sorted(set(re.search(r'\]\s+\w+\s+[0-9a-f]+:\s+(?:[0-9a-f]{2}\s+){4}(\w+)', l).group(1)
                    for l in out if re.search(r'\]\s+\w+\s+[0-9a-f]+:\s+(?:[0-9a-f]{2}\s+){4}(\w+)', l)))
    tot = [l for l in out[:3] if l.startswith('# total')]
    low = [l for l in out if re.match(r'\s+\[(load |store)\]', l) and int(re.search(r'\s([0-9a-f]+):', l).group(1), 16) < 0x7f60]
    print(hex(a), (nm.group(1) if nm else 'unnamed')[:46], '|', (tot[0][2:60] if tot else ''), '|', ','.join(mn), '| boot', len(low),
          '| OUTSIDE:', outside if outside else '-', '|', ', '.join(f for f, _ in funcs)[:150])

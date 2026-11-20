import json
import glob

STAGE = '/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage9/'
for f in sorted(glob.glob(STAGE + 'result_W14_globals[34].jsonl')):
    for l in open(f):
        r = json.loads(l)
        if r.get('address') in ('0x003fddba', '0x0040c270'):
            print(f.split('_')[-1], r['address'], r.get('old'), '->', r.get('new'))
            print('   EVIDENCE:', r.get('evidence'))
            print('   COMMENT:', r.get('comment'))
for f in sorted(glob.glob(STAGE + 'result_W14_functions[123].jsonl')):
    for l in open(f):
        r = json.loads(l)
        if r.get('old') in ('diag_dm1Buffer_circularFill', 'cm848_phase_groupB_calculation', 'hpcr_exception_process',
                            'j1939_dm1_diagnosticMessage_send', 'cm848_computeProtectionTrimDivisors',
                            'cm848_calculateVehicleSpeedFromOutputShaft', 'cm848_updateEngineSpeedFromCrankSignal',
                            'mpc555_updateEngineCrankState', 'mpc555_updateEngineRunState', 'hpcr_processEngineSyncPulses',
                            'cm848_checkSensorDeviationFlags', 'cm848_processSensorDeviationOnKeyoff',
                            'sensor_throttleTrim_ema_faultProcess', 'cm848_checkCoolantTemperatureSensorPerformance',
                            'hpcr_calculateFuelTrimOutput', 'timingProtectionFlagsOrchestrator', 'cm848_runCylinderContributionTest'):
            print(f.split('_')[-1], r.get('address'), r.get('old'), '->', r.get('new'), '|', r.get('verdict'))

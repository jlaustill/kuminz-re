"""Round 53: put the exact fault conditions of cm848_selectSensorValuesInUse into apply_r53a.py's substitute texts and
drop two unused constants (one named a function that does not exist)."""
p = "/home/linux/.claude/jobs/374b0424/tmp/w15/r53/apply_r53a.py"
t = open(p).read()
pairs = [
    ('SUB = "cm848_selectEngineProtectionSensorValues"\nFAULT = ("{}: the value {} uses while {} (the e2m names it by '
     'the fault that selects it; the old name went by the "\n         "value)")\n', ""),
    ('"intake_manifold_pressure_in_use while the intake manifold pressure sensor reads out of range high"',
     '"cm848_selectSensorValuesInUse: intake_manifold_pressure_in_use while fault_detected_cal.faults_0_to_15 mask "\n'
     '                   "0x100 is set (the e2m: failed out of range high)"'),
    ('"intake_manifold_pressure_in_use while the sensor reads out of range low"',
     '"cm848_selectSensorValuesInUse: intake_manifold_pressure_in_use while faults_0_to_15 mask 0x200 is set (out "\n'
     '                   "of range low)"'),
    ('"accelerator_pedal_position_in_use while pedal position sensor 1 reads out of range high"',
     '"cm848_selectSensorValuesInUse: accelerator_pedal_position_in_use while "\n'
     '                   "fault_detected_cal.pedal_position_sensor_1_high_error (dual channel) or faults_0_to_15 mask 0x400 "\n'
     '                   "is set (out of range high)"'),
    ('"accelerator_pedal_position_in_use while the sensor reads out of range low"',
     '"cm848_selectSensorValuesInUse: accelerator_pedal_position_in_use on the out of range low fault"'),
    ('"coolant_temperature_in_use while fault_detected_cal.coolant_temperature_high_error is set "',
     '"cm848_selectSensorValuesInUse: coolant_temperature_in_use while "\n'
     '                   "fault_detected_cal.coolant_temperature_high_error is set "'),
    ('"coolant_temperature_in_use while fault_detected_cal.coolant_temperature_low_error is set (256 deg "',
     '"cm848_selectSensorValuesInUse: coolant_temperature_in_use while "\n'
     '                   "fault_detected_cal.coolant_temperature_low_error is set (256 deg "'),
    ('"intake_manifold_temperature_in_use while the intake manifold temperature high error is set (-50 "',
     '"cm848_selectSensorValuesInUse: intake_manifold_temperature_in_use while "\n'
     '                   "fault_detected_cal.intake_manifold_temperature_high_error is set (-50 "'),
    ('"intake_manifold_temperature_in_use while fault_detected_cal.intake_manifold_temperature_low_error "',
     '"cm848_selectSensorValuesInUse: intake_manifold_temperature_in_use while "\n'
     '                   "fault_detected_cal.intake_manifold_temperature_low_error "'),
]
for old, new in pairs:
    assert t.count(old) == 1, old[:60]
    t = t.replace(old, new)
open(p, "w").write(t)
print("texts fixed")

"""One-off patch of the rows_item*.py sources after the advisor review (each replacement must hit exactly once)."""
import re

D = '/home/linux/.claude/jobs/d55ae3c6/tmp/renames/scratch_W9_gear_down/'


def patch(fname, pairs, cut=None):
    s = open(D + fname).read()
    if cut:
        a = s.index(cut[0])
        b = s.index(cut[1])
        s = s[:a] + s[b:]
    for old, new in pairs:
        n = s.count(old)
        assert n == 1, (fname, n, old[:70])
        s = s.replace(old, new)
    open(D + fname, 'w').write(s)


# ---- item 2/3: drop the old source 16 section, fix the fuel pair wording
patch('rows_item23.py', [
    ('"(cpp 19939) resets protection_fuel_limit_active to protection_fuel_limit_cal_active with source code 0x13; every limiter then "',
     '"(cpp 19939) - its only caller is cm848_processProtectionLimits (cpp 43018), which cm848_processProtectionSelection runs every "\n'
     '  "pass while governor_feature_flags bit 0x10 is clear - resets protection_fuel_limit_active to protection_fuel_limit_cal_active "\n'
     '  "with source code 0x13; every limiter then "'),
    ('(decimal): 13 processProtectionSelection (derate feature bit 0x10 set: protection_fuel_limit_c_working);',
     '(decimal): 13 cm848_processProtectionSelection (governor_feature_flags bit 0x10 SET, the limiters are skipped: "\n'
     '  "protection_fuel_limit_c_working);'),
    ('"The lowest fuel quantity limit of the derate sources this pass (fuel demand scale, 5888 = 400 mm3 = none), reset each pass and "\n'
     '  "lowered by the 12 limiters listed in the note;',
     '"The lowest fuel quantity limit of the derate sources (fuel demand scale, 5888 = 400 mm3 = none), reset every pass of "\n'
     '  "cm848_processProtectionLimits and lowered by the limiters listed in the note;'),
], cut=('# ---------------- (3b) source 16 subsystem ----------------', '# ---------------- (3c) W7 note 87 leftovers ----------------'))

# ---- item 1: stale names in the 0x3f35c plate, inference marking
patch('rows_item1.py', [
    ('"If torque_management_fuel_limit is below the running fuel limit protection_fuel_limit_active, takes it and records source code "\n'
     '  "45 (0x2d) in governor_fuel_mode_command; called from cm848_processProtectionLimits',
     '"If torque_management_fuel_limit is below the running fuel limit torque_derate_fuel_quantity, takes it and records source code "\n'
     '  "45 (0x2d) in torque_derate_fuel_source_code; called from cm848_processProtectionLimits'),
    ('"needs torque management (also when vehicle_speed is 0): 11530 = 5.63, the 1st gear of the NV5600. e2m Torque_Mgmt_Manual_GR "',
     '"needs torque management (also when vehicle_speed is 0): 11530 = 5.63 - which equals the 5.63:1 first gear of the NV5600 "\n'
     '  "6-speed manual (outside knowledge; reading drivetrain_ratio as the transmission gear ratio is an inference from the "\n'
     '  "e2m names). e2m Torque_Mgmt_Manual_GR "'),
    ('"ratio is the transmission gear ratio x 2048 (11530 = 5.63, which is also the 5.63:1 first gear of the NV5600 6-speed manual - "\n'
     '  "outside knowledge, not from the firmware; 8192 / 4096 / 1741 = 4.0 / 2.0 / 0.85).")',
     '"ratio is engine speed over vehicle speed x 2048; that it equals the transmission gear ratio is an inference from the e2m "\n'
     '  "names (11530 = 5.63 equals the 5.63:1 first gear of the NV5600 6-speed manual - outside knowledge, not from the firmware; "\n'
     '  "8192 / 4096 / 1741 = 4.0 / 2.0 / 0.85).")'),
])

# ---- item 4: register call site owners, dispatch caller wording
patch('rows_item4.py', [
    ('"flash 2: ROM 0x398 / 0x3a8 / 0x3bc / 0x3c8 / 0x3d4 (mpc555_initDiagnosticSubsystem: services 2, 7, 11, 16, 24), 0x1934 (25), "\n'
     '  "0x19a4 / 0x19b4 / 0x19c4 / 0x19d4 (68, 69, 75, 77), 0x1ae8 (65), 0x1b14 / 0x1b24 / 0x1b34 (67, 74, 76); no plain b targets it. "\n'
     '  "cm848_dispatchDiagnosticService (0x6d24) has one caller (ROM 0x60f8, the transport protocol data packet handler). The "',
     '"flash 2: ROM 0x398 / 0x3a8 / 0x3bc / 0x3c8 / 0x3d4 (cm848_registerStandardDiagServices: services 2, 7, 11, 16, 24), 0x1934 "\n'
     '  "(cm848_initService25Handler: 25), 0x19a4 / 0x19b4 / 0x19c4 / 0x19d4 (cm848_initDataBasedDiagServices: 68, 69, 75, 77), 0x1ae8 "\n'
     '  "(cm848_registerService65Handler: 65), 0x1b14 / 0x1b24 / 0x1b34 (cm848_registerMemoryReadServices: 67, 74, 76); no plain b "\n'
     '  "targets it. cm848_dispatchDiagnosticService (0x6d24) has one direct call (ROM 0x60f8 in "\n'
     '  "mpc555_handleJ1939TransportDataPacket); its RAM copy (&DAT_003fc8f4) is also passed to cm848_registerPgnEf00Handler, so it "\n'
     '  "can additionally run through that registration. The "'),
])
print('patched')

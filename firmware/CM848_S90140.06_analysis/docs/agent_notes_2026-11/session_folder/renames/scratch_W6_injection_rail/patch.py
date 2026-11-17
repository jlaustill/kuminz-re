import re

D = "/home/linux/.claude/jobs/d55ae3c6/tmp/renames/scratch_W6_injection_rail/"


def patch(fn, pairs):
    s = open(D + fn).read()
    for old, new in pairs:
        n = s.count(old)
        assert n == 1, (fn, n, old[:80])
        s = s.replace(old, new)
    open(D + fn, "w").write(s)


# ---------------------------------------------------------------- part1
s = open(D + "part1.py").read()
a = s.index("# ---------------------------------------------------------------- N41: auxiliary interaction tables")
b = s.index("# ---------------------------------------------------------------- N39: acceleration filter neighbours")
aux_new = '''# ---------------------------------------------------------------- N41: auxiliary interaction tables (downgraded to uncertain)
AUXROWS = [
    ("0x0005fa1a", "word[9]", "x axis of the SCALE lookup (x = auxiliary_injection_quantity): ROM 0, 736, 1472, 2208, 2944, 3680, 4048, 4416 = 0, 50, 100, 150, 200, 250, 275, 300 mm3 at 0.0679 mm3 per count (round numbers, fits a quantity axis)"),
    ("0x0005fa2c", "word[9]", "y axis of the SCALE lookup (y = fuel_pressure_sensor): ROM 0, 614, 1023, 1433, 1842, 2252, 2866, 3276 = 0, 30, 50, 70, 90, 110, 140, 160 MPa at 0.0488 MPa per count (round numbers, fits a rail pressure axis)"),
    ("0x0005fa3e", "word[64]", "8 x 8 grid of the SCALE lookup: all 64 ROM words are 0 (the main-path twin main_quantity_pilot_correction_scale_grid holds 16 / 12 / 8 / 4 / 3)"),
    ("0x0005f8ac", "word[26]", "x axis of the CORRECTION lookup (x = main_to_auxiliary_injection_interval, 3.2 us counts = ticks >> 3, at least 187 counts when the pulse is kept): ROM 0, 0, 1, 1, 1, 2, 2, 2, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 8, 8, 8, 9 - duplicates and a range of 0..9, so it does NOT fit its input (the main-path twin axis 0x5f69a runs 188..1375): unit test FAILED"),
    ("0x0005f8e0", "word[7]", "y axis of the CORRECTION lookup (y = main_injection_pulse_width_before_minimum_check): ROM 0, 1250, 3750, 6250, 8750, 10238 (the main-path twin 0x5f6ce is 0..1250 in steps of 250)"),
    ("0x0005f8ee", "word[150]", "6 x 25 grid of the CORRECTION lookup: all 150 ROM words are 0 (the main-path twin has 115 nonzero words)"),
]
for _addr, _typ, _what in AUXROWS:
    gl(_addr, "", "uncertain", None,
       "Old name column is EMPTY (row renders WORD_ARRAY_" + _addr[4:] + ", type " + _typ + "), so no rename is given. Code role is exact (cm848_calculateAuxiliaryInjectionPulseWidth, when main_injection_pulse_width_before_minimum_check is nonzero: quantity = ((scale lookup x correction lookup) >> 4) + auxiliary_injection_quantity, mirror of the main path). " + _what + ". Two earlier passes objected to naming these and the objection text could not be recovered (the campaign CSV cuts it at 427 characters, 'the first-pass objections still stand' sits on the scale rows); the correction triple fails the unit test and both grids are all zero, so the calibration is a placeholder and I do not name the group. Candidate names are in the note below.")
note("[W6 injection note 41] Auxiliary pulse interaction tables 0x5fa1a / 0x5fa2c / 0x5fa3e (scale lookup, 8 x 8) and 0x5f8ac / 0x5f8e0 / 0x5f8ee (correction lookup, 6 x 25): left uncertain, rows are WORD_ARRAY_0005xxxx with an EMPTY name column. Candidate names if a reviewer accepts them (the wave-4 proposal, kept in the existing injection_quantity_auxiliary_* family; rename only, types word[9] / word[9] / word[64] and word[26] / word[7] / word[150]): 0x5fa1a injection_quantity_auxiliary_main_correction_scale_x_axis, 0x5fa2c injection_quantity_auxiliary_main_correction_scale_y_axis, 0x5fa3e injection_quantity_auxiliary_main_correction_scale_grid, 0x5f8ac injection_quantity_auxiliary_main_correction_x_axis, 0x5f8e0 injection_quantity_auxiliary_main_correction_y_axis, 0x5f8ee injection_quantity_auxiliary_main_correction_grid. ROM evidence (originals/cm848_rom.bin): scale axes pass the unit test (quantity axis 0..300 mm3 in round steps; pressure axis 30..160 MPa in round steps), the correction x axis fails it (0..9 with duplicates against an interval of at least 187 counts) and all 214 grid words are 0. The main-path twins (0x5f69a-0x5f82c) have real data, so a copy-and-zero of the main tables is the likely origin of the aux ones.")

'''
s = s[:a] + aux_new + s[b:]
s = s.replace('"crank_pattern_valid_flag", "confirmed", "crank_pattern_first_tooth_flag"', '"crank_pattern_valid_flag", "confirmed", "crank_tooth_counter_zero_flag"')
s = s.replace("So it marks the first tooth of the crank pattern (tooth counter 0), not 'pattern valid'. The gap meaning is NOT proven, hence 'first tooth' only. Medium confidence.", "So the write site proves only 'the tooth counter of TPU-A channel 1 is 0' (the readers use that as the pattern-start condition); the inference 'first tooth after the sync gap' is NOT proven, hence the plain name. It is not 'pattern valid'. Medium confidence.")
s = s.replace("So it is the previous filtered speed error of the actuator E loop.", "So it is the previous filtered speed error of the actuator E loop (the 'governor_speed_error' stem is the actuator E position error per wave 5; rename it together with its sibling governor_speed_error_filtered_change 0x40b00e).")
open(D + "part1.py", "w").write(s)

# ---------------------------------------------------------------- part2
patch("part2.py", [
    ("each active source lowers the running minimum lowest_source_speed_limit and records its number in limiting_source_number - 5 fault derate, 6 stored reference, 7 fuel pressure faults, 13 converter slip, 14 auxiliary mode, 15 park/neutral exit, and the TSC1 / ETC1 requests (8, 9), the idle limit (11) and the governor override (16).",
     "each active source lowers the running minimum lowest_source_speed_limit and records its number in limiting_source_number - 5 engine_speed_limit_fault_derate, 6 torque_limit_fuel_reference, 7 fuel_pressure_fault_engine_speed_limit_working, 8 the TSC1 override mode select 1 request (DAT_0005c39a), 9 j1939_tsc1_override_state.etc1_torque_limit_value (governor mode 3), 11 governor_fuel_idle_limit, 13 engine_speed_limit_converter_slip, 14 torque_limit_fuel_min_working, 15 engine_speed_limit_park_neutral_exit, 16 torque_limit_override_source_cal (governor_active_flag_b648 set)."),
    ("and the lowest source limit plus the fuel pressure fault, auxiliary mode (14), 10 and 4 source limits to engine_speed_limit_default_cal (3750 rpm); the limiting source number is set to 6.",
     "and the lowest source limit plus the source words fuel_pressure_fault_engine_speed_limit_working (7), torque_limit_fuel_min_working (14), torque_fuel_limit_active (10) and torque_limit_fuel_minimum_snapshot (4) to engine_speed_limit_default_cal (3750 rpm); the limiting source number is set to 6."),
    # 0x3fdcf8
    ("EEPROM-range address (0x3fdcf8, time-shared window) so _cal. xref_addr.py: 2 reads / 0 writes, word, 1 function, no user below 0x7F60. No type change.",
     "EEPROM-range address (0x3fdcf8 is above the time-shared window 0x3F9800-0x3FDB30) so _cal. xref_addr.py: 2 reads / 0 writes, word, 1 function. No type change."),
    # 0x406fea
    ("except for sources 9 and 16 which use the integrator + deadband value capped at 36000. Outside the EEPROM range (0x406fea), keep the _cal removal.",
     "except for sources 9 and 16 which use the integrator + deadband value capped at 36000. Its only user is cm848_selectTorqueLimit (2 code lines, grep over the whole decompilation). Outside the EEPROM range (0x406fea), so the _cal goes."),
    # 0x406fec
    ("Cap of the arbitration: the lowest source limit is cut to it when above (28000 = 3500 rpm), applied before the floor. Outside the EEPROM range, no _cal.",
     "Cap of the arbitration: the lowest source limit is cut to it when above (28000 = 3500 rpm), applied before the floor. Second user faultTimerHandler encodes it as value / 0x50 (10 rpm units, 0xfa = 2500 rpm and above when the value is 0x4e21 or more) into a message byte, which again says engine speed. Outside the EEPROM range, no _cal."),
    # 0x406fe4
    ("drops to the minimum at once when above. The only use I read. Outside the EEPROM range, no _cal.",
     "drops to the minimum at once when above. Its only user is cm848_selectTorqueLimit (1 code line, grep over the whole decompilation). Outside the EEPROM range, no _cal."),
    # 0x40a30c
    ("read by the timing filter coefficient selection (compared with the DAT_0005c318 / DAT_0005c322 thresholds), by the protection threshold code (as the base of a recovery threshold) and in cm848_selectTorqueLimit (snapshot). Not a load.",
     "read in 5 functions (grep): selectSensorRawChannels (4 lines, picks the filter coefficient set by comparing it with the DAT_0005c318 / DAT_0005c322 thresholds), faultTimerHandler, cm848_processJ1939RxMessage, cm848_updateProtectionStateMachine and cm848_selectTorqueLimit (snapshot). Not a load."),
    # park/neutral family
    ("the window (cm848_updateParkNeutralExitEngineSpeedLimitWindow) only gates the engine speed limit source 15 (held at 6800 = 850 rpm, normally 30000 = 3750 rpm), not any torque.",
     "the words of this family are used only by cm848_updateParkNeutralExitTorqueLimitWindow, cm848_processTorqueLimitConfig and cm848_initTorqueLimitState (grep over the whole decompilation), and the window only gates the engine speed limit source 15 (held at 6800 = 850 rpm, normally 30000 = 3750 rpm), not any torque."),
    # algorithm_enable_flags_6_cal
    ("CODE: bit 0 with fuel_demand_mode_index, bit 1 the rpm-table fuel limiter, bit 2 (10 sites) the 48RE transmission strategy, bit 3 the gear 1 / 2 and lockup logic (9 tests), bit 4 cruise switches learned, bit 5 sensor deviation check pending, bit 15 cruise engaged.",
     "CODE (wave 4 reading): bit 0 (1 site, with fuel_demand_mode_index), bit 1 the rpm-table fuel limiter (1 site), bit 2 (10 sites, e.g. with protection_mode_changed_flag), bit 3 the transmission gear 1 / 2 and lockup logic (9 tests), bit 4 cruise switches learned (2 sites), bit 5 sensor deviation check pending (1 site), bit 15 cruise engaged (1 site)."),
    ("- every code bit above has a matching e2m enable. So it is a bank of feature enables with no single subject; 'protection' is wrong.",
     "- only bit 3 (gear 1 / 2 and lockup logic vs RE_2Lock_Enable, 2nd gear lockup strategy) is a solid match and bit 1 (rpm-table fuel limiter vs Low_Fuelpr_Derate_Enable) a plausible one; the other bits only agree by subject area. What is certain from the code is that the bits have no common subject, and the e2m shows a bank of feature enables, so the generic name is honest while 'protection' is wrong."),
])
print("patched")

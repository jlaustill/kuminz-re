import sys

path = "/home/linux/.claude/jobs/d55ae3c6/tmp/renames/w8_egr/gen_W8_egr_charge.py"
text = open(path).read()


def R(old, new, count=1):
    global text
    if count and text.count(old) != count:
        sys.exit("count %d (want %d): %s" % (text.count(old), count, old[:90]))
    text = text.replace(old, new)


# (a) the two unknown words become uncertain rows
R('''G("0x003fa7ae", "governor_target_speed_c_working", "egr_valve_h_bridge_boot_cleared_word_a",
  "code: written once, with 0, by cm848_clearEgrValveHBridgeFaultState; no other access in any function. Role unknown: the name is neutral on purpose (the old governor name is wrong).")
G("0x003fa7b0", "governor_target_speed_d_working", "egr_valve_h_bridge_boot_cleared_word_b",
  "code: written once, with 0, by cm848_clearEgrValveHBridgeFaultState; no other access in any function. Role unknown: neutral name (the old governor name is wrong).")
''', '''U("0x003fa7ae", "governor_target_speed_c_working", "zeroed once by cm848_clearEgrValveHBridgeFaultState and never accessed by any other function (xref and whole-binary load / store scan; time-shared window, no boot-ROM user); sits between the inrush input flag and the fault retry timer flags; its role is unknown, so no name is proposed, but the old 'governor target speed' name is wrong.")
U("0x003fa7b0", "governor_target_speed_d_working", "same as 0x003fa7ae: zeroed once by cm848_clearEgrValveHBridgeFaultState, no other access; role unknown, old governor name wrong.")
''')
# (b) the compressor outlet temperature estimate: the head was read
R('''"Estimates the compressor outlet temperature (1/64 degree F) from the ambient air temperature and a boost ratio lookup: the table output x (ambient_air_temperature_selected + 0x7300) >> 12 with a floor, filtered by an exponential moving average; returns the filtered value.",
  "code: the tail of the function (the part read): ambient temperature x lookup, floor, EMA. Only the caller cm848_selectCompressorOutletTemperature uses it.")''',
  '''"Estimates the compressor outlet temperature (1/64 degree F) from a compressor map: the corrected fresh air mass flow (boost_pressure_state fresh_air_mass_flow_filtered x a table factor of the ambient air temperature) and the corrected turbocharger speed (fuel_demand_quantity x 0x106 / 10000, divided by the same factor) index a dual-axis table, whose output scales the ambient air temperature in Rankine (ambient_air_temperature_selected + 0x7300), converted back, floored and filtered by an exponential moving average; returns the filtered value.",
  "code: the whole function was read: the two corrected inputs, the dual-axis lookup, the Rankine scaling and the EMA; the only caller is cm848_selectCompressorOutletTemperature. The corrected speed input is fuel_demand_quantity, which supports its turbocharger speed reading (lead).")''')
# (c) 0x3fa750
R('''"code: the ema_filter_state_t of the delta pressure filter in cm848_updateEgrValveOverTemperatureFault (coefficient pointer stored by cm848_initializeEgrValveMotorThermalModel, accumulator at 0x3fa754; no row at 0x3fa754). Row type to ema_filter_state_t (the decompiler already calls it PTR_egr_valve_motor_winding_temperature_filter_coefficient_003fa750).",''',
  '''"code: the ema_filter_state_t of the delta pressure filter in cm848_updateEgrValveOverTemperatureFault: cm848_initializeEgrValveMotorThermalModel stores (stw, instruction scan) the coefficient pointer at 0x3fa750 - it targets egr_valve_motor_winding_temperature_filter_coefficient, the cell the winding temperature filter uses too - and seeds the accumulator at 0x3fa754 (stw; no row there) with egr_delta_pressure << 16 (dump high word 85 = the delta pressure). Row type to ema_filter_state_t.",''')
# (d) feature flags
R("and T_EGR_Cooler_Fouling_Enable (2000); nothing here is cold start.",
  "and T_EGR_Cooler_Fouling_Enable (2000; the .12 file lists T_VGT_Pneumatic_Control_Enable at the same mask, a variant bit); nothing here is cold start.")
# (e) turbocharger speed label disclosure
R('''def G(addr, old, new, ev, typ=None):
    a = int(addr, 16)''', '''def G(addr, old, new, ev, typ=None):
    a = int(addr, 16)
    if "turbocharger_speed" in new:
        ev += (" The 'turbocharger speed' label comes from the e2m names (CHL_Turbo_Speed_*, C_EGR_AZ_Turbo_Speed_Thd, KRPM 0.008) and from"
               " fuel_demand_quantity feeding the compressor map in cm848_estimateCompressorOutletTemperature; the variable's own rename is left as a lead.")''')
R("code: the speed limit used when boost_control_mode is not 1; dump 16250.", "code: the speed limit used when boost_control_mode is not 1; dump 16250 x 0.008 = 130 KRPM.")
R("Dump 1500 (12 KRPM).", "Dump 1500 x 0.008 = 12 KRPM.")
# (f) family naming
R("egr_valve_h_bridge_inrush_fault_counter_latch_flag", "egr_valve_h_bridge_inrush_fault_latched_flag", 0)
R("egr_valve_h_bridge_fault_counter_latch_flag", "egr_valve_h_bridge_fault_latched_flag", 0)
# (g) no duplicate dump text
R("def tail(a, typ, old_type):", "def tail(a, typ, old_type, ev=\"\"):")
R("    if v is not None:\n        t += \" Dump %d.\" % v", "    if v is not None and \"Dump\" not in ev:\n        t += \" Dump %d.\" % v")
R("ev + tail(a, typ, row[2] if len(row) > 2 else None)", "ev + tail(a, typ, row[2] if len(row) > 2 else None, ev)")
R("ev + tail(a, typ, None)}", "ev + tail(a, typ, None, ev)}")

extra = '''
NOTE("LEAD ITEMS CHECKED AND NOT RENAMED (one line each): "
     "(1) cm848_calibration_group22_load 0x52e29c: reads the delta pressure sensor output (egr_delta_pressure_sensor_output, three reads) in a crank-phase plausibility check (key on, cold_start_phase CSP_CRANKING, egr_valve_position below DAT_00409e90, no fault 725, dwell counters boost_corr_crank_phase_dwell_a / _b): |output| above DAT_00409ea8 sets bits 0x240 of diagnostic_status_flags_working; a second, running-engine half uses DAT_00409e86 / 8a / 8c / 92 (speed, load and valve position limits). It is a delta pressure sensor plausibility check, but its bits and DTC slot were not decoded, so the function and the boost_corr_* words stay as they are (the unnamed cells 0x409e86-0x409ea8 are its thresholds). "
     "(2) cm848_calibration_group21_load_cont 0x52eae8: a cam / sync start-up evaluation (coolant minus battery temperature, fault bits, cold_start_phase CSP_CRANKING, engine_sync_validation_flags) whose only link to the valve is the position test against DAT_00409eb8 at cpp 86910; NOT part of the delta pressure chain. "
     "(3) cm848_completeBoostPressureMonitorReport 0x52d524: completion of the Boost / MAP monitor group (P0236 / P0299 / P0069 by the DTC table), gated on the group 21 / 22 triggers above; unresolved conflict: the DTC names say boost while the compared word is the EGR delta pressure; decode diagnostic_status_flags_working bits 0x40 / 0x80 / 0x100 / 0x200 against the slot table before renaming any of the three. "
     "(4) The 0x18070-0x182e8 'throttle' functions (cm848_throttlePositionProcessing, cm848_faultSeverityEvaluation, cm848_processThrottlePositionLookups, cm848_calculateThrottleProtectionLimit) and their throttle_position_* / throttle_cal_* / throttle_demand_* / throttle_protection_load_ratio words are a different 'throttle': a torque / fuel demand percentage from the governor integrator and ROM tables (DAT_0005c2b2-0x5c2ba, friction fuel by coolant temperature); not the EAC and not touched. "
     "(5) The other fuel_demand_rate_* words (0x3fa6de fuel_demand_rate_complement, 0x3fb420-0x3fb426 fuel_demand_rate_limiter_state and _lookup_a / b / c, 0x408998 / 0x40899a fuel_demand_rate_step_down / _up, 0x408db6 / 0x408dba) belong to the Bank 1 fuel demand limit module (cm848_calculateFuelDemandLimit 0x3ccb4, mpc555_initFuelDemandTrackingState 0x3cf40) and are unrelated to the charge manager; only fuel_demand_rate_limiter (0x40a37a), fuel_demand_rate_input, fuel_demand_rate_below_min_flag, fuel_demand_rate_increase_limit_cal and fuel_demand_rate_working (0x3ff73c) were CHL words and are renamed above. "
     "(6) 0x3fa7ae / 0x3fa7b0 (governor_target_speed_c / d_working): zeroed at boot by cm848_clearEgrValveHBridgeFaultState and never accessed again, role unknown - left as uncertain rows with no name.")
'''
marker = "# --- uncertain rows"
if text.count(marker) != 1:
    sys.exit("marker")
text = text.replace(marker, extra + "\n" + marker)

# the type note (7) fact for 0x3fa750
R("0x003fa750 (egr_valve_delta_pressure_filter_state), 0x003fa790 (egr_valve_derivative_filter_state, delete the 0x003fa794 row) - boot inits store pointer and accumulator with stw; the first two have no other row inside the 8 bytes.",
  "0x003fa750 (egr_valve_delta_pressure_filter_state: pointer stw at 0x3fa750 to egr_valve_motor_winding_temperature_filter_coefficient, accumulator stw at 0x3fa754 seeded with egr_delta_pressure << 16), 0x003fa790 (egr_valve_derivative_filter_state, delete the 0x003fa794 row) - boot inits store pointer and accumulator with stw (instruction scan); the first two have no other row inside the 8 bytes.")
open(path, "w").write(text)
print("patched3")

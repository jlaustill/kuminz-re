import re

P = "/home/linux/.claude/jobs/d55ae3c6/tmp/renames/scratch_W6_combustion/gen.py"
s = open(P).read()


def rep(old, new, count=1):
    global s
    n = s.count(old)
    assert n == count, ("count %d != %d for: %s" % (n, count, old[:80]))
    s = s.replace(old, new)


# 1. kept function names carry no "new"
rep('''    r = {"kind": "function", "address": "0x%08x" % addr, "old": old, "verdict": "confirmed", "new": new, "evidence": ev}
''', '''    r = {"kind": "function", "address": "0x%08x" % addr, "old": old, "verdict": "confirmed", "evidence": ev}
    if new != old:
        r["new"] = new
''')
rep('''def SF(struct, old, new, ev):''', '''def U(addr, old, ev, kind="global"):
    rows.append({"kind": kind, "address": "0x%08x" % addr, "old": old, "verdict": "uncertain", "evidence": ev})


def SF(struct, old, new, ev):''')

# 2. status flag scalars become uncertain
rep('''for a, o, nm, ev in CBR:
    G(a, o, nm, ev)
''', '''UNC = {
    0x4059da: "Code: the chi (hundredths, dump 400 = 4.00) that cm848_selectChiAndAlpha forces, with source code 14 and EGR off, when fuel_mode_status_flags bit 8, 0x10 or 0x200 is set. Origin of those bits checked: bit 8 is DAT_003fbd56 = 8 in cm848_updateSensorValidationFlags (from DAT_0040a43c, only when governor_feature_config_flags bit 0x40 is set); DAT_003fbd50 / DAT_003fbd54 are only initialised to 0 by name; DAT_00406568 / DAT_0040656a (1024 in the dump) are ROM-copied words that fuel_modeStatusFlags_update uses as or ORs into the flags, so bits 0x10 and 0x200 can come from the calibration. The bits do not come from one traceable function, so no name that says what triggers it. e2m: C_CBR_Protection_Chi +04 'If chi.source=CBR_PROTECTION_CHI, then Chi will be this' (the old name fuel_blend_step_a_cal stays until the trigger is known; the name must not use a bare protection).",
    0x4059f0: "Code: the level (dump 8192) paired with the same chi: combustion_chi_paired_level when the source code is 14. Same trigger problem as 0x4059da (bits 8 / 0x10 / 0x200 of fuel_mode_status_flags do not all come from cm848_updateSensorValidationFlags), so no name. e2m: C_CBR_Protection_EL +1A (G/HP*HR 0.000488) 'Corresponds to C_CBR_Protection_Chi'.",
}
for a, o, nm, ev in CBR:
    if a in UNC:
        U(a, o, UNC[a])
    else:
        G(a, o, nm, ev)
''')

# 3. 0x4059f4 code-only name
rep('"net_combustion_torque_governor_term_scale"', '"net_combustion_torque_subtracted_term_scale"')
rep('multiplies the torque looked up at the governor target quantity (fuel_demand_rpm_correction_lookup) by it',
    'multiplies fuel_demand_rpm_correction_lookup (the torque table value at governor_speed_target_base, a legacy name that was not checked) by it')

# 4. 0x40a61c becomes a note
m = re.search(r'G\(0x40a61c, .*?"\)\nG\(0x40a460', s, re.S)
assert m
s = s[:m.start()] + '''N("fuel_demand_boost_input (0x40a61c) is left unrenamed: it is a coolant temperature (1/64 deg F, dump 2050 = 32 deg F) by the code and the e2m - cm848_mainLoop_step_3 copies WORD_0040bd88 (a generic sensor channel output word), or WORD_0040bdae = 12160 = 190 deg F when sensor_generic_fault_status bit 2 is set; the combustion manager uses it as the x of the coolant protective chi table (e2m C_CBR_Coolant_Tmptr_Axis, signed deg F 1/64) and compares it with combustion_egr_off_coolant_temperature_limit (e2m C_CBR_UHC_Coolant_Tmptr_Limit). But it has at least twelve users outside the combustion manager (cm848_checkProtectionEnableConditions, cm848_processSensorMonitoringLogic, cm848_updateEngineModeFromSensor, mpc555_processSensorValidation, fuel_boostCorrection_enableCheck_trimCalc, fuel_demand_boost_ema_compensate and others), and a second coolant copy exists (coolant_temperature_in_use 0x40b152, from cm848_selectSensorValuesInUse with its own substitutes), so a scoped name like coolant_temperature_for_combustion would over-claim; candidate coolant_temperature_substituted once the generic sensor channel at 0x40bd88 is identified.")
G(0x40a460''' + s[m.end():]

# 5. flags word evidence: what the bit 13-15 sites show
rep("so the name covers both groups (the bit 13-15 functions were not read here).",
    "so the name covers both groups. Code at bits 13-15 (read for this row): bit 13 clear sets boost_correction_mode_flags = 0x80 beside boost_pressure_synthetic_ema (cm848_phase_groupA_exponentialAverage; the e2m says exhaust pressure estimate, the code shows a synthetic boost pressure, not verified to be the same quantity); bit 14 clear sets injection_enable_mode_byte = 0x80, which cm848_calculatePressureSensorFiltered turns into the channel default for fuel_demand_boost_offset (cm848_processBoostProtectionMode); bit 15 clear forces boost_fuel_weight_factor to its neutral 0x80 (cm848_calculateBoostTorqueOffset). Each of the three visibly gates an estimate or substitute path.")

# 6. axis evidence wording
rep("for the lookups of %s (in the timing function the %s grid is the pointer word of map N); the axis is shared by ",
    "for the %s lookups (the grid argument is the base grid for the base axes and the pointer word of the same map number otherwise, checked in all five functions); the axis is shared by ")
rep('% (stem.replace("_", " "), stem.replace("_", " "), E2MAX[stem], extra))', '% (stem.replace("_", " "), E2MAX[stem], extra))')

# 7. headroom flow word without "mass"
s = s.replace("fuel_mass_flow_temperature_headroom_limit", "fuel_flow_temperature_headroom_limit")
rep("(a mass flow like the charge mass flow, 1/128 lb/min)", "(a flow in the unit of the charge mass flow)")

# 8. review note additions
rep("(4) No name here contains hex digits; the e2m addresses are in the evidence only.",
    "(4) No name here contains hex digits; the e2m addresses are in the evidence only. (5) The sub-rows 0x40a496-0x40a49c of combustion_reference_state in global_variables.csv still read .reserved_02 .. .reserved_08. (6) The committed plate comments and row comments that call 0x40a604 the intake air density (for example cm848_limitMassChargeFlowReference) should say ambient air density once engine_load_input_value is renamed.")

# 9. enum member 14 left open
rep("COMBUSTION_CHI_SOURCE,14,COMBUSTION_CHI_SOURCE_STATUS_FLAG,chi and level of the status-flag calibration (combustion_status_flag_chi_hundredths / _paired_level) when fuel_mode_status_flags bit 8, 0x10 or 0x200 is set (e2m CBR_PROTECTION_CHI),2. ",
    "Value 14 (chi and level from fuel_blend_step_a_cal 0x4059da / fuel_blend_step_a_threshold_cal 0x4059f0 when fuel_mode_status_flags bit 8, 0x10 or 0x200 is set; e2m CBR_PROTECTION_CHI) has no member name proposed because the trigger bits are not traced to one source (see the two uncertain rows). ")

# 10. remaining-notes wording
rep("the origin of bits 8 / 0x10 / 0x200 that pick the status-flag chi was not traced;",
    "bit 8 of that word comes from cm848_updateSensorValidationFlags (DAT_0040a43c), bits 0x10 / 0x200 have no named writer (DAT_003fbd50 / DAT_003fbd54 are only initialised) and may come from the ROM-copied DAT_00406568 / DAT_0040656a (1024 in the dump);")

open(P, "w").write(s)
print("patched")

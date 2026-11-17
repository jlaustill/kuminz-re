exec(open('/home/linux/.claude/jobs/d55ae3c6/tmp/renames/w7/gen_W7b.py').read())

# ---- a few more state words of the same module (time-shared: boot scan sentence is added) ----
EXTRA = [
 (0x3fa7f0, 'enable_condition_counter', 'counter (0-200) of passes with the position sensor status or the control error present (cm848_updateExhaustGasRecirculationValveEnableAndDiagnosticConditions)'),
 (0x3fa7ee, 'enable_condition_flag', '1 when no position sensor / control error problem is present or the problem has lasted 200 passes; with the driver fault pending flag it sets or clears logical output request 67'),
 (0x3fa7f6, 'enable_timeout_flag', '1 while the electrical fault 726 is set or the position / control error problem is present and the over-current / over-temperature condition has not been seen; keeps the autozero from starting'),
 (0x3fa7e6, 'autozero_hysteresis_counter', 'counts passes up to exhaust_gas_recirculation_valve_autozero_retry_time while the enable-timeout flag and fault 718 are clear (cm848_updateExhaustGasRecirculationValveAutozeroConditions)'),
 (0x3fa7e8, 'autozero_hold_counter', 'hold counter of the autozero drive: counts up to exhaust_gas_recirculation_valve_autozero_active_time while ready, 0 while the reset flag is set; 0 in the dump because fault 718 is set'),
 (0x3fa7ea, 'autozero_hold_reset_flag', '1 while the enable-timeout flag or fault 718 is set: resets the hold counter and the hysteresis counter'),
]
for a, suf, code in EXTRA:
    old = grows[a][1]
    renamed_old[old] = V(suf)
    ev = 'code: ' + users_text(old) + code + '.' + ts_sentence(a)
    out.append({'kind': 'global', 'address': '0x%08x' % a, 'old': old, 'verdict': 'confirmed', 'new': V(suf), 'evidence': ev})

# ---- stale citations ----
done_addrs = {int(r['address'], 16) for r in out if r['kind'] in ('global', 'function', 'new_global')}
stale = []
pat_cache = {}
for old in renamed_old:
    if not old:
        continue
    pat_cache[old] = re.compile(r'(?<![A-Za-z0-9_])' + re.escape(old) + r'(?![A-Za-z0-9_])')
for src, table in (('function_renames.csv', frows), ('global_variables.csv', grows)):
    for a, r in table.items():
        if a in done_addrs:
            continue
        c = r[2] if src == 'function_renames.csv' and len(r) > 2 else (r[3] if len(r) > 3 else '')
        if not c:
            continue
        hit = [o for o, p in pat_cache.items() if p.search(c)]
        if hit:
            stale.append((src.split('_')[0], '0x%x' % a, r[1], hit[:3]))

notes = []
def note(t):
    notes.append({'kind': 'note', 'text': t})

nf = sum(1 for r in out if r['kind'] == 'function')
ng = sum(1 for r in out if r['kind'] == 'global')
nn = sum(1 for r in out if r['kind'] == 'new_global')
note("RESULT: the 'twin' (cm848_calculateFuelDemandLimits 0x19ea4 and the cluster 0x18bc0-0x1b37c plus its Bank 2 position / control diagnostic set) is the position servo of the EGR valve (exhaust gas recirculation), the sibling of variable_geometry_turbocharger_*, named exhaust_gas_recirculation_valve_*. "
     f"It is compiled in and runs every pass but is NOT fitted / driven on this truck. {nf} function rows, {ng} global rows and {nn} new_global rows are proposed (the three shared words fuel_timing_error_scale, boost_fuel_scale_cal and fuel_demand_boost_input are settled as battery voltage and coolant temperature: the two wave 6 uncertain rows are answered). "
     "CODE (proven): (1) setpoint = throttle_fuel_demand_limit (0x40a3a8), the EGR valve command output of the EGR / assist controller cm848_calculateLoadIntegral (a PI controller on throttle_rate_error = fuel_demand_rate_limiter - egr_fraction_actual; fuel_demand_rate_limiter is the rate-limited egr_fraction_combustion_command, cm848_calculateTurboBlendOutput); "
     "the block 0x40a3a2 lines up with the e2m EAC block 0x01169F00 word by word (+0x06 EAC_EGR_Valve_Cmd = 0x40a3a8, +0x0c feedforward = throttle_rate_coeff_snapshot, +0x0e integral term, +0x10 proportional term, +0x12 / +0x1a the P / I gains, +0x14 preset, +0x16 preset lift) and its assist throttle sibling (+0x00 EAC_Asst_Throt_Cmd = throttle_fuel_rate_reference 0x40a3a2) is computed but has no reader anywhere in the binary, while 0x40a3a8 has exactly one reader, the twin. "
     "(2) feedback = sensor channel 75 (0.5-4.5 V, ADC 102 -> -6, ADC 921 -> 15988, fault bits 642 / 643) through a learned zero offset (cm848_updateExhaustGasRecirculationValvePositionAutozero, fault 718) into exhaust_gas_recirculation_valve_position, 12800 = 100 percent; the position source word (0 sensor / 2 default) and the closed flag (boost_fuel_mode_active) are consumed outside the module: the EGR fraction limiter passes its command only while the valve is not closed (or boost_fuel_correction is below boost_fuel_correction_threshold), and cm848_limitMassChargeFlowReference uses the density limit while it is closed. "
     "(3) outputs = the sign of the compensated duty as logical output 68 (direction), |duty| x 2 as PWM on the output channel record of entry 39 (EEPROM 0x860, actuator_output_channel_g_cal), enabled by logical output 67; motor current, mean-squared current, winding / iron core thermal model and over-current / H-bridge fault paths as in the VGT sibling. "
     "E2M (corroboration only; e2m is the .12 file): the EGA / EGR blocks 0x0117AB00 (cal, +0x00 is C_Battery_Voltage_Nominal = 0x4067ea), 0x0117AC00 (state = 0x40a6c2), 0x0117A900 (thermal = 0x40a69e), 0x0117AE00 / 0x0117BF00 / 0x0117CD00 / 0x01190800 / 0x0117C000 (calibration) and 0x01179C00 / 0x01179D00 (position autozero / position, 0x40674e / 0x40a664) agree with the code at equal relative offsets for every row below; EGA_Control_State is documented as the same five states; "
     "e2m names and descriptions say 'EGR valve motor', 'EGR H-bridge', 'EGR valve position'; T_EGA_Cycle_Counter (EGR valve closings over its lifetime) matches DAT_003fdfb4, which cm848_countExhaustGasRecirculationValveClosings increments on each closed hold edge. "
     "DTC: none. The ROM slot table 0x5985a maps faults 642, 643, 718, 720-728 and 795 to slot 170 (no code), and the whole obd_dtc_code_table (0x5b57c, 170 entries) holds no EGR code (no P0400-P0409, P0488, P2412 / P2413); fault 729 = P0299 shares the word 720-735 (e2m Boost_In_Range_Low_Error, not EGR). "
     "FITTED: no. Output channel entry 39 = 0, protection_event_output_line_cal[67] and [68] = 0 (no line), sensor channel 75 reads -2001 = ADC 0 (floor; its ROM config 0x59446 has thresholds 1023 / 0, which a 10-bit reading cannot cross, the same config as channel 101), throttle_fuel_demand_limit = 0, the EGR maps are zero, fault 718 (position autozero error) is set in the dump so the position is the default 9216, and the EGR delta pressure (channel 105, fault 691) and orifice temperature (channel 108, fault 797) low faults are set too - all three EGR sensor inputs read below their limits and none of these faults has a DTC."
     "The module still runs: logical output request 67 is set (dump 0x40c088 = 0x18) and the control state is 3 (autozero drive, duty 0) because the hold counter cannot complete while fault 718 is set. Not proven by code: only the e2m names say 'EGR'; the code proves a position servo with an H-bridge motor whose setpoint comes from the EGR fraction controller.")
note("FAULT BITS (decoded through ROM 0x5985a -> obd_dtc_code_table 0x5b57c; fault n = word n / 16 bit n % 16; e2m word = 0x01103600 + 2 x word): sensor channel 75 high / low = 642 / 643 (e2m EGR_Position_Before_Autozero_High / Low_Error); position autozero error 718 (mask 0x4000 of fault_detected_bits_704_to_719, e2m EGR_Valve_Autozero_Error); "
     "word 720-735 = diagnostic_status_bits (0x3fe9ce, registered copy sensor_fault_status_flags 0x3fea32): 720 / 721 / 722 / 723 H-bridge status bits (masks 1 / 2 / 4 / 8, e2m EGA_Fault_HB1A / HB1B / HB1_OC_HI / HB1_OC_LO), 724 inrush (0x10), 725 position control error (0x20), 726 electrical fault (0x40), 727 driver over-current (0x80), 728 motor over-temperature (0x100) - the e2m masks 1 to 0x100 of 0x0110365A; 729 = P0299 (e2m Boost_In_Range_Low_Error, same word, not this module); "
     "795 valve over-temperature (mask 0x800 of fault_detected_bits_784_to_799; e2m EGA_Valve_Fault_Over_Tmptr is 0x1000 in the .12 file, only the order after the VGT bit agrees); 796 / 797 EGR orifice temperature high / low (channel 108), 690 / 691 EGR delta pressure high / low (channel 105). All of them decode to slot 170 = no DTC. For comparison the VGT valve: 682 / 683 / 709 / 710 / 670 / 671 and 738-746 except 744 have no slot either, 744 (electrical fault) maps to slot 123 = P9978. "
     "I suggest naming the two 720-735 words fault_detected_bits_720_to_735 (0x3fe9ce, was diagnostic_status_bits) and fault_registered_bits_720_to_735 (0x3fea32, was sensor_fault_status_flags) and leaving the P0299 bit unnamed: the boost code shares them (functions 0x5033a0 / 0x52d524 / 0x52e29c / 0x52eae8 read diagnostic_status_bits); they are not in the rows above because their users are not all this module.")
note("CODE ODDITIES (the code wins over the e2m): (a) cm848_estimateExhaustGasRecirculationValveMotorCurrent gates its applied voltage on mask 0x100 of fault_detected_bits_736_to_751 (disassembly 0x1905c-0x19064: lhz -5680 from 0x400000 = 0x3fe9d0), the VGT's electrical fault 744, not on this valve's own electrical fault 726 (mask 0x40 of diagnostic_status_bits); the VGT estimate uses the same bit correctly, so this reads as a copy slip in the source. "
     "(b) cm848_updateExhaustGasRecirculationValveOverTemperatureFault compares (diagnostic_status_bits & 0x100) != 1, which is always true, so mask 0x800 of fault_detected_bits_784_to_799 (fault 795) is set and cleared again in the same call (disassembly 0x19338 sets, 0x19358 clears); the VGT version tests == 0. "
     "(c) the current estimate and the thermal model run unconditionally; the VGT ones need variable_geometry_turbocharger_enable_flag. (d) the code names swap p / d: governor_speed_b_p_gain_* multiplies the error change (derivative gain) and governor_speed_b_d_gain_* the error (proportional gain), governor_speed_p_gain_* is the integral gain; the same swap exists in the EAC controller (throttle_rate_d_gain is its proportional gain, throttle_rate_p_gain its integral gain, throttle_rate_derivative_term its proportional term). "
     "(e) in the dump control state 3 (diagnostic drive, holding duty 0) is permanent because fault 718 keeps the autozero hold counter at 0.")
note("PREFIX: exhaust_gas_recirculation_valve_* mirrors the variable_geometry_turbocharger_* spelling and the caller's example. The brief's allowed list includes egr, and the existing family is egr_fraction_* / egr_mass_flow_*, so egr_valve_* (a plain prefix swap of every new name here, functions cm848_*ExhaustGasRecirculationValve* -> cm848_*EgrValve*) would also be consistent; pick one before applying. "
     "Two choices inside the family: the e2m 'Zero' gain / limit sets (command 0 = valve closing) are named _closed (the VGT's e2m 'Open' sets are _open), and the closed hold words use closed_hold_* (the VGT's open_hold_*).")
note("CONTROL STATE ENUM (suggestion, not a row): exhaust_gas_recirculation_valve_control_state (0x40a6ca) and _previous (0x3fa78e) take 0 closed loop, 1 closed hold (open-loop duty), 2 user duty override, 3 diagnostic (autozero) drive, 4 disabled (logical output 67 clear); an EXHAUST_GAS_RECIRCULATION_VALVE_CONTROL_STATE enum with CLOSED_LOOP / CLOSED_HOLD / DUTY_OVERRIDE / AUTOZERO_DRIVE / DISABLED would type both. The VGT sibling has six states (no autozero drive, two stop-seek states and a driver-disabled state 5), so the two enums stay separate.")
note("LEADS OUTSIDE THIS MODULE (not renamed here): (1) the EGR delta pressure chain on sensor channel 105 (faults 690 / 691 = e2m EGR_Delta_P_Sensor_High / Low_Error; dump: fault 691 set): sensor_channel105_*, boost_pressure_correction_*, boost_correction_* and boost_fuel_correction words, cm848_processFaultProtection (0x18ac0) with cm848_checkProtectionEnableConditions (0x18384), cm848_checkFaultConditionThreshold, cm848_updateFaultStatusRegisters, cm848_selectFaultProtectionValue, fuel_boostCorrection_enableCheck_trimCalc (0x5033a0) and the cranking / cylinder balance diagnostics 0x52e29c / 0x52eae8 that read the valve position; their e2m group is C_EGR_Delta_P_AZ_* / EGR_Delta_Press* / C_EGR_AZ_* (0x01176E00 blocks). boost_decel_mode_flag (0x40a65a) is written by that chain and forces this module's command to 12800 / 0 (key-off autozero precondition: engine speed 0, switch_input_state_bits[0] bit 0 clear, coolant above boost_decel_input_threshold_cal). "
     "(2) the EGR / assist controller cm848_calculateLoadIntegral (0x115cc), cm848_calculateLoadCompensation, cm848_selectLoadAdjustmentLimits, cm848_calculateLoadGainValues and the throttle_* words (all e2m EAC_*): the staged EGR / assist output; the assist throttle half drives nothing. (3) cm848_calculateTurboBlendOutput (0x10b28) = the CHL EGR fraction limiter (fuel_demand_rate_limiter = slew-limited command; e2m C_CHL_EGR_Slew_Up / Down_Rate). (4) the position block 0x40a664 +0 (EGR_Valve_Position_Offset) is the word sensor_channel105_fault_combined+2, written by cm848_updateExhaustGasRecirculationValvePositionAutozero: that dword row is mis-sized (xref_addr.py: no access to 0x40a664 by name).")
note("TYPE / ROW NOTES (no change proposed): 0x4067f2 (exhaust_gas_recirculation_valve_derivative_filter_coefficient) is typed byte but the first-order filter reads it as a word (same as the VGT 0x407720); 0x3fa73e (governor_speed_rate_d, dword: first word = driver over-current clear timer, second word = retry counter, the +2 row is governor_speed_rate_a) and the dwords 0x3fa7bc (cold_start_valid_flag, first word never written outside the init), 0x3fa7ca (cold_start_enable_flag_b: first word = fault retry-active flag, second word = inrush timer at-limit flag), 0x3fa7d0 (cold_start_timing_active_flag) mix two words and are left alone; "
     "0x40a70a / 0x40a716 (autozero_enable_flag / ready_for_autozero_flag) are dword rows used as words; the remaining state words of the H-bridge fault paths are not renamed: 0x3fa7b8 / 0x3fa7ba / 0x3fa7c0 / 0x3fa7c2 / 0x3fa7c4 / 0x3fa7c6 / 0x3fa7c8 (retry-active history and latches), 0x3fa7d4 / 0x3fa7d6 / 0x3fa7d8 / 0x3fa7e2 (inputs read from supervisor_register_162_status and the cold_start_fuel_timer), 0x3fa7da / 0x3fa7dc / 0x3fa7de / 0x3fa7e0 (the latched H-bridge status bits behind faults 720-723, named cold_start_diag_*), 0x3fa7ae / 0x3fa7b0 (never read), 0x3fa7e4, the three flags 0x3fa776 / 0x3fa778 / 0x40a62a of the over-temperature timer that depend on boost_fuel_correction (the EGR valve delta pressure lead above) and the pointer / index words 0x3fa790 / 0x3fa794 / 0x3fa750 of the derivative and delta pressure filters. They need the same boot-ROM scan and a second pass; the function plates already describe them by their current names. "
     "0x4067e8 (control_strong_drive_duty_threshold) is read as unsigned by this code (the VGT 0x407780 is signed i16); 0x406752 (C_EGR_Position_AZ_Fil_Cnst) has no access by name (reached through PTR_DAT_003fbcbe), so it has no new_global row. cm848_bothConditionsTrue (0x1a980) is a generic two-flag AND used only here and keeps its name.")
note("TIME-SHARED CHECK: every renamed or new word inside 0x3F9800-0x3FDB30 (0x3fa73c-0x3fa7f6, 0x3fa758-0x3fa768, 0x3fbccc, 0x3fd7f2-0x3fd800) was checked with xref_addr.py (no user below 0x7F60) and with a scan of the boot ROM 0x0-0x7F5F for instructions with the same low halfword and for 32-bit words equal to the address; the rows quote the result. No type of a time-shared word is changed. Words outside the window (0x3fdce2, 0x3fe9ce, 0x3fea32) are not time-shared.")
note("FOR THE APPLIER: (1) blank-name rows (old = ''): 0x4067b2, 0x4067cc, 0x4067ce, 0x3fa758, 0x3fa760, 0x3fa768, 0x40bd88, 0x40bdae - fill in the name and keep type and comment. (2) new_global rows are typed word (xref_addr.py widths in each row). (3) The row 0x3fd7fe was misnamed governor_speed_rate_d_init_flag and 0x3fd800 cold_start_speed_at_limit_flag: they are the two give-up enable words of the e2m T_EGA_Enable_*_Give_Up pair. "
     "(4) 0x4067ea (boost_fuel_scale_cal -> battery_voltage_nominal) and the battery / coolant words are shared with the VGT module: apply them together with the VGT rows that cite the old names (stale citations below). (5) regenerate firmware_functions.hpp / firmware_globals.hpp after applying. (6) Nothing was run: no CSV, build or git change; the generator is w7/gen_W7c.py in the same directory.")
sl = '; '.join(f"{s} {a} {n} [{', '.join(h)}]" for s, a, n, h in stale[:60])
note(f"STALE CITATIONS (rows not renamed here whose comment cites a name renamed here; refresh when applied; {len(stale)} rows, first {min(len(stale), 60)} listed): {sl}")

# ---- promote the two neutral 720-735 fault words and the closing counter ----
out.append({'kind': 'global', 'address': '0x003fe9ce', 'old': 'diagnostic_status_bits', 'verdict': 'confirmed', 'new': 'fault_detected_bits_720_to_735',
            'evidence': 'code: word 45 of the 50-word fault-detected array that starts at 0x3fe974 ((0x3fe9ce - 0x3fe974) / 2 = 45, faults 720-735, e2m word 0x0110365A); the EGR valve module sets and clears masks 0x01-0x100 (faults 720-728, 725 = position control error), '
                        'the boost code shares the word (fault 729 mask 0x200 = P0299, e2m Boost_In_Range_Low_Error); neutral name like fault_detected_bits_704_to_719 and fault_detected_bits_736_to_751. Not in the time-shared window.'})
out.append({'kind': 'global', 'address': '0x003fea32', 'old': 'sensor_fault_status_flags', 'verdict': 'confirmed', 'new': 'fault_registered_bits_720_to_735',
            'evidence': 'code: word 45 of the fault-registered array that starts at 0x3fe9d8 ((0x3fea32 - 0x3fe9d8) / 2 = 45): the registered copy of fault_detected_bits_720_to_735, cleared together with the detected bit at every clear site of the EGR valve module (masks 0x01-0x100). Not in the time-shared window.'})
out.append({'kind': 'new_global', 'address': '0x003fdfb4', 'new': V('closing_cycle_count_cal'), 'type': 'dword',
            'evidence': 'code: xref_addr.py says dword (1 read / 1 write): incremented by cm848_countExhaustGasRecirculationValveClosings on each rising edge of exhaust_gas_recirculation_valve_closed_hold_flag; inside the EEPROM mirror range 0x3fd482-0x3feec1, so _cal. e2m: T_EGA_Cycle_Counter (0x01192D00, counter for the number of EGR valve closings over its lifetime). Not in the time-shared window.'})
renamed_old['diagnostic_status_bits'] = 'fault_detected_bits_720_to_735'
renamed_old['sensor_fault_status_flags'] = 'fault_registered_bits_720_to_735'

# ---- text fixes, then substitution of renamed old names inside plates and evidence ----
FIX = [
 ("exhaust_gas_recirculation_valve_autozero_enabled_flag", "exhaust_gas_recirculation_valve_autozero_enabled_monitor"),
 ("exhaust_gas_recirculation_valve_coolant_temperature_at_default_flag", "exhaust_gas_recirculation_valve_coolant_temperature_at_or_above_default_flag"),
 (" The code's p / d gain names are swapped: governor_speed_b_p_gain_active is the derivative gain and governor_speed_b_d_gain_active the proportional gain.", ""),
 ("the synthetic boost model and the EGR trims", "the boost_pressure_synthetic_ema regression (cm848_phase_groupA_exponentialAverage; its boost label is inherited from the old name of this word) and the fuel trim lookups cm848_calculateLoadBasedFuelTrim / cm848_calculateRpmBasedFuelTrim"),
 ("(DAT_003fdfb4, e2m T_EGA_Cycle_Counter)", "(exhaust_gas_recirculation_valve_closing_cycle_count_cal, e2m T_EGA_Cycle_Counter)"),
 ("code: DAT_003fdfb4 (dword, 1 read / 1 write) is incremented", "code: exhaust_gas_recirculation_valve_closing_cycle_count_cal (0x3fdfb4, dword, 1 read / 1 write) is incremented"),
 ("(the fourth input comes from bit 0 of switch_input_state_bits[2] instead when bit 0 of fuel_feature_control_flags is set)", "(the third and fourth inputs, masks 4 / 8, both take bit 0x100, or both take bit 0 of switch_input_state_bits[2] when bit 0 of fuel_feature_control_flags is set; the inrush input keeps bit 0x100)"),
]
WAS = re.compile(r'(\(was [^)]*\))')
def subst(text, repl, pats):
    parts = WAS.split(text)
    for i in range(0, len(parts), 2):
        s = parts[i]
        for a, b in FIX:
            s = s.replace(a, b)
        for old, p in pats.items():
            s = p.sub(repl[old], s)
        # collapse "NEW (NEW)" left by 'new (old)' parentheticals
        s = re.sub(r'([a-z0-9_]{12,}) \(\1\)', r'\1', s)
        s = re.sub(r'([a-z0-9_]{12,}) \(\1, ', r'\1 (', s)
        s = re.sub(r'([a-z0-9_]{12,}) \(\1; ', r'\1 (', s)
        s = re.sub(r'([a-z0-9_]{12,}) \(\1: ', r'\1 (', s)
        s = re.sub(r'\(([a-z0-9_]{12,}), \1\)', r'(\1)', s)
        parts[i] = s
    return ''.join(parts)
repl = {o: n for o, n in renamed_old.items() if o}
pats = {o: re.compile(r'(?<![A-Za-z0-9_])' + re.escape(o) + r'(?![A-Za-z0-9_])') for o in repl}
for r in out:
    for k in ('plate_comment', 'evidence'):
        if k in r:
            r[k] = subst(r[k], repl, pats)
    if 'new' in r:
        for a, b in FIX[:2]:
            r['new'] = r['new'].replace(a, b)
    if r['kind'] == 'global' and r.get('old') == '' and 'Time-shared window' in r.get('evidence', ''):
        r['evidence'] = r['evidence'].replace('xref_addr.py lists no access below 0x7F60 and a scan', 'xref_addr.py lists no load / store for it (reached by address, not by name) and a scan')
# residue report: old names still present outside (was ...) clauses
resid = []
for r in out:
    for k in ('plate_comment', 'evidence'):
        if k in r:
            t = ''.join(WAS.split(r[k])[0::2])
            for o, p in pats.items():
                if p.search(t):
                    resid.append((r['address'], k, o))
print('residue', resid)

for n in notes:
    for a, b in [
        ("the EGR maps are zero, fault 718", "fuel_demand_rate_limiter = 0 (and, per the caller, the EGR tables are zero), fault 718"),
        ("and the cranking / cylinder balance diagnostics 0x52e29c / 0x52eae8 that read the valve position", "and the diagnostics 0x52e29c / 0x52eae8, which compare boost_pressure_filtered (now the valve position) with DAT_00409e90 / DAT_00409eb8 under cold_start_phase CSP_CRANKING / CSP_AT_GOVERNOR_SETPOINT conditions"),
        ("(key-off autozero precondition: engine speed 0, switch_input_state_bits[0] bit 0 clear, coolant above boost_decel_input_threshold_cal)", "(set while engine speed is 0, bit 0 of switch_input_state_bits[0] is clear, the coolant and position sources are primary and the coolant is above boost_decel_input_threshold_cal)"),
        ("I suggest naming the two 720-735 words fault_detected_bits_720_to_735 (0x3fe9ce, was diagnostic_status_bits) and fault_registered_bits_720_to_735 (0x3fea32, was sensor_fault_status_flags) and leaving the P0299 bit unnamed: the boost code shares them (functions 0x5033a0 / 0x52d524 / 0x52e29c / 0x52eae8 read diagnostic_status_bits); they are not in the rows above because their users are not all this module.",
         "The two 720-735 words are proposed as neutral global rows (fault_detected_bits_720_to_735 at 0x3fe9ce, was diagnostic_status_bits, and fault_registered_bits_720_to_735 at 0x3fea32, was sensor_fault_status_flags) because the boost code shares them (functions 0x5033a0 / 0x52d524 / 0x52e29c / 0x52eae8 read diagnostic_status_bits); the P0299 bit stays unnamed."),
    ]:
        n['text'] = n['text'].replace(a, b)

rows_out = out + notes
with open(RESULT, 'w') as f:
    for r in rows_out:
        f.write(json.dumps(r) + '\n')
print('written', len(rows_out), 'rows; functions', nf, 'globals', ng + len(EXTRA), 'new_global', nn, 'notes', len(notes), 'stale', len(stale))

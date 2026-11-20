"""Items 23-62 of bin globals2 (bin order)."""

B = []


def add(**kw):
    B.append(kw)


# ---- 23..31 block 81A9: equivalent throttle governor (cm848_calculateFuelDemandWithConditions)
add(addr="0x00409070", new="equivalent_throttle_tracking_integral_gain",
    quote="uVar8 = iVar12 * (uint)governor_speed_integral_gain_cal;",
    evidence="cm848_calculateFuelDemandWithConditions: iVar12 = final_fueling - modeled governor fueling; governor_speed_error_prescaled += iVar12 x governor_speed_integral_gain_cal >> 12 (the integrator of the PI loop that tracks the speed input; the proportional twin governor_speed_proportional_gain_cal at 0x409072 multiplies the same error); e2m 81A9 +0 Equiv_Throt_Integrator_Gain 'Equiv throttle tracking loop integrator gain' (RPM/MM3S, 12466 in the dump = 0.700) resolves here; RAM address, so no _cal.",
    comment="e2m 81A9 +0 Equiv_Throt_Integrator_Gain 'Equiv throttle tracking loop integrator gain' (RPM/MM3S, 0.0000562 per count; 12466 in the dump = 0.700): cm848_calculateFuelDemandWithConditions multiplies (final_fueling - modeled governor fueling) by it >> 12 into governor_speed_error_prescaled, the integrator of the equivalent throttle tracking loop. Twin at +2 is the proportional gain.")

add(addr="0x00409074", new="equivalent_throttle_minimum_droop_slope",
    quote="if (governor_fuel_timing_correction_threshold_cal < uVar8) {",
    evidence="cm848_calculateFuelDemandWithConditions: uVar8 = blend of all_speed_governor_droop_blend_128 / _0 lookups (the droop slope at the speed input); 'if (governor_fuel_timing_correction_threshold_cal < uVar8)' runs the droop tracking loop, else the isochronous branch follows engine_rpm_measured; e2m 81A9 +4 Min_Equiv_Droop_Level 'Minimum droop slope before isochronous gov is assumed' (RPM/MM3S, 0.0015; 7 in the dump = 0.0105) resolves here; minimum = the compare lets the loop run only above it; nothing to do with fuel timing.",
    comment="e2m 81A9 +4 Min_Equiv_Droop_Level 'Minimum droop slope before isochronous gov is assumed' (RPM/MM3S, 0.0015 per count; 7 in the dump = 0.0105): cm848_calculateFuelDemandWithConditions runs the droop tracking loop only while the blended all speed governor droop slope is above it; at or below it the isochronous branch follows engine_rpm_measured.")

add(addr="0x00409076", new="equivalent_throttle_cruise_control_adjust_integral_gain",
    quote="uVar10 = uVar10 * (int)(short)governor_override_integral_gain_cal;",
    evidence="cm848_calculateFuelDemandWithConditions: used only in the cruise branch (cruise_control_engaged_flag != 0) to scale the speed error (cruise_governor_reference_speed - cruise_speed_setpoint_active - vehicle_speed_rise_limited) >> 1 into iVar5 / iVar6 for the two equivalent throttle integrators; e2m 81A9 +6 Equiv_Throt_CC_Adjust_Int_Gain 'Integrator gain ( % throt / Sec MPH )' (S, 0.0061; 115 in the dump = 0.702) resolves here; nothing here is a governor override.",
    comment="e2m 81A9 +6 Equiv_Throt_CC_Adjust_Int_Gain 'Integrator gain ( % throt / Sec MPH )' (UNITLESS, signed, 0.0061 per count; 115 in the dump = 0.702): gain of the cruise control branch (cruise_control_engaged_flag != 0) of the equivalent throttle integrators in cm848_calculateFuelDemandWithConditions, applied to the vehicle speed error.")

add(addr="0x00409078", new="equivalent_throttle_cruise_control_adjust_down_speed_error",
    quote="uVar9 = (uint)(governor_override_integral_error_cal >> 1);",
    evidence="cm848_calculateFuelDemandWithConditions cruise branch: when the drive-down condition holds (adjusted_user_fueling <= final_fueling and below throttle_100_fueling_without_programmable_power minus the margin and the minimum fueling reached, or the vacuum offset mode) the speed error is replaced by +/- (this >> 1), the same halving as the real error ((reference - setpoint - speed) >> 1); e2m 81A9 +8 Equiv_Throt_CC_Adjust_Off_Cal 'CC MPH's to drive integrator down' (MPH 1/256; 1280 in the dump = 5.0 mph) resolves here.",
    comment="e2m 81A9 +8 Equiv_Throt_CC_Adjust_Off_Cal 'CC MPH's to drive integrator down' (MPH, 1/256 per count; 1280 in the dump = 5.0 mph): in the cruise control branch of cm848_calculateFuelDemandWithConditions, while the equivalent throttle is driven down, minus this value (halved like the real speed error) replaces the vehicle speed error.")

add(addr="0x0040907a", new="equivalent_throttle_power_take_off_adjust_integral_gain",
    quote="iVar12 = iVar12 * (short)governor_fuel_integral_gain_cal;",
    evidence="cm848_calculateFuelDemandWithConditions: used in the branch taken when cruise_control_engaged_flag == 0 (power take-off governor active) to scale power_take_off_governor_droop_compensated_speed_error (or its drive-down substitute) for both integrators; e2m 81A9 +A Equiv_Throt_PTO_Adjust_Int_Gain 'Integrator gain ( % throt / Sec RPM )' (S, 0.0061; 541 in the dump = 3.30) resolves here.",
    comment="e2m 81A9 +A Equiv_Throt_PTO_Adjust_Int_Gain 'Integrator gain ( % throt / Sec RPM )' (UNITLESS, signed, 0.0061 per count; 541 in the dump = 3.30): gain of the power take-off branch (cruise_control_engaged_flag = 0) of the equivalent throttle integrators in cm848_calculateFuelDemandWithConditions, applied to the power take-off speed error.")

add(addr="0x0040907c", new="equivalent_throttle_power_take_off_adjust_down_speed_error",
    quote="iVar11 = (int)(short)governor_fuel_integral_error_clamp_cal;",
    evidence="cm848_calculateFuelDemandWithConditions power take-off branch: when the drive-down condition holds the speed error is replaced by iVar11 = this, iVar12 = -iVar11 (the fuel integrator then falls, the speed integrator is wound towards 0), else power_take_off_governor_droop_compensated_speed_error is used; e2m 81A9 +C Equiv_Throt_PTO_Adjust_Off_Cal 'PTO RPM's to drive integrator down' (RPM 0.125; 640 in the dump = 80 rpm) resolves here; it is not a clamp.",
    comment="e2m 81A9 +C Equiv_Throt_PTO_Adjust_Off_Cal 'PTO RPM's to drive integrator down' (RPM, 0.125 per count; 640 in the dump = 80 rpm): in the power take-off branch of cm848_calculateFuelDemandWithConditions, while the equivalent throttle is driven down, minus this value replaces the power take-off speed error (read as a signed short).")

add(addr="0x0040907e", new="equivalent_throttle_negative_adjust_enable",
    quote="if (governor_rpm_integral_enable_cal == 0) {",
    evidence="cm848_calculateFuelDemandWithConditions: == 0 zeroes governor_rpm_integral_term_working; otherwise governor_rpm_integral runs between -(equivalent throttle << 16) and 0 (a negative-only term that integrates the throttle down to 0), while the other integrator governor_fuel_integral_accumulator is limited to 0..0x1900000 (positive); e2m 81A9 +E Negative_Equiv_Throt_Adjust 'Whether or not equivalent throttle value will integrate down to 0.' (1 in the dump) resolves here.",
    comment="e2m 81A9 +E Negative_Equiv_Throt_Adjust 'Whether or not equivalent throttle value will integrate down to 0.' (UNITLESS 0..65535; 1 in the dump): 0 zeroes the second integrator term in cm848_calculateFuelDemandWithConditions; non-zero lets that term run between 0 and minus the equivalent throttle, so the throttle can integrate down to 0.")

add(addr="0x00409080", new="equivalent_throttle_negative_adjust_minimum_fueling",
    quote="((uint)governor_integral_fuel_min_cal <= (uint)final_fueling)) || (bVar1)) {",
    evidence="cm848_calculateFuelDemandWithConditions: the drive-down substitute error is taken only when (adjusted_user_fueling <= final_fueling && adjusted_user_fueling < throttle_100_fueling_without_programmable_power - margin && governor_integral_fuel_min_cal <= final_fueling) || bVar1, so the code needs final_fueling at or above it (a minimum), while the e2m text says 'Fueling below which equivalent throttle will start ramp back to zero'; e2m 81A9 +10 Min_Fueling_Negative_Equiv_Throt_Adjust (MM3S 0.0679; 74 in the dump = 5.03 mm3) resolves here.",
    comment="e2m 81A9 +10 Min_Fueling_Negative_Equiv_Throt_Adjust 'Fueling below which equivalent throttle will start ramp back to zero.' (MM3S, 0.0679 mm3 per count; 74 in the dump = 5.03 mm3): minimum final_fueling for the drive-down condition of cm848_calculateFuelDemandWithConditions (the code needs minimum <= final_fueling).")

add(addr="0x00409084", new="equivalent_throttle_positive_adjust_fueling_margin",
    quote="(uint)fuel_correction_hysteresis_cal))) &&",
    evidence="cm848_calculateFuelDemandWithConditions: drive-down needs adjusted_user_fueling < throttle_100_fueling_without_programmable_power - fuel_correction_hysteresis_cal (a margin below the maximum throttle fueling, not a hysteresis band); the positive integrator governor_fuel_integral_accumulator is the 0..0x1900000 one; e2m 81A9 +14 Max_Fueling_Positive_Throt_Adjust 'Fueling below max throttle which equivalent throttle will ramp up to 100%' (MM3S 0.0679; 147 in the dump = 9.99 mm3) resolves here.",
    comment="e2m 81A9 +14 Max_Fueling_Positive_Throt_Adjust 'Fueling below max throttle which equivalent throttle will ramp up to 100%' (MM3S, 0.0679 mm3 per count; 147 in the dump = 9.99 mm3): margin below throttle_100_fueling_without_programmable_power; cm848_calculateFuelDemandWithConditions drives the equivalent throttle down only while adjusted_user_fueling is below that fueling minus this margin.")

# ---- 32..54 block 81AE: cylinder balance
add(addr="0x00408ee2", new="cylinder_balance_fueling_filter_coefficient",
    quote="(uint)cbd_fuel_demand_blend_scale_cal;",
    evidence="hpcr_processLoadThrottle: cylinder_balance_filtered_fueling = final_fueling + ((cylinder_balance_filtered_fueling - final_fueling) x this >> 13), clamped to 0..0x1700, so it is the weight of the previous value in 1/8192 (0 in the dump = no filtering); e2m 81AE +0 CBD_Fueling_Filter_Constant 'Cylinder Balancing Fueling Filter Constant' (1/8192 per count) resolves here; wave 13 turned e2m Filter_Constant into _filter_coefficient (commanded_throttle_filter_coefficient).",
    comment="e2m 81AE +0 CBD_Fueling_Filter_Constant 'Cylinder Balancing Fueling Filter Constant' (UNITLESS, 1/8192 per count; 0 in the dump): weight of the previous value in the low pass that hpcr_processLoadThrottle applies to final_fueling to make cylinder_balance_filtered_fueling (0 = no filtering).")

add(addr="0x00408eea", new="cylinder_balance_fourier_filter_coefficient",
    quote="uVar11 = (uint)cylinder_timing_scale_cal;",
    evidence="hpcr_cbdCalculateCylinderTrims: uVar11 multiplies (old - new) >> 13 in the low pass of cylinder_balance_fourier_real_component_1 / _imaginary_component_1, cylinder_balance_adjusted_real_component_2 / _imaginary_component_2 and cylinder_balance_adjusted_real_component_3 (0 in the dump = no filtering); e2m 81AE +8 CBD_FFT_Filter_Coeff 'FFT Filter Constant' resolves here; no cylinder timing scale.",
    comment="e2m 81AE +8 CBD_FFT_Filter_Coeff 'FFT Filter Constant' (UNITLESS, 1/8192 per count; 0 in the dump): weight of the previous value in the low pass of the cylinder balance Fourier components (first harmonic, adjusted second and third) in hpcr_cbdCalculateCylinderTrims (0 = no filtering).")

add(addr="0x00408eec", new="cylinder_balance_dynamic_compensation_filter_coefficient",
    quote="(uint)cam_timing_delta_scale_cal;",
    evidence="hpcr_cbdCalculateCylinderTrims: in the zero fueling window cylinder_balance_real_dynamic_compensation_cal = clamp(new - ((new - old) x this >> 13)), same for the imaginary one, so it is the weight of the previous value in 1/8192 (4096 in the dump = 0.5); e2m 81AE +A CBD_Error_Filter_Constant 'Cylinder Balancing Error Filter Constant' resolves here (the filtered error is the learned crank tooth error); wave 13 bin 2 report: 'cam_timing_*' needs a pass; wave 13 turned e2m Filter_Constant into _filter_coefficient.",
    comment="e2m 81AE +A CBD_Error_Filter_Constant 'Cylinder Balancing Error Filter Constant' (UNITLESS, 1/8192 per count; 4096 in the dump = 0.5): weight of the previous value in the filter that updates the real and imaginary dynamic compensation (the learned crank tooth error) in hpcr_cbdCalculateCylinderTrims.")

REF1 = [("0x00408ef8", "1_cylinder_1_real", "+16 CBD_Reference_1_Cylinder_1_Real", "6cyl_a", "8124", "iVar2 *"),
        ("0x00408efa", "1_cylinder_1_imaginary", "+18 CBD_Reference_1_Cylinder_1_Imag", "6cyl_b", "1055", "iVar9"),
        ("0x00408efc", "1_cylinder_5_real", "+1A CBD_Reference_1_Cylinder_5_Real", "6cyl_c", "3148", "iVar2 *"),
        ("0x00408efe", "1_cylinder_5_imaginary", "+1C CBD_Reference_1_Cylinder_5_Imag", "6cyl_d", "7563", "iVar9"),
        ("0x00408f00", "1_cylinder_3_real", "+1E CBD_Reference_1_Cylinder_3_Real", "6cyl_e", "-4976", "iVar2 *"),
        ("0x00408f02", "1_cylinder_3_imaginary", "+20 CBD_Reference_1_Cylinder_3_Imag", "6cyl_f", "6508", "iVar9")]
REF2 = [("0x00408f04", "2_cylinder_1_real", "+22 CBD_Reference_2_Cylinder_1_Real", "4cyl_a", "-8190", "iVar3 *"),
        ("0x00408f06", "2_cylinder_1_imaginary", "+24 CBD_Reference_2_Cylinder_1_Imag", "4cyl_b", "143", "iVar10"),
        ("0x00408f08", "2_cylinder_5_real", "+26 CBD_Reference_2_Cylinder_5_Real", "4cyl_c", "3971", "iVar3 *"),
        ("0x00408f0a", "2_cylinder_5_imaginary", "+28 CBD_Reference_2_Cylinder_5_Imag", "4cyl_d", "-7165", "iVar10"),
        ("0x00408f0c", "2_cylinder_3_real", "+2A CBD_Reference_2_Cylinder_3_Real", "4cyl_e", "4219", "iVar3 *"),
        ("0x00408f0e", "2_cylinder_3_imaginary", "+2C CBD_Reference_2_Cylinder_3_Imag", "4cyl_f", "7022", "iVar10")]
QUOTES = {
    "0x00408ef8": "uVar15 = (short)cylinder_balance_coeff_6cyl_a_cal * iVar2 +",
    "0x00408efa": "(short)cylinder_balance_coeff_6cyl_b_cal * iVar9;",
    "0x00408efc": "uVar15 = (short)cylinder_balance_coeff_6cyl_c_cal * iVar2 +",
    "0x00408efe": "(short)cylinder_balance_coeff_6cyl_d_cal * iVar9;",
    "0x00408f00": "uVar15 = (short)cylinder_balance_coeff_6cyl_e_cal * iVar2 +",
    "0x00408f02": "(short)cylinder_balance_coeff_6cyl_f_cal * iVar9;",
    "0x00408f04": "uVar15 = (short)cylinder_balance_coeff_4cyl_a_cal * iVar3 +",
    "0x00408f06": "(short)cylinder_balance_coeff_4cyl_b_cal * iVar10;",
    "0x00408f08": "uVar15 = (short)cylinder_balance_coeff_4cyl_c_cal * iVar3 +",
    "0x00408f0a": "(short)cylinder_balance_coeff_4cyl_d_cal * iVar10;",
    "0x00408f0c": "uVar15 = (short)cylinder_balance_coeff_4cyl_e_cal * iVar3 +",
    "0x00408f0e": "(short)cylinder_balance_coeff_4cyl_f_cal * iVar10;",
}
for table, harmonic in ((REF1, 1), (REF2, 2)):
    comp_real = "cylinder_balance_fourier_real_component_1" if harmonic == 1 else "cylinder_balance_adjusted_real_component_2"
    comp_imag = "cylinder_balance_fourier_imaginary_component_1" if harmonic == 1 else "cylinder_balance_adjusted_imaginary_component_2"
    used = "six cylinder engines only" if harmonic == 1 else "six and four cylinder engines"
    for addr, suffix, record, oldtag, dump, _ in table:
        cyl = suffix.split("_")[2]
        real = suffix.split("_")[3] == "real"
        scaled = f"{int(dump) / 8192:.3f}"
        if harmonic == 1:
            evid_extra = ("Reference_1 pairs are used only when the cylinder count is 6 and multiply the first harmonic components "
                          "(iVar2 = cylinder_balance_fourier_real_component_1, iVar9 = cylinder_balance_fourier_imaginary_component_1)")
        else:
            evid_extra = ("Reference_2 pairs multiply the second harmonic components (iVar3 = cylinder_balance_adjusted_real_component_2, "
                          "iVar10 = cylinder_balance_adjusted_imaginary_component_2) for cylinder counts 6 and 4, so the old 4cyl name was wrong")
        if real:
            how = f"forms ({comp_real} x it + {comp_imag} x the next word) >> 13"
        else:
            how = f"forms ({comp_real} x the previous word + {comp_imag} x it) >> 13"
        add(addr=addr, new=f"cylinder_balance_reference_{suffix}",
            quote=QUOTES[addr],
            evidence=(f"hpcr_cbdCalculateCylinderTrims ({oldtag} pair): (a x real + b x imaginary) >> 13 with the harmonic {harmonic} components rates cylinder {cyl} "
                      f"(cylinders 6 / 2 / 4 are the negated entries); {evid_extra}; e2m 81AE {record} (S, 1/8192; {dump} in the dump = {scaled}) resolves here; "
                      f"the 6cyl / 4cyl guess in the old name is wrong (cylinders 1 / 5 / 3 are the slots 0 / 1 / 2 of the firing order 1-5-3-6-2-4, as in the e2m)."),
            comment=(f"e2m 81AE {record} (signed, 1/8192 per count; {dump} in the dump = {scaled}): "
                     f"{'real' if real else 'imaginary'} part of the harmonic {harmonic} reference vector of cylinder {cyl}. "
                     f"hpcr_cbdCalculateCylinderTrims {how} to rate the cylinders ({used})."))

add(addr="0x00408f10", new="cylinder_balance_reference_3",
    quote="uVar15 = (int)(short)crank_state_default_value_cal & 0xff;",
    evidence="hpcr_cbdCalculateCylinderTrims: row index of the third harmonic table at ROM 0x57cde (16-byte rows): its low byte when cylinder_balance_adjusted_real_component_3 is negative, else 1 when it is 0 and 0 otherwise ('else if (crank_state_default_value_cal == 0) uVar15 = 1'); e2m 81AE +2E CBD_Reference_3 (S, scale 1, -1..1; 1 in the dump) resolves here; no crank state.",
    comment="e2m 81AE +2E CBD_Reference_3 'Cylinder Balancing Reference_3' (UNITLESS, signed, range -1..1; 1 in the dump): selects the row of the third harmonic table in hpcr_cbdCalculateCylinderTrims: its low byte while cylinder_balance_adjusted_real_component_3 is negative, else 1 when it is 0 and 0 otherwise.")

add(addr="0x00408f12", new="cylinder_balance_start_tooth",
    quote="bVar1 = cbd_sync_byte_a_cal;",
    evidence="hpcr_cbdFillAccelerationBuffers: bVar1 = this (or misfire_monitor_speed_buffer_start_tooth when the misfire speed buffer is enabled); when the low byte of tpu_a_ch0_param0.PARAM4 equals it and cylinder_event_seq_counter is 0xff the capture of the six acceleration buffers starts; e2m 81AE +30 CBD_Start_Tooth (U, 1 B; 15 in the dump) resolves here.",
    comment="e2m 81AE +30 CBD_Start_Tooth 'Cylinder Balancing Start Tooth' (UNITLESS, 1 B; 15 in the dump): hpcr_cbdFillAccelerationBuffers starts a new capture of the cylinder balance acceleration buffers when the low byte of TPU-A channel 0 PARAM4 (the crank tooth) equals it; the misfire monitor has its own start tooth.")

add(addr="0x00408f13", new="cylinder_balance_dynamic_compensation_reset_enable",
    quote="if (cam_timing_reset_enable_cal == 1) {",
    evidence="hpcr_cbdCalculateCylinderTrims: == 1 sets cylinder_balance_real_dynamic_compensation_cal and cylinder_balance_imaginary_dynamic_compensation_cal to 0 on every pass (0 in the dump = off); e2m 81AE +31 CBD_Dynamics_Compensation_Reset_N (U, 1 B, 0..1) resolves here; wave 13 bin 2 report: 'cam_timing_*' needs a pass.",
    comment="e2m 81AE +31 CBD_Dynamics_Compensation_Reset_N 'Cylinder Balancing Dynamics Compensation Reset' (UNITLESS, 1 B, 0..1; 0 in the dump): 1 zeroes the real and imaginary dynamic compensation (cylinder_balance_real_dynamic_compensation_cal, cylinder_balance_imaginary_dynamic_compensation_cal) on every pass of hpcr_cbdCalculateCylinderTrims.")

add(addr="0x00408f16", new="cylinder_balance_intake_manifold_temperature_threshold",
    quote="(short)crank_sync_load_threshold_cal)))))))) {",
    evidence="hpcr_cbdCalculateCylinderTrims: '(short)intake_manifold_temperature_sensor_filtered <= (short)crank_sync_load_threshold_cal' is one term of the OR chain that clears the trim terms (no learning), next to the coolant term at 0x408f14 (e2m CBD_Coolant_Temp_Threshold); e2m 81AE +34 CBD_Intake_Air_Temp_Threshold 'Cyl balance disabled below this intake air temp' (DEG_F S, 1/64; -3200 in the dump = -50 F) resolves here; sensor slot 9 is the intake manifold temperature; no load or crank sync.",
    comment="e2m 81AE +34 CBD_Intake_Air_Temp_Threshold 'Cyl balance disabled below this intake air temp' (DEG_F, signed, 1/64 per count; -3200 in the dump = -50 F): hpcr_cbdCalculateCylinderTrims clears the trims and learning while intake_manifold_temperature_sensor_filtered is at or below it.")

add(addr="0x00408f18", new="cylinder_balance_cutout_disable_time",
    quote="crank_state_debounce_timer = crank_state_debounce_timer_cal;",
    evidence="hpcr_cbdCalculateCylinderTrims: crank_state_debounce_timer (0x3fb57e) counts down every pass and is reloaded from this while cylinder_cutout_test_mask != 0; 'crank_state_debounce_timer != 0' is a term of the disable chain, so the balance stays off until it reaches 0 after a cylinder cutout; e2m 81AE +36 CBD_Cutout_Disable_Time 'Time delay before CBD resumes after cyl cutout' (SEC 0.2; 50 in the dump = 10 s) resolves here; no crank state.",
    comment="e2m 81AE +36 CBD_Cutout_Disable_Time 'Time delay before CBD resumes after cyl cutout' (SEC, 0.2 per count; 50 in the dump = 10 s): hpcr_cbdCalculateCylinderTrims reloads its countdown with it while a cylinder cutout test is active (cylinder_cutout_test_mask != 0); the balance stays disabled until the countdown reaches 0.")

add(addr="0x00408f1c", new="cylinder_balance_component_3_adjustment",
    quote="(unaff_r25 - cylinder_diag_offset_cal) +",
    evidence="hpcr_cbdCalculateCylinderTrims: cylinder_balance_adjusted_real_component_3 = low pass of (third harmonic sum unaff_r25 - cylinder_diag_offset_cal); e2m 81AE +3A CBD_Comp_3_Adjustment 'Cylinder Balancing Comp_3 Adjustment' (S, 1, -32000..32000; 0 in the dump) resolves here; no cylinder diagnostic.",
    comment="e2m 81AE +3A CBD_Comp_3_Adjustment 'Cylinder Balancing Comp_3 Adjustment' (UNITLESS, signed, -32000..32000; 0 in the dump): offset subtracted from the third harmonic sum before hpcr_cbdCalculateCylinderTrims low-pass filters it into cylinder_balance_adjusted_real_component_3.")

add(addr="0x00408f1e", new="cylinder_balance_fourier_threshold",
    quote="uVar15 = (uint)cylinder_diag_timing_delta_threshold_cal;",
    evidence="hpcr_cbdCalculateCylinderTrims: the trim gain cylinder_balance_fueling_trim_gain is used for a harmonic only when |real| + |imaginary| (third harmonic: |real|) of its components is above it ('if (iVar4 + iVar3 <= uVar15) wVar8 = 0'); e2m 81AE +3C CBD_FFT_Threshold (U, 1, 0..65535; 0 in the dump) resolves here; no cylinder diagnostic timing delta.",
    comment="e2m 81AE +3C CBD_FFT_Threshold 'Cylinder Balancing FFT Threshold' (UNITLESS, 0..65535; 0 in the dump): hpcr_cbdCalculateCylinderTrims applies cylinder_balance_fueling_trim_gain for a harmonic only while its magnitude (|real| + |imaginary|, |real| for the third) is above it.")

add(addr="0x00408f22", new="cylinder_balance_dynamic_compensation_reference_speed",
    quote="uVar7 = (uint)cylinder_timing_rpm_divisor_cal;",
    evidence="hpcr_cbdCalculateCylinderTrims: in the zero fueling window the measured dynamic compensation is scaled 'unaff_r27 = (int)(uVar15 * unaff_r27) / (int)uVar7' with uVar15 = filtered engine speed and uVar7 = this (clamped to +/-0x7fff) before it is learned; e2m 81AE +40 CBD_Comp_Ref_RPM 'Crank sensor tooth error comp normalized at this speed' (RPM 0.125; 6000 in the dump = 750 rpm) resolves here.",
    comment="e2m 81AE +40 CBD_Comp_Ref_RPM 'Crank sensor tooth error comp normalized at this speed' (RPM, 0.125 per count; 6000 in the dump = 750 rpm): in the zero fueling window hpcr_cbdCalculateCylinderTrims scales the measured dynamic compensation by engine speed / this speed before it learns it.")

# ---- 55..59 block 81B0 acceleration buffers
for k, (addr, off, quote) in enumerate([("0x0040b74c", "+12", "(&cylinder1_timing_offset)[cylinder_event_seq_counter] ="),
                                        ("0x0040b74e", "+14", "iVar3 = (int)(short)cylinder2_timing_offset;"),
                                        ("0x0040b750", "+16", "unaff_r27 = (int)(short)((cylinder3_timing_offset + cylinder_balance_acceleration_buffer_6) -"),
                                        ("0x0040b752", "+18", "iVar4 = (int)(short)cylinder4_timing_offset;"),
                                        ("0x0040b754", "+1A", "iVar2 = (int)(short)cylinder5_timing_offset;")], start=1):
    add(addr=addr, new=f"cylinder_balance_acceleration_buffer_{k}",
        quote=quote,
        evidence=(f"hpcr_cbdFillAccelerationBuffers stores (TPU-A channel 14 capture difference >> 2) at (&cylinder1_timing_offset)[cylinder_event_seq_counter] (firing event 0..5), "
                  f"hpcr_cbdCalculateCylinderTrims sums the six words into the first / second / third harmonic and the misfire monitor indexes them too; "
                  f"e2m 81B0 {off} CBD_Accel_Buffer_{k} 'Cylinder Balancing Accelaration Buffer_{k}' (S, 1; 0 in the dump) resolves here, and cylinder_balance_acceleration_buffer_6 (+1C) follows at 0x40b756; "
                  f"these are firing event samples, not cylinder timing offsets."),
        comment=(f"e2m 81B0 {off} CBD_Accel_Buffer_{k} 'Cylinder Balancing Accelaration Buffer_{k}' (UNITLESS, signed; 0 in the dump): crank acceleration sample of firing event {k} of the cycle: hpcr_cbdFillAccelerationBuffers stores the TPU capture time difference >> 2 here, hpcr_cbdCalculateCylinderTrims sums the buffers into the harmonics, and the misfire monitor reads them. Next: cylinder_balance_acceleration_buffer_{k + 1}."
                 if k < 5 else
                 "e2m 81B0 +1A CBD_Accel_Buffer_5 'Cylinder Balancing Accelaration Buffer_5' (UNITLESS, signed; 0 in the dump): crank acceleration sample of firing event 5 of the cycle: hpcr_cbdFillAccelerationBuffers stores the TPU capture time difference >> 2 here, hpcr_cbdCalculateCylinderTrims sums the buffers into the harmonics, and the misfire monitor reads them. Next: cylinder_balance_acceleration_buffer_6."))

# ---- 60 8A14 drift / 8A2A
add(addr="0x004086c6", new="ambient_air_pressure_initial_scaling_factor",
    quote="(uint)protection_iat_scale_factor_cal) / 100);",
    evidence="cm848_processSensorTemperatureData: protection_iat_scaled = sensor_readings_t_0040baf2.barometric_pressure x this / 100 (107 in the dump = 1.07), and protection_iat_scaled is the y axis (ROM 0x5b3d8: 1257..1823 counts = 20..29 inHg) of the intake air heater preheat table in cm848_computeIntakeAirHeaterPreheatDuration; the bin's record (8A14 +2C AC_Anti_Slugging_Driver_Off_Time) is the known 8A14 drift (the AC block ends at +2A); the code matches e2m 8A2A +0 APC_Initial_Scaling_Factor (UNITLESS 0.01, 0.5..1.5), which resolves here too; no intake air temperature is involved.",
    comment="e2m 8A2A +0 APC_Initial_Scaling_Factor 'Multiplier used to scale Boost_Pressure for initial Ambient_Air reading' (UNITLESS, 0.01 per count, 0.5..1.5; 107 in the dump = 1.07): cm848_processSensorTemperatureData scales the barometric pressure by it / 100 into the ambient pressure input (20..29 inHg y axis) of the intake air heater preheat table. e2m 8A14 +2C resolves here too: drift.")

# ---- 61, 62 keeps
B.append(dict(addr="0x0040b56a", keep=True,
              e2m_note="e2m 8C4E +0 OSS_Fault_Timer 'Time for OSS rationality test to fail' (SEC .01; 300 in the dump = 3.00 s)",
              evidence="cm848_monitorTransmissionOutputSpeedSensor (P0720): output_speed_sensor_check_fault_set_timer counts down while transmission_output_speed_sensor_filtered is below output_speed_sensor_check_minimum_output_speed and sets fault 320 at 0, and reloads from output_speed_sensor_check_fault_set_passes (300) otherwise; matches e2m 8C4E +0; e2m 8C58 +C RE_Governor_Pr_Mid_Rat_Pass_Timer also resolves here (the 8C58 tail overlaps 8C4E), the P0720 code matches 8C4E; set = sets the fault, more specific than the record."))
B.append(dict(addr="0x0040b56c", keep=True,
              e2m_note="e2m 8C4E +2 OSS_Passed_Timer 'Time for OSS rationality test to pass' (SEC .01; 300 in the dump = 3.00 s)",
              evidence="cm848_monitorTransmissionOutputSpeedSensor (P0720): output_speed_sensor_check_fault_heal_timer counts down while the filtered output speed is at or above the minimum and clears fault 320 at 0, and reloads from output_speed_sensor_check_fault_heal_passes (300) otherwise; matches e2m 8C4E +2; e2m 8C58 +E RE_Governor_Pr_Mid_Rat_Pass_This_DC also resolves here (the 8C58 tail overlaps 8C4E), the P0720 code matches 8C4E; heal = clears the fault, more specific than the record."))

"""patch_text.py: apply the advisor's text fixes to build.py (exact replacements, each must hit the expected count)."""
P = "/tmp/w14_functions1/build.py"
s = open(P).read()
edits = [
    # 0xe518 evidence/plate: masks, and the source 3 wording
    ("bit 0 of governor_feature_flags set -> 1; ", "mask 0x01 of governor_feature_flags set -> 1; ", 1),
    ("bit 0x4000 of governor_fault_status_flags set, fault_derate_active_flag = 1 and no running alpha_altitude_derate_timer \"\n    \"with bit 0x20 of feature_enable_flags_cal set -> 3; else 0.",
     "mask 0x4000 of governor_fault_status_flags set and fault_derate_active_flag = 1, unless alpha_altitude_derate_timer is nonzero \"\n    \"while mask 0x20 of feature_enable_flags_cal is set -> 3; else 0.", 1),
    # 0x50716c
    ("when bit 2 of egr_orifice_temperature_state (sensor status confirmed) is clear", "when mask 0x02 of egr_orifice_temperature_state (sensor status 2, confirmed) is clear", 1),
    ("0 primary, 2 default): when bit 2 of \"\n    \"egr_orifice_temperature_state (the sensor channel 108 fault status is confirmed) is clear",
     "0 primary, 2 default): when mask 0x02 of \"\n    \"egr_orifice_temperature_state (the sensor channel 108 fault status 2, confirmed) is clear", 1),
    # 0x173a8
    ("switch_input_state_bits[0] bit 0x80 set (switch 7 accelerator at idle) and [1] bit 1 clear (switch 8 off idle)",
     "switch_input_state_bits[0] mask 0x80 set (switch 7 accelerator at idle) and [1] mask 0x01 clear (switch 8 off idle)", 1),
    ("switch 7 (accelerator at idle, switch_input_state_bits[0] bit 0x80) is on and switch 8 (off idle, [1] bit 1) is off",
     "switch 7 (accelerator at idle, switch_input_state_bits[0] mask 0x80) is on and switch 8 (off idle, [1] mask 0x01) is off", 1),
    # 0x1eae8
    ("fuel_limit_mode_flags are the 1053 +A flags: bit 0 Throttle_Decrease_Flag set when the error is negative, bit 1 Throttle_Transient_Flag set when the candidate constant drops and ",
     "fuel_limit_mode_flags are the 1053 +A flags: mask 0x01 Throttle_Decrease_Flag set when the error is negative, mask 0x02 Throttle_Transient_Flag set when the candidate constant drops and ", 1),
    ("holds the e2m 1053 +A flags (bit 0 \"\n    \"Throttle_Decrease_Flag, bit 1 Throttle_Transient_Flag): a drop of the candidate starts a transient (bit 0 also set when the error is negative, i.e. the throttle is decreasing) and it ends ",
     "holds the e2m 1053 +A flags (mask 0x01 \"\n    \"Throttle_Decrease_Flag, mask 0x02 Throttle_Transient_Flag): a drop of the candidate starts a transient (mask 0x01 also set when the error is negative, i.e. the throttle is decreasing) and it ends ", 1),
    # 0x1f17c
    ("added when bit 12 of algorithm_enable_flags_41_cal is set,", "added when mask 0x1000 of algorithm_enable_flags_41_cal (reserved_bit_12) is set,", 1),
    # 0x13dc8 plate: the two filter stages only run with the compensation on
    ("and filters intake_manifold_temperature_after_lead with two cascaded cm848_signedFirstOrderFilter stages \"\n    \"(pressure_correction_first_filter / pressure_correction_second_filter, coefficient e2m 18D6 +0 C_TPE_IMT_Lag_Filter_Constant). ",
     "and filters intake_manifold_temperature_after_lead with two cascaded cm848_signedFirstOrderFilter stages \"\n    \"(pressure_correction_first_filter / pressure_correction_second_filter, coefficient e2m 18D6 +0 C_TPE_IMT_Lag_Filter_Constant), but only with the compensation on (sensor status 0, bypass cal 0 and mask 0x4000 of \"\n    \"algorithm_enable_flags_20_cal set); otherwise intake_manifold_temperature_after_lead passes through unfiltered. ", 1),
]
for old, new, n in edits:
    c = s.count(old)
    if c != n:
        raise SystemExit(f"expected {n} hit(s), got {c}: {old[:80]!r}")
    s = s.replace(old, new)
open(P, "w").write(s)
print("patched", len(edits), "edits")

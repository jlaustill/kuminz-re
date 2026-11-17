import sys
sys.path.insert(0, "/home/linux/.claude/jobs/d55ae3c6/tmp/renames/scratch_W6_injection_rail")
from rw import *

# ---------------------------------------------------------------- N34: combustion limit tables + CBO cals
E34 = ("Code: cm848_applyCombustionTimingLimits ({fn}). Names reuse the W5 combustion_rom proposal (same strings) and the wave-4 injection note; "
       "e2m C_CBL_SOI_Min_* / C_CBL_SOI_Max_* order is corroboration only. 0x405xxx is outside 0x3fd482-0x3feec1, so no _cal.")
gl("0x0040523e", "injection_timing_rpm_axis_cal", "confirmed", "injection_timing_combustion_minimum_limit_x_axis",
   "Code: x input of the first cm848_dualAxisTableInterpolation call in cm848_applyCombustionTimingLimits (x = engine_rpm_state.current_rpm), result = injection_timing_combustion_minimum_limit. Same string as the W5 combustion_rom proposal. Outside the EEPROM range, no _cal.")
gl("0x00405266", "injection_timing_load_axis_cal", "confirmed", "injection_timing_combustion_minimum_limit_y_axis",
   "Code: y input of the same call (y = fuel_quantity_compensated_reference, the CBO fuel output) for the minimum limit. Same string as W5.")
gl("0x00405288", "injection_timing_advance_yend_cal", "confirmed", "injection_timing_combustion_minimum_limit_grid",
   "Code: z grid (19 x 16 words, 304 entries) of the same call; the output is the minimum main timing limit. Same string as W5.")
gl("0x004054e8", "injection_timing_mode2_rpm_axis_cal", "confirmed", "injection_timing_combustion_maximum_limit_x_axis",
   "Code: x input of the second dualAxis call in cm848_applyCombustionTimingLimits (current_rpm), result stored in injection_timing_main_base_before_override and copied to injection_timing_combustion_maximum_limit. Same string as W5.")
gl("0x00405510", "injection_timing_mode2_ystart_cal", "confirmed", "injection_timing_combustion_maximum_limit_y_axis",
   "Code: y input of the second call (fuel_quantity_compensated_reference). Same string as W5.")
gl("0x00405532", "injection_timing_mode2_yend_cal", "confirmed", "injection_timing_combustion_maximum_limit_grid",
   "Code: z grid (304 entries) of the second call; output = maximum main timing limit (the clamp keeps the result at or below it, fuel_demand_mode_code 27). Same string as W5.")
gl("0x00405a0c", "engine_load_correction_lower_cal", "confirmed", "injection_timing_reference_delta_lower_limit",
   "Code: cm848_calculateTimingReferenceDeltaAdjustment clamps injection_timing_reference_delta_clamped = injection_timing_combustion_reference - main_injection_timing_for_air_handling to lower..upper; the clamp is the only use. e2m C_CBO_Delta_SOI_Min (offset match only). Outside the EEPROM range, no _cal.")
gl("0x00405a0e", "engine_load_correction_upper_cal", "confirmed", "injection_timing_reference_delta_upper_limit",
   "Code: upper bound of the same clamp in cm848_calculateTimingReferenceDeltaAdjustment. e2m C_CBO_Delta_SOI_Max (offset match only).")
gl("0x00405a5c", "engine_load_correction_axis_cal", "confirmed", "injection_timing_reference_adjustment_axis",
   "Code: cm848_applyOffNominalTimingAdjustment looks off_nominal_composite_adjustment up in this axis and gets injection_timing_reference_adjustment (timing counts) from 0x405a6c; the adjustment is added to the combustion timing reference. Family name from the W5 combustion_flash2 note (injection_timing_reference_adjustment_*); e2m C_CBO_SOI_Ref_Adj_Table offset match only. No _cal (not EEPROM).")
gl("0x00405a6c", "engine_load_correction_output_cal", "confirmed", "injection_timing_reference_adjustment_values",
   "Code: data column of the lookup above, result injection_timing_reference_adjustment. W5 family name; no _cal.")
gl("0x00405a7c", "fuel_demand_correction_scale_axis_cal", "confirmed", "injection_timing_off_nominal_adjustment_axis",
   "Code: cm848_calculateTimingReferenceDeltaAdjustment looks injection_timing_reference_delta_clamped up in this axis and stores the result of 0x405a8c in injection_timing_off_nominal_adjustment. Family name from the W5 combustion_flash2 note (injection_timing_off_nominal_adjustment_*); e2m C_CBO_Delta_SOI_Axis offset match only. No _cal.")
gl("0x00405a8c", "fuel_demand_correction_scale_output_cal", "confirmed", "injection_timing_off_nominal_adjustment_values",
   "Code: data column of the lookup above, result injection_timing_off_nominal_adjustment. W5 family name; no _cal.")
# working words of cm848_applyCombustionTimingLimits
gl("0x0040a05e", "fuel_correction_output_snapshot", "confirmed", "injection_timing_compensated_reference_previous",
   "Code: written only by cm848_storeFuelDemandPreviousValues (copy of injection_timing_compensated_reference, the CBO timing output; last call of the auxiliary-control task set), read twice by cm848_applyCombustionTimingLimits, which runs earlier in the next pass, as the timing input of the combustion limits. xref_addr.py: 2 reads / 1 write, word. Working RAM, no boot-ROM user.")
gl("0x003fa63c", "fuel_correction_output_working", "confirmed", "injection_timing_with_user_increment",
   "Code: cm848_applyCombustionTimingLimits stores injection_timing_compensated_reference_previous (+ injection_timing_user_increment when engine_feature_enable_flags bit 3 is set) here, then compares it with the minimum limit. xref_addr.py: 1 read / 1 write, word, only that function; time-shared window 0x3F9800-0x3FDB30 but no user below 0x7F60 (xref_addr.py). No type change.")
gl("0x003fa642", "fuel_demand_lookup_working", "confirmed", "injection_timing_after_minimum_limit",
   "Code: set to the sum above, or to injection_timing_combustion_minimum_limit when the sum is below it (fuel_demand_mode_code 28); then compared with the maximum limit to give injection_timing_main_base_before_override. xref_addr.py: 1 read / 2 writes, word, one function; time-shared window, no user below 0x7F60. No type change.")
gl("0x003fa644", "fuel_demand_mode_code_prev_snapshot", "confirmed", "injection_timing_source_code_after_minimum_limit",
   "Code: write-only copy of fuel_demand_mode_code taken right after the minimum-limit step (28 when the minimum limit applied), before the maximum-limit step may set 27. xref_addr.py: 0 reads / 1 write, word; time-shared window, no user below 0x7F60. No type change.")

# ---------------------------------------------------------------- N41: auxiliary interaction tables (downgraded to uncertain)
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

# ---------------------------------------------------------------- N39: acceleration filter neighbours
FS = "Layout checked in cm848_signedFirstOrderFilter (disassembly 0x5644c): the state argument is two dwords, +0 = pointer to the 16-bit coefficient word (0 = no filtering) and +4 = Q16 accumulator. "
gl("0x003fb3b0", "cruise_filter_state_a_ptr", "confirmed", "engine_acceleration_first_stage_filter_state",
   FS + "cm848_processEngineRpmDerivative passes &this word as the state of the first-stage filter (engine_acceleration_unfiltered -> engine_acceleration_first_stage_filtered); cm848_initEngineRpmFilterPointers points it at 0x408808. Not cruise state. xref_addr.py: 0 reads / 1 write (address-of uses are not counted), dword; time-shared window, no user below 0x7F60. No type change (the row says pointer; it is the first word of a two-word state).")
gl("0x003fb3b4", "cruise_filter_accumulator_working", "confirmed", "engine_acceleration_first_stage_filter_accumulator",
   FS + "This is the +4 accumulator of the first-stage state; cm848_processEngineRpmDerivative resets it to the clamp value << 16 when the filtered acceleration leaves engine_acceleration_first_stage_clamp_minimum .. _maximum. xref_addr.py: 0 reads / 2 writes, dword; no user below 0x7F60.")
gl("0x003fb3b8", "cruise_filter_state_b_ptr", "confirmed", "engine_acceleration_second_stage_filter_state",
   FS + "Passed as the state of the second filter (first stage -> engine_acceleration_second_stage_filtered); initialised to point at 0x40880a. xref_addr.py: 0 reads / 1 write, dword; no user below 0x7F60. No type change.")
gl("0x003fb3bc", "cruise_filter_accumulator_init", "confirmed", "engine_acceleration_second_stage_filter_accumulator",
   FS + "The +4 accumulator of the second-stage state (0x3fb3b8 + 4); the only named access is its zeroing in cm848_initEngineRpmFilterPointers, the filter updates it through the state pointer. xref_addr.py: 0 reads / 1 write, dword; no user below 0x7F60.")
gl("0x00408808", "cruise_filter_state_a_cal", "confirmed", "engine_acceleration_first_stage_filter_coefficient",
   "Code: cm848_initEngineRpmFilterPointers stores its address as the coefficient pointer of the first-stage state, and cm848_signedFirstOrderFilter reads it as a 16-bit word (disassembly: lhz r7,0(r12)). 0x408808 is outside 0x3fd482-0x3feec1, so the _cal suffix goes. Type note (no change proposed here): the row says byte, the filter reads a word.")
gl("0x0040880a", "cruise_filter_state_b_cal", "confirmed", "engine_acceleration_second_stage_filter_coefficient",
   "Code: coefficient word of the second-stage state (pointer set in cm848_initEngineRpmFilterPointers). No _cal (outside the EEPROM range). Same byte-vs-word type note.")
gl("0x003fb3ae", "governor_target_rpm_snapshot", "confirmed", "engine_acceleration_target_rpm_previous",
   "Code: the previous engine_rpm_state.target_rpm of cm848_processEngineRpmDerivative (engine_acceleration_unfiltered = target_rpm - this, then this = target_rpm); zeroed by cm848_initEngineRpmFilterPointers; no governor use. xref_addr.py: 1 read / 2 writes, word, only those two functions; time-shared window, no user below 0x7F60. No type change.")
gl("0x003fb046", "governor_speed_error_filtered_snapshot", "confirmed", "governor_speed_error_filtered_previous",
   "Code (checked this wave, it was not before): cm848_calculateActuatorEDriveCommand sets governor_speed_error_filtered_change = filtered speed error (cm848_signedFirstOrderFilter of governor_speed_error_a) - this word, then stores the new filtered value here; zeroed by cm848_initializeActuatorEControlLoop. So it is the previous filtered speed error of the actuator E loop (the 'governor_speed_error' stem is the actuator E position error per wave 5; rename it together with its sibling governor_speed_error_filtered_change 0x40b00e). xref_addr.py: 1 read / 2 writes, word; time-shared window, no user below 0x7F60. No type change.")

# ---------------------------------------------------------------- N38: crank_pattern_valid_flag
gl("0x003fb5c5", "crank_pattern_valid_flag", "confirmed", "crank_tooth_counter_zero_flag",
   "Code: the only write sites are in mpc555_updateEngineCrankState: set true when the low byte of tpu_a_ch1_param2.PARAM4 (the tooth counter of TPU-A channel 1) is 0, cleared in the other branch (where the tooth period is stored in crank_period_capture_array and the tooth counter is nonzero). Readers in hpcr_processEngineSyncPulses use it as the pattern-start condition: (tooth count = crank_pattern_tooth_count_cal OR flag), crank_sync_period_counter compared with crank_sync_tooth_count_cal only while it is set, crank_sync_period_counter reset to 0 while it is set, run state 1 / 3 period limit tests. So the write site proves only 'the tooth counter of TPU-A channel 1 is 0' (the readers use that as the pattern-start condition); the inference 'first tooth after the sync gap' is NOT proven, hence the plain name. It is not 'pattern valid'. Medium confidence. xref_addr.py: 3 reads / 1 write, byte, users 0x4526c-0x45ea0 only (none below 0x7F60, time-shared window); no type change.")

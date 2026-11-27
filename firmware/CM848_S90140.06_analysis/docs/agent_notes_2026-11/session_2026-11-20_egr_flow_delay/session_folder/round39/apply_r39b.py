"""Round 39 stage B: corrections to stage A (912c379) from the ECU's parameter ID table (e2m_block_addresses.py
--address) and the call sites, plus the cache stage A missed.
- Renames: cylinder_balance_enable_* -> cylinder_balance_stop_compensation_* (e2m 81B1-81B3); cylinder_event_index_a / _b
  -> next_cylinder_by_crank_tooth / _cam_tooth (e2m 8197 / 8198 and 8195 / 8196; table b reads TPU-A channel 1, not 0);
  crank_tooth_good_window_fraction (+ its tables) -> cam_tooth_good_window_fraction (e2m 8199-819B PMA, the cam wheel);
  low_speed_governor_no_load_fuel_* -> low_speed_governor_fuel_by_commanded_throttle_* (one addend of the no-load fuel);
  crank_sync_phase_counter -> crank_out_of_phase_count and crank_sync_phase_counter_threshold_cal ->
  crank_out_of_phase_threshold (e2m 8194 +8 Crank_Out_Of_Phase_Threshold; 0x408f5e is ROM-copied, no _cal).
- Type: crank_sync_phase_counter (dword) is two words: the counter (lhz @ 0x45d0c) and the good window lookup cache at
  0x3fb5bd (sth @ 0x44028), which replaces the junk row 'crank_sync_phase_counter+2'.
- Comments: every round 39 row gets its e2m record where the table resolves one, and the stage A errors go (table b's
  TPU channel, the expected firing revolutions flags, the fuel metering PWM unit).
Writes the proof map (address,name,old_label,kind,dims) of the label renames. Idempotent.
usage: apply_r39b.py <repo> <map.csv>"""
import ast
import os
import re
import sys

repo, map_path = os.path.abspath(sys.argv[1]), sys.argv[2]
src = open("/home/linux/.claude/jobs/374b0424/tmp/w15/apply_hand_worklist.py").read()
BANNED = ast.literal_eval(re.search(r"BANNED = (\{.*?\})", src, re.S).group(1))

THROTTLE = ("the commanded-throttle addend of low_speed_governor_reference.no_load_fuel: "
            "cm848_calculateLowSpeedGovernorNoLoadFuel looks it up by commanded_throttle_state.commanded_throttle (0.25 % "
            "per count) and adds it to friction_fuel_by_engine_speed, friction_fuel_adjustment_for_coolant_temperature "
            "and governor_speed_target_trim. Every value is 0 in this calibration. The parameter ID table resolves no "
            "e2m record here")
TURBO = ("e2m 8D18 / 8D19 / 8D1A C_TPE_3D_Pressure_Ratio_Axis / C_TPE_3D_Speed_Axis / C_TPE_3D_Turbo_Speed_Table "
         "[REV/SEC/SQRT(K)] (the turbocharger speed estimate table): cm848_estimateTurbochargerSpeed looks up "
         "turbocharger_speed_estimate_corrected_speed by the compressor pressure ratio (charge_pressure x 4096 / "
         "compressor_inlet_pressure; x) and turbocharger_speed_estimate_engine_speed_filtered (y), then scales it by "
         "compressor_inlet_temperature_square_root")
SAFETY = ("cm848_applyFuelPressureGovernorFaultBlend: safety_fuel_limit_lookup by the filtered engine speed. The "
          "parameter ID table resolves no e2m record here (its dump holds 1441 of 1886 records)")
STOP = ("e2m 81B1 / 81B2 / 81B3 CBD_Stop_Compensation_Speed_Vector [RPM] / _Fueling_Vector [MM3S] / _Table: "
        "hpcr_cbdCalculateCylinderTrims looks it up by engine_speed_state.engine_speed (x) and "
        "cylinder_balance_filtered_fueling (y). A result of 0 sets cylinder_event_seq_counter to 0xff and one below "
        "0x80 sets cylinder_balance_stop_compensation_flag. Only the first corner (1050 rpm and fueling 515) is 128 in "
        "the dump")
WINDOW = ("e2m 8199 / 819A PMA_Good_Window_X_Axis [RPM] / PMA_Good_Window_Y_Axis 'Tooth fraction defining expected "
          "normal cam tooth location': cm848_updateEngineSpeedFromCrankSignal looks up cam_tooth_good_window_fraction "
          "by average_engine_speed. PMA is the cam wheel input (block 8194: PMA_Special_Count = the number of teeth on "
          "the cam wheel, PMA_Edge_Type = the cam signal capture edge)")
CRANK_NEXT = ("e2m 8197 / 8198 Crank_Based_Next_Cyl_X_Axis (crank tooth number) / Crank_Based_Next_Cyl_Y_Axis 'Next "
              "cylinder to fuel on given current crank location': engine_injectionTiming_crankSyncDispatch looks up "
              "cylinder_event_index by the low byte of TPU-A channel 0 PARAM4 while engine_speed_limp_home_active_flag "
              "is 0")
CAM_NEXT = ("e2m 8195 / 8196 Cam_Based_Next_Cyl_X_Axis (cam tooth number) / Cam_Based_Next_Cyl_Y_Axis 'Next cylinder "
            "to fuel on given current cam location': engine_injectionTiming_crankSyncDispatch looks up "
            "cylinder_event_index by the low byte of TPU-A channel 1 PARAM4 while engine_speed_limp_home_active_flag is "
            "1, then calls cm848_scheduleInjectionAnglesInSpeedLimpHome")
FIRING = ("e2m 81A7 / 81A8 Expected_Firing_Revs_X_Axis [DEG_F] (coolant temperature at 1/64 deg F per count, signed: "
          "-20 to 80 deg F here) / Expected_Firing_Revs_Y_Axis 'Number of revs in preliminary sync state' (6 / 6 / 4 / 4 "
          "/ 4 / 4): hpcr_processEngineSyncPulses looks up crank_preliminary_sync_count as it enters the preliminary "
          "sync. It passes the literal 2 as the temperature (li r4,2 @ 0x452d8; li r7,1 = flags 1 = signed axis), so "
          "this firmware always reads the table at about 0 deg F")
PWM = ("e2m 80C1 / 80C2 HPCR_Fuelpr_PWM_RPM_Axis [RPM] / HPCR_Fuelpr_PWM_Axis [HZ] 'PWM frequency axis': "
       "cm848_setFuelMeteringPwm / mpc555_initTpuTimingInterrupts look it up by average_engine_speed (0-5000 rpm; "
       "2240 / 1920 alternate in narrow speed bands) and set TPU-B channel 11's period to 5000000 / value ticks. The "
       "e2m scale is 1.0 Hz per count, which needs a 0.2 us tick. The 3.2 us TPU-B tick that "
       "mpc555_tpuBSetPwmPeriodMicroseconds converts with (channel 11's own set-period slot uses it) would make it "
       "value / 16 Hz. Open: scope the fuel metering output")
RETARDER = ("e2m 13D6 Jcomm_Brake_Control_RPM_Axis [JCBCRPXA] (the J1939 retarder map's rpm axis): the filtered engine "
            "speed axis the engine retarder torque stage tables share (cm848_calculateEngineRetarderTorque / "
            "cm848_selectEngineRetarderStagePercent)")
TORQUE = ("e2m MT_Max_Torque_Map [MTTQMPZA] (x 140E MT_RPM_Axis [MTTQMPXA] = engine speed, y 1447 MT_Alpha_Axis "
          "[MTTQMPYA] = alpha): cm848_lookupMaximumTorqueAtEngineSpeed / cm848_calculateFuelDemandFilter")

# (address, name now, new name, new type or None, comment head, pre-round-39 name)
ROWS = [
    ("0x0040713a", "low_speed_governor_no_load_fuel_axis", "low_speed_governor_fuel_by_commanded_throttle_axis", None,
     "x axis (0-400 = 0-100 %) of " + THROTTLE, "governor_fuel_demand_axis_cal"),
    ("0x0040714c", "low_speed_governor_no_load_fuel_values", "low_speed_governor_fuel_by_commanded_throttle_values",
     None, "values of " + THROTTLE, "governor_fuel_demand_output_cal"),
    ("0x003faf7e", "low_speed_governor_no_load_fuel_cached_axis_offset",
     "low_speed_governor_fuel_by_commanded_throttle_cached_axis_offset", None, "the lookup cache of " + THROTTLE,
     "governor_interp_table_state_b"),
    ("0x004072a2", "turbocharger_corrected_speed_x_axis", None, None, "x axis (pressure ratio) of " + TURBO,
     "injection_timing_temp_corr_axis1_cal"),
    ("0x004072e8", "turbocharger_corrected_speed_y_axis", None, None, "y axis (engine speed) of " + TURBO,
     "injection_timing_temp_corr_ystart_cal"),
    ("0x00407308", "turbocharger_corrected_speed_grid", None, None, "grid (15 rows of 34) of " + TURBO,
     "injection_timing_temp_corr_yend_cal"),
    ("0x003fb01a", "turbocharger_corrected_speed_cached_axis_offsets", None, None, "the lookup cache of " + TURBO,
     "DAT_003fb01a"),
    ("0x004088e8", "safety_fuel_limit_axis", None, None, "x axis of " + SAFETY, "safety_fuel_limit_rpm_axis_cal"),
    ("0x0040891a", "safety_fuel_limit_values", None, None, "values of " + SAFETY, "safety_fuel_limit_rpm_output_cal"),
    ("0x003fb3c2", "safety_fuel_limit_cached_axis_offset", None, None, "the lookup cache of " + SAFETY, "DAT_003fb3c2"),
    ("0x00408f32", "cylinder_balance_enable_x_axis", "cylinder_balance_stop_compensation_x_axis", None,
     "x axis (engine speed) of " + STOP, "cylinder_seq_axis1_cal"),
    ("0x00408f38", "cylinder_balance_enable_y_axis", "cylinder_balance_stop_compensation_y_axis", None,
     "y axis (fueling) of " + STOP, "cylinder_seq_ystart_cal"),
    ("0x00408f3e", "cylinder_balance_enable_grid", "cylinder_balance_stop_compensation_grid", None,
     "grid (2 rows of 2) of " + STOP, "cylinder_seq_yend_cal"),
    ("0x003fb592", "cylinder_balance_enable_cached_axis_offsets", "cylinder_balance_stop_compensation_cached_axis_offsets",
     None, "the lookup cache of " + STOP, "cylinder_event_init_state_a"),
    ("0x003fb594", "cylinder_balance_enable_cached_axis_offsets[1]",
     "cylinder_balance_stop_compensation_cached_axis_offsets[1]", None,
     "the y segment offset of cylinder_balance_stop_compensation_cached_axis_offsets", "cylinder_event_init_state_b"),
    ("0x00408fae", "crank_tooth_good_window_fraction_axis", "cam_tooth_good_window_fraction_axis", None,
     "x axis of " + WINDOW, "crank_mios_timing_axis_cal"),
    ("0x00408fba", "crank_tooth_good_window_fraction_values", "cam_tooth_good_window_fraction_values", None,
     "values of " + WINDOW, "crank_mios_timing_values_cal"),
    ("0x00408fe0", "cylinder_event_index_b_axis", "next_cylinder_by_cam_tooth_axis", None, "x axis of " + CAM_NEXT,
     "cylinder_event_axis_b_cal"),
    ("0x00408ff6", "cylinder_event_index_b_values", "next_cylinder_by_cam_tooth_values", None, "values of " + CAM_NEXT,
     "cylinder_event_values_b_cal"),
    ("0x003fb5c1", "cylinder_event_index_b_cached_axis_offset", "next_cylinder_by_cam_tooth_cached_axis_offset", None,
     "the lookup cache of " + CAM_NEXT, "crank_timing_init_state_b"),
    ("0x0040900c", "cylinder_event_index_a_axis", "next_cylinder_by_crank_tooth_axis", None, "x axis of " + CRANK_NEXT,
     "cylinder_event_axis_a_cal"),
    ("0x00409030", "cylinder_event_index_a_values", "next_cylinder_by_crank_tooth_values", None,
     "values of " + CRANK_NEXT, "cylinder_event_values_a_cal"),
    ("0x003fb5bf", "cylinder_event_index_a_cached_axis_offset", "next_cylinder_by_crank_tooth_cached_axis_offset", None,
     "the lookup cache of " + CRANK_NEXT, "crank_timing_init_state_a"),
    ("0x00409054", "crank_preliminary_sync_count_axis", None, None, "x axis of " + FIRING,
     "engine_event_countdown_axis_cal"),
    ("0x00409062", "crank_preliminary_sync_count_values", None, None, "values of " + FIRING,
     "engine_event_countdown_values_cal"),
    ("0x003fb5c3", "crank_preliminary_sync_count_cached_axis_offset", None, None, "the lookup cache of " + FIRING,
     "crank_timing_init_state_c"),
    ("0x00409554", "fuel_metering_pwm_frequency_axis", None, None, "x axis of " + PWM,
     "engine_sync_speed_correction_axis_cal"),
    ("0x00409576", "fuel_metering_pwm_frequency_values", None, None, "values of " + PWM,
     "engine_sync_speed_correction_values_cal"),
    ("0x003fb6ea", "fuel_metering_pwm_frequency_cached_axis_offset", None, None, "the lookup cache of " + PWM,
     "cam_timing_filter_init_state"),
    ("0x0005a426", "engine_retarder_torque_engine_speed_axis", None, None, RETARDER, "governor_load_xaxis_cal"),
    ("0x0005c556", "maximum_torque_map_x_axis", None, None, "x axis of " + TORQUE, "j1939_fuel_table_xaxis_cal"),
    ("0x0005c582", "maximum_torque_map_y_axis", None, None, "y axis of " + TORQUE, "j1939_fuel_table_ystart_cal"),
    ("0x0005c58e", "maximum_torque_map_grid", None, None,
     "grid (5 rows of 21) of " + TORQUE + ". The parameter ID table dump resolves no record at 0x5c58e",
     "j1939_fuel_table_yend_cal"),
    ("0x003faf98", "maximum_torque_map_alpha_0_cached_axis_offsets", None, None,
     "the lookup cache of maximum_torque_map_grid at its alpha 0 row (y input 0) in cm848_calculateFuelDemandFilter; "
     + TORQUE, "fuel_demand_interp_state_a"),
    ("0x003faf9c", "maximum_torque_map_chi_lower_cached_axis_offsets", None, None,
     "the lookup cache of maximum_torque_map_grid at the combustion_chi_lower_map_number x 0x4000 row in "
     "cm848_calculateFuelDemandFilter; " + TORQUE, "fuel_demand_interp_state_c"),
    ("0x003fafa0", "maximum_torque_map_chi_upper_cached_axis_offsets", None, None,
     "the lookup cache of maximum_torque_map_grid at the combustion_chi_upper_map_number x 0x4000 row in "
     "cm848_calculateFuelDemandFilter; " + TORQUE, "fuel_demand_interp_state_e"),
]
NEW_ROWS = [  # (address, name now, new name, new type, full comment)
    ("0x003fb5bb", "crank_sync_phase_counter", "crank_out_of_phase_count", "word",
     "e2m 8194 +8 Crank_Out_Of_Phase_Threshold's counter: mpc555_handleCamSignalInterrupt adds 1 for each cam pulse at "
     "the other bank's crank tooth (crank_tooth_pattern_table + cam_wheel_pulse_count), clears it on an in-phase pulse, "
     "and above crank_out_of_phase_threshold clears it and calls cm848_setCrankPreliminarySyncFromCam (lhz @ 0x45d0c). "
     "It was the dword crank_sync_phase_counter, whose bytes 2-3 are the next row (PR #53 round 39)"),
    ("0x003fb5bd", "crank_sync_phase_counter+2", "cam_tooth_good_window_fraction_cached_axis_offset", "word",
     "the lookup cache of " + WINDOW + ". mpc555_resetEngineTimingAccumulators sets it to 2 (sth @ 0x44028). It was bytes "
     "2-3 of the dword crank_sync_phase_counter, plus a junk row 'crank_sync_phase_counter+2' (PR #53 round 39)"),
    ("0x00408f5e", "crank_sync_phase_counter_threshold_cal", "crank_out_of_phase_threshold", None,
     "e2m 8194 +8 Crank_Out_Of_Phase_Threshold 'Number of out-of-phase cam pulse detections before switching crank "
     "bank' (4 here): mpc555_handleCamSignalInterrupt compares crank_out_of_phase_count with it. ROM-copied (RAM = ROM "
     "+ 0x39a3e6, the dump matches), so no _cal (was crank_sync_phase_counter_threshold_cal; PR #53 round 39)"),
    ("0x0040b7d0", "crank_tooth_good_window_fraction", "cam_tooth_good_window_fraction", None, None),
]
gp = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output/global_variables.csv")
g = open(gp).read().split("\n")
names = {l.split(",")[1] for l in g if l.startswith("0x") and len(l.split(",")) > 1}
if "crank_out_of_phase_count" in names:
    print("already applied")
    sys.exit(0)
for r in ROWS + NEW_ROWS:
    n = r[2]
    if n:
        assert not any(t in BANNED for t in re.split(r"[_\[\]]", n) if t), n
        assert n not in names, f"name taken: {n}"


def find(addr, name):
    hits = [k for k, l in enumerate(g) if l.startswith(addr + "," + name + ",")]
    assert len(hits) == 1, (addr, name, len(hits))
    return hits[0]


rows = ["address,name,old_label,kind,dims"]
for a, cur, new, typ, head, original in ROWS:
    i = find(a, cur)
    p = g[i].split(",", 3)
    note = p[3] if len(p) > 3 else ""
    tail = note.split(" | earlier note: ", 1)[1].strip() if " | earlier note: " in note else ""
    name = new or cur
    comment = f"{head} (was {original}; PR #53 round 39)" + (f" | earlier note: {tail}" if tail else "")
    g[i] = f"{a},{name},{typ or p[2]},{comment}"
    if new and not cur.endswith("[1]"):
        rows.append(f"{a},{new},{cur},global,1")
for a, cur, new, typ, comment in NEW_ROWS:
    i = find(a, cur)
    p = g[i].split(",", 3)
    if comment is None:  # keep the comment, name the cam
        comment = ("the cam tooth good window (e2m 819A 'expected normal cam tooth location'; PMA = the cam wheel input, "
                   "block 8194) (was crank_tooth_good_window_fraction; PR #53 round 39) | earlier note: " + p[3])
    g[i] = f"{a},{new},{typ or p[2]},{comment}"
    if not cur.endswith("+2"):
        rows.append(f"{a},{new},{cur},global,1")
g = [l[:-len(" | earlier note:")] if l.endswith(" | earlier note:") and "PR #53 round 39" in l else l for l in g]
open(gp, "w").write("\n".join(g))
with open(map_path, "w") as fh:
    fh.write("\n".join(rows) + "\n")
print(f"{len(ROWS)} round 39 rows rewritten, {len(NEW_ROWS)} more; {len(rows) - 1} label renames in the map")

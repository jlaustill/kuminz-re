"""Stage 7 (label-only): the engine speed block e2m 819B. Each record's code use was checked against its description
(use_lines.py); the existing limits named in earlier waves (cam_crank_mismatch_count_limit,
crank_recovery_minimum_good_cam_pulse_count, cylinder_firing_acceleration_threshold,
crank_preliminary_sync_firing_detection_threshold, crank_sync_attempt_limit, primary / backup_period_rpm_conversion_factor)
tie them down.
Run after: rename_struct_types.py <out> map_struct7.csv engine_rpm_state_t=engine_speed_state_t@0x0040b7ac=engine_speed_state
Usage: apply_stage7.py <firmware output dir> <scratch dir>"""
import csv
import os
import sys

out, scratch = sys.argv[1:3]
REC = "e2m 819B"
ROWS = [  # address, old, new, record (+offset name), e2m description, code fact (None = keep the old comment after it)
    (0x0040b78e, "engine_rpm_measured", "average_engine_speed", "+0 Average_Engine_Speed [RPM]",
     "[ESAVES] Engine speed based on the 2^n pulse average",
     "the measured engine speed (1/8 rpm per count; not a setpoint): cm848_updateEngineSpeedFromCrankSignal takes "
     "backup_engine_speed or main_engine_speed by engine_speed_from_backup_sensor_flag; filtered into "
     "engine_speed_state.filtered_engine_speed (x 0.125 verified live 2026-01-31)"),
    (0x0040b790, "crank_period_accumulator", "average_pulse_period", "+2 Average_Pulse_Period [CNTS]",
     "[ESPLTMAV] time period over 1 cyl of primary speed pulses",
     "main_engine_speed = primary_period_rpm_conversion_factor / this (cm848_updateEngineSpeedFromCrankSignal); reset "
     "to 0xffffffff by mpc555_resetEngineTimingAccumulators"),
    (0x0040b794, "crank_tooth_period_raw", "average_pulse_period_backup", "+6 Average_Pulse_Period_Backup [CNTS]",
     "[ESPLAVBU] time period over 1 cyl of secondary speed pulses",
     "the sum of the backup (cam signal) pulse periods kept in pulse_period_table_backup by "
     "mpc555_handleCamSignalInterrupt; backup_engine_speed = backup_period_rpm_conversion_factor / this"),
    (0x0040b79a, "crank_tooth_rpm", "backup_engine_speed", "+C Backup_RPM [RPM]",
     "[ESES02] Engine speed calculated from secondary speed sensor",
     "backup_period_rpm_conversion_factor / average_pulse_period_backup (1/8 rpm per count); average_engine_speed "
     "while engine_speed_from_backup_sensor_flag is set; SCI command 20 reports it"),
    (0x0040b79c, "crank_period_computed", "cam_to_crank_tooth_number", "+E Cam_2_Crank_Tooth_Number",
     "Crank tooth number when cam pulse occurred", "written and compared by mpc555_handleCamSignalInterrupt"),
    (0x0040b79e, "crank_sync_timeout_count", "cam_crank_mismatch_count", "+10 Cam_Crank_Mismatch_Count",
     "persistence counter for cam-crank mismatch error",
     "counted by mpc555_handleCamSignalInterrupt and cm848_updateEngineSpeedFromCrankSignal against "
     "cam_crank_mismatch_count_limit"),
    (0x0040b7a0, "crank_tooth_count_a", "cam_crank_plausibility_count_1", "+12 Cam_Crank_Plausibility_1",
     "Number of cam pulses with expected crank tooth number per crank rev",
     "cleared by mpc555_updateEngineRunState / mpc555_handleCamSignalInterrupt, read by hpcr_processEngineSyncPulses"),
    (0x0040b7a2, "crank_sync_period_counter", "cam_crank_plausibility_count_2", "+14 Cam_Crank_Plausibility_2",
     "Number of cam pulses with expected crank tooth number per crank rev",
     "counted by mpc555_handleCamSignalInterrupt; mpc555_updateEngineRunState compares it with "
     "crank_recovery_minimum_good_cam_pulse_count"),
    (0x0040b7a4, "crank_capture_period_packed", "crank_accumulated_period", "+16 Crank_Accumulated_Period",
     "Period measured between speed interrupts",
     "assembled from the TPU-A capture words by hpcr_processEngineSyncPulses and added into "
     "engine_speed_state.main_speed_period_sum_between_vss_pulses"),
    (0x0040b7a8, "crank_tooth_position_count", "crank_speed_count", "+1A Crank_Speed_Count",
     "number of speed interrupts before extra cam pulse should occur",
     "counted by hpcr_processEngineSyncPulses up to crank_tooth_position_target; cleared by "
     "mpc555_updateEngineRunState"),
    (0x0040b7aa, "crank_period_variation_metric", "cylinder_acceleration", "+1C Cylinder_Acceleration [RPM/SEC]",
     "Acceleration measured over one cylinder",
     "hpcr_processEngineSyncPulses compares it with cylinder_firing_acceleration_threshold (a firing detection)"),
    (0x0040b7bc, "crank_tooth_count_b", "firing_detection_count", "+2E Firing_Detection_Count",
     "counts number of fueling events which caused accel",
     "+1 per detected firing in hpcr_processEngineSyncPulses; mpc555_updateEngineRunState compares it with "
     "crank_preliminary_sync_firing_detection_threshold; cleared by engine_injectionTiming_crankSyncDispatch"),
    (0x0040b7c2, "crank_derived_rpm", "main_engine_speed", "+34 Main_RPM [RPM]",
     "[ESES01] Engine speed calculated from primary speed sensor",
     "primary_period_rpm_conversion_factor / average_pulse_period (1/8 rpm per count); average_engine_speed while "
     "engine_speed_from_backup_sensor_flag is 0; SCI command 20 reports it"),
    (0x0040b7d4, "crank_period_scale_divisor", "crank_teeth_per_cylinder", "+46 RPM_Cylinder_Width",
     "number of crank teeth per cylinder",
     "set by mpc555_resetEngineTimingAccumulators, a divisor in hpcr_processEngineSyncPulses"),
    (0x0040b7d8, "engine_speed_from_tooth_period_flag", "engine_speed_from_backup_sensor_flag", "+4A Speed_Sensor_Select",
     "[ESSNSE] Specifies source for speed calculations", None),
    (0x0040b7da, "crank_sync_attempt_counter", "start_sync_count", "+4C Start_Sync_Count",
     "number of crank revs spent in Start_Sync mode",
     "counted by mpc555_updateEngineRunState up to crank_sync_attempt_limit"),
    (0x0040b7dc, "crank_period_capture_array", "pulse_period_table_backup", "+4E Pulse_Period_Table_Backup [CNTS]",
     "[ESPSTB02] Table containing main speed pulse periods",
     "16 bytes (4 dwords, up to +5E): mpc555_handleCamSignalInterrupt stores each backup (cam signal) pulse period at "
     "backup_period_capture_index (+3E Next_Table_Position_Backup) and sums the table into average_pulse_period_backup"),
    (0x0040b7f6, "crank_tbl_event_counter", "crank_resync_count", "+68 Crank_Resync_Count",
     "Global number of times crank has had to Re-Sync",
     "+1 per re-sync in hpcr_processEngineSyncPulses / mpc555_handleCamSignalInterrupt / mpc555_updateEngineRunState"),
    (0x0040b7f8, "crank_event_timebase_c", "first_cylinder_fire_time_ticks", "+6A First_Cylinder_Fire_Time [MSEC]",
     "First speed isr time to 1st Fire Acceleration Time",
     "captured once (while 0) by hpcr_processEngineSyncPulses as the time base minus first_speed_interrupt_time_ticks"),
    (0x0040b7fc, "crank_event_timebase_b", "crank_preliminary_sync_time_ticks", "+6E Crank_Prelim_Time [MSEC]",
     "First speed isr time to Crank State = Prelim Time",
     "captured once by cm848_engineRunState3HandlerWithTimebaseCapture (run state 3 = preliminary sync) as the time "
     "base minus first_speed_interrupt_time_ticks"),
    (0x0040b800, "crank_event_timebase_a", "cam_have_sync_time_ticks", "+72 Cam_Have_Sync_Time [MSEC]",
     "First speed isr time to Cam State = HAVE Time",
     "captured once by mpc555_handleCamSignalInterrupt as the time base minus first_speed_interrupt_time_ticks"),
    (0x0040b804, "crank_tooth_period_tbl", "crank_have_sync_time_ticks", "+76 Crank_Have_Sync_Time [MSEC]",
     "First speed isr time to Crank State = HAVE Time",
     "captured once by the run state 4 handlers (cm848_engineRunState4Handler / ...Conditional / ...Handler2) as the "
     "time base minus first_speed_interrupt_time_ticks"),
]
FIELDS = [  # old field, new field, comment (quoted)
    ("filtered_rpm", "engine_speed",
     "e2m 819B +1E Engine_Speed '[ESCMES] Engine speed based from period of one cam rev' (1/8 rpm): in this firmware "
     "written with the same value as filtered_engine_speed by the same writers; the fault freeze frames copy it "
     "(was filtered_rpm)"),
    ("crank_capture_period_sum", "main_speed_period_sum_between_vss_pulses",
     "e2m 819B +20 EPS_VSS_Accumulator '[ESACGR] Accumulated main EPS period between VSS interrupts': "
     "hpcr_processEngineSyncPulses adds each crank_accumulated_period; cm848_vehicleSpeedSensorInterruptHandler "
     "divides it by the count (was crank_capture_period_sum)"),
    ("crank_tooth_period_sum", "backup_speed_period_sum_between_vss_pulses",
     "e2m 819B +24 EPS_VSS_Accumulator_Backup '[ESACBKGR] Accumulated backup EPS period between VSS interrupts': "
     "added by mpc555_handleCamSignalInterrupt; divided by the count in cm848_vehicleSpeedSensorInterruptHandler "
     "(was crank_tooth_period_sum)"),
    ("crank_capture_period_sample_count", "main_speed_pulse_count_between_vss_pulses",
     "e2m 819B +28 EPS_VSS_Counter '[ESCTGR] Number of main EPS interrupts between VSS interrupts' "
     "(was crank_capture_period_sample_count)"),
    ("crank_tooth_period_sample_count", "backup_speed_pulse_count_between_vss_pulses",
     "e2m 819B +2A EPS_VSS_Counter_Backup '[ESCTBKGR] Number of backup EPS interrupts between VSS interrupts' "
     "(was crank_tooth_period_sample_count)"),
    ("current_rpm", "filtered_engine_speed",
     "e2m 819B +2C Filtered_Engine_Speed '[ENGRPM] Variable 2^n pulse averaged and filtered engine speed' (1/8 rpm; "
     "x 0.125 verified live at 0x40b7ba 2026-01-31): the engine speed the rest of the firmware reads (was current_rpm)"),
]
TYPE, INST = "engine_speed_state_t", "engine_speed_state"

names_in_csvs = set()
for name in ("global_variables.csv", "function_renames.csv", "arrays.csv", "labels.csv"):
    for row in csv.reader(open(os.path.join(out, name))):
        if len(row) > 1 and row[0].startswith("0x"):
            names_in_csvs.add(row[1])
for r in ROWS:
    assert r[2] not in names_in_csvs, r[2]

by_addr = {r[0]: r for r in ROWS}
seen = set()
path = os.path.join(out, "global_variables.csv")
lines = open(path).read().split("\n")
field_by_old = {o: n for o, n, _ in FIELDS}
for i, line in enumerate(lines):
    p = line.split(",", 3)
    if not p[0].startswith("0x"):
        continue
    a = int(p[0], 16)
    if a in by_addr:
        _, old, new, rec, desc, fact = by_addr[a]
        assert p[1] == old, (hex(a), p[1], old)
        rest = p[3] if len(p) > 3 else ""
        head = f"{REC} {rec} '{desc}'"
        if fact is None:
            comment = f"{head}: {rest} (was {old})"
        else:
            comment = f"{head}: {fact}. (was {old})" + (f" | earlier note: {rest}" if rest.strip() else "")
        lines[i] = f"{p[0]},{new},{p[2]},{comment}"
        seen.add(a)
    elif p[1].startswith(INST + "."):
        f = p[1][len(INST) + 1:]
        assert f in field_by_old, p
        lines[i] = f"{p[0]},{INST}.{field_by_old[f]},{p[2]},{p[3] if len(p) > 3 else ''}"
    elif a == 0x0040b7ac:
        assert p[1] == INST and p[2] == TYPE, p
        lines[i] = (f"{p[0]},{INST},{TYPE},The engine speed state, e2m 819B +1E .. +2D (table-resolved): Engine_Speed, the "
                    "main / backup EPS period sums and counts between vehicle speed sensor pulses (the drivetrain "
                    "ratio), Filtered_Engine_Speed. (was engine_rpm_state_t_0040b7ac)")
assert seen == set(by_addr), sorted(hex(a) for a in set(by_addr) - seen)
open(path, "w").write("\n".join(lines))

path = os.path.join(out, "structure_definitions.csv")
lines = open(path).read().split("\n")
done = 0
for i, line in enumerate(lines):
    if line == "# Engine RPM State - current and target engine speed values":
        lines[i] = "# Engine speed state - e2m 819B +1E .. +2D (the engine speed module ES)"
    elif line == "# Used by processEngineRpmTarget and governor control":
        lines[i] = "# Written by the speed interrupts; filtered_engine_speed is the engine speed the whole firmware reads"
    elif line.startswith(TYPE + ",0x0040b7ac,"):
        row = next(csv.reader([line]))
        old = row[2]
        new = field_by_old[old]
        comment = dict((o, c) for o, _, c in FIELDS)[old]
        row[2], row[5] = new, comment
        lines[i] = ",".join(row[:5]) + ',"' + comment + '",' + ",".join(row[6:])
        done += 1
assert done == len(FIELDS), done
open(path, "w").write("\n".join(lines))

with open(os.path.join(scratch, "map_stage7.csv"), "w", newline="") as f:
    w = csv.writer(f, lineterminator="\n")
    w.writerow(["address", "name", "old_label", "kind"])
    for a, old, new, *_ in ROWS:
        w.writerow([f"0x{a:08x}", new, old, "global"])
    for old, new, _ in FIELDS:
        w.writerow(["", new, old, "field"])
with open(os.path.join(scratch, "map_refresh_stage7.csv"), "w", newline="") as f:
    w = csv.writer(f, lineterminator="\n")
    w.writerow(["address", "name", "old_label", "kind"])
    for a, old, new, *_ in ROWS:
        w.writerow([f"0x{a:08x}", new, old, "global"])
    for old, new, _ in FIELDS:
        w.writerow(["", f"{INST}.{new}", f"engine_rpm_state_t_0040b7ac.{old}", "token"])
        w.writerow(["", f"{TYPE}.{new}", f"engine_rpm_state_t.{old}", "token"])
    w.writerow(["", INST, "engine_rpm_state_t_0040b7ac", "token"])
    w.writerow(["", TYPE, "engine_rpm_state_t", "token"])
print(f"globals {len(ROWS)}, struct fields {len(FIELDS)}")

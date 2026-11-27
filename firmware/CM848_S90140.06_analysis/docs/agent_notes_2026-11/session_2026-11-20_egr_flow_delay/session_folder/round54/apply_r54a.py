"""Round 54 stage A (labels / rows / plates only):
  1. The last unnamed tables. Ten WORD_ARRAY_ tables were left after the 2026-11-16 table campaign (their input or
     output could not be traced then); the parameter ID table now resolves nine of them, and the tenth is a lookup
     cache. Named in the table grammar (<base>_axis / _values, <base>_x_axis / _y_axis / _grid, <base>_cached_axis_
     offset(s)), with three cache words that had no name.
  2. The application stack high-water monitor (was 'message buffer' / 'buffer management'): the application's stack
     is RAM 0x3f9800-0x3f9ff8 (cm848_restartApplicationWithoutReset loads r1 = 0x3f9ff8). The main-loop task scans
     20 bytes a pass up from 0x3f9808 for the first nonzero byte, the deepest stack write, and keeps the lowest one.
  3. initSensorTableIndexing picks the newest lifetime_distance_8_mile_record_cal entry.
None of the old names is in CM550.  Idempotent.  usage: apply_r54a.py <repo> <map.csv>"""
import os
import re
import sys

sys.path.insert(0, "/home/linux/.claude/jobs/374b0424/tmp/w15/r53")
from e2m_cite import Rows  # noqa: E402

repo = os.path.abspath(sys.argv[1])
out = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")
rows = Rows(repo, "PR #53 round 54")
if "turbocharger_speed_linearization_axis" in rows.names:
    print("already applied")
    sys.exit(0)
R = "PR #53 round 54"
SPEED = "cm848_calculateTurbochargerSpeedSensorValue"
EGRT = "cm848_filterEgrOrificeTemperature"
WASTE = "cm848_calculateWastegateDutyRequest"
TORQUE = "cm848_calculateTorqueManagementFuelTableLimit"
# (address, new name, rendered label, citation)
TYPE_ONLY = [
    ("0x0040770e", "turbocharger_speed_linearization_axis", "WORD_ARRAY_0040770e",
     f"e2m 17CB +0 Turbo_Speed_Lin_Table_Freq_Axis 'Turbo speed sensor lin. freq axis' (HZ; 0 / 2500 Hz): {SPEED} looks "
     "up turbocharger_speed_sensor_frequency"),
    ("0x00407714", "turbocharger_speed_linearization_values", "WORD_ARRAY_00407714",
     "e2m 17CC +0 Turbo_Speed_Linearization_Table 'Turbo speed sensor linearization table' (KRPM, 0.008 per count; 0 / "
     "21425 = 0 / 171.4 krpm)"),
    ("0x00406778", "egr_orifice_temperature_lead_time_constant_axis", "WORD_ARRAY_00406778",
     "e2m 1A2F +0 C_INM_EGRT_Lead_EGR_Flow_Axis 'Input EGR flow axis for predicting EGR orifice temperature lead-time' "
     f"(LB/MIN, 0.0078125 per count): {EGRT} looks up egr_mass_flow_delayed_filtered"),
    ("0x0040678c", "egr_orifice_temperature_lead_time_constant_values", "WORD_ARRAY_0040678c",
     "e2m 1A30 +0 C_INM_EGRT_Lead_Time_Cnst_Table 'EGR orifice temperature lead time constant output axis' (SEC, 0.01 "
     "per count) into egr_orifice_temperature_lead_time_constant_lookup"),
    ("0x003ffcb6", "turbocharger_speed_derate_gain_axis", "WORD_ARRAY_003ffcb6",
     "e2m 19C7 +0 C_TGC_Turbo_Speed_Error_Axis 'Turbo speed error' (KRPM, signed, 0.008 per count; -10 to 25 krpm): "
     f"{WASTE} looks up charge_flow_turbocharger_speed_derate_limit - turbocharger_speed, clamped to 16 bits"),
    ("0x003ffcca", "turbocharger_speed_derate_gain_values", "WORD_ARRAY_003ffcca",
     "e2m 19C8 +0 C_TGC_Turbo_Drt_SET_Table 'Turbo Derate set table' (signed, 1/64 per count: 1.5 at -10 krpm down to 1.0 "
     "from 0 up) into wastegate_duty_controller_state.first_error_gain"),
    ("0x0005b4d6", "torque_management_fuel_table_x_axis", "WORD_ARRAY_0005b4d6",
     f"e2m 8A59 +0 Torque_Mgmt_Engine_Speed_Axis 'Engine Speed axis for torque management table' (RPM, 0.125 per count): "
     f"{TORQUE}'s x input engine_speed_state.filtered_engine_speed (21 breakpoints)"),
    ("0x0005b502", "torque_management_fuel_table_y_axis", "WORD_ARRAY_0005b502",
     "e2m 8A5A +0 Torque_Mgmt_Alpha_Axis 'Alpha axis for torque management table' (6.1e-05 per count; 0 / 16384): the y "
     "input combustion_alpha_input (2 breakpoints)"),
    ("0x0005b508", "torque_management_fuel_table_grid", "WORD_ARRAY_0005b508",
     "e2m 8A5B +0 Torque_Mgmt_Fueling_Table 'Fueling output of Torque Mgmt table' (MM3S, 0.0679 per count; 2 rows of "
     "21) into torque_management_table_fuel_limit"),
    ("0x003fbcfe", "egr_orifice_temperature_lead_time_constant_cached_axis_offset", "WORD_003fbcfe",
     f"The lookup cache of egr_orifice_temperature_lead_time_constant_axis ({EGRT})"),
    ("0x003fb738", "fuel_limit_by_rpm_and_demand_reference_map_cached_axis_offsets", "WORD_ARRAY_003fb738",
     "The two lookup caches of fuel_limit_by_rpm_and_demand_reference_map_grid (cm848_calculateFuelLimitByRpmAndDemand)"),
]
for a, new, label, text in TYPE_ONLY:
    p = rows.row(a)
    assert p[1] == "", (a, p[1])
    rows.check(new)
    rows.g[rows.idx[a]] = f"{a},{new},{p[2]},{text}. ({R}) {p[3]}".rstrip()
    rows.mapping.append(f"{a},{new},{label},global,1")
rows.add_text("0x003fcc06", "turbocharger_speed_linearization_cached_axis_offset", "word",
              f"The lookup cache of turbocharger_speed_linearization_axis ({SPEED})", "DAT_003fcc06")
rows.add_text("0x003fa18a", "turbocharger_speed_derate_gain_cached_axis_offset", "word",
              f"The lookup cache of turbocharger_speed_derate_gain_axis ({WASTE})", "DAT_003fa18a")
# ---- the stack high-water monitor ----------------------------------------------------------------------------------
STACK = ("The application stack is RAM 0x3f9800-0x3f9ff8 (2040 bytes; cm848_restartApplicationWithoutReset loads r1 = "
         "0x3f9ff8)")
rows.rename(None, "0x003fcf96", "message_buffer_scan_cursor", "stack_high_water_mark_scan_cursor", None, None,
            f"{STACK}: cm848_updateStackHighWaterMark walks it up 20 bytes a pass from 0x3f9808 until it meets the first "
            "nonzero byte (the deepest stack write so far) and then starts again at 0x3f9808")
rows.rename(None, "0x0040b608", "message_buffer_scan_low_watermark", "stack_deepest_address", None, None,
            f"The lowest nonzero stack byte cm848_updateStackHighWaterMark has found, 0x3f9ff8 at start (0x3f9d09 in the "
            "dump: 751 bytes used)")
rows.add_text("0x0040b60c", "stack_headroom_factor_tenths", "word",
              "cm848_updateStackHighWaterMark: 20400 / (0x3f9ff8 - stack_deepest_address) = 10 x the 2040-byte stack / "
              "the bytes used (divw): 10 means the stack was full; 27 in the dump = 2.7 times the deepest use. Stored "
              "and never read by the ECM (a diagnostic value)", "DAT_0040b60c")
rows.save(sys.argv[2])
# ---- the three functions --------------------------------------------------------------------------------------------
fp = os.path.join(out, "function_renames.csv")
t = open(fp).read()
FUNCS = [("0x00522700", "bufferManagementWithBounds", "cm848_updateStackHighWaterMark",
          "Main-loop stack high-water monitor: from stack_high_water_mark_scan_cursor it reads up to 20 bytes toward "
          "the stack top (0x3f9ff8) for a nonzero byte; on one below stack_deepest_address it records it and sets "
          "stack_headroom_factor_tenths = 20400 / the bytes used; then the scan starts again at 0x3f9808"),
         ("0x00522788", "initMessageBufferPointers", "cm848_initializeStackHighWaterMark",
          "Boot (cm848_applicationMain): stack_high_water_mark_scan_cursor = 0x3f9808 and stack_deepest_address = "
          "0x3f9ff8 (nothing used yet)"),
         ("0x005230f4", "initSensorTableIndexing", "cm848_initializeLifetimeDistanceRecordIndex",
          "Boot (cm848_applicationMain): lifetime_distance_8_mile_record_index = the index (0-3) of the largest "
          "lifetime_distance_8_mile_record_cal entry - the newest record")]
with open(sys.argv[2], "a") as fh:
    for a, cur, new, plate in FUNCS:
        m = re.search(rf"^{a},{cur}(,[^\n]*)?$", t, re.M)
        assert m and not (m.group(1) or "").strip(", "), (a, cur, m and m.group(1))
        assert re.fullmatch(r"(cm848|hpcr|mpc555)_[a-z][A-Za-z0-9]*", new) and new not in t
        assert "," not in plate
        t = t[:m.start()] + f"{a},{new},{plate} (was {cur}; {R})" + t[m.end():]
        fh.write(f"{a},{new},{cur},function,1\n")
open(fp, "w").write(t)
print(f"round 54 stage A applied")

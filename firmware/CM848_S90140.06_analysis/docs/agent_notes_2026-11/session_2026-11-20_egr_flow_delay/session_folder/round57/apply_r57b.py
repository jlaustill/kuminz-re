"""Round 57 stage B: two of the five warning chime sources of cm848_updateEngineWarningFlags kept legacy protection_*
names (none in CM550).
- protection_fault_latch_flag is 1 while any of four rail pressure / fuel metering faults is set (fault word 3 bits
  9-12: P1221 / P1222 / P1222 / P1223 by their setters' plates); PCI TX[2] 0x35 bit 6 sends it OR logical output 4's
  request ("request 4 or P1221-P1223" in that builder's plate). The 11.45 e2m puts 8A0F +10 Trans_Cruise_Cutoff_
  Request at its address: the 11.46 block has drifted from +C on (+C / +E are the warning chime flags too).
- protection_coolant_classb_active_flag is the A/C coolant-off condition: cm848_controlAirConditioningClutchForDrTruck
  sets it while the clutch is requested with air_conditioning_coolant_temperature_ok_flag 0 and clears it below
  air_conditioning_high_coolant_temperature_on_threshold; its chime is e2m 8B2D +6 AC_Coolant_Off_Chime_Count.
Idempotent.  usage: apply_r57b.py <repo> <map.csv>"""
import os
import sys

sys.path.insert(0, "/home/linux/.claude/jobs/374b0424/tmp/w15/r53")
from e2m_cite import Records, Rows  # noqa: E402

repo, map_path = os.path.abspath(sys.argv[1]), sys.argv[2]
R = "PR #53 round 57"
g = Rows(repo, R)
if "fuel_pressure_fault_active_flag" in g.names:
    print("already applied")
    sys.exit(0)
rec = Records(repo)
FUEL = "fuel_pressure_fault_active_flag"
AC = "air_conditioning_coolant_off_flag"
RENAMES = [
    ("0x0040b214", "protection_fault_latch_flag", FUEL,
     "1 while any of fault_detected_cal.fuel_pressure_governed_speed_check_error (P1221) / "
     ".fuel_pressure_governor_demand_above_limit_error / .fuel_pressure_decay_below_model_error (P1222) / "
     ".fuel_metering_feedback_low_error (P1223) is set - fault word 3 bits 9-12 - else 0 "
     "(cm848_updateEngineWarningFlags each pass). Its rising edge chimes warning_chime_count_fuel_pressure_fault times; "
     "cm848_buildPciTransmitMessage2CruiseControlAndStatusBits sends it OR logical output 4's request as PCI 0x35 bit 6. "
     "The 11.45 e2m puts 8A0F +10 Trans_Cruise_Cutoff_Request here: the 11.46 layout of 8A0F drifts from +C on."),
    ("0x0040b216", "protection_fault_latch_flag_copy", f"{FUEL}_copy",
     f"A copy of {FUEL} written each cm848_updateEngineWarningFlags pass; no ROM or flash2 code reads it."),
    ("0x003fcdba", "protection_fault_latch_flag_previous", f"{FUEL}_previous",
     f"{FUEL} at the previous cm848_updateEngineWarningFlags pass: the rising edge that loads warning_chime_countdown."),
    ("0x0040873c", "warning_chime_count_fault_latch", "warning_chime_count_fuel_pressure_fault",
     f"The chime count for a rising edge of {FUEL} (warning_chime_countdown = count x warning_chime_duration x 5 / 10). "
     "8B2D ends at +9, so no e2m record covers it."),
    ("0x0040b1e8", "protection_coolant_classb_active_flag", AC,
     "The A/C coolant-off condition: cm848_controlAirConditioningClutchForDrTruck sets it while the A/C clutch is "
     "requested (logical_output_request_bits_32_to_39.air_conditioning_clutch_request) with "
     "air_conditioning_coolant_temperature_ok_flag 0 and clears it when the coolant drops below "
     "air_conditioning_high_coolant_temperature_on_threshold. Its rising edge chimes "
     "warning_chime_count_air_conditioning_coolant_off times (e2m 8B2D +6 AC_Coolant_Off_Chime_Count). Nothing "
     "'class B' or protection about it."),
    ("0x003fcdb2", "protection_coolant_classb_active_flag_previous", f"{AC}_previous",
     f"{AC} at the previous cm848_updateEngineWarningFlags pass: the rising edge that loads warning_chime_countdown."),
    ("0x00408738", "warning_chime_count_coolant_class_b", "warning_chime_count_air_conditioning_coolant_off",
     f"The chime count for a rising edge of {AC} (e2m 8B2D +6 - cited in the earlier note)."),
]
for a, cur, new, text in RENAMES:
    g.rename(rec, a, cur, new, None, None, text)
g.save(map_path)
print(f"{len(RENAMES)} globals renamed")

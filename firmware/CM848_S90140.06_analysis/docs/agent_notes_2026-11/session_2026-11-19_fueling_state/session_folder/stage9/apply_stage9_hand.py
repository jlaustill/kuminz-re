"""Stage 9 (wave 14) hand part: two splits that were left out of the agents' bins.
- e2m 107C +5A / +5C / +5E and 107D +2E, the rpm deceleration limit. The dword fuel_demand_integrator_b covered the I
  term (rendered ._0_2_) and the P term (._2_2_). cm848_runOperatingModeSpeedGovernor integrates the rpm drop into the I
  term (clamped 0..maximum), sets the P term, and stores their clamped sum (Decel_Limit_Fuel).
- e2m 8194 +10 / +11: the word crank_timer_offset_cal covered two byte records. Its ._0_1_ reads are Crank_Sync_Tooth,
  its (byte) read is Crank_Teeth_Per_Cam_Measure.
Dump values are raw at the new widths. Writes map_stage9_hand.csv (address,name,old_label,kind).
usage: apply_stage9_hand.py <stage9 dir> <CM848 output dir>"""
import os
import sys

here, out = sys.argv[1:3]
ROWS = [
    ("0x0040a204", "fuel_demand_integrator_b", "dword", "rpm_deceleration_limit_integral_term", "i16",
     "e2m 107C +5A Decel_Rate_I_Term 'Integral term of rpm decel limit control' (MM3S, signed, 0.0679 mm3 per count; 0"
     " in the dump): cm848_runOperatingModeSpeedGovernor adds fuel_demand_integrator_gain_a_cal x the rpm drop >> 8 each"
     " pass (it is zeroed while the intake manifold pressure is below rpm_drop_fuel_minimum_manifold_pressure) and"
     " clamps it to 0..rpm_deceleration_limit_fuel_maximum; cm848_initFuelDemandVariables clears it. It was the high"
     " half (._0_2_) of the dword fuel_demand_integrator_b, which also covered the P term."),
    ("0x0040a206", "fuel_demand_integrator_b+2", "", "rpm_deceleration_limit_proportional_term", "i16",
     "e2m 107C +5C Decel_Rate_P_Term 'Proportional term of rpm decel limit control' (MM3S, signed; -32 in the dump):"
     " fuel_demand_integrator_gain_b_cal x the rpm drop >> 8, set each pass by cm848_runOperatingModeSpeedGovernor. It was"
     " the low half (._2_2_) of the dword fuel_demand_integrator_b."),
    ("0x0040a208", "fuel_demand_integrator_b_sum", "word", "rpm_deceleration_limit_fuel", "i16",
     "e2m 107C +5E Decel_Limit_Fuel 'Calculated fuel required to maintain rpm decel target' (MM3S, signed; 0 in the"
     " dump): the I term plus the P term, clamped to 0..rpm_deceleration_limit_fuel_maximum by"
     " cm848_runOperatingModeSpeedGovernor, then compared with fuel_demand_decaying_peak."),
    ("0x003ff6b4", "fuel_demand_integrator_b_limit", "word", "rpm_deceleration_limit_fuel_maximum", "word",
     "e2m 107D +2E Decel_Limit_Fuel_Max 'Max fuel value for rpm decel limit control algorithm' (MM3S, 0.0679 mm3 per"
     " count; 662 in the dump = 45 mm3): the upper clamp of the rpm deceleration limit's I term and of its sum. RAM"
     " outside the EEPROM mirror, so no _cal."),
    ("0x00408f66", "crank_timer_offset_cal", "word", "crank_sync_tooth", "byte",
     "e2m 8194 +10 Crank_Sync_Tooth 'Crank tooth number on which speed measurement is synced' (1 byte; 10 in the dump):"
     " written into the low byte of TPUA_CH14_PARAM0.PARAM7 by mpc555_updateEngineRunState and read by"
     " mpc555_resetEngineTimingAccumulators. The word row also covered 8194 +11 (now"
     " crank_teeth_per_cam_measurement). RAM outside the EEPROM mirror, so no _cal."),
    ("0x00408f67", "crank_timer_offset_cal+1", "", "crank_teeth_per_cam_measurement", "byte",
     "e2m 8194 +11 Crank_Teeth_Per_Cam_Measure 'crank teeth between cam targets' (1 byte; 10 in the dump):"
     " mpc555_resetEngineTimingAccumulators multiplies it by 2500000 / tooth_period_buffer_initial_engine_speed. It was"
     " read as (byte)crank_timer_offset_cal, the low byte of the old word row."),
]
path = os.path.join(out, "global_variables.csv")
lines = open(path, newline="").read().split("\n")
index = {l.split(",", 1)[0]: i for i, l in enumerate(lines) if l.startswith("0x")}
for address, old, old_type, new, new_type, comment in ROWS:
    a, name, typ, c = (lines[index[address]].split(",", 3) + [""])[:4]
    assert (name, typ) == (old, old_type), (address, name, typ)
    lines[index[address]] = ",".join([a, new, new_type, f"{comment} (was {old})" + (f" | earlier note: {c}" if c else "")])
open(path, "w", newline="").write("\n".join(lines))
with open(os.path.join(here, "map_stage9_hand.csv"), "w") as f:
    f.write("address,name,old_label,kind\n")
    for address, old, _, new, _, _ in ROWS:
        f.write(f"{address},{new},{old},global\n")
print(f"{len(ROWS)} hand rows applied")

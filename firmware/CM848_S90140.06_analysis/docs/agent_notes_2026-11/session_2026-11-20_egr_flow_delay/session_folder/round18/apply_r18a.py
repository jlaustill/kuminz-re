"""Round 18 stage A (types): three round 15 / 16 type leads.
- cruise_pid_integrator_q16 (0x3fd032) as q16_fixed_point_t (the fuel pressure governor's Q16 states use it): the
  governor reads and writes the integer half as a word (12 lines, now .integer_part), the preset clears the fraction
  (DAT_003fd034, now .fractional_part) and the integration is a dword (6 lines, were _-prefixed; now casts).
  The pilot build showed no pieces and one fewer underscore warning.
- The AFC fueling slew rates (e2m 11D5 +C / +10 / +14, 4-byte records at 0x3feffe / 0x3ff002 / 0x3ff006): dwords
  (0x0001cc00 each in the dump) on word rows named fuel_demand_load_*, read as dwords by
  cm848_calculateAirFuelControlFuelLimit (they rendered _-prefixed); renamed with the type, since a _-prefixed token
  cannot pass a label-only proof.
- The 4D fueling lookup caches (0x40a8a1 / 0x40a8a5): two words each (2 / 8 in the dump: the x and y segment
  offsets of cm848_dualAxisTableInterpolation), typed word; now word[2] named ..._cached_axis_offsets (the round 10
  rule for 2-D caches).
usage: apply_r18a.py <repo>"""
import os
import sys

gp = os.path.join(os.path.abspath(sys.argv[1]), "firmware/CM848_S90140.06_analysis/output/global_variables.csv")
ROWS = {
    "0x003fd032": ("cruise_pid_integrator_q16", "q16_fixed_point_t",
                   "The cruise / road speed governor's integrator (Q16.16): the integration adds the error x "
                   "cruise_pid_integral_gain and the integral adjustment as a dword, the clamps and the fueling read "
                   "the integer half (.integer_part), and the preset writes the integer half and clears the fraction "
                   "(was the word row 'Q16 cruise PID integral accumulator (ROM-aliased _prefix)'; the _ came from the "
                   "dword accesses on a word row)"),
    "0x003feffe": ("air_fuel_control_fueling_slew_rate_1", "dword",
                   "e2m 11D5 +C AFC_Fueling_Slew_Rate_1 'Slew rate applied to AFC_Fueling when > AFC_Fueling_Threshold_1' "
                   "(MM3S/SEC, 4 bytes; address from the ECU's parameter ID table): cm848_calculateAirFuelControlFuelLimit "
                   "slews by it above air_fuel_control_fueling_threshold_1 (0x0001cc00 in the dump) (was "
                   "fuel_demand_load_threshold_d word)"),
    "0x003ff002": ("air_fuel_control_fueling_slew_rate_2", "dword",
                   "e2m 11D5 +10 AFC_Fueling_Slew_Rate_2: the slew rate above air_fuel_control_fueling_threshold_2 (4 "
                   "bytes; 0x0001cc00) (was fuel_demand_load_result_working word)"),
    "0x003ff006": ("air_fuel_control_fueling_slew_rate_3", "dword",
                   "e2m 11D5 +14 AFC_Fueling_Slew_Rate_3: the slew rate above air_fuel_control_fueling_threshold_3 (4 "
                   "bytes; 0x0001cc00) (was fuel_demand_load_select_working word)"),
    "0x0040a8a1": ("four_dimensional_fueling_steady_state_cached_axis_offsets", "word[2]",
                   "Lookup cache of the steady-state 4D fueling map: the x / y segment offsets of "
                   "cm848_dualAxisTableInterpolation (2 / 8 in the dump; [0] = 2 at power-up) (was "
                   "four_dimensional_fueling_steady_state_cached_axis_offset word)"),
    "0x0040a8a5": ("four_dimensional_fueling_transient_cached_axis_offsets", "word[2]",
                   "Lookup cache of the transient 4D fueling map: the x / y segment offsets (2 / 8 in the dump) (was "
                   "four_dimensional_fueling_transient_cached_axis_offset word)"),
}
lines = open(gp).read().split("\n")
done = 0
for i, line in enumerate(lines):
    a = line[:10]
    if a in ROWS:
        addr, name, typ, comment = (line.split(",", 3) + [""])[:4]
        new_name, new_type, new_comment = ROWS[a]
        quoted = comment and comment in new_comment  # the integrator's new comment quotes its old one
        lines[i] = ",".join([addr, new_name, new_type,
                             new_comment + (" | earlier note: " + comment if comment and not quoted else "")])
        done += 1
assert done == len(ROWS), done
open(gp, "w").write("\n".join(lines))
print(done, "rows")

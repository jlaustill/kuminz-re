"""Replace the 12 flat high speed governor gain rows (sets 17-19) with 3 high_speed_governor_gain_set_t rows and add
the rows of cm848_loadHighSpeedGovernorWorkingGainSet (0x5c950 / 0x5c952 and gain sets 20 / 21).
Usage: hsg_gain_set_rows.py <global_variables.csv>"""
import sys

path = sys.argv[1]
lines = open(path).read().split("\n")
drop = {"0x0005c31a", "0x0005c31c", "0x0005c31e", "0x0005c320", "0x0005c324", "0x0005c326", "0x0005c328",
        "0x0005c32a", "0x0005c32c", "0x0005c32e", "0x0005c330", "0x0005c332"}
new_sets = {
    "0x0005c31a": "0x0005c31a,high_speed_governor_high_reference_speed_gain_set,high_speed_governor_gain_set_t,Gain set code 19 (derivative / error filter coefficient / integral / proportional = 2 / 0 / 262 / 82): selectHighSpeedGovernorGainSet loads it while engine_speed_limit_arbitrated is above high_speed_governor_high_reference_speed_threshold. ROM; read only (lhz). CM550 keeps the same words at 0x80811e-0x808124 (its error filter coefficient is the e2m hsg_engine_speed_error_filter_time_constant_for_high_ref_speed_c @0x808120). Typed as one struct 2026-11-18 (were the flat rows high_speed_governor_high_reference_speed_derivative_gain / _error_filter_coefficient / _integral_gain / _proportional_gain)",
    "0x0005c324": "0x0005c324,high_speed_governor_low_reference_speed_gain_set,high_speed_governor_gain_set_t,Gain set code 18 (2 / 0 / 262 / 82): selectHighSpeedGovernorGainSet loads it while engine_speed_limit_arbitrated is below high_speed_governor_low_reference_speed_threshold. ROM; read only (lhz). CM550 0x808128-0x80812e (e2m hsg_engine_speed_error_filter_time_constant_for_low_ref_speed_co @0x80812a). Typed as one struct 2026-11-18 (were the flat rows high_speed_governor_low_reference_speed_derivative_gain / _error_filter_coefficient / _integral_gain / _proportional_gain)",
    "0x0005c32c": "0x0005c32c,high_speed_governor_transient_gain_set,high_speed_governor_gain_set_t,Gain set code 17 (2 / 0 / 262 / 82): selectHighSpeedGovernorGainSet loads it while engine acceleration is above high_speed_governor_transient_acceleration_threshold. ROM; read only (lhz). CM550 0x808130-0x808136 (e2m hsg_engine_speed_error_filter_time_constant_for_transient_condit @0x808132). Typed as one struct 2026-11-18 (were the flat rows high_speed_governor_transient_derivative_gain / _error_filter_coefficient / _integral_gain / _proportional_gain)",
}
working = [
    "0x0005c950,system_speed_limit_working_minimum,word,cm848_loadHighSpeedGovernorWorkingGainSet raises system_speed_limit_working to this when it is at or below it (lhz @ 0x424a8) - 0 here; no other code writes the limit word (whole-binary sweep: lhz @ 0x424ac / sth @ 0x424b8 only) so the test passes only while it is 0 (new row 2026-11-18)",
    "0x0005c952,high_speed_governor_working_gain_set_selection_threshold,word,fuel_flow_rpm_divisor below this (205) loads high_speed_governor_gain_set_20 - otherwise high_speed_governor_gain_set_21 (lhz @ 0x424c8). What fuel_flow_rpm_divisor measures is not identified: its writers are the legacy-named Bank 2 protectionTimeoutControl / initGovernorJ1939Bypass / etcTransmissionModeControl (new row 2026-11-18)",
    "0x0005c954,high_speed_governor_gain_set_20,high_speed_governor_gain_set_t,Working gain set code 20 (6 / 64551 / 918 / 82): cm848_loadHighSpeedGovernorWorkingGainSet copies it into the high_speed_governor_*_working words while fuel_flow_rpm_divisor is below high_speed_governor_working_gain_set_selection_threshold (lhz @ 0x424e8-0x42514) (new row 2026-11-18)",
    "0x0005c95c,high_speed_governor_gain_set_21,high_speed_governor_gain_set_t,Working gain set code 21 (6 / 64551 / 918 / 82 - the same as set 20 in this calibration): loaded otherwise (lhz @ 0x42530 on) (new row 2026-11-18)",
]
out, done = [], 0
for line in lines:
    address = line.split(",", 1)[0]
    if address in new_sets:
        out.append(new_sets[address])
        done += 1
        continue
    if address in drop:
        continue
    if address == "0x0005c964":
        out.extend(working)
        done += 1
    out.append(line)
assert done == 4, done
open(path, "w").write("\n".join(out))
print("rows", len(lines), "->", len(out))

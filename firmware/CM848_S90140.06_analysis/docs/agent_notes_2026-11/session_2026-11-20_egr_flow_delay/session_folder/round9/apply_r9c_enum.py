"""Round 9 stage C: TRANSMISSION_PRESSURE_STATE (e2m 8C53 +0 RE_Trans_Pressure_State, 'Indicate the RE transmission
pressure state'; the e2m gives no value labels). Every value the code stores (1..24) is one mode handler's target, read from
the table or word it loads just before (round 9 stage A / B names), and the code compares only with 0x11 and 0x18; so
every member is proved by its store. The struct field transmission_pressure_state_t.pressure_state takes the enum.
usage: apply_r9c_enum.py <repo>"""
import csv
import io
import os
import sys

repo = os.path.abspath(sys.argv[1])
out = os.path.join(repo, "firmware", "CM848_S90140.06_analysis", "output")
E = "TRANSMISSION_PRESSURE_STATE"
MEMBERS = [
    (1, "NORMAL_CURVE", "governor_pressure_base_curve (e2m RE_Normal_Curve 'Gov press vs OSS for normal operating "
                        "conditions'): cm848_selectGovernorPressureBaseCurve; cm848_selectGovernorPressureAntiHunt after a shift"),
    (2, "FUEL_ECONOMY_CURVE", "governor_pressure_fuel_economy_curve (RE_Fuel_Economy_Curve) below "
                              "governor_pressure_fuel_economy_maximum_throttle: cm848_selectGovernorPressureBaseCurve"),
    (3, "CRUISE_CURVE", "governor_pressure_cruise_curve (RE_Cruise_Curve): cm848_selectGovernorPressureCruise"),
    (4, "COLD_CURVE", "governor_pressure_cold_curve (RE_Cold_Curve): cm848_selectGovernorPressureCold"),
    (5, "WIDE_OPEN_THROTTLE_CURVE", "governor_pressure_wide_open_throttle_curve (RE_WOT_Curve): the WOT / detent mode "
                                    "(cm848_selectGovernorPressureWideOpenThrottle / _Normal, cm848_runTransmissionControl)"),
    (6, "WIDE_OPEN_THROTTLE_COLD_CURVE", "governor_pressure_wide_open_throttle_cold_curve (RE_WOT_Cold_Curve): "
                                         "cm848_selectGovernorPressureCold"),
    (7, "WIDE_OPEN_THROTTLE_1_2_HOLD", "governor_pressure_wide_open_throttle_1_2_hold_pressure (RE_WOT_Hold_Pressure_1_2): "
                                       "holds 1st until the upshift point (or while the anti-hang timer runs)"),
    (8, "WIDE_OPEN_THROTTLE_1_2_BOOST", "governor_pressure_wide_open_throttle_1_2_boost_pressure (RE_WOT_Boost_Pressure_1_2): "
                                        "forces the 1-2 upshift"),
    (9, "WIDE_OPEN_THROTTLE_2_3_HOLD", "governor_pressure_wide_open_throttle_2_3_hold_pressure (RE_WOT_Hold_Pressure_2_3)"),
    (10, "WIDE_OPEN_THROTTLE_2_3_BOOST", "governor_pressure_wide_open_throttle_2_3_boost_pressure (RE_WOT_Boost_Pressure_2_3)"),
    (11, "LOW_RANGE_CURVE", "governor_pressure_low_range_curve (RE_Low_Range_Curve): cm848_selectGovernorPressureLowRange, "
                            "cm848_runTransmissionControl"),
    (12, "LOW_RANGE_1_2_HOLD", "transmission_low_range_1_2_hold_pressure (RE_Low_Range_Hold_Pressure_1_2)"),
    (13, "LOW_RANGE_1_2_BOOST", "transmission_low_range_1_2_boost_pressure (RE_Low_Range_Boost_Pressure_1_2)"),
    (14, "LOW_RANGE_2_3_HOLD", "transmission_low_range_2_3_hold_pressure (RE_Low_Range_Hold_Pressure_2_3)"),
    (15, "LOW_RANGE_2_3_BOOST", "transmission_low_range_2_3_boost_pressure (RE_Low_Range_Boost_Pressure_2_3)"),
    (16, "LOCKUP_BOOST", "governor_pressure_lockup_boost (RE_Lockup_Boost 'Gov pressure target during lockup, to prevent "
                         "downshift'): cm848_selectGovernorPressureLockupBoost, cm848_runTransmissionControl"),
    (17, "2ND_GEAR_LOCKUP_BOOST", "governor_pressure_2nd_gear_lockup_boost (RE_Lockup_Boost_2nd): cm848_runTransmissionControl; "
                                  "cm848_determineCurrentGearAndLockupInhibit compares with it"),
    (18, "ANTI_HUNT_1_2_BOOST", "transmission_anti_hunt_1_2_boost_pressure (RE_AH_Boost_Curve_1_2): forces the 1-2 upshift "
                                "(cm848_selectGovernorPressureAntiHunt / _Normal)"),
    (19, "ANTI_HUNT_2_3_BOOST", "transmission_anti_hunt_2_3_boost_pressure (RE_AH_Boost_Curve_2_3)"),
    (20, "ANTI_HUNT_1_2_HOLD", "transmission_anti_hunt_1_2_hold_pressure (RE_Hold_Curve_1): prevents the 1-2 upshift"),
    (21, "ANTI_HUNT_2_3_HOLD", "transmission_anti_hunt_2_3_hold_pressure (RE_Hold_Curve_2)"),
    (22, "MANUAL_2ND_CURVE", "governor_pressure_manual_2nd_curve (RE_Manual_2nd_Curve) with the lever in 1 or 2"),
    (23, "OVERRIDE", "governor_pressure_override_value (RE_Governor_Set_Override_Value) while "
                     "governor_pressure_override_enable is set: cm848_selectGovernorPressureLockupBoost"),
    (24, "EXHAUST_BRAKE_CURVE", "governor_pressure_exhaust_brake_curve with the exhaust brake switch (12) on at light "
                                "throttle (cm848_selectGovernorPressureBaseCurve); the lockup schedule and "
                                "cm848_determineCurrentGearAndLockupInhibit compare with it"),
]


def text_of(row):
    s = io.StringIO()
    csv.writer(s, lineterminator="").writerow(row)
    return s.getvalue()


p = os.path.join(out, "enums.csv")
s = open(p).read()
assert f"\n{E}," not in s
block = [f"# {E}: e2m 8C53 +0 RE_Trans_Pressure_State; the governor pressure mode that set governor_pressure_target "
         f"(PR #53 round 9, every value proved by its store)"]
block += [text_of([E, str(v), f"{E}_{m}", c, "2"]) for v, m, c in MEMBERS]
open(p, "w").write(s.rstrip("\n") + "\n" + "\n".join(block) + "\n")
p = os.path.join(out, "structure_definitions.csv")
lines = open(p).read().split("\n")
done = 0
for i, l in enumerate(lines):
    if l.startswith("transmission_pressure_state_t,0x0040b100,pressure_state,word,2,"):
        row = next(csv.reader([l]))
        row[3] = E
        row[5] = row[5] + f" Typed {E} (round 9)."
        lines[i] = text_of(row)
        done += 1
assert done == 1
open(p, "w").write("\n".join(lines))
print(f"{len(MEMBERS)} members; field typed")

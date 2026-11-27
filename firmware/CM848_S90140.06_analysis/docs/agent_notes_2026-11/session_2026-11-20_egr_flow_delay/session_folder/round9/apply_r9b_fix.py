"""Round 9 stage B post-fix: stage 9A's 14 exhaust brake table rows get their e2m records (9A called them '11.46 tables';
they are e2m 8CA6..8CB1 / 8D1D / 8D1E). String edits only (global_variables.csv takes commas unquoted).
usage: apply_r9b_fix.py <repo>"""
import os
import re
import sys

repo = os.path.abspath(sys.argv[1])
p = os.path.join(repo, "firmware", "CM848_S90140.06_analysis", "output", "global_variables.csv")
NEW = {
    "0x004080b0": "e2m 8CA6 RE_Cruise_Exhaust_Brake_3_4_OSS_Axis ('Trans output shaft speed for cruise 3-4 shift curve e_brake active')",
    "0x004080c2": "e2m 8CA7 RE_Cruise_Exhaust_Brake_3_4 ('TPS vs OSS defines 3-4 upshift point in cruise mode e_brake active'): "
                  "with switch 12 on and exhaust_brake_transmission_features_inhibit clear, cm848_selectGovernorPressureCruise "
                  "requests the 3-4 below it",
    "0x004080d4": "e2m 8CA8 RE_Cruise_Exhaust_Brake_4_3_OSS_Axis ('Trans out shaft speed for cruise 4-3 downshift curve e_brake active')",
    "0x004080e6": "e2m 8CA9 RE_Cruise_Exhaust_Brake_4_3 ('TPS vs OSS defines the 4-3 downshift point in cruise mode e_brake active'): "
                  "with switch 12 on, cm848_selectGovernorPressureCruise requests the 4-3 at or above it",
    "0x004080f8": "e2m 8CAA RE_Lockup_Curve_4_Exhaust_Brake_OSS_Axis ('Trans output shaft speed for 4th gear lockup curve e_brake active')",
    "0x0040810a": "e2m 8D1E RE_Lockup_Curve_4_Exhaust_Brake_Boost_Axis ('Boost pressure axis for 4th gear lockup curve with e_brake "
                  "active'; inline before the grid in 11.46)",
    "0x00408114": "e2m 8CAB RE_Lockup_Curve_4_Exhaust_Brake ('Max throttle for lockup in 4th gear vs OSS with e_brake active'): "
                  "8 x 4; cm848_applyConverterLockupSchedule while switch 12 is on",
    "0x00408154": "e2m 8CAC RE_Lockup_Curve_Cruise_Exhaust_Brake_OSS_Axis ('Trans output shaft speed axis for cruise lockup curve with "
                  "e_brake active')",
    "0x00408166": "e2m 8D1D RE_Lockup_Curve_Cruise_Exhaust_Brake_Boost_Axis ('Boost pressure axis for cruise lockup curve with e_brake "
                  "active'; inline before the grid in 11.46)",
    "0x00408170": "e2m 8CAD RE_Lockup_Curve_Cruise_Exhaust_Brake ('Max throttle for lockup vs OSS in cruise mode with e_brake active'): 8 x 4",
    "0x004081b0": "e2m 8CAE RE_Normal_Exhaust_Brake_3_4_OSS_Axis ('Trans output shaft speed axis for normal 3-4 curve with e_brake active')",
    "0x004081c2": "e2m 8CAF RE_Normal_Exhaust_Brake_3_4 ('TPS for 3-4 upshift vs OSS when not in cruise mode with e_brake active'): "
                  "cm848_requestOverdriveShiftsNormal requests the 3-4 below it while switch 12 is on",
    "0x004081d4": "e2m 8CB0 RE_Normal_Exhaust_Brake_4_3_OSS_Axis ('Trans output shaft speed axis for normal 4-3 curve with e_brake active')",
    "0x004081e6": "e2m 8CB1 RE_Normal_Exhaust_Brake_4_3 ('TPS for 4-3 downshift vs OSS when not in cruise mode with e_brake active'): "
                  "cm848_requestOverdriveShiftsNormal requests the 4-3 at or above it while switch 12 is on",
}
lines = open(p).read().split("\n")
done = 0
for i, l in enumerate(lines):
    a = l[:10].lower()
    if a in NEW:
        addr, name, typ, comment = l.split(",", 3)
        m = re.search(r" \(was [A-Za-z0-9_]+\)( \| earlier note: .*)?$", comment)
        assert m, (a, comment[-60:])
        tail = re.sub(r" \| earlier note: .*$", "", comment[m.start():])
        lines[i] = ",".join([addr, name, typ, NEW[a] + tail])
        done += 1
assert done == len(NEW), done
open(p, "w").write("\n".join(lines))
print("fixed", done)

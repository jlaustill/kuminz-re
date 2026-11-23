"""Round 43 stage C: the end of injection block named by its e2m records. An untruncated search found e2m 8B47 (+0
EOI_Default, +2 EOI_Hydraulic_Delay, +4 EOI_Max_Limit, +6 EOI_Min_Limit) and 8B48 (+0 EOI); the dumped parameter ID
table does not reach them, but names, order, signs, scales and descriptions match the code and the dump. The pulse
width addend becomes main_injection_end_timing_hydraulic_delay; all five rows cite their record. Idempotent.
usage: apply_r43c.py <repo> <map.csv>"""
import os
import sys

repo, map_path = os.path.abspath(sys.argv[1]), sys.argv[2]
gp = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output/global_variables.csv")
R = "PR #53 round 43"
CITE = {
    "0x0040b28a": "e2m 8B48 +0 EOI 'Main end of injection' (CRANK_DEG_BTDC, signed, 0.1171875 per count; kept word: "
                  "cm848_updateOilChangeMonitor loads it with lhz). ",
    "0x00408800": "e2m 8B47 +0 EOI_Default 'Main end of injection default; EOI set to this when no injection' "
                  "(CRANK_DEG_BTDC, signed, 0.1171875; -171 = -20.04 deg in the dump). ",
    "0x00408802": "e2m 8B47 +2 EOI_Hydraulic_Delay 'Hydraulic delay added to HPCR_Duration_Main_Injection to determine EOI' "
                  "(uSEC, 0.4 per count; 1975 = 790 us in the dump). ",
    "0x00408804": "e2m 8B47 +4 EOI_Max_Limit (CRANK_DEG_BTDC, signed, 0.1171875; 512 = 60.00 deg in the dump). ",
    "0x00408806": "e2m 8B47 +6 EOI_Min_Limit (CRANK_DEG_BTDC, signed, 0.1171875; -171 = -20.04 deg in the dump). ",
}
NOTE = ("(the blocks lie past the dumped parameter ID table; name, order, sign, scale and description match the code) ")
g = open(gp).read().split("\n")
if any(l.startswith("0x00408802,main_injection_end_timing_hydraulic_delay,") for l in g):
    print("already applied")
    sys.exit(0)
for k, l in enumerate(g):
    a = l[:10]
    if a in CITE and l.split(",")[1].startswith("main_injection_end_timing"):
        p = l.split(",", 3)
        name = p[1]
        if a == "0x00408802":
            assert name == "main_injection_end_timing_pulse_width_addend"
            name = "main_injection_end_timing_hydraulic_delay"
            p[3] = p[3].replace("(was fuel_rpm_compensated_offset_pulse_width_addend;",
                                "(was main_injection_end_timing_pulse_width_addend in d8d2cdf, before that "
                                "fuel_rpm_compensated_offset_pulse_width_addend;")
        g[k] = f"{a},{name},{p[2]},{CITE[a]}{NOTE}| {p[3]}"
open(gp, "w").write("\n".join(g))
with open(map_path, "w") as fh:
    fh.write("address,name,old_label,kind,dims\n0x00408802,main_injection_end_timing_hydraulic_delay,"
             "main_injection_end_timing_pulse_width_addend,global,1\n")
print("stage C applied")

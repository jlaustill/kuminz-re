"""Round 47 stage B: two more rows the dumped table resolves to an uncited default-e2m record, in consistent blocks:
- 0x40a442 fuel_blend_correction_inhibit_flag (dword) is two words of 1A57 (its other rows +4..+C are already named):
  +0 CHH_CBO_Off ('Flag indicating that EGR may be turned off'): cm848_updateEgrSystemHealthFlags sets it while charge
  or exhaust pressure runs on its backup source, and it stops cm848_applyOffNominalTimingAdjustment -> egr_off_allowed_flag;
  +2 CHH_EGR_Cooler_Fouled: cm848_updateEgrCoolerFoulingFaultCounter sets it at the fault time and clears it at 0, and it
  feeds egr_system_failure_flag -> egr_cooler_fouled_flag (a new row).
- 0x3fd530 j1939_ccvs1_switch_logic_option_cal = 1180 +8 Set_Accel_Switch_Select ('TRUE = SET/ACCEL and RESUME/COAST,
  FALSE = SET/COAST and RESUME/ACCEL'): its only reads map the switches onto the CCVS1 set / resume byte.
Idempotent.  usage: apply_r47b.py <repo> <map.csv>"""
import ast
import os
import re
import sys

repo, map_path = os.path.abspath(sys.argv[1]), sys.argv[2]
gp = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output/global_variables.csv")
src = open("/home/linux/.claude/jobs/374b0424/tmp/w15/apply_hand_worklist.py").read()
BANNED = ast.literal_eval(re.search(r"BANNED = (\{.*?\})", src, re.S).group(1))
R = "PR #53 round 47"
g = open(gp).read().split("\n")
idx = {l[:10]: k for k, l in enumerate(g) if l.startswith("0x")}
names = {l.split(",")[1] for l in g if l.startswith("0x") and len(l.split(",")) > 1}
if "egr_off_allowed_flag" in names:
    print("already applied")
    sys.exit(0)
for new in ("egr_off_allowed_flag", "egr_cooler_fouled_flag", "cruise_set_accelerate_switch_select_cal"):
    assert new not in names and not any(t in BANNED for t in new.split("_")), new
p = g[idx["0x0040a442"]].split(",", 3)
assert p[1] == "fuel_blend_correction_inhibit_flag" and p[2] == "dword", p[:3]
g[idx["0x0040a442"]] = (
    "0x0040a442,egr_off_allowed_flag,word,e2m 1A57 +0 CHH_CBO_Off 'Flag indicating that EGR may be turned off.' "
    "(UNITLESS): cm848_updateEgrSystemHealthFlags sets it while charge_pressure_source or exhaust_pressure_source is "
    "SENSOR_VALUE_SOURCE_BACKUP and clears it otherwise; while it is set cm848_applyOffNominalTimingAdjustment skips its "
    "correction. Was a dword covering it and egr_cooler_fouled_flag (was fuel_blend_correction_inhibit_flag; " + R + ")")
g.insert(idx["0x0040a442"] + 1,
         "0x0040a444,egr_cooler_fouled_flag,word,e2m 1A57 +2 CHH_EGR_Cooler_Fouled 'Flag indicating the EGR cooler has "
         "fouled.' (UNITLESS): cm848_updateEgrCoolerFoulingFaultCounter sets it once egr_cooler_fouling_fault_counter "
         "reaches its limit and clears it when the counter is back at 0; it feeds egr_system_failure_flag. The second "
         "word of the old dword fuel_blend_correction_inhibit_flag (" + R + ")")
idx = {l[:10]: k for k, l in enumerate(g) if l.startswith("0x")}
p = g[idx["0x003fd530"]].split(",", 3)
assert p[1] == "j1939_ccvs1_switch_logic_option_cal", p[1]
g[idx["0x003fd530"]] = (
    "0x003fd530,cruise_set_accelerate_switch_select_cal," + p[2] + ",e2m 1180 +8 Set_Accel_Switch_Select '[CRSEACSW] "
    "TRUE = SET/ACCEL and RESUME/COAST FALSE = SET/COAST and RESUME/ACCEL' (EEPROM offset 0xae; 0 in the dump): its four "
    "reads, all in cm848_buildPgn65265CruiseControlVehicleSpeedMessage, choose which switch sets the CCVS1 accelerate "
    "and coast bits (was j1939_ccvs1_switch_logic_option_cal; " + R + ") | earlier note: " + p[3])
open(gp, "w").write("\n".join(g))
with open(map_path, "w") as fh:
    fh.write("address,name,old_label,kind,dims\n"
             "0x0040a442,egr_off_allowed_flag,fuel_blend_correction_inhibit_flag,global,1\n"
             "0x003fd530,cruise_set_accelerate_switch_select_cal,j1939_ccvs1_switch_logic_option_cal,global,1\n")
print("2 renames (one split into two words), 1 new row")

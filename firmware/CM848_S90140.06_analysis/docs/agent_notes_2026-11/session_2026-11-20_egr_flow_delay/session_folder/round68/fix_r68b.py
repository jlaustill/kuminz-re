"""Round 68 follow-up (the advisor's closing review). Idempotent: every edit skips when its new text is present.
CSV phase:
- EEPROM 0x0c is e2m 0001 +0 ECM_Part_Number 'Module Part Number' (HEX - 4 bytes): eeprom_status_block (0x0100000c)
  -> ecm_part_number_cal (dword) and 3be13ab6's boot_eeprom_status_block (0x3fee26) -> boot_ecm_part_number.
- Two e2m quotes in the new struct comments were not e2m's text: Fuel_Lvl_Last_Valid_Percent's (cut at 160 characters
  and completed by hand) and IAH_Redundant_Preheat_Req's (its comma became a dash). The file is quote-aware, so the
  exact text goes in a quoted field.
- intake_air_heater_preheat_depleted_flag's comment named the removed field ('the shared EEPROM eeprom_status_flags').
- cm848_loadCalibrationFromEeprom's plate names the part number.
Docs phase: task 046 / the PR body (the 14 application functions - 3be13ab6 says 13 / the lookup reads worse / the
follow-up / a lead); apply_r68a.py's docstring.
usage: fix_r68b.py <repo> --csv <map.csv> | --docs <pr_body.md> <hash>"""
import os
import sys

repo, phase = os.path.abspath(sys.argv[1]), sys.argv[2]
O = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")
W = "/home/linux/.claude/jobs/374b0424/tmp/w15/r68"
R = "PR #53 round 68"


def edit(path, old, new):
    p = path if os.path.isabs(path) else os.path.join(repo, path)
    s = open(p).read()
    if new in s:
        return
    assert s.count(old) == 1, (path, old[:90], s.count(old))
    open(p, "w").write(s.replace(old, new))


if phase == "--csv":
    map_path = sys.argv[3]
    G = os.path.join(O, "global_variables.csv")
    edit(G, "0x003fee26,boot_eeprom_status_block,dword,Boot kernel: cm848_loadCalibrationFromEeprom's copy of EEPROM "
            "0x0c-0x0f (eeprom_status_block) - no reader found (was eeprom_shadow_header.serial_number",
         "0x003fee26,boot_ecm_part_number,dword,Boot kernel: cm848_loadCalibrationFromEeprom's copy of EEPROM 0x0c-0x0f "
         "(ecm_part_number_cal: e2m 0001 +0 ECM_Part_Number 'Module Part Number') - no reader found (was "
         "boot_eeprom_status_block in 3be13ab6; was eeprom_shadow_header.serial_number")
    edit(G, "0x0100000c,eeprom_status_block,byte,",
         "0x0100000c,ecm_part_number_cal,dword,EEPROM 0x0c: e2m 0001 +0 ECM_Part_Number 'Module Part Number' (HEX - 4 "
         f"bytes) - the boot kernel copies it to boot_ecm_part_number (was eeprom_status_block; {R})")
    edit(G, "also sets the shared EEPROM eeprom_status_flags - re-read next start to cap the preheat to 150",
         "also sets the EEPROM-saved intake_air_heater_saved_values_cal.redundant_preheat_request (e2m 8A36 +2) - re-read "
         f"next start to cap the preheat to 150 ({R}: the old text named eeprom_status_flags)")
    T = os.path.join(O, "structure_definitions.csv")
    edit(T, "fuel_level_saved_values_t,0x003fee18,last_valid_percent,byte,1,e2m 8A24 +1 Fuel_Lvl_Last_Valid_Percent [%] "
            "'Last Valid Fuel_Lvl_Percent_Tank_Full' - seeds fuel_level_slow_filter_reference,,verified",
         "fuel_level_saved_values_t,0x003fee18,last_valid_percent,byte,1,e2m 8A24 +1 Fuel_Lvl_Last_Valid_Percent [%] "
         "'Last Valid Fuel_Lvl_Percent_Tank_Full_Avg that was sent on the bus' - seeds "
         "fuel_level_slow_filter_reference,,verified")
    edit(T, "intake_air_heater_saved_values_t,0x003fee1c,redundant_preheat_request,word,2,e2m 8A36 +2 "
            "IAH_Redundant_Preheat_Req 'If preheat w/o cranking - this param=1; saved at powerdown' | boot kernel",
         "intake_air_heater_saved_values_t,0x003fee1c,redundant_preheat_request,word,2,\"e2m 8A36 +2 "
         "IAH_Redundant_Preheat_Req 'If preheat w/o cranking, this param=1;saved at powerdown' | boot kernel")
    edit(T, "serial_reflash_status_flags_cal (cm848_beginSerialReflash / mpc555_verifyDownloadedCalibration change bits 1 "
            "and 3),,verified",
         "serial_reflash_status_flags_cal (cm848_beginSerialReflash / mpc555_verifyDownloadedCalibration change bits 1 "
         "and 3)\",,verified")
    F = os.path.join(O, "function_renames.csv")
    edit(F, "copies EEPROM 0x4a (6 bytes) / 0x50 / 0x52 / 0x54 / 0x0c (4) / 0x56 into",
         "copies EEPROM 0x4a (6 bytes) / 0x50 / 0x52 / 0x54 / 0x0c (4 - ecm_part_number_cal) / 0x56 into")
    with open(map_path, "w") as fh:
        fh.write("address,name,old_label,kind,dims\n"
                 "0x003fee26,boot_ecm_part_number,boot_eeprom_status_block,global,1\n"
                 "0x0100000c,ecm_part_number_cal,eeprom_status_block,global,1\n")
    print("csv done")
elif phase == "--docs":
    pr, hb = sys.argv[3], sys.argv[4]
    A = os.path.join(W, "apply_r68a.py")
    edit(A, "(0x199e). Thirteen application functions rendered them",
         "(0x199e). Fourteen application functions (13 in the first version of this note) rendered them")
    T46 = "work/tasks/046-cm848-egr-flow-estimate.md"
    edit(T46, "  - The boot kernel's `eeprom_header_t` ran to 0x3fee29 over the application's EEPROM mirror, so 13 application\n"
              "    functions rendered",
         "  - The boot kernel's `eeprom_header_t` ran to 0x3fee29 over the application's EEPROM mirror, so 14 application\n"
         "    functions (10 + 3 + 1; 3be13ab6's message says 13) rendered")
    edit(T46, "    dropped (`fix_r68a3.py` / `fix_r68a4.py`).\n",
         "    dropped (`fix_r68a3.py` / `fix_r68a4.py`). It is the one function that reads worse than before the round:\n"
         "    the same 4 casts and fewer placeholders (16 -> 9), but the casts now name a misleading struct pointer, and\n"
         "    its parameter 1-4 path reads as `eeprom_shadow_header.header_block + parameter + 0xb`.\n")
    edit(T46, "- **firmware/CLAUDE.md:** line 146, a factual rename from the reference refresh",
         f"- **Follow-up ({hb}), from the closing review:**\n"
         "  - EEPROM 0x0c is e2m 0001 +0 ECM_Part_Number ('Module Part Number', 4 bytes): `ecm_part_number_cal` (was\n"
         "    `eeprom_status_block`), and its boot copy at 0x3fee26 is `boot_ecm_part_number` (3be13ab6 coined\n"
         "    `boot_eeprom_status_block`).\n"
         "  - Two e2m quotes are now e2m's exact text: `Fuel_Lvl_Last_Valid_Percent`'s had been cut and completed by\n"
         "    hand, and `IAH_Redundant_Preheat_Req`'s comma had become a dash.\n"
         "  - `intake_air_heater_preheat_depleted_flag`'s comment named the removed `eeprom_status_flags`.\n"
         "  - **Two history notes repaired.** `refresh_references.py` protects old labels after \"was\", but not after\n"
         "    \"named it\". So this round's \"3be13ab6 named it boot_eeprom_status_block\" was rewritten, and so was\n"
         "    round 66's \"382fa677 named it net_combustion_torque_coolant_friction_scale\" (its follow-up c48cc435 turned\n"
         "    it into the current name). Both now read \"(was <old> in <hash>)\". `history_corruption_r68.py` also checks\n"
         "    \"named it\" and \"said\"; its two remaining hits are these intermediate names, as intended.\n"
         "- **firmware/CLAUDE.md:** line 146, a factual rename from the reference refresh")
    edit(T46, "  - 0x3fee38 is the boot kernel's word buffer",
         "  - **0x3fee34 is the same time-share:** it is typed `dword` over e2m 8B50 +0 (the oil change monitor) while the\n"
         "    +2 row at 0x3fee36 has no type, so the boot kernel's width wins there.\n"
         "  - 0x3fee38 is the boot kernel's word buffer")
    edit(pr, "  runs over them, and its time-shared uses are noted.\n",
         "  runs over them, and its time-shared uses are noted.\n"
         f"- **Follow-up ({hb}):** EEPROM 0x0c is e2m's ECM_Part_Number (`ecm_part_number_cal` / `boot_ecm_part_number`);\n"
         "  two e2m quotes made exact; a stale comment.\n")
    print("docs done")

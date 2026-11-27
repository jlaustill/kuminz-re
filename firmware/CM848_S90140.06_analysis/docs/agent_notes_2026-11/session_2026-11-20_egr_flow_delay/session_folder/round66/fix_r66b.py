"""Round 66 follow-up (the advisor's closing review), from the boot kernel's own producers. Idempotent (every edit
skips when its new text is already there).
- BOOT_DIAGNOSTIC_RESULT: 0x09 UNMAPPED_ADDRESS -> ADDRESS_NOT_ACCEPTED (the boot lookup also returns 9 for Bank 2 with
  flash2_writes_enabled 0, and cm848_trackDownloadBlock for an out-of-sequence address or a block overrun); 0x0a
  REGION_REFUSED -> ROM_HANDLER_REFUSED (no boot region has type 10 - the dispatcher's refusal is its only producer);
  0x17 EEPROM_TRANSFER_NOT_STARTED -> FLASH_ERASE_FAILED (mpc555_initEepromTransfer answers 0x17 when its flash erase
  fails); new 0x10 NO_DOWNLOAD_BLOCK / 0x14 CHECKSUM_MISMATCH / 0x15 DOWNLOAD_BLOCK_LIST_FULL (cm848_trackDownloadBlock /
  cm848_finishDownloadBlock - passed up through the write worker).
- 0x4059f4 -> coolant_torque_adjustment_factor (e2m 16A4 +1E C_CBP_Coolant_Torque_Adj_Factor) and 0x3fba10 ->
  coolant_torque_adjustment_term.
- cm848_handleBootExecuteAtAddressService: its full prototype (request / the enum return).
usage: fix_r66b.py <repo> --csv <map.csv> | --docs <pr_body.md> <hash>"""
import os
import re
import sys

repo, phase = os.path.abspath(sys.argv[1]), sys.argv[2]
O = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")
R = "PR #53 round 66"
P = "BOOT_DIAGNOSTIC_RESULT_"


def edit(path, old, new):
    p = path if os.path.isabs(path) else os.path.join(repo, path)
    s = open(p).read()
    if new in s:
        return
    assert s.count(old) == 1, (path, old[:80], s.count(old))
    open(p, "w").write(s.replace(old, new))


if phase == "--csv":
    map_path = sys.argv[3]
    ep = os.path.join(O, "enums.csv")
    edit(ep, f"BOOT_DIAGNOSTIC_RESULT,0x09,{P}UNMAPPED_ADDRESS,No memory region holds the address range "
             "(cm848_lookupBootMemoryRegionType),4",
         f"BOOT_DIAGNOSTIC_RESULT,0x09,{P}ADDRESS_NOT_ACCEPTED,No region accepts the address range - none holds it or it "
         "is Bank 2 flash while flash2_writes_enabled is 0 (cm848_lookupBootMemoryRegionType) - or "
         "cm848_trackDownloadBlock refuses it (out of sequence or past the block length) (382fa677 named it "
         "UNMAPPED_ADDRESS),4")
    edit(ep, f"BOOT_DIAGNOSTIC_RESULT,0x0a,{P}REGION_REFUSED,The region refuses the access - or the dispatcher refuses "
             "a ROM handler while the low nibble of eeprom_service_mode_flags is set,4",
         f"BOOT_DIAGNOSTIC_RESULT,0x0a,{P}ROM_HANDLER_REFUSED,The dispatcher refuses a handler in ROM (at or below "
         "0x6fffe) while the low nibble of eeprom_service_mode_flags is set - only RAM handlers run then; no boot "
         "region has type 10 (382fa677 named it REGION_REFUSED),4")
    edit(ep, f"BOOT_DIAGNOSTIC_RESULT,0x11,{P}FLASH_WRITE_FAILED,",
         f"BOOT_DIAGNOSTIC_RESULT,0x10,{P}NO_DOWNLOAD_BLOCK,cm848_trackDownloadBlock: a write while "
         "eeprom_xfer_state.block_length is 0 - no download block announced,4\n"
         f"BOOT_DIAGNOSTIC_RESULT,0x11,{P}FLASH_WRITE_FAILED,")
    edit(ep, f"BOOT_DIAGNOSTIC_RESULT,0x17,{P}EEPROM_TRANSFER_NOT_STARTED,Service 2: mpc555_initEepromTransfer returned "
             "0,4",
         f"BOOT_DIAGNOSTIC_RESULT,0x14,{P}CHECKSUM_MISMATCH,cm848_finishDownloadBlock: the block's trailing CRC differs "
         "from the running CRC (the name CM550's DIAG_RESPONSE_CODE gave 0x14),4\n"
         f"BOOT_DIAGNOSTIC_RESULT,0x15,{P}DOWNLOAD_BLOCK_LIST_FULL,cm848_finishDownloadBlock: its 10-entry block list is "
         "full,4\n"
         f"BOOT_DIAGNOSTIC_RESULT,0x17,{P}FLASH_ERASE_FAILED,Service 2: the flash erase in mpc555_initEepromTransfer "
         "(mpc555_cmfEraseBlocks then cm848_flashEraseChip) failed (382fa677 named it EEPROM_TRANSFER_NOT_STARTED),4")
    edit(ep, "the twin of J1939_DIAGNOSTIC_RESULT with the boot kernel's own 5 / 0x11 / 0x17.",
         "the twin of J1939_DIAGNOSTIC_RESULT with the boot kernel's own 5 / 0x0a / 0x10 / 0x11 / 0x14 / 0x15 / 0x17.")
    gp = os.path.join(O, "global_variables.csv")
    edit(gp, "0x004059f4,net_combustion_torque_coolant_friction_scale,i16,",
         "0x004059f4,coolant_torque_adjustment_factor,i16,e2m 16A4 +1E C_CBP_Coolant_Torque_Adj_Factor 'Used on "
         "Coolant_Torque_Adjustment in CBR' (UNITLESS): ")
    edit(gp, "(was net_combustion_torque_subtracted_term_scale; PR #53 round 66)",
         "(was net_combustion_torque_subtracted_term_scale; PR #53 round 66 - 382fa677 named it "
         "net_combustion_torque_coolant_friction_scale)")
    edit(gp, "0x003fba10,net_combustion_torque_coolant_friction_term,i16,Code (sth @ 0x503afc): "
             "friction_torque_adjustment_for_coolant_temperature x net_combustion_torque_coolant_friction_scale / 2048",
         "0x003fba10,coolant_torque_adjustment_term,i16,Code (sth @ 0x503afc): "
         "friction_torque_adjustment_for_coolant_temperature (e2m Coolant_Torque_Adjustment) x "
         "coolant_torque_adjustment_factor / 2048")
    dp = os.path.join(O, "function_definitions.csv")
    d = open(dp).read()
    F = "cm848_handleBootExecuteAtAddressService"
    if f",{F}," not in d:
        a = next(l.split(",", 1)[0] for l in open(os.path.join(O, "function_renames.csv")) if f",{F}," in l)
        d = d.rstrip("\n") + "\n" + "\n".join([
            f"{a},{F},return,,BOOT_DIAGNOSTIC_RESULT,The validator's result or the region lookup's - 0xff after the "
            f"positive response and the call ({R})",
            f"{a},{F},0,request,j1939_rx_msg_t*,The boot kernel's PGN 61184 request ({R})"]) + "\n"
        open(dp, "w").write(d)
    with open(map_path, "w") as fh:
        fh.write("address,name,old_label,kind,dims\n"
                 "0x004059f4,coolant_torque_adjustment_factor,net_combustion_torque_coolant_friction_scale,global,1\n"
                 "0x003fba10,coolant_torque_adjustment_term,net_combustion_torque_coolant_friction_term,global,1\n"
                 f"-,{P}ADDRESS_NOT_ACCEPTED,{P}UNMAPPED_ADDRESS,enum,1\n"
                 f"-,{P}ROM_HANDLER_REFUSED,{P}REGION_REFUSED,enum,1\n"
                 f"-,{P}FLASH_ERASE_FAILED,{P}EEPROM_TRANSFER_NOT_STARTED,enum,1\n")
    print("csv: enum 3 renamed + 3 added / 2 globals renamed / 0x19 handler prototype")
elif phase == "--docs":
    pr, hb = sys.argv[3], sys.argv[4]
    T = "work/tasks/046-cm848-egr-flow-estimate.md"
    edit(T, "  - **The 30 unprefixed names shared with CM550** are cross-firmware twins by design. Only a few are vague\n"
            "    (`emptyStubFunction2`-`4`, empty functions called from code - compiled-out hooks), and renaming them needs\n"
            "    their CM550 call sites read too.\n",
         "  - **The 30 unprefixed names shared with CM550:** rename in both firmwares or keep. A few are vague\n"
         "    (`emptyStubFunction2`-`4`: empty functions called from code, likely compiled-out hooks), and renaming them\n"
         "    needs their CM550 call sites read too.\n")
    edit(T, "  - `net_combustion_torque_coolant_friction_term` (was `DAT_003fba10`, round 62's lead), with its scale renamed\n"
            "    `net_combustion_torque_coolant_friction_scale`.\n- **Proof:**",
         "  - `net_combustion_torque_coolant_friction_term` (was `DAT_003fba10`, round 62's lead), with its scale renamed\n"
         "    `net_combustion_torque_coolant_friction_scale`.\n"
         f"- **Follow-up ({hb}), from the closing review, renamed from the boot kernel's own producers:**\n"
         "  - 0x09 is `ADDRESS_NOT_ACCEPTED` (was `UNMAPPED_ADDRESS`). The boot lookup also returns 9 for Bank 2 with\n"
         "    `flash2_writes_enabled` 0, and `cm848_trackDownloadBlock` for an out-of-sequence address or a block\n"
         "    overrun.\n"
         "  - 0x0a is `ROM_HANDLER_REFUSED` (was `REGION_REFUSED`). No boot region has type 10.\n"
         "  - 0x17 is `FLASH_ERASE_FAILED` (was `EEPROM_TRANSFER_NOT_STARTED`). `mpc555_initEepromTransfer` answers\n"
         "    0x17 when its flash erase fails.\n"
         "  - New: 0x10 `NO_DOWNLOAD_BLOCK`, 0x14 `CHECKSUM_MISMATCH` (`cm848_finishDownloadBlock`'s CRC compare - the\n"
         "    open 0x14 lead, for the boot kernel) and 0x15 `DOWNLOAD_BLOCK_LIST_FULL`.\n"
         "  - The torque words take their e2m name: `coolant_torque_adjustment_factor` (e2m 16A4 +1E\n"
         "    C_CBP_Coolant_Torque_Adj_Factor) and `coolant_torque_adjustment_term`.\n"
         "  - `cm848_handleBootExecuteAtAddressService` has its full prototype (`request`, the enum return).\n"
         "- **Proof:**")
    edit(T, "  - CM550's unreviewed members, the three length tables, and 0x14 / 0xfe with no CM848 producer.\n",
         "  - CM550's unreviewed members, the three length tables, and 0xfe with no CM848 producer.\n"
         "  - **Service 2's names:** `mpc555_initEepromTransfer` writes the EEPROM magic, erases the flash and resets the\n"
         "    download tracking. So `BOOT_DIAGNOSTIC_SERVICE_INITIALIZE_EEPROM_TRANSFER`, its handler and that function\n"
         "    may each be misnamed; read the reflash flow before renaming.\n")
    edit(pr, "  0x17), types the boot validator and dispatcher. The coolant friction torque term is named (round 62's lead).\n",
         "  0x17), types the boot validator and dispatcher. The coolant friction torque term is named (round 62's lead).\n"
         f"- **Follow-up ({hb}):** three boot result members renamed from the boot kernel's own producers, three\n"
         "  added (0x10 / 0x14 checksum mismatch / 0x15), and the torque words renamed from e2m.\n")
    print("docs")

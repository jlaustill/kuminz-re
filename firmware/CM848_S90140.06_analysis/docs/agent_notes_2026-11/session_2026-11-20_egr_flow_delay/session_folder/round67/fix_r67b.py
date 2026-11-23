"""Round 67 follow-up (the advisor's closing review). Idempotent: every edit skips when its new text is present.
CSV phase:
- mpc555_verifyDownloadedCalibration's plate: CALIBRATION_VALID also resets the ECU after the answer.
- mpc555_beginReflash's plate: the erase claim's evidence (mpc555_cmfEraseBlocks' interlock writes).
- cm848_finishDownloadBlock: its full prototype (trailing_crc / a byte status).
- eeprom_block_tracking_t.watchdog_counter -> key_off_duration_ticks: mpc555_tickTransferTimeoutAndRuntimeCounter
  counts it with the runtime counter / mpc555_keyOnStateMachine zeroes it while SCRD bit 15 (key on - PR #48) is set
  and saves the runtime counter once it passes 0x2903. Nothing resets it per block.
- eeprom_header_t.eeprom_status_flags' comment: the boot kernel's word is serial_reflash_status_flags_cal; the
  application's is e2m 8A36 +2 IAH_Redundant_Preheat_Req (intake air heater - the old note said IAT derate).
- local_variables.csv: a comment's stale write_auth_attempt_counter.
Docs phase: task 046 (the proof recount / more leads / the follow-up) / the PR body / proof_r67.txt / the engine
hours doc's keyon_duration_counter / apply_r67a.py's docstring.
usage: fix_r67b.py <repo> --csv <map.csv> | --docs <pr_body.md> <hash>"""
import os
import sys

repo, phase = os.path.abspath(sys.argv[1]), sys.argv[2]
O = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")
W = "/home/linux/.claude/jobs/374b0424/tmp/w15/r67"
R = "PR #53 round 67"


def edit(path, old, new):
    p = path if os.path.isabs(path) else os.path.join(repo, path)
    s = open(p).read()
    if new in s:
        return
    assert s.count(old) == 1, (path, old[:90], s.count(old))
    open(p, "w").write(s.replace(old, new))


if phase == "--csv":
    map_path = sys.argv[3]
    F = os.path.join(O, "function_renames.csv")
    edit(F, "CALIBRATION_VALID answers 0. CALIBRATION_DOWNLOADED_NOT_VERIFIED:",
         "CALIBRATION_VALID answers 0 and then resets the ECU (after waiting for the answer to go out). "
         "CALIBRATION_DOWNLOADED_NOT_VERIFIED:")
    edit(F, "erases the internal flash but block 0 (mpc555_cmfEraseBlocks(0x7ffc) - the boot block keeps the boot ROM)",
         "erases the internal flash but block 0 (mpc555_cmfEraseBlocks(0x7ffc): its interlock writes go to 0x8000-0x38000 "
         "and 0x40000-0x68000 - blocks 1-7 of module A and all 6 of module B - so the boot block keeps the boot ROM)")
    D = os.path.join(O, "function_definitions.csv")
    d = open(D).read()
    if "0x00007840,cm848_finishDownloadBlock," not in d:
        d = d.rstrip("\n") + "\n" + "\n".join([
            f"0x00007840,cm848_finishDownloadBlock,return,,byte,0xff when the block is recorded / 0x14 CRC mismatch / "
            f"0x15 download_block_list full ({R})",
            f"0x00007840,cm848_finishDownloadBlock,0,trailing_crc,word*,The block's 2-byte CRC that follows its data "
            f"({R})"]) + "\n"
        open(D, "w").write(d)
    T = os.path.join(O, "structure_definitions.csv")
    edit(T, "eeprom_block_tracking_t,0x003028a6,watchdog_counter,word,2,Transfer watchdog counter (reset each block),,"
            "verified",
         "eeprom_block_tracking_t,0x003028a6,key_off_duration_ticks,word,2,Counted with the runtime counter by "
         "mpc555_tickTransferTimeoutAndRuntimeCounter (every 41 calls) - mpc555_keyOnStateMachine zeroes it while "
         "SCRD bit 15 (key on - PR #48) is set and saves the runtime counter once it passes 0x2903 (was "
         f"watchdog_counter 'Transfer watchdog counter (reset each block)'; {R}),,verified")
    edit(T, "# watchdog_counter: incremented per tick to detect transfer stalls",
         "# key_off_duration_ticks: ticks since the key was last on; the runtime counter is saved past 0x2903")
    lines = open(T).read().split("\n")
    idx = [i for i, l in enumerate(lines) if l.startswith("eeprom_header_t,0x003fee08,eeprom_status_flags,")]
    assert len(idx) == 1
    new = ("eeprom_header_t,0x003fee08,eeprom_status_flags,word,2,Boot kernel: EEPROM 0x50 "
           "(serial_reflash_status_flags_cal) - bit 3 set and bit 1 cleared by a verified serial download | "
           "application side (time-shared - the EEPROM mirror): e2m 8A36 +2 IAH_Redundant_Preheat_Req (the intake air "
           f"heater - the old note said IAT derate history; {R}),,verified")
    if lines[idx[0]] != new:
        assert "Bit0=IAT derate history" in lines[idx[0]], lines[idx[0]]
        lines[idx[0]] = new
        open(T, "w").write("\n".join(lines))
    edit(os.path.join(O, "local_variables.csv"), "Current value of write_auth_attempt_",
         "Current value of eeprom_block_tracking.failed_write_authorization_count (was write_auth_attempt_")
    with open(map_path, "w") as fh:
        fh.write("address,name,old_label,kind,dims\n"
                 "0x003028a6,eeprom_block_tracking.key_off_duration_ticks,eeprom_block_tracking.watchdog_counter,"
                 "global,1\n")
    print("csv done")
elif phase == "--docs":
    pr, hb = sys.argv[3], sys.argv[4]
    OLD = ("21 predicted (the 10 retyped reflash functions; the CRC table builder and reader; the block finish and the "
           "serial transfer block that fill download_block_list; the J1939 write worker and the serial data handler, "
           "which pass the channel; the erase dispatcher loop and its local; the five boot readers of ECM_STATUS; the "
           "serial begin, whose EEPROM casts went)")
    NEW = ("21 predicted (the 7 functions with new prototypes; the CRC table builder and reader; the block finish and "
           "the serial transfer block that fill download_block_list; the J1939 write worker and the serial data "
           "handler, which pass the channel; the erase dispatcher loop and its local; the six boot readers of "
           "ECM_STATUS, the serial finish among them; the serial begin, whose EEPROM casts went - the three renamed "
           "functions without a new prototype do not differ)")
    for p in (pr, os.path.join(W, "proof_r67.txt"), "work/tasks/046-cm848-egr-flow-estimate.md"):
        edit(p, OLD, NEW)
    T46 = "work/tasks/046-cm848-egr-flow-estimate.md"
    edit(T46, "    gates the ROM handlers), `eeprom_write_request_type` (a serial request byte that other handlers read as a\n"
              "    word) and `mpc555_processDiagnosticAndEepromRequests`.\n",
         "    gates the ROM handlers), `eeprom_write_request_type` (a serial request byte that other handlers read as a\n"
         "    word) and `mpc555_processDiagnosticAndEepromRequests`.\n"
         "  - **0x3fedee / 0x3fedf4 are time-shared too:** three transmission functions read e2m RE_Two_Three_Lag (the\n"
         "    learned 2-3 shift lag per temperature range) as `*(word *)(&serial_reflash_busy_flag + range * 2)` (it was\n"
         "    `&eeprom_calibration_pending_flag + ...`).\n"
         "  - **`DAT_01000000`** is EEPROM word 0, ECM_Status, in the boot kernel, but the EEPROM's lower bound in two\n"
         "    application range checks; one name would mislead one side.\n"
         "  - **`mpc555_beginReflash`'s `result_code` local** (0x17 / 0) stays `dword`: typing it needs its pre-stage\n"
         "    key.\n")
    edit(T46, "- **firmware/CLAUDE.md:** no edit.\n- **Leads:**\n  - **The time-shared header fields at 0x3fee18-0x3fee22.**",
         f"- **Follow-up ({hb}), from the closing review:**\n"
         "  - The proof breakdown above is recounted. The first version said \"the 10 retyped reflash functions\": 7 of\n"
         "    the 10 renamed functions got prototypes, and the other 3 are pure renames that do not differ.\n"
         "  - The verifier's plate says that CALIBRATION_VALID also resets the ECU, and the begin plate gives the\n"
         "    erase's evidence: `mpc555_cmfEraseBlocks`' interlock writes go to 0x8000-0x38000 and\n"
         "    0x40000-0x68000, so block 0 is left alone. The region table (ROM 0x3c60) puts EEPROM\n"
         "    0x1000000-0x1003fff in region type 5, so the write services can reach ECM_Status.\n"
         "  - `cm848_finishDownloadBlock` has its full prototype (`trailing_crc`, a byte status).\n"
         "  - `eeprom_block_tracking_t.watchdog_counter` is `key_off_duration_ticks`. The tick counts it with the\n"
         "    runtime counter; the key-on state machine zeroes it while SCRD bit 15 (key on, PR #48) is set and saves\n"
         "    the runtime counter once it passes 0x2903. Nothing resets it per block. The engine hours doc called it\n"
         "    `keyon_duration_counter`.\n"
         "  - `eeprom_header_t.eeprom_status_flags`' note said \"IAT derate history\". The application's word there is\n"
         "    e2m 8A36 +2 IAH_Redundant_Preheat_Req (the intake air heater); the boot kernel's is the serial reflash\n"
         "    flags.\n"
         "- **firmware/CLAUDE.md:** no edit.\n- **Leads:**\n  - **The time-shared header fields at 0x3fee18-0x3fee22.**")
    E = "firmware/CM848_S90140.06_analysis/docs/engine_hours_and_odometer.md"
    edit(E, "- `keyon_duration_counter` @ 0x003028a6 (session counter)",
         "- `eeprom_block_tracking.key_off_duration_ticks` @ 0x003028a6 (was `keyon_duration_counter`, then\n"
         "  `watchdog_counter`; PR #53 round 67: `mpc555_keyOnStateMachine` zeroes it while the key is on, so it\n"
         "  counts key-off time)")
    edit(E, "1. **Periodic save:** `keyon_duration_counter > 0x2903` (10,499 ticks)",
         "1. **Periodic save:** `key_off_duration_ticks > 0x2903` (10,499 ticks)")
    edit(E, "Purpose: Verify the 0x2903 (10,499) threshold on `keyon_duration_counter`.",
         "Purpose: Verify the 0x2903 (10,499) threshold on `key_off_duration_ticks` (was `keyon_duration_counter`).")
    edit(pr, "  `download_block_list` and `crc_ccitt_table` are typed, and `eeprom_param_t` / a duplicate enum are removed.\n",
         "  `download_block_list` and `crc_ccitt_table` are typed, and `eeprom_param_t` / a duplicate enum are removed.\n"
         f"- **Follow-up ({hb}):** the proof breakdown recounted; the verifier / begin plates; `cm848_finishDownloadBlock`'s\n"
         "  prototype; `key_off_duration_ticks` (was `watchdog_counter`); the header field's intake air heater note.\n")
    A = os.path.join(W, "apply_r67a.py")
    edit(A, "\"\"\"Round 67 stage A: the boot kernel's reflash state machine. Idempotent: each change keys on a row's "
            "address / enum\nvalue / prefix and skips when the new text is already there.\n",
         "\"\"\"Round 67 stage A: the boot kernel's reflash state machine. Each change keys on a row's address / enum "
         "value /\nprefix and skips when the new text is already there, so it can run twice. Run it once, then "
         "fix_r67a2.py: replayed\nafter fix_r67a2.py it re-adds the two retypes that fix_r67a2.py drops and then stops "
         "on the local row's assert.\n")
    print("docs done")

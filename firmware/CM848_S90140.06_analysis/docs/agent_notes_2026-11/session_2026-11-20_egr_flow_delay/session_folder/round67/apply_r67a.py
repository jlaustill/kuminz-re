"""Round 67 stage A: the boot kernel's reflash state machine. Idempotent: each change keys on a row's address / enum
value / prefix and skips when the new text is already there.

- ECM_STATUS (was EEPROM_MAGIC, applied nowhere): e2m 000B +0 ECM_Status = EEPROM word 0, typed on eeprom_header_t's
  field (was magic). 0x600d CALIBRATION_VALID / 0x1d0a REFLASH_IN_PROGRESS / 0x2b16 CALIBRATION_DOWNLOADED_NOT_VERIFIED.
- The reflash functions renamed from their bodies (none has a CM550 twin) with full prototypes, and a
  BOOT_REQUEST_CHANNEL enum (2 J1939 / 3 serial) on the five functions that carry the channel.
- cm848_sendDiagServiceResponse's result typed BOOT_DIAGNOSTIC_RESULT; 0xfe RESPONSE_PENDING added; 0x15 renamed
  DOWNLOAD_INVALID (the verifier also sends it); the 0x14 comment names CM550's J1939_DIAGNOSTIC_RESULT.
- The serial flags / the EEPROM 0x50-0x54 words / the saved service 2 request / the CRC-CCITT table / the download
  block list; four stale flat rows inside eeprom_block_tracking; eeprom_param_t (its only instance) removed.
usage: apply_r67a.py <repo> <map.csv>"""
import os
import sys

repo, map_path = os.path.abspath(sys.argv[1]), sys.argv[2]
O = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")
R = "PR #53 round 67"


def load(name):
    return open(os.path.join(O, name)).read().split("\n")


def save(name, lines):
    open(os.path.join(O, name), "w").write("\n".join(lines))


def one(lines, pred, what):
    idx = [i for i, l in enumerate(lines) if pred(l)]
    assert len(idx) == 1, (what, len(idx))
    return idx[0]


def replace_row(name, pred, new, what):
    lines = load(name)
    if new in lines:
        return
    lines[one(lines, pred, what)] = new
    save(name, lines)


def insert_after(name, anchor_pred, new_lines, what):
    lines = load(name)
    if new_lines[0] in lines:
        return
    i = one(lines, anchor_pred, what)
    lines[i + 1:i + 1] = new_lines
    save(name, lines)


# ---- enums.csv -------------------------------------------------------------------------------------------------------
E = "enums.csv"
ES = "ECM_STATUS"
ecm_rows = [
    f"# {ES} - e2m 000B +0 ECM_Status (EEPROM word 0) 'Indicator as to the calibration status of the ECM': the boot ROM's "
    f"reflash state on eeprom_header_t.ecm_status (was EEPROM_MAGIC - applied nowhere; {R})",
    f"{ES},0x600d,{ES}_CALIBRATION_VALID,The downloaded calibration was verified: with the boot mode strap pins low "
    "mpc555_hardwareInitialization jumps to flash_operational_code_entry_pointer - written by "
    "mpc555_verifyDownloadedCalibration (was VALID_MARKER),2",
    f"{ES},0x1d0a,{ES}_REFLASH_IN_PROGRESS,Written by cm848_sciCommand49Callback (the application's serial reflash request "
    "- its image still intact) and by mpc555_beginReflash before the erase: keeps the boot kernel resident "
    "(mpc555_systemInitialization runs cm848_runBootKernelLoop) and mpc555_sciHandleDownloadStart requires it "
    "(was FLASH_MODE_MARKER),2",
    f"{ES},0x2b16,{ES}_CALIBRATION_DOWNLOADED_NOT_VERIFIED,Written by cm848_finishSerialReflash after a serial download "
    "(no J1939 writer found in the firmware - the write memory services can reach EEPROM 0x0): "
    "mpc555_verifyDownloadedCalibration checks the image then writes CALIBRATION_VALID (was NEEDS_PROGRAMMING),2",
]
lines = load(E)
if ecm_rows[1] not in lines:
    i = one(lines, lambda l: l == "# EEPROM Magic Values", "magic header")
    assert lines[i + 1].startswith("EEPROM_MAGIC,0x600d,") and lines[i + 3].startswith("EEPROM_MAGIC,0x1d0a,")
    lines[i:i + 4] = ecm_rows
    save(E, lines)
P = "BOOT_DIAGNOSTIC_RESULT"
replace_row(E, lambda l: l.startswith(f"{P},0x14,"),
            f"{P},0x14,{P}_CHECKSUM_MISMATCH,cm848_finishDownloadBlock: the block's trailing CRC differs from the running "
            "CRC (the name CM550's J1939_DIAGNOSTIC_RESULT gives 0x14 - c48cc435 said DIAG_RESPONSE_CODE),4", "0x14")
replace_row(E, lambda l: l.startswith(f"{P},0x15,"),
            f"{P},0x15,{P}_DOWNLOAD_INVALID,The download does not form a valid calibration: cm848_finishDownloadBlock finds "
            "download_block_list full - or mpc555_verifyDownloadedCalibration (service 7) finds a region sum or the block "
            "layout unlike the image header at ROM 0x8104 or ECM_Status neither CALIBRATION_VALID nor "
            "CALIBRATION_DOWNLOADED_NOT_VERIFIED (c48cc435 named it DOWNLOAD_BLOCK_LIST_FULL),4", "0x15")
insert_after(E, lambda l: l.startswith(f"{P},0x1a,"),
             [f"{P},0xfe,{P}_RESPONSE_PENDING,cm848_sendDiagResponsePending: cm848_sendDiagServiceResponse answers it with "
              "service 0x0e and the wait time - the real result follows later (round 66 said 0xfe had no producer),4",
              "# BOOT_REQUEST_CHANNEL - which link a boot kernel reflash request came over: the channel argument of "
              "mpc555_beginReflash / mpc555_verifyDownloadedCalibration / cm848_sendBootResultToJ1939Requester / "
              f"cm848_trackDownloadBlock / cm848_updateDownloadCrc ({R}). The code also tests 1 - no caller passes it",
              "BOOT_REQUEST_CHANNEL,0x02,BOOT_REQUEST_CHANNEL_J1939,The PGN 61184 services: only this channel gets "
              "cm848_sendBootResultToJ1939Requester's answer / the CAN transmit runs while the verifier waits / a "
              "finished block's CRC is checked,4",
              "BOOT_REQUEST_CHANNEL,0x03,BOOT_REQUEST_CHANNEL_SERIAL,The serial reflash services: "
              "mpc555_runPacedSerialService runs while waiting / the verifier counts and flags the reflash in EEPROM / "
              "cm848_updateDownloadCrc never finishes a block,4"], "0x1a")
lines = load(E)
i = one(lines, lambda l: l.startswith(f"# {P} - the result code of a boot kernel"), "result header")
lines[i] = lines[i].replace("the boot kernel's own 5 / 0x0a / 0x10 / 0x11 / 0x14 / 0x15 / 0x17.",
                            "the boot kernel's own 5 / 0x0a / 0x10 / 0x11 / 0x14 / 0x15 / 0x17 / 0xfe.")
save(E, lines)
lines = load(E)
if any(l.startswith("DIAGNOSTIC_SERVICE,") for l in lines):  # the stale duplicate of BOOT_DIAGNOSTIC_SERVICE
    i = one(lines, lambda l: l.startswith("# Reflash-kernel diagnostic service IDs - registered in "), "old header")
    assert all(lines[i + 1 + k].startswith("DIAGNOSTIC_SERVICE,") for k in range(14)) and lines[i + 15] == ""
    del lines[i:i + 16]
    assert not any(l.startswith("DIAGNOSTIC_SERVICE,") for l in lines)
    save(E, lines)
S = "BOOT_DIAGNOSTIC_SERVICE"
replace_row(E, lambda l: l.startswith(f"{S},0x02,"),
            f"{S},0x02,{S}_BEGIN_REFLASH,cm848_handleBootBeginReflashService: response pending 0x96 then "
            "mpc555_beginReflash(J1939) - ECM_Status REFLASH_IN_PROGRESS / the erase / the download tracking reset "
            "(was INITIALIZE_EEPROM_TRANSFER),1", "service 2")
replace_row(E, lambda l: l.startswith(f"{S},0x07,"),
            f"{S},0x07,{S}_VERIFY_DOWNLOADED_CALIBRATION,cm848_handleBootVerifyDownloadedCalibrationService: "
            "mpc555_verifyDownloadedCalibration(request / J1939) (was DOWNLOAD_CALIBRATION),1", "service 7")

# ---- function_renames.csv ----------------------------------------------------------------------------------------------
F = "function_renames.csv"
FUNCS = [  # address, old, new, new plate (the old plate, if any, is kept as "earlier note")
    ("0x000003ec", "cm848_eepromProgressNotify", "cm848_sendBootResultToJ1939Requester",
     "Boot kernel: sends a reflash result with cm848_sendDiagServiceResponse only when the channel is "
     "BOOT_REQUEST_CHANNEL_J1939 - the serial channel answers through its own session state"),
    ("0x00000428", "mpc555_loadEepromCalibration", "mpc555_verifyDownloadedCalibration",
     "Boot kernel (service 7 and cm848_finishSerialReflash): reads ECM_Status (EEPROM 0x0). CALIBRATION_VALID answers 0. "
     "CALIBRATION_DOWNLOADED_NOT_VERIFIED: sums each region of the image header's checksum table (pointer at ROM "
     "0x8104 - a count then 10-byte sum / start / end records) and checks download_block_list against the header's "
     "expected block count and addresses (0x8116 onward) - a mismatch answers DOWNLOAD_INVALID (the serial channel "
     "then resets); a match writes CALIBRATION_VALID (the serial channel also sets bit 3 and clears bit 1 of "
     "serial_reflash_status_flags_cal and counts serial_reflash_success_count_cal) / the runtime counter to "
     "eeprom_config_block / answers 0 / resets when MIOS MDASM30 SCRD bit 15 is set. Any other status answers "
     "DOWNLOAD_INVALID. Clears bit 7 of eeprom_service_mode_flags first"),
    ("0x000008d4", "cm848_handleBootDownloadCalibrationService", "cm848_handleBootVerifyDownloadedCalibrationService",
     "Boot kernel service 7: mpc555_verifyDownloadedCalibration(request / J1939) answers the request itself - then "
     "returns 0xff (the dispatcher sends no response)"),
    ("0x000008fc", "mpc555_initEepromTransfer", "mpc555_beginReflash",
     "Boot kernel (service 2 and the serial erase request): writes ECM_Status REFLASH_IN_PROGRESS unless it already is "
     "/ erases the internal flash but block 0 (mpc555_cmfEraseBlocks(0x7ffc) - the boot block keeps the boot ROM) and "
     "then the Bank 2 chip (cm848_flashEraseChip) / answers begin_reflash_request with 0 or FLASH_ERASE_FAILED unless "
     "the channel is 1 / resets the download tracking / sets bit 7 of eeprom_service_mode_flags; returns nonzero when "
     "both erases succeeded"),
    ("0x000009e4", "cm848_handleBootInitializeEepromTransferService", "cm848_handleBootBeginReflashService",
     "Boot kernel service 2: sends response pending 0x96 / keeps the request in begin_reflash_request / "
     "mpc555_beginReflash(J1939) answers it - returns FLASH_ERASE_FAILED when an erase failed else 0xff"),
    ("0x000036f8", "cm848_resetEepromCalibrationState", "cm848_resetSerialReflashState",
     "Boot kernel: clears serial_reflash_busy_flag and diag_session_state_byte"),
    ("0x00003710", "cm848_beginEepromCalibrationWrite", "cm848_beginSerialReflash",
     "Boot kernel serial reflash request type 1: sets serial_reflash_busy_flag / sends response pending (0x78 / 0x74) "
     "/ waits out the serial transmit / clears bits 1 and 3 of serial_reflash_status_flags_cal / counts "
     "serial_reflash_attempt_count_cal / sets serial_reflash_erase_pending_flag - "
     "mpc555_processDiagnosticAndEepromRequests then runs mpc555_beginReflash(serial)"),
    ("0x000037e0", "cm848_updateEepromMagicAndReload", "cm848_finishSerialReflash",
     "Boot kernel serial reflash request type 2: when ECM_Status is REFLASH_IN_PROGRESS sets serial_reflash_busy_flag "
     "/ sends response pending (0x78 / 0x74) / waits out the serial transmit / writes "
     "CALIBRATION_DOWNLOADED_NOT_VERIFIED to EEPROM 0x0 and polls until it reads back (400 polls at least) / then "
     "mpc555_verifyDownloadedCalibration(serial); otherwise answers 0x40 / 0x7f"),
    ("0x000038f4", "cm848_dispatchEepromWriteRequest", "cm848_dispatchSerialReflashRequest",
     "Boot kernel: cm848_resetSerialReflashState then request type 1 (cm848_beginSerialReflash) or 2 "
     "(cm848_finishSerialReflash); any other type answers 0x12 / 0x7f. Readability Medium now: "
     "eeprom_write_request_type names a serial request byte that other handlers read as a word"),
    ("0x0000037c", "cm848_registerBootCalibrationAndNoOperationServices",
     "cm848_registerBootReflashAndNoOperationServices", None),
]
lines = load(F)
for addr, old, new, plate in FUNCS:
    i = one(lines, lambda l, a=addr: l.startswith(a + ","), addr)
    parts = lines[i].split(",", 2)
    if parts[1] == new:
        continue
    assert parts[1] == old, (addr, parts[1])
    old_plate = parts[2] if len(parts) > 2 else ""
    if plate is None:
        text = f"{old_plate} (was {old}; {R})"
    else:
        text = f"{plate} (was {old}; {R})" + (f" | earlier note: {old_plate}" if old_plate else "")
    lines[i] = f"{addr},{new},{text}"
save(F, lines)

# ---- global_variables.csv ----------------------------------------------------------------------------------------------
G = "global_variables.csv"


def rename_global(addr, old, new, typ, text):
    lines = load(G)
    i = one(lines, lambda l: l.startswith(addr + ","), addr)
    parts = lines[i].split(",", 3)
    if parts[1] == new:
        return
    assert parts[1] == old, (addr, parts[1])
    rest = parts[3] if len(parts) > 3 else ""
    lines[i] = f"{addr},{new},{typ if typ is not None else parts[2]},{text}{rest}"
    save(G, lines)


rename_global("0x003fedee", "eeprom_calibration_pending_flag", "serial_reflash_busy_flag", None,
              "Boot kernel: set by cm848_beginSerialReflash and cm848_finishSerialReflash - the serial transfer block "
              "and download services answer response pending while it is set - cleared after the erase "
              "(mpc555_processDiagnosticAndEepromRequests) / the verify / cm848_resetSerialReflashState (was "
              f"eeprom_calibration_pending_flag; {R})")
rename_global("0x003fedf4", "eeprom_write_pending_flag", "serial_reflash_erase_pending_flag", None,
              "Boot kernel: cm848_beginSerialReflash sets it to 1 - mpc555_processDiagnosticAndEepromRequests then runs "
              f"mpc555_beginReflash(serial) and clears it (was eeprom_write_pending_flag; {R})")
rename_global("0x003fee0a", "eeprom_shadow_header.magic", "eeprom_shadow_header.ecm_status", None,
              f"(was eeprom_shadow_header.magic; {R})")
rename_global("0x01000050", "eeprom_cal_word1", "serial_reflash_status_flags_cal", "word",
              "EEPROM 0x50: the boot kernel's serial reflash flags - cm848_beginSerialReflash clears bits 1 and 3 and a "
              "verified serial download sets bit 3 and clears bit 1 (mpc555_verifyDownloadedCalibration) - read into the "
              f"boot shadow 0x3fee1e by cm848_loadCalibrationFromEeprom (was eeprom_cal_word1; {R})")
rename_global("0x01000052", "eeprom_cal_word2", "serial_reflash_success_count_cal", "word",
              "EEPROM 0x52: counted by mpc555_verifyDownloadedCalibration after each verified serial download - read "
              f"into the boot shadow 0x3fee20 (was eeprom_cal_word2; {R})")
rename_global("0x01000054", "eeprom_cal_word3", "serial_reflash_attempt_count_cal", "word",
              "EEPROM 0x54: counted by cm848_beginSerialReflash at each serial reflash start - read into the boot shadow "
              f"0x3fee22 (was eeprom_cal_word3; {R})")
rename_global("0x0030252a", "eeprom_diag_callback", "begin_reflash_request", "j1939_rx_msg_t *",
              "Boot kernel: the service 2 request that cm848_handleBootBeginReflashService keeps for mpc555_beginReflash's "
              f"answer (was eeprom_diag_callback typed eeprom_param_t - its bytes 6 on are crc_ccitt_table; {R})")
rename_global("0x00302530", "eeprom_diag_callback.default_value", "crc_ccitt_table", "word[256]",
              "The reflected CRC-CCITT table (polynomial 0x8408) built by cm848_generateCrcTable - read by "
              "cm848_computeCrcCcitt and cm848_updateDownloadCrc; it ends at 0x30272f (was "
              f"eeprom_diag_callback.default_value; {R})")
lines = load(G)
if "0x00302532,can_tx_status.callback_param,," in lines:
    lines.remove("0x00302532,can_tx_status.callback_param,,")
    save(G, lines)
STALE = [("0x003028a8", "write_auth_attempt_counter", "failed_write_authorization_count"),
         ("0x003028a9", "keyon_duration_counter.last_write_addr", "last_write_addr"),
         ("0x003028ad", "qadc_a_result_ch28", "block_start_addr"),
         ("0x003028b1", "qadc_a_result_ch30", "block_count")]
for addr, old, field in STALE:
    rename_global(addr, old, f"eeprom_block_tracking.{field}", "",
                  f"(was {old}: a stale flat row inside the struct; {R})")
insert_after(G, lambda l: l.startswith("0x003028b1,"),
             ["0x003028b3,download_block_list,download_block_range_t[10],Boot kernel: the start and last data address of "
              "each finished download block - filled by cm848_finishDownloadBlock (DOWNLOAD_INVALID when all 10 are "
              "used) and checked against the image header by mpc555_verifyDownloadedCalibration; ends at 0x302902 (was "
              f"DAT_003028b3 / DAT_003028b7; {R})"], "0x3028b1")

# ---- structure_definitions.csv -----------------------------------------------------------------------------------------
T = "structure_definitions.csv"
replace_row(T, lambda l: l.startswith("eeprom_header_t,0x003fee08,magic,") or
            l.startswith("eeprom_header_t,0x003fee08,ecm_status,"),
            "eeprom_header_t,0x003fee08,ecm_status,ECM_STATUS,2,e2m 000B +0 ECM_Status (EEPROM 0x0) - the calibration "
            f"status the boot ROM reads before it jumps to the operational code (was magic; {R}),,verified", "magic")
replace_row(T, lambda l: l.startswith("eeprom_block_tracking_t,0x003028a6,block_count,"),
            "eeprom_block_tracking_t,0x003028a6,block_count,word,2,Finished download blocks in download_block_list (10 "
            f"at most - cm848_finishDownloadBlock answers DOWNLOAD_INVALID when it is full; {R}),,verified", "block_count")
replace_row(T, lambda l: l.startswith("# block_count: number of completed transfer blocks recorded"),
            "# block_count: finished download blocks recorded in download_block_list @ 0x3028b3 (10 at most)",
            "block_count comment")
insert_after(T, lambda l: l.startswith("eeprom_block_tracking_t,0x003028a6,block_count,"),
             [f"# download_block_range_t - one entry of download_block_list @ 0x3028b3 ({R})",
              "download_block_range_t,,start_address,dword,4,The block's first address "
              "(eeprom_block_tracking.block_start_addr),,verified",
              "download_block_range_t,,end_address,dword,4,The block's last data byte: start + block length - 3 (before "
              "its 2-byte CRC),,verified"], "block_count row")
lines = load(T)
if any(l.startswith("eeprom_param_t,") for l in lines):
    i = one(lines, lambda l: l == "# EEPROM Parameter Structure - customer-configurable parameter format", "param hdr")
    assert all(lines[i + 2 + k].startswith("eeprom_param_t,,") for k in range(4)) and lines[i + 6] == ""
    del lines[i:i + 7]
    j = one(lines, lambda l: l.startswith("# EEPROM diagnostic service callback parameter @ 0x30252a"), "instance hdr")
    assert lines[j - 1].startswith("# ====") and lines[j + 2].startswith("# ====")
    assert lines[j + 3].startswith("eeprom_param_t,0x0030252a,")
    del lines[j - 1:j + 4]
    assert not any(l.startswith("eeprom_param_t,") for l in lines)
    save(T, lines)

# ---- function_definitions.csv ------------------------------------------------------------------------------------------
D = "function_definitions.csv"
lines = load(D)
i = one(lines, lambda l: l.startswith("0x000074a0,cm848_sendDiagServiceResponse,1,result_code,"), "sender param 1")
lines[i] = lines[i].replace(",result_code,dword,", ",result_code,BOOT_DIAGNOSTIC_RESULT,")
i = one(lines, lambda l: l.startswith("0x000038f4,cm848_dispatchSerialReflashRequest,return,") or
        l.startswith("0x000038f4,cm848_dispatchEepromWriteRequest,return,"), "dispatcher return")
lines[i] = lines[i].replace("Dispatches EEPROM write by request type - takes no params (reads global directly)",
                            "Dispatches a serial reflash request by eeprom_write_request_type - takes no params "
                            f"(was 'Dispatches EEPROM write by request type'; {R})")
CH = "BOOT_REQUEST_CHANNEL"
NEW = [
    ("0x000003ec", "cm848_sendBootResultToJ1939Requester", [
        ("return", "", "void", "Nothing"),
        ("0", "request", "j1939_rx_msg_t*", "The PGN 61184 request to answer"),
        ("1", "channel", CH, "Only BOOT_REQUEST_CHANNEL_J1939 is answered"),
        ("2", "result", "BOOT_DIAGNOSTIC_RESULT", "The result to send")]),
    ("0x00000428", "mpc555_verifyDownloadedCalibration", [
        ("return", "", "void", "Nothing - it answers the request itself"),
        ("0", "request", "j1939_rx_msg_t*", "The service 7 request (0 from cm848_finishSerialReflash)"),
        ("1", "channel", CH, "J1939 from service 7 / serial from cm848_finishSerialReflash")]),
    ("0x000008d4", "cm848_handleBootVerifyDownloadedCalibrationService", [
        ("return", "", "BOOT_DIAGNOSTIC_RESULT", "0xff: the verifier answered already"),
        ("0", "request", "j1939_rx_msg_t*", "The boot kernel's PGN 61184 request")]),
    ("0x000008fc", "mpc555_beginReflash", [
        ("return", "", "short", "Nonzero when both erases succeeded"),
        ("0", "channel", CH, "J1939 from service 2 / serial from mpc555_processDiagnosticAndEepromRequests")]),
    ("0x000009e4", "cm848_handleBootBeginReflashService", [
        ("return", "", "BOOT_DIAGNOSTIC_RESULT", "FLASH_ERASE_FAILED when an erase failed else 0xff"),
        ("0", "request", "j1939_rx_msg_t*", "The boot kernel's PGN 61184 request")]),
    ("0x00005400", "cm848_writeBootDiagnosticMemory", [
        ("return", "", "BOOT_DIAGNOSTIC_RESULT",
         "The write result - including cm848_trackDownloadBlock's status whenever it is not 0xff (the asm returns it "
         "at 0x5710)")]),
    ("0x00007740", "cm848_trackDownloadBlock", [
        ("return", "", "byte", "0xff to go on / 9 out of sequence or past the block / 0x10 no block / or "
                               "cm848_updateDownloadCrc's status"),
        ("0", "data", "byte*", "The bytes being written"),
        ("1", "address", "dword", "Their first address"),
        ("2", "length", "ushort*", "Their length - 2 less (the trailing CRC) when they end the block"),
        ("3", "channel", CH, "The serial channel adds the bytes but never ends a block")]),
    ("0x000078d0", "cm848_updateDownloadCrc", [
        ("return", "", "byte", "0xff to go on - or cm848_finishDownloadBlock's status once a J1939 block ends"),
        ("0", "data", "byte*", "The bytes to add to ecu_power_state_flags.transfer_crc"),
        ("1", "length", "uint", "How many"),
        ("2", "channel", CH, "Only a J1939 block is finished here")]),
]
tail = [""] if lines and lines[-1] == "" else []
body = lines[:-1] if tail else lines
for addr, func, rows in NEW:
    for index, name, typ, comment in rows:
        key = f"{addr},{func},{index},"
        if any(l.startswith(key) for l in body):
            continue
        body.append(f"{key}{name},{typ},{comment} ({R})")
save(D, body + tail)

# ---- local_variables.csv -----------------------------------------------------------------------------------------------
L = "local_variables.csv"
replace_row(L, lambda l: l.startswith("0x00001fa4,mpc555_processDiagnosticAndEepromRequests,sVar1,"),
            "0x00001fa4,mpc555_processDiagnosticAndEepromRequests,sVar1,erase_result,short,mpc555_beginReflash(serial)'s "
            f"result - nonzero when both erases succeeded (0x73 into diag_session_state_byte; 0 gives 0x22) (was "
            f"eeprom_init_result whose note said 0=success; {R})", "local")

with open(map_path, "w") as fh:
    fh.write("address,name,old_label,kind,dims\n")
    for addr, old, new, _ in FUNCS:
        fh.write(f"{addr},{new},{old},function,1\n")
    for addr, old, new in [("0x003fedee", "eeprom_calibration_pending_flag", "serial_reflash_busy_flag"),
                           ("0x003fedf4", "eeprom_write_pending_flag", "serial_reflash_erase_pending_flag"),
                           ("0x003fee0a", "eeprom_shadow_header.magic", "eeprom_shadow_header.ecm_status"),
                           ("0x01000050", "eeprom_cal_word1", "serial_reflash_status_flags_cal"),
                           ("0x01000052", "eeprom_cal_word2", "serial_reflash_success_count_cal"),
                           ("0x01000054", "eeprom_cal_word3", "serial_reflash_attempt_count_cal"),
                           ("0x00302530", "eeprom_diag_callback.default_value", "crc_ccitt_table"),
                           ("0x0030252a", "eeprom_diag_callback", "begin_reflash_request")]:
        fh.write(f"{addr},{new},{old},global,1\n")
    for old, new in [("EEPROM_MAGIC", ES), ("VALID_MARKER", f"{ES}_CALIBRATION_VALID"),
                     ("FLASH_MODE_MARKER", f"{ES}_REFLASH_IN_PROGRESS"),
                     ("NEEDS_PROGRAMMING", f"{ES}_CALIBRATION_DOWNLOADED_NOT_VERIFIED"),
                     (f"{P}_DOWNLOAD_BLOCK_LIST_FULL", f"{P}_DOWNLOAD_INVALID"),
                     (f"{S}_INITIALIZE_EEPROM_TRANSFER", f"{S}_BEGIN_REFLASH"),
                     (f"{S}_DOWNLOAD_CALIBRATION", f"{S}_VERIFY_DOWNLOADED_CALIBRATION")]:
        fh.write(f"-,{new},{old},enum,1\n")
print("round 67 stage A applied")

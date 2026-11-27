"""Round 67 stage A, second pass (from the first build's render). Idempotent.
- cm848_sendDiagServiceResponse's result back to dword: typed, its body's reuse of the variable rendered 0x0c (the
  positive response service) as BOOT_DIAGNOSTIC_RESULT_UNKNOWN_PARAMETER_ID|BOOT_DIAGNOSTIC_RESULT_CANNOT_COMPLY.
- cm848_writeBootDiagnosticMemory's return row removed: the returned variable also carries the region type, so
  region 3 / 4 / 5 rendered as KEY_REFUSED / CANNOT_COMPLY / UNKNOWN_SERVICE.
- The erase_result local keys on wVar1: the callee's prototype types it word at the local stage (sVar1 and then
  wVar2 - the final numbering after diag_response_code's rename - were both skipped).
- download_block_list is filled by both paths: J1939 blocks end at start + length - 3 (before the 2-byte CRC) in
  cm848_finishDownloadBlock / serial blocks at start + length - 1 in mpc555_diagServiceTransferBlock (0x75 when full).
usage: fix_r67a2.py <repo>"""
import os
import sys

repo = os.path.abspath(sys.argv[1])
O = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")
R = "PR #53 round 67"


def edit(name, old, new):
    p = os.path.join(O, name)
    s = open(p).read()
    if new in s:
        return
    assert s.count(old) == 1, (name, old[:90], s.count(old))
    open(p, "w").write(s.replace(old, new))


D = "function_definitions.csv"
edit(D, "0x000074a0,cm848_sendDiagServiceResponse,1,result_code,BOOT_DIAGNOSTIC_RESULT,",
     "0x000074a0,cm848_sendDiagServiceResponse,1,result_code,dword,")
p = os.path.join(O, D)
lines = open(p).read().split("\n")
keep = [l for l in lines if not l.startswith("0x00005400,cm848_writeBootDiagnosticMemory,return,")]
if len(keep) != len(lines):
    assert len(lines) - len(keep) == 1
    open(p, "w").write("\n".join(keep))
edit(D, "0x00007740,cm848_trackDownloadBlock,3,channel,BOOT_REQUEST_CHANNEL,The serial channel adds the bytes but never "
        "ends a block",
     "0x00007740,cm848_trackDownloadBlock,3,channel,BOOT_REQUEST_CHANNEL,J1939 blocks end in cm848_updateDownloadCrc / "
     "serial blocks in mpc555_diagServiceTransferBlock")
edit("local_variables.csv", "0x00001fa4,mpc555_processDiagnosticAndEepromRequests,sVar1,erase_result,",
     "0x00001fa4,mpc555_processDiagnosticAndEepromRequests,wVar1,erase_result,")
edit("enums.csv", "a finished block's CRC is checked,4",
     "cm848_finishDownloadBlock checks a block's trailing CRC,4")
edit("enums.csv", "the verifier counts and flags the reflash in EEPROM / cm848_updateDownloadCrc never finishes a block,4",
     "the verifier counts and flags the reflash in EEPROM / mpc555_diagServiceTransferBlock ends a block against the "
     "CRC in its own request,4")
edit("structure_definitions.csv",
     "download_block_range_t,,end_address,dword,4,The block's last data byte: start + block length - 3 (before its "
     "2-byte CRC),,verified",
     "download_block_range_t,,end_address,dword,4,The block's last data byte: start + block length - 3 for a J1939 "
     "block (before its 2-byte CRC) / - 1 for a serial block,,verified")
edit("global_variables.csv",
     "each finished download block - filled by cm848_finishDownloadBlock (DOWNLOAD_INVALID when all 10 are used) and",
     "each finished download block - filled by cm848_finishDownloadBlock (J1939: DOWNLOAD_INVALID when all 10 are "
     "used) and mpc555_diagServiceTransferBlock (serial: 0x75 when full) and")
print("stage A second pass applied")

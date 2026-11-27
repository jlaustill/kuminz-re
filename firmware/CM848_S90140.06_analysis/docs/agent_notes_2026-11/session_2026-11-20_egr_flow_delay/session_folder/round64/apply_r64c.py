"""Round 64 stage C - one result-code enum for the application's PGN 61184 chain: J1939_DIAGNOSTIC_RESULT.
CM848 had two: DIAG_RESPONSE (size 4: 0 DIAG_ACK / 4 DIAG_NACK_NOT_READY / 7 DIAG_NACK_PROTECTED - on 5 handler
returns and 2 locals) and DIAG_RESPONSE_CODE (size 1, applied nowhere, "ported from CM550", abbreviated names).
Merged into J1939_DIAGNOSTIC_RESULT (size 4) with every code named from what produces it in this firmware
(the validator / the dispatcher / the memory workers / the handlers / the region lookup); CM550's 0x14
CHECKSUM_MISMATCH has no CM848 producer found and is not carried over. Typed on cm848_validateJ1939DiagnosticRequest's
return (full prototype: its param row exists) and the dispatcher's result_code local. CM550: its DIAG_RESPONSE_CODE
type takes the same name (shared names change in both firmwares); its members stay its own.
Idempotent.  usage: apply_r64c.py <repo> --cm848 <map.csv> | --cm550"""
import os
import sys

repo, phase = os.path.abspath(sys.argv[1]), sys.argv[2]
R = "PR #53 round 64"
P = "J1939_DIAGNOSTIC_RESULT_"


def edit(path, old, new, count=1):
    s = open(path).read()
    if new in s and old not in s:
        return
    assert s.count(old) == count, (path, old[:80], s.count(old))
    open(path, "w").write(s.replace(old, new))


if phase == "--cm848":
    map_path = sys.argv[3]
    O = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")
    ep = os.path.join(O, "enums.csv")
    e = open(ep).read()
    if "J1939_DIAGNOSTIC_RESULT," in e:
        print("already applied")
        sys.exit(0)
    lines = e.split("\n")
    i = lines.index("# Diagnostic Response Codes - Ported from CM550 (common diagnostic protocol)")
    j = i + 1
    while j < len(lines) and lines[j].startswith("DIAG_RESPONSE_CODE,"):
        j += 1
    assert j - i - 1 == 9, j - i - 1
    lines[i:j] = [f"# DIAG_RESPONSE_CODE (ported from CM550) was merged into J1939_DIAGNOSTIC_RESULT in {R}"]
    k = lines.index("# J1939 diagnostic request response codes - returned by handlers and sent back to tool on PGN 0xEF00")
    m = k + 1
    while m < len(lines) and lines[m].startswith("DIAG_RESPONSE,"):
        m += 1
    assert m - k - 1 == 3, m - k - 1
    MEMBERS = [
        (0x00, "ACCEPTED", "Done - cm848_sendJ1939ResponseFrame answers with 0x0c (was DIAG_ACK / SUCCESS)"),
        (0x02, "WRONG_LENGTH", "The request length is none of 8 / its header and data / that + 10 for the key - or a "
                               "memory length over 1764 (was DIAG_INVALID_LENGTH)"),
        (0x03, "KEY_REFUSED", "cm848_processSecurityCodeConversion refused the request's key (was SECURITY_FAILED)"),
        (0x04, "CANNOT_COMPLY", "Not now or not this: development mode is not on (cm848_exitDevelopmentMode) / no "
                                "transmit record is free (the read worker) / an unknown broadcast item "
                                "(cm848_updateJ1939BroadcastEnableMask) (was DIAG_NACK_NOT_READY / BUFFER_OVERFLOW)"),
        (0x07, "NOT_SAFE", "Refused in this state: not_safe_to_program_flag set (an EEPROM write / a forced exit from "
                           "development mode) / the engine not stopped (cm848_restartThroughBootRom) / outside the "
                           "key and flag gate of cm848_requestClearInactiveFaults (was DIAG_NACK_PROTECTED)"),
        (0x08, "UNKNOWN_PARAMETER_ID", "cm848_lookupParameterIdAddress does not know the ID (was "
                                       "ADDR_VALIDATION_FAIL)"),
        (0x09, "UNMAPPED_ADDRESS", "No memory region holds the address range (was INVALID_ADDR_RANGE)"),
        (0x0a, "REGION_REFUSED", "The region refuses the access: ROM for a write / the registers outside development "
                                 "mode / the EEPROM mirror RAM while the RAM refresh is on (was INVALID_ADDR_ALT)"),
        (0x0b, "EEPROM_WRITE_QUEUE_FULL", "cm848_queueEepromByteWrites would overflow its 64-entry queue"),
        (0x18, "UNKNOWN_SERVICE", "No handler is registered for the service byte (was UNKNOWN_SUBFUNC)"),
        (0x1a, "KEY_MISSING", "The service needs the key but the request carries none"),
        (0xff, "NONE", "Nothing to send: the validator passed the request / the handler answered itself / a response "
                       "came in - cm848_j1939DiagnosticServiceHandler sends no response"),
    ]
    block = [
        f"# J1939_DIAGNOSTIC_RESULT - the result code of a PGN 61184 request ({R}): was DIAG_RESPONSE (0 / 4 / 7) merged "
        "with DIAG_RESPONSE_CODE (ported from CM550 - its 0x14 CHECKSUM_MISMATCH has no CM848 producer found). "
        "cm848_j1939DiagnosticServiceHandler takes it from cm848_validateJ1939DiagnosticRequest or the handler; "
        "cm848_sendJ1939ResponseFrame answers ACCEPTED with 0x0c and the rest with 0x0d + the code",
        "# The memory workers pass a region type from cm848_lookupApplicationMemoryRegionType straight through: 9 (no "
        "region) / 10 (refused) - and a write to Bank 2 flash returns its type 2 (the value of WRONG_LENGTH). The boot "
        "kernel's dispatcher answers an unknown service with 5 and a refused ROM handler with 10",
    ]
    for h in block:
        assert "," not in h and '"' not in h
    for v, name, comment in MEMBERS:
        assert "," not in comment and '"' not in comment, name
        block.append(f"J1939_DIAGNOSTIC_RESULT,{v:#04x},{P}{name},{comment},4")
    lines[k:m] = block
    open(ep, "w").write("\n".join(lines))

    dp = os.path.join(O, "function_definitions.csv")
    edit(dp, "# DIAG_RESPONSE callback contract (ACK=0, NACK_NOT_READY=4, NACK_PROTECTED=7)",
         f"# J1939_DIAGNOSTIC_RESULT callback contract (was DIAG_RESPONSE: ACCEPTED 0 / CANNOT_COMPLY 4 / NOT_SAFE 7 - {R})")
    edit(dp, ",return,,DIAG_RESPONSE,", ",return,,J1939_DIAGNOSTIC_RESULT,", count=5)
    d = open(dp).read()
    assert ",cm848_validateJ1939DiagnosticRequest,return," not in d
    anchor = next(l for l in d.split("\n") if l.startswith("0x0050b634,cm848_validateJ1939DiagnosticRequest,0,"))
    d = d.replace(anchor, anchor + "\n" + "0x0050b634,cm848_validateJ1939DiagnosticRequest,return,,J1939_DIAGNOSTIC_RESULT,"
                  f"{P}NONE when the request may go to its handler - else WRONG_LENGTH / KEY_MISSING / KEY_REFUSED ({R})")
    open(dp, "w").write(d)

    lp = os.path.join(O, "local_variables.csv")
    for function in ("cm848_exitDevelopmentMode", "cm848_forceExitDevelopmentMode"):
        edit(lp, f",{function},uVar1,diag_ack_result,DIAG_RESPONSE,", f",{function},uVar1,result,J1939_DIAGNOSTIC_RESULT,")
    edit(lp, "0x00022128,cm848_j1939DiagnosticServiceHandler,uVar4,result_code,uint,",
         "0x00022128,cm848_j1939DiagnosticServiceHandler,uVar4,result_code,J1939_DIAGNOSTIC_RESULT,")
    with open(map_path, "w") as fh:
        fh.write("address,name,old_label,kind,dims\n")
        for old, new in (("DIAG_RESPONSE", "J1939_DIAGNOSTIC_RESULT"), ("DIAG_ACK", f"{P}ACCEPTED"),
                         ("DIAG_NACK_NOT_READY", f"{P}CANNOT_COMPLY"), ("DIAG_NACK_PROTECTED", f"{P}NOT_SAFE")):
            fh.write(f"-,{new},{old},enum,1\n")
    print(f"CM848: 2 enums merged into {len(MEMBERS)} members / 5 returns + 2 locals retyped / validator return / "
          "dispatcher local")
elif phase == "--cm550":
    p = os.path.join(repo, "firmware/CM550_J90350.00_analysis/output/enums.csv")
    lines = open(p).read().split("\n")
    if any(l.startswith("J1939_DIAGNOSTIC_RESULT,") for l in lines):
        print("already")
        sys.exit(0)
    rows = [i for i, l in enumerate(lines) if l.startswith("DIAG_RESPONSE_CODE,")]
    assert len(rows) == 9, len(rows)
    for i in rows:
        lines[i] = "J1939_DIAGNOSTIC_RESULT," + lines[i][len("DIAG_RESPONSE_CODE,"):]
    note = (f"# J1939_DIAGNOSTIC_RESULT (was DIAG_RESPONSE_CODE): renamed with CM848's in {R}. The members below are "
            "CM550's own and unreviewed against its handlers")
    assert "," not in note
    lines.insert(rows[0], note)
    open(p, "w").write("\n".join(lines))
    print("CM550: 9 rows retyped + 1 note")

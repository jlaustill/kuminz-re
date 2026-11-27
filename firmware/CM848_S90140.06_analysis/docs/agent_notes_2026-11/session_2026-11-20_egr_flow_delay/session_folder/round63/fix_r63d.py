"""Round 63 follow-up (the advisor's closing checks). Idempotent.
--cm848: the 0x0d member comment (0xfe sends 0x0e); the boot dispatcher's plate ("answered directly" - it sends
         nothing); diag_scan_step_counter -> boot_diagnostic_service_count (its only users: the boot registrar
         appends at it - at most 20 - and the boot dispatcher scans that many entries); the live docs the sweep found
         (parameter_by_id_system.md names the boot handlers / rom_to_ram_thunking.md's snapshot row /
         ecu_identification.md gets a CM848 footnote under its test matrix).
--cm550: CM550's EF00_SERVICE_ID type -> J1939_DIAGNOSTIC_SERVICE, the name CM848 uses (shared names change in both
         firmwares or neither); its members stay CM550's own (unreviewed: no CM550 handler evidence this round).
usage: fix_r63d.py <repo> --cm848 <map.csv> | --cm550"""
import os
import sys

repo, phase = os.path.abspath(sys.argv[1]), sys.argv[2]
R = "PR #53 round 63"


def edit(rel, old, new):
    p = os.path.join(repo, rel)
    s = open(p).read()
    if new in s:
        return "already"
    assert s.count(old) == 1, (rel, old[:80], s.count(old))
    open(p, "w").write(s.replace(old, new))
    return "edited"


if phase == "--cm848":
    map_path = sys.argv[3]
    O = "firmware/CM848_S90140.06_analysis/output"
    print(edit(f"{O}/enums.csv",
               "J1939_DIAGNOSTIC_SERVICE_NEGATIVE_RESPONSE,Sent by cm848_sendJ1939ResponseFrame for any other result - "
               "then the result code",
               "J1939_DIAGNOSTIC_SERVICE_NEGATIVE_RESPONSE,Sent by cm848_sendJ1939ResponseFrame for a nonzero result "
               "other than 0xfe (that sends 0x0e) - then the result code"))
    print(edit(f"{O}/function_renames.csv",
               "(its first data byte; 0x0c / 0x0d are answered directly; the boot twin of "
               "cm848_j1939DiagnosticServiceHandler)",
               "(its first data byte; a received 0x0c / 0x0d - a response - gets no handler and no answer (it said "
               f"answered directly before {R}); the boot twin of cm848_j1939DiagnosticServiceHandler)"))
    print(edit(f"{O}/global_variables.csv", "0x003fdb94,diag_scan_step_counter,byte,",
               "0x003fdb94,boot_diagnostic_service_count,byte,The number of services in diagnostic_service_dispatch_table: "
               "cm848_registerDiagnosticService appends at this index (at most 20 - it returns true when full) and "
               "cm848_dispatchDiagnosticService scans that many entries. The boot kernel's twin of "
               f"j1939_diagnostic_handler_count (was diag_scan_step_counter; {R})"))
    with open(map_path, "w") as fh:
        fh.write("address,name,old_label,kind,dims\n0x003fdb94,boot_diagnostic_service_count,diag_scan_step_counter,"
                 "global,1\n")
    D = "firmware/CM848_S90140.06_analysis/docs"
    print(edit(f"{D}/parameter_by_id_system.md",
               "- **Two kernels and two tables.** The 20-entry table at ROM 0x3CDC (`boot_parameter_id_table`) and the "
               "handlers at\n  0x19E8 / 0x1D5C belong to the boot kernel, which dispatches through "
               "`cm848_dispatchDiagnosticService`.",
               "- **Two kernels and two tables.** The 20-entry table at ROM 0x3CDC (`boot_parameter_id_table`) and the "
               "handlers at\n  0x19E8 / 0x1D5C belong to the boot kernel, which dispatches through "
               "`cm848_dispatchDiagnosticService`. Those\n  handlers are `cm848_handleBootGetAddressByParameterIdService` "
               "and `cm848_handleBootReadByParameterIdLongLengthService`;\n  the boot kernel's service IDs are the "
               "`BOOT_DIAGNOSTIC_SERVICE` enum."))
    print(edit(f"{D}/rom_to_ram_thunking.md", "0x003fb528,0x005958,cm848_getServiceDataOffset",
               "0x003fb528,0x005958,cm848_getBootMemoryServiceHeaderLength"))
    print(edit("ecu_identification.md",
               "| **Service 0x05** | 0x05 | J1708 only | ? | Write service (J1708 bus, not CAN) |\n",
               "| **Service 0x05** | 0x05 | J1708 only | ? | Write service (J1708 bus, not CAN) |\n\n"
               "CM848 from its firmware, not bench-tested (PR #53 round 63): 0x43 takes the parameter ID and a 4-byte "
               "length,\nwith no offset (the read starts at the ID's address). 0x46 takes the ID, a 2-byte offset and a "
               "1-byte length.\nThe service IDs are `J1939_DIAGNOSTIC_SERVICE` in "
               "`firmware/CM848_S90140.06_analysis/output/enums.csv`.\n"))
elif phase == "--cm550":
    p = os.path.join(repo, "firmware/CM550_J90350.00_analysis/output/enums.csv")
    lines = open(p).read().split("\n")
    if any(l.startswith("J1939_DIAGNOSTIC_SERVICE,") for l in lines):
        print("already")
        sys.exit(0)
    rows = [i for i, l in enumerate(lines) if l.startswith("EF00_SERVICE_ID,")]
    assert len(rows) == 24, len(rows)
    for i in rows:
        lines[i] = "J1939_DIAGNOSTIC_SERVICE," + lines[i][len("EF00_SERVICE_ID,"):]
    note = ("# J1939_DIAGNOSTIC_SERVICE (was EF00_SERVICE_ID - EF00 is the PGN in hex): renamed with CM848's in "
            f"{R}. The members below are CM550's own and unreviewed against its handlers")
    assert "," not in note
    lines.insert(rows[0], note)
    open(p, "w").write("\n".join(lines))
    print("CM550: 24 rows retyped + 1 note")

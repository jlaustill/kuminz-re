"""Round 61 stage A: the two diagnostic service dispatch tables get their struct types (the homes the templates' own
comments named), the request check gets its name, the three stale prototype names are synced and 15 plates stop
citing the registrar's old name (none of the names is in CM550).
- ef00_dispatch_entry_t -> j1939_diagnostic_service_entry_t {byte service_id, byte pad, pointer handler} (6 bytes) on
  j1939_diagnostic_service_table (RAM 0x3fa8b2, 32 slots: cm848_j1939RegisterDiagnosticService appends,
  cm848_j1939DiagnosticServiceHandler scans). The type-only pointer row 0x3fa8b4 inside it goes.
- diag_dispatch_entry_t -> boot_diagnostic_service_entry_t {byte service_id, pointer handler} (5 bytes, unaligned) on
  the boot kernel's diagnostic_service_dispatch_table (0x3fdb30): the arrays.csv byte[10] row becomes a
  global_variables.csv boot_diagnostic_service_entry_t[2] row - the same 10 bytes, short of the application's EEPROM
  mirror words from 0x3fdb3a (ApplyArrays maps primitive element types only).
- j1939_diagServiceDispatch -> cm848_validateJ1939DiagnosticRequest: it only checks a request's length / security.
- function_definitions.csv rows at 0x21918 / 0x220e4 / 0x227a0 carry pre-rename names (the build's three "Function
  name mismatch" warnings; the importer applies the prototypes anyway, so the sync changes no render).
Idempotent.  usage: apply_r61a.py <repo> <map.csv>"""
import os
import re
import sys

repo, map_path = os.path.abspath(sys.argv[1]), sys.argv[2]
O = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")
R = "PR #53 round 61"
sp = os.path.join(O, "structure_definitions.csv")
s = open(sp).read()
if "j1939_diagnostic_service_entry_t" in s:
    print("already applied")
    sys.exit(0)


def replace_block(text, name, new):
    m = re.search(rf"(?:^#[^\n]*\n)*(?:^{name},[^\n]*\n)+", text, re.M)
    assert m, name
    return text[:m.start()] + new + text[m.end():]


s = replace_block(s, "ef00_dispatch_entry_t",
    "# J1939 diagnostic service entry (6 bytes): j1939_diagnostic_service_table (RAM 0x3fa8b2 - 32 slots) - "
    "cm848_j1939RegisterDiagnosticService appends {service - handler} and cm848_j1939DiagnosticServiceHandler scans it "
    "for a PGN 61184 request's service byte (was ef00_dispatch_entry_t; PR #53 round 61)\n"
    "j1939_diagnostic_service_entry_t,,service_id,byte,1,The PGN 61184 diagnostic service byte (the request's first "
    "data byte),,verified\n"
    "j1939_diagnostic_service_entry_t,,pad,byte,1,Never written: the registrar stores only the service byte and the "
    "handler,,verified\n"
    "j1939_diagnostic_service_entry_t,,handler,pointer,4,The service handler: called with the received j1939_rx_msg_t "
    "once cm848_validateJ1939DiagnosticRequest accepts the request,,verified\n")
s = replace_block(s, "diag_dispatch_entry_t",
    "# Boot kernel diagnostic service entry (5 bytes - packed): diagnostic_service_dispatch_table (RAM 0x3fdb30) - "
    "cm848_registerDiagnosticService appends {service - handler} (14 entries - capacity 20) and "
    "cm848_dispatchDiagnosticService scans them; 2 entries are typed because the application's EEPROM mirror words share "
    "the RAM from 0x3fdb3a (was diag_dispatch_entry_t; PR #53 round 61)\n"
    "boot_diagnostic_service_entry_t,,service_id,byte,1,The boot diagnostic service byte,,verified\n"
    "boot_diagnostic_service_entry_t,,handler,pointer,4,The service handler at offset 1 (unaligned): "
    "cm848_dispatchDiagnosticService calls it,,verified\n")
open(sp, "w").write(s)

ap = os.path.join(O, "arrays.csv")
a = open(ap).read().split("\n")
k = next(i for i, l in enumerate(a) if l.startswith("0x003fdb30,diagnostic_service_dispatch_table,byte,10,"))
array_comment = a[k].split(",", 4)[4]
del a[k]
open(ap, "w").write("\n".join(a))

gp = os.path.join(O, "global_variables.csv")
g = open(gp).read().split("\n")
k = next(i for i, l in enumerate(g) if l.startswith("0x003fa8b4,"))
assert g[k] == "0x003fa8b4,,pointer,", g[k]
del g[k]
have = {l[:10] for l in g if l.startswith("0x")}
mapping = ["address,name,old_label,kind,dims"]
for addr, name, typ, text, rendered in [
        ("0x003fa8b2", "j1939_diagnostic_service_table", "j1939_diagnostic_service_entry_t[32]",
         "The application's J1939 (PGN 61184) diagnostic service table: cm848_j1939RegisterDiagnosticService appends "
         "{service byte - handler} at boot (up to 32 - counted by j1939_diagnostic_handler_count) and "
         "cm848_j1939DiagnosticServiceHandler scans it for a request's service byte. In the ROM-to-RAM window "
         f"(time-shared with the boot kernel image; no boot call lands in it) ({R})", "DAT_003fa8b2"),
        ("0x003fdb30", "diagnostic_service_dispatch_table", "boot_diagnostic_service_entry_t[2]",
         f"{array_comment} Typed since {R} as boot_diagnostic_service_entry_t[2] - the same 10 bytes - in "
         "global_variables.csv (was an arrays.csv byte[10] row; ApplyArrays maps primitive element types only).",
         None)]:
    assert addr not in have, addr
    later = [j for j, l in enumerate(g) if l.startswith("0x") and int(l[:10], 16) > int(addr, 16)]
    g.insert(later[0] if later else len(g), f"{addr},{name},{typ},{text}")
    if rendered:
        mapping.append(f"{addr},{name},{rendered},global,1")
open(gp, "w").write("\n".join(g))

fp = os.path.join(O, "function_renames.csv")
f = open(fp).read()
m = re.search(r"^0x0050b634,j1939_diagServiceDispatch(,[^\n]*)?$", f, re.M)
assert m
plate = ("Checks a J1939 (PGN 61184) diagnostic request before cm848_j1939DiagnosticServiceHandler calls its handler: "
         "for services below 0x1a the data length must be 8 or the header length (3 for services 4 / 5 - 5 for 0x19 - "
         "else 1) + 10; when j1939_command_security_flags marks the service and calibration_download_security_key_cal "
         "is set the request must carry the key after the header and cm848_processSecurityCodeConversion must accept it. "
         "Returns 0xff = accepted / 2 = wrong length / 0x1a = key missing / 3 = key refused")
assert "," not in plate
old_plate = (m.group(1) or ",")[1:].strip()
f = (f[:m.start()] + f"0x0050b634,cm848_validateJ1939DiagnosticRequest,{plate} (was j1939_diagServiceDispatch; {R})"
     + (f" | earlier note: {old_plate}" if old_plate else "") + f[m.end():])
mapping.append("0x0050b634,cm848_validateJ1939DiagnosticRequest,j1939_diagServiceDispatch,function,1")
n = f.count("registered with cm848_processJ1939DiagnosticRequest")
assert n == 15, n
f = f.replace("registered with cm848_processJ1939DiagnosticRequest", "registered with cm848_j1939RegisterDiagnosticService")
old = ("REGISTRAR for the J1939 diagnostic dispatch table 0x3fa8b2 - appends a service-id / handler entry up to 32 - not a "
       "request processor - scanned by cm848_j1939DiagnosticServiceHandler - 16 Bank-2 j1939_diagService comments still "
       "cite the old name (was cm848_processJ1939DiagnosticRequest)")
assert f.count(old) == 1
f = f.replace(old, "REGISTRAR for j1939_diagnostic_service_table (0x3fa8b2) - appends a service-id / handler entry up to "
                   "32 - not a request processor - scanned by cm848_j1939DiagnosticServiceHandler (was "
                   "cm848_processJ1939DiagnosticRequest)")
old = "sub-dispatches diagnostic service ids through the\n   0x3fa8b2 table"
if old not in f:
    old = "sub-dispatches diagnostic service ids through the 0x3fa8b2 table"
assert f.count(old) == 1, old
f = f.replace(old, "sub-dispatches diagnostic service ids through j1939_diagnostic_service_table (0x3fa8b2)")
open(fp, "w").write(f)

dp = os.path.join(O, "function_definitions.csv")
d = open(dp).read()
for addr, old_name, new_name in (("0x00021918", "cm848_validateCalibrationMemory", "cm848_commitEepromMirrorToEeprom"),
                                 ("0x000220e4", "cm848_processJ1939DiagnosticRequest", "cm848_j1939RegisterDiagnosticService"),
                                 ("0x000227a0", "cm848_j1939HandleDm1RequestMessage", "cm848_j1939HandlePgn58112Dm7")):
    assert f"{addr},{old_name}," in d, addr
    d = d.replace(f"{addr},{old_name},", f"{addr},{new_name},")
old = "0x000227a0,cm848_j1939HandlePgn58112Dm7,0,request_msg,j1939_rx_msg_t*,Pointer to DM1 (Active DTC) request"
assert d.count(old) == 1
d = d.replace(old, "0x000227a0,cm848_j1939HandlePgn58112Dm7,0,request_msg,j1939_rx_msg_t*,The received DM7 (PGN 58112) "
                   "request")
open(dp, "w").write(d)
with open(map_path, "w") as fh:
    fh.write("\n".join(mapping) + "\n")
print(f"2 tables typed, 1 function renamed, {n} plates refreshed, 3 prototype names synced")

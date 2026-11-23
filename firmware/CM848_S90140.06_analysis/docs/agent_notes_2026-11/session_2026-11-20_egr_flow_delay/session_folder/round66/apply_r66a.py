"""Round 66 stage A.
- BOOT_DIAGNOSTIC_RESULT, the boot kernel's twin of J1939_DIAGNOSTIC_RESULT (size 4 - the same reason: a one-byte
  result enum splits the dispatcher's masked value): 11 codes from their producers in the boot kernel. Its own: 5
  (the dispatcher's unknown service - the application uses 0x18) / 0x11 (a flash write at an odd address or a failed
  flash write) / 0x17 (service 2 when the EEPROM transfer does not start). 0xff (nothing to send) is no member - the
  dispatcher masks each result with 0xff. Typed on the boot validator's return (its full prototype) and the boot
  dispatcher's result local (keyed BVar4: positional names, the type's prefix).
- DAT_003fba10 -> net_combustion_torque_coolant_friction_term (sth @ 0x503afc): the coolant friction term
  cm848_calculateNetCombustionTorque subtracts; its scale net_combustion_torque_subtracted_term_scale ->
  net_combustion_torque_coolant_friction_scale.
Idempotent.  usage: apply_r66a.py <repo> <map.csv>"""
import os
import sys

repo, map_path = os.path.abspath(sys.argv[1]), sys.argv[2]
O = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")
R = "PR #53 round 66"
ep = os.path.join(O, "enums.csv")
e = open(ep).read()
if "BOOT_DIAGNOSTIC_RESULT," in e:
    print("already applied")
    sys.exit(0)
P = "BOOT_DIAGNOSTIC_RESULT_"
MEMBERS = [
    (0x00, "ACCEPTED", "Done - cm848_sendDiagServiceResponse answers with 0x0c"),
    (0x02, "WRONG_LENGTH", "The request length does not fit the service (the validator) or a memory length is over "
                           "1764 (the read and write workers)"),
    (0x03, "KEY_REFUSED", "cm848_validateWriteAuth refused the request's token"),
    (0x04, "CANNOT_COMPLY", "No response buffer is free (cm848_allocateDiagnosticResponseBuffer returned 0)"),
    (0x05, "UNKNOWN_SERVICE", "No handler is registered for the service byte (cm848_dispatchDiagnosticService - the "
                              "application answers this with 0x18)"),
    (0x08, "UNKNOWN_PARAMETER_ID", "cm848_lookupBootParameterIdAddress does not know the ID"),
    (0x09, "UNMAPPED_ADDRESS", "No memory region holds the address range (cm848_lookupBootMemoryRegionType)"),
    (0x0a, "REGION_REFUSED", "The region refuses the access - or the dispatcher refuses a ROM handler while the low "
                             "nibble of eeprom_service_mode_flags is set"),
    (0x11, "FLASH_WRITE_FAILED", "cm848_writeBootDiagnosticMemory: a flash write at an odd address or a flash write "
                                 "that failed"),
    (0x17, "EEPROM_TRANSFER_NOT_STARTED", "Service 2: mpc555_initEepromTransfer returned 0"),
    (0x1a, "KEY_MISSING", "The service needs the token but the request carries none"),
]
block = [
    f"# BOOT_DIAGNOSTIC_RESULT - the result code of a boot kernel PGN 61184 request ({R}): the twin of "
    "J1939_DIAGNOSTIC_RESULT with the boot kernel's own 5 / 0x11 / 0x17. cm848_dispatchDiagnosticService takes it "
    "from cm848_validateDiagnosticRequestLengthAndAuthorization or the handler; cm848_sendDiagServiceResponse answers "
    "ACCEPTED with 0x0c and the rest with 0x0d + the code. 0xff (nothing to send) is no member: the dispatcher masks "
    "each result with 0xff and a member of that value names the mask. The read and write workers pass region types "
    "and cm848_trackDownloadBlock codes straight through",
]
assert "," not in block[0]
for v, name, comment in MEMBERS:
    assert "," not in comment and '"' not in comment, name
    block.append(f"BOOT_DIAGNOSTIC_RESULT,{v:#04x},{P}{name},{comment},4")
lines = e.split("\n")
last = max(i for i, l in enumerate(lines) if l.startswith("BOOT_DIAGNOSTIC_SERVICE,"))
lines = lines[:last + 1] + block + lines[last + 1:]
open(ep, "w").write("\n".join(lines))

addresses = {}
for line in open(os.path.join(O, "function_renames.csv")):
    p = line.split(",", 2)
    if p[0].startswith("0x"):
        addresses[p[1].strip()] = p[0]
V = "cm848_validateDiagnosticRequestLengthAndAuthorization"
dp = os.path.join(O, "function_definitions.csv")
d = open(dp).read()
assert f",{V}," not in d
d = d.rstrip("\n") + "\n" + "\n".join([
    f"{addresses[V]},{V},return,,BOOT_DIAGNOSTIC_RESULT,0xff when the request may go to its handler - else "
    f"WRONG_LENGTH / KEY_REFUSED / KEY_MISSING ({R})",
    f"{addresses[V]},{V},0,request,j1939_rx_msg_t*,The boot kernel's PGN 61184 request ({R})"]) + "\n"
open(dp, "w").write(d)

lp = os.path.join(O, "local_variables.csv")
lv = open(lp).read()
D = "0x00006d24,cm848_dispatchDiagnosticService"
assert f"{D},BVar4," not in lv
lv = lv.rstrip("\n") + "\n" + "\n".join([
    f"{D},BVar4,result_code,BOOT_DIAGNOSTIC_RESULT,The validator's or the handler's result: 0xff = no response - "
    f"else cm848_sendDiagServiceResponse sends it ({R})",
    f"{D},pbVar3,entry,boot_diagnostic_service_entry_t *,The diagnostic_service_dispatch_table entry being compared "
    f"({R})"]) + "\n"
open(lp, "w").write(lv)

gp = os.path.join(O, "global_variables.csv")
g = open(gp).read()
assert "0x003fba10," not in g
anchor = next(l for l in g.split("\n") if l.startswith("0x003fba12,"))
g = g.replace(anchor, "0x003fba10,net_combustion_torque_coolant_friction_term,i16,Code (sth @ 0x503afc): "
                      "friction_torque_adjustment_for_coolant_temperature x net_combustion_torque_coolant_friction_scale "
                      "/ 2048 - the term cm848_calculateNetCombustionTorque subtracts with pumping_torque_adjustment from "
                      f"combustion_torque for net_combustion_torque; no other access found ({R})\n" + anchor)
old = "0x004059f4,net_combustion_torque_subtracted_term_scale,"
assert g.count(old) == 1
g = g.replace(old, "0x004059f4,net_combustion_torque_coolant_friction_scale,")
line = next(l for l in g.split("\n") if l.startswith("0x004059f4,"))
g = g.replace(line, line + f" (was net_combustion_torque_subtracted_term_scale; {R})")
open(gp, "w").write(g)
with open(map_path, "w") as fh:
    fh.write("address,name,old_label,kind,dims\n"
             "0x004059f4,net_combustion_torque_coolant_friction_scale,net_combustion_torque_subtracted_term_scale,"
             "global,1\n")
print(f"BOOT_DIAGNOSTIC_RESULT {len(MEMBERS)} members / validator prototype / 2 dispatcher locals / 1 global named + 1 "
      "renamed")

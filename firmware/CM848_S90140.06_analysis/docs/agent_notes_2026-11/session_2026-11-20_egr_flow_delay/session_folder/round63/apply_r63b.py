"""Round 63 stage B - the application's PGN 61184 request typed as j1939_rx_msg_t * (the dispatcher
cm848_j1939DiagnosticServiceHandler calls every handler with its j1939_rx_msg_t *rx_msg; each handler reads its
request bytes through +6 = data_pointer and the 0x41 handler its addresses through +0 / +2 / +3 = priority_dp_flags /
dest_address / source_address). Prototypes for the 15 request handlers that take it and the 5 workers they call (the
workers' other parameters named from stage A's reading: parameter ID / offset / length / address / enable).
Idempotent.  usage: apply_r63b.py <repo>"""
import os
import re
import sys

O = os.path.join(os.path.abspath(sys.argv[1]), "firmware/CM848_S90140.06_analysis/output")
R = "PR #53 round 63"
REQUEST = ("request", "j1939_rx_msg_t*", f"The PGN 61184 request from cm848_j1939DiagnosticServiceHandler ({R})")
SINGLE = ["cm848_handleJ1939DisableBroadcastService", "cm848_handleJ1939EnableBroadcastService",
          "cm848_handleJ1939RestartService", "cm848_handleJ1939GetAddressByParameterIdService",
          "cm848_handleJ1939ReadByParameterIdLongLengthService", "cm848_handleJ1939WriteByParameterIdService",
          "cm848_handleJ1939WriteByParameterIdLongLengthService", "cm848_handleJ1939ReadByParameterIdShortOffsetService",
          "cm848_handleJ1939WriteByParameterIdShortOffsetService", "cm848_handleJ1939ReadByParameterIdLongOffsetService",
          "cm848_handleJ1939WriteByParameterIdLongOffsetService", "cm848_handleJ1939ReadMemoryService",
          "cm848_handleJ1939WriteMemoryService", "cm848_handleJ1939ReadMemoryLongLengthService",
          "cm848_handleJ1939WriteMemoryLongLengthService"]
MULTI = {
    "cm848_updateJ1939BroadcastEnableMask": [
        ("request", "j1939_rx_msg_t*", f"The service 4 / 5 request: byte 1 the item and byte 2 the target ({R})"),
        ("enable", "uint", f"1 sets the selected bits of datalink_broadcast_enable_flags - anything else clears "
                           f"them ({R})")],
    "cm848_readJ1939DiagnosticMemoryByParameterId": [
        REQUEST,
        ("parameter_id", "ushort", f"The e2m block ID that cm848_lookupParameterIdAddress resolves ({R})"),
        ("offset", "uint", f"Added to the ID's address ({R})"),
        ("length", "uint", f"Bytes to read ({R})")],
    "cm848_writeJ1939DiagnosticMemoryByParameterId": [
        REQUEST,
        ("parameter_id", "ushort", f"The e2m block ID that cm848_lookupParameterIdAddress resolves ({R})"),
        ("offset", "uint", f"Added to the ID's address ({R})"),
        ("length", "uint", f"Bytes to write ({R})")],
    "cm848_readJ1939DiagnosticMemoryAndRespond": [
        REQUEST,
        ("address", "uint", f"The first byte to read ({R})"),
        ("length", "uint", f"Bytes to read - at most 1764 ({R})")],
    "cm848_writeJ1939DiagnosticMemory": [
        REQUEST,
        ("address", "byte*", f"The first byte to write ({R})"),
        ("length", "uint", f"Bytes to write - at most 1764 ({R})")],
}
addresses = {}
for line in open(os.path.join(O, "function_renames.csv")):
    parts = line.split(",", 2)
    if parts[0].startswith("0x"):
        addresses[parts[1].strip()] = parts[0]
dp = os.path.join(O, "function_definitions.csv")
d = open(dp).read()
if f",cm848_handleJ1939ReadMemoryService,0,request," in d:
    print("already applied")
    sys.exit(0)
new_rows = []
for name in SINGLE + list(MULTI):
    assert name in addresses, name
    assert not re.search(rf"^0x[0-9a-f]+,{name},", d, re.M), f"{name} already has rows"
    for index, (pname, ptype, comment) in enumerate(MULTI.get(name, [REQUEST])):
        assert "," not in comment
        new_rows.append(f"{addresses[name]},{name},{index},{pname},{ptype},{comment}")
open(dp, "w").write(d.rstrip("\n") + "\n" + "\n".join(new_rows) + "\n")
print(f"{len(new_rows)} prototype rows for {len(SINGLE) + len(MULTI)} functions")

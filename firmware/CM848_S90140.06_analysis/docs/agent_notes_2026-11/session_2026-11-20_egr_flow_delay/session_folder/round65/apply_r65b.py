"""Round 65 stage B - the J1939 receive handler table and its handlers typed.
cm848_dispatchJ1939ReceivedMessages walks RAM 0x3fd414 in 6-byte steps (a word key compared with the received frame's
PDU format / specific, the handler pointer at +2, called with the 18-byte receive queue entry = a j1939_rx_msg_t);
cm848_registerJ1939ReceiveHandler appends {key, handler} up to j1939_receive_handler_count (0x3fd47a, 17 slots - so
the table ends right at the count). No boot thunk lies in its 102 bytes. The two type-only pointer rows inside it go.
Every registered handler that took an int / dword * takes j1939_rx_msg_t *message, and so do the four TP.CM
sub-handlers the TP.CM dispatcher calls with the message still in r3 (their calls showed no argument).
Idempotent.  usage: apply_r65b.py <repo>"""
import os
import sys

O = os.path.join(os.path.abspath(sys.argv[1]), "firmware/CM848_S90140.06_analysis/output")
R = "PR #53 round 65"
sp = os.path.join(O, "structure_definitions.csv")
s = open(sp).read()
if "j1939_receive_handler_entry_t," in s:
    print("already applied")
    sys.exit(0)
anchor = next(l for l in s.split("\n") if l.startswith("j1939_diagnostic_service_entry_t,,handler,"))
block = [
    anchor,
    f"# J1939 receive handler entry (6 bytes): j1939_receive_handler_table (RAM 0x3fd414 - 17 slots) - "
    f"cm848_registerJ1939ReceiveHandler appends {{PGN key - handler}} and cm848_dispatchJ1939ReceivedMessages calls the "
    f"handler whose key matches a received frame ({R})",
    "j1939_receive_handler_entry_t,,pgn_key,word,2,The PGN's PDU format and PDU specific bytes as one word - specific "
    "0 for a destination-specific PGN (0xef00 = PGN 61184 / 0xfef1 = PGN 65265 / 0 = TSC1),,verified",
    "j1939_receive_handler_entry_t,,handler,pointer,4,The receive handler: called with the received j1939_rx_msg_t,,"
    "verified",
]
assert "," not in block[1]
s = s.replace(anchor, "\n".join(block))
open(sp, "w").write(s)

gp = os.path.join(O, "global_variables.csv")
g = open(gp).read()
lines = g.split("\n")
for gone in ("0x003fd416,,pointer,", "0x003fd41c,,pointer,"):
    assert lines.count(gone) == 1, gone
for l in lines:
    if l.startswith("0x") and 0x3fd414 <= int(l.split(",", 1)[0], 16) <= 0x3fd479:
        assert l in ("0x003fd416,,pointer,", "0x003fd41c,,pointer,"), l[:60]
row = ("0x003fd414,j1939_receive_handler_table,j1939_receive_handler_entry_t[17],The J1939 receive handler table: 17 "
       "six-byte {PGN key - handler} entries up to j1939_receive_handler_count (0x3fd47a - right after the table). "
       "cm848_registerJ1939ReceiveHandler fills it at startup and cm848_dispatchJ1939ReceivedMessages calls the handler "
       "whose key matches each received frame. In the ROM-to-RAM copy window: no boot thunk lies in its 102 bytes "
       f"({R})")
out = []
for l in lines:
    if l == "0x003fd416,,pointer,":
        out.append(row)
    elif l == "0x003fd41c,,pointer,":
        continue
    else:
        out.append(l)
open(gp, "w").write("\n".join(out))

addresses = {}
for line in open(os.path.join(O, "function_renames.csv")):
    p = line.split(",", 2)
    if p[0].startswith("0x"):
        addresses[p[1].strip()] = p[0]
HANDLERS = ["cm848_processJ1939Dm13StopStartBroadcast", "cm848_j1939ProcessPgn61445Etc2",
            "cm848_j1939HandlePgn56832Reset", "cm848_receivePgn56576AntiTheftRequestMessage",
            "cm848_receivePgn57344CabMessage1", "cm848_receivePgn61441ElectronicBrakeController1Message",
            "cm848_receivePgn61443ElectronicEngineController2Message", "cm848_receivePgn65252ShutdownMessage",
            "cm848_receivePgn65264PowerTakeoffInformationMessage",
            "cm848_receivePgn65265CruiseControlVehicleSpeedMessage",
            "cm848_dispatchJ1939TransportConnectionManagement", "cm848_handleJ1939TransportDataPacket",
            "cm848_handleJ1939TransportRequestToSend", "cm848_handleJ1939TransportClearToSend",
            "cm848_handleJ1939TransportEndOfMessageAcknowledge", "cm848_handleJ1939TransportAbort"]
dp = os.path.join(O, "function_definitions.csv")
d = open(dp).read()
rows = []
REG = "cm848_registerJ1939ReceiveHandler"
assert f",{REG}," not in d
rows.append(f"{addresses[REG]},{REG},0,pgn_key,ushort,The PGN key of the frames to hand over (see "
            f"j1939_receive_handler_entry_t) ({R})")
rows.append(f"{addresses[REG]},{REG},1,handler,void*,The handler: called with each matching j1939_rx_msg_t ({R})")
for name in HANDLERS:
    assert name in addresses and f",{name}," not in d, name
    rows.append(f"{addresses[name]},{name},0,message,j1939_rx_msg_t*,The received frame from "
                f"cm848_dispatchJ1939ReceivedMessages ({R})")
open(dp, "w").write(d.rstrip("\n") + "\n" + "\n".join(rows) + "\n")
print(f"struct + table / registrar prototype / {len(HANDLERS)} handler prototypes")

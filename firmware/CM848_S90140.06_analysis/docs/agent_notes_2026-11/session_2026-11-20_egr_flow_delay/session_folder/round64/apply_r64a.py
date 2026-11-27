"""Round 64 stage A - the two transmit records cm848_selectJ1939TransmitBuffer hands out, as j1939_tx_msg_t instances.
The selector fills them in place (+4 data_length / +6 data_pointer / +10 status_pointer of a 14-byte j1939_tx_msg_t):
up to 8 bytes the record at 0x3fcbc4 (data 0x3fcbd3 / status 0x3fcbd2), else the record at 0x3fc4ad (data 0x3fc4bc /
status 0x3fc4bb) while that status byte's high nibble is 0. The four type-only pointer rows inside the records go.
The transport data buffer gets a named first byte, not an array: its extent (to 0x3fcbc3) holds the boot reflash
kernel's image at boot, with boot ROM call targets (thunks) at 0x3fc580 - 0x3fcb24. The selector gets its full
prototype (return j1939_tx_msg_t *; length int32_t as inferred) so its three callers lose their casts.
Idempotent.  usage: apply_r64a.py <repo>"""
import os
import sys

O = os.path.join(os.path.abspath(sys.argv[1]), "firmware/CM848_S90140.06_analysis/output")
R = "PR #53 round 64"
gp = os.path.join(O, "global_variables.csv")
g = open(gp).read()
if "j1939_transport_tx_message," in g:
    print("already applied")
    sys.exit(0)
lines = g.split("\n")  # the file has no final newline; nothing at its end changes
GONE = {"0x003fc4b3,,pointer,": "transport", "0x003fc4b7,,pointer,": None,
        "0x003fcbca,,pointer,": "single", "0x003fcbce,,pointer,": None}
for gone in GONE:
    assert lines.count(gone) == 1, gone
USERS = ("the PGN 61184 replies (cm848_sendJ1939ResponseFrame / cm848_readJ1939DiagnosticMemoryAndRespond) and "
         "cm848_sendDataCollectorBuffer")
ROWS = [
    ("0x003fc4ad", "j1939_transport_tx_message", "j1939_tx_msg_t",
     "The transmit record cm848_selectJ1939TransmitBuffer hands out for a message over 8 bytes (sent with the J1939 "
     "transport protocol): it sets data_length and points data_pointer at j1939_transport_tx_data and status_pointer at "
     f"j1939_transport_transmit_status. Taken only while that status byte's high nibble is 0. Users: {USERS} ({R})"),
    ("0x003fc4bb", "j1939_transport_transmit_status", "byte",
     "The status byte of j1939_transport_tx_message (its status_pointer target): cm848_selectJ1939TransmitBuffer "
     f"refuses the record while the high nibble is not 0 ({R})"),
    ("0x003fc4bc", "j1939_transport_tx_data", "byte",
     "The first byte of j1939_transport_tx_message's data. The buffer runs to 0x3fcbc3 (1800 bytes; a 0x4c memory read "
     "reply needs up to 1775). Not typed as an array: the boot reflash kernel's image fills this RAM at boot and the "
     f"boot ROM calls into it (thunks at 0x3fc580 - 0x3fcb24) ({R})"),
    ("0x003fcbc4", "j1939_single_frame_tx_message", "j1939_tx_msg_t",
     "The transmit record cm848_selectJ1939TransmitBuffer hands out for a message of up to 8 bytes: it sets "
     "data_length and points data_pointer at j1939_single_frame_tx_data and status_pointer at "
     f"j1939_single_frame_transmit_status. Users: {USERS} ({R})"),
    ("0x003fcbd2", "j1939_single_frame_transmit_status", "byte",
     f"The status byte of j1939_single_frame_tx_message (its status_pointer target) ({R})"),
    ("0x003fcbd3", "j1939_single_frame_tx_data", "byte[8]",
     f"The data of j1939_single_frame_tx_message: one CAN frame ({R})"),
]
present = {int(l.split(",", 1)[0], 16) for l in lines if l.startswith("0x")}
block = {"transport": [], "single": []}
for address, name, typ, comment in ROWS:
    assert "," not in comment and int(address, 16) not in present, address
    block["transport" if address < "0x003fcb00" else "single"].append(f"{address},{name},{typ},{comment}")
out = []
for line in lines:  # each record's rows go where its first replaced type-only row was
    if line in GONE:
        if GONE[line]:
            out.extend(block[GONE[line]])
        continue
    out.append(line)
open(gp, "w").write("\n".join(out))

dp = os.path.join(O, "function_definitions.csv")
d = open(dp).read()
assert ",cm848_selectJ1939TransmitBuffer," not in d
d = d.rstrip("\n") + "\n" + "\n".join([
    f"0x0050d688,cm848_selectJ1939TransmitBuffer,return,,j1939_tx_msg_t*,j1939_single_frame_tx_message or "
    f"j1939_transport_tx_message - 0 while the transport record is busy ({R})",
    f"0x0050d688,cm848_selectJ1939TransmitBuffer,0,length,int32_t,The message's data bytes: up to 8 takes the single "
    f"frame record ({R})"]) + "\n"
open(dp, "w").write(d)
print("4 type-only rows replaced by 6 / selector prototype")

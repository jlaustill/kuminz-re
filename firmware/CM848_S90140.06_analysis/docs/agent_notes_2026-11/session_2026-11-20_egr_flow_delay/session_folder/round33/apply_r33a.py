"""Round 33 stage A (labels): the J1939 transmit status pointer and status bytes.
- j1939_tx_msg_t.data_end_pointer -> status_pointer (the field is the pointer to the message's status byte, like
  the boot twin diagnostic_response_message_t.status_pointer);
- every descriptor's status byte (the initializer's '<descriptor>.data_end_pointer = &DAT_x;') gets a byte row
  j1939_<message>_transmit_status; DM1's existing row j1939_dm1_fault_data_channel_byte is renamed; PGN 65259's
  (0x3fab4e, rendered LAB_003fab4c_2) waits for stage B (it sits in code units the payload struct clears);
- j1939_ackm_msg -> j1939_pgn59392_tx_message (its header is 0xe8ff00 = PGN 59392 from j1939_pgn59392_priority_cal),
  and the five stale flat rows inside it become dotted documentation rows;
- the three initializer plates that called the field an end pointer.
Writes the proof map (address,name,old_label,kind). Idempotent.
usage: apply_r33a.py <repo> <map.csv>"""
import os
import re
import sys

repo, map_path = os.path.abspath(sys.argv[1]), sys.argv[2]
out = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")
cpp = open(os.path.join(out, "cm848_rom.ghidra.cpp"), errors="replace").read()
CODES = ("0 queued / 1 zero length / 4 CAN transmit queue full from mpc555_sendJ1939SingleFrame; the application "
         "transport's 0x12 started / 0x13 sending / 9 complete / 10 aborted / 6 clear to send timeout / 7 data frame "
         "send failed / 8 another session busy / 3 source address not ours")
READERS = {"j1939_pgn65251_tx_message": "cm848_sendPgn65251EngineConfiguration1Message",
           "j1939_dm1_tx_message": "j1939HandlePgn65226Dm1ActiveDtc",
           "j1939_dm2_tx_message": "cm848_j1939HandlePgn65227Dm2PreviousDtc",
           "j1939_pgn65229_tx_message": "cm848_j1939HandlePgn65229Dm4FreezeFrame",
           "j1939_pgn65249_tx_message": "cm848_buildPgn65249RetarderConfigurationMessage"}
map_rows = ["address,name,old_label,kind", ",status_pointer,data_end_pointer,field",
            "0x003faa9c,j1939_pgn59392_tx_message,j1939_ackm_msg,global",
            "0x003fabca,j1939_dm1_transmit_status,j1939_dm1_fault_data_channel_byte,global"]


def status_name(descriptor):
    if descriptor == "j1939_ackm_msg":
        return "j1939_pgn59392_transmit_status", "j1939_pgn59392_tx_message"
    assert descriptor.endswith("_tx_message"), descriptor
    return descriptor[: -len("_tx_message")] + "_transmit_status", descriptor


new_rows = {}
for descriptor, label in re.findall(r"(\w+)\.data_end_pointer = &(DAT_003f[0-9a-f]{4});", cpp):
    address = int(label[4:], 16)
    name, shown = status_name(descriptor)
    reader = READERS.get(shown)
    extra = (f"; {reader} rebuilds the payload only while its 0xf0 nibble is clear (no transport session still "
             f"sending it)") if reader else ""
    new_rows[address] = (name, f"the status byte of {shown} (its status_pointer target): {CODES}{extra} (PR #53 "
                               f"round 33)")
    map_rows.append(f"0x{address:08x},{name},{label},global")
assert len(new_rows) == 29, len(new_rows)
gp = os.path.join(out, "global_variables.csv")
g = open(gp).read().split("\n")
STALE = {  # rows inside the PGN 59392 descriptor (0x3faa9c-0x3faaa9) from an old 'alternate 56320 descriptor' reading
    "0x003faa9e": ("j1939_dm1_cmd_word_b", "j1939_pgn59392_tx_message.header.can_id",
                   "byte 2 of the identifier: the destination 0xff"),
    "0x003faa9f": ("j1939_ackm_msg.can_id+3", "j1939_pgn59392_tx_message.header.can_id",
                   "byte 3 of the identifier: the source address (the request's destination)"),
    "0x003faaa0": ("j1939_pgn56320_alternate_data_length", "j1939_pgn59392_tx_message.header.data_length", "8"),
    "0x003faaa2": ("j1939_pgn56320_alternate_data_pointer", "j1939_pgn59392_tx_message.data_pointer",
                   "j1939_ack_payload"),
    "0x003faaa6": ("j1939_pgn56320_alternate_data_end_pointer", "j1939_pgn59392_tx_message.status_pointer",
                   "j1939_pgn59392_transmit_status"),
}
for i, l in enumerate(g):
    p = l.split(",", 3)
    if len(p) < 2 or not p[0].startswith("0x"):
        continue
    old_comment = p[3] if len(p) > 3 else ""
    if p[0] == "0x003fabca" and p[1] == "j1939_dm1_fault_data_channel_byte":
        g[i] = (f"0x003fabca,j1939_dm1_transmit_status,byte,the status byte of j1939_dm1_tx_message (its status_pointer "
                f"target): {CODES}; j1939HandlePgn65226Dm1ActiveDtc rebuilds the payload only while its 0xf0 nibble "
                f"is clear (was j1939_dm1_fault_data_channel_byte; PR #53 round 33) | earlier note: {old_comment}")
    elif p[0] == "0x003faa9c" and p[1] == "j1939_ackm_msg":
        g[i] = ("0x003faa9c,j1939_pgn59392_tx_message,j1939_tx_msg_t,the transmit descriptor of the J1939-21 "
                "Acknowledgement (PGN 59392: header 0xe8ff00 with the priority from j1939_pgn59392_priority_cal and "
                "identifier bytes 2-3 = 0xff / the request's destination address, both set per reply by "
                "cm848_sendJ1939AcknowledgeMessage and cm848_sendJ1939NegativeAcknowledgement; data pointer "
                "j1939_ack_payload; status byte j1939_pgn59392_transmit_status) (was j1939_ackm_msg; PR #53 round 33)")
    elif p[0] in STALE and p[1] == STALE[p[0]][0]:
        old, new, what = STALE[p[0]]
        g[i] = (f"{p[0]},{new},,{what} (was {old}: a stale flat row inside the PGN 59392 descriptor; an old reading "
                f"took this record for a second PGN 56320 descriptor; PR #53 round 33)")
    elif p[0] == "0x003faaaa" and p[1] == "j1939_ack_payload":
        g[i] = l.replace("that descriptor's data_pointer / data_end_pointer point at it",
                         "that descriptor's data_pointer points at it and its status byte "
                         "j1939_pgn59392_transmit_status follows it")
for address, (name, comment) in sorted(new_rows.items()):
    a = f"0x{address:08x}"
    if any(l.startswith(a + ",") for l in g):
        continue
    i = max(j for j, l in enumerate(g) if l.startswith("0x") and int(l[:10], 16) < address)
    g.insert(i + 1, f"{a},{name},byte,{comment}")
open(gp, "w").write("\n".join(g))
sd = os.path.join(out, "structure_definitions.csv")
s = open(sd).read()
OLD = "j1939_tx_msg_t,,data_end_pointer,pointer,4,Pointer one past the last payload byte,,verified"
NEW = ("j1939_tx_msg_t,,status_pointer,pointer,4,Points at the message's status byte j1939_<message>_transmit_status "
       "(was data_end_pointer: the byte often sits right after the payload; PR #53 round 33): in the application "
       "mpc555_sendJ1939SingleFrame stores its result there and initiateJ1939TransportProtocol / the "
       "j1939_transport_* handlers their session codes through j1939_multiframe_tx_status_ptr (0x12 started / 0x13 "
       "sending / 9 complete / 10 aborted / 6 clear to send timeout / 7 send failed / 8 busy / 3 not our source "
       "address); the multi-frame builders rebuild only while its 0xf0 nibble is clear. The boot twin is "
       "diagnostic_response_message_t.status_pointer,,verified")
if NEW not in s:
    assert s.count(OLD) == 1
    s = s.replace(OLD, NEW)
    open(sd, "w").write(s)
fp = os.path.join(out, "function_renames.csv")
f = open(fp).read()
for old, new in [
        ("j1939_auxiliary_input_output_status_1_byte (0x3faacc), end pointer 0x3faae2.",
         "j1939_auxiliary_input_output_status_1_byte (0x3faacc), status pointer j1939_pgn65241_transmit_status "
         "(0x3faae2)."),
        ("at 0x3fae20 and end pointer 0x3fae36 (was", "at 0x3fae20 and status pointer j1939_pgn65213_transmit_status "
                                                     "(0x3fae36) (was"),
        ("and the payload pointers (start j1939_pgn65249_payload_byte_1, end 0x3fae71)",
         "the data pointer (j1939_pgn65249_payload_byte_1) and the status pointer (j1939_pgn65249_transmit_status, "
         "0x3fae71)")]:
    if new not in f:
        assert f.count(old) == 1, old
        f = f.replace(old, new)
open(fp, "w").write(f)
with open(map_path, "w") as fh:
    fh.write("\n".join(map_rows) + "\n")
print(f"{len(new_rows)} new status rows, {len(map_rows) - 1} map rows")

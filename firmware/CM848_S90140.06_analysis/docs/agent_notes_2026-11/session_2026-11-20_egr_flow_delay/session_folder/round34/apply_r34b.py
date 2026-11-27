"""Round 34 stage B (types): the application J1939 transport's two broadcast (BAM) transmit session records.
j1939_broadcast_transmit_session_t: 32 bytes (a type-only template; the widths from the initiator's stores and the
packet sender's loads); the instance is the array row j1939_broadcast_transmit_sessions[2] at 0x3fbd74 ([0] for
j1939_source_address / [1] for j1939_engine_retarder_source_address). The named rows inside become untyped dotted
documentation rows and the two unnamed type-only pointer rows go (a typed row inside the array would be created
first and keep the array from applying). The two 8-byte frame buffers get rows. Field words follow the boot twin
j1939_transport_transmit_session_t where they match. Writes the proof map. Idempotent.
usage: apply_r34b.py <repo> <map.csv>"""
import os
import sys

repo, map_path = os.path.abspath(sys.argv[1]), sys.argv[2]
out = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")
T = "j1939_broadcast_transmit_session_t"
FIELDS = [  # (name, type, size, comment) - comma-free
    ("active", "byte", 1, "1 while the session runs: initiateJ1939TransportProtocol sets it / "
     "cm848_sendJ1939BroadcastDataPacket clears it after the last packet or a failed frame"),
    ("total_packet_count", "byte", 1, "(message_size - 1) / 7 + 1"),
    ("message_size", "word", 2, "the broadcast message's size in bytes (its descriptor's data_length)"),
    ("next_data_byte_number", "word", 2, "the 1-based number of the next data byte: 1 at the announce and +7 per "
     "packet (one sth; the last packet carries message_size - this + 1 bytes)"),
    ("next_packet_number", "byte", 1, "the next packet's number: 1 at the announce"),
    ("frame_queue_status", "byte", 1, "the result mpc555_sendJ1939SingleFrame writes for the last frame (0 queued / "
     "1 zero length / 4 queue full)"),
    ("message_data_pointer", "byte*", 4, "the next data byte (the descriptor's data pointer; advanced per byte)"),
    ("session_status_pointer", "byte*", 4, "the message's status byte (the descriptor's status_pointer): 0x10 "
     "announced / 0x11 sending / 5 complete / the send result"),
    ("packet_delay_timer", "word", 2, "service passes until the next packet: 5 after each (0 while "
     "j1939_broadcast_no_packet_delay_flag is set)"),
    ("frame_can_id", "dword", 4, "the CAN identifier of the next frame: the message's with PDU format 0xEC (TP.CM) "
     "for the announce then 0xEB (TP.DT) / destination 0xff"),
    ("frame_data_length", "word", 2, "data bytes of the next frame: 8 / the last packet's"),
    ("transmit_frame_pointer", "byte*", 4, "the frame assembly buffer (j1939_broadcast_transmit_frame_buffer_0 / _1; "
     "cm848_initializeJ1939Transport)"),
    ("unused", "byte", 4, "no access found in the application transport (the records are 32 bytes apart)"),
]
assert sum(f[2] for f in FIELDS) == 32
sd = os.path.join(out, "structure_definitions.csv")
lines = open(sd).read().split("\n")
if not any(l.startswith(T + ",") for l in lines):
    while lines and lines[-1] == "":
        lines.pop()
    lines.append(f"# {T}: one broadcast (BAM) transmit session record of the application J1939 transport (32 bytes; "
                 f"type-only template - the instance is j1939_broadcast_transmit_sessions[2] in global_variables.csv; "
                 f"PR #53 round 34)")
    for name, typ, size, comment in FIELDS:
        assert "," not in comment
        lines.append(f"{T},,{name},{typ},{size},{comment},,verified")
    lines.append("")
    open(sd, "w").write("\n".join(lines))
gp = os.path.join(out, "global_variables.csv")
g = open(gp).read().split("\n")
keep = []
for l in g:
    p = l.split(",", 3)
    old = p[3] if len(p) > 3 else ""
    if l.startswith("0x003fbd74,j1939_tp_rx_session_active,"):
        keep.append(f"0x003fbd74,j1939_broadcast_transmit_sessions,{T}[2],the two broadcast (BAM) transmit session "
                    f"records: [0] for j1939_source_address / [1] for j1939_engine_retarder_source_address "
                    f"(initiateJ1939TransportProtocol picks one by the message's source address) (was "
                    f"j1939_tp_rx_session_active and flat rows: nothing here receives; PR #53 round 34) | earlier "
                    f"note: {old}")
    elif l.startswith("0x003fbd80,j1939_tp_rx_session_status_ptr,"):
        keep.append(f"0x003fbd80,j1939_broadcast_transmit_sessions[0].session_status_pointer,,(was "
                    f"j1939_tp_rx_session_status_ptr; PR #53 round 34) | earlier note: {old}")
    elif l.startswith("0x003fbd8c,j1939_tp_rx_session_tx_buf_ptr,"):
        keep.append(f"0x003fbd8c,j1939_broadcast_transmit_sessions[0].transmit_frame_pointer,,(was "
                    f"j1939_tp_rx_session_tx_buf_ptr; PR #53 round 34) | earlier note: {old}")
    elif l.startswith("0x003fbd7c,,pointer") or l.startswith("0x003fbdac,,pointer"):
        continue  # type-only pointer rows inside the array: [0].message_data_pointer / [1].transmit_frame_pointer
    else:
        keep.append(l)
g = keep
NEW = [(0x3fbdb4, "j1939_broadcast_transmit_frame_buffer_0", "byte[8]",
        "the frame assembly buffer of j1939_broadcast_transmit_sessions[0] (cm848_initializeJ1939Transport points "
        "its transmit_frame_pointer here; PR #53 round 34)"),
       (0x3fbdbc, "j1939_broadcast_transmit_frame_buffer_1", "byte[8]",
        "the frame assembly buffer of j1939_broadcast_transmit_sessions[1] (PR #53 round 34)")]
for address, name, typ, comment in NEW:
    a = f"0x{address:08x}"
    if any(l.startswith(a + ",") for l in g):
        continue
    j = max(k for k, l in enumerate(g) if l.startswith("0x") and int(l[:10], 16) < address)
    g.insert(j + 1, f"{a},{name},{typ},{comment}")
open(gp, "w").write("\n".join(g))
offsets, o = {}, 0
for name, typ, size, _ in FIELDS:
    offsets[name] = o
    o += size
rows = ["address,name,old_label,kind",
        "0x003fbd74,j1939_broadcast_transmit_sessions[0].active,j1939_tp_rx_session_active,global",
        "0x003fbd80,j1939_broadcast_transmit_sessions[0].session_status_pointer,j1939_tp_rx_session_status_ptr,global",
        "0x003fbd8c,j1939_broadcast_transmit_sessions[0].transmit_frame_pointer,j1939_tp_rx_session_tx_buf_ptr,global",
        "0x003fbdb4,j1939_broadcast_transmit_frame_buffer_0,DAT_003fbdb4,global",
        "0x003fbdbc,j1939_broadcast_transmit_frame_buffer_1,DAT_003fbdbc,global",
        "0x003fbd7c,j1939_broadcast_transmit_sessions[0].message_data_pointer,"
        "PTR_j1939_pgn65242_transmit_status_003fbd7c,global",
        "0x003fbdac,j1939_broadcast_transmit_sessions[1].transmit_frame_pointer,PTR_DAT_003fbdac,global",
        "0x003fbd94,j1939_broadcast_transmit_sessions[1].active,DAT_003fbd94,global"]
for name, off in offsets.items():
    a = 0x3fbd74 + off
    if name in ("active", "session_status_pointer", "transmit_frame_pointer", "message_data_pointer"):
        continue
    rows.append(f"0x{a:08x},j1939_broadcast_transmit_sessions[0].{name},DAT_{a:08x},global")
with open(map_path, "w") as fh:
    fh.write("\n".join(rows) + "\n")
print(f"{len(rows) - 1} map rows")

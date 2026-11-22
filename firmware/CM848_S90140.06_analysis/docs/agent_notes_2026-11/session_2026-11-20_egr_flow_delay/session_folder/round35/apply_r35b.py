"""Round 35 stage B (types): the J1939 transport receive session, boot and application twins.
- j1939_transport_receive_session_t (18 bytes, type-only template): both kernels' request to send / data packet
  handlers access the record through one base register at the same offsets and widths (+0 / +1 / +4 / +5 bytes,
  +2 / +6 / +0xc words, +8 / +0xe dwords).
- Instances: boot_j1939_transport_receive_session at 0x302925 (was qadc_a_pause_status + the j1939_tp_pause_t
  struct j1939_tp_pause_state at 0x302927 + flat qadc_a_* rows; its _pad2 word was the next packet number and the
  granted packet count) and j1939_transport_receive_session at 0x3fbdef (was the flat j1939_multiframe_rx_* rows).
- The old type j1939_tp_pause_t goes; the rows inside the instances become untyped dotted rows.
- Named first bytes of the two receive buffers (no array: the application's can be 1700 bytes and runs over the
  kernel image copy, including boot-called addresses).
- eeprom_block_tracking_t._pad2 is cm848_validateWriteAuth's failed write authorization count.
Writes the proof map. Idempotent.  usage: apply_r35b.py <repo> <map.csv>"""
import os
import sys

repo, map_path = os.path.abspath(sys.argv[1]), sys.argv[2]
out = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")
T = "j1939_transport_receive_session_t"
B, A = "boot_j1939_transport_receive_session", "j1939_transport_receive_session"
FIELDS = [  # (name, type, size, comment) - comma-free
    ("active", "byte", 1, "1 while a message is being received: the request to send handler sets it / the last data "
     "packet / an abort / the timeout clear it"),
    ("total_packet_count", "byte", 1, "the request to send's packet count (TP.CM byte 4)"),
    ("transported_pgn", "word", 2, "the transported PGN's PDU format byte in the high byte (TP.CM byte 7; only 0xef00 "
     "= PGN 61184 is accepted)"),
    ("next_packet_number", "byte", 1, "the sequence number the next data packet must carry: 1 at the request to send"),
    ("granted_packet_count", "byte", 1, "the packets left in the window this ECU's clear to send granted (at most 5 in "
     "the application)"),
    ("timeout_timer", "word", 2, "counted down while the session waits: 0x70 at the request to send"),
    ("request_to_send_can_id", "dword", 4, "the request to send's CAN identifier (its source address byte is "
     "matched against the data packets and aborts)"),
    ("message_size", "word", 2, "the message size in bytes (TP.CM bytes 2-3; the application takes at most 0x6a4)"),
    ("receive_buffer_pointer", "byte*", 4, "where the next packet's data goes: reset to the receive buffer (boot "
     "0x303075 / application 0x3fbe09) and advanced per byte"),
]
assert sum(f[2] for f in FIELDS) == 18
sd = os.path.join(out, "structure_definitions.csv")
lines = open(sd).read().split("\n")
lines = [l for l in lines if not l.startswith("j1939_tp_pause_t,")]
for i, l in enumerate(lines):
    if l.startswith("eeprom_block_tracking_t,0x003028a6,_pad2,byte,1,"):
        lines[i] = ("eeprom_block_tracking_t,0x003028a6,failed_write_authorization_count,byte,1,cm848_validateWriteAuth's "
                    "count of failed write authorizations: at 0x11 every check fails / a matching token resets it / a "
                    "mismatch adds 1 (was _pad2; PR #53 round 35),,verified")
if not any(l.startswith(T + ",") for l in lines):
    while lines and lines[-1] == "":
        lines.pop()
    lines.append(f"# {T}: one J1939 transport connection mode receive session (18 bytes; type-only template - the "
                 f"instances are {B} and {A} in global_variables.csv; PR #53 round 35)")
    for name, typ, size, comment in FIELDS:
        assert "," not in comment
        lines.append(f"{T},,{name},{typ},{size},{comment},,verified")
    lines.append("")
open(sd, "w").write("\n".join(lines))
offset, field_at = 0, {}
for name, typ, size, _ in FIELDS:
    field_at[offset] = name
    offset += size
INSIDE = {  # address: (old name, instance, field)
    "0x00302926": ("qadc_a_pause_ctrl", B, "total_packet_count"),
    "0x00302927": ("j1939_tp_pause_state", B, "transported_pgn"),
    "0x00302929": ("qadc_a_queue_intr", B, "next_packet_number"),
    "0x0030292a": ("qadc_a_ccw_idx", B, "granted_packet_count"),
    "0x0030292b": ("qadc_a_result_idx", B, "timeout_timer"),
    "0x0030292d": ("qadc_diag_service_request_buf", B, "request_to_send_can_id"),
    "0x00302930": ("qadc_a_paused_channel_id", B, "request_to_send_can_id"),
    "0x00302931": ("qadc_a_completion_flag", B, "message_size"),
    "0x00302933": ("qadc_a_queue_flags.rx_buf_ptr", B, "receive_buffer_pointer"),
    "0x003fbdf0": ("j1939_multiframe_rx_total_packets", A, "total_packet_count"),
    "0x003fbdf1": ("j1939_multiframe_rx_pgn", A, "transported_pgn"),
    "0x003fbdf3": ("j1939_multiframe_rx_next_sequence", A, "next_packet_number"),
    "0x003fbdf4": ("j1939_multiframe_rx_packets_in_window", A, "granted_packet_count"),
    "0x003fbdf5": ("j1939_multiframe_rx_timeout", A, "timeout_timer"),
    "0x003fbdf7": ("j1939_multiframe_rx_rts_can_header", A, "request_to_send_can_id"),
    "0x003fbdfb": ("j1939_multiframe_rx_total_bytes", A, "message_size"),
    "0x003fbdfd": ("j1939_multiframe_rx_data_buf_ptr", A, "receive_buffer_pointer"),
}
INSTANCES = {
    "0x00302925": ("qadc_a_pause_status", B, "the boot reflash kernel's J1939 transport receive session (PGN 61184 "
                   "messages from the service tool): the twin of " + A),
    "0x003fbdef": ("j1939_multiframe_rx_active", A, "the application J1939 transport's receive session (PGN 61184 "
                   "messages up to 1700 bytes: j1939_transport_handleRequestToSend / _handleDataPacket / "
                   "_timeout_decrement): the twin of " + B),
}
gp = os.path.join(out, "global_variables.csv")
g = open(gp).read().split("\n")
for i, l in enumerate(g):
    p = l.split(",", 3)
    if len(p) < 2:
        continue
    old_comment = p[3] if len(p) > 3 else ""
    note = f" | earlier note: {old_comment}" if old_comment else ""
    if p[0] in INSTANCES and p[1] == INSTANCES[p[0]][0]:
        old, name, comment = INSTANCES[p[0]]
        g[i] = f"{p[0]},{name},{T},{comment} (was {old}; PR #53 round 35){note}"
    elif p[0] in INSIDE and p[1] == INSIDE[p[0]][0]:
        old, inst, field = INSIDE[p[0]]
        extra = "byte 3: the source address " if p[0] == "0x00302930" else ""
        g[i] = f"{p[0]},{inst}.{field},,{extra}(was {old}; PR #53 round 35){note}"
NEW = [(0x303075, "boot_j1939_transport_receive_buffer", "byte",
        f"the first byte of the boot kernel's J1939 transport receive buffer ({B}.receive_buffer_pointer starts here; "
        f"PR #53 round 35)"),
       (0x3fbe09, "j1939_transport_receive_buffer", "byte",
        f"the first byte of the application's J1939 transport receive buffer (up to 1700 bytes: it runs over the "
        f"kernel image copy; {A}.receive_buffer_pointer starts here; PR #53 round 35)")]
for address, name, typ, comment in NEW:
    a = f"0x{address:08x}"
    if any(l.startswith(a + ",") for l in g):
        continue
    j = max(k for k, l in enumerate(g) if l.startswith("0x") and int(l[:10], 16) < address)
    g.insert(j + 1, f"{a},{name},{typ},{comment}")
open(gp, "w").write("\n".join(g))
rows = ["address,name,old_label,kind", ",failed_write_authorization_count,_pad2,field",
        f"0x00302925,{B}.active,qadc_a_pause_status,global", f"0x003fbdef,{A}.active,j1939_multiframe_rx_active,global",
        "0x00303075,boot_j1939_transport_receive_buffer,DAT_00303075,global",
        "0x003fbe09,j1939_transport_receive_buffer,DAT_003fbe09,global"]
for a, (old, inst, field) in INSIDE.items():
    rows.append(f"{a},{inst}.{field},{old},global")
with open(map_path, "w") as fh:
    fh.write("\n".join(rows) + "\n")
print(f"{len(rows) - 1} map rows")

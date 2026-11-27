"""Round 34 stage C (types): the application J1939 transport's connection mode (RTS / CTS) transmit session.
- The flat j1939_multiframe_tx_* rows from 0x3fbdc7 are the boot twin's 28-byte layout: an application instance
  j1939_transport_transmit_session of j1939_transport_transmit_session_t (marker row + typed row). The flag and
  destination bytes before it stay flat (j1939_multiframe_tx_active is shared with CM550), like the boot kernel's
  two bytes before boot_j1939_transport_transmit_session. Rows inside become untyped dotted rows; the unnamed
  0x3fbdcf pointer row goes. Its frame buffer 0x3fbde7 gets a row.
- The type's three pointer fields become byte* (they were dword, so every use printed a cast).
- Prototypes: initiateJ1939TransportProtocol(j1939_tx_msg_t *msg) and mpc555_sendJ1939SingleFrame(can_id,
  data_length, data, result).
Writes the proof map. Idempotent.
usage: apply_r34c.py <repo> <map.csv>"""
import os
import sys

repo, map_path = os.path.abspath(sys.argv[1]), sys.argv[2]
out = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")
T, S = "j1939_transport_transmit_session_t", "j1939_transport_transmit_session"
sd = os.path.join(out, "structure_definitions.csv")
lines = open(sd).read().split("\n")
for i, l in enumerate(lines):
    for field in ("message_data_pointer", "session_status_pointer", "transmit_frame_pointer"):
        prefix = f"{T},0x00302905,{field},dword,4,"
        if l.startswith(prefix):
            lines[i] = f"{T},0x00302905,{field},byte*,4," + l[len(prefix):]
marker = f"{T},0x003fbdc7,,,,the application transport's instance {S} (PR #53 round 34) - marker only,,verified"
if marker not in lines:
    j = max(k for k, l in enumerate(lines) if l.startswith(T + ","))
    lines.insert(j + 1, marker)
s = "\n".join(lines)
s = s.replace("j1939_multiframe_tx_status_ptr (0x12 started", f"{S}.session_status_pointer (0x12 started")
open(sd, "w").write(s)
FIELD_ROWS = {  # address: (old name, field)
    "0x003fbdc9": ("j1939_multiframe_tx_total_packets", "total_packet_count"),
    "0x003fbdca": ("j1939_multiframe_tx_cts_start_packet", "next_packet_number"),
    "0x003fbdcb": ("j1939_multiframe_tx_packets_remaining", "granted_packet_count"),
    "0x003fbdcc": ("j1939_multiframe_tx_send_result", "frame_queue_status"),
    "0x003fbdcd": ("j1939_multiframe_tx_total_bytes", "message_size"),
    "0x003fbdd3": ("j1939_multiframe_tx_status_ptr", "session_status_pointer"),
    "0x003fbdd7": ("j1939_multiframe_tx_cts_timeout", "timeout_timer"),
    "0x003fbdd9": ("j1939_multiframe_tx_can_header", "frame_can_id"),
    "0x003fbddd": ("j1939_multiframe_tx_frame_len", "frame_data_length"),
    "0x003fbddf": ("j1939_multiframe_tx_buf_ptr", "transmit_frame_pointer"),
}
gp = os.path.join(out, "global_variables.csv")
g = open(gp).read().split("\n")
keep = []
for l in g:
    p = l.split(",", 3)
    old = p[3] if len(p) > 3 else ""
    if l.startswith("0x003fbdc7,j1939_multiframe_tx_dest_addr_word,"):
        keep.append(f"0x003fbdc7,{S},{T},the application transport's connection mode (RTS / CTS) transmit session: "
                    f"the boot twin's layout (initiateJ1939TransportProtocol fills it / "
                    f"cm848_sendJ1939ConnectionModeDataPackets and the clear to send / end of message acknowledge / "
                    f"abort handlers run it); the active flag and destination address before it stay flat "
                    f"(j1939_multiframe_tx_active / j1939_multiframe_tx_destination_address) (was "
                    f"j1939_multiframe_tx_dest_addr_word and flat j1939_multiframe_tx_* rows; PR #53 round 34) | "
                    f"earlier note: {old}")
    elif p[0] in FIELD_ROWS and p[1] == FIELD_ROWS[p[0]][0]:
        keep.append(f"{p[0]},{S}.{FIELD_ROWS[p[0]][1]},,(was {p[1]}; PR #53 round 34) | earlier note: {old}")
    elif l.startswith("0x003fbdcf,,pointer"):
        continue  # the type-only data pointer row inside the instance: .message_data_pointer
    else:
        keep.append(l)
g = keep
NEW = (0x3fbde7, "j1939_transport_transmit_frame_buffer", "byte[8]",
       f"the frame assembly buffer of {S} (cm848_initializeJ1939Transport points its transmit_frame_pointer here; PR "
       f"#53 round 34)")
if not any(l.startswith("0x003fbde7,") for l in g):
    j = max(k for k, l in enumerate(g) if l.startswith("0x") and int(l[:10], 16) < NEW[0])
    g.insert(j + 1, f"0x{NEW[0]:08x},{NEW[1]},{NEW[2]},{NEW[3]}")
open(gp, "w").write("\n".join(g))
fd = os.path.join(out, "function_definitions.csv")
f = open(fd).read().rstrip("\n").split("\n")
if not any(l.startswith("0x0050c8ec,") for l in f):
    f.append("# The application J1939 transport's senders (PR #53 round 34)")
    f.append("0x0050c8ec,initiateJ1939TransportProtocol,0,msg,j1939_tx_msg_t*,the transmit descriptor of a message "
             "longer than 8 bytes (from sendJ1939Message)")
    f.append("0x00053858,mpc555_sendJ1939SingleFrame,0,can_id,dword,the 29-bit identifier (priority / PGN / source "
             "address)")
    f.append("0x00053858,mpc555_sendJ1939SingleFrame,1,data_length,dword,the data bytes (padded to 8 with 0xff)")
    f.append("0x00053858,mpc555_sendJ1939SingleFrame,2,data,byte*,the data")
    f.append("0x00053858,mpc555_sendJ1939SingleFrame,3,result,byte*,where the result goes: 0 queued / 1 zero length / "
             "4 CAN transmit queue full")
    open(fd, "w").write("\n".join(f) + "\n")
rows = ["address,name,old_label,kind",
        f"0x003fbdc7,{S}.transported_pgn,j1939_multiframe_tx_dest_addr_word,global",
        f"0x003fbdcf,{S}.message_data_pointer,PTR_DAT_003fbdcf,global",
        "0x003fbde7,j1939_transport_transmit_frame_buffer,DAT_003fbde7,global"]
for a, (old, field) in FIELD_ROWS.items():
    rows.append(f"{a},{S}.{field},{old},global")
with open(map_path, "w") as fh:
    fh.write("\n".join(rows) + "\n")
print(f"{len(rows) - 1} map rows")

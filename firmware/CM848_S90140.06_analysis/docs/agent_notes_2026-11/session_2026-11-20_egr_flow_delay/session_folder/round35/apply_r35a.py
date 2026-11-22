"""Round 35 stage A (labels): the boot kernel's J1939 transport transmit session bytes.
- 0x302903 / 0x302904 (qadc_a_queue_status_1 / qadc_a_active_channel_id) are the boot session's active flag and
  destination address: mpc555_sendJ1939TransportRequestToSend sets them, the clear to send / end of message
  acknowledge / abort handlers match and clear them (the twins of j1939_multiframe_tx_active /
  j1939_multiframe_tx_destination_address). No QADC code touches them.
- The eight stale name-only qadc_a_* rows inside boot_j1939_transport_transmit_session become dotted documentation
  rows of the fields at their offsets (they never render).
Writes the proof map. Idempotent.  usage: apply_r35a.py <repo> <map.csv>"""
import os
import sys

repo, map_path = os.path.abspath(sys.argv[1]), sys.argv[2]
out = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")
S = "boot_j1939_transport_transmit_session"
RENAMES = {
    "0x00302903": ("qadc_a_queue_status_1", "boot_j1939_transport_transmit_active",
                   "1 while the boot kernel's connection mode (RTS / CTS) transmit session runs: "
                   "mpc555_sendJ1939TransportRequestToSend sets it / the end of message acknowledge and abort "
                   "handlers and the data sender's timeout clear it (the twin of j1939_multiframe_tx_active)"),
    "0x00302904": ("qadc_a_active_channel_id", "boot_j1939_transport_transmit_destination_address",
                   "the session's destination address (the message identifier's PDU specific byte); the clear to "
                   "send / end of message acknowledge / abort handlers match replies against it (the twin of "
                   "j1939_multiframe_tx_destination_address)"),
}
INSIDE = {  # stale name-only rows inside the boot transmit session: address -> (old name, field)
    "0x00302907": ("qadc_a_queue_status_2", "total_packet_count"),
    "0x00302908": ("qadc_a_range_start", "next_packet_number"),
    "0x00302909": ("qadc_a_queue_ptr", "granted_packet_count"),
    "0x0030290a": ("qadc_a_queue_count_1", "frame_queue_status"),
    "0x0030290b": ("qadc_a_queue_count_2", "message_size"),
    "0x00302911": ("qadc_a_queue_ctrl_1", "session_status_pointer"),
    "0x00302915": ("qadc_a_queue_ctrl_2", "timeout_timer"),
    "0x0030291d": ("qadc_a_queue_ctrl_3", "transmit_frame_pointer"),
}
gp = os.path.join(out, "global_variables.csv")
g = open(gp).read().split("\n")
rows = ["address,name,old_label,kind"]
for i, l in enumerate(g):
    p = l.split(",", 3)
    if len(p) < 2:
        continue
    old_comment = p[3] if len(p) > 3 else ""
    note = f" | earlier note: {old_comment}" if old_comment else ""
    if p[0] in RENAMES and p[1] == RENAMES[p[0]][0]:
        old, new, comment = RENAMES[p[0]]
        g[i] = f"{p[0]},{new},{p[2]},{comment} (was {old}; PR #53 round 35){note}"
        rows.append(f"{p[0]},{new},{old},global")
    elif p[0] in INSIDE and p[1] == INSIDE[p[0]][0]:
        old, field = INSIDE[p[0]]
        g[i] = f"{p[0]},{S}.{field},,(was {old}: a stale flat row inside the struct; PR #53 round 35){note}"
open(gp, "w").write("\n".join(g))
with open(map_path, "w") as fh:
    fh.write("\n".join(rows) + "\n")
print(f"{len(rows) - 1} map rows")

"""Round 25 stage D (types): the boot reflash kernel's two diagnostic response messages. cm848_allocateDiagnosticResponse
Buffer (kernel 0x6508) returns 0x303056 for replies under 9 bytes, else 0x303047 while its status byte's high nibble is
0; callers use the result as a message header. Each record is 14 bytes - the header (CAN id + data length), a data
pointer and a pointer to the status byte right after the record (0x303064 / 0x303055; the J1939 transport writes 0x12
/ 6 through it) - so it is not a j1939_tx_msg_t, whose last field is a data end pointer. diag_buf_a_ctrl_t /
diag_buf_b_ctrl_t (at +4) were their last 10 bytes.
usage: apply_r25d.py <repo> <tokens.json>"""
import csv
import io
import json
import os
import sys

repo, tokens_out = os.path.abspath(sys.argv[1]), sys.argv[2]
out = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")
T = "diagnostic_response_message_t"


def write_csv_row(row):
    s = io.StringIO()
    csv.writer(s, lineterminator="").writerow(row)
    return s.getvalue()


sp = os.path.join(out, "structure_definitions.csv")
sd = open(sp).read().split("\n")
idx = [i for i, l in enumerate(sd) if l.startswith(("diag_buf_a_ctrl_t,", "diag_buf_b_ctrl_t,"))]
assert len(idx) == 6, len(idx)
rows = [write_csv_row([T, "", "header", "j1939_msg_hdr_t", "6", "CAN id and data length (the reply length the "
                       "allocator gets)", "j1939_msg_hdr_t", "verified"]),
        write_csv_row([T, "", "data_pointer", "pointer", "4", "The reply data", "", "verified"]),
        write_csv_row([T, "", "status_pointer", "pointer", "4", "Points at the status byte right after the record (the "
                       "J1939 transport writes 0x12 while it sends, 6 on a timeout); not a data end pointer", "",
                       "verified"])]
first = idx[0]
sd = [l for i, l in enumerate(sd) if i not in set(idx)]
sd[first:first] = rows
open(sp, "w").write("\n".join(sd))
gp = os.path.join(out, "global_variables.csv")
g = open(gp).read().split("\n")
DROP = {0x30304b, 0x30304d, 0x303051, 0x30305a, 0x30305c, 0x303060}
new_g, dropped, seen = [], 0, set()
MULTI = ("0x00303047,diagnostic_transport_response_message,diagnostic_response_message_t,The boot reflash kernel's "
         "multi-frame diagnostic response: cm848_allocateDiagnosticResponseBuffer returns it for replies of 9 bytes or "
         "more while the high nibble of diagnostic_transport_response_status is 0 (data at 0x30293f, sent through the "
         "J1939 transport) (PR #53 round 25)")
SINGLE = ("0x00303056,diagnostic_single_frame_response_message,diagnostic_response_message_t,The boot reflash kernel's "
          "single-frame diagnostic response: cm848_allocateDiagnosticResponseBuffer returns it for replies under 9 "
          "bytes (data at 0x303065) (PR #53 round 25)")
for line in g:
    if line.startswith("0x00303") and len(line) > 10:
        a = int(line[:10], 16)
        if a in DROP:
            dropped += 1
            continue
        if a == 0x303055:
            assert line.startswith("0x00303055,diag_buffer_b_status,byte,"), line
            new_g.append(MULTI)
            old = line.split(",", 3)[3]
            new_g.append("0x00303055,diagnostic_transport_response_status,byte,Status byte of "
                         "diagnostic_transport_response_message (its status_pointer points here): the allocator hands "
                         "the message out only while the high nibble is 0; the J1939 transport writes 0x12 / 6 "
                         "(was diag_buffer_b_status) (PR #53 round 25)" + (f" | earlier note: {old}" if old else ""))
            new_g.append(SINGLE)
            new_g.append("0x00303064,diagnostic_single_frame_response_status,byte,Status byte of "
                         "diagnostic_single_frame_response_message (its status_pointer points here) (PR #53 round 25)")
            seen.add(a)
            continue
    new_g.append(line)
assert dropped == 6 and seen == {0x303055}, (dropped, seen)
for a in ("0x00303047,", "0x00303056,", "0x00303064,"):
    assert sum(1 for l in new_g if l.startswith(a)) == 1, a
open(gp, "w").write("\n".join(new_g))
old_tok = {"diag_buf_a_ctrl_t_0030305a.data_ptr": "SINGLE_DATA", "diag_buf_a_ctrl_t_0030305a.service_count":
           "SINGLE_LENGTH", "diag_buf_a_ctrl_t_0030305a.end_ptr": "SINGLE_STATUS_POINTER",
           "diag_buf_b_ctrl_t_0030304b.data_ptr": "MULTI_DATA", "diag_buf_b_ctrl_t_0030304b.service_count":
           "MULTI_LENGTH", "diag_buf_b_ctrl_t_0030304b.end_ptr": "MULTI_STATUS_POINTER", "DAT_00303056": "SINGLE",
           "DAT_00303047": "MULTI", "diag_buffer_b_status": "MULTI_STATUS"}
new_tok = {"diagnostic_single_frame_response_message.data_pointer": "SINGLE_DATA",
           "diagnostic_single_frame_response_message.header.data_length": "SINGLE_LENGTH",
           "diagnostic_single_frame_response_message.status_pointer": "SINGLE_STATUS_POINTER",
           "diagnostic_transport_response_message.data_pointer": "MULTI_DATA",
           "diagnostic_transport_response_message.header.data_length": "MULTI_LENGTH",
           "diagnostic_transport_response_message.status_pointer": "MULTI_STATUS_POINTER",
           "diagnostic_single_frame_response_message": "SINGLE", "diagnostic_transport_response_message": "MULTI",
           "diagnostic_transport_response_status": "MULTI_STATUS"}
json.dump({"old": old_tok, "new": new_tok}, open(tokens_out, "w"), indent=1)
print("two response messages typed, 6 rows dropped, 3 rows added")

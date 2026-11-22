"""Round 35 stage C (prototypes): the boot kernel's message record senders and the diagnostic service chain.
- cm848_transmitCanMessage / mpc555_sendJ1939TransportRequestToSend take one diagnostic_response_message_t * (they
  read the data pointer and the status pointer behind the header: their old j1939_msg_hdr_t * + data / length rows
  made the callers pass a leftover r4 / an unset r5);
- mpc555_canTransmitQueuePush: the boot twin of mpc555_sendJ1939SingleFrame (can_id / data_length / data / result);
- cm848_j1939DiagnosticServiceHandler / j1939_diagServiceDispatch / cm848_sendJ1939ResponseFrame take the received
  message as a j1939_rx_msg_t * (each reads its +2 / +3 address bytes / +4 length / +6 data pointer).
Idempotent.  usage: apply_r35c.py <repo>"""
import os
import sys

repo = os.path.abspath(sys.argv[1])
fd = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output/function_definitions.csv")
lines = open(fd).read().rstrip("\n").split("\n")
DROP = ("0x00003f20,", "0x00005adc,")
keep = [l for l in lines if not l.startswith(DROP)]
NEW = [
    "# The boot kernel's message record senders and the diagnostic service chain (PR #53 round 35): the record "
    "senders read the data / status pointers behind the header",
    "0x00003f20,cm848_transmitCanMessage,0,message,diagnostic_response_message_t*,the response record from "
    "cm848_allocateDiagnosticResponseBuffer (header / data pointer / status pointer)",
    "0x00005adc,mpc555_sendJ1939TransportRequestToSend,0,message,diagnostic_response_message_t*,the response record "
    "of a reply longer than 8 bytes",
    "0x00003dac,mpc555_canTransmitQueuePush,0,can_id,dword,the 29-bit identifier",
    "0x00003dac,mpc555_canTransmitQueuePush,1,data_length,ushort,the data bytes",
    "0x00003dac,mpc555_canTransmitQueuePush,2,data,byte*,the data",
    "0x00003dac,mpc555_canTransmitQueuePush,3,result,byte*,where the result goes: 0 queued / 1 no data / 4 queue full",
    "0x00022128,cm848_j1939DiagnosticServiceHandler,0,rx_msg,j1939_rx_msg_t*,the received PGN 61184 request (a "
    "single frame / or the transport receive session's message view from its request_to_send_can_id)",
    "0x0050b634,j1939_diagServiceDispatch,0,rx_msg,j1939_rx_msg_t*,the received request",
    "0x000249c4,cm848_sendJ1939ResponseFrame,0,request,j1939_rx_msg_t*,the request being answered (its addresses "
    "swap into the reply)",
    "0x000249c4,cm848_sendJ1939ResponseFrame,1,result_code,dword,the service result: 0 success / 0xfe an extended "
    "response / else an error code",
]
if NEW[1] not in keep:
    keep += NEW
open(fd, "w").write("\n".join(keep) + "\n")
print(f"{len(lines) - (len(keep) - len(NEW))} rows dropped, {len(NEW) - 1} rows added")

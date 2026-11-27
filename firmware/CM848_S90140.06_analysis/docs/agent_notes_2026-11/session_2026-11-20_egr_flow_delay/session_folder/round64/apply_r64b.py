"""Round 64 stage B - the boot kernel's transmit records use j1939_tx_msg_t.
diagnostic_response_message_t is j1939_tx_msg_t field for field (header j1939_msg_hdr_t / data_pointer /
status_pointer, 14 bytes) and the boot kernel already takes the receive side as j1939_rx_msg_t: the type is merged
(its rows and the two stale "diagnostic buffer A / B" comment blocks around them go; its status note moves onto
j1939_tx_msg_t.status_pointer). The boot allocator cm848_allocateDiagnosticResponseBuffer gets the selector's full
prototype, and its two data buffers are named (the transport one is 1800 bytes to its record at 0x303047 - no thunks
in that RAM, so a real array).  Idempotent.  usage: apply_r64b.py <repo>"""
import os
import sys

O = os.path.join(os.path.abspath(sys.argv[1]), "firmware/CM848_S90140.06_analysis/output")
R = "PR #53 round 64"
sp = os.path.join(O, "structure_definitions.csv")
s = open(sp).read()
if "diagnostic_response_message_t,,header," not in s:
    print("already applied")
    sys.exit(0)
lines = s.split("\n")
first = lines.index("# Diagnostic buffer B control state @ 0x30304B") - 1
assert lines[first].startswith("# ====="), lines[first]
start_a = lines.index("# Diagnostic buffer A control state @ 0x30305A") - 1
end_a = start_a + 1
while not lines[end_a].startswith("# ====="):
    end_a += 1
assert lines[start_a].startswith("# =====") and end_a - start_a == 7, (start_a, end_a)
block = lines[first:end_a + 1]
type_rows = [l for l in block if l.startswith("diagnostic_response_message_t,")]
assert len(type_rows) == 3 and all(l.startswith(("#", "diagnostic_response_message_t,")) for l in block), block
note = ("# diagnostic_response_message_t - the boot kernel's twin of j1939_tx_msg_t field for field - was merged into "
        f"j1939_tx_msg_t in {R} with the old diagnostic buffer A / B notes about its two records "
        "(diagnostic_single_frame_response_message at 0x303056 and diagnostic_transport_response_message at 0x303047)")
assert "," not in note
lines[first:end_a + 1] = [note]
s = "\n".join(lines)
old = ("header is j1939_msg_hdr_t (the boot kernel's cm848_transmitCanMessage takes its whole twin record "
       "diagnostic_response_message_t since PR #53 round 35)")
assert s.count(old) == 1
s = s.replace(old, "header is j1939_msg_hdr_t (the boot kernel's records use it too - cm848_transmitCanMessage and "
                   "mpc555_sendJ1939TransportRequestToSend take it - since its twin diagnostic_response_message_t was "
                   f"merged in {R})")
old = "The boot twin is diagnostic_response_message_t.status_pointer,,verified"
assert s.count(old) == 1
s = s.replace(old, "In the boot kernel (whose records use this type since its twin diagnostic_response_message_t was "
                   f"merged in {R}) the transport writes 0x12 while it sends and 6 on a timeout,,verified")
open(sp, "w").write(s)

dp = os.path.join(O, "function_definitions.csv")
d = open(dp).read()
assert d.count(",diagnostic_response_message_t*,") == 2
d = d.replace(",diagnostic_response_message_t*,", ",j1939_tx_msg_t*,")
assert ",cm848_allocateDiagnosticResponseBuffer," not in d
d = d.rstrip("\n") + "\n" + "\n".join([
    f"0x00006508,cm848_allocateDiagnosticResponseBuffer,return,,j1939_tx_msg_t*,diagnostic_single_frame_response_message "
    f"or diagnostic_transport_response_message - 0 while the transport record is busy ({R})",
    f"0x00006508,cm848_allocateDiagnosticResponseBuffer,0,length,int32_t,The reply's data bytes: up to 8 takes the "
    f"single frame record ({R})"]) + "\n"
open(dp, "w").write(d)

gp = os.path.join(O, "global_variables.csv")
g = open(gp).read()
assert g.count(",diagnostic_response_message_t,") == 2
g = g.replace(",diagnostic_response_message_t,", ",j1939_tx_msg_t,")
lines = g.split("\n")
spans = [(0x30293f, 0x303046), (0x303065, 0x30306c)]
for l in lines:
    if l.startswith("0x"):
        a = int(l.split(",", 1)[0], 16)
        assert not any(lo <= a <= hi for lo, hi in spans), l[:60]
transport = (f"0x0030293f,diagnostic_transport_response_data,byte[1800],The data of diagnostic_transport_response_message "
             "(cm848_allocateDiagnosticResponseBuffer points its data_pointer here): 1800 bytes up to the record at "
             f"0x303047 - the size of the application's j1939_transport_tx_data ({R})")
single = (f"0x00303065,diagnostic_single_frame_response_data,byte[8],The data of "
          f"diagnostic_single_frame_response_message: one CAN frame ({R})")
i = next(n for n, l in enumerate(lines) if l.startswith("0x00303047,diagnostic_transport_response_message,"))
lines.insert(i, transport)
j = next(n for n, l in enumerate(lines) if l.startswith("0x00303064,diagnostic_single_frame_response_status,"))
lines.insert(j + 1, single)
open(gp, "w").write("\n".join(lines))
print("type merged / 3 rows + 2 comment blocks gone / 2 prototype rows retyped + 2 new / 2 globals retyped + 2 new")

"""Round 6 stage B2, after its first build: three fixes.
- The J1939_Block_Message bitfield rendered worse: the masked read-modify-writes (& 3 / & 5 / & 6 / | 4) showed as
  the raw piece _32_2_ beside .tsc1_engine_blocked = 1. Back to the word field, with the bits in its comment.
- The lookup's local is JVar1 now that it returns J1939_CONTROL_DEVICE (the wVar1 row no longer matched): name it
  control_device.
- cm848_trackJ1939ControlSessions keeps the previous engine control state in three etc1-named words; the data link
  copy also split a pointer local into word* and CONTROL_NETWORK*. Names and types for the three.
usage: apply_r6b2_fixes.py <CM848 output dir>"""
import csv
import io
import os
import sys

out = sys.argv[1]


def text_of(row):
    s = io.StringIO()
    csv.writer(s, lineterminator="").writerow(row)
    return s.getvalue()


# structure_definitions.csv: the three bitfield rows -> one word row
p = os.path.join(out, "structure_definitions.csv")
lines = open(p).read().split("\n")
idx = [i for i, l in enumerate(lines) if l.startswith("j1939_powertrain_control_state_t,0x0040adf8,") and
       next(csv.reader([l]))[2] in ("tsc1_engine_blocked", "tsc1_retarder_blocked", "etc1_high_idle_override_blocked")]
assert len(idx) == 3 and idx == list(range(idx[0], idx[0] + 3)), idx
word_row = ["j1939_powertrain_control_state_t", "0x0040adf8", "j1939_blocked_message_bits", "word", "2",
            "e2m 10E8 +24 J1939_Block_Message (HEX): 'Bit 0 TSC1 destination engine; Bit 1 TSC1 Destination retarder; "
            "Bit 2 ETC1'. The J1939 messages blocked after a time limit: bit 0 = TSC1 to the engine (the sender went "
            "into the ignored request list), bit 1 = TSC1 to the engine retarder, bit 2 = the ETC1 high idle override "
            "(in recovery: e2m Jcomm_Recovery_Time). processEngineTsc1Request clears bit 0 on override disabled; ETC1 "
            "SPN 606 = 00 and the high idle timeout clear bit 2. A word, not a bitfield: the code clears and sets the "
            "bits with masks, which Ghidra renders as a raw piece on a bitfield (was time_limited_node_status_bits, "
            "before that speed_control_target)", "", "verified"]
lines[idx[0]:idx[0] + 3] = [text_of(word_row)]
open(p, "w").write("\n".join(lines))
# global_variables.csv: the alias row back; the three session snapshots
p = os.path.join(out, "global_variables.csv")
text = open(p).read()
a = "0x0040ae18,j1939_powertrain_control_state.tsc1_engine_blocked,,"
assert text.count(a) == 1
text = text.replace(a, "0x0040ae18,j1939_powertrain_control_state.j1939_blocked_message_bits,,")
SNAP = {
    "0x003fbd6c": ("etc1_governor_mode_transition_snapshot", "j1939_monitor_engine_override_control_mode_previous",
                   "TSC1_OVERRIDE_MODE",
                   "cm848_trackJ1939ControlSessions' copy of j1939_powertrain_control_state.tsc1_override_control_mode "
                   "from its last pass: a change starts or ends a J1939 engine control session record"),
    "0x003fbd70": ("etc1_active_state_transition_snapshot", "j1939_monitor_engine_control_data_link_previous",
                   "CONTROL_NETWORK",
                   "cm848_trackJ1939ControlSessions' copy of j1939_powertrain_control_state.tsc1_controlling_data_link "
                   "from its last pass (1 = J1939: a session to close)"),
    "0x003fbd72": ("etc1_source_address_transition_snapshot",
                   "j1939_monitor_engine_controlling_source_address_previous", "byte",
                   "cm848_trackJ1939ControlSessions' copy of j1939_powertrain_control_state.tsc1_controlling_source_address "
                   "from its last pass: a new sender closes the session and opens another"),
}
out_lines = []
for line in text.split("\n"):
    a0 = line.split(",", 1)[0]
    if a0 in SNAP and line.startswith(a0 + "," + SNAP[a0][0] + ","):
        row = next(csv.reader([line]))
        old, new, typ, role = SNAP[a0]
        row[1], row[2] = new, typ
        row[3] = f"{role} (was {old}) | earlier note: {row[3]}"
        line = text_of(row)
        SNAP[a0] = None
    out_lines.append(line)
assert all(v is None for v in SNAP.values()), SNAP
open(p, "w").write("\n".join(out_lines))
# local_variables.csv: the lookup's local
p = os.path.join(out, "local_variables.csv")
text = open(p).read()
a = "0x00053a4c,cm848_lookupJ1939ControlDevice,wVar1,address_index,word,"
assert text.count(a) == 1
line = [l for l in text.split("\n") if l.startswith(a)][0]
text = text.replace(line, text_of(["0x00053a4c", "cm848_lookupJ1939ControlDevice", "JVar1", "control_device",
                                   "J1939_CONTROL_DEVICE", "the control device the source address maps to (was "
                                   "address_index on wVar1)"]))
open(p, "w").write(text)
print("fixed: the word field, the alias row, 3 snapshots, the lookup local")

"""Round 10 stage C (label-only), part 3: the rows apply_hand_worklist.py cannot take.
- 0x3fceee renders as _protection_coldStart_channelB_fault_reported_flag (its word row is narrower than the dword
  accesses; stage D widens it), so the quote picker finds no use: renamed here, with map rows for both spellings.
- logical_output_request_bits_16_to_23_t.reserved_bit_0 (output 16) -> transmission_relay_request (a field row; map
  kind 'field', so the proof replaces it only after '.').
usage: apply_r10c_extra.py <repo> <map.csv>"""
import os
import sys

repo, map_path = os.path.abspath(sys.argv[1]), sys.argv[2]
out = os.path.join(repo, "firmware", "CM848_S90140.06_analysis", "output")
gv = os.path.join(out, "global_variables.csv")
lines = open(gv).read().split("\n")
OLD, NEW = "protection_coldStart_channelB_fault_reported_flag", "governor_pressure_mid_range_check_fault_reported_flag"
i = next(k for k, l in enumerate(lines) if l.startswith("0x003fceee,"))
a, n, t, c = lines[i].split(",", 3)
assert n == OLD, n
role = ("1 once the P1756 mid-range check's failure was reported to the readiness words (diagnostic_monitor_complete_bits "
        "bit 28) - reported once; cm848_initializeGovernorPressureTrackingMonitor clears it. Accessed as a dword (lwz @ "
        "0x51b460, stw @ 0x51b4dc / 0x51aee8)")
lines[i] = ",".join([a, NEW, t, f"{role} (was {OLD}) | earlier note: {c}"])
open(gv, "w").write("\n".join(lines))
sd = os.path.join(out, "structure_definitions.csv")
text = open(sd).read()
prefix = "logical_output_request_bits_16_to_23_t,,reserved_bit_0,bitfield:1@0,1,\""
start = text.index(prefix)
end = text.index("\n", start)
assert text[start:end].endswith('",,verified'), text[start:end][-30:]
comment = ("output 16 = the transmission control relay (mask 1). cm848_mainLoopMonitor checks output 16 with "
           "diag_faultMatch_outputCheck_update(0x10,0x16,0x88,0x89,...): faults 136 / 137 = P0883 / P0882 'TCM power "
           "input signal high / low' (the relay output voltage), and fault 137 sets the e2m 8C19 bit "
           "RE_Trans_Relay_Circuit_Open ('transmission power relay is open-circuit'). cm848_updateTransmissionRelayRequest "
           "requests it (cm848_setLogicalOutputRequest(0x10,0)) only while the engine is not stopped and none of the "
           "relay / solenoid circuit limp bits is set. The solenoid diagnostics (the governor pressure solenoid read-back "
           "debounce in cm848_debounceOutputReadBackFaults, the output checks of outputs 17 / 18) and the governor "
           "pressure monitors run only while it is set (was reserved_bit_0) | earlier note: guess (not proven, so "
           "reserved): a transmission solenoid enable request; the old note said transmission relay")
assert '"' not in comment
new_row = f'logical_output_request_bits_16_to_23_t,,transmission_relay_request,bitfield:1@0,1,"{comment}",,verified'
text = text[:start] + new_row + text[end:]
open(sd, "w").write(text)
with open(map_path, "a") as f:
    f.write(f"0x003fceee,{NEW},{OLD},global\n")
    f.write(f"0x003fceee,_{NEW},_{OLD},global\n")
    f.write(f",transmission_relay_request,reserved_bit_0,field\n")
print("0x3fceee renamed; output 16 field renamed")

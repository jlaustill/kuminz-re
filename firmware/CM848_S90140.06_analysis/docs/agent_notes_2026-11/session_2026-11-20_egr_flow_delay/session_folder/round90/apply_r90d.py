"""Round 90 stage D (CM848): the DM8 (PGN 65232) payload and its builder's prototype (round 88's skeptic lead).
- j1939_pgn65232_payload (0x3fad6e, j1939_pgn65232_payload_t, 8 bytes = the descriptor's data_pointer target): SPN 1224
  test identifier / 1225 test type or component identifier / 1226 test value / 1227 test limit maximum / 1228 test
  limit minimum (J1939-73 DM8, bytes 1 / 2 / 3-4 / 5-6 / 7-8). It rendered DAT_003fad6e / DAT_003fad6f and three
  generic words (j1939_pgn65232_param_tx_word / _field1_init_word / _field2_init_word).
- cm848_sendPgn65232NonContinuousMonitorTestResultMessage (0x255c0) takes (byte test_identifier, ushort test_value):
  its rows said (byte dest_address, byte fault_count), against its own plate comment; the body stores the halfword
  (CONCAT11(in_register_00000012, fault_count)) and both callers pass word results cast to (byte).
Idempotent; keeps line endings. usage: apply_r90d.py <repo> <map.csv>"""
import os
import re
import sys

repo, map_out = os.path.abspath(sys.argv[1]), sys.argv[2]
O = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")
R = "PR #53 round 90"


def read(p):
    return open(p, newline="").read()


def write(p, t):
    open(p, "w", newline="").write(t)


S = os.path.join(O, "structure_definitions.csv")
s = read(S)
E = "\r\n" if "\r\n" in s else "\n"
if "j1939_pgn65232_payload_t," not in s:
    rows = [f"# DM8 (PGN 65232) payload: 8 bytes at 0x3fad6e (j1939_pgn65232_tx_message.data_pointer) ({R})",
            "j1939_pgn65232_payload_t,0x003fad6e,test_identifier,byte,1,SPN 1224 test identifier (byte 1): 0 = the intake "
            "air heater monitor / 1 = the misfire monitor (cm848_j1939HandlePgn58112Dm7),,verified",
            "j1939_pgn65232_payload_t,0x003fad6e,test_type_component_identifier,byte,1,SPN 1225 test type / component "
            "identifier (byte 2): 0xff (not available) - set once by cm848_initializePgn65232Dm8Buffer,,verified",
            "j1939_pgn65232_payload_t,0x003fad6e,test_value,word,2,SPN 1226 test value (bytes 3-4): the monitor result "
            "byte-swapped to J1939 little-endian order by cm848_reverseByteOrder16,,verified",
            "j1939_pgn65232_payload_t,0x003fad6e,test_limit_maximum,word,2,SPN 1227 test limit maximum (bytes 5-6): "
            "0xffff (not available),,verified",
            "j1939_pgn65232_payload_t,0x003fad6e,test_limit_minimum,word,2,SPN 1228 test limit minimum (bytes 7-8): "
            "0xffff (not available),,verified"]
    s = s.rstrip("\r\n") + E + E + E.join(rows) + E
    write(S, s)

G = os.path.join(O, "global_variables.csv")
lines = read(G).split("\n")
OLD = {0x3fad70: "j1939_pgn65232_param_tx_word", 0x3fad72: "j1939_pgn65232_field1_init_word",
       0x3fad74: "j1939_pgn65232_field2_init_word"}
ROW = ("0x003fad6e,j1939_pgn65232_payload,j1939_pgn65232_payload_t,the DM8 (PGN 65232 Test Results for Non-continuously "
       "Monitored Systems) payload: 8 bytes that cm848_sendPgn65232NonContinuousMonitorTestResultMessage fills and sends "
       "and cm848_initializePgn65232Dm8Buffer presets (were DAT_003fad6e / DAT_003fad6f; +2 was "
       "j1939_pgn65232_param_tx_word; +4 was j1939_pgn65232_field1_init_word; +6 was j1939_pgn65232_field2_init_word; "
       f"{R})")
if not any(l.startswith("0x003fad6e,") for l in lines):
    lines = [l for l in lines if not (l.startswith("0x") and int(l.split(",")[0], 16) in OLD)]
    after = [i for i, l in enumerate(lines) if l.startswith("0x") and int(l.split(",")[0], 16) < 0x3fad6e]
    lines.insert(after[-1] + 1, ROW)
    write(G, "\n".join(lines))

F = os.path.join(O, "function_definitions.csv")
f = read(F)
f2 = re.sub(r"^0x000255c0,cm848_sendPgn65232NonContinuousMonitorTestResultMessage,0,[^\r\n]*",
            "0x000255c0,cm848_sendPgn65232NonContinuousMonitorTestResultMessage,0,test_identifier,byte,"
            f"SPN 1224: 0 = the intake air heater monitor / 1 = the misfire monitor (was dest_address; {R})", f, flags=re.M)
f2 = re.sub(r"^0x000255c0,cm848_sendPgn65232NonContinuousMonitorTestResultMessage,1,[^\r\n]*",
            "0x000255c0,cm848_sendPgn65232NonContinuousMonitorTestResultMessage,1,test_value,ushort,"
            f"SPN 1226: the 16-bit monitor result (the body stores the halfword; was fault_count byte; {R})", f2, flags=re.M)
if f2 != f:
    write(F, f2)

P = os.path.join(O, "function_renames.csv")
p = read(P)
OLD_TEXT = ("param_1 is the test identifier (SPN 1224, byte 1: 0 = the intake air heater monitor, 1 = the misfire "
            "monitor) and param_2 the 16-bit test value (SPN 1226, byte swapped with cm848_reverseByteOrder16 into bytes "
            "3-4). The test type byte and the limit words keep their 0xff / 0xffff initial values (not available).")
NEW_TEXT = ("test_identifier is SPN 1224 (byte 1: 0 = the intake air heater monitor, 1 = the misfire monitor) and "
            "test_value the 16-bit SPN 1226 test value (byte swapped with cm848_reverseByteOrder16 into bytes 3-4 of "
            "j1939_pgn65232_payload). The test type byte and the limit words keep their 0xff / 0xffff initial values "
            f"(not available) ({R}: the parameters were dest_address / fault_count).")
if NEW_TEXT not in p:
    assert p.count(OLD_TEXT) == 1, p.count(OLD_TEXT)
    write(P, p.replace(OLD_TEXT, NEW_TEXT))
with open(map_out, "w") as fh:
    fh.write("address,name,old_label,kind,dims\n")
    fh.write("0x003fad70,j1939_pgn65232_payload.test_value,j1939_pgn65232_param_tx_word,symbol,1\n")
    fh.write("0x003fad72,j1939_pgn65232_payload.test_limit_maximum,j1939_pgn65232_field1_init_word,symbol,1\n")
    fh.write("0x003fad74,j1939_pgn65232_payload.test_limit_minimum,j1939_pgn65232_field2_init_word,symbol,1\n")
print("stage D applied")

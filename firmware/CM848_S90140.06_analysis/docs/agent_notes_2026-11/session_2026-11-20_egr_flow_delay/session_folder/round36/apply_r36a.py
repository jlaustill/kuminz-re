"""Round 36 stage A (types): two more J1939 transmit payloads as structs.
- j1939_pgn65263_payload_t (EFL/P1 Engine Fluid Level / Pressure 1, 8 bytes at 0x3fadd9) in the J1939-71 order: the
  builder writes bytes 1 / 4 / 7 (the existing rows), the initializer sets bytes 2 and 8 to 0xff and the word at
  bytes 5-6 to 0xffff - the one 2-byte field (SPN 101); byte 3 is never written. SPNs from the automotive table.
- j1939_pgn65504_payload_t (Proprietary B PGN 65504, 8 bytes at 0x3faeb0): cm848_j1939HandlePgn65504ProprietaryB
  stores the engine speed and the net output torque + 0x7d7f low byte first, then the main injection timing
  scrambled with a key from the time base (byte 7) into bytes 5 / 6 / 8.
Old rows become the instance rows / untyped dotted rows. Writes the proof map. Idempotent.
usage: apply_r36a.py <repo> <map.csv>"""
import os
import sys

repo, map_path = os.path.abspath(sys.argv[1]), sys.argv[2]
out = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")
STRUCTS = {
    "j1939_pgn65263_payload_t": ("j1939_pgn65263_payload", 0x3fadd9, "the J1939 EFL/P1 (PGN 65263) payload: 8 bytes", [
        ("fuel_delivery_pressure", "byte", 1, "SPN 94 engine fuel delivery pressure"),
        ("extended_crankcase_blow_by_pressure", "byte", 1, "SPN 22: 0xff (not available) from the initializer"),
        ("oil_level", "byte", 1, "SPN 98 engine oil level: never written in this firmware"),
        ("oil_pressure", "byte", 1, "SPN 100 engine oil pressure"),
        ("crankcase_pressure", "word", 2, "SPN 101 engine crankcase pressure: 0xffff (not available) from the "
         "initializer"),
        ("coolant_pressure", "byte", 1, "SPN 109 engine coolant pressure"),
        ("coolant_level", "byte", 1, "SPN 111: 0xff (not available) from the initializer"),
    ]),
    "j1939_pgn65504_payload_t": ("j1939_pgn65504_payload", 0x3faeb0, "the Proprietary B PGN 65504 payload: 8 bytes", [
        ("engine_speed", "word", 2, "engine_speed_state.filtered_engine_speed in J1939 byte order (0 with the engine "
         "stopped)"),
        ("engine_net_output_torque", "word", 2, "j1939_powertrain_control_state.engine_net_output_torque + 0x7d7f "
         "(125 % in 1/256 % units / rounded) in J1939 byte order"),
        ("scrambled_injection_timing_byte_1", "byte", 1, "bits 0x52 of the scrambled timing (timing value XOR the key) "
         "shifted right once / the other bits time base noise"),
        ("scrambled_injection_timing_byte_2", "byte", 1, "bits 0x41 of the scrambled timing / the rest time base "
         "noise"),
        ("scramble_key", "byte", 1, "the key: the time base (TBLr) >> 7. The timing value is (main_injection_timing + "
         "injection_timing_top_dead_center_offset) x 120 >> 10 + 125"),
        ("scrambled_injection_timing_byte_3", "byte", 1, "bits 0x1a of the scrambled timing shifted left 3 / the rest "
         "time base noise"),
    ]),
}
sd = os.path.join(out, "structure_definitions.csv")
lines = open(sd).read().split("\n")
for T, (inst, base, title, fields) in STRUCTS.items():
    assert sum(f[2] for f in fields) == 8
    if any(l.startswith(T + ",") for l in lines):
        continue
    while lines and lines[-1] == "":
        lines.pop()
    lines.append(f"# {T}: {title} (PR #53 round 36)")
    for name, typ, size, comment in fields:
        assert "," not in comment
        lines.append(f"{T},0x{base:08x},{name},{typ},{size},{comment},,verified")
    lines.append("")
open(sd, "w").write("\n".join(lines))
ROWS = {  # address: (old name, new name or dotted name, typed?)
    "0x003fadd9": ("j1939_eflp1_fuel_delivery_pressure", "j1939_pgn65263_payload", "j1939_pgn65263_payload_t"),
    "0x003faddc": ("j1939_eflp1_engine_oil_pressure", "j1939_pgn65263_payload.oil_pressure", ""),
    "0x003faddd": ("j1939_diag_response_word_b", "j1939_pgn65263_payload.crankcase_pressure", ""),
    "0x003faddf": ("j1939_eflp1_coolant_pressure", "j1939_pgn65263_payload.coolant_pressure", ""),
    "0x003faeb0": ("j1939_rpm_tx_word", "j1939_pgn65504_payload", "j1939_pgn65504_payload_t"),
    "0x003faeb1": ("j1939_rpm_tx_word+1", "j1939_pgn65504_payload.engine_speed", ""),
    "0x003faeb2": ("j1939_etc1_speed_offset_tx_word", "j1939_pgn65504_payload.engine_net_output_torque", ""),
    "0x003faeb3": ("j1939_etc1_speed_offset_tx_word+1", "j1939_pgn65504_payload.engine_net_output_torque", ""),
}
gp = os.path.join(out, "global_variables.csv")
g = open(gp).read().split("\n")
for i, l in enumerate(g):
    p = l.split(",", 3)
    if len(p) >= 2 and p[0] in ROWS and p[1] == ROWS[p[0]][0]:
        old, new, typ = ROWS[p[0]]
        note = f" | earlier note: {p[3]}" if len(p) > 3 and p[3] else ""
        what = "the payload instance" if typ else ("its high byte" if old.endswith("+1") else "a field")
        g[i] = f"{p[0]},{new},{typ},{what} (was {old}; PR #53 round 36){note}"
open(gp, "w").write("\n".join(g))
rows = ["address,name,old_label,kind"]
for T, (inst, base, title, fields) in STRUCTS.items():
    off = 0
    for name, typ, size, _ in fields:
        a = base + off
        old = next((v[0] for k, v in ROWS.items() if int(k, 16) == a), f"DAT_{a:08x}")
        rows.append(f"0x{a:08x},{inst}.{name},{old},global")
        off += size
with open(map_path, "w") as fh:
    fh.write("\n".join(rows) + "\n")
print(f"{len(rows) - 1} map rows")

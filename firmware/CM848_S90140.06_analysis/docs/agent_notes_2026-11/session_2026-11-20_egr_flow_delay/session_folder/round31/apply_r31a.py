"""Round 31 stage A (types): the J1939 EC1 (PGN 65251 Engine Configuration 1) payload as a struct.
j1939_pgn65251_payload_t, 28 bytes in the original J1939-71 layout (data length 0x1c), J1939 byte order (little
endian: buildPgn65251EngineConfiguration1Payload stores the low byte first). Two instances: the payload (0x3fa7f8)
and the send-on-change previous copy (0x3fa814). Field widths follow the code's accesses: words where it reads a
halfword (+0 / +6 / +9 / +12 / +17), byte pairs where it joins two bytes (+3 / +4, +15 / +16), bytes for the percent
torques and limits. Names from the SPNs (automotive j1939_spns). The per-field rows in global_variables.csv become
dotted documentation rows; the offset alias rows go. Idempotent.
usage: apply_r31a.py <repo>"""
import os
import sys

out = os.path.join(os.path.abspath(sys.argv[1]), "firmware/CM848_S90140.06_analysis/output")
T = "j1939_pgn65251_payload_t"
FIELDS = [  # (name, type, size, comment)
    ("engine_speed_at_idle_point_1", "word", 2, "SPN 188 engine speed at idle (point 1); J1939 byte order (low byte at "
     "+0): the send-on-change test reads it as one (byte-swapped) halfword"),
    ("percent_torque_at_idle_point_1", "byte", 1, "SPN 539 percent torque at idle (point 1); +125 offset"),
    ("engine_speed_at_point_2_low_byte", "byte", 1, "SPN 528 engine speed at point 2; low byte"),
    ("engine_speed_at_point_2_high_byte", "byte", 1, "SPN 528; high byte (the test joins the two bytes)"),
    ("percent_torque_at_point_2", "byte", 1, "SPN 540; +125 offset"),
    ("engine_speed_at_point_3", "word", 2, "SPN 529; J1939 byte order"),
    ("percent_torque_at_point_3", "byte", 1, "SPN 541; +125 offset"),
    ("engine_speed_at_point_4", "word", 2, "SPN 530; J1939 byte order; at +9 (the test reads it with an unaligned "
     "halfword)"),
    ("percent_torque_at_point_4", "byte", 1, "SPN 542; +125 offset"),
    ("engine_speed_at_point_5", "word", 2, "SPN 531; J1939 byte order"),
    ("percent_torque_at_point_5", "byte", 1, "SPN 543; +125 offset"),
    ("engine_speed_at_high_idle_point_6_low_byte", "byte", 1, "SPN 532 engine speed at high idle (point 6); low byte"),
    ("engine_speed_at_high_idle_point_6_high_byte", "byte", 1, "SPN 532; high byte"),
    ("endspeed_governor_gain", "word", 2, "SPN 545 gain (Kp) of the endspeed governor: 0xffff (not available); "
     "initializePgn65251EngineConfiguration1Buffer writes it"),
    ("reference_engine_torque", "word", 2, "SPN 544 reference engine torque; J1939 byte order"),
    ("maximum_momentary_override_speed_point_7", "word", 2, "SPN 533 maximum momentary engine override speed (point "
     "7); J1939 byte order"),
    ("maximum_momentary_override_time_limit", "byte", 1, "SPN 534 maximum momentary override time limit"),
    ("requested_speed_control_range_lower_limit", "byte", 1, "SPN 535 (10 rpm per bit)"),
    ("requested_speed_control_range_upper_limit", "byte", 1, "SPN 536 (10 rpm per bit)"),
    ("requested_torque_control_range_lower_limit", "byte", 1, "SPN 537; +125 offset (0x7d = 0 %)"),
    ("requested_torque_control_range_upper_limit", "byte", 1, "SPN 538; +125 offset"),
]
assert sum(f[2] for f in FIELDS) == 28
sd = os.path.join(out, "structure_definitions.csv")
lines = open(sd).read().split("\n")
if not any(l.startswith(T + ",") for l in lines):
    block = [f"# {T}: the J1939 EC1 (PGN 65251) payload, 28 bytes, J1939 byte order; two instances (PR #53 round 31)"]
    for name, typ, size, comment in FIELDS:
        assert "," not in comment
        block.append(f"{T},0x003fa7f8,{name},{typ},{size},{comment},,verified")
    block.append(f"{T},0x003fa814,,,,second instance (j1939_pgn65251_payload_previous) - marker only,,verified")
    while lines and lines[-1] == "":
        lines.pop()
    lines += block + [""]
    open(sd, "w").write("\n".join(lines))
gv = os.path.join(out, "global_variables.csv")
g = open(gv).read().split("\n")
offsets, o = {}, 0
for name, typ, size, comment in FIELDS:
    offsets[o] = name
    o += size
out_lines = []
for line in g:
    parts = line.split(",", 3)
    if len(parts) < 3 or not parts[0].startswith("0x"):
        out_lines.append(line)
        continue
    a = int(parts[0], 16)
    if not (0x3fa7f8 <= a < 0x3fa830):
        out_lines.append(line)
        continue
    base, inst = (0x3fa7f8, "j1939_pgn65251_payload") if a < 0x3fa814 else (0x3fa814, "j1939_pgn65251_payload_previous")
    comment = parts[3] if len(parts) > 3 else ""
    if a == base:
        out_lines.append(f"{parts[0]},{inst},{T},{comment} (typed {T}; PR #53 round 31)".replace(",,", ","))
        continue
    if "+" in parts[1] or not parts[1]:
        continue                                  # offset alias rows / type-only rows inside the struct go
    field = offsets.get(a - base)
    if field is None:                             # a row inside a multi-byte field: keep it as a note on its field
        field = max((k for k in offsets if k < a - base), default=0)
        field = offsets[field]
    note = f"(was {parts[1]}; PR #53 round 31)" + (f" | earlier note: {comment}" if comment else "")
    out_lines.append(f"{parts[0]},{inst}.{field},,{note}")
open(gv, "w").write("\n".join(out_lines))
print("EC1 struct applied")

"""Round 33 stage B (types): two J1939 transmit payloads as structs.
- j1939_pgn65249_payload_t (RC, PGN 65249 Retarder Configuration; 19 bytes at 0x3fae50, the J1939-71 layout and byte
  order: cm848_buildPgn65249RetarderConfigurationMessage stores each speed / torque low byte first, so byte fields);
- j1939_pgn65259_payload_t (CI, PGN 65259 Component Identification; 44 bytes at 0x3fab22: make[5] '*' model[17] '*'
  serial_number[8] '*' unit_number[10] '*', the lengths from cm848_j1939HandlePgn65259ComponentId's copies) and its
  status byte 0x3fab4e (j1939_pgn65259_transmit_status; rendered LAB_003fab4c_2). The struct covers the boot-called
  RAM copy of mpc555_can2TransmitInterruptHandler at 0x3fab3c, so the thunk stage keeps the struct and makes those
  boot calls call overrides;
- the two old payload rows become the instance row and a dotted documentation row; plates and the CLAUDE.md note.
Writes the proof map. Idempotent.
usage: apply_r33b.py <repo> <map.csv>"""
import os
import sys

repo, map_path = os.path.abspath(sys.argv[1]), sys.argv[2]
out = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")
RC, CI = "j1939_pgn65249_payload_t", "j1939_pgn65259_payload_t"
RC_FIELDS = [  # (name, size, comment) - comma-free (quote-aware parser)
    ("retarder_type_and_location", 1, "SPN 901 retarder type (bits 1-4) and SPN 902 retarder location (bits 5-8): "
     "0x14 = exhaust (4) at the engine exhaust brake (1) for one engine_retarder_output_driver_count / 3 = "
     "compression release (3) at the engine compression release brake (0) for two or more / 0xff = not available"),
    ("retarder_control_method", 1, "SPN 557 retarder control method: 0xff / 6 / 3 / 2 / 1 for "
     "engine_retarder_stage_1_weight 0 / 1 / 2 / 3 / 6 (6 divided by the weight); other weights leave it"),
    ("retarder_speed_at_idle_point_1_low_byte", 1, "SPN 546 retarder speed at idle (point 1); low byte"),
    ("retarder_speed_at_idle_point_1_high_byte", 1, "SPN 546; high byte"),
    ("percent_torque_at_idle_point_1", 1, "SPN 551; 125 minus the high byte of the ROM percent word"),
    ("maximum_retarder_speed_point_2_low_byte", 1, "SPN 548 maximum retarder speed (point 2); low byte"),
    ("maximum_retarder_speed_point_2_high_byte", 1, "SPN 548; high byte"),
    ("percent_torque_at_maximum_speed_point_2", 1, "SPN 552; 125 minus the percent"),
    ("retarder_speed_at_point_3_low_byte", 1, "SPN 549; low byte"),
    ("retarder_speed_at_point_3_high_byte", 1, "SPN 549; high byte"),
    ("percent_torque_at_point_3", 1, "SPN 553; 125 minus the percent"),
    ("retarder_speed_at_point_4_low_byte", 1, "SPN 550; low byte"),
    ("retarder_speed_at_point_4_high_byte", 1, "SPN 550; high byte"),
    ("percent_torque_at_point_4", 1, "SPN 554; 125 minus the percent"),
    ("retarder_speed_at_peak_torque_point_5_low_byte", 1, "SPN 547 retarder speed at peak torque (point 5); low "
     "byte"),
    ("retarder_speed_at_peak_torque_point_5_high_byte", 1, "SPN 547; high byte"),
    ("reference_retarder_torque_low_byte", 1, "SPN 556 reference retarder torque; low byte"),
    ("reference_retarder_torque_high_byte", 1, "SPN 556; high byte"),
    ("percent_torque_at_peak_torque_point_5", 1, "SPN 555; 125 minus the percent"),
]
CI_FIELDS = [
    ("make", 5, "SPN 586 make: characters 1-5 of the component identification string at 0x3fd653 in the EEPROM "
     "mirror (CMMNS in the RAM dump)"),
    ("make_delimiter", 1, "the '*' after the make"),
    ("model", 17, "SPN 587 model: characters 6-22 of the same string (the field order follows the J1939-71 "
     "sequence make / model / serial number / unit number; the databases give no positions)"),
    ("model_delimiter", 1, "the '*' after the model"),
    ("serial_number", 8, "SPN 588 serial number: cm848_formatNumberAsDecimalText writes 8 decimal digits of the "
     "number at 0x3fd66a"),
    ("serial_number_delimiter", 1, "the '*' after the serial number"),
    ("unit_number", 10, "SPN 233 unit number (power unit): 10 characters from 0x3fd743"),
    ("unit_number_delimiter", 1, "the '*' that ends the message (data length 44)"),
]
assert sum(s for _, s, _ in RC_FIELDS) == 19 and sum(s for _, s, _ in CI_FIELDS) == 44
sd = os.path.join(out, "structure_definitions.csv")
lines = open(sd).read().split("\n")
for T, base, fields, title in [(RC, 0x3fae50, RC_FIELDS, "the J1939 RC (PGN 65249) payload: 19 bytes in J1939 byte "
                                                        "order"),
                               (CI, 0x3fab22, CI_FIELDS, "the J1939 component identification (PGN 65259) payload: "
                                                         "44 bytes of '*'-delimited text")]:
    if any(l.startswith(T + ",") for l in lines):
        continue
    while lines and lines[-1] == "":
        lines.pop()
    lines.append(f"# {T}: {title} (PR #53 round 33)")
    for name, size, comment in fields:
        assert "," not in comment, comment
        lines.append(f"{T},0x{base:08x},{name},byte,{size},{comment},,verified")
    lines.append("")
open(sd, "w").write("\n".join(lines))
map_rows = ["address,name,old_label,kind"]
gp = os.path.join(out, "global_variables.csv")
g = open(gp).read().split("\n")
for i, l in enumerate(g):
    p = l.split(",", 3)
    old = p[3] if len(p) > 3 else ""
    if l.startswith("0x003fae50,j1939_pgn65249_payload_byte_1,"):
        g[i] = (f"0x003fae50,j1939_pgn65249_payload,{RC},the RC (PGN 65249) payload: 19 bytes built by "
                f"cm848_buildPgn65249RetarderConfigurationMessage (was j1939_pgn65249_payload_byte_1 and 18 flat "
                f"bytes; PR #53 round 33) | earlier note: {old}")
    elif l.startswith("0x003fae51,j1939_pgn65249_payload_byte_2,"):
        g[i] = (f"0x003fae51,j1939_pgn65249_payload.retarder_control_method,,(was j1939_pgn65249_payload_byte_2; PR "
                f"#53 round 33) | earlier note: {old}")
NEW = [(0x3fab22, "j1939_pgn65259_payload", CI,
        "the component identification (PGN 65259) payload: 44 bytes that cm848_j1939HandlePgn65259ComponentId fills "
        "and sends (were DAT_ / LAB_ labels; PR #53 round 33)"),
       (0x3fab4e, "j1939_pgn65259_transmit_status", "byte",
        "the status byte of j1939_pgn65259_tx_message (its status_pointer target): the send result or the transport "
        "session code (see j1939_tx_msg_t.status_pointer) (rendered LAB_003fab4c_2 inside a code unit; PR #53 round "
        "33)")]
for address, name, typ, comment in NEW:
    a = f"0x{address:08x}"
    if any(l.startswith(a + ",") for l in g):
        continue
    j = max(k for k, l in enumerate(g) if l.startswith("0x") and int(l[:10], 16) < address)
    g.insert(j + 1, f"{a},{name},{typ},{comment}")
open(gp, "w").write("\n".join(g))
map_rows.append("0x003fae50,j1939_pgn65249_payload.retarder_type_and_location,j1939_pgn65249_payload_byte_1,global")
map_rows.append("0x003fae51,j1939_pgn65249_payload.retarder_control_method,j1939_pgn65249_payload_byte_2,global")
for k, (name, _, _) in enumerate(RC_FIELDS[2:], start=2):
    map_rows.append(f"0x{0x3fae50 + k:08x},j1939_pgn65249_payload.{name},DAT_{0x3fae50 + k:08x},global")
offset = 0
for name, size, _ in CI_FIELDS:
    a = 0x3fab22 + offset
    label = {0x3fab42: "LAB_003fab40_2", 0x3fab43: "LAB_003fab40_3", 0x3fab4d: "LAB_003fab4c_1"}.get(a,
                                                                                                f"DAT_{a:08x}")
    map_rows.append(f"0x{a:08x},j1939_pgn65259_payload.{name},{label},global")
    offset += size
map_rows.append("0x003fab4e,j1939_pgn65259_transmit_status,LAB_003fab4c_2,global")
fp = os.path.join(out, "function_renames.csv")
f = open(fp).read()
for old, new in [
        ("the data pointer (j1939_pgn65249_payload_byte_1) and the status pointer",
         "the data pointer (j1939_pgn65249_payload) and the status pointer")]:
    if new not in f:
        assert f.count(old) == 1, old
        f = f.replace(old, new)
open(fp, "w").write(f)
cl = os.path.join(repo, "firmware/CLAUDE.md")
with open(cl, newline="") as fh:
    t = fh.read()
OLD = "(e.g. the PGN-65249 TX payload 0x3FAE51–0x3FAE62 must be an array, not 18 flat bytes)"
NEWT = ("(e.g. the PGN-65249 TX payload 0x3FAE50–0x3FAE62 is the struct `j1939_pgn65249_payload` since PR #53 round "
        "33, not 19 flat bytes)")
if NEWT not in t:
    assert t.count(OLD) == 1
    with open(cl, "w", newline="") as fh:
        fh.write(t.replace(OLD, NEWT))
with open(map_path, "w") as fh:
    fh.write("\n".join(map_rows) + "\n")
print(f"{len(map_rows) - 1} map rows")

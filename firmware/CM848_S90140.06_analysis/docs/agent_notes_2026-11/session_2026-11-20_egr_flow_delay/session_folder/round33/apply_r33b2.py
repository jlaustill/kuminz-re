"""Round 33 stage B, part 2 (types): the SOFT (PGN 65242 software identification) payload as a struct, the decimal
text formatter's prototype (its text buffer was an int, so a buffer inside a struct printed as a bare constant) and
the plates of the two text-payload initializers. Appends to the stage B map. Idempotent.
usage: apply_r33b2.py <repo> <map.csv>"""
import os
import sys

repo, map_path = os.path.abspath(sys.argv[1]), sys.argv[2]
out = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")
T, BASE = "j1939_pgn65242_payload_t", 0x3fae80
FIELDS = [  # (name, size, comment) - comma-free
    ("number_of_software_identification_fields", 1, "SPN 965: 6"),
    ("software_identification_field_1", 8, "8 decimal digits of the 4-byte number at 0x3fd69b (EEPROM 0x219) from "
     "cm848_formatNumberAsDecimalText"),
    ("software_identification_field_1_delimiter", 1, "'*'"),
    ("software_identification_field_2", 8, "8 decimal digits of the 4-byte number at 0x3fd69f (EEPROM 0x21d)"),
    ("software_identification_field_2_delimiter", 1, "'*'"),
    ("software_identification_field_3", 12, "characters 10-21 of the string at 0x3fd6a5 (EEPROM 0x22d-0x238)"),
    ("software_identification_field_3_delimiter", 1, "'*'"),
    ("calibration_version_number", 8, "application_overlay_core_software_version (e2m 0019) as two decimal digits "
     "per byte (11460600 for V11.46.06)"),
    ("calibration_version_number_delimiter", 1, "'*'"),
    ("ecm_identifier", 2, "the two ASCII characters of ecm_hardware_type_identifier_cal (e2m 0000 ECM_Identifier) "
     "high byte first"),
    ("ecm_identifier_delimiter", 1, "'*'"),
    ("application_identifier", 2, "the two ASCII characters of application_identifier_cal (e2m 1292) high byte "
     "first"),
    ("application_identifier_delimiter", 1, "the '*' that ends the message (data length 47)"),
]
assert sum(s for _, s, _ in FIELDS) == 47
sd = os.path.join(out, "structure_definitions.csv")
lines = open(sd).read().split("\n")
if not any(l.startswith(T + ",") for l in lines):
    while lines and lines[-1] == "":
        lines.pop()
    lines.append(f"# {T}: the J1939 software identification (PGN 65242) payload: 47 bytes - the field count and six "
                 f"'*'-ended fields (PR #53 round 33)")
    for name, size, comment in FIELDS:
        assert "," not in comment
        lines.append(f"{T},0x{BASE:08x},{name},byte,{size},{comment},,verified")
    lines.append("")
    open(sd, "w").write("\n".join(lines))
gp = os.path.join(out, "global_variables.csv")
g = open(gp).read().split("\n")
for i, l in enumerate(g):
    if l.startswith("0x003fae80,j1939_pgn65242_field_count_byte,"):
        old = l.split(",", 3)[3]
        g[i] = (f"0x003fae80,j1939_pgn65242_payload,{T},the software identification (PGN 65242) payload: 47 bytes "
                f"that cm848_initPgn65242SoftwareIdHandler builds once at boot (was j1939_pgn65242_field_count_byte "
                f"and DAT_ bytes; PR #53 round 33) | earlier note: {old}")
open(gp, "w").write("\n".join(g))
fd = os.path.join(out, "function_definitions.csv")
f = open(fd).read().rstrip("\n").split("\n")
if not any(l.startswith("0x00027bc4,") for l in f):
    f.append("# The decimal text formatter (PR #53 round 33): the text buffer was an int")
    f.append("0x00027bc4,cm848_formatNumberAsDecimalText,0,number,uint*,the number (4 bytes; in the digit count 1 "
             "mode its 4 bytes are formatted one by one)")
    f.append("0x00027bc4,cm848_formatNumberAsDecimalText,1,text,byte*,the text buffer; the digits are written "
             "backwards from text + digit_count - 1")
    f.append("0x00027bc4,cm848_formatNumberAsDecimalText,2,digit_count,int32_t,the digit count (the callers use 8); "
             "1 selects two digits per byte")
    open(fd, "w").write("\n".join(f) + "\n")
fp = os.path.join(out, "function_renames.csv")
r = open(fp).read().split("\n")
PLATES = {
    "0x00024940,cm848_initPgn65259ComponentIdHandler": (
        "Initializes the CI (PGN 65259 component identification) transmit descriptor: identifier 0xfeeb with the "
        "priority from j1939_pgn65259_priority_cal and the source address j1939_source_address / data length 44 / "
        "data pointer j1939_pgn65259_payload / status byte j1939_pgn65259_transmit_status. Then it registers "
        "cm848_j1939HandlePgn65259ComponentId, which fills the payload and sends it when PGN 65259 is requested"),
    "0x000268ac,cm848_initPgn65242SoftwareIdHandler": (
        "Initializes the SOFT (PGN 65242 software identification) transmit descriptor (identifier 0x18feda00 + "
        "j1939_source_address / data length 47 / data pointer j1939_pgn65242_payload / status byte "
        "j1939_pgn65242_transmit_status) and builds the payload once: the field count 6 and six '*'-ended fields "
        "(two 8-digit numbers from EEPROM 0x219 / 0x21d / 12 characters from EEPROM 0x22d / the calibration version "
        "/ the ECM identifier / the application identifier). Then it registers cm848_j1939HandlePgn65242SoftwareId, "
        "which only sends it when PGN 65242 is requested"),
}
for i, l in enumerate(r):
    if l in PLATES:
        r[i] = l + "," + PLATES[l] + " (PR #53 round 33)"
open(fp, "w").write("\n".join(r))
rows = ["0x003fae80,j1939_pgn65242_payload.number_of_software_identification_fields,j1939_pgn65242_field_count_byte,"
        "global"]
offset = 0
for name, size, _ in FIELDS:
    if offset:
        rows.append(f"0x{BASE + offset:08x},j1939_pgn65242_payload.{name},DAT_{BASE + offset:08x},global")
    offset += size
with open(map_path) as fh:
    have = fh.read()
with open(map_path, "a") as fh:
    for row in rows:
        if row not in have:
            fh.write(row + "\n")
print(f"{len(rows)} map rows")

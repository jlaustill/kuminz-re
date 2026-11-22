"""Round 24 stage E (types): the three 50-word fault bit arrays of the EEPROM mirror as one struct type.
- 0x3fe974 detected (e2m 1036 System_Error_Status_00..49), 0x3fe9d8 registered, 0x3fea3c previous pass: fault n is
  bit n % 16 of word n / 16 in each (the generic accessors index the words; cm848_initEepromDriverAndLoadMirror clears
  the same bit 100 bytes apart). Before: a 21-word struct system_status_flags_t over words 0-20 of the detected array
  plus flat word rows for the rest of all three.
- fault_bit_words_t: faults_0_to_15 .. faults_784_to_799; each field comment = the e2m status word, every bit's e2m
  name (block 1036, single-bit masks of the labelled 11.45 e2m) and its DTC (ROM 0x5985a slot -> obd_dtc_code_table),
  then the old comment as an earlier note.
- global_variables.csv: the three instance rows (fault_detected_cal / fault_registered_cal / fault_previous_pass_cal,
  EEPROM mirror -> _cal); every flat row and dotted alias row in the three arrays becomes a dotted documentation row
  '<instance>.faults_A_to_B' (no type, old comment + '(was <old name>)').
- structure_definitions.csv: the 21 system_status_flags_t rows -> 50 fault_bit_words_t rows at 0x3fe974 and two
  instance marker rows.
Writes the old -> new token map for the proof. usage: apply_r24e.py <repo> <fault_bit_names.json> <map.json>"""
import csv
import io
import json
import os
import re
import struct
import sys

repo, names_path, map_out = os.path.abspath(sys.argv[1]), sys.argv[2], sys.argv[3]
out = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")
rom = open(os.path.join(repo, "firmware/CM848_S90140.06_analysis/originals/cm848_rom.bin"), "rb").read()
slots = rom[0x5985a:0x5985a + 800]
dtc = struct.unpack(">170H", rom[0x5b57c:0x5b57c + 340])
bit_names = {int(w): {int(b): n for b, n in v.items()} for w, v in json.load(open(names_path)).items()}
BASES = {0x3fe974: "fault_detected_cal", 0x3fe9d8: "fault_registered_cal", 0x3fea3c: "fault_previous_pass_cal"}
WORDS = 50


def field(w):
    return f"faults_{16 * w}_to_{16 * w + 15}"


def where(a):
    for base, inst in BASES.items():
        if base <= a < base + 2 * WORDS:
            return base, inst, (a - base) // 2
    return None


def write_csv_row(row):
    s = io.StringIO()
    csv.writer(s, lineterminator="").writerow(row)
    return s.getvalue()


# --- the old struct's field comments (words 0-20 of the detected array) and the token map ----------------------
sd_path = os.path.join(out, "structure_definitions.csv")
sd = open(sd_path).read().split("\n")
old_fields, first = [], None
for i, line in enumerate(sd):
    if line.startswith("system_status_flags_t,"):
        row = next(csv.reader([line]))
        old_fields.append((row[2], row[5]))
        first = i if first is None else first
assert len(old_fields) == 21, len(old_fields)
tokens = {}     # old render token -> new render token
for w, (name, comment) in enumerate(old_fields):
    tokens[f"system_status_flags_t_003fe974.{name}"] = f"fault_detected_cal.{field(w)}"
old_comment_of = {w: c for w, (n, c) in enumerate(old_fields)}

# --- global_variables.csv ---------------------------------------------------------------------------------------
gv_path = os.path.join(out, "global_variables.csv")
gv = open(gv_path).read().split("\n")
new_gv, instance_done, converted = [], set(), 0
for line in gv:
    if not line.startswith("0x"):
        new_gv.append(line)
        continue
    a_str, name, typ, comment = (line.split(",", 3) + ["", "", ""])[:4]
    loc = where(int(a_str, 16))
    if loc is None:
        new_gv.append(line)
        continue
    base, inst, w = loc
    if int(a_str, 16) == base and "." not in name:
        new_gv.append(f"{a_str},{inst},fault_bit_words_t,"
                      + {0x3fe974: "Detected faults: e2m 1036 System_Error_Status_00..49 (50 words, fault n = bit n % 16 "
                                   "of word n / 16; the e2m names every bit). The monitors set and clear them; ",
                         0x3fe9d8: "Registered faults (the same 50-word bit layout; detected at 0x3fe974, previous pass "
                                   "at 0x3fea3c); ",
                         0x3fea3c: "Previous pass faults (the same 50-word bit layout; detected at 0x3fe974, registered at "
                                   "0x3fe9d8); "}[base]
                      + "EEPROM mirror (EEPROM 0x%x-0x%x, checksummed and written back) (PR #53 round 24)"
                      % (base - 0x3fd482, base - 0x3fd482 + 99)
                      + (f" (was {name})" if name else "") + (f" | earlier note: {comment}" if comment else ""))
        instance_done.add(base)
        if name and name not in ("fault_detected_cal",):
            tokens[name] = f"{inst}.{field(0)}" if base != 0x3fe974 else "fault_detected_cal"
        continue
    if int(a_str, 16) % 2:
        raise SystemExit(f"odd address inside a fault array: {line[:80]}")
    new_name = f"{inst}.{field(w)}"
    if "." not in name and name:
        tokens[name] = new_name
    if w < 21 and base == 0x3fe974 and "." not in name and name:
        raise SystemExit(f"flat row inside the old struct: {line[:80]}")
    keep = comment if comment else ""
    was = f" (was {name})" if name and "." not in name else ""
    new_gv.append(f"{a_str},{new_name},,{keep}{was}".rstrip(","))
    converted += 1
assert instance_done == set(BASES), instance_done
open(gv_path, "w").write("\n".join(new_gv))

# --- structure_definitions.csv ------------------------------------------------------------------------------------
flat_comment = {}
for line in gv:
    if line.startswith("0x"):
        a_str, name, typ, comment = (line.split(",", 3) + ["", "", ""])[:4]
        loc = where(int(a_str, 16))
        if loc and loc[0] == 0x3fe974 and "." not in name and name.startswith("fault_detected_bits_"):
            flat_comment[loc[2]] = comment
rows = []
for w in range(WORDS):
    parts = []
    for b in range(16):
        n = 16 * w + b
        s = slots[n]
        code = f"P{dtc[s]:04x}".upper().replace("P", "P", 1) if s < 170 else ""
        names = "/".join(bit_names.get(w, {}).get(b, []))
        if names or code:
            parts.append(f"b{b} {names}{' ' if names and code else ''}{code}")
    text = (f"Faults {16 * w}-{16 * w + 15}: e2m 1036 +{2 * w:02X} System_Error_Status_{w:02d}; "
            + ("; ".join(parts) if parts else "no named bit, no DTC slot"))
    old = old_comment_of.get(w) or flat_comment.get(w, "")
    if old:
        text += f" | earlier note: {old}"
    rows.append(write_csv_row(["fault_bit_words_t", "0x003fe974", field(w), "word", "2", text, "", "verified"]))
rows.append(write_csv_row(["fault_bit_words_t", "0x003fe9d8", "", "", "", "second instance (fault_registered_cal) - "
                           "marker only", "", "verified"]))
rows.append(write_csv_row(["fault_bit_words_t", "0x003fea3c", "", "", "", "third instance (fault_previous_pass_cal) - "
                           "marker only", "", "verified"]))
new_sd = [l for l in sd if not l.startswith("system_status_flags_t,")]
new_sd[first:first] = rows
open(sd_path, "w").write("\n".join(new_sd))
json.dump(tokens, open(map_out, "w"), indent=1)
print(f"{converted} rows -> dotted documentation rows; 50 fields + 2 markers; {len(tokens)} tokens in the map")

"""Round 6 stage B1: the three j1939_powertrain_control_state_t fields e2m 10E8 corrects, the e2m 10E8 citation on
every field it covers (the struct starts at 10E8 +4), and their dotted alias rows. Label-only.
usage: apply_r6b1_fields.py <repo> <map.csv> [--dry-run]"""
import csv
import io
import os
import re
import subprocess
import sys

repo, map_path = sys.argv[1:3]
repo = os.path.abspath(repo)  # the e2m lookup runs with cwd=firmware
dry = "--dry-run" in sys.argv
fw = os.path.join(repo, "firmware")
out = os.path.join(fw, "CM848_S90140.06_analysis", "output")
T = "j1939_powertrain_control_state_t"
I = "j1939_powertrain_control_state"
RENAMES = {
    "etc1_out_of_gear_latch": ("out_of_gear_network_type",
        "the network that set the out of gear flag (e2m: 0 = J1922, 1 = J1939); the ETC1 handler sets 1 with "
        "etc1_out_of_gear_flag (was etc1_out_of_gear_latch, before that etc1_speed_disable_latch)"),
    "time_limited_node_status_bits": ("j1939_blocked_message_bits",
        "the J1939 messages blocked after a time limit: bit 0 = TSC1 to the engine (the sender went into the ignored "
        "request list), bit 1 = TSC1 to the engine retarder, bit 2 = the ETC1 high idle override (in recovery: e2m "
        "Jcomm_Recovery_Time). processEngineTsc1Request clears bit 0 on override disabled; ETC1 SPN 606 = 00 and the "
        "high idle timeout clear bit 2 (was time_limited_node_status_bits, before that speed_control_target)"),
    "proprietary_offset_value": ("engine_net_output_torque",
        "the engine's net output torque in ft lb (e2m: actual - friction, signed); read by "
        "cm848_j1939HandlePgn65504ProprietaryB, cm848_checkAirHandlingSystemProtectionHighLoad and "
        "governor_speedRatio_etcFuelCorrection_calc (was proprietary_offset_value)"),
}
problems = []
# --- the e2m 10E8 records by offset -------------------------------------------------------------------------
e2m = subprocess.run([sys.executable, os.path.join(fw, "scripts", "e2m_block_addresses.py"), "10E8"], capture_output=True,
                     text=True, cwd=fw).stdout
records = {}
for line in e2m.splitlines():
    m = re.match(r"10E8 \+([0-9A-F]{4}) (\S+) \[([^\]]*)\] -> \S+ .*?; (.*)$", line)
    if m:
        records[int(m.group(1), 16)] = (m.group(2), m.group(3), m.group(4).strip())
print(f"{len(records)} 10E8 records")
# --- structure_definitions.csv: offsets of the struct's fields ------------------------------------------------
sd_path = os.path.join(out, "structure_definitions.csv")
lines = open(sd_path).read().split("\n")
offset, new_lines, cited, renamed = 0, [], 0, 0
for line in lines:
    if not line.startswith(T + ","):
        new_lines.append(line)
        continue
    row = next(csv.reader([line]))
    field, size = row[2], int(row[4])
    if field in RENAMES:
        row[2], row[5] = RENAMES[field]
        renamed += 1
    rec = records.get(offset + 4)
    if rec and size:
        name, unit, text = rec
        text = re.sub(r"^\[[A-Z0-9]+\] ", "", text).replace(",", ";")
        cite = f"e2m 10E8 +{offset + 4:X} {name} ({unit}): '{text}'. "
        if not row[5].startswith("e2m 10E8"):
            row[5] = cite + row[5]
            cited += 1
    s = io.StringIO()
    csv.writer(s, lineterminator="").writerow(row)
    new_lines.append(s.getvalue())
    offset += size
print(f"{renamed} fields renamed, {cited} e2m citations, struct size {offset}")
if renamed != len(RENAMES):
    problems.append("not every rename found")
cpp = open(os.path.join(out, "cm848_rom.ghidra.cpp")).read()
for old, (new, _) in RENAMES.items():
    if re.search(r"(?<![A-Za-z0-9_])" + re.escape(new) + r"(?![A-Za-z0-9_])", cpp):
        problems.append(f"{new} is taken")
if problems:
    print("\n".join("PROBLEM " + p for p in problems))
    sys.exit(1)
# --- the dotted alias rows ------------------------------------------------------------------------------------
gv_path = os.path.join(out, "global_variables.csv")
gv = open(gv_path).read()
aliases = 0
for old, (new, _) in RENAMES.items():
    pat = re.compile(r"(?m)^(0x[0-9a-f]+)," + re.escape(I) + r"\." + re.escape(old) + r"((?:\+\d+)?),")
    gv, n = pat.subn(lambda m: f"{m.group(1)},{I}.{new}{m.group(2)},", gv)
    aliases += n
print(f"{aliases} alias rows renamed")
if dry:
    sys.exit(0)
open(sd_path, "w").write("\n".join(new_lines))
open(gv_path, "w").write(gv)
with open(map_path, "a") as f:
    for old, (new, _) in RENAMES.items():
        f.write(f",{new},{old},field\n")
print("map rows appended")

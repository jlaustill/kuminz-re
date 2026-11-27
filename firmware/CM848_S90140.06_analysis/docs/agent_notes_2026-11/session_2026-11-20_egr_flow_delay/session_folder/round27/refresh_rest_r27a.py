"""Round 27 stage A: the references refresh_references.py does not reach (comment lines starting with '#',
structure_definitions.csv comments, living docs, a script docstring, work/todo.md): old -> new tokens from the map,
plus the compound spellings, and the stale '#' note block of function_renames.csv rewritten.
usage: refresh_rest_r27a.py <repo> <map.csv>"""
import csv
import os
import re
import sys

repo, map_path = os.path.abspath(sys.argv[1]), sys.argv[2]
out = "firmware/CM848_S90140.06_analysis/output"
tokens = {r["old_label"]: r["name"] for r in csv.DictReader(open(map_path)) if r["kind"] != "local"}
COMPOUND = {
    "sensorChannelTypeB_configInit/_update": "cm848_processUnsignedSensorChannel / cm848_initializeUnsignedSensorChannel",
    "sensorChannelTypeB_*": "cm848_processUnsignedSensorChannel / cm848_initializeUnsignedSensorChannel",
    "cm848_sensorChannel10_intakeManifoldTemperatureInit/Process":
        "cm848_processIntakeManifoldTemperatureChannel / cm848_initializeIntakeManifoldTemperatureChannel",
    "updateSensorChannelTypeB": "cm848_initializeUnsignedSensorChannel",
    "boot-time twin of configInit": "boot-time twin of the periodic pass",
}
NOTE_BLOCK = {  # function_renames.csv '#' lines that named the wrong channels
    "# Sensor channel 0 (coolant load) - calls sensorChannelConfigInit":
        "# Sensor channel wrappers (PR #53 round 27): cm848_process<Channel>Channel runs a channel every pass and "
        "cm848_initialize<Channel>Channel once at boot; the older notes here named the wrong channels",
    "# Sensor channel 0 - calls updateSensorChannelWithConfig": None,
    "# Sensor channel 1 (coolant sensor) - calls sensorChannelConfigInit": None,
    "# Sensor channel 1 - calls updateSensorChannelWithConfig": None,
    "# Sensor channel utility functions - Type A (gain/offset config)":
        "# Signed sensor channels (lookup flags 2): cm848_processSignedSensorChannel / cm848_initializeSignedSensorChannel",
    "# Sensor channel calibration - calls sensorChannelConfigInit": None,
    "# Sensor channel calibration - calls updateSensorChannelWithConfig": None,
    "# Sensor channel utility functions - Type B (extended filtering, 27/29 calls - most-used)":
        "# Unsigned sensor channels (lookup flags 0): cm848_processUnsignedSensorChannel / "
        "cm848_initializeUnsignedSensorChannel",
    "# Wrapper: calls updateSensorChannelTypeB for sensor 0x1d (29)": None,
    "# Calls sensorChannelTypeB_configInit for crankshaft": None,
    "# Calls updateSensorChannelTypeB for crankshaft": None,
    "# Calls sensorChannelConfigInit for aux channel 103": None,
    "# Calls updateSensorChannelWithConfig for aux channel 103": None,
}
word = re.compile(r"(?<![A-Za-z0-9_])(" + "|".join(sorted(map(re.escape, tokens), key=len, reverse=True)) +
                  r")(?![A-Za-z0-9_])")


def refresh(s):
    for old, new in COMPOUND.items():
        s = s.replace(old, new)
    return word.sub(lambda m: tokens[m.group(1)], s)


changed = {}
# '#' lines only
for rel in (f"{out}/function_renames.csv", f"{out}/local_variables.csv", f"{out}/function_definitions.csv"):
    lines = open(os.path.join(repo, rel)).read().split("\n")
    new_lines = []
    for line in lines:
        if line in NOTE_BLOCK and rel.endswith("function_renames.csv"):
            if NOTE_BLOCK[line] is not None:
                new_lines.append(NOTE_BLOCK[line])
            continue
        new_lines.append(refresh(line) if line.startswith("#") else line)
    if new_lines != lines:
        changed[rel] = sum(1 for a, b in zip(lines, new_lines) if a != b) + abs(len(lines) - len(new_lines))
        open(os.path.join(repo, rel), "w").write("\n".join(new_lines))
# structure_definitions.csv: the comment column (column 6); quote-aware file, so replace inside the line text
rel = f"{out}/structure_definitions.csv"
text = open(os.path.join(repo, rel)).read()
lines = text.split("\n")
new_lines = []
for line in lines:
    if line.startswith("#"):
        new_lines.append(refresh(line))
        continue
    parts = line.split(",", 5)
    if len(parts) == 6:
        new_lines.append(",".join(parts[:5]) + "," + refresh(parts[5]))
    else:
        new_lines.append(line)
if new_lines != lines:
    changed[rel] = sum(1 for a, b in zip(lines, new_lines) if a != b)
    open(os.path.join(repo, rel), "w").write("\n".join(new_lines))
for rel in ("firmware/CM848_S90140.06_analysis/docs/tuning_parameters.md",
            "firmware/CM848_S90140.06_analysis/docs/service_0x4a_protocol.md",
            "firmware/CM848_S90140.06_analysis/docs/ecu_pinout.md",
            "firmware/CM848_S90140.06_analysis/scripts/extract_flash2.py", "work/todo.md"):
    t = open(os.path.join(repo, rel), newline="").read()      # newline="": keep CRLF files CRLF
    n = refresh(t)
    if n != t:
        changed[rel] = sum(1 for a, b in zip(t.split("\n"), n.split("\n")) if a != b)
        open(os.path.join(repo, rel), "w", newline="").write(n)
for rel, k in changed.items():
    print(f"{rel}: {k} lines")

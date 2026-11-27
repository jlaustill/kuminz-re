"""Round 30: functions that set fault bits (named bitfield stores 'x.<bit> = 1' and word-piece sets 'x._<2w>_2_ = ... |
mask', mapped to the bit names) whose own name shares no content word with any of those bits' names: candidates for
a misnamed function (or a misnamed bit). Prints function, address, the bits it sets.
usage: setter_name_scan.py <cpp> <structure_definitions.csv>"""
import csv
import re
import sys
from collections import defaultdict

cpp, sd = sys.argv[1:3]
bit_name = {}
for row in csv.reader(open(sd, newline="")):
    if len(row) > 3 and row[0] == "fault_bit_words_t" and row[3].startswith("bitfield:"):
        pass
# rebuild fault -> name from the struct rows in order (words 1-49 bitfields; word 0 is a plain word)
fault = 16
for row in csv.reader(open(sd, newline="")):
    if len(row) > 3 and row[0] == "fault_bit_words_t" and row[3].startswith("bitfield:1@"):
        k = int(row[3].split("@")[1])
        if k == 0 and fault % 16:
            raise SystemExit("bit order")
        bit_name[fault] = row[2]
        fault += 1
STOP = {"error", "fault", "high", "low", "control", "driver", "check", "sensor", "the", "of", "in", "to", "and",
        "range", "cm848", "mpc555", "hpcr", "monitor", "update", "process", "calculate", "detect", "run", "set",
        "clear", "check", "diagnose", "handle", "state", "flag", "value", "rationality", "performance", "circuit",
        "a", "b", "1", "2", "3", "4", "5", "6"}


def words(name):
    parts = re.sub(r"([a-z0-9])([A-Z])", r"\1_\2", name).lower().split("_")
    return {p for p in parts if p and p not in STOP and not p.isdigit()}


text = open(cpp, errors="replace").read()
marks = list(re.finditer(r"^// Function: (\S+) @ (0x[0-9a-f]+)", text, re.M))
for i, m in enumerate(marks):
    body = text[m.end(): marks[i + 1].start() if i + 1 < len(marks) else len(text)]
    body = re.sub(r"/\*.*?\*/", "", body, flags=re.S)
    flat = re.sub(r"\s+", " ", body)
    sets = set()
    for s in re.finditer(r"fault_detected_cal\.([a-z][a-z0-9_]*) = 1\b", flat):
        if s.group(1) in bit_name.values():
            sets.add(s.group(1))
    for s in re.finditer(r"fault_detected_cal\._(\d+)_2_ = fault_detected_cal\._\1_2_ \| (0x[0-9a-f]+|\d+)", flat):
        w, mask = int(s.group(1)) // 2, int(s.group(2), 0)
        for b in range(16):
            if mask >> b & 1 and 16 * w + b in bit_name:
                sets.add(bit_name[16 * w + b])
    sets = {s for s in sets if not re.fullmatch(r"fault_\d+", s)}
    if not sets:
        continue
    fw = words(m.group(1))
    if not any(fw & words(s) for s in sets):
        print(f"{m.group(1)} {m.group(2)}: sets {', '.join(sorted(sets))}")

"""Round 27: for every fault bit, the functions that SET it with a constant mask
(fault_detected_cal.faults_A_to_B = ... | mask) - the round 10 fault_setters.py for the round 24 struct form.
usage: fault_setters_r27.py <cpp> <faults...>   (no faults: all)"""
import re
import sys
from collections import defaultdict

text = open(sys.argv[1], errors="replace").read()
want = {int(x) for x in sys.argv[2:]}
marks = list(re.finditer(r"^// Function: (\S+) @ 0x([0-9a-fA-F]+)", text, re.M))
SET = re.compile(r"fault_detected_cal\.faults_(\d+)_to_\d+\s*=\s*[^;]*?\|\s*(0x[0-9a-fA-F]+|\d+)\s*;")
setters = defaultdict(set)
for i, m in enumerate(marks):
    body = text[m.end(): marks[i + 1].start() if i + 1 < len(marks) else len(text)]
    body = re.sub(r"/\*.*?\*/", "", body, flags=re.S)
    for s in SET.finditer(body):
        first, mask = int(s.group(1)), int(s.group(2), 0)
        for b in range(16):
            if mask >> b & 1:
                setters[first + b].add(m.group(1))
for f in sorted(setters):
    if not want or f in want:
        print(f, " ".join(sorted(setters[f])))

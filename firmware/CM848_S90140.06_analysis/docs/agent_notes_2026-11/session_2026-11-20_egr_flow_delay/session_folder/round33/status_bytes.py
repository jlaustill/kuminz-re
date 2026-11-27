"""Round 33: every J1939 transmit descriptor's status byte (the j1939_tx_msg_t third field, set by the descriptor's
initializer: '<msg>.data_end_pointer = &<label>;'), with the descriptor's data pointer / length, the status label's
CSV row (if any) and every function that uses the label outside the initializer.
usage: status_bytes.py <cpp> <global_variables.csv>"""
import re
import sys

cpp = open(sys.argv[1], errors="replace").read().split("\n")
rows = {}
for l in open(sys.argv[2], errors="replace"):
    p = l.rstrip("\n").split(",", 3)
    if len(p) >= 3 and p[0].startswith("0x"):
        rows[p[1]] = (p[0], p[2])
func_of = []
cur = None
for l in cpp:
    m = re.match(r"^// Function: (\S+) @", l)
    if m:
        cur = m.group(1)
    func_of.append(cur)
found = []
for i, l in enumerate(cpp):
    m = re.search(r"(\w+)\.data_end_pointer = &?([\w]+);", l)
    if m:
        found.append((m.group(1), m.group(2), func_of[i], i + 1))
for msg, label, init_function, line in found:
    users = {}
    pat = re.compile(r"(?<![\w.])" + re.escape(label) + r"(?!\w)")
    for i, l in enumerate(cpp):
        if pat.search(l) and func_of[i] != init_function:
            users[func_of[i]] = users.get(func_of[i], 0) + 1
    row = rows.get(label, ("", ""))
    print(f"{msg:40s} {label:34s} row={row[0]}:{row[1]:10s} init={init_function} users={users}")

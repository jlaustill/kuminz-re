"""List the SCI command 0x13 (19) output test codes of cm848_sciCommand19OutputTestCallback with the outputs each starts.
usage: sci_test_codes.py <cpp>"""
import re
import sys

text = open(sys.argv[1]).read()
s = text.index("void cm848_sciCommand19OutputTestCallback(void)")
e = text.index("\n}\n", s)
body = text[s:e]
ESC = {"\\t": 9, "\\n": 10, "\\v": 11, "\\f": 12, "\\r": 13, '\\"': 34, "\\'": 39}


def code(label):
    label = label[1:-1]
    if label in ESC:
        return ESC[label]
    if label.startswith("\\x"):
        return int(label[2:], 16)
    return ord(label[-1]) if label.startswith("\\") else ord(label)


parts = re.split(r"\n  case ('(?:\\.|[^'])+?'|\d+):", body)
for i in range(1, len(parts), 2):
    c = code(parts[i]) if parts[i].startswith("'") else int(parts[i])
    chunk = parts[i + 1].split("goto LAB_0051ee98")[0]
    tests = re.findall(r"cm848_sciStartTimedOutputTest\(&(\w+),(0x[0-9a-f]+|\d+),(0x[0-9a-f]+|\d+)\)", chunk)
    special = re.findall(r"(cold_start_\w+_countdown) = 0xb", chunk)
    if tests or special:
        print(f"0x{c:02x}", [(t, int(o, 0), int(d, 0)) for t, o, d in tests], special)

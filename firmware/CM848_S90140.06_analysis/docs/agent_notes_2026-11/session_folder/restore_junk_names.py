"""Undo the apply bug: restore auto-label names (from HEAD) on rows the follow-up did not plan to change."""
import sys

current_path, head_path, renames_log, coef_log = sys.argv[1], sys.argv[2], sys.argv[3], sys.argv[4]


def rows(path):
    out = {}
    for line in open(path):
        p = line.rstrip("\n").split(",", 3)
        if p[0].startswith("0x"):
            out.setdefault(int(p[0], 16), p)
    return out


head = rows(head_path)
intended_old_names = {l.split(",", 1)[0] for l in open(renames_log) if l.strip()}
intended_addresses = {int(a, 16) for a in open(coef_log).read().split() if a.startswith("0x")}
intended_addresses |= {0x000592a2, 0x003fefba}
lines = open(current_path).read().split("\n")
restored = []
for i, line in enumerate(lines):
    p = line.split(",", 3)
    if not p[0].startswith("0x"):
        continue
    a = int(p[0], 16)
    h = head.get(a)
    if not h or p[1] or not h[1]:
        continue                                   # still named, or had no name before
    if h[1] in intended_old_names or a in intended_addresses:
        continue                                   # a planned change
    p[1] = h[1]
    lines[i] = ",".join(p)
    restored.append(h[1])
open(current_path, "w").write("\n".join(lines))
print("restored", len(restored), "names; e.g.", restored[:8])

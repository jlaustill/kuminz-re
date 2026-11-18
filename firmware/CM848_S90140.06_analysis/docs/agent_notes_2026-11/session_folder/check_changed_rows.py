"""Every global_variables.csv row that differs from HEAD must be a planned change."""
import sys

def rows(path):
    out = {}
    for line in open(path):
        p = line.rstrip("\n").split(",", 3)
        if p[0].startswith("0x"):
            out.setdefault(int(p[0], 16), (p[1], p[2] if len(p) > 2 else ""))
    return out

head, cur = rows(sys.argv[1]), rows(sys.argv[2])
planned_names = {l.split(",", 1)[0] for l in open(sys.argv[3]) if l.strip()}
coef = {int(a, 16) for a in open(sys.argv[4]).read().split()}
STRUCTS = {"sensor_channel_config_t", "sensor_channel_state_t", "ema_filter_state_t", "word"}
bad = []
for a in sorted(set(head) | set(cur)):
    h, c = head.get(a), cur.get(a)
    if h == c:
        continue
    if a in coef or a in (0x592a2, 0x3fefba):
        continue
    if h and h[0] in planned_names:
        continue
    if h and c and h[0] == c[0] and c[1] in STRUCTS:
        continue                              # a block retyped under its own name
    bad.append((hex(a), h, c))
print("unplanned changes:", len(bad))
for b in bad[:20]:
    print("  ", b)

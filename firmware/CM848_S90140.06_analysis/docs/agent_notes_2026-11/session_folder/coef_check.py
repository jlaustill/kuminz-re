"""Filter coefficient targets: gap to the next row, overlap with typed extents, direct uses."""
import re
import sys

sys.path.insert(0, sys.argv[1])
import lookup_tables as L
import disasm_func as D

state = L.CsvState.load()
text = open(D.CPP).read()
targets = [l.strip() for l in open(sys.argv[2]) if l.strip()]
typed = []                                    # (start, end, name) of arrays / structs in global_variables.csv
SIZE = {"sensor_channel_config_t": 16, "sensor_channel_state_t": 12, "ema_filter_state_t": 8}
for a, (n, t, _) in state.rows.items():
    m = re.fullmatch(r"(word|byte|dword)\[(\d+)\]", t)
    if m:
        typed.append((a, a + {"byte": 1, "word": 2, "dword": 4}[m.group(1)] * int(m.group(2)), n or t))
    elif t in SIZE:
        typed.append((a, a + SIZE[t], n or t))
for name in targets:
    a = state.addresses[name][0] if name in state.addresses else int(name[-8:], 16)
    inside = state.rows_inside(a, a + 2)
    covering = [n for s, e, n in typed if s <= a < e or s < a + 2 <= e and s != a]
    uses = len(re.findall(r"(?<![A-Za-z0-9_])" + re.escape(name) + r"(?![A-Za-z0-9_])", text))
    row = state.rows.get(a, ("", "", ""))
    print(f"0x{a:08x} {name:34s} type={row[1] or '-':6s} uses={uses:2d} inside={[state.rows[b][0] for b in inside]} covered_by={covering}")

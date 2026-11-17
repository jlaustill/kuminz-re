"""The sensor / filter blocks left untyped: channel, instance row, interior rows and their uses."""
import re
import sys
from collections import defaultdict

sys.path.insert(0, sys.argv[1])
import lookup_tables as L
import disasm_func as D

state = L.CsvState.load()
text = open(D.CPP).read()
SENSOR = {"sensorChannelConfigInit", "updateSensorChannelWithConfig", "sensorChannelTypeB_configInit", "sensorChannelTypeB_update"}
FIELDS = {"sensor_channel_config_t": {0: "filter_coefficient", 2: "default_value", 4: "high_threshold", 6: "low_threshold",
                                      8: "debounce_step", 10: "recovery_decrement", 12: "debounce_limit", 14: "debounce_clear_threshold"},
          "sensor_channel_state_t": {0: "raw_adc_counts", 2: "value", 4: "debounce_count", 6: "held_value", 8: "spare", 10: "lookup_input"},
          "ema_filter_state_t": {0: "coefficient", 4: "accumulator"}}
CAST = re.compile(r"^\((sensor_channel_config_t|sensor_channel_state_t|ema_filter_state_t) \*\)&([A-Za-z_][A-Za-z0-9_]*)")
blocks = {}
for callee, args, fn in L.parse_calls(text, SENSOR | {"exponentialMovingAverage"}):
    for i, arg in enumerate(args):
        m = CAST.match(arg.strip())
        if not m:
            continue
        typ, name = m.groups()
        addr = state.addresses[name][0] if name in state.addresses else int(re.search(r"([0-9a-f]{8})$", name).group(1), 16)
        b = blocks.setdefault(addr, {"type": typ, "name": name, "channels": set(), "users": set()})
        b["users"].add(fn)
        if callee in SENSOR and len(args) > 7:
            b["channels"].add(args[7])
words = re.findall(r"[A-Za-z_][A-Za-z0-9_]*", text)
counts = defaultdict(int)
for w in words:
    counts[w] += 1
for addr in sorted(blocks):
    b = blocks[addr]
    size = {"sensor_channel_config_t": 16, "sensor_channel_state_t": 12, "ema_filter_state_t": 8}[b["type"]]
    print(f"0x{addr:08x} {b['type']:24s} {b['name']:44s} ch={','.join(sorted(b['channels'])) or '-'}  users={' '.join(sorted(b['users']))[:70]}")
    for inner in state.rows_inside(addr, addr + size):
        name, typ, _ = state.rows[inner]
        off = inner - addr
        print(f"      +{off:<2} {FIELDS[b['type']].get(off, '?'):24s} {name:52s} {typ:6s} uses={counts.get(name, 0)}")

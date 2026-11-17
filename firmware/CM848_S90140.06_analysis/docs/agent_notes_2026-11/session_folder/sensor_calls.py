"""Every call of the four sensor-channel functions: resolved argument globals with their CSV rows."""
import os
import sys
from collections import defaultdict

sys.path.insert(0, sys.argv[1])
import lookup_tables as L
import disasm_func as D

state = L.CsvState.load()
text = open(D.CPP).read()
NAMES = {"sensorChannelConfigInit", "updateSensorChannelWithConfig", "sensorChannelTypeB_configInit", "sensorChannelTypeB_update"}
calls = L.parse_calls(text, NAMES)
print("calls:", len(calls))
ARGS = {0: "config", 1: "state", 6: "ema", 10: "out10", 11: "out11", 12: "out12"}
per_arg = defaultdict(list)
for callee, args, fn in calls:
    for i, role in ARGS.items():
        if i < len(args):
            a = L.resolve_argument(args[i], state)
            per_arg[role].append((callee[:22], fn[:34], args[i][:46], a))
for role in ARGS.values():
    print(f"== {role}")
    seen = set()
    for callee, fn, raw, a in per_arg[role]:
        if (raw, a) in seen:
            continue
        seen.add((raw, a))
        row = state.rows.get(a, ("", "", "")) if a is not None else ("", "", "")
        print(f"  {callee:22s} {raw:46s} -> {hex(a) if a is not None else '-':10s} {row[0][:34]:34s} {row[1]}")

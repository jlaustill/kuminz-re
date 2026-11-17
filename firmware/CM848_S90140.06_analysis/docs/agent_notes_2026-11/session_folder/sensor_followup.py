"""Sensor-channel follow-up: type the 26 blocks with named rows inside, normalize instance names,
rename the value / default output globals. Prints the plan; --apply edits the CSVs."""
import re
import sys
from collections import defaultdict

sys.path.insert(0, sys.argv[1])
import lookup_tables as L
import disasm_func as D

APPLY = "--apply" in sys.argv
OUT = f"{sys.argv[1]}/../CM848_S90140.06_analysis/output"
state = L.CsvState.load()
text = open(D.CPP).read()
SENSOR = {"sensorChannelConfigInit", "updateSensorChannelWithConfig", "sensorChannelTypeB_configInit", "sensorChannelTypeB_update"}
SIZES = {"sensor_channel_config_t": 16, "sensor_channel_state_t": 12, "ema_filter_state_t": 8}
CAST = re.compile(r"^\((sensor_channel_config_t|sensor_channel_state_t|ema_filter_state_t) \*\)&([A-Za-z_][A-Za-z0-9_]*)")

# 1. the blocks still passed with a cast
blocks = {}
outputs = {10: defaultdict(set), 11: defaultdict(set)}
for callee, args, fn in L.parse_calls(text, SENSOR | {"exponentialMovingAverage"}):
    for arg in args:
        m = CAST.match(arg.strip())
        if m:
            typ, name = m.groups()
            addr = state.addresses[name][0] if name in state.addresses else int(name[-8:], 16)
            blocks[addr] = typ
    if callee in SENSOR:
        for i in (10, 11):
            t = args[i].strip().lstrip("&")
            if t in state.addresses and t not in state.duplicates:
                outputs[i][state.addresses[t][0]].add(t)

# instance names: explicit fixes, then the filter-state suffix rule
EXPLICIT = {0x000592a2: "barometric_pressure_sensor_config",        # channel 3 = barometric pressure (AMB SPN 108)
            0x003fefba: "accelerator_pedal_sensor_config",          # channel 13
            0x0040a09e: "sensor_channelGeneric_ram",                # was sensor_channelGeneric_raw (a state block)
            0x0040b19e: "fuel_level_sensor_channel_state",          # channel 68 (was fuel_level_sensor_adc_counts)
            0x003fa0d2: "cold_start_intake_temperature_filter_state",
            0x003fa884: "fuel_mode_filter_state",
            0x003fb0b6: "load_protection_filter_state",
            0x0040b6e8: "engine_temperature_protection_filter_state"}
SUFFIXES = ["_filter_coeff_table_pointer", "_coeff_table_pointer", "_table_pointer", "_filter_coeff_ptr",
            "_filter_config_ptr", "_ema_coeff_ptr", "_ema_state_pointer", "_ema_state_ptr", "_filter_state_ptr",
            "_smoothing_state_ptr", "_state_ptr", "_filter_pointer", "_coeff_ptr", "_working_ptr", "_pointer", "_ptr"]


def filter_name(name):
    for s in SUFFIXES:
        if name.endswith(s):
            base = name[: -len(s)]
            if s == "_smoothing_state_ptr":
                base += "_smoothing"
            return (base + "_state") if base.endswith("_filter") else (base + "_filter_state")
    return None


renames, retype = {}, {}
for a, typ in blocks.items():
    retype[a] = typ
for a, (name, typ, _) in state.rows.items():
    if typ == "ema_filter_state_t" or blocks.get(a) == "ema_filter_state_t":
        new = EXPLICIT.get(a) or (filter_name(name) if name and not L.JUNK_NAME.match(name) else None)
        if new and new != name:
            renames[a] = new
for a, new in EXPLICIT.items():
    if state.rows.get(a, ("",))[0] != new:
        renames[a] = new

# interior rows of the newly typed blocks
drop = {}
for a, typ in blocks.items():
    for b in state.rows_inside(a, a + SIZES[typ]):
        drop[b] = state.rows[b][0]

# output globals
def output_name(name, kind):
    base = re.sub(r"_(raw|filtered)$", "", name)
    base = re.sub(r"_adc$", "", base)
    return base + ("_value" if kind == 10 else "_default_value")

out_renames = {}
for kind, rows in outputs.items():
    for a, names in rows.items():
        (name,) = names
        if re.search(r"_(raw|filtered)$", name):
            out_renames[a] = output_name(name, kind)

all_renames = {**renames, **out_renames}
taken = {n for n in state.addresses} - {state.rows[a][0] for a in all_renames if a in state.rows}
clash = [(hex(a), n) for a, n in all_renames.items() if n in taken]
dupes = [n for n in set(all_renames.values()) if list(all_renames.values()).count(n) > 1]
print(f"blocks to type {len(retype)}  instance renames {len(renames)}  output renames {len(out_renames)}  interior rows dropped {len(drop)}")
print("clashes:", clash, "duplicates:", dupes)
for a in sorted(renames):
    print(f"   0x{a:08x} {state.rows.get(a, ('',))[0]:44s} -> {renames[a]}")
for a in sorted(out_renames)[:6]:
    print(f"   0x{a:08x} {state.rows[a][0]:44s} -> {out_renames[a]}  ...")
print("interior:", " ".join(sorted(drop.values())))

if APPLY and not clash and not dupes:
    path = f"{OUT}/global_variables.csv"
    lines = open(path).read().split("\n")
    out = []
    for line in lines:
        p = line.split(",", 3)
        if p[0].startswith("0x"):
            a = int(p[0], 16)
            if a in drop:
                continue
            name = all_renames.get(a, p[1])
            typ = retype.get(a, p[2] if len(p) > 2 else "")
            comment = p[3] if len(p) > 3 else ""
            if a in all_renames and p[1] and p[1] != name and not L.JUNK_NAME.match(p[1]):
                comment = (comment + " " if comment else "") + f"(was {p[1]})"
            line = f"{p[0]},{name if not L.JUNK_NAME.match(name) else ''},{typ},{comment}"
        out.append(line)
    open(path, "w").write("\n".join(out))
    rename_log = {state.rows[a][0]: n for a, n in all_renames.items() if a in state.rows and state.rows[a][0]}
    rename_log.update({v: "(field of the typed block)" for v in drop.values()})
    open(f"{sys.argv[2]}", "w").write("\n".join(f"{o},{n}" for o, n in sorted(rename_log.items())))
    print("applied; rename log written to", sys.argv[2])

"""Sensor-channel typing, step 2: type the globals passed as config / state / filter state / outputs."""
import re
import sys
from collections import defaultdict

sys.path.insert(0, sys.argv[1])
import lookup_tables as L
import disasm_func as D

APPLY = "--apply" in sys.argv
state = L.CsvState.load()
text = open(D.CPP).read()
SENSOR = {"sensorChannelConfigInit", "updateSensorChannelWithConfig", "sensorChannelTypeB_configInit", "sensorChannelTypeB_update"}
SIZES = {"sensor_channel_config_t": 16, "sensor_channel_state_t": 12, "ema_filter_state_t": 8, "word": 2}
ROLE_TYPES = {0: "sensor_channel_config_t", 1: "sensor_channel_state_t", 6: "ema_filter_state_t",
              10: "word", 11: "word", 12: "word"}


def resolve(arg):
    """Address an argument points at: &NAME / (T *)&NAME / ((int)&NAME + N) / hex / default labels."""
    t = arg.strip()
    t = re.sub(r"^\([A-Za-z_][A-Za-z0-9_ ]*\*\s*\)", "", t).strip()
    m = re.fullmatch(r"\(\(int\)&([A-Za-z_][A-Za-z0-9_]*) \+ (0x[0-9a-f]+|\d+)\)", t)
    if m:
        base = resolve("&" + m.group(1))
        return None if base is None else base + int(m.group(2), 0)
    if not t.startswith("&") and not re.fullmatch(r"0x[0-9a-f]+", t):
        return None
    t = t.lstrip("&")
    m = re.fullmatch(r"0x([0-9a-f]+)", t)
    if m:
        return int(m.group(1), 16)
    if t in state.duplicates:
        return None
    if t in state.addresses:
        return state.addresses[t][0]
    m = re.search(r"([0-9a-f]{8})$", t)            # DAT_ / PTR_DAT_ / WORD_ / struct default labels
    return int(m.group(1), 16) if m and re.match(r"^(_?DAT_|PTR_|WORD_|BYTE_|DWORD_|uRam|ram0x|sensor_channel_|ema_)", t) else None


wanted = defaultdict(set)      # address -> {type}
users = defaultdict(set)
unresolved = defaultdict(int)
for callee, args, fn in L.parse_calls(text, SENSOR | {"exponentialMovingAverage"}):
    roles = {1: "ema_filter_state_t"} if callee == "exponentialMovingAverage" else ROLE_TYPES
    for index, typ in roles.items():
        if index >= len(args):
            continue
        a = resolve(args[index])
        if a is None:
            unresolved[(callee, index, args[index][:40])] += 1
            continue
        wanted[a].add(typ); users[a].add(fn)

plan, conflicts = {}, []
for a in sorted(wanted):
    types = wanted[a]
    if len(types) > 1:
        conflicts.append((a, "types", " / ".join(sorted(types)))); continue
    typ = next(iter(types))
    size = SIZES[typ]
    row = state.rows.get(a)
    inside = state.rows_inside(a, a + size)
    others = [b for b in wanted if a < b < a + size]
    funcs = [n for f, n in state.functions.items() if a <= f < a + size]
    arrays = [n for b, (n, s) in state.arrays.items() if b < a + size and a < b + s]
    tables = [b for b in state.rows if a < b < a + size and "[" in state.rows[b][1]]
    if row and row[1] == typ:
        continue                                        # already typed
    if others or funcs or arrays or tables:
        conflicts.append((a, "overlap", f"others={[hex(b) for b in others]} funcs={funcs} arrays={arrays}")); continue
    junk_inside = [b for b in inside if L.JUNK_NAME.match(state.rows[b][0]) or not state.rows[b][0]
                   or "." in state.rows[b][0] or "+" in state.rows[b][0]]
    named_inside = [b for b in inside if b not in junk_inside]
    if named_inside and typ != "word":
        conflicts.append((a, "named rows inside", " ".join(f"0x{b:x}:{state.rows[b][0]}" for b in named_inside)))
        continue
    plan[a] = (typ, row, junk_inside)

print(f"instances wanted: {len(wanted)}  to type: {len(plan)}  conflicts: {len(conflicts)}  unresolved args: {sum(unresolved.values())}")
from collections import Counter
print("by type:", Counter(v[0] for v in plan.values()))
for c in conflicts:
    print("  CONFLICT", hex(c[0]), c[1], c[2][:150])
for k, v in sorted(unresolved.items(), key=lambda kv: -kv[1])[:12]:
    print("  unresolved", v, k)
named = [(a, v) for a, v in plan.items() if v[1] and v[1][0] and not L.JUNK_NAME.match(v[1][0])]
print("named rows retyped:", len(named))
for a, (typ, row, junk) in named[:80]:
    print(f"   0x{a:08x} {row[0]:44s} {row[1]:10s} -> {typ}" + (f"  drops {len(junk)} junk inside" if junk else ""))
junk_all = sum(len(v[2]) for v in plan.values())
print("junk rows inside to drop:", junk_all)

if APPLY:
    DESCRIPTION = {"sensor_channel_config_t": "Sensor channel calibration block", "sensor_channel_state_t": "Sensor channel RAM state",
                   "ema_filter_state_t": "EMA filter state", "word": "Sensor channel output word"}
    changes = {}
    for a, (typ, row, junk) in plan.items():
        readers = sorted(users[a])
        shown = " / ".join(readers[:3]) + (f" (+{len(readers) - 3} more)" if len(readers) > 3 else "")
        if row and row[0] and not L.JUNK_NAME.match(row[0]) and "." not in row[0] and "+" not in row[0]:
            changes[a] = (row[0], typ, row[2] or f"{DESCRIPTION[typ]} - used by {shown}")
        else:
            changes[a] = ("", typ, f"{DESCRIPTION[typ]} - used by {shown}" + (f" (was {row[0]})" if row and row[0] else ""))
    path = f"{sys.argv[1]}/../CM848_S90140.06_analysis/output/global_variables.csv"
    edited, inserted = L.write_rows(path, changes)
    drop = {b for v in plan.values() for b in v[2]}
    lines = open(path).read().split("\n")
    kept = [l for l in lines if not (l.split(",", 1)[0].startswith("0x") and int(l.split(",", 1)[0], 16) in drop)]
    open(path, "w").write("\n".join(kept))
    print(f"applied: {edited} retyped, {inserted} added, {len(lines) - len(kept)} junk rows dropped")

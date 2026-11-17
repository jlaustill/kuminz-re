"""Build the table-naming worklist: lookups (interpolator calls grouped by their table tuple) that use an
unnamed table, with the table contents, binned by reader function.

Usage: table_worklist.py <firmware_dir> <plan.csv> <out_dir> [max_tables_per_bin]
Writes out_dir/lookups.json (every lookup), out_dir/bin_NN.json (one per agent) and prints a summary.
"""
import csv
import json
import os
import re
import sys
from collections import defaultdict

FW, PLAN, OUT = sys.argv[1:4]
MAX_PER_BIN = int(sys.argv[4]) if len(sys.argv) > 4 else 30
sys.path.insert(0, os.path.join(FW, "scripts"))
import lookup_tables as LT  # noqa: E402

CPP = os.path.join(FW, "CM848_S90140.06_analysis/output/cm848_rom.ghidra.cpp")
GLOBALS = os.path.join(FW, "CM848_S90140.06_analysis/output/global_variables.csv")
# interpolator -> ({argument index: role}, [input argument indexes], output argument index or None)
SENSOR = ({3: "x_axis", 4: "values"}, [7], 10)
INTERPOLATORS = {
    "lookupTableInterpolation": ({2: "x_axis", 3: "values"}, [1], None),
    "cm848_interpolateTableWithoutCache": ({1: "x_axis", 2: "values"}, [0], None),
    "cm848_dualAxisTableInterpolation": ({2: "x_axis", 4: "y_axis", 5: "grid"}, [1, 3], None),
    "cm848_interpolateFuelMapTable": ({2: "x_axis", 3: "values", 4: "x2_axis", 5: "values2", 6: "values3",
                                       7: "values4"}, [1], 0),
    "sensorChannelTypeB_configInit": SENSOR,
    "sensorChannelTypeB_update": SENSOR,
    "sensorChannelConfigInit": SENSOR,
    "updateSensorChannelWithConfig": SENSOR,
}
HEADER = re.compile(r"^// Function: (\S+) @ (0x[0-9a-f]+)$", re.M)
CALL = re.compile(r"\b(" + "|".join(INTERPOLATORS) + r")\s*\(")
TABLE_LABEL = re.compile(r"\b(?:WORD_ARRAY|WORD)_([0-9a-f]{8})\b")

plan = {int(r["address"], 16): r for r in csv.DictReader(open(PLAN))}
names, by_name = {}, {}
for line in open(GLOBALS):
    p = line.split(",", 3)
    if p[0].startswith("0x") and len(p) > 1 and p[1]:
        names[int(p[0], 16)] = p[1]
        by_name.setdefault(p[1], int(p[0], 16))
unnamed = {a for a, r in plan.items() if not r["name"]}
image = LT.MemoryImage(os.path.join(FW, "CM848_S90140.06_analysis/originals"))


def signed(v):
    return v - 0x10000 if v & 0x8000 else v


def contents(a, role, axis_points=None, grid_shape=None):
    """Readable table contents: axis breakpoints, 1-D values, grid range."""
    words = int(plan[a]["words"]) if a in plan else None
    if words is None:
        return None
    raw = [image.word(a + 2 * i) for i in range(words)]
    if any(v is None for v in raw):
        return {"region": image.region(a), "words": words, "note": "not in the loaded images"}
    out = {"region": image.region(a), "words": words}
    if role.endswith("axis"):
        pts = raw[1:]
        out["breakpoints_unsigned"] = pts
        if any(v & 0x8000 for v in pts):
            out["breakpoints_signed"] = [signed(v) for v in pts]
    elif role == "grid":
        out["grid_min_max_unsigned"] = [min(raw), max(raw)]
        out["grid_min_max_signed"] = [min(map(signed, raw)), max(map(signed, raw))]
        if grid_shape:
            nx, ny = grid_shape
            out["shape_x_by_y"] = [nx, ny]
            if nx * ny == words:
                out["first_row"] = raw[:nx]
                out["last_row"] = raw[-nx:]
    else:
        vals = raw[1:]
        out["values_unsigned"] = vals
        if any(v & 0x8000 for v in vals):
            out["values_signed"] = [signed(v) for v in vals]
    return out


def split_args(text, start):
    depth, args, cur, i = 0, [], [], start
    while i < len(text):
        c = text[i]
        if c == "(":
            depth += 1
            if depth > 1:
                cur.append(c)
        elif c == ")":
            depth -= 1
            if depth == 0:
                args.append("".join(cur).strip())
                return args, i
            cur.append(c)
        elif c == "," and depth == 1:
            args.append("".join(cur).strip())
            cur = []
        else:
            cur.append(c)
        i += 1
    return args, i


def table_address(arg):
    t = TABLE_LABEL.search(arg)
    if t:
        return int(t.group(1), 16)
    ident = re.findall(r"[A-Za-z_][A-Za-z0-9_]*", arg)
    for n in reversed(ident):
        if n in by_name:
            return by_name[n]
    return None


src = open(CPP).read()
parts = HEADER.split(src)
lookups = {}                # key (tuple of (role, address)) -> lookup
for i in range(1, len(parts), 3):
    fn, body = parts[i], " ".join(parts[i + 2].split())
    for m in CALL.finditer(body):
        roles, inputs, output_arg = INTERPOLATORS[m.group(1)]
        args, end = split_args(body, m.end() - 1)
        tables = tuple((role, table_address(args[idx]) if idx < len(args) else None) for idx, role in roles.items())
        if not any(a in unnamed for _, a in tables):
            continue
        s = max(body.rfind(";", 0, m.start()), body.rfind("{", 0, m.start()), body.rfind("}", 0, m.start()))
        e = body.find(";", end)
        lk = lookups.setdefault(tables, {"interpolator": m.group(1), "tables": tables, "calls": []})
        lk["calls"].append({"function": fn, "statement": body[s + 1:e + 1].strip()[:420],
                            "inputs": [args[k] for k in inputs if k < len(args)],
                            "output_argument": args[output_arg] if output_arg is not None and output_arg < len(args) else None})

table_lookups = defaultdict(list)
ordered = sorted(lookups.values(), key=lambda lk: (lk["calls"][0]["function"], lk["tables"]))
for n, lk in enumerate(ordered):
    lk["id"] = f"L{n:03d}"
    for _, a in lk["tables"]:
        if a in unnamed:
            table_lookups[a].append(lk["id"])
by_id = {lk["id"]: lk for lk in ordered}


def render(lk):
    shape = None
    xs = dict(lk["tables"])
    if lk["interpolator"] == "cm848_dualAxisTableInterpolation" and xs.get("x_axis") and xs.get("y_axis"):
        nx = (image.word(xs["x_axis"]) or 0) // 2
        ny = (image.word(xs["y_axis"]) or 0) // 2
        shape = (nx, ny)
    tables = []
    for role, a in lk["tables"]:
        entry = {"role": role, "address": f"0x{a:08x}" if a is not None else None,
                 "current_name": names.get(a) if a is not None else None,
                 "to_name": a in unnamed}
        if a in unnamed:
            entry["shared_by_lookups"] = table_lookups[a]
        if a is not None:
            entry["contents"] = contents(a, role, grid_shape=shape)
        tables.append(entry)
    return {"id": lk["id"], "interpolator": lk["interpolator"], "kind": "2-D" if shape else "1-D",
            "tables": tables, "calls": lk["calls"]}


# carve-out: sensor-channel lookups whose value output is already named
scripted = []
for lk in ordered:
    if lk["interpolator"] in ("sensorChannelTypeB_configInit", "sensorChannelTypeB_update",
                              "sensorChannelConfigInit", "updateSensorChannelWithConfig"):
        outs = {c["output_argument"] for c in lk["calls"]}
        out_names = {re.sub(r"^&", "", o or "") for o in outs}
        if len(out_names) == 1:
            o = out_names.pop()
            if re.fullmatch(r"[a-z][a-z0-9_]*_value", o) and not o.startswith("sensor_channel"):
                scripted.append((lk["id"], o))
scripted_ids = {i for i, _ in scripted}

covered = set(table_lookups)
missing = sorted(unnamed - covered)
owner = {}
for lk in ordered:
    if lk["id"] in scripted_ids:
        continue
    owner.setdefault(lk["calls"][0]["function"], []).append(lk["id"])
fn_tables = {f: {a for i in ids for _, a in by_id[i]["tables"] if a in unnamed} for f, ids in owner.items()}
bins, cur, size, assigned = [], [], 0, set()
for f in sorted(owner, key=lambda f: -len(fn_tables[f])):
    new = fn_tables[f] - assigned
    if not new:
        continue
    if cur and size + len(new) > MAX_PER_BIN:
        bins.append(cur)
        cur, size = [], 0
    cur.append(f)
    size += len(new)
    assigned |= new
if cur:
    bins.append(cur)
os.makedirs(OUT, exist_ok=True)
json.dump([render(lk) for lk in ordered], open(os.path.join(OUT, "lookups.json"), "w"), indent=1)
summary = []
done = set()
for n, b in enumerate(bins):
    ids = [i for f in b for i in owner[f]]
    # each unnamed table is named by exactly one bin: the first bin that holds one of its lookups
    mine = sorted({a for i in ids for _, a in by_id[i]["tables"] if a in unnamed} - done)
    done |= set(mine)
    related = sorted({j for a in mine for j in table_lookups[a]} | set(ids))
    payload = {"bin": n, "functions": b, "assigned_tables": [f"0x{a:08x}" for a in mine],
               "lookups": [render(by_id[i]) for i in related]}
    json.dump(payload, open(os.path.join(OUT, f"bin_{n:02d}.json"), "w"), indent=1)
    regions = sorted({image.region(a) for a in mine})
    summary.append((n, len(mine), len(related), regions, b[:3]))
json.dump({"scripted": scripted, "missing": [f"0x{a:08x}" for a in missing]}, open(os.path.join(OUT, "extras.json"), "w"), indent=1)
print(f"unnamed {len(unnamed)}  in lookups {len(covered)}  lookups {len(ordered)}  scripted sensor lookups {len(scripted)}"
      f"  not in a call {len(missing)}")
for n, t, l, r, f in summary:
    print(f"bin {n:02d}: {t:2d} tables {l:2d} lookups {r} {f}")
print("tables assigned to bins:", len(done), " scripted:", len({a for i in scripted_ids for _, a in by_id[i]['tables'] if a in unnamed} - done))

"""Round 94 (read-only): for every proposed global of the leads batches whose type is wider than one byte, the live
rows that start strictly inside its span, with the path each maps to (a table_lookup_2d_arguments_t field by offset,
an array element by index; odd offsets inside a field map to nothing) and how often the row's name renders in the
committed .cpp. Writes the remove_globals dict (JSON) for the overrides. usage:
leads_removals_r94.py <repo> <cpp> <out.json> <batch_X.json>..."""
import json
import os
import re
import sys

repo, cpp_path, out_path, batches = os.path.abspath(sys.argv[1]), sys.argv[2], sys.argv[3], sys.argv[4:]
cpp = open(cpp_path, errors="replace").read()
FIELDS = {0: "x_axis_offset", 2: "x_axis_pointer", 6: "x_input", 8: "y_axis_offset", 0xa: "y_axis_pointer",
          0xe: "y_input", 0x10: "z_values_pointer", 0x14: "no_interpolation_flag"}
WIDTH = {"byte": 1, "word": 2, "i16": 2, "dword": 4, "i32": 4, "pointer": 4, "table_lookup_2d_arguments_t": 22}
DIRS = {"CM550": "firmware/CM550_J90350.00_analysis/output", "CM848": "firmware/CM848_S90140.06_analysis/output"}
rows = {}
for fw, d in DIRS.items():
    rows[fw] = []
    for line in open(os.path.join(repo, d, "global_variables.csv"), newline="").read().split("\n"):
        p = line.rstrip("\r").split(",", 3)
        if len(p) > 2 and p[0].startswith("0x"):
            rows[fw].append((int(p[0], 16), p[1], p[2]))
result = {"CM550": {}, "CM848": {}}
for path in batches:
    data = json.load(open(path))
    for g in data["proposal"].get("globals") or []:
        fw = "CM848" if "848" in g["firmware"] else "CM550"
        a = int(g["address"], 16)
        t = g["proposed_type"].strip()
        m = re.match(r"^(\w+)\[(\d+)\]$", t)
        base, count = (m.group(1), int(m.group(2))) if m else (t, 1)
        w = WIDTH.get(base)
        if not w or w * count <= 1:
            continue
        span = w * count
        name = g["proposed_name"]
        for ra, rn, rt in rows[fw]:
            if a < ra < a + span:
                off = ra - a
                if base == "table_lookup_2d_arguments_t":
                    target = f"{name}.{FIELDS[off]}" if off in FIELDS else ""
                elif off % w == 0:
                    target = f"{name}[{off // w}]"
                else:
                    target = ""
                uses = len(re.findall(rf"(?<![A-Za-z0-9_])_?{re.escape(rn)}(?![A-Za-z0-9_])", cpp)) if rn else 0
                result[fw][f"0x{ra:08x}"] = target
                print(f"{data['batch']} {fw} 0x{ra:x} {rn or '(no name)'} {rt} inside {name} @0x{a:x} +{off} -> {target or '(none)'}; renders {uses}")
json.dump(result, open(out_path, "w"), indent=1)
print({fw: len(v) for fw, v in result.items()})

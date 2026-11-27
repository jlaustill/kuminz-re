"""Round 91 (CM550 + CM848): apply the verified elements of workflow wf_368d2db4-707 (an investigator and a skeptic per
item: S1 the fault count table, S2 the datalogger records, S3 the all-speed governor gain sets, T1 the J1939 receive
layer twins, T2 the TSC1 source configuration twin and the wet tank pressure byte).
An element is applied when its skeptic verdict (matched by address / struct name) is CONFIRMED or AMENDED; AMENDED
comment texts are applied ("replace 'A' with 'B'" or 'Comment: "..."'); REFUTED or unmatched elements are skipped and
reported. Elements:
- structs: a type-only template in the firmware's structure_definitions.csv (skipped when the name exists there);
- globals: the row at the address renamed / retyped / commented (inserted when there is none); a dotted current name
  (CM848 instance.field) renames the struct field instead;
- rows_to_remove: global rows deleted; a function_renames.csv row moves to deleted_functions.csv;
- functions: renamed, with the plate comment; function_definitions / local_variables follow;
- local_rows: added.
Writes refresh maps per firmware (old -> new; removed rows inside a new struct-array instance map to their element
field). Idempotent; keeps line endings. usage: apply_r91.py <repo> <outdir> <item_X.json>..."""
import csv
import io
import json
import os
import re
import sys

repo, outdir, items = os.path.abspath(sys.argv[1]), sys.argv[2], sys.argv[3:]
R = "PR #53 round 91"
DIRS = {"CM550": os.path.join(repo, "firmware/CM550_J90350.00_analysis/output"),
        "CM848": os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")}


def fw_of(x):
    f = (x or "").upper()
    return "CM848" if "848" in f else "CM550"


def read(p):
    return open(p, newline="").read()


def write(p, t):
    open(p, "w", newline="").write(t)


def norm(a):
    return f"0x{int(a, 16):08x}"


def quote(text):
    text = " ".join(text.split())
    return '"' + text.replace('"', "'") + '"' if ("," in text or '"' in text) else text


def amend(text, amendment):
    """Apply a skeptic's amendment to a comment / plate text."""
    if not amendment:
        return text
    for a, b in re.findall(r"replace '(.+?)' with '(.+?)'(?:\.\s|\.?$)", amendment, re.S):
        if a in text:
            text = text.replace(a, b)
    m = re.search(r'Comment: "(.+)"\s*$', amendment, re.S)
    if m:
        text = m.group(1)
    return text


report, maps = [], {"CM550": [], "CM848": []}
state = {}
for fw, d in DIRS.items():
    state[fw] = {k: read(os.path.join(d, k)) for k in ("global_variables.csv", "structure_definitions.csv",
                                                        "function_renames.csv", "function_definitions.csv",
                                                        "local_variables.csv", "deleted_functions.csv")}


def verdict_for(verdicts, key):
    hits = [v for v in verdicts if key.lower() in v["element"].lower()]
    return hits[0] if hits else None


for path in items:
    data = json.load(open(path))
    p, vd = data["proposal"], (data.get("verdict") or {}).get("verdicts", [])
    item = p.get("item", os.path.basename(path))
    new_structs = {}
    # ------------------------------------------------------------ structs
    for s in p.get("structs") or []:
        fw = fw_of(s.get("firmware"))
        v = verdict_for(vd, s["struct_name"])
        if not v or v["verdict"] == "REFUTED":
            report.append(f"{item} SKIP struct {s['struct_name']} ({v['verdict'] if v else 'no verdict'})")
            continue
        new_structs[s["struct_name"]] = s
        t = state[fw]["structure_definitions.csv"]
        if re.search(rf"^{re.escape(s['struct_name'])},", t, re.M):
            report.append(f"{item} {fw} struct {s['struct_name']} exists: kept")
            continue
        E = "\r\n" if "\r\n" in t else "\n"
        rows = [f"# {s['struct_name']} ({s['size']} bytes; {R}, item {item})"]
        for f in sorted(s["fields"], key=lambda f: f["offset"]):
            comment = f.get("comment") or ""
            rows.append(f"{s['struct_name']},,{f['name']},{f['type']},{f['size']},{quote(comment)},,verified")
        assert sum(f["size"] for f in s["fields"]) == s["size"], (s["struct_name"], "field sizes")
        state[fw]["structure_definitions.csv"] = t.rstrip("\r\n") + E + E + E.join(rows) + E
        report.append(f"{item} {fw} struct {s['struct_name']} added ({len(s['fields'])} fields)")
    # ------------------------------------------------------------ functions
    for f in p.get("functions") or []:
        fw, a = fw_of(f.get("firmware")), norm(f["address"])
        v = verdict_for(vd, f["address"].lower().replace("0x000", "0x000")) or verdict_for(vd, a)
        if not v or v["verdict"] == "REFUTED":
            report.append(f"{item} SKIP function {fw} {a} ({v['verdict'] if v else 'no verdict'})")
            continue
        t = state[fw]["function_renames.csv"]
        m = re.search(rf"^{a},([^,\r\n]*)(,[^\r\n]*)?$", t, re.M)
        old = m.group(1) if m else ""
        if old == f["proposed_name"]:
            continue
        plate = amend(f.get("plate_comment") or "", v.get("amendment"))
        plate = f"{plate} (was {old or 'no row'}; {R})"
        row = f"{a},{f['proposed_name']},{' '.join(plate.split())}"
        if m:
            t = t[:m.start()] + row + t[m.end():]
        else:
            t = t.rstrip("\n") + "\n" + row + "\n"
        state[fw]["function_renames.csv"] = t
        for k in ("function_definitions.csv", "local_variables.csv"):
            if old:
                state[fw][k] = re.sub(rf"^({a},){re.escape(old)},", rf"\g<1>{f['proposed_name']},", state[fw][k], flags=re.M)
        if old:
            maps[fw].append((a, f["proposed_name"], old))
        report.append(f"{item} {fw} function {a} {old or '(new)'} -> {f['proposed_name']}")
    # ------------------------------------------------------------ globals
    for g in p.get("globals") or []:
        fw, a = fw_of(g.get("firmware")), norm(g["address"])
        v = verdict_for(vd, g["address"]) or verdict_for(vd, a)
        if not v or v["verdict"] == "REFUTED":
            report.append(f"{item} SKIP global {fw} {a} ({v['verdict'] if v else 'no verdict'})")
            continue
        cur, new, typ = g.get("current_name") or "", g["proposed_name"], g["proposed_type"]
        comment = amend(g.get("comment") or "", v.get("amendment"))
        if "." in cur:      # a struct field of an instance (CM848)
            inst, field = cur.split(".", 1)
            new_field = new.split(".", 1)[1]
            t = state[fw]["structure_definitions.csv"]
            m = re.search(rf"^([A-Za-z0-9_]+),(0x[0-9a-fA-F]+|),{re.escape(field)},([^\r\n]*)$", t, re.M)
            if m:
                rest = m.group(3)
                if f"(was {field}" not in rest:
                    rest = rest.replace(",,verified", f" (was {field}; {R}),,verified", 1) if ",,verified" in rest else rest
                t = t[:m.start()] + f"{m.group(1)},{m.group(2)},{new_field},{rest}" + t[m.end():]
                state[fw]["structure_definitions.csv"] = t
                maps[fw].append(("", new, cur))
                report.append(f"{item} {fw} field {cur} -> {new}")
            elif not re.search(rf"^[A-Za-z0-9_]+,(0x[0-9a-fA-F]+|),{re.escape(new_field)},", t, re.M):
                report.append(f"{item} PROBLEM {fw} field {cur} not found")
            continue
        lines = state[fw]["global_variables.csv"].split("\n")
        idx = next((i for i, l in enumerate(lines) if l.lower().startswith(a + ",")), None)
        old = lines[idx].split(",")[1] if idx is not None else ""
        if idx is not None and old == new and lines[idx].split(",")[2] == typ:
            continue
        was = f" (was {old}; {R})" if old and old != new else f" ({R})"
        row = f"{a},{new},{typ},{' '.join(comment.split())}{was}"
        if idx is not None:
            lines[idx] = row
        else:
            after = [i for i, l in enumerate(lines) if l.startswith("0x") and int(l.split(",")[0], 16) < int(a, 16)]
            lines.insert(after[-1] + 1, row)
        state[fw]["global_variables.csv"] = "\n".join(lines)
        if old and old != new:
            maps[fw].append((a, new, old))
        report.append(f"{item} {fw} global {a} {old or '(new)'} -> {new} {typ}")
    # ------------------------------------------------------------ removals
    instances = []
    for g in p.get("globals") or []:
        m = re.match(r"^(\w+)\s*\[(\d+)\]$", g["proposed_type"])
        st = (m.group(1) if m else g["proposed_type"]).strip()
        if st in new_structs:
            instances.append((int(g["address"], 16), g["proposed_name"], new_structs[st], int(m.group(2)) if m else 1))
    for r in p.get("rows_to_remove") or []:
        fw, a = fw_of(r.get("firmware")), norm(r["address"])
        v = verdict_for(vd, r["address"]) or verdict_for(vd, a)
        if not v or v["verdict"] == "REFUTED":
            report.append(f"{item} SKIP remove {fw} {a} ({v['verdict'] if v else 'no verdict'})")
            continue
        lines = state[fw]["global_variables.csv"].split("\n")
        idx = next((i for i, l in enumerate(lines) if l.lower().startswith(a + ",")), None)
        if idx is not None:
            old = lines[idx].split(",")[1]
            del lines[idx]
            state[fw]["global_variables.csv"] = "\n".join(lines)
            addr = int(a, 16)
            for base, name, s, count in instances:
                if base <= addr < base + s["size"] * count:
                    i, off = divmod(addr - base, s["size"])
                    holder = next((f for f in s["fields"] if f["offset"] <= off < f["offset"] + f["size"]), None)
                    field = (holder["name"] + (f"+{off - holder['offset']}" if off > holder["offset"] else "")
                             if holder else f"+{off}")
                    path = f"{name}[{i}].{field}" if count > 1 else f"{name}.{field}"
                    maps[fw].append((a, path, old))
                    break
            report.append(f"{item} {fw} removed global {a} {old}")
            continue
        t = state[fw]["function_renames.csv"]
        m = re.search(rf"^{a},([^,\r\n]*)[^\r\n]*\r?\n", t, re.M)
        if m:
            state[fw]["function_renames.csv"] = t[:m.start()] + t[m.end():]
            for k in ("function_definitions.csv", "local_variables.csv"):
                state[fw][k] = "\n".join(l for l in state[fw][k].split("\n") if not l.lower().startswith(a + ","))
            dt = state[fw]["deleted_functions.csv"]
            if f"\n{a}," not in dt:
                state[fw]["deleted_functions.csv"] = (dt.rstrip("\n") + f"\n{a},{' '.join(r.get('reason', '').split())} "
                                                      f"(was {m.group(1)}; {R})\n")
            report.append(f"{item} {fw} function {a} {m.group(1)} -> deleted_functions.csv")
        elif f"\n{a}," not in state[fw]["deleted_functions.csv"]:
            report.append(f"{item} PROBLEM {fw} remove {a}: no row")
    # ------------------------------------------------------------ local rows
    for lr in p.get("local_rows") or []:
        fw = fw_of(lr.get("firmware"))
        fa = norm(lr["function_address"])
        v = verdict_for(vd, lr["old_name"])
        if not v or v["verdict"] == "REFUTED":
            report.append(f"{item} SKIP local {fw} {fa} {lr['old_name']} ({v['verdict'] if v else 'no verdict'})")
            continue
        row = f"{fa},{lr.get('function_name', '')},{lr['old_name']},{lr['new_name']},{lr['type']},{' '.join((lr.get('comment') or '').split())} ({R})"
        if f"{fa},{lr.get('function_name', '')},{lr['old_name']}," not in state[fw]["local_variables.csv"]:
            state[fw]["local_variables.csv"] = state[fw]["local_variables.csv"].rstrip("\n") + "\n" + row + "\n"
            report.append(f"{item} {fw} local {fa} {lr['old_name']} -> {lr['new_name']}")
for fw, d in DIRS.items():
    for k, t in state[fw].items():
        if read(os.path.join(d, k)) != t:
            write(os.path.join(d, k), t)
    with open(os.path.join(outdir, f"map_r91_{fw.lower()}.csv"), "w") as fh:
        fh.write("address,name,old_label,kind,dims\n")
        for a, n, o in maps[fw]:
            fh.write(f"{a},{n},{o},symbol,1\n")
open(os.path.join(outdir, "apply_report_r91.txt"), "w").write("\n".join(report) + "\n")
print("\n".join(r for r in report if "SKIP" in r or "PROBLEM" in r) or "no skips / problems")
print(len(report), "report lines; maps:", {k: len(v) for k, v in maps.items()})

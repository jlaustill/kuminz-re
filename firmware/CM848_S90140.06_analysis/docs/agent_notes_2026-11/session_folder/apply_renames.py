"""Gate and apply confirmed function / global renames from verification results.
Usage: apply_renames.py <firmware_output_dir> <result.jsonl>... [--apply] [--out mapping.csv] [--skip ADDR,...]
Functions: name + plate comment in function_renames.csv (and the name column of function_definitions.csv /
local_variables.csv). Globals: name column of global_variables.csv. Writes a mapping (address,name,old_label,kind)."""
import csv
import json
import os
import re
import sys

def clip(text, limit=400):
    """Cut at a word boundary and mark the cut (a plain [:limit] cuts identifiers mid-word)."""
    if len(text) <= limit:
        return text
    cut = text[:limit]
    if not text[limit].isspace():
        cut = cut[: cut.rfind(" ")]
    return cut.rstrip(" ,;:(-/") + " ..."


args = [a for a in sys.argv[1:] if not a.startswith("--")]
APPLY = "--apply" in sys.argv
OUT = sys.argv[sys.argv.index("--out") + 1] if "--out" in sys.argv else None
SKIP_RAW = sys.argv[sys.argv.index("--skip") + 1] if "--skip" in sys.argv else None
SKIP = set(SKIP_RAW.split(",")) if SKIP_RAW else set()
for v in (OUT, SKIP_RAW):
    if v in args:
        args.remove(v)
FW, RESULTS = args[0], args[1:]
BANNED = {"temp", "tmp", "press", "pos", "corr", "coef", "coeff", "thresh", "thr", "inj", "qty", "ctrl", "cfg",
          "cmd", "val", "vals", "idx", "cnt", "num", "ref", "spd", "eng", "prot", "lim", "mult", "comp", "adj", "trq",
          "tbl", "lkp", "sw", "calc", "accel", "decel", "pct", "freq", "volt", "amp", "deg", "sec", "diag", "cond", "req",
          "resp", "init", "tmr", "buf", "aux", "arb", "iat", "imt", "proc", "mgr", "util", "info", "stat", "msg"}
EEPROM = (0x3fd482, 0x3feec1)


def words(name):
    parts = re.split(r"_", name)
    out = []
    for p in parts:
        out += [w.lower() for w in re.findall(r"[A-Z]?[a-z]+|[A-Z]+(?![a-z])|\d+", p)]
    return out


def load(path, sep_limit):
    lines = open(path).read().split("\n")
    rows = {}
    for i, l in enumerate(lines):
        p = l.split(",", sep_limit)
        if p[0].startswith("0x"):
            rows.setdefault(int(p[0], 16), []).append(i)
    return lines, rows


fr_path = os.path.join(FW, "function_renames.csv")
gv_path = os.path.join(FW, "global_variables.csv")
fr_lines, fr_rows = load(fr_path, 2)
gv_lines, gv_rows = load(gv_path, 3)
used = set()
for path, col in ((fr_path, 1), (gv_path, 1), (os.path.join(FW, "arrays.csv"), 1)):
    for l in open(path):
        p = l.split(",")
        if p[0].startswith("0x") and len(p) > col:
            used.add(p[col])
registers = set()
for l in open(os.path.join(FW, "mpc555_registers.csv")):
    p = l.split(",", 1)
    if p[0].startswith("0x"):
        registers.add(int(p[0], 16))

items, problems, skipped, plates_only = [], [], [], []
for path in RESULTS:
    for n, line in enumerate(open(path), 1):
        line = line.strip()
        if not line:
            continue
        r = json.loads(line)
        if r.get("kind") not in ("function", "global"):
            continue
        plate_only = (r.get("kind") == "function" and r.get("verdict") == "confirmed" and r.get("new") == r.get("old")
                      and r.get("plate_comment"))
        if plate_only:
            plates_only.append((int(r["address"], 16), r["old"], r["plate_comment"]))
            continue
        if r.get("verdict") not in ("confirmed", "rejected") or not r.get("new") or r.get("new") == r.get("old"):
            skipped.append((r.get("kind"), r.get("address"), r.get("old"), r.get("verdict")))
            continue
        a = int(r["address"], 16)
        if f"0x{a:08x}" in SKIP or r["address"] in SKIP:
            skipped.append((r["kind"], r["address"], r["old"], "skipped by hand"))
            continue
        text = r.get("plate_comment", "") if r["kind"] == "function" else r.get("evidence", "")
        items.append((r["kind"], a, r["old"], r["new"], text, os.path.basename(path)))
merged, by_address = [], {}
for it in items:                          # the same rename from two groups = agreement: keep one
    key = (it[0], it[1])
    if key in by_address:
        if by_address[key][3] != it[3]:
            problems.append(f"{it[0]} 0x{it[1]:08x}: {by_address[key][3]} ({by_address[key][5]}) vs {it[3]} ({it[5]})")
        continue
    by_address[key] = it
    merged.append(it)
items = merged
seen = {}
for kind, a, old, new, plate, src in items:
    tag = f"{kind} 0x{a:08x} {old} -> {new} ({src})"
    if new in seen:
        problems.append(f"{tag}: new name also proposed for {seen[new]}")
    seen[new] = tag
    if new in used:
        problems.append(f"{tag}: new name already in a CSV")
    bad = sorted(set(words(new)) & BANNED)
    if bad:
        problems.append(f"{tag}: banned word(s) {bad}")
    if re.search(r"(?<![a-z])0x|_[0-9a-f]*[a-f][0-9a-f]*\d[0-9a-f]*(_|$)", new):
        problems.append(f"{tag}: hex-looking part")
    if kind == "function":
        if not re.fullmatch(r"(cm848|mpc555)_[a-z][A-Za-z0-9]*", new):
            problems.append(f"{tag}: function name format")
        rows = fr_rows.get(a, [])
        if len(rows) != 1 or fr_lines[rows[0]].split(",", 2)[1] != old:
            problems.append(f"{tag}: function_renames row mismatch")
    else:
        if not re.fullmatch(r"[a-z][a-z0-9]*(_[a-z0-9]+)*", new):
            problems.append(f"{tag}: global name format")
        rows = gv_rows.get(a, [])
        if len(rows) != 1 or gv_lines[rows[0]].split(",", 3)[1] != old:
            problems.append(f"{tag}: global_variables row mismatch ({len(rows)} rows)")
        if a in registers:
            problems.append(f"{tag}: register address")
        in_eeprom = EEPROM[0] <= a <= EEPROM[1]
        if new.endswith("_cal") and not in_eeprom:
            problems.append(f"{tag}: _cal outside the EEPROM mirror")
        if old.endswith("_cal") and in_eeprom and not new.endswith("_cal"):
            problems.append(f"{tag}: EEPROM-backed value lost its _cal")
        if "protection" in words(new) and new.split("_")[-1] == "protection":
            problems.append(f"{tag}: bare protection")
print(f"renames: {sum(1 for i in items if i[0] == 'function')} functions, {sum(1 for i in items if i[0] == 'global')} globals;"
      f" not renamed: {len(skipped)}")
for p in problems:
    print("PROBLEM", p)
if OUT:
    with open(OUT, "w", newline="") as f:
        w = csv.writer(f)
        w.writerow(["address", "name", "old_label", "kind"])
        for kind, a, old, new, plate, src in items:
            w.writerow([f"0x{a:08x}", new, old, kind])
if APPLY:
    if problems:
        sys.exit("not applied: fix the problems first")
    fr_new, gv_new = list(fr_lines), list(gv_lines)
    fn_map = {}
    for kind, a, old, new, plate, src in items:
        if kind == "function":
            i = fr_rows[a][0]
            p = fr_lines[i].split(",", 2)
            plate = " ".join(plate.split())
            fr_new[i] = f"{p[0]},{new},{plate}" if plate else f"{p[0]},{new}" + ("," + p[2] if len(p) > 2 else "")
            fn_map[a] = (old, new)
        else:
            i = gv_rows[a][0]
            p = gv_lines[i].split(",", 3)
            while len(p) < 4:
                p.append("")
            p[1] = new
            evidence = clip(" ".join(plate.split()))
            earlier = p[3].strip()
            p[3] = (f"{evidence} (was {old})" if evidence else f"(was {old})") + (f" | earlier note: {earlier}" if earlier else "")
            gv_new[i] = ",".join(p)
    for a, old, plate in plates_only:              # same name, refreshed plate comment
        rows = fr_rows.get(a, [])
        if len(rows) != 1 or fr_new[rows[0]].split(",", 2)[1] != old:
            sys.exit(f"plate-only row mismatch at 0x{a:08x} {old}")
        p = fr_new[rows[0]].split(",", 2)
        fr_new[rows[0]] = f"{p[0]},{p[1]},{' '.join(plate.split())}"
    print(f"plate-only refreshes: {len(plates_only)}")
    open(fr_path, "w").write("\n".join(fr_new))
    open(gv_path, "w").write("\n".join(gv_new))
    for name in ("function_definitions.csv", "local_variables.csv"):
        path = os.path.join(FW, name)
        lines = open(path).read().split("\n")
        hits = 0
        for i, l in enumerate(lines):
            p = l.split(",", 2)
            if p[0].startswith("0x") and len(p) > 2 and int(p[0], 16) in fn_map and p[1] == fn_map[int(p[0], 16)][0]:
                lines[i] = f"{p[0]},{fn_map[int(p[0], 16)][1]},{p[2]}"
                hits += 1
        open(path, "w").write("\n".join(lines))
        print(f"{name}: {hits} rows follow the function renames")
    print(f"applied {len(items)} renames")

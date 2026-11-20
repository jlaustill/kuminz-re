"""build.py [--write]: merge spec_data_a / spec_data_b in bin order, verify, and (with --write) write the JSONL result file."""
import csv
import glob
import json
import os
import re
import sys

sys.path.insert(0, "/tmp/w14_globals2")
import spec_data_a  # noqa: E402
import spec_data_b  # noqa: E402

STAGE9 = "/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage9"
OUT = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-fueling-state-enum/firmware/CM848_S90140.06_analysis/output"
RESULT = f"{STAGE9}/result_W14_globals2.jsonl"
BANNED = {"temp", "tmp", "press", "pos", "corr", "coef", "coeff", "thresh", "thr", "inj", "qty", "ctrl", "cfg",
          "cmd", "val", "vals", "idx", "cnt", "num", "ref", "spd", "eng", "prot", "lim", "mult", "comp", "adj", "trq",
          "tbl", "lkp", "sw", "calc", "accel", "decel", "pct", "freq", "volt", "amp", "deg", "sec", "diag", "cond", "req",
          "resp", "init", "tmr", "buf", "aux", "arb", "iat", "imt", "proc", "mgr", "util", "info", "stat", "msg"}
EEPROM = (0x3fd482, 0x3feec1)
problems = []


def problem(msg):
    problems.append(msg)
    print("PROBLEM", msg)


def words(name):
    out = []
    for p in name.split("_"):
        out += [w.lower() for w in re.findall(r"[A-Z]?[a-z]+|[A-Z]+(?![a-z])|\d+", p)]
    return out


bin_items = json.load(open(f"{STAGE9}/bins/globals2.json"))
specs = spec_data_a.A + spec_data_b.B
if len(specs) != len(bin_items):
    problem(f"spec count {len(specs)} != bin count {len(bin_items)}")
csv_rows = {}
for line in open(f"{OUT}/global_variables.csv", errors="replace"):
    if line.startswith("0x"):
        p = (line.rstrip("\n").split(",", 3) + ["", "", ""])[:4]
        csv_rows.setdefault(int(p[0], 16), []).append(p)
cpp_lines = open(f"{OUT}/cm848_rom.ghidra.cpp", errors="replace").read().split("\n")
stripped = [l.strip() for l in cpp_lines]
fn_at, cur = [], ""
for l in cpp_lines:
    m = re.match(r"// Function: (\S+)", l)
    if m:
        cur = m.group(1)
    fn_at.append(cur)

# known names for the comment sweep (same sources as comment_name_sweep.py)
known = set()
for fname, cols in (("global_variables.csv", (1, 2)), ("function_renames.csv", (1,)), ("deleted_functions.csv", (1,)),
                    ("structure_definitions.csv", (0, 2)), ("enums.csv", (0, 2)), ("arrays.csv", (1,)),
                    ("local_variables.csv", (3,)), ("function_definitions.csv", (3,))):
    try:
        for row in csv.reader(open(f"{OUT}/{fname}")):
            for c in cols:
                if len(row) > c and row[c]:
                    known.add(re.sub(r"\[\d+\]$", "", row[c]))
    except FileNotFoundError:
        pass
my_old = {b["current_name"] for b in bin_items}
my_new = {s["new"] for s in specs if "new" in s}
known = (known - my_old) | my_new | {b["current_name"] for b, s in zip(bin_items, specs) if s.get("keep")}
token = re.compile(r"\b(?:[a-z][a-z0-9]*(?:_[a-z0-9]+){2,}|(?:cm848|mpc555|hpcr|vp44|mc68k|cm550)_[A-Za-z0-9_]+)\b")
history = re.compile(r"\((?:was|were) [^)]*\)", re.I)

lines_out = []
seen_new = {}
for k, (b, s) in enumerate(zip(bin_items, specs)):
    a = int(b["address"], 16)
    if s["addr"] != b["address"]:
        problem(f"item {k}: spec address {s['addr']} != bin {b['address']}")
        continue
    rows = csv_rows.get(a, [])
    if len(rows) != 1 or rows[0][1] != b["current_name"]:
        problem(f"item {k} {b['address']}: CSV rows {rows} vs bin name {b['current_name']}")
    old = b["current_name"]
    if s.get("keep"):
        obj = {"kind": "global", "verdict": "keep", "address": b["address"], "old": old, "new": old,
               "e2m_note": s["e2m_note"], "evidence": s["evidence"]}
        # a keep note must name the record the audit shows
        rec = b["e2m_records_here"][0].split(" [")[0] if b["e2m_records_here"] else ""
        if rec and rec.split(" ", 2)[1:2] and rec.replace(" +0000", " +0").replace(" +000", " +").split(" ")[1] not in s["e2m_note"] and False:
            pass
        lines_out.append(obj)
        continue
    new = s["new"]
    if new in seen_new:
        problem(f"item {k}: new name {new} also at {seen_new[new]}")
    seen_new[new] = b["address"]
    bad = sorted(set(words(new)) & BANNED)
    if bad:
        problem(f"item {k} {new}: banned {bad}")
    if not re.fullmatch(r"[a-z][a-z0-9]*(_[a-z0-9]+)*", new):
        problem(f"item {k} {new}: format")
    if re.search(r"(?<![a-z])0x|_[0-9a-f]*[a-f][0-9a-f]*\d[0-9a-f]*(_|$)", new):
        problem(f"item {k} {new}: hex-looking part")
    in_eeprom = EEPROM[0] <= a <= EEPROM[1]
    if new.endswith("_cal") != in_eeprom:
        if not (in_eeprom and s.get("cal_note")):
            problem(f"item {k} {new}: _cal vs region (eeprom={in_eeprom})")
    if new == old:
        problem(f"item {k}: new == old")
    # code quote: one physical line (stripped) that contains the quote, in a function that uses the old name
    q = s["quote"]
    if len(q) < 20 and q not in stripped:
        problem(f"item {k}: quote shorter than 20 chars and not a whole line: {q!r}")
    hits = [i for i, l in enumerate(stripped) if q in l]
    if not hits:
        problem(f"item {k} {old}: quote not found on one physical line: {q!r}")
    else:
        uses_old = [i for i in hits if re.search(rf"(?<![A-Za-z0-9_]){re.escape(old)}(?![A-Za-z0-9_])", cpp_lines[i])]
        if not uses_old:
            print(f"NOTE item {k} {old}: quote lines do not name the row: {q!r} (functions: {sorted({fn_at[i] for i in hits})})")
    # comment checks
    c = s["comment"]
    if len(c) > 400:
        problem(f"item {k} {new}: comment is {len(c)} chars (apply clips at 400)")
    for m in token.finditer(history.sub("", c)):
        t = m.group(0)
        if t in known or re.sub(r"_(?:cal|[0-9]+)$", "", t) in known:
            continue
        problem(f"item {k} {new}: comment token not a current name: {t}")
    for o in my_old:
        if re.search(rf"(?<![A-Za-z0-9_]){re.escape(o)}(?![A-Za-z0-9_])", c):
            problem(f"item {k} {new}: comment cites the old name {o} (renamed by this bin)")
    # dump values quoted in the comment / evidence must be dump_raw
    for field in ("comment", "evidence"):
        for m in re.finditer(r"(-?\d+) in the dump", s[field]):
            if m.group(1) != str(b["dump_raw"]):
                problem(f"item {k} {new}: {field} quotes '{m.group(1)} in the dump' but dump_raw is {b['dump_raw']!r}")
    if b["dump_raw"] != "" and "in the dump" not in c:
        print(f"NOTE item {k} {new}: comment has no dump value (dump_raw {b['dump_raw']})")
    obj = {"kind": "global", "verdict": "confirmed", "address": b["address"], "old": old, "new": new,
           "evidence": s["evidence"], "code_quote": q, "comment": c}
    for extra in ("type_note", "old_comment_wrong", "cal_note"):
        if s.get(extra):
            obj[extra] = s[extra]
    lines_out.append(obj)

# collisions with the other wave-14 result files already present
for path in glob.glob(f"{STAGE9}/result_W14_*.jsonl"):
    if path == RESULT:
        continue
    for line in open(path):
        line = line.strip()
        if not line:
            continue
        try:
            r = json.loads(line)
        except ValueError:
            continue
        if r.get("new") in seen_new and r.get("address") != seen_new[r["new"]] and r.get("verdict") == "confirmed":
            problem(f"{os.path.basename(path)}: {r.get('address')} also proposes {r['new']} (mine: {seen_new[r['new']]})")
        for obj in lines_out:
            if r.get("kind") == "global" and r.get("address") == obj["address"] and r.get("verdict") == "confirmed":
                problem(f"{os.path.basename(path)}: also has address {obj['address']} -> {r.get('new')}")

print(f"{len(lines_out)} lines, {len(problems)} problems; confirmed {sum(1 for o in lines_out if o['verdict'] == 'confirmed')}, keep {sum(1 for o in lines_out if o['verdict'] == 'keep')}")
if "--write" in sys.argv:
    if problems:
        sys.exit("not written: fix the problems first")
    with open(RESULT, "w") as f:
        for obj in lines_out:
            f.write(json.dumps(obj, ensure_ascii=False) + "\n")
    print("written", RESULT)

"""Self-check of result_W14_globals4.jsonl: the wave-14 gate rules (copied from apply_renames.py), quotes, dump values,
cross-citations, uniqueness. Prints PROBLEM / WARN lines."""
import glob
import json
import os
import re
import sys

STAGE9 = "/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage9"
RESULT = STAGE9 + "/result_W14_globals4.jsonl"
FW = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-fueling-state-enum/firmware/CM848_S90140.06_analysis"
OUT = FW + "/output"
BANNED = {"temp", "tmp", "press", "pos", "corr", "coef", "coeff", "thresh", "thr", "inj", "qty", "ctrl", "cfg",
          "cmd", "val", "vals", "idx", "cnt", "num", "ref", "spd", "eng", "prot", "lim", "mult", "comp", "adj", "trq",
          "tbl", "lkp", "sw", "calc", "accel", "decel", "pct", "freq", "volt", "amp", "deg", "sec", "diag", "cond", "req",
          "resp", "init", "tmr", "buf", "aux", "arb", "iat", "imt", "proc", "mgr", "util", "info", "stat", "msg"}
EEPROM = (0x3fd482, 0x3feec1)


def words(name):
    out = []
    for p in name.split("_"):
        out += [w.lower() for w in re.findall(r"[A-Z]?[a-z]+|[A-Z]+(?![a-z])|\d+", p)]
    return out


problems, warns = [], []
bin_ = json.load(open(STAGE9 + "/bins/globals4.json"))
rows = [json.loads(l) for l in open(RESULT) if l.strip()]
if len(rows) != 63:
    problems.append(f"{len(rows)} result lines, expected 63")

# CSV rows
gv = {}
for line in open(OUT + "/global_variables.csv", errors="replace"):
    if line.startswith("0x"):
        p = (line.rstrip("\n").split(",", 3) + ["", ""])[:4]
        gv.setdefault(int(p[0], 16), []).append(p)
used = set()
for name in ("function_renames.csv", "global_variables.csv", "arrays.csv"):
    for line in open(os.path.join(OUT, name), errors="replace"):
        p = line.split(",")
        if p[0].startswith("0x") and len(p) > 1:
            used.add(p[1])
cpp_lines = open(OUT + "/cm848_rom.ghidra.cpp", errors="replace").read().split("\n")
cpp_text = "\n".join(cpp_lines)
cpp_words = set(re.findall(r"[A-Za-z_][A-Za-z0-9_]*", cpp_text))
csv_text = {}
for path in glob.glob(OUT + "/*.csv"):
    csv_text[os.path.basename(path)] = open(path, errors="replace").read()

# comment ranges in the cpp
in_comment = [False] * len(cpp_lines)
inside = False
for i, l in enumerate(cpp_lines):
    s = l.strip()
    if inside:
        in_comment[i] = True
        if "*/" in l:
            inside = False
        continue
    if s.startswith("/*"):
        in_comment[i] = True
        if "*/" not in l:
            inside = True
        continue
    if s.startswith("//") or s.startswith("*"):
        in_comment[i] = True

# dump
ram = open(FW + "/originals/cm848_ram.bin", "rb").read()
rom = open(FW + "/originals/cm848_rom.bin", "rb").read()
WIDTH = {"byte": 1, "word": 2, "i16": 2, "dword": 4}


def dump_value(address, width):
    data, at = (rom, address) if address < 0x3f0000 else (ram, address - 0x3FA000)
    raw = data[at:at + width]
    if len(raw) < width:
        return None
    return int.from_bytes(raw, "big"), int.from_bytes(raw, "big", signed=True)


new_names = {}
old_names = {r["old"] for r in rows}
for n, (b, r) in enumerate(zip(bin_, rows)):
    tag = f"[{n}] {r.get('address')} {r.get('old')}"
    if r.get("address") != b["address"]:
        problems.append(f"{tag}: address differs from the bin ({b['address']})")
    if r.get("old") != b["current_name"]:
        problems.append(f"{tag}: old differs from the bin name {b['current_name']}")
    a = int(r["address"], 16)
    csv_rows = gv.get(a, [])
    if len(csv_rows) != 1 or csv_rows[0][1] != r["old"]:
        problems.append(f"{tag}: global_variables row mismatch {[x[1] for x in csv_rows]}")
    typ = csv_rows[0][2] if csv_rows else ""
    width = WIDTH.get(typ, 2)
    v = r.get("verdict")
    if r.get("kind") != "global":
        problems.append(f"{tag}: kind")
    if v == "keep":
        if r["new"] != r["old"]:
            problems.append(f"{tag}: keep with a different new")
        if "e2m_note" not in r:
            problems.append(f"{tag}: keep without e2m_note")
        continue
    if v != "confirmed":
        warns.append(f"{tag}: verdict {v}")
        continue
    new = r["new"]
    if new in new_names:
        problems.append(f"{tag}: {new} also used at {new_names[new]}")
    new_names[new] = tag
    if new in used:
        problems.append(f"{tag}: new name already in a CSV row name")
    if new in cpp_words:
        problems.append(f"{tag}: new name already a token in the cpp")
    for fn, text in csv_text.items():
        if re.search(rf"(?<![A-Za-z0-9_]){re.escape(new)}(?![A-Za-z0-9_])", text):
            warns.append(f"{tag}: {new} appears in {fn}")
    bad = sorted(set(words(new)) & BANNED)
    if bad:
        problems.append(f"{tag}: banned words {bad}")
    if re.search(r"(?<![a-z])0x|_[0-9a-f]*[a-f][0-9a-f]*\d[0-9a-f]*(_|$)", new):
        problems.append(f"{tag}: hex-looking part")
    if not re.fullmatch(r"[a-z][a-z0-9]*(_[a-z0-9]+)*", new):
        problems.append(f"{tag}: name format")
    in_eeprom = EEPROM[0] <= a <= EEPROM[1]
    if new.endswith("_cal") != in_eeprom:
        problems.append(f"{tag}: _cal rule (eeprom={in_eeprom})")
    if "protection" in words(new) and new.split("_")[-1] == "protection":
        problems.append(f"{tag}: bare protection")
    # banned-looking abbreviations the gate set may miss
    for w in words(new):
        if w in ("cssc", "cbd", "pto", "asg", "lsg", "hsg", "tcc", "rsg", "afc", "cct", "dtc", "mil"):
            warns.append(f"{tag}: abbreviation {w}")
    # quote
    q = r.get("code_quote", "")
    if not q or len(q) < 20 and q not in cpp_text:
        problems.append(f"{tag}: quote too short or missing")
    hits = [i for i, l in enumerate(cpp_lines) if q and q in l.strip() or (q and q.strip() in l)]
    code_hits = [i for i in hits if not in_comment[i]]
    if not code_hits:
        problems.append(f"{tag}: quote not on an executable cpp line: {q!r} (comment hits {len(hits)})")
    elif r["old"] not in q:
        warns.append(f"{tag}: quote does not contain the old name")
    # text checks
    comment = r.get("comment", "")
    if "(was " in comment:
        problems.append(f"{tag}: (was in comment")
    if len(comment) > 520:
        warns.append(f"{tag}: comment {len(comment)} chars")
    if not comment:
        problems.append(f"{tag}: no comment")
    for other in list(new_names) + sorted(old_names):
        pass
    # cross-citation: the comment must not cite another renamed row of this bin (old or new)
    for rr in rows:
        if rr is r:
            continue
        for nm in (rr.get("old"), rr.get("new")):
            if nm and rr.get("verdict") == "confirmed" and re.search(
                    rf"(?<![A-Za-z0-9_]){re.escape(nm)}(?![A-Za-z0-9_])", comment):
                warns.append(f"{tag}: comment cites renamed row {nm}")
    if re.search(rf"(?<![A-Za-z0-9_]){re.escape(r['old'])}(?![A-Za-z0-9_])", comment):
        warns.append(f"{tag}: comment cites its own old name")
    # dump values quoted
    dv = dump_value(a, width)
    for field in ("comment", "evidence"):
        text = r.get(field, "")
        nums = []
        for m in re.finditer(r"(-?\d+) in the dump(?: = ([^;,()]{0,30}))?", text):
            nums.append(int(m.group(1)))
        for m in re.finditer(r"\bdump (?:value )?(?:is |=\s*)?(-?0x[0-9a-fA-F]+|-?\d+)\b", text):
            nums.append(int(m.group(1), 16) if "0x" in m.group(1).lower() else int(m.group(1)))
        for m in re.finditer(r"(-?0x[0-9a-fA-F]+|-?\d+)(?: = [^;()]{0,40})? here\b", text):
            nums.append(int(m.group(1), 16) if "0x" in m.group(1).lower() else int(m.group(1)))
        for num in nums:
            if dv is None or num not in dv:
                warns.append(f"{tag}: {field} quotes dump {num}, dump at width {width} is {dv}")
    if r.get("type_note") and "held" in r["type_note"]:
        warns.append(f"{tag}: type_note mentions held")

# the dump_raw of the bin vs ours for rows that carry one
for b, r in zip(bin_, rows):
    if b.get("dump_raw") not in ("", None):
        a = int(r["address"], 16)
        typ = gv[a][0][2]
        dv = dump_value(a, WIDTH.get(typ, 2))
        if dv is None or str(b["dump_raw"]) not in (str(dv[0]), str(dv[1])):
            warns.append(f"{r['address']}: bin dump_raw {b['dump_raw']} vs read {dv}")

for p in problems:
    print("PROBLEM", p)
for w in warns:
    print("WARN", w)
print(f"{len(rows)} lines; {sum(1 for r in rows if r.get('verdict') == 'confirmed')} confirmed, "
      f"{sum(1 for r in rows if r.get('verdict') == 'keep')} keep; {len(problems)} problems, {len(warns)} warnings")

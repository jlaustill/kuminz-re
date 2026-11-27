"""J2 investigator (round 93, read-only): checks result.json against the frozen CSVs.
usage: validate_result.py [result.json]"""
import csv
import json
import os
import re
import sys

csv.field_size_limit(10 ** 9)
here = os.path.dirname(os.path.abspath(__file__))
frozen = "/home/linux/.claude/jobs/374b0424/tmp/w15/r93/frozen"
res = json.load(open(sys.argv[1] if len(sys.argv) > 1 else os.path.join(here, "result.json")))


def rows(path):
    out = []
    for line in csv.reader(open(path, errors="replace")):
        if not line or line[0].startswith("#"):
            continue
        out.append(line)
    return out


def addr(s):
    try:
        return int(s, 16)
    except ValueError:
        return None


fn = {}
gl = {}
for fw in ("cm550", "cm848"):
    f = {}
    for r in rows(f"{frozen}/{fw}/function_renames.csv"):
        a = addr(r[0])
        if a is None or len(r) < 2:
            continue
        f.setdefault(a, []).append(r[1])
    fn[fw] = f
    g = {}
    for r in rows(f"{frozen}/{fw}/global_variables.csv"):
        a = addr(r[0])
        if a is None or len(r) < 3:
            continue
        g[a] = (r[1], r[2])
    gl[fw] = g

fn_names = {fw: {n for v in fn[fw].values() for n in v} for fw in fn}
gl_names = {fw: {v[0] for v in gl[fw].values()} for fw in gl}
struct_names = {}
struct_fields = {}
for fw in ("cm550", "cm848"):
    s = {}
    for r in rows(f"{frozen}/{fw}/structure_definitions.csv"):
        if r[0] == "struct_name":
            continue
        s.setdefault(r[0], []).append(r)
    struct_names[fw] = set(s)
    struct_fields[fw] = s
enum_rows = {}
for fw in ("cm550", "cm848"):
    e = {}
    for r in rows(f"{frozen}/{fw}/enums.csv"):
        if r[0] == "enum_name":
            continue
        try:
            v = int(r[1], 0)
        except ValueError:
            continue
        e[(r[0], v)] = r[2]
    enum_rows[fw] = e

problems = []
P = problems.append

# ---- coverage ----
need = [0x1fdc0, 0x1ff38, 0x212b2, 0x2142c, 0x216c6, 0x21778, 0x21872, 0x21920, 0x21f4e, 0x21fac, 0x22070, 0x231da,
        0x23244, 0x23216]
seen = {}
for f in res["functions"]:
    seen.setdefault(addr(f["address"]), []).append("functions")
for s in res["skipped"]:
    seen.setdefault(addr(s["address"]), []).append("skipped")
for a in need:
    if len(seen.get(a, [])) != 1:
        P(f"coverage: 0x{a:x} appears {seen.get(a)}")
for a, v in seen.items():
    if len(v) != 1:
        P(f"duplicate address 0x{a:x}: {v}")

# ---- functions ----
props = {}
for f in res["functions"]:
    a = addr(f["address"])
    cur = fn["cm550"].get(a)
    if not cur or f["current_name"] not in cur:
        P(f"function 0x{a:x}: current_name {f['current_name']} != row {cur}")
    p = f["proposed_name"]
    props.setdefault(p, []).append(a)
    if p != f["current_name"] and p in fn_names["cm550"]:
        P(f"function 0x{a:x}: proposed {p} already in CM550 function_renames.csv")
    if p in gl_names["cm550"]:
        P(f"function 0x{a:x}: proposed {p} is a CM550 global name")
    unpref = not re.match(r"(cm550|vp44|mc68k)_", p)
    if f["relation"] == "twin":
        if not unpref:
            P(f"function 0x{a:x}: twin but prefixed {p}")
        if not f.get("cm848_address"):
            P(f"function 0x{a:x}: twin without cm848_address")
    elif unpref and p != f["current_name"]:
        P(f"function 0x{a:x}: relation {f['relation']} but unprefixed {p}")
    if f.get("cm848_address"):
        ca = addr(f["cm848_address"])
        ccur = fn["cm848"].get(ca)
        if not ccur or f.get("cm848_current_name") not in ccur:
            P(f"function 0x{a:x}: cm848_current_name {f.get('cm848_current_name')} != CM848 row {ccur} at 0x{ca:x}")
        if f["relation"] == "twin" and p in fn_names["cm848"] and p not in (ccur or []):
            P(f"function 0x{a:x}: twin name {p} already used elsewhere in CM848")
    if not re.fullmatch(r"[a-z][A-Za-z0-9]*(_[a-z][A-Za-z0-9]*)?", p):
        P(f"function 0x{a:x}: name shape {p}")
    for field in ("role", "discriminator", "plate_comment", "evidence", "confidence", "relation"):
        if not f.get(field):
            P(f"function 0x{a:x}: empty {field}")
for p, v in props.items():
    if len(v) > 1:
        P(f"proposed function name {p} used by {[hex(x) for x in v]}")

# ---- globals ----
gprops = {}
width = {"byte": 1, "sbyte": 1, "word": 2, "short": 2, "dword": 4, "pointer": 4}
extent_hits = []
for g in res.get("globals", []):
    fw = g["firmware"].lower()
    a = addr(g["address"])
    row = gl[fw].get(a)
    cur = row[0] if row else ""
    if cur != g["current_name"]:
        P(f"global {fw} 0x{a:x}: current_name '{g['current_name']}' != row '{cur}'")
    p = g["proposed_name"]
    gprops.setdefault((fw, p), []).append(a)
    if p != cur and p in gl_names[fw]:
        P(f"global {fw} 0x{a:x}: proposed {p} already a global in {fw}")
    if p in fn_names[fw]:
        P(f"global {fw} 0x{a:x}: proposed {p} is a function name")
    if not re.fullmatch(r"[a-z][a-z0-9]*(_[a-z0-9]+)*", p):
        P(f"global {fw} 0x{a:x}: name shape {p}")
    lo, hi = (0x803B0A, 0x804155) if fw == "cm550" else (0x3fd482, 0x3feec1)
    if p.endswith("_cal") != (lo <= a <= hi):
        P(f"global {fw} 0x{a:x}: _cal mismatch for {p}")
    t = g["proposed_type"]
    m = re.fullmatch(r"(\w+)(?:\[(\d+)\])?", t)
    if not m:
        P(f"global {fw} 0x{a:x}: type shape {t}")
        continue
    base, n = m.group(1), int(m.group(2) or 1)
    if base in width:
        size = width[base] * n
        if width[base] > 1 and a % 2:
            P(f"global {fw} 0x{a:x}: {t} at an odd address")
    else:
        size = None
        if base not in struct_names[fw]:
            extent_hits.append(f"global {fw} 0x{a:x}: type {t} is not in {fw} structure_definitions.csv (new struct)")
        else:
            sz = sum(int(r[4]) for r in struct_fields[fw][base] if r[4].isdigit())
            extent_hits.append(f"global {fw} 0x{a:x}: struct {base} exists in {fw}, summed field sizes {sz}")
    g["_size"] = size
    if row and row[1] != t:
        extent_hits.append(f"global {fw} 0x{a:x}: type changes {row[1]} -> {t}")
for (fw, p), v in gprops.items():
    if len(v) > 1:
        P(f"proposed global name {p} used by {[hex(x) for x in v]} in {fw}")

# ---- enum members ----
for e in res.get("enum_members", []):
    fw = "cm550" if e["firmware"] in ("CM550", "both") else "cm848"
    cur = enum_rows[fw].get((e["enum_name"], int(e["value"])))
    if not e["current_member"] and any(k[0] == e["enum_name"] for k in enum_rows[fw]):
        P(f"enum {e['enum_name']}: proposed as new but the enum exists in {fw}")
    if (cur or "") != e["current_member"]:
        P(f"enum {e['enum_name']} {e['value']}: current_member '{e['current_member']}' != row '{cur}'")
    other = enum_rows["cm848"].get((e["enum_name"], int(e["value"])))
    extent_hits.append(f"enum {e['enum_name']} {int(e['value']):#x}: CM848 member {other} / proposed {e['proposed_member']}")
    if other and other != e["proposed_member"]:
        P(f"enum {e['enum_name']} {e['value']}: proposed {e['proposed_member']} != CM848's {other}")

print("\n".join(problems) or "no problems")
print("---- information")
print("\n".join(extent_hits))

import csv, json, re, sys

OUT = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-typing-arrays/firmware/CM848_S90140.06_analysis/output/"
RES = "/home/linux/.claude/jobs/d55ae3c6/tmp/renames/result_W6_injection_rail.jsonl"


def rows(fn):
    with open(OUT + fn, newline="") as f:
        for r in csv.reader(f):
            if not r or not r[0].startswith("0x"):
                continue
            yield r


G = {}
for r in rows("global_variables.csv"):
    G.setdefault(int(r[0], 16), []).append(r)
F = {}
for r in rows("function_renames.csv"):
    F[int(r[0], 16)] = r
A = {}
for r in rows("arrays.csv"):
    A[int(r[0], 16)] = r
allnames = set()
for tab in (G.values(),):
    for lst in tab:
        for r in lst:
            allnames.add(r[1])
for r in F.values():
    allnames.add(r[1])
for r in A.values():
    allnames.add(r[1])
structs = {}
with open(OUT + "structure_definitions.csv", newline="") as _f:
    for r in csv.reader(_f):
        if len(r) > 2 and r[0] and not r[0].startswith("#"):
            structs.setdefault(r[0], set()).add(r[2])

errs = []
new_seen = {}
objs = []
for i, line in enumerate(open(RES)):
    try:
        o = json.loads(line)
    except Exception as e:
        errs.append("line %d: JSON error %s" % (i + 1, e))
        continue
    objs.append(o)
BAD_TOKENS = {"init", "arb", "abs", "alt", "calc", "prev", "ptr", "cfg", "tmp", "val", "cnt", "idx", "snap", "reg", "thr", "temp", "cmd", "req", "pos", "mgr", "ctx"}


def tokens(name):
    t = re.sub(r"([a-z0-9])([A-Z])", r"\1_\2", name)
    return [x.lower() for x in t.split("_") if x]


def check_name(kind, addr, new):
    if new in allnames:
        errs.append("%s %s: new name already exists: %s" % (kind, addr, new))
    if new in new_seen:
        errs.append("%s %s: new name duplicated in file (also %s): %s" % (kind, addr, new_seen[new], new))
    new_seen[new] = addr
    if re.search(r"0x", new) or re.search(r"\b[0-9a-f]*[a-f][0-9a-f]{3,}\b", new.replace("_", " ")):
        errs.append("%s %s: hex-like name %s" % (kind, addr, new))
    for t in tokens(new):
        if t in BAD_TOKENS:
            errs.append("%s %s: banned fragment %s in %s" % (kind, addr, t, new))
        if t == "protection":
            errs.append("%s %s: bare protection in %s" % (kind, addr, new))
    if kind == "function" and not new.startswith("cm848_"):
        errs.append("function %s: name not cm848_ prefixed: %s" % (addr, new))
    if kind != "function" and not re.fullmatch(r"[a-z][a-z0-9_]*", new):
        errs.append("%s %s: name not snake_case: %s" % (kind, addr, new))


def eeprom(a):
    return 0x3fd482 <= a <= 0x3feec1


def timeshared(a):
    return 0x3F9800 <= a <= 0x3FDB30 or 0x3fee08 <= a <= 0x3fee3d


counts = {}
for o in objs:
    k = o["kind"]
    counts[k] = counts.get(k, 0) + 1
    if k == "function":
        a = int(o["address"], 16)
        cur = F.get(a)
        if cur is None:
            errs.append("function %s: no row in function_renames.csv" % o["address"])
        elif cur[1] != o["old"]:
            errs.append("function %s: old %s != CSV %s" % (o["address"], o["old"], cur[1]))
        if o["verdict"] == "confirmed" and o.get("new"):
            check_name("function", o["address"], o["new"])
            if not o.get("plate_comment"):
                errs.append("function %s: no plate_comment" % o["address"])
            if "(was %s" % o["old"] not in o.get("plate_comment", ""):
                errs.append("function %s: plate lacks (was old)" % o["address"])
    elif k == "global":
        a = int(o["address"], 16)
        rs = G.get(a)
        if not rs:
            errs.append("global %s: no row in global_variables.csv" % o["address"])
        else:
            if rs[0][1] != o["old"]:
                errs.append("global %s: old %r != CSV %r" % (o["address"], o["old"], rs[0][1]))
        if o.get("new"):
            check_name("global", o["address"], o["new"])
            hascal = o["new"].endswith("_cal")
            if eeprom(a) and not hascal:
                errs.append("global %s: EEPROM range but no _cal: %s" % (o["address"], o["new"]))
            if not eeprom(a) and hascal:
                errs.append("global %s: _cal outside EEPROM range: %s" % (o["address"], o["new"]))
            if timeshared(a) and not ("7F60" in o["evidence"] or "boot" in o["evidence"].lower()):
                errs.append("global %s: time-shared word, evidence lacks boot-ROM user statement" % o["address"])
    elif k == "new_global":
        a = int(o["address"], 16)
        if a in G:
            errs.append("new_global %s: row already exists %s" % (o["address"], G[a][0][1]))
        check_name("new_global", o["address"], o["new"])
        if eeprom(a) != o["new"].endswith("_cal"):
            errs.append("new_global %s: _cal rule" % o["address"])
    elif k == "struct_field":
        if o["old"] not in structs.get(o["struct"], set()):
            errs.append("struct_field %s.%s: not in structure_definitions.csv" % (o["struct"], o["old"]))
        if o["new"] in structs.get(o["struct"], set()):
            errs.append("struct_field %s: new field name exists" % o["new"])
        for t in tokens(o["new"]):
            if t in BAD_TOKENS:
                errs.append("struct_field banned fragment %s" % t)
    elif k == "note":
        pass
    else:
        errs.append("unknown kind %s" % k)

# every text token with underscores in plate comments / comments: must exist as a name, a new name, or an old name
known = set(allnames) | set(new_seen)
for s in structs.values():
    known |= s
for o in objs:
    known.add(o.get("old", ""))
unk = {}
for o in objs:
    for fld in ("plate_comment", "comment"):
        txt = o.get(fld, "")
        for tkn in re.findall(r"[A-Za-z][A-Za-z0-9]*(?:_[A-Za-z0-9]+)+", txt):
            base = tkn
            if base not in known and base.lower() not in known:
                unk.setdefault(base, o.get("address"))
print("counts", counts)
print("ERRORS:", len(errs))
for e in errs:
    print("  ", e)
print("tokens in plate/comment not known as a name (review):")
for k, v in sorted(unk.items()):
    print("  ", k, v)

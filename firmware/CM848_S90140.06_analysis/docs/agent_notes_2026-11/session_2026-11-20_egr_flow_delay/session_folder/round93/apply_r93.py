"""Round 93 (CM550, and CM848 for twins / shared enum members): apply the judged elements of workflow
wf_9501d76c-676 (per call-graph family: an investigator, an independent describer who did not see the proposals, and
a judge with both). Input: batch_<id>.json = {proposal, blind, verdict}.

An element is applied when its judge verdict is CONFIRMED or AMENDED; the judge's exact final_name / final_type /
final_relation / final_cm848_address / final_comment win over the proposal's. REFUTED or unjudged elements are
skipped and reported. OVERRIDES (overrides_r93.json, written by hand from the review of the verdicts, each entry with
its reason) can drop an element or replace a final value.
- functions: the CM550 row renamed with the plate comment; a twin also renames CM848's row to the same unprefixed
  name (its comment keeps its text and gains a twin note). function_definitions.csv / local_variables.csv follow.
- globals: the row renamed / retyped / commented (inserted when there is none; an older comment stays as
  '| earlier note: ...').
- enum members: renamed in the firmware(s) named (both = both enums.csv); a new member is added after its enum's rows.
Checks that refuse the whole apply: a final name used twice in a firmware, a twin with a firmware prefix or a
non-twin without one (unless the name is unchanged), _cal outside / missing inside the EEPROM mirror, an unknown type.
Writes the refresh maps (old -> new) per firmware. Idempotent; keeps line endings.
usage: apply_r93.py <repo> <outdir> <batch_X.json>..."""
import csv
import json
import os
import re
import sys

repo, outdir, batches = os.path.abspath(sys.argv[1]), sys.argv[2], sys.argv[3:]
R = "PR #53 round 93"
DIRS = {"CM550": os.path.join(repo, "firmware/CM550_J90350.00_analysis/output"),
        "CM848": os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")}
MIRROR = {"CM550": (0x803B0A, 0x804155), "CM848": (0x3fd482, 0x3feec1)}
PREFIXES = {"CM550": ("cm550_", "mc68k_", "vp44_"), "CM848": ("cm848_", "mpc555_", "hpcr_")}
ANY_PREFIX = PREFIXES["CM550"] + PREFIXES["CM848"]
PRIMITIVES = {"byte", "sbyte", "char", "uchar", "word", "short", "ushort", "dword", "int", "uint", "long", "ulong",
              "bool", "i16", "u16", "i32", "u32", "pointer", "undefined", "undefined1", "undefined2", "undefined4"}
FILES = ("global_variables.csv", "function_renames.csv", "function_definitions.csv", "local_variables.csv", "enums.csv",
         "structure_definitions.csv")
OVERRIDES = {}
OP = os.path.join(os.path.dirname(os.path.abspath(__file__)), "overrides_r93.json")
if os.path.exists(OP):
    OVERRIDES = json.load(open(OP))


def read(p):
    return open(p, newline="").read()


def norm(a):
    return f"0x{int(str(a).strip(), 16):08x}"


def clean(text):
    return " ".join(str(text or "").split())


INSTRUCTION = re.compile(r"^\s*(append|prepend|keep|add to|replace|insert|same as|unchanged|see above)\b|current comment|existing comment", re.I)


def checked_comment(text, label):
    """A comment must be the comment itself. Round 91 wrote a proposal's 'APPEND to the current comment: ...' in
    place of seven plate comments; such a text refuses the apply."""
    if INSTRUCTION.search(text or ""):
        problems.append(f"{label}: the comment reads like an instruction, not a comment: {text[:80]!r}")
    return text


def csv_field(text):
    """A comment for a CSV whose parser is quote-aware (enums.csv / structure_definitions.csv)."""
    text = clean(text)
    return '"' + text.replace('"', "'") + '"' if ("," in text or '"' in text) else text


state = {fw: {k: read(os.path.join(d, k)) for k in FILES} for fw, d in DIRS.items()}
types = {}
for fw in DIRS:
    known = set(PRIMITIVES)
    for row in csv.reader(state[fw]["structure_definitions.csv"].splitlines()):
        if row and not row[0].startswith("#"):
            known.add(row[0])
    for row in csv.reader(state[fw]["enums.csv"].splitlines()):
        if row and not row[0].startswith("#"):
            known.add(row[0])
    types[fw] = known
report, problems, maps = [], [], {"CM550": [], "CM848": []}
introduced = {"CM550": set(), "CM848": set()}     # the names this apply writes: each must be unique afterwards


def function_row(fw, a):
    return re.search(rf"^{a},([^,\r\n]*)(?:,([^\r\n]*))?$", state[fw]["function_renames.csv"], re.M)


def rename_function(fw, a, new, comment, label):
    t = state[fw]["function_renames.csv"]
    m = function_row(fw, a)
    if not m:
        problems.append(f"{label}: {fw} {a} has no function_renames.csv row")
        return None
    old = m.group(1)
    if old == new:
        return old
    state[fw]["function_renames.csv"] = t[:m.start()] + f"{a},{new},{comment(old, m.group(2) or '')}" + t[m.end():]
    introduced[fw].add(new)
    for k in ("function_definitions.csv", "local_variables.csv"):
        state[fw][k] = re.sub(rf"^({a},){re.escape(old)},", lambda x: x.group(1) + new + ",", state[fw][k], flags=re.M | re.I)
    maps[fw].append((a, new, old))
    return old


def verdict_index(vd):
    index = {}
    for v in vd:
        kind, address = v["kind"], str(v["address"]).strip()
        if kind == "enum_member":
            m = re.match(r"^(\w+)\s*[:=]\s*(0x[0-9a-fA-F]+|\d+)$", address)
            if not m:
                problems.append(f"verdict address not understood: {address}")
                continue
            key = (kind, m.group(1), int(m.group(2), 0))
        else:
            try:
                key = (kind, ("CM848" if v.get("firmware") == "CM848" else "CM550") if kind == "global" else "", norm(address))
            except ValueError:
                problems.append(f"verdict address not understood: {address}")
                continue
        index[key] = v
    return index


for path in batches:
    data = json.load(open(path))
    p, vd = data["proposal"], (data.get("verdict") or {}).get("verdicts", [])
    b = data.get("batch") or p.get("batch")
    index = verdict_index(vd)
    used = set()
    # ---------------------------------------------------------------- functions
    for f in p.get("functions") or []:
        a = norm(f["address"])
        key = ("function", "", a)
        v = index.get(key)
        used.add(key)
        ov = OVERRIDES.get(f"function|{a}", {})
        if ov.get("drop"):
            report.append(f"{b} DROPPED function {a} ({ov['reason']})")
            continue
        if not v or v["verdict"] == "REFUTED":
            report.append(f"{b} SKIP function {a} {f['current_name']} -> {f['proposed_name']} ({v['verdict'] if v else 'no verdict'})")
            continue
        new = ov.get("name") or clean(v.get("final_name")) or f["proposed_name"]
        relation = ov.get("relation") or clean(v.get("final_relation")).split(" ")[0].lower() or f["relation"]
        plate = checked_comment(ov.get("comment") or clean(v.get("final_comment")) or clean(f.get("plate_comment")), f"{b} function {a}")
        m = function_row("CM550", a)
        if not m:
            problems.append(f"{b}: CM550 {a} has no function_renames.csv row")
            continue
        old = m.group(1)
        if not re.match(r"^[A-Za-z][A-Za-z0-9_]*$", new):
            problems.append(f"{b}: function {a}: bad name {new!r}")
            continue
        if new != old:
            if relation == "twin" and new.startswith(ANY_PREFIX):
                problems.append(f"{b}: function {a}: twin name {new} carries a firmware prefix")
            if relation != "twin" and not new.startswith(PREFIXES["CM550"]):
                problems.append(f"{b}: function {a}: {relation} name {new} has no CM550 prefix")
        twin_address = ""
        if relation == "twin":
            raw = ov.get("cm848_address") or clean(v.get("final_cm848_address")) or clean(f.get("cm848_address"))
            hit = re.search(r"0x[0-9a-fA-F]+", raw)
            if not hit:
                problems.append(f"{b}: function {a}: twin without a CM848 address")
                continue
            twin_address = norm(hit.group(0))
        if new == old and not twin_address:
            report.append(f"{b} function {a} {old}: name kept")
            continue
        note = f" The twin of CM848 {twin_address}: one shared name." if twin_address else ""
        rename_function("CM550", a, new, lambda o, c: f"{plate}{note} (was {o}; {R})", b)
        report.append(f"{b} CM550 function {a} {old} -> {new} [{relation}]")
        if twin_address:
            was = rename_function("CM848", twin_address, new,
                                  lambda o, c: (f"{c} | " if c else "") + f"the twin of CM550 {a}: one shared name (was {o}; {R})", b)
            if was is not None:
                report.append(f"{b} CM848 function {twin_address} {was} -> {new} [twin of CM550 {a}]" if was != new
                              else f"{b} CM848 function {twin_address} already {new}")
    # ---------------------------------------------------------------- globals
    for g in p.get("globals") or []:
        fw = "CM848" if "848" in g["firmware"] else "CM550"
        a = norm(g["address"])
        key = ("global", fw, a)
        v = index.get(key)
        used.add(key)
        ov = OVERRIDES.get(f"global|{fw}|{a}", {})
        if ov.get("drop"):
            report.append(f"{b} DROPPED global {fw} {a} ({ov['reason']})")
            continue
        if not v or v["verdict"] == "REFUTED":
            report.append(f"{b} SKIP global {fw} {a} {g['current_name']} -> {g['proposed_name']} ({v['verdict'] if v else 'no verdict'})")
            continue
        new = ov.get("name") or clean(v.get("final_name")) or g["proposed_name"]
        typ = ov.get("type") or clean(v.get("final_type")) or g["proposed_type"]
        comment = checked_comment(ov.get("comment") or clean(v.get("final_comment")) or clean(g.get("comment")), f"{b} global {fw} {a}")
        if not re.match(r"^[a-z][a-z0-9_]*$", new):
            problems.append(f"{b}: global {fw} {a}: bad name {new!r}")
            continue
        base = re.match(r"^([A-Za-z0-9_]+)\s*(\*)?\s*(?:\[\d+\])?$", typ)
        if not base or base.group(1) not in types[fw]:
            problems.append(f"{b}: global {fw} {a} {new}: unknown type {typ!r}")
            continue
        lo, hi = MIRROR[fw]
        if new.endswith("_cal") != (lo <= int(a, 16) <= hi):
            problems.append(f"{b}: global {fw} {a} {new}: _cal does not match the EEPROM mirror")
            continue
        lines = state[fw]["global_variables.csv"].split("\n")
        idx = next((i for i, l in enumerate(lines) if l[:10].lower() == a and l[10:11] == ","), None)
        old, old_type, old_comment = "", "", ""
        if idx is not None:
            parts = lines[idx].split(",", 3)
            old, old_type, old_comment = parts[1], parts[2], (parts[3] if len(parts) > 3 else "")
        if idx is not None and old == new and old_type == typ:
            continue
        was = f" (was {old}; {R})" if old and old != new else f" ({R})"
        earlier = f" | earlier note: {old_comment}" if old_comment and old_comment not in comment else ""
        row = f"{a},{new},{typ},{comment}{was}{earlier}"
        if idx is not None:
            lines[idx] = row
        else:
            after = [i for i, l in enumerate(lines) if l.startswith("0x") and int(l.split(",")[0], 16) < int(a, 16)]
            lines.insert(after[-1] + 1, row)
        state[fw]["global_variables.csv"] = "\n".join(lines)
        introduced[fw].add(new)
        if old and old != new:
            maps[fw].append((a, new, old))
        report.append(f"{b} {fw} global {a} {old or '(no row)'} {old_type or ''} -> {new} {typ}")
    # ---------------------------------------------------------------- enum members
    for e in p.get("enum_members") or []:
        value = int(e["value"])
        key = ("enum_member", e["enum_name"], value)
        v = index.get(key)
        used.add(key)
        ov = OVERRIDES.get(f"enum|{e['enum_name']}|{value}", {})
        if ov.get("drop"):
            report.append(f"{b} DROPPED enum member {e['enum_name']} {value} ({ov['reason']})")
            continue
        if not v or v["verdict"] == "REFUTED":
            report.append(f"{b} SKIP enum member {e['enum_name']} {value} -> {e['proposed_member']} ({v['verdict'] if v else 'no verdict'})")
            continue
        new = ov.get("name") or clean(v.get("final_name")) or e["proposed_member"]
        comment = checked_comment(ov.get("comment") or clean(v.get("final_comment")) or clean(e.get("comment")), f"{b} enum {e['enum_name']} {value}")
        which = ov.get("firmware") or (v.get("firmware") if v.get("firmware") in ("CM550", "CM848", "both") else e["firmware"])
        if not re.match(r"^[A-Z][A-Z0-9_]*$", new):
            problems.append(f"{b}: enum member {e['enum_name']} {value}: bad name {new!r}")
            continue
        for fw in (("CM550", "CM848") if which == "both" else (which,)):
            lines = state[fw]["enums.csv"].split("\n")
            E = "\r" if lines and lines[0].endswith("\r") else ""
            rows = [(i, next(csv.reader([l.rstrip("\r")]))) for i, l in enumerate(lines) if l.startswith(e["enum_name"] + ",")]
            if not rows:
                problems.append(f"{b}: {fw} has no enum {e['enum_name']}")
                continue
            hit = [(i, r) for i, r in rows if int(r[1], 0) == value]
            if any(r[2] == new and int(r[1], 0) != value for _, r in rows):
                problems.append(f"{b}: {fw} {e['enum_name']} already has a member {new}")
                continue
            if hit:
                i, r = hit[0]
                if r[2] == new:
                    continue
                label = re.search(r"(Calterm \w+ [0-9A-Fa-f]+=\w+|e2m label \w+ \([^)]*\))", r[3] if len(r) > 3 else "")
                text = comment if (not label or label.group(1) in comment) else f"{comment} - {label.group(1)}"
                lines[i] = f"{r[0]},{r[1]},{new},{csv_field(f'{text} (was {r[2]}; {R})')},{r[4] if len(r) > 4 else ''}" + E
                maps[fw].append(("", new, r[2]))
                report.append(f"{b} {fw} enum {e['enum_name']} {value}: {r[2]} -> {new}")
            else:
                i, r = rows[-1]
                lines.insert(i + 1, f"{r[0]},{value},{new},{csv_field(f'{comment} ({R})')},{r[4] if len(r) > 4 else ''}" + E)
                report.append(f"{b} {fw} enum {e['enum_name']} {value}: new member {new}")
            state[fw]["enums.csv"] = "\n".join(lines)
    for key in index:
        if key not in used:
            report.append(f"{b} NOTE verdict with no proposal element: {key}")
# -------------------------------------------------------------------- whole-firmware checks
# (only the names this apply writes: both CSVs hold older repeats - switchD rows, struct member rows)
for fw in DIRS:
    holders = {}
    for row in csv.reader(state[fw]["function_renames.csv"].splitlines()):
        if row and row[0].startswith("0x"):
            holders.setdefault(row[1], []).append(f"function {row[0]}")
    for line in state[fw]["global_variables.csv"].split("\n"):
        parts = line.split(",", 2)
        if len(parts) > 1 and parts[0].startswith("0x") and parts[1]:
            holders.setdefault(parts[1], []).append(f"global {parts[0]}")
    for name in sorted(introduced[fw]):
        if len(holders.get(name, [])) != 1:
            problems.append(f"{fw}: the new name {name} is held by {holders.get(name)}")
if problems:
    print("REFUSED - nothing written:\n" + "\n".join(problems))
    sys.exit(1)
changed = 0
for fw, d in DIRS.items():
    for k, t in state[fw].items():
        if read(os.path.join(d, k)) != t:
            open(os.path.join(d, k), "w", newline="").write(t)
            changed += 1
    mp = os.path.join(outdir, f"map_r93_{fw.lower()}.csv")
    if maps[fw] or not os.path.exists(mp):      # a re-run (nothing left to rename) must not empty the map
        with open(mp, "w") as fh:
            fh.write("address,name,old_label,kind,dims\n")
            for a, n, o in maps[fw]:
                fh.write(f"{a},{n},{o},symbol,1\n")
if changed or not os.path.exists(os.path.join(outdir, "apply_report_r93.txt")):
    open(os.path.join(outdir, "apply_report_r93.txt"), "w").write("\n".join(report) + "\n")
print("\n".join(r for r in report if " SKIP " in r or " DROPPED " in r or " NOTE " in r) or "no skips")
print(f"{len(report)} report lines; {changed} files written; maps: " + str({k: len(v) for k, v in maps.items()}))

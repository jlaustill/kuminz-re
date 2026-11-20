"""Wave 14 inputs: three function bins and three global bins.
- Functions: the renames the wave-12 / wave-13 agents proposed in their reports (function_leads.json, from
  extract_function_leads.py) plus the leads added by hand below, each with its current plate, callers and callees. The
  diagnostic-session / RAM refresh functions and the two held enum-typed rows go together into the last bin.
- Globals: global_worklist_kept.json (sibling rows of the families waves 13 / 8c renamed: low token overlap or a wrong
  _cal, plus every row a wave-13 report named by address), with the e2m record, the region, the access widths, up to 6
  code lines, the block's named rows, and the report lines that mention the address.
usage: build_context_W14.py <stage9 dir> <stage8 dir> <audit.csv> <repo>"""
import collections
import csv
import glob
import json
import os
import re
import subprocess
import sys

here, stage8, audit_path, repo = sys.argv[1:5]
T = os.path.dirname(here.rstrip("/"))
OUT = os.path.join(repo, "firmware", "CM848_S90140.06_analysis", "output")
lines = open(os.path.join(OUT, "cm848_rom.ghidra.cpp"), errors="replace").read().split("\n")
function_at, current, bodies = [], "", collections.defaultdict(list)
for line in lines:
    m = re.match(r"// Function: (\S+)", line)
    if m:
        current = m.group(1)
    function_at.append(current)
    bodies[current].append(line)
reports = {os.path.basename(p): open(p).read() for p in glob.glob(os.path.join(stage8, "reports", "*.md"))}


def report_lines(token):
    out = []
    for name, text in sorted(reports.items()):
        for line in text.split("\n"):
            if token in line:
                out.append(f"{name}: {' '.join(line.split())[:500]}")
    return out[:4]


# ---- functions
plates, by_name = {}, {}
for line in open(os.path.join(OUT, "function_renames.csv"), errors="replace"):
    if line.startswith("0x"):
        parts = (line.rstrip("\r\n").split(",", 2) + [""])[:3]
        plates[int(parts[0], 16)] = parts[2]
        by_name[parts[1]] = int(parts[0], 16)
leads = json.load(open(os.path.join(here, "function_leads.json")))
MANUAL = [
    ("0x00013dc8", "cm848_calculatePressureSensorFiltered", "cm848_filterIntakeManifoldTemperature",
     "review_e2m_names_wave_13_bin_2.md"),
    ("0x00533b18", "diag_protection_history_increment", "cm848_incrementEngineStartCountsSinceFaultLogged",
     "review_e2m_names_wave_13_bin_3.md"),
    ("0x00533b5c", "diag_protection_history_shiftIn", "cm848_shiftInEngineStartCountsSinceFaultLogged",
     "review_e2m_names_wave_13_bin_3.md"),
    ("0x00533b94", "diag_protection_history_shift", "cm848_shiftEngineStartCountsSinceFaultLogged",
     "review_e2m_names_wave_13_bin_3.md"),
    ("0x00021624", "cm848_activateDiagnosticSession", None, "review_e2m_names_wave_13_bin_2.md"),
    ("0x00021668", "cm848_resetDiagnosticSession", None, "review_e2m_names_wave_13_bin_2.md"),
    ("0x00021694", "cm848_forceActivateDiagnosticSession", None, "review_e2m_names_wave_13_bin_2.md"),
    ("0x00026f80", "cm848_j1939FormatDm1Message", None, "wave 12 (task 045): it is the TSC1 lost management"),
    ("0x00027bc4", "cm848_governorDroopCalculation", None, "wave 12 (task 045): it is a number-to-text helper"),
]
have = {e["address"] for e in leads}
for address, old, new, source in MANUAL:
    assert by_name.get(old) == int(address, 16), (address, old)
    if address in have:
        continue
    token = f"0x{int(address, 16):x}"
    reason = " / ".join(report_lines(old)) or source
    leads.append({"address": address, "current": old,
                  "proposals": [{"name": new, "reason": reason[:600], "source": source}] if new else [],
                  "note": None if new else f"no name proposed yet: {source}"})
call = re.compile(r"\b([A-Za-z_][A-Za-z0-9_]*)\s*\(")
SHARED = open(os.path.join(repo, "firmware", "CM550_J90350.00_analysis", "output", "function_renames.csv"), errors="replace").read() + \
    open(os.path.join(repo, "firmware", "cross_firmware_matches.csv"), errors="replace").read()
functions = []
for e in leads:
    name = e["current"]
    body = bodies.get(name, [])
    callees = sorted({m.group(1) for l in body[1:] for m in call.finditer(l) if m.group(1) in by_name and m.group(1) != name})
    callers = sorted({function_at[i] for i, l in enumerate(lines) if re.search(rf"\b{re.escape(name)}\b", l)
                      and function_at[i] != name and not l.strip().startswith(("//", "/*", "*"))})
    plate = plates.get(int(e["address"], 16), "")
    note = re.search(r"(?:^|\| )(jlaustill review[^|]*)", plate)
    functions.append({**e, "current_plate": plate, "body_lines": len(body), "callers": callers[:12],
                      "callees": callees[:20], "shared_with_cm550": bool(re.search(rf"(?<![A-Za-z0-9_]){re.escape(name)}(?![A-Za-z0-9_])", SHARED)),
                      **({"user_review_note": note.group(1).strip()} if note else {})})
functions.sort(key=lambda e: int(e["address"], 16))
# bins by family (address lists), so a family is judged by one agent
FAMILIES = [
    # 1: alpha; EGR / charge flow / intake manifold temperature; fueling, throttle and air models
    [0xe0f4, 0xe164, 0xe218, 0xe248, 0xe2cc, 0xe360, 0xe3a4, 0xe518, 0xe748,
     0x1242c, 0x125f4, 0x127bc, 0x12ad4, 0x12cf4, 0x130dc, 0x1359c, 0x13d14, 0x13dc8, 0x17f50, 0x506f88, 0x507028, 0x50716c,
     0x173a8, 0x1e830, 0x1eae8, 0x1f17c, 0x50dba8, 0x50eaa8, 0x502b6c, 0x506e28, 0x50e7f4],
    # 2: J1939 torque curve / PGN 65251 / EEC1 / DM8 / TSC1 lost; control sessions; data collector; engine protection
    #    shutdown; the number-to-text helper
    [0x18070, 0x1811c, 0x1820c, 0x182e8, 0x1b3a0, 0x20500, 0x209e8, 0x20a58, 0x20c64, 0x20d10, 0x212dc, 0x21ac0, 0x21cd4,
     0x2588c, 0x255c0, 0x26f80, 0x50be6c, 0x50beec, 0x50bff4, 0x505c20, 0x505d94, 0x505df0, 0x505f98, 0x27bc4,
     0x508130, 0x508898, 0x508e78, 0x508ee0],
    # 3: rear axle / drivetrain ratio / power down; converter clutch; crank / HPCR; diagnostics; RAM refresh + sessions
    [0x4272c, 0x42770, 0x5268e8, 0x525e54, 0x3e210, 0x51ba1c, 0x51ba6c, 0x457d0, 0x49004, 0x42cfc, 0x529ea4,
     0x29f54, 0x2bf44, 0x50ddb4, 0x5341a8, 0x533b18, 0x533b5c, 0x533b94, 0x50638c,
     0x21624, 0x21668, 0x21694, 0x5389c4, 0x538a84],
]
by_address_fn = {int(f["address"], 16): f for f in functions}
assigned = [a for fam in FAMILIES for a in fam]
assert sorted(assigned) == sorted(by_address_fn), (set(by_address_fn) ^ set(assigned))
function_bins = [[by_address_fn[a] for a in fam] for fam in FAMILIES]
HELD = [{"address": "0x0040c04a", "current": "diagnostic_session_state", "kind": "global (enum-typed)",
         "wave13_proposal": "ram_refresh_enable",
         "wave13_evidence": " / ".join(report_lines("ram_refresh_enable"))[:900]},
        {"address": "0x0040aa9a", "current": "j1939_standby_flag", "kind": "global (enum-typed)",
         "wave13_proposal": "development_mode",
         "wave13_evidence": " / ".join(report_lines("development_mode"))[:900]}]

# ---- globals
audit = list(csv.DictReader(open(audit_path)))
by_block = collections.defaultdict(list)
for r in audit:
    by_block[r["block"]].append(r)
records_at = collections.defaultdict(list)
for r in audit:
    records_at[int(r["address"], 16)].append(r)
comments = {}
for line in open(os.path.join(OUT, "global_variables.csv"), errors="replace"):
    if line.startswith("0x"):
        parts = (line.rstrip("\n").split(",", 3) + [""])[:4]
        comments[int(parts[0], 16)] = parts
worklist = json.load(open(os.path.join(here, "global_worklist_expanded.json")))
labels = {w["row_name"] for w in worklist}
code = collections.defaultdict(list)
pattern = re.compile(r"\b(" + "|".join(map(re.escape, sorted(labels, key=len, reverse=True))) + r")\b")
for i, line in enumerate(lines):
    s = line.strip()
    if s.startswith(("//", "/*", "*")):
        continue
    for m in pattern.finditer(line):
        if len(code[m.group(1)]) < 6:
            code[m.group(1)].append(f"{function_at[i]}: {s[:160]}")
addresses = sorted({w["address"] for w in worklist})
census = {}
for k in range(0, len(addresses), 60):
    out = subprocess.run([sys.executable, f"{T}/width_census.py", f"{T}/all.dis", *addresses[k:k + 60]],
                         capture_output=True, text=True)
    for line in out.stdout.splitlines():
        m = re.match(r"(0x[0-9a-f]+): (.*)", line)
        if m:
            census[int(m.group(1), 16)] = m.group(2)


def region(a):
    if 0x3fd482 <= a <= 0x3feec1:
        return "EEPROM mirror (name ends _cal)"
    if a < 0x3f0000:
        return "flash / ROM constant (no _cal)"
    if 0x3f9800 <= a < 0x3fdb30:
        return "RAM in the ROM-to-RAM copy window (no _cal)"
    return "RAM (working value or ROM-copied constant; no _cal)"


sys.path.insert(0, os.path.join(repo, "firmware", "scripts"))
from e2m_name_audit import load_struct_sizes  # noqa: E402
STRUCT = load_struct_sizes(os.path.join(OUT, "structure_definitions.csv"))
SIZE = {"byte": 1, "char": 1, "word": 2, "i16": 2, "short": 2, "dword": 4, "i32": 4, "pointer": 4, "int": 4}


def width_check(a, typ):
    m = re.match(r"^([A-Za-z_0-9]+)\[(\d+)\]$", typ)
    width = SIZE.get(m.group(1), STRUCT.get(m.group(1), 0)) * int(m.group(2)) if m else SIZE.get(typ, STRUCT.get(typ, 0))
    covered = [] if not width else [f"0x{b:08x} {r['block']} +{r['offset']} {r['record']} ({r['size']} B)"
                                    for b in range(a, a + width) for r in records_at.get(b, [])[:1]]
    scalar = not m and typ in SIZE
    flag = scalar and (len(covered) > 1 or (covered and records_at.get(a) and int(records_at[a][0]["size"] or 0) != width))
    return {"row_width_bytes": width, "covered_records": covered[:12],
            **({"width_problem": "the row width differs from its record(s): name each covered record in 'split'"} if flag else {})}


globals_ = []
for w in worklist:
    a = int(w["address"], 16)
    recs = records_at.get(a, [])
    block = recs[0]["block"] if recs else w.get("block", "")
    row = comments.get(a, ["", w["row_name"], w.get("row_type", ""), ""])
    globals_.append({
        "address": f"0x{a:08x}", "current_name": row[1], "current_type": row[2],
        "current_comment": row[3][:700], "region": region(a), "access_widths": census.get(a, "?"),
        "e2m_records_here": [f"{r['block']} +{r['offset']} {r['record']} [{r['unit']}, {r['size']} B, {r['signed']},"
                             f" scale {r['scale']}, {r['min']}..{r['max']}]: {r['description'][:160]}" for r in recs][:3],
        "dump_raw": recs[0]["dump_raw"] if recs else "", "references": int(w.get("references") or 0),
        "code": code.get(row[1], []),
        "block_named_rows": [f"+{x['offset']} {x['record']} -> {x['row_name']}" for x in by_block.get(block, [])
                             if x["status"] == "named"][:24],
        "report_leads": report_lines(f"0x{a:x}") + [l for l in report_lines(row[1]) if l not in report_lines(f"0x{a:x}")],
        "block": block,
        **width_check(a, row[2]),
        **({"added_by": w["added_by"]} if w.get("added_by") else {}),
    })
groups = collections.defaultdict(list)
for g in globals_:
    groups[g["block"] or g["address"][:7]].append(g)
global_bins = [[] for _ in range(4)]
for group in sorted(groups.values(), key=len, reverse=True):
    min(global_bins, key=len).extend(group)
os.makedirs(os.path.join(here, "bins"), exist_ok=True)
for k, b in enumerate(function_bins, 1):
    payload = {"functions": b}
    if k == 3:
        payload["held_enum_rows"] = HELD
    json.dump(payload, open(os.path.join(here, "bins", f"functions{k}.json"), "w"), indent=1)
for k, b in enumerate(global_bins, 1):
    json.dump(sorted(b, key=lambda g: (g["block"], g["address"])), open(os.path.join(here, "bins", f"globals{k}.json"), "w"),
              indent=1)
print("function bins:", [len(b) for b in function_bins], "| global bins:", [len(b) for b in global_bins])

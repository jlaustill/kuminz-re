"""Apply rename wave 15 (the misname review of the low-overlap e2m rows) after its checks. From apply_W14.py, globals only.
- Every result line: known kind / verdict, address in its bin, `old` = the current CSV name; every bin address is
  answered exactly once.
- Renames: snake_case; `_cal` exactly when the row is in the EEPROM mirror (0x3fd482-0x3feec1); the new name is not an
  existing global, function, struct field, parameter, local or any other .cpp identifier (a field or local with the
  same name breaks the label-only proof or shadows); no two rows get one name; the code_quote is in the .cpp with the
  old name; no invented abbreviation token.
- Held (held_W15.json, not applied): old names shared with CM550 or the cross-firmware maps; rows in HOLD.
- Listed for a hand check: renames and keeps whose evidence says the type looks wrong.
- The repo gate (apply_renames.py, dry run) runs on the renames; any PROBLEM line stops the apply.
- Globals: comment = the agent's comment + " (was <old>)" + " | earlier note: <old comment>" (dropped when the address
  is in WRONG_OLD_COMMENTS or the agent's comment already carries it). Keeps get "| e2m: <note>" unless the comment
  already cites the record.
Writes map_stage10.csv.
usage: apply_W15.py <w15 dir> <repo> [--dry-run]"""
import csv
import glob
import json
import os
import re
import subprocess
import sys

here, repo = sys.argv[1:3]
dry = "--dry-run" in sys.argv
HOLD = set()                 # addresses held after the review (filled from the reports)
WRONG_OLD_COMMENTS = set()   # addresses whose old comment an agent showed to be wrong
# address -> replacement new name, decided in the main session after reading every rename against its quote
RENAMED_BY_HAND = {
    # 68 characters; the record text is "IVS switch status when Throttle_Validation_Process_Error became active"
    "0x003fddac": "idle_validation_switch_state_at_throttle_validation_error_cal",
    # PGN 65249 byte 19 (0x3fae62) is "percent torque at peak torque, point 5"; pairs with ..._peak_torque_speed
    "0x0005c380": "engine_retarder_configuration_peak_torque_percent",
    # the repo writes the Cruise_RSG_* calibrations as cruise_* (1186 / 1187: cruise_zone_1_proportional_gain ...)
    "0x003feff0": "cruise_neutral_fuel_ramp_rate",
    "0x00408e6e": "cruise_minimum_fuel_ramp_rate",
    # e2m 18E8 +0 is Compressor_Inlet_Density and 1966 +10 the Compressor_Inlet_Tmptr_Sensor: the sensor-based
    # values are the compressor inlet ones (the ambient air temperature 1921 +6 is computed from them)
    "0x004065be": "compressor_inlet_density_negative_rate_limit",
    "0x004065c0": "compressor_inlet_density_positive_rate_limit",
    # the four low speed governor gain sets (4 words P, I, D, jerk, selected by the gain state): named as sets, so
    # the struct stage only changes the type; the agents named the first word (bins 2 / 3) or the set (bin 5)
    "0x004070e6": "low_speed_governor_default_gain_set",
    "0x004070aa": "low_speed_governor_aggressive_gain_set",
    "0x00408eda": "low_speed_governor_middle_gear_gain_set",
    "0x00408ed2": "low_speed_governor_high_gear_gain_set",
}
COMMENT_APPEND = {a: " The row is the first word of a 4-word gain set (proportional, integral, derivative, jerk) that "
                     "the low speed governor gain state selects (0 default, 1 aggressive, 2 middle gear, 3 high gear, "
                     "4 the TSC1 set; an FSS override uses the copy at 0x40ae82); cm848_updateGovernorSetpointParameters loads the "
                     "four words."
                  for a in ("0x004070e6", "0x004070aa", "0x00408eda", "0x00408ed2")}
# text fixes in the agents' comments: bin 3 showed the anti-theft status header 0xdc2800 is the PDU1 PGN 56320
COMMENT_FIXES = [("PGN 56360", "PGN 56320")]
# old names that also exist in CM550 for an unrelated role (not twins): renamed on CM848 alone
NOT_TWINS = {"0x0040b53e"}   # CM550 0x800090 governor_integral_accumulator is a pointer in validateServiceDataLength
BANNED = {"temp", "tmp", "cnt", "ref", "val", "calc", "init", "cfg", "coef", "coeff", "ptr", "addr", "buf", "idx",
          "msg", "thd", "thresh", "hyst", "accel", "est", "press", "spd", "filt", "diag", "ovr", "vlv", "pct", "cyl",
          "trq", "batt", "veh", "baro", "amb", "cmd", "adj", "lmt", "lim", "sw", "inj", "avg", "frac", "pos", "sel",
          "req", "err", "freq", "ctrl", "stat", "seq", "src", "dst", "num", "cond", "info", "mgr", "proc",
          "sens", "volt", "curr", "accum", "thr", "tbl", "lut", "hdr"}
out = os.path.join(repo, "firmware", "CM848_S90140.06_analysis", "output")
cpp = open(os.path.join(out, "cm848_rom.ghidra.cpp"), errors="replace").read()
norm = lambda t: re.sub(r"\s+", "", t)
cpp_norm = norm(cpp)
cpp_identifiers = set(re.findall(r"[A-Za-z_][A-Za-z0-9_]*", cpp))
bins = {}
for path in glob.glob(os.path.join(here, "bins", "bin*.json")):
    for item in json.load(open(path)):
        bins[(os.path.basename(path)[:-5], f"0x{int(item['address'], 16):08x}")] = item
gv = {l.split(",")[0]: (l.rstrip("\n").split(",", 3) + [""])[:4]
      for l in open(os.path.join(out, "global_variables.csv"), errors="replace") if l.startswith("0x")}
gv_names = {v[1] for v in gv.values()}
fn_names = {l.split(",")[1] for l in open(os.path.join(out, "function_renames.csv"), errors="replace")
            if l.startswith("0x") and "," in l}
field_names = {row[2] for row in csv.reader(open(os.path.join(out, "structure_definitions.csv"), errors="replace"))
               if len(row) > 2}
struct_names = {row[0] for row in csv.reader(open(os.path.join(out, "structure_definitions.csv"), errors="replace"))
                if row}
param_names = {row[3] for row in csv.reader(open(os.path.join(out, "function_definitions.csv"), errors="replace"))
               if len(row) > 3}
local_names = {row[3] for row in csv.reader(open(os.path.join(out, "local_variables.csv"), errors="replace"))
               if len(row) > 3}
taken = gv_names | fn_names | field_names | struct_names | param_names | local_names | cpp_identifiers
shared_text = ""
for f in glob.glob(os.path.join(repo, "firmware", "CM550_J90350.00_analysis", "output", "*.csv")) + \
        [os.path.join(repo, "firmware", "cross_firmware_matches.csv"),
         os.path.join(repo, "docs", "cross_firmware_variable_map.csv")]:
    if os.path.exists(f):
        shared_text += open(f, errors="replace").read()
results, problems, held, hand_check = [], [], [], []
answered = {}
for path in sorted(glob.glob(os.path.join(here, "results", "result_W15_bin*.jsonl"))):
    bin_name = os.path.basename(path)[len("result_W15_"):-len(".jsonl")]
    for n, line in enumerate(open(path), 1):
        if not line.strip():
            continue
        try:
            r = json.loads(line)
        except json.JSONDecodeError as e:
            problems.append(f"{bin_name}:{n} not JSON: {e}")
            continue
        r["_bin"], r["_line"] = bin_name, n
        address = f"0x{int(r['address'], 16):08x}"
        r["address"] = address
        if (bin_name, address) not in bins:
            problems.append(f"{bin_name}:{n} {address} is not in the bin")
            continue
        answered.setdefault((bin_name, address), []).append(n)
        kind, verdict = r.get("kind"), r.get("verdict")
        if kind != "global" or verdict not in ("confirmed", "keep", "drift", "uncertain"):
            problems.append(f"{bin_name}:{n} bad kind / verdict {kind} / {verdict}")
            continue
        current = gv.get(address, ["", ""])[1]
        if r.get("old") != current:
            problems.append(f"{bin_name}:{n} {address} old {r.get('old')} != current {current}")
            continue
        if address in RENAMED_BY_HAND and r.get("new") and r["new"] != RENAMED_BY_HAND[address]:
            # the comments of every bin may cite the agent's name for this row: they get the final one
            COMMENT_FIXES.append((r["new"], RENAMED_BY_HAND[address]))
            r["new"] = RENAMED_BY_HAND[address]
        results.append(r)
# longest first, so a name that contains another one is replaced whole
COMMENT_FIXES.sort(key=lambda pair: len(pair[0]), reverse=True)
for key in bins:
    if key[0] in {r["_bin"] for r in results} or os.path.exists(os.path.join(here, "results", f"result_W15_{key[0]}.jsonl")):
        lines_for = answered.get(key, [])
        if len(lines_for) != 1:
            problems.append(f"{key[0]} {key[1]} answered {len(lines_for)} times (lines {lines_for})")
renames = [r for r in results if r["verdict"] == "confirmed" and r.get("new") and r["new"] != r["old"]]
seen = {}
apply_globals = []
TYPE_WORDS = re.compile(r"\b(type|width|signed|unsigned|i16|i32|i8|dword|word|byte|lha|lhz|lbz)\b[^.;|]{0,80}\b(wrong|"
                        r"should|mismatch|instead|too narrow|too wide|candidate|but the record|retype|stays)\b", re.I)
for r in results:
    if TYPE_WORDS.search(r.get("evidence", "") + " " + r.get("comment", "")):
        hand_check.append(r)
for r in renames:
    a = int(r["address"], 16)
    new = r["new"]
    if new in seen:
        problems.append(f"duplicate new name {new}: {seen[new]} and {r['address']}")
    seen[new] = r["address"]
    if not re.match(r"^[a-z][a-z0-9_]*[a-z0-9]$", new) or "__" in new:
        problems.append(f"{r['address']} name format: {new}")
    if new in taken:
        problems.append(f"{r['address']} name exists (global / function / field / parameter / local / .cpp): {new}")
    in_mirror = 0x3fd482 <= a <= 0x3feec1
    if in_mirror != new.endswith("_cal"):
        problems.append(f"{r['address']} _cal rule: {new} ({'EEPROM mirror' if in_mirror else 'not EEPROM'})")
    bad = [t for t in new.split("_") if t in BANNED]
    if bad:
        problems.append(f"{r['address']} abbreviation {bad} in {new}")
    quote = r.get("code_quote", "")
    quote_code = quote.split(": ", 1)[1] if ": " in quote else quote
    if len(norm(quote_code)) < 12 or norm(quote_code) not in cpp_norm or r["old"] not in quote_code:
        problems.append(f"{r['address']} {r['old']}: code_quote not found with the name: {quote[:90]}")
    if a in HOLD:
        held.append({**r, "why": "held after review"})
        continue
    if r["address"] not in NOT_TWINS and \
            re.search(r"(?<![A-Za-z0-9_])" + re.escape(r["old"]) + r"(?![A-Za-z0-9_])", shared_text):
        held.append({**r, "why": "old name shared with CM550 / the cross-firmware maps"})
        continue
    apply_globals.append(r)
keeps = [r for r in results if r["verdict"] == "keep" and r.get("e2m_note")]
counts = {}
for r in results:
    counts[r["verdict"]] = counts.get(r["verdict"], 0) + 1
print("verdicts:", dict(sorted(counts.items())), f"of {len(bins)} bin rows")
print(f"to apply: {len(apply_globals)} renames, {len(keeps)} keep notes; held: {len(held)}; "
      f"type remarks for a hand check: {len(hand_check)}")
for r in held:
    print(f"  held: {r['address']} {r['old']} -> {r['new']} ({r['why']})")
gate_input = os.path.join(here, "gate_input_W15.jsonl")
with open(gate_input, "w") as f:
    for r in apply_globals:
        f.write(json.dumps({"kind": "global", "verdict": "confirmed", "address": r["address"], "old": r["old"],
                            "new": r["new"], "evidence": r.get("comment") or r.get("evidence", "")}) + "\n")
gate = subprocess.run([sys.executable, os.path.join(repo, "firmware", "scripts", "rename_waves", "apply_renames.py"), out,
                       gate_input], capture_output=True, text=True)
problems += [l for l in gate.stdout.splitlines() + gate.stderr.splitlines() if "PROBLEM" in l]
print(gate.stdout.strip().splitlines()[-1] if gate.stdout.strip() else gate.stderr[-300:])
json.dump(held, open(os.path.join(here, "held_W15.json"), "w"), indent=1)
json.dump(hand_check, open(os.path.join(here, "type_remarks_W15.json"), "w"), indent=1)
print("\n".join(problems) if problems else "checks: no problems")
if dry or problems:
    sys.exit(1 if problems else 0)

path = os.path.join(out, "global_variables.csv")
lines = open(path, newline="").read().split("\n")
index = {l.split(",", 1)[0]: i for i, l in enumerate(lines) if l.startswith("0x")}
for r in apply_globals:
    i = index[r["address"]]
    a, name, typ, comment = (lines[i].split(",", 3) + [""])[:4]
    assert name == r["old"], (r["address"], name)
    text = " ".join((r.get("comment") or r.get("evidence") or "").split()) + COMMENT_APPEND.get(r["address"], "")
    for before, after in COMMENT_FIXES:
        text = re.sub(r"(?<![A-Za-z0-9_])" + re.escape(before) + r"(?![A-Za-z0-9_])", after, text)
    new_comment = text + f" (was {r['old']})"
    if comment and r["address"] not in WRONG_OLD_COMMENTS and comment[:40] not in new_comment:
        new_comment += f" | earlier note: {comment}"
    lines[i] = ",".join([a, r["new"], typ, new_comment])
noted = 0
for r in keeps:
    i = index.get(r["address"])
    a, name, typ, comment = (lines[i].split(",", 3) + [""])[:4]
    record = r["e2m_note"].split()[3] if len(r["e2m_note"].split()) > 3 else ""
    if name != r["old"] or "| e2m:" in comment or (record and re.search(rf"\b{re.escape(record)}\b", comment)):
        continue
    note = " ".join(r["e2m_note"].split())
    for before, after in COMMENT_FIXES:
        note = re.sub(r"(?<![A-Za-z0-9_])" + re.escape(before) + r"(?![A-Za-z0-9_])", after, note)
    lines[i] = ",".join([a, name, typ, f"{comment} | e2m: {note}" if comment else f"e2m: {note}"])
    noted += 1
# drift / uncertain rows: a short reviewed marker, so a later wave does not pick them up again
marked = 0
for r in results:
    if r["verdict"] not in ("drift", "uncertain"):
        continue
    item = bins[(r["_bin"], r["address"])]
    i = index.get(r["address"])
    a, name, typ, comment = (lines[i].split(",", 3) + [""])[:4]
    if name != r["old"] or "| e2m:" in comment:
        continue
    what = ("resolves here but does not match the code (layout drift" if r["verdict"] == "drift"
            else "resolves here; the code does not show the role (uncertain")
    note = f"e2m {item['block']} +{item['offset']} {item['record']} {what}, rename wave 15)"
    lines[i] = ",".join([a, name, typ, f"{comment} | e2m: {note}" if comment else f"e2m: {note}"])
    marked += 1
open(path, "w", newline="").write("\n".join(lines))
with open(os.path.join(here, "map_stage10.csv"), "w") as f:
    f.write("address,name,old_label,kind\n")
    for r in apply_globals:
        f.write(f"{r['address']},{r['new']},{r['old']},global\n")
print(f"applied {len(apply_globals)} global renames, keep notes on {noted} rows, drift / uncertain notes on {marked}")

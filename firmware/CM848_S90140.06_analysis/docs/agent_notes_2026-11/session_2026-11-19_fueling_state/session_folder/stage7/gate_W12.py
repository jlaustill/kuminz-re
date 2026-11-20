"""Gate for rename wave 12 (new rows from the e2m records): the apply_renames.py name rules (its BANNED set, hex-looking
parts, the format, _cal by the memory map, bare protection) plus: duplicate addresses / names across bins, collisions
with the CSVs and the .cpp, an address that already has a row, the type against the record size. Only confirmed rows
pass. Writes gated_W12.jsonl (the passing rows) and prints every problem.
usage: gate_W12.py <stage7 dir> <CM848 output dir> [--skip ADDRESS,...] [--prefer ADDRESS=binN,...]"""
import ast
import collections
import glob
import json
import os
import re
import sys

here, out = sys.argv[1], sys.argv[2]
skip = set()
prefer = {}
for arg in sys.argv[3:]:
    if arg.startswith("--skip="):
        skip |= {a.lower() for a in arg.split("=", 1)[1].split(",") if a}
    if arg.startswith("--prefer="):
        for pair in arg.split("=", 1)[1].split(","):
            address, bin_name = pair.split(":")
            prefer[address.lower()] = bin_name
sys.path.insert(0, "/home/linux/code/kuminz-re/.claude/worktrees/cm848-fueling-state-enum/firmware/scripts/rename_waves")
source = open("/home/linux/code/kuminz-re/.claude/worktrees/cm848-fueling-state-enum/firmware/scripts/rename_waves/"
              "apply_renames.py").read()
# parse the literal set from the repo's own gate without executing code
BANNED = ast.literal_eval(re.search(r"^BANNED = (\{.*?\})", source, re.S | re.M).group(1))
EEPROM = (0x3fd482, 0x3feec1)
SIZE_TYPES = {"1": {"byte"}, "2": {"word", "i16"}, "4": {"dword", "i32"}}


def words(name):
    out_ = []
    for p in name.split("_"):
        out_ += [w.lower() for w in re.findall(r"[A-Z]?[a-z]+|[A-Z]+(?![a-z])|\d+", p)]
    return out_


bins = {}
for path in sorted(glob.glob(os.path.join(here, "bins", "bin*.json"))):
    for record in json.load(open(path)):
        bins.setdefault(record["address"].lower(), []).append((os.path.basename(path)[:-5], record))
gv = [l for l in open(os.path.join(out, "global_variables.csv"), errors="replace") if l.startswith("0x")]
rows_at = {int(l.split(",", 1)[0], 16): l.split(",")[1] for l in gv}
used = {l.split(",")[1] for l in gv}
for name in ("function_renames.csv", "structure_definitions.csv", "enums.csv"):
    for l in open(os.path.join(out, name), errors="replace"):
        parts = l.split(",")
        if len(parts) > 2:
            used |= {parts[1], parts[2]}
cpp_tokens = set(re.findall(r"\b[a-z_][a-z0-9_]*\b", open(os.path.join(out, "cm848_rom.ghidra.cpp"), errors="replace").read()))

results = []
for path in sorted(glob.glob(os.path.join(here, "aligned_W12_bin*.jsonl"))):
    bin_name = os.path.basename(path).split("_")[-1].split(".")[0]
    for line in open(path):
        if line.strip():
            r = json.loads(line)
            r["_bin"] = bin_name
            results.append(r)
verdicts = collections.Counter(r.get("verdict") for r in results)
kinds = collections.Counter(r.get("kind") for r in results)
problems, passing = [], []
by_address = collections.defaultdict(list)
for r in results:
    if r.get("verdict") == "confirmed" and r.get("new"):
        by_address[r["address"].lower()].append(r)
for address, rs in by_address.items():
    if len(rs) > 1:
        names = {r["new"] for r in rs}
        chosen = [r for r in rs if r["_bin"] == prefer.get(address)]
        if len(names) > 1 and not chosen:
            problems.append(f"{address}: two bins disagree {[(r['_bin'], r['new']) for r in rs]}")
            continue
        by_address[address] = chosen[:1] or rs[:1]
seen = {}
for address, rs in sorted(by_address.items()):
    r = rs[0]
    if address in skip:
        continue
    new, a = r["new"], int(address, 16)
    tag = f"{address} {new} ({r['_bin']})"
    issues = []
    if new in seen:
        issues.append(f"name also proposed for {seen[new]}")
    seen[new] = address
    if new in used or new in cpp_tokens:
        issues.append("name already in a CSV or the .cpp")
    bad = sorted(set(words(new)) & BANNED)
    if bad:
        issues.append(f"banned word(s) {bad}")
    if re.search(r"(?<![a-z])0x|_[0-9a-f]*[a-f][0-9a-f]*\d[0-9a-f]*(_|$)", new):
        issues.append("hex-looking part")
    if not re.fullmatch(r"[a-z][a-z0-9_]*[a-z0-9]", new) or "__" in new:
        issues.append("malformed name")
    in_eeprom = EEPROM[0] <= a <= EEPROM[1]
    if new.endswith("_cal") and not in_eeprom:
        issues.append("_cal outside the EEPROM mirror")
    if in_eeprom and not new.endswith("_cal") and not new.startswith("fault_detected_bits_"):
        issues.append("EEPROM mirror without _cal")
    if new.split("_")[-1] == "protection":
        issues.append("bare protection")
    record = (bins.get(address) or [(None, {})])[0][1]
    if r.get("kind") == "new_global":
        if a in rows_at:
            issues.append(f"address already has a row ({rows_at[a] or 'unnamed'})")
        allowed = SIZE_TYPES.get(str(record.get("size_bytes")), set())
        if r.get("type") not in allowed:
            issues.append(f"type {r.get('type')} for a {record.get('size_bytes')}-byte record")
    elif r.get("kind") == "global":
        if rows_at.get(a, None) != (r.get("old") or ""):
            issues.append(f"old {r.get('old')!r} is not the row's name {rows_at.get(a)!r}")
    else:
        issues.append(f"kind {r.get('kind')}")
    if issues:
        problems.append(f"{tag}: " + "; ".join(issues))
    else:
        passing.append(r)
with open(os.path.join(here, "gated_W12.jsonl"), "w") as f:
    for r in passing:
        f.write(json.dumps({k: v for k, v in r.items() if k != "_bin"}) + "\n")
print(f"{len(results)} rows; verdicts {dict(verdicts)}; kinds {dict(kinds)}")
print(f"passing: {len(passing)}; problems: {len(problems)}")
print("\n".join(problems))

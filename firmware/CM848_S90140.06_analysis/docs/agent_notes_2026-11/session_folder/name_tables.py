"""Compose table names from agent results (base per lookup + role suffix), gate them, optionally apply.

Usage: name_tables.py <tables_dir> <firmware_output_dir> <result.jsonl>... [--apply] [--out proposed.csv]
A table is named only if its lookups agree (or it has a shared_base). --apply edits the existing type-only
global_variables.csv rows in place (name column only) and checks the edit touched nothing else.
"""
import csv
import glob
import json
import os
import re
import sys
from collections import defaultdict

args = [a for a in sys.argv[1:] if not a.startswith("--")]
APPLY = "--apply" in sys.argv
OUT_CSV = sys.argv[sys.argv.index("--out") + 1] if "--out" in sys.argv else None
if OUT_CSV in args:
    args.remove(OUT_CSV)
REWRITE = sys.argv[sys.argv.index("--rewrite") + 1] if "--rewrite" in sys.argv else None
if REWRITE in args:
    args.remove(REWRITE)
TABLES, FWOUT, RESULTS = args[0], args[1], args[2:]
rewrite = json.load(open(REWRITE)) if REWRITE else {}

BANNED_WORDS = {"cal", "temp", "tmp", "press", "pos", "corr", "coef", "coeff", "thresh", "thr", "inj", "qty",
                "ctrl", "cfg", "cmd", "val", "vals", "idx", "cnt", "num", "ref", "spd", "eng", "prot", "lim",
                "mult", "comp", "adj", "trq", "tbl", "lkp", "sw", "calc", "accel", "decel", "pct", "freq",
                "volt", "amp", "deg", "sec", "ms", "diag", "cond", "req", "resp", "init", "tmr", "buf",
                "xaxis", "yaxis", "aux", "arb", "iat", "imt", "rr", "fb"}
NAME = re.compile(r"^[a-z][a-z0-9]*(?:_[a-z0-9]+)*$")
HEXISH = re.compile(r"^(?=[0-9a-f]*\d)(?=[0-9a-f]*[a-f])[0-9a-f]{3,}$")
SUFFIX = {("1-D", "x_axis"): "axis", ("1-D", "values"): "values", ("2-D", "x_axis"): "x_axis",
          ("2-D", "y_axis"): "y_axis", ("2-D", "grid"): "grid", ("1-D", "x2_axis"): "axis_2",
          ("1-D", "values2"): "values_2", ("1-D", "values3"): "values_3", ("1-D", "values4"): "values_4"}

lookups = {lk["id"]: lk for lk in json.load(open(os.path.join(TABLES, "lookups.json")))}
bins = {}
for f in sorted(glob.glob(os.path.join(TABLES, "bin_*.json"))):
    b = json.load(open(f))
    for a in b["assigned_tables"]:
        bins[a] = b["bin"]
problems, warnings = [], []
base_of, skip_of, shared_of, info = {}, {}, {}, {}
for path in RESULTS:
    for n, line in enumerate(open(path), 1):
        line = line.strip()
        if not line:
            continue
        try:
            r = json.loads(line)
        except json.JSONDecodeError as e:
            problems.append(f"{os.path.basename(path)}:{n}: not JSON ({e})")
            continue
        if "lookup" in r:
            k = r["lookup"]
            if k in base_of or k in skip_of:
                problems.append(f"{k}: more than one result line")
            if r.get("skip"):
                skip_of[k] = r.get("reason", "")
            elif r.get("base"):
                base_of[k] = r["base"]
                info[k] = r
            else:
                problems.append(f"{k}: neither base nor skip")
        elif "table" in r:
            a = r["table"].lower()
            a = f"0x{int(a, 16):08x}"
            shared_of[a] = r.get("shared_base") or r.get("base")
            info[a] = r
        else:
            problems.append(f"{os.path.basename(path)}:{n}: no lookup / table key")

# tables of the bins these results cover
covered_bins = set()
for k in list(base_of) + list(skip_of):
    for t in lookups.get(k, {}).get("tables", []):
        if t.get("to_name") and t["address"] in bins:
            covered_bins.add(bins[t["address"]])
assigned = sorted(a for a, b in bins.items() if b in covered_bins)
for a in assigned:
    for k in next(t for lk in lookups.values() for t in lk["tables"] if t["address"] == a)["shared_by_lookups"]:
        if k not in base_of and k not in skip_of:
            problems.append(f"{k}: no result line (holds {a})")

for k, b in rewrite.get("lookups", {}).items():
    if k not in base_of:
        problems.append(f"rewrite for {k}: no named result to rewrite")
    base_of[k] = b
for a, b in rewrite.get("shared", {}).items():
    shared_of[a] = b
proposed = {}
for a in assigned:
    roles = {(lookups[k]["kind"], t["role"]) for k, lk in lookups.items() for t in lk["tables"] if t["address"] == a}
    if len(roles) > 1 and {r for _, r in roles} == {"x_axis"}:
        roles = {("1-D", "x_axis")}            # an x axis shared by 1-D and 2-D lookups: plain _axis
    if len(roles) != 1:
        problems.append(f"{a}: inconsistent roles {roles}")
        continue
    role = roles.pop()
    ks = next(t for lk in lookups.values() for t in lk["tables"] if t["address"] == a)["shared_by_lookups"]
    if a in shared_of:
        base = shared_of[a]
    else:
        bases = {base_of[k] for k in ks if k in base_of}
        if not bases:
            continue
        if len(bases) > 1:
            problems.append(f"{a}: its lookups {ks} disagree {sorted(bases)} and there is no shared_base")
            continue
        if any(k in skip_of for k in ks):
            warnings.append(f"{a}: named from {sorted(bases)} although one of {ks} was skipped")
        base = bases.pop()
    if role not in SUFFIX:
        problems.append(f"{a}: no suffix for role {role}")
        continue
    proposed[a] = (f"{base}_{SUFFIX[role]}", base, role, ks)

# gates
existing = defaultdict(set)
for fname, col in (("global_variables.csv", 1), ("arrays.csv", 1), ("function_renames.csv", 1)):
    for line in open(os.path.join(FWOUT, fname)):
        p = line.rstrip("\n").split(",")
        if p[0].startswith("0x") and len(p) > col and p[col]:
            existing[p[col]].add((fname, p[0].lower()))
seen = defaultdict(list)
for a, (name, base, role, ks) in proposed.items():
    seen[name].append(a)
    words = base.split("_")
    if not NAME.match(name):
        problems.append(f"{a}: bad format {name!r}")
    if len(base) > 52:
        problems.append(f"{a}: base longer than 52 ({len(base)}) {base}")
    if len(name) > 60:
        problems.append(f"{a}: name longer than 60 ({len(name)}) {name}")
    bad = sorted(set(words) & BANNED_WORDS)
    if bad:
        problems.append(f"{a}: banned word(s) {bad} in {name}")
    if any(HEXISH.match(w) for w in words):
        problems.append(f"{a}: hex-looking word in {name}")
    if "protection" in words:
        warnings.append(f"{a}: check 'protection' says of what: {name}")
    others = {x for x in existing.get(name, set()) if not (x[0] == "global_variables.csv" and int(x[1], 16) == int(a, 16))}
    if others:
        problems.append(f"{a}: {name} already used by {sorted(others)}")
for name, addrs in seen.items():
    if len(addrs) > 1:
        problems.append(f"name {name} proposed for {addrs}")

named_lookups = len(base_of)
print(f"results: {named_lookups} lookups named, {len(skip_of)} skipped, {len(shared_of)} shared bases;"
      f" bins {sorted(covered_bins)}; assigned tables {len(assigned)}; names proposed {len(proposed)}")
for p in problems:
    print("PROBLEM", p)
for w in warnings:
    print("warning", w)
if OUT_CSV:
    with open(OUT_CSV, "w", newline="") as f:
        w = csv.writer(f)
        w.writerow(["address", "name", "role", "lookups", "bin", "confidence", "evidence"])
        for a, (name, base, role, ks) in sorted(proposed.items()):
            r = info.get(a) or next((info[k] for k in ks if k in info), {})
            w.writerow([a, name, "/".join(role), " ".join(ks), bins.get(a), r.get("confidence", ""),
                        (r.get("evidence", "") or "")[:300]])
if APPLY:
    if problems:
        sys.exit("not applied: fix the problems first")
    path = os.path.join(FWOUT, "global_variables.csv")
    old = open(path).read().split("\n")
    new = list(old)
    hits = defaultdict(int)
    for i, line in enumerate(old):
        p = line.split(",", 3)
        if p[0].startswith("0x"):
            a = f"0x{int(p[0], 16):08x}"
            if a in proposed:
                if p[1] != "" or not re.fullmatch(r"word\[\d+\]", p[2] if len(p) > 2 else ""):
                    sys.exit(f"row for {a} is not a type-only word[N] row: {line[:120]}")
                p[1] = proposed[a][0]
                new[i] = ",".join(p)
                hits[a] += 1
    missing = sorted(set(proposed) - set(hits))
    double = sorted(a for a, n in hits.items() if n > 1)
    if missing or double:
        sys.exit(f"row problems: missing {missing[:5]} duplicated {double[:5]}")
    changed = [i for i in range(len(old)) if old[i] != new[i]]
    assert len(changed) == len(proposed), (len(changed), len(proposed))
    for i in changed:
        o, n = old[i].split(","), new[i].split(",")
        assert len(o) == len(n) and all(o[j] == n[j] for j in range(len(o)) if j != 1) and o[1] == "", old[i]
    open(path, "w").write("\n".join(new))
    print(f"applied {len(changed)} names (name column only)")

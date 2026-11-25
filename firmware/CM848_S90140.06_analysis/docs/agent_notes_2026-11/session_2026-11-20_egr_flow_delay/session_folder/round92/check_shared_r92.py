"""Round 92 (read-only): for every proposed word, compare the proposed field names with CM848's
algorithm_enable_flags_<n>_t (when CM848 has that type): per bit same / differs, and whether the proposal's
shared_with_cm848 claim holds on names. Also checks each proposed bitfield has bits 0-15 exactly once.
usage: check_shared_r92.py <repo> <batch_X.json>..."""
import csv
import json
import os
import re
import sys

repo = sys.argv[1]
cm848 = {}
for row in csv.reader(open(os.path.join(repo, "firmware/CM848_S90140.06_analysis/output/structure_definitions.csv"), newline="")):
    if len(row) > 3 and re.match(r"^algorithm_enable_flags_\d+_t$", row[0]):
        m = re.match(r"^bitfield:1@(\d+)$", row[3])
        if m:
            cm848.setdefault(row[0], {})[int(m.group(1))] = row[2]
for path in sys.argv[2:]:
    data = json.load(open(path))
    for w in data["proposal"]["words"]:
        n, typ = w["word"], w["proposed_type"]
        fields = {f["bit"]: f["name"] for f in w.get("fields") or []}
        problems = []
        if typ != "word":
            if sorted(fields) != list(range(16)):
                problems.append(f"bits {sorted(fields)}")
            if len(set(fields.values())) != len(fields):
                problems.append("duplicate field names")
        ref = cm848.get(f"algorithm_enable_flags_{n}_t")
        diff = []
        if ref and fields:
            diff = [f"{b}: {fields.get(b)} / CM848 {ref.get(b)}" for b in range(16) if fields.get(b) != ref.get(b)]
        claim = "SHARED" if w.get("shared_with_cm848") else ("cm550_" if typ.startswith("cm550_") else typ)
        status = "names equal" if ref and not diff else (f"{len(diff)} bits differ" if ref else "CM848 has no such type")
        print(f"word {n:>2} {typ:36} claim {claim:7} | {status}" + (f" | PROBLEMS {problems}" if problems else ""))
        if w.get("shared_with_cm848") and diff:
            for d in diff:
                print("      SHARED CLAIM BROKEN:", d)
        elif diff and len(diff) <= 6:
            for d in diff:
                print("     ", d)

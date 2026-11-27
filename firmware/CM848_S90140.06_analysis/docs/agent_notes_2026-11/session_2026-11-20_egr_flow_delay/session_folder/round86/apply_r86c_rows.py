"""Round 86 stage C (CM550 function_definitions.csv): the wave 2 rows from the workflow (wf_7593be98-3c4). For each
function the skeptic accepted or amended, its final rows are appended under one section comment. Refuses a function
that already has rows, a row set with a gap in param_index, and a return-only set. Idempotent.
usage: apply_r86c_rows.py <repo> <workflow output file> <applied.csv>"""
import json
import os
import re
import sys

repo, wf_path, applied_path = os.path.abspath(sys.argv[1]), sys.argv[2], sys.argv[3]
O5 = os.path.join(repo, "firmware/CM550_J90350.00_analysis/output")
D5, F5 = os.path.join(O5, "function_definitions.csv"), os.path.join(O5, "function_renames.csv")
R = "PR #53 round 86"
SECTION = f"# Stack parameter layout: wave 2 prototypes ({R}; workflow wf_7593be98-3c4 - proposed then verified)"

names = {}
for line in open(F5, newline=""):
    p = line.rstrip("\r\n").split(",", 2)
    if p[0].startswith("0x") and len(p) > 1:
        names[int(p[0], 16)] = p[1]
text = open(D5, newline="").read()
eol = "\r\n" if "\r\n" in text else "\n"
before_section = text.split(SECTION)[0]   # rows this stage added do not count as existing ones
existing = {int(l.split(",")[0], 16) for l in before_section.split(eol) if l.startswith("0x")}
data = json.load(open(wf_path))["result"]
out, applied, refused = [], [], []
for group in data:
    for v in group["verdicts"]["verdicts"]:
        address = int(v["address"], 16)
        if v["verdict"] == "reject" or not v["rows"]:
            refused.append((address, "rejected: " + "; ".join(v.get("problems", []))[:160]))
            continue
        if address in existing:
            refused.append((address, "already has rows"))
            continue
        params = sorted((r for r in v["rows"] if r["param_index"] != "return"), key=lambda r: int(r["param_index"]))
        indexes = [int(r["param_index"]) for r in params]
        if not params or indexes != list(range(len(params))):
            refused.append((address, f"no rows or a gap: {indexes}"))
            continue
        name = names.get(address)
        if name is None:
            refused.append((address, "no function_renames.csv name"))
            continue
        rows = [r for r in v["rows"] if r["param_index"] == "return"] + params
        for r in rows:
            comment = re.sub(r"\s*,\s*", "; ", r["comment"]).strip()
            tag = "amended by the skeptic; " if v["verdict"] == "amend" else ""
            out.append(f"0x{address:08x},{name},{r['param_index']},{r['name']},{r['type']},{comment} ({tag}{R})")
        applied.append((address, name, v["verdict"], len(params)))
if SECTION not in text and out:
    body = text.rstrip("\r\n") + eol + SECTION + eol + eol.join(out) + eol
    open(D5, "w", newline="").write(body)
with open(applied_path, "w") as fh:
    fh.write("address,name,verdict,parameters\n")
    for a, n, v, c in applied:
        fh.write(f"0x{a:05x},{n},{v},{c}\n")
print(f"applied {len(applied)} functions ({sum(c for *_, c in applied)} parameter rows); refused {len(refused)}")
for a, why in refused:
    print(f"  refused 0x{a:05x}: {why}")

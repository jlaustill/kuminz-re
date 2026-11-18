"""Append the rename-wave results to task 042 and update todo 042."""
import csv
import json
import os
import sys
from collections import Counter

repo, d = sys.argv[1], sys.argv[2]
maps = list(csv.DictReader(open(os.path.join(d, "mapping_renames.csv"))))
fams = list(csv.DictReader(open(os.path.join(d, "mapping_families.csv"))))
fns = [m for m in maps if m["kind"] == "function"]
gls = [m for m in maps if m["kind"] == "global"]
prefix = Counter("_".join(m["name"].split("_")[:2]) for m in gls)
notes, uncertain = [], []
for g in ("G1a", "G1b", "G2", "G3", "G4"):
    for line in open(os.path.join(d, f"aligned_{g}.jsonl")):
        r = json.loads(line)
        if r.get("kind") == "note":
            notes.append(f"- [{g}] " + " ".join(r.get("text", "").split())[:420])
        elif r.get("verdict") == "uncertain":
            uncertain.append(f"- `{r.get('old')}` ({r.get('address')}): " + " ".join((r.get("evidence") or "").split())[:300])
lines = ["", "## DONE 2026-11-16 (PR #50): verified and renamed",
         "",
         "Five read-only agents verified the leads above against the code (RAM-dump reproductions where possible); "
         "every lead held. Applied: 27 function renames (new plate comments), 234 global renames (each comment now "
         "starts with the evidence and `(was <old>)`), 3 new rows for unnamed words, and 89 table renames that "
         "follow the new family vocabulary (`injection_timing_offset_*` -> `injection_timing_pilot_offset_*`, "
         "`pilot_quantity_*` -> `injection_quantity_pilot_*`). Proof: mapping every new name back to its old one "
         "gives back the previous .cpp (plate comments aside; three functions only reorder their declarations).",
         "",
         "### Functions",
         ""]
lines += [f"- `{m['name']}` (was `{m['old_label']}`, {m['address']})" for m in sorted(fns, key=lambda m: m["name"])]
lines += ["", "### Globals by family (count)", "",
          ", ".join(f"`{p}_*` {n}" for p, n in prefix.most_common(30)), "",
          "### Left uncertain (not renamed)", ""] + (uncertain or ["- none"])
lines += ["", "### Further leads, notes and type issues from the verification agents", ""] + notes
lines += ["", "Also still open from the list above: the struct fields (`rpm_governor_state_t.desired_rpm` / "
          "`lower_rpm_limit` / `commanded_rpm` are wastegate duty / 2), and `cold_start_phase` (see the vocabulary note)."]
p = os.path.join(repo, "work/tasks/042-table-campaign-rename-leads.md")
open(p, "a").write("\n".join(lines) + "\n")
t = open(os.path.join(repo, "work/todo.md")).read()
old_start = "042 [ ] [firmware] CM848D rename leads from the table-naming campaign:"
assert t.count(old_start) == 1
i = t.index(old_start)
j = t.index("\n", i)
t = t[:i] + ("042 [>] [firmware] CM848D rename leads from the table-naming campaign: DONE for the listed leads (PR #50, "
             "2026-11-16): 27 functions + 237 globals verified and renamed (pilot / main / auxiliary injection timing, "
             "quantity and on-time chains; rail pressure setpoint and monitors; wastegate duty + monitor; charging "
             "regulator; intake air heater test; retarder; oil change monitor), duplicate names fixed; still open: "
             "the agents' further leads and type notes in tasks/042-table-campaign-rename-leads.md") + t[j:]
open(os.path.join(repo, "work/todo.md"), "w").write(t)
print(f"task 042: {len(fns)} functions, {len(gls)} globals, {len(uncertain)} uncertain, {len(notes)} notes")

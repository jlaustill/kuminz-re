"""Stage 9 cross-firmware check (after the advisor review), by address as well as by name:
- functions: every applied function rename joined against firmware/cross_firmware_matches.csv by CM848 address and by
  the old name; for each hit, the CM550 side's current name (CM550 function_renames.csv) and whether it is the same bare
  name as the CM848 old name (a shared name = a true twin by name);
- globals: every renamed global's old name grepped in CM550's CSVs and the two cross-firmware maps (apply_W13.py's
  check, which apply_W14.py dropped), and every renamed address joined against docs/cross_firmware_variable_map.csv;
- stale CM848 names: rows of the two maps whose CM848 name is an old name renamed in stage 9.
usage: cross_firmware_check_W14.py <stage9 dir> <repo>"""
import csv
import os
import re
import sys

here, repo = sys.argv[1:3]
fw = os.path.join(repo, "firmware")
cm550 = {}
for line in open(os.path.join(fw, "CM550_J90350.00_analysis", "output", "function_renames.csv"), errors="replace"):
    if line.startswith("0x"):
        a, n = line.rstrip("\r\n").split(",")[:2]
        cm550[int(a, 16)] = n
matches = list(csv.DictReader(open(os.path.join(fw, "cross_firmware_matches.csv"))))
varmap = list(csv.DictReader(open(os.path.join(repo, "docs", "cross_firmware_variable_map.csv"))))
mapping = list(csv.DictReader(open(os.path.join(here, "map_stage9_all.csv"))))
print("== functions (by address or old name in cross_firmware_matches.csv)")
for r in [m for m in mapping if m["kind"] == "function"]:
    a = int(r["address"], 16)
    for m in matches:
        if (m["cm848_addr"] and int(m["cm848_addr"], 16) == a) or m["cm848_name"] == r["old_label"]:
            cm550_now = cm550.get(int(m["cm550_addr"], 16), "?")
            bare = re.sub(r"^(cm848|cm550|hpcr|vp44|mpc555|mc68k)_", "", r["old_label"])
            shared = cm550_now in (r["old_label"], bare)
            print(f"  {r['address']} {r['old_label']} -> {r['name']} | map row cm550 {m['cm550_addr']} {m['cm550_name']}"
                  f" (now {cm550_now}), score {m['score']}, {m['action']}{' | SHARED NAME' if shared else ''}")
shared_text = ""
for name in os.listdir(os.path.join(fw, "CM550_J90350.00_analysis", "output")):
    if name.endswith(".csv"):
        shared_text += open(os.path.join(fw, "CM550_J90350.00_analysis", "output", name), errors="replace").read()
shared_text += open(os.path.join(fw, "cross_firmware_matches.csv")).read()
shared_text += open(os.path.join(repo, "docs", "cross_firmware_variable_map.csv")).read()
print("== globals (old name in CM550's CSVs or the maps; address in the variable map)")
var_by_address = {int(v["cm848_address"], 16): v for v in varmap if v.get("cm848_address")}
for r in [m for m in mapping if m["kind"] == "global"]:
    a = int(r["address"], 16)
    hit = re.search(rf"(?<![A-Za-z0-9_]){re.escape(r['old_label'])}(?![A-Za-z0-9_])", shared_text) if "+" not in r["old_label"] else None
    v = var_by_address.get(a)
    if hit or v:
        print(f"  {r['address']} {r['old_label']} -> {r['name']} | name in CM550 / maps: {bool(hit)}"
              f"{' | variable map: ' + v['name'] + ' (' + v['match_type'] + ')' if v else ''}")
olds = {r["old_label"] for r in mapping}
stale = [m for m in matches if m["cm848_name"] in olds] + [v for v in varmap if v["name"] in olds]
print(f"== map rows naming a stage-9 old name: {len(stale)}")
for s in stale[:20]:
    print("  ", {k: s[k] for k in list(s)[:4]})

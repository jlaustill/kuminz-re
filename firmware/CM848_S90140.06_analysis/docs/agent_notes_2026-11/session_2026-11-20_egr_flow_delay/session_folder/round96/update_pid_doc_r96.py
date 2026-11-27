"""Round 96: rewrite the 'Table Contents (20 entries)' table and the 'Address Distribution' list of CM848's
docs/parameter_by_id_system.md from output/parameter_id_lookup_table.csv. The doc's purpose notes are kept; the stale
QADC register names go (0x302000-0x3037ff is the DPTRAM array). usage: update_pid_doc_r96.py <repo>"""
import collections
import csv
import os
import re
import sys

repo = os.path.abspath(sys.argv[1])
D = os.path.join(repo, "firmware/CM848_S90140.06_analysis")
doc = os.path.join(D, "docs/parameter_by_id_system.md")
t = open(doc, newline="").read()
start = t.index("| Param ID | Address | Region | Variable/Purpose |")
end = t.index("\n\n", start)
notes = {}
for line in t[start:end].split("\n")[2:]:
    cells = [c.strip() for c in line.strip("|").split("|")]
    purpose = cells[3]
    if re.match(r"qadc_", purpose):
        purpose = ""
    notes[cells[0].upper()] = purpose
rows = list(csv.DictReader(open(os.path.join(D, "output/parameter_id_lookup_table.csv"), newline="")))
out = ["| Param ID | Address | Region | Variable | Purpose |", "|----------|---------|--------|----------|---------|"]
for r in rows:
    pid = r["param_id_hex"].upper().replace("0X", "0x")
    name = f"`{r['firmware_variable']}`" if r["firmware_variable"] else ""
    out.append(f"| {pid} | {r['address_hex']} | {r['region']} | {name} | {notes.get(pid.upper(), '')} |")
t = t[:start] + "\n".join(out) + t[end:]
count = collections.Counter(r["region"] for r in rows)
old_dist = re.search(r"### Address Distribution\n(?:- .*\n)+", t).group(0)
new_dist = ("### Address Distribution\n"
            f"- **EEPROM** (0x01xxxxxx): {count['EEPROM']} entries - non-volatile configuration (variable names through the RAM mirror 0x3fd482 + offset)\n"
            f"- **DPTRAM** (0x00302000-0x003037FF, the MPC555 dual-port TPU RAM array): {count['DPTRAM']} entries - application RAM variables, not registers (QADC_A is at 0x304800; PR #53 round 96 corrected the earlier 'qadc_a_*' register names)\n"
            f"- **ROM** (0x000xxxxx): {count['ROM']} entries - build info and constants\n")
t = t.replace(old_dist, new_dist)
open(doc, "w", newline="").write(t)
print(dict(count))

"""Round 39 stage C: statement_diff.py rules. The type changes first (the byte halves of j1939_tx_periodic_counter, the
four transmit words as one word[4]), then the 48 label renames of map_r39c.csv as whole tokens, then whitespace before
';' (wrapping moves when a name's length changes).  usage: make_rules_r39c.py <map.csv> <rules.json>"""
import csv
import json
import re
import sys

rules = [[r"\bj1939_tx_periodic_counter\._0_1_", "supervisor_watchdog_cycle_counter"],
         [r"\bj1939_tx_periodic_counter\._1_1_", "supervisor_register_46_read_counter"],
         [r"\(byte\)j1939_tx_periodic_counter\b", "supervisor_register_46_read_counter"],
         [r"&j1939_proprietary_status_byte_0\b", "supervisor_configuration_transmit_words"],
         [r"\bj1939_proprietary_status_byte_([0-3])\b", r"supervisor_configuration_transmit_words[\1]"]]
for r in csv.DictReader(open(sys.argv[1])):
    if r["old_label"].startswith("j1939_proprietary_status_byte_") or r["old_label"] == "j1939_tx_periodic_counter":
        continue
    rules.append([r"\b" + re.escape(r["old_label"]) + r"\b", r["name"]])
rules.append([" ;", ";"])
json.dump({"*": rules}, open(sys.argv[2], "w"), indent=1)
print(len(rules), "rules")

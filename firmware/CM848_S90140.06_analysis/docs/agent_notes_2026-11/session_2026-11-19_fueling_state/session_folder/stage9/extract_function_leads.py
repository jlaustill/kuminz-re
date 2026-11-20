"""Collect the function renames the wave-12 / wave-13 agents proposed in their reports (not applied there): every report
line with a function address, its current name (checked against function_renames.csv) and a proposed camelCase name.
A line can hold several pairs ("0xa / 0xb | `x` / `y` -> `p` / `q`"): current names and proposals pair up in order.
Writes function_leads.json: [{address, current, proposals: [{name, reason, source}]}].
usage: extract_function_leads.py <function_renames.csv> <out.json> <report.md>..."""
import json
import os
import re
import sys

renames_path, out_path, reports = sys.argv[1], sys.argv[2], sys.argv[3:]
by_address, by_name = {}, {}
for line in open(renames_path, errors="replace"):
    if line.startswith("0x"):
        address, name = line.rstrip("\r\n").split(",")[:2]
        by_address[int(address, 16)] = name
        by_name[name] = int(address, 16)
FUNCTION_LIKE = re.compile(r"^[a-z0-9]+_[a-z][A-Za-z0-9]*[A-Z][A-Za-z0-9]*$|^[a-z]+[A-Z][A-Za-z0-9]*$")
leads = {}
for report in reports:
    source = os.path.basename(report)
    for line in open(report, errors="replace"):
        names = re.findall(r"`([A-Za-z_][A-Za-z0-9_]*)`", line)
        current = [n for n in names if n in by_name]
        proposed = [n for n in names if n not in by_name and FUNCTION_LIKE.match(n)]
        if not current or not proposed:
            continue
        addresses = [int(a, 16) for a in re.findall(r"0x([0-9a-fA-F]{4,8})", line)]
        # keep only current names whose address the line quotes (the line is about them, not a passing mention)
        current = [n for n in current if by_name[n] in addresses]
        for old, new in zip(current, proposed):
            entry = leads.setdefault(by_name[old], {"address": f"0x{by_name[old]:08x}", "current": old, "proposals": []})
            if new not in [p["name"] for p in entry["proposals"]]:
                entry["proposals"].append({"name": new, "reason": " ".join(line.split())[:600], "source": source})
json.dump(sorted(leads.values(), key=lambda e: e["address"]), open(out_path, "w"), indent=1)
print(f"{len(leads)} functions, {sum(len(e['proposals']) for e in leads.values())} proposals")
for e in sorted(leads.values(), key=lambda e: e["address"]):
    print(e["address"], e["current"], "->", " | ".join(p["name"] for p in e["proposals"]))

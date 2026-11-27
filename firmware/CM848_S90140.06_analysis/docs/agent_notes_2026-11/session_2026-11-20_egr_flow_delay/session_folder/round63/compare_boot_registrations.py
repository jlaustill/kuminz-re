"""Compare the cm848_registerDiagnosticService calls of two .cpp files with whitespace joined: the old one's numeric
service IDs against the new one's BOOT_DIAGNOSTIC_SERVICE member names mapped back to their values, and every
registrar body besides those calls.  usage: compare_registrations.py <repo> <old_renamed.cpp> <new.cpp>"""
import csv
import os
import re
import sys

repo, old_path, new_path = os.path.abspath(sys.argv[1]), sys.argv[2], sys.argv[3]
members = {r[2]: int(r[1], 0) for r in csv.reader(open(os.path.join(
    repo, "firmware/CM848_S90140.06_analysis/output/enums.csv"))) if r and r[0] == "BOOT_DIAGNOSTIC_SERVICE"}
CALL = re.compile(r"cm848_registerDiagnosticService\s*\(\s*([A-Za-z0-9_]+)\s*,\s*(.+?)\s*\)\s*;")


def calls(path):
    text = open(path, errors="replace").read()
    out, rest = [], []
    for block in re.split(r"^// Function: ", text, flags=re.M)[1:]:
        owner = block.split(" @ ", 1)[0]
        if not owner.startswith("cm848_registerBoot"):
            continue
        body = " ".join(re.sub(r"/\*.*?\*/", "", block.split("\n", 1)[-1], flags=re.S).split())
        for value, handler in CALL.findall(body):
            out.append((owner, members.get(value, None) if value in members else int(value, 0), handler, value))
        rest.append((owner, CALL.sub("CALL;", body)))
    return out, rest


old_calls, old_rest = calls(old_path)
new_calls, new_rest = calls(new_path)
print("calls old / new:", len(old_calls), len(new_calls))
print("same (registrar, value, handler) in order:",
      [(a, b, c) for a, b, c, _ in old_calls] == [(a, b, c) for a, b, c, _ in new_calls])
print("new calls not rendered as a member:", [v for _, _, _, v in new_calls if v not in members])
print("registrar bodies equal apart from the calls:", old_rest == new_rest)

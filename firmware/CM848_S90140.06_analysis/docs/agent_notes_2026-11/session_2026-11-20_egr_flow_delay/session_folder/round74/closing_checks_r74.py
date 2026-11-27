"""Round 74 closing checks (the advisor's reads): every span row name and the two retyped words with a '_' prefix
before / after, and the type importer's summary counts in round 73's log and this one.
usage: closing_checks_r74.py <pre.cpp> <new.cpp> <global_variables.csv> <old log> <new log>"""
import csv
import re
import sys

pre, new, gv, old_log, new_log = sys.argv[1:6]
pre_t, new_t = open(pre, errors="replace").read(), open(new, errors="replace").read()
names = []
for r in csv.reader(open(gv)):
    if r and r[0].startswith("0x") and 0x80ddc6 <= int(r[0], 16) <= 0x80de7c and r[1]:
        names.append(r[1])
names += ["fuel_timing_advance_value", "timing_control_status_flags"]
bad = 0
for n in names:
    pat = re.compile(r"(?<![A-Za-z0-9_])_" + re.escape(n) + r"(?![A-Za-z0-9_])")
    b, a = len(pat.findall(pre_t)), len(pat.findall(new_t))
    if b or a:
        print(f"_{n}: before {b} after {a}")
        bad += a
print(f"span names checked: {len(names)}; '_' renders after: {bad}")
for log in (old_log, new_log):
    lines = [l for l in open(log, errors="replace") if "ApplyGlobalVariableTypes" in l and
             re.search(r"(?i)applied|failed|skipped|cleared", l)]
    print(log.split("/")[-1], "|", " ".join(sorted({l.split(">", 1)[-1].strip()[:60] for l in lines})))

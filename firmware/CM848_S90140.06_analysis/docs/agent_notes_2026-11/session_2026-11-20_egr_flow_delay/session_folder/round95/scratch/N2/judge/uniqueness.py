"""Uniqueness of the N2 final names (proposals with the judge's amendments) in CM550: against the frozen global and
function names at any other address, against struct / enum names, and against each other. Also flags any word that is
a known invented abbreviation. usage: python3 uniqueness.py"""
import csv
import json
import re

J = "/home/linux/.claude/jobs/374b0424/tmp/w15/r95/scratch/N2/judge/"
F = "/home/linux/.claude/jobs/374b0424/tmp/w15/r95/frozen/cm550/"
AMEND = {
    "0x00800192": "engine_retarder_full_scale_torque_lookup",
    "0x0080020e": "cylinder_pressure_maintenance_timing_per_temperature_degree_lookup",
    "0x00060640": "cylinder_pressure_maintenance_timing_per_temperature_degree_axis",
    "0x0006065c": "cylinder_pressure_maintenance_timing_per_temperature_degree_values",
    "0x008072f4": "cylinder_balance_engine_speed_axis",
    "0x000611d0": "engine_protection_oil_pressure_limit_engine_speed_axis",
}
gl = {}
for r in csv.reader(open(F + "global_variables.csv")):
    if r and r[0].startswith("0x"):
        gl.setdefault(r[1], set()).add(int(r[0], 16))
fn = {}
for r in csv.reader(open(F + "function_renames.csv")):
    if r and r[0].startswith("0x"):
        fn[r[1]] = int(r[0], 16)
other = set()
for f in ("structure_definitions.csv", "enums.csv"):
    for r in csv.reader(open(F + f)):
        if r and not r[0].startswith("#") and len(r) > 2:
            other.add(r[0])
            other.add(r[2])
props = json.load(open(J + "proposals_globals.json"))
final = {}
for e in props:
    final[e["address"]] = AMEND.get(e["address"], e["proposed_name"])
seen = {}
for a, n in final.items():
    seen.setdefault(n, []).append(a)
problems = 0
for n, addrs in seen.items():
    if len(addrs) > 1:
        print("DUPLICATE among proposals:", n, addrs)
        problems += 1
for a, n in final.items():
    ai = int(a, 16)
    if n in gl and gl[n] - {ai}:
        print("CLASH with an existing global:", n, a, [hex(x) for x in gl[n]])
        problems += 1
    if n in fn:
        print("CLASH with a function:", n, a)
        problems += 1
    if n in other:
        print("CLASH with a struct / field / enum name:", n, a)
        problems += 1
    if re.search(r"(^|_)(init|anc|asg|hsg|lsg|pto|epf|eps|cbd|imt|temp|ptr|cfg|calc|ctrl|val|num|cnt|idx|tbl)(_|$)", n):
        print("ABBREVIATION?", n, a)
        problems += 1
    if 0x803B0A <= ai <= 0x804F93 and not n.endswith("_cal"):
        print("EEPROM window without _cal:", n, a)
        problems += 1
print("final names:", len(final), "problems:", problems)
print("longest:", max(len(n) for n in final.values()), max(final.values(), key=len))

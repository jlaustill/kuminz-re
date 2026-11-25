"""J2 investigator (round 93, read-only): (1) every existing CM550 / CM848 global row that starts inside a proposed
global's extent; (2) every identifier-looking word in the comments / plate comments that is not in a frozen CSV and is
not a proposal of this result.
usage: validate_extents_mentions.py [result.json]"""
import csv
import json
import os
import re
import sys

csv.field_size_limit(10 ** 9)
here = os.path.dirname(os.path.abspath(__file__))
frozen = "/home/linux/.claude/jobs/374b0424/tmp/w15/r93/frozen"
res = json.load(open(sys.argv[1] if len(sys.argv) > 1 else os.path.join(here, "result.json")))

SIZES = {"byte": 1, "sbyte": 1, "word": 2, "short": 2, "dword": 4, "pointer": 4,
         "j1939_control_session_t": 24, "j1939_periodic_transmit_entry_t": 10, "engine_tsc1_ignored_request_t": 8,
         "retarder_tsc1_ignored_request_t": 4}


def rows(path):
    for line in csv.reader(open(path, errors="replace")):
        if line and not line[0].startswith("#"):
            yield line


gl = {}
known = set()
for fw in ("cm550", "cm848"):
    g = {}
    for r in rows(f"{frozen}/{fw}/global_variables.csv"):
        try:
            g[int(r[0], 16)] = (r[1], r[2] if len(r) > 2 else "")
        except ValueError:
            pass
        if len(r) > 1:
            known.add(r[1])
    gl[fw] = g
    for r in rows(f"{frozen}/{fw}/function_renames.csv"):
        if len(r) > 1:
            known.add(r[1])
    for r in rows(f"{frozen}/{fw}/structure_definitions.csv"):
        known.add(r[0])
        if len(r) > 2:
            known.add(r[2])
    for r in rows(f"{frozen}/{fw}/enums.csv"):
        known.add(r[0])
        if len(r) > 2:
            known.add(r[2])

print("---- existing rows inside a proposed extent")
for g in res.get("globals", []):
    fw = g["firmware"].lower()
    a = int(g["address"], 16)
    m = re.fullmatch(r"(\w+)(?:\[(\d+)\])?", g["proposed_type"])
    size = SIZES[m.group(1)] * int(m.group(2) or 1)
    inside = [(b, n) for b, n in gl[fw].items() if a < b < a + size]
    if inside:
        print(f"{fw} 0x{a:x} {g['proposed_name']} ({g['proposed_type']}, {size} bytes): "
              + "; ".join(f"0x{b:x} {n[0]} ({n[1]})" for b, n in sorted(inside)))

proposals = {f["proposed_name"] for f in res["functions"]} | {g["proposed_name"] for g in res.get("globals", [])} \
            | {e["proposed_member"] for e in res.get("enum_members", [])}
print("---- identifiers in comments that are in no frozen CSV and are no proposal")
ident = re.compile(r"\b(?:[a-z][a-z0-9]*(?:_[a-z0-9]+)+|[a-z]+[0-9]*[A-Z][A-Za-z0-9]*(?:_[A-Za-z0-9]+)*|[A-Z][A-Z0-9]*(?:_[A-Z0-9]+)+)\b")
for kind, items, key, fields in (("function", res["functions"], "address", ("plate_comment", "role", "discriminator")),
                                 ("global", res.get("globals", []), "address", ("comment",)),
                                 ("enum", res.get("enum_members", []), "value", ("comment",))):
    for it in items:
        for field in fields:
            for w in sorted(set(ident.findall(it[field]))):
                if w in known or w in proposals:
                    continue
                print(f"{kind} {it[key]} {field}: {w}")

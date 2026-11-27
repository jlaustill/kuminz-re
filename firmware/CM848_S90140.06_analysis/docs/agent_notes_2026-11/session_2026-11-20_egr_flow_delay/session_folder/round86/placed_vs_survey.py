"""Check each placed prototype (the build log's 'Placed <name>: p sp+off:len, ...' lines) against the round 85 survey:
every ROM read of the callee must sit inside one placed parameter, and every call-site push layout must match the
placed slots. usage: placed_vs_survey.py <placed.txt> <post cpp> <classes.json>"""
import json
import re
import sys

addr_of = {name: int(a, 16) for name, a in re.findall(r"^// Function: (\S+) @ (0x[0-9a-f]+)", open(sys.argv[2]).read(), re.M)}
survey = {e["address"]: e for e in json.load(open(sys.argv[3]))["table"]}
SIZE = {"B": 1, "W": 2, "L": 4}
checked = not_in_survey = 0
problems = []
for line in open(sys.argv[1]):
    name, _, rest = line.strip().partition(": ")
    params = [(int(o), int(n)) for o, n in re.findall(r" sp\+(\d+):(\d+)", rest)]
    address = addr_of.get(name)
    entry = survey.get(address)
    if entry is None:
        not_in_survey += 1
        continue
    checked += 1
    for read, count in entry.get("rom_reads", {}).items():
        m = re.match(r"(r|rw|&)\+(\d+)/(\d+|-)", read)
        if not m:
            problems.append(f"{name}: unparsed read {read}")
            continue
        off, width = int(m.group(2)), (1 if m.group(3) == "-" else int(m.group(3)))
        if m.group(1) == "&":       # the slot's address is taken (pea): it must start a placed parameter
            if not any(o == off for o, n in params):
                problems.append(f"{name}: address of +{off} is taken, but no placed parameter starts there {params}")
        elif not any(o <= off and off + width <= o + n for o, n in params):
            problems.append(f"{name}: {m.group(1)} +{off}/{width} is outside every placed parameter {params}")
    for layout in entry.get("layouts", {}):
        for kind, off in re.findall(r"([BWL])@\+(\d+)", layout):
            off, size = int(off), SIZE[kind]
            slot_ok = any((o == off and n == size) or (kind == "W" and n == 1 and o == off + 1) or
                          (kind == "L" and o == off and n == 4) for o, n in params)
            if not slot_ok:
                problems.append(f"{name}: a push {kind}@+{off} matches no placed parameter {params}")
print(f"{checked} placed functions checked against the survey, {not_in_survey} not in it (4-byte-only rows)")
print(f"{len(problems)} problems")
for p in problems:
    print("  ", p)

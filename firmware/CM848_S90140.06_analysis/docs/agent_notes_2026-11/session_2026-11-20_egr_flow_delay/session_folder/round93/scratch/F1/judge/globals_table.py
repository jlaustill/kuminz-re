"""Judge F1: one table for the 43 proposed globals - frozen row, neighbours inside the proposed width, name uniqueness,
the CM848 row carrying the proposed name."""
import json
import re

R = "/home/linux/.claude/jobs/374b0424/tmp/w15/r93"
d = json.load(open(f"{R}/scratch/F1/investigator/result_f1.json"))


def rows(p):
    out = []
    for line in open(p, newline=""):
        line = line.rstrip("\r\n")
        if not line.startswith("0x"):
            continue
        parts = line.split(",", 3)
        while len(parts) < 4:
            parts.append("")
        out.append((int(parts[0], 16), parts[1], parts[2], parts[3]))
    return out


g550 = rows(f"{R}/frozen/cm550/global_variables.csv")
g848 = rows(f"{R}/frozen/cm848/global_variables.csv")
by550 = {}
for r in g550:
    by550.setdefault(r[0], []).append(r)
names550 = {}
for r in g550:
    names550.setdefault(r[1], []).append(r[0])
names848 = {}
for r in g848:
    names848.setdefault(r[1], []).append(r)
f550 = [l.split(",", 2) for l in open(f"{R}/frozen/cm550/function_renames.csv") if l.startswith("0x")]
fn550 = {x[1].strip() for x in f550}
W = {"word": 2, "dword": 4, "FUELING_STATE": 2, "byte": 1}
SIZES = {"byte": 1, "char": 1, "sbyte": 1, "bool": 1, "word": 2, "short": 2, "ushort": 2, "dword": 4, "pointer": 4, "int": 4,
         "uint": 4, "FUELING_STATE": 2, "ENGINE_STATE": 2}
props = {}
for g in d["globals"]:
    props.setdefault(g["proposed_name"], []).append(g["address"])
for g in d["globals"]:
    a = int(g["address"], 16)
    cur = by550.get(a, [])
    print(f"== {g['address']} proposed {g['proposed_name']} : {g['proposed_type']}")
    for r in cur:
        print(f"   frozen row: {r[1]!r} type={r[2]!r} comment={r[3][:260]!r}")
    if not cur:
        print("   frozen row: NONE")
    if (cur[0][1] if cur else "") != g["current_name"]:
        print(f"   !! current_name mismatch: proposal says {g['current_name']!r}")
    w = W[g["proposed_type"]]
    for k in range(1, w):
        if a + k in by550:
            print(f"   !! row inside the width at +{k}: {by550[a + k]}")
    for r in g550:
        if a - 4096 <= r[0] < a and r[2]:
            m = re.match(r"^(\w+)(?:\[(\d+)\])?$", r[2])
            base = m.group(1) if m else r[2]
            n = int(m.group(2)) if m and m.group(2) else 1
            size = SIZES.get(base)
            if size is None:
                if a - r[0] <= 64:
                    print(f"   ?? earlier typed row of unknown size: 0x{r[0]:x} {r[1]} {r[2]}")
            elif r[0] + size * n > a:
                print(f"   !! covered by 0x{r[0]:x} {r[1]} {r[2]}")
    holders = names550.get(g["proposed_name"], [])
    if holders and holders != [a]:
        print(f"   !! name already held in CM550 by {[hex(x) for x in holders]}")
    if g["proposed_name"] in fn550:
        print("   !! name is a CM550 function name")
    if len(props[g["proposed_name"]]) > 1:
        print(f"   !! proposed twice: {props[g['proposed_name']]}")
    for r in names848.get(g["proposed_name"], []):
        print(f"   CM848 same name: 0x{r[0]:x} type={r[2]} comment={r[3][:220]!r}")
    if g["proposed_name"] not in names848:
        print("   CM848: no row with this name")

"""Round 94 tooling: extend apply_r94.py with
- struct templates from overrides_r94.json ("structs": {fw: {name: [[field, type, size, comment], ...]}}), added as
  type-only templates before the globals are checked (J2 proposes CM550 structs that exist only in its notes);
- row removals from overrides_r94.json ("remove_globals": {fw: {address: "instance.field path or empty"}}), done
  before the globals (rows inside a new struct instance);
- a cross-batch check: two batches giving the same address different final names is a problem unless an override
  names it (the override then applies to both).
Idempotent. usage: patch_apply_r94.py <apply_r94.py>"""
import sys

p = sys.argv[1]
s = open(p).read()


def rep(old, new):
    global s
    if new in s:
        return
    assert s.count(old) == 1, (old[:70], s.count(old))
    s = s.replace(old, new)


rep('''def spans(fw):''', '''STRUCT_ROWS = []
for fw, structs in (OVERRIDES.get("structs") or {}).items():
    t = state[fw]["structure_definitions.csv"]
    E = "\\r\\n" if "\\r\\n" in t else "\\n"
    for sname, fields in structs.items():
        if re.search(rf"^{re.escape(sname)},,", t, re.M):
            continue
        assert sum(int(f[2]) for f in fields) == int(OVERRIDES["struct_sizes"][fw][sname]), (sname, "field sizes")
        rows = [f"# {sname} ({OVERRIDES['struct_sizes'][fw][sname]} bytes; {R})"]
        for field, ftype, size, comment in fields:
            c = " ".join(str(comment).split())
            c = '"' + c.replace('"', "'") + '"' if ("," in c or '"' in c) else c
            rows.append(f"{sname},,{field},{ftype},{size},{c},,verified")
        t = t.rstrip("\\r\\n") + E + E + E.join(rows) + E
        types[fw].add(sname)
        WIDTH[fw][sname] = int(OVERRIDES["struct_sizes"][fw][sname])
        STRUCT_ROWS.append(f"{fw} struct {sname} added ({len(fields)} fields)")
    state[fw]["structure_definitions.csv"] = t
for fw, rows in (OVERRIDES.get("remove_globals") or {}).items():
    lines = state[fw]["global_variables.csv"].split("\\n")
    for address, path in rows.items():
        key = norm(address)
        idx = next((i for i, l in enumerate(lines) if l[:10].lower() == key and l[10:11] == ","), None)
        if idx is None:
            continue
        old = lines[idx].split(",")[1]
        del lines[idx]
        if path and old:
            maps[fw].append((key, path, old))
        STRUCT_ROWS.append(f"{fw} removed global {key} {old} (inside a new instance{': ' + path if path else ''})")
    state[fw]["global_variables.csv"] = "\\n".join(lines)
report.extend(STRUCT_ROWS)
ASSIGNED = {}


def spans(fw):''')
rep('''        new = ov.get("name") or clean(v.get("final_name")) or g["proposed_name"]
        typ = ov.get("type") or clean(v.get("final_type")) or g["proposed_type"]''',
    '''        new = ov.get("name") or clean(v.get("final_name")) or g["proposed_name"]
        typ = ov.get("type") or clean(v.get("final_type")) or g["proposed_type"]
        prior = ASSIGNED.get((fw, a))
        if prior and prior[1] != new and not ov.get("name"):
            problems.append(f"{b}: global {fw} {a}: {new} here, {prior[1]} in batch {prior[0]} - decide with an override")
            continue
        ASSIGNED[(fw, a)] = (b, new)''')
open(p, "w").write(s)
print("patched")

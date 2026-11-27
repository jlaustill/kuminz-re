"""Round 97 stage E (batches R1-R4): overrides_r97.json and the R4 batch fix-up.
- R4: the judge named 0x80847a / 0x80847c, which the investigator left out (no proposal element); they are added to the
  proposal's globals with the judge's names, types and comments (current names from the CSV).
- structs: CM550 cm550_low_speed_governor_gain_set_t (R1's judge: proportional / integral / derivative gain, short at
  +0 / +2 / +4; the RAM dump's working gains 530 / 283 / 55 equal the set at 0x808230 that both pointers hold).
- new_enums: LOW_SPEED_GOVERNOR_GAIN_STATE, size 2, both firmwares (R1's enum_members create it).
- remove_globals: every live row strictly inside a judged global's final span (R1's gain set instances, R3's dword
  0x8001a4 over 0x8001a6 ...). A row that is itself a judged element is kept and reported.
- drop: judged function elements whose final comment is 'Keep the round N name ...' (no change).
usage: make_overrides_r97_e.py <repo> <overrides.json> <batch.json>..."""
import csv
import json
import os
import re
import sys

repo, out_path, batch_paths = os.path.abspath(sys.argv[1]), sys.argv[2], sys.argv[3:]
OUT = {"CM550": os.path.join(repo, "firmware/CM550_J90350.00_analysis/output"),
       "CM848": os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")}
GAIN = [["proportional_gain", "short", 2, "The proportional gain (LSPPGN in the working copy): +0"],
        ["integral_gain", "short", 2, "The integral gain (LSITGN): +2"],
        ["derivative_gain", "short", 2, "The derivative gain (LSDVGN): +4"]]
STRUCTS = {"CM550": {"cm550_low_speed_governor_gain_set_t": GAIN}}
SIZES = {"CM550": {"cm550_low_speed_governor_gain_set_t": 6}}
NEW_ENUMS = {"CM550": {"LOW_SPEED_GOVERNOR_GAIN_STATE": 2}, "CM848": {"LOW_SPEED_GOVERNOR_GAIN_STATE": 2}}
PRIMITIVE = {"byte": 1, "char": 1, "bool": 1, "sbyte": 1, "uchar": 1, "word": 2, "short": 2, "ushort": 2, "sword": 2,
             "dword": 4, "int": 4, "uint": 4, "pointer": 4, "float": 4, "long": 4, "ulong": 4, "undefined": 1,
             "undefined2": 2, "undefined4": 4, "i8": 1, "u8": 1, "i16": 2, "u16": 2, "i32": 4, "u32": 4}


def known(fw):
    k = {}
    for r in csv.reader(open(os.path.join(OUT[fw], "enums.csv"), newline="")):
        if len(r) > 4 and r[0] and not r[0].startswith("#") and r[4].strip().isdigit():
            k.setdefault(r[0], int(r[4]))
    for r in csv.reader(l for l in open(os.path.join(OUT[fw], "structure_definitions.csv"), newline="") if not l.startswith("#")):
        if len(r) > 4 and r[0] and r[0] != "struct_name" and r[4].strip().isdigit():
            k[r[0]] = k.get(r[0], 0) + int(r[4])
    k.update(SIZES.get(fw, {}))
    k.update(NEW_ENUMS.get(fw, {}))
    return k


def width(t, k):
    t = t.strip()
    if t.endswith("*"):
        return 4
    m = re.match(r"^(.+?)((?:\[\d+\])+)$", t)
    if m:
        n = 1
        for d in re.findall(r"\[(\d+)\]", m.group(2)):
            n *= int(d)
        w = width(m.group(1), k)
        return None if w is None else w * n
    return PRIMITIVE.get(t) or k.get(t)


# R4 fix-up
for p in batch_paths:
    d = json.load(open(p))
    if d["batch"] != "R4":
        continue
    have = {g["address"].lower() for g in d["proposal"]["globals"]}
    names = {}
    for line in open(os.path.join(OUT["CM550"], "global_variables.csv"), newline=""):
        q = line.rstrip("\r\n").split(",", 2)
        if len(q) > 1 and q[0].startswith("0x"):
            names[q[0].lower()] = q[1]
    for v in d["verdict"]["verdicts"]:
        a = v["address"].lower()
        if v["kind"] == "global" and a in ("0x0080847a", "0x0080847c") and a not in have:
            d["proposal"]["globals"].append({"firmware": "CM550", "address": a, "current_name": names.get(a, ""),
                                             "proposed_name": v["final_name"], "proposed_type": v["final_type"],
                                             "comment": v["final_comment"], "evidence": v["reason"], "confidence": "high"})
            print("R4: added", a, v["final_name"])
    json.dump(d, open(p, "w"), indent=1)

rows = {fw: [] for fw in OUT}
for fw in OUT:
    for line in open(os.path.join(OUT[fw], "global_variables.csv"), newline="").read().split("\n"):
        q = line.rstrip("\r").split(",", 3)
        if len(q) > 2 and q[0].startswith("0x"):
            rows[fw].append((int(q[0], 16), q[1]))
elements = {fw: set() for fw in OUT}
judged = []
o = {}
for p in batch_paths:
    d = json.load(open(p))
    vd = {(x.get("kind"), str(x.get("address")).lower()): x for x in d["verdict"]["verdicts"]}
    for g in d["proposal"].get("globals") or []:
        fw = g.get("firmware") or "CM550"
        v = vd.get(("global", str(g["address"]).lower())) or {}
        if v.get("verdict") in ("CONFIRMED", "AMENDED"):
            a = int(g["address"], 16)
            final = v.get("final_name") or g["proposed_name"]
            if "." in final:            # a field of a struct instance: the judge deletes the flat row (round 91 precedent)
                o[f"global|{fw}|0x{a:08x}"] = {"drop": True, "reason": f"a field of a struct instance ({final}): the row goes"}
                o.setdefault("_dotted", {}).setdefault(fw, {})[f"0x{a:08x}"] = final
                print(f"dotted {fw} 0x{a:x} -> {final}: dropped, its row goes")
                continue
            elements[fw].add(a)
            judged.append((fw, a, final, (v.get("final_type") or g.get("proposed_type") or "").strip()))
    for kind, items in (("function", d["proposal"].get("functions") or []), ("cm848_function", d["proposal"].get("cm848_functions") or [])):
        for f in items:
            v = vd.get((kind, f["address"].lower())) or {}
            if re.match(r"^\s*Keep the round \d+ name", v.get("final_comment") or f.get("plate_comment") or ""):
                o[f"{kind}|0x{int(f['address'], 16):08x}"] = {"drop": True, "reason": "the judge kept the earlier name and plate"}
remove = {fw: {} for fw in OUT}
for fw, a, name, typ in judged:
    w = width(typ, known(fw)) if typ else None
    if typ and w is None:
        print("UNKNOWN WIDTH", fw, hex(a), name, typ)
    if not w or w < 2:
        continue
    for ra, rn in rows[fw]:
        if a < ra < a + w:
            if ra in elements[fw]:
                print(f"KEEP {fw} 0x{ra:x} {rn}: a judged element inside {name} {typ}")
                continue
            remove[fw][f"0x{ra:08x}"] = ""
            print(f"remove {fw} 0x{ra:x} {rn or '(unnamed)'}: inside {name} {typ}")
for fw in STRUCTS:
    for s, fields in STRUCTS[fw].items():
        for f in fields:
            f[3] = f[3].replace(",", " /")
for fw, paths in (o.pop("_dotted", {}) or {}).items():
    for a, path in paths.items():
        remove[fw][a] = path                            # the old name maps to the field path for the refresh
o.update({"structs": STRUCTS, "struct_sizes": SIZES, "new_enums": NEW_ENUMS, "remove_globals": {fw: r for fw, r in remove.items() if r}})
json.dump(o, open(out_path, "w"), indent=1)
print({fw: len(r) for fw, r in remove.items()}, "rows to remove;", sum(1 for k in o if k.startswith(("function|", "cm848_function|"))), "kept elements dropped")

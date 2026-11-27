"""Round 97 stage F (batches R5-R7): overrides_r97.json for the apply.
- structs: R5's four CM550 types from the investigator's proposed_structure_definitions.csv (the judge proved the
  layout field by field); their '#' header lines go to struct_headers_r97f.json for the post-step.
- new_enums: CM550 ENGINE_RETARDER_COMMAND_SOURCE, size 2 (R6). ENGINE_PROTECTION_TASK is the renamed
  PROTECTION_STATE (rename_enum_r97f.py runs first).
- remove_globals: every live row strictly inside a judged global's final span (R5's channel tables and fault logs,
  R7's i32[6] at 0x8002ac); a row that is itself a judged element is kept and reported.
- drop: judged dotted names (a field of an instance: the row goes) and 'Keep the round N name' functions.
- comment overrides: 0x80060e (the judge's text ends with an applier note).
usage: make_overrides_r97_f.py <repo> <overrides.json> <batch.json>..."""
import csv
import json
import os
import re
import sys

repo, out_path, batch_paths = os.path.abspath(sys.argv[1]), sys.argv[2], sys.argv[3:]
W = "/home/linux/.claude/jobs/374b0424/tmp/w15/r97"
OUT = {"CM550": os.path.join(repo, "firmware/CM550_J90350.00_analysis/output"),
       "CM848": os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")}
PROPOSED = f"{W}/scratch/R5/investigator/proposed_structure_definitions.csv"
EXPECTED = {"engine_protection_fault_log_entry_t": 8, "engine_protection_channel_configuration_t": 36,
            "cm550_engine_protection_channel_state_t": 46, "engine_protection_channel_history_t": 30}
fields, headers = {}, {}
for line in open(PROPOSED, newline=""):
    if line.startswith("#"):
        m = re.match(r"^# ([A-Za-z0-9_]+): (.*)$", line.rstrip("\r\n"))
        headers[m.group(1)] = m.group(2)
        continue
    r = next(csv.reader([line]))
    if r[0] == "struct_name":
        continue
    assert r[1] == "" and r[7] == "verified", r
    fields.setdefault(r[0], []).append([r[2], r[3], int(r[4]), r[5]])
SIZES = {s: sum(f[2] for f in fl) for s, fl in fields.items()}
assert SIZES == EXPECTED, SIZES
STRUCTS = {"CM550": fields}
NEW_ENUMS = {"CM550": {"ENGINE_RETARDER_COMMAND_SOURCE": 2}}
PRIMITIVE = {"byte": 1, "char": 1, "bool": 1, "sbyte": 1, "uchar": 1, "word": 2, "short": 2, "ushort": 2, "sword": 2,
             "dword": 4, "int": 4, "uint": 4, "pointer": 4, "float": 4, "long": 4, "ulong": 4, "undefined": 1,
             "undefined2": 2, "undefined4": 4, "i8": 1, "u8": 1, "i16": 2, "u16": 2, "i32": 4, "u32": 4,
             "sdword": 4}


def known(fw):
    k = {}
    for r in csv.reader(open(os.path.join(OUT[fw], "enums.csv"), newline="")):
        if len(r) > 4 and r[0] and not r[0].startswith("#") and r[4].strip().isdigit():
            k.setdefault(r[0], int(r[4]))
    for r in csv.reader(l for l in open(os.path.join(OUT[fw], "structure_definitions.csv"), newline="") if not l.startswith("#")):
        if len(r) > 4 and r[0] and r[0] != "struct_name" and r[4].strip().isdigit():
            k[r[0]] = k.get(r[0], 0) + int(r[4])
    if fw == "CM550":
        k.update(SIZES)
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
            if final.strip() in ("(delete)", "") or "(delete" in (v.get("final_type") or g.get("proposed_type") or ""):
                o[f"global|{fw}|0x{a:08x}"] = {"drop": True, "reason": "the judge deletes the row (a junk row inside an instance)"}
                o.setdefault("_deleted", {}).setdefault(fw, set()).add(a)
                print(f"delete {fw} 0x{a:x} {g.get('current_name')}: dropped, its row goes")
                continue
            if "." in final:
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
def layouts(fw):
    """{struct: [(offset, size, field, type)]} from the type-only templates (and R5's new types for CM550)."""
    out = {}
    src = [r for r in csv.reader(l for l in open(os.path.join(OUT[fw], "structure_definitions.csv"), newline="") if not l.startswith("#"))
           if len(r) > 4 and r[0] and r[0] != "struct_name" and r[1] == "" and r[4].strip().isdigit()]
    if fw == "CM550":
        src += [[s, "", f[0], f[1], str(f[2])] for s, fl in fields.items() for f in fl]
    for r in src:
        lst = out.setdefault(r[0], [])
        size = int(r[4])
        if size == 0:
            continue                                     # a bitfield continuation shares its opener's unit
        off = lst[-1][0] + lst[-1][1] if lst else 0
        lst.append((off, size, r[2], r[3]))
    return out


def path_in(fw, base_name, typ, off):
    """The C path of byte offset off inside base_name of type typ, or '' when it is not a member's start."""
    k = known(fw)
    m = re.match(r"^(.+?)\[(\d+)\]$", typ.strip())
    elem, count = (m.group(1), int(m.group(2))) if m else (typ.strip(), 1)
    w = width(elem, k)
    if not w:
        return ""
    index, rem = divmod(off, w)
    head = f"{base_name}[{index}]" if m else base_name
    lay = layouts(fw).get(elem)
    if not lay:
        return head if rem == 0 and m else ""
    for foff, fsize, fname, ftype in lay:
        if foff <= rem < foff + fsize:
            fw_width = width(ftype, k) or fsize
            if rem == foff:
                return f"{head}.{fname}" if fname else ""
            sub, srem = divmod(rem - foff, fw_width)
            return f"{head}.{fname}[{sub}]" if srem == 0 and fsize > fw_width and fname else ""
    return ""


remove = {fw: {} for fw in OUT}
names_of = {fw: dict(rows[fw]) for fw in OUT}
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
            remove[fw][f"0x{ra:08x}"] = path_in(fw, name, typ, ra - a) if rn else ""
            if rn and not remove[fw][f"0x{ra:08x}"]:
                print(f"NO PATH {fw} 0x{ra:x} {rn} inside {name} {typ} (+{ra - a})")
for fw, addrs in (o.pop("_deleted", {}) or {}).items():
    for a in addrs:
        host = [(ja, jn, jt) for jf, ja, jn, jt in judged if jf == fw and ja < a < ja + (width(jt, known(fw)) or 0)]
        assert host, (fw, hex(a), "a deleted row outside every judged span")
        ja, jn, jt = host[0]
        remove[fw][f"0x{a:08x}"] = path_in(fw, jn, jt, a - ja) if names_of[fw].get(a) else ""
        print(f"deleted {fw} 0x{a:x} {names_of[fw].get(a)} -> {remove[fw][f'0x{a:08x}'] or '(no path)'}")
for fw, paths in (o.pop("_dotted", {}) or {}).items():
    for a, path in paths.items():
        remove[fw][a] = path
o["global|CM550|0x0080060e"] = {"comment": (
    "The round-robin task of cm550_runEngineProtectionScheduler (CM848's engine_protection_task_index): 0 the "
    "over-limit durations, 1 the restart severity, 2 the fault derate fuel limit, 3 the engine speed limit and the "
    "fault logs, 4 the shutdown. It advances once per call while engine protection is enabled (it holds while EPEN "
    "is clear), wraps after 4 and is cleared by cm550_initializeEngineProtection. Typed ENGINE_PROTECTION_TASK (the "
    "enum was PROTECTION_STATE, which nothing used).")}
o.update({"structs": STRUCTS, "struct_sizes": {"CM550": SIZES}, "new_enums": NEW_ENUMS,
          "remove_globals": {fw: r for fw, r in remove.items() if r}})
json.dump(o, open(out_path, "w"), indent=1)
json.dump(headers, open(f"{W}/struct_headers_r97f.json", "w"), indent=1)
print({fw: len(r) for fw, r in remove.items()}, "rows to remove;", sum(1 for k in o if k.startswith(("function|", "cm848_function|"))), "kept elements dropped")

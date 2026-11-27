"""Round 96: the Q1 / Q2 / Q4 part of overrides_r96.json (merged into the file; the Q5 element keys stay).
- structs: CM550 copies of CM848's j1939_pgn65249_payload_t (19 bytes, Q1), j1939_pgn_handler_entry_t (6, Q2) and
  j1939_pgn65261_payload_t (8, Q2), read from CM848's structure_definitions.csv; the new j1939_pgn65230_payload_t
  (8 bytes, both firmwares, Q2) and CM550's j1708_memory_write_record_t (10 bytes, Q4) from the judges' layouts.
- remove_globals: every live row strictly inside the span of a judged global whose final type is wider than one row,
  plus the judges' named extras (Q2: CM550 0x8035e0 inside the 0x8035de dword; Q4: 0x801a6c inside the 0x801a6a dword,
  0x801a85 inside the 0x801a84 word). A row that is itself a judged element is never removed (reported).
usage: make_overrides_r96_q124.py <repo> <overrides_r96.json> <batch.json>..."""
import csv
import json
import os
import re
import sys

repo, out_path, batch_paths = os.path.abspath(sys.argv[1]), sys.argv[2], sys.argv[3:]
OUT = {"CM550": os.path.join(repo, "firmware/CM550_J90350.00_analysis/output"),
       "CM848": os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")}


def cm848_fields(name):
    rows = []
    for r in csv.reader(l for l in open(os.path.join(OUT["CM848"], "structure_definitions.csv"), newline="") if not l.startswith("#")):
        if len(r) > 5 and r[0] == name and r[2]:
            rows.append([r[2], r[3], int(r[4]), r[5]])
    assert rows, name
    return rows


PGN65230 = [["active_trouble_code_count", "byte", 1, "DM5 byte 1: the number of active diagnostic trouble codes (SPN 1218)"],
            ["previously_active_trouble_code_count", "byte", 1, "DM5 byte 2: the number of previously active codes (SPN 1219)"],
            ["obd_compliance", "byte", 1, "DM5 byte 3: OBD compliance (SPN 1220)"],
            ["continuously_monitored_systems_support", "byte", 1, "DM5 byte 4: continuously monitored systems support / status (SPN 1221)"],
            ["non_continuously_monitored_systems_support", "word", 2, "DM5 bytes 5-6: non-continuously monitored systems support (SPN 1222)"],
            ["non_continuously_monitored_systems_status", "word", 2, "DM5 bytes 7-8: non-continuously monitored systems status (SPN 1223)"]]
J1708 = [["address", "dword", 4, "the target address (from cm550_lookupParameterIdAddress when the item names a 2-byte parameter ID)"],
         ["data_pointer", "byte*", 4, "the item's data in the J1708 receive ring"],
         ["length", "byte", 1, "the number of bytes to write"],
         ["region_type", "MEMORY_REGION_TYPE", 1, "the memory region type of the target (picks the writer)"]]
STRUCTS = {"CM550": {"j1939_pgn65249_payload_t": cm848_fields("j1939_pgn65249_payload_t"),
                     "j1939_pgn_handler_entry_t": cm848_fields("j1939_pgn_handler_entry_t"),
                     "j1939_pgn65261_payload_t": cm848_fields("j1939_pgn65261_payload_t"),
                     "j1939_pgn65230_payload_t": PGN65230,
                     "j1708_memory_write_record_t": J1708},
           "CM848": {"j1939_pgn65230_payload_t": PGN65230}}
for fw in STRUCTS:
    for s, fields in STRUCTS[fw].items():
        for f in fields:
            f[3] = f[3].replace(",", " /")                       # the quote-aware struct parser: no commas
SIZES = {fw: {s: sum(f[2] for f in fields) for s, fields in d.items()} for fw, d in STRUCTS.items()}
assert SIZES["CM550"]["j1939_pgn65249_payload_t"] == 19 and SIZES["CM550"]["j1939_pgn_handler_entry_t"] == 6
assert SIZES["CM550"]["j1939_pgn65261_payload_t"] == 8 and SIZES["CM550"]["j1939_pgn65230_payload_t"] == 8
assert SIZES["CM550"]["j1708_memory_write_record_t"] == 10
EXTRA = {"CM550": {"0x008035e0": "", "0x00801a6c": "", "0x00801a85": ""}}
PRIMITIVE = {"byte": 1, "char": 1, "bool": 1, "sbyte": 1, "uchar": 1, "i8": 1, "u8": 1, "word": 2, "short": 2,
             "ushort": 2, "i16": 2, "u16": 2, "sword": 2, "dword": 4, "int": 4, "uint": 4, "i32": 4, "u32": 4,
             "pointer": 4, "float": 4, "long": 4, "ulong": 4}


def sizes(fw):
    s = {}
    for r in csv.reader(open(os.path.join(OUT[fw], "enums.csv"), newline="")):
        if len(r) > 4 and r[0] and not r[0].startswith("#") and r[4].strip().isdigit():
            s.setdefault(r[0], int(r[4]))
    for r in csv.reader(l for l in open(os.path.join(OUT[fw], "structure_definitions.csv"), newline="") if not l.startswith("#")):
        if len(r) > 4 and r[0] and r[0] != "struct_name" and r[4].strip().isdigit():
            s[r[0]] = s.get(r[0], 0) + int(r[4])
    s.update(SIZES.get(fw, {}))
    return s


def width(t, known):
    t = t.strip()
    if t.endswith("*"):
        return 4
    m = re.match(r"^(.+?)((?:\[\d+\])+)$", t)
    if m:
        n = 1
        for d in re.findall(r"\[(\d+)\]", m.group(2)):
            n *= int(d)
        w = width(m.group(1), known)
        return None if w is None else w * n
    return PRIMITIVE.get(t) or known.get(t)


rows = {fw: [] for fw in OUT}
for fw in OUT:
    for line in open(os.path.join(OUT[fw], "global_variables.csv"), newline="").read().split("\n"):
        parts = line.rstrip("\r").split(",", 3)
        if len(parts) > 2 and parts[0].startswith("0x"):
            rows[fw].append((int(parts[0], 16), parts[1], parts[2]))
elements = {fw: set() for fw in OUT}
judged = []
for p in batch_paths:
    d = json.load(open(p))
    vd = {(x.get("kind"), str(x.get("address")).lower()): x for x in d["verdict"]["verdicts"]}
    for g in d["proposal"].get("globals") or []:
        fw = g.get("firmware") or "CM550"
        v = vd.get(("global", str(g["address"]).lower())) or {}
        if v.get("verdict") not in ("CONFIRMED", "AMENDED"):
            continue
        a = int(g["address"], 16)
        elements[fw].add(a)
        judged.append((fw, a, v.get("final_name") or g["proposed_name"], (v.get("final_type") or g.get("proposed_type") or "").strip(), d["batch"]))
remove = {fw: {} for fw in OUT}
for fw, a, name, typ, b in judged:
    w = width(typ, sizes(fw)) if typ else None
    if not w or w < 2:
        continue
    for ra, rn, rt in rows[fw]:
        if a < ra < a + w:
            if ra in elements[fw]:
                print(f"KEEP {fw} 0x{ra:x} {rn}: a judged element inside {name} ({b})")
                continue
            remove[fw][f"0x{ra:08x}"] = ""
for fw, extra in EXTRA.items():
    for a, path in extra.items():
        remove[fw].setdefault(a, path)
try:
    o = json.load(open(out_path))
except (OSError, ValueError):
    o = {}
o["structs"], o["struct_sizes"] = STRUCTS, SIZES
o["remove_globals"] = {fw: r for fw, r in remove.items() if r}
json.dump(o, open(out_path, "w"), indent=1)
print({fw: len(r) for fw, r in remove.items()}, "rows to remove;", {fw: list(d) for fw, d in SIZES.items()})

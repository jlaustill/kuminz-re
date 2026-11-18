"""Summarize the wave-11 shape proposals for triage: kind, name / type, address, size, the rows they drop, and flags
(copy window = boot-kernel time-shared RAM 0x3f9800-0x3fdb30 or the CMF area 0x3fdba4-0x3fdc38, EEPROM mirror,
named rows dropped). Usage: triage_shapes.py <result dir>"""
import glob
import json
import os
import sys

TYPE_SIZE = {"byte": 1, "word": 2, "dword": 4, "i16": 2, "i8": 1, "i32": 4, "pointer": 4}


def flags(address, size, name, drop):
    out = []
    if 0x3f9800 <= address < 0x3fdb30 or 0x3fdba4 <= address < 0x3fdc38:
        out.append("TIME-SHARED")
    if 0x3fd482 <= address <= 0x3feec1:
        out.append("EEPROM" + ("" if name.endswith("_cal") else " (no _cal!)"))
    named = [d for d in drop if not d.split(" ", 1)[-1].startswith(("DAT_", "PTR_", "BYTE_", "WORD_"))]
    if named:
        out.append(f"drops {len(named)} named")
    return out


for path in sorted(glob.glob(os.path.join(sys.argv[1], "result_W11_*.jsonl"))):
    group = path.rsplit("_", 1)[-1][:-6]
    for line in open(path):
        line = line.strip()
        if not line:
            continue
        r = json.loads(line)
        k = r.get("kind")
        if k == "array_proposal":
            a = int(r["address"], 16)
            print(f"{group:9} ARRAY  0x{a:06x} {r['name']} {r['element_type']}[{r['count']}] drop {len(r.get('drop_rows', []))} "
                  + " ".join(flags(a, 0, r["name"], r.get("drop_rows", []))))
        elif k == "struct_proposal":
            for inst in r.get("instances", []):
                a = int(inst["address"], 16)
                print(f"{group:9} STRUCT 0x{a:06x} {inst['name']} {r['type']}(size {r.get('size')}) x{inst.get('count', 1)} "
                      f"drop {len(r.get('drop_rows', []))} " + " ".join(flags(a, 0, inst["name"], r.get("drop_rows", []))))
            if not r.get("instances"):
                print(f"{group:9} STRUCT (type only) {r['type']} size {r.get('size')}")
        elif k == "bitfield_proposal":
            a = int(r["address"], 16)
            print(f"{group:9} BITS   0x{a:06x} {r['name']} {r['struct']} {r['storage_bytes']} bytes, {len(r['bits'])} bits "
                  f"drop {len(r.get('drop_rows', []))} " + " ".join(flags(a, 0, r["name"], r.get("drop_rows", []))))

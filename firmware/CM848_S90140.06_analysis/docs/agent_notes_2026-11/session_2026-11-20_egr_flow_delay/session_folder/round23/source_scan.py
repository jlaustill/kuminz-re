"""Round 23: SENSOR_VALUE_SOURCE's reach (round 19 lead). Every global and every struct field whose name ends in
_source: its e2m record through the parameter ID table, the record's value list, and every literal the code stores
or compares. A word qualifies when the list (in any order) is PRIMARY / BACKUP / DEFAULT or its PRIMARY / BACKUP
subset at 0 / 1 / 2, and the code uses no other literal. Rows already typed SENSOR_VALUE_SOURCE are reported as typed.
(The first version only took word globals and one list order, so it printed 7 of stage B's 10; stage C added the
i16 global and the struct fields after the review.)
usage: source_scan.py <firmware dir> <source_values.py>"""
import os
import re
import subprocess
import sys

fw, source_values = sys.argv[1], sys.argv[2]
out = os.path.join(fw, "CM848_S90140.06_analysis", "output")
cpp_path = os.path.join(out, "cm848_rom.ghidra.cpp")
code = re.sub(r"/\*.*?\*/", "", open(cpp_path).read(), flags=re.S)
E2M = os.path.join(fw, "../e2m-analysis/CHR/CHR_CC_11.45.01.07.e2m")
records = {}
for line in open(E2M, errors="replace"):
    f = line.split(";")[0].split(",")
    if len(f) > 18:
        records[(f[2], int(f[3], 16) if re.fullmatch(r"[0-9A-Fa-f]+", f[3]) else -1)] = f[-1]
VALUES = {"0": "PRIMARY", "1": "BACKUP", "2": "DEFAULT"}


def list_ok(values):
    pairs = dict(p.split("=", 1) for p in values.split(":") if "=" in p)
    norm = {str(int(k, 16)) if re.fullmatch(r"[0-9A-Fa-f]+", k) else k: v.strip() for k, v in pairs.items()}
    return bool(norm) and set(norm) <= set(VALUES) and all(VALUES[k] == v for k, v in norm.items()) and "0" in norm


def e2m_list(address):
    line = subprocess.run(["python3", os.path.join(fw, "scripts/e2m_block_addresses.py"), "--address", hex(address)],
                          capture_output=True, text=True).stdout.strip().split("\n")[-1]
    m = re.match(r"(\w+) \+(\w+) ", line)
    return records.get((m.group(1), int(m.group(2), 16)), "") if m else ""


candidates = []  # (label, address, type, literal regex)
instances = {}
for l in open(os.path.join(out, "global_variables.csv")):
    if l.startswith("0x"):
        a, n, t = l.split(",", 3)[:3]
        # dotted rows (instance.field, no type) only document a struct field; the struct pass below covers it
        if n.endswith("_source") and "." not in n:
            candidates.append((n, int(a, 16), t, rf"\b{re.escape(n)}\s*(==|!=|=)\s*(\w+)"))
        if t.endswith("_t") and n:
            instances.setdefault(t, []).append((n, int(a, 16)))
offsets = {}
for l in open(os.path.join(out, "structure_definitions.csv")):
    r = l.rstrip("\n").split(",")
    if len(r) > 4 and not r[0].startswith("#") and r[0].endswith("_t") and r[2]:
        off = offsets.setdefault(r[0], [0, {}])
        if r[2].endswith("_source"):
            off[1][r[2]] = (off[0], r[3])
        if r[4].isdigit() and not r[3].startswith("bitfield"):
            off[0] += int(r[4])
for struct, (size, fields) in offsets.items():
    for inst, base in instances.get(struct, []):
        for field, (o, t) in fields.items():
            candidates.append((f"{inst}.{field}", base + o, t, rf"\b{re.escape(inst)}\.{field}\s*(==|!=|=)\s*(\w+)"))
for label, address, typ, pat in candidates:
    values = e2m_list(address)
    literals = sorted({v for _, v in re.findall(pat, code)})
    if typ == "SENSOR_VALUE_SOURCE":
        verdict = "typed    "
    elif list_ok(values) and all(x in VALUES or x.startswith("SENSOR_VALUE_SOURCE_") for x in literals):
        verdict = "QUALIFIES"
    else:
        verdict = "no       "
    print(f"{verdict} {address:#x} {label} [{typ}] list={values!r} literals={literals}")

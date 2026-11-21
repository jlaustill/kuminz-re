"""Mechanical pre-pass over bin 5: _cal vs region, banned tokens, shape flags.
usage: prepass.py"""
import json
import re

data = json.load(open("/home/linux/.claude/jobs/374b0424/tmp/w15/bins/bin5.json"))
BANNED = {"init", "std", "ch19", "ch", "freq", "prop", "temp", "cnt", "ref", "val", "calc", "cfg", "coef", "lim", "lmt",
          "tmptr", "thd", "cmd", "amb", "avg", "frac", "adj", "sw", "pos", "filt", "diag", "ovr", "vlv", "pct", "cyl", "est",
          "press", "spd", "accel", "hyst", "inj", "veh", "baro", "alt", "trq", "batt", "imt", "ct", "aps", "icp", "cot", "mcf",
          "cmf", "vgt", "pto", "cc", "eb", "jcomm", "el", "tpe", "chp", "lsg", "hsg", "asg", "vsg", "pp", "esp", "tgc", "tw", "rsg",
          "bdo", "oc", "nv", "dat42", "etc1", "pci", "ifr", "ecm", "mm3s"}
print(f"{'#':>2} {'address':10} {'name':62} flags")
for i, r in enumerate(data):
    name = r["label_in_cpp"]
    a = int(r["address"], 16)
    in_mirror = 0x3fd482 <= a <= 0x3feec1
    flags = []
    if name.endswith("_cal") and not in_mirror:
        flags.append("WRONG_CAL(has _cal, not mirror)")
    if in_mirror and not name.endswith("_cal"):
        flags.append("MISSING_CAL(mirror)")
    toks = set(re.split(r"_+", name))
    bad = sorted(t for t in toks if t in BANNED)
    if bad:
        flags.append("tokens:" + ",".join(bad))
    sz = int(r["size_bytes"])
    t = r["current_row_type"]
    width = {"byte": 1, "word": 2, "dword": 4, "i16": 2, "i32": 4, "i8": 1, "pointer": 4}.get(t)
    if width is not None and width != sz:
        flags.append(f"WIDTH(row {t}={width}B, record {sz}B)")
    if sz > 1 and a % 2:
        flags.append("ODD_ADDRESS")
    if not r["access_widths"].split("->")[0].strip().strip("{}"):
        flags.append("NO_DISP_ACCESS(address-taken?)")
    if r["current_row_type"].endswith("]") or r["current_row_type"].isupper():
        flags.append(f"ARRAY/STRUCT type {t}")
    print(f"{i:>2} {r['address']:10} {name:62} {'; '.join(flags)}")

"""Round 96 (read-only): struct and enum TYPE names with invented abbreviations, both firmwares, with their row count.
usage: type_name_abbreviations_r96.py <repo>"""
import collections
import csv
import os
import re
import sys

repo = os.path.abspath(sys.argv[1])
WATCH = {"ptr", "msg", "func", "idx", "dest", "src", "config", "cfg", "ctrl", "req", "cmd", "hi", "lo", "len", "param",
         "params", "diag", "resp", "buf", "calc", "init", "ack", "addr", "accum", "auth", "cnt", "tmp", "val", "num",
         "prev", "cur", "seq", "sel", "err", "stat", "tp", "rx", "tx", "regs", "reg", "mgr", "info", "desc", "std",
         "hdr", "xfer", "ext", "misc", "bkp", "pwr", "eng", "veh", "spd", "temp", "prot", "fuel_temp", "cbd", "lsg",
         "asg", "anc", "hsg", "vsg", "rsg", "pto"}
for fw, d in (("CM550", "firmware/CM550_J90350.00_analysis/output"), ("CM848", "firmware/CM848_S90140.06_analysis/output")):
    types = collections.Counter()
    for r in csv.reader(l for l in open(os.path.join(repo, d, "structure_definitions.csv"), newline="") if not l.startswith("#")):
        if r and r[0] and r[0] != "struct_name":
            types[r[0]] += 1
    enums = collections.Counter()
    for r in csv.reader(l for l in open(os.path.join(repo, d, "enums.csv"), newline="") if not l.startswith("#")):
        if r and r[0] and r[0] != "enum_name":
            enums[r[0]] += 1
    print("==", fw)
    for kind, c in (("struct", types), ("enum", enums)):
        for name, n in sorted(c.items()):
            words = set(w.lower() for w in re.split(r"_+", name.lower().removesuffix("_t")))
            hit = sorted(words & WATCH)
            if hit:
                print(f"  {kind:6s} {name:45s} rows {n:3d}  {hit}")

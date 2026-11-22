"""Round 15: compare each worklist row's width with its e2m record's size (the audit's size / row_width columns).
usage: width_check_r15.py <audit.csv> <worklist.py>"""
import csv
import runpy
import sys

audit, worklist = sys.argv[1:3]
addrs = {a.lower() for a, _, _ in runpy.run_path(worklist)["GLOBALS"]}
for r in csv.DictReader(open(audit)):
    a = "0x%08x" % int(r["address"], 16)
    if a in addrs and r["status"] == "named":
        flag = "" if str(r["size"]) == str(r["row_width"]) else "  <-- WIDTH"
        print(a, r["row_name"][:44], "e2m", r["size"], "row", r["row_width"], r["record"][:36], flag)

"""Round 93 J1 investigator: make the quoted e2m descriptions exact (v64t6_s.e2m cuts some of them), then re-validate.
usage: fix_draft2.py <draft_output.json>"""
import json
import sys

path = sys.argv[1]
text = open(path).read()
swaps = [
    ("'PRIORITY OF CLIENT WHICH IS CURRENTLY OVERRIDING ENGINE BRAKE SWITCH LEVEL'",
     "'PRIORITY OF CLIENT WHICH IS CURRENTLY OVERRIDING ENGINE BRAKE SWI' (cut; CM848's e2m: 'Engine Brake switch level')"),
    ("'IVS PARAMETER NOT PROPERLY CONFIGURED. NOT LOGGED AS A FAULT'",
     "'IVS PARAMETER NOT PROPERLY CONFIGURED. NOT LOGGED AS A FAUL' (cut)"),
    ("'PGN TIMEOUT ERROR FLAG FOR APS/IVS/REMOTE THROTTLE. NOT LOGGED'",
     "'PGN TIMEOUT ERROR FLAG FOR APS/IVS/REMOTE THROTTLE. NOT LOG' (cut)"),
    ("'COVERS ALL GLOBAL DEFAULT SWITCH BITS'", "'COVERTS ALL GLOBAL DEFAULT SWITCH BITS' (sic)"),
    ("'COVERS ALL INVERSION SWITCH BITS (TRUE=INVERT)'", "'COVERTS ALL INVERSION SWITCH BITS (TRUE=INVERT; FALSE=NO IN' (sic, cut)"),
    ("and their helper functions are instruction-for-instruction the same.", "and their helper functions are step for step the same."),
]
for old, new in swaps:
    n = text.count(old)
    print(n, "x", old[:60])
    text = text.replace(old, new)
open(path, "w").write(text)
d = json.load(open(path))
assert len(d["functions"]) == 22 and not d["skipped"] and len(d["globals"]) == 26
print("ok")

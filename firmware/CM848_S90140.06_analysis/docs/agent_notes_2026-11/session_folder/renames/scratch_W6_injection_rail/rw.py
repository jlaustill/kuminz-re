import json

RESULT = "/home/linux/.claude/jobs/d55ae3c6/tmp/renames/result_W6_injection_rail.jsonl"


def _w(o):
    with open(RESULT, "a") as f:
        f.write(json.dumps(o, ensure_ascii=False) + "\n")


def fn(address, old, verdict, new=None, plate=None, evidence=""):
    o = {"kind": "function", "address": address, "old": old, "verdict": verdict}
    if new:
        o["new"] = new
    if plate:
        o["plate_comment"] = plate
    o["evidence"] = evidence
    _w(o)


def gl(address, old, verdict, new=None, evidence="", comment=None):
    o = {"kind": "global", "address": address, "old": old, "verdict": verdict}
    if new:
        o["new"] = new
    if comment:
        o["comment"] = comment
    o["evidence"] = evidence
    _w(o)


def ng(address, new, typ, evidence):
    _w({"kind": "new_global", "address": address, "new": new, "type": typ, "evidence": evidence})


def sf(struct, old, new, evidence):
    _w({"kind": "struct_field", "struct": struct, "old": old, "new": new, "evidence": evidence})


def note(text):
    _w({"kind": "note", "text": text})

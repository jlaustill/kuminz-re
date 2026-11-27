"""Sanity check draft_output.json against the StructuredOutput schema's required fields and enums, and print it as
one compact JSON line per top-level array item for pasting (read-only helper, round 93 batch D1 investigator).
usage: schema_check.py [dump]"""
import json
import os
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
d = json.load(open(os.path.join(HERE, "draft_output.json")))
assert sorted(d.keys()) == ["batch", "enum_members", "functions", "globals", "notes", "skipped", "summary"]
for f in d["functions"]:
    for k in ("address", "current_name", "proposed_name", "role", "discriminator", "relation", "plate_comment",
              "evidence", "confidence"):
        assert f[k], (f["address"], k)
    assert f["relation"] in ("twin", "counterpart", "standalone")
    assert f["confidence"] in ("high", "medium", "low")
    if f["relation"] == "standalone":
        assert f["cm848_address"] == "" and f["cm848_current_name"] == "", f["address"]
    else:
        assert f["cm848_address"] and f["cm848_current_name"], f["address"]
for g in d["globals"]:
    for k in ("firmware", "address", "proposed_name", "proposed_type", "comment", "evidence", "confidence"):
        assert g[k], (g["address"], k)
    assert "current_name" in g
    assert g["firmware"] in ("CM550", "CM848")
    assert g["confidence"] in ("high", "medium", "low")
for m in d["enum_members"]:
    assert m["firmware"] in ("CM550", "CM848", "both") and isinstance(m["value"], int)
    for k in ("enum_name", "proposed_member", "comment", "evidence", "confidence"):
        assert m[k], (m, k)
    assert "current_member" in m
for s in d["skipped"]:
    assert s["address"] and s["current_name"] and s["reason"]
print("schema sanity ok; functions", len(d["functions"]), "skipped", len(d["skipped"]), "globals",
      len(d["globals"]), "enum members", len(d["enum_members"]), "bytes", len(json.dumps(d)))
if len(sys.argv) > 1 and sys.argv[1] == "dump":
    part = sys.argv[2]
    if part in ("functions", "globals", "enum_members", "skipped"):
        lo = int(sys.argv[3]) if len(sys.argv) > 3 else 0
        hi = int(sys.argv[4]) if len(sys.argv) > 4 else len(d[part])
        print(json.dumps(d[part][lo:hi], ensure_ascii=True))
    else:
        print(json.dumps(d[part], ensure_ascii=True))

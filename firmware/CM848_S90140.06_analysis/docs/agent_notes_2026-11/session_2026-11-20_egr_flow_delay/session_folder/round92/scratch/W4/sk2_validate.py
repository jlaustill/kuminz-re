"""Skeptic pass 2 (read-only): validate the saved verdict JSON (one entry per word and per bit, amendments present)
and print it back as compact JSON for the final answer.
usage: sk2_validate.py <verdicts json> [--print]"""
import collections
import json
import sys

j = json.load(open(sys.argv[1]))
v = j["verdicts"]
print("entries:", len(v), dict(collections.Counter(x["verdict"] for x in v)))
els = [x["element"] for x in v]
assert len(els) == len(set(els)), [e for e, c in collections.Counter(els).items() if c > 1]
for w in (25, 26, 27, 28, 32, 33):
    assert "word %d" % w in els
    missing = [b for b in range(16) if "word %d bit %d" % (w, b) not in els]
    print("word", w, "missing bits:", missing)
for x in v:
    assert set(x) <= {"element", "verdict", "reason", "amendment"}, x
    if x["verdict"] == "AMENDED":
        assert x.get("amendment"), x["element"]
        print("AMENDED", x["element"], "|", x["amendment"][:110])
    else:
        assert "amendment" not in x, x["element"]
print("max reason len", max(len(x["reason"]) for x in v), "overall len", len(j["overall"]))
if "--print" in sys.argv:
    for x in v:
        print(json.dumps(x, ensure_ascii=True))
    print("OVERALL:", json.dumps(j["overall"], ensure_ascii=True))

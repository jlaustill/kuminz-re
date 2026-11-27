"""J2 investigator run 2, the final builder: result.json (full; copied to result_full.json) ->
result_compact.json / .min.json (the StructuredOutput payload) and result_fallback.min.json (the same with the nine
functions outside the batch list reduced to a table in the notes, for the case that the payload is too large).
Short texts: compact_functions.py (discriminator, plate comment), compact_evidence.py (role, evidence digest),
compact_comments.py (global comments), summary_notes_compact.py. Global evidence is cut at a clause boundary and ends
with ' ...' (complete in result_full.json); the 11 new-enum members stay in the full file only."""
import json
import os
import re
import sys

here = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, here)
from compact_comments import COMMENTS  # noqa: E402
from compact_evidence import DIGEST, WIDE_GLOBAL_EVIDENCE  # noqa: E402
from compact_functions import TEXTS  # noqa: E402
import summary_notes_compact as sn  # noqa: E402

full = json.load(open(os.path.join(here, "result.json")))
json.dump(full, open(os.path.join(here, "result_full.json"), "w"), indent=1)
LISTED = ["0x1fdc0", "0x1ff38", "0x212b2", "0x2142c", "0x216c6", "0x21778", "0x21872", "0x21920", "0x21f4e", "0x21fac",
          "0x22070", "0x231da", "0x23244", "0x23216", "0x21642", "0x238ac", "0x238ec"]


def cut(text, cap, marker=" ..."):
    if len(text) <= cap:
        return text
    head = text[:cap]
    best = max(head.rfind(". "), head.rfind("; "), head.rfind(" | "))
    if best < cap * 0.5:
        best = head.rfind(" ")
    return head[:best].rstrip(" ;|.,") + marker


def estimate(text):
    toks = re.findall(r"0x[0-9a-fA-F]+|[A-Za-z]+|\d+|[^\sA-Za-z\d]", text)
    return sum(1 + (len(t) - 1) // 2 if t.startswith("0x") else max(1, (len(t) + 5) // 6) if t.isalpha()
               else max(1, (len(t) + 2) // 3) if t.isdigit() else 1 for t in toks)


functions = []
for f in full["functions"]:
    a = f["address"]
    role, evidence = DIGEST[a]
    _, discriminator, plate = TEXTS[a]
    g = dict(address=a, current_name=f["current_name"], proposed_name=f["proposed_name"], role=role,
             discriminator=discriminator, relation=f["relation"])
    if f.get("cm848_address"):
        g["cm848_address"] = f["cm848_address"]
        g["cm848_current_name"] = f["cm848_current_name"]
    g["plate_comment"] = plate
    g["evidence"] = evidence
    g["confidence"] = f["confidence"]
    functions.append(g)
globals_ = []
for g in full["globals"]:
    g = dict(g)
    g["comment"] = COMMENTS[(g["firmware"], g["address"])]
    g["evidence"] = cut(g["evidence"], 200 if g["address"] in WIDE_GLOBAL_EVIDENCE else 55)
    globals_.append(g)
enum_members = []
for e in full["enum_members"]:
    if not e["current_member"]:
        continue
    e = dict(e)
    e["comment"] = re.sub(r" \(was [^)]*\)$", "", e["comment"])
    e["evidence"] = cut(e["evidence"], 80)
    enum_members.append(e)

out = dict(batch=full["batch"], summary=sn.summary_compact, functions=functions, skipped=full["skipped"],
           globals=globals_, enum_members=enum_members, notes=sn.notes_compact)
for f in out["functions"]:
    for k in ("role", "discriminator", "plate_comment", "evidence"):
        assert f[k] and not (k != "evidence" and f[k].endswith("...")), (f["address"], k)
for g in out["globals"]:
    assert not g["comment"].endswith("...")
json.dump(out, open(os.path.join(here, "result_compact.json"), "w"), indent=1)
compact = json.dumps(out, separators=(",", ":"))
open(os.path.join(here, "result_compact.min.json"), "w").write(compact)
print("compact:", len(compact), "bytes; crude token estimate", estimate(compact))
for k in ("functions", "globals", "enum_members", "summary", "notes"):
    print("  ", k, len(json.dumps(out[k], separators=(",", ":"))))

# the fallback: the functions outside the batch list as one table in the notes
extra = [f for f in functions if f["address"] not in LISTED]
table = "; ".join(f"{f['address']} {f['current_name']} -> {f['proposed_name']} ({f['relation']}"
                  + (f" of CM848 {f['cm848_address']}" if f.get("cm848_address") else "") + ")" for f in extra)
fallback = dict(out)
fallback["functions"] = [f for f in functions if f["address"] in LISTED]
fallback["notes"] = sn.notes_compact + " 12. OUT-OF-LIST FUNCTION PROPOSALS (full entries in result_compact.json / " \
    "result_full.json): " + table + "."
fb = json.dumps(fallback, separators=(",", ":"))
open(os.path.join(here, "result_fallback.min.json"), "w").write(fb)
json.dump(fallback, open(os.path.join(here, "result_fallback.json"), "w"), indent=1)
print("fallback:", len(fb), "bytes; crude token estimate", estimate(fb))

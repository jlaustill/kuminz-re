"""J2 investigator run 2: result.json (full; copied to result_full.json) -> result_compact.json, the answer that fits
one StructuredOutput call. Hand-written short texts come from compact_functions.py / compact_comments.py /
summary_notes_compact.py; evidence is cut at a clause boundary and ends with ' ...' (complete in result_full.json);
the 11 new-enum members stay in the full file only."""
import json
import os
import re
import sys

here = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, here)
from compact_comments import COMMENTS  # noqa: E402
from compact_functions import TEXTS  # noqa: E402
import summary_notes_compact as sn  # noqa: E402

full = json.load(open(os.path.join(here, "result.json")))
json.dump(full, open(os.path.join(here, "result_full.json"), "w"), indent=1)
LISTED = {"0x1fdc0", "0x1ff38", "0x212b2", "0x2142c", "0x216c6", "0x21778", "0x21872", "0x21920", "0x21f4e", "0x21fac",
          "0x22070", "0x231da", "0x23244", "0x23216", "0x21642", "0x238ac", "0x238ec"}


def cut(text, cap, marker=" ..."):
    if len(text) <= cap:
        return text
    head = text[:cap]
    best = max(head.rfind(". "), head.rfind("; "), head.rfind(" | "))
    if best < cap * 0.5:
        best = head.rfind(" ")
    return head[:best].rstrip(" ;|.,") + marker


out = dict(batch=full["batch"], summary=sn.summary_compact, functions=[], skipped=full["skipped"], globals=[],
           enum_members=[], notes=sn.notes_compact)
for f in full["functions"]:
    a = f["address"]
    role, discriminator, plate = TEXTS[a]
    g = dict(address=a, current_name=f["current_name"], proposed_name=f["proposed_name"], role=role,
             discriminator=discriminator, relation=f["relation"])
    if f.get("cm848_address"):
        g["cm848_address"] = f["cm848_address"]
        g["cm848_current_name"] = f["cm848_current_name"]
    g["plate_comment"] = plate
    g["evidence"] = cut(f["evidence"], 150 if a in LISTED else 100)
    g["confidence"] = f["confidence"]
    out["functions"].append(g)
for g in full["globals"]:
    g = dict(g)
    g["comment"] = COMMENTS[(g["firmware"], g["address"])]
    g["evidence"] = cut(g["evidence"], 55)
    out["globals"].append(g)
for e in full["enum_members"]:
    if not e["current_member"]:
        continue
    e = dict(e)
    e["comment"] = re.sub(r" \(was [^)]*\)$", "", e["comment"])
    e["evidence"] = cut(e["evidence"], 80)
    out["enum_members"].append(e)
path = os.path.join(here, "result_compact.json")
json.dump(out, open(path, "w"), indent=1)
compact = json.dumps(out, separators=(",", ":"))
open(os.path.join(here, "result_compact.min.json"), "w").write(compact)
toks = re.findall(r"0x[0-9a-fA-F]+|[A-Za-z]+|\d+|[^\sA-Za-z\d]", compact)
est = sum(1 + (len(t) - 1) // 2 if t.startswith("0x") else max(1, (len(t) + 5) // 6) if t.isalpha()
          else max(1, (len(t) + 2) // 3) if t.isdigit() else 1 for t in toks)
print(path, len(compact), "bytes compact; crude token estimate", est)
for k in ("functions", "globals", "enum_members", "summary", "notes"):
    print(" ", k, len(json.dumps(out[k], separators=(",", ":"))))

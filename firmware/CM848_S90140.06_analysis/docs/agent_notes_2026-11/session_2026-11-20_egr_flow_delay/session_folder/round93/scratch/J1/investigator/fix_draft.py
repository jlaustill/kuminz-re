"""Round 93 J1 investigator: last fixes to draft_output.json (advisor review), then re-validate.
usage: fix_draft.py <draft_output.json>"""
import json
import sys

path = sys.argv[1]
d = json.load(open(path))

for g in d["globals"]:
    if g["address"] == "0x00808158":
        g["comment"] = (
            "e2m 12FE +0 MXMOPZ 'PRIORITY GIVEN WHICH MUXED PARAMETERS WILL USE FOR THE PRIORITY' (0-255) = CM848's "
            "j1939_input_source_priority (0x5c340, Mux_Module_Priority): the client priority the J1939 input layer works at. "
            "Each processor skips its input while the input's current client priority is above this word. The switch "
            "processors (low idle switch, idle switch pair, the descriptor table switches, the output bit copy) then store its "
            "low byte (0x808159) as the switch's priority and write the switch's override value only while that priority is 0; "
            "the pedal position and wet tank pressure processors store the word as the A/D channel's priority; the retarder, "
            "fan and remote accelerator processors only compare. Not a source address. 0 in the RAM dump."
        )

extra = (
    " | FALLBACK NAMES IN COMMENTS: the plate comments and global comments use the proposed names; if a fallback is "
    "chosen the same swap is needed in them - mc68k_updateIdleSwitchesFromLocalInputs (in the plate comments of 0x20c98 "
    "and in the comments of 0x800aac / 0x800aae / 0x800aaf / 0x80bced / 0x80d72c) and switch_input_source_priority[7] / "
    "[switch] / [output number] (in the plate comments of 0x204b0, 0x206a8, 0x20890). | VERB PHRASES: the three "
    "any...Active names are CM848's reviewed names without the prefix (the twin rule) and are predicates, not verb "
    "phrases; that is deliberate. | SCOPE: the describer's scratch directory was not opened; everything here is from the "
    "frozen copies, the ROM / RAM images and the e2m files."
)
if "FALLBACK NAMES IN COMMENTS" not in d["notes"]:
    d["notes"] += extra

json.dump(d, open(path, "w"), indent=2, ensure_ascii=False)
d = json.load(open(path))
assert len(d["functions"]) == 22 and not d["skipped"]
assert len({f["address"] for f in d["functions"]}) == 22
assert len({f["proposed_name"] for f in d["functions"]}) == 22
assert len({g["proposed_name"] for g in d["globals"]}) == len(d["globals"])
for f in d["functions"]:
    for k in ("address", "current_name", "proposed_name", "role", "discriminator", "relation", "plate_comment", "evidence", "confidence"):
        assert f[k] or k in (), (f["address"], k)
    assert f["relation"] in ("twin", "counterpart", "standalone")
    assert (f["relation"] == "standalone") == (f["cm848_address"] == "")
for g in d["globals"]:
    for k in ("firmware", "address", "proposed_name", "proposed_type", "comment", "evidence", "confidence"):
        assert g[k], (g["address"], k)
print("ok", len(d["functions"]), "functions,", len(d["globals"]), "globals, notes", len(d["notes"]), "chars")

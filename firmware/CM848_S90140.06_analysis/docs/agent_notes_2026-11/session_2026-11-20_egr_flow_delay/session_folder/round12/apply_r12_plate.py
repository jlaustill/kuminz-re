"""Round 12 closing: cm848_calculateFuelMeteringCommand's plate said its engine_sync_* / cam_sync_* /
injection_timing_* names were older guesses still to re-domain; stage B re-domained them (none is left in the body).
function_renames.csv is split(",", 3): the plate takes unquoted commas. usage: apply_r12_plate.py <repo> [--undo]"""
import os
import sys

repo = os.path.abspath(sys.argv[1])
undo = "--undo" in sys.argv
p = os.path.join(repo, "firmware", "CM848_S90140.06_analysis", "output", "function_renames.csv")
OLD = "engine_sync_* / cam_sync_* / injection_timing_* names are older guesses still to re-domain"
NEW = ("its engine_sync_* / cam_sync_* guesses were re-domained in round 12 from the e2m HPCR_* records (the CP3 M-PROP "
       "fuel metering vocabulary)")
a, b = (NEW, OLD) if undo else (OLD, NEW)
lines = open(p).read().split("\n")
hits = [i for i, l in enumerate(lines) if a in l and ",cm848_calculateFuelMeteringCommand," in l]
assert len(hits) == 1, hits
lines[hits[0]] = lines[hits[0]].replace(a, b)
open(p, "w").write("\n".join(lines))
print("plate", "restored" if undo else "updated")

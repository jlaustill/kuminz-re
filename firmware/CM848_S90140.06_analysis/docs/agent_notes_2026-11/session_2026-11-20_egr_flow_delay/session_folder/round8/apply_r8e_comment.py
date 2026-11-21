"""Round 8 stage E: the converter_clutch_transition_state comment (bits 0 and 2 proved by
cm848_monitorConverterClutchEngagement). usage: apply_r8e_comment.py <repo> [--dry-run]"""
import csv
import io
import os
import sys

repo = os.path.abspath(sys.argv[1])
p = os.path.join(repo, "firmware", "CM848_S90140.06_analysis", "output", "global_variables.csv")
rows = open(p).read().split("\n")
new_comment = ("Converter clutch transition flags byte (23 accesses - all lbz / stb). Bit 0 = engagement pending: set at "
               "the rising edge of the converter clutch solenoid request, cleared when transmission_speed_ratio shows "
               "lock for the gear, in 1st, at the request's falling edge or under the lockup inhibit. Bit 2 = engagement "
               "timed out: set with the lockup inhibit (condition_eval bit 6) when converter_clutch_engagement_timer "
               "runs out, cleared when the inhibit clears (both proved in cm848_monitorConverterClutchEngagement, round 8). "
               "Bit 1 = retarder forced gear 2 is still the wave-11 agent's medium-confidence reading, and the byte is "
               "updated with | / & masks, so no bitfield (was protection_condition_state, a word)")
done = 0
for i, line in enumerate(rows):
    if line.startswith("0x0040b0fe,converter_clutch_transition_state,byte,"):
        row = next(csv.reader([line]))
        row[3] = new_comment
        s = io.StringIO()
        csv.writer(s, lineterminator="").writerow(row)
        rows[i] = s.getvalue()
        done += 1
assert done == 1
print("comment updated")
if "--dry-run" not in sys.argv:
    open(p, "w").write("\n".join(rows))

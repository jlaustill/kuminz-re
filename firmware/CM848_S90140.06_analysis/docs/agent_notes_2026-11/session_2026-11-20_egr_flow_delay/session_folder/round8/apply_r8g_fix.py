"""Round 8 stage G post-fix, after apply_hand_worklist.py: the renamed rows / plate get no 'earlier note' (it would
repeat the stage F text with the old names) and a '(was ...)' with every earlier name; the 0x408388 comment states its
polarity. String edits only: global_variables.csv / function_renames.csv take commas unquoted.
usage: apply_r8g_fix.py <repo>"""
import os
import re
import sys

repo = os.path.abspath(sys.argv[1])
out = os.path.join(repo, "firmware", "CM848_S90140.06_analysis", "output")
HISTORY = {
    "0x0040b0fe": "exhaust_brake_lockup_flags in stage F, before that converter_clutch_transition_state",
    "0x0040b14c": "exhaust_brake_lockup_inhibit_timer in stage F, converter_clutch_engagement_timer in stage E, before "
                  "that protection_monitor_countdown",
    "0x0040838a": "exhaust_brake_lockup_inhibit_timeout in stage F, converter_clutch_engagement_time_limit in stage E, "
                  "before that protection_monitor_countdown_cal",
    "0x003fb1cc": "exhaust_brake_lockup_inhibit_previous in stage F, converter_clutch_engagement_pending_previous in "
                  "stage E, before that protection_condition_state_bit0_flag",
}
POLARITY = ("e2m 8C18 +94 RE_Closed_Throttle_Lu_Enable ('Flag to disable TCC lockup with brake transition'): 1 here. "
            "With 0, cm848_determineCurrentGearAndLockupInhibit unlocks the converter when switch 11 (the brake) or switch "
            "2 comes on: it clears the converter clutch request, reloads converter_clutch_apply_delay_countdown with "
            "converter_clutch_brake_release_relock_delay_time and sets condition_flags_1 bit 3 (plus the lockup off "
            "timer, condition_flags_1 bit 5 and condition_eval bit 6 if the clutch was on). With 1 that block is skipped, "
            "so closed-throttle lockup is not dropped by the brake")
p = os.path.join(out, "global_variables.csv")
lines = open(p).read().split("\n")
done = 0
for i, l in enumerate(lines):
    a = l[:10].lower()
    if a in HISTORY:
        addr, name, typ, comment = l.split(",", 3)
        comment = re.sub(r" \| earlier note: .*$", "", comment)
        m = re.search(r" \(was ([A-Za-z0-9_]+)\)$", comment)
        assert m, (a, comment[-80:])
        comment = comment[:m.start()] + f" (was {HISTORY[a]})"
        assert '"' not in comment
        lines[i] = ",".join([addr, name, typ, comment])
        done += 1
    elif a == "0x00408388":
        addr, name, typ, comment = l.split(",", 3)
        assert name == "converter_clutch_closed_throttle_lockup_enable", name
        m = re.search(r" \(was [A-Za-z0-9_]+\)( \| earlier note: .*)?$", comment)
        assert m, comment[-80:]
        lines[i] = ",".join([addr, name, typ, POLARITY + comment[m.start():]])
        done += 1
assert done == 5, done
open(p, "w").write("\n".join(lines))
p = os.path.join(out, "function_renames.csv")
lines = open(p).read().split("\n")
k = 0
for i, l in enumerate(lines):
    if l[:10].lower() == "0x00034f4c":
        a, name, plate = l.split(",", 2)
        plate = re.sub(r" \| earlier note: .*$", "", plate)
        plate = re.sub(r" \(was cm848_updateExhaustBrakeLockupInhibit\)$", "", plate)
        lines[i] = f"{a},{name},{plate} (was cm848_updateExhaustBrakeLockupInhibit in stage F, "
        lines[i] += "cm848_monitorConverterClutchEngagement in stage E, before that cm848_processProtectionRateLimitFlags)"
        k += 1
assert k == 1
open(p, "w").write("\n".join(lines))
print("fixed", done, "rows and 1 plate")

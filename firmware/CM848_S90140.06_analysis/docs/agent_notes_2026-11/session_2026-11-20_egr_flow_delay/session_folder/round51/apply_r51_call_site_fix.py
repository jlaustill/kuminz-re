"""Round 51 closing fix: cm848_flagTripInformationPowerDownDataLoss has ONE call site (0x54de0, find_branch_callers.py
over the ROM and the live flash2), inside cm848_restartApplicationWithoutReset's code; cm848_applicationMain ends at
0x54d2c without a return and falls through into it, so both decompilations show the call. The 0x30d4 the decompiler
showed as an argument is 12500 from `li r3,12500 / mtdec r3` (the decrementer reload) just before the bl.
Stage A's plate said cm848_applicationMain called it twice and stage B's text said two calls: fixed here.
Idempotent.  usage: apply_r51_call_site_fix.py <repo>"""
import os
import sys

out = os.path.join(os.path.abspath(sys.argv[1]), "firmware/CM848_S90140.06_analysis/output")
R = "PR #53 round 51"
done = 0
fp = os.path.join(out, "function_renames.csv")
t = open(fp).read()
old = ("Power-down step (cm848_applicationMain and cm848_restartApplicationWithoutReset each call it after the RAM "
       "calibration refresh)")
new = ("Power-down step called once (bl @ 0x54de0 after the RAM calibration refresh) in cm848_restartApplicationWithoutReset;"
       " cm848_applicationMain falls through into that code from 0x54d2c so both decompilations show the call")
if old in t:
    assert t.count(old) == 1 and "," not in new
    open(fp, "w").write(t.replace(old, new))
    done += 1
fd = os.path.join(out, "function_definitions.csv")
t = open(fd).read()
old = ("Takes no parameters: its power-down calls in cm848_applicationMain and cm848_restartApplicationWithoutReset pass "
       "the r3 left over from the preceding code (0x30d4)")
new = ("Takes no parameters: at its one call (0x54de0) r3 still holds 12500 = 0x30d4 from li r3 / mtdec r3 (the "
       "decrementer reload) which the decompiler showed as an argument")
if old in t:
    assert t.count(old) == 1 and "," not in new
    open(fd, "w").write(t.replace(old, new))
    done += 1
print(f"{done} fixes")

"""J2 investigator run 2: corrections to build_result_part3.py (when the remove functions are called)."""
import os

p = os.path.join(os.path.dirname(os.path.abspath(__file__)), "build_result_part3.py")
t = open(p).read()
REPLACEMENTS = [
    ("processEngineTsc1Request and the J1922 command handlers call it when they accept a request from that sender. Twin of CM848 0x53fa8",
     "processEngineTsc1Request calls it when that sender sends control mode 0 (tst.w d3 at 0x2f18c), the J1922 command handlers when they accept a mode 1 / 2 / 3 command. Twin of CM848 0x53fa8"),
    ("cm550_retarderControlModeHandler calls it when it accepts a request from that sender. The counterpart of cm848_removeRetarderTsc1IgnoredRequestEntry",
     "cm550_retarderControlModeHandler calls it when that sender sends control mode 0 (tst.w d4 at 0x2f870). The counterpart of cm848_removeRetarderTsc1IgnoredRequestEntry"),
]
done = 0
for old, new in REPLACEMENTS:
    if new in t:
        continue
    assert t.count(old) == 1, old[:60]
    t = t.replace(old, new)
    done += 1
open(p, "w").write(t)
print("patched", done)

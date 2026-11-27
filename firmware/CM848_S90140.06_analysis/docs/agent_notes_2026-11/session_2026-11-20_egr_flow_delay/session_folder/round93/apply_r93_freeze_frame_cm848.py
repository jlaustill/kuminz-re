"""Round 93 (CM848): the freeze frame functions take the names of what they do, parallel to CM550's (the same roles,
found while typing CM550's freeze frame records; counterparts, not twins: 8 + 8 records of a different layout).
- 0x1df64 hpcr_setFaultActiveStatus -> cm848_captureFaultFreezeFrame: it sets no fault status; it fills the shadow
  record (entry + 8, definition flag 0x10) and the primary record (when the fault code differs), then the OBD part.
- 0x1cea4 cm848_registerFaultInActiveList -> cm848_assignFaultFreezeFrameEntry: it has no active list; it picks the
  entry (the fault's own, a free one, or an evicted one) and captures.
- 0x1cdc0 cm848_faultCodeLookup -> cm848_findOldestFreezeFrameEntryByFaultStatus.
- 0x1ce28 cm848_findFaultByTypeAndSeverity -> cm848_findOldestFreezeFrameEntryByFaultStatusWithoutFlags: its second
  argument is a mask of the entry's status_flags, not a severity.
The fault_entry_t header comment in structure_definitions.csv named two of them by names older still; fixed.
Idempotent. usage: apply_r93_freeze_frame_cm848.py <repo> <map.csv>"""
import os
import re
import sys

repo, map_out = os.path.abspath(sys.argv[1]), sys.argv[2]
R = "PR #53 round 93"
O = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")
FUNCTIONS = {
    0x0001df64: ("cm848_captureFaultFreezeFrame",
                 "Fills a fault freeze frame record (fault_freeze_frame_entries_cal, 48-byte fault_entry_t) for (entry, fault code): the shadow "
                 "record (entry + 8) when the fault's definition flag 0x10 is set, and the primary record when its fault code differs (the first "
                 "capture). With the OBD fault handler enabled (algorithm_enable_flags_12_cal.obd_fault_handler_enable) and the fault's entry "
                 "flag 1: a newly written primary sets its status_flags bit 0 and is queued (cm848_queueFaultFreezeFrameEntry) unless entry flag "
                 "0x20 is set - then cm848_recordFaultDetection runs instead. It sets no fault status. Called by "
                 "cm848_assignFaultFreezeFrameEntry. The counterpart of CM550's cm550_captureFaultFreezeFrame (0x2fe38)"),
    0x0001cea4: ("cm848_assignFaultFreezeFrameEntry",
                 "Gives a fault a freeze frame entry and captures it (cm848_captureFaultFreezeFrame): the entry that already holds the fault "
                 "code; else the first free entry (0xAA). Else, without the OBD fault handler: the entry of the oldest fault with status 2 (whose "
                 "status becomes 0), else of the oldest with status 3 (becomes 1), by cm848_findOldestFreezeFrameEntryByFaultStatus. With the "
                 "OBD fault handler: the oldest status 2 entry with neither status_flags bit 0 nor 1 (status becomes 0); else the oldest status 3 "
                 "entry with neither bit, the oldest status 2 entry without bit 1, the oldest status 3 entry without bit 1 (status becomes 1); "
                 "else cm848_markFaultForReplacement and the search without the handler. 8 entries. The counterpart of CM550's "
                 "cm550_assignFaultFreezeFrameEntry (0x14720)"),
    0x0001cdc0: ("cm848_findOldestFreezeFrameEntryByFaultStatus",
                 "Returns the index (0-7) of the primary freeze frame entry whose fault has the given fault_state_records_cal status and the "
                 "smallest timestamp, or 0xffff when no entry's fault has that status. The counterpart of CM550's "
                 "cm550_findOldestFreezeFrameEntryByFaultStatus (0x146b4)"),
    0x0001ce28: ("cm848_findOldestFreezeFrameEntryByFaultStatusWithoutFlags",
                 "cm848_findOldestFreezeFrameEntryByFaultStatus restricted to the entries whose status_flags have none of the bits of the mask "
                 "(the second argument): the index (0-7) of the oldest such entry whose fault has the given status, or 0xffff. Used by "
                 "cm848_assignFaultFreezeFrameEntry when the OBD fault handler is enabled (masks 3 and 2)"),
}
STRUCT_COMMENT_FIXES = [
    ("# Code evidence: hpcr_setFaultActiveStatus (0x0001df64) - it also captures the freeze frame",
     "# Code evidence: cm848_captureFaultFreezeFrame (0x0001df64) fills both records"),
    ("# Iteration: addFaultToActiveList (0x0001cea4) uses pbVar3 += 0x30 with limit < 8",
     "# Iteration: cm848_assignFaultFreezeFrameEntry (0x0001cea4) steps 0x30 with limit < 8"),
    ("# findFaultByTypeAndSeverity (0x0001ce28) uses puVar3 = &DAT_003fe674, puVar3 += 0xc (as dword*)",
     "# cm848_findOldestFreezeFrameEntryByFaultStatusWithoutFlags (0x0001ce28) walks the 8 primary records"),
]


def read(p):
    return open(p, newline="").read()


pairs = []
F = os.path.join(O, "function_renames.csv")
t = read(F)
for a, (new, plate) in FUNCTIONS.items():
    key = f"0x{a:08x}"
    m = re.search(rf"^{key},([^,\r\n]*)(?:,([^\r\n]*))?$", t, re.M)
    assert m, key
    old = m.group(1)
    if old == new:
        continue
    earlier = f" | earlier note: {m.group(2)}" if m.group(2) else ""
    t = t[:m.start()] + f"{key},{new},{plate} (was {old}; {R}){earlier}" + t[m.end():]
    for k in ("function_definitions.csv", "local_variables.csv"):
        p = os.path.join(O, k)
        c = read(p)
        c2 = re.sub(rf"^({key},){re.escape(old)},", lambda x: x.group(1) + new + ",", c, flags=re.M | re.I)
        if c2 != c:
            open(p, "w", newline="").write(c2)
    pairs.append((key, new, old))
open(F, "w", newline="").write(t)
S = os.path.join(O, "structure_definitions.csv")
s = read(S)
fixed = 0
for old, new in STRUCT_COMMENT_FIXES:
    if old in s:
        assert s.count(old) == 1, old
        s = s.replace(old, new)
        fixed += 1
    else:
        assert new in s, old
open(S, "w", newline="").write(s)
if pairs:
    with open(map_out, "w") as fh:
        fh.write("address,name,old_label,kind,dims\n")
        for key, new, old in pairs:
            fh.write(f"{key},{new},{old},symbol,1\n")
print(f"{len(pairs)} CM848 functions renamed; {fixed} struct header lines fixed")

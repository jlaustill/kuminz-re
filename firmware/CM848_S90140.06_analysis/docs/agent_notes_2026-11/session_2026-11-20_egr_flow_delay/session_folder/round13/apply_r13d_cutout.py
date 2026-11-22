"""Round 13 stage D (comments only): SCI command 0x25 tests 5-10 cut out firing-order slots, not physical cylinders.
The injection dispatch tests bit (cylinder_event_index & 0x3f) of cylinder_cutout_test_mask | cylinder_cutout_mask, and
the fault cutout ORs in 0x55 / 0xaa for one injector group. With the banks at cylinders 1-2-3 / 4-5-6 (e2m 8C74
Cylinder_Bank_Contribution_1 'avg. of physical cyls. 1,2,3'), alternate events form a bank only in firing order
1-5-3-6-2-4, so bit n is firing-order slot n + 1 (DRB 25-05 FUEL_INJ1 anchors slot 1 = cylinder 1). The marker word
of each slot (0x3fcf64 table) is never counted down. Plus three task 046 leads from the review.
usage: apply_r13d_cutout.py <repo>"""
import os
import sys

repo = os.path.abspath(sys.argv[1])
out = os.path.join(repo, "firmware", "CM848_S90140.06_analysis", "output")


def edit(path, old, new):
    text = open(path).read()
    assert text.count(old) == 1, (os.path.basename(path), old[:70], text.count(old))
    open(path, "w").write(text.replace(old, new))


SLOTS = "firing-order slots 1-6 (cylinders 1 / 5 / 3 / 6 / 2 / 4)"
gv = os.path.join(out, "global_variables.csv")
edit(gv, "/ 5-10 injector 1-6 cutout (DRB 25-05 FUEL_INJ1_ENAB / _DISAB) / 0 ends every test",
     f"/ 5-10 cut out {SLOTS}; DRB 25-05 FUEL_INJ1_ENAB / _DISAB is slot 1 / 0 ends every test")
edit(gv, "(an injector: 2 cuts it out - its word in the cutout table",
     "(a firing-order slot: 2 cuts it out - its word in the cutout table")
edit(gv, "Cylinder cutout test mask, bit n = cylinder n + 1 cut out.",
     "Cylinder cutout test mask: bit n = firing-order slot n + 1 cut out (cylinders 1 / 5 / 3 / 6 / 2 / 4 - the "
     "injection dispatch indexes it by the event slot, and the fault cutout's one-injector-group masks 0x55 / 0xaa "
     "only fit firing order; PR #53 round 13; the e2m text gives only bit0=cyl1).")
edit(gv, "sub-ids 5-10 = cylinders 1-6, value 2 cuts the cylinder out for a 1000 count timer that the tool refreshes,",
     "sub-ids 5-10 = slots 1-6, value 2 cuts the slot out (its marker word at 0x3fcf64 + 2 x index becomes 1000; "
     "nothing counts it down),")
fr = os.path.join(out, "function_renames.csv")
edit(fr, "0x26 high pressure safety valve (DRB 25-26) / 5-10 injector 1-6 cutout; 0 ends every test.",
     f"0x26 high pressure safety valve (DRB 25-26) / 5-10 cutout of {SLOTS}; 0 ends every test.")
t46 = os.path.join(repo, "work", "tasks", "046-cm848-egr-flow-estimate.md")
edit(t46, "    - 5-10 cut out injectors 1-6.\n",
     f"    - 5-10 cut out {SLOTS}: the fault cutout's bank masks 0x55 / 0xaa only fit firing order.\n")
edit(t46, "  - **The injector cutout markers** at 0x3fcf64 are a `word[8]` array candidate (the cancel loop reads them with\n"
          "    `lhz`).\n",
     "  - **The injector cutout markers** at 0x3fcf64 are a `word[8]` array candidate (the cancel loop reads them with\n"
     "    `lhz`). The request bytes at 0x3fcf61-62 are the callback's receive buffer (stored at 0x3fcf61 + count).\n"
     "  - **The ASG leftovers:** `governor_tuning_set_blend_weight` (its default is e2m 1387 +8 ASG_Droop_Flag_Trim, a\n"
     "    droop-source select), `governor_speed_lower_limit*`, `governor_speed_error_input` / `_prescaled` and the\n"
     "    unread set 3 (0008 +3C / +3E).\n"
     "  - **`cm848_setLogicalOutputRequest()`** renders with no arguments in `cm848_setEndOfLineTestOutputRequest`,\n"
     "    while its SCI callers show two: check its prototype row.\n")
print("cutout comments, the callback plate, task 046")

"""Round 69 follow-up (the advisor's closing review). Idempotent: every edit skips when its new text is present.
- smart_boot_indicator: no CM848 code builds 0x98765432 (no lis 0x9876 / ori 0x5432 pair in either image), while
  CM550's boot code compares it: cmpi.l #$98765432,(a0) at CM550 0x3c02.
- Round 67's two live comments that said 'the image header at ROM 0x8104' point at the round's names.
usage: fix_r69b.py <repo>"""
import os
import sys

O = os.path.join(os.path.abspath(sys.argv[1]), "firmware/CM848_S90140.06_analysis/output")
R = "PR #53 round 69"


def edit(name, old, new):
    p = os.path.join(O, name)
    s = open(p).read()
    if new in s:
        return
    assert s.count(old) == 1, (name, old[:90], s.count(old))
    open(p, "w").write(s.replace(old, new))


edit("global_variables.csv",
     "(HEX) - 0x98765432 here - no reader found: the calibration image starts its header with it (PR #53 round 69)",
     "(HEX) - 0x98765432 here - no reader found: no CM848 code builds the value (no lis 0x9876 / ori 0x5432 pair in the "
     "ROM or Bank 2 image), while CM550's boot code compares it (cmpi.l #$98765432,(a0) at CM550 0x3c02). The "
     f"calibration image starts its header with it ({R})")
edit("enums.csv",
     "finds a region sum or the block layout unlike the image header at ROM 0x8104 or ECM_Status",
     "finds a region sum unlike checksum_region_table or the block layout unlike block_data_structure (round 69) or "
     "ECM_Status")
edit("global_variables.csv",
     "and checked against the image header by mpc555_verifyDownloadedCalibration",
     "and checked against block_data_structure (round 69) by mpc555_verifyDownloadedCalibration")
print("follow-up applied")

"""Round 72 stage B2 (the closing review's sweep): CM848's enums.csv still carried MEMORY_ACCESS_FLAG ('Ported from CM550
(memory region protection)') - the same codes as MEMORY_REGION_TYPE (round 71) with the J90280.05-era reading; it
rendered nowhere and nothing typed by it. It goes, as CM550's did in stage A2. CM550's writer header said it returns
MEMORY_OP_RESULT - its return is the char of stage B1. Idempotent; keeps line endings.  usage: apply_r72b2.py <repo>"""
import os
import sys

repo = os.path.abspath(sys.argv[1])
R = "PR #53 round 72"


def edit(p, old, new):
    s = open(p, newline="").read()
    eol = "\r\n" if "\r\n" in s else "\n"
    s = s.replace("\r\n", "\n")
    if new in s:
        return
    assert s.count(old) == 1, (os.path.basename(p), old[:90], s.count(old))
    open(p, "w", newline="").write(s.replace(old, new).replace("\n", eol))


edit(os.path.join(repo, "firmware/CM848_S90140.06_analysis/output/enums.csv"),
     "# Memory Access Flags - Ported from CM550 (memory region protection)\n"
     "MEMORY_ACCESS_FLAG,0x00,DIRECT_ACCESS,READ: Allowed | WRITE: Direct access no security check,1\n"
     "MEMORY_ACCESS_FLAG,0x03,SECURITY_REQUIRED,READ: Allowed | WRITE: Requires security check or bypass,1\n"
     "MEMORY_ACCESS_FLAG,0x04,WRITE_DENIED,READ: Allowed | WRITE: Denied - returns error 0x0A,1\n"
     "MEMORY_ACCESS_FLAG,0x05,LOGGING_MODE,READ: Allowed | WRITE: Requires system_logging_state check,1\n"
     "MEMORY_ACCESS_FLAG,0x09,RANGE_INVALID,READ: Denied | WRITE: Error - address not in validation table,1\n"
     "MEMORY_ACCESS_FLAG,0x0A,ACCESS_DENIED,READ: Denied | WRITE: Error - explicitly blocked region,1\n",
     f"# (MEMORY_ACCESS_FLAG - ported from CM550 - removed in {R}: MEMORY_REGION_TYPE holds these codes; it rendered "
     "nowhere)\n")
edit(os.path.join(repo, "firmware/CM550_J90350.00_analysis/output/function_definitions.csv"),
     "# Returns: MEMORY_OP_RESULT enum (0=success, 2=invalid_length, 3=auth_failed, etc.)\n",
     "# Returns: char - the MEMORY_OP_RESULT numbers (0 written / 2 wrong length / 3 key / 7 / 0x0a / 0x0b / 0x1a) or "
     f"the region type passed back (was documented as MEMORY_OP_RESULT; {R})\n")
print("round 72 stage B2 applied")

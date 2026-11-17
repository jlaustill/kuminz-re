import sys

sys.path.insert(0, '/home/linux/.claude/jobs/d55ae3c6/tmp/renames/scratch_W7_injection_rail')
import peek

# width 2 per the table read: fault n -> slot word at 0x5985a + 2n -> obd_dtc_code_table word per slot (0x5b57c)
for n in (10, 11, 347, 348, 196, 197, 395):
    slot = peek.rd(0x5985a + n * 2, 1, 2)[0]
    code = peek.rd(0x5b57c + slot * 2, 1, 2)[0]
    print('fault %d -> slot %d -> P%04X' % (n, slot, code))

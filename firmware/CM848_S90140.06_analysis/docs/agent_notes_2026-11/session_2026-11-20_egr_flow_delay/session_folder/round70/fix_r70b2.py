"""Round 70 follow-up, second pass: cm848_writeBootKernelCanTxMailbox's frame parameter goes back to word *
frame_words. Typed boot_can_transmit_frame_t *, the writer's six-halfword copy started at 'frame[-1].data + 6' (two
bytes before the frame) and read '*(undefined2 *)pbVar1' - worse than the original - while only its two callers lost a
cast each. The writer copies halfwords, so word * is its honest type. Idempotent. usage: fix_r70b2.py <repo>"""
import os
import sys

p = os.path.join(os.path.abspath(sys.argv[1]), "firmware/CM848_S90140.06_analysis/output/function_definitions.csv")
s = open(p).read()
typed = ("0x00004f2c,cm848_writeBootKernelCanTxMailbox,2,frame,boot_can_transmit_frame_t*,The frame (was word * "
         "frame_words: identifier high / low and data bytes 0-7 - 6 halfwords; PR #53 round 70)")
original = ("0x00004f2c,cm848_writeBootKernelCanTxMailbox,2,frame_words,word*,The frame: identifier high / low and data "
            "bytes 0-7 (6 halfwords) - one boot_can_transmit_frame_t; as that type the copy loop read worse (PR #53 "
            "round 70)")
if original not in s:
    assert s.count(typed) == 1
    open(p, "w").write(s.replace(typed, original))
print("second pass applied")

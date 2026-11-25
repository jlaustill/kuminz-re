"""Count D-form loads/stores whose base register is r2 or r13 (small data area use) in both CM848 banks."""
import os
import struct

base = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM848_S90140.06_analysis/originals"
banks = [(0, open(os.path.join(base, "cm848_rom.bin"), "rb").read()),
         (0x500000, open(os.path.join(base, "cm848_flash2_live.bin"), "rb").read())]
OPS = {32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45}
for org, data in banks:
    count = {2: 0, 13: 0}
    samples = {2: [], 13: []}
    for off in range(0, len(data) - 3, 4):
        w = struct.unpack(">I", data[off:off + 4])[0]
        op = w >> 26
        ra = (w >> 16) & 31
        if op in OPS and ra in (2, 13):
            count[ra] += 1
            if len(samples[ra]) < 5:
                samples[ra].append(hex(org + off))
    print(hex(org), count, samples)

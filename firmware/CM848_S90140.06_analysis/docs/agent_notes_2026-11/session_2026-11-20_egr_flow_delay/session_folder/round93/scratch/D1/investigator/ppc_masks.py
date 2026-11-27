"""For every CM848 access to an address (via ppc_xref.scan), print the next instructions decoded for mask tests
(rlwinm / andi. / andis.) - read-only helper, round 93 batch D1 investigator.
usage: ppc_masks.py 0xADDR[-0xADDR] ..."""
import struct
import sys

sys.path.insert(0, "/home/linux/.claude/jobs/374b0424/tmp/w15/r93/scratch/D1/investigator")
import ppc_xref  # noqa: E402

FW = ppc_xref.FW
imgs = {0: open(FW + "cm848_rom.bin", "rb").read(), 0x500000: open(FW + "cm848_flash2_live.bin", "rb").read()}


def rd(pc):
    base = 0x500000 if pc >= 0x500000 else 0
    return struct.unpack_from(">I", imgs[base], pc - base)[0]


def dec(w):
    op = w >> 26
    if op == 21:  # rlwinm
        rs = (w >> 21) & 31
        ra = (w >> 16) & 31
        sh = (w >> 11) & 31
        mb = (w >> 6) & 31
        me = (w >> 1) & 31
        mask = 0
        for b in range(32):
            inrange = (mb <= me and mb <= b <= me) or (mb > me and (b >= mb or b <= me))
            if inrange:
                mask |= 1 << (31 - b)
        src = ((mask >> sh) | (mask << (32 - sh))) & 0xffffffff
        return f"rlwinm r{ra},r{rs},{sh},{mb},{me}{'.' if w & 1 else ''} (source mask 0x{src:x})"
    if op == 28:
        return f"andi. r{(w >> 16) & 31},r{(w >> 21) & 31},0x{w & 0xffff:x}"
    if op == 29:
        return f"andis. r{(w >> 16) & 31},r{(w >> 21) & 31},0x{w & 0xffff:x}"
    return f"op{op} 0x{w:08x}"


ranges = []
for a in sys.argv[1:]:
    if "-" in a:
        lo, hi = a.split("-")
        ranges.append((int(lo, 16), int(hi, 16)))
    else:
        ranges.append((int(a, 16), int(a, 16)))
for pc, name, width, v in ppc_xref.scan(ranges):
    nxt = [dec(rd(pc + 4 * k)) for k in (1, 2, 3)]
    print(f"0x{pc:06x} {name} w{width} -> 0x{v:06x} in {ppc_xref.owner(pc)}: " + " | ".join(nxt))

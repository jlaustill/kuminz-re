"""Emulate CM550 0x333d6 (word) step by step from the disassembly, and CM848 0x1b624, for a few value pairs."""


def s32(x):
    x &= 0xFFFFFFFF
    return x - (1 << 32) if x & 0x80000000 else x


def divs(a, b):
    # m68k divs.l: signed 32-bit quotient, truncates toward zero
    q = abs(a) // abs(b)
    return q if (a < 0) == (b < 0) else -q


def cm550_word(prev, cur):
    d3, d2 = prev & 0xFFFF, cur & 0xFFFF
    if d3 == 0:
        return 1 if d2 != 0 else 0
    d0 = s32(d3 - d2)
    if d0 < 0:  # bmi
        d0 = s32(-d3 - d2)
    else:
        d0 = s32(d3 - d2)
    diff = d0
    q = divs(diff, d3)
    if q < 0:  # blt
        d0 = divs(s32(-diff), d3)
    else:
        d0 = divs(diff, d3)
    d0 = (d0 * 10) & 0xFFFFFFFF
    return 0 if 1 > d0 else 1  # cmp.l d0,d1 (d1=1); bhi -> return 0


def cm848_word(old, new):
    old &= 0xFFFF
    if old == 0:
        return 1 if new != 0 else 0
    r5 = s32(old - new)
    if r5 < 0:
        r5 = s32(new - old)
    if not (old > (r5 & 0xFFFFFFFF)):
        return 1
    r12 = ((r5 & 0xFFFF) * 10) // old
    return 1 if (r12 & 0xFFFF) > 0 else 0


for prev, cur in [(1000, 1000), (1000, 1001), (1000, 1050), (1000, 1100), (1000, 1999), (1000, 2000),
                  (1000, 950), (1000, 900), (1000, 500), (1000, 1), (1000, 0), (0, 0), (0, 5)]:
    print(f"prev {prev:5d} cur {cur:5d}  cm550 {cm550_word(prev, cur)}  cm848 {cm848_word(prev, cur)}")

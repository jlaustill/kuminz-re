"""Emulates CM550 0x333d6 (word) / 0x33460 (byte) and CM848 0x1b624 / 0x1b69c step by step from their disassembly,
to state exactly when each returns 1."""


def s32(v):
    v &= 0xFFFFFFFF
    return v - 0x100000000 if v & 0x80000000 else v


def divs_l(dividend, divisor):
    # 68k divs.l: signed 32-bit quotient, truncated toward zero
    q = abs(dividend) // abs(divisor)
    return q if (dividend >= 0) == (divisor > 0) else -q


def cm550_helper(previous, new):
    d3, d2 = previous, new                      # move.w (0xc,a7),d3 = previous ; move.w (0xe,a7),d2 = new
    if d3 == 0:
        return 1 if d2 != 0 else 0
    d0 = s32(d3 - d2)                           # sub.l ; bmi
    if d0 < 0:
        d0 = s32(-d3 - d2)                      # neg.l d0 (=-previous) ; sub.l new
    d2 = d0
    q = divs_l(d0, d3)
    if q >= 0:                                  # tst.l ; blt
        q = divs_l(d2, d3)
    else:
        q = divs_l(s32(-d2), d3)
    d0 = (q * 10) & 0xFFFFFFFF                  # lsl #2 + add + add = x10
    return 0 if 1 > d0 else 1                   # cmp.l d0,d1 (d1 = 1) ; bhi -> 0


def cm848_helper(previous, new):
    if previous == 0:
        return 1 if new != 0 else 0
    diff = previous - new
    if diff < 0:
        diff = new - previous
    if not previous > diff:                     # cmplw r12,r5 ; bgt
        return 1
    return 1 if (diff * 10) // previous > 0 else 0


cases = [(0, 0), (0, 5), (100, 100), (100, 101), (100, 109), (100, 110), (100, 150), (100, 91), (100, 90),
         (100, 50), (100, 1), (100, 0), (1000, 1100), (1000, 900), (1000, 950)]
print("previous new | CM550 CM848")
for p, n in cases:
    print(f"{p:5d} {n:5d} | {cm550_helper(p, n)}     {cm848_helper(p, n)}")

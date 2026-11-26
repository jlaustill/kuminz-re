# Machine (0x12ca2-0x12d84) vs AFTER render (lines 219-233) for cylinder_balance_trim_index_1.
def s32(x):
    x &= 0xffffffff
    return x - (1 << 32) if x & 0x80000000 else x


def divs(a, b):  # 68k divs.l: truncates toward zero
    q = abs(a) // abs(b)
    return q if (a >= 0) == (b > 0) else -q


def proj(ref_imag, ref_real, fi, fr):  # ext.l + mulu.l (low 32) + add.l + divs.l #10000
    return divs(s32(s32(ref_imag * fi) + s32(ref_real * fr)), 10000)


def argmax(p0, rest):  # cmp.l (a2),d4 / bge: take a new max only when strictly greater
    d4, idx = p0, 0
    for i, v in enumerate(rest, start=1):
        if d4 < v:
            d4, idx = v, i
    return idx


ref1 = dict(c1=(0, 10000), c5=(8660, -5000), c3=(-8660, -5000))  # (imag, real)
fi1, fr1 = 1000, 0
# machine: this call's pass-1 values in 0x8002ac..0x8002c0
p = [0] * 6
p[0] = proj(*ref1['c1'], fi1, fr1)
p[4] = proj(*ref1['c5'], fi1, fr1)
p[2] = proj(*ref1['c3'], fi1, fr1)
p[5], p[1], p[3] = -p[0], -p[4], -p[2]
machine = argmax(p[0], p[1:])
# render: iVar4 = pass-1 c1 projection, then reads what memory holds (previous call's pass-2 values)
previous_pass2 = [0, 0, 0, 0, 0, 0]  # e.g. CBDARC2 = CBDAIC2 = 0 on the previous call
render = argmax(p[0], previous_pass2[1:])
print('pass-1 projections', p)
print('machine trim_index_1 =', machine, ' render trim_index_1 =', render)

import csv, re, sys, json
OUT = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-typing-arrays/firmware/CM848_S90140.06_analysis/output/'

rows = {}
for r in csv.reader(open(OUT + 'global_variables.csv')):
    if len(r) >= 3 and r[0].startswith('0x'):
        rows.setdefault(int(r[0], 16), r)

# 1. VGT name by e2m suffix (VGA_xxx / C_VGA_xxx / T_VGA_xxx / VGT_xxx / C_VGT_xxx)
vgt = {}
tok = re.compile(r'e2m(?: \(name level only[^)]*\))?:\s*((?:C_|T_)?VG[AT]_\w+)')
for a, r in rows.items():
    if r[1].startswith('variable_geometry_turbocharger_'):
        c = r[3] if len(r) > 3 else ''
        for m in tok.finditer(c):
            suf = re.sub(r'^(?:C_|T_)?VG[AT]_', '', m.group(1))
            key = (m.group(1).startswith('C_'), suf)
            vgt.setdefault(key, []).append((r[1], a))

# 2. EGA e2m parameters
e2m = []
for r in csv.reader(open(OUT + 'e2m_parameters.csv')):
    if r and (r[0].startswith('EGA_') or r[0].startswith('C_EGA_')):
        try:
            e2m.append((r[0], int(r[2], 16), r[3], r[4], r[5], r[6][:90] if len(r) > 6 else ''))
        except ValueError:
            pass

# 3. anchors: e2m block base -> code base
ANCH = {
    0x0117AB00: 0x4067ea,   # main calibration (+0x00 = C_Battery_Voltage_Nominal)
    0x0117AE00: 0x4067d8,   # position control diagnostic calibration
    0x0117BF00: 0x4067b0,   # thermal / current calibration
    0x0117CD00: 0x406834,   # H-bridge calibration
    0x01190800: 0x4067a0,   # driver over-current calibration
    0x0117C000: 0x40684c,   # autozero calibration
    0x0117AC00: 0x40a6c2,   # control loop state
    0x0117A900: 0x40a69e,   # thermal / current state
    0x0117AA00: 0x40a70a,   # flags (override / autozero)
    0x0117AF00: None,       # diag state (find)
    0x0117C200: None,       # H-bridge state (find)
    0x01190900: None,       # driver over-current state (find)
}
out = []
for name, ad, sz, unit, scale, desc in sorted(e2m, key=lambda t: t[1]):
    base = ad & ~0xFF
    off = ad - base
    cb = ANCH.get(base, 'none')
    code = (cb + off) if isinstance(cb, int) else None
    suf = re.sub(r'^(?:C_)?EGA_', '', name)
    cflag = name.startswith('C_')
    v = vgt.get((cflag, suf)) or vgt.get((not cflag, suf))
    cur = rows.get(code)
    out.append((name, f"0x{ad:08x}", f"+0x{off:02x}", f"0x{code:06x}" if code else '-', cur[1] if cur else ('<no row>' if code else ''), cur[2] if cur else '', v[0][0] if v else '<no vgt mirror>'))
for o in out:
    print(' | '.join(o))

print("=========== VGA-anchored mirror ===========")
VANCH = {0x01183000: 0x40771a, 0x01183100: 0x40b002, 0x01183700: 0x40b042, 0x01183800: 0x40b07e,
         0x01183900: 0x40b050, 0x01183C00: 0x407782, 0x01183B00: 0x407770, 0x01183A00: 0x4077b8,
         0x01190B00: 0x4077a8, 0x01190C00: 0x40b078}
vga = {}
for r in csv.reader(open(OUT + 'e2m_parameters.csv')):
    if r and re.match(r'^(C_|T_)?VG[AT]_', r[0]):
        try:
            ad = int(r[2], 16)
        except ValueError:
            continue
        suf = re.sub(r'^(?:C_|T_)?VG[AT]_', '', r[0])
        vga.setdefault(suf, []).append((r[0], ad))
res = {}
unm = []
for name, ad, sz, unit, scale, desc in sorted(e2m, key=lambda t: t[1]):
    suf = re.sub(r'^(?:C_)?EGA_', '', name)
    cands = vga.get(suf, [])
    hit = None
    for vn, vad in cands:
        base = vad & ~0xFF
        if base in VANCH:
            code = VANCH[base] + (vad - base)
            r = rows.get(code)
            if r and r[1].startswith('variable_geometry_turbocharger_'):
                hit = (vn, f"0x{code:06x}", r[1], r[2])
                break
    if hit:
        res[name] = hit
    else:
        unm.append(name)
for k, v in res.items():
    print(k, '->', v[2].replace('variable_geometry_turbocharger_', 'exhaust_gas_recirculation_valve_'), v[1], v[0])
print("UNMATCHED:", unm)

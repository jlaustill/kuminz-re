"""Round 45 tool fixes (advisor review): the e2m size column is decimal; prefer the default release's layout for absent
blocks (then the nearest release) and record layouts that differ between releases; show_placement reads ROM / flash2
values for code-space addresses. Idempotent."""
p = "/home/linux/.claude/jobs/374b0424/tmp/w15/r45/sweep_table_gaps.py"
t = open(p).read()
old_size = '            size = int(f[7], 16) if re.fullmatch(r"[0-9A-Fa-f]{1,4}", f[7]) else None\n'
new_size = ('            size = int(f[7]) if re.fullmatch(r"[0-9]{1,4}", f[7]) else None  '
            '# the size column is decimal (100 / 30 / 40 bytes occur)\n')
if new_size not in t:
    assert t.count(old_size) == 1
    t = t.replace(old_size, new_size)
old_rel = '''releases = sorted(glob.glob(os.path.join(repo, "e2m-analysis/CHR/CHR_CC_*.e2m")), reverse=True)
absent = {}
for path in releases:
    for b, recs in load(path).items():
        if b not in table and b not in absent:
            absent[b] = (os.path.basename(path), recs)
'''
new_rel = '''DEFAULT_VERSION = (11, 45, 1, 7)


def version(path):
    return tuple(int(x) for x in re.search(r"CHR_CC_(\\d+)\\.(\\d+)\\.(\\d+)\\.(\\d+)", path).groups())


def distance(v):
    def num(x):
        return x[0] * 10**6 + x[1] * 10**4 + x[2] * 10**2 + x[3]
    return abs(num(v) - num(DEFAULT_VERSION))


# prefer the default release, then the nearest release by version (a layout can differ between releases)
releases = sorted(glob.glob(os.path.join(repo, "e2m-analysis/CHR/CHR_CC_*.e2m")), key=lambda p: distance(version(p)))
absent, layouts = {}, {}
for path in releases:
    for b, recs in load(path).items():
        if b in table:
            continue
        sig = tuple(sorted((o, r[2]) for o, r in recs.items()))
        layouts.setdefault(b, {}).setdefault(sig, []).append(os.path.basename(path))
        if b not in absent:
            absent[b] = (os.path.basename(path), recs)
'''
if new_rel not in t:
    assert t.count(old_rel) == 1
    t = t.replace(old_rel, new_rel)
open(p, "w").write(t)
q = "/home/linux/.claude/jobs/374b0424/tmp/w15/r45/show_placement.py"
u = open(q).read()
old_dump = '''def dump(a, n):
    if 0x01000000 <= a < 0x01001000:
        a = 0x3fd482 + (a - 0x01000000)
    if 0x3FA000 <= a < 0x3FA000 + len(ram) and n in (1, 2, 4):
        return int.from_bytes(ram[a - 0x3FA000:a - 0x3FA000 + n], "big")
    return None
'''
new_dump = '''rom = open(os.path.join(s.CM, "originals/cm848_rom.bin"), "rb").read()


def dump(a, n):
    """The value at a: the RAM dump for RAM (EEPROM through its mirror), the ROM / live flash2 images for code space."""
    if n not in (1, 2, 4):
        return None
    if 0x01000000 <= a < 0x01001000:
        a = 0x3fd482 + (a - 0x01000000)
    if 0x3FA000 <= a < 0x3FA000 + len(ram):
        return int.from_bytes(ram[a - 0x3FA000:a - 0x3FA000 + n], "big")
    if a < len(rom):
        return int.from_bytes(rom[a:a + n], "big")
    if 0x500000 <= a < 0x500000 + len(s.flash2):
        return int.from_bytes(s.flash2[a - 0x500000:a - 0x500000 + n], "big")
    return None
'''
if new_dump not in u:
    assert u.count(old_dump) == 1
    u = u.replace(old_dump, new_dump)
old_hdr = '''        print(f"== {b:04X} at {base:#x} ({src})")'''
new_hdr = '''        lay = s.layouts.get(b, {})
        alts = " / ".join(f"{len(v)}x {v[0]}" for v in lay.values()) if len(lay) > 1 else ""
        print(f"== {b:04X} at {base:#x} ({src}; {len(lay)} layout(s) in {sum(len(v) for v in lay.values())} "
              f"releases{': ' + alts if alts else ''})")'''
if new_hdr not in u:
    assert u.count(old_hdr) == 1
    u = u.replace(old_hdr, new_hdr)
open(q, "w").write(u)
print("tools fixed")

"""N2 judge (round 95, read-only): check every proposed global of batch N2 against the dumps, the e2m records
(resolved through the CM550 parameter ID table) and the frozen global_variables.csv.
usage: python3 check_all.py > check_all_out.txt"""
import csv
import json
import os
import re
import struct

REPO = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay"
J = "/home/linux/.claude/jobs/374b0424/tmp/w15/r95/scratch/N2/judge"
FROZEN = "/home/linux/.claude/jobs/374b0424/tmp/w15/r95/frozen/cm550"
ram = open(os.path.join(REPO, "firmware/CM550_J90350.00_analysis/firmware/J90350.00.ram.bin"), "rb").read()
xram = open(os.path.join(REPO, "firmware/CM550_J90350.00_analysis/firmware/J90350.00.extended_ram.bin"), "rb").read()
rom = open(os.path.join(REPO, "firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin"), "rb").read()


def rd(addr, n):
    """Bytes at a CM550 address from the ROM / RAM / extended RAM dumps, or None."""
    if addr + n <= len(rom) and addr < 0x800000:
        return rom[addr:addr + n]
    if 0x800000 <= addr and addr - 0x800000 + n <= len(ram) and addr < 0x8091c2:
        return ram[addr - 0x800000:addr - 0x800000 + n]
    if addr >= 0x809242 and addr - 0x809242 + n <= len(xram):
        return xram[addr - 0x809242:addr - 0x809242 + n]
    return None


def w(addr):
    b = rd(addr, 2)
    return None if b is None else struct.unpack(">H", b)[0]


def l(addr):
    b = rd(addr, 4)
    return None if b is None else struct.unpack(">I", b)[0]


# block table
blocks = {}
for r in csv.DictReader(open(os.path.join(J, "e2m_block_table.csv"))):
    a = int(r["address_hex"], 16)
    if a:
        blocks[int(r["param_id_hex"], 16)] = a
EEPROM_BASE, MIRROR, ELEN = 0x01000000, 0x803B0A, 0x148A


def ram_address(a):
    if EEPROM_BASE <= a < EEPROM_BASE + ELEN:
        return MIRROR + a - EEPROM_BASE
    return a


records = []  # (address, mnemonic, unit, block, offset, type, length, description)
STORAGE = {"N", "S", "B", "T", "X", "Y", "Z"}
for line in open(os.path.join(REPO, "e2m-analysis/originals/v64t6_s.e2m"), errors="replace"):
    f = line.rstrip("\r\n").split(",")
    if len(f) < 8 or f[5].strip() not in STORAGE:
        continue
    try:
        blk, off = int(f[2], 16), int(f[3], 16)
    except ValueError:
        continue
    if blk not in blocks:
        continue
    desc = line.split(";", 1)[1].strip() if ";" in line else ""
    records.append((ram_address(blocks[blk] + off), f[0], f[1], blk, off, f[5].strip(), f[7].strip(), desc))
by_addr = {}
for rec in records:
    by_addr.setdefault(rec[0], []).append(rec)
starts = sorted(by_addr)


def next_record(a):
    for s in starts:
        if s > a:
            return s
    return None


# frozen globals
grows = []
for r in csv.reader(open(os.path.join(FROZEN, "global_variables.csv"))):
    if r and r[0].startswith("0x"):
        grows.append((int(r[0], 16), r[1], r[2] if len(r) > 2 else "", r[3] if len(r) > 3 else ""))
gby = {}
for a, n, t, c in grows:
    gby.setdefault(a, []).append((n, t, c))


def rows_in(a, n):
    return [(x, nm, t) for x, nm, t, c in grows if a <= x < a + n]


props = json.load(open(os.path.join(J, "proposals_globals.json")))
for e in props:
    a = int(e["address"], 16)
    t = e["proposed_type"]
    print(f"=== {e['address']} {e['current_name'] or '-'} -> {e['proposed_name']} ({t})")
    cur = gby.get(a)
    print(f"  frozen row at address: {cur[0][:2] if cur else None}")
    if t == "table_lookup_1d_arguments_t":
        size = 14
        x0, xp, xi, yp, fl = w(a), l(a + 2), w(a + 6), l(a + 8), w(a + 12)
        print(f"  dump: +0 {x0} +2 0x{xp:x} +6 {xi} +8 0x{yp:x} +0xc {fl}" if xp is not None else "  dump: none")
        for p, role in ((xp, "x"), (yp, "y")):
            if p is None:
                continue
            recs = by_addr.get(p, [])
            rn = gby.get(p)
            print(f"   {role} 0x{p:x}: e2m {[ (hex(r[3]), r[1], r[5]) for r in recs]} row {rn[0][:2] if rn else None}")
            if role == "x" and e['comment'].find(f"0x{p:x}") < 0:
                print(f"   !! x pointer 0x{p:x} not cited in the comment")
            if role == "y" and e['comment'].find(f"0x{p:x}") < 0:
                print(f"   !! y pointer 0x{p:x} not cited in the comment")
    else:
        m = re.match(r"word\[(\d+)\]", t)
        n = int(m.group(1))
        size = 2 * n
        recs = by_addr.get(a, [])
        print(f"  e2m at address: {[(hex(r[3]), '+%x' % r[4], r[1], r[2], r[5], r[6], r[7][:70]) for r in recs]}")
        nx = next_record(a)
        nxrec = by_addr.get(nx, [])
        print(f"  next e2m record: 0x{nx:x} {[r[1] for r in nxrec]} gap {nx - a} bytes = word[{(nx - a) // 2}]")
        cnt = w(a)
        if cnt is not None and a >= 0x800000:
            pts = [w(a + 2 + 2 * i) for i in range(cnt // 2)]
            print(f"  dump byte count {cnt} -> word[{cnt // 2 + 1}]; points {pts}")
            if cnt // 2 + 1 != n:
                print(f"  !! size mismatch: dump says word[{cnt // 2 + 1}], proposed word[{n}]")
        if nx - a != size:
            print(f"  !! gap {nx - a} != proposed size {size}")
    inside = rows_in(a, size)
    print(f"  rows inside [{a:#x},{a + size:#x}): {[(hex(x), nm, tt) for x, nm, tt in inside]}")
    # rows cited as removed in the comment
    cited = re.findall(r"0x([0-9a-f]{6}) ([a-z0-9_]+)", e["comment"].split("The rows inside are removed")[-1]) if "rows inside are removed" in e["comment"] else []
    inside_set = {(x, nm) for x, nm, tt in inside if x != a}
    cited_set = {(int(x, 16), nm) for x, nm in cited}
    if inside_set != cited_set:
        print(f"  !! rows-inside mismatch: actual-not-cited {sorted((hex(x), n) for x, n in inside_set - cited_set)} cited-not-actual {sorted((hex(x), n) for x, n in cited_set - inside_set)}")
    if "No other rows lie inside" in e["comment"] or "no rows inside" in e.get("evidence", ""):
        if inside_set:
            print(f"  !! comment says no rows inside but there are {sorted(inside_set)}")

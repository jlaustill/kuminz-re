"""Read-only: dump every lookupTableInterpolation argument record (14 bytes) from the CM550 RAM dumps, follow the
axis / values pointers, resolve them with e2m_block_addresses.py and list the global rows inside each record.
usage: records.py [0xADDR ...]   (default: the full list below)"""
import csv
import re
import subprocess
import sys

REPO = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay"
FW = REPO + "/firmware/CM550_J90350.00_analysis/firmware/"
rom = open(FW + "J90350.00.rom.bin", "rb").read()
ram = open(FW + "J90350.00.ram.bin", "rb").read()
ext = open(FW + "J90350.00.extended_ram.bin", "rb").read()
GLOBALS = "/home/linux/.claude/jobs/374b0424/tmp/w15/r95/frozen/cm550/global_variables.csv"
STRUCTS = "/home/linux/.claude/jobs/374b0424/tmp/w15/r95/frozen/cm550/structure_definitions.csv"


def read(addr, n):
    if addr + n <= 0x40000:
        return rom[addr:addr + n]
    if 0x800000 <= addr and addr + n <= 0x800000 + len(ram):
        return ram[addr - 0x800000:addr - 0x800000 + n]
    if 0x809242 <= addr and addr + n <= 0x809242 + len(ext):
        return ext[addr - 0x809242:addr - 0x809242 + n]
    return None


def word(addr):
    b = read(addr, 2)
    return None if b is None else int.from_bytes(b, "big")


def dword(addr):
    b = read(addr, 4)
    return None if b is None else int.from_bytes(b, "big")


struct_size = {}
for row in csv.reader(open(STRUCTS)):
    if not row or row[0].startswith("#") or row[0] == "struct_name" or len(row) < 5:
        continue
    try:
        struct_size[row[0]] = struct_size.get(row[0], 0) + int(row[4])
    except ValueError:
        pass
BASE = {"byte": 1, "char": 1, "uchar": 1, "sbyte": 1, "undefined": 1, "undefined1": 1, "bool": 1, "word": 2,
        "short": 2, "ushort": 2, "undefined2": 2, "dword": 4, "int": 4, "uint": 4, "long": 4, "ulong": 4,
        "undefined4": 4, "pointer": 4, "float": 4}


def type_size(t):
    t = t.strip()
    m = re.match(r"(.+?)\s*\[(\d+)\]$", t)
    if m:
        s = type_size(m.group(1))
        return None if s is None else s * int(m.group(2))
    if t.endswith("*"):
        return 4
    if t in BASE:
        return BASE[t]
    return struct_size.get(t)


rows = []
for row in csv.reader(open(GLOBALS)):
    if not row or not row[0].startswith("0x"):
        continue
    a = int(row[0], 16)
    rows.append((a, row[1], row[2] if len(row) > 2 else "", type_size(row[2]) if len(row) > 2 else None))
rows.sort()


def rows_in(start, end):
    out = []
    for a, n, t, s in rows:
        size = s or 1
        if a < end and a + size > start:
            out.append(f"0x{a:x} {n} ({t}{'' if s else ' ?size'})")
    return out


def e2m(addr):
    r = subprocess.run(["python3", REPO + "/firmware/scripts/e2m_block_addresses.py", "--firmware", "cm550", "--address",
                        hex(addr)], capture_output=True, text=True, cwd=REPO + "/firmware")
    return [ln for ln in r.stdout.strip().split("\n") if ln.strip()]


def table(ptr):
    if ptr is None:
        return "?"
    n = word(ptr)
    if n is None:
        return f"0x{ptr:x}: not dumped"
    pts = [word(ptr + 2 + 2 * k) for k in range(n // 2)] if n < 200 else []
    return f"0x{ptr:x}: byte count {n} -> {n // 2} points {pts}"


DEFAULT = [0x80004a, 0x800058, 0x800102, 0x800118, 0x800126, 0x800136, 0x800144, 0x800184, 0x800192, 0x8001ea,
           0x80020e, 0x80024e, 0x80025c, 0x80026a, 0x80058e, 0x80059c, 0x8005fe, 0x800632, 0x8006aa, 0x80071e,
           0x80072c, 0x80073a, 0x801a3e, 0x801a4c, 0x801c0e, 0x801c1c, 0x801c2a, 0x801c38, 0x801e30, 0x801e3e,
           0x801e4c, 0x801e5a, 0x801e68, 0x8036c6, 0x8036d4, 0x80db20, 0x80db2e]
addrs = [int(a, 16) for a in sys.argv[1:]] or DEFAULT
for rec in addrs:
    off, xp, inp, vp, flag = word(rec), dword(rec + 2), word(rec + 6), dword(rec + 8), word(rec + 12)
    print(f"=== record 0x{rec:x}: offset {off} x_axis_pointer {hex(xp) if xp is not None else None} input {inp} "
          f"values_pointer {hex(vp) if vp is not None else None} no_interpolation_flag {flag}")
    print("  rows inside:", "; ".join(rows_in(rec, rec + 14)) or "none")
    for lab, p in (("axis", xp), ("values", vp)):
        print(f"  {lab} {table(p)}")
        if p is not None:
            for ln in e2m(p):
                print("     e2m:", ln[:230])
            print("     rows at pointer:", "; ".join(rows_in(p, p + 2)) or "none")
    for k, lab in ((0, "offset"), (6, "input"), (12, "flag")):
        for ln in e2m(rec + k):
            print(f"  e2m at record +{k} ({lab}):", ln[:200])

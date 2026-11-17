"""Whole-binary access scanner for the wave-8 EGR / charge research (read-only, scratch).

  python3 scan.py build           -> disassemble ROM + FLASH2 once, scan every function window for loads and stores
                                      whose tracked effective address is in TARGETS, pickle the result
  python3 scan.py q 0xADDR ...    -> print every access that covers each address (width aware) plus the boot-ROM
                                      low-halfword and 32-bit-constant scan of 0x0-0x7F5F
"""
import importlib.util
import os
import json
import re
import struct
import subprocess
import sys

REPO = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-typing-arrays"
spec = importlib.util.spec_from_file_location("D", REPO + "/firmware/scripts/disasm_func.py")
D = importlib.util.module_from_spec(spec)
spec.loader.exec_module(D)

CACHE = os.path.join(os.path.dirname(os.path.abspath(__file__)), "scan_cache.json")
RANGES = [
    (0x3F9800, 0x3FDB40), (0x3FEE00, 0x3FEE40), (0x3FDFA0, 0x3FDFC0), (0x3FD7E0, 0x3FD810),
    (0x406730, 0x406770), (0x4067A0, 0x406860), (0x406880, 0x4068C0), (0x40A400, 0x40A720),
    (0x40BD70, 0x40BDC0), (0x40BE00, 0x40BE40), (0x400000, 0x400400), (0x4072A0, 0x4072C0),
    (0x40B7A0, 0x40B7C0), (0x40BAF0, 0x40BB20), (0x3FF720, 0x3FF740), (0x4002E0, 0x4002F0),
    (0x40A440, 0x40A460), (0x4059E0, 0x405A00), (0x407290, 0x4072A0), (0x40C080, 0x40C090),
    (0x3FF710, 0x3FF750), (0x3FFC80, 0x3FFCB0), (0x4051E0, 0x405200), (0x40A360, 0x40A400), (0x3FA120, 0x3FA180),
    (0x40AFC0, 0x40AFF0), (0x3FBD00, 0x3FBD20), (0x40A600, 0x40A640), (0x3FB415, 0x3FB430), (0x400400, 0x400420),
]


def targets():
    out = set()
    for lo, hi in RANGES:
        out.update(range(lo, hi))
    return out


def windows():
    funcs = D.function_table()
    res = []
    for i, (a, n) in enumerate(funcs):
        stop = funcs[i + 1][0] if i + 1 < len(funcs) else a + 0x800
        res.append((a, stop, n))
    return res


def run_objdump(binary, vma):
    cmd = ["powerpc-linux-gnu-objdump", "-D", "-b", "binary", "-m", "powerpc", "-EB",
           f"--adjust-vma={hex(vma)}", binary]
    return subprocess.run(cmd, capture_output=True, text=True).stdout.splitlines()


def split_by_address(lines):
    by_addr = {}
    for ln in lines:
        m = D.ASM_LINE.match(ln)
        if m:
            by_addr[int(ln.split(":")[0].strip(), 16)] = ln
    return by_addr


def scan_window(lines, tg):
    ld_st = re.compile(r"^r(\d+),(-?\d+)\(r(\d+)\)$")
    ld_x = re.compile(r"^r(\d+),r(\d+),r(\d+)$")
    regs = {0: 0}
    hits = []
    for ln in lines:
        m = D.ASM_LINE.match(ln)
        if not m:
            continue
        mnem, ops = m.group(2), m.group(3).replace(" ", "")
        op = ops.split(",")
        w = D.WIDTH.get(mnem)
        if w:
            lm = ld_st.match(ops)
            rd = None
            if lm:
                rd, disp, ra = int(lm.group(1)), int(lm.group(2)), int(lm.group(3))
                b = D.register_base(regs, ra)
                if b is not None:
                    ea = (b + disp) & 0xFFFFFFFF
                    if ea in tg:
                        hits.append((ea, "store" if mnem.startswith("st") else "load", w, mnem, ln.strip()))
            else:
                xm = ld_x.match(ops)
                if xm:
                    rd, ra, rb = int(xm.group(1)), int(xm.group(2)), int(xm.group(3))
                    va, vb = D.register_base(regs, ra), D.register_base(regs, rb)
                    if va is not None and vb is not None and ((va + vb) & 0xFFFFFFFF) in tg:
                        hits.append(((va + vb) & 0xFFFFFFFF, "store" if mnem.startswith("st") else "load", w,
                                     mnem, ln.strip() + " [indexed exact]"))
                    elif va in tg or vb in tg:
                        hits.append((va if va in tg else vb, "store" if mnem.startswith("st") else "load", w,
                                     mnem, ln.strip() + " [indexed array-base]"))
            if rd is not None and not mnem.startswith("st"):
                regs.pop(rd, None)
            continue
        D.step_address_registers(regs, mnem, op)
    return hits


def build():
    tg = targets()
    result = {}
    wins = windows()
    for binary, vma, lo, hi in ((D.ROM, 0, 0, 0x500000), (D.FLASH2, 0x500000, 0x500000, 0x10000000)):
        lines = run_objdump(binary, vma)
        by_addr = split_by_address(lines)
        addrs = sorted(by_addr)
        import bisect
        for start, stop, name in wins:
            if not (lo <= start < hi):
                continue
            i0 = bisect.bisect_left(addrs, start)
            i1 = bisect.bisect_left(addrs, stop)
            chunk = [by_addr[a] for a in addrs[i0:i1]]
            for ea, kind, width, mnem, ln in scan_window(chunk, tg):
                result.setdefault(ea, []).append((name, start, kind, width, mnem, ln))
    json.dump({str(k): v for k, v in result.items()}, open(CACHE, "w"))
    print("targets hit:", len(result), "total hits:", sum(len(v) for v in result.values()))


SIZE = {"byte": 1, "word": 2, "dword": 4}


def boot_scan(addr):
    rom = open(D.ROM, "rb").read()
    low = addr & 0xFFFF
    lows = {low, (low - 0x10000) if low >= 0x8000 else low}
    out = []
    for off in range(0, 0x7F60, 4):
        word = struct.unpack(">I", rom[off:off + 4])[0]
        if word == addr:
            out.append((off, "32-bit constant %08x" % word))
        opcode = word >> 26
        if opcode in (32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 14, 15, 24, 25, 12, 13, 28, 29):
            imm = word & 0xFFFF
            if imm == low:
                out.append((off, "low-halfword %04x opcode %d insn %08x" % (low, opcode, word)))
    return out


def query(addrs):
    cache = {int(k): v for k, v in json.load(open(CACHE)).items()}
    for a in addrs:
        print("=== 0x%06x ===" % a)
        seen = False
        for ea in range(a - 3, a + 1):
            for (name, start, kind, width, mnem, ln) in cache.get(ea, []):
                if ea + SIZE[width] > a:
                    print("  %-6s %-5s ea=0x%06x  %-60s @0x%x  %s" % (kind, width, ea, name, start, ln.split("\t", 1)[-1][:60] if False else mnem))
                    seen = True
        if not seen:
            print("  (no tracked access)")
        bs = boot_scan(a)
        print("  boot ROM 0x0-0x7F5F scan: %d hit(s)" % len(bs))
        for off, what in bs[:6]:
            print("    0x%05x %s" % (off, what))


if __name__ == "__main__":
    if sys.argv[1] == "build":
        build()
    elif sys.argv[1] == "q":
        query([int(x, 16) for x in sys.argv[2:]])

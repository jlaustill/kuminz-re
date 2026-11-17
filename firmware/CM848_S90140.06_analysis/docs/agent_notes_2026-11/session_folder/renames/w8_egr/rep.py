"""Compact per-address report: CSV row, dump value, every access (function: loads/stores, width), boot-ROM hits.

  python3 rep.py 0x3fa7b8 0x3fa7ba ...     (word addresses; byte rows are shown by their own address)
"""
import csv
import json
import os
import struct
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import scan  # noqa: E402

OUT = scan.REPO + "/firmware/CM848_S90140.06_analysis/output"
SIZE = {"byte": 1, "word": 2, "dword": 4}
cache = {int(k): v for k, v in json.load(open(scan.CACHE)).items()}
rows = {}
for row in csv.reader(open(OUT + "/global_variables.csv")):
    if row and row[0].startswith("0x"):
        rows[int(row[0], 16)] = row
ram = open(scan.D.ROM.replace("cm848_rom.bin", "cm848_ram.bin"), "rb").read()
rom = open(scan.D.ROM, "rb").read()


def dump(addr, width):
    n = SIZE[width]
    if 0x3FA000 <= addr < 0x3FA000 + len(ram):
        buf, off = ram, addr - 0x3FA000
    elif addr < len(rom):
        buf, off = rom, addr
    else:
        return None
    return int.from_bytes(buf[off:off + n], "big")


def accesses(addr):
    out = {}
    for ea in range(addr - 3, addr + 1):
        for (name, start, kind, width, mnem, ln) in cache.get(ea, []):
            if ea + SIZE[width] > addr:
                out.setdefault((name, start), []).append("%s%s%s" % ("R" if kind == "load" else "W", {"byte": "b", "word": "h", "dword": "w"}[width], "" if ea == addr else "@%x" % ea))
    return out


def main():
    full = "--full" in sys.argv
    for a in [int(x, 16) for x in sys.argv[1:] if not x.startswith("--")]:
        row = rows.get(a)
        name = row[1] if row else "-"
        typ = row[2] if row else "-"
        width = typ if typ in SIZE else "word"
        val = dump(a, width)
        print("=== 0x%06x  %s  [%s]  dump=%s" % (a, name, typ, ("%d (0x%x)" % (val, val)) if val is not None else "n/a"))
        if row and full:
            print("    comment:", row[3][:300] if len(row) > 3 else "")
        acc = accesses(a)
        if not acc:
            print("    (no tracked access)")
        for (fname, start), ops in sorted(acc.items(), key=lambda kv: kv[0][1]):
            print("    %-72s @0x%x %s" % (fname, start, " ".join(ops)))
        bs = scan.boot_scan(a)
        print("    boot ROM 0x0-0x7F5F: %s" % ("none" if not bs else "; ".join("0x%05x %s" % x for x in bs[:4])))


if __name__ == "__main__":
    main()

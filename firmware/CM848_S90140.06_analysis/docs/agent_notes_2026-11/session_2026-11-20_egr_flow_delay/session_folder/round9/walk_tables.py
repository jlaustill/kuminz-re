"""Walk the e2m ROM calibration blocks in their memory order (e2m column 5) from a known start address, sizing each
table from the RAM dump: an X axis or Y curve is a byte-length word + that many bytes, a Z grid is nx x ny words with no
header (nx / ny from its two axis blocks), a T table is taken as a byte-length word + data too (flagged). Stops at the
first scalar (N) block and prints where the walk ends, so the end can be checked against that block's proved base.
Prints each table with the CSV row at its address.
usage: walk_tables.py <repo> <first col5> <start address> [--csv out.csv]"""
import csv
import os
import re
import sys

repo, first, start = os.path.abspath(sys.argv[1]), sys.argv[2].upper(), int(sys.argv[3], 16)
out_csv = sys.argv[sys.argv.index("--csv") + 1] if "--csv" in sys.argv else None
E2M = os.path.join(repo, "e2m-analysis", "CHR", "CHR_CC_11.45.01.07.e2m")
OUT = os.path.join(repo, "firmware", "CM848_S90140.06_analysis", "output")
RAM = open(os.path.join(repo, "firmware", "CM848_S90140.06_analysis", "originals", "cm848_ram.bin"), "rb").read()


def word(a):
    o = a - 0x3FA000
    return int.from_bytes(RAM[o:o + 2], "big")


blocks, by_block = {}, {}
for line in open(E2M, errors="replace"):
    g = line.split(";")[0].split(",")
    if len(g) > 4 and re.match(r"^[0-9A-F]{4}$", g[2]):
        by_block.setdefault(g[2], g[0])
    f = line.split(";")[0].split(",")
    if len(f) < 16 or not re.match(r"^[0-9A-F]{4}$", f[2]) or not re.match(r"^0B[0-9A-F]{2}$", f[4]):
        continue
    desc = line.split(";", 1)[1].strip() if ";" in line else ""
    blocks.setdefault(f[4], (f[2], f[5], f[0], f[15], desc))
rows = {}
for line in open(os.path.join(OUT, "global_variables.csv")):
    if re.match(r"^0x[0-9a-f]{8},", line):
        a, n, t = (line.split(",", 3) + ["", ""])[:3]
        rows[int(a, 16)] = (n, t)
order = sorted(k for k in blocks if k >= first)
addr, size_of, result = start, {}, []
for k in order:
    block, typ, name, axes, desc = blocks[k]
    if typ == "N":
        print(f"== stop at {k} {block} (N {name}): the walk ends at {hex(addr)}")
        break
    if typ in ("X", "Y", "T"):
        length = word(addr)
        size = 2 + length
        points = length // 2
    elif typ == "Z":
        xa, ya = axes.split(":")
        if xa in size_of and ya in size_of:
            nx, ny = size_of[xa][1], size_of[ya][1]
            size, points = 2 * nx * ny, nx * ny
        else:  # an axis outside this sequence (11.45): in 11.46 it can sit inline just before the grid
            missing = ya if xa in size_of else xa
            length = word(addr)
            axis_points = length // 2
            known = size_of[xa if missing == ya else ya][1]
            n0, t0 = rows.get(addr, ("-", ""))
            print(f"    {k}: axis {missing} ({by_block.get(missing, '?')}) inline at {hex(addr)}: {axis_points} points "
                  f"(row: {n0} {t0})")
            result.append((k + "a", missing, "X", by_block.get(missing, "?"), hex(addr), 1 + axis_points, n0, t0, "inline axis"))
            size_of[missing] = (2 + length, axis_points)
            addr += 2 + length
            nx, ny = size_of[xa][1], size_of[ya][1]
            size, points = 2 * nx * ny, nx * ny
    else:
        print(f"!! {k} {block} type {typ} {name}: not a table, stop at {hex(addr)}")
        break
    size_of[block] = (size, points)
    n, t = rows.get(addr, ("-", ""))
    m = re.match(r"^word\[(\d+)\]$", t)
    words = size // 2
    ok = "OK " if m and int(m.group(1)) == words else ("TYP" if t else "NO ")
    result.append((k, block, typ, name, hex(addr), words, n, t, desc))
    print(f"{ok} {k} {block} {typ} {hex(addr)} {words:3d}w {name:45s} row: {n} {t}")
    addr += size
if out_csv:
    with open(out_csv, "w", newline="") as f:
        w = csv.writer(f)
        w.writerow(["col5", "block", "type", "e2m_name", "address", "words", "row_name", "row_type", "description"])
        w.writerows(result)

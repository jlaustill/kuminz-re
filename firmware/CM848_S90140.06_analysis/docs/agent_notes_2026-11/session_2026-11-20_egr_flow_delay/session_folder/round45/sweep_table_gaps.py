"""Round 45: sweep every gap between consecutive dumped parameter ID table blocks for absent CHR_CC blocks that fill it
exactly (round 44's tiling method, made systematic).
- Dumped block extent = max(offset + size) over its records in the default e2m; an axis / array record (X Y T A C) in
  ROM or flash2 adds its byte-length word + 2; a grid (Z) or an unreadable length makes the extent unknown.
- Absent block extent = the same over the records of the newest CHR_CC release that has the block (scalar records
  only; a block with any table record is listed as 'table' and matched by walking ROM length words at the gap start).
- A gap matches one absent block (extent == gap, or extent + 1 == gap for an odd extent before a word boundary) or a
  pair of absent blocks.
usage: sweep_table_gaps.py <repo> [max_gap]"""
import glob
import os
import re
import sys
from itertools import combinations

repo = os.path.abspath(sys.argv[1])
max_gap = int(sys.argv[2]) if len(sys.argv) > 2 else 48
sys.path.insert(0, os.path.join(repo, "firmware/scripts"))
import e2m_block_addresses as e  # noqa: E402

CM = os.path.join(repo, "firmware/CM848_S90140.06_analysis")
flash2 = open(e.DEFAULTS["flash2"], "rb").read()
rom = open(os.path.join(CM, "originals/cm848_rom.bin"), "rb").read()
table = e.parse_table(flash2)
TABLE_TYPES = set("XYTAC")


def load(path):
    out = {}
    for line in open(path, errors="replace"):
        head, _, desc = line.strip().partition(";")
        f = head.split(",")
        if len(f) > 11 and re.fullmatch(r"[0-9A-Fa-f]{4}", f[2]) and re.fullmatch(r"[0-9A-Fa-f]{1,4}", f[3]) and f[2].upper() != "FFFF":
            size = int(f[7]) if re.fullmatch(r"[0-9]{1,4}", f[7]) else None  # the size column is decimal (100 / 30 / 40 bytes occur)
            out.setdefault(int(f[2], 16), {}).setdefault(int(f[3], 16), (f[0], f[5], size, desc.strip()[:70]))
    return out


default = load(os.path.join(repo, "e2m-analysis/CHR/CHR_CC_11.45.01.07.e2m"))
DEFAULT_VERSION = (11, 45, 1, 7)


def version(path):
    return tuple(int(x) for x in re.search(r"CHR_CC_(\d+)\.(\d+)\.(\d+)\.(\d+)", path).groups())


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


def read_word(a):
    if a < len(rom):
        return int.from_bytes(rom[a:a + 2], "big")
    if 0x500000 <= a < 0x500000 + len(flash2):
        return int.from_bytes(flash2[a - 0x500000:a - 0x500000 + 2], "big")
    return None


def extent(base, recs):
    """(extent, kind) of a block placed at base; kind 'scalar' / 'table' / None when unknown."""
    end, kind = 0, "scalar"
    for o, (name, typ, size, _) in recs.items():
        if typ == "Z":
            return None, None
        if typ in TABLE_TYPES:
            kind = "table"
            n = read_word(base + o) if base is not None else None
            if n is None or n > 1024 or n % 2:
                return None, None
            end = max(end, o + 2 + n)
        elif size:
            end = max(end, o + size)
    return end, kind


blocks = sorted((a, b) for b, a in table.items())
absent_scalar = {}
for b, (fn, recs) in absent.items():
    if all(t not in TABLE_TYPES and t != "Z" for _, t, _, _ in recs.values()):
        x, _ = extent(None, recs)
        if x:
            absent_scalar.setdefault(x, []).append(b)
gaps = []
for (a1, b1), (a2, b2) in zip(blocks, blocks[1:]):
    if b1 not in default or (a2 >> 24) != (a1 >> 24):
        continue
    x, kind = extent(a1, default[b1])
    if x is None:
        continue
    gap = a2 - (a1 + x)
    if 0 < gap <= max_gap:
        gaps.append((a1 + x, gap, b1, b2))
print(f"{len(blocks)} dumped blocks, {len(absent)} absent CHR_CC blocks ({sum(len(v) for v in absent_scalar.values())} "
      f"scalar-only with a known extent), {len(gaps)} gaps of 1..{max_gap} bytes")
for start, gap, b1, b2 in gaps:
    single = list(absent_scalar.get(gap, []))
    if gap % 2 == 0:
        single += [b for b in absent_scalar.get(gap - 1, [])]
    pairs = []
    if gap <= 24:
        for x1 in absent_scalar:
            x2 = gap - x1
            if x1 <= x2 and x2 in absent_scalar:
                for p in absent_scalar[x1]:
                    for q in absent_scalar[x2]:
                        if p != q:
                            pairs.append((p, q))
    tag = "UNIQUE" if len(single) == 1 and not pairs else f"{len(single)} single / {len(pairs)} pairs"
    print(f"gap {start:#09x} +{gap:<3} after {b1:04X} before {b2:04X}: {tag}"
          + (f" -> {' '.join(f'{b:04X}' for b in single[:8])}" if single else ""))

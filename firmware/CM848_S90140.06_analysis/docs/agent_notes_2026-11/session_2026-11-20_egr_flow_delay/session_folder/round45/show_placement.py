"""Round 45: lay candidate absent blocks over the CM848 rows at a base (block@address[,block@address...]), records from
the newest CHR_CC release that has the block, with the dump value and the row's name / type / comment.
usage: show_placement.py <repo> 8A89@0x409ec6,1D41@0x409ed2 [...]"""
import contextlib
import csv
import io
import os
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
repo = os.path.abspath(sys.argv[1])
groups = sys.argv[2:]
sys.argv = [sys.argv[0], repo, "8"]
with contextlib.redirect_stdout(io.StringIO()):
    import sweep_table_gaps as s  # noqa: E402

ram = open(os.path.join(s.CM, "originals/cm848_ram.bin"), "rb").read()
rows = {}
for r in csv.reader(open(os.path.join(s.CM, "output/global_variables.csv"))):
    if r and r[0].startswith("0x"):
        rows.setdefault(int(r[0], 16), []).append((r[1], r[2] if len(r) > 2 else "", (r[3] if len(r) > 3 else "")[:110]))


rom = open(os.path.join(s.CM, "originals/cm848_rom.bin"), "rb").read()


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


for g in groups:
    for item in g.split(","):
        b, a = item.split("@")
        b, base = int(b, 16), int(a, 16)
        src, recs = s.absent[b] if b in s.absent else ("default", s.default[b])
        lay = s.layouts.get(b, {})
        alts = " / ".join(f"{len(v)}x {v[0]}" for v in lay.values()) if len(lay) > 1 else ""
        print(f"== {b:04X} at {base:#x} ({src}; {len(lay)} layout(s) in {sum(len(v) for v in lay.values())} "
              f"releases{': ' + alts if alts else ''})")
        for o in sorted(recs):
            name, typ, size, desc = recs[o]
            addr = base + o
            mirror = 0x3fd482 + (addr - 0x01000000) if addr >= 0x01000000 else addr
            print(f"   +{o:02X} {mirror:#x} {name} [{typ}{size}] dump {dump(addr, size)}: {desc}")
            for n, t, c in rows.get(mirror, []):
                print(f"        row: {n} {t} | {c}")

"""Find every reference (4-byte big-endian absolute, or 16-bit pc-relative bsr / bra / bcc) to given CM550 ROM
addresses (read-only helper, round 93 batch D1 investigator).
usage: find_refs.py 0xADDR ..."""
import sys

ROM = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin"
rom = open(ROM, "rb").read()
for arg in sys.argv[1:]:
    a = int(arg, 16)
    pat = a.to_bytes(4, "big")
    hits = []
    i = rom.find(pat)
    while i != -1:
        prev = rom[i - 2:i].hex() if i >= 2 else ""
        hits.append((i, prev))
        i = rom.find(pat, i + 1)
    rel = []
    for j in range(0, len(rom) - 4, 2):
        op = int.from_bytes(rom[j:j + 2], "big")
        if (op & 0xf0ff) == 0x6000:  # bra.w / bsr.w / bcc.w (16-bit displacement)
            d = int.from_bytes(rom[j + 2:j + 4], "big", signed=True)
            if j + 2 + d == a:
                rel.append(j)
        elif (op & 0xf000) == 0x6000 and (op & 0xff) not in (0, 0xff):  # 8-bit displacement
            d = op & 0xff
            d = d - 256 if d & 0x80 else d
            if j + 2 + d == a:
                rel.append(j)
    print(f"0x{a:x}: abs refs " + (", ".join(f"0x{i:x}(prev {p})" for i, p in hits) or "none")
          + "; relative branches " + (", ".join(f"0x{j:x}" for j in rel) or "none"))

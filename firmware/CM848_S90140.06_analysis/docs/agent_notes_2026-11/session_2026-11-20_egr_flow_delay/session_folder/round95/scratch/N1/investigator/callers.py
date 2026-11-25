"""Find every reference to CM550 code addresses in the ROM: jsr/jmp abs.l, bsr/bra (8/16/32-bit), jsr/lea/pea d16(pc),
and raw 4-byte big-endian occurrences (tables / pea / move.l #).
usage: callers.py <0xADDR> [...]"""
import sys
import bisect
import re

ROM = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin"
CPP = "/home/linux/.claude/jobs/374b0424/tmp/w15/r95/frozen/cm550/J90350.00.ghidra.cpp"
rom = open(ROM, "rb").read()
funcs = []
for m in re.finditer(r"^// Function: (\S+) @ 0x([0-9a-fA-F]+)", open(CPP, errors="replace").read(), flags=re.M):
    funcs.append((int(m.group(2), 16), m.group(1)))
funcs.sort()
starts = [f[0] for f in funcs]


def owner(a):
    i = bisect.bisect_right(starts, a) - 1
    if i < 0:
        return "?"
    return f"{funcs[i][1]}+0x{a - funcs[i][0]:x}"


def s16(v):
    return v - 0x10000 if v & 0x8000 else v


def s8(v):
    return v - 0x100 if v & 0x80 else v


for arg in sys.argv[1:]:
    t = int(arg, 16)
    print(f"== 0x{t:x}")
    hits = []
    for pc in range(0, len(rom) - 6, 2):
        w = int.from_bytes(rom[pc:pc + 2], "big")
        if w in (0x4eb9, 0x4ef9) and int.from_bytes(rom[pc + 2:pc + 6], "big") == t:
            hits.append((pc, "jsr.l" if w == 0x4eb9 else "jmp.l"))
        elif w in (0x4eba, 0x4efa, 0x41fa, 0x43fa, 0x45fa, 0x47fa, 0x49fa, 0x4bfa, 0x4dfa, 0x4ffa, 0x487a):
            if pc + 2 + s16(int.from_bytes(rom[pc + 2:pc + 4], "big")) == t:
                hits.append((pc, {0x4eba: "jsr(pc)", 0x4efa: "jmp(pc)", 0x487a: "pea(pc)"}.get(w, "lea(pc)")))
        elif (w >> 8) in (0x61, 0x60):
            kind = "bsr" if (w >> 8) == 0x61 else "bra"
            d = w & 0xff
            if d == 0:
                if pc + 2 + s16(int.from_bytes(rom[pc + 2:pc + 4], "big")) == t:
                    hits.append((pc, kind + ".w"))
            elif d == 0xff:
                if pc + 2 + int.from_bytes(rom[pc + 2:pc + 6], "big", signed=True) == t:
                    hits.append((pc, kind + ".l"))
            else:
                if pc + 2 + s8(d) == t and kind == "bsr":
                    hits.append((pc, kind + ".s"))
    pat = t.to_bytes(4, "big")
    i = rom.find(pat)
    while i != -1:
        if not any(h[0] + 2 == i for h in hits):
            prev = rom[i - 2:i].hex()
            hits.append((i, f"raw4 (prev word {prev})"))
        i = rom.find(pat, i + 1)
    for pc, kind in sorted(hits):
        print(f"  0x{pc:05x} {kind:24s} in {owner(pc)}")

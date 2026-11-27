"""Round 93 (read-only): CM550 global rows typed 'undefined' (they print with a leading underscore when the code
reads them as a word or a long) and the width the ROM proves for each: every aligned 4-byte occurrence of the row's
address is decoded as an operand of an instruction with a size (move / movea / cmp / cmpi / tst / clr / add / sub /
and / or / eor / addq / subq / bit instructions ...). A row is a CANDIDATE when
- it has at least one occurrence and every occurrence decodes (none unknown, no bare address load whose use is unseen),
- all occurrences have the same width,
- no occurrence of the addresses inside that width (address+1 for a word, +1..+3 for a long) exists,
- the next row starts at or after address + width.
Writes a TSV of all undefined rows with the verdict. usage: untyped_width_scan_r93.py <repo> <out.tsv>"""
import os
import sys

repo, out = os.path.abspath(sys.argv[1]), sys.argv[2]
rom = open(os.path.join(repo, "firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin"), "rb").read()
G = os.path.join(repo, "firmware/CM550_J90350.00_analysis/output/global_variables.csv")
rows = []
for line in open(G, newline="").read().split("\n"):
    parts = line.split(",", 3)
    if len(parts) > 2 and parts[0].startswith("0x"):
        rows.append((int(parts[0], 16), parts[1], parts[2]))
rows.sort()
addresses = [r[0] for r in rows]
# index every aligned occurrence of a RAM address (0x0080xxxx) once
occ = {}
for i in range(0, len(rom) - 3, 2):
    if rom[i] == 0x00 and rom[i + 1] == 0x80:
        occ.setdefault(int.from_bytes(rom[i:i + 4], "big"), []).append(i)
SZ = {0: "b", 1: "w", 2: "l"}


def w16(a):
    return int.from_bytes(rom[a:a + 2], "big")


def classify(i):
    """Size of the instruction that has the absolute long at i as an operand; None when not recognised."""
    if i >= 2:
        w = w16(i - 2)
        top, mode_src, mode_dst = w >> 12, w & 0x3f, (w >> 6) & 0x3f
        if top in (1, 2, 3):
            size = {1: "b", 3: "w", 2: "l"}[top]
            if mode_src == 0x39:                       # move (abs).l,<ea>   (incl. movea)
                return size
            if mode_dst == 0x0f and mode_src < 0x28:   # move <reg / (An) / (An)+ / -(An)>,(abs).l  -> dst mode 111 reg 001 = bits 0x1c0|... check below
                pass
            if ((w >> 6) & 7) == 7 and ((w >> 9) & 7) == 1 and mode_src < 0x28:
                return size                            # move <no-extension source>,(abs).l
        if (w & 0xff00) in (0x4a00, 0x4200, 0x4400, 0x4600) and (w & 0x3f) == 0x39 and ((w >> 6) & 3) != 3:
            return SZ[(w >> 6) & 3]                    # tst / clr / neg / not
        if top in (0x8, 0x9, 0xb, 0xc, 0xd) and (w & 0x3f) == 0x39:
            opm = (w >> 6) & 7
            return {0: "b", 1: "w", 2: "l", 4: "b", 5: "w", 6: "l", 3: "w", 7: "l"}[opm]   # or/sub/cmp/and/add (+ the A forms)
        if top == 5 and (w & 0x3f) == 0x39 and ((w >> 6) & 3) != 3:
            return SZ[(w >> 6) & 3]                    # addq / subq
        if (w & 0xf1ff) in (0x0139, 0x0179, 0x01b9, 0x01f9):
            return "b"                                 # btst / bchg / bclr / bset Dn,(abs).l
    if i >= 4:
        w = w16(i - 4)
        top = w >> 12
        if (w & 0xff00) in (0x0000, 0x0200, 0x0400, 0x0600, 0x0a00, 0x0c00) and (w & 0x3f) == 0x39 and ((w >> 6) & 3) in (0, 1):
            return SZ[(w >> 6) & 3]                    # ori / andi / subi / addi / eori / cmpi  #imm.b/.w
        if w in (0x0839, 0x0879, 0x08b9, 0x08f9):
            return "b"                                 # btst / bchg / bclr / bset #n
        if top in (1, 2, 3) and ((w >> 6) & 7) == 7 and ((w >> 9) & 7) == 1 and (w & 0x3f) in (0x28, 0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f, 0x38, 0x3a) :
            return {1: "b", 3: "w", 2: "l"}[top]       # move (d16,An) / abs.w / (d16,pc) ,(abs).l
        if top in (1, 3) and ((w >> 6) & 7) == 7 and ((w >> 9) & 7) == 1 and (w & 0x3f) == 0x3c:
            return {1: "b", 3: "w"}[top]               # move #imm.b/.w,(abs).l
    if i >= 6:
        w = w16(i - 6)
        top = w >> 12
        if top in (1, 2, 3) and ((w >> 6) & 7) == 7 and ((w >> 9) & 7) == 1 and (w & 0x3f) == 0x39:
            return {1: "b", 3: "w", 2: "l"}[top]       # move (abs).l,(abs).l : this is the destination
        if top == 2 and ((w >> 6) & 7) == 7 and ((w >> 9) & 7) == 1 and (w & 0x3f) == 0x3c:
            return "l"                                 # move.l #imm,(abs).l
        if (w & 0xff00) in (0x0000, 0x0200, 0x0400, 0x0600, 0x0a00, 0x0c00) and (w & 0x3f) == 0x39 and ((w >> 6) & 3) == 2:
            return "l"                                 # ori / andi / subi / addi / eori / cmpi  #imm.l
    return None


WIDTH = {"b": 1, "w": 2, "l": 4}
TYPE = {"b": "byte", "w": "word", "l": "dword"}
counts = {}
with open(out, "w") as fh:
    fh.write("address\tname\tverdict\twidth\toccurrences\tdetail\n")
    for k, (a, name, typ) in enumerate(rows):
        if typ != "undefined" or not name:
            continue
        sites = occ.get(a, [])
        sizes = [classify(i) for i in sites]
        nxt = addresses[k + 1] if k + 1 < len(addresses) else a + 8
        if not sites:
            verdict, width = "no-direct-access", ""
        elif None in sizes:
            verdict, width = "undecoded-access", ""
        elif len(set(sizes)) != 1:
            verdict, width = "mixed-widths", ""
        else:
            width = sizes[0]
            inner = sum(len(occ.get(a + d, [])) for d in range(1, WIDTH[width]))
            if inner:
                verdict = "inner-access"
            elif nxt < a + WIDTH[width]:
                verdict = "next-row-overlaps"
            else:
                verdict = "CANDIDATE"
        counts[verdict] = counts.get(verdict, 0) + 1
        fh.write(f"0x{a:08x}\t{name}\t{verdict}\t{TYPE.get(width, '')}\t{len(sites)}\t{','.join(str(s) for s in sizes)[:60]}\n")
print(counts)

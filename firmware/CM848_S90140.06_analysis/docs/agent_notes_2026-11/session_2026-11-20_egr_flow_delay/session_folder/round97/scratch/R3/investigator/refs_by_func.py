"""For each CM550 address: every absolute-long reference in the ROM, the containing function (from the .cpp function
starts), and the access guess from abs_refs-like decoding. usage: refs_by_func.py 0xADDR ..."""
import re, sys, bisect
CPP = "/home/linux/.claude/jobs/374b0424/tmp/w15/r97/frozen/cm550/J90350.00.ghidra.cpp"
ROM = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin"
rom = open(ROM, "rb").read()
funcs = []
for m in re.finditer(r"^// Function: (\S+) @ 0x([0-9a-fA-F]+)", open(CPP, errors="replace").read(), re.M):
    funcs.append((int(m.group(2), 16), m.group(1)))
funcs.sort()
starts = [f[0] for f in funcs]


def owner(a):
    i = bisect.bisect_right(starts, a) - 1
    return funcs[i][1] + "@0x%x" % funcs[i][0] if i >= 0 else "?"


SIZE = {0x1: "b", 0x3: "w", 0x2: "l"}
for arg in sys.argv[1:]:
    a = int(arg, 16)
    pat = a.to_bytes(4, "big")
    i = rom.find(pat)
    print("== 0x%x" % a)
    while i != -1:
        if i % 2 == 0:
            w2 = int.from_bytes(rom[i-2:i], "big")
            w4 = int.from_bytes(rom[i-4:i-2], "big")
            w6 = int.from_bytes(rom[i-6:i-4], "big")
            g = []
            if (w2 >> 12) in SIZE and (w2 & 0x3f) == 0x39:
                g.append("move.%s src" % SIZE[w2 >> 12])
            if (w6 >> 12) in SIZE and ((w6 >> 6) & 0x3f) == 0x0f and (w6 & 0x3f) == 0x39:
                g.append("move.%s abs->abs dst" % SIZE[w6 >> 12])
            if (w2 >> 12) in SIZE and ((w2 >> 6) & 0x3f) == 0x0f:
                g.append("move.%s dst" % SIZE[w2 >> 12])
            if w4 in (0x0c79, 0x0c39, 0x0cb9):
                g.append({0x0c79: "cmpi.w", 0x0c39: "cmpi.b", 0x0cb9: "cmpi.l"}[w4])
            if w2 in (0x4a79, 0x4a39, 0x4ab9, 0x4279, 0x4239, 0x42b9):
                g.append({0x4a79: "tst.w", 0x4a39: "tst.b", 0x4ab9: "tst.l", 0x4279: "clr.w", 0x4239: "clr.b", 0x42b9: "clr.l"}[w2])
            if (w2 & 0xf1ff) == 0xb079:
                g.append("cmp.w ,d")
            if (w2 & 0xf1ff) == 0x41f9 or w2 == 0x4879:
                g.append("lea/pea")
            print("  0x%x %-55s prev %s | %s" % (i, owner(i), rom[i-6:i].hex(' '), "; ".join(g) or "?"))
        i = rom.find(pat, i + 1)

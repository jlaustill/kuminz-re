"""Linear sweep of both CM848 banks with disasm_func.find_accesses for every address in a range;
reports accesses whose byte span overlaps the target words. Discovery aid (register state carries
across function boundaries, so verify each hit in context)."""
import sys
sys.path.insert(0, sys.argv[1])
import disasm_func as D
SIZE = {"byte": 1, "word": 2, "dword": 4}
targets = [(0x40a292, 2), (0x40a2a8, 2)]
lo, hi = 0x40a28c, 0x40a2ac
for dis in sys.argv[2:]:
    lines = open(dis).read().splitlines()
    for a in range(lo, hi):
        hits, _ = D.find_accesses(lines, a)
        for kind, ln, w in hits:
            span = range(a, a + SIZE[w])
            for t, n in targets:
                if any(t <= b < t + n for b in span):
                    print(f"0x{a:06x} {kind:5} {w:5} overlaps 0x{t:06x}: {ln}")

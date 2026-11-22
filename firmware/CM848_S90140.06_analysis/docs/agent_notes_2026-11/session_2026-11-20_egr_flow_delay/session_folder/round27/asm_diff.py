"""Round 27: instruction-level diff of two flash2 functions (Type A vs Type B sensor channel bodies).
Branch targets inside each function become offsets from its start; calls keep their absolute target.
usage: asm_diff.py <flash2.bin> <startA> <endA> <startB> <endB>"""
import difflib
import re
import subprocess
import sys

binf = sys.argv[1]
ra = (int(sys.argv[2], 16), int(sys.argv[3], 16))
rb = (int(sys.argv[4], 16), int(sys.argv[5], 16))
LINE = re.compile(r"^\s*([0-9a-f]+):\t[0-9a-f ]+\t\s*(\S+)\s*(.*)$")


def dis(start, stop):
    out = subprocess.run(["powerpc-linux-gnu-objdump", "-D", "-b", "binary", "-m", "powerpc", "-EB",
                          "--adjust-vma=0x500000", f"--start-address={hex(start)}", f"--stop-address={hex(stop)}",
                          binf], capture_output=True, text=True).stdout.splitlines()
    rows = []
    for line in out:
        m = LINE.match(line)
        if not m:
            continue
        mnem, ops = m.group(2), m.group(3)
        ops = re.sub(r"<[^>]*>", "", ops).strip()
        t = re.search(r"\b0x([0-9a-f]+)\b", ops)
        if mnem.startswith("b") and t and mnem != "bl":
            target = int(t.group(1), 16)
            if start <= target < stop:
                ops = ops.replace(t.group(0), f"+{target - start:#x}")
        rows.append(f"{mnem} {ops}")
    return rows


def canon(rows):
    """Rename registers by first appearance (r0 / r1 keep their names): register allocation is noise here."""
    seen = {}

    def sub(m):
        k = m.group(0)
        if k in ("r0", "r1"):
            return k
        seen.setdefault(k, f"R{len(seen)}")
        return seen[k]
    return [re.sub(r"\br\d+\b", sub, x) for x in rows]


CANON = "--canon" in sys.argv
a, b = (canon(dis(*ra)), canon(dis(*rb))) if CANON else (dis(*ra), dis(*rb))
sm = difflib.SequenceMatcher(None, a, b, autojunk=False)
print(f"A {len(a)} instructions, B {len(b)}; equal {sum(i2 - i1 for t, i1, i2, j1, j2 in sm.get_opcodes() if t == 'equal')}")
for tag, i1, i2, j1, j2 in sm.get_opcodes():
    if tag != "equal":
        print(f"--- {tag} A[{i1}:{i2}] ({ra[0] + 4 * i1:#x}) vs B[{j1}:{j2}] ({rb[0] + 4 * j1:#x})")
        for x in a[i1:i2]:
            print("   A  " + x)
        for x in b[j1:j2]:
            print("   B  " + x)

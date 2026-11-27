"""For each proposed global: current row, e2m record(s) at/inside, abs-ref widths, name uniqueness, rows swallowed."""
import csv
import re
import subprocess
import sys

sys.path.insert(0, "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/scripts")
import e2m_block_addresses as e  # noqa: E402

REPO = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay"
ROM = REPO + "/firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin"
GLOBALS = "/home/linux/.claude/jobs/374b0424/tmp/w15/r96/frozen/cm550/global_variables.csv"
rows = {}
names = {}
with open(GLOBALS, newline="", errors="replace") as f:
    for r in csv.reader(f):
        if not r or not r[0].startswith("0x"):
            continue
        a = int(r[0], 16)
        while len(r) < 4:
            r.append("")
        rows[a] = r
        names.setdefault(r[1], []).append(a)
table = e.parse_cm550_table(open(ROM, "rb").read())
by_address = {}
for name, unit, block, offset, description in e.parse_e2m_storage(REPO + "/e2m-analysis/originals/v64t6_s.e2m"):
    base = table.get(block)
    if base is None:
        continue
    address = e.cm550_ram_address(base) + offset
    by_address.setdefault(address, []).append(f"{block:04X}+{offset:X} {name} [{unit}] {description[:70]}")
lens = {}
for line in open(REPO + "/e2m-analysis/originals/v64t6_s.e2m", errors="replace"):
    parts = line.split(",")
    if len(parts) > 10:
        lens[parts[0].strip()] = (parts[7].strip(), parts[9].strip(), parts[5].strip())


def size_of(t):
    m = re.fullmatch(r"(\w+)\[(\d+)\]", t)
    base, n = (m.group(1), int(m.group(2))) if m else (t, 1)
    s = {"byte": 1, "u8": 1, "i8": 1, "word": 2, "i16": 2, "u16": 2, "dword": 4, "i32": 4, "u32": 4}.get(base, 2)
    return s * n


for line in open(sys.argv[1]):
    a, n, t = line.rstrip("\n").split("\t")
    a = int(a, 16)
    r = rows.get(a)
    cur = f"{r[1]} | {r[2]} | {r[3][:100]}" if r else "(no row)"
    print(f"=== 0x{a:x} -> {n} {t}")
    print(f"   current: {cur}")
    for x in by_address.get(a, []):
        mn = x.split()[1]
        print(f"   e2m: {x}  len/sign/type={lens.get(mn)}")
    sz = size_of(t)
    inside = [b for b in rows if a < b < a + sz]
    if inside:
        print("   rows inside: " + ", ".join(f"0x{b:x} {rows[b][1]} {rows[b][2]}" for b in sorted(inside)))
    e2m_inside = [b for b in by_address if a < b < a + sz]
    if e2m_inside:
        print("   e2m inside: " + "; ".join(f"0x{b:x} {by_address[b]}" for b in sorted(e2m_inside)))
    other = [x for x in names.get(n, []) if x != a]
    if other:
        print(f"   NAME COLLISION with {[hex(x) for x in other]}")
    out = subprocess.run(["python3", "/home/linux/.claude/jobs/374b0424/tmp/w15/r93/tools/abs_refs.py", REPO, hex(a)],
                         capture_output=True, text=True).stdout
    refs = [ln.strip() for ln in out.splitlines() if ln.startswith("  0x")]
    print(f"   refs ({len(refs)}): " + " || ".join(re.sub(r"prev words [0-9a-f ]+\| ", "", x) for x in refs[:16]))

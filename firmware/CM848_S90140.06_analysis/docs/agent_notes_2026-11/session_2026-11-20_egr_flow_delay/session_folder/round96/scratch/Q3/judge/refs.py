"""usage: refs.py <start hex> <end hex> : disassemble the CM550 range and list every 0x80xxxx / 0xffxxxx address
it references, with the CM550 global row (name, type, first 140 chars of comment) and the e2m record(s) there."""
import re
import subprocess
import sys

sys.path.insert(0, "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/scripts")
import e2m_block_addresses as e  # noqa: E402

REPO = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay"
ROM = REPO + "/firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin"
GLOBALS = "/home/linux/.claude/jobs/374b0424/tmp/w15/r96/frozen/cm550/global_variables.csv"

rows = {}
for line in open(GLOBALS, errors="replace"):
    if line.startswith("0x"):
        parts = line.rstrip("\n").split(",", 3)
        while len(parts) < 4:
            parts.append("")
        rows[int(parts[0], 16)] = (parts[1], parts[2], parts[3])

table = e.parse_cm550_table(open(ROM, "rb").read())
by_address = {}
for name, unit, block, offset, description in e.parse_e2m_storage(REPO + "/e2m-analysis/originals/v64t6_s.e2m"):
    base = table.get(block)
    if base is None:
        continue
    address = e.cm550_ram_address(base) + offset
    by_address.setdefault(address, []).append(f"{block:04X}+{offset:X} {name} [{unit}] {description[:80]}")


def describe(a):
    r = rows.get(a)
    if r is None:
        # nearest typed row below
        below = [b for b in rows if a - 64 < b < a]
        near = f" (inside? nearest row below 0x{max(below):x} {rows[max(below)][0]} {rows[max(below)][1]})" if below else ""
        name = "(no row)" + near
    else:
        name = f"{r[0]} {r[1]} | {r[2][:140]}"
    recs = "; ".join(by_address.get(a, []))
    return f"0x{a:06x} {name}" + (f"\n      e2m: {recs}" if recs else "")


if __name__ == "__main__":
    out = subprocess.run(["python3", "/home/linux/.claude/jobs/374b0424/tmp/w15/r93/tools/m68k.py", ROM, sys.argv[1], sys.argv[2]],
                         capture_output=True, text=True).stdout
    seen = []
    for m in re.finditer(r"0x(8[0-9a-f]{5}|ff[0-9a-f]{4})\b", out):
        a = int(m.group(1), 16)
        if a not in seen:
            seen.append(a)
    for a in sorted(seen):
        print(describe(a))

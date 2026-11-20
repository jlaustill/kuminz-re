"""For every bin row: the table-resolved e2m records covering its bytes, with e2m size (column 8).
usage: addr_records.py"""
import json
import subprocess
import sys

REPO = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-fueling-state-enum"
E2M = REPO + "/e2m-analysis/CHR/CHR_CC_11.45.01.07.e2m"
TOOL = REPO + "/firmware/scripts/e2m_block_addresses.py"
sizes = {}
for line in open(E2M, errors="replace"):
    f = line.rstrip("\r\n").split(";")[0].split(",")
    if len(f) > 9:
        sizes.setdefault((f[0], f[2].upper(), f[3].upper()), f[7])
bin_ = json.load(open("/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage9/bins/globals4.json"))
for i, it in enumerate(bin_):
    a = int(it["address"], 16)
    width = it.get("row_width_bytes") or 2
    seen = []
    for off in range(0, max(width, 1)):
        out = subprocess.run([sys.executable, TOOL, "--address", f"0x{a + off:x}"], capture_output=True, text=True).stdout
        for l in out.splitlines():
            if l.strip() and l not in seen:
                seen.append(l)
    print(f"[{i}] {it['address']} {it['current_name']} (row {width} B, listed {len(it['e2m_records_here'])})")
    for l in seen:
        parts = l.split()
        blk, off = parts[0], parts[1].lstrip("+")
        name = parts[2]
        size = sizes.get((name, blk.upper(), off.upper().zfill(4)), "?")
        print(f"      {l[:170]}  [e2m size {size}]")

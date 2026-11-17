#!/usr/bin/env python3
"""Cross-check: table addresses loaded into the argument registers right before each
call to a table interpolator, from the ROM / flash2 disassembly. Prints a CSV of
(call_site, callee, role, table_address). Usage: disasm_tables.py <analysis_dir> <out_csv>"""
import csv
import re
import subprocess
import sys

ANALYSIS, OUT = sys.argv[1], sys.argv[2]
CALLEES = {
    0x55ef4: ("lookupTableInterpolation", {"r5": "x", "r6": "y"}),
    0x15d2c: ("cm848_interpolateTableWithoutCache", {"r4": "x", "r5": "y"}),
    0x566cc: ("cm848_dualAxisTableInterpolation", {"r5": "x", "r7": "y2d", "r8": "z"}),
    0x15e08: ("cm848_interpolateFuelMapTable", {"r5": "x", "r6": "y", "r7": "x2", "r8": "y2", "r9": "y3", "r10": "y4"}),
    0x5012dc: ("sensorChannelTypeB_configInit", {"r6": "x", "r7": "y"}),
    0x501b4c: ("sensorChannelTypeB_update", {"r6": "x", "r7": "y"}),
    0x500234: ("sensorChannelConfigInit", {"r6": "x", "r7": "y"}),
    0x500a4c: ("updateSensorChannelWithConfig", {"r6": "x", "r7": "y"}),
}
IMAGES = [("cm848_rom.bin", 0x0, 0x70000), ("cm848_flash2_live.bin", 0x500000, 0x53E000)]
INS = re.compile(r"^\s*([0-9a-f]+):\s+(?:[0-9a-f]{2} ){4}\s*(\S+)\s*(.*)$")

def s16(v):
    v &= 0xFFFF
    return v - 0x10000 if v & 0x8000 else v

rows = []
for image, base, end in IMAGES:
    out = subprocess.run(
        ["powerpc-linux-gnu-objdump", "-D", "-b", "binary", "-m", "powerpc", "-EB",
         f"--adjust-vma={base:#x}", f"{ANALYSIS}/originals/{image}"],
        capture_output=True, text=True, check=True).stdout
    window = []   # recent (addr, mnemonic, operands)
    for line in out.splitlines():
        m = INS.match(line)
        if not m:
            continue
        addr, mnem, ops = int(m.group(1), 16), m.group(2), m.group(3).split("#")[0].strip()
        if addr >= end:
            break
        if mnem in ("bl",):
            t = re.match(r"0x([0-9a-f]+)", ops)
            if t and int(t.group(1), 16) in CALLEES:
                callee, regs = CALLEES[int(t.group(1), 16)]
                for reg, role in regs.items():
                    # walk back to the latest definition of reg
                    value = None
                    for (_, mn, op) in reversed(window[-24:]):
                        parts = [p.strip() for p in op.split(",")]
                        if not parts or parts[0] != reg:
                            continue
                        if mn == "addi" and len(parts) == 3:
                            src, imm = parts[1], int(parts[2], 0)
                            # find lis of src before this point
                            hi = None
                            for (_, mn2, op2) in reversed(window[-24:]):
                                p2 = [p.strip() for p in op2.split(",")]
                                if mn2 == "lis" and p2[0] == src:
                                    hi = int(p2[1], 0); break
                            if hi is not None:
                                value = ((hi << 16) + s16(imm)) & 0xFFFFFFFF
                        elif mn == "lis":
                            value = (int(parts[1], 0) << 16) & 0xFFFFFFFF
                        break
                    rows.append({"call_site": f"0x{addr:x}", "callee": callee, "role": role,
                                 "table": f"0x{value:08x}" if value is not None else ""})
            window = []
            continue
        window.append((addr, mnem, ops))
        if mnem in ("b", "blr", "bctr", "bctrl") or mnem.startswith("b") and mnem not in ("bl",):
            # conditional or unconditional branches end straight-line argument setup
            window = []

with open(OUT, "w", newline="") as f:
    w = csv.DictWriter(f, fieldnames=["call_site", "callee", "role", "table"])
    w.writeheader(); w.writerows(rows)
resolved = [r for r in rows if r["table"]]
print(f"call-site args: {len(rows)}  resolved: {len(resolved)}  distinct tables: {len({r['table'] for r in resolved})}")

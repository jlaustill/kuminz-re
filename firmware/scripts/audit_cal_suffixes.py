#!/usr/bin/env python3
"""Audit `_cal` suffixes in a firmware global_variables.csv against the memory map.

The project rule (firmware/CLAUDE.md, investigate-firmware-symbol skill):
    `_cal` = EEPROM-backed (Calterm-tunable WITHOUT a reflash) ONLY.
    ROM / Bank2 flash / the ROM->RAM copy window / computed working RAM are NOT `_cal`.
    On CM848, EEPROM only shadows into the 0x3FEExx RAM block.

This script does the MECHANICAL half: classify each address by region and report names
whose `_cal` presence/absence contradicts the region. It does NOT edit anything and it
does NOT decide borderline cases for you -- the Bank1-ROM calibration block is a genuine
judgment call (those constants ARE reflashed by Calterm), so it is reported as a SOFT
contradiction for a human to adjudicate, separate from the HARD ones.

Usage:
    python3 audit_cal_suffixes.py <global_variables.csv> [--firmware cm848|cm550]

Exit status is always 0 (reporting tool). Output groups:
    HARD   `_cal` on working-RAM / ROM->RAM / Bank2-flash / HW-reg  -> almost certainly wrong
    SOFT   `_cal` on Bank1 ROM/flash constants                      -> rule says no, but reflash-cal; you decide
    MISSING EEPROM-direct or 0x3FEExx shadow WITHOUT `_cal`         -> probably should have it
"""
import csv
import sys


# --- Memory-map regions. (lo, hi) inclusive-exclusive, plus whether `_cal` is allowed. ---
# CM848 (PowerPC MPC555). CM550 (m68k) differs; see --firmware below.
CM848_REGIONS = [
    # name,            lo,           hi,           cal_ok,  kind
    ("EEPROM",        0x01000000,   0x01001000,   True,    "eeprom"),       # direct EEPROM
    ("EEPROM_SHADOW", 0x003FEE00,   0x003FEF00,   True,    "eeprom"),       # RAM block EEPROM shadows into
    ("ROM_TO_RAM",    0x003F9800,   0x003FDB30,   False,   "code_image"),   # boot-copied ROM code/data image
    ("HW_REG",        0x00300000,   0x00310000,   False,   "hw"),           # QADC / MPC555 peripheral regs
    ("BANK1_ROM",     0x00000000,   0x00070000,   False,   "rom"),          # Bank1 flash (incl. cal constants)
    ("BANK2_FLASH",   0x00500000,   0x0053E000,   False,   "flash"),        # Bank2 flash
    # everything else in 0x0030xxxx-0x0040xxxx that isn't matched above = working RAM
]

CM550_REGIONS = [
    ("EEPROM",        0x01000000,   0x01001000,   True,    "eeprom"),
    ("ROM",           0x00000000,   0x00040000,   False,   "rom"),
    ("RAM",           0x00800000,   0x00809200,   False,   "ram"),
    ("EXT_RAM",       0x008091C2,   0x00810000,   False,   "ram"),
]


def classify(addr, regions):
    for name, lo, hi, cal_ok, kind in regions:
        if lo <= addr < hi:
            return name, cal_ok, kind
    return "WORKING_RAM", False, "ram"   # default: computed/working RAM, never _cal


def is_default_name(name):
    """Ghidra default / placeholder names that aren't real curated names."""
    return (name.startswith(("DAT_", "_DAT_", "u_", "u__", "uRam", "switchD",
                             "caseD", "PTR_DAT_", "FUN_", "SUB_"))
            or name in ("", "default"))


def main():
    if len(sys.argv) < 2:
        print(__doc__)
        sys.exit(0)
    path = sys.argv[1]
    fw = "cm848"
    if "--firmware" in sys.argv:
        fw = sys.argv[sys.argv.index("--firmware") + 1]
    regions = CM550_REGIONS if fw == "cm550" else CM848_REGIONS

    hard, soft, missing = [], [], []
    total = 0
    for row in csv.reader(open(path)):
        if not row or row[0].startswith("#") or row[0] == "address":
            continue
        try:
            addr = int(row[0], 16)
        except ValueError:
            continue
        name = row[1].strip() if len(row) > 1 else ""
        total += 1
        region, cal_ok, kind = classify(addr, regions)
        has_cal = name.endswith("_cal")

        if has_cal and not cal_ok:
            (soft if kind in ("rom", "flash") else hard).append((row[0], name, region))
        elif cal_ok and not has_cal and not is_default_name(name):
            missing.append((row[0], name, region))

    def dump(title, rows):
        print(f"\n=== {title} ({len(rows)}) ===")
        for a, n, r in sorted(rows):
            print(f"  {a:<12} {r:<14} {n}")

    print(f"Audited {total} named entries in {path}  (firmware={fw})")
    dump("HARD contradictions: _cal on non-calibration memory (likely wrong)", hard)
    dump("SOFT contradictions: _cal on ROM/flash constants (rule says no; reflash-cal? you decide)", soft)
    dump("MISSING _cal: EEPROM-backed name without _cal suffix", missing)
    print(f"\nSummary: {len(hard)} hard, {len(soft)} soft, {len(missing)} missing. "
          f"No files were modified.")


if __name__ == "__main__":
    main()

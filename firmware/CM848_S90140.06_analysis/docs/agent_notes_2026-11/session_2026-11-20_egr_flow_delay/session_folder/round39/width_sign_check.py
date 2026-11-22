"""Round 39 closing: (a) words of RAM 0x3feed0-0x40a048 that differ from ROM at RAM - 0x39a3e6; (b) every round 39 row
named from an e2m record: the record's size (column 8) and sign (column 10) against the CSV type.
usage: width_sign_check.py <repo> <address>..."""
import os
import re
import subprocess
import sys

repo = os.path.abspath(sys.argv[1])
fw = os.path.join(repo, "firmware")
d = os.path.join(fw, "CM848_S90140.06_analysis")
ram = open(os.path.join(d, "originals/cm848_ram.bin"), "rb").read()
rom = open(os.path.join(d, "originals/cm848_rom.bin"), "rb").read()
diff = [a for a in range(0x3feed0, 0x40a04a, 2) if ram[a - 0x3FA000:a - 0x3FA000 + 2] != rom[a - 0x39a3e6:a - 0x39a3e6 + 2]]
print(f"(a) 0x3feed0-0x40a048: {len(diff)} of {(0x40a04a - 0x3feed0) // 2} words differ; first: "
      + " ".join(hex(a) for a in diff[:12]))
e2m = {}
for l in open(os.path.join(repo, "e2m-analysis/CHR/CHR_CC_11.45.01.07.e2m"), errors="replace"):
    p = l.split(",")
    if len(p) > 10:
        e2m.setdefault(p[0], (p[7], p[9]))
rows = {}
for l in open(os.path.join(d, "output/global_variables.csv"), errors="replace"):
    p = l.split(",", 3)
    if len(p) >= 3 and p[0].startswith("0x"):
        rows[int(p[0], 16)] = (p[1], p[2])
WIDTH = {"byte": 1, "word": 2, "i16": 2, "dword": 4, "i32": 4}
for a in sys.argv[2:]:
    out = subprocess.run(["python3", os.path.join(fw, "scripts/e2m_block_addresses.py"), "--address", a],
                         capture_output=True, text=True, cwd=fw).stdout.strip().splitlines()
    if not out:
        print(f"{a}: no record")
        continue
    rec = out[0].split()[2]
    size, sign = e2m.get(rec, ("?", "?"))
    name, typ = rows.get(int(a, 16), ("?", "?"))
    base = re.sub(r"\[\d+\]$", "", typ)
    w = WIDTH.get(base, "?")
    flag = ""
    if str(w) != size:
        flag += " WIDTH"
    if (sign == "S") != (base in ("i16", "i32")) and "[" not in typ:
        flag += " SIGN"
    print(f"{a} {name} {typ}: e2m {rec} size {size} {sign}{flag}")

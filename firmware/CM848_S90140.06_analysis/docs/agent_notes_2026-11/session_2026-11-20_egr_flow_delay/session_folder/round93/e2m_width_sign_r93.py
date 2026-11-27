"""Round 93 (read-only): a third witness for the typed rows - the Calterm file. For every CM550 e2m record with
storage of type N (a plain value), its RAM address (through the ECU's parameter ID table), its length in bytes
(column 8) and its sign flag (column 10: U / S). For each row of <pass.csv>:
- WIDTH: the record length against the typed width (a mismatch must be looked at);
- SIGN: S records whose row is typed unsigned are written to <out.csv> (address,name,type,new_type).
usage: e2m_width_sign_r93.py <repo> <pass.csv> <signed_by_cast.csv> <out.csv>"""
import csv
import importlib.util
import os
import sys

repo, passed, by_cast, out = os.path.abspath(sys.argv[1]), sys.argv[2], sys.argv[3], sys.argv[4]
spec = importlib.util.spec_from_file_location("eba", os.path.join(repo, "firmware/scripts/e2m_block_addresses.py"))
eba = importlib.util.module_from_spec(spec)
spec.loader.exec_module(eba)
rom = open(os.path.join(repo, "firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin"), "rb").read()
table = eba.parse_cm550_table(rom)
records = {}          # address -> list of (mnemonic, length, sign)
for line in open(os.path.join(repo, "e2m-analysis/originals/v64t6_s.e2m"), errors="replace"):
    f = line.split(";", 1)[0].rstrip("\r\n").split(",")
    if len(f) < 10 or f[5].strip() != "N":
        continue
    try:
        block, offset, length = int(f[2], 16), int(f[3], 16), int(f[7])
    except ValueError:
        continue
    base = table.get(block) if isinstance(table, dict) else None
    if base is None:
        continue
    address = eba.cm550_ram_address(base + offset)
    records.setdefault(address, []).append((f[0], length, f[9].strip()))
WIDTH = {"byte": 1, "word": 2, "dword": 4}
cast_signed = {r["address"].lower() for r in csv.DictReader(open(by_cast))}
match = mismatch = none = 0
rows = []
for r in csv.DictReader(open(passed)):
    a = int(r["address"], 16)
    recs = records.get(a)
    if not recs:
        none += 1
        continue
    lengths = {l for _, l, _ in recs}
    signs = {s for _, _, s in recs}
    if lengths == {WIDTH[r["type"]]}:
        match += 1
    else:
        mismatch += 1
        print(f"WIDTH MISMATCH {r['address']} {r['name']}: typed {r['type']}, e2m {recs}")
    if signs == {"S"} and r["type"] != "byte" and r["address"].lower() not in cast_signed:
        rows.append((r["address"], r["name"], r["type"], "i16" if r["type"] == "word" else "i32", "/".join(m for m, _, _ in recs)))
    if signs == {"U"} and r["address"].lower() in cast_signed:
        print(f"SIGN DISAGREES {r['address']} {r['name']}: casts say signed, e2m {recs} says unsigned")
with open(out, "w") as fh:
    fh.write("address,name,type,new_type,record\n")
    for row in rows:
        fh.write(",".join(row) + "\n")
print(f"typed rows with an e2m N record: {match} width matches, {mismatch} mismatches; {none} rows have no N record; "
      f"{len(rows)} more rows are signed by their record")

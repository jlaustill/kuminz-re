"""Round 93 (read-only): a second typing pass for CM550 rows still typed 'undefined' - the rows the first pass
could not prove from direct ROM accesses. Witness 1 is the Calterm file: the row's address holds plain-value (N)
records that all give one length (1 / 2 / 4 bytes) and one sign. (For the 419 rows of the first pass that have such
a record, the length matched the ROM-proven width in 418.) A row is a candidate when
- its N records agree on length and sign, and no S / B / T record sits on the address (a bit or a table),
- the next row starts at or after address + length,
- no ROM access contradicts it: every DECODED direct access has that width and nothing accesses the bytes inside,
- the decompiler does not contradict it: a 2 / 4 byte row never prints plain, a 1 byte row never with an underscore.
Writes address,name,type,record,renders. usage: e2m_type_candidates_r93.py <repo> <out.csv>"""
import csv
import importlib.util
import os
import re
import sys

repo, out = os.path.abspath(sys.argv[1]), sys.argv[2]
here = os.path.dirname(os.path.abspath(__file__))
spec = importlib.util.spec_from_file_location("scan", os.path.join(here, "untyped_width_scan_r93.py"))
# reuse the scan's instruction classifier without running its main part: load its source up to the output section
src = open(os.path.join(here, "untyped_width_scan_r93.py")).read().split("WIDTH = {")[0]
ns = {"__name__": "scan", "sys": type("S", (), {"argv": ["x", repo, os.devnull]})}
exec(compile(src.replace("repo, out = os.path.abspath(sys.argv[1]), sys.argv[2]", f"repo, out = {repo!r}, os.devnull"), "scan", "exec"), ns)
occ, classify, rows = ns["occ"], ns["classify"], ns["rows"]
spec = importlib.util.spec_from_file_location("eba", os.path.join(repo, "firmware/scripts/e2m_block_addresses.py"))
eba = importlib.util.module_from_spec(spec)
spec.loader.exec_module(eba)
rom = ns["rom"]
table = eba.parse_cm550_table(rom)
records, other = {}, set()
for line in open(os.path.join(repo, "e2m-analysis/originals/v64t6_s.e2m"), errors="replace"):
    f = line.split(";", 1)[0].rstrip("\r\n").split(",")
    if len(f) < 10:
        continue
    try:
        block, offset = int(f[2], 16), int(f[3], 16)
    except ValueError:
        continue
    base = table.get(block)
    if base is None or block == 0:        # block 0 = the tool's system records (ECM_ID ...): not a storage layout
        continue
    address = eba.cm550_ram_address(base + offset)
    kind = f[5].strip()
    if kind == "N":
        try:
            records.setdefault(address, []).append((f[0], int(f[7]), f[9].strip()))
        except ValueError:
            pass
    elif kind in ("S", "B", "T", "X", "Y", "Z"):
        other.add(address)
cpp = open(os.path.join(repo, "firmware/CM550_J90350.00_analysis/output/J90350.00.ghidra.cpp"), errors="replace").read()
code = re.sub(r"/\*.*?\*/", " ", cpp, flags=re.S)
code = "\n".join(l for l in code.split("\n") if not l.lstrip().startswith("//"))
words = {}
for m in re.finditer(r"[A-Za-z_][A-Za-z0-9_]*", code):
    words[m.group(0)] = words.get(m.group(0), 0) + 1
TYPE = {(1, "U"): "byte", (1, "S"): "i8", (2, "U"): "word", (2, "S"): "i16", (4, "U"): "dword", (4, "S"): "i32"}
SIZE = {"b": 1, "w": 2, "l": 4}
addresses = [r[0] for r in rows]
why, passed = {}, []
for k, (a, name, typ) in enumerate(rows):
    if typ != "undefined" or not name:
        continue
    recs = records.get(a)
    if not recs:
        continue
    lengths, signs = {l for _, l, _ in recs}, {s for _, _, s in recs}
    reason = None
    if len(lengths) != 1 or len(signs) != 1 or (next(iter(lengths)), next(iter(signs))) not in TYPE:
        reason = "records disagree or odd length"
    elif a in other:
        reason = "a bit / table record on the address"
    else:
        length = next(iter(lengths))
        nxt = addresses[k + 1] if k + 1 < len(addresses) else a + 8
        sizes = [classify(i) for i in occ.get(a, [])]
        if nxt < a + length:
            reason = "next row overlaps"
        elif any(s is not None and SIZE[s] != length for s in sizes):
            reason = "a ROM access has another width"
        elif any(occ.get(a + d) for d in range(1, length)):
            reason = "an access inside the width"
        else:
            under, plain = words.get("_" + name, 0), words.get(name, 0)
            if length == 1 and under:
                reason = "byte record but printed with an underscore"
            elif length > 1 and plain:
                reason = "wide record but printed plain"
    if reason:
        why[reason] = why.get(reason, 0) + 1
        continue
    length = next(iter(lengths))
    passed.append((f"0x{a:08x}", name, TYPE[(length, next(iter(signs)))], "/".join(m for m, _, _ in recs),
                   words.get("_" + name, 0) + words.get(name, 0)))
with open(out, "w") as fh:
    fh.write("address,name,type,record,renders\n")
    for row in passed:
        fh.write(",".join(str(x) for x in row) + "\n")
by = {}
for _, _, t, _, n in passed:
    by.setdefault(t, [0, 0, 0])
    by[t][0] += 1
    by[t][1] += n
    by[t][2] += 1 if n else 0
print("candidates:", {t: f"{v[0]} rows ({v[2]} in the code, {v[1]} renders)" for t, v in sorted(by.items())}, "total", len(passed))
print("left out:", why)

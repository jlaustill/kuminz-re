"""Round 90 (read-only): resolve CM550 e2m records with the ECU's own parameter ID table and compare them with the
CSV rows at their addresses. CM550's table is output/parameter_id_lookup_table.csv (id -> address; the e2m block id is
column 3 of a record, so a record's address is table[block] + column 4, as CM848's e2m_block_addresses.py does).
Round 89 proved the layout for blocks 1003 / 1004 against v64t6_s.e2m. Kinds per resolved record:
  no_row      no global row starts at the address (it may sit inside a typed row: see 'inside')
  inside      the address is inside a struct instance / array row (field path given)
  unnamed     a row with an empty name or a placeholder name (unnamed_data_ / DAT_ / *_param mnemonic stubs)
  named       a named row
usage: cm550_e2m_census_r90.py <repo> <e2m file> <out.tsv>"""
import collections
import csv
import os
import re
import sys

repo, e2m_path, out = sys.argv[1], sys.argv[2], sys.argv[3]
O = os.path.join(repo, "firmware/CM550_J90350.00_analysis/output")
table = {}
for r in csv.DictReader(open(os.path.join(O, "parameter_id_lookup_table.csv"), newline="")):
    table[int(r["param_id_hex"], 16)] = int(r["address_hex"], 16)
rows = {}
for r in csv.reader(open(os.path.join(O, "global_variables.csv"), newline="")):
    if r and r[0].startswith("0x"):
        rows[int(r[0], 16)] = (r[1], r[2], r[3] if len(r) > 3 else "")
sizes, fields = {}, {}
for r in csv.reader(open(os.path.join(O, "structure_definitions.csv"), newline="")):
    if len(r) < 5 or r[0].startswith("#") or r[0] == "struct_name" or not r[2]:
        continue
    try:
        z = int(r[4])
    except ValueError:
        continue
    off = sum(x[2] for x in fields.get(r[0], []))
    fields.setdefault(r[0], []).append((r[2], off, z))
for k, v in fields.items():
    sizes[k] = sum(x[2] for x in v)
SCALAR = {"byte": 1, "char": 1, "bool": 1, "word": 2, "i16": 2, "short": 2, "ushort": 2, "dword": 4, "i32": 4,
          "uint": 4, "int": 4, "pointer": 4, "float": 4}


def type_size(t):
    t = t.strip()
    m = re.match(r"^(.+?)\s*\[(\d+)\]$", t)
    if m:
        e = type_size(m.group(1))
        return e * int(m.group(2)) if e else 0
    if t.endswith("*"):
        return 4
    return sizes.get(t, SCALAR.get(t, 0))


starts = sorted(rows)


def covering(a):
    """The typed row whose bytes cover a (not starting at a): (base, name, type, path)."""
    import bisect
    i = bisect.bisect_right(starts, a) - 1
    while i >= 0 and a - starts[i] < 4096:
        b = starts[i]
        name, typ, _ = rows[b]
        z = type_size(typ)
        if b < a < b + z:
            off = a - b
            path = f"+{off}"
            base_t = re.sub(r"\s*\[\d+\]$", "", typ)
            if base_t in fields:
                st = sizes[base_t]
                idx, rem = divmod(off, st) if st else (0, off)
                fp = next((f"{f}" if o == rem else f"{f}+{rem - o}" for f, o, s in fields[base_t] if o <= rem < o + s),
                          f"+{rem}")
                path = (f"[{idx}]." if typ.endswith("]") else ".") + fp
            elif typ.endswith("]"):
                e = type_size(base_t) or 1
                path = f"[{off // e}]" + (f"+{off % e}" if off % e else "")
            return b, name, typ, path
        if z and b + z <= a and i < len(starts) - 1:
            pass
        i -= 1
    return None


PLACEHOLDER = re.compile(r"^(unnamed_data_[0-9a-f]+|DAT_[0-9a-f]+|[a-z0-9]+_param|[A-Z0-9]{4,10})$")
records = []
for raw in open(e2m_path, encoding="latin-1"):
    data, _, comment = raw.rstrip("\r\n").partition(";")
    c = data.split(",")
    if len(c) < 12:
        continue
    try:
        block, offset = int(c[2], 16), int(c[3], 16)
    except ValueError:
        continue
    if block not in table:
        continue
    a = table[block] + offset
    kind, current, typ, path = "no_row", "", "", ""
    if a in rows:
        current, typ, _ = rows[a]
        kind = "unnamed" if (not current or PLACEHOLDER.match(current)) else "named"
    else:
        cov = covering(a)
        if cov:
            kind, current, typ, path = "inside", cov[1], cov[2], cov[3]
    records.append((c[0], c[2], c[3], f"0x{a:08x}", c[1], c[5], c[7], c[9], c[10], comment.strip(), kind, current,
                    typ, path))
count = collections.Counter(r[10] for r in records)
blocks = len({r[1] for r in records})
print(f"{len(records)} records resolved in {blocks} blocks:", dict(count))
with open(out, "w") as fh:
    fh.write("name\tblock\toffset\taddress\tunit\ttype\tlength\tsigned\tscale\tcomment\tkind\tcurrent\tcurrent_type\tpath\n")
    for r in sorted(records, key=lambda r: r[3]):
        fh.write("\t".join(r) + "\n")

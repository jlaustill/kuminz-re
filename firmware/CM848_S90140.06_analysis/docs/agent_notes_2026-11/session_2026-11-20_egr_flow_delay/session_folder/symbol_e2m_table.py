"""For each function: the globals its code uses, each with its CSV row and the e2m record(s) the ECU's parameter ID
table resolves at that address (from an e2m_name_audit.py output).
Usage: symbol_e2m_table.py <cpp> <global_variables.csv> <audit.csv> <function>...
A function argument may be a name or a 0x address."""
import csv
import re
import sys

cpp, gv_path, audit_path, *functions = sys.argv[1:]
text = open(cpp).read()
rows = {}
for r in csv.reader(open(gv_path)):
    if len(r) > 2 and r[0].startswith("0x"):
        rows.setdefault(r[1], (int(r[0], 16), r[2], r[3] if len(r) > 3 else "")) if r[1] else None
by_addr = {}
for r in csv.DictReader(open(audit_path)):
    by_addr.setdefault(int(r["address"], 16), []).append(r)
row_at = {}
for r in csv.reader(open(gv_path)):
    if len(r) > 2 and r[0].startswith("0x"):
        row_at[int(r[0], 16)] = r
heads = [(m.start(), m.group(1), m.group(2)) for m in re.finditer(r"(?m)^// Function: (\S+) @ (0x[0-9a-f]+)", text)]


def body(fn):
    for i, (pos, name, addr) in enumerate(heads):
        if fn in (name, addr) or (fn.startswith("0x") and int(fn, 16) == int(addr, 16)):
            end = heads[i + 1][0] if i + 1 < len(heads) else len(text)
            return name, addr, text[pos:end]
    return None, None, ""


for fn in functions:
    name, addr, b = body(fn)
    if not name:
        print(f"## {fn}: not found")
        continue
    code = re.sub(r"/\*.*?\*/", "", b, flags=re.S)
    code = re.sub(r"//[^\n]*", "", code)
    idents = sorted(set(re.findall(r"\b[A-Za-z_]\w*\b", code)))
    print(f"## {name} @ {addr}")
    for ident in idents:
        a = None
        if ident in rows:
            a, typ, comment = rows[ident]
        else:
            m = re.fullmatch(r"(?:DAT|WORD|BYTE|uRam|PTR_DAT|WORD_ARRAY|DWORD)_?([0-9a-f]{8})", ident)
            if m:
                a = int(m.group(1), 16)
                typ = row_at.get(a, ["", "", "(no row)"])[2]
        if a is None:
            continue
        recs = by_addr.get(a, [])
        e2m = "; ".join(f"{r['block']} +{r['offset']} {r['record']} [{r['size']}B {r['signed']}] '{r['description'][:70]}'"
                        for r in recs) or "-"
        print(f"  0x{a:08x} {ident} [{typ}] -> {e2m}")

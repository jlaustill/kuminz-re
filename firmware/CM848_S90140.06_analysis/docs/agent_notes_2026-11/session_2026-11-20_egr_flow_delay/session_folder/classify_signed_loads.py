"""Signedness sweep: for each named word row whose table-resolved e2m record is a signed 2-byte value, collect every
load of its address in every referencing function (xref_addr / disasm_func access detector) and classify it:
  lha-only  -> i16 candidate (the compiler sign-extends every load)
  has-lhz   -> keep word (at least one zero-extending load)
  no-load   -> skip (only stores, or reached through a pointer)
Usage: classify_signed_loads.py <firmware scripts dir> <audit.csv> <out.csv>"""
import csv
import functools
import re
import sys

scripts, audit_path, out_path = sys.argv[1:4]
sys.path.insert(0, scripts)
import disasm_func as D  # noqa: E402
import xref_addr as X  # noqa: E402

rows = [r for r in csv.DictReader(open(audit_path))
        if r["status"] == "named" and r["row_type"] == "word" and r["signed"] == "S" and r["size"] == "2"
        and not r["inside"]]
funcs = D.function_table()


@functools.lru_cache(maxsize=None)
def window_lines(start):
    s, stop = D.func_window(start, funcs)
    lines, _ = D.objdump(s, stop)
    return lines


MNEMONIC = re.compile(r"\t(l[bhw][az]?x?|lha|lhz|lhax|lhzx|lhau|lhzu|st[bhw]x?|stbu|sthu|stwu)\s")
results = []
for i, r in enumerate(rows):
    addr = int(r["address"], 16)
    name, refs = X.referencing_functions(addr)
    loads, stores = [], 0
    for start, fname in refs:
        hits, _ = D.find_accesses(window_lines(start), addr)
        for kind, ln, width in hits:
            if kind == "load":
                m = re.search(r"\t(lhau|lhzu|lhax|lhzx|lha|lhz|lwz|lbz)\b", ln)
                loads.append((fname, m.group(1) if m else "?"))
            elif kind == "store":
                stores += 1
    kinds = {k for _, k in loads}
    if not loads:
        verdict = "no-load"
    elif kinds <= {"lha", "lhax", "lhau"}:
        verdict = "lha-only"
    else:
        verdict = "has-" + "/".join(sorted(kinds - {"lha", "lhax", "lhau"}))
    results.append({"address": r["address"], "name": r["row_name"], "record": f"{r['block']} +{r['offset']} {r['record']}",
                    "verdict": verdict, "loads": len(loads), "stores": stores,
                    "functions": ";".join(sorted({f for f, _ in loads}))})
    if i % 50 == 0:
        print(f"{i}/{len(rows)}", file=sys.stderr)
with open(out_path, "w", newline="") as f:
    w = csv.DictWriter(f, fieldnames=list(results[0]), lineterminator="\n")
    w.writeheader()
    w.writerows(results)
from collections import Counter  # noqa: E402
print(Counter(r["verdict"] for r in results))

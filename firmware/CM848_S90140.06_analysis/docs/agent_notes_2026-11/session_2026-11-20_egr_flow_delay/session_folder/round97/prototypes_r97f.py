"""Round 97 stage F: function_definitions.csv rows for the judged prototypes of batches R5 / R6 (CONFIRMED: the
proposal's return type and parameters; the three AMENDED R6 prototypes are written here from the judge's text).
A function's existing rows are replaced by its new row set (the CM550 stack layout places every parameter from its
row, so the set is complete). Comments take ';' for commas (parseCSVLine splits on every comma). Function names come
from function_renames.csv as it stands after the apply. usage: prototypes_r97f.py <repo> <batch.json>..."""
import collections
import json
import os
import re
import sys

repo, batch_paths = os.path.abspath(sys.argv[1]), sys.argv[2:]
OUT = {"CM550": os.path.join(repo, "firmware/CM550_J90350.00_analysis/output"),
       "CM848": os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")}
R = "(PR #53 round 97)"
AMENDED = {   # R6's three amended prototypes, from its judge's final_comment
    ("CM550", 0x1192a): {"keep_return": True, "params": [
        (0, "request", "can_standard_receive_descriptor_t*", "The PGN 61184 request to answer - the long at +4 (move.l (8;a6);-(sp) at 0x119fa after link) passed unchanged to cm550_diagnosticMultiPacketResponseBuilder when acknowledge_datalink is 0 and not dereferenced here; handleJ1939RestartService passes its own request and cm550_restartThroughBootRomAfterJ1708Request passes NULL (clr.l) because it acknowledges on J1708 (was dword)"),
        (1, None, None, None)]},     # keep the existing row 1
    ("CM550", 0x31b22): {"return": ("void", "No result - d0 is cm550_sendCanMessage's leftover and none of the three callers reads it"),
                         "params": [(0, "request", "can_standard_receive_descriptor_t*", None)]},
    ("CM550", 0x2ed6a): {"return": ("byte", "link a6;#-4 holds a local only and no stack argument is read; it returns moveq #2 / #3 / #20 / the count + 2 / clr.b and its caller keeps the low byte (move.b d0;d2 / beq at 0x1e9d0)"),
                         "params": []},
}


def clean(s):
    return re.sub(r"\s+", " ", (s or "").replace(",", ";")).strip()


names = {fw: {} for fw in OUT}
for fw, d in OUT.items():
    for line in open(os.path.join(d, "function_renames.csv"), newline=""):
        p = line.rstrip("\r\n").split(",", 2)
        if len(p) > 1 and p[0].startswith("0x"):
            names[fw][int(p[0], 16)] = p[1]
plans = collections.defaultdict(dict)
for path in batch_paths:
    b = json.load(open(path))
    vd = {}
    for x in b["verdict"]["verdicts"]:
        if x.get("kind") == "prototype":
            vd[int(str(x["address"]), 16)] = x
    for p in b["proposal"].get("prototypes") or []:
        fw = p["firmware"]
        a = int(p["address"], 16)
        v = vd.get(a) or {}
        if v.get("verdict") not in ("CONFIRMED", "AMENDED"):
            print("SKIP (no verdict / refuted)", fw, hex(a))
            continue
        plans[fw][a] = (p, v, b["batch"])
total = 0
for fw, plan in plans.items():
    path = os.path.join(OUT[fw], "function_definitions.csv")
    t = open(path, newline="").read()
    E = "\r\n" if "\r\n" in t else "\n"
    lines = t.split(E)
    existing = collections.defaultdict(list)
    for i, l in enumerate(lines):
        q = l.split(",", 5)
        if len(q) > 4 and q[0].startswith("0x"):
            existing[int(q[0], 16)].append((i, q))
    new_rows, drop = [], set()
    for a, (p, v, batch) in sorted(plan.items()):
        name = names[fw].get(a)
        assert name, (fw, hex(a), "no function row")
        old = existing.get(a, [])
        old_by_index = {q[2]: q for _, q in old}
        rows = []
        if v["verdict"] == "AMENDED":
            am = AMENDED[(fw, a)]
            if am.get("keep_return"):
                if "return" in old_by_index:
                    q = old_by_index["return"]
                    rows.append(f"0x{a:08x},{name},return,,{q[4]},{q[5] if len(q) > 5 else ''}")
            else:
                typ, comment = am["return"]
                rows.append(f"0x{a:08x},{name},return,,{typ},{clean(comment)} {R}")
            for idx, pname, ptype, comment in am["params"]:
                if pname is None:
                    q = old_by_index[str(idx)]
                    rows.append(f"0x{a:08x},{name},{idx},{q[3]},{q[4]},{q[5] if len(q) > 5 else ''}")
                else:
                    if comment is None:
                        comment = next(pp["comment"] for pp in p["params"] if pp["index"] == idx)
                    rows.append(f"0x{a:08x},{name},{idx},{pname},{ptype},{clean(comment)} {R}")
        else:
            rows.append(f"0x{a:08x},{name},return,,{p["return_type"].replace(" *", "*")},{clean(p.get("evidence"))} {R}")
            for pp in sorted(p["params"], key=lambda x: x["index"]):
                rows.append(f"0x{a:08x},{name},{pp['index']},{pp['name']},{pp["type"].replace(" *", "*")},{clean(pp['comment'])} {R}")
        drop.update(i for i, _ in old)
        new_rows.append((a, rows))
        total += len(rows)
    out = [l for i, l in enumerate(lines) if i not in drop]
    k = max(i for i, l in enumerate(out) if l.startswith("0x")) + 1
    block = [f"# PR #53 round 97 (batches R5 / R6): judged prototypes"]
    for a, rows in new_rows:
        block += rows
    out[k:k] = block
    open(path, "w", newline="").write(E.join(out))
    print(fw, len(new_rows), "functions,", sum(len(r) for _, r in new_rows), "rows; replaced", len(drop), "old rows")

"""Round 92 stage A (CM550, and CM848 field renames): the algorithm enable words (e2m 106B AENBLFLG, CM550 0x803c92).
Applies workflow wf_5794b4eb-1ec's proposals (an investigator and a skeptic per batch of words):
- a word is applied when its skeptic verdict is CONFIRMED or AMENDED (REFUTED / no verdict: skipped and reported);
- a bit whose name the skeptic REFUTED becomes reserved_bit_<n> (the refuted guess stays in its comment);
- AMEND below holds the skeptics' free-text amendments as exact values (word-level: name / type / row_comment;
  bit-level: name / comment), written by hand from the verdicts;
- a word typed algorithm_enable_flags_<n>_t shares CM848's type: its 16 field names must equal CM848's (checked);
  cm550_algorithm_enable_flags_<n>_t is CM550's own; `word` is a plain word (indexed, written, or mostly unproved)
  with the bit meanings in the row comment.
Rows are renamed algorithm_enable_flags_<n>_cal (the table is in the EEPROM mirror); the length word is
algorithm_enable_flags_table_length_cal. CM848 field renames the skeptic confirmed are applied to CM848's types.
Idempotent; keeps line endings. usage: apply_r92a.py <repo> <outdir> <batch_X.json>..."""
import csv
import json
import os
import re
import sys

repo, outdir, batches = os.path.abspath(sys.argv[1]), sys.argv[2], sys.argv[3:]
R = "PR #53 round 92"
O5 = os.path.join(repo, "firmware/CM550_J90350.00_analysis/output")
O8 = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")

# The skeptics' amendments as exact values. Keys: (word, None) for the word, (word, bit) for a field,
# ("cm848", type, bit) for a CM848 field rename. Values override the proposal's.
AMEND = {}
AMEND_FILE = os.path.join(os.path.dirname(os.path.abspath(__file__)), "amend_r92a.json")
if os.path.exists(AMEND_FILE):
    for k, v in json.load(open(AMEND_FILE)).items():
        parts = k.split("|")
        key = ("cm848", parts[1], int(parts[2])) if parts[0] == "cm848" else (int(parts[0]), None if parts[1] == "" else int(parts[1]))
        AMEND[key] = v


def read(p):
    return open(p, newline="").read()


def write(p, t):
    open(p, "w", newline="").write(t)


def quote(text):
    text = " ".join(str(text).split())
    return '"' + text.replace('"', "'") + '"' if ("," in text or '"' in text) else text


cm848_types = {}
for row in csv.reader(open(os.path.join(O8, "structure_definitions.csv"), newline="")):
    if len(row) > 3 and re.match(r"^algorithm_enable_flags_\d+_t$", row[0]):
        m = re.match(r"^bitfield:1@(\d+)$", row[3])
        if m:
            cm848_types.setdefault(row[0], {})[int(m.group(1))] = row[2]

S5 = os.path.join(O5, "structure_definitions.csv")
s5 = read(S5)
E5 = "\r\n" if "\r\n" in s5 else "\n"
G5 = os.path.join(O5, "global_variables.csv")
lines = read(G5).split("\n")
s8 = read(os.path.join(O8, "structure_definitions.csv"))
report, problems, map550, map848 = [], [], [], []
for path in batches:
    data = json.load(open(path))
    p, vd = data["proposal"], (data.get("verdict") or {}).get("verdicts", [])
    word_v, bit_v, cm848_v = {}, {}, {}
    for v in vd:
        el = v["element"].lower()
        m = re.search(r"cm848\s+(algorithm_enable_flags_\d+_t)\s+bit\s+(\d+)", el)
        if m:
            cm848_v[(m.group(1), int(m.group(2)))] = v
            continue
        m = re.search(r"word\s+(-?\d+)(?:\s+bit\s+(\d+))?", el)
        if m:
            if m.group(2) is None:
                word_v[int(m.group(1))] = v
            else:
                bit_v[(int(m.group(1)), int(m.group(2)))] = v
            continue
        if "length" in el:
            word_v[-1] = v
            continue
        problems.append(f"{p['batch']}: verdict element not understood: {v['element']}")
    for w in p["words"]:
        n = w["word"]
        wv = word_v.get(n)
        if wv is None or wv["verdict"] == "REFUTED":
            report.append(f"{p['batch']} SKIP word {n} ({wv['verdict'] if wv else 'no verdict'})")
            continue
        over = AMEND.get((n, None), {})
        name, typ = over.get("name", w["proposed_name"]), over.get("type", w["proposed_type"])
        row_comment = over.get("row_comment", w.get("row_comment") or "")
        # some proposals already end their row comment with the "(was ...)" note that is added below
        row_comment = re.sub(r"\s*\(was [^()]*; PR #53 round 92\)\s*$", "", row_comment)
        differences = over.get("differences", w.get("differences_from_cm848") or "")
        a = int(w["address"], 16)
        fields = {}
        for f in w.get("fields") or []:
            b = f["bit"]
            fo = AMEND.get((n, b), {})
            fname, fcomment = fo.get("name", f["name"]), fo.get("comment", f.get("comment") or "")
            bv = bit_v.get((n, b))
            if bv and bv["verdict"] == "REFUTED" and "name" not in fo:
                fcomment = f"refuted guess {fname}: {bv['reason'][:160]} | {fcomment}"
                fname = f"reserved_bit_{b}"
            fields[b] = (fname, fcomment)
        if typ != "word":
            if sorted(fields) != list(range(16)) or len({v[0] for v in fields.values()}) != 16:
                problems.append(f"word {n}: fields are not bits 0-15 with 16 distinct names")
                continue
            if re.match(r"^algorithm_enable_flags_\d+_t$", typ):
                ref = cm848_types.get(typ)
                diff = [b for b in range(16) if not ref or ref.get(b) != fields[b][0]]
                if diff:
                    problems.append(f"word {n}: shared type {typ} differs from CM848's at bits {diff}")
                    continue
            if not re.search(rf"^{re.escape(typ)},,", s5, re.M):
                rows = [f"# {typ}: algorithm enable flags word {n} (e2m 106B +0x{2 + 2 * n:x}; {R})"
                        + (" - CM848's type of the same name (the same 16 bits)" if not typ.startswith("cm550_")
                           else " - against CM848: " + " ".join(differences.split()))]
                for b in range(16):
                    rows.append(f"{typ},,{fields[b][0]},bitfield:1@{b},{2 if b == 0 else 0},{quote(fields[b][1])},,verified")
                s5 = s5.rstrip("\r\n") + E5 + E5 + E5.join(rows) + E5
        idx = next((i for i, l in enumerate(lines) if l.startswith("0x") and int(l.split(",")[0], 16) == a), None)
        old = lines[idx].split(",")[1] if idx is not None else ""
        if idx is not None and old == name and lines[idx].split(",")[2] == typ:
            continue
        was = f" (was {old}; {R})" if old and old != name else f" ({R})"
        row = f"0x{a:08x},{name},{typ},{' '.join(row_comment.split())}{was}"
        if idx is not None:
            lines[idx] = row
        else:
            after = [i for i, l in enumerate(lines) if l.startswith("0x") and int(l.split(",")[0], 16) < a]
            lines.insert(after[-1] + 1, row)
        if old and old != name:
            map550.append((f"0x{a:08x}", name, old))
        report.append(f"{p['batch']} word {n} 0x{a:x} {old or '(no row)'} -> {name} {typ}")
    for r in p.get("cm848_field_renames") or []:
        key = (r["type_name"], r["bit"])
        v = cm848_v.get(key)
        over = AMEND.get(("cm848",) + key, {})
        if v is None or (v["verdict"] == "REFUTED" and not over):
            report.append(f"{p['batch']} SKIP cm848 {key} ({v['verdict'] if v else 'no verdict'})")
            continue
        new_field = over.get("name", r["proposed_field"])
        m = re.search(rf"^({re.escape(r['type_name'])},,){re.escape(r['current_field'])}(,bitfield:1@{r['bit']},[^\r\n]*)$", s8, re.M)
        if not m:
            if not re.search(rf"^{re.escape(r['type_name'])},,{re.escape(new_field)},bitfield:1@{r['bit']},", s8, re.M):
                problems.append(f"cm848 {key}: field row {r['current_field']} not found")
            continue
        rest = m.group(2)
        note = f" (was {r['current_field']}; {R})"
        rest = (rest[:rest.rindex(',,verified')].rstrip('"') + note + ('"' if rest[:rest.rindex(',,verified')].endswith('"') else "")
                + ",,verified") if ",,verified" in rest else rest
        s8 = s8[:m.start()] + m.group(1) + new_field + rest + s8[m.end():]
        if not r["current_field"].startswith("reserved_bit_"):
            map848.append(("", new_field, r["current_field"]))
        report.append(f"{p['batch']} cm848 {r['type_name']} bit {r['bit']}: {r['current_field']} -> {new_field}")
if problems:
    print("REFUSED:\n" + "\n".join(problems))
    sys.exit(1)
write(S5, s5)
write(G5, "\n".join(lines))
write(os.path.join(O8, "structure_definitions.csv"), s8)
for name, rows in (("map_r92a_cm550.csv", map550), ("map_r92a_cm848.csv", map848)):
    if rows or not os.path.exists(os.path.join(outdir, name)):
        with open(os.path.join(outdir, name), "w") as fh:
            fh.write("address,name,old_label,kind,dims\n")
            for a, n, o in rows:
                fh.write(f"{a},{n},{o},symbol,1\n")
open(os.path.join(outdir, "apply_report_r92a.txt"), "a").write("\n".join(report) + "\n")
print("\n".join(report))

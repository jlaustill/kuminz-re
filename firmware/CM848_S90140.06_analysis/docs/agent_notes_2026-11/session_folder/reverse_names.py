"""Proof that naming tables changed nothing but labels: map every new name back to its old label in the new
.cpp, sort each function's local declaration block (Ghidra may reorder declarations when the symbol table
changes), strip whitespace, and compare with the old .cpp. Usage: reverse_names.py old.cpp new.cpp mapping.csv
mapping.csv: address,name[,...,old_label] - old_label (when set) is what the name replaced; else WORD_ARRAY_<address>."""
import csv
import difflib
import re
import sys

old_path, new_path, mapping = sys.argv[1:4]
IGNORE_COMMENTS = "--ignore-comments" in sys.argv     # plate comments changed on purpose: compare code only
rows = [r for r in csv.DictReader(open(mapping)) if r.get("kind") not in ("delete",)]
fields = [(r["name"], r["old_label"]) for r in rows if r.get("kind") == "field"]
rows = [r for r in rows if r.get("kind") != "field"]
names = {r["name"]: int(r["address"], 16) if r["address"] else 0 for r in rows}
old_label = {r["name"]: r["old_label"] for r in rows if r.get("old_label")}
new_text = open(new_path).read()
old = open(old_path).read()
strip_header = lambda t: re.sub(r"^// Generated:.*$", "", t, flags=re.M)
new, old = strip_header(new_text), strip_header(old)
if IGNORE_COMMENTS:
    strip_comments = lambda t: re.sub(r"/\*.*?\*/", "", t, flags=re.S)
    new, old = strip_comments(new), strip_comments(old)
present = {n for n in names if re.search(rf"\b{re.escape(n)}\b", new)}
underscored = sorted(n for n in names if re.search(rf"\b_{re.escape(n)}\b", new))
for n in sorted(names, key=len, reverse=True):
    a = names[n]
    back = old_label.get(n, f"WORD_ARRAY_{a:08x}")
    new = re.sub(rf"\bPTR_{re.escape(n)}_([0-9a-f]{{8}})\b", (rf"PTR_{back}_\1" if n in old_label else r"PTR_WORD_ARRAY_\1"), new)
    new = re.sub(rf"\b_{re.escape(n)}\b", f"_{back}", new)          # the width-mismatch variant
    new = re.sub(rf"\b{re.escape(n)}\b", back, new)
for n, o in sorted(fields, key=lambda f: -len(f[0])):           # struct fields: only after '.' or '->'
    new = re.sub(rf"([.>]\s*){re.escape(n)}\b", lambda m: m.group(1) + o, new)
if "--canonical-code-labels" in sys.argv:     # per function: labels renumbered by first appearance (one-to-one)
    lab = re.compile(r"\b(?:LAB_[0-9a-f]{8}|switchD_[0-9a-f]{8}(?:_default|::caseD_[0-9a-f]+)?|caseD_[0-9a-f]+)\b")

    def canon(text):
        out = []
        for chunk in re.split(r"(?m)^(?=// Function: )", text):
            seen = {}
            out.append(lab.sub(lambda m: seen.setdefault(m.group(0), f"L{len(seen)}"), chunk))
        return "".join(out)
    new, old = canon(new), canon(old)
if "--normalize-code-labels" in sys.argv:     # goto-target labels: LAB_x / switchD_x_default / caseD_x are cosmetic
    lab = re.compile(r"\b(?:LAB_[0-9a-f]{8}|switchD_[0-9a-f]{8}(?:_default|::caseD_[0-9a-f]+)?|caseD_[0-9a-f]+)\b")
    new, old = lab.sub("LBL", new), lab.sub("LBL", old)
if "--write-reversed" in sys.argv:
    open(sys.argv[sys.argv.index("--write-reversed") + 1], "w").write(new)
DECL = re.compile(r"^  [A-Za-z_][\w ]*[\w\*]\s*\**[A-Za-z_]\w*(\[\d+\])?;$")


def normalize(text):
    """Per function: sort the declaration lines right after the opening brace, then drop whitespace."""
    chunks = re.split(r"(?m)^(?=// Function: )", text)
    out = []
    reordered = 0
    for c in chunks:
        lines = c.split("\n")
        try:
            i = lines.index("{") + 1
        except ValueError:
            out.append(re.sub(r"\s+", "", c))
            continue
        j = i
        while j < len(lines) and DECL.match(lines[j]):
            j += 1
        block = lines[i:j]
        if block != sorted(block):
            reordered += 1
        lines[i:j] = sorted(block)
        out.append(re.sub(r"\s+", "", "\n".join(lines)))
    return out, reordered


fa, ra = normalize(old)
fb, rb = normalize(new)
print(f"names {len(names)}  rendered {len(present)}  underscore variants {len(underscored)} {underscored[:5]}")
labels_left = sorted({f"0x{v:08x}" for n, v in names.items() if n not in old_label and f"WORD_ARRAY_{v:08x}" in new_text})
print(f"old WORD_ARRAY_ labels of named tables still in the new .cpp: {len(labels_left)} {labels_left[:5]}")
if fa == fb:
    changed_order = sum(1 for x, y in zip(re.split(r"(?m)^(?=// Function: )", old), re.split(r"(?m)^(?=// Function: )", new))
                        if re.sub(r"\s+", "", x) != re.sub(r"\s+", "", y))
    print(f"EQUIVALENT: the new .cpp is the old one with labels renamed"
          f" ({changed_order} functions differ only in the order of their local declarations)")
else:
    print(f"NOT EQUIVALENT: {len(fa)} vs {len(fb)} function chunks")
    shown = 0
    for x, y in zip(fa, fb):
        if x != y and shown < 6:
            sm = difflib.SequenceMatcher(None, x, y, autojunk=False)
            for tag, i1, i2, j1, j2 in sm.get_opcodes():
                if tag != "equal":
                    print(f"DIFF in {x[:50]}\n   old ...{x[max(0, i1 - 60):i2 + 20]}\n   new ...{y[max(0, j1 - 60):j2 + 20]}")
                    break
            shown += 1
    sys.exit(1)

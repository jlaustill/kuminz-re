"""Round 27 stage B, nested layout: each fault word 1-49 keeps its field (faults_A_to_B) and is typed as its own
16-bit struct fault_bits_A_to_B_t of 16 one-bit bitfields (bit k = mask 1 << k; fault n = bit n % 16 of word n / 16).
Word 0 stays a plain word: it is the base of the indexed accesses. The type-only templates go just before the
fault_bit_words_t rows. Names and comments come from fault_fields.tsv.
usage: bitfield_words_nested.py <repo> <fault_fields.tsv>"""
import csv
import io
import os
import re
import sys

repo, fields_tsv = os.path.abspath(sys.argv[1]), sys.argv[2]
p = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output/structure_definitions.csv")
lines = open(p).read().split("\n")
fields = {}
for line in open(fields_tsv):
    fault, word, bit, field, comment = line.rstrip("\n").split("\t")
    fields[int(fault)] = (field, comment)
templates, out, first_row = [], [], None
for i, line in enumerate(lines):
    row = next(csv.reader(io.StringIO(line))) if line and not line.startswith("#") else None
    m = re.fullmatch(r"faults_(\d+)_to_(\d+)", row[2]) if row and len(row) > 2 and row[0] == "fault_bit_words_t" else None
    if row and row[0] == "fault_bit_words_t" and first_row is None:
        first_row = len(out)
    if not m or int(m.group(1)) == 0:
        out.append(line)
        continue
    a, b = int(m.group(1)), int(m.group(2))
    t = f"fault_bits_{a}_to_{b}_t"
    templates.append(f"# {t}: fault_bit_words_t.faults_{a}_to_{b}, one bit per fault (fault n = bit n - {a}); PR #53 "
                     f"round 27, the user's decision")
    for k in range(16):
        field, comment = fields[a + k]
        comment = comment.replace('"', "'")
        assert "," not in comment, comment
        templates.append(",".join([t, "", field, f"bitfield:1@{k}", "2" if k == 0 else "0", comment, "", "verified"]))
    row[3], row[6] = t, t
    buf = io.StringIO()
    csv.writer(buf, lineterminator="").writerow(row)
    out.append(buf.getvalue())
out[first_row:first_row] = templates
open(p, "w").write("\n".join(out))
print(f"{len(templates) // 17} nested word types, {len(templates) - len(templates) // 17} bitfield rows")

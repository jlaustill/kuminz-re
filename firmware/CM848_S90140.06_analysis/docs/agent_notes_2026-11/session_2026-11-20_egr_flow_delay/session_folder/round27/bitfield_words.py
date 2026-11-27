"""Round 27 stage B: turn words of fault_bit_words_t into 16 one-bit bitfields each (fault n = bit n % 16 of word
n / 16; bit k = mask 1 << k of the word). The opener (bit 0) carries the storage width 2 and the word's e2m record;
the other 15 rows have size 0. Names and comments come from fault_fields.tsv (fault_field_names.py).
usage: bitfield_words.py <repo> <fault_fields.tsv> <word index>... | all"""
import csv
import io
import os
import re
import sys

repo, fields_tsv = os.path.abspath(sys.argv[1]), sys.argv[2]
words = set(range(50)) if sys.argv[3:] == ["all"] else {int(w) for w in sys.argv[3:]}
p = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output/structure_definitions.csv")
lines = open(p).read().split("\n")
fields = {}
for line in open(fields_tsv):
    fault, word, bit, field, comment = line.rstrip("\n").split("\t")
    fields[int(fault)] = (field, comment)
out, converted = [], 0
for line in lines:
    row = next(csv.reader(io.StringIO(line))) if line and not line.startswith("#") else None
    m = re.fullmatch(r"faults_(\d+)_to_(\d+)", row[2]) if row and len(row) > 2 and row[0] == "fault_bit_words_t" else None
    if not m or int(m.group(1)) // 16 not in words:
        out.append(line)
        continue
    first = int(m.group(1))
    record = re.match(r"Faults \d+-\d+: (e2m 1036 \+[0-9A-F]+ System_Error_Status_\d+)", row[5])
    for k in range(16):
        field, comment = fields[first + k]
        if k == 0:
            comment = f"word {row[2]} ({record.group(1) if record else 'e2m 1036'}) bit 0 = {comment}"
        comment = comment.replace('"', "'")
        assert "," not in comment, comment
        out.append(",".join(["fault_bit_words_t", "0x003fe974", field, f"bitfield:1@{k}", "2" if k == 0 else "0",
                             comment, "", "verified"]))
    converted += 1
open(p, "w").write("\n".join(out))
print(f"{converted} words -> {16 * converted} bitfields")

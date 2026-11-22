"""Round 32: every call of the discrete output read-back check (diag_faultMatch_outputCheck_update): the logical
output, the read-back switch line, the high / low fault bits with their names (fault_bit_words_t; word 0 from
fault_fields.tsv), and the five state addresses.
usage: output_check_calls.py <cpp> <structure_definitions.csv> <fault_fields.tsv>"""
import csv
import re
import sys

cpp, sd, tsv = sys.argv[1:4]
names = {}
for line in open(tsv):
    f, w, b, field, c = line.rstrip("\n").split("\t")
    names[int(f)] = field
fault = 16
for row in csv.reader(open(sd, newline="")):
    if len(row) > 3 and row[0] == "fault_bit_words_t" and row[3].startswith("bitfield:1@"):
        names[fault] = row[2]
        fault += 1
text = re.sub(r"\s+", " ", open(cpp, errors="replace").read())
heads = [(m.start(), m.group(1)) for m in re.finditer(r"// Function: (\S+) @", text)]
for m in re.finditer(r"diag_faultMatch_outputCheck_update \(([^;]*?)\);", text):
    args = [a.strip() for a in m.group(1).split(",")]
    caller = max((p, n) for p, n in heads if p < m.start())[1]
    if len(args) != 9:
        continue
    out, line, hi, lo = (int(a, 0) for a in args[:4])
    print(f"{caller}: output {out} line {line} high {hi} {names.get(hi)} low {lo} {names.get(lo)} state "
          + " ".join(a.lstrip("&") for a in args[4:]))

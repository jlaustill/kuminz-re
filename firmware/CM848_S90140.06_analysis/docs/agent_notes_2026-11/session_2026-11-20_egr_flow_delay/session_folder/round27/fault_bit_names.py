"""Round 27 stage B: the fault bit names from fault_bit_words_t's field comments ('b<k> <e2m 1036 name>[ <DTC>]' or
'b<k> <DTC>'), one row per bit: fault, word, bit, e2m name, DTC. Prints the token census of the e2m names (tokens not
in an English word list are the abbreviation candidates).
usage: fault_bit_names.py <structure_definitions.csv> <out.tsv>"""
import csv
import re
import sys
from collections import Counter

src, out = sys.argv[1], sys.argv[2]
rows = []
with open(src, newline="") as fh:
    for row in csv.reader(fh):
        if len(row) > 5 and row[0] == "fault_bit_words_t" and row[2].startswith("faults_"):
            first = int(row[2].split("_")[1])
            body = row[5].split(";", 1)[1] if ";" in row[5] else ""
            for part in body.split(";"):
                m = re.match(r"\s*b(\d+) (\S+)(?: ([PCBU][0-9A-F]{4}))?", part)
                if not m:
                    continue
                k, name, dtc = int(m.group(1)), m.group(2), m.group(3)
                if re.fullmatch(r"[PCBU][0-9A-F]{4}", name):
                    name, dtc = None, name
                rows.append((first + k, first // 16, k, name, dtc, part.strip()))
with open(out, "w") as fh:
    for r in rows:
        fh.write("\t".join("" if v is None else str(v) for v in r[:5]) + "\n")
named = [r for r in rows if r[3]]
print(f"{len(rows)} bits listed; {len(named)} with an e2m name; {len(rows) - len(named)} DTC only")
words = set()
try:
    words = {w.strip().lower() for w in open("/usr/share/dict/words")}
except OSError:
    pass
tokens = Counter(t.lower() for r in named for t in r[3].split("_"))
odd = sorted((t for t in tokens if t not in words or len(t) <= 2), key=lambda t: -tokens[t])
print("tokens:", len(tokens), "not in the word list:", " ".join(f"{t}({tokens[t]})" for t in odd))

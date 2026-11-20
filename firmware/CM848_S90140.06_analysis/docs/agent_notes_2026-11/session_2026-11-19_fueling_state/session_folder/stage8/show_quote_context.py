"""Print every dump-value quote (the patterns check_quoted_dump_values_W13.py reads) of the named rows, with context.
usage: show_quote_context.py <names.txt> <global_variables.csv>"""
import re
import sys

names = open(sys.argv[1]).read().split()
rows = {l.split(",")[1]: l.rstrip("\n").split(",", 3)[3] for l in open(sys.argv[2], errors="replace") if l.startswith("0x")}
QUOTE = re.compile(r"(-?0x[0-9a-fA-F]+|-?\d+)(?: = [^;()]{0,40})? here\b|\bdump (?:value )?(?:is |=\s*)?(-?0x[0-9a-fA-F]+|-?\d+)\b")
for n in names:
    c = rows[n]
    for m in QUOTE.finditer(c):
        print(f"{n}: ...{c[max(0, m.start() - 60):m.end() + 12]}...")

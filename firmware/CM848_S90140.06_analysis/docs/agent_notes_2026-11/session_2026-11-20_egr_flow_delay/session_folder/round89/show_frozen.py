"""Print each 'frozen ...' citation (with 50 characters before) in rows carrying a marker. usage: show_frozen.py <csv> <marker>"""
import re
import sys

for line in open(sys.argv[1], errors="replace"):
    if sys.argv[2] not in line:
        continue
    for m in re.finditer(r"frozen", line):
        print(line[:10], "|", line[max(0, m.start() - 50):m.start() + 70].replace("\n", ""))

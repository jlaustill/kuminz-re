"""List each line of the CM550 .cpp matching a regex with the enclosing function (name @ address).
usage: cpp_refs.py <cpp> <regex>"""
import re, sys
cpp = open(sys.argv[1], errors='replace').read().splitlines()
pat = re.compile(sys.argv[2])
fn = re.compile(r'^// Function: (\S+) @ 0x([0-9a-fA-F]+)')
cur = ('?', '?')
for i, line in enumerate(cpp, 1):
    m = fn.match(line)
    if m:
        cur = (m.group(1), m.group(2))
        continue
    if pat.search(line):
        print(f'{i:6} {cur[0]}@0x{cur[1]}: {line.strip()[:170]}')

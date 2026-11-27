"""Round 42: the functions whose body (comments stripped) references a symbol.  usage: list_users.py <cpp> <symbol>"""
import re
import sys

t = open(sys.argv[1], errors="replace").read()
parts = re.split(r"^// Function: (\S+) @[^\n]*\n", t, flags=re.M)
for i in range(1, len(parts), 2):
    b = re.sub(r"/\*.*?\*/", "", parts[i + 1], flags=re.S)
    if re.search(r"\b" + re.escape(sys.argv[2]) + r"\b", b):
        print(parts[i])

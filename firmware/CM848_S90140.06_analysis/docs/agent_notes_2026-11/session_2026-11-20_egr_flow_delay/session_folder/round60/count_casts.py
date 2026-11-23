"""Round 56: prove_caches.py strips scalar casts, so count them separately in the changed functions (old name / new
name pairs).  usage: count_casts.py <old.cpp> <new.cpp> <old fn>:<new fn>..."""
import re
import sys

CAST = re.compile(r"\((short|ushort|int|uint|word|dword|undefined1|undefined2|undefined4|char|uchar|byte)\)")


def body(path, name):
    t = open(path, errors="replace").read()
    m = re.search(r"^// Function: " + re.escape(name) + r" @.*?(?=^// Function: |\Z)", t, re.S | re.M)
    return re.sub(r"/\*.*?\*/", "", m.group(0), flags=re.S)


for pair in sys.argv[3:]:
    old, new = pair.split(":")
    print(f"{new}: casts {len(CAST.findall(body(sys.argv[1], old)))} -> {len(CAST.findall(body(sys.argv[2], new)))}")

"""Round 33 stage B: the named functions are equal once their leading local declarations are sorted (comments and
whitespace dropped).  usage: check_reorders_r33b.py <old flat cpp> <new flat cpp> <function>..."""
import re
import sys

old_t, new_t = open(sys.argv[1]).read(), open(sys.argv[2]).read()


def body(t, name):
    m = re.search(r"^// Function: " + re.escape(name) + r" @[^\n]*\n(.*?)(?=^// Function: |\Z)", t, re.S | re.M)
    return re.sub(r"\s+", "", re.sub(r"/\*.*?\*/", "", m.group(1), flags=re.S))


def sorted_decls(s):
    m = re.match(r"(.*?\{)((?:[a-z_0-9]+\*?[A-Za-z_0-9]+(?:\[\d+\])?;)+)(.*)", s)
    if not m:
        return s
    decls = sorted(re.findall(r"[a-z_0-9]+\*?[A-Za-z_0-9]+(?:\[\d+\])?;", m.group(2)))
    return m.group(1) + "".join(decls) + m.group(3)


for name in sys.argv[3:]:
    print(name, "equal with sorted declarations:", sorted_decls(body(old_t, name)) == sorted_decls(body(new_t, name)))

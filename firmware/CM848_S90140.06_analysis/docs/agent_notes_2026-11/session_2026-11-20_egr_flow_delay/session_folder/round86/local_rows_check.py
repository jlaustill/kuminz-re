"""For the functions a stage changed that have local_variables.csv rows, show each named local's assignment lines before
and after, so a row that a renumbering moved onto another variable stands out.
usage: local_rows_check.py <pre cpp> <post cpp> <local_variables.csv> <function_set_check output>..."""
import re
import sys

pre_path, post_path, locals_path = sys.argv[1:4]
changed = set()
for f in sys.argv[4:]:
    changed |= {l.split()[0] for l in open(f) if re.match(r"^  0x[0-9a-f]+ ", l)}


def functions(path):
    text = re.sub(r"/\*.*?\*/", "", open(path, errors="replace").read(), flags=re.S)
    parts = re.split(r"^// Function: (\S+) @ (0x[0-9a-f]+)[^\n]*\n", text, flags=re.M)
    return {int(parts[i + 1], 16): (parts[i], parts[i + 2]) for i in range(1, len(parts), 3)}


pre, post = functions(pre_path), functions(post_path)
rows = {}
for line in open(locals_path, newline=""):
    p = line.rstrip("\r\n").split(",")
    if p[0].startswith("0x") and len(p) > 3:
        rows.setdefault(int(p[0], 16), []).append(p[3])
hits = sorted(a for a in rows if f"0x{a:08x}" in changed)
print(f"{len(hits)} changed functions have local rows")
for a in hits:
    name = post[a][0]
    for local in rows[a]:
        def uses(body):
            return [re.sub(r"\s+", " ", l.strip())[:110] for l in body.split("\n")
                    if re.search(rf"\b{re.escape(local)}\b", l) and "=" in l and not l.strip().startswith(("byte", "word", "dword", "uint", "int", "short", "ushort", "char", "undefined"))]
        before, after = uses(pre[a][1]), uses(post[a][1])
        flag = "same" if before == after else "DIFFERENT"
        print(f"  0x{a:05x} {name} {local}: {flag}")
        if before != after:
            for l in before[:3]:
                print("     before:", l)
            for l in after[:3]:
                print("     after: ", l)

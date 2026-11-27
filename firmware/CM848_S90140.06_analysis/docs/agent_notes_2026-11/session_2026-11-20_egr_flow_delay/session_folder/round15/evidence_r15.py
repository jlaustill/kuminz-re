"""Round 15: per candidate name, its functions and up to N code lines (comments stripped), to check each pool row's use
against its e2m record before naming it. usage: evidence_r15.py <cpp> <names.txt> [N]"""
import collections
import re
import sys

cpp_path, names_path = sys.argv[1], sys.argv[2]
N = int(sys.argv[3]) if len(sys.argv) > 3 else 2
text = open(cpp_path).read()
code = re.sub(r"/\*.*?\*/", lambda m: "\n" * m.group(0).count("\n"), text, flags=re.S)
lines = code.split("\n")
func = []
cur = ""
for l in lines:
    m = re.match(r"// Function: (\S+)", l)
    if m:
        cur = m.group(1)
    func.append(cur)
for name in [n.strip() for n in open(names_path) if n.strip()]:
    hits = [i for i, l in enumerate(lines) if re.search(rf"\b{re.escape(name)}\b", l) and not l.lstrip().startswith("//")]
    fs = collections.Counter(func[i] for i in hits)
    print(f"== {name}: {len(hits)} lines in {', '.join(f'{f}:{c}' for f, c in fs.most_common(5))}")
    for i in hits[:N]:
        print("   " + lines[i].strip()[:150])

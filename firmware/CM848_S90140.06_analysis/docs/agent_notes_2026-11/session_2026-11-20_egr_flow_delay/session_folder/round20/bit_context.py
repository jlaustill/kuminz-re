"""Print the code lines (comments stripped) around each test of the given flag bits.
usage: bit_context.py <cpp> <word:mask> [<word:mask> ...]   e.g. 21:0x8000"""
import re
import sys

raw = open(sys.argv[1]).read()
t = re.sub(r"/\*.*?\*/", lambda m: "\n" * m.group(0).count("\n"), raw, flags=re.S)
t = re.sub(r"//[^\n]*", "", t)
lines = t.split("\n")
func = []
cur = "?"
for l in raw.split("\n"):
    if l.startswith("// Function: "):
        cur = l.split()[2]
    func.append(cur)
for spec in sys.argv[2:]:
    w, mask = spec.split(":")
    m = int(mask, 0)
    forms = {str(m), f"0x{m:x}"}
    pat = re.compile(rf"\balgorithm_enable_flags_{w}_cal\s*&\s*({'|'.join(re.escape(f) for f in forms)})\)")
    print(f"##### word {w} mask {mask}")
    for i, l in enumerate(lines):
        if pat.search(l):
            print(f"--- {func[i]} (line {i + 1})")
            for k in range(max(0, i - 3), min(len(lines), i + 5)):
                if lines[k].strip():
                    print(f"  {lines[k].rstrip()[:150]}")

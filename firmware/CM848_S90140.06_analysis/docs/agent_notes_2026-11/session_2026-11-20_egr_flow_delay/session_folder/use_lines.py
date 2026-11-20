"""For each symbol: up to N code lines (not comments) that use it, with the enclosing function.
Usage: use_lines.py <cpp> <N> <symbol>..."""
import re
import sys

cpp, n, symbols = sys.argv[1], int(sys.argv[2]), sys.argv[3:]
text = open(cpp).read()
code = re.sub(r"/\*.*?\*/", lambda m: "\n" * m.group(0).count("\n"), text, flags=re.S)
lines = code.split("\n")
fn = []
cur = None
for line in lines:
    m = re.match(r"^[A-Za-z_][\w \*]*?\b([A-Za-z_]\w*)\(.*\)\s*$", line)
    if m and not line.startswith(" "):
        cur = m.group(1)
    fn.append(cur)
for sym in symbols:
    pat = re.compile(rf"\b{re.escape(sym)}\b")
    hits = [(fn[i], l.strip()) for i, l in enumerate(lines) if pat.search(l) and fn[i] and not l.lstrip().startswith(("//",))
            and not re.match(r"^\s*(word|dword|uint|int|short|ushort|byte)\s", l)]
    print(f"== {sym} ({len(hits)} lines)")
    for f, l in hits[:n]:
        print(f"   [{f}] {l[:170]}")

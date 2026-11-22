"""Round 24: for each struct instance label, the functions whose bodies use it (count per function, address,
kernel = boot reflash kernel ROM 0x3c30-0x7f60) and the fields used.
usage: instance_users.py <cpp> <label>..."""
import re
import sys
from collections import Counter

cpp = open(sys.argv[1]).read()
HEAD = re.compile(r"^// Function: (\S+) @ 0x([0-9a-f]+)$", re.M)
heads = list(HEAD.finditer(cpp))
for label in sys.argv[2:]:
    users, fields = [], Counter()
    for i, m in enumerate(heads):
        body = cpp[m.end():heads[i + 1].start() if i + 1 < len(heads) else len(cpp)]
        body = re.sub(r"/\*.*?\*/", "", body, flags=re.S)
        n = len(re.findall(r"\b" + label + r"\b", body))
        if n:
            a = int(m.group(2), 16)
            users.append((m.group(1), a, n, "KERNEL" if 0x3c30 <= a < 0x7f60 else ""))
            fields.update(re.findall(r"\b" + label + r"\.([a-zA-Z_0-9]+)", body))
    print(f"== {label}: {sum(u[2] for u in users)} uses in {len(users)} functions; kernel functions "
          f"{sum(1 for u in users if u[3])}")
    for name, a, n, k in sorted(users, key=lambda u: -u[2])[:12]:
        print(f"   {n:4} {name} @ {a:#x} {k}")
    print("   fields:", dict(fields.most_common()))

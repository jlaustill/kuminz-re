"""Round 30: per byte offset of the two EC1 (PGN 65251) buffers (0x3fa7f8 payload, 0x3fa814 previous copy), every
load / store width that xref_addr.py finds, so the struct's fields take the widths the code uses.
usage: ec1_access_census.py <firmware dir>"""
import re
import subprocess
import sys
from collections import defaultdict

fw = sys.argv[1]
for base, label in ((0x3fa7f8, "payload"), (0x3fa814, "previous")):
    print(f"== {label} @ {base:#x}")
    for off in range(28):
        a = base + off
        r = subprocess.run([sys.executable, f"{fw}/scripts/xref_addr.py", f"{a:#x}"], capture_output=True, text=True,
                           cwd=fw)
        widths = defaultdict(set)
        func = "?"
        for line in r.stdout.splitlines():
            m = re.match(r"^(\S+): \d+r/\d+w", line)
            if m:
                func = m.group(1)
            m = re.search(r"\[(load |store)\] (byte|word|dword)", line)
            if m:
                widths[f"{m.group(1).strip()} {m.group(2)}"].add(func)
        if widths:
            print(f"  +{off:2} {a:#x}: " + "; ".join(f"{k} ({', '.join(sorted(v))})" for k, v in sorted(widths.items())))

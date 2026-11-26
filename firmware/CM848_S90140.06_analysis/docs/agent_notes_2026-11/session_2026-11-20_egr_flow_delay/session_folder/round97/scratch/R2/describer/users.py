"""For each listed CM550 global, list the functions in the frozen CM550 .cpp that mention it (by name, also _name)."""
import bisect
import re

cpp = open("/home/linux/.claude/jobs/374b0424/tmp/w15/r97/frozen/cm550/J90350.00.ghidra.cpp", errors="replace").read()
funcs = []
for m in re.finditer(r"^// Function: (\S+) @ (0x[0-9a-fA-F]+)", cpp, flags=re.M):
    funcs.append((m.start(), m.group(1), m.group(2)))
starts = [f[0] for f in funcs]
rows = [l.split() for l in open("/home/linux/.claude/jobs/374b0424/tmp/w15/r97/family_R2.txt") if l.strip()]
for addr, name, typ in rows:
    pat = re.compile(r"(?<![A-Za-z0-9_])_?" + re.escape(name) + r"(?![A-Za-z0-9_])")
    hits = {}
    for m in pat.finditer(cpp):
        i = bisect.bisect_right(starts, m.start()) - 1
        if i < 0:
            continue
        f = funcs[i]
        hits.setdefault((f[1], f[2]), 0)
        hits[(f[1], f[2])] += 1
    print(f"{addr} {name} {typ}: " + ", ".join(f"{n}@{a}x{c}" for (n, a), c in sorted(hits.items(), key=lambda x: int(x[0][1], 16))))

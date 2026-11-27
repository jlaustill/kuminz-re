"""Check each proposed CM550 name against every other CM550 global row / function name / struct field name, and
against the other proposals. usage: check_unique.py proposals.txt"""
import sys
F = "/home/linux/.claude/jobs/374b0424/tmp/w15/r97/frozen/cm550/"
props = [l.split() for l in open(sys.argv[1]) if l.strip()]
rows = {}
for line in open(F + "global_variables.csv", errors="replace"):
    p = line.rstrip("\r\n").split(",", 3)
    if len(p) > 1 and p[0].startswith("0x"):
        rows.setdefault(p[1], []).append(p[0].lower())
funcs = set()
for line in open(F + "function_renames.csv", errors="replace"):
    p = line.split(",", 2)
    if len(p) > 1 and p[0].startswith("0x"):
        funcs.add(p[1])
seen = {}
for addr, name in props:
    issues = []
    for a in rows.get(name, []):
        if int(a, 16) != int(addr, 16):
            issues.append("row at " + a)
    if name in funcs:
        issues.append("function name")
    if name in seen:
        issues.append("duplicate proposal " + seen[name])
    seen[name] = addr
    if len(name) > 90:
        issues.append("long %d" % len(name))
    print(addr, name, "OK" if not issues else "; ".join(issues))

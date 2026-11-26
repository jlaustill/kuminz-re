"""Round 94 (read-only): sort the distinct unmapped token changes of a token_diff.py census into kinds, so a review
reads only the kinds that need a look. Kinds:
- temp: a decompiler temporary renumbered or retyped (uVar3 => uVar2, puVar5 => pwVar4, local_6 => ...);
- named: an unnamed address (DAT_ / _DAT_ / BYTE_ ...) became a name or a field path;
- enum: a number became an enum member (0 => IDLE_SHUTDOWN_STATE_RESET);
- cast / index: cast or pointer-arithmetic tokens that typing removes or turns into [ ] / . field;
- other: everything else (printed in full).
usage: classify_census_r94.py <token_diff.txt> [map.csv]"""
import re
import sys

lines = open(sys.argv[1]).read().split("---- census of distinct changes", 1)[1].strip().splitlines()
new_names = set()
if len(sys.argv) > 2:
    for r in open(sys.argv[2]).read().splitlines()[1:]:
        p = r.split(",")
        if len(p) > 1:
            new_names.add(p[1].split(".")[0].split("[")[0])
TEMP = re.compile(r"^(?:[a-z]{1,3}Var\d+|local_[0-9a-f]+|[a-z]Stack_[0-9a-f]+|in_[A-Za-z0-9_]+|extraout_[A-Za-z0-9_]+|unaff_[A-Za-z0-9_]+)$")
UNNAMED = re.compile(r"^_?(?:DAT|BYTE|WORD|DWORD|PTR|UNK|ram)_?[0-9a-fA-F]+")
NUMBER = re.compile(r"^-?(?:0x[0-9a-fA-F]+|\d+)$|^'.*'$")
kinds = {"temp": [], "named": [], "enum": [], "cast / index": [], "other": []}
for line in lines:
    m = re.match(r"^\s*(\d+) (.*?) => (.*)$", line)
    if not m:
        continue
    n, old, new = int(m.group(1)), m.group(2).strip(), m.group(3).strip()
    ot, nt = old.split(), new.split()
    if ot and nt and len(ot) == len(nt) and all(TEMP.match(a) and TEMP.match(b) for a, b in zip(ot, nt)):
        kinds["temp"].append((n, old, new))
    elif ot and UNNAMED.match(ot[0]) and nt and re.match(r"^[a-z_][a-z0-9_]*$", nt[0]):
        kinds["named"].append((n, old, new))
    elif ot and all(NUMBER.match(t) or t in "()-" for t in ot) and nt and all(re.match(r"^[A-Z][A-Z0-9_]+$", t) or t in "|" for t in nt):
        kinds["enum"].append((n, old, new))
    elif all(re.match(r"^[()*\[\]&.+,]|^(?:u?int|u?short|word|dword|byte|char|undefined\d?|ushort|uint|bool|[a-z_]+_t)$|^0x[0-9a-f]+$|^\d+$", t)
             for t in ot + nt if t):
        kinds["cast / index"].append((n, old, new))
    else:
        kinds["other"].append((n, old, new))
for k, items in kinds.items():
    print(f"== {k}: {len(items)} kinds, {sum(i[0] for i in items)} changes")
    if True:
        for n, old, new in items:
            print(f"   {n:3d} {old} => {new}")

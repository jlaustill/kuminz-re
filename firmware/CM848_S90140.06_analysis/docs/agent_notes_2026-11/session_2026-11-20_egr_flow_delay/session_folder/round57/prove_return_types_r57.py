"""Round 57: prove the CRUISE_CONTROL_STATE return types change only the five getters' types. For each old / new pair:
drop the plate and the local declarations, put CRUISE_CONTROL_STATE members back as their values, remove the casts,
write every decompiler local (uVar1 / CVar1 / iVar1 ...) as V and the return type as T, remove whitespace, compare.
usage: prove_return_types_r57.py <old.cpp> <new.cpp> <enums.csv> <old>:<new>..."""
import csv
import re
import sys

old_t, new_t = open(sys.argv[1], errors="replace").read(), open(sys.argv[2], errors="replace").read()
members = {r[2]: int(r[1], 0) for r in csv.reader(open(sys.argv[3])) if r and r[0] == "CRUISE_CONTROL_STATE"}
MEMBER = re.compile(r"\b(" + "|".join(sorted(members, key=len, reverse=True)) + r")\b")


def norm(t, name):
    m = re.search(r"^// Function: " + re.escape(name) + r" @.*?(?=^// Function: |\Z)", t, re.S | re.M)
    b = re.sub(r"/\*.*?\*/", "", m.group(0), flags=re.S)
    b = b.split("\n", 1)[1]
    b = "\n".join(l for l in b.splitlines() if not re.fullmatch(r"\s*(?!return\b)[A-Za-z_]\w* \w+;", l))
    b = re.sub(r"^\s*\w+\s+" + r"\w+\(void\)", "T F(void)", b, count=1, flags=re.M)
    b = MEMBER.sub(lambda x: str(members[x.group(1)]), b)
    b = re.sub(r"\((int|short|ushort|uint|undefined4|CRUISE_CONTROL_STATE)\)", "", b)
    b = re.sub(r"\b[a-zA-Z]Var\d+\b", "V", b)
    return re.sub(r"\s+", "", b)


bad = 0
for pair in sys.argv[4:]:
    o, n = pair.split(":")
    same = norm(old_t, o) == norm(new_t, n)
    bad += not same
    print(f"{'same' if same else 'DIFFERENT'}  {n}")
print("PROVEN" if not bad else "NOT PROVEN")

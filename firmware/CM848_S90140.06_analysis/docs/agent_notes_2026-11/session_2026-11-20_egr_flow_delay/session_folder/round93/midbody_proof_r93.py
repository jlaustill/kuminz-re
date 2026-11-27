"""Round 93 proof for the mid-body row removal (read-only). Compares two CM550 decompilations by function ADDRESS
(two functions shared a name before, so a name-keyed comparison would merge them):
- the addresses that left and that arrived;
- for every address in both, whether the code text (plate comments and the '// Function:' header dropped) is the same.
usage: midbody_proof_r93.py <before.cpp> <after.cpp>"""
import re
import sys


def functions(path):
    text = open(path, errors="replace").read()
    out = {}
    for m in re.finditer(r"^// Function: (\w+) @ (0x[0-9a-f]+)\n(.*?)(?=^//\n// Function: |^// Function: |\Z)", text, re.M | re.S):
        body = m.group(3)
        body = re.sub(r"/\*.*?\*/", "", body, flags=re.S)                     # plate / warning comments
        code = "\n".join(l.rstrip() for l in body.split("\n") if l.strip() and not l.strip().startswith("//"))
        out[int(m.group(2), 16)] = (m.group(1), code)
    return out


before, after = functions(sys.argv[1]), functions(sys.argv[2])
gone = sorted(set(before) - set(after))
new = sorted(set(after) - set(before))
changed = [a for a in sorted(set(before) & set(after)) if before[a][1] != after[a][1]]
renamed = [a for a in sorted(set(before) & set(after)) if before[a][0] != after[a][0]]
print(f"{len(before)} functions before, {len(after)} after")
print(f"left ({len(gone)}): " + " ".join(f"{a:x}:{before[a][0]}" for a in gone))
print(f"arrived ({len(new)}): " + " ".join(f"{a:x}:{after[a][0]}" for a in new))
print(f"same address, different name ({len(renamed)}): " + " ".join(f"{a:x}" for a in renamed))
print(f"same address, different code ({len(changed)}): " + " ".join(f"{a:x}:{after[a][0]}" for a in changed))
for a in changed[:6]:
    b, c = before[a][1].split("\n"), after[a][1].split("\n")
    diff = [(x, y) for x, y in zip(b, c) if x != y][:3]
    print(f"  {a:x} {after[a][0]}: {len(b)} -> {len(c)} lines; first differences: {diff}")

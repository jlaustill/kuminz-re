"""Caller-side census of a build: for each changed function, count the decompiler artifacts that a wrong or phantom
prototype row shows at call sites (unaff_ / extraout_ / in_ at any offset / uStack / CONCAT), before and after, and
list every function whose count went up. usage: caller_census.py <pre cpp> <post cpp> <function_set_check output>"""
import re
import sys

ARTIFACTS = {"unaff_": r"\bunaff_\w+", "extraout_": r"\bextraout_\w+", "in_": r"\bin_\w+", "uStack": r"\buStack_\w+",
             "CONCAT": r"\bCONCAT\d+"}


def functions(path):
    text = re.sub(r"/\*.*?\*/", "", open(path, errors="replace").read(), flags=re.S)
    parts = re.split(r"^// Function: (\S+) @ (0x[0-9a-f]+)[^\n]*\n", text, flags=re.M)
    return {parts[i + 1]: (parts[i], parts[i + 2]) for i in range(1, len(parts), 3)}


pre, post = functions(sys.argv[1]), functions(sys.argv[2])
changed = [l.split()[0] for l in open(sys.argv[3]) if re.match(r"^  0x[0-9a-f]+ ", l)]
totals = {k: [0, 0] for k in ARTIFACTS}
rose = []
for address in changed:
    before, after = pre[address][1], post[address][1]
    deltas = {}
    for k, rx in ARTIFACTS.items():
        a, z = len(re.findall(rx, before)), len(re.findall(rx, after))
        totals[k][0] += a
        totals[k][1] += z
        if z > a:
            deltas[k] = (a, z, sorted(set(re.findall(rx, after)) - set(re.findall(rx, before)))[:4])
    if deltas:
        rose.append((address, post[address][0], deltas))
print("totals over the changed functions (before -> after):",
      ", ".join(f"{k} {a} -> {z}" for k, (a, z) in totals.items()))
print(f"{len(rose)} functions with a count that went up:")
for address, name, deltas in rose:
    print(f"  {address} {name}: {deltas}")

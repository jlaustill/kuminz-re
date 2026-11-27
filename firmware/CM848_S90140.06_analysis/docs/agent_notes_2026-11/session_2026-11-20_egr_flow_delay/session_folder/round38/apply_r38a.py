"""Round 38 stage A: fix the named lookup cache rows that cache_audit.py flags.
- Widen: a 2-D cache typed word becomes word[2] (its y offset was unnamed), when the second word holds no row; a name
  ending _cached_axis_offset becomes _cached_axis_offsets.
- Rename: a cache whose name is not its own lookup's (a legacy guess) takes <data table>_cached_axis_offset(s), when
  that name is clean (no banned abbreviation / no _cal / no phantom / no unnamed table / not taken).
Writes the proof map (address,name,old_label,kind,dims). Idempotent per row.
usage: apply_r38a.py <repo> <cpp> <map.csv>"""
import ast
import os
import re
import sys
from collections import defaultdict

repo, cpp, map_path = os.path.abspath(sys.argv[1]), sys.argv[2], sys.argv[3]
src = open("/home/linux/.claude/jobs/374b0424/tmp/w15/apply_hand_worklist.py").read()
BANNED = ast.literal_eval(re.search(r"BANNED = (\{.*?\})", src, re.S).group(1))  # the gate's set literal
gp = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output/global_variables.csv")
g = open(gp).read().split("\n")
by_name, by_addr = {}, {}
for i, l in enumerate(g):
    p = l.split(",", 3)
    if len(p) >= 3 and p[0].startswith("0x"):
        by_addr.setdefault(int(p[0], 16), []).append(i)
        if p[1]:
            by_name[p[1]] = (int(p[0], 16), p[2], i)
text = open(cpp, errors="replace").read()
uses = defaultdict(list)
for m in re.finditer(r"\b(lookupTableInterpolation|cm848_dualAxisTableInterpolation)\s*\(([^;]*?)\);", text, re.S):
    args = [a.strip() for a in re.sub(r"\s+", " ", m.group(2)).split(",")]
    first = args[0].lstrip("&").split("[")[0].strip()
    if first in by_name:
        dims = 1 if m.group(1) == "lookupTableInterpolation" else 2
        data = args[3] if dims == 1 else (args[5] if len(args) > 5 else "")
        uses[first].append((dims, re.sub(r"(_values|_grid)$", "", data.lstrip("&").split("[")[0].replace(
            "(word *)", "").strip())))
taken = set(by_name)
g_types = {v[0]: v[1] for v in by_name.values()}
plan, skipped = [], []
for name, us in sorted(uses.items()):
    a, typ, row = by_name[name]
    dims = {u[0] for u in us}
    bases = sorted({u[1] for u in us})
    if len(dims) != 1:
        continue
    d = dims.pop()
    widen = d == 2 and typ == "word"
    merge = None
    if widen and (by_addr.get(a + 1) or by_addr.get(a + 3)):
        skipped.append(f"0x{a:06x} {name}: a byte row inside the cache")
        widen = False
    elif widen and by_addr.get(a + 2):
        rows2 = [g[i].split(",", 3) for i in by_addr[a + 2]]
        n2 = rows2[0][1] if len(rows2) == 1 else ""
        renders = re.findall(r"[^\n;{}]*\b" + re.escape(n2) + r"\b[^\n;{}]*", text) if n2 else []
        if n2 and rows2[0][2] == "word" and n2 not in uses and all(re.fullmatch(r"\s*" + re.escape(n2) + r" = (?:0x)?[0-9a-f]+\s*", r) for r in renders):
            merge = (by_addr[a + 2][0], n2)
        else:
            skipped.append(f"0x{a:06x} {name}: the second word holds a row that is more than the y half")
            widen = False
    new = name
    if len(bases) == 1:
        want = bases[0] + ("_cached_axis_offset" if d == 1 else "_cached_axis_offsets")
        bad = (any(t in BANNED for t in want.split("_")) or "_cal_" in want or "in_r" in want or "WORD_ARRAY" in want
               or "PTR_" in want or not re.match(r"^[a-z][a-z0-9_]+$", want))
        if want != name and not bad and want not in taken:
            if not (name.endswith("_2") and want == name[:-2]):
                new = want
        elif want != name and not bad and want in taken and not name.endswith("_2") and want + "_2" not in taken \
                and not re.search(r"_cached_axis_offsets?$", name):
            new = want + "_2"
        elif want != name:
            skipped.append(f"0x{a:06x} {name}: {want} is {'taken' if want in taken else 'not clean'}")
    if widen and new == name and name.endswith("_cached_axis_offset"):
        new = name + "s"
    if typ == "word[2]" and d == 1:
        continue  # two 1-D caches side by side: leave
    if widen and new == name and not re.search(r"_cached_axis_offsets?$", name):
        skipped.append(f"0x{a:06x} {name}: no clean name for the widened cache")
        widen, merge = False, None
    if new != name or widen:
        plan.append((a, name, new, "word[2]" if widen else typ, d, row, merge))
        taken.add(new)
for a, old, new, typ, d, row, merge in plan:
    if merge:
        i2, n2 = merge
        q = g[i2].split(",", 3)
        g[i2] = f"{q[0]},{new}[1],,the y segment offset of {new} (was {n2}; PR #53 round 38) | earlier note: {q[3] if len(q) > 3 else ''}"
    p = g[row].split(",", 3)
    note = p[3] if len(p) > 3 else ""
    what = ("widened to word[2]: a 2-D cache's x / y segment offsets" if typ != p[2] else "named after its own lookup")
    g[row] = f"{p[0]},{new},{typ},{what} (was {old}; PR #53 round 38) | earlier note: {note}"
open(gp, "w").write("\n".join(g))
with open(map_path, "w") as fh:
    fh.write("address,name,old_label,kind,dims\n")
    for a, old, new, typ, d, row, merge in plan:
        widened = typ == "word[2]" and g_types[a] == "word"
        fh.write(f"0x{a:08x},{new},{old},global,{2 if widened else 1}\n")
        if merge:
            fh.write(f"0x{a + 2:08x},{new}[1],{merge[1]},global,1\n")
print(f"{len(plan)} rows changed ({sum(1 for x in plan if x[3] == 'word[2]')} word[2], {sum(1 for x in plan if x[6])} merged y halves), {len(skipped)} skipped")
for s in skipped:
    print("SKIP", s[:200])

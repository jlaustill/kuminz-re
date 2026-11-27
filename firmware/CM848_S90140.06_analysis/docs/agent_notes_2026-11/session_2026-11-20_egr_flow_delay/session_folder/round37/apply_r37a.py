"""Round 37 stage A: name the unnamed lookup cache words from their own lookups (cache_names.tsv), and the pilot
quantity blend maps' shared cache (0x3fd134, timing_limit_boost_blend_cached_axis_offset -> word[2]).
Drops a name with a banned abbreviation (the rename gate's list) or a legacy _cal (a cache is never EEPROM data), and
a 2-D cache whose second word holds a row or another cache. Inserts sorted rows. Writes the proof map
(address,name,old_label,kind,dims). Idempotent.  usage: apply_r37a.py <repo> <cache_names.tsv> <map.csv>"""
import ast
import os
import re
import sys

repo, tsv, map_path = os.path.abspath(sys.argv[1]), sys.argv[2], sys.argv[3]
src = open("/home/linux/.claude/jobs/374b0424/tmp/w15/apply_hand_worklist.py").read()
BANNED = ast.literal_eval(re.search(r"BANNED = (\{.*?\})", src, re.S).group(1))  # the gate's set literal, parsed safely
out = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")
gp = os.path.join(out, "global_variables.csv")
g = open(gp).read().split("\n")
rows = {int(l[:10], 16): l for l in g if l.startswith("0x")}
cands = []
for l in open(tsv):
    if l.strip():
        a, name, typ, how = l.rstrip("\n").split("\t")
        cands.append((int(a, 16), name, typ, how))
starts = {a for a, *_ in cands}
keep, dropped = [], []
for a, name, typ, how in cands:
    tokens = name.split("_")
    if any(t in BANNED for t in tokens) or "_cal_" in name:
        dropped.append(f"0x{a:06x} {name}: banned word or legacy _cal")
        continue
    if typ == "word[2]" and (a + 2 in rows or a + 2 in starts or a + 1 in rows or a + 3 in rows):
        dropped.append(f"0x{a:06x} {name}: the second word holds a row or another cache")
        continue
    keep.append((a, name, typ, how))
map_rows = ["address,name,old_label,kind,dims"]
for a, name, typ, how in keep:
    line = f"0x{a:08x},{name},{typ},the lookup cache of {name.replace('_cached_axis_offsets', '').replace('_cached_axis_offset', '')} ({'2-D: the x / y segment offsets' if typ == 'word[2]' else '1-D: the segment offset'} of the last lookup; {how}; PR #53 round 37)"
    if a in rows and rows[a].split(",")[1] == "":
        i = g.index(rows[a])
        g[i] = line
    elif a not in rows:
        j = max(k for k, l in enumerate(g) if l.startswith("0x") and int(l[:10], 16) < a)
        g.insert(j + 1, line)
    map_rows.append(f"0x{a:08x},{name},DAT_{a:08x},global,{2 if typ == 'word[2]' else 1}")
OLD134 = "0x003fd134,timing_limit_boost_blend_cached_axis_offset,word,"
for i, l in enumerate(g):
    if l.startswith(OLD134):
        g[i] = ("0x003fd134,injection_quantity_pilot_blend_map_cached_axis_offsets,word[2],the shared 2-D lookup cache of "
                "the pilot quantity blend maps injection_quantity_pilot_map_1-4 (8 cm848_dualAxisTableInterpolation "
                "calls in cm848_calculatePilotInjectionQuantity; cm848_initializePilotInjectionQuantityState resets both "
                "words) (was timing_limit_boost_blend_cached_axis_offset; PR #53 round 37) | earlier note: "
                + l[len(OLD134):])
map_rows.append("0x003fd134,injection_quantity_pilot_blend_map_cached_axis_offsets,"
                "timing_limit_boost_blend_cached_axis_offset,global,2")
open(gp, "w").write("\n".join(g))
with open(map_path, "w") as fh:
    fh.write("\n".join(map_rows) + "\n")
print(f"{len(keep)} cache rows (+0x3fd134), {len(dropped)} dropped")
for d in dropped:
    print("DROP", d)

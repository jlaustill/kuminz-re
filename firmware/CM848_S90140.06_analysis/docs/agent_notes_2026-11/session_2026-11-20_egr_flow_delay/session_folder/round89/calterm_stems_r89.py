"""Round 89 stage C input (read-only): which e2m original carries J90350.00's A/D channel layout, and each channel's
Calterm stem. e2m block 1003 = the 25 sensor_config_t records (0x806ae2 + 24 x k), block 1004 = the 25 runtime
records (0x80a2aa + 22 x k). A file matches when its block 1003 / 1004 parameters agree with the CM550 rows at the same
addresses before round 89 stage B (git show <rev>): the e2m comment normalized like the importer did
(lowercase, non-alphanumeric -> _) is the row name's start, or the row is the mnemonic itself (NAME / name_param).
usage: calterm_stems_r89.py <repo> <rev before stage B> <out.tsv>"""
import collections
import glob
import os
import re
import subprocess
import sys

repo, rev, out = sys.argv[1], sys.argv[2], sys.argv[3]
G5 = "firmware/CM550_J90350.00_analysis/output/global_variables.csv"
old = {}
for line in subprocess.run(["git", "-C", repo, "show", f"{rev}:{G5}"], capture_output=True, text=True).stdout.split("\n"):
    if line.startswith("0x"):
        p = line.split(",")
        old[int(p[0], 16)] = p[1]
BLOCKS = {"1003": (0x806ae2, 24), "1004": (0x80a2aa, 22)}


def norm(s):
    return re.sub(r"[^a-z0-9]+", "_", s.lower()).strip("_")


def parse(path):
    params = {}
    for raw in open(path, encoding="latin-1"):
        data, _, comment = raw.rstrip("\r\n").partition(";")
        c = data.split(",")
        if len(c) < 12 or c[2] not in BLOCKS:
            continue
        try:
            offset = int(c[3], 16)
        except ValueError:
            continue
        base, stride = BLOCKS[c[2]]
        params[(c[2], offset)] = {"name": c[0], "unit": c[1], "length": c[7], "signed": c[9], "scale": c[10],
                                  "minimum": c[11], "comment": comment.strip(), "address": base + offset}
    return params


def matches(p):
    row = old.get(p["address"])
    if not row:
        return None
    n = norm(p["comment"].replace("~", " "))
    return row == p["name"] or row.lower() == p["name"].lower() + "_param" or (n and row.startswith(n[:24]))


scores = []
for f in sorted(glob.glob(os.path.join(repo, "e2m-analysis/originals/*.e2m"))):
    params = parse(f)
    if not params:
        continue
    results = [matches(p) for p in params.values()]
    checked = [r for r in results if r is not None]
    scores.append((sum(checked), len(checked), len(params), os.path.basename(f)))
scores.sort(reverse=True)
for s in scores[:6]:
    print(f"{s[3]}: {s[0]}/{s[1]} rows agree ({s[2]} block 1003/1004 parameters)")
best = os.path.join(repo, "e2m-analysis/originals", scores[0][3])
params = parse(best)
with open(out, "w") as fh:
    fh.write("channel\tblock\toffset\taddress\tname\tunit\tsigned\tscale\tminimum\tcomment\told_row\tagrees\n")
    for (block, offset), p in sorted(params.items(), key=lambda kv: (kv[0][0], kv[0][1])):
        base, stride = BLOCKS[block]
        fh.write(f"{offset // stride}\t{block}\t{offset % stride}\t0x{p['address']:x}\t{p['name']}\t{p['unit']}\t"
                 f"{p['signed']}\t{p['scale']}\t{p['minimum']}\t{p['comment']}\t{old.get(p['address'], '')}\t"
                 f"{matches(p)}\n")
stems = collections.defaultdict(set)
for (block, offset), p in params.items():
    base, stride = BLOCKS[block]
    stems[offset // stride].add(p["name"][:-2])
print("best:", scores[0][3])
for k in sorted(stems):
    print(k, sorted(stems[k]))

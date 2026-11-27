"""Round 52: find absent (not table-resolved) CHR_CC blocks whose layout matches EXISTING rows record for record - the
pattern that placed 8B9A / 8BB4 / 8C2D / 8B6C / 8B6D in round 51 / 52. For every absent block and every base that
puts one of its records on an existing row start, count the records that land on a row start of the same width;
reject the base if any record lands inside another row or on a row start of a different known width. Blocks whose
records are already cited somewhere (`e2m <block> +`) are skipped. Prints bases with >= 3 matched records, most
first, with the record / row names side by side for a by-meaning review.
usage: record_for_record_matches.py <repo> [min matched]"""
import bisect
import contextlib
import csv
import io
import os
import re
import sys

sys.path.insert(0, "/home/linux/.claude/jobs/374b0424/tmp/w15/r45")
repo = os.path.abspath(sys.argv[1])
need = int(sys.argv[2]) if len(sys.argv) > 2 else 3
sys.argv = [sys.argv[0], repo, "64"]
with contextlib.redirect_stdout(io.StringIO()):
    import sweep_table_gaps as s  # noqa: E402  (absent blocks with the default-release layout)
out = os.path.join(s.CM, "output")
WIDTH = {"byte": 1, "bool": 1, "char": 1, "word": 2, "i16": 2, "short": 2, "dword": 4, "i32": 4, "float": 4}
enum_size = {}
for r in csv.reader(open(os.path.join(out, "enums.csv"))):
    if r and not r[0].startswith("#") and len(r) >= 5 and r[4].strip().isdigit():
        enum_size[r[0]] = int(r[4])
struct_size = {}
for r in csv.reader(open(os.path.join(out, "structure_definitions.csv"))):
    if r and not r[0].startswith("#") and len(r) >= 5 and r[0] != "struct_name" and r[4].strip().isdigit():
        if r[1] and r[2] == "":
            continue  # marker row of a further instance
        struct_size[r[0]] = struct_size.get(r[0], 0) + int(r[4])


def width_of(typ):
    m = re.fullmatch(r"([A-Za-z_0-9]+)\[(\d+)\]", typ)
    if m:
        w = width_of(m.group(1))[0]
        return (w * int(m.group(2)), True) if w else (None, True)
    if typ in WIDTH:
        return WIDTH[typ], False
    if typ in enum_size:
        return enum_size[typ], False
    if typ.endswith("*"):
        return 4, False
    if typ in struct_size:
        return struct_size[typ], True
    return None, False


rows, comments, cited = {}, [], set()
for r in csv.reader(open(os.path.join(out, "global_variables.csv"))):
    if r and r[0].startswith("0x") and len(r) > 2 and "." not in r[1]:
        w, aggregate = width_of(r[2])
        rows[int(r[0], 16)] = (r[1], w, aggregate)
        comments.append(r[3] if len(r) > 3 else "")
        if re.search(r"e2m [0-9A-F]{4} \+", r[3] if len(r) > 3 else ""):
            cited.add(int(r[0], 16))
alltext = "\n".join(comments)
inside = {}
for a, (name, w, aggregate) in rows.items():
    for k in range(1, w or 1):
        inside[a + k] = a
starts = sorted(rows)
cited_sorted = sorted(cited)
results = []
for b, (rel, recs) in s.absent.items():
    if len(recs) < need or re.search(rf"e2m {b:04X} \+", alltext):
        continue
    offs = sorted(recs)
    bases = set()
    for o in offs[:2]:  # a placement worth reviewing puts the block's first or second record on a row
        for a in starts:
            bases.add(a - o)
    span_end = max(o + (recs[o][2] or 1) for o in offs)
    per_block = []
    for base in bases:
        k = bisect.bisect_left(cited_sorted, base)
        if k < len(cited_sorted) and cited_sorted[k] < base + span_end:
            continue  # the span already holds a row cited from some e2m block
        matched, mixed, conflict, names = 0, False, False, []
        for o in offs:
            name, typ, size, desc = recs[o]
            a = base + o
            if a in inside:
                conflict = True
                break
            if a in rows:
                rw = rows[a][1]
                if rw is not None and size and rw != size and not rows[a][2]:
                    conflict = True
                    break
                if rw == size:
                    matched += 1
                    mixed |= size != 2
                    names.append(f"{name}={rows[a][0]}")
        lo_k, hi_k = bisect.bisect_left(starts, base), bisect.bisect_left(starts, base + span_end)
        uncovered = sum(1 for a in starts[lo_k:hi_k] if a - base not in recs)
        if not conflict and matched >= need:
            per_block.append((mixed, matched, -uncovered, len(offs), b, base, names))
    per_block.sort(reverse=True)
    results += per_block[:3]
results.sort(key=lambda r: (r[0], r[1] / r[3], r[1]), reverse=True)
for mixed, matched, unc, total, b, base, names in results[:90]:
    print(f"{b:04X} @ {base:#x}: {matched}/{total} matched{' (mixed widths)' if mixed else ''}, {-unc} rows inside "
          "uncovered | " + "; ".join(names[:5])[:250])
print(f"{len(results)} candidate placements (best 3 per block)")

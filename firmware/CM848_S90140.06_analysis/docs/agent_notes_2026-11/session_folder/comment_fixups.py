"""Comment-only fix-ups for PR #50 (no names, types or addresses change).

1. Bodies the apply scripts cut at 400 characters (`{evidence[:400]} (was X)` / `(new row D)`, in any
   ` | earlier note: ` segment) are re-cut at a word boundary and marked ` ...`; the full text is
   recovered from the agents' result files when one starts with the body.
2. Default struct labels `<type>_t_<8 hex>` in comments whose address now has a named row -> that name.
3. Specific stale mentions (retired names) -> current names.
4. Wave-7 new rows: `(new row 2026-11-16)` -> `(new row 2026-11-17)`.
usage: comment_fixups.py <output dir> <tmp dir> [--apply]"""
import csv
import glob
import json
import re
import sys

out, tmp = sys.argv[1], sys.argv[2]
apply = "--apply" in sys.argv
LIMIT = 400

full_texts = {}
for path in glob.glob(f"{tmp}/renames/*.jsonl") + glob.glob(f"{tmp}/tables/*.jsonl"):
    for line in open(path, errors="replace"):
        try:
            r = json.loads(line)
        except ValueError:
            continue
        if not isinstance(r, dict):
            continue
        for k in ("evidence", "plate_comment", "comment", "text"):
            v = r.get(k)
            if isinstance(v, str):
                v = " ".join(v.split())
                if len(v) > LIMIT:
                    full_texts.setdefault(v[:LIMIT], v)

names = {}
for row in csv.reader(open(f"{out}/global_variables.csv")):
    if len(row) > 1 and row[0].startswith("0x") and row[1]:
        names.setdefault(int(row[0], 16), row[1])

w7_new = {r["address"].lower() for r in csv.DictReader(open(f"{tmp}/renames/mapping_w7_newrows.csv"))}
STALE = [("used by mpc555_updateSensorDiagnosticFlags", "used by cm848_updateEngineSpeedFromCrankSignal"),
         ("main timing source_priority", "main_injection_timing_source_code")]
SEGMENT = re.compile(r"^(.{%d}) (\((?:was [^)]*|new row [0-9-]+)\))(.*)$" % LIMIT, re.S)
LABEL = re.compile(r"\b([a-z][a-z0-9_]*_t)_([0-9a-f]{8})\b")
WAS = re.compile(r"\((?:was|were) [^)]*\)")
stats = {"truncated": 0, "recovered": 0, "labels": 0, "stale": 0, "date": 0}
samples = []


def recut(body):
    full = full_texts.get(body)
    if full:
        stats["recovered"] += 1
        complete_word = full[LIMIT].isspace()
    else:
        complete_word = not (body[-1].isalnum() or body[-1] == "_")
    cut = body if complete_word else body[: body.rfind(" ")]
    return cut.rstrip(" ,;:(-/") + " ..."


def fix_comment(c, address):
    orig = c
    segs = c.split(" | earlier note: ")
    for i, seg in enumerate(segs):
        m = SEGMENT.match(seg)
        if m:
            stats["truncated"] += 1
            segs[i] = f"{recut(m.group(1))} {m.group(2)}{m.group(3)}"
    c = " | earlier note: ".join(segs)

    def label(m):
        a = int(m.group(2), 16)
        if a in names:
            stats["labels"] += 1
            return names[a]
        return m.group(0)

    parts, last = [], 0
    for m in WAS.finditer(c):                      # never touch history inside (was ...)
        parts.append(LABEL.sub(label, c[last:m.start()]))
        parts.append(m.group(0))
        last = m.end()
    parts.append(LABEL.sub(label, c[last:]))
    c = "".join(parts)
    for o, n in STALE:
        if o in c:
            stats["stale"] += 1
            c = c.replace(o, n)
    if address in w7_new and "(new row 2026-11-16)" in c:
        stats["date"] += 1
        c = c.replace("(new row 2026-11-16)", "(new row 2026-11-17)")
    if c != orig and len(samples) < 6:
        samples.append((orig[-150:], c[-150:]))
    return c


for name, col in (("global_variables.csv", 3), ("function_renames.csv", 2)):
    path = f"{out}/{name}"
    lines = open(path).read().split("\n")
    changed = 0
    for i, line in enumerate(lines):
        p = line.split(",", col)
        if len(p) <= col or not p[0].startswith("0x"):
            continue
        new = fix_comment(p[col], p[0].lower())
        if new != p[col]:
            p[col] = new
            lines[i] = ",".join(p)
            changed += 1
    print(f"{name}: {changed} rows changed")
    if apply:
        open(path, "w").write("\n".join(lines))
print(stats)
for o, n in samples:
    print("  -", o, "\n  +", n)

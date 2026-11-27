"""Round 47: the default e2m's layout drifts from this firmware for some blocks (0x40b210 resolves to 8A0F +C
Prev_Debounced_CC_Switch_Mux, but the code proves it is the warning chime request). So a low-score row is only a lead
inside a block whose other rows match their records. For every table block with resolved, named rows: the share of rows
whose words match their record (score >= 0.3, cited rows count as matching); then the low-score rows (< 0.15) of the
blocks that are at least 70 % consistent with 3 or more rows.
usage: block_reliability.py <repo>"""
import contextlib
import csv
import io
import os
import re
import sys

repo = os.path.abspath(sys.argv[1])
sys.path.insert(0, os.path.join(repo, "firmware/scripts"))
sys.path.insert(0, "/home/linux/.claude/jobs/374b0424/tmp/w15/r45")
import e2m_block_addresses as e  # noqa: E402

with contextlib.redirect_stdout(io.StringIO()):
    sys.argv = [sys.argv[0], repo, "8"]
    import rank_gap_semantics as rs  # noqa: E402

table = e.parse_table(open(e.DEFAULTS["flash2"], "rb").read())
recs = {}
for line in open(os.path.join(repo, "e2m-analysis/CHR/CHR_CC_11.45.01.07.e2m"), errors="replace"):
    head, _, desc = line.strip().partition(";")
    f = head.split(",")
    if len(f) > 11 and re.fullmatch(r"[0-9A-Fa-f]{4}", f[2]) and re.fullmatch(r"[0-9A-Fa-f]{1,4}", f[3]):
        b, o = int(f[2], 16), int(f[3], 16)
        if b in table and f[5] in ("N", "S", "B"):
            a = table[b] + o
            if a >= 0x01000000:
                a = 0x3FD482 + (a - 0x01000000)
            recs.setdefault(a, (b, o, f[0], f[7], desc.strip()))
per_block = {}
for r in csv.reader(open(os.path.join(repo, "firmware/CM848_S90140.06_analysis/output/global_variables.csv"))):
    if r and r[0].startswith("0x") and len(r) > 1 and r[1] and "." not in r[1] and "[" not in r[1]:
        a = int(r[0], 16)
        if a not in recs:
            continue
        b, o, name, size, desc = recs[a]
        comment = r[3] if len(r) > 3 else ""
        cited = f"e2m {b:04X}" in comment or name in comment
        rw, cw = rs.words(name) | rs.words(desc), rs.words(r[1]) | rs.words(comment[:300])
        score = 1.0 if cited else len(rw & cw) / max(1, len(rw))
        per_block.setdefault(b, []).append((score, cited, a, r[1], r[2], o, name, desc[:90]))
good, leads = [], []
for b, items in per_block.items():
    n = len(items)
    ok = sum(1 for s, *_ in items if s >= 0.3)
    if n >= 3 and ok / n >= 0.7:
        good.append(b)
        for s, cited, a, nm, t, o, name, desc in items:
            if not cited and s < 0.15:
                leads.append((b, ok, n, s, a, nm, t, o, name, desc))
print(f"{len(per_block)} blocks with resolved named rows; {len(good)} are >= 70 % consistent with 3+ rows; "
      f"{len(leads)} low-score rows inside those")
for b, ok, n, s, a, nm, t, o, name, desc in sorted(leads):
    print(f"{b:04X} ({ok}/{n} rows match) {s:.2f} {a:#x} {nm} [{t}] <- +{o:X} {name}: {desc}")

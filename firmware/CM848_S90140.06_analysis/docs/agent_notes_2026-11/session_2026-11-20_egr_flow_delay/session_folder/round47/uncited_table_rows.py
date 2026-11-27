"""Round 47: rows whose address the dumped parameter ID table resolves to a default-e2m record, but whose comment does
not cite that block ('e2m XXXX'). Round 46 found such a family (8C49 RE_RCTM_* under park_neutral_exit_* names).
Ranks them by the words the record (name + description) shares with the row (name + comment): a low score is a
possible misread to check against the code.
usage: uncited_table_rows.py <repo>"""
import csv
import os
import re
import sys

repo = os.path.abspath(sys.argv[1])
sys.path.insert(0, os.path.join(repo, "firmware/scripts"))
sys.path.insert(0, "/home/linux/.claude/jobs/374b0424/tmp/w15/r45")
import e2m_block_addresses as e  # noqa: E402
import contextlib  # noqa: E402
import io  # noqa: E402

with contextlib.redirect_stdout(io.StringIO()):
    sys.argv = [sys.argv[0], repo, "8"]
    import rank_gap_semantics as rs  # noqa: E402  (its word normaliser)

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
rows = []
for r in csv.reader(open(os.path.join(repo, "firmware/CM848_S90140.06_analysis/output/global_variables.csv"))):
    if r and r[0].startswith("0x") and len(r) > 1 and r[1] and "." not in r[1] and "[" not in r[1]:
        a = int(r[0], 16)
        if a in recs:
            b, o, name, size, desc = recs[a]
            comment = r[3] if len(r) > 3 else ""
            if f"e2m {b:04X}" in comment or name in comment:
                continue
            rw, cw = rs.words(name) | rs.words(desc), rs.words(r[1]) | rs.words(comment[:300])
            score = len(rw & cw) / max(1, len(rw))
            rows.append((score, a, r[1], r[2], b, o, name, size, desc[:90]))
rows.sort()
print(f"{len(recs)} default-e2m scalar records resolve through the dumped table; {len(rows)} rows at those addresses "
      f"do not cite their block")
for score, a, n, t, b, o, name, size, desc in rows:
    print(f"{score:.2f} {a:#x} {n} [{t}] <- {b:04X} +{o:X} {name} [{size}]: {desc}")

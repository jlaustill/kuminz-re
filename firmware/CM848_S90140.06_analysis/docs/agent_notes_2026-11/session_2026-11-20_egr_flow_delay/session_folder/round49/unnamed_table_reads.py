"""Round 49: unnamed data the .cpp reads (DAT_ / WORD_ / BYTE_ / DWORD_ tokens) at addresses the dumped parameter ID
table resolves to a default-e2m scalar record. Each hit is graded by its block's consistency (the share of the block's
named rows whose words match their records; round 47's guard against layout drift) and listed with the functions
that read it.  usage: unnamed_table_reads.py <repo>"""
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

CM = os.path.join(repo, "firmware/CM848_S90140.06_analysis")
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
            recs.setdefault(a, (b, o, f[0], f[1], f[7], f[9], f[10], desc.strip()))
rows = {}
for r in csv.reader(open(os.path.join(CM, "output/global_variables.csv"))):
    if r and r[0].startswith("0x"):
        rows[int(r[0], 16)] = r
# block consistency over named rows
score = {}
for a, (b, o, name, unit, size, sign, scale, desc) in recs.items():
    r = rows.get(a)
    if not r or not r[1] or "." in r[1] or "[" in r[1]:
        continue
    comment = r[3] if len(r) > 3 else ""
    cited = f"e2m {b:04X}" in comment or name in comment
    rw, cw = rs.words(name) | rs.words(desc), rs.words(r[1]) | rs.words(comment[:300])
    ok = cited or len(rw & cw) / max(1, len(rw)) >= 0.3
    n, k = score.get(b, (0, 0))
    score[b] = (n + 1, k + (1 if ok else 0))
cpp = open(os.path.join(CM, "output/cm848_rom.ghidra.cpp"), errors="replace").read()
users = {}
for m in re.finditer(r"\b(?:DAT|WORD|BYTE|DWORD|_DAT)_00([0-9a-f]{6})\b", cpp):
    a = int(m.group(1), 16)
    s = cpp.rfind("// Function: ", 0, m.start())
    users.setdefault(a, set()).add(cpp[s + 13:cpp.find(" @", s)] if s != -1 else "?")
hits = []
for a, fs in users.items():
    if a in recs and a not in rows:
        b, o, name, unit, size, sign, scale, desc = recs[a]
        n, k = score.get(b, (0, 0))
        hits.append((-(k / n if n else 0), b, o, a, name, unit, size, sign, scale, desc, n, k, sorted(fs)))
hits.sort()
print(f"{len(users)} unnamed addresses read; {len(hits)} resolve to a default-e2m record through the dumped table")
for neg, b, o, a, name, unit, size, sign, scale, desc, n, k, fs in hits:
    print(f"{b:04X} ({k}/{n}) +{o:X} {a:#x} {name} [{unit} {sign}{size} x{scale}] <- {', '.join(fs)[:80]}: {desc[:80]}")

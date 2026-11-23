"""Round 46: the gap sweep's remainder.
(a) For each gap with PERFECT width matches that round 45 did not decide, rank only those width-matching candidates by
    shared words with the rows' names / comments.
(b) For every gap, list the unnamed data the .cpp reads inside it (DAT_ / WORD_ / BYTE_ / DWORD_ tokens) - the rows a
    placement would add - and the candidates whose records land on those addresses with a plausible width.
usage: gap_leads.py <repo>"""
import contextlib
import csv
import io
import os
import re
import sys

sys.path.insert(0, "/home/linux/.claude/jobs/374b0424/tmp/w15/r45")
repo = os.path.abspath(sys.argv[1])
sys.argv = [sys.argv[0], repo, "64"]
with contextlib.redirect_stdout(io.StringIO()):
    import match_gap_signatures as m  # noqa: E402
    import rank_gap_semantics as rs  # noqa: E402
s = m.s
DONE = {0x3ff6ca, 0x408a66, 0x408e96, 0x40913a, 0x409a8a, 0x409ec6, 0x40a264, 0x40b54a, 0x40b64e, 0x1000034}
cpp = open(os.path.join(s.CM, "output/cm848_rom.ghidra.cpp"), errors="replace").read()
unnamed = {}
for tok in re.findall(r"\b(?:DAT|WORD|BYTE|DWORD|_DAT)_00([0-9a-f]{6})\b", cpp):
    a = int(tok, 16)
    unnamed[a] = unnamed.get(a, 0) + 1
rows = {}
for r in csv.reader(open(os.path.join(s.CM, "output/global_variables.csv"))):
    if r and r[0].startswith("0x"):
        rows[int(r[0], 16)] = (r[1], r[3] if len(r) > 3 else "")
print("== (a) perfect-match gaps not yet decided: width-matching candidates ranked by shared words")
for start, gap, b1, b2 in s.gaps:
    if start in DONE:
        continue
    cands = []
    for b, x in m.sizes.items():
        if x == gap or (x % 2 and x + 1 == gap):
            if m.score(start, gap, [(b, 0)])[0]:
                cands.append(b)
    if not cands:
        continue
    in_gap = [rows[a] for a in sorted(rows) if start <= a < start + gap]
    row_words = set()
    for n, c in in_gap:
        row_words |= rs.words(n) | rs.words(c[:200])
    ranked = []
    for b in cands:
        rec_words = set()
        for name, _, _, desc in s.absent[b][1].values():
            rec_words |= rs.words(name) | rs.words(desc)
        common = rec_words & row_words
        ranked.append((len(common) / max(1, len(rec_words)), b, sorted(common)[:8]))
    ranked.sort(reverse=True)
    print(f"gap {start:#09x} +{gap} after {b1:04X} before {b2:04X}: {len(cands)} candidates; rows: "
          f"{', '.join(n for n, _ in in_gap)[:120]}")
    for sc, b, common in ranked[:3]:
        recs = s.absent[b][1]
        print(f"   {sc:.2f} {b:04X} {[recs[o][0] for o in sorted(recs)][:4]} {common}")
print("\n== (b) unnamed data the .cpp reads inside a gap")
for start, gap, b1, b2 in s.gaps:
    hits = {a: n for a, n in unnamed.items() if start <= a < start + gap}
    if hits:
        print(f"gap {start:#09x} +{gap} after {b1:04X} before {b2:04X}: " +
              ", ".join(f"{a:#x} x{n}" for a, n in sorted(hits.items())))

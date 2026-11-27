"""Round 45: for each gap with PERFECT width matches (match_gap_signatures.py), rank the candidates by how well their
record names / descriptions share words with the CM848 rows' names and comments in the gap. A high score is a lead to
read, not a proof.  usage: rank_gap_semantics.py <repo> [max_gap]"""
import contextlib
import csv
import io
import os
import re
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
repo = os.path.abspath(sys.argv[1])
max_gap = sys.argv[2] if len(sys.argv) > 2 else "64"
sys.argv = [sys.argv[0], repo, max_gap]
with contextlib.redirect_stdout(io.StringIO()):
    import match_gap_signatures as m  # noqa: E402

STOP = set("the a an of to in for and or is be this that if than when with by at on as it its value cal flag per "
           "from into not used set while only one two pass passes was round pr 53 e2m".split())
SYN = {"rpm": "speed", "temp": "temperature", "thd": "threshold", "thr": "threshold", "max": "maximum", "min": "minimum",
       "cnt": "count", "counts": "count", "ctr": "counter", "pct": "percent", "spd": "speed", "veh": "vehicle",
       "eng": "engine", "fuelpr": "fuel pressure", "fp": "fuel pressure", "accel": "accelerator", "throt": "throttle",
       "tps": "throttle", "pps": "pedal", "dc": "duty", "pwm": "duty", "lvl": "level", "coeff": "coefficient",
       "filt": "filter", "cc": "cruise", "eb": "exhaust brake", "vss": "vehicle speed", "ect": "coolant"}


def words(text):
    text = re.sub(r"([a-z])([A-Z])", r"\1 \2", text)
    out = set()
    for w in re.split(r"[^A-Za-z0-9]+", text.lower()):
        if w and w not in STOP and not w.isdigit():
            for x in SYN.get(w, w).split():
                out.add(x)
    return out


rows = {}
for r in csv.reader(open(os.path.join(m.s.CM, "output/global_variables.csv"))):
    if r and r[0].startswith("0x"):
        rows[int(r[0], 16)] = (r[1], r[3] if len(r) > 3 else "")
for start, gap, b1, b2 in m.s.gaps:
    in_gap = [rows[a] for a in sorted(rows) if start <= a < start + gap]
    if not in_gap:
        continue
    row_words = set()
    for n, c in in_gap:
        row_words |= words(n) | words(c[:200])
    ranked = []
    for b, recs in m.s.absent.items():
        recs = recs[1]
        x = m.sizes.get(b)
        if x is None or x > gap:
            continue
        ok = m.score(start, gap, [(b, 0)])
        rec_words = set()
        for name, _, _, desc in recs.values():
            rec_words |= words(name) | words(desc)
        common = rec_words & row_words
        if common:
            ranked.append((len(common) / max(1, len(rec_words)), b, x, ok[3], ok[4], sorted(common)[:8]))
    ranked.sort(reverse=True)
    if ranked and ranked[0][0] >= 0.3:
        print(f"gap {start:#09x} +{gap} after {b1:04X} before {b2:04X}, rows: {', '.join(n for n, _ in in_gap)[:150]}")
        for sc, b, x, mt, n, common in ranked[:3]:
            print(f"   {sc:.2f} {b:04X} (extent {x}, {mt}/{n} records on same-width rows) {common}")

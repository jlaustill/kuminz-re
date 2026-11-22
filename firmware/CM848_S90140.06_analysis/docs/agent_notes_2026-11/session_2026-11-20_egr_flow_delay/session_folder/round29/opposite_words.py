"""Round 29: e2m records whose row name carries the OPPOSITE word (min / max, high / low, upper / lower, enable /
disable, positive / negative, increase / decrease, on / off, open / close, rise / fall, lead / lag): candidates for
a swapped or backwards name. Each hit needs its code use read: an e2m layout can drift, and a name can describe the
effect on purpose.
usage: opposite_words.py <e2m_audit.csv>"""
import csv
import re
import sys

PAIRS = [({"min", "minimum", "lower", "low", "lo"}, {"max", "maximum", "upper", "high", "hi"}),
         ({"enable", "enabled", "enables"}, {"disable", "disabled", "inhibit", "inhibited", "block"}),
         ({"pos", "positive", "increase", "increment", "inc", "up", "rise", "rising"},
          {"neg", "negative", "decrease", "decrement", "dec", "down", "fall", "falling"}),
         ({"on"}, {"off"}), ({"open", "opening"}, {"close", "closed", "closing"}), ({"lead"}, {"lag"})]


def words(s):
    return {w.lower() for w in re.split(r"[_\W]+", s) if w}


for r in csv.DictReader(open(sys.argv[1])):
    if r["status"] != "named" or not r["row_name"]:
        continue
    rec, row = words(r["record"]), words(r["row_name"])
    for a, b in PAIRS:
        ra, rb, wa, wb = rec & a, rec & b, row & a, row & b
        if (ra and not rb and wb and not wa) or (rb and not ra and wa and not wb):
            print(f"{r['address']} {r['block']} +{r['offset']} {r['record']:44} -> {r['row_name']} ({r['references']} refs)")
            break

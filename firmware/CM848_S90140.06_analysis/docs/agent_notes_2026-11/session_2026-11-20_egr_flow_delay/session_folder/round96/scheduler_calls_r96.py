"""Round 96 (read-only): every scheduleJ1939PeriodicMessage call in a decompilation with its five arguments (calls
that wrap are joined), and for each builder argument whether it is a function (a name) or only a label (&LAB_...).
usage: scheduler_calls_r96.py <cpp>"""
import re
import sys

text = open(sys.argv[1], errors="replace").read()
text = re.sub(r"/\*.*?\*/", " ", text, flags=re.S)
flat = re.sub(r"\s+", " ", text)
calls = re.findall(r"scheduleJ1939PeriodicMessage\s*\(([^;]*?)\)\s*;", flat)
for args in calls:
    parts = [a.strip() for a in args.split(",")]
    if len(parts) < 5:
        continue
    queue, pgn, interval, offset, builder = parts[:5]
    try:
        pgn_value = int(pgn, 0)
    except ValueError:
        pgn_value = None
    kind = "LABEL" if builder.startswith("&LAB_") else "function"
    print(f"{queue:38s} PGN {pgn_value if pgn_value is not None else pgn:>6} interval {interval:>6} offset {offset:>5} "
          f"{kind:8s} {builder}")
print(len(calls), "calls")

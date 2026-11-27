"""Round 38: for 2-D caches typed word, the row at +2 (the y offset half?) and how its label renders.
usage: second_words.py <cpp> <global_variables.csv> <hex address>..."""
import re
import sys

text = open(sys.argv[1], errors="replace").read()
rows = {}
for l in open(sys.argv[2], errors="replace"):
    p = l.split(",", 3)
    if len(p) >= 3 and p[0].startswith("0x"):
        rows.setdefault(int(p[0], 16), []).append((p[1], p[2]))
for h in sys.argv[3:]:
    a = int(h, 16)
    for b in (a + 1, a + 2, a + 3):
        for name, typ in rows.get(b, []):
            label = name or f"(type-only {typ})"
            uses = [m.group(0) for m in re.finditer(r"[^\n;]*\b" + re.escape(name) + r"\b[^\n;]*", text)] if name else []
            calls = sum(1 for u in uses if "Interpolation(" in u or "Interpolation\n" in u)
            print(f"0x{a:06x} +{b - a}: {label} {typ}; {len(uses)} renders, as a lookup cache argument {calls}; "
                  f"e.g. {uses[0].strip()[:90] if uses else '-'}")

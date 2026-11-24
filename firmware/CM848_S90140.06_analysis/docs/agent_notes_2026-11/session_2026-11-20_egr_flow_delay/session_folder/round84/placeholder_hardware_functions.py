"""CM550 functions that still carry placeholder names (cm550_FUN_ / mc68k_FUN_ / vp44_FUN_ / FUN_) but touch named
hardware registers: their register modules and counts, the named globals they use most, and their callers.
usage: placeholder_hardware_functions.py <cpp>"""
import collections
import re
import sys

MODULES = [("SCI", r"\bQSM_SC(CR0|CR1|SR|DR)\b"),
           ("QSPI", r"\bQSM_(SPCR[0-3]|SPSR|TR\d+|RR\d+|CR\d+|QSMCR|QILR|QIVR|PORTQS|PQSPAR|DDRQS)\b"),
           ("QADC", r"\bQADC_\w+"), ("CTM4", r"\bCTM4_\w+"), ("TPU", r"\bTPU_\w+"), ("SIM", r"\bSIM_\w+"),
           ("CAN_CS5", r"\bCAN_CS5_\w+"), ("CAN_CS4", r"\bCAN_CS4_\w+"), ("CS2", r"\bCS2_\w+")]
text = open(sys.argv[1], errors="replace").read()
parts = re.split(r"^// Function: (\S+) @ (0x[0-9a-f]+)[^\n]*\n", text, flags=re.M)
bodies = {parts[i]: (parts[i + 1], re.sub(r"/\*.*?\*/", "", parts[i + 2], flags=re.S)) for i in range(1, len(parts), 3)}
for name, (address, body) in bodies.items():
    if not re.match(r"^(cm550_|mc68k_|vp44_)?FUN_[0-9a-f]+$", name):
        continue
    touched = {m: len(re.findall(p, body)) for m, p in MODULES if re.search(p, body)}
    if not touched:
        continue
    named = collections.Counter(w for w in re.findall(r"\b_?[a-z][a-z0-9_]{10,}\b", body)
                                if not re.match(r"^_?[a-z]?[a-z]Var\d", w) and w != name)
    callers = sorted({n for n, (_, b) in bodies.items() if n != name and re.search(rf"\b{re.escape(name)}\b", b)})
    print(f"{address} {name}: {touched}; uses {[w for w, _ in named.most_common(4)]}; callers {callers[:3]}")

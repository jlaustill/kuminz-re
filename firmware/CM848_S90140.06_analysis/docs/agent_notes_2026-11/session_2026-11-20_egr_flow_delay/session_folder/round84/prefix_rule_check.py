"""CM550: functions without the mc68k_ prefix whose bodies touch MC68336 registers or the external chip-select devices
(the prefix rule: MC68336-specific code is prefixed mc68k_, docs/superpowers/specs/2026-03-17-cross-firmware-
convergence-pipeline-design.md), and any real code (not another image copy) that references an ImageCopy function.
usage: prefix_rule_check.py <cpp>"""
import collections
import re
import sys

text = open(sys.argv[1], errors="replace").read()
parts = re.split(r"^// Function: (\S+) @ (0x[0-9a-f]+)[^\n]*\n", text, flags=re.M)
bodies = {parts[i]: (parts[i + 1], re.sub(r"/\*.*?\*/", "", parts[i + 2], flags=re.S)) for i in range(1, len(parts), 3)}
REGISTER = re.compile(r"\b(SIM|QSM|QADC|CTM4|TPU|CAN_CS5|CAN_CS4|CS2)_[A-Z0-9_]+\b")
hits = []
for name, (address, body) in bodies.items():
    if name.startswith("mc68k_"):
        continue
    registers = collections.Counter(m.group(0) for m in REGISTER.finditer(body))
    if registers:
        hits.append((address, name, dict(registers.most_common(3))))
print(len(hits), "functions without mc68k_ touch MC68336 / external device registers")
for hit in hits:
    print(" ", *hit)
copies = [n for n in bodies if n.endswith("ImageCopy")]
for copy in copies:
    users = sorted(n for n, (_, b) in bodies.items()
                   if n != copy and not n.endswith("ImageCopy") and re.search(rf"\b{copy}\b", b))
    if users:
        print("REAL CODE USES", copy, users)
print("image copies:", len(copies))

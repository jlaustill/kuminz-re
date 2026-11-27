"""For each listed CM550 function: the hardware it touches, split into the watchdog kick (SIM_SWSR / CS2_WATCHDOG_SERVICE)
and everything else - named registers and unnamed 0xFFxxxx addresses (DAT_00ff.... / _DAT_00ff....) alike.
Commit 16143a5c's rule: a function whose only hardware access is the watchdog kick is generic code (not mc68k_).
usage: hardware_access_kinds.py <cpp> <name>..."""
import collections
import re
import sys

text = open(sys.argv[1], errors="replace").read()
parts = re.split(r"^// Function: (\S+) @ (0x[0-9a-f]+)[^\n]*\n", text, flags=re.M)
bodies = {parts[i]: re.sub(r"/\*.*?\*/", "", parts[i + 2], flags=re.S) for i in range(1, len(parts), 3)}
HARDWARE = re.compile(r"\b(?:_?DAT_00ff[0-9a-f]{4}|(?:SIM|QSM|QADC|CTM4|TPU|CAN_CS5|CAN_CS4|CS2)_[A-Z0-9_]+)\b")
WATCHDOG = {"SIM_SWSR", "CS2_WATCHDOG_SERVICE"}
for name in sys.argv[2:]:
    body = bodies.get(name)
    if body is None:
        print(f"{name}: NOT FOUND")
        continue
    seen = collections.Counter(m.group(0) for m in HARDWARE.finditer(body))
    other = {k: v for k, v in seen.items() if k not in WATCHDOG}
    kind = "watchdog-only" if seen and not other else ("none" if not seen else "REAL ACCESS")
    print(f"{name}: {kind}; other = {dict(other)}")

"""Stage 2 type fixes from the wave-3 disassembly notes. Usage: type_fixes.py <globals.csv>"""
import sys

path = sys.argv[1]
FIX = {  # address: (name, new type) ; None type = delete the row
    0x003fee34: ("oil_change_monitor_fault_event_bits_cal", "word"),
    0x003fee36: ("oil_change_monitor_fuel_hundredth_gallons_cal", "dword"),
    0x003fee3a: ("oil_change_monitor_distance_pulses_cal", "dword"),
    0x003fee3b: ("sensor_validation_delta+1", None),
    0x003fd108: ("injection_quantity_pilot_arbitrated_target", "dword"),
}
lines = open(path).read().split("\n")
out, done = [], set()
for l in lines:
    p = l.split(",", 3)
    if p[0].startswith("0x") and int(p[0], 16) in FIX:
        a = int(p[0], 16)
        name, typ = FIX[a]
        assert p[1] == name, (hex(a), p[1])
        done.add(a)
        if typ is None:
            continue
        while len(p) < 3:
            p.append("")
        p[2] = typ
        l = ",".join(p)
    out.append(l)
assert done == set(FIX), set(FIX) - done
open(path, "w").write("\n".join(out))
print("type fixes", len(FIX))

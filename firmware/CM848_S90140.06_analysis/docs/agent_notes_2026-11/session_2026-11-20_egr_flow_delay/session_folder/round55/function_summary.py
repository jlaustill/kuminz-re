"""Round 55: one line per function in an address range - name, line count, whether it has a plate, its callers.
usage: function_summary.py <cpp> <low hex> <high hex>"""
import re
import sys

cpp, low, high = sys.argv[1], int(sys.argv[2], 16), int(sys.argv[3], 16)
t = open(cpp, errors="replace").read()
funcs = [(m.group(1), int(m.group(2), 16), m.start()) for m in re.finditer(r"^// Function: (\S+) @ 0x([0-9a-f]+)", t, re.M)]
bodies = {}
for k, (name, addr, start) in enumerate(funcs):
    end = funcs[k + 1][2] if k + 1 < len(funcs) else len(t)
    bodies[name] = (addr, t[start:end])
for name, (addr, body) in sorted(bodies.items(), key=lambda kv: kv[1][0]):
    if not low <= addr < high:
        continue
    callers = sorted({n for n, (a, b) in bodies.items() if n != name and re.search(rf"\b{re.escape(name)}\(", b)})
    plate = "/*" in body.split("\n{", 1)[0]
    print(f"{addr:#08x} {name} ({body.count(chr(10))} lines, plate {'yes' if plate else 'no'}) <- {', '.join(callers[:4])}"
          + (" ..." if len(callers) > 4 else ""))

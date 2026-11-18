"""Census of the J1939 transmit descriptors: for every name the decompile passes as
sendJ1939Message((j1939_tx_msg_t *)&NAME), list the global_variables.csv rows inside the 14-byte descriptor window
(header dword @+0, data length word @+4, data pointer @+6, data end pointer @+10) and every ROM-to-RAM thunk / call
override address (4 bytes each, from the build log) that overlaps the window.
Usage: descriptor_census.py <cm848_rom.ghidra.cpp> <global_variables.csv> <build.log>"""
import re
import sys

cpp, gv, log = sys.argv[1:4]
rows = {}
for line in open(gv):
    p = line.rstrip("\n").split(",", 3)
    if p[0].startswith("0x"):
        rows.setdefault(int(p[0], 16), []).append((p[1], p[2] if len(p) > 2 else ""))
by_name = {n: a for a, lst in rows.items() for n, _ in lst}
thunks = {}
for line in open(log):
    m = re.search(r"(Thunk|Call override): .*?RAM 0x([0-9a-f]+) -> ROM 0x([0-9a-f]+) \((\w+)\)", line)
    if m:
        thunks[int(m.group(2), 16)] = (m.group(1), m.group(4))
names = sorted(set(re.findall(r"sendJ1939Message\(\(j1939_tx_msg_t \*\)&(\w+)\)", open(cpp).read())))
for name in names:
    base = by_name.get(name)
    if base is None:
        print(f"{name}: NO ROW")
        continue
    inside = [(f"+{a - base}", n, t) for a in range(base, base + 14) for n, t in rows.get(a, [])]
    hits = [(f"+{a - base}", k, f) for a, (k, f) in thunks.items() if a < base + 14 and a + 4 > base]
    print(f"0x{base:06x} {name}: rows {inside}" + (f"  THUNK OVERLAP {hits}" if hits else ""))

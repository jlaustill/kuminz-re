"""Describer D1 scratch: parse executiveFrameInterruptHandler's switch into callee -> phases -> period."""
import re
import subprocess
import collections

R = "/home/linux/.claude/jobs/374b0424/tmp/w15/r93"
out = subprocess.run(
    ["python3", f"{R}/tools/body.py", f"{R}/frozen/cm550/J90350.00.ghidra.cpp", "executiveFrameInterruptHandler"],
    capture_output=True, text=True).stdout
phase = None
calls = collections.OrderedDict()
for line in out.split("\n"):
    m = re.match(r"\s*case (0x[0-9a-f]+|\d+):", line)
    if m:
        phase = int(m.group(1), 0)
        continue
    if "default:" in line:
        phase = None
    m = re.match(r"\s*([A-Za-z_0-9]+)\(\);", line)
    if m and phase is not None:
        calls.setdefault(m.group(1), []).append(phase)
names = {}
for line in open(f"{R}/frozen/cm550/function_renames.csv"):
    p = line.split(",")
    if p[0].startswith("0x"):
        names[p[1].strip()] = int(p[0], 16)
for n, ph in calls.items():
    diffs = sorted(set((b - a) for a, b in zip(ph, ph[1:])))
    period = 40 // len(ph)
    a = names.get(n)
    print(f"{('0x%05x' % a) if a else '(func_0x)':>10} {n:62s} count {len(ph):2d} period {period:2d} phases {ph} diffs {diffs}")

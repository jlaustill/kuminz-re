"""Round 95 (read-only): CM848's executive frame schedule from the ROM (method 1) and from the decompiled
executiveFrameInterruptHandler switch (method 2), and the slot name each task set takes.
- Method 1 (after round 94's L4 judge's slots_judge.py): the 40-entry jump table at 0xc198 (b to each case), each
  case's bl targets in order until its closing unconditional branch.
- Method 2: in the .cpp, the 'case N:' blocks of executiveFrameInterruptHandler and the calls in each.
A task set called in frames p, p+N, p+2N ... (all 40 / N of them) is runEvery<N>FramesTaskSetPhase<p>; one called in
every frame is runEveryFrameTaskSet (CM550's round 93 scheme). Prints the schedule, the derived names and whether
both methods agree. usage: cm848_frame_schedule_r95.py <repo> <cpp> [--csv out.csv]"""
import os
import re
import struct
import sys

repo, cpp_path = os.path.abspath(sys.argv[1]), sys.argv[2]
rom = open(os.path.join(repo, "firmware/CM848_S90140.06_analysis/originals/cm848_rom.bin"), "rb").read()
cpp = open(cpp_path, errors="replace").read()
names = {int(m.group(2), 16): m.group(1) for m in re.finditer(r"^// Function: (\S+) @ 0x([0-9a-fA-F]+)", cpp, re.M)}


def word(a):
    return struct.unpack(">I", rom[a:a + 4])[0]


def branch(a):
    w = word(a)
    if (w >> 26) != 18:
        return None
    li = w & 0x03fffffc
    if li & 0x02000000:
        li -= 0x04000000
    dest = li if (w & 2) else (a + li)
    return dest, bool(w & 1)


frames = []
for i in range(40):
    d, lk = branch(0xc198 + 4 * i)
    assert not lk
    a, calls = d, []
    for _ in range(400):
        b = branch(a)
        if b is not None:
            dest, link = b
            if link:
                calls.append(dest)
            else:
                break
        a += 4
    frames.append(calls)
# method 2: the decompiled switch
body_start = cpp.index("// Function: executiveFrameInterruptHandler @")
body_end = cpp.index("// Function: ", body_start + 10)
body = cpp[body_start:body_end]
cases = {}
current = None
for line in body.splitlines():
    m = re.match(r"\s*case (0x[0-9a-f]+|\d+):", line)
    if m:
        current = int(m.group(1), 0)
        cases.setdefault(current, [])
        continue
    if current is not None:
        for c in re.findall(r"(\w+)\(\)", line):
            cases[current].append(c)
by_target = {}
for f, calls in enumerate(frames):
    for c in calls:
        by_target.setdefault(c, []).append(f)
rows = []
for target, fs in sorted(by_target.items()):
    fs = sorted(set(fs))
    name = None
    if fs == list(range(40)):
        name = "cm848_runEveryFrameTaskSet"
    else:
        for n in (2, 4, 5, 8, 10, 20, 40):
            p = fs[0]
            if p < n and fs == list(range(p, 40, n)):
                name = f"cm848_runEvery{n}FramesTaskSetPhase{p}"
                break
    rows.append((target, names.get(target, hex(target)), fs, name))
print("frame calls (method 1):")
for f, calls in enumerate(frames):
    print(f"  {f:2d}: " + " ".join(names.get(c, hex(c)) for c in calls))
agree = all(
    [names.get(c, hex(c)) for c in frames[f]] == [x for x in cases.get(f, []) if not x.startswith("FUN_") or True]
    for f in range(40))
print("method 2 cases found:", len(cases), "| call lists agree with method 1:", agree)
if not agree:
    for f in range(40):
        a = [names.get(c, hex(c)) for c in frames[f]]
        b = cases.get(f, [])
        if a != b:
            print(f"   frame {f}: ROM {a} | cpp {b}")
print("task sets:")
for target, nm, fs, name in rows:
    print(f"  0x{target:x} {nm}: frames {fs if len(fs) <= 8 else str(fs[:4]) + '... (' + str(len(fs)) + ')'} -> {name}")
if "--csv" in sys.argv:
    with open(sys.argv[sys.argv.index("--csv") + 1], "w") as f:
        f.write("address,current_name,frames,slot_name\n")
        for target, nm, fs, name in rows:
            f.write(f"0x{target:08x},{nm},{' '.join(map(str, fs))},{name or ''}\n")

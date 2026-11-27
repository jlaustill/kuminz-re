"""Round 95 stage A (CM848): name the executive frame task sets (the contiguous block 0xb76c-0xc078 that
executiveFrameInterruptHandler's 40 frames call) by their schedule slot, as CM550's round 93 did and as round 94 named
four of them: cm848_runEveryFrameTaskSet / cm848_runEvery<N>FramesTaskSetPhase<P>. The schedule comes from the ROM's
40-entry jump table at 0xc198 and agrees frame for frame with the decompiled switch (cm848_frame_schedule_r95.py).
The old names were role guesses (cm848_periodicTaskSet_canTx ...), ordinals (cm848_periodicTaskGroup12_calibration1
...), a phase group name in snake_case and an orphaned twin name (periodicTaskSet_fuelDemand; CM550's task set took
its slot name in round 93). Each plate gives the period, the frames, the call position in those frames and the callees
in order; an older plate stays as '| earlier note:'. Writes the map for the proofs. Idempotent.
usage: cm848_task_sets_r95.py <repo> <cpp> <map out.csv>"""
import os
import re
import struct
import sys

repo, cpp_path, map_path = os.path.abspath(sys.argv[1]), sys.argv[2], sys.argv[3]
R = "PR #53 round 95"
rom = open(os.path.join(repo, "firmware/CM848_S90140.06_analysis/originals/cm848_rom.bin"), "rb").read()
cpp = open(cpp_path, errors="replace").read()
heads = list(re.finditer(r"^// Function: (\S+) @ 0x([0-9a-fA-F]+)", cpp, re.M))
names = {int(m.group(2), 16): m.group(1) for m in heads}
bodies = {}
for i, m in enumerate(heads):
    end = heads[i + 1].start() if i + 1 < len(heads) else len(cpp)
    bodies[int(m.group(2), 16)] = cpp[m.start():end]


def word(a):
    return struct.unpack(">I", rom[a:a + 4])[0]


def branch(a):
    w = word(a)
    if (w >> 26) != 18:
        return None
    li = w & 0x03fffffc
    if li & 0x02000000:
        li -= 0x04000000
    return (li if (w & 2) else (a + li)), bool(w & 1)


frames = []
for i in range(40):
    d, _ = branch(0xc198 + 4 * i)
    a, calls = d, []
    for _ in range(400):
        b = branch(a)
        if b is not None:
            if b[1]:
                calls.append(b[0])
            else:
                break
        a += 4
    frames.append(calls)
KEYWORDS = {"if", "while", "for", "switch", "return", "sizeof"}
path = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output/function_renames.csv")
text = open(path, newline="").read()
E = "\r\n" if "\r\n" in text else "\n"
lines = text.split(E)
renames = []
for target in sorted({c for f in frames for c in f if 0xb76c <= c <= 0xc078}):
    fs = [i for i, f in enumerate(frames) if target in f]
    positions = sorted({frames[i].index(target) + 1 for i in fs})
    if fs == list(range(40)):
        new, period, phase = "cm848_runEveryFrameTaskSet", 1, 0
    else:
        period = next(n for n in (2, 4, 5, 8, 10, 20) if fs[0] < n and fs == list(range(fs[0], 40, n)))
        phase = fs[0]
        new = f"cm848_runEvery{period}FramesTaskSetPhase{phase}"
    body = bodies[target]
    own = names[target]
    callees = []
    for c in re.findall(r"\b([A-Za-z_]\w*)\s*\(", body.split("{", 1)[1]):
        if c not in KEYWORDS and c != own and c not in callees:
            callees.append(c)
    when = ("every frame (5 ms)" if period == 1 else
            f"every {period} frames ({period * 5} ms), at frames {', '.join(map(str, fs))} of the 40-frame cycle")
    pos = f"as call {positions[0]}" if len(positions) == 1 else "as calls " + " / ".join(map(str, positions))
    plate = (f"Executive frame task set: runs {when}, {pos} of those frames in executiveFrameInterruptHandler. "
             f"Calls, in order: {', '.join(callees) if callees else 'nothing'}.")
    idx = next(i for i, l in enumerate(lines) if l.lower().startswith(f"0x{target:08x},"))
    parts = lines[idx].split(",", 2)
    old = parts[1]
    if old == new:
        continue
    earlier = parts[2] if len(parts) > 2 and parts[2] else ""
    lines[idx] = f"0x{target:08x},{new},{plate} (was {old}; {R})" + (f" | earlier note: {earlier}" if earlier else "")
    renames.append((f"0x{target:08x}", new, old))
    print(f"0x{target:x} {old} -> {new}")
open(path, "w", newline="").write(E.join(lines))
for k in ("function_definitions.csv", "local_variables.csv"):
    p = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output", k)
    t = open(p, newline="").read()
    for a, new, old in renames:
        t = re.sub(rf"^({a},){re.escape(old)},", lambda x: x.group(1) + new + ",", t, flags=re.M | re.I)
    open(p, "w", newline="").write(t)
with open(map_path, "w") as f:
    f.write("address,name,old_label,kind,dims\n")
    for a, new, old in renames:
        f.write(f"{a},{new},{old},symbol,1\n")
print(len(renames), "renamed")

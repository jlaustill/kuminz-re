"""Round 93 (CM550): name the 45 executive frame task sets by their schedule slot. executiveFrameInterruptHandler
(0x1b876) switches on the phase index 0-39 (one phase per interrupt = one frame); each phase calls, in a fixed
order: the every-frame set, the every-2-frames set of that phase, the every-4, every-8, every-10 and every-20 sets,
then one or two functions that run once per cycle. The schedule is read here from the ROM (the switch table and each
case's bsr.w / jsr), and a set is named only when its phases are evenly spaced:
    cm550_runEveryFrameTaskSet, cm550_runEvery<N>FramesTaskSetPhase<P>   (N = 2 / 4 / 8 / 10 / 20; P = first phase).
A frame is 5 ms: the hour meters step once per 40-frame cycle (0x34512, phase 0) and their Calterm unit is 0.2 s per
count (e2m 0004 +0 CMECTR / 11BC +0 CMEGTR). The old names carried cycle numbers that did not match (a
'SlowCycle20Coordinator' on an every-10-frames set) and prefixes of unrelated subsystems.
Each row gets a plate comment with its slot and the calls it makes, in order. Idempotent.
usage: apply_r93_task_sets.py <repo> <map.csv>"""
import os
import re
import sys

repo, map_out = os.path.abspath(sys.argv[1]), sys.argv[2]
R = "PR #53 round 93"
O = os.path.join(repo, "firmware/CM550_J90350.00_analysis/output")
rom = open(os.path.join(repo, "firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin"), "rb").read()
HANDLER, END, LAYER = 0x1b876, 0x1bf90, (0x1b4d0, 0x1b876)
FRAME_MS = 5
F = os.path.join(O, "function_renames.csv")
text = open(F, newline="").read()
rows = {}
for line in text.split("\n"):
    parts = line.split(",", 2)
    if len(parts) > 1 and parts[0].startswith("0x"):
        rows[int(parts[0], 16)] = parts[1]


def word(a):
    return int.from_bytes(rom[a:a + 2], "big")


j = rom.find(b"\x4e\xfb\x00\x02", HANDLER, END)
assert j != -1 and rom[j - 4:j - 2] == b"\x30\x3b"
table = j + 4
count = next((word(k) & 0xff) + 1 for k in range(j - 6, j - 20, -2) if (word(k) & 0xf100) == 0x7000)
assert count == 40, count
cases = [table + int.from_bytes(rom[table + 2 * n:table + 2 * n + 2], "big", signed=True) for n in range(count)]
starts = sorted(set(cases))
calls, position = {}, {}
for n, start in enumerate(cases):
    a, limit, k = start, min([s for s in starts if s > start] + [END]), 0
    while a < limit:
        w = word(a)
        target = None
        if w == 0x6100:
            target, a = a + 2 + int.from_bytes(rom[a + 2:a + 4], "big", signed=True), a + 4
        elif w == 0x4eb9:
            target, a = int.from_bytes(rom[a + 2:a + 6], "big"), a + 6
        elif w == 0x4e95:                    # jsr (a5), a5 = 0x1b4d0
            target, a = 0x1b4d0, a + 2
        elif (w & 0xff00) == 0x6000:
            break
        else:
            a += 2
        if target is not None:
            calls.setdefault(target, []).append(n)
            position.setdefault(target, set()).add(k)
            k += 1


def body_calls(a):
    """The jsr targets of a task set, in order (a straight list ending in rts)."""
    out = []
    while word(a) != 0x4e75:
        w = word(a)
        assert w in (0x4eb9, 0x4267, 0x548f), f"0x{a:x}: {w:04x}"
        if w == 0x4eb9:
            out.append(int.from_bytes(rom[a + 2:a + 6], "big"))
            a += 6
        else:
            a += 2
    return out


new_names = {}
for a in sorted(rows):
    if not (LAYER[0] <= a < LAYER[1]):
        continue
    assert a in calls, f"0x{a:x} {rows[a]}: the handler does not call it"
    phases = calls[a]
    period = count // len(phases)
    assert count % len(phases) == 0 and all(p == phases[0] + i * period for i, p in enumerate(phases)), f"0x{a:x}: uneven phases {phases}"
    assert len(position[a]) == 1, f"0x{a:x}: called at different positions {position[a]}"
    name = "cm550_runEveryFrameTaskSet" if period == 1 else f"cm550_runEvery{period}FramesTaskSetPhase{phases[0]}"
    new_names[a] = (name, period, phases[0], min(position[a]) + 1)
assert len(new_names) == 45 and len({v[0] for v in new_names.values()}) == 45, len(new_names)
final = dict(rows)
for a, v in new_names.items():
    final[a] = v[0]
pairs = []
for a, (name, period, first, pos) in sorted(new_names.items()):
    key = f"0x{a:08x}"
    m = re.search(rf"^{key},([^,\r\n]*)(?:,([^\r\n]*))?$", text, re.M)
    old = m.group(1)
    if old == name:
        continue
    callees = body_calls(a)
    listed = ", ".join(final.get(c, f"0x{c:x} (not dumped)" if c >= 0x40000 else f"0x{c:x}") for c in callees)
    when = ("every frame (5 ms)" if period == 1 else
            f"every {period} frames ({period * FRAME_MS} ms): frames {first}, {first + period}, ... of the 40-frame cycle")
    plate = (f"Executive frame task set: runs {when}, as call {pos} of those frames in executiveFrameInterruptHandler. "
             + (f"Calls, in order: {listed}." if callees else "Empty (a single rts): nothing is scheduled in this slot."))
    earlier = f" | earlier note: {m.group(2)}" if m.group(2) else ""
    text = text[:m.start()] + f"{key},{name},{plate} (was {old}; {R}){earlier}" + text[m.end():]
    for k in ("function_definitions.csv", "local_variables.csv"):
        p = os.path.join(O, k)
        c = open(p, newline="").read()
        c2 = re.sub(rf"^({key},){re.escape(old)},", lambda x: x.group(1) + name + ",", c, flags=re.M | re.I)
        if c2 != c:
            open(p, "w", newline="").write(c2)
    pairs.append((key, name, old))
if pairs:
    open(F, "w", newline="").write(text)
    with open(map_out, "w") as fh:
        fh.write("address,name,old_label,kind,dims\n")
        for key, new, old in pairs:
            fh.write(f"{key},{new},{old},symbol,1\n")
print(f"{len(new_names)} task sets; {len(pairs)} renamed")

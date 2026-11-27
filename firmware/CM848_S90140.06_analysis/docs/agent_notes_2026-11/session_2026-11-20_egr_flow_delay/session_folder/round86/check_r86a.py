"""Round 86 checks of the stack parameter layout build (the design's T3). usage: check_r86a.py <pre cpp> <post cpp> <function_definitions.csv>
- b: the control set (functions that call nothing whose prototype changes) must be byte-identical, comments stripped.
- c: in_stack_0000000N (N >= 4) and <name>._N_M_ tokens in functions that have rows, before and after.
- d: the rendered arguments of the calls the design predicts (the pushed constants).
- g: the function count and the whole-file token counts."""
import collections
import re
import sys

CONTROL = [0x3640, 0x104e8, 0x10520, 0x1bfde, 0x1c484, 0x1e02a, 0x206a8, 0x21982, 0x22956, 0x22b50, 0x22d8e, 0x22de2,
           0x22e5e, 0x2eea2, 0x2fbd8, 0x2fcdc, 0x34de0, 0x35064, 0x35076, 0x35088]
STACK = re.compile(r"\bin_stack_000000(?:0[4-9a-f]|[1-9a-f][0-9a-f])\b")
PIECE = re.compile(r"\b(param_\d+|[a-z][a-z0-9_]*)\._\d+_\d+_")


def functions(path):
    text = re.sub(r"/\*.*?\*/", "", open(path, errors="replace").read(), flags=re.S)
    parts = re.split(r"^// Function: (\S+) @ (0x[0-9a-f]+)[^\n]*\n", text, flags=re.M)
    return {int(parts[i + 1], 16): (parts[i], parts[i + 2]) for i in range(1, len(parts), 3)}


pre, post = functions(sys.argv[1]), functions(sys.argv[2])
rows = collections.defaultdict(list)
for line in open(sys.argv[3], newline=""):
    p = line.rstrip("\r\n").split(",")
    if p[0].startswith("0x") and len(p) > 3 and p[2] != "return":
        rows[int(p[0], 16)].append(p[3])
print(f"g: functions {len(pre)} -> {len(post)}")
for label, rx in (("in_stack_0000000N (N >= 4)", STACK), ("<name>._N_M_", PIECE)):
    a = sum(len(rx.findall(b)) for _, b in pre.values())
    z = sum(len(rx.findall(b)) for _, b in post.values())
    print(f"g: {label} tokens in the whole file: {a} -> {z}")
changed = [a for a in CONTROL if pre.get(a) != post.get(a)]
print(f"b: control set: {len(CONTROL) - len(changed)} of {len(CONTROL)} byte-identical" +
      (f"; CHANGED: {', '.join(hex(a) for a in changed)}" if changed else ""))
print("c: functions with rows that still show a stack token or a piece of a parameter (after):")
left = 0
for address in sorted(rows):
    if address not in post:
        print(f"   0x{address:05x} not in the .cpp")
        continue
    name, body = post[address]
    params = set(rows[address])
    tokens = STACK.findall(body) + [m.group(0) for m in PIECE.finditer(body)
                                    if m.group(1) in params or m.group(1).startswith("param_")]
    if tokens:
        left += 1
        before = pre.get(address, ("", ""))[1]
        nb = len(STACK.findall(before)) + sum(1 for m in PIECE.finditer(before)
                                               if m.group(1) in params or m.group(1).startswith("param_"))
        print(f"   0x{address:05x} {name}: {len(tokens)} (was {nb}) {sorted(set(tokens))[:4]}")
print(f"   {left} functions")
print("d: predicted call arguments (after):")
for callee in ("cm550_busyWaitDelayLoop", "cm550_diagnosticMessageQueueWrite", "cm550_parameterCircularBufferWrite",
               "cm550_circularBufferInit", "exponentialMovingAverage", "cm550_memcpy",
               "mc68k_delayTimeBaseTicksWithWatchdogService"):
    calls = collections.Counter()
    for _, body in post.values():
        for m in re.finditer(rf"\b{callee}\s*\(([^;]*?)\);", body, re.S):
            calls[re.sub(r"\s+", " ", m.group(1))[:70]] += 1
    print(f"   {callee}: {sum(calls.values())} calls; {dict(calls.most_common(6))}")

"""List the functions that request (set) or clear the given logical outputs through cm848_setLogicalOutputRequest /
cm848_clearLogicalOutputRequest, outside the SCI actuator tests and the end-of-line test. usage:
output_requesters.py <cpp> <output>..."""
import collections
import re
import sys

text = open(sys.argv[1]).read()
outputs = {int(o, 0) for o in sys.argv[2:]}
starts = [(m.start(), m.group(1)) for m in re.finditer(r"^// Function: (\S+) @", text, re.M)]
SKIP = {"cm848_sciCommand19OutputTestCallback", "cm848_sciStartTimedOutputTest", "cm848_stepSciOutputTest",
        "cm848_stopSciOutputTest", "cm848_stopAllSciOutputTests", "cm848_updateSciOutputTests",
        "engine_coldStart_protection_stateMachine"}


def func_of(pos):
    name = None
    for s, f in starts:
        if s > pos:
            break
        name = f
    return name


found = collections.defaultdict(lambda: collections.Counter())
for m in re.finditer(r"cm848_(set|clear)LogicalOutputRequest\s*\(\s*(0x[0-9a-f]+|\d+)\s*,", text):
    o = int(m.group(2), 0)
    if o in outputs:
        f = func_of(m.start())
        if f not in SKIP:
            found[o][f"{m.group(1)}@{f}"] += 1
for o in sorted(outputs):
    print(f"output {o} (0x{o:x}):", dict(found[o]) or "no requester outside the tests")

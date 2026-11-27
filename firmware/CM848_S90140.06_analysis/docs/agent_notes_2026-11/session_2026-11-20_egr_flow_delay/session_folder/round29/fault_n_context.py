"""Round 29: the code around each set (or read) of the given fault bits, flat pieces and fault_<n> names alike, with
the enclosing function. Shows the statements just before each hit (the condition that sets it).
usage: fault_n_context.py <cpp> <before> <fault>..."""
import re
import sys

cpp, before = sys.argv[1], int(sys.argv[2])
faults = [int(x) for x in sys.argv[3:]]
lines = open(cpp, errors="replace").read().split("\n")
func = ""
owner = []
for l in lines:
    m = re.match(r"// Function: (\S+)", l)
    if m:
        func = m.group(1)
    owner.append(func)
for f in faults:
    w, b = f // 16, f % 16
    mask = 1 << b
    lit = str(mask) if mask < 10 else f"0x{mask:x}"
    pat = re.compile(r"fault_detected_cal\.(?:fault_%d\b|_%d_2_ = fault_detected_cal\._%d_2_ \| %s\b)" % (f, 2 * w, 2 * w, lit)
                     + r"|fault_(?:detected|registered|previous_pass)_cal\.fault_%d\b" % f)
    hits = [i for i, l in enumerate(lines) if pat.search(l) and not l.lstrip().startswith(("/*", "*", "//"))]
    print(f"===== fault {f} (word {w} mask {lit}): {len(hits)} lines")
    for i in hits[:3]:
        print(f"  -- {owner[i]}")
        for j in range(max(0, i - before), i + 1):
            print("   " + lines[j].strip()[:150])

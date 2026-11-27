"""Name the function that contains each address (the greatest '// Function: name @ addr' start <= it).
usage: enclosing.py <cpp> <0xaddr>..."""
import re
import sys

text = open(sys.argv[1], errors="replace").read()
starts = sorted((int(a, 16), n) for n, a in re.findall(r"^// Function: (\S+) @ (0x[0-9a-fA-F]+)", text, flags=re.M))
for arg in sys.argv[2:]:
    t = int(arg, 16)
    best = None
    for a, n in starts:
        if a <= t:
            best = (a, n)
        else:
            break
    print(f"0x{t:x} -> {best[1]} @ 0x{best[0]:x}" if best else f"0x{t:x} -> ?")

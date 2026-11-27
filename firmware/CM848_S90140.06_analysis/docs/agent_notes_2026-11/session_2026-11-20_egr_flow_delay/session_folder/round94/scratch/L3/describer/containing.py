"""For each call-site address, print the function (from the .cpp '// Function: name @ addr' headers) that contains it."""
import re
import sys

cpp = "/home/linux/.claude/jobs/374b0424/tmp/w15/r94/frozen/cm550/J90350.00.ghidra.cpp"
text = open(cpp, errors="replace").read()
starts = sorted((int(a, 16), n) for n, a in re.findall(r"^// Function: (\S+) @ (0x[0-9a-fA-F]+)", text, flags=re.M))
for arg in sys.argv[1:]:
    a = int(arg, 16)
    best = None
    for s, n in starts:
        if s <= a:
            best = (s, n)
        else:
            break
    print(f"0x{a:x}: {best[1]} @ 0x{best[0]:x}")

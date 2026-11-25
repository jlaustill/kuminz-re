import re,sys
cpp=open("/home/linux/.claude/jobs/374b0424/tmp/w15/r95/frozen/cm550/J90350.00.ghidra.cpp",errors="replace").read()
funcs=sorted((int(a,16),n) for n,a in re.findall(r"^// Function: (\S+) @ (0x[0-9a-f]+)",cpp,flags=re.M))
import bisect
starts=[f[0] for f in funcs]
for x in sys.argv[1:]:
    a=int(x,16); i=bisect.bisect_right(starts,a)-1
    print(x, "->", funcs[i][1], hex(funcs[i][0]), "next", hex(funcs[i+1][0]) if i+1<len(funcs) else "")

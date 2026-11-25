import re,sys,bisect
cpp=open("/home/linux/.claude/jobs/374b0424/tmp/w15/r95/frozen/cm848/cm848_rom.ghidra.cpp",errors="replace").read()
lines=cpp.split("\n")
heads=[(i+1,m.group(1),m.group(2)) for i,l in enumerate(lines) for m in [re.match(r"// Function: (\S+) @ (0x[0-9a-f]+)",l)] if m]
nums=[h[0] for h in heads]
sym=sys.argv[1]
seen={}
for i,l in enumerate(lines):
    if re.search(r"\b"+re.escape(sym)+r"\b",l):
        j=bisect.bisect_right(nums,i+1)-1
        seen.setdefault(heads[j][1]+" "+heads[j][2],[]).append(i+1)
for k,v in seen.items(): print(k,v[:8])

import re, sys

CPP = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-typing-arrays/firmware/CM848_S90140.06_analysis/output/cm848_rom.ghidra.cpp"
lines = open(CPP).read().split("\n")
# map line -> function
func_at = []
cur = "?"
for l in lines:
    if l.startswith("// Function:"):
        cur = l.split("Function:")[1].split("@")[0].strip()
    func_at.append(cur)
maxper = int(sys.argv[1])
for sym in sys.argv[2:]:
    pat = re.compile(r"\b" + re.escape(sym) + r"\b")
    hits = [i for i, l in enumerate(lines) if pat.search(l) and not l.startswith("//") and not l.lstrip().startswith("/*")]
    print("##### %s : %d code lines" % (sym, len(hits)))
    byf = {}
    for i in hits:
        byf.setdefault(func_at[i], []).append(i)
    for f, idx in byf.items():
        print("  [%s] %d line(s)" % (f, len(idx)))
        for i in idx[:maxper]:
            print("     %d: %s" % (i + 1, lines[i].strip()[:170]))

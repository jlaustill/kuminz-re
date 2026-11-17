import sys

CPP = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-typing-arrays/firmware/CM848_S90140.06_analysis/output/cm848_rom.ghidra.cpp"
lines = open(CPP).read().split("\n")
q = sys.argv[1].lower()
maxl = int(sys.argv[2]) if len(sys.argv) > 2 else 400
start = int(sys.argv[3]) if len(sys.argv) > 3 else 0
for i, l in enumerate(lines):
    if l.startswith("// Function:"):
        ll = l.lower()
        name = ll.split("function:")[1].split("@")[0].strip()
        addr = ll.split("@")[-1].strip()
        if name == q or addr == q:
            j = i + 1
            while j < len(lines) and not lines[j].startswith("// Function:"):
                j += 1
            print("LINES", i + 1, "-", j)
            for k in range(i + start, min(j, i + start + maxl)):
                print("%d: %s" % (k + 1, lines[k]))
            break

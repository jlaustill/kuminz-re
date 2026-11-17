import re
import sys

sys.path.insert(0, "/home/linux/code/kuminz-re/.claude/worktrees/cm848-typing-arrays/firmware/scripts")
import xref_addr as X

print("== time-shared referencing functions (start address, name); BOOT = start < 0x7f60")
addrs = [0x3fa646 + 4 * i for i in range(20)] + [0x3fd5a6, 0x3fa644]
for a in addrs:
    name, refs = X.referencing_functions(a)
    boot = [(hex(s), f) for s, f in refs if s < 0x7F60]
    print(hex(a), name, "| refs:", len(refs), "| boot-ROM users:", boot or "none", "|", [f for s, f in refs][:8])

print()
print("== engine_feature_enable_flags tests in the decompiled C")
OUT = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-typing-arrays/firmware/CM848_S90140.06_analysis/output/"
cur = None
pat = re.compile(r"\bengine_feature_enable_flags\b")
n = 0
for i, ln in enumerate(open(OUT + "cm848_rom.ghidra.cpp", errors="replace")):
    m = re.match(r"^// Function: (\S+) @ 0x([0-9a-fA-F]+)", ln)
    if m:
        cur = m.group(1)
    if pat.search(ln) and not ln.lstrip().startswith(("*", "/*", "//")):
        n += 1
        print(i + 1, cur, "|", ln.strip()[:150])
print("total lines:", n)

"""usage: callers.py <cpp> <name>... : list the functions whose body mentions <name>, and ROM 4-byte pointer hits"""
import re
import sys

cpp = sys.argv[1]
text = open(cpp, errors="replace").read()
funcs = [(m.start(), m.group(1), m.group(2)) for m in re.finditer(r"^// Function: (\S+) @ (\S+)", text, flags=re.M)]
rom = open("/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin", "rb").read()
for name in sys.argv[2:]:
    hits = []
    for i, (start, fname, addr) in enumerate(funcs):
        end = funcs[i + 1][0] if i + 1 < len(funcs) else len(text)
        body = text[start:end]
        lines = body.split("\n")
        cnt = 0
        for ln in lines[1:]:
            if re.search(r"\b" + re.escape(name) + r"\b", ln):
                cnt += 1
        if fname == name:
            cnt -= 1
        if cnt > 0:
            hits.append(f"{fname}@{addr}({cnt})")
    addr = None
    for s, f, a in funcs:
        if f == name:
            addr = int(a, 16)
    ptr = []
    if addr is not None:
        pat = addr.to_bytes(4, "big")
        i = rom.find(pat)
        while i != -1:
            ptr.append(hex(i))
            i = rom.find(pat, i + 1)
    print(f"{name} @ {hex(addr) if addr is not None else '?'}: callers {hits}; ROM pointer hits {ptr}")

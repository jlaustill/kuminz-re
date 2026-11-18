import subprocess, sys

REPO = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-typing-arrays"
# usage: xr.py <maxlines per address> addr [addr ...]
maxl = int(sys.argv[1])
for a in sys.argv[2:]:
    out = subprocess.run(["python3", "firmware/scripts/xref_addr.py", a], cwd=REPO, capture_output=True, text=True).stdout.split("\n")
    print("##########", a)
    for l in out[:maxl]:
        print(l[:170])
    # boot-ROM users (below 0x7F60)
    boot = [l for l in out if "\t" in l and l.strip().split(" ")[0].replace(":", "") != "" and l.strip().startswith(("[load", "[store"))]
    low = []
    for l in out:
        t = l.strip()
        if t.startswith("[load") or t.startswith("[store"):
            parts = t.split()
            # format: [load ] word   14228:\t...
            for p in parts:
                if p.endswith(":") and all(c in "0123456789abcdef" for c in p[:-1]):
                    if int(p[:-1], 16) < 0x7F60:
                        low.append(t)
                    break
    print("BOOT-ROM USERS BELOW 0x7F60:", low if low else "none")

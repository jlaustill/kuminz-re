"""List CM550 e2m records by block / offset (hex), optional mask filter.
usage: e2mrec.py <block hex> <offset hex> [mask hex]
       e2mrec.py --name <mnemonic>"""
import sys
path = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/e2m-analysis/originals/v64t6_s.e2m"
if sys.argv[1] == "--name":
    want = sys.argv[2].upper()
    for line in open(path, errors="replace"):
        f = line.rstrip("\n").split(",")
        if f and f[0].upper() == want:
            print(line.rstrip("\n")[:250])
    sys.exit(0)
block = int(sys.argv[1], 16)
off = int(sys.argv[2], 16)
mask = int(sys.argv[3], 16) if len(sys.argv) > 3 else None
seen = set()
for line in open(path, errors="replace"):
    f = line.rstrip("\n").split(",")
    if len(f) < 15:
        continue
    try:
        b = int(f[2], 16)
        o = int(f[3], 16)
    except ValueError:
        continue
    if b != block or o != off:
        continue
    if mask is not None and f[5] == "S":
        try:
            m = int(f[10], 16)
        except ValueError:
            continue
        if not (m & mask):
            continue
    key = (f[0], f[10])
    if key in seen:
        continue
    seen.add(key)
    desc = ",".join(f[15:])
    print(f"{f[0]:10s} type={f[5]} len={f[7]} sign={f[9]} scale/mask={f[10]} grp={f[13]} :: {desc[:160]}")

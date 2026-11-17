import csv, re, sys, collections
OUT = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-typing-arrays/firmware/CM848_S90140.06_analysis/output/'
cpp = open(OUT + 'cm848_rom.ghidra.cpp', errors='replace').read().split('\n')
# global rows
rows = {}
byname = {}
for r in csv.reader(open(OUT + 'global_variables.csv')):
    if len(r) >= 3 and r[0].startswith('0x'):
        rows[int(r[0], 16)] = r
        if r[1]:
            byname.setdefault(r[1], []).append(int(r[0], 16))
# function bodies
funcs = {}
cur = None
fpat = re.compile(r'^// Function: (\S+) @ 0x([0-9a-fA-F]+)')
for i, line in enumerate(cpp):
    m = fpat.match(line)
    if m:
        cur = (int(m.group(2), 16), m.group(1))
        funcs[cur] = []
    elif cur:
        funcs[cur].append(line)
ident = re.compile(r'[A-Za-z_][A-Za-z_0-9]*')
def idents(body):
    s = set()
    for l in body:
        s.update(ident.findall(l))
    return s
TWIN = [0x18bc0, 0x18cfc, 0x18f1c, 0x18f8c, 0x191a0, 0x191e8, 0x19390, 0x1956c, 0x196a4, 0x197b4, 0x19830,
        0x19900, 0x199f4, 0x19ac0, 0x19b20, 0x19e08, 0x19ea4, 0x19fe0, 0x1a1b4, 0x1a1dc, 0x1a204, 0x1a340,
        0x1a47c, 0x1a608, 0x1a754, 0x1a980, 0x1a9a8, 0x1ae2c, 0x1af94, 0x1b120, 0x1b35c, 0x1b37c]
names_in_twin = collections.OrderedDict()
for (a, n), body in funcs.items():
    if a in TWIN:
        for t in sorted(idents(body)):
            if t in byname:
                for ad in byname[t]:
                    names_in_twin.setdefault(t, set()).add(a)
if len(sys.argv) > 1 and sys.argv[1] == 'globals':
    for t, fs in names_in_twin.items():
        ad = byname[t][0]
        print(f"0x{ad:08x},{t},{rows[ad][2]},nfun={len(fs)}")
    sys.exit()
# other functions referencing twin-only names (referenced by twin functions only at the Bank 1 side)
cand = collections.Counter()
for (a, n), body in funcs.items():
    if a in TWIN: continue
    ids = idents(body)
    hit = [t for t in names_in_twin if t in ids]
    if hit:
        cand[(a, n)] = hit
for (a, n), hit in sorted(cand.items()):
    print(f"0x{a:08x} {n}: {len(hit)} twin names: {hit[:8]}")

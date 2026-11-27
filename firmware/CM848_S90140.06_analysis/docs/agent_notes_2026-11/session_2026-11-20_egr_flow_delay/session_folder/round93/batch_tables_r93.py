"""Round 93 (read-only): the function table of each workflow batch for the agents' prompts: address, current name,
code lines, callers and callees by name (from the frozen CM550 .cpp), where the address is stored in the ROM when
nothing calls it by name, and the scored candidates of firmware/cross_firmware_matches.csv for it (untrusted).
usage: batch_tables_r93.py <repo> <frozen cm550 dir>"""
import collections
import csv
import os
import re
import sys

repo, frozen = sys.argv[1], sys.argv[2]
BATCHES = collections.OrderedDict([
    ("J1", "201d6 20210 2024a 20284 202a0 202bc 20310 20348 20380 2041c 205c4 206a8 20784 20890 20c98 20e14 20fac 21070 21146 211f4"),
    ("J2", "1fdc0 1ff38 212b2 2142c 216c6 21778 21872 21920 21f4e 21fac 22070 231da 23244"),
    ("D1", "ac3c e998 1b754 1b788 1b7f2 1d9b4 253b0 254b6 26834 26852 26854"),
    ("F1", "b3b2 b4ce c2a0 c2ee c742 12484 17120 196e4 1c152 1ca54 1ce58 2658c 26af0 2d9a8 30ade 30b0e 30b10 30b34 30bf6 30c14 30c3c 34512 34dba"),
])
rom = open(os.path.join(repo, "firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin"), "rb").read()
names, by_addr = {}, {}
for r in csv.reader(open(os.path.join(frozen, "function_renames.csv"), newline="")):
    if r and r[0].startswith("0x"):
        names[r[1]] = int(r[0], 16)
        by_addr[int(r[0], 16)] = r[1]
cpp = open(os.path.join(frozen, "J90350.00.ghidra.cpp"), errors="replace").read()
bodies = {m.group(1): m.group(3) for m in re.finditer(r"^// Function: (\w+) @ (0x[0-9a-f]+)\n(.*?)(?=^// Function: |\Z)", cpp, re.M | re.S)}
callees, callers = collections.defaultdict(set), collections.defaultdict(set)
for fn, body in bodies.items():
    code = "\n".join(l for l in body.split("\n") if not l.strip().startswith(("//", "/*", "*")))
    for other in set(re.findall(r"\b(\w+)\b", code)):
        if other in names and other != fn:
            callees[fn].add(other)
            callers[other].add(fn)
matches = collections.defaultdict(list)
for r in csv.DictReader(open(os.path.join(repo, "firmware/cross_firmware_matches.csv"))):
    matches[int(r["cm550_addr"], 16)].append(f"{r['cm848_name']}@{r['cm848_addr']} (score {r['score']})")
for b, addresses in BATCHES.items():
    print(f"== {b}")
    total = 0
    for a in addresses.split():
        addr = int(a, 16)
        fn = by_addr[addr]
        code = [l for l in bodies[fn].split("\n") if l.strip() and not l.strip().startswith(("//", "/*", "*"))]
        total += len(code)
        cs = sorted(callers[fn], key=names.get)
        refs = []
        if not cs:
            i = rom.find(addr.to_bytes(4, "big"))
            while i != -1:
                refs.append(f"0x{i:x}")
                i = rom.find(addr.to_bytes(4, "big"), i + 1)
        line = f"- 0x{addr:05x} {fn} ({len(code)} lines); called by: " + (", ".join(cs) if cs else "nothing by name - its address is stored in the ROM at " + (" ".join(refs) or "NOWHERE"))
        ce = sorted(callees[fn], key=names.get)
        if ce:
            line += "; calls: " + ", ".join(ce)
        if matches.get(addr):
            line += "; scored CM848 candidates (untrusted): " + ", ".join(matches[addr])
        print(line)
    print(f"   ({len(addresses.split())} functions, {total} code lines)")

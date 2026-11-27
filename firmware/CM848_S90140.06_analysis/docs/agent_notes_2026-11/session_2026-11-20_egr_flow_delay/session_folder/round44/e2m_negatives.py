"""Round 44: the e2m negatives behind stage A, done without regex holes (offsets parsed as hex numbers, any padding).
1. records at 107D +0x44..+0x49 and 118F +0x0D..+0x11 in every e2m file;
2. a keyword-free pass for the pedal block 0x408a72-0x408a7e: description keywords over blocks absent from the dumped
   parameter ID table, and every absent block with a run of >= 7 two-byte records at even offsets.
usage: e2m_negatives.py <repo>"""
import glob
import os
import re
import sys

repo = os.path.abspath(sys.argv[1])
sys.path.insert(0, os.path.join(repo, "firmware/scripts"))
import e2m_block_addresses as e  # noqa: E402

table = e.parse_table(open(e.DEFAULTS["flash2"], "rb").read())
files = sorted(glob.glob(os.path.join(repo, "e2m-analysis", "**", "*.e2m"), recursive=True))
records = {}  # (block, offset) -> {(name, size, description)}
files_by_record = {}
for path in files:
    for line in open(path, errors="replace"):
        line = re.sub(r"^#\s*\S+\.e2m:\s*", "", line.strip(), flags=re.I)
        head, _, desc = line.partition(";")
        f = head.split(",")
        if len(f) < 8 or not re.fullmatch(r"[0-9A-Fa-f]{4}", f[2]) or not re.fullmatch(r"[0-9A-Fa-f]{1,4}", f[3]):
            continue
        key = (int(f[2], 16), int(f[3], 16))
        records.setdefault(key, set()).add((f[0], f[7], desc.strip()[:90]))
        files_by_record.setdefault(key, set()).add(os.path.basename(path))
print(f"{len(files)} e2m files, {len(records)} distinct (block, offset) records")

print("== 1. 107D +0x44..+0x49 and 118F +0x0D..+0x11")
hits = [(k, v) for k, v in records.items() if (k[0] == 0x107D and 0x44 <= k[1] <= 0x49) or (k[0] == 0x118F and 0x0D <= k[1] <= 0x11)]
print("   none" if not hits else "\n".join(f"   {k[0]:04X} +{k[1]:02X} {sorted(v)}" for k, v in hits))
print("   (context) 107D offsets:", " ".join(f"{o:02X}" for b, o in sorted(records) if b == 0x107D))
print("   (context) 118F offsets:", " ".join(f"{o:02X}" for b, o in sorted(records) if b == 0x118F))

absent = sorted({b for b, _ in records} - set(table))
print(f"== 2a. description keywords in {len(absent)} blocks absent from the dumped table")
kw = re.compile(r"pedal|accelerator|throttle|idle|learn|disagree|debounce|APS", re.I)
for b in absent:
    for (bb, o), v in sorted(records.items()):
        if bb == b:
            for name, size, desc in sorted(v):
                if kw.search(desc) or kw.search(name):
                    print(f"   {b:04X} +{o:02X} {name} size {size}: {desc}")
print("== 2b. absent blocks with >= 7 two-byte records at even offsets 0..0x1E")
for b in absent:
    two = sorted(o for (bb, o), v in records.items() if bb == b and o % 2 == 0 and o <= 0x1E and any(s == "2" for _, s, _ in v))
    if len(two) >= 7:
        names = [sorted(records[(b, o)])[0][0] for o in two]
        print(f"   {b:04X}: " + ", ".join(f"+{o:02X} {n}" for o, n in zip(two, names)))

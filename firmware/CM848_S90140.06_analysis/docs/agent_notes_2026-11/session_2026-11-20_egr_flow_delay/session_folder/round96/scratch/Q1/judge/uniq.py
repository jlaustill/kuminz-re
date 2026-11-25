"""Check exact-name uniqueness of names in the frozen CSVs of both firmwares.
usage: uniq.py name [name ...]"""
import sys

base = "/home/linux/.claude/jobs/374b0424/tmp/w15/r96/frozen"
files = {
    "cm550_fn": f"{base}/cm550/function_renames.csv",
    "cm550_gv": f"{base}/cm550/global_variables.csv",
    "cm848_fn": f"{base}/cm848/function_renames.csv",
    "cm848_gv": f"{base}/cm848/global_variables.csv",
}
rows = {}
for k, p in files.items():
    rows[k] = []
    for line in open(p, errors="replace"):
        if line.startswith("#"):
            continue
        parts = line.rstrip("\n").split(",")
        if len(parts) >= 2:
            rows[k].append((parts[0], parts[1]))
for name in sys.argv[1:]:
    hits = []
    for k, rs in rows.items():
        for addr, n in rs:
            if n == name or n.split(".")[0] == name:
                hits.append(f"{k}:{addr}:{n}")
    print(f"{name}: {'UNIQUE (no rows)' if not hits else hits}")

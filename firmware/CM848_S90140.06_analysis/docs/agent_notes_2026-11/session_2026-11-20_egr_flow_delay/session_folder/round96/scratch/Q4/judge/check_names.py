"""Check that proposed names are unique in the frozen CSVs (function and global names) of both firmwares.
usage: check_names.py <name> [<name> ...]"""
import sys

base = "/home/linux/.claude/jobs/374b0424/tmp/w15/r96/frozen/"


def load(path):
    names = {}
    for line in open(path, errors="replace"):
        if line.startswith("#") or not line.strip():
            continue
        parts = line.rstrip("\n").split(",")
        if len(parts) >= 2:
            names.setdefault(parts[1], []).append(parts[0])
    return names


sets = {
    "cm550_func": load(base + "cm550/function_renames.csv"),
    "cm550_glob": load(base + "cm550/global_variables.csv"),
    "cm848_func": load(base + "cm848/function_renames.csv"),
    "cm848_glob": load(base + "cm848/global_variables.csv"),
}
for arg in sys.argv[1:]:
    hits = [f"{k}:{v}" for k, d in sets.items() for n, v in d.items() if n == arg]
    print(arg, "->", hits if hits else "FREE")

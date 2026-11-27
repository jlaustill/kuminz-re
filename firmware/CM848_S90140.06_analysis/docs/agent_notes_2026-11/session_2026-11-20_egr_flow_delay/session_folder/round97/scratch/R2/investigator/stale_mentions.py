"""List rows of the frozen CM550 CSVs whose text mentions an old name this batch renames (stale after the rename).
usage: stale_mentions.py"""
import re

BASE = "/home/linux/.claude/jobs/374b0424/tmp/w15/r97"
props = [line.rstrip("\n").split("\t") for line in open(f"{BASE}/scratch/R2/investigator/proposals.tsv") if line.strip()]
family = {line.split()[0]: line.split()[1] for line in open(f"{BASE}/family_R2.txt") if line.strip()}
old_names = {family[p[0]]: p[1] for p in props if p[0] in family and family[p[0]] != p[1]}
files = ["global_variables.csv", "function_renames.csv", "structure_definitions.csv", "enums.csv",
         "function_definitions.csv", "local_variables.csv"]
pattern = re.compile(r"\b(" + "|".join(sorted(map(re.escape, old_names), key=len, reverse=True)) + r")\b")
for name in files:
    for number, line in enumerate(open(f"{BASE}/frozen/cm550/{name}", errors="replace"), 1):
        first = line.split(",", 2)
        hits = set(pattern.findall(line))
        # skip the row that defines the old name itself
        if len(first) > 1 and first[1] in hits and name == "global_variables.csv":
            hits.discard(first[1])
        if hits:
            print(f"{name}:{number}: {first[0]} {first[1][:60] if len(first) > 1 else ''} -> {sorted(hits)}")

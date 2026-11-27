"""Stem check limited to the caches round 10 named after their tables (stages A and D, map_r10a.csv / map_r10d.csv,
followed through stage C's suffix change): for each lookup call that takes one of them, the cache's stem must be the
stem of a table argument. usage: stem_check_r10.py <cpp> <map_r10a.csv> <map_r10c.csv> <map_r10d.csv>"""
import csv
import re
import sys

cpp, map_a, map_c, map_d = sys.argv[1:5]
suffix_change = {r["old_label"]: r["name"] for r in csv.DictReader(open(map_c))}
names = set()
for r in csv.DictReader(open(map_a)):
    names.add(suffix_change.get(r["name"], r["name"]))
for r in csv.DictReader(open(map_d)):
    names.add(r["name"])
text = open(cpp).read()
CALL = re.compile(r"(lookupTableInterpolation|cm848_dualAxisTableInterpolation)\s*\(\s*&?\s*([a-z0-9_]+?)(\[\d\])?\s*,"
                  r"([^;]*?)\)\s*;", re.S)
SUFFIX = re.compile(r"_cached_axis_offsets?(?:_y|_\d+)?$")
TABLE = re.compile(r"\b([a-z0-9_]+?)_(?:x_axis|y_axis|axis|values|grid|table)\b")
seen, bad = set(), []
for m in CALL.finditer(text):
    cache = m.group(2)
    if cache not in names:
        continue
    seen.add(cache)
    stem = SUFFIX.sub("", cache)
    stems = set(TABLE.findall(m.group(4)))
    if stem not in stems:
        bad.append((cache, sorted(stems)))
print(f"{len(names)} round 10 table-named caches; {len(seen)} seen in lookup calls; {len(bad)} calls do not match")
for b in bad:
    print(" ", b)
print("not seen in a direct lookup call:", sorted(names - seen))

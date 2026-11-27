"""For every lookup call whose first argument is a *_cached_axis_offset* cache, check that the cache's stem equals the
stem of the table arguments (<stem>_axis / _x_axis / _y_axis / _values / _grid / _table). Prints the calls that do
not match. usage: stem_check.py <cpp>"""
import re
import sys

text = open(sys.argv[1]).read()
CALL = re.compile(r"(lookupTableInterpolation|cm848_dualAxisTableInterpolation)\s*\(\s*&?([a-z0-9_]+?)(\[\d\])?\s*,"
                  r"([^;]*?)\)\s*;", re.S)
SUFFIX = re.compile(r"_cached_axis_offsets?(?:_y|_\d+)?$")
TABLE = re.compile(r"\b([a-z0-9_]+?)_(?:x_axis|y_axis|axis|values|grid|table)\b")
checked = mismatched = 0
for m in CALL.finditer(text):
    cache = m.group(2)
    if not SUFFIX.search(cache):
        continue
    stem = SUFFIX.sub("", cache)
    stems = set(TABLE.findall(m.group(4)))
    if not stems:
        continue
    checked += 1
    if stem not in stems:
        mismatched += 1
        print(f"{cache}: tables {sorted(stems)}")
print(f"{checked} calls checked, {mismatched} mismatches")

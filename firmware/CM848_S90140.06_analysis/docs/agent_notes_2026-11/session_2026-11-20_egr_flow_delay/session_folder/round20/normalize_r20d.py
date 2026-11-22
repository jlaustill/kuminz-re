"""Proof helper for round 20 stage D: rewrite the new .cpp back to the old forms -
<word>.<field> -> (<word> & mask) for every algorithm_enable_flags_<N>_t typed this stage (the map comes from
structure_definitions.csv), and cold_delta_fuel_cached_axis_offsets -> &DAT_003fb35c - then gate on per-word, per-mask
counts (old masked reads = new field reads), no masked read left on a typed word, no piece access.
usage: normalize_r20d.py <old.cpp> <new.cpp> <structure_definitions.csv> <out.cpp> <word> [<word> ...]"""
import collections
import re
import sys

old_cpp, new_cpp, struct_csv, out_cpp = sys.argv[1:5]
words = [int(w) for w in sys.argv[5:]]
fields = collections.defaultdict(dict)
for line in open(struct_csv):
    m = re.match(r"algorithm_enable_flags_(\d+)_t,,(\w+),bitfield:1@(\d+),", line)
    if m and int(m.group(1)) in words:
        fields[int(m.group(1))][m.group(2)] = 1 << int(m.group(3))
assert all(len(fields[w]) == 16 for w in words), {w: len(fields[w]) for w in words}


def code_only(text):
    text = re.sub(r"/\*.*?\*/", lambda m: "\n" * m.group(0).count("\n"), text, flags=re.S)
    return re.sub(r"//[^\n]*", "", text)


old, new = open(old_cpp).read(), open(new_cpp).read()
old_code, new_code = code_only(old), code_only(new)
problems = []
for w in words:
    name = f"algorithm_enable_flags_{w}_cal"
    old_counts = collections.Counter(int(m, 0) for m in re.findall(rf"\b{name}\s*&\s*(0x[0-9a-fA-F]+|\d+)\)", old_code))
    new_counts = collections.Counter()
    for f, n in collections.Counter(re.findall(rf"\b{name}\.(\w+)", new_code)).items():
        if f not in fields[w]:
            problems.append(f"{name}.{f}: not a field of the struct")
            continue
        new_counts[fields[w][f]] += n
    if old_counts != new_counts:
        problems.append(f"{name}: old masked reads {dict(old_counts)} != new field reads {dict(new_counts)}")
    if re.search(rf"\b{name}\s*&", new_code):
        problems.append(f"{name}: a masked read is left in the new .cpp")
    if re.search(rf"\b{name}\._\d", new_code):
        problems.append(f"{name}: a piece access in the new .cpp")
text = new
total = 0
for w in words:
    for f, mask in fields[w].items():
        m = str(mask) if mask < 10 else f"0x{mask:x}"
        text, n = re.subn(rf"\balgorithm_enable_flags_{w}_cal\.{f}\b", f"(algorithm_enable_flags_{w}_cal & {m})", text)
        total += n
text, n_cache = re.subn(r"\bcold_delta_fuel_cached_axis_offsets\b", "&DAT_003fb35c", text)
open(out_cpp, "w").write(text)
print(f"{len(words)} words, {total} field reads rewritten, cache uses {n_cache}")
print("\n".join(problems) if problems else "count gate: PASS (per word and mask, old masked reads = new field reads)")

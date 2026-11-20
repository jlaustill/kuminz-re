"""One-off patch of build_results.py: member comments must not contain a comma (enums.csv column order)."""
path = "/tmp/w14_functions3/build_results.py"
s = open(path).read()
old = '''    for m in row["members"]:
        if m["new"]:'''
new = '''    for m in row["members"]:
        if "," in m["comment"]:
            problems.append(f"{tag}: member {m['old']} comment contains a comma (enums.csv column order)")
        if m["new"]:'''
assert old in s
s = s.replace(old, new)
open(path, "w").write(s)
print("patched")

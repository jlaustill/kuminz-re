"""Round 37 check: a statement diff of named functions between two .cpp files. Both sides drop comments and local
declarations, unify undefined1 / undefined2 / undefined4 with byte / word / dword, number the temporaries
(uVar1, pbVar3, ...) by first use, and apply the given old -> new rewrites (regex; parameter / field forms) to the
old side. What is left is printed statement by statement.
usage: statement_diff.py <old cpp> <new cpp> <rules.json> <function>...
rules.json: {"function": [["old regex", "replacement"], ...], "*": [...]}"""
import difflib
import json
import re
import sys

old_cpp, new_cpp, rules_path, names = sys.argv[1], sys.argv[2], sys.argv[3], sys.argv[4:]
rules = json.load(open(rules_path))
TEMP = re.compile(r"\b(?:[a-z]{1,3}Var\d+|[a-z]{1,2}Stack_[0-9a-f]+|extraout_r\d+(?:_\d+)?)\b")


def body(path, name):
    t = open(path, errors="replace").read()
    m = re.search(r"^// Function: " + re.escape(name) + r" @[^\n]*\n(.*?)(?=^// Function: |\Z)", t, re.S | re.M)
    s = re.sub(r"/\*.*?\*/", "", m.group(1), flags=re.S)
    return re.sub(r"\s+", " ", s)


def canon(s, extra):
    for pat, rep in extra:
        s = re.sub(pat, rep, s)
    s = s.replace("undefined1", "byte").replace("undefined2", "word").replace("undefined4", "dword")
    s = re.sub(r"(?<=[{;}]) ?(?:const )?[A-Za-z_][A-Za-z0-9_]* \**[A-Za-z_][A-Za-z0-9_]*(?: \[\d+\])?(?:\[\d+\])?;",
               "", s)
    seen = {}
    s = TEMP.sub(lambda m: seen.setdefault(m.group(0), f"T{len(seen)}"), s)
    return [x.strip() for x in re.split(r"(?<=[;{}])", s) if x.strip()]


for name in names:
    extra = [tuple(r) for r in rules.get(name, []) + rules.get("*", [])]
    post = [tuple(r) for r in rules.get('*', [])]
    a, b = canon(body(old_cpp, name), extra), canon(body(new_cpp, name), post)
    a = [x for x in a if x != ';']
    b = [x for x in b if x != ';']
    d = [x for x in difflib.unified_diff(a, b, "old", "new", n=0, lineterm="") if x[:1] in "+-" and x[:3] not in
         ("---", "+++")]
    print(f"===== {name}: {len(d)} differing statements")
    for x in d:
        print("  " + x[:200])

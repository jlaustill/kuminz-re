"""Round 96: diff one function's body between two decompilations with decompiler temporaries normalized
(xVarN -> T, local_N -> L), the map applied to the old text, and statements joined onto one line each
(a statement ends at ';' or '{' or '}'). usage: normalized_fdiff_r96.py <old.cpp> <new.cpp> <hex address> [map.csv]"""
import csv
import difflib
import re
import sys

old_path, new_path, address = sys.argv[1], sys.argv[2], int(sys.argv[3], 16)
mapping = {}
if len(sys.argv) > 4:
    for r in csv.DictReader(open(sys.argv[4])):
        if r["old_label"]:
            mapping[r["old_label"]] = r["name"]


def body(path):
    text = open(path, errors="replace").read()
    m = re.search(r"// Function: \S+ @ 0x%08x\n" % address, text)
    assert m, (path, hex(address))
    end = text.find("\n// Function: ", m.end())
    return text[m.end():end if end > 0 else len(text)]


def statements(text, apply_map):
    text = re.sub(r"/\*.*?\*/", "", text, flags=re.S)
    if apply_map and mapping:
        text = re.sub(r"\b[A-Za-z_][A-Za-z0-9_]*\b", lambda t: mapping.get(t.group(0), t.group(0)), text)
    text = re.sub(r"\b[a-z]{1,3}Var\d+\b", "T", text)
    text = re.sub(r"\blocal_[0-9a-f]+\b", "L", text)
    text = re.sub(r"\s+", " ", text)
    return [s.strip() for s in re.split(r"(?<=[;{}])", text) if s.strip()]


a, b = statements(body(old_path), True), statements(body(new_path), False)
for line in difflib.unified_diff(a, b, lineterm="", n=0):
    if not line.startswith(("---", "+++", "@@")):
        print(line[:220])

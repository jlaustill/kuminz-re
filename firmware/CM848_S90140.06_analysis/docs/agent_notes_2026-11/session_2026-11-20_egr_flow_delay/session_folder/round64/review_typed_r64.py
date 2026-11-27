"""Stage review for a type change: for each named function, compare its body in the old and new .cpp (plates and
declarations excluded) - casts added / removed, placeholder names (param_N / [a-z]Var / local_) added / removed and
the line counts. With --diff also print the changed lines.  usage: review_typed.py <old.cpp> <new.cpp> [--diff] <name>..."""
import difflib
import re
import sys

old_path, new_path, rest = sys.argv[1], sys.argv[2], sys.argv[3:]
show = "--diff" in rest
names = [n for n in rest if n != "--diff"]
CAST = re.compile(r"\((?:[a-zA-Z_][a-zA-Z0-9_]*\s*\**\s*)\)\s*(?=[\w(&*-])")
PLACEHOLDER = re.compile(r"\b(?:param_\d+|[a-zA-Z]{1,2}Var\d+|[a-z]{1,3}Stack_[0-9a-f]+|local_[0-9a-f]+|in_r\w+|extraout_\w+)\b")
TYPES = r"(?:byte|char|bool|short|ushort|word|int|uint|dword|long|float|double|undefined\d?|code|j1939_\w+|[A-Z][A-Z0-9_]+)"


def body(path, name):
    text = open(path, errors="replace").read()
    m = re.search(rf"^// Function: {re.escape(name)} @.*?(?=^// Function: |\Z)", text, re.M | re.S)
    if not m:
        return None
    block = m.group(0).split("*/", 1)[-1] if "/*" in m.group(0)[:400] else m.group(0)
    lines = [l.strip() for l in block.split("\n") if l.strip() and l.strip() != "//"]
    head = [l for l in lines if not re.fullmatch(rf"{TYPES}\s*\**\s*\w+(\s*\[\d+\])?;", l)]
    return head


total = {"casts+": 0, "casts-": 0, "placeholders+": 0, "placeholders-": 0}
for name in names:
    a, b = body(old_path, name), body(new_path, name)
    if a is None or b is None:
        print(f"{name}: missing ({'old' if a is None else 'new'})")
        continue
    ca, cb = sum(len(CAST.findall(l)) for l in a[1:]), sum(len(CAST.findall(l)) for l in b[1:])
    pa = sum(len(PLACEHOLDER.findall(l)) for l in a)
    pb = sum(len(PLACEHOLDER.findall(l)) for l in b)
    total["casts+"] += max(0, cb - ca)
    total["casts-"] += max(0, ca - cb)
    total["placeholders+"] += max(0, pb - pa)
    total["placeholders-"] += max(0, pa - pb)
    print(f"{name}: casts {ca} -> {cb} | placeholders {pa} -> {pb} | lines {len(a)} -> {len(b)}")
    if show:
        for line in difflib.unified_diff(a, b, lineterm="", n=0):
            if line[:1] in "+-" and not line.startswith(("+++", "---")):
                print("    " + line[:170])
print("totals:", total)

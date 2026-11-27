"""Round 27: normalized diff of two decompiled function bodies (is Type A vs Type B only signed vs unsigned?).
Normalizes: the function's own name and LAB_ / local auto-names (uVarN, iVarN, wVarN, sVarN, cVarN, bVarN) to
placeholders numbered by first appearance, whitespace runs to one space. Prints a unified diff.
usage: normalized_body_diff.py <cpp> <function A> <function B>"""
import difflib
import re
import sys

cpp, fa, fb = sys.argv[1:4]
text = open(cpp).read()


def body(name):
    m = re.search(r"^// Function: " + re.escape(name) + r" @[^\n]*\n(.*?)(?=^// Function: )", text, re.S | re.M)
    return m.group(1)


def normalize(src, name):
    src = src.replace(name, "FUNC")
    seen = {}

    def sub(m):
        k = m.group(0)
        if k not in seen:
            seen[k] = f"{'LAB' if k.startswith('LAB_') else 'V'}{len(seen)}"
        return seen[k]
    src = re.sub(r"\bLAB_[0-9a-f]{8}\b|\b[uiwscbd]Var\d+\b|\bextraout_\w+\b", sub, src)
    lines = []
    for line in src.splitlines():
        line = re.sub(r"\s+", " ", line).strip()
        if line and not line.startswith(("/*", "*", "//")):
            lines.append(line)
    return lines


a, b = normalize(body(fa), fa), normalize(body(fb), fb)
diff = list(difflib.unified_diff(a, b, fa, fb, n=0, lineterm=""))
print(f"{len(a)} vs {len(b)} lines; {sum(1 for d in diff if d.startswith(('-', '+')) and not d.startswith(('---', '+++')))} differing lines")
print("\n".join(diff[:80]))

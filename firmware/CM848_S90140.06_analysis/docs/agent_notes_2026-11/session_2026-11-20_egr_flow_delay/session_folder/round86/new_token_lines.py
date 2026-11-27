"""Print the lines of each listed function that carry an artifact token (unaff_ / extraout_ / in_ / uStack / CONCAT) in
the post build but not in the pre build, so each can be classified: inside a call's argument list (a stale byte of a
pushed word) or in a test / assignment of a call result (a return row too narrow or missing).
usage: new_token_lines.py <pre cpp> <post cpp> <function name>..."""
import re
import sys

TOKEN = re.compile(r"\b(?:unaff_\w+|extraout_\w+|in_\w+|uStack_\w+|CONCAT\d+)")


def body(path, name):
    text = re.sub(r"/\*.*?\*/", "", open(path, errors="replace").read(), flags=re.S)
    m = re.search(rf"^// Function: {re.escape(name)} @ [^\n]*\n(.*?)(?=^// Function: |\Z)", text, re.M | re.S)
    return m.group(1) if m else ""


for name in sys.argv[3:]:
    before = set(re.sub(r"\s+", " ", l.strip()) for l in body(sys.argv[1], name).split("\n"))
    lines = [re.sub(r"\s+", " ", l.strip()) for l in body(sys.argv[2], name).split("\n")]
    new = [l for l in lines if TOKEN.search(l) and l not in before]
    print(f"== {name}: {len(new)} new token lines")
    for l in new[:6]:
        print("   ", l[:160])

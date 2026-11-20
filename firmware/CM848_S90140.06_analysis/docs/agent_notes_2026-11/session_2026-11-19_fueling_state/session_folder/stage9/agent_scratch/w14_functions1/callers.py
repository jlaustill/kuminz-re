"""callers.py: real call sites (comments stripped) of the functions1 items in the current .cpp.
Also prints the callees (named functions called inside each body) for the items."""
import json
import re

CPP = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-fueling-state-enum/firmware/CM848_S90140.06_analysis/output/cm848_rom.ghidra.cpp"
BINS = "/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage9/bins/"
items = json.load(open(BINS + "functions1.json"))["functions"]
text = open(CPP).read().split("\n")
starts = [(i, m.group(1)) for i, line in enumerate(text) if (m := re.match(r"^// Function: (\S+) @", line))]
spans = {}
for k, (i, name) in enumerate(starts):
    spans[name] = (i, starts[k + 1][0] if k + 1 < len(starts) else len(text))


def strip_comments(lines):
    s = "\n".join(lines)
    s = re.sub(r"/\*.*?\*/", "", s, flags=re.S)
    s = re.sub(r"//[^\n]*", "", s)
    return s


bodies = {n: strip_comments(text[a:b]) for n, (a, b) in spans.items()}
names = [x["current"] for x in items]
for nm in names:
    callers = sorted(f for f, body in bodies.items() if f != nm and re.search(r"\b" + re.escape(nm) + r"\s*\(", body))
    own = bodies.get(nm, "")
    callees = sorted({f for f in spans if f != nm and re.search(r"\b" + re.escape(f) + r"\s*\(", own)})
    print(f"{nm}: callers={callers} callees={callees}")

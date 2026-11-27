"""Token-normalized gate for a type change: old.cpp with the 'old' tokens mapped to canonical tokens (and the
'old_regex' substitutions applied), new.cpp with the 'new' tokens (and 'new_regex'), then comments stripped, labels
canonical, declarations sorted, whitespace dropped, compared per function. Also prints the piece / underscore census.
tokens.json: {"old": {render: token}, "new": {render: token}, "old_regex": [[pattern, repl]], "new_regex": [...]}.
usage: prove_tokens.py <old.cpp> <new.cpp> <tokens.json> [--show N]"""
import json
import re
import sys

sys.path.insert(0, "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/scripts/rename_waves")
from common import canonical_labels, strip_comments, strip_generated_header  # noqa: E402

old_path, new_path, tokens_path = sys.argv[1:4]
show = int(sys.argv[sys.argv.index("--show") + 1]) if "--show" in sys.argv else 4
spec = json.load(open(tokens_path))
DECL = re.compile(r"^  [A-Za-z_][\w ]*[\w\*]\s*\**[A-Za-z_]\w*(\[\d+\])?;$")


def census(text):
    code = strip_comments(text)
    return len(re.findall(r"\._\d+_\d+_", code)), len(re.findall(r"(?<![A-Za-z0-9_.>])_[a-z][a-z0-9_]{3,}\b", code))


def normalize(text, mapping, regexes):
    text = strip_comments(strip_generated_header(text))
    for pat, rep in regexes:
        text = re.sub(pat, rep, text)
    for k in sorted(mapping, key=len, reverse=True):
        text = re.sub(r"(?<![A-Za-z0-9_.])" + re.escape(k) + r"(?![A-Za-z0-9_])", mapping[k], text)
    return canonical_labels(text)


def functions(text):
    out = {}
    for c in re.split(r"(?m)^(?=// Function: )", text):
        m = re.match(r"// Function: (\S+)", c)
        lines = c.split("\n")
        if "{" in lines:
            i = lines.index("{") + 1
            j = i
            while j < len(lines) and DECL.match(lines[j]):
                j += 1
            lines[i:j] = sorted(lines[i:j])
        out[m.group(1) if m else "_head"] = re.sub(r"\s+", "", "\n".join(lines))
    return out


old, new = open(old_path).read(), open(new_path).read()
print("pieces / underscore names: old %d / %d, new %d / %d" % (census(old) + census(new)))
fo = functions(normalize(old, spec["old"], spec.get("old_regex", [])))
fn = functions(normalize(new, spec["new"], spec.get("new_regex", [])))
differ = [f for f in fo if fo[f] != fn.get(f)]
print(f"functions {len(fo)}; differing after the token normalization: {len(differ)}")
for f in differ[:show]:
    a, b = fo[f], fn.get(f, "")
    i = next((k for k in range(min(len(a), len(b))) if a[k] != b[k]), min(len(a), len(b)))
    print("==", f)
    print("   old:", a[max(0, i - 80):i + 120])
    print("   new:", b[max(0, i - 80):i + 120])
print("GATE PASS" if not differ else "GATE: review the differences")

"""List EVERY function that differs between an old .cpp and a reversed new .cpp (reverse_names.py --write-reversed),
with reverse_names.py's normalization: comments stripped, each function's declaration block sorted, whitespace dropped.
(reverse_names.py itself prints at most six DIFF entries.)
usage: all_diff_functions.py <old.cpp> <reversed new.cpp> <repo>"""
import re
import sys

old_path, new_path, repo = sys.argv[1:4]
sys.path.insert(0, f"{repo}/firmware/scripts/rename_waves")
from common import canonical_labels, strip_comments, strip_generated_header  # noqa: E402

DECL = re.compile(r"^  [A-Za-z_][\w ]*[\w\*]\s*\**[A-Za-z_]\w*(\[\d+\])?;$")


def functions(path, comments_already_stripped=False):
    text = strip_generated_header(open(path, errors="replace").read())
    if not comments_already_stripped:  # the reversed file is also label-canonical (reverse_names --canonical-code-labels)
        text = canonical_labels(strip_comments(text))
    out = {}
    for chunk in re.split(r"(?m)^(?=// Function: )", text):
        m = re.match(r"// Function: (\S+)", chunk)
        lines = chunk.split("\n")
        if "{" in lines:
            i = lines.index("{") + 1
            j = i
            while j < len(lines) and DECL.match(lines[j]):
                j += 1
            lines[i:j] = sorted(lines[i:j])
        out[m.group(1) if m else "<header>"] = re.sub(r"\s+", "", "\n".join(lines))
    return out


old, new = functions(old_path), functions(new_path, comments_already_stripped=True)
differ = sorted(n for n in old if n in new and old[n] != new[n])
print(len(differ), "functions differ:", " ".join(differ))

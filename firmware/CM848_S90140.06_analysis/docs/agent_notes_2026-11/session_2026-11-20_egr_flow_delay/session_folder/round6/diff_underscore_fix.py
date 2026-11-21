"""Stage 0b check: deleting the orphan governor_control_t / etc1_state_t struct definitions may change only the
underscore renders of the globals the dead struct overlapped (and drop the overlap warning lines).
usage: diff_underscore_fix.py old.cpp new.cpp NAME[,NAME...]"""
import difflib
import re
import sys

old_path, new_path, names = sys.argv[1], sys.argv[2], sys.argv[3].split(",")
WARN = "/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */"
UNDER = re.compile(r"\b_(" + "|".join(map(re.escape, names)) + r")\b")


def norm(path):
    out = []
    for line in open(path).read().split("\n"):
        if line.startswith("// Generated") or line.strip() == WARN or not line.strip():
            continue
        out.append(UNDER.sub(r"\1", line))
    return out


old, new = norm(old_path), norm(new_path)
residual = [d for d in difflib.unified_diff(old, new, lineterm="", n=0) if d[:1] in "+-" and d[:3] not in ("+++", "---")]
print("\n".join(residual[:20]))
print(f"residual lines: {len(residual)}")
text_old, text_new = open(old_path).read(), open(new_path).read()
for n in names:
    print(f"_{n}: {len(re.findall(r'\b_' + re.escape(n) + r'\b', text_old))} -> {len(re.findall(r'\b_' + re.escape(n) + r'\b', text_new))}")
print(f"overlap warnings: {text_old.count(WARN)} -> {text_new.count(WARN)}")

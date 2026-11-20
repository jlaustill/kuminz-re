"""Every call of a function in the .cpp (calls split over several lines joined), with the enclosing function, the
assignment target and the last argument.
usage: filter_call_census.py <cpp> <function name>"""
import re
import sys

path, callee = sys.argv[1:3]
lines = open(path, errors="replace").read().split("\n")
function_at, current = [], ""
for line in lines:
    m = re.match(r"// Function: (\S+)", line)
    if m:
        current = m.group(1)
    function_at.append(current)
text = "\n".join(lines)
offsets = [0]
for line in lines:
    offsets.append(offsets[-1] + len(line) + 1)


def line_of(position):
    lo, hi = 0, len(offsets) - 1
    while lo < hi:
        mid = (lo + hi + 1) // 2
        if offsets[mid] <= position:
            lo = mid
        else:
            hi = mid - 1
    return lo


count = 0
for m in re.finditer(re.escape(callee) + r"\s*\(", text):
    n = line_of(m.start())
    stripped = lines[n].strip()
    if stripped.startswith(("//", "/*", "*")) or re.match(r"^\w[\w\s\*]*\b" + re.escape(callee) + r"\s*\(", stripped) \
            and not re.search(r"[=;]", stripped.split(callee)[0]):
        if lines[n].startswith((" ", "\t")) is False:
            continue
    depth, i = 0, m.end() - 1
    while i < len(text):
        if text[i] == "(":
            depth += 1
        elif text[i] == ")":
            depth -= 1
            if depth == 0:
                break
        i += 1
    args = re.sub(r"\s+", " ", text[m.end():i])
    before = re.sub(r"\s+", " ", text[offsets[n]:m.start()]).strip()
    target = before[:-1].strip() if before.endswith("=") else before
    last = args.rsplit(",", 1)[-1].strip()
    if not lines[n].startswith((" ", "\t")) and not before.endswith("="):
        continue
    count += 1
    print(f"{n + 1} | {function_at[n]} | {target[-60:]} | {last}")
print(f"{count} calls")

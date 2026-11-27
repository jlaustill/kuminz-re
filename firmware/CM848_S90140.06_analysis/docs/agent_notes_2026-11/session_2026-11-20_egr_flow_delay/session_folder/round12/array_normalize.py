"""Proof helper for scalar rows typed as arrays: rewrite the new .cpp to the scalar rendering - `name[<constant k>]`
-> the label the element's address had (the name itself for k = 0, else DAT_<address>), `name[<expression>]` ->
`(&name)[<expression>]`, `&name[0]` -> `&name`, and a bare `name` (the decayed array) -> `&name` - so
cast_normalized_diff.py can compare it with the old .cpp. usage: array_normalize.py <new.cpp> <out.cpp> <arrays.json>"""
import json
import re
import sys

new_path, out_path, spec_path = sys.argv[1:4]
spec = json.load(open(spec_path))
text = open(new_path).read()
counts = {}


def find_close(s, i):
    """index of the ] that closes the [ at s[i]"""
    depth = 0
    for j in range(i, len(s)):
        if s[j] == "[":
            depth += 1
        elif s[j] == "]":
            depth -= 1
            if depth == 0:
                return j
    return -1


for entry in spec:
    name, base, size, count = entry[:4]
    old_base = entry[4] if len(entry) > 4 else name
    out, pos, n = [], 0, 0
    pattern = re.compile(r"(&)?(?<![A-Za-z0-9_])" + re.escape(name) + r"(?![A-Za-z0-9_])")
    for m in pattern.finditer(text):
        if m.start() < pos:
            continue
        out.append(text[pos:m.start()])
        after = m.end()
        amp = m.group(1) or ""
        if after < len(text) and text[after] == "[":
            close = find_close(text, after)
            index = text[after + 1:close].strip()
            if re.fullmatch(r"0x[0-9a-f]+|\d+", index):
                k = int(index, 0)
                label = old_base if k == 0 else f"DAT_{base + k * size:08x}"
                out.append(amp + label)
            else:
                out.append(f"{amp}(&{old_base})[{index}]" if not amp else f"&(&{old_base})[{index}]")
            pos = close + 1
        else:
            out.append(f"&{old_base}" if amp or True else m.group(0))
            pos = after
        n += 1
    out.append(text[pos:])
    text = "".join(out)
    counts[name] = n
open(out_path, "w").write(text)
print("rewritten uses:", counts)

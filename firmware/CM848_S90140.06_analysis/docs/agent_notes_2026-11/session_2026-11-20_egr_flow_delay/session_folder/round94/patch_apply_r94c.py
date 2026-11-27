"""Round 94 tooling: apply_r94.py creates an enum that does not exist yet when overrides_r94.json names its size
("new_enums": {fw: {ENUM_NAME: size}}); the first member written adds a header line. Idempotent.
usage: patch_apply_r94c.py <apply_r94.py>"""
import sys

p = sys.argv[1]
s = open(p).read()
old = '''            rows = [(i, next(csv.reader([l.rstrip("\\r")]))) for i, l in enumerate(lines) if l.startswith(e["enum_name"] + ",")]
            if not rows:
                problems.append(f"{b}: {fw} has no enum {e['enum_name']}")
                continue'''
new = '''            rows = [(i, next(csv.reader([l.rstrip("\\r")]))) for i, l in enumerate(lines) if l.startswith(e["enum_name"] + ",")]
            if not rows:
                size = ((OVERRIDES.get("new_enums") or {}).get(fw) or {}).get(e["enum_name"])
                if not size:
                    problems.append(f"{b}: {fw} has no enum {e['enum_name']}")
                    continue
                while lines and lines[-1] == "":
                    lines.pop()
                lines += ["", f"# {e['enum_name']}: a new enum of batch {b} ({R})"]
                head = [e["enum_name"], str(value), new, "", str(size)]
                lines.append(",".join(head[:3]) + "," + csv_field(f"{comment} ({R})") + f",{size}" + E)
                lines.append("")
                state[fw]["enums.csv"] = "\\n".join(lines)
                report.append(f"{b} {fw} enum {e['enum_name']} created (size {size}) with {value}: {new}")
                continue'''
if new not in s:
    assert s.count(old) == 1, s.count(old)
    s = s.replace(old, new)
open(p, "w").write(s)
print("patched")

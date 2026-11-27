"""Quote the comment column of the enums.csv rows a round wrote (ApplyEnums parses with the quote-aware
ScriptUtils.parseCSVLine, so a comma inside an unquoted comment shifts the size column). A row is
enum_name,value,member,comment,size: the comment is everything between the third comma and the last one.
Only rows containing the marker and not already quoted are touched. Idempotent; keeps line endings.
usage: quote_enum_comments.py <enums.csv> <marker>"""
import sys

path, marker = sys.argv[1], sys.argv[2]
data = open(path, newline="").read()
eol = "\r\n" if "\r\n" in data else "\n"
lines = data.split(eol)
changed = 0
for i, l in enumerate(lines):
    if marker not in l or l.startswith("#"):
        continue
    head = l.split(",", 3)
    if len(head) < 4:
        continue
    rest, _, size = head[3].rpartition(",")
    if rest.startswith('"') and rest.endswith('"'):
        continue
    if "," in rest or '"' in rest:
        lines[i] = ",".join(head[:3]) + ',"' + rest.replace('"', '""') + '",' + size
        changed += 1
open(path, "w", newline="").write(eol.join(lines))
print(changed, "rows quoted")

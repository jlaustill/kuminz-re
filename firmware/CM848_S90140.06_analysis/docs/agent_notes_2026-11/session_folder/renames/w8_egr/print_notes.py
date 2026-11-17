import json
import sys

path = sys.argv[1]
rows = [json.loads(line) for line in open(path) if line.strip()]
for index, row in enumerate(rows):
    if row.get("kind") == "note":
        print("=== ROW", index, "===")
        print(row.get("text"))
        extra = {key: value for key, value in row.items() if key not in ("kind", "text")}
        if extra:
            print("EXTRA:", extra)
        print()

"""Round 95 (read-only): print every passage of the batch files (proposal notes, verdict overall, element comments and
reasons) that mentions one of the given names, so the struct / enum definitions can be read in one place.
usage: struct_texts_r95.py <name> <batch.json>..."""
import json
import sys

name = sys.argv[1]


def walk(obj, path):
    if isinstance(obj, dict):
        for k, v in obj.items():
            yield from walk(v, f"{path}.{k}")
    elif isinstance(obj, list):
        for i, v in enumerate(obj):
            yield from walk(v, f"{path}[{i}]")
    elif isinstance(obj, str) and name in obj:
        yield path, obj


for p in sys.argv[2:]:
    d = json.load(open(p))
    for path, text in walk(d, d["batch"]):
        i = text.find(name)
        print(f"== {path} ({len(text)} chars)")
        print(text[max(0, i - 200): i + 2200])
        print()

"""Print result_W2.json as the StructuredOutput call takes it: one compact JSON object per word, the renames, the
raw notes. usage: print_payload.py <result.json> [word number | renames | notes]"""
import json
import sys

d = json.load(open(sys.argv[1]))
what = sys.argv[2] if len(sys.argv) > 2 else "all"
for w in d["words"]:
    if what in ("all", str(w["word"])):
        head = {k: w[k] for k in w if k != "fields"}
        print("WORD", w["word"])
        print(json.dumps(head, ensure_ascii=True))
        for f in w["fields"]:
            print(json.dumps(f, ensure_ascii=True))
        print()
if what in ("all", "renames"):
    print("RENAMES")
    print(json.dumps(d["cm848_field_renames"], ensure_ascii=True))
    print()
if what in ("all", "notes"):
    print("NOTES")
    print(json.dumps(d["notes"], ensure_ascii=True))

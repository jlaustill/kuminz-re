"""Print the result texts recorded in a workflow journal (one per finished agent), each cut to a length.
usage: journal_results.py <journal.jsonl> <max characters per result>"""
import json
import sys

limit = int(sys.argv[2])
for line in open(sys.argv[1]):
    try:
        record = json.loads(line)
    except ValueError:
        continue
    if record.get("type") != "result":
        continue
    value = record.get("value", record.get("result"))
    text = value if isinstance(value, str) else json.dumps(value, indent=1)
    print(f"===== {record.get('label') or record.get('key') or ''} ({len(text)} characters)")
    print(text[:limit])
    print()

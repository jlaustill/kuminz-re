"""Write each subagent's final report (its SubagentHandback message) from the session's subagents/ folder to
<out dir>/<description>.md, with the usage numbers from the transcript.
usage: extract_handback_reports.py <session folder (the transcript path without .jsonl)> <out dir> <description>..."""
import json
import os
import re
import sys

session, out, descriptions = sys.argv[1], sys.argv[2], sys.argv[3:]
folder = os.path.join(session, "subagents")
for meta_name in sorted(os.listdir(folder)):
    if not meta_name.endswith(".meta.json"):
        continue
    meta = json.load(open(os.path.join(folder, meta_name)))
    if meta.get("description") not in descriptions:
        continue
    report, tools, first, last = None, 0, None, None
    for line in open(os.path.join(folder, meta_name.replace(".meta.json", ".jsonl")), errors="replace"):
        try:
            record = json.loads(line)
        except ValueError:
            continue
        stamp = record.get("timestamp")
        first, last = first or stamp, stamp or last
        message = record.get("message") or {}
        if message.get("role") == "assistant" and isinstance(message.get("content"), list):
            for content in message["content"]:
                if content.get("type") == "tool_use":
                    tools += 1
                    if content.get("name") == "SubagentHandback":
                        value = content.get("input") or {}
                        report = value.get("message") if isinstance(value, dict) else value
    name = re.sub(r"[^a-z0-9]+", "_", meta["description"].lower()).strip("_") + ".md"
    open(os.path.join(out, name), "w").write(report or "")
    print(f"{name}: {len(report or '')} chars, {tools} tool uses, {first} .. {last}")

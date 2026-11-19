"""Write the final report (and print the usage numbers) of one Agent call of a session transcript, found by its
description.
usage: extract_agent_report.py <transcript.jsonl> <description> <out.md>"""
import json
import sys

src, description, out = sys.argv[1:4]
records = []
for line in open(src, errors="replace"):
    try:
        records.append(json.loads(line))
    except ValueError:
        pass

ids = set()
for r in records:
    msg = r.get("message") or {}
    if msg.get("role") == "assistant" and isinstance(msg.get("content"), list):
        for c in msg["content"]:
            if c.get("type") == "tool_use" and c.get("name") == "Agent" \
                    and (c.get("input") or {}).get("description") == description:
                ids.add(c.get("id"))

report, usage = "", {}
for r in records:
    msg = r.get("message") or {}
    if msg.get("role") == "user" and isinstance(msg.get("content"), list):
        for c in msg["content"]:
            if c.get("type") == "tool_result" and c.get("tool_use_id") in ids:
                body = c.get("content")
                if isinstance(body, str):
                    report = body
                else:
                    report = "\n".join(x.get("text", "") for x in body or [] if isinstance(x, dict))
                result = r.get("toolUseResult")
                if isinstance(result, dict):
                    usage = {k: result[k] for k in ("totalTokens", "totalToolUseCount", "totalDurationMs", "status")
                             if k in result}
print("tool_use ids:", ids, "usage:", usage, "report chars:", len(report))
open(out, "w").write(report)

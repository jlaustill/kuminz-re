"""Write the text of the transcript record that carries a background agent's final report (a task notification or a
handback), found by the agent's tool_use id and a phrase the report must contain.
usage: find_agent_notification.py <transcript.jsonl> <tool_use_id> <phrase> <out.md>"""
import json
import sys

src, tool_use_id, phrase, out = sys.argv[1:5]


def texts(content):
    if isinstance(content, str):
        yield content
    elif isinstance(content, list):
        for c in content:
            if isinstance(c, dict):
                if isinstance(c.get("text"), str):
                    yield c["text"]
                if "content" in c:
                    yield from texts(c["content"])


found = []
for number, line in enumerate(open(src, errors="replace"), 1):
    try:
        r = json.loads(line)
    except ValueError:
        continue
    msg = r.get("message") or {}
    if msg.get("role") != "user":
        continue
    for text in texts(msg.get("content")):
        if phrase in text and (tool_use_id in text or "task-notification" in text or "handback" in text.lower()):
            found.append((number, r.get("timestamp"), text))
for number, timestamp, text in found:
    print(f"line {number} {timestamp} chars {len(text)}")
if found:
    open(out, "w").write(found[-1][2])

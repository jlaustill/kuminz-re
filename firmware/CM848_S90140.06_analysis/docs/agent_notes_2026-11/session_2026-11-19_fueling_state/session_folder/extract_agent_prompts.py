"""Write every Agent prompt of the session transcript once (exact text) to agent_prompts.jsonl.
usage: extract_agent_prompts.py <transcript.jsonl> <out.jsonl>"""
import json
import sys

src, out = sys.argv[1:3]
seen, rows = set(), []
for line in open(src, errors="replace"):
    try:
        r = json.loads(line)
    except ValueError:
        continue
    msg = r.get("message") or {}
    if msg.get("role") != "assistant" or not isinstance(msg.get("content"), list):
        continue
    for c in msg["content"]:
        if c.get("type") == "tool_use" and c.get("name") == "Agent":
            i = c.get("input") or {}
            key = (i.get("description"), i.get("prompt"))
            if key in seen:
                continue
            seen.add(key)
            rows.append({"timestamp": r.get("timestamp"), "description": i.get("description"),
                         "subagent_type": i.get("subagent_type"), "model": i.get("model"), "prompt": i.get("prompt")})
text = "".join(json.dumps(x) + "\n" for x in rows)
open(out, "w").write(text)
print(len(rows), "agent prompts written")

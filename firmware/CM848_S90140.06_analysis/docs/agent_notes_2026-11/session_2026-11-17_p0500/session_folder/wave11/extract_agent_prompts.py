"""Append the Agent tool prompts of this session that are not yet in agent_prompts.jsonl to it, and regenerate
agent_prompts.md from the JSONL (numbered sections, prompt in a fenced block).
Usage: extract_agent_prompts.py <session transcript.jsonl> <agent_prompts.jsonl> <agent_prompts.md>"""
import json
import sys

transcript, prompts_jsonl, prompts_md = sys.argv[1:4]
known = [json.loads(l) for l in open(prompts_jsonl) if l.strip()]
seen = {(k["timestamp"], k["description"]) for k in known}
new = []
for line in open(transcript):
    try:
        entry = json.loads(line)
    except json.JSONDecodeError:
        continue
    message = entry.get("message") or {}
    if entry.get("type") != "assistant" or not isinstance(message.get("content"), list):
        continue
    for block in message["content"]:
        if block.get("type") == "tool_use" and block.get("name") == "Agent":
            data = block.get("input", {})
            row = {"timestamp": entry.get("timestamp"), "description": data.get("description"),
                   "subagent_type": data.get("subagent_type"), "model": data.get("model"),
                   "background": data.get("run_in_background"), "prompt": data.get("prompt")}
            if (row["timestamp"], row["description"]) not in seen:
                new.append(row)
                seen.add((row["timestamp"], row["description"]))
rows = known + new
with open(prompts_jsonl, "w") as f:
    for r in rows:
        f.write(json.dumps(r) + "\n")
header = open(prompts_md).read().split("\n## ")[0].rstrip() + "\n"
parts = [header]
for i, r in enumerate(rows, 1):
    parts.append(f"\n## {i}. {r['description']} ({r['timestamp']}, {r['subagent_type']}, {r['model']})\n\n```\n{r['prompt']}\n```\n")
open(prompts_md, "w").write("".join(parts))
print(f"{len(known)} known, {len(new)} added: " + "; ".join(r["description"] for r in new))

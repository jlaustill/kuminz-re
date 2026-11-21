"""Extract each wave 15 agent's final report (its SubagentHandback text, else its last assistant text) from the agent
transcripts into one markdown file, with the prompt and the token use.
usage: extract_reports_W15.py <out.md> <bin>=<transcript.jsonl>..."""
import json
import sys

out = sys.argv[1]
parts = ["# Wave 15 agent prompts and reports\n"]
for arg in sys.argv[2:]:
    k, path = arg.split("=", 1)
    prompt, report, last_text = "", "", ""
    for line in open(path, errors="replace"):
        try:
            event = json.loads(line)
        except json.JSONDecodeError:
            continue
        message = event.get("message") or {}
        role = message.get("role") or event.get("type")
        content = message.get("content")
        if role == "user" and not prompt:
            if isinstance(content, str):
                prompt = content
            elif isinstance(content, list):
                prompt = "\n".join(c.get("text", "") for c in content if isinstance(c, dict) and c.get("type") == "text")
        if role == "assistant" and isinstance(content, list):
            for c in content:
                if not isinstance(c, dict):
                    continue
                if c.get("type") == "tool_use" and c.get("name") == "SubagentHandback":
                    inp = c.get("input") or {}
                    report = inp.get("report") or inp.get("message") or inp.get("text") or json.dumps(inp)
                if c.get("type") == "text" and c.get("text", "").strip():
                    last_text = c["text"]
    parts.append(f"\n## Bin {k}\n\n### Prompt\n\n{prompt.strip()}\n\n### Report\n\n{(report or last_text).strip()}\n")
open(out, "w").write("\n".join(parts))
print(f"wrote {out}: {sum(len(p) for p in parts)} chars")

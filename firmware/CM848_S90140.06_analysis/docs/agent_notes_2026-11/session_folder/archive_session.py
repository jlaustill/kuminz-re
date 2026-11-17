"""Keep everything from the session's scratch folder: plain files mirrored, the big .cpp snapshots and build logs
in one tar.xz, and every Agent prompt from the session transcript.
usage: archive_session.py <scratch dir> <notes dir> <session transcript.jsonl>"""
import json
import os
import re
import shutil
import subprocess
import sys

src, notes, transcript = sys.argv[1:4]
mirror = os.path.join(notes, "session_folder")
large, copied, skipped = [], 0, 0
PRIVATE = re.compile(r"jlaustill@|gmail\.com|ghp_|github_pat_|sk-ant-", re.I)
for root, dirs, files in os.walk(src):
    dirs[:] = sorted(d for d in dirs if d != "__pycache__")
    for f in sorted(files):
        path = os.path.join(root, f)
        rel = os.path.relpath(path, src)
        if f.endswith(".pyc"):
            skipped += 1
            continue
        if f.endswith(".log") or (f.endswith(".cpp") and os.path.getsize(path) > 1_000_000):
            large.append(rel)
            continue
        if rel != "archive_session.py" and PRIVATE.search(open(path, errors="replace").read()):
            sys.exit(f"private-looking text in {rel}: stop")
        os.makedirs(os.path.dirname(os.path.join(mirror, rel)), exist_ok=True)
        shutil.copy2(path, os.path.join(mirror, rel))
        copied += 1
print(f"mirrored {copied} files ({skipped} .pyc skipped); {len(large)} large files to the archive")
archive = os.path.join(notes, "session_folder_large_files.tar.xz")
with open(os.path.join(notes, "session_folder_large_files.txt"), "w") as f:
    f.write("\n".join(sorted(large)) + "\n")
tar = subprocess.Popen(["tar", "--sort=name", "-C", src, "-cf", "-", *sorted(large)], stdout=subprocess.PIPE)
with open(archive, "wb") as out:
    subprocess.run(["xz", "-9", "--lzma2=preset=9,dict=128MiB", "-T1", "-c"], stdin=tar.stdout, stdout=out, check=True)
tar.wait()
print(f"{archive}: {os.path.getsize(archive) / 1e6:.1f} MB")

prompts = []
for line in open(transcript, errors="replace"):
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
            prompts.append({"timestamp": r.get("timestamp"), "description": i.get("description"),
                            "subagent_type": i.get("subagent_type"), "model": i.get("model"),
                            "background": i.get("run_in_background"), "prompt": i.get("prompt")})
text = "".join(json.dumps(p) + "\n" for p in prompts)
if PRIVATE.search(text):
    sys.exit("private-looking text in the prompts: stop")
open(os.path.join(notes, "agent_prompts.jsonl"), "w").write(text)
md = ["# Agent prompts (PR #50 session, 2026-11-16/17)", "",
      f"All {len(prompts)} subagents this session started, in order, with the exact prompt each was given. "
      "Most prompts point at a brief in `rename_waves/briefs/` or `table_campaign/` (paths name the session's scratch "
      "folder, kept as `session_folder/`).", ""]
for n, p in enumerate(prompts, 1):
    md += [f"## {n}. {p['description']} ({p['timestamp']}, {p['subagent_type'] or 'default'}, {p['model'] or 'inherited model'})",
           "", "```", (p["prompt"] or "").rstrip(), "```", ""]
open(os.path.join(notes, "agent_prompts.md"), "w").write("\n".join(md))
print(f"{len(prompts)} agent prompts written")

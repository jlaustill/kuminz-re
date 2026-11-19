"""Keep everything from the 2026-11-19 fueling state session (todo 045).
Plain files go to <notes>/session_folder/, the large ones (.cpp snapshots, build logs, the full disassembly, the
baseline headers) into one tar.xz next to it. The session transcript goes to a private archive outside the repo
(mode 600) because it holds the session's private context, together with the session folder next to it (the
eleven read-only agents' own transcripts and the saved tool results). The agents' exact prompts and their reports
are in agent_prompts.jsonl / agent_prompts_and_reports.md.
usage: archive_fueling_state_session.py <scratch dir> <notes dir> <transcript.jsonl> <private archive.tar.xz>"""
import os
import re
import shutil
import subprocess
import sys

src, notes, transcript, private = sys.argv[1:5]
mirror = os.path.join(notes, "session_folder")
def private_pattern():
    """The owner's address and handle from the local git config (never written into this public file) plus
    generic token prefixes."""
    email = subprocess.run(["git", "config", "user.email"], capture_output=True, text=True).stdout.strip()
    parts = [re.escape(email), re.escape(email.split("@")[0] + "@")] if "@" in email else []
    return re.compile("|".join(parts + ["ghp_", "github_pat_", "sk-ant-"]), re.I)


PRIVATE = private_pattern()
large, copied = [], 0
for root, dirs, files in os.walk(src):
    dirs[:] = sorted(d for d in dirs if d != "__pycache__")
    for f in sorted(files):
        path = os.path.join(root, f)
        rel = os.path.relpath(path, src)
        if f.endswith((".pyc",)):
            continue
        if f.endswith((".log", ".cpp", ".dis", ".hpp")) or os.path.getsize(path) > 1_000_000:
            large.append(rel)
            continue
        if f not in (os.path.basename(__file__), "scan_private.py") and PRIVATE.search(open(path, errors="replace").read()):
            sys.exit(f"private-looking text in {rel}: stop")
        os.makedirs(os.path.dirname(os.path.join(mirror, rel)), exist_ok=True)
        shutil.copy2(path, os.path.join(mirror, rel))
        copied += 1
for rel in large:
    if PRIVATE.search(open(os.path.join(src, rel), errors="replace").read()):
        sys.exit(f"private-looking text in {rel}: stop")
print(f"mirrored {copied} files; {len(large)} large files to the archive")
archive = os.path.join(notes, "session_folder_large_files.tar.xz")
with open(os.path.join(notes, "session_folder_large_files.txt"), "w") as f:
    f.write("\n".join(sorted(large)) + "\n")
tar = subprocess.Popen(["tar", "--sort=name", "-C", src, "-cf", "-", *sorted(large)], stdout=subprocess.PIPE)
with open(archive, "wb") as out:
    subprocess.run(["xz", "-9", "--lzma2=preset=9,dict=128MiB", "-T1", "-c"], stdin=tar.stdout, stdout=out, check=True)
tar.wait()
print(f"{archive}: {os.path.getsize(archive) / 1e6:.2f} MB")

session_folder = transcript[:-len(".jsonl")] if transcript.endswith(".jsonl") else ""
members = [os.path.basename(transcript)] + ([os.path.basename(session_folder)] if os.path.isdir(session_folder) else [])
tar = subprocess.Popen(["tar", "--sort=name", "-C", os.path.dirname(transcript), "-cf", "-", *members],
                       stdout=subprocess.PIPE)
fd = os.open(private, os.O_WRONLY | os.O_CREAT | os.O_TRUNC, 0o600)
with os.fdopen(fd, "wb") as out:
    subprocess.run(["xz", "-9", "-T1", "-c"], stdin=tar.stdout, stdout=out, check=True)
tar.wait()
os.chmod(private, 0o600)
print(f"{private}: {os.path.getsize(private) / 1e6:.2f} MB, {len(members)} members (mode 600, outside the repo)")

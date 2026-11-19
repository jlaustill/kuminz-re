"""Keep everything from the 2026-11-19 fueling state session (todo 045).
Plain files go to <notes>/session_folder/, the large ones (.cpp snapshots, build logs, the full disassembly, the
baseline headers) into one tar.xz next to it. The session transcript goes to a private archive outside the repo
(mode 600) because it holds the session's private context. The session started no subagents, so there are no
agent prompts to keep.
usage: archive_fueling_state_session.py <scratch dir> <notes dir> <transcript.jsonl> <private archive.tar.xz>"""
import os
import re
import shutil
import subprocess
import sys

src, notes, transcript, private = sys.argv[1:5]
mirror = os.path.join(notes, "session_folder")
PRIVATE = re.compile(r"jlaustill@|gmail\.com|ghp_|github_pat_|sk-ant-", re.I)
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
        if f != os.path.basename(__file__) and PRIVATE.search(open(path, errors="replace").read()):
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

tar = subprocess.Popen(["tar", "-C", os.path.dirname(transcript), "-cf", "-", os.path.basename(transcript)],
                       stdout=subprocess.PIPE)
fd = os.open(private, os.O_WRONLY | os.O_CREAT | os.O_TRUNC, 0o600)
with os.fdopen(fd, "wb") as out:
    subprocess.run(["xz", "-9", "-T1", "-c"], stdin=tar.stdout, stdout=out, check=True)
tar.wait()
os.chmod(private, 0o600)
print(f"{private}: {os.path.getsize(private) / 1e6:.2f} MB (mode 600, outside the repo)")

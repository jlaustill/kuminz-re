"""Check that the session's tar.xz restores every large file byte-identically.
usage: check_archive_restore.py <scratch dir> <notes dir>"""
import filecmp
import os
import subprocess
import sys
import tempfile

src, notes = sys.argv[1:3]
names = [n for n in open(os.path.join(notes, "session_folder_large_files.txt")).read().split("\n") if n]
with tempfile.TemporaryDirectory() as out:
    subprocess.run(["tar", "-xJf", os.path.join(notes, "session_folder_large_files.tar.xz"), "-C", out], check=True)
    bad = [n for n in names if not filecmp.cmp(os.path.join(out, n), os.path.join(src, n), shallow=False)]
print(f"{len(names)} files restored, {len(bad)} differ" + (f": {bad}" if bad else ""))
sys.exit(1 if bad else 0)

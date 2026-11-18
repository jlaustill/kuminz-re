"""Check the large-files archive: every listed file is in it, byte-identical to the scratch folder's copy.
usage: verify_archive.py <scratch dir> <notes dir>"""
import hashlib
import os
import sys
import tarfile

src, notes = sys.argv[1:3]
listed = [l for l in open(os.path.join(notes, "session_folder_large_files.txt")).read().split("\n") if l]
total, bad = 0, []
with tarfile.open(os.path.join(notes, "session_folder_large_files.tar.xz"), "r:xz") as t:
    members = {m.name: m for m in t.getmembers()}
    for rel in listed:
        m = members.get(rel)
        data = t.extractfile(m).read() if m else None
        orig = open(os.path.join(src, rel), "rb").read()
        total += len(orig)
        if data is None or hashlib.sha256(data).digest() != hashlib.sha256(orig).digest():
            bad.append(rel)
print(f"{len(listed)} listed, {len(members)} in the archive, {total / 1e6:.0f} MB checked, mismatches: {len(bad)} {bad[:3]}")

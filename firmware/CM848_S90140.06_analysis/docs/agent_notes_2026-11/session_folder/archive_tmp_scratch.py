"""Keep the agents' scratch they wrote under /tmp (outside the job folder): scan for private data, then one tar.xz in the
notes plus a file list. Also scan the job folder's large files (the other archive's sources) the same way.
usage: archive_tmp_scratch.py <notes dir> <job scratch dir>"""
import os
import re
import subprocess
import sys

notes, job = sys.argv[1:3]
ITEMS = ["bin01_compact.txt", "bin01_work", "bin05", "bin12", "bin12_dump.txt", "boot_calls_w7.json", "boot_dis_w7.txt",
         "cpp_8a72628_w7.cpp", "fn_lines_07.txt", "g3_build_result.py", "g3_names.txt", "g3_scan_uses.py",
         "gv_134d735_w7.csv", "gv_8a72628_w7.csv", "gv_pre_w4_w7.csv", "scratch_w8", "tables_02a", "w3_inj",
         "w4inj_disasm1.txt", "w7"]
PRIVATE = re.compile(rb"jlaustill@|gmail\.com|ghp_[A-Za-z0-9]{20}|github_pat_|sk-ant-|BEGIN (RSA|OPENSSH) PRIVATE")
files = []
for item in ITEMS:
    path = os.path.join("/tmp", item)
    if os.path.isfile(path):
        files.append(item)
    for root, dirs, fs in os.walk(path):
        dirs[:] = sorted(d for d in dirs if d != "__pycache__")
        files += [os.path.relpath(os.path.join(root, f), "/tmp") for f in sorted(fs) if not f.endswith(".pyc")]
hits = [f for f in files if PRIVATE.search(open(os.path.join("/tmp", f), "rb").read())]
large = [l for l in open(os.path.join(notes, "session_folder_large_files.txt")).read().split("\n") if l]
hits += [f"(job) {f}" for f in large if PRIVATE.search(open(os.path.join(job, f), "rb").read())]
if hits:
    sys.exit(f"private-looking text: {hits[:5]}")
open(os.path.join(notes, "session_tmp_scratch_files.txt"), "w").write("\n".join(files) + "\n")
tar = subprocess.Popen(["tar", "--sort=name", "-C", "/tmp", "-cf", "-", *files], stdout=subprocess.PIPE)
out = os.path.join(notes, "session_tmp_scratch.tar.xz")
with open(out, "wb") as f:
    subprocess.run(["xz", "-9", "--lzma2=preset=9,dict=128MiB", "-T1", "-c"], stdin=tar.stdout, stdout=f, check=True)
tar.wait()
total = sum(os.path.getsize(os.path.join("/tmp", f)) for f in files)
print(f"{len(files)} files ({total / 1e6:.1f} MB) -> {out} {os.path.getsize(out) / 1e6:.1f} MB; private scan clean "
      f"(also the {len(large)} large files of the job folder)")

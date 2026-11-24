"""Round 74 sweep: this round's old names across the repo (all text files) and the memory directory, skipping the
session archive, generated snapshots and history notes; plus the tool side's key scrambling.
usage: sweep_r74.py <repo> <memory dir>"""
import os
import re
import sys

repo, mem = sys.argv[1], sys.argv[2]
NAMES = re.compile(r"cm848_validateWriteAuth|cm848_descrambleAuthToken|j1708_multipacket_msg_t|count_106|"
                   r"insite_response_byte_offset|insite_request_byte_offset|CALIBRATION_BANK\b|CALIBRATION_STATE_SIGNATURE")
SKIP_DIRS = {".git", "agent_notes_2026-11", "node_modules", "build", "context_tier1", "decompiled"}
SKIP_FILES = re.compile(r"\.ghidra\.cpp$|\.hpp$|classification\.csv$|cross_firmware_.*\.csv$|"
                        r"parameter_id_lookup_table\.csv$|local_variables_actual\.csv$|bank1\.txt$|\.bin$|\.xz$|\.rep$")
HISTORY = re.compile(r"was |\(was|removed in PR #53 round 74|its low byte|was a field of the misapplied")
TOOL = re.compile(r"0x46,\s*0x58,\s*0x9a|46 58 9a|0x23,\s*0x24,\s*0xc0|scrambl", re.I)


def walk(root, skip_dirs):
    for d, dirs, files in os.walk(root):
        dirs[:] = [x for x in dirs if x not in skip_dirs and not x.startswith("worklist_")]
        for f in files:
            if not SKIP_FILES.search(f):
                yield os.path.join(d, f)


hits = 0
for p in walk(repo, SKIP_DIRS):
    try:
        for n, line in enumerate(open(p, errors="strict"), 1):
            if NAMES.search(line) and not HISTORY.search(line):
                print(f"{os.path.relpath(p, repo)}:{n}: {line.strip()[:110]}")
                hits += 1
    except (UnicodeDecodeError, OSError):
        continue
print("repo hits:", hits)
for p in walk(mem, set()):
    if NAMES.search(open(p, errors="replace").read()):
        print("memory:", os.path.basename(p))
for sub in ("clip-core", "kuminz-cli", "kuminz-ui"):
    for p in walk(os.path.join(repo, sub), SKIP_DIRS):
        if p.endswith((".cpp", ".h", ".hpp")):
            for n, line in enumerate(open(p, errors="replace"), 1):
                if TOOL.search(line):
                    print(f"tool: {os.path.relpath(p, repo)}:{n}: {line.strip()[:100]}")

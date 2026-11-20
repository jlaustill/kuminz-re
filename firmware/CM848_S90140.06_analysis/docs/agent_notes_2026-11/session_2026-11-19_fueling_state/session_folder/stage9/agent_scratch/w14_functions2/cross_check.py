"""Lists records of the other W14 result files at the addresses the functions2 plates depend on."""
import glob
import json
import os

STAGE9 = "/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage9"
WANT = {0x5c556, 0x5c582, 0x5c58e, 0x40aee6, 0x5c398, 0x3feb90, 0x5c2f4, 0x5c3ac, 0x40b1ee, 0x3fd5ee, 0x3fd5a0, 0x3fd59c,
        0x40a78a, 0x40a78e, 0x3fbd40, 0x40ada6, 0x40ada8, 0x5c348, 0x5c34a}
WANT |= set(range(0x40adca, 0x40add4, 2)) | set(range(0x40a630, 0x40a648, 2)) | set(range(0x40ad8a, 0x40add6, 2))
for path in sorted(glob.glob(os.path.join(STAGE9, "result_W14_*.jsonl"))):
    if path.endswith("functions2.jsonl"):
        continue
    for line in open(path):
        if not line.strip():
            continue
        r = json.loads(line)
        try:
            a = int(r.get("address", "0"), 16)
        except ValueError:
            continue
        if a in WANT:
            note = (r.get("evidence") or "")[:260]
            print(f"{os.path.basename(path)[11:-6]} 0x{a:x} {r.get('kind')} {r.get('verdict')} {r.get('old')} -> {r.get('new')} | {note}")

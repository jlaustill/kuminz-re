import glob
import json

base = "/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage8"
want = ("0x0040a16", "0x0040a17", "0x0040a18", "0x0040a19", "0x0040a1a", "0x0040a1b", "0x0040a1c", "0x0040a2",
        "0x0040a41", "0x0040a61", "0x0040a67", "0x0040a68", "0x004062d", "0x0040c27", "0x0040c28", "0x0040b79",
        "0x0040b7", "0x0040b80", "0x003fdfb", "0x003feb", "0x0040ad8", "0x0040911", "0x0040912", "0x0040b9e",
        "0x00408f9", "0x0040a3", "0x00408720")
n = 0
for path in sorted(glob.glob(base + "/result_W13_bin[1-5].jsonl")):
    for line in open(path):
        if not line.strip():
            continue
        r = json.loads(line)
        a = r.get("address", "")
        n += 1
        if any(a.lower().startswith(w) for w in want):
            print(path[-11:-6], a, r.get("verdict"), r.get("old"), "->", r.get("new"))
print("rows read from other bins:", n)

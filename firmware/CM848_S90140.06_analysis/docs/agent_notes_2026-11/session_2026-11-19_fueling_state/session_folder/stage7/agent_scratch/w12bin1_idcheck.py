import glob
import json
import re

OUT = '/home/linux/.claude/jobs/f6a06670/tmp/fueling_state/stage7/result_W12_bin1.jsonl'
FW = 'firmware/CM848_S90140.06_analysis/output'
E2M = 'e2m-analysis/CHR/CHR_CC_11.45.01.07.e2m'

rows = [json.loads(l) for l in open(OUT)]
new_names = {r['new'] for r in rows}

corpus = ""
for path in glob.glob(FW + '/*.csv') + [FW + '/cm848_rom.ghidra.cpp', FW + '/firmware_globals.hpp', FW + '/firmware_types.hpp',
                                        FW + '/firmware_functions.hpp']:
    corpus += open(path, errors='replace').read() + "\n"
tokens = set(re.findall(r"[A-Za-z_][A-Za-z0-9_]*", corpus))

e2m_names = set()
for line in open(E2M, errors='replace'):
    first = line.split(',', 1)[0]
    if re.fullmatch(r"[A-Za-z0-9_]+", first):
        e2m_names.add(first)

TOOLS = {"xref_addr"}
unknown = {}
for r in rows:
    for key in ('evidence', 'comment'):
        text = r[key]
        for ident in re.findall(r"[A-Za-z][A-Za-z0-9]*(?:_[A-Za-z0-9]+)+", text):
            for part in ident.split('.'):
                pass
            if ident in new_names or ident in tokens or ident in e2m_names or ident in TOOLS:
                continue
            unknown.setdefault(ident, []).append((r['address'], key))
for ident, where in sorted(unknown.items()):
    print(ident, where[:3])
print("unknown identifiers:", len(unknown))

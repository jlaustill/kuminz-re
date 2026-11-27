"""Round 96: the Q5 part of overrides_r96.json (merged into the file; other keys stay).
- cal_exempt for the boot kernel's own rows in 0x3fdba4-0x3fdc38: the range lies inside the EEPROM mirror, but the
  kernel writes its CMF erase / program parameters there before the application loads the EEPROM image over it, and
  firmware/CLAUDE.md's _cal rule already counts boot-named rows at addresses the kernel shares as exceptions (the
  audit's MISSING list). The rows the application reads keep their _cal names (the judge named them so).
- drop + remove_globals for the 14 rows the judge marks 'DELETE THIS ROW': entries 1-7 of the two arrays the batch
  types (cmf_program_control_step_bits dword[8] at 0x3fdbde, cmf_program_step_pulse_limits word[8] at 0x3fdc1e); each
  old name maps to its element path for the refresh.
usage: make_overrides_r96_q5.py <batch_Q5.json> <overrides_r96.json>"""
import json
import re
import sys

batch = json.load(open(sys.argv[1]))
path = sys.argv[2]
try:
    o = json.load(open(path))
except (OSError, ValueError):
    o = {}
MIRROR = (0x3fd482, 0x3feec1)
vd = {str(x.get("address")).lower(): x for x in batch["verdict"]["verdicts"] if x.get("kind") == "global"}
exempt = drop = 0
for g in batch["proposal"]["globals"]:
    a = g["address"].lower()
    v = vd.get(a, {})
    name = (v.get("final_name") or g.get("proposed_name") or "").strip()
    key = f"global|CM848|{a}"
    if not name:
        m = re.search(r"entry (\d+)(?: \([^)]*\))? of ([a-z0-9_]+)", v.get("final_comment") or g.get("comment") or "")
        assert m, a
        o[key] = {"drop": True, "reason": f"entry {m.group(1)} of {m.group(2)} (the Q5 judge: DELETE THIS ROW)"}
        o.setdefault("remove_globals", {}).setdefault("CM848", {})[a] = f"{m.group(2)}[{m.group(1)}]"
        drop += 1
    elif not name.endswith("_cal") and MIRROR[0] <= int(a, 16) <= MIRROR[1]:
        o[key] = {"cal_exempt": True, "reason": "a boot kernel CMF parameter row: the kernel's own value before the application loads the EEPROM image over the range"}
        exempt += 1
json.dump(o, open(path, "w"), indent=1)
print("cal_exempt", exempt, "drop", drop)

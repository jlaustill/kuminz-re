"""Round 94: the leads apply's folder r94/leads/ (apply_r94.py copied, overrides_r94.json written) and the placeholder
function rows the apply needs. Overrides, each with its reason:
- remove_globals CM550: the 76 rows that start inside the leads' new types (leads_removals_r94.json: L2's
  fault_processing_enable_flags word[19], L3's 15 lookup records and the duty cycle / cylinder balance tables; each
  mapped to its field / element), and L2's 28 rows 0x8037b6-0x8037ee (can_priority_table_start /
  j1939_priority_pgn<N>: the L2 judge found no code reference and no e2m record; none renders);
- force_type for the record rows whose live type a typing pass gave (filled in from the dry run).
usage: make_leads_overrides_r94.py [force_type addresses...]"""
import json
import os
import shutil
import sys

W = "/home/linux/.claude/jobs/374b0424/tmp/w15/r94"
L = os.path.join(W, "leads")
os.makedirs(L, exist_ok=True)
shutil.copy(os.path.join(W, "apply_r94.py"), os.path.join(L, "apply_r94.py"))
removals = json.load(open(os.path.join(W, "leads_removals_r94.json")))
priority = {}
for name_line in open(os.path.join(W, "priority_rows_r94.txt")).read().split():
    pass
o = {"remove_globals": {"CM550": dict(removals["CM550"])}}
# the 28 priority rows: addresses 0x8037b6-0x8037ee that have a row (read from the repo by the caller list below)
PRIORITY = [0x8037b6] + list(range(0x8037b8, 0x8037e4, 2)) + list(range(0x8037e6, 0x8037f0, 2))
for a in PRIORITY:
    o["remove_globals"]["CM550"][f"0x{a:08x}"] = ""
for a in sys.argv[1:]:
    key = f"global|CM550|0x{int(a, 16):08x}"
    o[key] = {"force_type": True, "type": "table_lookup_2d_arguments_t",
              "reason": "L3's judge: a 22-byte cm550_tableLookup2D argument record (its dump pointers equal its initializer's constants; every ROM reference into it is the initializer, an input store or the base push); a typing pass had given its first word a width"}
o["global|CM848|0x0040aeea"] = {"force_type": True, "type": "i16",
                                "reason": "L4's judge: e2m 8A3D +2 SOI_Before_MST is a signed record (0.1171875 deg); the stores are sth only (0x29e40 / 0x29f04) and the copied value is an lha of main_injection_timing_copy"}
o["global|CM848|0x003fb500"] = {"force_type": True, "type": "dword",
                                "reason": "L4's judge: the only access is stw (the 32-bit value 5 at 0x3ecd4); 0x3fb502 has no row"}
json.dump(o, open(os.path.join(L, "overrides_r94.json"), "w"), indent=1)
print("overrides:", {k: (len(v["CM550"]) if k == "remove_globals" else 1) for k, v in o.items()})

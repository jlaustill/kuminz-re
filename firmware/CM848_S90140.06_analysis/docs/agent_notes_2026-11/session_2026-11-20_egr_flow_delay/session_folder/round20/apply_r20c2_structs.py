"""Round 20 stage C, part 2 rerun (structs only - the first run wrote the field rows to the map; the struct refresh
must not see field rows: it replaced reserved_bit_N in every struct):
- the read 'guess (not proven, so reserved)' bits and the e2m-named unread bits of algorithm_enable_flags_12_t / 18_t /
  41_t take their e2m records' names: the block alignment (RAM 0x3fd59a + e2m offset; word N at +2+2N) is now proven by
  the direct readers, the indexed fuel temperature channel (word 8 bits 0-3, word 26 bit 4) and calculateAlpha's
  pointer reads; unread bits are named as in algorithm_enable_flags_3_t, with 'no reader' kept in the comment;
- the mentions of those reserved bits in other comments are refreshed;
- rows for words 7, 8, 11 and 26 (no rows yet; no direct reader), with their e2m bits; words 8 / 26 note the indexed
  readers.
Appends the field rows (,new,old,field) to the map. usage: apply_r20c2.py <repo> <map.csv>"""
import collections
import os
import re
import sys

repo, map_path = os.path.abspath(sys.argv[1]), sys.argv[2]
out = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")
FIELDS = [  # (struct, bit, new name, read?)
    ("algorithm_enable_flags_12_t", 0, "idle_speed_save_enable", False),
    ("algorithm_enable_flags_12_t", 5, "reverse_electronic_smart_power_enable", False),
    ("algorithm_enable_flags_18_t", 2, "driver_reward_enable", False),
    ("algorithm_enable_flags_18_t", 3, "duty_cycle_monitor_enable", True),
    ("algorithm_enable_flags_18_t", 6, "smart_air_compressor_enable", False),
    ("algorithm_enable_flags_18_t", 11, "cruise_control_auto_resume_enable", False),
    ("algorithm_enable_flags_18_t", 13, "remote_throttle_transition_verification_enable", True),
    ("algorithm_enable_flags_18_t", 15, "engine_retarder_rate_limit_enable", False),
    ("algorithm_enable_flags_41_t", 11, "torque_normalization_enable", True),
    ("algorithm_enable_flags_41_t", 12, "throttle_100_cold_increment_enable", True),
    ("algorithm_enable_flags_41_t", 13, "air_fuel_control_cold_increment_enable", True),
]
GUESS = "guess (not proven, so reserved): "
sp = os.path.join(out, "structure_definitions.csv")
lines = open(sp).read().split("\n")
existing_fields = {l.split(",")[2] for l in lines if l and not l.startswith("#") and len(l.split(",")) > 3}
cpp_ids = set(re.findall(r"[A-Za-z_][A-Za-z0-9_]*", open(os.path.join(out, "cm848_rom.ghidra.cpp")).read()))
map_rows = []
for struct, bit, new, read in FIELDS:
    assert new not in existing_fields and new not in cpp_ids, new
    old = f"reserved_bit_{bit}"
    prefix = f"{struct},,{old},bitfield:1@{bit},"
    k = [i for i, l in enumerate(lines) if l.startswith(prefix)]
    assert len(k) == 1, (struct, bit)
    line = lines[k[0]]
    m = re.match(re.escape(f"{struct},,{old},bitfield:1@{bit},") + r'(\d+),"(.*)",(.*)$', line)
    assert m, line
    size, comment, tail = m.groups()
    if read:
        assert comment.startswith(GUESS), comment
        comment = (comment[len(GUESS):] + f" (was {old}: a guess until PR #53 round 20 proved the e2m 106B block "
                   "alignment)")
    else:
        assert "No reader" in comment, comment
        comment += f" (was {old}; named from its e2m record in PR #53 round 20, as in algorithm_enable_flags_3_t)"
    assert '"' not in comment
    lines[k[0]] = f'{struct},,{new},bitfield:1@{bit},{size},"{comment}",{tail}'
open(sp, "w").write("\n".join(lines))

print(len(FIELDS), "fields (structs only; the map rows were written by the first run)")

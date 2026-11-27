"""Round 74 stage A2 (from stage A's CM550 build): with the struct gone the decompiler shows the code's real widths where the
struct's byte arrays had split them - each confirmed in the m68k code:
- 0x80ddce is a dword (move.l d0,(0x80ddce).l at 0x1ddaa - the buffer pointer init stores 0x00808cff): it was the four
  byte elements reserved_04[4..7];
- 0x80de50 is a word (move.w #1,(0x80de50).l at 0x30704): reserved_126[0xc] / [0xd];
- 0x80de6e (test_variable_used_to_snapshot_the_system_interface_variable_s_0_120) is a word (move.w 0x80d346 -> 0x80de6e
  at 0x30b82): reserved_166[2] / [3];
- 0x80de72 (flags_of_final_timing_increment_states_0_ff) is a word (move.w (a2) at 0x30bea): reserved_166[6] / [7];
- the source of that copy, 0x80d346 fuel_timing_advance_value, and 0x80d34a timing_control_status_flags (clr.w /
  move.w #1 / move.w 0x80d34a -> 0x80d346) were 'undefined' (one byte) rows read as words - they already rendered with a
  '_' prefix elsewhere.
Idempotent; keeps line endings.  usage: apply_r74a2.py <repo> <pairs.json>"""
import json
import os
import sys

repo, pairs_path = os.path.abspath(sys.argv[1]), sys.argv[2]
G5 = os.path.join(repo, "firmware/CM550_J90350.00_analysis/output/global_variables.csv")
R = "PR #53 round 74"
s = open(G5, newline="").read()
eol = "\r\n" if "\r\n" in s else "\n"
lines = s.replace("\r\n", "\n").split("\n")
RETYPE = {0x80ddce: "dword", 0x80de50: "word", 0x80de6e: "word", 0x80d346: "word", 0x80d34a: "word", 0x80de72: "word"}
WHY = {0x80ddce: "move.l at 0x1ddaa", 0x80de50: "move.w #1 at 0x30704", 0x80de6e: "move.w from 0x80d346 at 0x30b82",
       0x80d346: "move.w at 0x12492 / 0x30b82 / 0x1c79e / 0x30bde", 0x80d34a: "clr.w at 0x17d24 / move.w #1 at 0x1c798",
       0x80de72: "move.w (a2) at 0x30bea - the copy of timing_control_status_flags"}
DROP = {0x80ddcf, 0x80ddd0, 0x80ddd1, 0x80de51, 0x80de6f, 0x80de73}
out = []
for l in lines:
    if l.startswith("0x"):
        parts = l.split(",", 3)
        a = int(parts[0], 16)
        if a in DROP:
            continue
        if a in RETYPE and parts[2] != RETYPE[a]:
            comment = parts[3] if len(parts) > 3 else ""
            note = f"typed {RETYPE[a]} ({WHY[a]}; was {parts[2] or 'untyped'}; {R} stage A2)"
            l = f"{parts[0]},{parts[1]},{RETYPE[a]},{(comment + ' | ') if comment else ''}{note}"
    out.append(l)
open(G5, "w", newline="").write("\n".join(out).replace("\n", eol))
pairs = json.load(open(pairs_path))
fix = {"BYTE_0080ddce": "DWORD_0080ddce", "BYTE_0080de50": "WORD_0080de50"}
pairs = [[old, fix.get(new, new)] for old, new in pairs]
json.dump(pairs, open(pairs_path, "w"), indent=0)
print("round 74 stage A2 applied")

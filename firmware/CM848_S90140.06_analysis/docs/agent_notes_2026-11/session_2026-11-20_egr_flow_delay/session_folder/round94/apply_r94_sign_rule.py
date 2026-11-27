"""Round 94 (CM550): one sign rule for the rows typed in round 93 - the code's semantic uses decide, Calterm's flag
only when the code shows none. Round 93's pass 2 had followed Calterm alone. sign_rule_r94.py listed the rows whose
casts disagree with their type; cast_contexts_r94.py showed each cast's line, and only casts in a compare, a
'< 0' test or a widening that feeds arithmetic count as evidence. Casts that only pack a byte into a message
('(char)((ushort)x >> 8)'), build a fixed-point value ('(uint)(ushort)x << 0x10') or truncate an addition to a byte
say nothing about the sign, so those rows keep their Calterm sign.
Idempotent. usage: apply_r94_sign_rule.py <repo>"""
import os
import sys

repo = os.path.abspath(sys.argv[1])
R = "PR #53 round 94"
G = os.path.join(repo, "firmware/CM550_J90350.00_analysis/output/global_variables.csv")
CHANGES = {  # address: (from, to, evidence)
    0x008058ce: ("word", "i16", "the code sign-extends it for its index arithmetic ((short)index * 0x24 / * 0x2e, (int)(short)index == ...)"),
    0x0080800a: ("word", "i16", "signed compares ((short)value < (short)minimum_fueling_value_0_100) at two places"),
    0x0080815e: ("word", "i16", "signed widening into arithmetic ((int)(short)value - ...) at two places"),
    0x0080bc74: ("word", "i16", "signed widening into a multiply ((int)(short)value * ...)"),
    0x0080da38: ("word", "i16", "sign tests ((short)value < 0) at two places"),
    0x0080da62: ("word", "i16", "sign tests ((short)value < 0) at three places"),
    0x0080dee4: ("word", "i16", "a signed compare ((int)(short)value < ...)"),
    0x00808256: ("i16", "word", "an unsigned compare ((ushort)value < ...)"),
    0x0080d62c: ("i16", "word", "unsigned compares ((ushort)value < ...)"),
    0x00807ef0: ("i16", "word", "an unsigned compare and unsigned arithmetic ((ushort)value < ..., (uint)(ushort)value - ...)"),
    0x00807ef2: ("i16", "word", "unsigned compare / multiply ((ushort)value ..., (uint)(ushort)value * ...)"),
    0x0080a26e: ("i16", "word", "an unsigned compare (... < (ushort)value)"),
}
lines = open(G, newline="").read().split("\n")
done = 0
for i, line in enumerate(lines):
    if not line.startswith("0x"):
        continue
    a = int(line.split(",")[0], 16)
    if a not in CHANGES:
        continue
    parts = line.split(",", 3)
    old, new, why = CHANGES[a]
    if parts[2] == new:
        continue
    assert parts[2] == old, (hex(a), parts[2], old)
    comment = parts[3] if len(parts) > 3 else ""
    note = f"typed {new} by the code's own use: {why} ({R})"
    lines[i] = f"{parts[0]},{parts[1]},{new},{comment} | {note}" if comment else f"{parts[0]},{parts[1]},{new},{note}"
    done += 1
if done:
    open(G, "w", newline="").write("\n".join(lines))
print(done, "rows retyped")

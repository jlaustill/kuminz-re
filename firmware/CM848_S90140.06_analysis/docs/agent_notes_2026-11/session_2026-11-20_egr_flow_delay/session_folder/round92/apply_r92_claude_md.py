"""Round 92: one factual sentence in firmware/CLAUDE.md's bitfield bullet (line 371): the bullet says bitfield names
render on CM848's Ghidra 12.1; stage A proved the same on CM550 (Ghidra 12.2, the 68000 language). Idempotent.
usage: apply_r92_claude_md.py <repo>"""
import os
import sys

p = os.path.join(os.path.abspath(sys.argv[1]), "firmware/CLAUDE.md")
t = open(p, newline="").read()
old = ("CM848 is pinned to 12.1 (which has this fix); see the **Ghidra version pinning** section above for how each "
       "firmware's version is enforced.")
new = old + (" CM550's Ghidra 12.2 (the 68000 language) renders bitfield names the same way: its algorithm enable words "
             "(`algorithm_enable_flags_<n>_cal`, e2m 106B) are bitfield structs since PR #53 round 92, and no store rendered "
             "as a piece there because the dumped ROM never writes those words.")
if new not in t:
    assert t.count(old) == 1, t.count(old)
    open(p, "w", newline="").write(t.replace(old, new))
print("firmware/CLAUDE.md: the bitfield bullet names CM550")

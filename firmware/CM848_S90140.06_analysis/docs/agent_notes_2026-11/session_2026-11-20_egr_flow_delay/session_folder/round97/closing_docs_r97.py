"""Round 97 closing: task 046's round 97 entry with its leads (after round 96's leads, before '## Leads (not in this
PR)') and the todo.md line's round list. Refuses on a missing anchor. usage: closing_docs_r97.py <repo> <entry.md> <stage F sha>"""
import os
import sys

repo, entry_path, sha_f = os.path.abspath(sys.argv[1]), sys.argv[2], sys.argv[3]
entry = open(entry_path).read().replace("SHA_F", sha_f)
assert "SHA_" not in entry
p = os.path.join(repo, "work/tasks/046-cm848-egr-flow-estimate.md")
t = open(p, newline="").read()
anchor = "\n## Leads (not in this PR)\n"
assert t.count(anchor) == 1 and "## Done, round 97" not in t
t = t.replace(anchor, "\n" + entry.rstrip("\n") + "\n" + anchor, 1)
open(p, "w", newline="").write(t)
p = os.path.join(repo, "work/todo.md")
t = open(p, newline="").read()
old = ("seven CM550 functions that never decompiled, the serial EEPROM write queue, the import warning's cause - open: the "
       "task 046 leads (the abbreviation sweep is ready)")
new = ("seven CM550 functions that never decompiled, the serial EEPROM write queue, the import warning's cause; round 97: "
       "the abbreviation sweep (139 parameter / local / field names, 51 enum types, 162 function names, 11 struct types "
       "spelled out in both firmwares), then seven judged batches: CM550's governor families with the low speed governor "
       "gain set struct, the engine protection channel tables, the PGN 61184 request chain typed as "
       "can_standard_receive_descriptor_t*, the cylinder balance projections - open: the task 046 leads")
assert t.count(old) == 1
t = t.replace(old, new)
open(p, "w", newline="").write(t)
print("ok")

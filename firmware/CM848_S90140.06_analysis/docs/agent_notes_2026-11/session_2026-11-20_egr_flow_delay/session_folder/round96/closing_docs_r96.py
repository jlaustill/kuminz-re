"""Round 96 closing: task 046's round 96 entry (after round 95's leads, before '## Leads (not in this PR)') and the
todo.md line's round list. Refuses on a missing anchor. usage: closing_docs_r96.py <repo> <entry.md> <stage H sha>"""
import os
import sys

repo, entry_path, sha_h = os.path.abspath(sys.argv[1]), sys.argv[2], sys.argv[3]
entry = open(entry_path).read().replace("SHA_H", sha_h)
assert "SHA_" not in entry
p = os.path.join(repo, "work/tasks/046-cm848-egr-flow-estimate.md")
t = open(p, newline="").read()
anchor = "\n## Leads (not in this PR)\n"
assert t.count(anchor) == 1 and "## Done, round 96" not in t
t = t.replace(anchor, "\n" + entry.rstrip("\n") + "\n" + anchor, 1)
open(p, "w", newline="").write(t)
p = os.path.join(repo, "work/todo.md")
t = open(p, newline="").read()
old = "CM550's last 0x30000-0x34fff placeholders and every 1-D lookup record - open: the task 046 leads"
new = ("CM550's last 0x30000-0x34fff placeholders and every 1-D lookup record; round 96: the struct types spelled out, the "
       "boot kernel's CMF tables, the J1939 builders by PGN and CM550's request responders (five batches), seven CM550 "
       "functions that never decompiled, the serial EEPROM write queue, the import warning's cause - open: the task 046 "
       "leads (the abbreviation sweep is ready)")
assert t.count(old) == 1
t = t.replace(old, new)
open(p, "w", newline="").write(t)
print("ok")

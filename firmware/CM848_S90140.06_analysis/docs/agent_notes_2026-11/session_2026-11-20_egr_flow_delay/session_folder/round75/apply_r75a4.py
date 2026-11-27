"""Round 75 stage A4 (CM550): the two J1708 functions take the mc68k_ prefix - CM550's prefix for functions that access
MC68336 hardware registers (commit 16143a5c) - since both access the QSM SCI directly; and the schedule struct's comment
names the initializer by its new name. Idempotent; keeps line endings. usage: apply_r75a4.py <repo> <map.csv>"""
import os
import sys

repo, map5 = os.path.abspath(sys.argv[1]), sys.argv[2]
O5 = os.path.join(repo, "firmware/CM550_J90350.00_analysis/output")


def edit(p, old, new):
    s = open(p, newline="").read()
    if new in s:
        return
    assert s.count(old) == 1, (os.path.basename(p), old[:90], s.count(old))
    open(p, "w", newline="").write(s.replace(old, new))


F5, S5 = os.path.join(O5, "function_renames.csv"), os.path.join(O5, "structure_definitions.csv")
edit(F5, "0x00016d4e,cm550_startJ1708Transmission,", "0x00016d4e,mc68k_startJ1708Transmission,")
edit(F5, "0x00029130,cm550_initializeJ1708Datalink,", "0x00029130,mc68k_initializeJ1708Datalink,")
edit(S5, "(the initializer mc68k_FUN_00029130 sets next due = period + this)",
     "(the initializer mc68k_initializeJ1708Datalink sets next due = period + this)")
with open(map5, "w") as fh:
    fh.write("address,name,old_label,kind,dims\n"
             "0x00016d4e,mc68k_startJ1708Transmission,cm550_startJ1708Transmission,function,1\n"
             "0x00029130,mc68k_initializeJ1708Datalink,cm550_initializeJ1708Datalink,function,1\n")
print("round 75 stage A4 applied")

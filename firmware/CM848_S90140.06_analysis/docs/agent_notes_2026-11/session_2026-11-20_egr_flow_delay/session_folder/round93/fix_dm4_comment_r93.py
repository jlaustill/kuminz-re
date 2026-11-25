"""Round 93 (CM550): the j1939_pgn65229_tx_message row said the DM4 sender at 0x3258a was 'misnamed <old name>';
the function has its name now, so the refresh left 'misnamed <new name>'. Idempotent.
usage: fix_dm4_comment_r93.py <repo>"""
import os
import sys

p = os.path.join(os.path.abspath(sys.argv[1]), "firmware/CM550_J90350.00_analysis/output/global_variables.csv")
t = open(p, newline="").read()
old = "registers the DM4 sender (0x3258a, misnamed cm550_j1939HandlePgn65229Dm4FreezeFrame) for PGN 65229."
new = "registers the DM4 request handler cm550_j1939HandlePgn65229Dm4FreezeFrame (0x3258a) for PGN 65229."
if new not in t:
    assert t.count(old) == 1, t.count(old)
    open(p, "w", newline="").write(t.replace(old, new))
print("comment fixed")

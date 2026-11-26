"""Round 97 stage F post-refresh fix: refresh_other_csvs.py rewrote one history note that has no round tag - the 0x1ffd6
prototype's '(was cm550_j1939TorqueControlModeParser)' (batch R6 text) became '(was updateJ1939BroadcastEnableMask)'.
usage: post_refresh_r97f.py <repo>"""
import os
import sys

p = os.path.join(os.path.abspath(sys.argv[1]), "firmware/CM550_J90350.00_analysis/output/function_definitions.csv")
t = open(p, newline="").read()
old = "because the function is renamed (was updateJ1939BroadcastEnableMask). Return: clr.b d0 / moveq #4."
new = "because the function is renamed (was cm550_j1939TorqueControlModeParser). Return: clr.b d0 / moveq #4."
assert t.count(old) == 1
open(p, "w", newline="").write(t.replace(old, new))
print("restored the 0x1ffd6 history note")

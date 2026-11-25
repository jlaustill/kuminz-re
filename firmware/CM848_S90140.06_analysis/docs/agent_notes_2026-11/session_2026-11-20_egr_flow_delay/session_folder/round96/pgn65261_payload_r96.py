"""Round 96 stage C (CM848): the CCSS payload follows its siblings' names (j1939_pgn<N>_payload / j1939_pgn<N>_payload_t:
65251 / 65263 / 65249 / 65242 / 65259). The type stage C first spelled out as
j1939_cruise_control_vehicle_speed_setup_payload_t is j1939_pgn65261_payload_t, and its instance at 0x3fab0a, which
had no row and so rendered as Ghidra's default label j1939_ccss_tx_payload_t_003fab0a, is named j1939_pgn65261_payload.
Idempotent; keeps line endings. usage: pgn65261_payload_r96.py <repo>"""
import os
import re
import sys

repo = os.path.abspath(sys.argv[1])
OUT = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")
R = "PR #53 round 96"
OLD, NEW = "j1939_cruise_control_vehicle_speed_setup_payload_t", "j1939_pgn65261_payload_t"
for name in ("structure_definitions.csv", "global_variables.csv"):
    p = os.path.join(OUT, name)
    t = open(p, newline="").read()
    n = len(re.findall(rf"\b{OLD}\b", t))
    if n:
        open(p, "w", newline="").write(re.sub(rf"\b{OLD}\b", NEW, t))
    print(name, n)
p = os.path.join(OUT, "global_variables.csv")
t = open(p, newline="").read()
E = "\r\n" if "\r\n" in t else "\n"
lines = t.split(E)
if not any(l.startswith("0x003fab0a,") for l in lines):
    row = ("0x003fab0a,j1939_pgn65261_payload,j1939_pgn65261_payload_t,the CCSS (PGN 65261 Cruise Control / Vehicle Speed "
           "Setup) payload: 8 bytes - SPN 74 maximum vehicle speed limit / SPN 87 and 88 the cruise control high and low "
           "set limit speeds / five 0xff bytes - sent through j1939_pgn65261_tx_message (it had no row and rendered as the "
           f"default label j1939_ccss_tx_payload_t_003fab0a; {R})")
    i = next(i for i, l in enumerate(lines) if l.startswith("0x003fab12,"))
    lines.insert(i, row)
    open(p, "w", newline="").write(E.join(lines))
    print("instance row added")
m = os.path.join(os.path.dirname(os.path.abspath(__file__)), "map_r96c_types.csv")
s = open(m).read()
s = s.replace(f"0x00000000,{OLD},j1939_ccss_tx_payload_t,type,1", f"0x00000000,{NEW},j1939_ccss_tx_payload_t,type,1")
if "j1939_ccss_tx_payload_t_003fab0a" not in s:
    s = s.rstrip("\n") + "\n0x003fab0a,j1939_pgn65261_payload,j1939_ccss_tx_payload_t_003fab0a,symbol,1\n"
open(m, "w").write(s)
print(open(m).read())

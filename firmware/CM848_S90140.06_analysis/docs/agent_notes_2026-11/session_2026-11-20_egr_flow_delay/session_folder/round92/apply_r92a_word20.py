"""Round 92 stage A side row (CM550): algorithm enable flags word 20 (0x803cbc). It was in no workflow batch because
v64t6_s.e2m has no record at 106B +2A, but the stage A build still rendered _DAT_00803cbc & 0x200. One absolute
reference in the ROM (abs_refs_r92.py: move.w at 0x20fd8); the other unlisted words (10, 21, 24, 29, 30, 31, 34) have
none. A plain word: one proven bit use. Idempotent. usage: apply_r92a_word20.py <repo>"""
import os
import sys

repo = os.path.abspath(sys.argv[1])
G = os.path.join(repo, "firmware/CM550_J90350.00_analysis/output/global_variables.csv")
ROW = ("0x00803cbc,algorithm_enable_flags_20_cal,word,Algorithm enable flags word 20 (EEPROM 0x1b2; e2m 106B +2A): no record in "
       "v64t6_s.e2m. One reader: cm550_FUN_00020fac tests 0x200 (move.w at 0x20fd8) before it lets the J1939 client of slot 9 "
       "(j1939_received_wet_tank_pressure) write analog_sensor_raw_override_values[0]. Other ISB e2m files (63c5.e2m) put "
       "AD25OD 'BIT 9 OF 0-15. A/D CHANNEL 25 OVERRIDE' at 0x200 and ADSYFIOD 'OVERRIDE FOR FUEL PRESSURE FILTERED VALUE "
       "(INITIAL)' at 0x100 here. Plain word: one proven bit use (PR #53 round 92)")
lines = open(G, newline="").read().split("\n")
if not any(l.startswith("0x00803cbc,") for l in lines):
    after = [i for i, l in enumerate(lines) if l.startswith("0x") and int(l.split(",")[0], 16) < 0x803cbc]
    lines.insert(after[-1] + 1, ROW)
    open(G, "w", newline="").write("\n".join(lines))
    print("word 20 row added")
else:
    print("word 20 row present")

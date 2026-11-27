"""Round 74 stage C (the closing review's read of CM550's enums.csv): two more J90280.05-era enums model variables that
CM848's enums now type - remove the duplicates, as MEMORY_ACCESS_FLAG went in round 72. Both render nowhere and type
nothing. Idempotent; keeps line endings.
- CALIBRATION_BANK (0 FACTORY / 1 ACTIVE) for 0x80dc6c: that is ram_refresh_enable (e2m block 10C7) and RAM_REFRESH_STATE
  holds its 0 / 1. Its claim that the value picks bytes 0-3 or 4-7 of the parameter table entries at 0x35224 stays as a
  lead in the comment.
- CALIBRATION_STATE_SIGNATURE (0xEEEE / 0xEAEA / 0xEAEB / 0xEEEF) for 0x80dc90: that is run_location (e2m block 0010) and
  RUN_LOCATION holds 0xeeee / 0xeaea; no write of 0xeaeb or 0xeeef was found.
usage: apply_r74c.py <repo>"""
import os
import sys

P = os.path.join(os.path.abspath(sys.argv[1]), "firmware/CM550_J90350.00_analysis/output/enums.csv")
R = "PR #53 round 74"
s = open(P, newline="").read()
eol = "\r\n" if "\r\n" in s else "\n"
s = s.replace("\r\n", "\n")
for old, new in (
        ("# Calibration Bank Selector - calibration_bank_selector @ 0x0080dc6c\n"
         "# Controls which address field is read from parameter lookup table at 0x35224\n"
         "CALIBRATION_BANK,0,FACTORY,Factory calibration bank - reads bytes 0-3 of parameter entries (original OEM "
         "values),1\n"
         "CALIBRATION_BANK,1,ACTIVE,Active calibration bank - reads bytes 4-7 of parameter entries (tunable values),1\n",
         f"# (CALIBRATION_BANK - J90280.05's reading of 0x80dc6c as a factory / active calibration bank - removed in {R}: "
         "0x80dc6c is ram_refresh_enable (e2m block 10C7) and RAM_REFRESH_STATE holds its 0 / 1. Its claim that the value "
         "picks bytes 0-3 or 4-7 of the parameter table entries at 0x35224 is not checked - a lead)\n"),
        ("# Calibration State Signature - calibration_state_signature @ 0x0080dc90\n"
         "# Magic values indicating calibration state machine position\n"
         "CALIBRATION_STATE_SIGNATURE,0xEEEE,ACTIVE_BANK_SELECTED,Active calibration bank is selected,2\n"
         "CALIBRATION_STATE_SIGNATURE,0xEAEA,FACTORY_BANK_SELECTED,Factory calibration bank is selected,2\n"
         "CALIBRATION_STATE_SIGNATURE,0xEAEB,TRANSITION_PENDING,Transition to active bank pending,2\n"
         "CALIBRATION_STATE_SIGNATURE,0xEEEF,SYNC_COMPLETE,RAM to flash sync complete,2\n",
         f"# (CALIBRATION_STATE_SIGNATURE - J90280.05's reading of 0x80dc90 - removed in {R}: 0x80dc90 is run_location (e2m "
         "block 0010) and RUN_LOCATION holds 0xeeee / 0xeaea; no write of its 0xeaeb / 0xeeef was found)\n")):
    if new in s:
        continue
    assert s.count(old) == 1, old[:60]
    s = s.replace(old, new)
open(P, "w", newline="").write(s.replace("\n", eol))
print("round 74 stage C applied")

"""Round 86 stage D (CM550), from an advisor review of stage C. Idempotent; keeps line endings.
usage: apply_r86d.py <repo> <local_variables backup>
- mc68k_dispatchJ1708ReceivedMessages (0x15f8e): stage C's word return for cm550_crc16Calculate made the decompiler
  merge three values of one register into wVar4: the elapsed CTM4_BIUTBR read, the CRC result and a QSM_SCCR1 temp (a
  build without the function's local rows shows it). The row wVar4 -> elapsedTimerCount therefore landed on the CRC
  result. A name for all three would mislead, so that row goes; currentTimerCount (wVar3, the entry read) stays.
- cm550_diagMemoryReadResponseBuilder (0x2238e): both callers call it as a statement, so its unused 4-byte return
  (return CONCAT31(extraout_var, ...)) becomes a void return row; its rows take the current function name."""
import os
import sys

repo, backup = os.path.abspath(sys.argv[1]), sys.argv[2]
O5 = os.path.join(repo, "firmware/CM550_J90350.00_analysis/output")
L5, D5 = os.path.join(O5, "local_variables.csv"), os.path.join(O5, "function_definitions.csv")
R = "PR #53 round 86"

text = open(backup, newline="").read()
eol = "\r\n" if "\r\n" in text else "\n"
lines = [l for l in text.split(eol) if not l.startswith("0x00015f8e,") or ",wVar3,currentTimerCount," in l]
assert sum(1 for l in lines if l.startswith("0x00015f8e,")) == 1
open(L5, "w", newline="").write(eol.join(lines))

d = open(D5, newline="").read()
deol = "\r\n" if "\r\n" in d else "\n"
d = d.replace("0x0002238e,diagMemoryReadResponseBuilder,", "0x0002238e,cm550_diagMemoryReadResponseBuilder,")
row = (f"0x0002238e,cm550_diagMemoryReadResponseBuilder,return,,void,No result: both callers call it as a statement "
       f"({R})")
if row not in d:
    anchor = "0x0002238e,cm550_diagMemoryReadResponseBuilder,0,request_ptr,"
    assert d.count(anchor) == 1
    d = d.replace(anchor, row + deol + anchor)
open(D5, "w", newline="").write(d)
print("round 86 stage D applied")

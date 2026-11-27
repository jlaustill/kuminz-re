"""Round 75 stage A5 (CM550): 0x1e288 mc68k_epsPositionSensorIsrHandler is the J1708 SCI interrupt handler. On QSM_SCSR
RDRF (0x40) it reads the byte from QSM_SCDR into the J1708 receive buffer and adds it to the checksum. While
transmitting, it sends the next transmit byte to QSM_SCDR and, at the end, the two's complement of the checksum
(~sum + 1). It clears QSM_SCCR1 RIE when the receive buffer is full. Idempotent. usage: apply_r75a5.py <repo> <map.csv>"""
import os
import sys

repo, map5 = os.path.abspath(sys.argv[1]), sys.argv[2]
p = os.path.join(repo, "firmware/CM550_J90350.00_analysis/output/function_renames.csv")
s = open(p, newline="").read()
old = "0x0001e288,mc68k_epsPositionSensorIsrHandler\n"
new = ("0x0001e288,mc68k_j1708SciInterruptHandler,The J1708 SCI interrupt handler: on QSM_SCSR RDRF (0x40) it reads the "
       "byte from QSM_SCDR into the J1708 receive buffer and adds it to the checksum - while transmitting it sends the "
       "next transmit byte to QSM_SCDR and at the end the two's complement of the checksum (~sum + 1) - and it clears "
       "QSM_SCCR1 RIE when the receive buffer is full. No EPS position sensor is involved (was "
       "mc68k_epsPositionSensorIsrHandler; PR #53 round 75)\n")
if new not in s:
    assert s.count(old) == 1, s.count(old)
    open(p, "w", newline="").write(s.replace(old, new))
with open(map5, "w") as fh:
    fh.write("address,name,old_label,kind,dims\n"
             "0x0001e288,mc68k_j1708SciInterruptHandler,mc68k_epsPositionSensorIsrHandler,function,1\n")
print("round 75 stage A5 applied")

"""Round 75 stage A3 (CM550): the J1708 datalink's SCI. Idempotent; keeps line endings.
- 0xFFFC08-0xFFFC0E are the MC68336 QSM SCI registers SCCR0 / SCCR1 / SCSR / SCDR. The proof is in the code:
  mc68k_tpuTransmissionTrigger writes the first J1708 transmit byte (*_j1708_transmit_buffer_2_32_dc98) to 0xFFFC0E,
  and the initializer mc68k_FUN_00029130 writes SCCR0 = 0x34 and SCCR1 = 0x102c (ILT + RIE + TE + RE). CM550 had no
  row in the 0x00FFxxxx register space, so every register rendered as Ram00fffXXX.
- mc68k_tpuTransmissionTrigger (0x16d4e) -> cm550_startJ1708Transmission. With a message pending and SCSR bit 0x20 (RAF,
  receiver active) clear (an idle bus), it writes the first byte to SCDR. It then arms the CTM4 timer at 0xFFF458 / 0xFFF45A
  and sets SCCR1 bit 0x20 (RIE) to read back its own bytes - the J1708 collision check. It drives no TPU channel.
- mc68k_FUN_00029130 (0x29130) -> cm550_initializeJ1708Datalink. It initializes the secure write scratch pad, the
  diagnostic buffer pointers, the J1708 receive state, the multipacket flags, the broadcast enable word and the InSite
  parameter schedule, and then the SCI.
usage: apply_r75a3.py <repo> <map.csv>"""
import os
import sys

repo, map5 = os.path.abspath(sys.argv[1]), sys.argv[2]
O5 = os.path.join(repo, "firmware/CM550_J90350.00_analysis/output")
R = "PR #53 round 75"


def read(p):
    with open(p, "rb") as fh:
        raw = fh.read().decode()
    return raw, ("\r\n" if "\r\n" in raw else "\n")


def write(p, s):
    with open(p, "wb") as fh:
        fh.write(s.encode())


def edit(p, old, new):
    s, _ = read(p)
    if new in s:
        return
    assert s.count(old) == 1, (os.path.basename(p), old[:90], s.count(old))
    write(p, s.replace(old, new))


G5, F5 = (os.path.join(O5, n) for n in ("global_variables.csv", "function_renames.csv"))
REGISTERS = [
    ("0x00fffc08", "QSM_SCCR0", "MC68336 QSM SCI control register 0 (the baud rate divisor): "
     "cm550_initializeJ1708Datalink writes 0x34"),
    ("0x00fffc0a", "QSM_SCCR1", "MC68336 QSM SCI control register 1: cm550_initializeJ1708Datalink writes 0x102c "
     "(ILT 0x1000 + RIE 0x20 + TE 0x08 + RE 0x04); cm550_startJ1708Transmission sets RIE (0x20) to read back its own bytes"),
    ("0x00fffc0c", "QSM_SCSR", "MC68336 QSM SCI status register: cm550_startJ1708Transmission sends only while bit 0x20 "
     "(RAF - receiver active) is clear"),
    ("0x00fffc0e", "QSM_SCDR", "MC68336 QSM SCI data register: cm550_startJ1708Transmission writes the first J1708 "
     "transmit byte here"),
]
g, eol = read(G5)
if "0x00fffc08,QSM_SCCR0," not in g:
    rows = [f"{a},{n},word,{c} ({R})" for a, n, c in REGISTERS]
    body = g.rstrip(eol)
    write(G5, body + eol + eol.join(rows) + eol)
edit(F5, "0x00016d4e,mc68k_tpuTransmissionTrigger",
     "0x00016d4e,cm550_startJ1708Transmission,Starts a J1708 transmission: with a message pending and the bus idle "
     "(QSM_SCSR bit 0x20 RAF clear) it writes the first byte to QSM_SCDR - arms the timer at 0xFFF458 / "
     "0xFFF45A (the CTM4 address range) and sets QSM_SCCR1 RIE to read back its own bytes (the J1708 collision check). It drives no TPU channel "
     f"(was mc68k_tpuTransmissionTrigger; {R})")
edit(F5, "0x00029130,mc68k_FUN_00029130",
     "0x00029130,cm550_initializeJ1708Datalink,Initializes the J1708 datalink: the secure write scratch pad - the "
     "diagnostic buffer pointers (cm550_diagnosticBufferPointerInit) - the J1708 receive state - the multipacket flags "
     "- the broadcast enable word (from EEPROM 0x47e) - the InSite parameter schedule (next due ticks from "
     "insite_parameter_schedule_table) - then the QSM SCI (QSM_SCCR0 = 0x34 / QSM_SCCR1 = 0x102c). Six startup "
     f"functions call it (was mc68k_FUN_00029130; {R})")
with open(map5, "w") as fh:
    fh.write("address,name,old_label,kind,dims\n"
             "0x00016d4e,cm550_startJ1708Transmission,mc68k_tpuTransmissionTrigger,function,1\n"
             "0x00029130,cm550_initializeJ1708Datalink,mc68k_FUN_00029130,function,1\n")
print("round 75 stage A3 applied")

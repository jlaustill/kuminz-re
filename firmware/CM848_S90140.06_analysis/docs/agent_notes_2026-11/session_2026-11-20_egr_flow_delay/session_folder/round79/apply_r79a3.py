"""Round 79 stage A3 (CM550): the CS5 CAN controller's two functions, named for what they drive (keeping CM550's mc68k_
prefix for code that accesses hardware registers). Idempotent. usage: apply_r79a3.py <repo> <map.csv>
- 0xc760 mc68k_tpuTimerInitializer -> mc68k_configureCanCs5MessageObjects. It touches no TPU register: it stores the
  controller base &CAN_CS5_CONTROL in 0x8000f0, sets _can_1_chip_s_last_message_object_used_0_15 to 6, sets
  CAN_CS5_CONTROL bits 0x0a and sets up message objects 1-6. Objects 1 / 3 / 5 are receive (configuration 0x80) with
  11-bit identifiers 0x112 / 0x512 / 0x712; objects 2 / 4 / 6 are transmit (0x88) with 0x100 / 0x500 / 0x700.
- 0x1e1d0 mc68k_serialPort2IsrHandler -> mc68k_canCs5InterruptHandler. It loops while CAN_CS5_INTERRUPT is non-zero:
  codes below 3 are the status change / message 15 cases (it reads CAN_CS5_STATUS and resets CAN_CS5_CONTROL), and
  code n otherwise reaches message object n - 2 at CAN_CS5_INTERRUPT * 0x10 + 0xffc7e0. No serial port is involved."""
import os
import sys

repo, map5 = os.path.abspath(sys.argv[1]), sys.argv[2]
p = os.path.join(repo, "firmware/CM550_J90350.00_analysis/output/function_renames.csv")
s = open(p, newline="").read()
R = "PR #53 round 79"
for old, new in (
        ("0x0000c760,mc68k_tpuTimerInitializer\n",
         "0x0000c760,mc68k_configureCanCs5MessageObjects,Sets up the 82527 CAN controller on chip select 5: stores its base "
         "&CAN_CS5_CONTROL in 0x8000f0 - sets _can_1_chip_s_last_message_object_used_0_15 to 6 - sets CAN_CS5_CONTROL bits "
         "0x0a - and configures message objects 1-6: 1 / 3 / 5 receive (configuration 0x80) 11-bit identifiers 0x112 / "
         "0x512 / 0x712 and 2 / 4 / 6 transmit (0x88) 0x100 / 0x500 / 0x700. No TPU register is involved (was "
         f"mc68k_tpuTimerInitializer; {R})\n"),
        ("0x0001e1d0,mc68k_serialPort2IsrHandler\n",
         "0x0001e1d0,mc68k_canCs5InterruptHandler,The interrupt handler of the 82527 CAN controller on chip select 5: loops "
         "while CAN_CS5_INTERRUPT is non-zero - codes below 3 are the status change / message 15 cases (reads "
         "CAN_CS5_STATUS and resets CAN_CS5_CONTROL) - code n reaches message object n - 2 at CAN_CS5_INTERRUPT * 0x10 + "
         f"0xffc7e0. No serial port is involved (was mc68k_serialPort2IsrHandler; {R})\n")):
    if new not in s:
        assert s.count(old) == 1, (old, s.count(old))
        s = s.replace(old, new)
open(p, "w", newline="").write(s)
with open(map5, "w") as fh:
    fh.write("address,name,old_label,kind,dims\n"
             "0x0000c760,mc68k_configureCanCs5MessageObjects,mc68k_tpuTimerInitializer,function,1\n"
             "0x0001e1d0,mc68k_canCs5InterruptHandler,mc68k_serialPort2IsrHandler,function,1\n")
print("round 79 stage A3 applied")

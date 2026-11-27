"""Round 71 follow-up (the advisor's closing review). Idempotent.
- The lookups' parameters address / length collided with their callers' own address / length, so Ghidra named the
  callers' temps length_00 / address_00 (20 renders, none before). They become range_start / range_length.
- MEMORY_REGION_TYPE_BANK_2_FLASH: the application writer passes the code back, which J1939_DIAGNOSTIC_RESULT reads as
  0x02 WRONG_LENGTH (the codes coincide).
- 0x3fee03 'j1939_cruise_state_t_003fee00.cruise_state_pad_03': no such struct exists and nothing renders it - a junk
  field row inside supervisor_watchdog_serious_error_events_cal.
usage: fix_r71b.py <repo>"""
import os
import sys

O = os.path.join(os.path.abspath(sys.argv[1]), "firmware/CM848_S90140.06_analysis/output")
R = "PR #53 round 71"


def edit(name, old, new):
    p = os.path.join(O, name)
    s = open(p).read()
    if new in s:
        return
    assert s.count(old) == 1, (name, old[:90], s.count(old))
    open(p, "w").write(s.replace(old, new))


for addr, func in (("0x000076c8", "cm848_lookupBootMemoryRegionType"),
                   ("0x0050d784", "cm848_lookupApplicationMemoryRegionType")):
    edit("function_definitions.csv", f"{addr},{func},0,address,uint,The range's first address ({R})",
         f"{addr},{func},0,range_start,uint,The range's first address - not 'address': the callers' own address made "
         f"Ghidra name their temps address_00 ({R})")
    edit("function_definitions.csv", f"{addr},{func},1,length,int,Its length in bytes ({R})",
         f"{addr},{func},1,range_length,int,Its length in bytes - not 'length': the callers' own length made Ghidra "
         f"name their temps length_00 ({R})")
edit("enums.csv", "the application writer passes the code back,1",
     "the application writer passes the code back - which J1939_DIAGNOSTIC_RESULT reads as 0x02 WRONG_LENGTH (the codes "
     "coincide),1")
p = os.path.join(O, "global_variables.csv")
lines = open(p).read().split("\n")
junk = "0x003fee03,j1939_cruise_state_t_003fee00.cruise_state_pad_03,,"
if junk in lines:
    lines.remove(junk)
    open(p, "w").write("\n".join(lines))
print("follow-up applied")

"""Round 68 stage A, third pass. Idempotent.
- cm848_lookupEepromParameterAddress's byte * prototype took (its caller lost its cast), but its local stayed
  intake_air_heater_saved_values_t * from the 0x3fee1c path and every path cast to it. The local gets byte * too
  (key piVar2: nothing else in the function is renamed, so the final name is the pre-stage one).
usage: fix_r68a3.py <repo>"""
import os
import sys

O = os.path.join(os.path.abspath(sys.argv[1]), "firmware/CM848_S90140.06_analysis/output")
p = os.path.join(O, "local_variables.csv")
s = open(p).read()
row = ("0x00002d08,cm848_lookupEepromParameterAddress,piVar2,value_address,byte *,The address returned - typed so the "
       "0x3fee1c path does not make it a struct pointer (PR #53 round 68)")
if row not in s:
    s = s.rstrip("\n") + "\n" + row + "\n"
    open(p, "w").write(s)
print("third pass applied")

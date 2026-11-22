"""Round 21 stage E (types, after the review): the engine protection thresholds are read signed everywhere.
- configuration +0x10 / +0x12 (the shutdown duration thresholds): lha 16(r29) / lha 18(r29) in
  cm848_updateEngineProtectionShutdown, lha 18(r3) and lhax in cm848_isEngineProtectionInputPastThreshold; they
  rendered (int)(short)configuration->...;
- configuration +0x0A / +0x0C (the fueling minimum / maximum thresholds) are read only through the state's threshold
  pointers, and every dereference of the three threshold pointers is lha (lha r8 / r3,0(r12) in the threshold test,
  (int)(short)* in the restart index update and the fault derate fuel limit).
So the four fields become short and the three pointers short* (+0x0E was short already). The input pointer stays
word*: it is read unsigned for the switch masks (lhz) and signed for the compares. The e2m says NU for these four;
the loads decide. usage: apply_r21e.py <repo>"""
import os
import sys

p = os.path.join(os.path.abspath(sys.argv[1]), "firmware/CM848_S90140.06_analysis/output/structure_definitions.csv")
lines = open(p).read().split("\n")
CHANGES = [("engine_protection_channel_configuration_t", f, "word", "short") for f in
           ("fueling_minimum_threshold", "fueling_maximum_threshold", "fueling_shutdown_duration_threshold",
            "engine_speed_shutdown_duration_threshold")] + \
          [("engine_protection_channel_state_t", f, "word*", "short*") for f in
           ("minimum_threshold_pointer", "maximum_threshold_pointer", "engine_speed_lower_limit_pointer")]
NOTE = " | typed signed in round 21 stage E: every load is lha (the e2m's NU notwithstanding)"
for struct, field, old, new in CHANGES:
    prefix = f"{struct},,{field},{old},"
    k = [i for i, l in enumerate(lines) if l.startswith(prefix)]
    assert len(k) == 1, (struct, field)
    line = lines[k[0]].replace(prefix, f"{struct},,{field},{new},", 1)
    assert line.endswith('",,verified'), line[-40:]
    lines[k[0]] = line[:-len('",,verified')] + NOTE + '",,verified'
open(p, "w").write("\n".join(lines))
print(len(CHANGES), "fields typed signed")

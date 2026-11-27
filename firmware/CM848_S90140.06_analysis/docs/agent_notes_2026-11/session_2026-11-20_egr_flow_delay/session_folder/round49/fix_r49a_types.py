"""Round 49 stage A fix: three base rows get the element width the code indexes them with (the first build rendered
pointer arithmetic for them): the four J1939 NAMEs are copied as four halfwords (word), j1939_command_security_flags is
indexed bytewise, one bit per command (byte), and mil_fault_indicator_bits is read as halfwords indexed by fault / 16
(word). Idempotent.  usage: fix_r49a_types.py <repo>"""
import os
import sys

gp = os.path.join(os.path.abspath(sys.argv[1]), "firmware/CM848_S90140.06_analysis/output/global_variables.csv")
g = open(gp).read().split("\n")
fix = {
    "0x0040ad6c": ("j1939_engine_name", "word", "copied as four halfwords"),
    "0x0040ad76": ("j1939_engine_retarder_name", "word", "copied as four halfwords"),
    "0x0005a476": ("j1939_default_engine_name", "word", "copied as four halfwords"),
    "0x0005a47e": ("j1939_default_retarder_name", "word", "copied as four halfwords"),
    "0x0005a486": ("j1939_command_security_flags", "byte", "indexed bytewise, one bit per command"),
    "0x0005b6d0": ("mil_fault_indicator_bits", "word", "read as halfwords indexed by fault / 16"),
}
n = 0
for k, l in enumerate(g):
    a = l[:10]
    if a in fix and l.startswith(a + ","):
        name, typ, how = fix[a]
        p = l.split(",", 3)
        assert p[1] == name, (a, p[1])
        if p[2] != typ:
            p[2] = typ
            p[3] = p[3].replace(" (PR #53 round 49)", f" Typed {typ}: the code reads it {how} (PR #53 round 49)")
            g[k] = ",".join(p)
            n += 1
open(gp, "w").write("\n".join(g))
print(f"{n} rows retyped")

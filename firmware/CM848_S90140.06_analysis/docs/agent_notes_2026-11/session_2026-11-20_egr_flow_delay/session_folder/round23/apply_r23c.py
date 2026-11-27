"""Round 23 stage C (types, after the review): SENSOR_VALUE_SOURCE's reach beyond word globals.
- exhaust_temperature_source (0x40a688, i16; e2m 17A1 +A Exhaust_Tmptr_Source '0=PRIMARY:1=BACKUP:2=DEFAULT'; the code
  stores and compares 0 / 1);
- the struct fields charge_flow_estimate_terms_t.charge_flow_source (e2m 177D +C Charge_Flow_Source) and
  .fresh_air_flow_source (177B +2 Fresh_Air_Flow_Source): both records list PRIMARY / BACKUP; the code stores 0 / 1 in
  both and compares fresh_air_flow_source with 2 (DEFAULT) too;
- two comments that still named 0x40a1a6 by its Ghidra label (DAT_0040a1a6, barometric_altitude_source since round
  19) are refreshed.
usage: apply_r23c.py <repo>"""
import os
import sys

out = os.path.join(os.path.abspath(sys.argv[1]), "firmware/CM848_S90140.06_analysis/output")
gp, sp, fp, ep = (os.path.join(out, n) for n in ("global_variables.csv", "structure_definitions.csv",
                                                 "function_renames.csv", "enums.csv"))
g = open(gp).read().split("\n")
k = [i for i, l in enumerate(g) if l.startswith("0x0040a688,exhaust_temperature_source,i16,")]
assert len(k) == 1
a, n, t, c = g[k[0]].split(",", 3)
g[k[0]] = ",".join([a, n, "SENSOR_VALUE_SOURCE", c + " | typed SENSOR_VALUE_SOURCE in PR #53 round 23 (was i16): its e2m "
                    "record lists 0=PRIMARY, 1=BACKUP, 2=DEFAULT and the code uses 0 / 1"])
open(gp, "w").write("\n".join(g))
s = open(sp).read().split("\n")
for field, record in (("charge_flow_source", "177D +C Charge_Flow_Source"),
                      ("fresh_air_flow_source", "177B +2 Fresh_Air_Flow_Source")):
    prefix = f"charge_flow_estimate_terms_t,0x0040a406,{field},word,2,"
    k = [i for i, l in enumerate(s) if l.startswith(prefix)]
    assert len(k) == 1, field
    line = s[k[0]].replace(prefix, f"charge_flow_estimate_terms_t,0x0040a406,{field},SENSOR_VALUE_SOURCE,2,", 1)
    note = (f" | typed SENSOR_VALUE_SOURCE in PR #53 round 23 (was word): e2m {record} lists 0=PRIMARY, 1=BACKUP, and "
            f"the code uses only " + ("0 / 1" if field == "charge_flow_source" else "0 / 1 and compares 2 (DEFAULT)"))
    # the row ends '"<comment>",<dependency>,<status>' (these two are needs_review; the status is kept)
    q = line.rindex('",')
    line = line[:q] + note + line[q:]
    s[k[0]] = line
open(sp, "w").write("\n".join(s))
for p in (fp, gp):
    t = open(p).read()
    n = t.count("DAT_0040a1a6")
    t = t.replace("DAT_0040a1a6", "barometric_altitude_source")
    open(p, "w").write(t)
    print(os.path.basename(p), n, "DAT_0040a1a6 refreshed")
e = open(ep).read()
old = "turbocharger speed / EGR flow sources\n"
new = ("turbocharger speed / EGR flow sources, and the exhaust temperature source and the charge flow estimate's "
       "charge flow and fresh air flow sources (struct fields)\n")
assert e.count(old) == 1
open(ep, "w").write(e.replace(old, new))
print("3 more SENSOR_VALUE_SOURCE uses")

"""Round 65: repair two doubled edits. fix_r65c.py's edit() skipped an applied edit only when the old text was gone,
so a second run re-applied every edit whose new text contains the old one: task 046 got its follow-up bullet twice
and docs/tpu_mios_channel_map.md line 25 a nested "(were ... (were ...))". Also labels the two "(this follow-up)"
headers with their commits and records the firmware/CLAUDE.md fix (ab2dce05). Checks its own result.
usage: fix_r65e.py <repo>"""
import os
import sys

repo = os.path.abspath(sys.argv[1])
T = os.path.join(repo, "work/tasks/046-cm848-egr-flow-estimate.md")
s = open(T).read()
HEAD = "- **Follow-up (this follow-up), from the closing review:**\n"
start = s.find(HEAD)
assert start != -1 or "- **Follow-up (79e9e95f), from the closing review:**" in s
if start != -1:
    second = s.find(HEAD, start + 1)
    assert second != -1, "expected the doubled bullet"
    block = s[start:second]
    assert s[second:second + len(block)] == block, "the copies differ"
    s = s[:second] + s[second + len(block):]
    s = s.replace(HEAD, "- **Follow-up (79e9e95f), from the closing review:**\n", 1)
NOTE = ("  - `firmware/CLAUDE.md` lines 217 / 230 on the current names (ab2dce05). On line 217 the refresh had changed only\n"
        "    the registrar, not the `j1939_receivePgn{...}Handler` brace list. Line 230 said the two CCVS1 / EEC2 transmit\n"
        "    builders were not yet renamed; earlier rounds had renamed both.\n")
anchor = ("  - Commit 5e0d02e6 says the registrar differs by newly named globals. It differs by its renamed count and\n"
          "    the `PTR_..._003fd416` auto-label.\n")
if NOTE not in s:
    assert s.count(anchor) == 1, s.count(anchor)
    s = s.replace(anchor, anchor + NOTE)
s = s.replace("- **Corrections (this follow-up), from the closing review:**",
              "- **Corrections (f7e7b6c1), from the closing review:**")
assert "(this follow-up)" not in s
assert s.count("- **Follow-up (79e9e95f), from the closing review:**") == 1
open(T, "w").write(s)

D = os.path.join(repo, "firmware/CM848_S90140.06_analysis/docs/tpu_mios_channel_map.md")
d = open(D).read()
NEW = ("`cm848_loadInjectionStartAnglesOnTpuChannel6` / `cm848_scheduleInjectionAnglesInSpeedLimpHome` / "
       "`cm848_scheduleInjectionAnglesOnPrimarySpeedInput`")
OLD_LIST = "`engine_injectionAngle_{computeLoadCh6,schedule_crankValid,schedule_crankInvalid}`"
nested = f"{NEW} (were {NEW} (were {OLD_LIST}))"
single = f"{NEW} (were {OLD_LIST})"
if nested in d:
    d = d.replace(nested, single)
assert d.count(single) == 1 and nested not in d
open(D, "w").write(d)
print("task 046: 1 bullet + 2 labels + CLAUDE.md note / channel map line 25 repaired")

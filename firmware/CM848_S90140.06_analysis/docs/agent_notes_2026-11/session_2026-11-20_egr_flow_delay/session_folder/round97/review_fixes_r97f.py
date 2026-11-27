"""Round 97 stage F review fixes (from the statement-count check workflow wf_d98cbafa-77a):
- 0x31b22 cm550_sendPgn59392AcknowledgementMessage: R6's judge amended the prototype and said to keep the existing
  parameter 1 row (acknowledgement_type, the word at +8); prototypes_r97f.py dropped it, so all three callers lost their
  ACK / NACK argument (two skeptics confirmed it from move.w (0x10,a7),d1 at 0x31b26). The committed row comes back under
  the new function name, and parameter 0 takes the judge's amended text.
- 0x18fcc processDiagnosticLimitStatus: a void(void) row. It reads no stack argument (its only (n,a7) uses are the lea
  pops after its calls) and its only call, jsr at 0x18676, falls into 0x1867c, which never reads d0; the ushort return was
  d0's leftover.
usage: review_fixes_r97f.py <repo> <head function_definitions.csv>"""
import json
import os
import sys

repo, head_path = os.path.abspath(sys.argv[1]), sys.argv[2]
p = os.path.join(repo, "firmware/CM550_J90350.00_analysis/output/function_definitions.csv")
t = open(p, newline="").read()
E = "\r\n" if "\r\n" in t else "\n"
lines = t.split(E)
R = "PR #53 round 97"
# 0x31b22
d = json.load(open("/home/linux/.claude/jobs/374b0424/tmp/w15/r97/batch_R6.json"))
judged = next(x["final_comment"] for x in d["verdict"]["verdicts"] if x.get("kind") == "prototype" and str(x["address"]).lower().endswith("31b22"))
part0 = next(s for s in judged.split(" | ") if s.startswith("0 request "))
text0 = part0.split(": ", 1)[1].replace(",", ";")
head1 = next(l for l in open(head_path, newline="").read().splitlines() if l.startswith("0x00031b22,") and l.split(",")[2] == "1")
i0 = next(k for k, l in enumerate(lines) if l.startswith("0x00031b22,") and l.split(",")[2] == "0")
name = lines[i0].split(",")[1]
lines[i0] = f"0x00031b22,{name},0,request,can_standard_receive_descriptor_t*,{text0}"
q = head1.split(",", 5)
lines.insert(i0 + 1, f"0x00031b22,{name},1,{q[3]},{q[4]},{q[5]}")
print("0x31b22: parameter 1 restored:", lines[i0 + 1][:110])
# 0x18fcc
assert not any(l.startswith("0x00018fcc,") for l in lines)
fn = [l for l in open(os.path.join(repo, "firmware/CM550_J90350.00_analysis/output/function_renames.csv"), newline="").read().splitlines() if l.startswith("0x00018fcc,")][0].split(",")[1]
k = next(k for k, l in enumerate(lines) if l.startswith("0x") and int(l.split(",", 1)[0], 16) > 0x18fcc)
lines.insert(k, f"0x00018fcc,{fn},return,,void,No result and no stack argument: its only call (jsr at 0x18676 in "
             f"cm550_runEngineProtectionScheduler) falls into 0x1867c and never reads d0; the ushort it rendered was d0's "
             f"leftover ({R})")
print("0x18fcc: void row before", lines[k + 1][:40])
open(p, "w", newline="").write(E.join(lines))

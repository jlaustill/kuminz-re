"""Round 62 follow-up closing: record stage B (the no-op service handler and its registrar) in task 046, the PR body and
memory; the stage A name in task 046 is replaced. Idempotent.  usage: fix_r62c.py <repo> <pr_body.md> <hash B> <count>"""
import os
import re
import sys

repo, pr, hb, count = os.path.abspath(sys.argv[1]), sys.argv[2], sys.argv[3], sys.argv[4]


def edit(path, old, new):
    p = path if os.path.isabs(path) else os.path.join(repo, path)
    s = open(p).read()
    if new in s:
        return
    assert s.count(old) == 1, (path, old[:70], s.count(old))
    open(p, "w").write(s.replace(old, new))


T = "work/tasks/046-cm848-egr-flow-estimate.md"
edit(T, "    `cm848_registerJ1939ParameterAndBroadcastServices` / `cm848_registerJ1939MemoryWriteServices` /",
     "    `cm848_registerJ1939BroadcastAndNoOperationServices` (stage B) / `cm848_registerJ1939MemoryWriteServices` /")
edit(T, "- **Not done:** typing the J1939 service ID as `EF00_SERVICE_ID`.",
     f"- **Stage B ({hb}), from the closing checks:** stage A named the services 0x0f / 0x10 / 4 / 5 registrar\n"
     "  `...ParameterAndBroadcastServices` after the `EF00_SERVICE_ID` member names. But `j1939_diagService15And16Handler`\n"
     "  only returns 0: 0x0f / 0x10 are accepted no-ops in this build. The handler is now\n"
     "  `cm848_j1939DiagnosticServiceAcknowledgeNoOperation` (the application's twin of the boot kernel's\n"
     "  `cm848_diagServiceAcknowledgeNoOperation`), and the registrar is `cm848_registerJ1939BroadcastAndNoOperationServices`.\n"
     "  Also checked:\n"
     "  - e2m 10CE (Limp_Home_*) holds every `pedal_fault_mode_*` setting, and the filter coefficient row now cites\n"
     "    10CE +0;\n"
     "  - `j1939_input_fault_start_delay` reads 1000 in the dump, as it should with the J1939 input layer off, and both\n"
     "    input processors clear the two faults while it is nonzero;\n"
     "  - none of the round's old labels is in CM550;\n"
     "  - \"first byte\" for the DM7 Test Identifier rests on the code reading byte 0, since the database gives no byte\n"
     "    positions.\n"
     "- **Not done:** typing the J1939 service ID as `EF00_SERVICE_ID`.")
edit(pr, "  start delay and four vague Bank 2 helpers are named from their code, and one more combustion torque cache is\n"
         "  typed.\n",
     "  start delay and four vague Bank 2 helpers are named from their code, and one more combustion torque cache is\n"
     "  typed.\n"
     f"- **Stage B ({hb}):** the services 0x0f / 0x10 handler is a no-op, now\n"
     "  `cm848_j1939DiagnosticServiceAcknowledgeNoOperation`, and its registrar is\n"
     "  `cm848_registerJ1939BroadcastAndNoOperationServices` (stage A had named it after the enum's member names).\n")
M = "/home/linux/.claude/projects/-home-linux-code-kuminz-re/memory/MEMORY.md"
m = open(M).read()
open(M, "w").write(re.sub(r"\(cm848/egr-flow-delay-model, \d+ commits\)", f"(cm848/egr-flow-delay-model, {count} commits)", m))
print("round 62 follow-up closing applied")

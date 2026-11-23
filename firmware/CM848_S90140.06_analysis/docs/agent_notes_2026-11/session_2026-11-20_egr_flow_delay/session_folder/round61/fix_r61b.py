"""Round 61 follow-up: stage A's new field comments dropped two facts the old ones carried. Both are verified, so they
come back. Struct field comments do not render in the .cpp, so this needs no rebuild. Idempotent.
usage: fix_r61b.py <repo>
- j1939_diagnostic_service_entry_t.service_id pointed at the EF00_SERVICE_ID enum (24 members in enums.csv).
- boot_diagnostic_service_entry_t.service_id listed 0x43 / 0x4A / 0x4C. The kernel's constant-ID
  cm848_registerDiagnosticService calls register 0x0b / 0x10 / 0x18 (acknowledge - no operation), 0x19 (execute
  function), 0x41 (service 65) and 0x43 / 0x4a / 0x4c (memory reads)."""
import os
import sys

repo = os.path.abspath(sys.argv[1])


def edit(rel, old, new):
    p = os.path.join(repo, rel)
    s = open(p).read()
    if new in s:
        return
    assert s.count(old) == 1, (rel, old[:70], s.count(old))
    open(p, "w").write(s.replace(old, new))


S = "firmware/CM848_S90140.06_analysis/output/structure_definitions.csv"
edit(S, "j1939_diagnostic_service_entry_t,,service_id,byte,1,The PGN 61184 diagnostic service byte (the request's first "
        "data byte),,verified",
     "j1939_diagnostic_service_entry_t,,service_id,byte,1,The PGN 61184 diagnostic service byte (the request's first "
     "data byte; its values are the EF00_SERVICE_ID enum),,verified")
edit(S, "boot_diagnostic_service_entry_t,,service_id,byte,1,The boot diagnostic service byte,,verified",
     "boot_diagnostic_service_entry_t,,service_id,byte,1,The boot diagnostic service byte: the kernel's constant-ID "
     "cm848_registerDiagnosticService calls register 0x0b / 0x10 / 0x18 (acknowledge - no operation) / 0x19 (execute "
     "function) / 0x41 (service 65) / 0x43 / 0x4a / 0x4c (memory reads),,verified")
T = "work/tasks/046-cm848-egr-flow-estimate.md"
edit(T, "- **Leads:** the `j1939_dm1_request_mode_byte` global holds the DM7 request's mode byte, so the name looks wrong; 69\n"
        "  unprefixed CM848-only functions remain.",
     "- **Follow-up (comments only):** stage A's new field comments had dropped two verified facts, and they are\n"
     "  restored. The J1939 `service_id` points at the `EF00_SERVICE_ID` enum. The boot `service_id` lists the kernel's\n"
     "  constant-ID registrations: 0x0b / 0x10 / 0x18 acknowledge, 0x19, 0x41, and 0x43 / 0x4a / 0x4c memory reads.\n"
     "- **Leads:**\n"
     "  - Type `j1939_diagnostic_service_entry_t.service_id` as `EF00_SERVICE_ID`; pilot it and count the casts.\n"
     "  - `cm848_validateJ1939DiagnosticRequest`'s plate says the key check runs when\n"
     "    `calibration_download_security_key_cal` \"is set\". The code tests `!= 0xff`, so fix the plate at the next\n"
     "    rebuild.\n"
     "  - `j1939_dm1_request_mode_byte` holds the DM7 request's mode byte, so the name looks wrong.\n"
     "  - 69 unprefixed CM848-only functions remain.")
M = "/home/linux/.claude/projects/-home-linux-code-kuminz-re/memory/MEMORY.md"
m = open(M).read()
open(M, "w").write(m.replace("(cm848/egr-flow-delay-model, 264 commits)", "(cm848/egr-flow-delay-model, 265 commits)"))
print("round 61 follow-up applied")

"""Round 63 follow-up closing: record the follow-up stage in task 046 / the PR body / memory. Idempotent.
usage: fix_r63e_closing.py <repo> <pr_body.md> <hash D> <count>"""
import os
import re
import sys

repo, pr, hd, count = os.path.abspath(sys.argv[1]), sys.argv[2], sys.argv[3], sys.argv[4]


def edit(path, old, new):
    p = path if os.path.isabs(path) else os.path.join(repo, path)
    s = open(p).read()
    if new in s:
        return
    assert s.count(old) == 1, (path, old[:70], s.count(old))
    open(p, "w").write(s.replace(old, new))


T = "work/tasks/046-cm848-egr-flow-estimate.md"
edit(T, "  - `boot_kernel_rom_end` is also where the boot read reply table starts.\n- **Proof:**",
     "  - `boot_kernel_rom_end` is also where the boot read reply table starts.\n"
     f"- **Follow-up ({hd}), from the closing checks:**\n"
     "  - CM550's `EF00_SERVICE_ID` type is `J1939_DIAGNOSTIC_SERVICE` too, since shared names change in both\n"
     "    firmwares. Its members stay CM550's own, and the enum renders nowhere in CM550: its `.cpp` matches a base\n"
     "    build.\n"
     "  - The 0x0d member comment: 0xfe sends 0x0e.\n"
     "  - The boot dispatcher's plate: a received 0x0c / 0x0d gets no answer. It said \"answered directly\".\n"
     "  - `diag_scan_step_counter` -> `boot_diagnostic_service_count`. The boot registrar appends at it (at most 20)\n"
     "    and the boot dispatcher scans that many entries.\n"
     "  - A wider sweep for the round's 46 old names and its three overturned claims. It fixed three docs:\n"
     "    - `parameter_by_id_system.md` names the boot handlers;\n"
     "    - `rom_to_ram_thunking.md`'s snapshot row;\n"
     "    - `ecu_identification.md` has a CM848 footnote under its test matrix.\n"
     "    Snapshots, worklists, dated plans and task logs keep the old names.\n"
     "- **Proof:**")
edit(T, "  - `DAT_003fba10` (round 62's lead) is still open.\n  - 38 unprefixed CM848-only functions remain.\n",
     "  - `DAT_003fba10` (round 62's lead) is still open.\n"
     "  - **CM550's `J1939_DIAGNOSTIC_SERVICE` members are unreviewed.** They are its own CLIP-era names (0x43\n"
     "    `MEM_READ_2B_PARAM_4B_OFFSET`), and no CM550 handler was read this round.\n"
     "  - **Three unnamed length tables:**\n"
     "    - 0x53a322, the application's header lengths. The code's base 0x53a2e1 falls inside input signal\n"
     "      descriptor 10.\n"
     "    - 0x5761e, the Bank 1 echo lengths (base 0x575dd).\n"
     "    - The boot kernel's header lengths, in its image at RAM 0x3f97cd + service.\n"
     "  - 38 unprefixed CM848-only functions remain.\n")
edit(pr, "  23 functions renamed.\n",
     "  23 functions renamed.\n"
     f"- **Follow-up ({hd}):**\n"
     "  - CM550's copy of the enum type is renamed too (its members stay its own).\n"
     "  - Two wrong comments fixed.\n"
     "  - The boot kernel's service count named.\n"
     "  - Three docs that still described the old reading fixed.\n")
M = "/home/linux/.claude/projects/-home-linux-code-kuminz-re/memory/MEMORY.md"
m = open(M).read()
open(M, "w").write(re.sub(r"\(cm848/egr-flow-delay-model, \d+ commits\)", f"(cm848/egr-flow-delay-model, {count} commits)", m))
print("round 63 follow-up closing applied")

"""Round 87 stage C closing fix-up: task 046, PR body, README, the memory round log (the marker check's fault is 318 =
P0604, not 462), the stage C entries. Idempotent.
usage: apply_r87c_closing.py <repo> <pr_body.md> <hash C> <count> <proof C file>"""
import os
import re
import sys

repo, pr, hc, count, pc_file = os.path.abspath(sys.argv[1]), *sys.argv[2:6]
proof_c = open(pc_file).read().strip()


def path(rel):
    return rel if os.path.isabs(rel) else os.path.join(repo, rel)


def edit(rel, old, new):
    p = path(rel)
    t = open(p).read()
    if new in t:
        return
    assert t.count(old) == 1, (rel, old[:70], t.count(old))
    open(p, "w").write(t.replace(old, new))


T = "work/tasks/046-cm848-egr-flow-estimate.md"
edit(T, "`cm848_checkWorkingRamEndMarker` (was `cm848_main_loop_initialization`) sets fault 462\n"
        "    (`working_ram_end_marker_error`, no DTC slot) when it is gone.",
     "`cm848_checkWorkingRamEndMarker` (was `cm848_main_loop_initialization`) sets fault 318\n"
     "    (`working_ram_end_marker_error`, P0604 internal control module RAM error) when it is gone; stage B said\n"
     "    fault 462, which stage C corrected.")
edit(T, "- **firmware/CLAUDE.md:** stage A renamed the CM848 functions in three lines; stage B corrected the ROM-to-RAM line",
     f"- **Stage C ({hc}), from an advisor review of stages A-B:**\n"
     "  - The marker check's fault is 318 (P0604), not 462. The store is `sth r11,38(r3)` at 0x5279cc off the fault\n"
     "    word base, and Ghidra's piece offset in `fault_detected_cal._38_2_` is a decimal byte offset: byte 38 = word\n"
     "    19, bit 14 = fault 318. Stage B had matched the e2m \"+38\" of word 28, which is hex. Word 28 bit 14 is\n"
     "    `fault_462` again.\n"
     "  - CM550 0x15f8c `emptyStubFunction4` -> `cm550_emptyStubFunction4`: its old shared name belonged to CM848\n"
     "    0x26f78, which stage A made `ignoreCanTransmitInterrupt` (one `bl` at 0x53acc and no pointer in either image\n"
     "    reach 0x26f78, `find_pointer.py`); 0x15f8c is another empty stub, called once from\n"
     "    `mc68k_sampleAndDebounceDiscreteInputs`.\n"
     "  - CM550 0x1192a's plate states what its body does (the waits, the hour meter saves, the `ram_refresh_enable`\n"
     "    branch).\n"
     f"  - **Proof:** {proof_c}\n"
     "- **firmware/CLAUDE.md:** stage A renamed the CM848 functions in three lines; stage B corrected the ROM-to-RAM line")
edit(T, "  - `clearWorkingRam` in both twins: `dword *` local rows would drop the pointer casts that the marker's dword type\n"
        "    brought into CM848's loop, and CM550's twin still ends at a raw 0x80def4.",
     "  - `clearWorkingRam` in both twins: `dword *` local rows would drop the pointer casts that the marker's dword type\n"
     "    brought into CM848's loop, and CM550's twin still ends at a raw 0x80def4.\n"
     "  - `emptyStubFunction2` / `emptyStubFunction3` are shared names on empty stubs; nobody has checked their pairing\n"
     "    (no CM550 caller in the `.cpp`).")
edit(pr, "  `cm550_initializeDiscreteInputs`, and CM848's working RAM end marker (`cm848_writeWorkingRamEndMarker` /\n"
         "  `cm848_checkWorkingRamEndMarker`, fault 462).\n",
     "  `cm550_initializeDiscreteInputs`, and CM848's working RAM end marker (`cm848_writeWorkingRamEndMarker` /\n"
     "  `cm848_checkWorkingRamEndMarker`, fault 318 = P0604).\n"
     f"- **Stage C ({hc}):** the marker check's fault is 318 (P0604), not 462 as stage B said (Ghidra's `_38_2_` piece\n"
     "  offset is a decimal byte offset); `cm550_emptyStubFunction4` (its old name was CM848 0x26f78's); the CM550\n"
     "  restart routine's plate.\n")
edit(pr, "- [x] Round 87: B: ", f"- [x] Round 87: C: {proof_c}\n- [x] Round 87: B: ")
README = "firmware/CM848_S90140.06_analysis/docs/agent_notes_2026-11/session_2026-11-20_egr_flow_delay/README.md"
edit(README, "- **Closing:** `apply_r87_closing.py`, `update_large_tar_r87.sh`.\n",
     "- **Stage C:** `apply_r87c.py`, `find_pointer.py` (big-endian pointers to an address and the PowerPC branches that\n"
     "  target it, in one or more images).\n"
     "- **Closing:** `apply_r87_closing.py`, `apply_r87c_closing.py`, `update_large_tar_r87.sh`.\n")
M = "/home/linux/.claude/projects/-home-linux-code-kuminz-re/memory/"
for name, pat, rep in (("MEMORY.md", r"\(cm848/egr-flow-delay-model, \d+ commits\)", f"(cm848/egr-flow-delay-model, {count} commits)"),
                       ("pr53_egr_flow_delay_rounds.md", r"is still OPEN on 2026-11-24\n\(\d+ commits\)",
                        f"is still OPEN on 2026-11-24\n({count} commits)")):
    p = M + name
    s = open(p).read()
    s2 = re.sub(pat, rep, s)
    assert f"{count} commits" in s2, name
    open(p, "w").write(s2)
edit(M + "pr53_egr_flow_delay_rounds.md", "the CM848 working RAM end marker (fault 462)",
     "the CM848 working RAM end marker (fault 318 = P0604; stage C corrected stage B's 462 - see "
     "[[ghidra-piece-offsets-decimal]])")
print("round 87 stage C closing applied")

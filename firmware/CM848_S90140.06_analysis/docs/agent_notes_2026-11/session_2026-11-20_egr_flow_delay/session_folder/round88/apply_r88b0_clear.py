"""Round 88 stage B0 (CM550 + CM848): local rows for the twin clearWorkingRam, which clears one dword per step.
CM848's loop (pointer word *, chunk end dword *) rendered pointer casts once working_ram_end_marker became a dword in
round 87; CM550's used undefined4 pointers. Both locals become dword * in both twins, so each reads
working_ram_pointer <= chunk_end / working_ram_pointer + 1 / *working_ram_pointer = 0. Auto-names from the current
builds. Idempotent. usage: apply_r88b0_clear.py <repo>"""
import os
import sys

repo = os.path.abspath(sys.argv[1])
R = "PR #53 round 88"
ROWS = {
    "firmware/CM848_S90140.06_analysis/output/local_variables.csv": [
        "0x00538974,clearWorkingRam,pwVar1,working_ram_pointer,dword *,The next dword to clear (one stw per step) "
        f"from executive_frame_ticks (0x3fa000) up to working_ram_end_marker ({R})",
        "0x00538974,clearWorkingRam,pdVar2,chunk_end,dword *,The end of this pass: 256 bytes on or "
        f"working_ram_end_marker; the loop runs while working_ram_pointer <= chunk_end - inclusive ({R})",
    ],
    "firmware/CM550_J90350.00_analysis/output/local_variables.csv": [
        "0x0002e9ac,clearWorkingRam,puVar2,working_ram_pointer,dword*,The next dword to clear (clr.l (a2)+) from "
        f"0x800000 up to 0x80def4 ({R})",
        "0x0002e9ac,clearWorkingRam,puVar1,chunk_end,dword*,The end of this pass: 256 bytes on or 0x80def4; the loop "
        f"runs while working_ram_pointer <= chunk_end - inclusive (the CM848 twin's quirk) ({R})",
    ],
}
for rel, rows in ROWS.items():
    path = os.path.join(repo, rel)
    lines = open(path, newline="").read().split("\n")
    for row in rows:
        if row in lines:
            continue
        address = int(row.split(",")[0], 16)
        for i, l in enumerate(lines):
            if l.startswith("0x") and int(l.split(",")[0], 16) > address:
                lines.insert(i, row)
                break
        else:
            lines.insert(len(lines) - 1 if lines[-1] == "" else len(lines), row)
    open(path, "w", newline="").write("\n".join(lines))
print("clearWorkingRam rows applied")

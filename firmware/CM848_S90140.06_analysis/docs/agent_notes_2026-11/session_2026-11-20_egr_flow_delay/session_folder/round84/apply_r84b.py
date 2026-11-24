"""Round 84 stage B (CM550). Idempotent; keeps line endings. usage: apply_r84b.py <repo> <map.csv>
- The boot block image (ROM 0x291F4-0x2CE63) is data that cm550_updateBootBlockFromImage programs into flash at 0; no
  real code calls into it (prefix_rule_check.py: only other image copies reference the nine copies). Stage A named the
  nine functions Ghidra's analysis found inside it <original>ImageCopy; stage B records them in a new
  deleted_functions.csv (the build removes them after the analysis) and drops their rows, so the image is no longer
  shown as code.
- tpu_microcode_image gets back its whole extent, dword[419] = the 0x68C bytes mc68k_loadTpuMicrocode copies (to the
  entry table at 0x31328). Round 83 stopped it at 0x311F4 only because the image copy of mc68k_hardwareInitAndStartup
  read 0x311F4 / 0x31256 - the image's PC-relative view of ROM 0x8000 / 0x8062.
- 0x395a gets the mc68k_ prefix: it writes SIM_SWSR (MC68336-specific code is prefixed mc68k_)."""
import os
import sys

repo, map5 = os.path.abspath(sys.argv[1]), sys.argv[2]
O5 = os.path.join(repo, "firmware/CM550_J90350.00_analysis/output")
R = "PR #53 round 84"
F5, G5, D5, X5 = (os.path.join(O5, n) for n in ("function_renames.csv", "global_variables.csv",
                                               "function_definitions.csv", "deleted_functions.csv"))
COPIES = [("0x0002c834", "cm550_huffmanTreeBuilderImageCopy", "0x00003640"),
          ("0x0002c986", "cm550_huffmanDecompressImageCopy", "0x00003792"),
          ("0x0002ca2a", "cm550_huffmanDecompressMainImageCopy", "0x00003836"),
          ("0x0002ca64", "cm550_busyWaitDelayLoopImageCopy", "0x00003870"),
          ("0x0002ca7e", "mc68k_portPinTestSequence2ImageCopy", "0x0000388a"),
          ("0x0002cb4e", "cm550_waitForChipSelect2InputBit0HighImageCopy", "0x0000395a"),
          ("0x0002cb9c", "mc68k_checkSerialEepromSignatureImageCopy", "0x000039a8"),
          ("0x0002cc88", "mc68k_hardwareInitAndStartupImageCopy", "0x00003a94"),
          ("0x0002ce14", "cm550_ramClearWithWatchdogImageCopy", "0x00003c20")]

# function_renames.csv: drop the nine image copies; the mc68k_ prefix on 0x395a
s = open(F5, newline="").read()
lines = s.split("\n")
keep = [l for l in lines if not any(l.startswith(a + "," + n + ",") for a, n, _ in COPIES)]
assert len(lines) - len(keep) in (0, 9), len(lines) - len(keep)
s = "\n".join(keep)
old = "0x0000395a,cm550_waitForChipSelect2InputBit0High,"
new = "0x0000395a,mc68k_waitForChipSelect2InputBit0High,"
if new not in s:
    assert s.count(old) == 1
    s = s.replace(old, new)
    s = s.replace("the signal is not identified (was cm550_FUN_0000395a; PR #53 round 84)",
                  "the signal is not identified (was cm550_FUN_0000395a; PR #53 round 84; mc68k_ because it writes "
                  "SIM_SWSR - round 84 stage B)")
open(F5, "w", newline="").write(s)

# function_definitions.csv: the copy's prototype row goes with the copy
d = open(D5, newline="").read()
dl = d.split("\n")
dk = [l for l in dl if not l.startswith("0x0002ca64,")]
assert len(dl) - len(dk) in (0, 1)
open(D5, "w", newline="").write("\n".join(dk))

# deleted_functions.csv (new for CM550)
if not os.path.exists(X5):
    with open(X5, "w", newline="") as fh:
        fh.write("address,reason\n")
        fh.write("# Function-deletion delta (common.sh cmd_deletions -> ApplyFunctionDeletions.java): the build removes these\n")
        fh.write("# function records after the auto-analysis. CM550's first rows (PR #53 round 84): the nine functions the\n")
        fh.write("# analysis finds inside boot_block_image (ROM 0x291F4-0x2CE63, a byte copy of the boot block ROM 0x0-0x3C6F)\n")
        fh.write("# are data here - cm550_updateBootBlockFromImage programs them into flash at 0 - and only other copies call them.\n")
        for address, name, original in COPIES:
            fh.write(f"{address},boot_block_image data: the image's copy of the boot block function at {original} "
                     f"(named {name} in round 84 stage A)\n")

# global_variables.csv: the microcode's whole extent; the image's comment
g = open(G5, newline="").read()
edits = [
    ("0x00030c9c,tpu_microcode_image,dword[342],", "0x00030c9c,tpu_microcode_image,dword[419],"),
    ("The array stops at 0x311F4: mc68k_hardwareInitAndStartupImageCopy reads 0x311F4 / 0x31256 - but that is the boot "
     "block image's PC-relative view of ROM 0x8000 / 0x8062 (the application signature and entry pointer), not a "
     "record in the microcode (PR #53 rounds 83-84)",
     "dword[419] covers the 0x68C bytes the loader copies, up to tpu_microcode_entry_table. Round 83 stopped the array "
     "at 0x311F4 because the boot block image's copy of mc68k_hardwareInitAndStartup read 0x311F4 / 0x31256 - that is "
     "the image's PC-relative view of ROM 0x8000 / 0x8062 (the application signature and entry pointer), and the "
     "image copies are not functions any more (PR #53 rounds 83-84)"),
    ("The nine functions Ghidra finds inside are named <original>ImageCopy (PR #53 round 84)",
     "Data here, not code: the nine functions the analysis finds inside (copies of the boot block's at address - "
     "0x291F4; round 84 stage A named them <original>ImageCopy) are in deleted_functions.csv. Their PC-relative "
     "references show the boot block's 0x8000 / 0x8062 / 0x80339E as 0x311F4 / 0x31256 / 0x82C592 (PR #53 round 84)"),
]
for old, new in edits:
    if new not in g:
        assert g.count(old) == 1, (old[:60], g.count(old))
        g = g.replace(old, new)
open(G5, "w", newline="").write(g)
with open(map5, "w") as fh:
    fh.write("address,name,old_label,kind,dims\n")
    fh.write("0x0000395a,mc68k_waitForChipSelect2InputBit0High,cm550_waitForChipSelect2InputBit0High,function,1\n")
print("round 84 stage B applied")

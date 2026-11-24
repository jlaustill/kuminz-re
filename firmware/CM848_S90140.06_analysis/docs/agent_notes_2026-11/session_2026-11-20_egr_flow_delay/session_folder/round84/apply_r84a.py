"""Round 84 stage A (CM550): the boot block image. Idempotent; keeps line endings. usage: apply_r84a.py <repo> <map.csv>
- ROM 0x291F4-0x2CE63 is byte-for-byte ROM 0x0-0x3C6F (15472 bytes): the boot block image. cm550_FUN_0002ce64 (right
  after it) reprograms the boot block from it. When the boot block's version word (ROM 0x16) is non-zero and the key is
  0xbad1 with an older running version, or 0x1d1d with a different version, it erases the sector and copies 0x291F4 up
  to its own address through a 256-byte RAM buffer into flash at address 0 (cm550_flashProgramFromRam).
- The nine functions Ghidra found inside the image are copies of the boot block's (address - 0x291F4); their PC-relative
  references show the original's 0x8000 / 0x8062 / 0x80339E as 0x311F4 / 0x31256 / 0x82C592. Each gets its
  original's name + ImageCopy.
- cm550_FUN_0000395a services both watchdogs and then waits until bit 0 of the chip select 2 device's register 0
  (0xFFD000) reads 1 in 5 consecutive samples."""
import os
import sys

repo, map5 = os.path.abspath(sys.argv[1]), sys.argv[2]
O5 = os.path.join(repo, "firmware/CM550_J90350.00_analysis/output")
R = "PR #53 round 84"
F5, G5, D5 = (os.path.join(O5, n) for n in ("function_renames.csv", "global_variables.csv", "function_definitions.csv"))
COPY = "A copy inside boot_block_image (byte-for-byte ROM 0x0-0x3C6F at 0x291F4) of {orig} at {oaddr}: data that " \
       "cm550_updateBootBlockFromImage programs into the boot block - not code run here. Its PC-relative references " \
       "show the original's addresses + 0x291F4"
RENAMES = [
    ("0x0002ce64", "cm550_FUN_0002ce64", "cm550_updateBootBlockFromImage",
     "Reprograms the boot block from boot_block_image: when boot_block_version (ROM 0x16) is non-zero and "
     "_this_key_must_be_set_to_bad1_before_boot_block_is_programmed_none is 0xbad1 with boot_block_version below "
     "boot_block_image_version - or 0x1d1d with a different version - it sets the boot block programming enable flag "
     "bit 2 - erases (cm550_FUN_0001c484(0 / 1)) - and copies 0x291F4 up to this function's address through a 256-byte RAM "
     "buffer into flash at address 0 with cm550_flashProgramFromRam"),
    ("0x0000395a", "cm550_FUN_0000395a", "cm550_waitForChipSelect2InputBit0High",
     "Services both watchdogs (SIM_SWSR / CS2_WATCHDOG_SERVICE) and then waits until bit 0 of the chip select 2 device's "
     "register 0 (0xFFD000) reads 1 in 5 consecutive samples (cm550_busyWaitDelayLoop between them) - the same pattern "
     "as CM848's cm848_waitForStableIgnitionKeyOn; the signal is not identified"),
]
for caddr, cname, oaddr, oname in (
        ("0x0002c834", "cm550_FUN_0002c834", "0x00003640", "cm550_huffmanTreeBuilder"),
        ("0x0002c986", "cm550_FUN_0002c986", "0x00003792", "cm550_huffmanDecompress"),
        ("0x0002ca2a", "cm550_FUN_0002ca2a", "0x00003836", "cm550_huffmanDecompressMain"),
        ("0x0002ca64", "cm550_FUN_0002ca64", "0x00003870", "cm550_busyWaitDelayLoop"),
        ("0x0002ca7e", "mc68k_FUN_0002ca7e", "0x0000388a", "mc68k_portPinTestSequence2"),
        ("0x0002cb4e", "cm550_FUN_0002cb4e", "0x0000395a", "cm550_waitForChipSelect2InputBit0High"),
        ("0x0002cb9c", "mc68k_FUN_0002cb9c", "0x000039a8", "mc68k_checkSerialEepromSignature"),
        ("0x0002cc88", "mc68k_FUN_0002cc88", "0x00003a94", "mc68k_hardwareInitAndStartup"),
        ("0x0002ce14", "cm550_FUN_0002ce14", "0x00003c20", "cm550_ramClearWithWatchdog")):
    RENAMES.append((caddr, cname, oname + "ImageCopy", COPY.format(orig=oname, oaddr=oaddr)))
s = open(F5, newline="").read()
for address, old, new, plate in RENAMES:
    if f"{address},{new}," in s:
        continue
    line = f"{address},{old}\n"
    assert s.count(line) == 1, (address, s.count(line))
    s = s.replace(line, f"{address},{new},{plate} (was {old}; {R})\n")
open(F5, "w", newline="").write(s)
d = open(D5, newline="").read()
old = "0x0002ca64,busyWaitDelayLoop,0,"
if old in d:
    d = d.replace(old, "0x0002ca64,cm550_busyWaitDelayLoopImageCopy,0,")
    open(D5, "w", newline="").write(d)
ROWS = [
    ("0x00000016", "0x00000016,boot_block_version,word,The boot block's version word: cm550_updateBootBlockFromImage "
     f"reprograms the boot block when it is non-zero and below (key 0xbad1) or not equal to (key 0x1d1d) "
     f"boot_block_image_version ({R})"),
    ("0x000291f4", "0x000291f4,boot_block_image,,A byte-for-byte copy of the boot block ROM 0x0-0x3C6F (15472 bytes, to "
     "0x2CE63): cm550_updateBootBlockFromImage programs it into flash at address 0. The nine functions Ghidra finds "
     f"inside are named <original>ImageCopy ({R})"),
    ("0x0002920a", "0x0002920a,boot_block_image_version,word,The boot block image's version word (boot_block_image + "
     f"0x16 - the image's copy of boot_block_version) ({R})"),
]
g = open(G5, newline="").read()
lines = g.split("\n")
for address, row in ROWS:
    if any(l.startswith(address + ",") for l in lines):
        continue
    for i, l in enumerate(lines):
        if l.startswith("0x") and int(l.split(",")[0], 16) > int(address, 16):
            lines.insert(i, row)
            break
open(G5, "w", newline="").write("\n".join(lines))
with open(map5, "w") as fh:
    fh.write("address,name,old_label,kind,dims\n")
    for address, old, new, _ in RENAMES:
        fh.write(f"{address},{new},{old},function,1\n")
print("round 84 stage A applied")

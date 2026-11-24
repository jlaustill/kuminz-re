"""Round 88 stage C docs: the dump chunk-skip bug and the existing dumps it shifted. Idempotent.
usage: apply_r88c_docs.py <repo>
- CM550 README.md / docs/memory_map.md: J90350.00.extended_ram.bin is 0x80 bytes short; from 0x8092C2 on each
  value sits at file offset address - 0x809242 (round 87: of 100 init-time constant stores, 40 match only at
  address - 0x80 and none only at the address); the skipped chunk was the first or the second (0x8091C2 / 0x809242),
  so 0x8091C2-0x8092C1 is uncertain; SetupMemoryMap.java still loads the file at 0x8091C2.
- firmware/CLAUDE.md: the cause of CM848's 0x40c200 gap (one factual sentence added to the existing bullet)."""
import os
import sys

repo = os.path.abspath(sys.argv[1])
R = "PR #53 round 88"


def edit(rel, old, new):
    p = os.path.join(repo, rel)
    t = open(p, newline="").read()
    if "\r\n" in t:
        old, new = old.replace("\n", "\r\n"), new.replace("\n", "\r\n")
    if new in t:
        return
    assert t.count(old) == 1, (rel, old[:60], t.count(old))
    open(p, "w", newline="").write(t.replace(old, new))


NOTE = ("**The extended RAM dump is 0x80 bytes short.** `J90350.00.extended_ram.bin` (0x6DBE bytes) was read in 128-byte "
        "chunks from 0x8091C2, and the dump tool skipped one failed chunk - the first (0x8091C2) or the second "
        "(0x809242) - without padding. So from 0x8092C2 on, each value sits at file offset address - 0x809242 "
        "(address - 0x80 from the region start): of 100 init-time constant stores, 40 match the dump only at address "
        "- 0x80 and none only at the address (PR #53 round 87). 0x8091C2-0x8092C1 is uncertain. clip-core's "
        "`ECUReader` pads a failed chunk with 0xFF and lists it in `<dump>.gaps.txt` since PR #53 round 88, so new "
        "dumps stay aligned. `SetupMemoryMap.java` still loads this file at 0x8091C2.")
README = "firmware/CM550_J90350.00_analysis/README.md"
edit(README, "| EXT_RAM | 0x8091C2-0x80FF7F | 28KB | rwx | Extracted |\n",
     "| EXT_RAM | 0x8091C2-0x80FFFF | 28KB | rwx | Extracted, 0x80 bytes short (below) |\n")
edit(README, "| MC68336 Peripherals | 0xFFD000-0xFFFFFF | 12KB | - | Hardware registers (not extractable) |\n",
     "| MC68336 Peripherals | 0xFFD000-0xFFFFFF | 12KB | - | Hardware registers (not extractable) |\n\n" + NOTE + "\n")
MAP = "firmware/CM550_J90350.00_analysis/docs/memory_map.md"
edit(MAP, "| **EXT_RAM** | 0x8091C2-0x80FF7F | 28KB | Extracted | Scheduler, J1708, diagnostics |\n",
     "| **EXT_RAM** | 0x8091C2-0x80FFFF | 28KB | Extracted (0x80 bytes short, see EXT_RAM below) | Scheduler, J1708, "
     "diagnostics |\n")
edit(MAP, "### EXT_RAM (0x8091C2-0x80FF7F)\n", "### EXT_RAM (0x8091C2-0x80FFFF)\n\n" + NOTE + "\n\n")
edit("firmware/CLAUDE.md",
     "    - The proof: the collector end pointer 0x40c28a, then 0 and the table address 0x3fddc4, sit at dump 0x40c200, and\n"
     "      the file is exactly 0x80 short of 0x440000.\n",
     "    - The proof: the collector end pointer 0x40c28a, then 0 and the table address 0x3fddc4, sit at dump 0x40c200, and\n"
     "      the file is exactly 0x80 short of 0x440000.\n"
     "    - The cause: clip-core's `ECUReader::readMemoryService4ALarge` skipped a failed 128-byte chunk without padding.\n"
     f"      Since {R} it pads the chunk with 0xFF and lists it in `<dump>.gaps.txt` (`readInChunks`, with unit tests).\n"
     "      CM550's extended RAM dump has the same 0x80 shift (its README).\n")
print("stage C docs applied")

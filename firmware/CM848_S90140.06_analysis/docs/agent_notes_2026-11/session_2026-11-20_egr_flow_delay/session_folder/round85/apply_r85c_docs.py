"""Round 85 stage C (docs, from an advisor review of the closing). Idempotent.
usage: apply_r85c_docs.py <repo> <pr_body.md>
- The stage A split was misstated as 11 mc68k_ / 12 cm550_. The 23 new names are 14 mc68k_ and 9 cm550_; 12 is the number
  of proposals kept off mc68k_ (8 renamed with cm550_, 4 left as they were).
- The survey's class Z names two more fragment records and 10 call targets with no function: task 046 leads.
- Comments that still name the renamed J1708 dispatcher (CM550 enums.csv section headers, the CLIP protocol spec).
- CLAUDE.md's relocation map section: only CM550 has a map, and it is the historical J90280.05 -> J90350.00 one."""
import os
import sys

repo, pr = os.path.abspath(sys.argv[1]), sys.argv[2]


def edit(p, old, new):
    p = p if os.path.isabs(p) else os.path.join(repo, p)
    t = open(p, newline="").read()
    if "\r\n" in t:
        old, new = old.replace("\n", "\r\n"), new.replace("\n", "\r\n")
    if new in t:
        return
    assert t.count(old) == 1, (p, old[:60], t.count(old))
    open(p, "w", newline="").write(t.replace(old, new))


T46 = "work/tasks/046-cm848-egr-flow-estimate.md"
edit(T46, "  - **23 renames, 11 `mc68k_` and 12 `cm550_`**, for example:",
     "  - **23 renames, 14 `mc68k_` and 9 `cm550_`** (12 proposals were kept off `mc68k_`: 8 renamed with `cm550_`, 4 left\n"
     "    as they were; the closing first misstated this as 11 / 12), for example:")
edit(T46, "  - **Unreliable renders:** the .cpp drops blocks in `mc68k_flashEraseBlock` and `cm550_flashProgramAndVerifyWords`;\n"
          "    read the ROM.\n",
     "  - **Unreliable renders:** the .cpp drops blocks in `mc68k_flashEraseBlock` and `cm550_flashProgramAndVerifyWords`;\n"
     "    read the ROM.\n"
     "  - **More spurious records (the survey's class Z):** 0xFBE4 is a fragment of 0xFB26, and 0x1B4C2 an interrupt\n"
     "    epilogue fragment entered from 0x1B4B2. 10 call targets have no function in the .cpp.\n"
     "  - **Round 86:** the stack argument fix (the research reports are `session_folder/round85/research_*.txt`). Re-derive the design's\n"
     "    wave-0 rows and its counts (89 functions, 72 / 79 lines) from the current .cpp first.\n")
edit(pr, "  (11 take `mc68k_`; the watchdog-only ones stay `cm550_` under commit 16143a5c), and 9 spurious function records\n",
     "  (14 take `mc68k_`; the 9 watchdog-only ones stay `cm550_` under commit 16143a5c), and 9 spurious function records\n")
E5 = "firmware/CM550_J90350.00_analysis/output/enums.csv"
WAS = "mc68k_dispatchJ1708ReceivedMessages (0x15F8E; 0x12484 in J90280.05; was diagnosticCommandDispatcher)"
edit(E5, "case 4 in diagnosticCommandDispatcher", "case 4 in " + WAS)
edit(E5, "(diagnosticCommandDispatcher @ 0x12484)", "(" + WAS + ")")
edit(E5, "(Secured Commands - diagnosticCommandDispatcher switch @ 0x125a6)",
     "(Secured Commands - the J1708 dispatcher's switch: 0x125a6 in J90280.05)")
edit(E5, "(System Control - diagnosticCommandDispatcher switch @ 0x12690)",
     "(System Control - the J1708 dispatcher's switch: 0x12690 in J90280.05)")
edit("work/docs/clip-protocol-spec.md", "From reverse engineering `diagnosticCommandDispatcher` at 0x00012484:\n",
     "From reverse engineering `diagnosticCommandDispatcher` at 0x00012484:\n\n"
     "> **Note (2026-11-24, PR #53 round 85):** 0x00012484 is this function's address in J90280.05, a removed dump. In\n"
     "> J90350.00 it is `mc68k_dispatchJ1708ReceivedMessages` at 0x00015F8E: it drains the J1708 receive buffer and picks the\n"
     "> handler from the first message byte.\n")
edit("CLAUDE.md",
     "Each firmware analysis directory contains `output/relocation_map.csv` mapping function addresses between firmware versions:\n",
     "Only CM550 has one: `firmware/CM550_J90350.00_analysis/output/relocation_map.csv` maps function addresses from the\n"
     "historical J90280.05 dump (removed) to J90350.00 (see that firmware's `docs/comparison_report.md`). It is not a\n"
     "CM550 -> CM848 map, and CM848 has none:\n")
edit("CLAUDE.md",
     "Relocation maps are per-firmware in `output/relocation_map.csv`. Currently only CM550 J90350.00 and CM848 S90140.06 are active.\n",
     "Cross-firmware twins share one name in both firmwares' `function_renames.csv`. `firmware/cross_firmware_matches.csv`\n"
     "lists scored match candidates (CM550 -> CM848, action `review`); check each one, since not every row is a twin.\n")
print("round 85 stage C applied")

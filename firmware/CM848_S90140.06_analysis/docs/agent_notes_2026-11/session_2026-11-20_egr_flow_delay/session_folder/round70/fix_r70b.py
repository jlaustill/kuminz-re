"""Round 70 follow-up (the advisor's closing review): the dual-port TPU RAM from the MPC5xx memory map. Idempotent.
NXP's 'Motorola MPC5xx Memory Maps' (Revision C, March 2003) lists for the MPC555: DPTRAM Control 0x300000-0x30003f,
DPTRAM (6 Kbytes) 0x302000-0x3037ff, TPU3_A 0x304000, TPU3_B 0x304400, USIU Control 0x2fc000-0x2fc7ff. The MPC555
user's manual (as excerpted by a web search) puts RAMBAR at 0x300004 and requires 0xffa0 in it; TPUMCR's EMU bit runs
a TPU's microcode from the DPTRAM and takes the RAM away from the CPU.
- 0x300004 usiu_ext_004 -> DPTRAM_RAMBAR (word: it rendered _usiu_ext_004 = 0xffa0, too narrow).
- mpc555_registers.csv: the TPU3 register map it put at 0x302000 (29 rows, applied by the build's
  ApplyMPC555Registers.java) goes; its TPUA / TPUB headers say TPU3_A / TPU3_B, not the 'second' / 'third' instance.
- The comments that said 'by that use' / 'the only 6 KB RAM' cite the map, and mpc555_initTpuConfiguration's plate
  names EMU.
- cm848_writeBootKernelCanTxMailbox's frame parameter is typed boot_can_transmit_frame_t * (the 12 bytes it copies
  into a mailbox: its callers pass the push's local frame and a ring entry).
usage: fix_r70b.py <repo> <map.csv>"""
import os
import sys

repo, map_path = os.path.abspath(sys.argv[1]), sys.argv[2]
O = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")
R = "PR #53 round 70"
MAP = "the MPC5xx memory map (NXP rev C 2003)"


def edit(name, old, new):
    p = os.path.join(O, name)
    s = open(p).read()
    if new in s:
        return
    assert s.count(old) == 1, (name, old[:90], s.count(old))
    open(p, "w").write(s.replace(old, new))


# ---- mpc555_registers.csv ----------------------------------------------------------------------------------------------
REG = "mpc555_registers.csv"
p = os.path.join(O, REG)
lines = open(p).read().split("\n")
BLOCK = [
    "# =============================================================================",
    f"# DPTRAM - the dual-port TPU RAM: control 0x300000-0x30003f / 6 Kbyte array 0x302000-0x3037ff ({MAP}) ({R})",
    "# The boot kernel keeps its RAM variables in the array and the application loads TPU microcode into it, so they",
    "# are named in global_variables.csv (DPTRAM_RAMBAR / dual_port_tpu_ram_* / boot_can_*_ring). This block used to",
    "# be a TPU3 register map at 0x302000 - the TPU3 registers are TPU3_A 0x304000 / TPU3_B 0x304400 below.",
    "# =============================================================================",
]
if BLOCK[1] not in lines:
    i = lines.index("# TPU3 - Time Processing Unit 3 (0x302000 - 0x303FFF)")
    j = [n for n, l in enumerate(lines) if l.startswith("0x003021f0,TPU3_CH15_PARAM0,")][0]
    start = i - 1
    assert lines[start].startswith("# ===="), lines[start]
    gone = [l for l in lines[start:j + 1] if l.startswith("0x")]
    assert all(l.split(",")[1].startswith("TPU3_") for l in gone), gone
    assert len(gone) == 29, len(gone)  # TPUMCR + 12 control registers + 16 channel parameter words
    lines[start:j + 1] = BLOCK
    open(p, "w").write("\n".join(lines))
edit(REG, "# Second TPU3 instance used for crank/cam timing (mpc555_initTpuConfiguration)",
     f"# TPU3_A in {MAP} - crank/cam timing (mpc555_initTpuConfiguration) ({R}: was 'Second TPU3 instance')")
edit(REG, "# Third TPU3 instance; mpc555_tpuBInterruptDispatcher handles its channels",
     f"# TPU3_B in {MAP} - mpc555_tpuBInterruptDispatcher handles its channels ({R}: was 'Third TPU3 instance')")

# ---- global_variables.csv ----------------------------------------------------------------------------------------------
G = "global_variables.csv"
edit(G, "0x00300004,usiu_ext_004,,",
     "0x00300004,DPTRAM_RAMBAR,word,The dual-port TPU RAM's base address register in its control block 0x300000-0x30003f "
     f"({MAP}): mpc555_reset_vector / mpc555_initSystemRegisters / cm848_initClockAndTimers write 0xffa0 - the value the "
     "MPC555 user's manual requires (was usiu_ext_004: the USIU block is 0x2fc000-0x2fc7ff; it rendered _usiu_ext_004 "
     f"untyped; {R})")
edit(G, "The 6 KB RAM 0x302000-0x3037ff that cm848_clearRamRegions clears: the MPC555's only 6 KB RAM - the dual-port "
        "TPU RAM (its SRAM is 0x3f9800 on).",
     "The 6 KB RAM 0x302000-0x3037ff that cm848_clearRamRegions clears: the dual-port TPU RAM - 'DPTRAM (6 Kbytes)' "
     f"0x302000-0x3037ff in {MAP}.")
edit(G, "before it sets both TPU module configuration registers - TPU microcode by that use.",
     "before it sets both TPU module configuration registers with bit 0x400 (EMU) - TPU microcode: in emulation mode a "
     "TPU runs its microcode from this RAM and the CPU loses access to it - so the load comes first (MPC555 user's "
     "manual; the bit position is from the TPU3 register layout).")
# ---- function_renames.csv ----------------------------------------------------------------------------------------------
edit("function_renames.csv",
     "0x00055c1c,mpc555_initTpuConfiguration,Unless TPU B's TPUMCR has bit 0x400 set: copies "
     "dual_port_tpu_ram_load_table's records into the dual-port TPU RAM (0x302000-0x302fff) / then sets both TPU module "
     "configuration registers (0x4430 B / 0x4460 A) and their interrupt registers",
     "0x00055c1c,mpc555_initTpuConfiguration,Unless TPU B is already in emulation mode (TPUMCR bit 0x400 - EMU): copies "
     "dual_port_tpu_ram_load_table's records - the TPU microcode - into the dual-port TPU RAM (0x302000-0x302fff) while "
     "the CPU can still write it / then sets both TPU module configuration registers with EMU (0x4430 B / 0x4460 A) so "
     "both TPUs run it / and their interrupt registers")
# ---- function_definitions.csv: the mailbox writer's frame --------------------------------------------------------------
edit("function_definitions.csv",
     "0x00004f2c,cm848_writeBootKernelCanTxMailbox,2,frame_words,word*,The frame: identifier high / low and data bytes "
     "0-7 (6 halfwords)",
     "0x00004f2c,cm848_writeBootKernelCanTxMailbox,2,frame,boot_can_transmit_frame_t*,The frame (was word * frame_words: "
     f"identifier high / low and data bytes 0-7 - 6 halfwords; {R})")
with open(map_path, "w") as fh:
    fh.write("address,name,old_label,kind,dims\n0x00300004,DPTRAM_RAMBAR,usiu_ext_004,global,1\n")
print("follow-up applied")

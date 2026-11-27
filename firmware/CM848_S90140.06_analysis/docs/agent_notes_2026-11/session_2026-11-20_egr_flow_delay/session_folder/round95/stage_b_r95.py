"""Round 95 stage B (CM848): the MPC555 register blocks, checked against the MPC555 User's Manual (NXP MPC555UM;
Appendix A internal memory map, 13.12 QADC64, 15.10-15.11 MIOS1, 17 TPU3).
1. SCRD -> SCR text pass: every current-state 'SCRD' means the +6 MIOS register, which the manual calls SCR (SCRD is
   the duplicate address at +4: 'The MDASMSCRD and the MDASMSCR are the same registers accessed at two different
   addresses', 15.11.1.3 / 15.10.1.3). History files (work/tasks, todo.md, agent notes, session folders) keep theirs.
2. structure_definitions.csv: mios_mdasm_t XR -> SCRD, mios_mmcsm_b_t _pad -> SCRD; qadc64_regs_t CCW / RJURR /
   LJSRR / LJURR -> QACR0 / QACR1 / QACR2 / QASR0 (the CCW table and the result areas are at +0x200 / +0x280 /
   +0x300 / +0x380); TPU3: one type tpu3_module_registers_t for both modules (_pad1-6 / R028 / R02A -> TCR / DSCR /
   DSSR / LR / SGLR / DCNR / TPUMCR2 / TPUMCR3); qadc64b_regs_t / tpub_module_regs_t become marker rows.
3. global_variables.csv: instances named for their block, not their first register; the wrong register names
   (USIU_INITCFG = SGPIOCR, USIU_SGPIODT1 = EMCR, USIU_EMCR = PDMCR, qsmcm_sccr0 = QDSCI_IL, mios1_ext_816 = MCPSMSCR,
   mios1_sched_ctrl = MIOS1LVL0, QADC64x_RESULTn = the CCW table); the named rows inside typed spans are removed
   (the register stage now skips typed data, so they guard nothing; 0x3fee36's documented alias stays).
4. mpc555_registers.csv: the names the manual contradicts.
Writes the CM848 map for the proofs and the refresh. Line-ending aware; asserts each edit.
usage: stage_b_r95.py <repo> <map out>"""
import csv
import io
import os
import re
import sys

repo, map_path = os.path.abspath(sys.argv[1]), sys.argv[2]
OUT = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")
R = "PR #53 round 95"


def load(path):
    text = open(path, newline="").read()
    return text, ("\r\n" if "\r\n" in text else "\n")


def save(path, text):
    open(path, "w", newline="").write(text)


# 1. SCRD -> SCR over the current-state files
current = [os.path.join(OUT, f) for f in ("global_variables.csv", "function_renames.csv", "structure_definitions.csv",
                                           "enums.csv", "local_variables.csv", "function_definitions.csv")]
current += [os.path.join(repo, "firmware/CM848_S90140.06_analysis/docs", f)
            for f in os.listdir(os.path.join(repo, "firmware/CM848_S90140.06_analysis/docs")) if f.endswith(".md")]
current.append(os.path.join(repo, "firmware/CLAUDE.md"))
scrd_count = 0
for p in current:
    t, _ = load(p)
    n = len(re.findall(r"\bSCRD\b", t))
    if n:
        save(p, re.sub(r"\bSCRD\b", "SCR", t))
        scrd_count += n
        print(f"SCRD -> SCR: {os.path.relpath(p, repo)} {n}")

# 2. structure_definitions.csv
p = os.path.join(OUT, "structure_definitions.csv")
t, E = load(p)
lines = t.split(E)


def replace_row(prefix, new):
    idx = [i for i, l in enumerate(lines) if l.startswith(prefix)]
    assert len(idx) == 1, (prefix, len(idx))
    lines[idx[0]] = new


MANUAL = "MPC555UM"
replace_row("mios_mdasm_t,0x00306058,XR,",
            f"mios_mdasm_t,0x00306058,SCRD,word,2,Status/Control Register Duplicated: the same register as SCR at a "
            f"second address ({MANUAL} 15.11.1.3; the manual says not to write it); no code here accesses it (was XR; "
            f"{R}),,verified")
replace_row("mios_mdasm_t,0x00306058,SCR,",
            f"mios_mdasm_t,0x00306058,SCR,word,2,Status/Control Register (mode bits: 0x9 = output PWM / 1 = input; "
            f"bit 15 = the pin state) (was SCRD; {MANUAL}: SCRD is the +4 duplicate; {R}),,verified")
replace_row("mios_mmcsm_b_t,0x00306030,_pad,",
            f"mios_mmcsm_b_t,0x00306030,SCRD,word,2,Status/Control Register Duplicated: the same register as SCR "
            f"({MANUAL} 15.10.1.3); not accessed here (was _pad; {R}),,verified")
replace_row("mios_mmcsm_b_t,0x00306030,SCR,",
            f"mios_mmcsm_b_t,0x00306030,SCR,word,2,Status/Control Register (was SCRD; {MANUAL}: SCRD is the +4 "
            f"duplicate; {R}),,verified")
QADC = {"CCW": ("QACR0", "QADC64 Control Register 0: the QCLK prescaler fields and external multiplexing (written once "
                         "at initialization)"),
        "RJURR": ("QACR1", "QADC64 Control Register 1: queue 1's completion / pause interrupt enables and operating mode"),
        "LJSRR": ("QACR2", "QADC64 Control Register 2: queue 2's interrupt enables, operating mode and resume pointer"),
        "LJURR": ("QASR0", "QADC64 Status Register 0: the CF1 / PF1 / CF2 / PF2 queue flags, trigger overruns, queue "
                           "status and the command word pointer")}
for old, (new, comment) in QADC.items():
    replace_row(f"qadc64_regs_t,0x00304800,{old},",
                f"qadc64_regs_t,0x00304800,{new},word,2,{comment} ({MANUAL} 13.12; was {old}: the CCW table is at "
                f"+0x200 and the result registers at +0x280 / +0x300 / +0x380; {R}),,verified")
TPU = {"_pad1": ("TCR", "Test Configuration Register (test mode only)"),
       "_pad2": ("DSCR", "Development Support Control Register"),
       "_pad3": ("DSSR", "Development Support Status Register"),
       "_pad4": ("LR", "Link Register (test)"),
       "_pad5": ("SGLR", "Service Grant Latch Register (test)"),
       "_pad6": ("DCNR", "Decoded Channel Number Register (test)"),
       "R028": ("TPUMCR2", "TPU Module Configuration Register 2 (initialization writes 0x80 / 0x20 / 0)"),
       "R02A": ("TPUMCR3", "TPU Module Configuration Register 3 (initialization writes 0 on TPU-A / 0x1E on TPU-B)")}
out_lines = []
tpub_marker_done = qadc_b_marker_done = False
for l in lines:
    if l.startswith("tpub_module_regs_t,") or l.startswith("qadc64b_regs_t,"):
        continue                                        # the B module types collapse into the shared types
    if l.startswith("tpua_module_regs_t,"):
        parts = next(csv.reader(io.StringIO(l)))
        if parts[2] in TPU:
            new, comment = TPU[parts[2]]
            l = (f"tpu3_module_registers_t,0x00304000,{new},word,2,{comment} ({MANUAL} Table A-7; was {parts[2]}; "
                 f"{R}),,verified")
        elif parts[2] == "TPUMCR":
            l = ("tpu3_module_registers_t,0x00304000,TPUMCR,word,2,TPU3 Module Configuration Register (0x8000 = STOP; "
                 "initialization writes 0x4460 on TPU-A and 0x4430 on TPU-B),,verified")
        elif parts[2] == "TICR":
            l = ("tpu3_module_registers_t,0x00304000,TICR,word,2,TPU3 Interrupt Configuration Register "
                 "(initialization writes 0x100 on TPU-A and 0x200 on TPU-B),,verified")
        else:
            l = "tpu3_module_registers_t" + l[len("tpua_module_regs_t"):]
        out_lines.append(l)
        if parts[2] == "R02A":
            out_lines.append(f"tpu3_module_registers_t,0x00304400,,,,TPU-B module registers - marker only (was the "
                             f"separate type tpub_module_regs_t; {R}),,verified")
            tpub_marker_done = True
        continue
    out_lines.append(l)
    if l.startswith("qadc64_regs_t,0x00304800,QASR0,"):
        out_lines.append(f"qadc64_regs_t,0x00304c00,,,,QADC64 module B registers - marker only (was the separate type "
                         f"qadc64b_regs_t; {R}),,verified")
        qadc_b_marker_done = True
assert tpub_marker_done and qadc_b_marker_done
lines = out_lines
HEADERS = [
    ("# TPUA Module Register Block - Time Processing Unit A control registers",
     "# TPU3 module registers - tpu3_module_registers_t, one type for TPU-A (0x304000) and TPU-B (0x304400 marker row)"),
    ("# Applied at 0x304000 (IMB3 base + 0x4000) — crank timing TPU module",
     f"# Register names and offsets from the MPC555 User's Manual Table A-7 ({R}; the TPU-B type was a copy)"),
    ("# Register offsets match TPU3 at 0x302000; confirmed by mpc555_initTpuConfiguration",
     "# mpc555_initTpuConfiguration writes TPUMCR / TICR / TPUMCR2 / TPUMCR3 for both modules"),
    ("# QADC64 Peripheral Struct - Queued ADC module register layout",
     "# QADC64 module registers - qadc64_regs_t, one type for QADC64 A (0x304800) and B (0x304c00 marker row)"),
    ("# Functions: mpc555_initQadcRegisters writes CCW/result registers directly",
     f"# Fields from the MPC555 User's Manual 13.12 ({R}): +0xA-0x10 are QACR0-2 / QASR0, not the CCW / result tables"),
    ("# MMCSM  = Modulus Counter Submodule (CNT/ML/_pad/SCR) - MMCSM6 at +0x30 and MMCSM22 at +0xB0 (marker row)",
     "# MMCSM  = Modulus Counter Submodule (CNT/ML/SCRD/SCR) - MMCSM6 at +0x30 and MMCSM22 at +0xB0 (marker row)"),
    ("# MDASM  = Double Action Submodule (AR/BR/XR/SCR) - MDASM12 / MDASM15 here; MDASM11 and 28-31 use mios_mdasm_t",
     "# MDASM  = Double Action Submodule (AR/BR/SCRD/SCR) - MDASM12 / MDASM15 here; MDASM11 and 28-31 use mios_mdasm_t"),
    ("# Same 8-byte layout as mios_mdasm_t (AR, BR, XR, SCR)", "# Same 8-byte layout as mios_mdasm_t (AR, BR, SCRD, SCR)"),
    ("# MMCSM6 = mios_mmcsm_cnt at 0x306030", "# MMCSM6 = mios_mmcsm6 at 0x306030"),
]
for old, new in HEADERS:
    idx = [i for i, l in enumerate(lines) if l.startswith(old)]
    assert len(idx) == 1, (old, len(idx))
    lines[idx[0]] = new + lines[idx[0]][len(old):]
# drop the QADC64B / TPUB type headers (their comment blocks described the separate copies)
for block_start in ("# QADC64B Peripheral Struct - second QADC module at 0x304C00",
                    "# TPUB Module Register Block - Time Processing Unit B control registers"):
    i = next(i for i, l in enumerate(lines) if l.startswith(block_start))
    j = i
    while lines[j + 1].startswith("#") and not lines[j + 1].startswith("# ====="):
        j += 1
    assert lines[i - 1].startswith("# =====") and lines[j + 1].startswith("# =====")
    del lines[i - 1:j + 2]
save(p, E.join(lines))
print("structure_definitions.csv: done")

# 3. global_variables.csv
p = os.path.join(OUT, "global_variables.csv")
t, E = load(p)
lines = t.split(E)
RENAMES = [  # address, old, new, new type or None, comment or None (None keeps the comment)
    ("0x002fc02c", "USIU_INITCFG", "USIU_SGPIOCR", None, "SIU SGPIO control register (0x2FC02C SGPIOCR)"),
    ("0x002fc030", "USIU_SGPIODT1", "USIU_EMCR", None, "External master mode control register (0x2FC030 EMCR; SGPIODT1 is SIU_SGPIODT1 at 0x2FC024)"),
    ("0x002fc03c", "USIU_EMCR", "USIU_PDMCR", None, "Pads module configuration register (0x2FC03C PDMCR)"),
    ("0x002fc100", "USIU_BR0", "usiu_memory_controller", None, "USIU memory controller: the base / option register pairs BR0-OR3 (0x2FC100-0x2FC11F)"),
    ("0x002fc240", "USIU_PISCR", "usiu_periodic_interrupt_timer", None, "USIU periodic interrupt timer: PISCR / PITC / PITR (0x2FC240-0x2FC24B)"),
    ("0x002fc280", "USIU_SCCR", "usiu_clocks_and_reset", None, "USIU clocks and reset: SCCR / PLPRCR / RSR / COLIR / VSRMCR (0x2FC280-0x2FC293)"),
    ("0x00304000", "tpu_a_mcr", "tpu_a", "tpu3_module_registers_t", "TPU3 module A registers (0x304000-0x30402B)"),
    ("0x00304400", "tpu_b_mcr", "tpu_b", "tpu3_module_registers_t", "TPU3 module B registers (0x304400-0x30442B)"),
    ("0x00304100", "tpu_a_ch0_param0", "tpu_a_channel_0_parameters", None, "TPU-A channel 0 parameter RAM (0x304100-0x30410F)"),
    ("0x00304110", "tpu_a_ch1_param2", "tpu_a_channel_1_parameters", None, "TPU-A channel 1 parameter RAM (0x304110-0x30411F; the old name said parameter 2, the block starts at parameter 0)"),
    ("0x00304190", "tpu_channel_control", "tpu_a_channel_9_parameters", None, "TPU-A channel 9 parameter RAM (0x304190-0x30419F)"),
    ("0x003041c0", "TPUA_CH12_PARAM0", "tpu_a_channel_12_parameters", None, "TPU-A channel 12 parameter RAM (0x3041C0-0x3041CF)"),
    ("0x003041e0", "TPUA_CH14_PARAM0", "tpu_a_channel_14_parameters", None, "TPU-A channel 14 parameter RAM (0x3041E0-0x3041EF)"),
    ("0x00304500", "tpu_b_ch0_param0", "tpu_b_channel_0_parameters", None, None),
    ("0x003045b0", "TPUB_CH11_PARAM0", "tpu_b_channel_11_parameters", None, "TPU-B channel 11 parameter RAM (0x3045B0-0x3045BF)"),
    ("0x003045e0", "TPUB_CH14_PARAM0", "tpu_b_channel_14_parameters", None, "TPU-B channel 14 parameter RAM (0x3045E0-0x3045EF)"),
    ("0x00304800", "QADC64A_MCR", "qadc64_a", None, "QADC64 module A registers (0x304800-0x304811); its CCW table is at 0x304A00 and its result registers at 0x304A80 / 0x304B00 / 0x304B80 (was qadc_b_mcr before PR #48)"),
    ("0x00304c00", "QADC64B_MCR", "qadc64_b", "qadc64_regs_t", "QADC64 module B registers (0x304C00-0x304C11); its CCW table is at 0x304E00 and its result registers at 0x304E80 / 0x304F00 / 0x304F80"),
    ("0x00305004", "qsmcm_sccr0", "QSMCM_QDSCI_IL", None, "QSMCM dual SCI interrupt level register (0x305004 QDSCI_IL; the byte access is its high byte)"),
    ("0x00305008", "qsmcm_sccr1", "qsmcm_sci1", None, "QSMCM SCI1 registers SCC1R0 / SCC1R1 / SC1SR / SC1DR (0x305008-0x30500F)"),
    ("0x00306030", "mios_mmcsm_cnt", "mios_mmcsm6", None, "MIOS1 submodule 6, modulus counter MMCSM6 (CNT / ML / SCRD / SCR): the boot time base"),
    ("0x00306816", "mios1_ext_816", "MIOS_MCPSMSCR", None, "MIOS1 counter prescaler submodule status/control register (0x306816 MCPSMSCR); the reset code writes 0x8000 = prescaler enable"),
    ("0x00306c30", "mios1_sched_ctrl", "MIOS1LVL0", None, "MIOS1 interrupt level register 0 (0x306C30 MIOS1LVL0)"),
]
for n in range(12):
    RENAMES.append((f"0x{0x304a00 + 2 * n:08x}", f"QADC64A_RESULT{n}", f"QADC64A_CCW{n}", "word",
                    f"QADC64 A conversion command word {n} (CCW table 0x304A00-0x304A7F); the result registers are at 0x304A80 / 0x304B00 / 0x304B80"))
for n in range(4):
    RENAMES.append((f"0x{0x304e00 + 2 * n:08x}", f"QADC64B_RESULT{n}", f"QADC64B_CCW{n}", "word",
                    f"QADC64 B conversion command word {n} (CCW table 0x304E00-0x304E7F); the result registers are at 0x304E80 / 0x304F00 / 0x304F80"))
mapping = []
for address, old, new, new_type, comment in RENAMES:
    idx = [i for i, l in enumerate(lines) if l.lower().startswith(address + ",")]
    assert len(idx) == 1, (address, len(idx))
    parts = lines[idx[0]].split(",", 3)
    assert parts[1] == old, (address, parts[1], old)
    typ = new_type or parts[2]
    old_comment = parts[3] if len(parts) > 3 else ""
    if comment is None:
        text = old_comment + (" " if old_comment else "") + f"(was {old}; {R})"
    else:
        text = f"{comment} (was {old}; {R})" + (f" | earlier note: {old_comment}" if old_comment else "")
    lines[idx[0]] = f"{parts[0]},{new},{typ},{text}"
    mapping.append((address, new, old))
# the named rows inside typed spans: guards for a register stage that never ran, most with stale names
sys.path.insert(0, "/home/linux/.claude/jobs/374b0424/tmp/w15/r94")
save(p, E.join(lines))
spec = "/home/linux/.claude/jobs/374b0424/tmp/w15/r94/overlap_check_r94.py"
src = open(spec).read().split("\nrepo = os.path.abspath")[0]
ns = {}
exec(compile(src, spec, "exec"), ns)
found, _ = ns["overlaps"](repo, "firmware/CM848_S90140.06_analysis/output")
remove = {a for a, n, t, h in found if n and "." not in n and "[" not in n and a != 0x3fee36}
t, E = load(p)
lines = t.split(E)
kept, removed = [], []
for l in lines:
    parts = l.split(",", 2)
    if parts[0].startswith("0x") and int(parts[0], 16) in remove:
        removed.append(l)
        continue
    kept.append(l)
save(p, E.join(kept))
print(f"global_variables.csv: {len(RENAMES)} renamed, {len(removed)} rows inside typed spans removed")
open(os.path.join(os.path.dirname(map_path), "removed_rows_r95b.txt"), "w").write("\n".join(removed) + "\n")

# 4. mpc555_registers.csv
p = os.path.join(OUT, "mpc555_registers.csv")
t, E = load(p)
REGISTERS = {
    "0x002fc024": ("USIU_PADCFG_A", "USIU_SGPIODT1", "SGPIO data register 1"),
    "0x002fc028": ("USIU_PADCFG_B", "USIU_SGPIODT2", "SGPIO data register 2"),
    "0x002fc02c": ("USIU_INITCFG", "USIU_SGPIOCR", "SGPIO control register"),
    "0x002fc030": ("USIU_SGPIODT1", "USIU_EMCR", "External master mode control register"),
    "0x002fc03c": ("USIU_EMCR", "USIU_PDMCR", "Pads module configuration register"),
    "0x002fc204": ("USIU_TBREFF0", "USIU_TBREF0", "Time base reference register 0"),
    "0x002fc208": ("USIU_TBREFF1", "USIU_TBREF1", "Time base reference register 1"),
    "0x002fc304": ("USIU_TBREFF0K", "USIU_TBREF0K", "Time base reference register 0 key"),
    "0x002fc308": ("USIU_TBREFF1K", "USIU_TBREF1K", "Time base reference register 1 key"),
    "0x002fc320": ("USIU_RTCSK", "USIU_RTCSCK", "Real-time clock status and control register key"),
    "0x002fc340": ("USIU_PISCRK", "USIU_PISCRIK", "Periodic interrupt status and control register key"),
    "0x002fc384": ("USIU_PLPRCK", "USIU_PLPRCRK", "PLL, low-power and reset control register key"),
    "0x00304028": ("TPUA_R028", "TPUA_TPUMCR2", "TPU-A module configuration register 2"),
    "0x0030402a": ("TPUA_R02A", "TPUA_TPUMCR3", "TPU-A module configuration register 3"),
    "0x00304428": ("TPUB_R028", "TPUB_TPUMCR2", "TPU-B module configuration register 2"),
    "0x0030442a": ("TPUB_R02A", "TPUB_TPUMCR3", "TPU-B module configuration register 3"),
    "0x00305002": ("QSMCM_TEST", "QSMCM_QTEST", "QSMCM test register"),
    "0x00305004": ("QSMCM_IDSCI", "QSMCM_QDSCI_IL", "QSMCM dual SCI interrupt level register"),
    "0x00305006": ("QSMCM_IDSPI", "QSMCM_QSPI_IL", "QSPI interrupt level register"),
}
for module, base in (("A", 0x304800), ("B", 0x304c00)):
    for offset, old, new, text in ((0xa, "CCW", "QACR0", "control register 0"), (0xc, "RJURR", "QACR1", "control register 1"),
                                   (0xe, "LJSRR", "QACR2", "control register 2"), (0x10, "LJURR", "QASR0", "status register 0"),
                                   (0x12, "SR", "QASR1", "status register 1")):
        REGISTERS[f"0x{base + offset:08x}"] = (f"QADC64{module}_{old}", f"QADC64{module}_{new}", f"QADC64 {module} {text}")
    count = 12 if module == "A" else 4
    for n in range(count):
        REGISTERS[f"0x{base + 0x200 + 2 * n:08x}"] = (f"QADC64{module}_RESULT{n}", f"QADC64{module}_CCW{n}",
                                                       f"QADC64 {module} conversion command word {n}")
lines = t.split(E)
done = 0
for i, l in enumerate(lines):
    parts = l.split(",", 3)
    if not parts[0].startswith("0x"):
        continue
    a = parts[0].lower()
    if a in REGISTERS:
        old, new, text = REGISTERS[a]
        assert parts[1] == old, (a, parts[1], old)
        lines[i] = f"{parts[0]},{new},{parts[2]},{text} (MPC555UM Appendix A; was {old}; {R})"
        done += 1
        continue
    m = re.match(r"^(MIOS_(?:MDASM|MMCSM)\d+)_(SCRD|XR)$", parts[1])
    if m:
        offset = int(parts[0], 16) & 7
        if m.group(2) == "SCRD":
            assert offset == 6, l
            lines[i] = (f"{parts[0]},{m.group(1)}_SCR,{parts[2]},{parts[3] if len(parts) > 3 else ''} (MPC555UM "
                        f"15.10-15.11: SCR at +6; was {parts[1]}; {R})")
        else:
            assert offset == 4, l
            lines[i] = (f"{parts[0]},{m.group(1)}_SCRD,{parts[2]},{m.group(1).split('_')[1]} status/control register "
                        f"duplicated: the same register as SCR (MPC555UM 15.11.1.3; was {parts[1]}; {R})")
        done += 1
assert done == len(REGISTERS) + 14, (done, len(REGISTERS))
save(p, E.join(lines))
print(f"mpc555_registers.csv: {done} rows")

# the CM848 map: global renames + the struct field renames that render
CHAINED = {"USIU_INITCFG", "USIU_SGPIODT1", "USIU_EMCR"}     # no text uses them; kept out of the refresh (a chain)
with open(map_path, "w") as f:
    f.write("address,name,old_label,kind,dims\n")
    for a, new, old in mapping:
        if old not in CHAINED:
            f.write(f"{a},{new},{old},symbol,1\n")
with open(map_path + ".proof.csv", "w") as f:
    f.write("address,name,old_label,kind,dims\n")
    for a, new, old in mapping:
        f.write(f"{a},{new},{old},symbol,1\n")
    for old, new in (("CCW", "QACR0"), ("RJURR", "QACR1"), ("LJSRR", "QACR2"), ("LJURR", "QASR0"), ("R028", "TPUMCR2"),
                     ("R02A", "TPUMCR3"), ("SCRD", "SCR")):
        f.write(f"0x00000000,{new},{old},field,1\n")
print(f"map: {len(mapping)} symbols + 7 fields; SCRD text references: {scrd_count}")

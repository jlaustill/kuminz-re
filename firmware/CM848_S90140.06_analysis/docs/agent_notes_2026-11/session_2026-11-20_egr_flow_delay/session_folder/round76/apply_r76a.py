"""Round 76 stage A (CM550): the MC68336 module registers the code reaches, named from the MC68336/376 User's Manual,
Appendix D (Register Summary, Rev. 15 Oct 2000; Y = F because the code addresses the block at $FFF000). Each name is
<module>_<mnemonic>, like CM848's mpc555_registers.csv (TPUA_CIER, TPUA_CH0_PARAM0), and each width is the manual's
(byte registers at odd addresses), confirmed by the decoded m68k accesses (register_access_sizes.txt).
Also removes the five register struct types whose only instances sat in this space and never applied: their names
contradict the manual (a 'QSM SCI data register' at 0xFFD00E, TPU blocks on QSM addresses, a SIM timer on CTM4 BIUTBR).
Idempotent; keeps line endings. usage: apply_r76a.py <repo>"""
import os
import sys

repo = os.path.abspath(sys.argv[1])
O5 = os.path.join(repo, "firmware/CM550_J90350.00_analysis/output")
R = "PR #53 round 76"
SRC = "MC68336/376 UM App. D"

ROWS = [
    # SIM, Table D-3 (byte registers sit in the low byte of their word)
    ("fffa00", "SIM_SIMCR", "word", "SIM Module Configuration Register"),
    ("fffa04", "SIM_SYNCR", "word", "Clock Synthesizer Control Register"),
    ("fffa11", "SIM_PORTE0", "byte", "Port E Data (PORTE0)"),
    ("fffa15", "SIM_DDRE", "byte", "Port E Data Direction"),
    ("fffa17", "SIM_PEPAR", "byte", "Port E Pin Assignment"),
    ("fffa19", "SIM_PORTF0", "byte", "Port F Data (PORTF0)"),
    ("fffa1d", "SIM_DDRF", "byte", "Port F Data Direction"),
    ("fffa1f", "SIM_PFPAR", "byte", "Port F Pin Assignment"),
    ("fffa21", "SIM_SYPCR", "byte", "System Protection Control"),
    ("fffa22", "SIM_PICR", "word", "Periodic Interrupt Control Register"),
    ("fffa24", "SIM_PITR", "word", "Periodic Interrupt Timing Register"),
    ("fffa27", "SIM_SWSR", "byte", "Software Service register (the watchdog service writes 0x55 then 0xAA)"),
    ("fffa44", "SIM_CSPAR0", "word", "Chip-Select Pin Assignment 0"),
    ("fffa46", "SIM_CSPAR1", "word", "Chip-Select Pin Assignment 1"),
    ("fffa48", "SIM_CSBARBT", "word", "Chip-Select Base Boot"),
    ("fffa4a", "SIM_CSORBT", "word", "Chip-Select Option Boot"),
]
for n in range(11):
    ROWS.append((f"{0xfffa4c + 4 * n:06x}", f"SIM_CSBAR{n}", "word", f"Chip-Select Base {n}"))
    ROWS.append((f"{0xfffa4e + 4 * n:06x}", f"SIM_CSOR{n}", "word", f"Chip-Select Option {n}"))
ROWS += [
    # TPURAM, Table D-58 / SRAM, Table D-19
    ("fffb04", "TPURAM_TRAMBAR", "word", "TPURAM Base Address and Status Register"),
    ("fffb40", "SRAM_RAMMCR", "word", "RAM Module Configuration Register"),
    ("fffb44", "SRAM_RAMBAH_RAMBAL", "dword", "RAM Array Base Address Registers High and Low (RAMBAH / RAMBAL): the "
     "code's only access is one 32-bit write of both (0x810000)"),
    # QADC
    ("fff200", "QADC_QADCMCR", "word", "QADC Module Configuration Register"),
    ("fff202", "QADC_QADCTEST", "word", "QADC Test Register"),
    ("fff204", "QADC_QADCINT", "word", "QADC Interrupt Register"),
    ("fff206", "QADC_PORTQA_PORTQB", "word", "Port QA Data (high byte) and Port QB Data (low byte): the code reads and "
     "writes both as one word"),
    ("fff208", "QADC_DDRQA", "word", "Port QA Data Direction Register"),
    ("fff20a", "QADC_QACR0", "word", "QADC Control Register 0"),
    ("fff20c", "QADC_QACR1", "word", "QADC Control Register 1"),
    ("fff20e", "QADC_QACR2", "word", "QADC Control Register 2"),
    ("fff210", "QADC_QASR", "word", "QADC Status Register"),
    ("fff230", "QADC_CCW", "word", "Conversion Command Word table ($YFF230-$YFF27E): the first entry - the code walks the "
     "table from here"),
    # QSM, Table D-31 (the four SCI registers are named since round 75)
    ("fffc00", "QSM_QSMCR", "word", "QSM Module Configuration Register"),
    ("fffc04", "QSM_QILR", "byte", "QSM Interrupt Level Register"),
    ("fffc05", "QSM_QIVR", "byte", "QSM Interrupt Vector Register"),
    ("fffc15", "QSM_PORTQS", "byte", "PQS Data Register"),
    ("fffc16", "QSM_PQSPAR", "byte", "PQS Pin Assignment Register"),
    ("fffc17", "QSM_DDRQS", "byte", "PQS Data Direction Register"),
    ("fffc18", "QSM_SPCR0", "word", "QSPI Control Register 0"),
    ("fffc1a", "QSM_SPCR1", "word", "QSPI Control Register 1"),
    ("fffc1c", "QSM_SPCR2", "word", "QSPI Control Register 2"),
    ("fffc1f", "QSM_SPSR", "byte", "QSPI Status Register"),
]
for n in (2, 3, 4):
    ROWS.append((f"{0xfffd00 + 2 * n:06x}", f"QSM_RR{n}", "word", f"QSPI Receive Data RAM entry {n}"))
for n in range(6):
    ROWS.append((f"{0xfffd20 + 2 * n:06x}", f"QSM_TR{n}", "word", f"QSPI Transmit Data RAM entry {n}"))
for n in range(6):
    ROWS.append((f"{0xfffd40 + n:06x}", f"QSM_CR{n}", "byte", f"QSPI Command RAM entry {n}"))
ROWS += [
    # CTM4, Table D-35
    ("fff400", "CTM4_BIUMCR", "word", "BIUSM Module Configuration Register"),
    ("fff404", "CTM4_BIUTBR", "word", "BIUSM Time Base Register"),
    ("fff408", "CTM4_CPCR", "word", "CPSM Control Register"),
    ("fff410", "CTM4_MCSM2SIC", "word", "MCSM2 Status/Interrupt/Control Register"),
    ("fff414", "CTM4_MCSM2ML", "word", "MCSM2 Modulus Latch"),
    ("fff418", "CTM4_DASM3SIC", "word", "DASM3 Status/Interrupt/Control Register"),
    ("fff41a", "CTM4_DASM3A", "word", "DASM3 Register A"),
    ("fff41c", "CTM4_DASM3B", "word", "DASM3 Register B"),
    ("fff420", "CTM4_DASM4SIC", "word", "DASM4 Status/Interrupt/Control Register"),
]
for n in (5, 6, 7, 8):
    base = 0xfff428 + 8 * (n - 5)
    ROWS.append((f"{base:06x}", f"CTM4_PWM{n}SIC", "word", f"PWMSM{n} Status/Interrupt/Control Register"))
    ROWS.append((f"{base + 2:06x}", f"CTM4_PWM{n}A", "word", f"PWMSM{n} Period"))
    ROWS.append((f"{base + 4:06x}", f"CTM4_PWM{n}B", "word", f"PWMSM{n} Pulse Width"))
ROWS += [
    ("fff448", "CTM4_DASM9SIC", "word", "DASM9 Status/Interrupt/Control Register"),
    ("fff450", "CTM4_DASM10SIC", "word", "DASM10 Status/Interrupt/Control Register"),
    ("fff458", "CTM4_MCSM11SIC", "word", "MCSM11 Status/Interrupt/Control Register: mc68k_startJ1708Transmission "
     "sets an interrupt level here after loading CTM4_MCSM11CNT and mc68k_j1708SciInterruptHandler clears it"),
    ("fff45a", "CTM4_MCSM11CNT", "word", "MCSM11 Counter (mc68k_startJ1708Transmission loads it)"),
    ("fff460", "CTM4_FCSM12SIC", "word", "FCSM12 Status/Interrupt/Control Register"),
    # TPU
    ("fffe00", "TPU_TPUMCR", "word", "TPU Module Configuration Register"),
    ("fffe08", "TPU_TICR", "word", "TPU Interrupt Configuration Register"),
    ("fffe0a", "TPU_CIER", "word", "TPU Channel Interrupt Enable Register"),
    ("fffe0c", "TPU_CFSR0", "word", "TPU Channel Function Selection Register 0 (channels 15-12)"),
    ("fffe0e", "TPU_CFSR1", "word", "TPU Channel Function Selection Register 1 (channels 11-8)"),
    ("fffe12", "TPU_CFSR3", "word", "TPU Channel Function Selection Register 3 (channels 3-0)"),
    ("fffe14", "TPU_HSQR0", "word", "TPU Host Sequence Register 0 (channels 15-8)"),
    ("fffe16", "TPU_HSQR1", "word", "TPU Host Sequence Register 1 (channels 7-0)"),
    ("fffe18", "TPU_HSRR0", "word", "TPU Host Service Request Register 0 (channels 15-8)"),
    ("fffe1a", "TPU_HSRR1", "word", "TPU Host Service Request Register 1 (channels 7-0)"),
    ("fffe1c", "TPU_CPR0", "word", "TPU Channel Priority Register 0 (channels 15-8)"),
    ("fffe1e", "TPU_CPR1", "word", "TPU Channel Priority Register 1 (channels 7-0)"),
    ("fffe20", "TPU_CISR", "word", "TPU Channel Interrupt Status Register"),
]
# TPU parameter RAM, Table D-57: channel n parameter m at $YFFF00 + 0x10 n + 2 m (channels 0-13 have parameters 0-5)
for channel, parameters in ((0, (0, 1, 2, 3, 4, 6)), (1, (0, 1, 3, 4)), (3, (0, 2, 4, 5)), (10, (0, 1, 2, 3, 4)),
                            (12, (0, 2)), (13, (0, 1)), (15, (6,))):
    for m in parameters:
        note = ""
        if m > 5 and channel < 14:
            note = " - not implemented on channels 0-13 per Table D-57; the code clears it"
        ROWS.append((f"{0xffff00 + 0x10 * channel + 2 * m:06x}", f"TPU_CH{channel}_PARAM{m}", "word",
                     f"TPU parameter RAM channel {channel} parameter {m}{note}"))
ROWS += [
    ("ffff1b", "TPU_CH1_PARAM5_LOW_BYTE", "byte", "The low byte of TPU parameter RAM channel 1 parameter 5 (the code "
     "accesses it alone)"),
    ("fffffd", "TPU_CH15_PARAM6_LOW_BYTE", "byte", "The low byte of TPU parameter RAM channel 15 parameter 6 (the code "
     "accesses it alone)"),
]


def read(p):
    with open(p, "rb") as fh:
        raw = fh.read().decode()
    return raw, ("\r\n" if "\r\n" in raw else "\n")


def write(p, s):
    with open(p, "wb") as fh:
        fh.write(s.encode())


S5, G5 = os.path.join(O5, "structure_definitions.csv"), os.path.join(O5, "global_variables.csv")
DEAD = ("mc68336_reg16_t,", "tpu_dscr_block_t,", "tpu_hsq_block_t,", "sim_timer_block_t,", "serial_port_regs_t,")
s, eol = read(S5)
lines = s.split(eol)
kept = [l for l in lines if not l.startswith(DEAD)]
if len(kept) != len(lines):
    write(S5, eol.join(kept))
g, eol = read(G5)
existing = {l.split(",")[0] for l in g.split(eol) if l.startswith("0x")}
new = [f"0x00{a},{n},{t},MC68336 {d} ({SRC}; {R})" for a, n, t, d in ROWS if f"0x00{a}" not in existing]
assert len({a for a, *_ in ROWS}) == len(ROWS), "duplicate register address"
if new:
    write(G5, g.rstrip(eol) + eol + eol.join(new) + eol)
print(f"round 76 stage A applied: {len(lines) - len(kept)} struct rows removed, {len(new)} register rows added "
      f"({len(ROWS)} listed)")

"""Round 79 stage A (CM550): the two Intel 82527 CAN controllers on chip selects 5 (0xFFC800) and 4 (0xFFD800).
Idempotent. usage: apply_r79a.py <repo>
- The chip selects: SIM_CSBAR5 = 0xffc8 / SIM_CSBAR4 = 0xffd8, the same option word 0x5bf0 (SIM_CSOR5 / SIM_CSOR4).
- The register map is the 82527's (Intel 82527 Architectural Overview, section 4.1 Address Map): 00H control, 01H
  status, 02H CPU interface, 06-07H global mask standard, 08-0BH global mask extended, 0C-0FH message 15 mask, 1FH
  CLKOUT, 2FH bus configuration, 3FH / 4FH bit timing 0 / 1, 5FH interrupt. Message object n sits at n * 10H:
  +0 control 0, +1 control 1, +2-+5 arbitration 0-3, +6 message configuration, +7-+0E data 0-7.
- The code matches it: an interrupt handler loops while the interrupt register is non-zero and indexes the message
  objects with interrupt * 0x10 + base - 0x20. The control pairs are written as bit pairs (0x9955 / 0x5559), and the
  configuration bytes are 0x80 (receive, 8 bytes) / 0x88 (transmit, 8 bytes).
- Widths follow the renders: one word write covers the control 0 / 1 pair and one covers arbitration 0 / 1 (an 11-bit
  identifier). The 0xFFC800 controller's standard mask is a word and its message 15 mask a dword. Every other register
  is a byte.
- The 0xFFD800 controller's message objects are reached by index from a base (&DAT_00ffd810 + index * 0x10,
  (&DAT_00ffd806)[i]), so only its scalar registers are named here."""
import os
import sys

p = os.path.join(os.path.abspath(sys.argv[1]), "firmware/CM550_J90350.00_analysis/output/global_variables.csv")
s = open(p, newline="").read()
R = "PR #53 round 79"
SRC = "Intel 82527 Architectural Overview 4.1"
rows = []
for cs, base in (("CS5", 0xffc800), ("CS4", 0xffd800)):
    common = [
        (0x00, "CONTROL", "byte", "Control Register (00H)"),
        (0x01, "STATUS", "byte", "Status Register (01H)"),
        (0x02, "CPU_INTERFACE", "byte", "CPU Interface Register (02H)"),
        (0x08, "GLOBAL_MASK_EXTENDED_0", "byte", "Global Mask - Extended Register byte 0 (08H)"),
        (0x09, "GLOBAL_MASK_EXTENDED_1", "byte", "Global Mask - Extended Register byte 1 (09H)"),
        (0x0a, "GLOBAL_MASK_EXTENDED_2", "byte", "Global Mask - Extended Register byte 2 (0AH)"),
        (0x0b, "GLOBAL_MASK_EXTENDED_3", "byte", "Global Mask - Extended Register byte 3 (0BH)"),
        (0x1f, "CLOCK_OUT", "byte", "CLKOUT Register (1FH)"),
        (0x2f, "BUS_CONFIGURATION", "byte", "Bus Configuration Register (2FH)"),
        (0x3f, "BIT_TIMING_0", "byte", "Bit Timing Register 0 (3FH)"),
        (0x4f, "BIT_TIMING_1", "byte", "Bit Timing Register 1 (4FH)"),
        (0x5f, "INTERRUPT", "byte", "Interrupt Register (5FH): 0 none / 1 status change / 2 message 15 / n + 2 message n"),
    ]
    if cs == "CS5":
        common += [
            (0x06, "GLOBAL_MASK_STANDARD", "word", "Global Mask - Standard Register (06-07H), written as one word from "
             "the_can_1_standard_mask_0_65535"),
            (0x0c, "MESSAGE_15_MASK", "dword", "Message 15 Mask Register (0C-0FH) - written as one dword"),
        ]
        for n in range(1, 7):
            o = 0x10 * n
            common += [
                (o, f"MESSAGE_{n}_CONTROL", "word", f"message object {n} Control 0 and Control 1 ({o:02X}H-{o + 1:02X}H, "
                 "written together as bit pairs)"),
                (o + 2, f"MESSAGE_{n}_ARBITRATION", "word", f"message object {n} Arbitration 0 and 1 ({o + 2:02X}H-"
                 f"{o + 3:02X}H: an 11-bit identifier)"),
                (o + 6, f"MESSAGE_{n}_CONFIGURATION", "byte", f"message object {n} Message Configuration ({o + 6:02X}H: "
                 "0x80 receive / 0x88 transmit - 8 data bytes)"),
            ]
    else:
        common += [(0x0c, "MESSAGE_15_MASK", "byte", "Message 15 Mask Register (0C-0FH) - first byte")]
    for offset, reg, type_, desc in common:
        rows.append((base + offset, f"CAN_{cs}_{reg}", type_, f"82527 CAN controller on chip select {cs[2:]}: {desc} "
                     f"({SRC}; {R})"))
existing = {l.split(",")[0].lower() for l in s.split("\n") if l.startswith("0x")}
new = [f"0x{a:08x},{n},{t},{c}" for a, n, t, c in sorted(rows) if f"0x{a:08x}" not in existing]
assert len({a for a, *_ in rows}) == len(rows)
if new:
    s = s.rstrip("\n") + "\n" + "\n".join(new) + "\n"
    open(p, "w", newline="").write(s)
print(f"round 79 stage A applied: {len(new)} rows added ({len(rows)} listed)")

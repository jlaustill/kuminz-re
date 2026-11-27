"""Round 25 stage B (types): the TouCAN A register map. mpc555_initCanController proves the module registers sit at
0x307080-0x3070a7 (MCR 0x5000 then 0, CANICR 0x400, CANCTRL0/1 0 / 0x10, PRESDIV / CANCTRL2 9 / 0x36, the receive
masks written as dwords at +0x10 / +0x14, IMASK / IFLAG at +0x22 / +0x24) and the 16 message buffers at
0x307100-0x3071ff (it zeroes byte +1 of each). The repo put the module at 0x307000 (register CSV + 19 byte rows, no code
touches 0x307000-0x30707f by the raw lis scan) and modelled 0x307080 / 90 / a0 as message buffers 0-2.
- structure_definitions.csv: toucan_a_mb0_t / mb1_t / mb2_t -> toucan_module_registers_t at 0x307080 (the register
  CSV's mnemonics at the right base; the masks are dwords as the code writes them) + the type-only
  toucan_message_buffer_t.
- global_variables.csv: toucan_a (was toucan_a_mcr), toucan_a_message_buffers (toucan_message_buffer_t[16]); the 19
  wrong-base rows, the 8 label rows that only kept the old struct whole and the 4 rows inside the module go.
- mpc555_registers.csv: its 19 wrong-base rows and 7 'message buffer 0' rows go (the struct names the registers; a
  register row inside the struct would split it).
Writes the proof's token map. usage: apply_r25b.py <repo> <tokens.json>"""
import csv
import io
import json
import os
import sys

repo, tokens_out = os.path.abspath(sys.argv[1]), sys.argv[2]
out = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")
T, M = "toucan_module_registers_t", "toucan_message_buffer_t"
FIELDS = [  # name, type, size, comment
    ("MCR", "word", 2, "Module configuration: mpc555_initCanController writes 0x5000 (freeze + halt) before the setup "
                       "and 0 after it"),
    ("TCR", "word", 2, "Test register"),
    ("CANICR", "word", 2, "Interrupt configuration (0x400 at init)"),
    ("CANCTRL0", "byte", 1, "Control register 0 (0 at init)"),
    ("CANCTRL1", "byte", 1, "Control register 1 (0x10 at init)"),
    ("PRESDIV", "byte", 1, "Prescaler divide (9 at init)"),
    ("CANCTRL2", "byte", 1, "Control register 2 (0x36 at init)"),
    ("TIMER", "word", 2, "Free-running timer (the message buffer time stamps count it)"),
    ("reserved_0c", "dword", 4, "Reserved"),
    ("RXGMSK", "dword", 4, "Receive global mask, high and low halves (0x1fee0000 at init, one 32-bit store)"),
    ("RX14MSK", "dword", 4, "Receive buffer 14 mask (0x1feffe00 at init)"),
    ("RX15MSK", "dword", 4, "Receive buffer 15 mask"),
    ("reserved_1c", "dword", 4, "Reserved"),
    ("ESR", "word", 2, "Error and status"),
    ("IMASK", "word", 2, "Interrupt mask, one bit per message buffer (0 at init)"),
    ("IFLAG", "word", 2, "Interrupt flags, one bit per message buffer (read, then cleared, at init)"),
    ("RXECTR", "byte", 1, "Receive error counter"),
    ("TXECTR", "byte", 1, "Transmit error counter"),
]
MB = [("CONTROL_STATUS", "word", 2, "Bits 15-8 time stamp, 7-4 CODE, 3-0 LENGTH; mpc555_initCanController zeroes byte "
                                    "+1 (CODE / LENGTH) of all 16 buffers"),
      ("ID_HIGH", "word", 2, "Identifier, high word"), ("ID_LOW", "word", 2, "Identifier, low word"),
      ("DATA_0_1", "word", 2, "Data bytes 0-1"), ("DATA_2_3", "word", 2, "Data bytes 2-3"),
      ("DATA_4_5", "word", 2, "Data bytes 4-5"), ("DATA_6_7", "word", 2, "Data bytes 6-7"),
      ("RESERVED", "word", 2, "Reserved")]


def write_csv_row(row):
    s = io.StringIO()
    csv.writer(s, lineterminator="").writerow(row)
    return s.getvalue()


sp = os.path.join(out, "structure_definitions.csv")
sd = open(sp).read().split("\n")
idx = [i for i, l in enumerate(sd) if l.startswith(("toucan_a_mb0_t,", "toucan_a_mb1_t,", "toucan_a_mb2_t,"))]
assert len(idx) == 24, len(idx)
rows = [write_csv_row([T, "0x00307080", n, t, str(s), c + " (PR #53 round 25)", "", "verified"]) for n, t, s, c in FIELDS]
rows += [write_csv_row([M, "", n, t, str(s), c, "", "verified"]) for n, t, s, c in MB]
first = idx[0]
sd = [l for i, l in enumerate(sd) if i not in set(idx)]
sd[first:first] = rows
open(sp, "w").write("\n".join(sd))
gp = os.path.join(out, "global_variables.csv")
g = open(gp).read().split("\n")
DROP = set(range(0x307000, 0x307028)) | {0x307082, 0x307084, 0x307086, 0x307087, 0x307088, 0x307089, 0x30708a,
                                         0x30708c, 0x307090, 0x307094, 0x3070a2, 0x3070a4}
new_g, dropped, renamed = [], [], 0
for line in g:
    if line.startswith("0x00307") and len(line) > 10:
        a = int(line[:10], 16)
        if a in DROP:
            dropped.append(line.split(",", 2)[1])
            continue
        if a == 0x307080:
            assert line.startswith("0x00307080,toucan_a_mcr,toucan_a_mb0_t,"), line
            new_g.append("0x00307080,toucan_a,toucan_module_registers_t,TouCAN A module registers (0x307080-0x3070a7; "
                         "the 16 message buffers follow at 0x307100): mpc555_initCanController freezes the module (MCR "
                         "0x5000), sets CANCTRL0-2 / PRESDIV, the receive masks and CANICR, clears IMASK / IFLAG and "
                         "every buffer's CODE byte, then leaves freeze; the mailbox writers take its address as their "
                         "base. The register CSV and 19 rows here used to put the module at 0x307000 (no code touches "
                         "0x307000-0x30707f, raw lis scan) and message buffer 0 at this address (was toucan_a_mcr, typed "
                         "as message buffer 0) (PR #53 round 25)")
            new_g.append("0x00307100,toucan_a_message_buffers,toucan_message_buffer_t[16],The 16 TouCAN A message "
                         "buffers (16 bytes each, 0x307100-0x3071ff): mpc555_initCanController zeroes byte +1 (CODE / "
                         "LENGTH) of each; the CAN drivers address them as 0x3070f0 + 16 x (buffer + 1) (PR #53 round 25)")
            renamed += 1
            continue
    new_g.append(line)
assert renamed == 1 and len(dropped) == 31, (renamed, len(dropped), dropped)
assert not any(l.startswith("0x00307100,") for l in g)
open(gp, "w").write("\n".join(new_g))
rp = os.path.join(out, "mpc555_registers.csv")
r = open(rp).read().split("\n")
new_r, gone = [], 0
for line in r:
    if line.startswith("0x003070") and len(line) > 10 and (0x307000 <= int(line[:10], 16) <= 0x30708c):
        gone += 1
        continue
    if line == "# TouCAN A Message Buffers (16 buffers, 16 bytes each at 0x307080-0x30717F)":
        new_r.append("# TouCAN A (PR #53 round 25): mpc555_initCanController proves the module registers at "
                     "0x307080-0x3070a7 and the 16 message buffers at 0x307100-0x3071ff. They are the struct toucan_a "
                     "(toucan_module_registers_t) and the array toucan_a_message_buffers in global_variables.csv; a row "
                     "here inside the struct would split it. The rows that were here put the module at 0x307000 (no "
                     "code touches 0x307000-0x30707f) and message buffer 0 at 0x307080")
        continue
    new_r.append(line)
assert gone == 26, gone
open(rp, "w").write("\n".join(new_r))
old = {"toucan_a_mcr.CTRL": "TA_MCR", "toucan_a_mcr.ID_LO": "TA_CANICR", "toucan_a_mcr.DATA0._0_1_": "TA_CANCTRL0",
       "toucan_a_mcr.DATA0._1_1_": "TA_CANCTRL1", "toucan_a_mcr.DATA2._0_1_": "TA_PRESDIV",
       "toucan_a_mcr.DATA2._1_1_": "TA_CANCTRL2", "toucan_a_mcr.DATA4": "TA_TIMER", "toucan_a_mcr": "TA_BASE",
       "toucan_a_mb1_t_00307090._0_4_": "TA_RXGMSK", "toucan_a_mb1_t_00307090._4_4_": "TA_RX14MSK",
       "toucan_a_mb2_t_003070a0.ID_HI": "TA_IMASK", "toucan_a_mb2_t_003070a0.ID_LO": "TA_IFLAG",
       "DAT_00307100": "TA_MB0"}
new = {"toucan_a.MCR": "TA_MCR", "toucan_a.CANICR": "TA_CANICR", "toucan_a.CANCTRL0": "TA_CANCTRL0",
       "toucan_a.CANCTRL1": "TA_CANCTRL1", "toucan_a.PRESDIV": "TA_PRESDIV", "toucan_a.CANCTRL2": "TA_CANCTRL2",
       "toucan_a.TIMER": "TA_TIMER", "toucan_a": "TA_BASE", "toucan_a.RXGMSK": "TA_RXGMSK",
       "toucan_a.RX14MSK": "TA_RX14MSK", "toucan_a.IMASK": "TA_IMASK", "toucan_a.IFLAG": "TA_IFLAG",
       "toucan_a_message_buffers": "TA_MB0"}
json.dump({"old": old, "new": new}, open(tokens_out, "w"), indent=1)
print(f"struct rows replaced, {len(dropped)} global rows dropped, {gone} register rows dropped")

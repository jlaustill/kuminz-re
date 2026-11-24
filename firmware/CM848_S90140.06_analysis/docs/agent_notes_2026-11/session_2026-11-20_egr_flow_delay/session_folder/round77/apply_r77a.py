"""Round 77 stage A (CM550): remove the malformed J1708 state structs and type the J1708 driver's globals by their
m68k access widths. Idempotent; keeps line endings. usage: apply_r77a.py <repo>
- j1708_tx_state_t / j1708_rx_state_t give every field its own address (0x80DC94-0x80DCA1 / 0x80DCA2-0x80DCAF), so
  ApplyStructures built one 14-byte type per name with an instance at every field address. The receive struct's
  instance at its last field's address 0x80DCAF covered 0x80DCAF-0x80DCBC. That made 61 renders of the separate globals
  there pieces of it: j1708_rx_state_t_0080dcaf.buffer_ptr_1._1_1_ for j1708_receive_mode_flag (0x80DCB0) and so on.
- Widths, from the decoded accesses (m68k_abs_access.py): the four receive / transmit buffer pointers are dwords
  (move.l). 0x80DCB0 / B1 / B3 / BA / BB / BC are bytes (clr.b / tst.b / cmpi.b / addq.b / move.b), and 0x80DCB6 is a
  dword (clr.l / move.l).
- Names for the three bytes that had none (each from its uses):
  - 0x80DCB3 j1708_message_checksum: the SCI interrupt handler adds every received and transmitted byte to it and
    sends ~sum + 1 at the end of a transmission, and the end-of-message code checks it for 0.
  - 0x80DCBA j1708_bus_timer_armed_flag: mc68k_startJ1708Transmission needs it at 0, arms the CTM4 MCSM11 timer and
    sets it to 1. The SCI interrupt handler clears it when a byte arrives and sets it when it arms the timer again.
  - 0x80DCBB j1708_received_message_count: mc68k_tpuChannelStateMachine adds 1 when it closes a received message of
    at least 3 bytes.
- 0x80DCBC is cleared once at initialization and read nowhere else, so it is typed but stays unnamed."""
import os
import sys

repo = os.path.abspath(sys.argv[1])
O5 = os.path.join(repo, "firmware/CM550_J90350.00_analysis/output")
R = "PR #53 round 77"


def read(p):
    with open(p, "rb") as fh:
        raw = fh.read().decode()
    return raw, ("\r\n" if "\r\n" in raw else "\n")


def write(p, s):
    with open(p, "wb") as fh:
        fh.write(s.encode())


S5, G5 = os.path.join(O5, "structure_definitions.csv"), os.path.join(O5, "global_variables.csv")
s, eol = read(S5)
lines = s.split(eol)
kept = [l for l in lines if not l.startswith(("j1708_tx_state_t,", "j1708_rx_state_t,"))]
assert len(lines) - len(kept) in (0, 10), len(lines) - len(kept)
if len(kept) != len(lines):
    write(S5, eol.join(kept))

TYPES = {  # address -> (name or None to keep the row's name, type, comment)
    "0x0080dc94": (None, "dword", "the J1708 transmit buffer pointer (move.l)"),
    "0x0080dc98": (None, "dword", "the J1708 transmit pointer - the SCI interrupt handler sends *pointer (move.l)"),
    "0x0080dc9c": (None, "dword", "the J1708 transmit buffer end pointer (move.l)"),
    "0x0080dca0": (None, "byte", "the J1708 transmit buffer full flag"),
    "0x0080dca2": (None, "dword", "the J1708 receive buffer pointer (move.l)"),
    "0x0080dca6": (None, "dword", "the J1708 receive write pointer - the SCI interrupt handler stores each received "
                   "byte at *pointer"),
    "0x0080dcaa": (None, "dword", "the J1708 receive buffer pointer the end-of-message code compares with"),
    "0x0080dcae": (None, "byte", "the J1708 receive buffer full flag"),
    "0x0080dcb0": (None, "byte", "1 while the J1708 driver listens: the SCI interrupt handler stores received bytes only "
                   "then, and mc68k_startJ1708Transmission needs it at 1 and clears it (clr.b / tst.b / cmpi.b / move.b)"),
    "0x0080dcb1": (None, "byte", "addq.b / move.b"),
    "0x0080dcb6": (None, "dword", "the J1708 transmit state the SCI interrupt handler switches on (clr.l / move.l)"),
}
NEW = {
    "0x0080dcb3": ("j1708_message_checksum", "byte", "The J1708 message checksum: the SCI interrupt handler adds every "
                   "received and transmitted byte to it and sends ~sum + 1 at the end of a transmission; the "
                   "end-of-message code checks it for 0 (clr.b)"),
    "0x0080dcba": ("j1708_bus_timer_armed_flag", "byte", "1 while the CTM4 MCSM11 timer is armed: "
                   "mc68k_startJ1708Transmission needs it at 0 and sets it after arming the timer - the SCI interrupt "
                   "handler clears it when a byte arrives and sets it when it arms the timer again (clr.b / move.b)"),
    "0x0080dcbb": ("j1708_received_message_count", "byte", "Received J1708 messages in the buffer: "
                   "mc68k_tpuChannelStateMachine adds 1 when it closes a received message of at least 3 bytes "
                   "(addq.b / clr.b / tst.b)"),
    "0x0080dcbc": ("", "byte", "Cleared once by mc68k_initializeJ1708Datalink; no other access found (clr.b)"),
}
g, eol = read(G5)
out, seen = [], set()
for line in g.split(eol):
    address = line.split(",")[0] if line.startswith("0x") else ""
    if address in TYPES and address not in seen:
        name, type_, note = TYPES[address]
        parts = line.split(",", 3)
        comment = parts[3] if len(parts) > 3 else ""
        if R not in comment:
            comment = (f"{note} (typed {type_} - was {parts[2] or 'untyped'}; {R})" + (" " + comment if comment else ""))
        line = ",".join([parts[0], parts[1], type_, comment])
        seen.add(address)
    elif address == "0x0080dcb3" and "j1708_rx_state_t_0080dcaf.buffer_ptr_2" in line:
        name, type_, note = NEW[address]
        line = f"{address},{name},{type_},{note} (was the coordinate row j1708_rx_state_t_0080dcaf.buffer_ptr_2; {R})"
        seen.add(address)
    out.append(line)
missing = [a for a in TYPES if a not in seen]
assert not missing, missing
for address in ("0x0080dcba", "0x0080dcbb", "0x0080dcbc"):
    if not any(l.startswith(address + ",") for l in out):
        name, type_, note = NEW[address]
        row = f"{address},{name},{type_},{note} ({R})"
        for i, l in enumerate(out):
            if l.startswith("0x") and int(l.split(",")[0], 16) > int(address, 16):
                out.insert(i, row)
                break
write(G5, eol.join(out))
print("round 77 stage A applied")

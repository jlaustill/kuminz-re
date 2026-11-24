"""Round 77 stage A2 (CM550): the J1708 bus timer. Idempotent; keeps line endings. usage: apply_r77a2.py <repo> <map.csv>
- 0x1e266 mc68k_tpuTimerChannelEnable -> mc68k_armJ1708BusTimer. It sets 0x80DCBA to 1, loads CTM4_MCSM11CNT with 0xfc8a,
  clears CTM4_MCSM11SIC bit 15 and sets its bit 14 (an interrupt level). It drives no TPU channel. Its callers push
  nothing before the jsr, so the prototype row's channel_mask parameter (never read) becomes a return-only void row.
  That parameter is what made the SCI interrupt handler render 'channel_mask = (word)in_D0'.
- 0x300d4 mc68k_tpuChannelStateMachine -> mc68k_j1708BusTimerInterruptHandler: it has no caller (it is reached through
  the vector table). It clears CTM4_MCSM11SIC's interrupt level and bit 15 and clears 0x80DCBA. It then closes the
  received J1708 message (it drops messages of fewer than 3 bytes and checks j1708_message_checksum) and writes a
  pending transmit byte to QSM_SCDR.
- 0x80DCBA j1708_tpu_channel_active -> j1708_bus_timer_armed_flag (byte).
- 0x80DCBB keeps j1708_pending_abort_count (byte), and 0x80DCBC (the coordinate row
  j1708_rx_state_t_0080dcaf.buffer_reserved) becomes a type-only byte."""
import os
import sys

repo, map5 = os.path.abspath(sys.argv[1]), sys.argv[2]
O5 = os.path.join(repo, "firmware/CM550_J90350.00_analysis/output")
R = "PR #53 round 77"


def edit(p, old, new):
    s = open(p, newline="").read()
    if new in s:
        return
    assert s.count(old) == 1, (os.path.basename(p), old[:90], s.count(old))
    open(p, "w", newline="").write(s.replace(old, new))


G5, F5, D5 = (os.path.join(O5, n) for n in ("global_variables.csv", "function_renames.csv", "function_definitions.csv"))
edit(G5, "0x0080dcba,j1708_tpu_channel_active,,",
     "0x0080dcba,j1708_bus_timer_armed_flag,byte,1 while the CTM4 MCSM11 timer is armed: mc68k_armJ1708BusTimer and "
     "mc68k_startJ1708Transmission set it when they arm the timer - mc68k_j1708SciInterruptHandler clears it when a "
     "byte arrives and mc68k_j1708BusTimerInterruptHandler when the timer expires - mc68k_startJ1708Transmission "
     f"sends only while it is 0 (clr.b / move.b; was j1708_tpu_channel_active - no TPU channel is involved; {R})")
edit(G5, "0x0080dcbb,j1708_pending_abort_count,,",
     "0x0080dcbb,j1708_pending_abort_count,byte,mc68k_j1708BusTimerInterruptHandler adds 1 when it closes a received "
     "message of at least 3 bytes and writes a 2 / 6 / 0x74 record into the receive buffer - the name is older and "
     f"not checked against that (addq.b / clr.b / tst.b; typed byte - was untyped; {R})")
edit(G5, "0x0080dcbc,j1708_rx_state_t_0080dcaf.buffer_reserved,,",
     "0x0080dcbc,,byte,Cleared once by mc68k_initializeJ1708Datalink - no other access found (clr.b; was the "
     f"coordinate row j1708_rx_state_t_0080dcaf.buffer_reserved; {R})")
edit(F5, "0x0001e266,mc68k_tpuTimerChannelEnable\n",
     "0x0001e266,mc68k_armJ1708BusTimer,Arms the J1708 bus timer: sets j1708_bus_timer_armed_flag - loads "
     "CTM4_MCSM11CNT with 0xfc8a - clears CTM4_MCSM11SIC bit 15 and sets its bit 14 (an interrupt level). It drives no "
     f"TPU channel and takes no parameter (was mc68k_tpuTimerChannelEnable; {R})\n")
edit(F5, "0x000300d4,mc68k_tpuChannelStateMachine\n",
     "0x000300d4,mc68k_j1708BusTimerInterruptHandler,The CTM4 MCSM11 interrupt handler of the J1708 driver (no caller - "
     "reached through the vector table): clears CTM4_MCSM11SIC's interrupt level and bit 15 and "
     "j1708_bus_timer_armed_flag - closes the received message (drops messages of fewer than 3 bytes and checks "
     "j1708_message_checksum) - and writes a pending transmit byte to QSM_SCDR. It drives no TPU channel (was "
     f"mc68k_tpuChannelStateMachine; {R})\n")
edit(D5, "0x0001e266,tpuTimerChannelEnable,0,channel_mask,ushort,TPU channel enable bitmask",
     "0x0001e266,mc68k_armJ1708BusTimer,return,,void,No parameter: the callers push nothing before the jsr and the "
     f"body reads no input (the channel_mask parameter row was never read; {R})")
with open(map5, "w") as fh:
    fh.write("address,name,old_label,kind,dims\n"
             "0x0001e266,mc68k_armJ1708BusTimer,mc68k_tpuTimerChannelEnable,function,1\n"
             "0x000300d4,mc68k_j1708BusTimerInterruptHandler,mc68k_tpuChannelStateMachine,function,1\n"
             "0x0080dcba,j1708_bus_timer_armed_flag,j1708_tpu_channel_active,global,1\n")
print("round 77 stage A2 applied")

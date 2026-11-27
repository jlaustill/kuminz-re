"""Round 93 F1 (read-only): decode the jump table of CM550 sendPgn61444ElectronicEngineController1Message
(0x32cfc: move.w (0x32d04,pc,d0.l*2),d0 ; jmp (0x32d04,pc,d0.w)) - one word per final_fueling_state 1..41 -
and print the byte each target stores into the EEC1 torque mode byte (move.b #imm,(a2))."""
import struct

ROM = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin"
rom = open(ROM, "rb").read()
BASE = 0x32D04
groups = {}
for state in range(1, 42):
    off = struct.unpack(">h", rom[BASE + (state - 1) * 2:BASE + (state - 1) * 2 + 2])[0]
    target = BASE + off
    groups.setdefault(target, []).append(state)
for target in sorted(groups):
    # the handlers are 'move.b #imm,(a2)' = 14bc 00ii, or a compare first
    words = rom[target:target + 12].hex(" ")
    print(f"target 0x{target:x}: states {groups[target]} : {words}")

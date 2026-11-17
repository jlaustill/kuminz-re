import struct
ROM = open('/home/linux/code/kuminz-re/.claude/worktrees/cm848-typing-arrays/firmware/CM848_S90140.06_analysis/originals/cm848_rom.bin','rb').read()
SLOT = 0x5985a
DTC = 0x5b57c
def u16(a): return struct.unpack('>H', ROM[a:a+2])[0]
# fault bit -> slot, for as many entries as the slot table plausibly has (up to DTC table start)
nfaults = (DTC - SLOT)//2
slot_to_faults = {}
for n in range(nfaults):
    s = u16(SLOT + 2*n)
    if s < 170:
        slot_to_faults.setdefault(s, []).append(n)
print("slot table entries:", nfaults)
for s in range(170):
    code = u16(DTC + 2*s)
    print(f"slot {s:3d}  P{code:04X}  faults {slot_to_faults.get(s)}")

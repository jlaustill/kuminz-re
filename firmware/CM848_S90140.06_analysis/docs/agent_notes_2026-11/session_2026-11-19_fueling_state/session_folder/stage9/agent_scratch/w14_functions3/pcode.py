"""usage: pcode.py FAULT [FAULT...] -- fault number -> ROM slot table 0x5985a -> obd_dtc_code_table 0x5b57c (P-code).
Fault n = fault_detected_bits_<first>_to_<last> word n // 16, bit n % 16."""
import sys

ROM = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-fueling-state-enum/firmware/CM848_S90140.06_analysis/originals/cm848_rom.bin"
rom = open(ROM, "rb").read()


def u16(address):
    return int.from_bytes(rom[address:address + 2], "big")


for arg in sys.argv[1:]:
    fault = int(arg, 0)
    slot = u16(0x5985A + 2 * fault)
    code = f"P{u16(0x5B57C + 2 * slot):04x}" if slot < 170 else f"(slot {slot}: no DTC slot)"
    print(f"fault {fault} (word {fault // 16}, bit 0x{1 << (fault % 16):04x}) -> slot {slot} -> {code}")

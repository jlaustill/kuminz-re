"""usage: peek.py <addr>:<width>[:s] ...  -> RAM-dump / ROM / flash2 values (big endian). Append :s for signed.
RAM dump quirk: cm848_ram.bin misses 0x40c200-0x40c27f, so 0x40c280+ is read at address - 0x80."""
import sys
BASE = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM848_S90140.06_analysis/originals/"


def load(name):
    with open(BASE + name, "rb") as handle:
        return handle.read()


rom = load("cm848_rom.bin")
ram = load("cm848_ram.bin")
flash2 = load("cm848_flash2_live.bin")
eeprom = load("cm848_eeprom.bin")


def peek(addr, width):
    if 0x1000000 <= addr < 0x1000000 + len(eeprom):
        o = addr - 0x1000000
        return int.from_bytes(eeprom[o:o + width], "big")
    if 0x500000 <= addr and addr + width <= 0x500000 + len(flash2):
        o = addr - 0x500000
        return int.from_bytes(flash2[o:o + width], "big")
    if addr >= 0x3FA000:
        a = addr
        if addr >= 0x40c280:
            a = addr - 0x80
        elif 0x40c200 <= addr < 0x40c280:
            return None
        o = a - 0x3FA000
        if o + width <= len(ram):
            return int.from_bytes(ram[o:o + width], "big")
    if addr + width <= len(rom) and addr < 0x70000:
        return int.from_bytes(rom[addr:addr + width], "big")
    return None


for arg in sys.argv[1:]:
    parts = arg.split(":")
    a = int(parts[0], 16)
    w = int(parts[1]) if len(parts) > 1 and parts[1] else 2
    signed = len(parts) > 2 and parts[2] == "s"
    v = peek(a, w)
    if v is None:
        print(f"{a:#010x}: out of range")
        continue
    sv = v - (1 << (8 * w)) if signed and v >= 1 << (8 * w - 1) else v
    print(f"{a:#010x} width {w}: {sv} ({v:#x})")

import os, sys
FW = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-typing-arrays/firmware/CM848_S90140.06_analysis'
ORIG = os.path.join(FW, 'originals')


def load(n):
    with open(os.path.join(ORIG, n), 'rb') as f:
        return f.read()


rom = load('cm848_rom.bin')
ram = load('cm848_ram.bin')
flash2 = load('cm848_flash2_live.bin')
eep = load('cm848_eeprom.bin')
blocks = [(0x0, rom[:0x70000], 'rom'), (0x3F9800, rom[0x3C30:0x3C30 + 0x800], 'rommirror'),
          (0x3FA000, ram, 'ram'), (0x500000, flash2, 'flash2'), (0x1000000, eep, 'eeprom')]


def rd(addr, n):
    for base, data, name in blocks:
        if base <= addr and addr + n <= base + len(data):
            return int.from_bytes(data[addr - base:addr - base + n], 'big')
    return None


def w(addr):
    return rd(addr, 2)


def sw(addr):
    v = rd(addr, 2)
    return None if v is None else (v - 65536 if v >= 32768 else v)


def b(addr):
    return rd(addr, 1)


def d(addr):
    return rd(addr, 4)


def romw(addr):
    return int.from_bytes(rom[addr:addr + 2], 'big')


if __name__ == '__main__':
    for a in sys.argv[1:]:
        ad = int(a, 16)
        print(hex(ad), 'word', w(ad), 'sw', sw(ad), 'byte', b(ad), 'dword', d(ad))

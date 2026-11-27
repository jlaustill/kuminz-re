"""Print the nine engine protection records of each table from the CM550 RAM dumps."""
import struct

base = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/'
ram = open(base + 'J90350.00.ram.bin', 'rb').read()
ext = open(base + 'J90350.00.extended_ram.bin', 'rb').read()


def ram_bytes(addr, n):
    if addr < 0x8091c2:
        return ram[addr - 0x800000:addr - 0x800000 + n]
    return ext[addr - 0x809242:addr - 0x809242 + n]


print('configuration 0x807032 + 36n (18 words):')
for n in range(9):
    b = ram_bytes(0x807032 + 36 * n, 36)
    print(n, ' '.join(f'{w:04x}' for w in struct.unpack('>18H', b)))
print('state 0x80d0dc + 46n: input mask fuel_dur rpm_dur min_ptr max_ptr rpm_ptr eren pker fscu rscu fswt rswt ertm erfg flog rlog')
for n in range(9):
    b = ram_bytes(0x80d0dc + 46 * n, 46)
    v = struct.unpack('>LHHHLLLHHHHHHHHLL', b)
    print(n, ' '.join(f'{x:x}' for x in v))
print('history 0x8057c0 + 30n: flix rpix flri rpri ex extm flet rpet flfg flin rpfg rpin')
for n in range(9):
    b = ram_bytes(0x8057c0 + 30 * n, 30)
    v = struct.unpack('>HHHHHLLLHHHH', b)
    print(n, ' '.join(f'{x:x}' for x in v))
print('logs 0x805562..0x8057be (8-byte entries: time extreme duration):')
for a in range(0x805562, 0x8057be, 40):
    b = ram_bytes(a, 40)
    ents = [struct.unpack('>LHH', b[k:k + 8]) for k in range(0, 40, 8)]
    print(hex(a), ' | '.join(f'{t:x} {e:x} {d:x}' for t, e, d in ents))
for a, n in ((0x80060e, 2), (0x800622, 4), (0x800626, 4), (0x80062a, 4), (0x80d27a, 0x18), (0x8058ce, 6), (0x80a26a, 4),
             (0x807410, 2), (0x80061a, 8)):
    print(hex(a), ram_bytes(a, n).hex())

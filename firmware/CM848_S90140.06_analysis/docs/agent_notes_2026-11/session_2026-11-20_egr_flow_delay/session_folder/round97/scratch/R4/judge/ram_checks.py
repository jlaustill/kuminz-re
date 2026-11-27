"""RAM-dump checks: values at given addresses, zero spans, and 4-byte RAM values pointing into given ranges."""
import sys

base = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/'
ram = open(base + 'J90350.00.ram.bin', 'rb').read()
ext = open(base + 'J90350.00.extended_ram.bin', 'rb').read()


def rd(a, n):
    if 0x800000 <= a and a + n <= 0x800000 + len(ram):
        return ram[a - 0x800000:a - 0x800000 + n]
    if 0x809242 <= a and a + n <= 0x809242 + len(ext):
        return ext[a - 0x809242:a - 0x809242 + n]
    return None


print('ram size', hex(len(ram)), 'ext size', hex(len(ext)), 'ext end', hex(0x809242 + len(ext)))
spans = [(0x801500, 0x801900), (0x803380, 0x803448), (0x8036e3, 0x803780), (0x809a00, 0x809c46)]
for lo, hi in spans:
    b = rd(lo, hi - lo)
    if b is None:
        print(f'span 0x{lo:x}-0x{hi:x}: not in dumps')
        continue
    nz = [lo + i for i, x in enumerate(b) if x]
    print(f'span 0x{lo:x}-0x{hi:x}: {len(nz)} nonzero bytes; first {[hex(x) for x in nz[:12]]}')

targets = [(0x8016b0, 0x801720), (0x803410, 0x803427), (0x80373c, 0x80373f), (0x809b02, 0x809b0b),
           (0x80d076, 0x80d08f), (0x808794, 0x808815)]
for name, blob, off in (('ram', ram, 0x800000), ('ext', ext, 0x809242)):
    for i in range(0, len(blob) - 3, 2):
        v = int.from_bytes(blob[i:i + 4], 'big')
        for lo, hi in targets:
            if lo <= v <= hi:
                print(f'{name} pointer at 0x{off + i:x} = 0x{v:x} (target range 0x{lo:x}-0x{hi:x})')

for a, n in [(0x807839, 1), (0x80783a, 4), (0x80783e, 4), (0x807d90, 2), (0x807e9a, 1), (0x807e9b, 1), (0x807ea4, 2),
             (0x807ea6, 2), (0x807ec0, 1), (0x807ec1, 1), (0x807ec2, 1), (0x807ec3, 1), (0x807ec4, 2), (0x807ec6, 2),
             (0x807ec8, 2), (0x807eca, 2), (0x807eda, 2), (0x807ede, 2), (0x807ee0, 2), (0x807ee2, 2), (0x807ee4, 2),
             (0x807f4e, 1), (0x807f4f, 1), (0x807f50, 1), (0x807f51, 1), (0x807f52, 2), (0x807f58, 2), (0x807f5a, 2),
             (0x807f5c, 2), (0x807f94, 2), (0x807f96, 2), (0x807f98, 2), (0x807f9a, 2), (0x807f9c, 2), (0x807faa, 1),
             (0x807fab, 1), (0x80847a, 2), (0x80847c, 2), (0x80a9f4, 2), (0x80a9f6, 2), (0x80ccea, 2), (0x80ccec, 2),
             (0x80ccf2, 2), (0x80ccf4, 2), (0x80ccf6, 2), (0x80cd04, 2), (0x80cd06, 2), (0x80cd16, 2), (0x80cd1e, 4),
             (0x80cd7a, 4), (0x80cd7e, 4), (0x80ceae, 4), (0x80ceb2, 4), (0x80d03e, 4), (0x80d042, 4), (0x80d046, 2),
             (0x80d048, 2), (0x80d04a, 4), (0x80d04e, 4), (0x80d058, 2), (0x80d05a, 2), (0x80d05c, 2), (0x80d05e, 2),
             (0x80d060, 4), (0x80d064, 4), (0x80d070, 4), (0x80d074, 4), (0x80d078, 4), (0x80d07c, 4), (0x80d080, 4),
             (0x80d084, 4), (0x80d088, 4), (0x80d08c, 4), (0x80d0bc, 2), (0x80d0be, 2), (0x80d292, 1), (0x80d293, 1),
             (0x80d296, 1), (0x80d297, 1), (0x80d298, 2), (0x80d29a, 2), (0x80d29c, 2), (0x80d2be, 1), (0x80d2bf, 1),
             (0x80d2c8, 1), (0x80d2c9, 1), (0x80d2ca, 1), (0x80d2cb, 1), (0x80d2cc, 1), (0x80deda, 4)]:
    b = rd(a, n)
    print(f'0x{a:x}: {b.hex() if b is not None else "not dumped"}' + (f' = {int.from_bytes(b, "big")}' if b is not None else ''))

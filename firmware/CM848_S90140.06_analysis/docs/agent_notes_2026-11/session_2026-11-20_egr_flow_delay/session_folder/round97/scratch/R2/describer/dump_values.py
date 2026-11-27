"""Print the RAM dump value of each listed CM550 global (word, or byte for byte rows, or long for 0x800716)."""
import os

base = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware"
ram = open(os.path.join(base, "J90350.00.ram.bin"), "rb").read()
ext = open(os.path.join(base, "J90350.00.extended_ram.bin"), "rb").read()


def read(addr, n):
    if 0x800000 <= addr and addr + n <= 0x800000 + len(ram):
        return ram[addr - 0x800000:addr - 0x800000 + n]
    if 0x809242 <= addr and addr + n <= 0x809242 + len(ext):
        return ext[addr - 0x809242:addr - 0x809242 + n]
    return None


rows = [l.split() for l in open("/home/linux/.claude/jobs/374b0424/tmp/w15/r97/family_R2.txt") if l.strip()]
for addr, name, typ in rows:
    a = int(addr, 16)
    n = 1 if typ == "byte" else (4 if a == 0x800716 else 2)
    b = read(a, n)
    if b is None:
        print(f"{addr} {name}: not in the dumps")
        continue
    u = int.from_bytes(b, "big")
    s = u - (1 << (8 * n)) if u >= 1 << (8 * n - 1) else u
    print(f"{addr} {name} ({typ}): 0x{u:0{2 * n}x} = {u} (signed {s})")

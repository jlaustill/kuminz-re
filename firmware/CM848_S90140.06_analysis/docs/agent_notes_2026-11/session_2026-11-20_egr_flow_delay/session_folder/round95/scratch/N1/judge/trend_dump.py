"""Decode the CM550 RAM dump's trending block (126D 0x8049ea.. and 126E table 0x804a1a)."""
RAM = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/J90350.00.ram.bin"
ram = open(RAM, "rb").read()


def w(a):
    return int.from_bytes(ram[a - 0x800000:a - 0x800000 + 2], "big")


def l(a):
    return int.from_bytes(ram[a - 0x800000:a - 0x800000 + 4], "big")


for a, n, s in [(0x8049ea, "TRRBOC", 2), (0x8049ec, "TRRBTMST", 4), (0x8049f0, "TRTMST", 4), (0x8049f4, "TRITTM", 2),
                (0x8049f6, "TRITWNLM", 2), (0x8049f8, "TRITWNTM", 2), (0x8049fa, "TRNOSATN", 2), (0x8049fc, "TRSAIN", 2),
                (0x8049fe, "TRNOSARB", 2), (0x804a00, "TRTRCDTM", 2), (0x804a02, "TRTRCDTR", 2), (0x804a04, "TRITWNAE", 2),
                (0x804a06, "TRITWNAL", 2), (0x804a08, "TRTRCD", 2), (0x804a0a, "TRAVNOCU", 2), (0x804a0c, "TRLDRNT2", 4),
                (0x804a10, "TRLDINAV", 2), (0x804a12, "TRTQCDID", 2), (0x804a14, "TRAVFLCN", 2), (0x804a16, "TRFLUSSR", 4),
                (0x808a7a, "TRNOSARQ", 2), (0x808a7c, "TRITTR", 2), (0x808a7e, "TRTRSATM", 2), (0x808a80, "TRESMX", 2),
                (0x808a82, "TRESMN", 2), (0x808a84, "TRPCLDMX", 2), (0x808a86, "TRPCLDMN", 2), (0x808a88, "TRIMTPMX", 2),
                (0x808a8a, "TRIMTPMN", 2), (0x808a8c, "TRCQMX", 2), (0x808a8e, "TRCQMN", 2),
                (0x801e98, "spd flag", 2), (0x801e9a, "load flag", 2), (0x801e9c, "imt flag", 2), (0x801e9e, "clt flag", 2),
                (0x801ea0, "minute div", 2)]:
    v = w(a) if s == 2 else l(a)
    print(f"0x{a:x} {n:10s} = 0x{v:x} ({v})")
print("byte 0x801ea2 =", ram[0x801ea2 - 0x800000])
for i in range(30):
    b = 0x804a1a + 14 * i
    oil, boost, clt, fuel, load = (w(b + 2 * k) for k in range(5))
    ts = l(b + 10)
    print(f"{i:2d} oil={oil:5d} boost={boost:5d} clt={clt:5d} ({clt / 128 - 50:.1f}F?) fuel={fuel} ({fuel * 0.125:.2f}gph) "
          f"load={load} ts=0x{ts:08x} hours={((ts & 0xffffff00) * 0.2 / 3600):.1f} tq=0x{ts & 0xff:02x}")

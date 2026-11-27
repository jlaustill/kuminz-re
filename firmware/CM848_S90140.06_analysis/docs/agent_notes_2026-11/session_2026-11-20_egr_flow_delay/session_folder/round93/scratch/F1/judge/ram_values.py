"""Judge F1: RAM dump values at the declared width (ram.bin = 0x800000..0x8091C1, extended_ram.bin = 0x809242..)."""
import struct

D = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM550_J90350.00_analysis/firmware/"
ram = open(D + "J90350.00.ram.bin", "rb").read()
ext = open(D + "J90350.00.extended_ram.bin", "rb").read()


def raw(a, n):
    if a < 0x800000 + len(ram):
        return ram[a - 0x800000:a - 0x800000 + n]
    return ext[a - 0x809242:a - 0x809242 + n]


def w(a):
    return struct.unpack(">H", raw(a, 2))[0]


def l(a):
    return struct.unpack(">I", raw(a, 4))[0]


WORDS = [("FSLMFL", 0x80dec8), ("FSLMFLST", 0x80deca), ("FSAPLMFL", 0x80decc), ("FLLMAHFL", 0x80dece), ("FSLMAHST", 0x80ded0),
         ("NZFLLM", 0x80a28c), ("AFFL", 0x80a8f6), ("ATFLLM", 0x80a922), ("EPFLLM", 0x80d284), ("FSMXTHFL", 0x80d368),
         ("PTSS", 0x80dc26), ("TQDQTQ", 0x80d338), ("TQDQTQST", 0x80d33a), ("PTMXEGLD", 0x80400e), ("JCEGMD", 0x80da50),
         ("JCTQLMFL", 0x80da62), ("WPTQLM", 0x80ccc6), ("WPLMFG", 0x80ccb2), ("WPSSFG", 0x80ccb4), ("FSTQDQUO", 0x803f2a),
         ("FSUOFL", 0x803f2c), ("FSGVFL", 0x80a8f0), ("FSGVFLST", 0x80a8f2), ("FSLMDSFL", 0x80d332), ("FSLMDSST", 0x80d334),
         ("FSFNFL", 0x80d32e), ("FSFNFLST", 0x80d330), ("FSMNFL", 0x80800a), ("FSMXFL", 0x808004), ("FSOSFL", 0x808008),
         ("EBFL", 0x808006), ("CKFL", 0x80d098), ("w698", 0x800698), ("FSLSSTFG", 0x80a908), ("MSODEN", 0x80a926),
         ("MSCNFG", 0x80d336), ("MSFNODFL", 0x80a924), ("TSMXTA", 0x808a74), ("d6", 0x8000d6), ("NZTALM", 0x80a28e),
         ("wsstate", 0x8036e2), ("TSAJ4DTA", 0x80aaa4), ("idleadj", 0x801a82), ("LSICBKRF", 0x805f0a),
         ("lifeavgprev", 0x801e92), ("tripavgprev", 0x801e94), ("TIEGAVLD", 0x806186), ("TIAVLD", 0x806188),
         ("ASRFST", 0x80a98e), ("engine_state", 0x80d0c8), ("TSOI", 0x80d346), ("TSTPTAST", 0x80d348),
         ("flags12", 0x803cac), ("flags18", 0x803cb8), ("flags1", 0x803c96), ("flags3", 0x803c9a), ("flags0", 0x803c94),
         ("flags32", 0x803cd4), ("LSMNRFTN", 0x803fca), ("LSMXRFTN", 0x803fcc), ("LSMNRF", 0x808342), ("LSMXRF", 0x808344)]
for name, a in WORDS:
    try:
        print(f"{name:12s} 0x{a:x} = {w(a)} (0x{w(a):04x})")
    except struct.error:
        print(f"{name:12s} 0x{a:x} : outside the dumps")
for name, a in [("CMEGTR", 0x80ccee), ("keyon", 0x80bda4), ("prevfuel", 0x801e82), ("TIITFU", 0x80619a), ("TIT3DQTM", 0x806192)]:
    try:
        print(f"{name:12s} 0x{a:x} = {l(a)}")
    except struct.error:
        print(f"{name:12s} 0x{a:x} : outside the dumps")
print("fso byte 0x80bcfb", hex(raw(0x80bcfb, 1)[0]), "prio 0x80bd47", hex(raw(0x80bd47, 1)[0]), "0x8000d7 byte", hex(raw(0x8000d7, 1)[0]))

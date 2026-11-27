# Search the CM848 ROM and flash2 images for big-endian 4-byte pointers and bl / b branches to the given addresses.
import sys, struct
base = '/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM848_S90140.06_analysis/originals/'
rom = open(base + 'cm848_rom.bin', 'rb').read()
fl2 = open(base + 'cm848_flash2_live.bin', 'rb').read()
images = [('rom', 0, rom), ('flash2', 0x500000, fl2)]
for a in sys.argv[1:]:
    t = int(a, 16)
    pat = struct.pack('>I', t)
    print('== target', hex(t))
    for nm, b, img in images:
        i = img.find(pat)
        while i >= 0:
            print('  pointer in', nm, 'at', hex(b + i))
            i = img.find(pat, i + 1)
        # branches: I-form opcode 18 (b / bl), relative
        for off in range(0, len(img) - 3, 4):
            w = struct.unpack('>I', img[off:off + 4])[0]
            if (w >> 26) == 18:
                li = w & 0x03fffffc
                if li & 0x02000000:
                    li -= 0x04000000
                aa = (w >> 1) & 1
                lk = w & 1
                dest = li if aa else (b + off + li)
                if dest == t:
                    print('  %s at %s in %s' % ('bl' if lk else 'b', hex(b + off), nm))

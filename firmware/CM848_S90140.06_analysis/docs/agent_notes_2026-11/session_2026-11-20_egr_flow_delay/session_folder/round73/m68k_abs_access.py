"""Find the m68k instructions that reference an absolute long address in a CM550 ROM image and print the opcode word
before it (the access width): cmpi / tst / move with the .b / .w / .l size.
usage: m68k_abs_access.py <rom.bin> <hex address> [...]"""
import re
import sys

KIND = {
    "0c39": "cmpi.b #imm,(abs).l", "0c79": "cmpi.w #imm,(abs).l", "0cb9": "cmpi.l #imm,(abs).l",
    "4a39": "tst.b (abs).l", "4a79": "tst.w (abs).l", "4ab9": "tst.l (abs).l",
    "1039": "move.b (abs).l,d0", "3039": "move.w (abs).l,d0", "2039": "move.l (abs).l,d0",
    "13fc": "move.b #imm,(abs).l", "33fc": "move.w #imm,(abs).l", "23fc": "move.l #imm,(abs).l",
    "4239": "clr.b (abs).l", "4279": "clr.w (abs).l", "42b9": "clr.l (abs).l",
    "5239": "addq.b #1,(abs).l", "5279": "addq.w #1,(abs).l",
}

rom = open(sys.argv[1], "rb").read()
for a in sys.argv[2:]:
    target = int(a, 16).to_bytes(4, "big")
    for m in re.finditer(re.escape(target), rom):
        o = m.start()
        found = [(k, KIND[rom[o - k:o - k + 2].hex()]) for k in (2, 4, 6) if rom[o - k:o - k + 2].hex() in KIND]
        print(f"{a} @ {o:#07x}: {rom[o - 6:o + 4].hex(' ')} -> {found or '?'}")

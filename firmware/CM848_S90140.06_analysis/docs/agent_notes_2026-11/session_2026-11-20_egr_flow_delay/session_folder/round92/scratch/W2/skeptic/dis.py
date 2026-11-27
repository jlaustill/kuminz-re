"""Skeptic: disassemble a CM550 ROM range with llvm-mc-18 (m68k), resynchronising after undecodable words.
usage: dis.py <rom> <start hex> <end hex>
Each instruction is decoded on its own (llvm-mc is fed a window starting at the current address), so the printed
address is exact. An undecodable word prints as .word and the cursor moves 2 bytes."""
import subprocess
import sys

rom = open(sys.argv[1], "rb").read()
start = int(sys.argv[2], 16)
end = int(sys.argv[3], 16)


def decode_one(addr):
    """Return (text, length) of the instruction at addr, or (None, 2)."""
    for length in (2, 4, 6, 8, 10):
        chunk = rom[addr:addr + length]
        if len(chunk) < length:
            break
        text = " ".join("0x%02x" % b for b in chunk)
        r = subprocess.run(["llvm-mc-18", "--disassemble", "--triple=m68k"], input=text, capture_output=True, text=True)
        out = [line.strip() for line in r.stdout.splitlines() if line.strip() and not line.strip().startswith(".text")]
        err = r.stderr
        if len(out) == 1 and "invalid instruction encoding" not in err and "warning" not in err:
            return out[0], length
    return None, 2


addr = start
while addr < end:
    text, length = decode_one(addr)
    raw = rom[addr:addr + length].hex()
    if text is None:
        print(f"{addr:06x}: {raw:<20} .word 0x{raw}")
    else:
        print(f"{addr:06x}: {raw:<20} {text}")
    addr += length

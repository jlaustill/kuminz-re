"""Access sizes of the MC68336 registers in the CM550 ROM: every absolute-long reference to an address is decoded with
llvm-mc-18 from a few candidate instruction starts before it. A candidate counts when it decodes cleanly, ends exactly
after the address, and its last instruction names the address. Prints address -> {size: count} and the undecoded count.
usage: register_access_sizes.py <rom.bin> <address list file (hex per line)>"""
import collections
import re
import subprocess
import sys

rom = open(sys.argv[1], "rb").read()
addresses = [int(x, 16) for x in open(sys.argv[2]).read().split()]
SIZE = re.compile(r"^\s*([a-z]+)\.([bwl])\s")


def decode(blob):
    text = " ".join(f"0x{b:02x}" for b in blob)
    out = subprocess.run(["llvm-mc-18", "--disassemble", "--triple=m68k", "-mcpu=M68020"], input=text,
                         capture_output=True, text=True)
    if "warning" in out.stderr or "error" in out.stderr:
        return None
    lines = [l for l in out.stdout.splitlines() if l.strip() and not l.strip().startswith(".text")]
    return lines


for address in addresses:
    needle = address.to_bytes(4, "big")
    sizes = collections.Counter()
    undecoded = 0
    start = 0
    while True:
        p = rom.find(needle, start)
        if p < 0:
            break
        start = p + 1
        if p % 2:
            continue
        found = None
        for back in (2, 4, 6, 8):
            s = p - back
            if s < 0:
                continue
            lines = decode(rom[s:p + 4])
            if not lines:
                continue
            last = lines[-1]
            if f"${address:x}" not in last:
                continue
            m = SIZE.match(last)
            found = (m.group(1) + "." + m.group(2)) if m else last.split()[0]
            break
        if found is None:
            undecoded += 1
        else:
            sizes[found] += 1
    print(f"0x{address:06x} {dict(sizes)} undecoded {undecoded}")

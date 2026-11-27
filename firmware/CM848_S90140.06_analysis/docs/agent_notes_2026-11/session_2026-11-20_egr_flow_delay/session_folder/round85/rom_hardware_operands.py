"""Scan each listed CM550 function's ROM bytes (from its entry to the next function entry in the .cpp) for 32-bit
values 0x00FFxxxx - absolute-long operands into the MC68336 / chip select register space - and print every value
other than the watchdog kick's SIM_SWSR (0xFFFA27) and CS2_WATCHDOG_SERVICE (0xFFD00F). The .cpp can drop blocks, so
this reads the ROM itself. Short-absolute operands are not covered (no decoder here).
usage: rom_hardware_operands.py <rom> <cpp> <hex address>..."""
import collections
import re
import sys

rom = open(sys.argv[1], "rb").read()
starts = sorted({int(a, 16) for a in re.findall(r"^// Function: \S+ @ (0x[0-9a-f]+)", open(sys.argv[2]).read(), re.M)})
for a in (int(x, 16) for x in sys.argv[3:]):
    later = [s for s in starts if s > a]
    end = later[0] if later else a + 0x400
    found = collections.Counter()
    for p in range(a, end - 3, 2):
        v = int.from_bytes(rom[p:p + 4], "big")
        if v >> 16 == 0x00FF and v not in (0x00FFFA27, 0x00FFD00F):
            found[f"0x{v:06x}@0x{p:05x}"] += 1
    print(f"0x{a:05x}-0x{end:05x}: {'clean' if not found else dict(found)}")

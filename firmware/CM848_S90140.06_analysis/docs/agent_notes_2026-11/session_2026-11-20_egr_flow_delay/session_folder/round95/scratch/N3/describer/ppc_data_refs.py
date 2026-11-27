"""D-form loads / stores (and addi) that reach a data address through lis rA,hi + disp(rA) in the CM848 images:
looks back up to 24 instructions for the lis of the base register (stops if the register is written otherwise).
usage: ppc_data_refs.py <0xADDR>..."""
import sys

BASE = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-egr-flow-delay/firmware/CM848_S90140.06_analysis/originals/"
IMAGES = ((BASE + "cm848_rom.bin", 0), (BASE + "cm848_flash2_live.bin", 0x500000))
NAMES = {32: "lwz", 33: "lwzu", 34: "lbz", 35: "lbzu", 36: "stw", 37: "stwu", 38: "stb", 39: "stbu", 40: "lhz",
         41: "lhzu", 42: "lha", 43: "lhau", 44: "sth", 45: "sthu", 14: "addi"}
targets = [int(a, 16) for a in sys.argv[1:]]
for path, base in IMAGES:
    data = open(path, "rb").read()
    words = [int.from_bytes(data[i:i + 4], "big") for i in range(0, len(data) - 3, 4)]
    for index, word in enumerate(words):
        opcode = word >> 26
        if opcode not in NAMES:
            continue
        register_a = (word >> 16) & 0x1F
        if register_a == 0:
            continue
        displacement = word & 0xFFFF
        if displacement & 0x8000:
            displacement -= 0x10000
        for back in range(index - 1, max(index - 25, -1), -1):
            previous = words[back]
            previous_opcode = previous >> 26
            destination = (previous >> 21) & 0x1F
            if previous_opcode == 15 and destination == register_a and ((previous >> 16) & 0x1F) == 0:
                value = (((previous & 0xFFFF) << 16) + displacement) & 0xFFFFFFFF
                if value in targets:
                    print(f"0x{base + index * 4:x}: {NAMES[opcode]} -> 0x{value:x} (lis at 0x{base + back * 4:x})")
                break
            if destination == register_a and previous_opcode in (14, 15, 24, 25, 31, 32, 33, 34, 35, 40, 41, 42, 43, 21):
                break

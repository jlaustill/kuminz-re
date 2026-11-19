"""Print the combustion torque by fuel quantity grid (0x405d9c, 304 signed words) as rows of 19 and of 16."""
import sys

sys.argv = ["peek"]
FW = "/home/linux/code/kuminz-re/.claude/worktrees/cm848-fueling-state-enum/firmware/CM848_S90140.06_analysis/originals/"
ram = open(FW + "cm848_ram.bin", "rb").read()


def words(address, count, signed=True):
    at = address - 0x3FA000
    return [int.from_bytes(ram[at + 2 * i:at + 2 * i + 2], "big", signed=signed) for i in range(count)]


x = words(0x405d52, 20)
y = words(0x405d7a, 17)
grid = words(0x405d9c, 304)
print("x axis (rpm x 8):", x[1:], "bytes", x[0])
print("y axis (fuel counts):", y[1:], "bytes", y[0])
print("--- rows of 19 (x = rpm across), one row per fuel breakpoint")
for r in range(16):
    print(f"fuel {y[1 + r]:5d}:", grid[r * 19:(r + 1) * 19])

import sys
sys.path.insert(0, "/home/linux/code/kuminz-re/.claude/worktrees/cm848-typing-arrays/firmware/scripts")
import lookup_tables as L

M = L.MemoryImage()


def w(a):
    return M.word(a)


def s(a):
    v = M.word(a)
    return None if v is None else (v - 65536 if v >= 32768 else v)


def b(a):
    # one byte, read through the word that holds it
    base = a & ~1
    v = M.word(base)
    if v is None:
        return None
    return (v >> 8) & 0xFF if a == base else v & 0xFF


def axis(a, signed=False):
    n = w(a) // 2
    f = s if signed else w
    return [f(a + 2 + 2 * i) for i in range(n)]


def grid(a, nx, ny, signed=False):
    f = s if signed else w
    return [[f(a + 2 * (y * nx + x)) for x in range(nx)] for y in range(ny)]


def uniq(a, n, signed=False):
    f = s if signed else w
    return sorted(set(f(a + 2 * i) for i in range(n)))

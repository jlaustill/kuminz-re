"""Round 75 stage A4 (CM550) copy of prove_r68.py with this round's renders as exact replacements. Round 68 label proof: every function body of the old and new .cpp is compared after the old one gets the round's
renames as exact string replacements (prove_r67.sh's \\b-bounded regexes cannot match labels that end in ']'),
casts to the plain integer types are dropped, and comments and whitespace are ignored. Prints each differing function.
usage: prove_r68.py <old.cpp> <new.cpp>"""
import re
import sys

PAIRS = [
    ('cm550_startJ1708Transmission', 'mc68k_startJ1708Transmission'),
    ('cm550_initializeJ1708Datalink', 'mc68k_initializeJ1708Datalink'),
    ('Ram00fffc08', 'QSM_SCCR0'),
    ('Ram00fffc0a', 'QSM_SCCR1'),
    ('Ram00fffc0c', 'QSM_SCSR'),
    ('Ram00fffc0e', 'QSM_SCDR'),
]
CAST = re.compile(r"\((short|ushort|int|uint|word|dword|undefined1|undefined2|undefined4|char|uchar|byte|longlong|"
                  r"ulonglong)\)")


def bodies(path, rename):
    t = open(path, errors="replace").read()
    parts = re.split(r"^// Function: (\S+) @[^\n]*\n", t, flags=re.M)
    out = {}
    for i in range(1, len(parts), 2):
        b = re.sub(r"/\*.*?\*/", "", parts[i + 1], flags=re.S)
        if rename:
            for old, new in PAIRS:  # boundary-aware: a name that is a prefix of another must not rename it
                b = re.sub(r"(?<![A-Za-z0-9_])" + re.escape(old) + r"(?![A-Za-z0-9_])", new, b)
        b = CAST.sub("", b).replace("'\\0'", "0").replace("'\\x01'", "1")
        key = parts[i]
        if rename:  # a renamed function: compare it under its new name (exact match - not a substring)
            key = dict(PAIRS).get(key, key)
        out[key] = re.sub(r"\s+", "", b)
    return out


if __name__ == "__main__":
  old_b, new_b = bodies(sys.argv[1], True), bodies(sys.argv[2], False)
  diff = [f for f in old_b if old_b[f] != new_b.get(f)]
  print(f"functions {len(old_b)}; differing after the renames: {len(diff)}")
  for f in diff:
      print(" ", f)

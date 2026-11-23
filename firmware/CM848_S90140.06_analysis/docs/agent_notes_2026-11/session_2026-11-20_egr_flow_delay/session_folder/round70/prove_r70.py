"""Round 70 copy of prove_r68.py with this round's renders as exact replacements. Round 68 label proof: every function body of the old and new .cpp is compared after the old one gets the round's
renames as exact string replacements (prove_r67.sh's \\b-bounded regexes cannot match labels that end in ']'),
casts to the plain integer types are dropped, and comments and whitespace are ignored. Prints each differing function.
usage: prove_r68.py <old.cpp> <new.cpp>"""
import re
import sys

PAIRS = [
    ("TPU3_TPUMCR", "dual_port_tpu_ram_start"),
    ("DAT_00303800", "dual_port_tpu_ram_end"),
    ("DAT_000591f6", "first_checksum_region_end_marker"),
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
            for old, new in PAIRS:
                b = b.replace(old, new)
        b = CAST.sub("", b).replace("'\\0'", "0").replace("'\\x01'", "1")
        out[parts[i]] = re.sub(r"\s+", "", b)
    return out


old_b, new_b = bodies(sys.argv[1], True), bodies(sys.argv[2], False)
diff = [f for f in old_b if old_b[f] != new_b.get(f)]
print(f"functions {len(old_b)}; differing after the renames: {len(diff)}")
for f in diff:
    print(" ", f)

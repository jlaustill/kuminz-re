"""Round 73 stage A copy of prove_r68.py with this round's renders as exact replacements. Round 68 label proof: every function body of the old and new .cpp is compared after the old one gets the round's
renames as exact string replacements (prove_r67.sh's \\b-bounded regexes cannot match labels that end in ']'),
casts to the plain integer types are dropped, and comments and whitespace are ignored. Prints each differing function.
usage: prove_r68.py <old.cpp> <new.cpp>"""
import re
import sys

PAIRS = [
    ('ecu_identity_test_pattern', 'security_master_password_cal'),
    ('DAT_00801e76', 'security_key_failure_count'),
    ('_DAT_00803b98', 'calibration_download_security_key_cal'),
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


old_b, new_b = bodies(sys.argv[1], True), bodies(sys.argv[2], False)
diff = [f for f in old_b if old_b[f] != new_b.get(f)]
print(f"functions {len(old_b)}; differing after the renames: {len(diff)}")
for f in diff:
    print(" ", f)

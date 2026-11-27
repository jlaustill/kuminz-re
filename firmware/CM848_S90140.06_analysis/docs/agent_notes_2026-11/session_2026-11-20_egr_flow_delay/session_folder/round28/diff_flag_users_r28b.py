"""Round 28 stage B: statement diff of the ring flag users after mapping the old pieces to the new field names and
the old 'char' compares ('\\x01' / '\\0') to the byte forms; temps are renamed by first appearance on both sides.
usage: diff_flag_users_r28b.py <old cpp> <new cpp> <function>..."""
import difflib
import re
import sys

old_cpp, new_cpp, names = sys.argv[1], sys.argv[2], sys.argv[3:]


def body(path, name):
    t = open(path, errors="replace").read()
    m = re.search(r"^// Function: " + re.escape(name) + r" @[^\n]*\n(.*?)(?=^// Function: )", t, re.S | re.M)
    s = re.sub(r"/\*.*?\*/", "", m.group(1), flags=re.S)
    return re.sub(r"\s+", " ", s)


def canon(s):
    s = s.replace("boot_can_ring_state._pad16._0_1_", "boot_can_ring_state.transmit_ring_full_flag")
    s = s.replace("boot_can_ring_state._pad16._1_1_", "boot_can_ring_state.receive_ring_full_flag")
    s = s.replace("'\\x01'", "1").replace("'\\0'", "0")
    # drop the local declarations (a removed temp renumbers the rest), then rename temps by first use in the body
    s = re.sub(r"(?<=[{;}]) ?(?:const )?[A-Za-z_][A-Za-z0-9_]* \**[A-Za-z_][A-Za-z0-9_]*(?:\[\d+\])?;", "", s)
    seen = {}
    s = re.sub(r"\b[cbuiwsdp][A-Za-z]*Var\d+\b",
               lambda m: seen.setdefault(m.group(0), f"T{len(seen)}"), s)
    s = re.sub(r"\b(char|byte|undefined1) (T\d+);", r"BYTE \2;", s)
    return [x.strip() for x in re.split(r"(?<=[;{}])", s) if x.strip()]


ANON = "--anonymous-temps" in sys.argv
names = [n for n in names if not n.startswith("--")]


def anonymize(lines):
    """Every temp (and the propagated frame_words name) becomes T, casts to word * / undefined2 * / dword drop out:
    what stays is each statement's operators, constants and globals."""
    out = []
    for l in lines:
        l = re.sub(r"\bT\d+\b|\bframe_words\b", "T", l)
        l = re.sub(r"\((?:word|undefined2|dword|undefined1|byte) \*\)|\((?:dword|word|byte)\)", "", l)
        out.append(l)
    return sorted(out)


for name in names:
    a, b = canon(body(old_cpp, name)), canon(body(new_cpp, name))
    if ANON:
        a, b = anonymize(a), anonymize(b)
    d = [l for l in difflib.unified_diff(a, b, n=0, lineterm="") if l[:1] in "+-" and l[:3] not in ("---", "+++")]
    print(f"== {name}: {len(d)} differing statements")
    for l in d[:8]:
        print("   " + l[:200])

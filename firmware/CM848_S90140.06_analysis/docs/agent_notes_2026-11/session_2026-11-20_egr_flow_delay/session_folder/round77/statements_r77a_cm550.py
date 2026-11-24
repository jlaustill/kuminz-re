"""Compare functions statement by statement (the body joined, split at ';', '{' and '}', whitespace removed, temporaries
renumbered, casts dropped) after prove_r77a_cm550.py's renames - line wrapping cannot show up here.
usage: statements_r77a_cm550.py <old.cpp> <new.cpp>"""
import collections
import re
import sys

sys.path.insert(0, "/home/linux/.claude/jobs/374b0424/tmp/w15/r77")
sys.argv, args = sys.argv[:1] + ["/dev/null", "/dev/null"], sys.argv[1:]
import prove_r77a_cm550 as p  # noqa: E402  (runs on /dev/null - harmless)

DECL = re.compile(r"^[A-Za-z_][A-Za-z0-9_ ]*\**\s+\**[A-Za-z_][A-Za-z0-9_]*(\[\w+\])?$")


def statements(path, rename):
    t = open(path, errors="replace").read()
    parts = re.split(r"^// Function: (\S+) @[^\n]*\n", t, flags=re.M)
    out = {}
    for i in range(1, len(parts), 2):
        b = re.sub(r"/\*.*?\*/", "", parts[i + 1], flags=re.S)
        key = parts[i]
        if rename:
            for old, new in p.PAIRS:
                b = b.replace(old, new)
            key = dict(p.PAIRS).get(key, key)
        b = p.CAST.sub("", p.TEMP.sub("T", b)).replace("'\\x01'", "1").replace("'\\0'", "0")
        b = re.sub(r"case\(BADTYPE\)0x([0-9a-f]+):", lambda m: f"case{int(m.group(1), 16)}:", re.sub(r"\s+", "", b))
        stm = [s for s in re.split(r"[;{}]", b) if s and not DECL.match(s)]
        out[key] = collections.Counter(stm)
    return out


old_s, new_s = statements(args[0], True), statements(args[1], False)
for f in old_s:
    if old_s[f] != new_s.get(f):
        gone, came = old_s[f] - new_s.get(f, collections.Counter()), new_s.get(f, collections.Counter()) - old_s[f]
        print(f"== {f}: {sum(gone.values())} statements gone, {sum(came.values())} new")
        for s in gone:
            print("   - " + s[:140])
        for s in came:
            print("   + " + s[:140])

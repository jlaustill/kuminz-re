"""Round 97 stage F: rows whose comment holds the same '(was <name>; PR #53 round N)' note twice (the R6 apply restated a
note that a judge's final plate already carried). With --fix, the second copy (and the ' | ' or space before it) goes.
usage: repeated_notes_r97f.py [--fix] <csv>..."""
import re
import sys

fix = "--fix" in sys.argv
NOTE = re.compile(r"\(was [^()]*?; PR #53 round \d+\)")
for p in [a for a in sys.argv[1:] if a != "--fix"]:
    t = open(p, newline="").read()
    E = "\r\n" if "\r\n" in t else "\n"
    lines = t.split(E)
    n = 0
    for k, l in enumerate(lines):
        notes = NOTE.findall(l)
        dup = {x for x in notes if notes.count(x) > 1}
        if not dup:
            continue
        n += 1
        print(f"{p.split('/')[-3][:5]} {p.split('/')[-1]}:{k + 1}: {sorted(dup)}")
        if fix:
            for x in dup:
                first = l.find(x) + len(x)
                rest = l[first:]
                second = rest.find(x)
                pre = rest[:second]
                cut = len(pre.rstrip(" |")) if pre.rstrip(" |") != pre else len(pre)
                l = l[:first] + rest[:cut] + rest[second + len(x):]
            lines[k] = l
    if fix and n:
        open(p, "w", newline="").write(E.join(lines))
    print(p.split("/")[-1], n, "rows")

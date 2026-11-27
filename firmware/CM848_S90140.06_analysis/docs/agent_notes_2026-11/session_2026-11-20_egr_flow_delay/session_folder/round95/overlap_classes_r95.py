"""Round 95 (read-only): every CM848 (or CM550) global row that starts inside another typed row's span, classified:
documentation rows (a 'name.field' / 'name[n]' path: they label a field or element on purpose), unnamed rows (a type
only) and plain named rows (a separate name inside a typed span: the suspects), each plain row with how often its
name renders in the .cpp. usage: overlap_classes_r95.py <repo> <CM848|CM550> [--list]"""
import importlib.util
import os
import re
import sys

repo, fw = os.path.abspath(sys.argv[1]), sys.argv[2]
spec = importlib.util.spec_from_file_location("oc", "/home/linux/.claude/jobs/374b0424/tmp/w15/r94/overlap_check_r94.py")
src = open(spec.origin).read().split("\nrepo = os.path.abspath")[0]      # the helpers only, not the script's main
ns = {}
exec(compile(src, spec.origin, "exec"), ns)
out = ns["FIRMWARES"][fw]
found, _ = ns["overlaps"](repo, out)
cpp_name = "cm848_rom.ghidra.cpp" if fw == "CM848" else "J90350.00.ghidra.cpp"
cpp = open(os.path.join(repo, out, cpp_name), errors="replace").read()
doc = [f for f in found if "." in f[1] or "[" in f[1]]
unnamed = [f for f in found if not f[1]]
plain = [f for f in found if f[1] and f not in doc]
print(f"{fw}: {len(found)} rows inside a typed span: {len(doc)} documentation, {len(unnamed)} unnamed, {len(plain)} plain named")
if "--list" in sys.argv:
    for a, n, t, (ha, hn, ht) in plain:
        uses = len(re.findall(rf"(?<![A-Za-z0-9_])_?{re.escape(n)}(?![A-Za-z0-9_])", cpp))
        print(f"   0x{a:x} {n} {t or '-'} renders {uses}; inside 0x{ha:x} {hn} {ht}")
if "--fields" in sys.argv:
    import csv
    sd = os.path.join(repo, out, "structure_definitions.csv")
    fields = {}
    rows = list(csv.reader(l for l in open(sd, newline="") if not l.startswith("#")))
    for r in rows[1:]:
        if len(r) >= 5 and r[0] and r[2]:
            fields.setdefault(r[0], []).append((r[2], r[3], r[4]))

    def field_at(struct, offset):
        o = 0
        for name, typ, size in fields.get(struct, []):
            try:
                s = int(size, 0)
            except ValueError:
                s = 0
            if o == offset:
                return f"{name}:{typ}"
            o += s
        return "?"
    for a, n, t, (ha, hn, ht) in plain:
        print(f"   0x{a:x} {n} ({t or '-'}) = {ht}+0x{a - ha:x} field {field_at(ht, a - ha)}")

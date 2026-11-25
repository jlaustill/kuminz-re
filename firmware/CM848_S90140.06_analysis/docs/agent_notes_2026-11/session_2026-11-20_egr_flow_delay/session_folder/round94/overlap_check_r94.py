"""Round 94 (read-only): every global row that starts strictly inside the span of an earlier typed row (the span from
the row's type: primitives, enums from enums.csv, structs from structure_definitions.csv, T[N] arrays), per firmware.
With --since <git rev> only the overlaps that rev did not have are printed. usage:
overlap_check_r94.py <repo> [--since <rev>]"""
import csv
import io
import os
import re
import subprocess
import sys

PRIMITIVE = {"byte": 1, "char": 1, "uchar": 1, "bool": 1, "undefined1": 1, "int8_t": 1, "uint8_t": 1, "i8": 1, "u8": 1,
             "word": 2, "short": 2, "ushort": 2, "i16": 2, "u16": 2, "undefined2": 2, "int16_t": 2, "uint16_t": 2,
             "dword": 4, "int": 4, "uint": 4, "i32": 4, "u32": 4, "pointer": 4, "float": 4, "undefined4": 4,
             "int32_t": 4, "uint32_t": 4, "addr": 4, "qword": 8, "double": 8, "undefined8": 8}
FIRMWARES = {"CM550": "firmware/CM550_J90350.00_analysis/output", "CM848": "firmware/CM848_S90140.06_analysis/output"}


def read(repo, path, rev):
    if rev:
        return subprocess.run(["git", "-C", repo, "show", f"{rev}:{path}"], capture_output=True, text=True).stdout
    return open(os.path.join(repo, path), newline="").read()


def overlaps(repo, out, rev=None):
    enums, structs = {}, {}
    for r in csv.reader(io.StringIO(read(repo, f"{out}/enums.csv", rev))):
        if len(r) > 4 and r[0] and not r[0].startswith("#") and r[4].strip().isdigit():
            enums.setdefault(r[0], int(r[4]))
    for r in csv.reader(io.StringIO(read(repo, f"{out}/structure_definitions.csv", rev))):
        if len(r) > 4 and r[0] and not r[0].startswith("#") and r[4].strip().isdigit():
            structs[r[0]] = structs.get(r[0], 0) + int(r[4])

    def width(t):
        t = t.strip().rstrip("*") if not t.strip().endswith("*") else "pointer"
        m = re.match(r"^(.+?)((\[\d+\])+)$", t)
        if m:
            n = 1
            for d in re.findall(r"\[(\d+)\]", m.group(2)):
                n *= int(d)
            w = width(m.group(1))
            return None if w is None else w * n
        if t in ("", "undefined"):
            return 1
        return PRIMITIVE.get(t) or enums.get(t) or structs.get(t)

    rows = []
    for line in read(repo, f"{out}/global_variables.csv", rev).split("\n"):
        parts = line.rstrip("\r").split(",", 3)
        if len(parts) > 2 and parts[0].startswith("0x"):
            rows.append((int(parts[0], 16), parts[1], parts[2]))
    rows.sort()
    found, unknown = [], set()
    end, holder = -1, None
    for address, name, typ in rows:
        if address < end:
            found.append((address, name, typ, holder))
        w = width(typ)
        if w is None:
            unknown.add(typ)
            w = 1
        if address + w > end:
            end, holder = address + w, (address, name, typ)
    return found, unknown


repo = os.path.abspath(sys.argv[1])
since = sys.argv[sys.argv.index("--since") + 1] if "--since" in sys.argv else None
for fw, out in FIRMWARES.items():
    now, unknown = overlaps(repo, out)
    old = {(a, n) for a, n, _, _ in overlaps(repo, out, since)[0]} if since else set()
    new = [f for f in now if (f[0], f[1]) not in old]
    print(f"{fw}: {len(now)} rows inside another row's span" + (f", {len(new)} new since {since}" if since else "")
          + (f"; types with no width: {sorted(unknown)[:8]}" if unknown else ""))
    for address, name, typ, (ha, hn, ht) in (new if since else now)[:40]:
        print(f"   0x{address:x} {name} {typ}  inside 0x{ha:x} {hn} {ht}")

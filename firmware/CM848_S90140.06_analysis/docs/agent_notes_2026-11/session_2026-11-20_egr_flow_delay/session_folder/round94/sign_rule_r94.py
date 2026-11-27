"""Round 94 (read-only): one sign rule for the 1943 rows typed in round 93. Round 93 pass 1 followed the code's casts
(and Calterm's S flag), pass 2 followed Calterm's flag only, so seven pass 2 rows the code reads signed stayed
unsigned. The rule here, for every typed row:
- the CODE decides when its uses agree: a signed use is a signed cast on the row - '(short)_name' / '(int)_name' /
  '(char)_name' in the render before typing (the row was 'undefined', so each use carried its own cast) or
  '(short)name' / '(int)name' / '(char)name' once typed unsigned; an unsigned use is '(ushort)' / '(uint)' / '(byte)'
  on the untyped row, or on the row once typed signed. Only signed uses -> signed; only unsigned uses -> unsigned.
- otherwise (no cast, or both kinds) Calterm's S / U flag decides where the row has a record, else unsigned.
Writes address,name,current,decided,reason for the rows whose type would change.
usage: sign_rule_r94.py <repo> <r93 dir> <out.csv>"""
import csv
import importlib.util
import os
import re
import sys

repo, r93, out = os.path.abspath(sys.argv[1]), sys.argv[2], sys.argv[3]


def code(path):
    t = open(path, errors="replace").read()
    t = re.sub(r"/\*.*?\*/", " ", t, flags=re.S)
    return "\n".join(l for l in t.split("\n") if not l.lstrip().startswith("//"))


def casts(text, prefix=""):
    sig, uns = {}, {}
    for m in re.finditer(rf"\((short|int|long|char)\)\s*{prefix}([A-Za-z][A-Za-z0-9_]*)\b", text):
        sig[m.group(2)] = sig.get(m.group(2), 0) + 1
    for m in re.finditer(rf"\((ushort|uint|ulong|byte|uchar)\)\s*{prefix}([A-Za-z][A-Za-z0-9_]*)\b", text):
        uns[m.group(2)] = uns.get(m.group(2), 0) + 1
    return sig, uns


O = os.path.join(repo, "firmware/CM550_J90350.00_analysis/output")
now_sig, now_uns = casts(code(os.path.join(O, "J90350.00.ghidra.cpp")))
passes = [  # (rows csv, render before typing, render typed unsigned)
    (os.path.join(r93, "untyped_pass_r93.csv"), os.path.join(r93, "pre_r93ty_cm550.cpp"), os.path.join(r93, "post_r93ty1_cm550.cpp")),
    (os.path.join(r93, "e2m_typed_final_r93.csv"), os.path.join(r93, "pre_r93te_cm550.cpp"), None),
]
# Calterm flags by address (N records)
spec = importlib.util.spec_from_file_location("eba", os.path.join(repo, "firmware/scripts/e2m_block_addresses.py"))
eba = importlib.util.module_from_spec(spec)
spec.loader.exec_module(eba)
rom = open(os.path.join(repo, "firmware/CM550_J90350.00_analysis/firmware/J90350.00.rom.bin"), "rb").read()
table = eba.parse_cm550_table(rom)
flag = {}
for line in open(os.path.join(repo, "e2m-analysis/originals/v64t6_s.e2m"), errors="replace"):
    f = line.split(";", 1)[0].rstrip("\r\n").split(",")
    if len(f) < 10 or f[5].strip() != "N":
        continue
    try:
        block, offset = int(f[2], 16), int(f[3], 16)
    except ValueError:
        continue
    if block == 0 or table.get(block) is None:
        continue
    flag.setdefault(eba.cm550_ram_address(table[block] + offset), set()).add(f[9].strip())
live = {}
for line in open(os.path.join(O, "global_variables.csv"), newline="").read().split("\n"):
    parts = line.split(",", 3)
    if len(parts) > 2 and parts[0].startswith("0x"):
        live[parts[0].lower()] = (parts[1], parts[2])
SIGNED = {"byte": "i8", "word": "i16", "dword": "i32"}
UNSIGNED = {v: k for k, v in SIGNED.items()}
changes, counts = [], {}
for rows_csv, before_path, unsigned_path in passes:
    b_sig, b_uns = casts(code(before_path), "_")
    u_sig = casts(code(unsigned_path))[0] if unsigned_path else {}
    for r in csv.DictReader(open(rows_csv)):
        a = r["address"].lower()
        if a not in live:
            continue
        name, current = live[a]
        if current not in SIGNED and current not in UNSIGNED:
            continue                                    # no longer a plain integer (a later round typed it otherwise)
        is_signed = current in UNSIGNED
        s = b_sig.get(name, 0) + u_sig.get(name, 0) + (0 if is_signed else now_sig.get(name, 0))
        u = b_uns.get(name, 0) + (now_uns.get(name, 0) if is_signed else 0)
        if s and not u:
            want, why = True, f"code: {s} signed uses, no unsigned use"
        elif u and not s:
            want, why = False, f"code: {u} unsigned uses, no signed use"
        else:
            f = flag.get(int(a, 16), set())
            if f == {"S"}:
                want, why = True, ("code mixed (%d / %d); " % (s, u) if s else "no cast; ") + "Calterm S"
            elif f == {"U"}:
                want, why = False, ("code mixed (%d / %d); " % (s, u) if s else "no cast; ") + "Calterm U"
            else:
                want, why = is_signed, "no evidence either way: unchanged"
        decided = (current if is_signed else SIGNED[current]) if want else (UNSIGNED[current] if is_signed else current)
        counts[(current, decided)] = counts.get((current, decided), 0) + 1
        if decided != current:
            changes.append((r["address"], name, current, decided, why))
with open(out, "w") as fh:
    w = csv.writer(fh)
    w.writerow(["address", "name", "current", "decided", "reason"])
    w.writerows(changes)
print({f"{a}->{b}": n for (a, b), n in sorted(counts.items())})
for c in changes:
    print("CHANGE", c)

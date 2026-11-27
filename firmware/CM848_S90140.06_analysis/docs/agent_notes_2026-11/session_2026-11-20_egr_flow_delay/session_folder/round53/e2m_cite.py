"""Round 53: the shared helpers of the e2m citation stages (rounds 51-52 copied them per script).
  Records(repo): the default-release e2m records, value labels merged over duplicate records.
  Rows(repo, round_tag): global_variables.csv with cite_only / rename / add / save, the rename map and the banned-word
  check of apply_hand_worklist.py.
  cite(): 'e2m BLOCK +OFF Name 'description' (unit, scale per count; value = engineering value in the dump / ROM).'"""
import ast
import os
import re

HAND = "/home/linux/.claude/jobs/374b0424/tmp/w15/apply_hand_worklist.py"
BANNED = ast.literal_eval(re.search(r"BANNED = (\{.*?\})", open(HAND).read(), re.S).group(1))
WIDTH = {"byte": 1, "word": 2, "i16": 2, "dword": 4}


def numeric_scale(scale):
    """a number only with a decimal point / exponent or without a leading zero; '00FF' / '0004' are enumerations"""
    if re.fullmatch(r"0[0-9A-Fa-f]+", scale) or re.search(r"[A-Da-fF]", scale.replace("E-", "").replace("E+", "")):
        return None
    try:
        return float(scale)
    except ValueError:
        return None


class Records:
    def __init__(self, repo, release="CHR_CC_11.45.01.07.e2m"):
        cm = os.path.join(repo, "firmware/CM848_S90140.06_analysis")
        self.ram = open(os.path.join(cm, "originals/cm848_ram.bin"), "rb").read()
        self.rom = open(os.path.join(cm, "originals/cm848_rom.bin"), "rb").read()
        self.recs, labels = {}, {}
        for line in open(os.path.join(repo, "e2m-analysis/CHR", release), errors="replace"):
            head, _, desc = line.strip().partition(";")
            f = head.split(",")
            if len(f) > 11 and re.fullmatch(r"[0-9A-Fa-f]{4}", f[2]) and re.fullmatch(r"[0-9A-Fa-f]{1,4}", f[3]):
                key = (int(f[2], 16), int(f[3], 16))
                self.recs.setdefault(key, [f[0], f[1], f[7], f[9], f[10], desc.strip(), ""])
                if len(f) > 19 and "=" in f[19]:
                    labels.setdefault(key, set()).update(x for x in f[19].split(":") if "=" in x)
        for key, labs in labels.items():
            self.recs[key][6] = ":".join(sorted(labs, key=lambda x: int(x.split("=")[0], 16)))

    def block(self, block):
        return sorted(o for (b, o) in self.recs if b == block)

    def size(self, block, off):
        return int(self.recs[(block, off)][2])

    def cite(self, block, off, a):
        name, unit, size, sign, scale, desc, labels = self.recs[(block, off)]
        size = int(size)
        if 0x3FA000 <= a < 0x3FA000 + len(self.ram):
            v, where = int.from_bytes(self.ram[a - 0x3FA000:a - 0x3FA000 + size], "big"), "the dump"
        else:
            v, where = int.from_bytes(self.rom[a:a + size], "big"), "ROM"
        if sign == "S" and v >> (8 * size - 1):
            v -= 1 << (8 * size)
        head = f"e2m {block:04X} +{off:X} {name} '{desc}'"
        if unit.upper() == "HEX":
            return f"{head} (bit-mapped; 0x{v:0{2 * size}x} in {where})."
        s = numeric_scale(scale)
        unit = f"{unit}, " if unit.upper() not in ("NONE", "UNITLESS", "") else ""
        if s is None:
            lab = f" {labels.replace(':', ' / ')};" if labels else ""
            return f"{head} ({unit}enumerated;{lab} {v} in {where})."
        return f"{head} ({unit}{'signed, ' if sign == 'S' else ''}{s:g} per count; {v} = {v * s:.6g} in {where})."


class Rows:
    def __init__(self, repo, tag):
        self.path = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output/global_variables.csv")
        self.g = open(self.path).read().split("\n")
        self.tag = tag
        self.names = {l.split(",")[1] for l in self.g if l.startswith("0x") and len(l.split(",")) > 1}
        self.mapping = ["address,name,old_label,kind,dims"]
        self.reindex()

    def reindex(self):
        self.idx = {l[:10]: k for k, l in enumerate(self.g) if l.startswith("0x")}

    def row(self, a):
        p = self.g[self.idx[a]].split(",", 3)
        return p + [""] * (4 - len(p))

    def has(self, a):
        return a in self.idx

    def check(self, new):
        assert new not in self.names and not any(t in BANNED for t in new.split("_")), new
        self.names.add(new)

    def cite_only(self, records, a, cur, block, off, extra=""):
        p = self.row(a)
        assert p[1] == cur, (a, p[1], cur)
        assert f"e2m {block:04X} +{off:X} " not in p[3], (a, "already cited")
        self.g[self.idx[a]] = f"{a},{p[1]},{p[2]},{records.cite(block, off, int(a, 16))}{extra} ({self.tag}) {p[3]}".rstrip()

    def rename(self, records, a, cur, new, block, off, text):
        p = self.row(a)
        assert p[1] == cur, (a, p[1], cur)
        self.check(new)
        head = (records.cite(block, off, int(a, 16)) + " " if block is not None else "") + text
        self.g[self.idx[a]] = (f"{a},{new},{p[2]},{head} (was {cur}; {self.tag})"
                               + (f" | earlier note: {p[3]}" if p[3] else ""))
        self.mapping.append(f"{a},{new},{cur},global,1")

    def add(self, records, a, new, typ, block, off, text, rendered):
        assert a not in self.idx, a
        self.check(new)
        later = sorted(x for x in self.idx if int(x, 16) > int(a, 16))
        line = f"{a},{new},{typ},{records.cite(block, off, int(a, 16))} {text} ({self.tag})"
        self.g.insert(self.idx[later[0]] if later else len(self.g), line)
        self.reindex()
        if rendered:
            self.mapping.append(f"{a},{new},{rendered},global,1")

    def add_text(self, a, new, typ, text, rendered):
        """a new row whose comment is written by hand (e.g. a table, where cite() would read the byte-length word)"""
        assert a not in self.idx, a
        self.check(new)
        later = sorted(x for x in self.idx if int(x, 16) > int(a, 16))
        self.g.insert(self.idx[later[0]] if later else len(self.g), f"{a},{new},{typ},{text} ({self.tag})")
        self.reindex()
        if rendered:
            self.mapping.append(f"{a},{new},{rendered},global,1")

    def save(self, map_path):
        open(self.path, "w").write("\n".join(self.g))
        with open(map_path, "w") as fh:
            fh.write("\n".join(self.mapping) + "\n")


def place(records, rows, block, base, renames, new_rows, note, elsewhere=()):
    """cite every record of the block that sits on a row (width checked), rename the `renames` rows, add the
    `new_rows` (accessed records without a row); records with neither are listed in the first row's note, except
    the `elsewhere` addresses (covered by a row in another CSV, e.g. arrays.csv)"""
    offs = records.block(block)
    missing = [f"+{off:X} {records.recs[(block, off)][0]}" for off in offs
               if not rows.has(f"0x{base + off:08x}") and f"0x{base + off:08x}" not in new_rows
               and base + off not in elsewhere]
    if missing:
        note += f"; {', '.join(missing)} have no row (no direct access found)"
    first = True
    for off in offs:
        a = f"0x{base + off:08x}"
        extra = note if first else ""
        if rows.has(a):
            p = rows.row(a)
            w = WIDTH.get(p[2])
            assert w is None or w == records.size(block, off), (a, p[1], p[2], records.size(block, off))
            if a in renames:
                cur, new, text = renames[a]
                rows.rename(records, a, cur, new, block, off, text + extra)
            else:
                rows.cite_only(records, a, p[1], block, off, extra)
            first = False
        elif a in new_rows:
            new, typ, text, rendered = new_rows[a]
            rows.add(records, a, new, typ, block, off, text + extra, rendered)
            first = False
    return missing

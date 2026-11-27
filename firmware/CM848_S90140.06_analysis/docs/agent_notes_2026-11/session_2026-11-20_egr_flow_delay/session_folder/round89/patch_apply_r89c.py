"""Patch apply_r89c.py (round 89 stage C, second pass): the stem is the most common prefix of a channel's 15 config
names (channel 19's filter constant ADCRFTCS made the first pass pick ADCRFT; the stem is ADCR); an exception is a name
that is not stem + one of the field's suffixes; blank e2m units / ranges print "-" (or "no unit"); the intro breaks the
37 disagreements down; the field table shows e2m's own descriptions. usage: patch_apply_r89c.py <apply_r89c.py>"""
import sys

p = sys.argv[1]
s = open(p).read()
edits = [
    ('''cm848_names = {l.split(",")[1]''',
     '''EXPECTED = {("1003", 0): ("CS",), ("1003", 2): ("GD",), ("1003", 4): ("CC", "FC"), ("1003", 6): ("DT", "FD"),
            ("1003", 8): ("IC", "FI"), ("1003", 10): ("SE", "FS"), ("1003", 12): ("HL",), ("1003", 14): ("LL",),
            ("1003", 16): ("CA",), ("1003", 18): ("MU",), ("1003", 19): ("TS",), ("1003", 20): ("HE",),
            ("1003", 21): ("LE",), ("1003", 22): ("TE",), ("1003", 23): ("SA", "SR"), ("1004", 8): ("FT",),
            ("1004", 10): ("UF",), ("1004", 16): ("RC",)}


def stem_of(k):
    return collections.Counter(e2m[k][key]["name"][:-2] for key in EXPECTED if key[0] == "1003").most_common(1)[0][0]


def unit_of(p):
    return p["unit"].strip() or "no unit"


def range_text(p):
    r = rng(p["comment"])
    return "" if r in ("", "NONE") else r


cm848_names = {l.split(",")[1]'''),
    ('''    stem = cs["name"][:-2]''', '''    stem = stem_of(k)'''),
    ('''f"{config[k]} (0x{0x806ae2 + 24 * k:x}). Calterm {ft['name']} = filtered_value ({ft['unit']}; e2m scale "
            f"{ft['scale']} and minimum {ft['minimum']}; {rng(ft['comment'])}) / {uf['name']} = unfiltered_value / "''',
     '''f"{config[k]} (0x{0x806ae2 + 24 * k:x}). Calterm {ft['name']} = filtered_value ({unit_of(ft)}; e2m scale "
            f"{ft['scale']} and minimum {ft['minimum']}{'; ' + range_text(ft) if range_text(ft) else ''}) / "
            f"{uf['name']} = unfiltered_value / "'''),
    ('''    if "Calterm stem" in lines[i]:
        continue
    lines[i] = lines[i].replace(" (were ", f"; Calterm stem {stem} (e2m block 1003; every name in "
                                          f"docs/analog_sensor_channels.md) (were ", 1)''',
     '''    note = f"; Calterm stem {stem} (e2m block 1003; every name in docs/analog_sensor_channels.md)"
    if "; Calterm stem " in lines[i]:
        lines[i] = re.sub(r"; Calterm stem \\S+ \\(e2m block 1003; every name in docs/analog_sensor_channels\\.md\\)",
                          note, lines[i])
    else:
        lines[i] = lines[i].replace(" (were ", note + " (were ", 1)'''),
    ('''"J90350.00 global that carried an e2m name before PR #53 round 89 (410 of 447 rows). The other 37 were rows that "
       "an earlier round had renamed, older mnemonics (ambient air temperature was ADTTFT / ADTTUF) and the throttle "
       "position sensor supply voltage config, which carried misplaced boost pressure table names "
       "(ADBSPRXA / ADBSPRYA). The ECU's''',
     '''"J90350.00 global that carried an e2m name before PR #53 round 89 (410 of 447 rows). The other 37: the 25 filter "
       "constants that round 88 had renamed, ambient air temperature's older mnemonics (ADTTFT / ADTTUF / ADTTMU) "
       "and nine throttle position sensor supply voltage config rows that carried boost pressure table names "
       "(ADBSPRXA / ADBSPRYA entries) that do not belong there. The ECU's'''),
    ('''    names = [e2m[k][(block, o)]["name"] for k in range(25)]
    stems = [e2m[k][("1003", 0)]["name"][:-2] for k in range(25)]
    suffixes = collections.Counter(n[len(st):] for n, st in zip(names, stems) if n.startswith(st))
    suffix_text = " / ".join(f"{x} ({c})" if len(suffixes) > 1 else x for x, c in suffixes.most_common())
    others = sum(1 for n, st in zip(names, stems) if not n.startswith(st))''',
     '''    names = [e2m[k][(block, o)]["name"] for k in range(25)]
    stems = [stem_of(k) for k in range(25)]
    suffixes = collections.Counter(n[len(st):] for n, st in zip(names, stems)
                                   if n.startswith(st) and n[len(st):] in EXPECTED[(block, o)])
    suffix_text = " / ".join(f"{x} ({c})" if len(suffixes) > 1 else x for x, c in suffixes.most_common())
    others = 25 - sum(suffixes.values())'''),
    ('''{e2m[0][(block, o)]['comment'].split('~')[0].title()} |")''',
     '''{e2m[0][(block, o)]['comment'].split('~')[0].strip()} |")'''),
    ('''    others = [f"+{o} {e2m[k][(b, o)]['name']}" if b == "1003" else f"state +{o} {e2m[k][(b, o)]['name']}"
              for b, o, field in FIELDS
              if not e2m[k][(b, o)]["name"].startswith(stem) or (b == "1004" and e2m[k][(b, o)]["name"] not in
                                                                 (stem + "FT", stem + "UF", stem + "RC"))]''',
     '''    others = [f"{'config' if b == '1003' else 'state'} +{o} {e2m[k][(b, o)]['name']}" for b, o, field in FIELDS
              if e2m[k][(b, o)]["name"] not in {stem + x for x in EXPECTED[(b, o)]}]'''),
    ('''f"{ft['name']} | {ft['unit']} | {ft['scale']} | {ft['minimum']} | {rng(ft['comment'])} | "''',
     '''f"{ft['name']} | {ft['unit'].strip() or '-'} | {ft['scale']} | {ft['minimum']} | {range_text(ft) or '-'} | "'''),
]
if "def stem_of" not in s:
    for old, new in edits:
        assert s.count(old) == 1, old[:70]
        s = s.replace(old, new)
    open(p, "w").write(s)
print("patched" if "def stem_of" in s else "not patched")

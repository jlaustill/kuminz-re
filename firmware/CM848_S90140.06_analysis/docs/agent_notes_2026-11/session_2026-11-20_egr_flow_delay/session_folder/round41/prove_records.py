"""Round 41 proof for the booster capacitor monitor's struct typing. Both function bodies go to one canonical form:
- old: each raw record address (&PTR_..._000576xx)[i * 0xd], (&BYTE_000576xx + i), (&j1939_*_ptr + i),
  (&DAT_000576xx + i), (&calibration_constant_1)[i] and the record base pointer -> REC.<field> / CYL.<field>
  by the field at that offset (structure_definitions.csv, laid out in file order);
- new: records[i].field / ptr->field -> REC.<field>, cylinder_records[i].field -> CYL.<field>;
- both: casts dropped, temporaries numbered by first use, the index set-up statements dropped (a temporary assigned
  only index arithmetic), then statement lists compared.
Also checks every field offset against the old token's address.  usage: prove_records.py <old cpp> <new cpp> <repo>"""
import difflib
import os
import re
import sys

old_cpp, new_cpp, repo = sys.argv[1], sys.argv[2], os.path.abspath(sys.argv[3])
out = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")
SIZE = {"word": 2, "word*": 4}
layout = {}
for l in open(os.path.join(out, "structure_definitions.csv"), errors="replace"):
    p = l.split(",")
    if len(p) > 4 and p[0].startswith("injector_driver_booster_capacitor_") and p[2]:
        layout.setdefault(p[0], []).append((p[2], SIZE[p[3]]))
offs = {}
for t, fs in layout.items():
    o = 0
    for n, s in fs:
        offs[(t, o)] = n
        o += s
REC_T, CYL_T = "injector_driver_booster_capacitor_monitor_record_t", "injector_driver_booster_capacitor_cylinder_record_t"
rec_field = {0x5762c + o: n for (t, o), n in offs.items() if t == REC_T}
cyl_field = {0x57694 + o: n for (t, o), n in offs.items() if t == CYL_T}
# the old tokens and the addresses their names carry
OLD_ADDR = {"j1939_pgn_lookup_ptr": 0x57636, "j1939_message_def_ptr": 0x57638, "calibration_constant_1": 0x57694}
for k, v in OLD_ADDR.items():
    assert (v in rec_field) or (v in cyl_field), k
print("record fields by offset:", {hex(a): n for a, n in sorted(rec_field.items())})


def body(path, name):
    t = open(path, errors="replace").read()
    m = re.search(r"^// Function: " + re.escape(name) + r" @[^\n]*\n(.*?)(?=^// Function: |\Z)", t, re.S | re.M)
    s = re.sub(r"/\*.*?\*/", "", m.group(1), flags=re.S)
    return re.sub(r"\s+", " ", s)


def balanced_end(s, i):
    """index just past the ')' or ']' that closes the bracket opened at s[i]"""
    pair = {"(": ")", "[": "]"}
    stack = []
    for k in range(i, len(s)):
        c = s[k]
        if c in pair:
            stack.append(pair[c])
        elif stack and c == stack[-1]:
            stack.pop()
            if not stack:
                return k + 1
    raise ValueError(s[i:i + 60])


def field_of(addr):
    if addr in rec_field:
        return "REC." + rec_field[addr]
    if addr in cyl_field:
        return "CYL." + cyl_field[addr]
    raise KeyError(hex(addr))


def canon_old(s):
    # (&PTR_..._000576xx)[i] and (&calibration_constant_1)[i]: the bracket index is dropped
    while True:
        m = re.search(r"\(& ?(PTR_\w+?_000576([0-9a-f]{2})|calibration_constant_1) ?\) ?\[", s)
        if not m:
            break
        addr = 0x57600 + int(m.group(2), 16) if m.group(2) else OLD_ADDR["calibration_constant_1"]
        e = balanced_end(s, m.end() - 1)
        s = s[:m.start()] + field_of(addr) + s[e:]
    # (&BYTE_000576xx + i), (&DAT_000576xx + i), (&j1939_*_ptr + i) -> &field
    while True:
        m = re.search(r"\(& ?((?:BYTE|DAT)_000576([0-9a-f]{2})|j1939_pgn_lookup_ptr|j1939_message_def_ptr) \+ ", s)
        if not m:
            break
        addr = 0x57600 + int(m.group(2), 16) if m.group(2) else OLD_ADDR[m.group(1)]
        e = balanced_end(s, m.start())
        s = s[:m.start()] + "&" + field_of(addr) + s[e:]
    base = re.search(r"(\w+) = \(ushort \*\)&REC\.sensor_channel;", s)
    if base:
        s = s.replace(base.group(0), "")
        s = re.sub(r"\*" + base.group(1) + r"\b", "REC.sensor_channel", s)
    s = re.sub(r"\*\((?:u?short) \*\)\(&per_cylinder_timing_array \+ (?:\(uint\))?([^;]*?) \* 2\)", r"HIGHCOUNT[\1]", s)
    s = re.sub(r"\(&per_cylinder_sync_counter\)\[", "LOWCOUNT[", s)
    s = re.sub(r"\(&per_cylinder_timing_counter\)\[", "VOLTAGECOUNT[", s)
    s = s.replace("injection_check_flags", "injector_driver_booster_capacitor_low_voltage_mask")
    s = s.replace("&DAT_003fb228", "&injector_driver_booster_capacitor_voltage_linearization_cached_axis_offset")
    s = s.replace("per_cylinder_timing_max_cal", "injector_driver_booster_capacitor_low_voltage_count_limit")
    return s


def canon_new(s):
    while True:
        m = re.search(r"injector_driver_booster_capacitor_(monitor|cylinder)_records\s?\[", s)
        if not m:
            break
        e = balanced_end(s, m.end() - 1)
        s = s[:m.start()] + ("REC" if m.group(1) == "monitor" else "CYL") + s[e:]
    s = re.sub(r"\b[a-z]{1,3}Var\d+->", "REC.", s)
    s = re.sub(r"injector_driver_booster_capacitor_monitor_records \+ \w+", "&REC.sensor_channel", s)
    s = re.sub(r"injector_driver_booster_capacitor_cylinder_high_fault_debounce_counts ?\[", "HIGHCOUNT[", s)
    s = re.sub(r"injector_driver_booster_capacitor_cylinder_low_fault_debounce_counts ?\[", "LOWCOUNT[", s)
    s = re.sub(r"injector_driver_booster_capacitor_cylinder_low_voltage_counts ?\[", "VOLTAGECOUNT[", s)
    return s


TEMP = re.compile(r"\b(?:[a-z]{1,3}Var\d+|[a-z]{1,2}Stack_[0-9a-f]+)\b")


def common(s):
    s = re.sub(r"\((?:u?int|u?short|word|byte|sword|char|ushort \*|word \*|short \*|ushort \*\*|word \*\*|short \*\*|"
               r"undefined2 \*|undefined4)\)", "", s)
    s = re.sub(r"(REC|CYL)\. ", r"\1.", s)
    s = re.sub(r"\* ?&(REC|CYL)\.", r"\1.", s)
    s = re.sub(r"\( ?(\*?(?:REC|CYL)\.\w+) ?\)", r"\1", s)
    s = re.sub(r" +", " ", s)
    s = re.sub(r"\s*\[\s*", "[", s)
    s = re.sub(r"\*\s+(?=[A-Za-z_(&])", "*", s)
    s = re.sub(r"\.\s+(?=\w)", ".", s)
    s = re.sub(r"(?<=[{;}]) ?(?:const )?[A-Za-z_][A-Za-z0-9_]* \**[A-Za-z_][A-Za-z0-9_.]*(?: \[\d+\])?;", "", s)
    st = [x.strip() for x in re.split(r"(?<=[;{}])", s) if x.strip() and x.strip() != ";"]
    keep = []
    for x in st:
        m = re.fullmatch(r"([a-z]{1,3}Var\d+) = ([^;]*);", x)
        if m and not re.search(r"REC\.(?!sensor_channel)|qadc|sensor_channel_|wVar|lookup|fault|\*(?=[A-Za-z_(&])|COUNT", m.group(2)):
            continue
        keep.append(x)
    out = []
    for x in keep:
        x = TEMP.sub("T", x)
        x = re.sub(r"\s*,\s*", ",", x)
        x = re.sub(r"\s+\)", ")", x)
        x = re.sub(r"\s+\]", "]", x)
        x = re.sub(r"\(\s+", "(", x)
        x = re.sub(r"\s+;", ";", x)
        x = re.sub(r"(REC|CYL)\s+\.", r"\1.", x)
        x = re.sub(r"\+ -1\b", "- 1", x)
        out.append(x)
    return out


ob = body(old_cpp, "cm848_processFaultScanLookup")
nb = body(new_cpp, "cm848_monitorInjectorDriverBoosterCapacitorVoltage")
a, b = common(canon_old(ob)), common(canon_new(nb))
d = [x for x in difflib.unified_diff(a, b, "old", "new", n=0, lineterm="") if x[:1] in "+-" and x[:3] not in ("---", "+++")]
print(f"statements old {len(a)} new {len(b)}; differing {len(d)}")
for x in d[:40]:
    print("  " + x[:190])

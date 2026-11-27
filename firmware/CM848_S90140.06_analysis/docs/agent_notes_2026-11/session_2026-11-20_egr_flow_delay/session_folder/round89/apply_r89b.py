"""Round 89 stage B (CM550 + CM848): the third audit (workflow wf_c8937a9e-bb1: 2 investigators, 2 skeptics; read a
copy taken before round 88 stage B, so everything is applied by address). Idempotent; keeps line endings.
usage: apply_r89b.py <repo> <audit2_changes_r88.tsv> <map550.csv> <map848.csv>
- Functions: the filter records' users and initializers - 9 twin pairs take one shared name; CM550-only renames;
  0x1ae0c / 0x1ae06 are fall-through points inside cm550_initializeElectronicSmartPower (0x1ade8), so their rows
  go to deleted_functions.csv (the skeptic's action).
- CM550 types: sensor_config_t, the 24-byte A/D channel config record (e2m block 1003 = 25 of them from 0x806ae2),
  replaces the unused sensor_fault_config_t template; the unused ad_sensor_config_t template goes.
- 25 instances <channel>_sensor_config: each replaces its +0 coefficient row (round 88's <channel>_filter_coefficient,
  now the field filter_coefficient) and the Calterm-named rows inside its 24 bytes (no user, or its own fields)."""
import os
import re
import sys

repo, tsv, map550, map848 = os.path.abspath(sys.argv[1]), sys.argv[2], sys.argv[3], sys.argv[4]
DIRS = {"CM550": os.path.join(repo, "firmware/CM550_J90350.00_analysis/output"),
        "CM848": os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")}
R = "PR #53 round 89"
changes = [l.rstrip("\n").split("\t") for l in open(tsv)]


def read(path):
    return open(path, newline="").read()


def write(path, text):
    open(path, "w", newline="").write(text)


def clean(reason, limit=380):
    r = " ".join(reason.split())
    r = re.sub(r"\(Extra: not in the task list\. It is (the|a|the third) user of ([^)]+?)\.\) ",
               lambda m: (f"It is the third user of {m.group(2)}. " if m.group(1) == "the third"
                          else f"It uses {m.group(2)}. "), r)
    sentences = re.split(r"(?<=[.)])\s+(?=[A-Z(0-9])", r)
    keep = [s for s in sentences if not re.search(r"\.csv:\d|need(s)? the new name|APPLY|Action|cites the old|"
                                                  r"investigator|proposal|frozen|Twin rule used|this output|"
                                                  r"see that row|Update the comment", s)]
    out = ""
    for s in keep:
        if out and len(out) + len(s) + 1 > limit:
            break
        out = (out + " " + s).strip()
    return out.rstrip(";, ")


def norm(a):
    return f"0x{int(a, 16):08x}"


TWINS, by_final = {}, {}
for c in changes:
    if c[2] == "function":
        by_final.setdefault(c[5], []).append(c)
for final, cs in by_final.items():
    f = {c[1]: c for c in cs}
    if set(f) == {"CM550", "CM848"}:
        TWINS[("CM550", norm(f["CM550"][3]))] = f"CM848 0x{int(f['CM848'][3], 16):x}"
        TWINS[("CM848", norm(f["CM848"][3]))] = f"CM550 0x{int(f['CM550'][3], 16):x}"
DELETE550 = {
    "0x0001ae0c": "not a function entry: a fall-through point inside cm550_initializeElectronicSmartPower (0x1ade8 runs "
                  "straight through to its only rts at 0x1ae20); no link / movem there and no reference",
    "0x0001ae06": "not a function entry: a fall-through point inside cm550_initializeElectronicSmartPower (the clr.w at "
                  "0x1ae00 falls into it); no link / movem there and no reference",
}
renames = {"CM550": [], "CM848": []}

# ---------------------------------------------------------------- functions
for fw in ("CM550", "CM848"):
    path = os.path.join(DIRS[fw], "function_renames.csv")
    s = read(path)
    for group, cfw, kind, address, current, final, ftype, fields, verdict, conf, reason in changes:
        if cfw != fw or kind != "function":
            continue
        a = norm(address)
        if fw == "CM550" and a in DELETE550:
            m = re.search(rf"^{a},[^\r\n]*\r?\n", s, re.M)
            if m:
                s = s[:m.start()] + s[m.end():]
            dpath = os.path.join(DIRS[fw], "deleted_functions.csv")
            d = read(dpath)
            if f"\n{a}," not in d:
                write(dpath, d.rstrip("\n") + f"\n{a},{DELETE550[a]} (was {current}; {R})\n")
            continue
        m = re.search(rf"^{a},([^,\r\n]*)(,[^\r\n]*)?$", s, re.M)
        assert m, (fw, a)
        if m.group(1) == final:
            continue
        old_comment = (m.group(2) or "")[1:]
        twin = TWINS.get((fw, a))
        note = f"(was {m.group(1)}; {R}" + (f"; the twin of {twin}: one shared name)" if twin else ")")
        comment = f"{old_comment} | {note}" if old_comment else f"{clean(reason)} {note}"
        s = s[:m.start()] + f"{a},{final},{comment}" + s[m.end():]
        renames[fw].append((a, final, m.group(1)))
    write(path, s)
    for name in ("function_definitions.csv", "local_variables.csv"):
        p = os.path.join(DIRS[fw], name)
        d = read(p)
        for a, final, old in renames[fw]:
            d = re.sub(rf"^({a},){re.escape(old)},", rf"\g<1>{final},", d, flags=re.M)
        write(p, d)

# ---------------------------------------------------------------- CM550 struct types (CRLF)
S5 = os.path.join(DIRS["CM550"], "structure_definitions.csv")
s = read(S5)
EOL = "\r\n" if "\r\n" in s else "\n"
FIELDS = [
    ("filter_coefficient", "word", 2, "+0: A/D digital filter constant (1/65536): the weight of the previous value - the "
     "channel's ema_filter_state_t.coefficient points here and cm550_exponentialMovingAverage reads it"),
    ("default_value", "word", 2, "+2: global default value in the channel's units: filtered_value and the accumulator "
     "(<< 16) while the fault is active or on a tri-state reading"),
    ("fault_clear_threshold", "short", 2, "+4: A/D fault clear counts: debounce_counter at or below it clears "
     "fault_active_flag; each high / low status bit (0x806000) clears only while its 0x806040 first-occurrence bit is "
     "clear"),
    ("debounce_counter_decrement", "short", 2, "+6: A/D fault decrement: taken off debounce_counter on each in-range "
     "sample (floored at 0)"),
    ("debounce_counter_increment", "short", 2, "+8: A/D fault increment: added to debounce_counter on each out-of-range "
     "sample"),
    ("fault_set_threshold", "short", 2, "+10: A/D fault set: debounce_counter at or above it sets the fault and is "
     "capped there"),
    ("high_error_limit", "word", 2, "+12: A/D high error limit in raw counts (0-1023): adc_raw_value above it counts "
     "toward high_error_fault_number"),
    ("low_error_limit", "word", 2, "+14: A/D low error limit in raw counts: adc_raw_value below it counts toward "
     "low_error_fault_number"),
    ("qadc_result_register_index", "word", 2, "+16: the QADC result slot (0-39) whose right-justified result register "
     "(0xfff2b0 + 2 x n) gives adc_raw_value"),
    ("multiplexer_setting", "byte", 1, "+18: channel multiplexer setting: no reader in J90350.00 (0 in all 25 records)"),
    ("tri_state_error_enable", "byte", 1, "+19: tri-state flag: nonzero makes a lookup result of 4 count toward "
     "tri_state_error_fault_number (0 in all 25 records)"),
    ("high_error_fault_number", "byte", 1, "+20: the fault the high limit sets (bit n mod 16 of status word n / 16 at "
     "0x806000 / 0x806040)"),
    ("low_error_fault_number", "byte", 1, "+21: the fault the low limit sets"),
    ("tri_state_error_fault_number", "byte", 1, "+22: the in-range / tri-state error: set at the fifth consecutive "
     "lookup result of 4 and cleared at the fifth other reading"),
    ("sample_period", "byte", 1, "+23: the channel runs once every sample_period passes of the A/D loop (0 = not "
     "processed); the e2m scale calls a pass 20 ms - not measured"),
]
NEW = ["# A/D channel config record (24 bytes; e2m block 1003 = 25 of them from 0x806ae2 in channel order). "
       f"Replaces the unused sensor_fault_config_t template ({R})"]
NEW += [f"sensor_config_t,,{n},{t},{z},{c},,verified" for n, t, z, c in FIELDS]
if "sensor_config_t,,filter_coefficient," not in s:
    m = re.search(r"^# Sensor Fault Configuration Entry \(24 bytes per sensor\)\r?\n(?:sensor_fault_config_t,[^\r\n]*\r?\n)+",
                  s, re.M)
    assert m
    s = s[:m.start()] + EOL.join(NEW) + EOL + s[m.end():]
if "ad_sensor_config_t,," in s:
    m = re.search(r"^# A/D Sensor Config Block \(ambient air pressure sensor pattern\)\r?\n(?:ad_sensor_config_t,[^\r\n]*\r?\n)+",
                  s, re.M)
    assert m
    s = s[:m.start()] + (f"# (ad_sensor_config_t removed in {R}: no user; the A/D channel config record is "
                         f"sensor_config_t){EOL}") + s[m.end():]
write(S5, s)

# ---------------------------------------------------------------- the 25 config instances
G5 = os.path.join(DIRS["CM550"], "global_variables.csv")
lines = read(G5).split("\n")
index = {int(l.split(",")[0], 16): i for i, l in enumerate(lines) if l.startswith("0x")}
delete = set()
for group, cfw, kind, address, current, final, ftype, fields, verdict, conf, reason in changes:
    if kind != "struct_instance":
        continue
    a = int(address, 16)
    k = (a - 0x806ae2) // 24
    assert 0x806ae2 + 24 * k == a
    head = lines[index[a]].split(",")[1] if a in index else ""
    if head == final:
        continue
    inside = [lines[index[a + o]].split(",")[1] for o in range(1, 24) if a + o in index]
    for o in range(1, 24):
        if a + o in index:
            delete.add(index[a + o])
    filter_record = head[:-len("_coefficient")] + "_state" if head.endswith("_filter_coefficient") else ""
    text = (f"A/D channel {k}'s 24-byte config record (e2m block 1003 +{24 * k}: 0x806ae2 + 24 x {k}); "
            + (f"{filter_record}.coefficient points at its +0 (filter_coefficient)" if filter_record else
               "its filter record's coefficient points at +0"))
    note = f"(were {head} at +0 and {len(inside)} Calterm-named field rows with no user; {R})"
    row = f"0x{a:08x},{final},sensor_config_t,{text} {note}"
    if a in index:
        lines[index[a]] = row
    else:
        raise SystemExit(f"no +0 row at 0x{a:x}")
    renames["CM550"].append((f"0x{a:08x}", f"{final}.filter_coefficient", head))
for group, cfw, kind, address, current, final, ftype, fields, verdict, conf, reason in changes:
    if kind == "global_removal":
        a = int(address, 16)
        if a in index:
            delete.add(index[a])
lines = [l for i, l in enumerate(lines) if i not in delete]
write(G5, "\n".join(lines))

for fw, path in (("CM550", map550), ("CM848", map848)):
    with open(path, "w") as fh:
        fh.write("address,name,old_label,kind,dims\n")
        for a, final, old in renames[fw]:
            fh.write(f"{a},{final},{old},symbol,1\n")
print(f"round 89 stage B applied: CM550 {len(renames['CM550'])} / CM848 {len(renames['CM848'])} map rows; "
      f"{len(delete)} rows removed")

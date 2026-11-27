"""Round 89 stage C (CM550): the 25 A/D channel runtime records typed, and their Calterm names written back.
usage: apply_r89c.py <repo> <calterm_stems_r89.tsv> <map_own.csv> <docs.md>
- sensor_debounce_state_t -> sensor_state_t: the 22-byte record is the channel's whole runtime state (filter +
  filtered / unfiltered values + debounce + raw counts), the pair of sensor_config_t. Field lookup_result ->
  unfiltered_value: Calterm calls +10 "unfiltered and linearized" (...UF), +8 "filtered and linearized" (...FT).
- 25 instances <channel>_sensor_state at 0x80a2aa + 22 x k (e2m block 1004 = 25 records in channel order). Each
  replaces the channel's ema_filter_state_t row at +0 (now the field filter) and the e2m-named rows at +8 / +10 / +16
  (now filtered_value / unfiltered_value / adc_raw_value). The names come from the config instance of the same channel.
- The Calterm names: v64t6_s.e2m's block 1003 / 1004 layout matches J90350.00 (calterm_stems_r89.py). The
  sensor_config_t field comments get back their suffixes (stage B dropped them); each instance names its stem; the
  docs page lists every name.
Idempotent; keeps line endings (structure_definitions.csv is CRLF)."""
import collections
import csv
import os
import re
import sys

repo, tsv, map_own, doc = os.path.abspath(sys.argv[1]), sys.argv[2], sys.argv[3], sys.argv[4]
O5 = os.path.join(repo, "firmware/CM550_J90350.00_analysis/output")
O8 = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")
R = "PR #53 round 89"
SOURCE = "v64t6_s.e2m"
e2m = collections.defaultdict(dict)
for r in csv.DictReader(open(tsv), delimiter="\t"):
    e2m[int(r["channel"])][(r["block"], int(r["offset"]))] = r


def read(path):
    return open(path, newline="").read()


def write(path, text):
    open(path, "w", newline="").write(text)


def rng(comment):
    tail = comment.split("~", 1)[1].strip() if "~" in comment else ""
    m = re.match(r"^(-?[0-9.]+)\s*-\s*(-?[0-9.]+)$", tail)
    return f"{m.group(1)} to {m.group(2)}" if m else tail.replace(" TO ", " to ")


EXPECTED = {("1003", 0): ("CS",), ("1003", 2): ("GD",), ("1003", 4): ("CC", "FC"), ("1003", 6): ("DT", "FD"),
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


cm848_names = {l.split(",")[1] for l in read(os.path.join(O8, "global_variables.csv")).split("\n") if l.startswith("0x")}

# ---------------------------------------------------------------- types (CRLF)
S5 = os.path.join(O5, "structure_definitions.csv")
s = read(S5)
s = s.replace("# Sensor Debounce State Entry (22 bytes per sensor)",
              "# A/D channel runtime record (22 bytes; e2m block 1004 = 25 of them from 0x80a2aa in channel order; the "
              f"pair of sensor_config_t) (was sensor_debounce_state_t; {R})")
s = re.sub(r"^sensor_debounce_state_t,,", "sensor_state_t,,", s, flags=re.M)
STATE_FIELDS = {
    "filtered_value": ("(was interpolated_value; PR #53 round 88)",
                       "(Calterm ...FT: filtered and linearized) (was interpolated_value; PR #53 round 88)"),
    "lookup_result": None,
    "adc_raw_value": ("+16: raw A/D conversion value,", "+16: raw A/D conversion value (Calterm ...RC: raw counts),"),
}
for field, change in STATE_FIELDS.items():
    m = re.search(rf"^sensor_state_t,,{field},([^\r\n]*)(?=\r?$)", s, re.M)
    if not m:
        continue
    if field == "lookup_result":
        s = s[:m.start()] + (f"sensor_state_t,,unfiltered_value,word,2,+10: the linearized reading before the filter - "
                             f"the table lookup result (Calterm ...UF: unfiltered and linearized) (was lookup_result; "
                             f"{R}),,verified") + s[m.end():]
    elif change[1] not in m.group(0):
        s = s[:m.start()] + m.group(0).replace(change[0], change[1]) + s[m.end():]
CONFIG_SUFFIX = {
    "filter_coefficient": "Calterm ...CS", "default_value": "Calterm ...GD or ADDF + the channel code",
    "fault_clear_threshold": "Calterm ...CC or ...FC", "debounce_counter_decrement": "Calterm ...DT or ...FD",
    "debounce_counter_increment": "Calterm ...IC or ...FI", "fault_set_threshold": "Calterm ...SE or ...FS",
    "high_error_limit": "Calterm ...HL", "low_error_limit": "Calterm ...LL", "qadc_result_register_index":
    "Calterm ...CA: channel address", "multiplexer_setting": "Calterm ...MU", "tri_state_error_enable": "Calterm ...TS",
    "high_error_fault_number": "Calterm ...HE", "low_error_fault_number": "Calterm ...LE",
    "tri_state_error_fault_number": "Calterm ...TE", "sample_period": "Calterm ...SA or ...SR",
}
for field, suffix in CONFIG_SUFFIX.items():
    m = re.search(rf"^(sensor_config_t,,{field},[^,]*,[^,]*,)([^\r\n]*)(,,verified)(?=\r?$)", s, re.M)
    assert m, field
    comment = m.group(2).replace("the channel's ema_filter_state_t.coefficient points here",
                                 "the channel's sensor_state_t.filter.coefficient points here")
    if suffix not in comment:
        comment = f"{comment} ({suffix})"
    s = s[:m.start()] + m.group(1) + comment + m.group(3) + s[m.end():]
assert "," not in "".join(CONFIG_SUFFIX.values())
write(S5, s)

# ---------------------------------------------------------------- instances
G5 = os.path.join(O5, "global_variables.csv")
lines = read(G5).split("\n")
index = {int(l.split(",")[0], 16): i for i, l in enumerate(lines) if l.startswith("0x")}
config = {k: lines[index[0x806ae2 + 24 * k]].split(",")[1] for k in range(25)}
assert all(v.endswith("_sensor_config") for v in config.values()), config
renames, delete, channels = [], set(), []
FIELD_AT = {8: "filtered_value", 10: "unfiltered_value", 16: "adc_raw_value"}
for k in range(25):
    base = 0x80a2aa + 22 * k
    state = config[k][:-len("_config")] + "_state"
    head = lines[index[base]].split(",")
    ft, uf, rc, cs = (e2m[k][("1004", 8)], e2m[k][("1004", 10)], e2m[k][("1004", 16)], e2m[k][("1003", 0)])
    stem = stem_of(k)
    channels.append((k, state, stem, ft, uf, rc))
    if head[1] == state:
        continue
    assert head[2] == "ema_filter_state_t", head
    inner = [(o, lines[index[base + o]].split(",")[1]) for o in range(1, 22) if base + o in index]
    assert {o for o, _ in inner} <= set(FIELD_AT), (k, inner)
    for o, _ in inner:
        delete.add(index[base + o])
    same = (f"; CM848 keeps this channel's filter as a standalone ema_filter_state_t under the old name {head[1]}"
            if head[1] in cm848_names else "")
    # one "+N was X" per old row: refresh_references protects a name right after "was", but a "were a, b, c" list
    # only within 120 characters of its "were" - the e2m names are long enough to fall outside it
    were = "; ".join(f"+{o} was {n}" for o, n in [(0, head[1])] + inner)
    text = (f"A/D channel {k}'s 22-byte runtime record (e2m block 1004 +{22 * k}: 0x80a2aa + 22 x {k}); its config is "
            f"{config[k]} (0x{0x806ae2 + 24 * k:x}). Calterm {ft['name']} = filtered_value ({unit_of(ft)}; e2m scale "
            f"{ft['scale']} and minimum {ft['minimum']}{'; ' + range_text(ft) if range_text(ft) else ''}) / "
            f"{uf['name']} = unfiltered_value / "
            f"{rc['name']} = adc_raw_value{same} ({were}; {R})")
    lines[index[base]] = f"0x{base:08x},{state},sensor_state_t,{text}"
    renames.append((f"0x{base:08x}", f"{state}.filter", head[1]))
    for o, n in inner:
        renames.append((f"0x{base + o:08x}", f"{state}.{FIELD_AT[o]}", n))
# the config instances name their stem
for k, state, stem, ft, uf, rc in channels:
    i = index[0x806ae2 + 24 * k]
    note = f"; Calterm stem {stem} (e2m block 1003; every name in docs/analog_sensor_channels.md)"
    if "; Calterm stem " in lines[i]:
        lines[i] = re.sub(r"; Calterm stem \S+ \(e2m block 1003; every name in docs/analog_sensor_channels\.md\)",
                          note, lines[i])
    else:
        lines[i] = lines[i].replace(" (were ", note + " (were ", 1)
    assert "Calterm stem" in lines[i], k
write(G5, "\n".join(l for i, l in enumerate(lines) if i not in delete))

L5 = os.path.join(O5, "local_variables.csv")
write(L5, read(L5).replace(",sensor_debounce_state_t*,", ",sensor_state_t*,"))

if renames:
    with open(map_own, "w") as fh:
        fh.write("address,name,old_label,kind,dims\n")
        for a, n, o in renames:
            fh.write(f"{a},{n},{o},symbol,1\n")
        fh.write(",sensor_state_t,sensor_debounce_state_t,symbol,1\n")

# ---------------------------------------------------------------- docs page
FIELDS = [("1003", 0, "filter_coefficient"), ("1003", 2, "default_value"), ("1003", 4, "fault_clear_threshold"),
          ("1003", 6, "debounce_counter_decrement"), ("1003", 8, "debounce_counter_increment"),
          ("1003", 10, "fault_set_threshold"), ("1003", 12, "high_error_limit"), ("1003", 14, "low_error_limit"),
          ("1003", 16, "qadc_result_register_index"), ("1003", 18, "multiplexer_setting"),
          ("1003", 19, "tri_state_error_enable"), ("1003", 20, "high_error_fault_number"),
          ("1003", 21, "low_error_fault_number"), ("1003", 22, "tri_state_error_fault_number"),
          ("1003", 23, "sample_period"), ("1004", 8, "filtered_value"), ("1004", 10, "unfiltered_value"),
          ("1004", 16, "adc_raw_value")]
out = ["# CM550 analog sensor channels (J90350.00)", "",
       "The A/D channel loop `mc68k_processAnalogSensorChannels` (0xb7bc) and its start-up routine "
       "`cm550_initializeAnalogSensorChannels` (0xbcf0) walk two arrays of 25 records in step, one record per channel:",
       "", "| Array | Type | First record | Stride | e2m block |", "|---|---|---|---|---|",
       "| Configuration | `sensor_config_t` | 0x806ae2 | 24 bytes | 1003 |",
       "| Runtime state | `sensor_state_t` | 0x80a2aa | 22 bytes | 1004 |", "",
       f"The Calterm names come from `e2m-analysis/originals/{SOURCE}`. Its block 1003 / 1004 layout agrees with every "
       "J90350.00 global that carried an e2m name before PR #53 round 89 (410 of 447 rows). The other 37: the 25 filter "
       "constants that round 88 had renamed, ambient air temperature's older mnemonics (ADTTFT / ADTTUF / ADTTMU) "
       "and nine throttle position sensor supply voltage config rows that carried boost pressure table names "
       "(ADBSPRXA / ADBSPRYA entries) that do not belong there. The ECU's parameter ID table gives the two blocks' addresses "
       "(`output/parameter_id_lookup_table.csv`: 0x1003 -> 0x806ae2 and 0x1004 -> 0x80a2aa; "
       "`firmware/scripts/e2m_block_addresses.py` resolves CM848 only).", "",
       "CM848 is a counterpart, not a twin: `sensor_channel_config_t` holds the same parameter family in another "
       "order, and its filter records are standalone `ema_filter_state_t` globals outside its 12-byte "
       "`sensor_channel_state_t` records.", "",
       "## Fields and their Calterm suffixes", "",
       "A Calterm name is the channel's stem plus the suffix (ADIMTP + CS = ADIMTPCS). The default value, a few "
       "channels' runtime values and one low limit use other names; the channel table lists every exception.", "",
       "| Record | Offset | Field | Suffixes | e2m description (channel 0) |", "|---|---|---|---|---|"]
for block, o, field in FIELDS:
    names = [e2m[k][(block, o)]["name"] for k in range(25)]
    stems = [stem_of(k) for k in range(25)]
    suffixes = collections.Counter(n[len(st):] for n, st in zip(names, stems)
                                   if n.startswith(st) and n[len(st):] in EXPECTED[(block, o)])
    suffix_text = " / ".join(f"{x} ({c})" if len(suffixes) > 1 else x for x, c in suffixes.most_common())
    others = 25 - sum(suffixes.values())
    if others:
        suffix_text += f"; {others} other name{'s' if others > 1 else ''}"
    record = "config" if block == "1003" else "state"
    out.append(f"| {record} | +{o} | `{field}` | {suffix_text} | {e2m[0][(block, o)]['comment'].split('~')[0].strip()} |")
out += ["", "## Channels", "",
        "Units, scale and minimum are the e2m columns of the filtered value (FT); the range is the one its e2m "
        "comment gives.", "",
        "| Channel | Runtime record | Config record | Calterm stem | Filtered value | Unit | e2m scale | e2m minimum | "
        "Range | Other names |", "|---|---|---|---|---|---|---|---|---|---|"]
for k, state, stem, ft, uf, rc in channels:
    others = [f"{'config' if b == '1003' else 'state'} +{o} {e2m[k][(b, o)]['name']}" for b, o, field in FIELDS
              if e2m[k][(b, o)]["name"] not in {stem + x for x in EXPECTED[(b, o)]}]
    out.append(f"| {k} | `{state}` 0x{0x80a2aa + 22 * k:x} | `{config[k]}` 0x{0x806ae2 + 24 * k:x} | {stem} | "
               f"{ft['name']} | {ft['unit'].strip() or '-'} | {ft['scale']} | {ft['minimum']} | {range_text(ft) or '-'} | "
               f"{', '.join(others) if others else '-'} |")
out.append("")
write(os.path.join(repo, doc), "\n".join(out))
print(f"stage C applied: {len(renames)} map rows, {len(delete)} rows removed; docs {doc}")

"""Round 88 stage A (CM550 + CM848): the round 87 audit's filter library group (verified by its skeptic), plus the
coefficient words named by CM848's <x>_filter_coefficient convention. Idempotent; keeps line endings (CM550's
structure_definitions.csv is CRLF). usage: apply_r88a.py <repo> <ema_changes.tsv> <map550.csv> <map848.csv>
- CM550 struct types: ema_filter_state_t (coefficient word* / Q16.16 accumulator, CM848's layout) and
  second_order_filter_state_t (type-only templates); the unused sensor_debounce_state_t template gets its real
  layout (an ema_filter_state_t at +0; reserved_12 was at +18 decimal).
- 38 CM550 record instances as ema_filter_state_t globals (13 filters + the 25 A/D channel records 0x80a2aa + 22k);
  the rows inside a record's 8 bytes go - they are its own fields under old names, or rows with no user (0 renders).
- 40 coefficient words typed word; 37 renamed <record base>_filter_coefficient (3 of them new rows).
- CM550 functions: 0x34e9a exponentialMovingAverage -> cm550_signedFirstOrderFilter (it is the SIGNED filter; the
  shared name paired it with CM848's unsigned one), 0x34f8a cm550_coreTableInterpolation ->
  cm550_exponentialMovingAverage, 0x34f00 cm550_unsignedLinearInterpolation -> cm550_secondOrderFilter, 0x34fe0 (no
  function yet) cm550_secondOrderFilterUnsigned; their prototypes (return word, then the sample and the record).
- CM848 0x56594 exponentialMovingAverage -> cm848_exponentialMovingAverage (no CM550 twin: a different formulation)."""
import os
import re
import sys

repo, tsv, map550, map848 = os.path.abspath(sys.argv[1]), sys.argv[2], sys.argv[3], sys.argv[4]
O5 = os.path.join(repo, "firmware/CM550_J90350.00_analysis/output")
O8 = os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")
R = "PR #53 round 88"
changes = [l.rstrip("\n").split("\t") for l in open(tsv)]


def read(path):
    return open(path, newline="").read()


def write(path, text):
    open(path, "w", newline="").write(text)


# ---------------------------------------------------------------- struct types (CM550, CRLF)
S5 = os.path.join(O5, "structure_definitions.csv")
s = read(S5)
EOL = "\r\n" if "\r\n" in s else "\n"
TEMPLATES = [
    "# Filter records (PR #53 round 88): CM848's ema_filter_state_t layout; cm550_signedFirstOrderFilter / "
    "cm550_exponentialMovingAverage take one, cm550_secondOrderFilter / cm550_secondOrderFilterUnsigned the second "
    "order record",
    "ema_filter_state_t,,coefficient,word*,4,Points at the filter coefficient word: the weight of the previous value "
    "in 1/65536 (0 = no filtering),,verified",
    "ema_filter_state_t,,accumulator,dword,4,Q16.16 filtered value (offset binary in the signed filter); the filters "
    "return its rounded integer part,,verified",
    "second_order_filter_state_t,,coefficient_1,word*,4,+0: points at coefficient 1 (1/65535): the weight of the new "
    "input,,verified",
    "second_order_filter_state_t,,coefficient_3,word*,4,+4: points at coefficient 3 (1/65535): the weight of the "
    "output before last,,verified",
    "second_order_filter_state_t,,output,dword,4,+8: the filter output (its integer part is returned),,verified",
    "second_order_filter_state_t,,output_previous,dword,4,+12: the output of the previous call,,verified",
]
if "ema_filter_state_t,,coefficient," not in s:
    anchor = "# Sensor Debounce State Entry (22 bytes per sensor)"
    assert s.count(anchor) == 1
    s = s.replace(anchor, EOL.join(TEMPLATES) + EOL + anchor)
OLD_SDS = [
    "sensor_debounce_state_t,,reserved_00,byte,8,Reserved bytes at offset 0x00-0x07,,verified",
    "sensor_debounce_state_t,,interpolated_value,word,2,Interpolated sensor value,,verified",
    "sensor_debounce_state_t,,lookup_result,word,2,Table lookup result,,verified",
    "sensor_debounce_state_t,,debounce_counter,word,2,Current debounce count,,verified",
    "sensor_debounce_state_t,,fault_active_flag,byte,1,Fault currently active flag,,verified",
    "sensor_debounce_state_t,,sample_counter,byte,1,Sample phase counter,,verified",
    "sensor_debounce_state_t,,adc_raw_value,word,2,Raw A/D conversion value,,verified",
    "sensor_debounce_state_t,,reserved_12,byte,4,Reserved bytes at offset 0x12-0x15,,verified",
]
NEW_SDS = [
    "sensor_debounce_state_t,,filter,ema_filter_state_t,8,+0: the channel's filter record (its coefficient points at "
    f"the channel config's +0 filter constant) (was reserved_00; {R}),,verified",
    "sensor_debounce_state_t,,filtered_value,word,2,+8: the filter output - or the config default while the fault "
    f"is active - or the channel's override value (was interpolated_value; {R}),,verified",
    "sensor_debounce_state_t,,lookup_result,word,2,+10: the linearized reading (the table lookup result),,verified",
    "sensor_debounce_state_t,,debounce_counter,short,2,+12: the fault debounce count (signed: floored at 0),,verified",
    "sensor_debounce_state_t,,fault_active_flag,byte,1,+14: fault currently active flag,,verified",
    "sensor_debounce_state_t,,sample_counter,byte,1,+15: sample phase counter,,verified",
    "sensor_debounce_state_t,,adc_raw_value,word,2,+16: raw A/D conversion value,,verified",
    "sensor_debounce_state_t,,reserved_18,byte,4,+18-+21: no access; 0 in all 25 dumped records (was reserved_12 - "
    f"the hex offset; {R}),,verified",
]
if NEW_SDS[0] not in s:
    old = EOL.join(OLD_SDS)
    assert s.count(old) == 1
    s = s.replace(old, EOL.join(NEW_SDS))
write(S5, s)

# ---------------------------------------------------------------- the record instances and coefficient words (CM550)
INSTANCE_TEXT = {
    "0x00800066": "The signed filter record of the engine acceleration first stage: cm550_outputControlTimingGenerator "
                  "(0xb210) filters the change of current_engine_rpm_filtered since the last pass (0x80a292) into "
                  "0x80a294. CM848 names its record the same (0x3fb3b0)",
    "0x0080006e": "The signed filter record of the engine acceleration second stage (the same function as the first "
                  "stage, fed by the first stage's output)",
    "0x00800670": "The filter record of the engine deceleration rate (coefficient: Calterm filtered engine decel rate)",
    "0x0080d636": "The signed filter record of the high speed governor's engine speed error (its coefficient points "
                  "at the selected gain set's filter time constant)",
    "0x00801a5a": "The signed filter record of the low speed governor's speed error: "
                  "vp44_fuel_timing_calculation_with_fault_checking (0x25b1c, really the low speed governor) filters "
                  "(reference - engine_rpm_primary) into lsg_filtered_speed_error (0x80dae0) and presets the "
                  "accumulator at its clamps. CM848 names its record the same (0x3faf66, e2m 14EF)",
    "0x00801c00": "The signed filter record of the power take-off governor's speed error",
    "0x0080a91a": "The filter record of the alpha fuel rate (the twin calculateAlphaFuelRateResult filters with "
                  "cm550_exponentialMovingAverage; CM848 names its record alpha_fuel_rate_filter_state)",
    "0x0080a984": "The unsigned filter record of the all-speed governor reference: cm550_engine_speed_governor filters "
                  "asg_reference_speed_working (0x80a990) into asg_filtered_reference_speed_0_4500 (0x80a972); its "
                  "coefficient pointer is the selected set's: all_speed_governor_application_reference_filter_"
                  "coefficient / all_speed_governor_j1939_reference_filter_coefficient / "
                  "all_speed_governor_reference_filter_coefficient",
    "0x008005aa": "The filter record of the engine speed (the 2^n pulse average)",
    "0x00800612": "The filter record of the engine protection speed limit (Calterm maximum rpm limit filter)",
    "0x00801a32": "The filter record of the pedal fault mode engine speed: preset to current_engine_rpm_filtered << 16 "
                  "(move.l at 0x258ce)",
    "0x00801a62": "The filter record of the low speed governor's throttle reference offset (Calterm digital filter "
                  "time constant used in the throttle deadband fix)",
    "0x00801c46": "The filter record of the power take-off governor reference (coefficient: Calterm reference speed "
                  "change constant)",
}
G5 = os.path.join(O5, "global_variables.csv")
F5 = os.path.join(O5, "function_renames.csv")
cpp5 = open(os.path.join(O5, "J90350.00.ghidra.cpp"), errors="replace").read()
lines = read(G5).split("\n")
rows = {}
for i, l in enumerate(lines):
    if l.startswith("0x"):
        rows[int(l.split(",")[0], 16)] = i
renames550 = []
instances = {}
for kind, address, current, proposed, typ, fields, verdict, final, final_type, conf, reason in changes:
    if kind == "struct_instance":
        instances[int(address, 16)] = (final, current, conf)


def base_name(instance):
    return instance[:-len("_state")] if instance.endswith("_filter_state") else instance


COEFFICIENT_OF = {0x807a42: 0x800066, 0x807a44: 0x80006e, 0x807f66: 0x800670, 0x80d634: 0x80d636, 0x80823e: 0x801a5a,
                  0x80889a: 0x801c00, 0x807ab0: 0x80a91a, 0x807ea8: 0x8005aa, 0x807f3a: 0x800612, 0x80820e: 0x801a32,
                  0x808258: 0x801a62, 0x8088ac: 0x801c46}
for k in range(25):
    COEFFICIENT_OF[0x806ae2 + 24 * k] = 0x80a2aa + 22 * k
ASG_COEFFICIENTS = {0x80a946: ("all_speed_governor_application_reference_filter_coefficient",
                               "the all-speed governor application specific set's reference filter coefficient"),
                    0x807b8c: ("all_speed_governor_j1939_reference_filter_coefficient",
                               "Calterm ASJCFTCS ASG JCOMM REFERENCE FILTER CONSTANT (fueling state 2 - TSC1 speed control)"),
                    0x807bda: ("all_speed_governor_reference_filter_coefficient",
                               "Calterm ASFTCF ASG REFERENCE FILTER COEFFICIENT CALIBRATION")}
removed = []
deletions = set()
new_rows = []
for a, (final, current, conf) in sorted(instances.items()):
    inside = [(o, lines[rows[a + o]].split(",")[1]) for o in range(1, 8) if a + o in rows]
    own = lines[rows[a]].split(",")[1] if a in rows else ""
    if own == final:
        continue
    for o, n in inside:
        deletions.add(rows[a + o])
        removed.append((a + o, n, final, o))
    if f"0x{a:08x}" in INSTANCE_TEXT:
        text = INSTANCE_TEXT[f"0x{a:08x}"]
    else:
        k = (a - 0x80a2aa) // 22
        assert 0x80a2aa + 22 * k == a and 0 <= k < 25
        text = (f"A/D channel {k}'s record +0-+7 (0x80a2aa + 22 x {k}): the filter record the A/D channel loop passes "
                "to cm550_exponentialMovingAverage; the channel is named from its config rows")
        if conf == "low":
            text += " (only its channel address row names it)"
    coefficient = next((c for c, i in COEFFICIENT_OF.items() if i == a), None)
    if coefficient:
        text += f"; coefficient -> {base_name(final)}_coefficient (0x{coefficient:x})"
    replaced = ([f"{own} at +0"] if own else []) + [f"{n} at +{o}" for o, n in inside]
    note = f"(were {' / '.join(replaced)}; {R})" if replaced else f"({R})"
    row = f"0x{a:08x},{final},ema_filter_state_t,{text} {note}"
    if a in rows:
        lines[rows[a]] = row
    else:
        new_rows.append((a, row))
    for old_label in ([own] if own else []) + ([f"DAT_{a:08x}"] if not own else []):
        renames550.append((f"0x{a:08x}", final, old_label))
for c, i in sorted(COEFFICIENT_OF.items()):
    name = f"{base_name(instances[i][0])}_coefficient"
    old = lines[rows[c]].split(",") if c in rows else None
    old_name = old[1] if old else ""
    if old_name == name:
        continue
    text = (f"The filter coefficient of {instances[i][0]} (0x{i:x}): the weight of the previous value in 1/65536; read "
            "with move.w through the record's pointer. Outside the EEPROM mirror, so no _cal")
    note = f"(was {old_name}; {R})" if old_name and old_name != name else f"({R})"
    row = f"0x{c:08x},{name},word,{text} {note}"
    if old:
        lines[rows[c]] = row
        if old_name != name:
            renames550.append((f"0x{c:08x}", name, old_name))
            renames550.append((f"0x{c:08x}", name, "_" + old_name))
    else:
        new_rows.append((c, row))
        renames550.append((f"0x{c:08x}", name, f"DAT_{c:08x}"))
        renames550.append((f"0x{c:08x}", name, f"_DAT_{c:08x}"))
for c, (name, what) in sorted(ASG_COEFFICIENTS.items()):
    old_name = lines[rows[c]].split(",")[1]
    if old_name == name:
        continue
    lines[rows[c]] = (f"0x{c:08x},{name},word,One of the three coefficients all_speed_governor_reference_filter_state "
                      f"points at ({what}); the weight of the previous value in 1/65536. No _cal "
                      f"(was {old_name}; {R})")
    if old_name != name:
        renames550.append((f"0x{c:08x}", name, old_name))
        renames550.append((f"0x{c:08x}", name, "_" + old_name))
lines = [l for i, l in enumerate(lines) if i not in deletions]
for a, row in sorted(new_rows):
    for i, l in enumerate(lines):
        if l.startswith("0x") and int(l.split(",")[0], 16) > a:
            lines.insert(i, row)
            break
write(G5, "\n".join(lines))
for a, n, final, o in removed:
    field = "coefficient" if o == 0 else "accumulator" if o == 4 else None
    if field:
        renames550.append((f"0x{a:08x}", f"{final}.{field}", n))
        renames550.append((f"0x{a:08x}", f"{final}.{field}", "_" + n))

# ---------------------------------------------------------------- the four CM550 filter functions
FUNCS = [
    ("0x00034e9a", "exponentialMovingAverage", "cm550_signedFirstOrderFilter",
     "The signed first-order filter on an ema_filter_state_t: the sample is offset binary (+ 0x8000); accumulator = "
     "coefficient x accumulator / 65536 + (sample + 0x8000) x (65536 - coefficient); it returns the rounded integer "
     "part - 0x8000. By role it pairs with CM848's cm848_signedFirstOrderFilter (0x5644c), a different formulation "
     "(a truncated +- |difference| step), so it is a counterpart, not a twin (was exponentialMovingAverage, a name it "
     f"shared with CM848's UNSIGNED filter 0x56594; {R})"),
    ("0x00034f8a", "cm550_coreTableInterpolation", "cm550_exponentialMovingAverage",
     "The unsigned first-order filter (exponential moving average) on an ema_filter_state_t: accumulator = coefficient "
     "x accumulator / 65536 + sample x (65536 - coefficient); it returns the rounded integer part. No table or axis: "
     "it is the signed filter without the offset-binary step. By role it pairs with CM848's "
     "cm848_exponentialMovingAverage (0x56594) - the twin calculateAlphaFuelRateResult calls it in both firmwares - "
     f"but the formulation differs (a truncated +- |difference| step), so it is a counterpart (was "
     f"cm550_coreTableInterpolation; {R})"),
    ("0x00034f00", "cm550_unsignedLinearInterpolation", "cm550_secondOrderFilter",
     "A signed second-order filter on a second_order_filter_state_t (muls.l / divs.l by 0xffff; it saturates to "
     "0x7fffffff / 0x80000000); the counterpart of CM848's cm848_secondOrderFilter (0x564c0, which shifts by 16 and "
     f"does not saturate). No caller in the dumped ROM (was cm550_unsignedLinearInterpolation; {R})"),
]
f5 = read(F5)
for address, old, new, plate in FUNCS:
    row = f"{address},{new},{plate}"
    if row in f5:
        continue
    m = re.search(rf"^{address},{re.escape(old)}(,[^\r\n]*)?$", f5, re.M)
    assert m, (address, old)
    f5 = f5[:m.start()] + row + f5[m.end():]
    renames550.append((address, new, old))
NEW_FUNC = ("0x00034fe0,cm550_secondOrderFilterUnsigned,The unsigned version of cm550_secondOrderFilter (mulu.l / divu.l; "
            "it clamps to 0 when the products go negative and to 0xffffffff on overflow): the fourth function of the "
            "filter module - CM848 has the same four in the same order (0x5644c / 0x564c0 / 0x56594 / 0x56608) - and "
            "the counterpart of cm848_secondOrderFilterUnsigned. No reference in the dumped ROM; this row creates the "
            f"function ({R})")
if "0x00034fe0," not in f5:
    out = f5.split("\n")
    for i, l in enumerate(out):
        if l.startswith("0x") and int(l.split(",")[0], 16) > 0x34fe0:
            out.insert(i, NEW_FUNC)
            break
    f5 = "\n".join(out)
    renames550.append(("0x00034fe0", "cm550_secondOrderFilterUnsigned", "FUN_00034fe0"))
write(F5, f5)

D5 = os.path.join(O5, "function_definitions.csv")
d5 = read(D5).split("\n")
PROTOS = {
    "0x00034e9a": ["0x00034e9a,cm550_signedFirstOrderFilter,return,,word,The rounded integer part of the accumulator - "
                   "0x8000: a signed value (no signed 16-bit prototype type yet)",
                   "0x00034e9a,cm550_signedFirstOrderFilter,0,new_sample,ushort,The sample (signed) - the word at +4 "
                   "(move.w (8;a6))",
                   "0x00034e9a,cm550_signedFirstOrderFilter,1,filter_state,ema_filter_state_t*,The filter record - the "
                   f"long at +6 (movea.l (10;a6)) ({R})"],
    "0x00034f8a": ["0x00034f8a,cm550_exponentialMovingAverage,return,,word,The rounded integer part of the accumulator",
                   "0x00034f8a,cm550_exponentialMovingAverage,0,new_sample,ushort,The sample - the word at +4 (move.w "
                   "(8;a6))",
                   "0x00034f8a,cm550_exponentialMovingAverage,1,filter_state,ema_filter_state_t*,The filter record - "
                   f"the long at +6 (movea.l (10;a6)) ({R})"],
    "0x00034f00": ["0x00034f00,cm550_secondOrderFilter,return,,word,The integer part of the new output (swap d2 / "
                   "move.w d2;d0)",
                   "0x00034f00,cm550_secondOrderFilter,0,input,ushort,The input - the word at +4 (move.w (20;sp) after "
                   "a movem of 4 registers)",
                   "0x00034f00,cm550_secondOrderFilter,1,filter,second_order_filter_state_t*,The filter record - the "
                   f"long at +6 (movea.l (22;sp)) ({R})"],
    "0x00034fe0": ["0x00034fe0,cm550_secondOrderFilterUnsigned,return,,word,The integer part of the new output",
                   "0x00034fe0,cm550_secondOrderFilterUnsigned,0,input,ushort,The input - the word at +4 (after a movem "
                   "of 4 registers)",
                   "0x00034fe0,cm550_secondOrderFilterUnsigned,1,filter,second_order_filter_state_t*,The filter record "
                   f"- the long at +6 (movea.l (22;sp)) ({R})"],
}
if PROTOS["0x00034e9a"][0] not in d5:
    first = {}
    keep = []
    for i, l in enumerate(d5):
        a = l[:10]
        if a in PROTOS:
            first.setdefault(a, len(keep))
            continue
        keep.append(l)
    for a in sorted(PROTOS, key=lambda x: -first.get(x, 10 ** 9)):
        if a in first:
            keep[first[a]:first[a]] = PROTOS[a]
    if "0x00034fe0" not in first:
        anchor = next(i for i, l in enumerate(keep) if l.startswith("0x00034f00,")) + 3
        keep[anchor:anchor] = PROTOS["0x00034fe0"]
    d5 = keep
write(D5, "\n".join(d5))

# ---------------------------------------------------------------- CM848: the unsigned filter keeps a prefixed name
F8 = os.path.join(O8, "function_renames.csv")
f8 = read(F8)
new848 = ("0x00056594,cm848_exponentialMovingAverage,The unsigned first-order filter (exponential moving average) on "
          "an ema_filter_state_t: the accumulator moves by +- |sample - its integer part| x (65536 - coefficient), "
          "truncated; it returns the integer part. CM550's role counterpart is cm550_exponentialMovingAverage "
          "(0x34f8a), a different formulation, so the name takes the prefix (was exponentialMovingAverage, shared "
          f"with CM550 0x34e9a - which is the signed filter; {R})")
if new848 not in f8:
    m = re.search(r"^0x00056594,exponentialMovingAverage(,[^\r\n]*)?$", f8, re.M)
    assert m
    f8 = f8[:m.start()] + new848 + f8[m.end():]
    write(F8, f8)

with open(map550, "w") as fh:
    fh.write("address,name,old_label,kind,dims\n")
    for a, n, o in renames550:
        fh.write(f"{a},{n},{o},symbol,1\n")
with open(map848, "w") as fh:
    fh.write("address,name,old_label,kind,dims\n")
    fh.write("0x00056594,cm848_exponentialMovingAverage,exponentialMovingAverage,function,1\n")
print(f"round 88 stage A applied: {len(instances)} instances, {len(COEFFICIENT_OF) + len(ASG_COEFFICIENTS)} coefficient "
      f"words, {len(removed)} rows inside records removed, map rows {len(renames550)}")
for a, n, final, o in removed:
    print(f"  removed 0x{a:x} {n} (+{o} of {final})")

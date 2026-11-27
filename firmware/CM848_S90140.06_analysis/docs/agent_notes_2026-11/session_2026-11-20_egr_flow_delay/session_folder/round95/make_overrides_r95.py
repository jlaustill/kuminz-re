"""Round 95: write overrides_r95.json for apply_r95.py from the judged batches N1-N3 and the judges' applier notes.
- structs (CM550): table_lookup_1d_arguments_t (14 bytes, the N2 judge's layout with its y_values_pointer wording),
  cm550_j1939_powertrain_messages_received_t (22 bytes, N3: 13 fields with explicit padding, as ApplyStructures packs
  fields one after another), trending_sample_record_t (14 bytes, N1).
- new_enums: TRIP_INFORMATION_ENGINE_STATE (CM550, 2 bytes: N1), J1939_PERIODIC_TRANSMIT_QUEUE (both, 4 bytes: N3).
- remove_globals: every live row strictly inside the span of a judged global whose final type is wider than one row
  (struct / array / wider primitive), plus the judges' named extras (N1: 0x804a18 inside the TRFLUSSR dword, 0x803698
  inside 0x803696, part_number_list 0x803ec2 which moves to 0x803ec5). A row that is itself a judged element is never
  removed (reported). Field paths for the refresh come from the new structs' offsets and from array element sizes.
usage: make_overrides_r95.py <repo> <out.json> <batch.json>..."""
import csv
import json
import os
import re
import sys

repo, out_path, batch_paths = os.path.abspath(sys.argv[1]), sys.argv[2], sys.argv[3:]
OUT = {"CM550": os.path.join(repo, "firmware/CM550_J90350.00_analysis/output"),
       "CM848": os.path.join(repo, "firmware/CM848_S90140.06_analysis/output")}
STRUCTS = {"CM550": {
    "table_lookup_1d_arguments_t": [
        ["x_axis_offset", "word", 2, "the byte offset of the x axis point the previous lookup found (2 = the first point); "
                                     "the search starts there and cm550_lookupTableInterpolation writes it back (the only field it writes)"],
        ["x_axis_pointer", "word*", 4, "the x axis table: its first word is the byte count of the points that follow (compared unsigned)"],
        ["x_input", "word", 2, "the x input value (compared unsigned)"],
        ["y_values_pointer", "word*", 4, "the y values: the value of the x point at byte offset n is read at y_values_pointer + n, "
                                         "so the word at +0 is never read (in a Calterm Y table it is the byte count)"],
        ["no_interpolation_flag", "word", 2, "nonzero: the lookup returns the value of the point at or below the input without "
                                             "interpolating (no code writes it; 0 in every record of the dump)"]],
    "cm550_j1939_powertrain_messages_received_t": [
        ["etc1_status_byte_1", "byte", 1, "ETC1 (PGN 61442) data byte 1, stored by the ETC1 handler 0x2efd0"],
        ["etc1_bytes_2_to_4", "byte", 3, "never written (CM550 keeps no ETC1 output shaft speed)"],
        ["etc1_status_byte_5", "byte", 1, "ETC1 data byte 5"],
        ["etc1_bytes_6_to_8", "byte", 3, "never written"],
        ["tsc1_control_byte", "byte", 1, "TSC1 (PGN 0) data byte 1: the override control mode and priority bits"],
        ["tsc1_requested_speed", "byte", 2, "TSC1 bytes 2-3 stored high byte first (data[2] at +0 and data[1] at +1)"],
        ["tsc1_requested_torque", "byte", 1, "TSC1 data byte 4"],
        ["tsc1_bytes_5_to_8", "byte", 4, "never written"],
        ["tsc1_accepted_priority", "byte", 1, "the priority of the accepted TSC1 request"],
        ["padding_1", "byte", 1, "no access (aligns the next word)"],
        ["tsc1_accepted_requested_speed", "word", 2, "the accepted TSC1 requested speed"],
        ["tsc1_accepted_requested_torque", "byte", 1, "the accepted TSC1 requested torque"],
        ["padding_2", "byte", 1, "no access"]],
    "trending_sample_record_t": [
        ["oil_pressure", "word", 2, "the oil pressure at the sample (sensor 4 filtered)"],
        ["boost_pressure", "word", 2, "the boost pressure at the sample (sensor 5)"],
        ["coolant_temperature", "word", 2, "the coolant temperature at the sample (sensor 6)"],
        ["average_fuel_consumption", "word", 2, "the interval's average fuel consumption (e2m TRAVFLCN)"],
        ["average_load", "word", 2, "the interval's average load (e2m TRLDINAV)"],
        ["time_stamp", "dword", 4, "engine_hour_meter with its low byte replaced by throttle_100_fueling >> 8"]]}}
SIZES = {fw: {s: sum(f[2] for f in fields) for s, fields in d.items()} for fw, d in STRUCTS.items()}
assert SIZES["CM550"] == {"table_lookup_1d_arguments_t": 14, "cm550_j1939_powertrain_messages_received_t": 22,
                          "trending_sample_record_t": 14}, SIZES
NEW_ENUMS = {"CM550": {"TRIP_INFORMATION_ENGINE_STATE": 2, "J1939_PERIODIC_TRANSMIT_QUEUE": 4},
             "CM848": {"J1939_PERIODIC_TRANSMIT_QUEUE": 4}}
EXTRA = {"CM550": {"0x00804a18": "", "0x00803698": "", "0x00803ec2": ""}}
PRIMITIVE = {"byte": 1, "char": 1, "bool": 1, "sbyte": 1, "uchar": 1, "i8": 1, "u8": 1, "word": 2, "short": 2,
             "ushort": 2, "i16": 2, "u16": 2, "sword": 2, "dword": 4, "int": 4, "uint": 4, "i32": 4, "u32": 4,
             "pointer": 4, "float": 4, "long": 4, "ulong": 4}


def sizes(fw):
    s = {}
    for r in csv.reader(open(os.path.join(OUT[fw], "enums.csv"), newline="")):
        if len(r) > 4 and r[0] and not r[0].startswith("#") and r[4].strip().isdigit():
            s.setdefault(r[0], int(r[4]))
    for r in csv.reader(l for l in open(os.path.join(OUT[fw], "structure_definitions.csv"), newline="") if not l.startswith("#")):
        if len(r) > 4 and r[0] and r[0] != "struct_name" and r[4].strip().isdigit():
            s[r[0]] = s.get(r[0], 0) + int(r[4])
    s.update(SIZES.get(fw, {}))
    s.update(NEW_ENUMS.get(fw, {}))
    return s


def width(fw, t, known):
    t = t.strip()
    if t.endswith("*"):
        return 4
    m = re.match(r"^(.+?)((?:\[\d+\])+)$", t)
    if m:
        n = 1
        for d in re.findall(r"\[(\d+)\]", m.group(2)):
            n *= int(d)
        w = width(fw, m.group(1), known)
        return None if w is None else w * n
    return PRIMITIVE.get(t) or known.get(t)


def field_path(name, typ, offset, known):
    base = re.sub(r"(\[\d+\])+$", "", typ).strip()
    elem = known.get(base) or PRIMITIVE.get(base) or 1
    index, inner = divmod(offset, elem) if typ.endswith("]") else (None, offset)
    prefix = f"{name}[{index}]" if index is not None else name
    fields = STRUCTS["CM550"].get(base)
    if fields:
        o = 0
        for f, ft, size, _ in fields:
            if o == inner:
                return f"{prefix}.{f}"
            o += size
        return ""
    return prefix if index is not None and inner == 0 else ""


rows = {fw: [] for fw in OUT}
for fw in OUT:
    for line in open(os.path.join(OUT[fw], "global_variables.csv"), newline="").read().split("\n"):
        parts = line.rstrip("\r").split(",", 3)
        if len(parts) > 2 and parts[0].startswith("0x"):
            rows[fw].append((int(parts[0], 16), parts[1], parts[2]))
remove = {fw: {} for fw in OUT}
report = []
elements = {fw: set() for fw in OUT}
judged = []
for p in batch_paths:
    d = json.load(open(p))
    vd = {(x.get("kind"), str(x.get("address")).lower()): x for x in d["verdict"]["verdicts"]}
    for g in d["proposal"].get("globals") or []:
        fw = g.get("firmware") or "CM550"
        v = vd.get(("global", str(g["address"]).lower())) or {}
        if v.get("verdict") not in ("CONFIRMED", "AMENDED"):
            continue
        a = int(g["address"], 16)
        elements[fw].add(a)
        judged.append((fw, a, v.get("final_name") or g["proposed_name"], (v.get("final_type") or g.get("proposed_type") or "").strip(), d["batch"]))
for fw, a, name, typ, b in judged:
    known = sizes(fw)
    w = width(fw, typ, known) if typ else None
    if not w or w < 2:
        continue
    for ra, rn, rt in rows[fw]:
        if a < ra < a + w:
            if ra in elements[fw]:
                report.append(f"KEEP {fw} 0x{ra:x} {rn}: a judged element inside {name} ({b})")
                continue
            remove[fw][f"0x{ra:08x}"] = field_path(name, typ, ra - a, known) if rn else ""
for fw, extra in EXTRA.items():
    for a, path in extra.items():
        remove[fw].setdefault(a, path)
json.dump({"structs": STRUCTS, "struct_sizes": SIZES, "new_enums": NEW_ENUMS,
           "remove_globals": {fw: r for fw, r in remove.items() if r}}, open(out_path, "w"), indent=1)
print({fw: len(r) for fw, r in remove.items()}, "rows to remove")
for line in report:
    print(line)

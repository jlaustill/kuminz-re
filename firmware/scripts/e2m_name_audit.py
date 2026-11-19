#!/usr/bin/env python3
"""Audit CM848 global_variables.csv against the e2m records the ECU's parameter ID table resolves.

For every scalar e2m record (type N) whose block the table holds, the record's address is table[block] + offset
(e2m_block_addresses.py). This reports, per record:
- the row there: `named` / `unnamed` (a row starts at the address), `inside` (a wider row - a struct, an array or a
  dword - starts earlier and covers it; struct sizes come from structure_definitions.csv) or `none`;
- the row's name and type, and the label the .cpp renders (the name, or DAT_<addr>) with its reference count;
- the e2m size (column 8, bytes) against the row's width;
- the dump value at the e2m size and signedness (the RAM dump; flash addresses from the ROM image) and whether
  value x scale lies inside the record's min..max (columns 11, 13, 14);
- `token_overlap`: the share of the record's words (abbreviations expanded) found in the current name - a rough
  pointer to names that disagree with the record, for a person or an agent to judge.

usage: e2m_name_audit.py <out.csv> [--summary]
"""
import argparse
import csv
import os
import re
import struct
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import e2m_block_addresses as table_tool  # noqa: E402

CM848 = table_tool.CM848
SIZES = {"byte": 1, "char": 1, "word": 2, "i16": 2, "short": 2, "ushort": 2, "dword": 4, "i32": 4, "pointer": 4,
         "float": 4, "uint": 4, "int": 4}
# e2m abbreviations -> words, for the overlap score only (names are never generated from this)
EXPANSIONS = {
    "tmptr": "temperature", "temp": "temperature", "thd": "threshold", "cmd": "command", "amb": "ambient",
    "ref": "reference", "max": "maximum", "min": "minimum", "avg": "average", "frac": "fraction", "adj": "adjustment",
    "spd": "speed", "eng": "engine", "press": "pressure", "pres": "pressure", "cnt": "count", "ctr": "counter",
    "lmt": "limit", "lim": "limit", "tbl": "table", "sw": "switch", "stat": "status", "val": "value", "pos": "position",
    "filt": "filtered", "diag": "diagnostic", "ovr": "override", "vlv": "valve", "pct": "percent", "cyl": "cylinder",
    "inj": "injection", "soi": "injection", "accel": "accelerator", "decel": "deceleration", "veh": "vehicle",
    "rpm": "speed", "pto": "power_take_off", "el": "emission_level", "cot": "compressor_outlet_temperature",
    "texh": "exhaust_temperature", "egr": "egr", "vgt": "variable_geometry_turbocharger", "batt": "battery",
    "volt": "voltage", "fuel": "fuel", "mcf": "charge_mass_flow", "cmf": "charge_mass_flow", "o2": "oxygen",
    "nox": "nitrogen_oxide", "bsnox": "nitrogen_oxide", "fsnox": "nitrogen_oxide", "uhc": "hydrocarbon",
    "ctrl": "control", "calc": "calculated", "gov": "governor", "lsg": "low_speed_governor",
    "hsg": "high_speed_governor", "asg": "all_speed_governor", "vsg": "variable_speed_governor", "cc": "cruise",
    "brk": "brake", "eb": "engine_brake", "trq": "torque", "torq": "torque", "alt": "altitude", "baro": "barometric",
    "coolant": "coolant", "ct": "coolant_temperature", "oil": "oil", "imt": "intake_manifold_temperature",
    "map": "manifold_pressure", "iat": "intake_air_temperature", "aps": "accelerator", "ecm": "ecm",
}
STOP = {"c", "t", "f", "the", "of", "and", "a", "to", "for", "in", "on", "is", "emo", "emm", "emr", "cbo", "cbr", "cbp",
        "jcomm", "fss", "ps", "e", "s", "b", "x"}


def words(text):
    out = []
    for token in re.split(r"[^A-Za-z0-9]+", text):
        for piece in re.findall(r"[A-Z]?[a-z]+|[A-Z]+(?![a-z])|\d+", token) or [token]:
            low = piece.lower()
            if not low or low in STOP:
                continue
            out += EXPANSIONS.get(low, low).split("_")
    return [w for w in out if w and w not in STOP]


def token_overlap(record_name, current_name):
    record = set(words(record_name))
    if not record or not current_name:
        return ""
    current = set(words(current_name))
    return f"{len(record & current) / len(record):.2f}"


def load_rows(path):
    rows = []
    for line in open(path, errors="replace"):
        if line.startswith("0x"):
            address, name, typ, comment = (line.rstrip("\n").split(",", 3) + ["", ""])[:4]
            rows.append((int(address, 16), name, typ))
    return rows


STRUCT_SIZES = {}


def load_struct_sizes(path):
    """Struct type -> byte size, from structure_definitions.csv (the sum of each field's size column; a bitfield
    packed into the same unit has size 0)."""
    sizes = {}
    for parts in csv.reader(open(path, errors="replace")):
        if len(parts) < 5 or not parts[0] or parts[0].startswith("#") or parts[0] == "struct_name":
            continue
        try:
            sizes[parts[0]] = sizes.get(parts[0], 0) + int(parts[4] or 0)
        except ValueError:
            pass
    return sizes


def width(typ):
    m = re.match(r"(\w+)\s*\[(\d+)\]$", typ)
    if m:
        return (SIZES.get(m.group(1)) or STRUCT_SIZES.get(m.group(1)) or 2) * int(m.group(2))
    return SIZES.get(typ) or STRUCT_SIZES.get(typ, 0)


def main(argv):
    parser = argparse.ArgumentParser()
    parser.add_argument("out")
    parser.add_argument("--summary", action="store_true")
    args = parser.parse_args(argv)
    table = table_tool.parse_table(open(table_tool.DEFAULTS["flash2"], "rb").read())
    STRUCT_SIZES.update(load_struct_sizes(os.path.join(CM848, "output", "structure_definitions.csv")))
    rows = load_rows(table_tool.DEFAULTS["globals"])
    starts = {a: (n, t) for a, n, t in rows}
    spans = sorted((a, a + max(width(t), 1), n, t) for a, n, t in rows)
    ram = open(os.path.join(CM848, "originals", "cm848_ram.bin"), "rb").read()
    rom = open(os.path.join(CM848, "originals", "cm848_rom.bin"), "rb").read()
    cpp = open(os.path.join(CM848, "output", "cm848_rom.ghidra.cpp"), errors="replace").read()
    code = "\n".join(l for l in cpp.split("\n") if not l.strip().startswith(("//", "/*", "*")))
    references = {}
    for token in re.findall(r"\b[A-Za-z_]\w*\b", code):
        references[token] = references.get(token, 0) + 1

    result = []
    for line in open(table_tool.DEFAULTS["e2m"], errors="replace"):
        fields = line.rstrip("\r\n").split(";", 1)[0].split(",")
        if len(fields) < 14 or fields[5] != "N":
            continue
        try:
            block, offset, size = int(fields[2], 16), int(fields[3], 16), int(fields[7])
        except ValueError:
            continue
        base = table.get(block)
        if base is None:
            continue
        address = table_tool.ram_address(base) + offset
        signed = fields[9] == "S"
        try:
            scale, low, high = float(fields[10]), float(fields[12]), float(fields[13])
        except ValueError:
            scale = low = high = None
        description = line.split(";", 1)[1].strip() if ";" in line else ""
        status, name, typ, inside = "none", "", "", ""
        if address in starts:
            name, typ = starts[address]
            status = "named" if name else "unnamed"
        else:
            for a, end, n, t in spans:
                if a < address < end:
                    status, name, typ, inside = "inside", n, t, f"+{address - a}"
                    break
        label = name or f"DAT_{address:08x}"
        raw = None
        if size in (1, 2, 4):
            data, at = (rom, address) if address < 0x3f0000 else (ram, address - 0x3FA000)
            if 0 <= at and at + size <= len(data):
                raw = int.from_bytes(data[at:at + size], "big", signed=signed)
        in_range = ""
        if raw is not None and scale is not None:
            value = raw * scale
            in_range = "yes" if low - 1e-9 <= value <= high + 1e-9 else "no"
        result.append({
            "block": f"{block:04X}", "offset": f"{offset:04X}", "record": fields[0], "unit": fields[1],
            "size": size, "signed": "S" if signed else "U", "scale": fields[10], "min": fields[12], "max": fields[13],
            "address": f"0x{address:08x}", "status": status, "row_name": name, "row_type": typ, "inside": inside,
            "row_width": width(typ) if status in ("named", "unnamed") else "",
            "label": label, "references": references.get(label, 0), "dump_raw": "" if raw is None else raw,
            "dump_in_range": in_range, "token_overlap": token_overlap(fields[0], name), "description": description[:160],
        })
    with open(args.out, "w", newline="") as f:
        writer = csv.DictWriter(f, fieldnames=list(result[0]))
        writer.writeheader()
        writer.writerows(result)
    if args.summary:
        counts = {}
        for r in result:
            counts[r["status"]] = counts.get(r["status"], 0) + 1
        print(f"{len(result)} scalar records resolved: {counts}")
        named = [r for r in result if r["status"] == "named"]
        low = [r for r in named if r["token_overlap"] and float(r["token_overlap"]) < 0.34]
        print(f"named rows with token overlap < 0.34: {len(low)}")
        used = [r for r in result if r["status"] in ("none", "unnamed") and r["references"]]
        print(f"no row / unnamed with references in the .cpp: {len(used)}")
    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))

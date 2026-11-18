#!/usr/bin/env python3
"""Collect the lookup-table globals passed to the CM848 table interpolators and size
them from their length words in the loaded images. Read-only: prints a report and
writes a proposals CSV. Usage: size_tables.py <analysis_dir> <out_csv>"""
import csv
import re
import sys
from collections import defaultdict

ANALYSIS = sys.argv[1]
OUT = sys.argv[2]
CPP = f"{ANALYSIS}/output/cm848_rom.ghidra.cpp"

# callee -> list of (role, arg index); axis = has its own byte-length word
CALLEES = {
    "lookupTableInterpolation": {"x": 2, "y": 3},
    "cm848_interpolateTableWithoutCache": {"x": 1, "y": 2},
    "cm848_dualAxisTableInterpolation": {"x": 2, "y2d": 4, "z": 5},
    "cm848_interpolateFuelMapTable": {"x": 2, "y": 3, "x2": 4, "y2": 5, "y3": 6, "y4": 7},
}
CACHE_ARG = {"lookupTableInterpolation": 0, "cm848_dualAxisTableInterpolation": 0}

images = {}
def load(name):
    with open(f"{ANALYSIS}/originals/{name}", "rb") as f:
        return f.read()
rom, flash2, ram, eeprom = load("cm848_rom.bin"), load("cm848_flash2_live.bin"), load("cm848_ram.bin"), load("cm848_eeprom.bin")

def region(a):
    if 0 <= a < 0x70000: return "rom"
    if 0x3F9800 <= a < 0x3FA000: return "romram_low"
    if 0x3FA000 <= a < 0x3FA000 + len(ram): return "ram"
    if 0x500000 <= a < 0x500000 + len(flash2): return "flash2"
    if 0x1000000 <= a < 0x1000000 + len(eeprom): return "eeprom"
    return None

def byte_at(a):
    r = region(a)
    if r == "rom": return rom[a]
    if r == "romram_low": return rom[0x3C30 + (a - 0x3F9800)]
    if r == "ram": return ram[a - 0x3FA000]
    if r == "flash2": return flash2[a - 0x500000]
    if r == "eeprom": return eeprom[a - 0x1000000]
    return None

def word_at(a):
    hi, lo = byte_at(a), byte_at(a + 1)
    if hi is None or lo is None: return None
    return (hi << 8) | lo

# --- name -> address resolution ---------------------------------------------------
name_to_addr = {}
global_rows = {}
with open(f"{ANALYSIS}/output/global_variables.csv") as f:
    for line in f:
        if line.startswith("#") or line.startswith("address,"): continue
        parts = line.rstrip("\n").split(",", 3)
        if len(parts) < 2 or not parts[0].startswith("0x"): continue
        a = int(parts[0], 16)
        name_to_addr[parts[1]] = a
        global_rows[a] = (parts[1], parts[2] if len(parts) > 2 else "", parts[3] if len(parts) > 3 else "")
array_rows = {}
with open(f"{ANALYSIS}/output/arrays.csv") as f:
    for line in f:
        if line.startswith("#") or line.startswith("address,"): continue
        parts = line.rstrip("\n").split(",", 4)
        if len(parts) < 4 or not parts[0].startswith("0x"): continue
        a = int(parts[0], 16)
        name_to_addr[parts[1]] = a
        size = {"byte": 1, "word": 2, "dword": 4, "pointer": 4}.get(parts[2], 0) * int(parts[3])
        array_rows[a] = (parts[1], size)
func_addrs = {}
with open(f"{ANALYSIS}/output/function_renames.csv") as f:
    for line in f:
        parts = line.split(",", 2)
        if parts and parts[0].startswith("0x"):
            func_addrs[int(parts[0], 16)] = parts[1]

array_names = {v[0] for v in array_rows.values()} | {r[0] for r in global_rows.values() if "[" in r[1]}
def resolve(text):
    """Address of the table an argument points at, or (None, why). Only address-of forms,
    hex literals and names that are already arrays point at the global itself; a bare
    scalar name is passed by VALUE (a pointer variable), so it is not the table."""
    t = text.strip()
    t = re.sub(r"^\((?:word|ushort|short|undefined2|byte|undefined|undefined1) \*\)", "", t).strip()
    address_of = t.startswith("&")
    t = t.lstrip("&").strip()
    m = re.fullmatch(r"0x([0-9a-fA-F]+)", t)
    if m: return int(m.group(1), 16), t
    if not address_of and t not in array_names:
        return None, "value:" + t
    if t in name_to_addr: return name_to_addr[t], t
    if t.startswith("_") and t[1:] in name_to_addr: return name_to_addr[t[1:]], t[1:]
    m = re.fullmatch(r"(?:_?DAT_|uRam|ram0x|UNK_|BYTE_|WORD_)([0-9a-fA-F]{6,8})", t)
    if m: return int(m.group(1), 16), t
    return None, t

# --- parse calls --------------------------------------------------------------------
src = open(CPP).read()
tok = re.compile(r"([A-Za-z_][A-Za-z0-9_]*)\s*\(|(\()|(\))|(,)|([^(),A-Za-z_]+|[A-Za-z_][A-Za-z0-9_]*)")
calls = []          # (callee, [arg texts])
stack = []          # [owner, argtexts, current]
for m in tok.finditer(src):
    fn, op, cp, comma, other = m.groups()
    if fn is not None:
        stack.append([fn, [], []])
    elif op is not None:
        stack.append(["(", [], []])
    elif cp is not None:
        if not stack: continue
        owner, args, cur = stack.pop()
        args.append("".join(cur))
        if owner in CALLEES or owner in CACHE_ARG:
            calls.append((owner, [x.strip() for x in args]))
        text = ("" if owner == "(" else owner) + "(" + ",".join(args) + ")"
        if stack: stack[-1][2].append(text)
    elif comma is not None:
        if stack:
            stack[-1][1].append("".join(stack[-1][2])); stack[-1][2] = []
    else:
        if stack: stack[-1][2].append(other)

# --- size -----------------------------------------------------------------------------
tables = {}        # addr -> dict(name, roles set, sizes set, notes)
unresolved = defaultdict(int)
cache_words = defaultdict(lambda: [0, ""])
def note(a, nm, role, count, why):
    t = tables.setdefault(a, {"name": nm, "roles": set(), "counts": set(), "why": set()})
    t["roles"].add(role); t["counts"].add(count); t["why"].add(why)

def axis_count(a):
    n = word_at(a)
    if n is None or n == 0 or n & 1 or n > 0x400: return None, n
    return 1 + n // 2, n

def monotonic(a, count):
    vals = [word_at(a + 2 * i) for i in range(1, count)]
    if any(v is None for v in vals): return False
    uns = all(vals[i] <= vals[i + 1] for i in range(len(vals) - 1))
    sig = [v - 0x10000 if v & 0x8000 else v for v in vals]
    sg = all(sig[i] <= sig[i + 1] for i in range(len(sig) - 1))
    return uns or sg

bad = []
for callee, args in calls:
    if callee in CACHE_ARG and len(args) > CACHE_ARG[callee]:
        a, nm = resolve(args[CACHE_ARG[callee]])
        if a is not None:
            cache_words[(a, nm, callee)][0] += 1
    if callee not in CALLEES: continue
    roles = CALLEES[callee]
    res = {}
    for role, idx in roles.items():
        if idx >= len(args): continue
        a, nm = resolve(args[idx])
        if a is None:
            unresolved[nm] += 1
            continue
        res[role] = (a, nm)
    # axes first
    n = {}
    for role in ("x", "x2", "y2d"):
        if role in res:
            a, nm = res[role]
            c, raw = axis_count(a)
            if c is None or not monotonic(a, c):
                bad.append((callee, role, hex(a), nm, raw)); continue
            n[role] = c - 1
            note(a, nm, "axis", c, f"{callee}:{role}")
    for role, axis_role in (("y", "x"), ("y2", "x2"), ("y3", "x2"), ("y4", "x2")):
        if role in res and axis_role in n:
            a, nm = res[role]
            note(a, nm, "data", n[axis_role] + 1, f"{callee}:{role}")
    if "z" in res and "x" in n and "y2d" in n:
        a, nm = res["z"]
        note(a, nm, "grid", n["x"] * n["y2d"], f"{callee}:z")

# --- conflicts ----------------------------------------------------------------------
rows = []
sorted_addrs = sorted(tables)
named_sorted = sorted(global_rows)
import bisect
for a in sorted_addrs:
    t = tables[a]
    counts = t["counts"]
    count = max(counts)
    flags = []
    if len(counts) > 1: flags.append("sizes " + "/".join(map(str, sorted(counts))))
    if "data" in t["roles"] and "axis" not in t["roles"]:
        w0 = word_at(a)
        if w0 != (count - 1) * 2: flags.append(f"data[0]={w0} != {(count - 1) * 2}")
    end = a + 2 * count
    # interior named globals
    i = bisect.bisect_right(named_sorted, a)
    interior = []
    while i < len(named_sorted) and named_sorted[i] < end:
        interior.append(global_rows[named_sorted[i]][0]); i += 1
    overl = [b for b in sorted_addrs if a < b < end]
    funcs = [func_addrs[f] for f in func_addrs if a <= f < end]
    arr = [array_rows[b][0] for b in array_rows if a <= b < end or (b < a < b + array_rows[b][1])]
    rows.append({
        "address": f"0x{a:08x}", "name": t["name"], "region": region(a), "count": count,
        "roles": "+".join(sorted(t["roles"])), "global_row": global_rows.get(a, ("", "", ""))[0],
        "global_type": global_rows.get(a, ("", "", ""))[1], "interior_named": " ".join(interior),
        "overlapping_tables": " ".join(hex(b) for b in overl), "functions_inside": " ".join(funcs),
        "existing_arrays": " ".join(arr), "flags": "; ".join(flags),
        "users": " ".join(sorted(t["why"])),
    })

with open(OUT, "w", newline="") as f:
    w = csv.DictWriter(f, fieldnames=list(rows[0].keys()))
    w.writeheader(); w.writerows(rows)

print(f"calls parsed: {len(calls)}  tables: {len(tables)}  bad axes: {len(bad)}  unresolved args: {sum(unresolved.values())}")
from collections import Counter
print("regions:", Counter(r["region"] for r in rows))
print("named (has global row):", sum(1 for r in rows if r["global_row"]), " unnamed:", sum(1 for r in rows if not r["global_row"]))
print("with interior named globals:", sum(1 for r in rows if r["interior_named"]))
print("with overlapping tables:", sum(1 for r in rows if r["overlapping_tables"]))
print("with functions inside:", sum(1 for r in rows if r["functions_inside"]))
print("with existing arrays:", sum(1 for r in rows if r["existing_arrays"]))
print("flagged:", sum(1 for r in rows if r["flags"]))
print("in ROM->RAM copy window 0x3f9800-0x3fdb30:", sum(1 for r in rows if 0x3F9800 <= int(r['address'], 16) < 0x3FDB30))
print("cache words:", len(cache_words))
print("top unresolved:", sorted(unresolved.items(), key=lambda kv: -kv[1])[:12])
print("bad axes sample:", bad[:12])

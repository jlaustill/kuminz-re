"""Round 78 stage A proof (CM550): every old 'global.field' render of the four rendering multi-address structs is mapped
to the address it really reaches (the global's address + the field's offset in the oversize type) and printed with the
name that address has now. Then the functions are compared statement by statement (temporaries renumbered, casts
dropped), old renders replaced by the mapped names, and the remaining changed statements are listed.
usage: prove_r78a_cm550.py <old.cpp> <new.cpp> <global_variables.csv>"""
import collections
import re
import sys

old_path, new_path, gv = sys.argv[1:4]
LAYOUT = {  # struct -> [(field, offset, size)] in row order (the type ApplyStructures built)
    "data_collector_t": [("ram_start_addr", 0, 4), ("ram_end_addr", 4, 4), ("logical_start", 8, 4),
                         ("logical_center", 12, 4)],
    "engine_rpm_history_t": [("previous_engine_rpm", 0, 2), ("previous_nonzero", 2, 2), ("previous_sample", 4, 2),
                             ("rpm_delta", 6, 2)],
    "fuel_arbitrator_diag_t": [("control_mode", 0, 2), ("response_timer", 2, 2), ("status_counter", 4, 2),
                               ("speed_timer", 6, 2), ("status_timer", 8, 2), ("session_timer", 10, 2),
                               ("session_counter", 12, 2), ("throttle_override", 14, 2)],
    "diagnostic_buffers_t": [("tx_buffer_base", 0, 256), ("rx_buffer_base", 256, 256)],
}
INSTANCES = {  # the globals that carried the struct type -> (address, struct)
    "logical_address_canter_value_stored_to_the_data_collector_buffer_none": (0x80aab6, "data_collector_t"),
    "previous_engine_rpm": (0x80000c, "engine_rpm_history_t"),
    "engine_rpm_previous_nonzero": (0x8002e6, "engine_rpm_history_t"),
    "engine_rpm_delta": (0x800346, "engine_rpm_history_t"),
    "fuel_arbitrator_throttle_override": (0x80d036, "fuel_arbitrator_diag_t"),
    "diagnostic_rx_buffer_base": (0x808c00, "diagnostic_buffers_t"),
}
names = {}
for line in open(gv, newline=""):
    parts = line.rstrip("\r\n").split(",", 3)
    if len(parts) > 2 and parts[0].startswith("0x"):
        names[int(parts[0], 16)] = parts[1]
FIELD = re.compile(r"\b(" + "|".join(map(re.escape, INSTANCES)) + r")\.([a-z_0-9]+)(?:\._(\d+)_(\d+)_)?")
seen = collections.Counter()


def target(m):
    base, struct = INSTANCES[m.group(1)]
    field = dict((f, o) for f, o, _ in LAYOUT[struct]).get(m.group(2))
    if field is None:
        return m.group(0)
    address = base + field + (int(m.group(3)) if m.group(3) else 0)
    name = names.get(address) or f"DAT_{address:08x}"
    seen[(m.group(0), f"0x{address:06x}", name)] += 1
    return name


TEMP = re.compile(r"\b(?:[a-z]Var|p[a-z]?Var|in_|unaff_|extraout_)[A-Za-z0-9_]*\b")
CAST = re.compile(r"\((?:short|ushort|int|uint|word|dword|undefined1|undefined2|undefined4|char|uchar|byte)\s*\**\)")
DECL = re.compile(r"^[A-Za-z_][A-Za-z0-9_ ]*\**\s+\**[A-Za-z_][A-Za-z0-9_]*(\[\w+\])?$")


def statements(path, mapped):
    t = open(path, errors="replace").read()
    parts = re.split(r"^// Function: (\S+) @[^\n]*\n", t, flags=re.M)
    out = {}
    for i in range(1, len(parts), 2):
        b = re.sub(r"/\*.*?\*/", "", parts[i + 1], flags=re.S)
        if mapped:
            b = FIELD.sub(target, b)
        b = re.sub(r"\s+", "", CAST.sub("", TEMP.sub("T", b)))
        out[parts[i]] = collections.Counter(s for s in re.split(r"[;{}]", b) if s and not DECL.match(s))
    return out


old_s, new_s = statements(old_path, True), statements(new_path, False)
print("old field renders -> the address they reach -> its name now:")
for (render, address, name), n in sorted(seen.items(), key=lambda x: x[0][1]):
    print(f"  {n:3} {render} -> {address} {name}")
changed = [f for f in old_s if old_s[f] != new_s.get(f)]
print(f"functions differing after the mapping (statement level): {len(changed)}")
for f in changed:
    gone = old_s[f] - new_s.get(f, collections.Counter())
    came = new_s.get(f, collections.Counter()) - old_s[f]
    print(f"== {f}")
    for s in gone:
        print("   - " + s[:150])
    for s in came:
        print("   + " + s[:150])

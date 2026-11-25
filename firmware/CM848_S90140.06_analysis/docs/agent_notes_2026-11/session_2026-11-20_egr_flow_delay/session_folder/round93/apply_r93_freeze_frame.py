"""Round 93 (CM550): the fault freeze frame records. 40 records of 48 bytes at 0x80426a - records 0-19 hold a
fault's first capture, records 20-39 (the 'shadow') its latest - the counterpart of CM848's
fault_freeze_frame_entries_cal (fault_entry_t[16]: 8 + 8). The layout is read from the capture function 0x2fe38:
one store per field, move.w except the two move.l (+0 from key_on_hour_meter, +26 from 0x80ccee), at
0x80462a + 48 x entry (shadow) and 0x80426a + 48 x entry (primary); the DM4 handler 0x3258a reads both halves as one
array (entry + 20 x 48).
- struct cm550_fault_entry_t (CM848's field names where the field holds the same record; the VP44 words are CM550's);
- fault_freeze_frame_entries : cm550_fault_entry_t[40] at 0x80426a; the rows inside it go: diagnostic_fault_code_table
  (0x80426e = entry 0's fault code index) and flash_program_block_1_buffer / _2_buffer (0x804882 / 0x80488e: no
  reference anywhere in the ROM);
- the sources: three words of the VP44 RAM image get rows (e2m 801A FLDFES / FLFLTP / FLFLSS); the system switch
  status words and three more take CM848's names for the same e2m records; four are only typed;
- six functions named for what they do with the records.
Idempotent; keeps line endings. usage: apply_r93_freeze_frame.py <repo> <map.csv>"""
import os
import re
import sys

repo, map_out = os.path.abspath(sys.argv[1]), sys.argv[2]
R = "PR #53 round 93"
O = os.path.join(repo, "firmware/CM550_J90350.00_analysis/output")
STRUCT = "cm550_fault_entry_t"
FIELDS = [  # name, type, size, comment
    ("key_on_hour_meter", "dword", 4, "key_on_hour_meter (0x80bda4) at capture (move.l)"),
    ("fault_code_index", "word", 2, "the fault code index (0-124) that owns the entry; 125 = free (cm550_releaseFaultFreezeFrameEntry). CM848 fault_entry_t.fault_code is a byte with 0xAA = free"),
    ("vehicle_speed", "word", 2, "0x80a9d0 at capture: e2m 117D +C VSFTAVVS 'sampled road speed after it has been filtered'"),
    ("filtered_rpm", "word", 2, "0x80ccf4 at capture: e2m 100C +2 ESCMES 'engine speed based from period of one cam rev'"),
    ("system_switch_status", "word", 2, "system_switch_status (0x80bcc8; e2m 1092 +0 SSSWSS01) at capture"),
    ("engine_load_at_current_speed", "word", 2, "engine_load_at_current_speed_percent (0x80db5e; e2m 10BF +0 JCPCLD) at capture"),
    ("accelerator_pedal_position", "word", 2, "0x80aa82 at capture: e2m 1047 +0 THROTTLE 'validated percent throttle commanded by driver'"),
    ("intake_manifold_pressure", "word", 2, "boost_pressure_sensor_state.filtered_value at capture"),
    ("coolant_temperature", "word", 2, "coolant_temperature_sensor_state.filtered_value at capture"),
    ("intake_manifold_temperature", "word", 2, "intake_manifold_temperature_sensor_state.filtered_value at capture"),
    ("oil_pressure", "word", 2, "oil_pressure_sensor_state.filtered_value at capture"),
    ("system_switch_status_2", "word", 2, "system_switch_status_2 (0x80bcca; e2m 1092 +2 SSSWSS02) at capture"),
    ("engine_hour_meter", "dword", 4, "engine_hour_meter (0x80ccee; e2m 11BC +0 CMEGTR 'time that the engine is not in stop state') at capture (move.l). CM848's fault_entry_t leaves these four bytes unwritten"),
    ("final_fueling_state", "FUELING_STATE", 2, "final_fueling_state (0x80d330) at capture; CM848 keeps only its low byte"),
    ("battery_voltage", "word", 2, "battery_voltage_sensor_state.filtered_value at capture"),
    ("final_fueling", "word", 2, "final_fueling (0x80d32e; e2m 1051 +0 FSFNFL) at capture"),
    ("selected_timing_advance", "word", 2, "selected_timing_advance_output_0_120 (0x80de6a; e2m 105B +2 TSFNTA) at capture; CM848's field here is main_injection_timing"),
    ("vp44_pump_status", "word", 2, "vp44_pump_status (0x80a18e; e2m 801A +1C FLFLSS) at capture. From here on CM848's fault_entry_t holds its common rail words instead"),
    ("vp44_fuel_temperature", "word", 2, "vp44_fuel_temperature (0x80a188; e2m 801A +16 FLFLTP) at capture"),
    ("cruise_control_switch_multiplexer", "word", 2, "cruise_control_switch_multiplexer_sensor_state.filtered_value at capture"),
    ("vp44_engine_speed", "word", 2, "vp44_engine_speed (0x80a17e; e2m 801A +C FLDFES) at capture"),
    ("system_switch_status_3", "word", 2, "system_switch_status_3 (0x80bccc; e2m 1092 +4 SSSWSS03) at capture"),
]
assert sum(f[2] for f in FIELDS) == 48
INSTANCE = (0x0080426a, "fault_freeze_frame_entries", f"{STRUCT}[40]",
            "The fault freeze frames: 40 records of 48 bytes (0x80426a-0x8049e9). Records 0-19 are a fault's first capture "
            "(written when the entry is given to the fault), records 20-39 the latest capture of the same entry (the shadow: "
            "rewritten at every capture of a fault whose definition flag 0x10 is set). fault_code_index 125 = free. Written by "
            "cm550_captureFaultFreezeFrame, freed by cm550_releaseFaultFreezeFrameEntry, searched by "
            "cm550_assignFaultFreezeFrameEntry / cm550_findOldestFreezeFrameEntryByFaultStatus and sent by "
            "cm550_j1939HandlePgn65229Dm4FreezeFrame (73 bytes per used entry, both halves). No e2m record. The counterpart of "
            "CM848's fault_freeze_frame_entries_cal (fault_entry_t[16], 8 + 8, in its EEPROM mirror); this one is outside "
            "CM550's mirror, so no _cal")
REMOVE = {0x0080426e: "fault_freeze_frame_entries[0].fault_code_index", 0x00804882: "", 0x0080488e: ""}
# address: (new name or None = keep, type, comment or None = keep the row's; history is added)
GLOBALS = {
    0x0080a17e: ("vp44_engine_speed", "word", "e2m 801A +C FLDFES 'engine speed as measured by VP44 controller' (RPM). The only reader in the dumped ROM is cm550_captureFaultFreezeFrame (through a4 = 0x80a17e), which stores it in the freeze frame"),
    0x0080a188: ("vp44_fuel_temperature", "word", "e2m 801A +16 FLFLTP 'RAM image of fuel temp measured by pump controller' (DEGF). Word reads at 0x1cb48 and 0x3381a; cm550_captureFaultFreezeFrame stores it in the freeze frame"),
    0x0080a18e: ("vp44_pump_status", "word", "e2m 801A +1C FLFLSS 'RAM image of pump status info maintained by pump controller' (HEX). Read only by cm550_captureFaultFreezeFrame (move.w at 0x2ff68 / 0x3009c)"),
    0x0080bcc8: ("system_switch_status", "word", "e2m 1092 +0 SSSWSS01 'bit mapped system switch status': the same record as CM848's system_switch_status (0x40a813). Word accesses only; stored in every fault freeze frame"),
    0x0080bcca: ("system_switch_status_2", "word", "e2m 1092 +2 SSSWSS02 'bit mapped system switch status': the same record as CM848's system_switch_status_2 (0x40a815). Word accesses only; stored in every fault freeze frame"),
    0x0080bccc: ("system_switch_status_3", "word", "e2m 1092 +4 SSSWSS03 'bit mapped system switch status': the third word of the block (CM848's e2m has two). or.w / and.w at 0x14f04 / 0x14f10; stored in every fault freeze frame"),
    0x0080db5e: ("engine_load_at_current_speed_percent", "word", "e2m 10BF +0 JCPCLD 'current output torque as a percent of maximum torque available' (0 - 127.5): the same record as CM848's engine_load_at_current_speed_percent (0x40af22). Word accesses only"),
    0x0080ccee: ("engine_hour_meter", "dword", "e2m 11BC +0 CMEGTR 'time that the engine is not in stop state' (SEC; 0 - 2^29): the same record as CM848's engine_hour_meter (0x40a794). Long accesses only (11 direct)"),
    0x0080d32e: ("final_fueling", "word", "e2m 1051 +0 FSFNFL 'final fueling value' (0 - 100), next to final_fueling_state (+2): the same record as CM848's final_fueling (0x40a2ce). Word accesses only (39 direct)"),
    0x0080a9d0: (None, "word", None),
    0x0080ccf4: (None, "word", None),
    0x0080aa82: (None, "word", None),
}
FUNCTIONS = {
    0x0002fe38: ("cm550_captureFaultFreezeFrame",
                 "Fills a fault freeze frame (fault_freeze_frame_entries, 48-byte cm550_fault_entry_t): the fault code index, key_on_hour_meter, "
                 "engine_hour_meter, the vehicle and engine speeds, load, throttle, boost / coolant / intake manifold temperature / oil pressure / "
                 "battery sensor values, the three system switch status words, final_fueling and its state, the timing advance, the cruise switch "
                 "multiplexer value and three words of the VP44 RAM image. When the fault's definition flags word (0x8067c6 + 6 x code) has bit 0x10 "
                 "it writes the shadow record (entry + 20); it writes the primary record only when the entry's fault code index differs (the first "
                 "capture). Called by cm550_assignFaultFreezeFrameEntry. CM848 does this inside hpcr_setFaultActiveStatus"),
    0x00014720: ("cm550_assignFaultFreezeFrameEntry",
                 "Gives a fault a freeze frame entry and captures it (cm550_captureFaultFreezeFrame): the entry that already holds the fault code "
                 "index; else the first free entry (125); else the entry of the oldest fault with status 2 (inactive), whose status becomes 0; else "
                 "of the oldest with status 3 (active), whose status becomes 1 (cm550_findOldestFreezeFrameEntryByFaultStatus). 20 entries. Called "
                 "by cm550_processFaultScanGroup when a fault turns active. The counterpart of CM848's cm848_registerFaultInActiveList (0x1cea4), "
                 "which has an OBD severity search on top"),
    0x000146b4: ("cm550_findOldestFreezeFrameEntryByFaultStatus",
                 "Returns the index (0-19) of the freeze frame entry whose fault has the given fault_count_table status and the smallest "
                 "status_change_time, or 0xffff when no entry's fault has that status. The counterpart of CM848's cm848_faultCodeLookup"),
    0x0002fd90: ("cm550_releaseFaultFreezeFrameEntry",
                 "Frees the freeze frame entry of a fault: finds the first of the 20 entries whose fault code index is the given one and writes 125 "
                 "(free) to the code of its primary and of its shadow record. Called by cm550_resetFaultStatus for a fault with status 2"),
    0x0003258a: ("cm550_j1939HandlePgn65229Dm4FreezeFrame",
                 "The J1939 request handler for PGN 65229 DM4 freeze frame (registered by cm550_initializePgn65229Dm4Handler): while the transmit "
                 "status is idle it builds j1939_pgn65229_tx_message - 8 bytes of 0 / 0xff when there is no active or previously active fault, else "
                 "73 bytes per used freeze frame entry (the standard fields from the shadow record when it is in use, else the primary; then both "
                 "records' words) - and sends it with cm550_sendCanMessage. CM848 splits this into cm848_j1939BuildDm4FreezeFrame and "
                 "cm848_j1939HandlePgn65229Dm4FreezeFrame"),
    0x000329d2: ("cm550_initializePgn65229Dm4Handler",
                 "Start-up: sets up the DM4 transmit descriptor at 0x802d62 (CAN ID from 0xFECD00 with the priority bits of 0x803f5a, the source "
                 "address, the data pointer 0x802d70 and the status pointer), writes each of the 20 entries' length byte 73 and 0xff, and registers "
                 "cm550_j1939HandlePgn65229Dm4FreezeFrame for PGN 65229 (0xFECD) with the request handler registrar at 0x2f47e. The counterpart of "
                 "CM848's cm848_initPgn65229Dm4Handler (0x25094)"),
}


def read(p):
    return open(p, newline="").read()


def write(p, t):
    open(p, "w", newline="").write(t)


def quote(text):
    text = " ".join(text.split())
    return '"' + text.replace('"', "'") + '"' if ("," in text or '"' in text) else text


pairs = []
# ---- struct
S = os.path.join(O, "structure_definitions.csv")
s = read(S)
E = "\r\n" if "\r\n" in s else "\n"
if not re.search(rf"^{STRUCT},,", s, re.M):
    rows = [f"# {STRUCT}: a fault freeze frame record (48 bytes; {R}) - CM848's fault_entry_t with a word fault code index, the engine hour meter at +26 and the VP44 words in place of the common rail ones"]
    for name, typ, size, comment in FIELDS:
        rows.append(f"{STRUCT},,{name},{typ},{size},{quote(comment)},,verified")
    write(S, s.rstrip("\r\n") + E + E + E.join(rows) + E)
# ---- globals
G = os.path.join(O, "global_variables.csv")
lines = read(G).split("\n")


def find(a):
    key = f"0x{a:08x}"
    return next((i for i, l in enumerate(lines) if l[:10].lower() == key and l[10:11] == ","), None)


for a, new_ref in REMOVE.items():
    i = find(a)
    if i is not None:
        old = lines[i].split(",")[1]
        del lines[i]
        if new_ref:
            pairs.append((f"0x{a:08x}", new_ref, old))
a, name, typ, comment = INSTANCE
if find(a) is None:
    after = [i for i, l in enumerate(lines) if l.startswith("0x") and int(l.split(",")[0], 16) < a]
    lines.insert(after[-1] + 1, f"0x{a:08x},{name},{typ},{comment} (was the row diagnostic_fault_code_table at 0x80426e and no rows for the rest; {R})")
for a, (new, typ, comment) in GLOBALS.items():
    i = find(a)
    if i is None:
        assert new and comment, hex(a)
        after = [k for k, l in enumerate(lines) if l.startswith("0x") and int(l.split(",")[0], 16) < a]
        lines.insert(after[-1] + 1, f"0x{a:08x},{new},{typ},{comment} ({R})")
        continue
    parts = lines[i].split(",", 3)
    old, old_type, old_comment = parts[1], parts[2], (parts[3] if len(parts) > 3 else "")
    name = new or old
    if old == name and old_type == typ:
        continue
    if new and new != old:
        text = f"{comment} (was {old}; {R})" + (f" | earlier note: {old_comment}" if old_comment else "")
        pairs.append((f"0x{a:08x}", new, old))
    else:
        text = (old_comment + " | " if old_comment else "") + f"typed {typ} (was {old_type}; word accesses only; {R})"
    lines[i] = f"0x{a:08x},{name},{typ},{text}"
write(G, "\n".join(lines))
# ---- functions
F = os.path.join(O, "function_renames.csv")
t = read(F)
for a, (new, plate) in FUNCTIONS.items():
    key = f"0x{a:08x}"
    m = re.search(rf"^{key},([^,\r\n]*)(?:,([^\r\n]*))?$", t, re.M)
    assert m, key
    old = m.group(1)
    if old == new:
        continue
    earlier = f" | earlier note: {m.group(2)}" if m.group(2) else ""
    t = t[:m.start()] + f"{key},{new},{plate} (was {old}; {R}){earlier}" + t[m.end():]
    for k in ("function_definitions.csv", "local_variables.csv"):
        p = os.path.join(O, k)
        c = read(p)
        c2 = re.sub(rf"^({key},){re.escape(old)},", lambda x: x.group(1) + new + ",", c, flags=re.M | re.I)
        if c2 != c:
            write(p, c2)
    pairs.append((key, new, old))
write(F, t)
if pairs:      # a re-run (nothing left to rename) must not empty the map
    with open(map_out, "w") as fh:
        fh.write("address,name,old_label,kind,dims\n")
        for key, new, old in pairs:
            fh.write(f"{key},{new},{old},symbol,1\n")
print(f"struct {STRUCT} ({len(FIELDS)} fields); instance {INSTANCE[1]}; {len(pairs)} renames in the map")

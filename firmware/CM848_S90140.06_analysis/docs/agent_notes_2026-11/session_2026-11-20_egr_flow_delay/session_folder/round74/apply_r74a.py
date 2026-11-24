"""Round 74 stage A: CM550's j1708_multipacket_msg_t instance at 0x80ddc6 (256 bytes) is not a record - CM550's own
parameter ID table puts 13 separate e2m blocks inside it (1127 J1708_Tx_Buffer at +0, 1128 J1708_Rx_Buffer at +4, 1001,
1002, 1328 development_mode, 0013 / 0014 / 0015 the scratch pad, 116B, 121A, 1215, 105B, 1080), nothing takes its
address, and the type has no other instance. The instance and the template go; every accessed address gets a row typed
with the struct field's own width (what the render already used) and keeps CM550's existing name - a relabel, proved as
a rename (the PAIRS file maps each access text to its new render). Idempotent; keeps line endings.
- coordinate rows ('j1708_transmit_buffer_2_32_ddc6.field[n]' / '+1') go: an accessed one becomes a type-only row;
- the two byte rows inside dwords (0x80dded insite_response_byte_offset / 0x80ddf5 insite_request_byte_offset) go - the
  code writes the low byte of the pointer, which renders as a piece of the dword - and their names move to the comments;
- 0x80ddca (block 1128, 4 bytes) and 0x80de28 (block 1001, 4 bytes) are dwords - the struct had them inside byte arrays.
usage: apply_r74a.py <repo> <pairs.json>"""
import json
import os
import sys

repo, pairs_path = os.path.abspath(sys.argv[1]), sys.argv[2]
O5 = os.path.join(repo, "firmware/CM550_J90350.00_analysis/output")
G5, S5 = os.path.join(O5, "global_variables.csv"), os.path.join(O5, "structure_definitions.csv")
R = "PR #53 round 74"
INST = "j1708_transmit_buffer_2_32_ddc6"
EOL = {}


def read(p):
    s = open(p, newline="").read()
    EOL[p] = "\r\n" if "\r\n" in s else "\n"
    return s.replace("\r\n", "\n")


def write(p, s):
    open(p, "w", newline="").write(s.replace("\n", EOL[p]))


# (offset, type, the old access texts that render here) - from struct_accesses.py over the round 73 .cpp (hex indexes
# included: reserved_126 is read as four bytes at +138..+141, never whole)
LAYOUT = [
    (0, "dword", ["base_ptr"]),
    (4, "dword", ["reserved_04._0_4_"]),
    (8, "byte", ["reserved_04[4]"]), (9, "byte", ["reserved_04[5]"]), (10, "byte", ["reserved_04[6]"]),
    (11, "byte", ["reserved_04[7]"]), (13, "byte", ["reserved_04[9]"]),
    (16, "word", ["length_16"]), (18, "dword", ["data_ptr_18"]), (24, "word", ["field_24"]),
    (26, "word", ["field_26"]),
    (28, "byte", ["reserved_28[0]"]), (29, "byte", ["reserved_28[1]"]), (30, "byte", ["reserved_28[2]"]),
    (31, "byte", ["reserved_28[3]"]), (33, "byte", ["reserved_28[5]"]),
    (36, "dword", ["write_ptr"]), (40, "dword", ["next_ptr"]), (44, "dword", ["segment_ptr"]),
    (48, "byte", ["reserved_48[0]"]), (49, "byte", ["reserved_48[1]"]), (50, "byte", ["reserved_48[2]"]),
    (52, "dword", ["buffer_ptr"]), (56, "byte", ["reserved_56[0]"]), (88, "dword", ["end_ptr"]),
    (92, "byte", ["reserved_92[0]"]), (93, "byte", ["reserved_92[1]"]), (94, "byte", ["reserved_92[2]"]),
    (95, "byte", ["reserved_92[3]"]), (96, "byte", ["reserved_92[4]"]), (98, "dword", ["reserved_92._6_4_"]),
    (102, "word", ["status_102"]), (104, "word", ["index_104"]), (106, "DEVELOPMENT_MODE_STATE", ["development_mode"]),
    (108, "dword", ["ctrl_ptr"]), (112, "word", ["reserved_112._0_2_"]),
    (114, "word", ["reserved_112._2_2_", ("reserved_112[2]", "._0_1_"), ("reserved_112[3]", "._1_1_")]),
    (116, "word", [("reserved_112[4]", "._0_1_"), ("reserved_112[5]", "._1_1_")]),
    (118, "word", ["reserved_112._6_2_"]), (120, "word", ["reserved_112._8_2_"]), (122, "dword", ["state_ptr"]),
    (138, "byte", ["reserved_126[0xc]"]), (139, "byte", ["reserved_126[0xd]"]), (140, "byte", ["reserved_126[0xe]"]),
    (141, "byte", ["reserved_126[0xf]"]), (142, "dword", ["msg_ptr"]),
    (154, "word", ["param_154"]), (156, "word", ["param_156"]), (158, "word", ["param_158"]),
    (160, "word", ["param_160"]), (162, "word", ["param_162"]), (164, "word", ["param_164"]),
    (168, "byte", ["reserved_166[2]"]), (169, "byte", ["reserved_166[3]"]), (170, "word", ["reserved_166._4_2_"]),
    (172, "byte", ["reserved_166[6]"]), (173, "byte", ["reserved_166[7]"]),
    (174, "word", ["param_174"]), (176, "word", ["param_176"]), (178, "word", ["param_178"]), (180, "word", ["param_180"]),
]
FOLD = {0x80dded: 0x80ddea, 0x80ddf5: 0x80ddf2}  # byte rows inside a dword: their names go to the dword's comment
BASE = 0x80ddc6

s = read(G5)
lines = s.split("\n")
rows = {}
for i, l in enumerate(lines):
    if l.startswith("0x"):
        parts = l.split(",", 3)
        rows[int(parts[0], 16)] = (i, parts)
already = not any(l.startswith(f"0x{BASE:08x},{INST},j1708_multipacket_msg_t,") for l in lines)

pairs, new_rows, drop = [], {}, set()
for off, typ, texts in LAYOUT:
    a = BASE + off
    row = rows.get(a)
    name = row[1][1] if row else ""
    if "." in name or "+" in name:
        name = ""  # a coordinate row: the address stays typed, unnamed
    if a == BASE:
        name = INST
    comment = row[1][3] if row and len(row[1]) > 3 else ""
    for b, into in FOLD.items():
        if into == a and b in rows:
            comment = (comment + " | " if comment else "") + f"its low byte {b:#x} was the row {rows[b][1][1]}"
    new_rows[a] = (name, typ, comment)
    # an unnamed typed row renders with its type's default label (BYTE_ / WORD_ / DWORD_ - seen in the build)
    render = name or {"byte": "BYTE", "word": "WORD", "dword": "DWORD"}[typ] + f"_{a:08x}"
    for t in texts:
        old, suffix = (t, "") if isinstance(t, str) else t
        pairs.append((f"{INST}.{old}", render + suffix))
for a, (i, parts) in rows.items():
    if BASE <= a < BASE + 256 and a not in new_rows:
        name = parts[1]
        if "." in name or "+" in name or a in FOLD:
            drop.add(a)

if not already:
    out = []
    for i, l in enumerate(lines):
        if l.startswith("0x"):
            a = int(l.split(",", 1)[0], 16)
            if a in drop or a in new_rows:
                continue
        out.append(l)
    # insert the span's rows in address order
    first = next(i for i, l in enumerate(out) if l.startswith("0x") and int(l.split(",", 1)[0], 16) > BASE)
    span = []
    for a in sorted(new_rows):
        name, typ, comment = new_rows[a]
        note = f"PR #53 round 74: typed {typ} - was a field of the misapplied j1708_multipacket_msg_t instance"
        if a == BASE:
            note += " (e2m block 1127 J1708_Tx_Buffer in CM550's parameter ID table - 4 bytes; was typed with the struct)"
        span.append(f"0x{a:08x},{name},{typ},{(comment + ' | ' if comment else '')}{note}")
    out[first:first] = span
    write(G5, "\n".join(out))
    st = read(S5).split("\n")
    st = [l for l in st if not l.startswith("j1708_multipacket_msg_t,")]
    write(S5, "\n".join(st))
pairs.sort(key=lambda p: -len(p[0]))
json.dump(pairs, open(pairs_path, "w"), indent=0)
print(f"round 74 stage A applied ({len(new_rows)} rows, {len(drop)} dropped, {len(pairs)} pairs)")
